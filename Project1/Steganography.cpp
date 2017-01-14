#include "Steganography.h"



void Steganography::code()
{
}

void Steganography::decode()
{
}

std::vector<bool> Steganography::stringToBits(std::string message)
{
	std::bitset<8> b;
	std::vector<bool> bitArray;
	
	for (std::size_t i = 0; i < message.size(); ++i) {

		b = std::bitset<8>(message[i]);
		for (int j = 0; j < 8; ++j)
			bitArray.push_back(b[j]);
	}

	return bitArray;
}

void Steganography::pixelsArray()
{

}

Steganography::Steganography():messageLength(0)
{}


Steganography::~Steganography()
{
}
