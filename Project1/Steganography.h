#pragma once
#include "Image.h"
#include <bitset>
#include <vector>

using namespace std;

class Steganography
{
	Image imgObj;
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	int messageLength;
	std::vector<SDL_Color> pixelsArray;
	
public:
	void Code(vector<bool>,vector<bool>,char*);
	void Decode();
	void ChangePix(Uint8, bool, bool, vector<bool>);

	vector<bool> ushortToBits(unsigned short);
	vector<bool> stringToBits(string); //zwraca vector ze stringiem w bitach
	vector<bool> intToBits(int); //zwraca vector<bool>(32 bit) w ktorych zapisany jest przyjmowany int 
	unsigned short BitsToUShort(vector<bool>);
	
	void makePixelsArray(char *);
	void modifyPixel(int,Uint8,Uint8,Uint8);
	
	Steganography(Image &);
	~Steganography();
};

