#include "renderer.h"

#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>

namespace engine {
	glm::mat4x4 Renderer::m_projection;
	glm::mat4x4 Renderer::m_view;

	void Renderer::SetBackgroundColor(float red, float green, float blue)
	{
		glClearColor(red, green, blue, 1.0f);
	}

	void Renderer::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Renderer::Draw(VertexArray* vao, Shader* shader, Texture* texture, glm::mat4x4 model)
	{
		vao->Bind();
		shader->Use();
		texture->Bind();

		shader->SetMatrix4x4("model", model);
		shader->SetMatrix4x4("projection", m_projection);
		shader->SetMatrix4x4("view", m_view);

		glDrawElements(GL_TRIANGLES, vao->GetIBO()->GetCount(), GL_UNSIGNED_INT, nullptr);
	}

}

