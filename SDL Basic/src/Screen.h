/*
 * Screen.h
 *
 *  Created on: Aug 2, 2017
 *      Author: Ian
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>
#include <string.h>
#include <stdio.h>

namespace CPPTutorials {

class Screen {
public:
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;

private:
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer1;
	Uint32 *m_buffer2;

public:
	Screen();
	bool init();
	bool processEvents();
	void close();
	virtual ~Screen();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	void update();
	void clear();
	void boxBlur();
};

} /* namespace CPPTutorials */

#endif /* SCREEN_H_ */
