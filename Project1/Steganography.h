#pragma once
#include "Image.h"
#include "bitset"
#include <vector>


class Steganography: public Image
{
	int messageLength;
	
public:
	void code();
	void decode();
	std::vector<bool> stringToBits(std::string);
	void pixelsArray();
	Steganography();
	~Steganography();
};

