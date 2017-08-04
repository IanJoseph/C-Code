/*
 * Screen.cpp
 *
 *  Created on: Aug 2, 2017
 *      Author: Ian J
 */

#include "Screen.h"

namespace CPPTutorials {

Screen::Screen() :
		m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL) {
}

// Initialize screen, create window.
bool Screen::init() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return false;
	}

//	Create Window
	m_window = SDL_CreateWindow("Particle Fire Explosion",
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
			SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (m_window == NULL) {
		SDL_Quit();
		return false;
	}
// Center window title ?


// Create rendering context
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
	if (m_renderer == NULL) {
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

// Create texture, loads in Video card's VRAM
	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (m_texture == NULL) {
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

//Create variable to hold screen pixel data
	m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

// Initialize buffer to black
	memset(m_buffer, 0x0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

	return true;
}

// Process Window Events
bool Screen::processEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			return false;
		}
	}
	return true;
}

// Clear screen
void Screen::clear() {
	memset(m_buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

}


// Set color for each individual pixelv
void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
		return;
	}

	Uint32 pixelColor = 0;

	pixelColor += red;
	pixelColor <<= 8;
	pixelColor +=green;
	pixelColor <<= 8;
	pixelColor +=blue;
	pixelColor <<= 8;
	pixelColor += 0xFF;

	m_buffer[(y * SCREEN_WIDTH) + x] = pixelColor;
}

// Draw buffer data in WIndow
void Screen::update() {
	SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);
}

// Close screen and release memory
void Screen::close() {
	delete[] m_buffer;
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyTexture(m_texture);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

Screen::~Screen() {
	// TODO Auto-generated destructor stub
}

} /* namespace CPPTutorials */
