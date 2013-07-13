uniform sampler2DRect displacementMap;
varying vec4 color;

void main(void)
{
	vec4 newVertexPos;
	vec4 col;
	float df;
	
	col = texture2DRect( displacementMap, gl_MultiTexCoord0.xy );
	df = col.x;
	newVertexPos = gl_Vertex;
    newVertexPos.z =  df*300.0;
	
	gl_Position = gl_ModelViewProjectionMatrix * newVertexPos;
    if(newVertexPos.z < 100.0){
        color = vec4(0.0,0.0,0.0,0.0);
    }else{
        color = vec4(1.0,1.0,1.0,1.0);
    }

}
