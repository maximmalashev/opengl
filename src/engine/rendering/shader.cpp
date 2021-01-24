#include "shader.h"

#include <gl/glew.h>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

namespace engine {

	Shader::Shader(unsigned int vertexId, unsigned int fragmentId)
	{
		m_id = glCreateProgram();

		glAttachShader(m_id, vertexId);
		glAttachShader(m_id, fragmentId);

		glLinkProgram(m_id);

		int success;
		char infoLog[512];

		glGetProgramiv(m_id, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(m_id, 512, NULL, infoLog);
			std::cout << "ERROR: shader failed to link: " << infoLog << std::endl;
			std::exit(-1);
		}

		glDeleteShader(vertexId);
		glDeleteShader(fragmentId);
	}

	void Shader::CheckCompilation(unsigned int id, ShaderType type)
	{
		int success;
		char infoLog[512];
		const char* typeStr = "error";

		switch (type)
		{
			case ShaderType::VERTEX:
				typeStr = "vertex";
				break;

			case ShaderType::FRAGMENT:
				typeStr = "fragment";
				break;
		}

		glGetShaderiv(id, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(id, 512, nullptr, infoLog);
			std::cout << "ERROR: " << typeStr << " shader failed to compile: " << infoLog << std::endl;
			std::exit(-1);
		}
	}

	Shader* Shader::CompileFromString(const char* vertex, const char* fragment)
	{
		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertex, nullptr);
		glCompileShader(vertexShader);
		CheckCompilation(vertexShader, ShaderType::VERTEX);

		unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragment, nullptr);
		glCompileShader(fragmentShader);
		CheckCompilation(fragmentShader, ShaderType::FRAGMENT);

		return new Shader(vertexShader, fragmentShader);
	}

	Shader* Shader::CompileFromFile(const char* path)
	{
		std::ifstream file(path);

		std::stringstream vertex;
		std::stringstream fragment;

		std::stringstream* current = nullptr;

		std::string line;
		while (std::getline(file, line))
		{
			if (line.rfind("@VERTEX", 0) == 0) current = &vertex;
			else if (line.rfind("@FRAGMENT", 0) == 0) current = &fragment;
			else *current << line << std::endl;
		}

		return CompileFromString(vertex.str().c_str(), fragment.str().c_str());
	}

	void Shader::Use()
	{
		glUseProgram(m_id);
	}

	void Shader::SetFloat(const char* name, float value)
	{
		Use();
		int location = glGetUniformLocation(m_id, name);
		glUniform1f(location, value);
	}

	void Shader::SetFloat2(const char* name, glm::vec2 value)
	{
		Use();
		int location = glGetUniformLocation(m_id, name);
		glUniform2f(location, value.x, value.y);
	}

	void Shader::SetFloat3(const char* name, glm::vec3 value)
	{
		Use();
		int location = glGetUniformLocation(m_id, name);
		glUniform3f(location, value.x, value.y, value.z);
	}

	void Shader::SetFloat4(const char* name, glm::vec4 value)
	{
		Use();
		int location = glGetUniformLocation(m_id, name);
		glUniform4f(location, value.x, value.y, value.z, value.w);
	}

	void Shader::SetMatrix4x4(const char* name, glm::mat4x4 value)
	{
		Use();
		int location = glGetUniformLocation(m_id, name);
		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
	}

	Shader::~Shader()
	{
		glDeleteProgram(m_id);
	}
}