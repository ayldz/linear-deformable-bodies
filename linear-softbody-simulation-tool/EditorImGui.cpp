#include "EditorImGui.h"

void EditorImGui::Init(GLFWwindow* window, const char* glsl_version)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();

	ImGuiIO& io = ImGui::GetIO();

	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init(glsl_version);

	ImGui::StyleColorsLight();
}

void EditorImGui::NewFrame() 
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}


void EditorImGui::Update()
{	
	ImGuiWindowFlags flags = ImGuiWindowFlags_NoResize;					      

	ImGui::SetNextWindowPos(ImVec2(0,0));
	ImGui::SetNextWindowSize(ImVec2(600, 215));
	ImGui::Begin("Properties", &this->isActive, flags);
	
	ImGui::SliderFloat("Spring Constant", &springConstant, 0.0f, 1.0f);
	ImGui::SliderFloat("Spring Friction Constant", &springFrictionConstant, 0.0f, 1.0f);
	ImGui::SliderFloat("Spring Length", &springLength, 0.0f, 1.0f);
	ImGui::SliderFloat("Ground Repulsion Constant", &groundRepulsionConstant, 0.0f, 1.0f);
	ImGui::SliderFloat("Ground Friction Constant", &groundFrictionConstant, 0.0f, 1.0f);
	ImGui::SliderFloat("Ground Absorption Constant", &groundAbsorptionConstant, 0.0f, 1.0f);
	ImGui::SliderFloat("Air Friction Constant", &airFrictionConstant, 0.0f, 1.0f);

	if (ImGui::Button("Apply Configuration"))
	{
		
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
