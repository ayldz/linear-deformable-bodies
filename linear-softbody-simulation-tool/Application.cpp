#include "Application.h"

Application& Application::Instance()
{
	static Application instance;
	return instance;
}

void Application::Init() 
{
	m_window = new Window(1024, 768, "Linear Soft Body Simulation");
	m_window->Init();
}

void Application::Run() 
{
	float lastTime = (float)glfwGetTime();

	this->Start();

	while (!m_window->IsClosed)
	{
		float current = (float)glfwGetTime();
		float deltaTime = current - lastTime;

		this->Update(deltaTime);
		this->Render();

		lastTime = current;
	}

	this->Quit();
}

static Renderer* renderer;

void Application::Start() 
{
	Shader shader;
	shader.Compile("shaders/shader.vert", "shaders/shader.frag", nullptr);
	renderer = new Renderer(shader);
}


void Application::Update(float dt) 
{
	if (Input::GetButton(GLFW_KEY_ESCAPE))
	{
		m_window->IsClosed = true;
	}

	m_window->Update();
}

void Application::Render() 
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.8f, 0.5f, 0.5f, 1.0f);

	renderer->Draw(glm::vec2(512.0 - 50, 384.0 - 50), glm::vec2(100.0, 100.0), 45.0f * (float)glfwGetTime() * -5, glm::vec3(0.8f, 0.8f, 0.1f));
	renderer->Draw(glm::vec2(50, 50), glm::vec2(100.0, 100.0), 45.0f * (float)glfwGetTime() * 5, glm::vec3(0.0f, 0.8f, 0.2f));

}

void Application::Quit() 
{

}