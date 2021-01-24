#pragma once
#include "mesh.h"
#include "texture.h"

namespace engine {

	class Renderer 
	{
	public:
		static void SetBackgroundColor(float red, float green, float blue);
		static void DrawMesh(Mesh* mesh);
		static void DrawMesh(Mesh* mesh, Texture* texture);
		static void Clear();
	private:
	};

}