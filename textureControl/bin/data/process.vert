varying vec2 texCoord;

void main(void)
{
    gl_Position = gl_ModelViewProjectionMatrix*gl_Vertex;
    texCoord = vec2(gl_MultiTexCoord0);
}