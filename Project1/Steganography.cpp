#include "Steganography.h"



void Steganography::code(vector<bool> messageB,vector<bool> passwordB,char *img)
{
	makePixelsArray(img);

	/*Algorytm*/


	//modifyPixel(pos,R,G,B);

}

void Steganography::decode()
{
}

vector<bool> Steganography::stringToBits(string message)
{
	bitset<8> b;
	vector<bool> bitArray;
	
	for (size_t i = 0; i < message.size(); ++i) 
	{

		b = bitset<8>(message[i]);
		for (int j = 0; j < 8; ++j)
			bitArray.push_back(b[j]);
	}

	return bitArray;
}

vector<bool> Steganography::intToBits(int num)
{

	bitset<32> a;
	vector<bool> bitArray;

	bitset<32>(num);
	for (int j = 0; j < 32; ++j)
			bitArray.push_back(a[j]);
	return bitArray;
}

void Steganography::makePixelsArray(char *img)
{
	SDL_Surface *bmp = LoadBitMap(img);
	int a = (messageLength / 3) + 33;

	/*Vector obiektów typu SDL_Color*/
	for (int i = 0; i<a; ++i)
		pixelsArray.push_back(getPixel(i,0));

	
	//(SDL_FreeSurface(bmp);
	//SDL_DestroyWindow(Image::returnWindow());
}
void Steganography::modifyPixel(int pos, Uint8 R, Uint8 G, Uint8 B)
{
	setPixel(pos, 0, R, G, B);
}


Steganography::Steganography():messageLength(0)
{}


Steganography::~Steganography()
{
}
