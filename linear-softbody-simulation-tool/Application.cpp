#include "Application.h"

Application& Application::Instance()
{
	static Application instance;
	return instance;
}


void Application::Init()
{
	m_window = new Window(1024, 1024 / 16 * 9, "Linear Soft Body Simulation");
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

//static EditorImGui editor;

RopeSimulation* sim = new RopeSimulation(
	80,                            
	0.05f,                         
	10000.0f,                        
	0.05f,                           
	0.2f,                            
	glm::vec3(0, -9.81f, 0),          
	0.02f,                           
	100.0f,                          
	0.2f,                            
	2.0f,                            
	-1.5f);

void Application::Start()
{
	Shader shader;
	shader.Compile("shaders/shader3d.vert", "shaders/shader3d.frag", nullptr);
	renderer = new Renderer(shader);
	//editor.Init(m_window->m_window, "#version 130");

}



void Application::Update(float dt)
{
	if (Input::GetButton(GLFW_KEY_ESCAPE))
	{
		m_window->IsClosed = true;
	}
	m_window->Update();


	sim->Operate(dt);

	for (size_t i = 0; i < sim->m_numOfMasses; i++)
	{
		std::cout << i + ". " << sim->m_masses[0]->m_pos.x << std::endl;

	}

	//editor.NewFrame();
	//editor.Update();

}


void Application::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.8f, 0.5f, 0.5f, 1.0f);


	for (size_t i = 0; i < sim->m_numOfMasses; i++)
	{
		renderer->Draw(sim->m_masses[i]->m_pos, glm::vec2(1.0, 1), 45.0f * (float)glfwGetTime(), glm::vec3(0.8f, 0.8f, 0.1f));
	}

	//ImGui::ShowDemoWindow();
	//editor.Render();
}

void Application::Quit()
{
	sim->Release();
	delete sim;
	sim = nullptr;
	//editor.Shutdown();
	delete renderer;
	renderer = nullptr;
}