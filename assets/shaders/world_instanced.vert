#version 330

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 uv;
layout(location = 2) in vec4 color;
layout(location = 3) in mat4 transform;

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

	gl_Position = viewProj * transform * vec4(position, 1.0);
}