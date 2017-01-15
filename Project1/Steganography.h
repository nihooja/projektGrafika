#pragma once
#include "Image.h"
#include <bitset>
#include <vector>

using namespace std;

class Steganography: public Image
{
	int messageLength;
	vector<SDL_Color> pixelsArray;
	
public:
	void code(vector<bool>,vector<bool>,char*);
	void decode();
	vector<bool> ushortToBits(unsigned short int);
	vector<bool> stringToBits(string); //zwraca vector ze stringiem w bitach
	vector<bool> intToBits(int); //zwraca vector<bool>(32 bit) w ktorych zapisany jest przyjmowany int 
	void makePixelsArray(char *);
	void modifyPixel(int,Uint8,Uint8,Uint8);
	
	Steganography();
	~Steganography();
};

