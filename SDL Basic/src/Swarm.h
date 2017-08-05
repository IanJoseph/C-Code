/*
 * Swarm.h
 *
 *  Created on: Aug 2, 2017
 *      Author: Ian
 */

#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace CPPTutorials {

class Swarm {
public:
	const static int NPARTICLES = 5000;
private:
	Particle * m_pParticles;
	int lastTime;

public:
	Swarm();
	virtual ~Swarm();
	void update(int elapsed);
	const Particle * const getParticles() {return m_pParticles; };
};

} /* namespace CPPTutorials */

#endif /* SWARM_H_ */
