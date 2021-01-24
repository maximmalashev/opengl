#pragma once

#include "vbo.h"
#include "ibo.h"

namespace engine {

	class VertexArray 
	{
	public:
		VertexArray();
		~VertexArray();

		void Bind();
		void Unbind();
		void AttachBuffers(VertexBuffer &vbo, IndexBuffer& ibo);

		inline unsigned int GetId() { return m_id; }
		inline VertexBuffer* GetVBO() { return m_vbo; }
		inline IndexBuffer* GetIBO() { return m_ibo; }
	private:
		unsigned int m_id;
		VertexBuffer* m_vbo;
		IndexBuffer* m_ibo;
	};

}