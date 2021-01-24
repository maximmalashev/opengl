#include "renderer.h"

#include <GL/glew.h>

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

	void Renderer::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

}

