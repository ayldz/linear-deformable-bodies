#pragma once
#include "Simulation.h"

class ConstantVelocityApplication : public Simulation
{
public:


	ConstantVelocityApplication() : Simulation(1, 1.0f)
	{
		m_masses[0]->m_pos = glm::vec3(-10.0f, 0.0f, 0.0f);
		m_masses[0]->m_vel = glm::vec3(1.0f, 0.0f, 0.0f);
	}

	void Solve() override { m_masses[0]->ApplyForce(glm::vec3(0.5f, 0.0f, 0.0f)); }
};

