// Copyright 2019 the donut authors. See AUTHORS.md

#include "FrameBuffer.h"
#include <iostream>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <ThirdParty/stb_image_write.h>

namespace Donut::GL
{
	GLint FrameBuffer::MAX_ATTACHMENTS = -1;
	GLint FrameBuffer::MAX_SAMPLES = -1;

	FrameBuffer::Format::Format() :
		_target(GL_TEXTURE_2D),
		_colourInternalFormat(GL_RGBA8),
		_colourFormat(GL_RGBA),
		_colourType(GL_UNSIGNED_BYTE),
		_depthInternalFormat(GL_DEPTH_COMPONENT24),
		_depthBufferAsTexture(true),
		_samples(0),
		_colourBufferCount(1),
		_depthBuffer(true),
		_mipmapping(false),
		_wrapS(GL_CLAMP_TO_EDGE),
		_wrapT(GL_CLAMP_TO_EDGE),
		_filterMin(GL_LINEAR),
		_filterMag(GL_LINEAR)
	{

	}

	FrameBuffer::FrameBuffer(int width, int height, const Format& format) :
		_handle(0),
		_resolveHandle(0),
		_width(width),
		_height(height),
		_format(format),
		_depthRenderBuffer(NULL),
		_multisampleDepthRenderBuffer(NULL)
	{
		Load();
	}

	FrameBuffer::~FrameBuffer()
	{
		Unload();
	}

	void FrameBuffer::Load()
	{
		BindingState bindingState;

		bool useMultisampling = _format.GetSamples() > 0;

		glGenFramebuffers(1, &_handle);
		glBindFramebuffer(GL_FRAMEBUFFER, _handle);

		for (int i = 0; i < _format.GetColourBufferCount(); ++i)
		{
			GLuint textureHandle;
			glGenTextures(1, &textureHandle);
			glBindTexture(_format._target, textureHandle);
			glTexImage2D(_format._target, 0, _format._colourInternalFormat, _width, _height, 0, _format._colourFormat, _format._colourType, NULL);
			glTexParameteri(_format._target, GL_TEXTURE_WRAP_S, _format._wrapS);
			glTexParameteri(_format._target, GL_TEXTURE_WRAP_T, _format._wrapT);
			glTexParameteri(_format._target, GL_TEXTURE_MIN_FILTER, _format._filterMin);
			glTexParameteri(_format._target, GL_TEXTURE_MAG_FILTER, _format._filterMag);
			glBindTexture(_format._target, 0);
			_colourTextureHandles.push_back(textureHandle);
		}

		if (_format._colourBufferCount == 0)
		{
			glDrawBuffer(GL_NONE);
			glReadBuffer(GL_NONE);
		}

		if (!useMultisampling || !LoadMultisample())
		{
			std::vector<GLenum> drawBuffers;

			for (size_t i = 0; i < _colourTextureHandles.size(); ++i)
			{
				GLenum colourAttachment = (GLenum)(GL_COLOR_ATTACHMENT0 + i);
				glFramebufferTexture2D(GL_FRAMEBUFFER, colourAttachment, _format._target, _colourTextureHandles[i], 0);
				drawBuffers.push_back(colourAttachment);
			}

			if (!drawBuffers.empty())
			{
				glDrawBuffers((GLsizei)drawBuffers.size(), &drawBuffers[0]);
			}

			if (_format._depthBuffer)
			{
				if (_format._depthBufferAsTexture)
				{
					glGenTextures(1, &_depthTextureHandle);
					glBindTexture(_format._target, _depthTextureHandle);
					glTexImage2D(_format._target, 0, _format._depthInternalFormat, _width, _height, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);

					glTexParameteri(_format._target, GL_TEXTURE_WRAP_S, _format._wrapS);
					glTexParameteri(_format._target, GL_TEXTURE_WRAP_T, _format._wrapT);
					glTexParameteri(_format._target, GL_TEXTURE_MIN_FILTER, _format._filterMin);
					glTexParameteri(_format._target, GL_TEXTURE_MAG_FILTER, _format._filterMag);

					glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, _format._target, _depthTextureHandle, 0);
					glBindTexture(_format._target, 0);
				}
				else
				{
					_depthRenderBuffer = new RenderBuffer(_width, _height, _format._depthInternalFormat);
					glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, _depthRenderBuffer->GetHandle());
				}
			}

