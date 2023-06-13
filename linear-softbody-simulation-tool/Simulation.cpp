#include "Simulation.h"

Simulation::Simulation(int numOfMasses, float m)
{
	this->m_numOfMasses = numOfMasses;


	for (size_t i = 0; i < m_numOfMasses; ++i)
	{
		m_masses.push_back(new Mass(m));
	}

}

void Simulation::Release()
{
	for (size_t i = 0; i < m_numOfMasses; i++)
	{
		delete m_masses[i];
		m_masses[i] = nullptr;
	}
}

Mass* Simulation::GetMass(int index)
{
	if (index < 0 || index >= m_numOfMasses)
	{
		return nullptr;
	}

	return m_masses[index];
}

void Simulation::Init()
{
	for (size_t i = 0; i < m_numOfMasses; i++)
	{
		m_masses[i]->Init();
	}
}

void Simulation::Solve() {};

void Simulation::Simulate(float dt)
{
	for (size_t i = 0; i < m_numOfMasses; i++)
	{
		m_masses[i]->Simulate(dt);
	}
}

void Simulation::Operate(float dt)
{
	Init();
	Solve();
	Simulate(dt);
}