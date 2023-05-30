#include "Input.h"

Input& Input::Instance()
{
	static Input* instance = new Input;
	return *instance;
}

void Input::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS)
	{
		Instance().m_keyPressed[key] = true;
	}

	else if (action == GLFW_RELEASE) 
	{
		Instance().m_keyPressed[key] = false;
	}
}

void Input::CursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
{
	Instance().m_lastX = Instance().m_posX;
	Instance().m_lastY = Instance().m_posY;
	Instance().m_posX = xpos;
	Instance().m_posY = ypos;
}

void Input::MouseButtonCallback(GLFWwindow* window, int button, int action, int mod)
{
	if (action == GLFW_PRESS)
	{
		Instance().m_mouseButtonPressed[button] = true;
	}
	else
	{
		Instance().m_mouseButtonPressed[button] = false;
	}
}

bool Input::GetMouseButton(uint8_t button) 
{
	return Instance().m_mouseButtonPressed[button];
}

bool Input::GetButton(uint16_t key)
{
	return Instance().m_keyPressed[key];
}

double Input::GetMousePosX() 
{
	return Instance().m_posX;
}

double Input::GetMousePosY()
{
	return Instance().m_posY;
}