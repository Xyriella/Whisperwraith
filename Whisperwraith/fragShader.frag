#version 460

out vec4 fragColor;
in vec2 texCoord0;
uniform sampler2D sampler;

void main(){
	fragColor = texture2D(sampler, texCoord0.st);
}