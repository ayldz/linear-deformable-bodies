#pragma once

#include "Window.h"
#include "Renderer.h"
#include "EditorImGui.h"
#include "Lsst.h"
#include "ConstantVelocityApplication.h"
#include "MotionUnderGravition.h"
#include "MassConnectedWithSpring.h"
#include "RopeSimulation.h"

class Application 
{
public:
	void Init();
	void Run();
	void Start();
	void Update(float);
	void Render();
	void Quit();

private:
	Window* m_window = nullptr;


//make singleton
public:
	static Application& Instance();
private:
	Application() = default;
	Application(const Application&) = delete;
	void operator=(const Application&) = delete;
};