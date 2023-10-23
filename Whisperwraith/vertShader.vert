#version 460

layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 texCoord;
//out vec4 color;
out vec2 texCoord0;
uniform mat4 transform;

void main(){
	gl_Position = transform * vec4(pos, 1.0);
	texCoord0 = texCoord;
}