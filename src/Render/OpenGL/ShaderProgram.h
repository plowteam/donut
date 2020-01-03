// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include "Core/Math/Fwd.h"
#include "Render/OpenGL/glad/glad.h"

#include <map>
#include <string>

namespace Donut::GL
{

class ShaderProgram
{
public:
	ShaderProgram() = delete;
	ShaderProgram(const std::string& vertexSource, const std::string& fragmentSource);
	~ShaderProgram();

	void Bind();
	void Unbind();

	void SetUniformValue(const char* uniformName, int value);
	void SetUniformValue(const char* uniformName, float value);
	void SetUniformValue(const char* uniformName, const Vector2& v);
	void SetUniformValue(const char* uniformName, const Vector3& v);
	void SetUniformValue(const char* uniformName, const Vector4& v);
	void SetUniformValue(const char* uniformName, const Matrix3x3& m);
	void SetUniformValue(const char* uniformName, const Matrix4x4& m);
	void SetUniformValue(const char* uniformName, std::size_t count, const Matrix4x4* m);

	GLuint GetRawHandle() const { return _program; }

private:
	GLuint _program;
	std::map<std::string, GLint> _uniforms;

	GLuint createSubShader(GLenum type, const std::string& source);
};

} // namespace Donut::GL
