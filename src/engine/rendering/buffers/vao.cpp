#include "vao.h"

#include <GL/glew.h>

namespace engine {

	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &m_id);
		Bind();
	}

	void VertexArray::Bind()
	{
		glBindVertexArray(m_id);
	}

	void VertexArray::Unbind()
	{
		glBindVertexArray(0);
	}

	void VertexArray::AttachBuffers(VertexBuffer &vbo, IndexBuffer &ibo)
	{
		Bind();
		vbo.Bind();
		ibo.Bind();

		m_vbo = &vbo;
		m_ibo = &ibo;
		
		const auto& layout = vbo.GetLayout();
		unsigned int stride = 0;
		unsigned int offset = 0;

		for (const auto& location : layout)
			stride += location * sizeof(float);

		for (int location = 0; location < layout.size(); location++)
		{
			glVertexAttribPointer(location, layout[location], GL_FLOAT, GL_FALSE, stride, (const void*) offset);
			offset += layout[location] * sizeof(float);

			glEnableVertexAttribArray(location);
		}
	}

	VertexArray::~VertexArray()
	{
		glDeleteVertexArrays(1, &m_id);
	}

}
