#include "entity.h"

#include <glm/gtc/matrix_transform.hpp>

namespace engine {

	Entity::Entity() 
	{
		m_transform = Transform();
	}

	Entity::~Entity() { }

	glm::mat4x4 Entity::Transform::GetTransformationMatrix()
	{
		glm::mat4x4 transformation = glm::mat4x4(1.0f);
		transformation = glm::translate(transformation, position);
		transformation = glm::rotate(transformation, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
		transformation = glm::rotate(transformation, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
		transformation = glm::rotate(transformation, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
		transformation = glm::scale(transformation, scale);

		return transformation;
	}
}


