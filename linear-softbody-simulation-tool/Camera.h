#pragma once


#include "Lsst.h"

class Camera
{
public:
	Camera();
	~Camera() = default;

	inline glm::mat4 GetProjectionMatrix() { return m_projection; }
	inline glm::mat4 GetViewMatrix() { return m_view; }
	inline glm::vec3 GetPosition() { return m_position; }
	inline glm::vec3 GetRotation() { return m_rotation; }

	glm::mat4 GetViewProjectionMatrix();

	void SetProjection(float, float);
	void SetPosition(glm::vec3);
	void SetRotation(glm::vec3);
	void Move(glm::vec3);
	void Rotate(glm::vec3);

protected:
	void CalculateViewMatrix();

	glm::vec3 m_position = { 0,0,0 };
	glm::vec3 m_rotation = { 0,0,0 };
	glm::mat4 m_projection;
	glm::mat4 m_view;
};