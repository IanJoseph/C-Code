//============================================================================
// Name        : SDL Basic.cpp
// Author      : Ian Joseph
// Version     :
// Description : Graphic pixel manipulation
//============================================================================

#include <iostream>
#include <string.h>
#include <SDL.h>
#include "screen.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "swarm.h"

using namespace std;
using namespace CPPTutorials;

int WinMain() {

	srand(time(NULL));
	Screen screen;

	if (screen.init() == false) {
		cout << "Error initializing SDL." << endl;
	}

	Swarm swarm;

	while (true) {
		//update particles
		int elapsed = SDL_GetTicks();
//		screen.clear();
		swarm.update(elapsed);

		// Draw particles

		unsigned char green = (1 + (cos(elapsed * 0.0001)) * 128);
		unsigned char red =   (1 + (cos(elapsed * 0.0002)) * 128);
		unsigned char blue =  (1 + (sin(elapsed * 0.0002)) * 128);
		const Particle * const pParticles = swarm.getParticles();

		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particle = pParticles[i];
			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH/2;
			int y = particle.m_y * Screen::SCREEN_WIDTH/2 + Screen::SCREEN_HEIGHT /2;
			screen.setPixel(x,y, (int) red, (int) green, (int) blue);
		}

		// Draw the updated screen
		screen.boxBlur();
		screen.update();

		// Check for messages/events
		if (screen.processEvents() == false) {
			break;
		}
	}

	screen.close();

	return 0;
}

//int main() {
//	cout << "!!!Hello World!!! Main" << endl; // prints !!!Hello World!!!
//	return 0;
//}
