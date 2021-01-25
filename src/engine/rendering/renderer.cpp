#include "renderer.h"

#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>

namespace engine {
	void Renderer::SetBackgroundColor(float red, float green, float blue)
	{
		glClearColor(red, green, blue, 1.0f);
	}

	void Renderer::DrawMesh(Mesh* mesh)
	{
		mesh->GetShader()->Use();
		mesh->GetVAO()->Bind();

		glDrawElements(GL_TRIANGLES, mesh->GetVAO()->GetIBO()->GetCount(), GL_UNSIGNED_INT, nullptr);
	}

	void Renderer::DrawMesh(Mesh* mesh, Texture* texture)
	{
		texture->Bind();
		DrawMesh(mesh);
	}

	void Renderer::DrawEntity(Entity* entity, Texture* texture)
	{
		texture->Bind();

		entity->GetMesh()->GetShader()->Use();
		entity->GetMesh()->GetVAO()->Bind();

		entity->GetMesh()->GetShader()->SetMatrix4x4("transformation", entity->GetTransform()->GetTransformationMatrix());

		glDrawElements(GL_TRIANGLES, entity->GetMesh()->GetVAO()->GetIBO()->GetCount(), GL_UNSIGNED_INT, nullptr);
	}

	void Renderer::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

}

