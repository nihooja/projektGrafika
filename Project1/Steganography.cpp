#include "Steganography.h"

void Steganography::changePix(Uint8 & pix, bool number, bool number2)
{
	usint.clear();
	//zamiana r/g/b na short int
	unsigned short a = (unsigned short)pix;
	//zamiana short int na bity
	usint = ushortToBits(a);
	//xor
	usint[0] = (number ^ number2);
	//zamiana z bitow na r/g/b
	pix = (Uint8)bitsToUShort(usint);
}

//----------------------------------------
void Steganography::code(vector<bool> messageB, vector<bool> passwordB, char *img)
{
	//d³ugoœci (inty) wiadomoœci i has³a w postaci BITOWEJ
	bitwiseMessageLength = messageB.size();
	bitwisePasswordLength = passwordB.size();

	//d³ugoœci (vector<bool>) wiadomoœci i has³a w postaci BITOWEJ
	bitwiseMessageLengthB = intToBits(bitwiseMessageLength);
	bitwisePasswordLengthB = intToBits(bitwisePasswordLength);

	/*Umieszcza w atrybucie vector<SDL_Color>pixelsArray wyznaczon¹ liczbê pikseli z bmp o œcie¿ce char*img */
	makePixelsArray(img);

	//ktory bit wiadomosci, ktory pixel oraz ktory bit hasla
	int w = 0, k = 0, h = 0; 
	
	//kodowanie hasla, zaczynamy od green bo potrzeba 32 bity z 11 pikseli (33bitow)
	while (1)
	{		
		changePix(pixelsArray[k].g, bitwiseMessageLengthB[w++], 1);
		//jesli ostatni bit rozmiaru zostal wpisany wyjdzie z while, jesli nie to robi dalej
		if (w == bitwiseMessageLengthB.size())  break;

		changePix(pixelsArray[k++].b, bitwiseMessageLengthB[w++], 1);
		if (w == bitwiseMessageLengthB.size())  break;

		changePix(pixelsArray[k].r, bitwiseMessageLengthB[w++], 1);
		if (w == bitwiseMessageLengthB.size())  break;
	}
	//kodowanie tresci wiadomosci
	w = 0; h = 0; k = 11;
	while (1)
	{
		changePix(pixelsArray[k].r, messageB[w++], passwordB[h++]);
		if (h == passwordB.size()) 	h = 0;
		if (w == bitwiseMessageLength)	break;
		changePix(pixelsArray[k].g, messageB[w++], passwordB[h++]);
		if (h == passwordB.size())	h = 0;
		if (w == bitwiseMessageLength)	break;
		changePix(pixelsArray[k].b, messageB[w++], passwordB[h++]);
		if (h == passwordB.size()) 	h = 0;
		if (w == bitwiseMessageLength)	break;
		k++;
	}
	saveCoded(img);
}

//----------------------------------------
void Steganography::decode(vector<bool> passwordB, char * img_path)
{}

//----------------------------------------

/*Dorobic obs?ug? b??dów w ?rodku!*/
void Steganography::saveCoded(char *img)
{
	Image obj(640, 480);

	string bmpFile = "";
	cout << "Podaj nazwe pliku bmp do stworzenia" << endl;
	cout << "->"; cin >> bmpFile; cout << endl;

	char *bmpFileChar = new char[bmpFile.length() + 1];
	strcpy(bmpFileChar, bmpFile.c_str());

	char *newBmpPath = bmpFileChar;
	strcat(newBmpPath, ".bmp");

	//wczytanie do nowej bitmapy pikseli z pixelsArray
	SDL_Surface *bmp = obj.loadBitMap(img);
	int loop_cond = ((bitwiseMessageLength + 32) / 3);
	int j = 1;

	//wypelnienie zmienionymi pixelami
	for (int i = bmp->w-1, y = 0; y < loop_cond; i--,y++) 
	{
		if (i + 1 == 0) 
		{
			j += 1;
			i = bmp->w-1;
			obj.setPixel(i, bmp->h - j, pixelsArray[y].r, pixelsArray[y].g, pixelsArray[y].b);
		}
		
		else 
		{
			obj.setPixel(i, bmp->h - j, pixelsArray[y].r, pixelsArray[y].g, pixelsArray[y].b);
		}
	}

	//zapis
	SDL_SaveBMP(bmp, newBmpPath);

	cout << "Zakonczono kodowanie wiadomosci. Rezultat zostal zapisany w pliku '" << newBmpPath << "'" << endl;
}

vector<bool> Steganography::stringToBits(string str)
{
	bitset<8> b;
	vector<bool> bitArray;

	for (size_t i = 0; i < str.size(); ++i)
	{
		b = bitset<8>(str.c_str()[i]);

		for (int j = 7; j >= 0; j--)
			bitArray.push_back(b[j]);
	}
	return bitArray;
}

//----------------------------------------
vector<bool> Steganography::intToBits(int num)
{
	bitset<32> a(num);
	vector<bool> bitArray;

	for (int j = 0; j < 32; ++j)
		bitArray.push_back(a[j]);

	return bitArray;
}

//----------------------------------------
vector<bool> Steganography::ushortToBits(unsigned short num)
{
	bitset<8> a(num);
	vector<bool> bitArray;

	for (int i = 0; i<8; i++)
		bitArray.push_back(a[i]);

	return bitArray;
}

//----------------------------------------
unsigned short Steganography::bitsToUShort(vector <bool> vec)
{
	unsigned short a = 0;
	for (int i = 7; i >= 0; i--)
		a += (unsigned short)(vec[i] * pow(2, i));

	return a;
}

//----------------------------------------
void Steganography::makePixelsArray(char *img)
{
	SDL_Surface *bmp = imgObj.loadBitMap(img);
	
	int loop_cond = ((bitwiseMessageLength + 32) / 3) + 1;
	int j = 1;

	//pobiera wymagana liczbe pikseli od dolnego prawego rogu
	for (int i = bmp->w-1, y = 0; y < loop_cond; i--, ++y)
	{
		if (i + 1 == 0)
		{
			j += 1;
			i = bmp->w;
			pixelsArray.push_back(imgObj.getPixel(i, bmp->h - j));
		}
		else pixelsArray.push_back(imgObj.getPixel(i, bmp->h - j));
	}
}



Steganography::Steganography(Image &obj) :bitwiseMessageLength(0),bitwisePasswordLength(0),imgObj(obj)
{}


Steganography::~Steganography()
{}