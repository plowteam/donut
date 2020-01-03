// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include "RenderBuffer.h"

#include <vector>

namespace Donut::GL
{
class FrameBuffer
{

public:
	class Format
	{

		friend class FrameBuffer;

	public:
		Format();

		void EnableColourBuffer(bool colourBuffer = true, int colourBufferCount = 1)
		{
			_colourBufferCount = colourBuffer ? colourBufferCount : 0;
		}
		void EnableDepthBuffer(bool depthBuffer = true, bool depthBufferAsTexture = true)
		{
			_depthBuffer = depthBuffer;
			_depthBufferAsTexture = depthBufferAsTexture;
		}
		void EnableMipmapping(bool mipmapping = true) { _mipmapping = mipmapping; }

		inline bool HasMipmapping() const { return _mipmapping; }
		inline bool HasColourBuffer() const { return _colourBufferCount > 0; }
		inline bool HasDepthBuffer() const { return _depthBuffer; }
		inline bool HasDepthBufferTexture() const { return _depthBufferAsTexture; }

		inline void SetTarget(GLenum target) { _target = target; }
		inline void SetColourInternalFormat(GLenum colourInternalFormat) { _colourInternalFormat = colourInternalFormat; }
		inline void SetColourFormat(GLenum colourFormat) { _colourFormat = colourFormat; }
		inline void SetColourType(GLenum colourType) { _colourType = colourType; }
		inline void SetDepthInternalFormat(GLenum depthInternalFormat) { _depthInternalFormat = depthInternalFormat; }
		inline void SetWrap(GLenum wrapS, GLenum wrapT)
		{
			SetWrapS(wrapS);
			SetWrapT(wrapT);
		}
		inline void SetSamples(int samples) { _samples = samples; }
		inline void SetWrapS(GLenum wrapS) { _wrapS = wrapS; }
		inline void SetWrapT(GLenum wrapT) { _wrapT = wrapT; }
		inline void SetFilterMin(GLenum filterMin) { _filterMin = filterMin; }
		inline void SetFilterMag(GLenum filterMag) { _filterMag = filterMag; }

		inline GLenum GetTarget() const { return _target; }
		inline GLenum GetColourInternalFormat() const { return _colourInternalFormat; }
		inline GLenum GetDepthInternalFormat() const { return _depthInternalFormat; }
		inline int GetSamples() const { return _samples; }
		inline int GetColourBufferCount() const { return _colourBufferCount; }

	private:
		GLenum _target;
		GLenum _colourInternalFormat;
		GLenum _colourFormat;
		GLenum _colourType;
		GLenum _depthInternalFormat;
		int _samples;
		bool _mipmapping;
		bool _depthBuffer;
		bool _depthBufferAsTexture;
		int _colourBufferCount;
		GLenum _wrapS;
		GLenum _wrapT;
		GLenum _filterMin;
		GLenum _filterMag;
	};

	FrameBuffer(int width, int height, const Format& format = Format());
	~FrameBuffer();

	void Bind();
	void BindColorTexture(int attachment);
	void BindDepthTexture();
	static void Unbind();

	void SetSize(int width, int height);

	inline GLuint GetHandle() const { return _handle; }
	inline GLuint GetResolveHandle() const { return _resolveHandle; }
	inline GLint GetWidth() const { return _width; }
	inline GLint GetHeight() const { return _height; }
	inline const Format& GetFormat() const { return _format; }
	inline GLint GetColorTexture(int attachment) { return _colourTextureHandles.at(attachment); }
	static GLint GetMaxSamples();
	static GLint GetMaxAttachments();

	void Save();

private:
	class BindingState
	{

	public:
		BindingState();
		~BindingState();

	private:
		GLint _value;
	};

	void Load();
	void Unload();
	bool LoadMultisample();
	void ResolveTextures();
	void UpdateMipmaps(bool bindFirst, int attachment) const;
	bool CheckStatus();

	GLuint _handle;
	GLuint _resolveHandle;
	int _width;
	int _height;
	Format _format;
	std::vector<GLuint> _colourTextureHandles;
	std::vector<RenderBuffer*> _multisampleColourRenderBuffers;
	GLuint _depthTextureHandle;
	RenderBuffer* _multisampleDepthRenderBuffer;
	RenderBuffer* _depthRenderBuffer;
	bool _needsResolve;
	bool _needsMipmapUpdate;
	static GLint MAX_ATTACHMENTS;
	static GLint MAX_SAMPLES;
};
} // namespace Donut::GL
