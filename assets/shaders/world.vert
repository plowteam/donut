#version 330

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 uv;
layout(location = 2) in vec4 color;

out VertexData
{
    vec2 uv;
    vec4 color;
} outData;

uniform mat4 viewProj;

void main()
{
    outData.uv = uv;
    outData.color = color;

	gl_Position = viewProj * vec4(position, 1.0);
}