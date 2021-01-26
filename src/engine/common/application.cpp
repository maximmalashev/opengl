#include "application.h"

#include <iostream>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../rendering/buffers/vao.h"
#include "../rendering/buffers/vbo.h"
#include "../rendering/buffers/ibo.h"
#include "../rendering/shader.h"
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

		/* Transformation matrix */
		glm::mat4x4 transform = glm::mat4x4(1.0f);
		transform = glm::translate(transform, glm::vec3(300.0f, 300.0f, 0.0f));
		transform = glm::scale(transform, glm::vec3(100.0f, 100.0f, 1.0f));

		/* Projection matrix */
		Renderer::SetProjection(glm::ortho(0.0f, 720.0f, 0.0f, 720.0f, 0.0f, 100.0f));

		/* View matrix */
		glm::mat4x4 view = glm::mat4x4(1.0f);
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, 0.0f));
		view = glm::scale(view, glm::vec3(1.0f, 1.0f, 1.0f));

		Renderer::SetView(view);

		/* Background colour */
		Renderer::SetBackgroundColor(0.0f, 0.0f, 0.0f);
		
		while (!glfwWindowShouldClose(m_window))
		{
			Renderer::Clear();
			Renderer::Draw(vao, shader, texture, transform);

			glfwSwapBuffers(m_window);
			glfwPollEvents();
		}

		glfwTerminate();
	}

}