#pragma once
#include "Image.h"


class Steganography: public Image
{
	int messageLength;






	
public:
	void code();
	void decode();
	int stringLength(std::string);
	void bitMessage(std::string);
	void bitPassword(std::string);
	void pixelsArray();
	Steganography();
	~Steganography();
};

