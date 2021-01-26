@VERTEX
#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTextureCoords;

uniform mat4 model;
uniform mat4 projection;
uniform mat4 view;

out vec2 textureCoords;

void main()
{
   gl_Position = projection * view * model * vec4(aPos.x, aPos.y, aPos.z, 1.0f);
   textureCoords = aTextureCoords;
}

@FRAGMENT
#version 330 core

in vec2 textureCoords;

uniform sampler2D quadTexture;

out vec4 FragColor;

void main()
{
	FragColor = texture(quadTexture, textureCoords);
}