#pragma once

#include <glm/glm.hpp>

namespace engine {

	enum class ShaderType { VERTEX, FRAGMENT };

	class Shader
	{
	public:
		~Shader();

		static Shader* CompileFromString(const char* vertex, const char* fragment);
		static Shader* CompileFromFile(const char* path);

		void Use();

		void SetFloat(const char* name, float value);
		void SetFloat2(const char* name, glm::vec2 value);
		void SetFloat3(const char* name, glm::vec3 value);
		void SetFloat4(const char* name, glm::vec4 value);
		void SetMatrix4x4(const char* name, glm::mat4x4 value);

	private:
		Shader(unsigned int vertexId, unsigned int fragmentId);

		static void CheckCompilation(unsigned int id, ShaderType type);

		unsigned int m_id;
	};

}
