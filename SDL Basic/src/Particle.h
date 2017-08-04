/*
 * Particle.h
 *
 *  Created on: Aug 2, 2017
 *      Author: Ian
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace CPPTutorials {

struct Particle {

	double m_x;
	double m_y;

	const static double SPEED = 0.001;
	double m_xspeed;
	double m_yspeed;

public:
	Particle();
	virtual ~Particle();
	void update();
};

} /* namespace CPPTutorials */

#endif /* PARTICLE_H_ */
