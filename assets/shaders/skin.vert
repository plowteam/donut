#version 330

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 uv;
layout(location = 3) in vec3 boneWeights;
layout(location = 4) in ivec3 boneIndices;

out VertexData
{
    vec2 uv;
    vec3 normal;
} outData;

uniform mat4 viewProj;
uniform samplerBuffer boneBuffer;

mat4 GetMatrix(int index)
{
    return mat4(texelFetch(boneBuffer, (index * 4) + 0),
                texelFetch(boneBuffer, (index * 4) + 1),
                texelFetch(boneBuffer, (index * 4) + 2),
                texelFetch(boneBuffer, (index * 4) + 3));
}

void main()
{
    mat4 boneMatrix = GetMatrix(boneIndices[0]) * boneWeights[0];
    boneMatrix += GetMatrix(boneIndices[1]) * boneWeights[1];
    boneMatrix += GetMatrix(boneIndices[2]) * boneWeights[2];

    outData.uv = uv;
    outData.normal = normal;
    gl_Position = viewProj * (boneMatrix * vec4(position, 1.0));
}