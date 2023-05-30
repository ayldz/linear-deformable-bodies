#include "Window.h"

Window::Window(int width = 1024, int height = 768, const std::string& title = "LSST")
	: m_width(width), m_height(height), m_title(title), IsClosed(false)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

}

Window::~Window()
{
	glfwTerminate();
}

void Window::Init()
{
	m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);
	glfwMakeContextCurrent(m_window);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	glViewport(0, 0, m_width, m_height);

	glfwSetCursorPosCallback(m_window, Input::CursorPositionCallback);
	glfwSetMouseButtonCallback(m_window, Input::MouseButtonCallback);
	glfwSetKeyCallback(m_window, Input::KeyCallback);

	glfwSetWindowUserPointer(m_window, this);
	glfwSetFramebufferSizeCallback(m_window, [](GLFWwindow* glfw_Window, int width, int height) {
			Window* window = (Window*)glfwGetWindowUserPointer(glfw_Window);
			window->UpdateWindowSize(width, height);
		});
}

void Window::Update()
{


	glfwSwapBuffers(m_window);
	glfwPollEvents();

	this->IsClosed = glfwWindowShouldClose(m_window);
}

void Window::UpdateWindowSize(int width, int height)
{
	this->m_width = width;
	this->m_height = height;
	glViewport(0, 0, width, height);
}