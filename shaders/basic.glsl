#type vertex
#version 330 core

layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec4 a_Color;
layout(location = 2) in vec2 a_TexCoords;

out vec4 v_Color;
out vec3 v_Position;
out vec2 v_TexCoords;

void main() {
	v_TexCoords = a_TexCoords;
	v_Color = a_Color;
	gl_Position = vec4(a_Position, 1.0);
};

#type fragment
#version 330 core

in vec4 v_Color;
in vec2 v_TexCoords;

out vec4 FragColor;

void main() {
	FragColor = vec4(v_TexCoords, 0.0f, 1.0f);
};