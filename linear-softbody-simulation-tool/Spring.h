#pragma once
#include "Mass.h"

class Spring
{
public:
	Mass* m_mass1;
	Mass* m_mass2;

	float m_springConstant;
	float m_springLength;
	float m_frictionConstant;

	Spring(Mass* mass1, Mass* mass2, float springConstant, float springLength, float frictionConstant)
	{
		this->m_springConstant = springConstant;
		this->m_springLength = springLength;
		this->m_frictionConstant = frictionConstant;
		
		this->m_mass1 = mass1;
		this->m_mass2 = mass2;

	}

	void Solve()
	{
		glm::vec3 springVector = m_mass1->m_pos - m_mass2->m_pos; // vector between two masses

		float r = springVector.length(); // distance between two masses

		glm::vec3 force = glm::vec3(0.0f);

		if (r != 0)
		{
			force += -(springVector / r) * (r - m_springLength) * m_springConstant;
		}

		force += -(m_mass1->m_vel - m_mass2->m_vel) * m_frictionConstant;

		m_mass1->ApplyForce(force);
		m_mass2->ApplyForce(-force);
	}

};

