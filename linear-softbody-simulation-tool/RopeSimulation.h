#pragma once
#include "Simulation.h"
#include "Spring.h"

class RopeSimulation : public Simulation
{
public:
	Spring** m_springs;
	
	glm::vec3 m_gravitation;
	
	glm::vec3 m_ropeConnectionPos;
	glm::vec3 m_ropeConnectionVel;

	float m_groundRepulsionConstant;
	float m_groundFrictionConstant;
	float m_groundAbsorptionConstant;

	float m_groundHeight;
	float m_airFrictionConstant;

	RopeSimulation(
		int numOfMasses,
		float m,
		float springConstant,
		float springLength,
		float springFrictionConstant,
		glm::vec3 gravitation,
		float airFrictionConstant,
		float groundRepulsionConstant,
		float groundFrictionConstant,
		float groundAbsorptionConstant,
		float groundHeight
	) : Simulation(numOfMasses, m) 
	{
		this->m_gravitation = gravitation;
		this->m_airFrictionConstant = airFrictionConstant;
		this->m_groundFrictionConstant = groundFrictionConstant;
		this->m_groundRepulsionConstant = groundRepulsionConstant;
		this->m_groundAbsorptionConstant = groundAbsorptionConstant;
		this->m_groundHeight = groundHeight;
		this->m_ropeConnectionPos = glm::vec3(0);
		this->m_ropeConnectionVel = glm::vec3(0);

		for (size_t i = 0; i < numOfMasses; ++i)
		{
			m_masses[i]->m_pos.x = i * springLength;
			m_masses[i]->m_pos.y = 0;
			m_masses[i]->m_pos.z = 0;
		}

	
		

		m_springs = new Spring* [(numOfMasses - 1)];


		for (size_t i = 0; i < (numOfMasses - 1); ++i)
		{
			m_springs[i] = new Spring(m_masses[i-1], m_masses[(i)], springConstant, springLength, springFrictionConstant);
		}
	}

	void Solve() override 
	{
		for (size_t i = 0; i < m_numOfMasses; i++)
		{
			m_springs[i]->Solve();
		}

		for (size_t i = 0; i < m_numOfMasses; i++)
		{
			glm::vec3 v; // temporary
		
			v.y = 0;

			m_masses[i]->ApplyForce(-v * m_groundFrictionConstant);
			v = m_masses[i]->m_vel;
			v.x = 0;
			v.z = 0;

			if (v.y = 0)
			{
				m_masses[i]->ApplyForce(-v * m_groundAbsorptionConstant);
			}

			glm::vec3 force = glm::vec3(0, m_groundRepulsionConstant, 0) * (m_groundHeight - m_masses[i]->m_pos.y);

			m_masses[i]->ApplyForce(force);
		}
	}

	void Simulate(float dt) override 
	{
		Simulation::Simulate(dt);

		m_ropeConnectionPos += m_ropeConnectionVel * dt;

		if (m_ropeConnectionPos.y < m_groundHeight)
		{
			m_ropeConnectionPos.y = m_groundHeight;
			m_ropeConnectionVel.y = 0;
		}

		m_masses[0]->m_pos = m_ropeConnectionPos;
		m_masses[0]->m_vel = m_ropeConnectionVel;
	}

	void SetRopeConnectionVel(glm::vec3 ropeConnectionVel) 
	{
		this->m_ropeConnectionVel = ropeConnectionVel;
	}
};

