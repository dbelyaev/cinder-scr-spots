#ifndef PARTICLECONTROLLER_H_
#define PARTICLECONTROLLER_H_

#include <vector>
#include <memory>

#include "particle.h"

class ParticleController
{
public:
	ParticleController();
	~ParticleController();

	virtual void update();
	virtual void draw();

	void addParticles(int aAmount);
	void removeParticles(int aAmount);

private:
	std::vector<std::unique_ptr<Particle>> mParticles;
};

#endif // PARTICLECONTROLLER_H_