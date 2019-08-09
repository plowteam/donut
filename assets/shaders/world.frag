#version 330

uniform sampler2D diffuseTex;
uniform float alphaMask;

in VertexData
{
    vec2 uv;
    vec4 color;
} inData;

out vec4 fragColor;

void main()
{
	vec4 diffuseColor = texture2D(diffuseTex, inData.uv);

	if (diffuseColor.a < alphaMask) discard;
	else fragColor = vec4(diffuseColor.rgb * inData.color.rgb, diffuseColor.a);
}