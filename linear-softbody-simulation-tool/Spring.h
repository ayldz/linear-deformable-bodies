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

	Spring(Mass* mass1, Mass* mass2, float springConstant, float springLength, float frictionConstant);
	
	void Solve();
};

