uniform sampler2DRect displacementMap;

void main(void)
{
	vec4 newVertexPos;
	vec4 col;
	float df;
	
	col = texture2DRect( displacementMap, gl_MultiTexCoord0.xy );
	df = col.x + col.y + col.z;
	newVertexPos = gl_Vertex;
    newVertexPos.z = newVertexPos.y + df*100.0;
	
	gl_Position = gl_ModelViewProjectionMatrix * newVertexPos;

}