			CheckStatus();
		}

		_needsResolve = false;
		_needsMipmapUpdate = false;
	}

	void FrameBuffer::Unload()
	{
		if (_handle)
		{
			glDeleteFramebuffers(1, &_handle);
			_handle = 0;
		}

		if (_resolveHandle)
		{
			glDeleteFramebuffers(1, &_resolveHandle);
			_resolveHandle = 0;
		}

		if (!_colourTextureHandles.empty())
		{
			glDeleteTextures((GLsizei)_colourTextureHandles.size(), &_colourTextureHandles[0]);
			_colourTextureHandles.clear();
		}

		if (_depthTextureHandle)
		{
			glDeleteTextures(1, &_depthTextureHandle);
			_depthTextureHandle = 0;
		}

		if (_depthRenderBuffer != NULL)
		{
			delete _depthRenderBuffer;
			_depthRenderBuffer = NULL;
		}

		if (_multisampleDepthRenderBuffer != NULL)
		{
			delete _multisampleDepthRenderBuffer;
			_multisampleDepthRenderBuffer = NULL;
		}

		for (size_t i = 0; i < _multisampleColourRenderBuffers.size(); ++i)
		{
			delete _multisampleColourRenderBuffers[i];
		}

		_multisampleColourRenderBuffers.clear();
	}

	bool FrameBuffer::LoadMultisample()
	{
		glGenFramebuffers(1, &_resolveHandle);
		glBindFramebuffer(GL_FRAMEBUFFER, _resolveHandle);

		std::vector<GLenum> drawBuffers;

		for (size_t i = 0; i < _colourTextureHandles.size(); ++i)
		{
			GLenum colourAttachment = (GLenum)(GL_COLOR_ATTACHMENT0 + i);
			glFramebufferTexture2D(GL_FRAMEBUFFER, colourAttachment, _format._target, _colourTextureHandles[i], 0);
			drawBuffers.push_back(colourAttachment);
		}

		if (_format._depthBufferAsTexture)
		{
			glGenTextures(1, &_depthTextureHandle);
			glBindTexture(_format._target, _depthTextureHandle);
			glTexImage2D(_format._target, 0, _format._depthInternalFormat, _width, _height, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
			glTexParameteri(_format._target, GL_TEXTURE_WRAP_S, _format._wrapS);
			glTexParameteri(_format._target, GL_TEXTURE_WRAP_T, _format._wrapT);
			glTexParameteri(_format._target, GL_TEXTURE_MIN_FILTER, _format._filterMin);
			glTexParameteri(_format._target, GL_TEXTURE_MAG_FILTER, _format._filterMag);
			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, _format._target, _depthTextureHandle, 0);
			glBindTexture(_format._target, 0);
		}

		if (!drawBuffers.empty())
		{
			glDrawBuffers((GLsizei)drawBuffers.size(), &drawBuffers[0]);
		}

		if (!CheckStatus())
		{
			return false;
		}

		glBindFramebuffer(GL_FRAMEBUFFER, _handle);

		GLint maxSamples = GetMaxSamples();
		if (_format.GetSamples() < 0) _format.SetSamples(0);
		else if (_format.GetSamples() > maxSamples) _format.SetSamples(maxSamples);

		for (int i = 0; i < _format._colourBufferCount; ++i)
		{
			RenderBuffer* renderBuffer = new RenderBuffer(_width, _height, _format._colourInternalFormat, _format._samples);
			_multisampleColourRenderBuffers.push_back(renderBuffer);
			glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + i, GL_RENDERBUFFER, renderBuffer->GetHandle());
		}

		if (!drawBuffers.empty())
		{
			glDrawBuffers((GLsizei)drawBuffers.size(), &drawBuffers[0]);
		}

		if (_format._depthBuffer)
		{
			_multisampleDepthRenderBuffer = new RenderBuffer(_width, _height, _format._depthInternalFormat, _format._samples);
			glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, _multisampleDepthRenderBuffer->GetHandle());
		}

		return CheckStatus();
	}

	void FrameBuffer::ResolveTextures()
	{
		if (!_needsResolve)
		{
			return;
		}

		if (_resolveHandle)
		{
			BindingState bindingState;

			glBindFramebuffer(GL_READ_FRAMEBUFFER, _handle);
			glBindFramebuffer(GL_DRAW_FRAMEBUFFER, _resolveHandle);

			std::vector<GLenum> drawBuffers;

			for (size_t i = 0; i < _colourTextureHandles.size(); ++i)
			{
				GLenum colourAttachment = (GLenum)(GL_COLOR_ATTACHMENT0 + i);

				glDrawBuffer(colourAttachment);
				glReadBuffer(colourAttachment);

				GLbitfield bitfield = GL_COLOR_BUFFER_BIT;

				if (_depthTextureHandle)
				{
					bitfield |= GL_DEPTH_BUFFER_BIT;
				}

				glBlitFramebuffer(0, 0, _width, _height, 0, 0, _width, _height, GL_COLOR_BUFFER_BIT, GL_LINEAR);

				if (_depthTextureHandle)
				{
					glBlitFramebuffer(0, 0, _width, _height, 0, 0, _width, _height, GL_DEPTH_BUFFER_BIT, GL_LINEAR);
				}

				drawBuffers.push_back(colourAttachment);
			}

			glBindFramebuffer(GL_FRAMEBUFFER, _handle);
			glDrawBuffers((GLsizei)drawBuffers.size(), &drawBuffers[0]);
		}

		_needsResolve = false;
	}

	void FrameBuffer::UpdateMipmaps(bool bindFirst, int attachment) const
	{
		if (!_needsMipmapUpdate)
		{
			return;
		}

		if (bindFirst)
		{
			glBindTexture(_format._target, _colourTextureHandles[attachment]);
		}

		glGenerateMipmap(_format._target);
	}

	bool FrameBuffer::CheckStatus()
	{
		GLenum status = (GLenum)glCheckFramebufferStatus(GL_FRAMEBUFFER);

		switch (status)
		{
			case GL_FRAMEBUFFER_COMPLETE:
			{
				break;
			}
			case GL_FRAMEBUFFER_UNSUPPORTED:
			{
				std::cout << "Unsupported framebuffer format" << std::endl;
				return false;
			}
			case GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT:
			{
				std::cout << "Framebuffer incomplete: missing attachment" << std::endl;
				return false;
			}
			case GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT:
			{
				std::cout << "Framebuffer incomplete: duplicate attachment" << std::endl;
				return false;
			}
			case GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER:
			{
				std::cout << "Framebuffer incomplete: missing draw buffer" << std::endl;
				return false;
			}
			case GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER:
			{
				std::cout << "Framebuffer incomplete: missing read buffer" << std::endl;
				return false;
			}
			default:
			{
				std::cout << "Framebuffer invalid: unknown reason" << std::endl;
				return false;
			}
		}

		return true;
	}

	void FrameBuffer::Save()
	{
		//glBindFramebuffer(GL_READ_FRAMEBUFFER, _handle);
		//glBindFramebuffer(GL_DRAW_FRAMEBUFFER, fboID);
		//glBlitFramebuffer(0, 0, _width, _height, 0, 0, _width, _height, GL_COLOR_BUFFER_BIT, GL_NEAREST);

		auto w = _width;
		auto h = _height;
		uint32_t channels = 3;
		std::vector<uint8_t> data(((w * h) * channels) + (w * channels));
		uint8_t* row = &data[w * h * channels];

		glReadBuffer((GLenum)GL_COLOR_ATTACHMENT0);

		GLint alignment;
		glGetIntegerv(GL_PACK_ALIGNMENT, &alignment);
		glPixelStorei(GL_PACK_ALIGNMENT, 1);
		glReadPixels(0, 0, w, h, GL_RGB, GL_UNSIGNED_BYTE, data.data());
		glPixelStorei(GL_PACK_ALIGNMENT, alignment);

		for (int y = 0; y < h / 2; ++y)
		{
			memcpy(row, &data[y * w * channels], w * channels);
			memcpy(&data[y * w * channels], &data[(h - y - 1) * w * channels], w * channels);
			memcpy(&data[(h - y - 1) * w * channels], row, w * channels);
		}

		stbi_write_png("screenshot.png", w, h, channels, data.data(), w * channels);

		int i = 0;
	}

	void FrameBuffer::Bind()
	{
		glBindFramebuffer(GL_FRAMEBUFFER, _handle);

		if (_resolveHandle)
		{
			_needsResolve = true;
		}

		if (_format._mipmapping)
		{
			_needsMipmapUpdate = true;
		}
	}

	void FrameBuffer::BindColorTexture(int attachment)
	{
		if (attachment >= (int)_colourTextureHandles.size())
		{
			return;
		}

		ResolveTextures();

		glBindTexture(_format._target, _colourTextureHandles[attachment]);

		UpdateMipmaps(false, attachment);
	}

	void FrameBuffer::BindDepthTexture()
	{
		glBindTexture(_format._target, _depthTextureHandle);
	}

	void FrameBuffer::Unbind()
	{
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	void FrameBuffer::SetSize(int width, int height)
	{
		_width = width;
		_height = height;

		Unload();
		Load();
	}

	GLint FrameBuffer::GetMaxAttachments()
	{
		if (MAX_ATTACHMENTS < 0)
		{
			glGetIntegerv(GL_MAX_COLOR_ATTACHMENTS, &MAX_ATTACHMENTS);
		}

		return MAX_ATTACHMENTS;
	}

	GLint FrameBuffer::GetMaxSamples()
	{
		if (MAX_SAMPLES < 0)
		{
			glGetIntegerv(GL_MAX_SAMPLES, &MAX_SAMPLES);
		}

		return MAX_SAMPLES;
	}

	FrameBuffer::BindingState::BindingState()
	{
		glGetIntegerv(GL_FRAMEBUFFER_BINDING, &_value);
	}

	FrameBuffer::BindingState::~BindingState()
	{
		glBindFramebuffer(GL_FRAMEBUFFER, _value);
	}
}
