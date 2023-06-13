#pragma once

#include "Lsst.h"

class Mass
{
public:

	float m_m;
	glm::vec3 m_pos;
	glm::vec3 m_vel;
	glm::vec3 m_force;

	Mass(float m); 

	void Init();
	void ApplyForce(glm::vec3 force);

	void Simulate(float dt);
};



