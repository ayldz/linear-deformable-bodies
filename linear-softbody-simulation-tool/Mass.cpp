#include "Mass.h"


Mass::Mass(float m) : m_m(m)
{
	m_pos = glm::vec3(0.0f, 0.0f, 0.0f);
	m_vel = glm::vec3(0.0f, 0.0f, 0.0f);
	m_force = glm::vec3(0.0f, 0.0f, 0.0f);
}

void Mass::Init()
{
	m_force = glm::vec3(0);
}

void Mass::ApplyForce(glm::vec3 force)
{
	this->m_force += force;
}

void Mass::Simulate(float dt)
{
	m_vel += (m_force / m_m) * dt;
	m_pos += m_vel * dt;
}