uniform sampler2DRect tex1;
uniform sampler2DRect tex2;

uniform float phase;
varying vec2 texCoord;

void main(void)
{
    float x, y;
    x = texCoord.s;
    y = texCoord.t;
    
    x += sin((y + phase) * 0.01744) * 10.0;
    y += sin((x + phase) * 0.01744) * 10.0;
    
    vec3 nz = texture2DRect(tex2, vec2(x, y+phase)).rgb;
    x += nz.r * 300.0 - 150.0;
    vec3 tex  = texture2DRect(tex1, vec2(x, y)).rgb;
    gl_FragColor = vec4(tex.r, tex.g, tex.b, 1.0);
}