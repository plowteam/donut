#version 330

uniform sampler2D diffuseTex;

in VertexData
{
    vec2 uv;
    vec4 color;
} inData;

out vec4 fragColor;

void main()
{
	vec4 diffuseColor = texture2D(diffuseTex, inData.uv);
    fragColor = vec4(diffuseColor.rgb * inData.color.rgb, diffuseColor.a);
}