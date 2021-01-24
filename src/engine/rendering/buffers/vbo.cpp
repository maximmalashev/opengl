#include "vbo.h"

#include <GL/glew.h>

namespace engine {

	VertexBuffer::VertexBuffer(float vertices[], unsigned int size, std::vector<int> layout) : m_size(size), m_layout(layout)
	{
		glGenBuffers(1, &m_id);
		Bind();
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	}

	void VertexBuffer::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_id);
	}

	void VertexBuffer::Unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	VertexBuffer::~VertexBuffer()
	{
		glDeleteBuffers(1, &m_id);
	}

}
