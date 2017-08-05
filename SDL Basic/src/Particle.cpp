/*
 * Particle.cpp
 *
 *  Created on: Aug 2, 2017
 *      Author: Ian
 */

#include "Particle.h"
#include <stdlib.h>
#include <math.h>

namespace CPPTutorials {

Particle::Particle(): m_x(0), m_y(0)  {

	Init();
}

Particle::~Particle() {
	// TODO Auto-generated destructor stub
}

void Particle:: Init() {
	m_x = 0;
	m_y = 0;
	m_direction = (2 * M_PI * rand())/RAND_MAX;
	m_speed = (SPEED * rand())/RAND_MAX;
	m_speed *= m_speed;
}

void Particle::update(int interval) {
	m_direction += interval * 0.0002;
	double xspeed = m_speed * cos(m_direction);
	double yspeed = m_speed * sin(m_direction);
	m_x += xspeed * interval;
	m_y += yspeed *interval;

	if (m_x < -1 || m_x >1 || m_y < -1 || m_y > 1) {
		Init();
	}
	 if (rand() < RAND_MAX/100) {
		 Init();
	 }
}

} /* namespace CPPTutorials */
