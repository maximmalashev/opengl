#pragma once

#include <vector>

namespace engine {

	class VertexBuffer 
	{
	public:
		VertexBuffer(float vertices[], unsigned int size, std::vector<int> layout);
		~VertexBuffer();

		void Bind();
		void Unbind();

		inline unsigned int GetId() { return m_id; }
		inline unsigned int GetSize() { return m_size; }
		inline std::vector<int> GetLayout() { return m_layout; }
	private:
		unsigned int m_id;
		unsigned int m_size;
		std::vector<int> m_layout;
	};

}