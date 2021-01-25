#include "texture.h"

#include <GL/glew.h>
#include <stb_image.h>

#include <iostream>

namespace engine {

	Texture::Texture(const char* path)
	{
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load(path, &m_width, &m_height, &m_channels, 0);
		
		if (!data)
		{
			std::cout << "Unable to load image " << path << std::endl;
			std::exit(-1);
		}

		glGenTextures(1, &m_id);
		Bind();

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		stbi_image_free(data);
	}

	void Texture::Bind()
	{
		glBindTexture(GL_TEXTURE_2D, m_id);
	}

	Texture::~Texture() { }
}


