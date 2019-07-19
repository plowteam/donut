#version 330

uniform sampler2D diffuseTex;

in VertexData
{
    vec2 uv;
    vec3 normal;
} inData;

out vec4 fragColor;

void main()
{
    vec3 n = normalize(inData.normal);
    vec3 light0Position = normalize(vec3(-0.4, 0.5, -0.6));
    float NdotL0 = clamp(dot(n, light0Position), 0.0, 1.0);
    vec3 diffuse = vec3(NdotL0 + 0.5);
    diffuse.rgb = clamp(diffuse.rgb, 0.0, 1.0);
    vec3 diffuseColor = texture(diffuseTex, inData.uv).rgb;

    fragColor = vec4(diffuseColor * diffuse, 1.0);
}