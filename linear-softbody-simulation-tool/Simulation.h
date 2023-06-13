#pragma once
#include "Mass.h"
#include "Lsst.h"

class Simulation
{
public:
	int m_numOfMasses;
	std::vector<Mass*> m_masses{};

	Simulation(int numOfMasses, float m);


	virtual void Release();

	Mass* GetMass(int index);

	virtual void Init();

	virtual void Solve();

	virtual void Simulate(float dt);

	virtual void Operate(float dt);
};

