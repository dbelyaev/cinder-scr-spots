#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <cinder/gl/gl.h>

#include <glm/glm.hpp> // vec2

using glm::vec2;

class Particle
{
public:
	Particle();
	~Particle();

public:
	virtual void update();
	virtual void draw();

	void init();

private:
	vec2 mPos;
	vec2 mDir;

	float mVel;
	float mRadius;
	float mLife;
	float mMaxLife;

	bool mAchievedMax;

	double mPrevTime;

	float mColor;
};

#endif // PARTICLE_H_