#pragma once
#include "SDL.h"
#include <iostream>
#include <string>

class Image
{	
	
	SDL_Surface *image;
	SDL_Window *window;
	SDL_Surface *screenSurface;
	

	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;

public:
	void createWindow();
	SDL_Surface *LoadBitMap(char *);
	Image(int,int);
	~Image();
	Image() {}
};

