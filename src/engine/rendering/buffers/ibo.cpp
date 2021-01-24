#include "ibo.h"

#include <GL/glew.h>

engine::IndexBuffer::IndexBuffer(unsigned int indices[], unsigned int size, unsigned int count) : m_size(size), m_count(count)
{
	glGenBuffers(1, &m_id);
	Bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

engine::IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &m_id);
}

void engine::IndexBuffer::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
}

void engine::IndexBuffer::Unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
