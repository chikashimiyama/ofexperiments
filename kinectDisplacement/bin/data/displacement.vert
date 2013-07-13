uniform sampler2DRect displacementMap;

void main(void)
{
	vec4 newVertexPos;
	vec4 col;
	float df;
	
	col = texture2DRect( displacementMap, gl_MultiTexCoord0.xy );
	df = col.x;
	newVertexPos = gl_Vertex;
    newVertexPos.z =  df*-500.0;
	
	gl_Position = gl_ModelViewProjectionMatrix * newVertexPos;

}
