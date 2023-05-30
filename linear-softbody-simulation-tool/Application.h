#pragma once

#include "Window.h"
#include "Renderer.h"

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