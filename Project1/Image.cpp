#include "Image.h"


void Image::createWindow()
{
	// Create window
	window = SDL_CreateWindow("Project", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (!window){
		std::cerr << "SDL_CreateWindow() Failed: " << SDL_GetError() << std::endl;
		exit(1);
	}
	else {
		//Get window surface
		screenSurface = SDL_GetWindowSurface(window);
	}
}

SDL_Surface *Image::LoadBitMap(char *path) {

	createWindow(); 
	
	image = SDL_LoadBMP(path);
	if (!image){
		std::cerr << "SDL_LoadBMP() Failed: " << SDL_GetError() << std::endl;
		exit(1);
	}


	SDL_BlitSurface(image, nullptr, screenSurface, nullptr);
	SDL_UpdateWindowSurface(window);
	return image;
}



Image::Image(int weight,int height):
	SCREEN_WIDTH(weight),SCREEN_HEIGHT(height),image(nullptr),window(nullptr),screenSurface(nullptr){
	
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cerr << "SDL_Init() Failed: " << SDL_GetError() << std::endl;
		exit(1);
	}
	
}


Image::~Image(){

	//Deallocate surface
	SDL_FreeSurface(image);
	image = nullptr;

	//Destroy window
	SDL_DestroyWindow(window);
	window = nullptr;

	//Quit SDL subsystems
	SDL_Quit();
}
