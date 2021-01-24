#pragma once

namespace engine {

	class IndexBuffer
	{
	public:
		IndexBuffer(unsigned int indices[], unsigned int size, unsigned int count);
		~IndexBuffer();

		void Bind();
		void Unbind();

		inline unsigned int GetId() { return m_id; }
		inline unsigned int GetSize() { return m_size; }
		inline unsigned int GetCount() { return m_count; }
	private:
		unsigned int m_id;
		unsigned int m_size;
		unsigned int m_count;
	};

}
