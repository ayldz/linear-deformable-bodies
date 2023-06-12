#include "EditorImGui.h"

void EditorImGui::Init(GLFWwindow* window, const char* glsl_version)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();

	ImGuiIO& io = ImGui::GetIO();

	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init(glsl_version);

	ImGui::StyleColorsDark();
}

void EditorImGui::NewFrame() 
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void EditorImGui::Update()
{	
	ImGuiWindowFlags flags = ImGuiWindowFlags_MenuBar    |
						     ImGuiWindowFlags_NoTitleBar |
						     ImGuiWindowFlags_NoResize   |
						     ImGuiWindowFlags_NoMove; 

	ImGui::SetNextWindowPos(ImVec2(0,0));
	ImGui::SetNextWindowSize(ImVec2(1024, 1024/16*9));
	ImGui::Begin("Properties", &this->isActive, flags);
	
	if (ImGui::BeginMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Open..", "Ctrl+O")) { /* Do stuff */ }
			if (ImGui::MenuItem("Save", "Ctrl+S")) { /* Do stuff */ }
			if (ImGui::MenuItem("Close", "Ctrl+W")) { /* Do stuff */ }
			ImGui::EndMenu();
	
		}
		if (ImGui::BeginMenu("Edit"))
		{
			if (ImGui::MenuItem("Open..", "Ctrl+O")) { /* Do stuff */ }
			if (ImGui::MenuItem("Save", "Ctrl+S")) { /* Do stuff */ }
			if (ImGui::MenuItem("Close", "Ctrl+W")) { /* Do stuff */ }
			ImGui::EndMenu();

		}
		if (ImGui::BeginMenu("View"))
		{
			if (ImGui::MenuItem("Open..", "Ctrl+O")) { /* Do stuff */ }
			if (ImGui::MenuItem("Save", "Ctrl+S")) { /* Do stuff */ }
			if (ImGui::MenuItem("Close", "Ctrl+W")) { /* Do stuff */ }
			ImGui::EndMenu();

		}
		if (ImGui::BeginMenu("Help"))
		{
			if (ImGui::MenuItem("Open..", "Ctrl+O")) { /* Do stuff */ }
			if (ImGui::MenuItem("Save", "Ctrl+S")) { /* Do stuff */ }
			if (ImGui::MenuItem("Close", "Ctrl+W")) { /* Do stuff */ }
			ImGui::EndMenu();
		
		}

		ImGui::EndMenuBar();
	}

	ImGuiID propertiesId = 1;
	ImGui::BeginChildFrame(propertiesId, ImVec2(300,576));

	ImGui::EndChildFrame();

	ImGui::Text("Hello, Imgui!");
	
	if (ImGui::Button("Save"))
	{
		 std::cout << "Hello, ImGui" << std::endl;
	}
	
	ImGui::End();
}

void EditorImGui::Render()
{
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void EditorImGui::Shutdown()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}
