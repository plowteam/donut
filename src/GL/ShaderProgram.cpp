#include <GL/ShaderProgram.h>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <glm/gtc/type_ptr.hpp>

namespace Donut::GL
{

ShaderProgram::ShaderProgram(const std::string& vertexSource, const std::string& fragmentSource)
{
	_program = glCreateProgram();

	// lazy assert, todo: better error handling
	assert(_program != 0);

	GLuint vertexShader   = createSubShader(GL_VERTEX_SHADER, vertexSource.c_str());
	GLuint fragmentShader = createSubShader(GL_FRAGMENT_SHADER, fragmentSource.c_str());

	// lazy assert, todo: better error handling
	assert(vertexShader != 0 && fragmentShader != 0);

	glAttachShader(_program, vertexShader);
	glAttachShader(_program, fragmentShader);
	glLinkProgram(_program);

	GLint linkStatus = GL_FALSE;
	glGetProgramiv(_program, GL_LINK_STATUS, &linkStatus);

	if (linkStatus == GL_FALSE)
	{
		GLint infoLogLen = 0;
		glGetShaderiv(_program, GL_INFO_LOG_LENGTH, &infoLogLen);

		char* infoLog = new char[infoLogLen];
		glGetProgramInfoLog(_program, infoLogLen, &infoLogLen, infoLog);
		std::fprintf(stderr, "ShaderProgram linking errors:\n%s\n", infoLog); // throw an exception?
		delete[] infoLog;

		glDeleteProgram(_program);
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		return;
	}

	// we can delete these now they exist in the program
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	int uniformCount = -1;
	glGetProgramiv(_program, GL_ACTIVE_UNIFORMS, &uniformCount);
	for (int i = 0; i < uniformCount; i++)
	{
		int name_len = -1, num = -1;
		GLenum type = GL_ZERO;
		char name[64];
		glGetActiveUniform(_program, GLuint(i), sizeof(name) - 1, &name_len, &num, &type, name);
		name[name_len] = 0;

		_uniforms[std::string(name)] = glGetUniformLocation(_program, name);
	}
}

ShaderProgram::~ShaderProgram()
{
	if (_program != 0)
		glDeleteProgram(_program);
}

void ShaderProgram::Bind()
{
	glUseProgram(_program);
}

void ShaderProgram::Unbind()
{
	glUseProgram(0);
}

void ShaderProgram::SetUniformValue(const char* uniformName, int value)
{
	glUniform1i(_uniforms[uniformName], value);
}

void ShaderProgram::SetUniformValue(const char* uniformName, float value)
{
	glUniform1f(_uniforms[uniformName], value);
}

void ShaderProgram::SetUniformValue(const char* uniformName, const glm::vec2& v)
{
	glUniform2fv(_uniforms[uniformName], 1, glm::value_ptr(v));
}

void ShaderProgram::SetUniformValue(const char* uniformName, const glm::vec3& v)
{
	glUniform3fv(_uniforms[uniformName], 1, glm::value_ptr(v));
}

void ShaderProgram::SetUniformValue(const char* uniformName, const glm::vec4& v)
{
	glUniform4fv(_uniforms[uniformName], 1, glm::value_ptr(v));
}

void ShaderProgram::SetUniformValue(const char* uniformName, const glm::mat3& m)
{
	glUniformMatrix3fv(_uniforms[uniformName], 1, GL_FALSE, glm::value_ptr(m));
}

void ShaderProgram::SetUniformValue(const char* uniformName, const glm::mat4& m)
{
	glUniformMatrix4fv(_uniforms[uniformName], 1, GL_FALSE, glm::value_ptr(m));
}

void ShaderProgram::SetUniformValue(const char* uniformName, std::size_t count, const glm::mat4* m)
{
	glUniformMatrix4fv(_uniforms[uniformName], (GLsizei)count, GL_FALSE, glm::value_ptr(m[0]));
}

GLuint ShaderProgram::createSubShader(GLenum type, const std::string& source)
{
	GLuint shader = glCreateShader(type);

	const GLchar* glsource = (const GLchar*)source.c_str();
	glShaderSource(shader, 1, &glsource, nullptr);
	glCompileShader(shader);

	GLint compileStatus = GL_FALSE;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compileStatus);

	if (compileStatus == GL_FALSE)
	{
		GLint infoLogLen = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLen);

		char* infoLog = new char[infoLogLen];
		glGetShaderInfoLog(shader, infoLogLen, &infoLogLen, infoLog);
		std::fprintf(stderr, "ShaderProgram compile errors:\n%s\n", infoLog); // throw an exception?
		delete[] infoLog;

		glDeleteShader(shader);
		return 0;
	}

	return shader;
}

} // namespace Donut::GL
