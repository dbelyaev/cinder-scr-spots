#include "particlecontroller.h"


using namespace ci;


ParticleController::ParticleController()
{
}

ParticleController::~ParticleController()
{
}

void
ParticleController::update()
{
	for (auto const& particle : mParticles)
		particle->update();
}

void
ParticleController::draw()
{
	for (auto const& particle : mParticles)
		particle->draw();
}

void
ParticleController::addParticles(int aAmount)
{
	for (int i = 0; i < aAmount; i++)
		mParticles.emplace_back(new Particle);
}

void
ParticleController::removeParticles(int aAmount)
{
	for (int i = 0; i < aAmount; i++)
		mParticles.pop_back();
}