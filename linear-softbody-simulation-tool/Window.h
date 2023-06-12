#pragma once

#include "Lsst.h"
#include "Input.h"


class Window 
{
	friend class Application;

public:
	Window(int, int, const std::string&);
	~Window();

	void Init();
	void Update();
	void UpdateWindowSize(int, int);

public:
	bool IsClosed;

private:
	GLFWwindow* m_window;

	int m_width, m_height;
	std::string m_title;
};