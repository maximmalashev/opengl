#pragma once

namespace engine {

	class Texture
	{
	public:
		Texture(const char* path);
		~Texture();

		void Bind();
	private:
		unsigned int m_id;

		int m_width, m_height;
		int m_channels;
	};

}