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
	SDL_Surface *LoadBitMap(char *, SDL_Surface *);
	SDL_Color getPixel(int,int);
	SDL_Window* returnWindow()const;
	SDL_Surface* returnImage()const;

	void setPixel(int,int,Uint8,Uint8,Uint8);
	Image(int,int);
	~Image();
	Image() {}
};

