#pragma once

#include "buffers/vao.h"
#include "shader.h"

namespace engine {

	class Mesh
	{
	public:
		Mesh(VertexArray* vao, Shader* shader);
		~Mesh();

		inline VertexArray* GetVAO() { return m_vao; }
		inline Shader* GetShader() { return m_shader; }
		inline void SetVAO(VertexArray* vao) { m_vao = vao; }
		inline void SetShader(Shader* shader) { m_shader = shader; }

	private:
		VertexArray* m_vao;
		Shader* m_shader;
	};

}