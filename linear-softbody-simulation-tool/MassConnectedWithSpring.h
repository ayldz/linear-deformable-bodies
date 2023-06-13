#pragma once
#include "Lsst.h"
#include "Simulation.h"

class MassConnectedWithSpring : public Simulation
{
public:

	float m_springConstant;
	glm::vec3 m_connectionPos;

	MassConnectedWithSpring(float springConstant);

	void Solve() override;
};

