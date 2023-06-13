#pragma once
#include "Simulation.h"

class ConstantVelocityApplication : public Simulation
{
public:

	ConstantVelocityApplication(); 
	void Solve() override; 
};

