
uniform sampler2DRect fbo;
uniform sampler2DRect image;
varying vec2 texCoord;

void main(void)
{
    vec3 color_tex1 = texture2DRect(fbo, texCoord).xyz;
    vec3 color_tex2 = texture2DRect(image, texCoord).xyz;
    vec3 mix = color_tex1 * color_tex2;
    
    gl_FragColor = vec4(mix.r, mix.g, mix.b, 1.0);
}