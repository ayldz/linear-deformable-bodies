#pragma once
#include "Simulation.h"
#include "Spring.h"
#include "Lsst.h"

class RopeSimulation : public Simulation
{
public:
	std::vector<Spring*> m_springs{};

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
	);

	void Solve() override;

	void Simulate(float dt) override;

	void SetRopeConnectionVel(glm::vec3 ropeConnectionVel);
};

