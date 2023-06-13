#include "Application.h"


std::vector<float> vertices =
{
	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
	 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
	-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
};

std::vector<float> ground_vertices =
{
	 0.5f, 0.0f,  0.5f, 0.0f, 1.0f,
	 0.5f, 0.0f, -0.5f, 0.0f, 1.0f,
	-0.5f, 0.0f,  0.5f, 0.0f, 1.0f,

	 0.5f, 0.0f, -0.5f, 0.0f, 1.0f,
	-0.5f, 0.0f, -0.5f, 0.0f, 1.0f,
	-0.5f, 0.0f,  0.5f, 0.0f, 1.0f
};


Application& Application::Instance()
{
	static Application instance;
	return instance;
}


void Application::Init()
{
	m_window = new Window(1024, 1024 / 16 * 9, "Linear Soft Body Simulation Demo");
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
static GroundRenderer* ground_renderer;

//static EditorImGui editor;

static RopeSimulation* sim = new RopeSimulation(
	80,
	0.05f,
	1000.0f,
	0.05f,
	0.2f,
	glm::vec3(0, -9.81f, 0),
	5.0f,
	1.0f,
	5.f,
	10.0f,
	-8.0f);

void Application::Start()
{
	Shader shader;
	shader.Compile("shaders/shader3d.vert", "shaders/shader3d.frag", nullptr);
	renderer = new Renderer(shader, vertices);
	ground_renderer = new GroundRenderer(shader, ground_vertices);

	//editor.Init(m_window->m_window, "#version 130");

	for (size_t i = 0; i < sim->m_masses.size(); i++)
	{
		std::cout << sim->m_masses[i]->m_pos.x << std::endl;
	}
}

void Application::Update(float dt)
{
	if (Input::GetButton(GLFW_KEY_ESCAPE))
	{
		m_window->IsClosed = true;
	}
	else if (Input::GetButton(GLFW_KEY_PAGE_UP))
	{
		sim->SetRopeConnectionVel(glm::vec3(0.0f, 5.0f, 0.0f));
	}
	else if (Input::GetButton(GLFW_KEY_PAGE_DOWN))
	{
		sim->SetRopeConnectionVel(glm::vec3(0.0f, -5.0f, 0.0f));
	}
	else if (Input::GetButton(GLFW_KEY_UP))
	{
		sim->SetRopeConnectionVel(glm::vec3(0.0f, 0.0f, -5.0f));
	}
	else if (Input::GetButton(GLFW_KEY_RIGHT))
	{
		sim->SetRopeConnectionVel(glm::vec3(5.0f, 0.0f, 0.0f));
	}
	else if (Input::GetButton(GLFW_KEY_DOWN))
	{
		sim->SetRopeConnectionVel(glm::vec3(0.0f, 0.0f, 5.0f));
	}
	else if (Input::GetButton(GLFW_KEY_LEFT))
	{
		sim->SetRopeConnectionVel(glm::vec3(-5.0f, 0.0f, 0.0f));
	}
	else
	{
		sim->SetRopeConnectionVel(glm::vec3(0.0f, 0.0f, 0.0f));
	}

	m_window->Update();

	sim->Operate(dt);

	//editor.NewFrame();
	//editor.Update();
}


void Application::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.8f, 0.5f, 0.5f, 1.0f);

	for (size_t i = 0; i < sim->m_masses.size(); i++)
	{
		renderer->Draw(sim->m_masses[i]->m_pos, glm::vec3(0.5, 0.5, 0.5), 45.0f * (float)glfwGetTime(), glm::vec3(0.0f, i / 80.0f, 1.0f - (i / 80.0f)));
	}

	ground_renderer->Draw(glm::vec3(0.0f, -15.0f, 0.0f), glm::vec3(50, 1, 50), 0.0f, glm::vec3(0.7, 0.7, 0.7));

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