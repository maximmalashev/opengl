#include "application.h"

#include <iostream>
#include <vector>
#include <glm/glm.hpp>

#include "../rendering/buffers/vao.h"
#include "../rendering/buffers/vbo.h"
#include "../rendering/buffers/ibo.h"
#include "../rendering/shader.h"
#include "../rendering/mesh.h"
#include "../rendering/renderer.h"

namespace engine {

	bool Application::InitializeWindow(int width, int height, std::string title)
	{
		if (!glfwInit())
		{
			std::cout << "GLFW initialization error." << std::endl;
			return false;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);


		m_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
		if (!m_window)
		{
			std::cout << "GLFW window error." << std::endl;
			glfwTerminate();
			return false;
		}

		glfwMakeContextCurrent(m_window);
		glViewport(0, 0, width, height);

		if (!glewInit())
		{
			std::cout << "" << std::endl;
		}

		return true;
	}

	void Application::Start()
	{
		float vertices[] = {
			 0.5f,  0.5f, 0.0f,  1.0f,  1.0f,  
			 0.5f, -0.5f, 0.0f,  1.0f,  0.0f,
			-0.5f, -0.5f, 0.0f,  0.0f,  0.0f,
			-0.5f,  0.5f, 0.0f,  0.0f,  1.0f
		};

		unsigned int indices[] = {  
			0, 1, 3,   
			1, 2, 3    
		};

		/* Texture */
		Texture* texture = new Texture("res/textures/wood.jpeg");

		/* Vertex Buffer */
		std::vector<int> layout;
		layout.push_back(3);
		layout.push_back(2);

		VertexBuffer* vbo = new VertexBuffer(vertices, sizeof(vertices), layout);

		/* Index Buffer */
		IndexBuffer* ibo = new IndexBuffer(indices, sizeof(indices), 6);

		/* Shader */
		Shader* shader = Shader::CompileFromFile("res/shaders/standard.shader");

		/* Vertex Array */
		VertexArray* vao = new VertexArray();
		vao->AttachBuffers(*vbo, *ibo);

		Renderer::SetBackgroundColor(0.0f, 0.0f, 0.0f);

		Mesh* mesh = new Mesh(vao, shader);

		Entity* entity = new Entity();
		entity->SetMesh(mesh);
		entity->GetTransform()->position.x = .5f;
		entity->GetTransform()->scale.x = .5f;
		entity->GetTransform()->scale.y = .5f;

		while (!glfwWindowShouldClose(m_window))
		{
			Renderer::Clear();
			Renderer::DrawEntity(entity, texture);

			glfwSwapBuffers(m_window);
			glfwPollEvents();
		}

		glfwTerminate();
	}

}