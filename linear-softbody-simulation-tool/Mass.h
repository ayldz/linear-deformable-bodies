#pragma once

#include "Lsst.h"

class Mass
{
public:

	float m_m;
	glm::vec3 m_pos;
	glm::vec3 m_vel;
	glm::vec3 m_force;

	Mass(float m) : m_m(m)
	{
		m_pos = glm::vec3(0.0f, 0.0f, 0.0f);
		m_vel = glm::vec3(0.0f, 0.0f, 0.0f);
		m_force = glm::vec3(0.0f, 0.0f, 0.0f);
	}

	void Init()
	{
		m_force = glm::vec3(0);
	}

	void ApplyForce(glm::vec3 force)
	{
		this->m_force += force;
	}

	void Simulate(float dt)
	{
		m_vel += (m_force / m_m) * dt;
		m_pos += m_vel * dt;
	}
};



