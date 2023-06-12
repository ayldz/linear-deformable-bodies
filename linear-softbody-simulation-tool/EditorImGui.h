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
};