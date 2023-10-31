#version 460

out vec4 fragColor;
in vec2 texCoord0;
//uniform sampler2D sampler;

void main(){
	fragColor = vec4(texCoord0, 0.0, 1.0);
}