#include "Spring.h"

Spring::Spring(Mass* mass1, Mass* mass2, float springConstant, float springLength, float frictionConstant)
{
	this->m_springConstant = springConstant;
	this->m_springLength = springLength;
	this->m_frictionConstant = frictionConstant;

	this->m_mass1 = mass1;
	this->m_mass2 = mass2;

}

void Spring::Solve()
{
	glm::vec3 springVector = (m_mass1->m_pos) - (m_mass2->m_pos); // vector between two masses

	constexpr float r = springVector.length(); // distance between two masses

	glm::vec3 force = glm::vec3(0.0f);

	if (r != 0)
	{
		force += -(springVector / r) * (r - m_springLength) * m_springConstant;
	}

	force += -(m_mass1->m_vel - m_mass2->m_vel) * m_frictionConstant;

	m_mass1->ApplyForce(force);
	m_mass2->ApplyForce(-force);
}