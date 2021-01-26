#pragma once

#include <glm/glm.hpp>

#include "texture.h"
#include "buffers/vao.h"
#include "shader.h"

namespace engine {

	class Renderer 
	{
	public:
		static void SetBackgroundColor(float red, float green, float blue);
		static void Clear();

		static inline void SetProjection(glm::mat4x4 projection) { m_projection = projection; }
		static inline void SetView(glm::mat4x4 view) { m_view = view; }

		static void Draw(VertexArray* vao, Shader* shader, Texture* texture, glm::mat4x4 model);
	private:
		static glm::mat4x4 m_projection;
		static glm::mat4x4 m_view;
	};
}