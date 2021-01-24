#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

namespace engine {

	class Application 
	{
	public:
		bool InitializeWindow(int width, int height, std::string title);
		void Start();
	private:
		GLFWwindow* m_window;
	};

}