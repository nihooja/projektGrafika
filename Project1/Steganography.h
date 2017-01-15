#pragma once
#include "Image.h"
#include <bitset>
#include <vector>


class Steganography: public Image
{
	int messageLength;
	std::vector<SDL_Color> pixelsArray;
	
public:
	void code(std::vector<bool>,std::vector<bool>,char*);
	void decode();
	std::vector<bool> stringToBits(std::string); //zwraca vector ze stringiem w bitach
	std::vector<bool> intToBits(int); //zwraca vector<bool>(32 bit) w ktorych zapisany jest przyjmowany int 
	void makePixelsArray(char *);
	void modifyPixel(int,Uint8,Uint8,Uint8);
	
	Steganography();
	~Steganography();
};

