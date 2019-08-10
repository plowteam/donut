#version 330

layout(location = 0) in vec2 vertex;
layout(location = 1) in vec3 offset;
layout(location = 2) in vec2 size;
layout(location = 3) in vec4 color;
layout(location = 4) in mat4x2 uvs;

out VertexData
{
    vec2 uv;
    vec4 color;
} outData;

uniform mat4 viewProj;

void main()
{
    outData.uv = uvs[gl_VertexID];
    outData.color = color;

    vec4 p = viewProj * vec4(vec3(vertex.xy * vec2(0, size.y), 0) + offset, 1.0);
    p.x += vertex.x * size.x;
	gl_Position = p;
}
