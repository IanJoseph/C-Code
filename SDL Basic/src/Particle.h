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
private:
	double m_speed;
	double m_direction;
	const static double SPEED = 0.04;

private:
	void Init();

public:
	Particle();
	virtual ~Particle();
	void update(int interval);
};

} /* namespace CPPTutorials */

#endif /* PARTICLE_H_ */
