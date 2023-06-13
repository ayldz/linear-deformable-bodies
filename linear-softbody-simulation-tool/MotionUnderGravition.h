#pragma once
#include "Lsst.h"
#include "Simulation.h"

class MotionUnderGravition :public Simulation
{
public:
	glm::vec3 m_gravitation = glm::vec3(0);

	MotionUnderGravition(glm::vec3 gravitation);

	void Solve() override;
};

