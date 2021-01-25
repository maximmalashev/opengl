#pragma once

#include <glm/glm.hpp>

#include "../rendering/mesh.h"

namespace engine {

	class Entity
	{
	public:
		struct Transform
		{
			glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
			glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 0.0f);
			glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f);

			glm::mat4x4 GetTransformationMatrix();
		};

		Entity();
		~Entity();

		inline Mesh* GetMesh() { return m_mesh; }
		inline void SetMesh(Mesh* mesh) { m_mesh = mesh; }

		inline Transform* GetTransform() { return &m_transform; }
	private:
		Mesh* m_mesh = nullptr;
		Transform m_transform;
	};

	

}