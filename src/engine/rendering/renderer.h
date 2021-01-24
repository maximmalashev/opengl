#pragma once
#include "mesh.h"

namespace engine {

	class Renderer 
	{
	public:
		static void SetBackgroundColor(float red, float green, float blue);
		static void DrawMesh(Mesh* mesh);
		static void Clear();
	private:
	};

}