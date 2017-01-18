#pragma once
#pragma warning(disable:4996)
#include "Image.h"
#include <bitset>
#include <vector>

using namespace std;

class Steganography
{
	Image imgObj;
	int bitwiseMessageLength;
	int bitwisePasswordLength;
	vector <bool> usint;
	vector<bool> bitwisePasswordLengthB;
	vector<bool> bitwiseMessageLengthB;
	vector<SDL_Color> pixelsArray;
	
public:
	void code(vector<bool>,vector<bool>,char*);
	void decode(vector<bool>,char *);
	void changePix(Uint8&, bool, bool);
	vector<bool> ushortToBits(unsigned short);
	void saveCoded(char *);
	vector<bool> stringToBits(string); //zwraca vector ze stringiem w bitach
	vector<bool> intToBits(int); //zwraca vector<bool>(32 bit) w ktorych zapisany jest przyjmowany int 
	unsigned short bitsToUShort(vector<bool>);
	void makePixelsArray(char *);
	
	Steganography(Image &);
	~Steganography();
};

