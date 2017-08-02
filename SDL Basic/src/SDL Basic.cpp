//============================================================================
// Name        : SDL Basic.cpp
// Author      : Ian Joseph
// Version     :
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL.h>
using namespace std;

int WinMain() {

	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		cout << "SDL Init failed." << endl;
		return 1;
	}
	cout << "SDL Init succeeded." << endl;
	SDL_Quit();
	return 0;
}

int main() {
	cout << "!!!Hello World!!! Main" << endl; // prints !!!Hello World!!!
	return 0;
}
