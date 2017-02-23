#include "particle.h"

#include <cinder/app/AppScreenSaver.h>
#include <cinder/Rand.h>
#include <cinder/gl/gl.h>


using namespace ci;
using namespace ci::app;


Particle::Particle()
	: mPrevTime(0)
{
	init();

	// particle will be initialized with empty life
	// by logic purposes on re-init, but for the first
	// time it must look like it existed before start
	mLife = Rand::randFloat(0.f, mMaxLife);
}

Particle::~Particle()
{
}

void
Particle::update()
{
	// calculate new position using time (no based on CPU cycles)
	double dt = getElapsedSeconds() - mPrevTime;
	mPos += (mDir * mVel) * (float) (dt);

	// particle first goes to highest brightness possible
	// then when it is achieved fade out and dies to be reborn
	if (mAchievedMax)
		mLife -= (float) dt *.5f;
	else
		mLife += (float) dt *.5f;

	if (mLife >= mMaxLife)
		mAchievedMax = true;

	// reset, if particle went out of borders
	Area window = app::getWindowBounds();
	if (mLife <= 0 || !window.contains(mPos))
		init();

	mPrevTime += dt;
}

void
Particle::draw()
{
	gl::color(ColorA(CM_HSV, mColor, 1.f, mLife));
	gl::enableAlphaBlending();
	gl::drawSolidCircle(mPos, mRadius, 10);
}

void
Particle::init()
{
	mMaxLife = 1.f;
	mLife = 0.f;
	mAchievedMax = false;

	mRadius = Rand::randFloat(5.f, getWindowHeight()*.01f);
	mPos = vec2(Rand::randFloat(mRadius, app::getWindowWidth() - mRadius), Rand::randFloat(mRadius, app::getWindowHeight() - mRadius));

	mDir = Rand::randVec2();
	mVel = Rand::randFloat(100.f / mRadius, 300.f / mRadius);

	mColor = Rand::randFloat();
}