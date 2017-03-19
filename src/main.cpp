#include <cinder/app/RendererGl.h>
#include <cinder/Rand.h>
#include <cinder/gl/gl.h>

#include "particlecontroller.h"

using namespace ci;
using namespace ci::app;

// in DEBUG mode run as normal app (Window)
// in RELEASE start as screen saver (full screen, exits on clicks\movement etc)
#ifdef  _DEBUG
#include "cinder/app/App.h"
class CinderApp : public App
#else
#include <cinder/app/AppScreenSaver.h>
class CinderApp : public AppScreenSaver
#endif // _DEBUG
{
public:
	void setup() override;
	void update() override;
	void draw() override;
	void resize() override;

private:
	ci::Color mColor, mBackgroundColor;
	ParticleController mParticleController;
};

void
CinderApp::setup()
{
	ci::app::getWindow()->setTitle("cinder-scr-spots");
	
	mBackgroundColor = Color(0, 0, 0);

	Rand::randSeed((int32_t) time(NULL));	// feed randomizer with seed

	mParticleController.addParticles(200);
}

void
CinderApp::update()
{
	mParticleController.update();
}

void
CinderApp::draw()
{
	gl::clear(mBackgroundColor);
	mParticleController.draw();
}

void
CinderApp::resize()
{
	// TODO
	// Not needed so much as screensaver starts in full screen
	// and no resize occurs during run, but great to have for 
	// 'DEBUG' mode, when resize can occur
}

#ifdef  _DEBUG
CINDER_APP(CinderApp, RendererGl)
#else
CINDER_APP_SCREENSAVER(CinderApp, RendererGl)
#endif // _DEBUG