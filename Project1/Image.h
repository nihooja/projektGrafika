#pragma once
#include "SDL.h"
#include <iostream>
#include <string>

class Image
{	
	//The image we will load and show on the screen
	SDL_Surface *image;
	
	//The window we'll be rendering to
	SDL_Window *window;

	//The surface contained by the window
	SDL_Surface *screenSurface;
	

	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;

public:
	void createWindow();
	SDL_Surface *LoadBitMap(char *);
	Image(int,int);
	~Image();
};

