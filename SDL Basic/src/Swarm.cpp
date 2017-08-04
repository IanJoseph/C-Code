/*
 * Swarm.cpp
 *
 *  Created on: Aug 2, 2017
 *      Author: Ian
 */

#include "Swarm.h"

namespace CPPTutorials {


Swarm::Swarm() {
	m_pParticles = new Particle[NPARTICLES];

}

Swarm::~Swarm() {
	delete [] m_pParticles;
}

void Swarm::update() {
	for (int i = 0; i < Swarm::NPARTICLES; i++) {
		m_pParticles[i].update();
	}
}


} /* namespace CPPTutorials */
