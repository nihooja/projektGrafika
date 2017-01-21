#pragma once
#pragma warning(disable:4996)
#include "Image.h"
#include "Conversion.h"
#include <bitset>
#include <vector>

using namespace std;

class Steganography
{
	Image imgObj;
	Conversion converObj;

	int bitwiseMessageLength;
	int bitwisePasswordLength;
	vector <bool> usint;
	vector<bool> bitwisePasswordLengthB;
	vector<bool> bitwiseMessageLengthB;
	vector<SDL_Color> pixelsArray;

public:
	void code(vector<bool>, vector<bool>, char*);
	void decode(vector<bool>, char *);
	void changePix(Uint8&, bool, bool);
	void saveCoded(char *);
	void makePixelsArray(char *);

	Steganography(Image &,Conversion &);
	~Steganography();
};