#pragma once

#include "Lsst.h"

class Input
{
public:
	static double GetMousePosX();
	static double GetMousePosY();
	static bool GetButton(uint16_t);
	static bool GetMouseButton(uint8_t);

	static void CursorPositionCallback(GLFWwindow*, double, double);
	static void MouseButtonCallback(GLFWwindow*, int, int, int);
	static void KeyCallback(GLFWwindow*, int, int, int, int);

private:
	double m_scrollX, m_scrollY;
	double m_posX, m_posY;
	double m_lastX, m_lastY;

	std::array<bool, 3> m_mouseButtonPressed{};
	std::array<bool, 350> m_keyPressed{};

//make singleton
public:
	static Input& Instance();
private:
	Input() = default;
	Input(const Input&) = delete;
	Input operator=(Input&) = delete;
};