#include "MassConnectedWithSpring.h"

MassConnectedWithSpring::MassConnectedWithSpring(float springConstant) : Simulation(1, 1.0f)
{
	this->m_springConstant = springConstant;
	m_connectionPos = glm::vec3(0.0f, 0.0f, 0.0f);

	m_masses[0]->m_pos = m_connectionPos + glm::vec3(10.0f, -5.0f, 0.0f);
	m_masses[0]->m_vel = glm::vec3(0.0f, 0.0f, 0.0f);
}

void MassConnectedWithSpring::Solve()
{
	for (size_t i = 0; i < m_numOfMasses; i++)
	{
		glm::vec3 springVector = m_masses[0]->m_pos - m_connectionPos;
		m_masses[0]->ApplyForce(-springVector * m_springConstant);
	}
}