#pragma once

#include "Lsst.h"

#include <imgui.h>

class EditorImGui 
{
public:
	bool isActive = true;
public:
	void Init(GLFWwindow* window, const char* glsl_version);
	void NewFrame();
	virtual void Update();
	void Render();
	void Shutdown();

private:

	//attributes;
	float m							= 0;
	int numOfMasses					= 0;
	float springConstant			= 0;
	float springLength				= 0;
	float springFrictionConstant	= 0;
	glm::vec3 gravitation			= glm::vec3(0);
	float airFrictionConstant		= 0;
	float groundRepulsionConstant	= 0;
	float groundFrictionConstant	= 0;
	float groundAbsorptionConstant	= 0;
	float groundHeight				= 0;
};