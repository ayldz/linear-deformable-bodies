#pragma once
#include "Lsst.h"
#include "Simulation.h"

class MotionUnderGravition :public Simulation
{
public:
	glm::vec3 m_gravitation = glm::vec3(0);

	MotionUnderGravition(glm::vec3 gravitation) : Simulation(1, 1.0f)
	{
		this->m_gravitation = gravitation;
		m_masses[0]->m_pos = glm::vec3(-10.0f, 5.0f, 0.0f);
		m_masses[0]->m_vel = glm::vec3(10.0f, 0.0f, 0.0f);
	}

	void Solve() override 
	{
		for (size_t i = 0; i < m_numOfMasses; i++)
		{
			m_masses[i]->ApplyForce(m_gravitation * m_masses[i]->m_m);
		}
	}
};

