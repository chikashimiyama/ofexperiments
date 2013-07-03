
uniform sampler2DRect tex1;
uniform sampler2DRect tex2;
varying vec2 texCoord;  

void main(void)
{
    vec3 color_tex1 = texture2DRect(tex1, texCoord).xyz;
    vec3 color_tex2 = texture2DRect(tex2, texCoord).xyz;
    vec3 mix = color_tex1 - color_tex2;

    gl_FragColor = vec4(mix.r, mix.g, mix.b, 1.0);
}