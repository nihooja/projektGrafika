#include "Steganography.h"

void Steganography::changePix(Uint8 & pix, bool number, bool number2)
{
	/*rgb -> short int -> wektor z bitami -> xor -> short int -> rgb*/
	usint.clear();
	unsigned short a = (unsigned short)pix;
	usint = converObj.ushortToBits(a);
	usint[0] = (number ^ number2);
	pix = (Uint8)converObj.bitsToUShort(usint);
}

//----------------------------------------
void Steganography::code(vector<bool> messageB, vector<bool> passwordB, char *img)
{
	/*dlugosci (inty) wiadomo?ci i hasla w postaci BITOWEJ*/
	bitwiseMessageLength = messageB.size();
	bitwisePasswordLength = passwordB.size();

	/*dlugosci (vector<bool>) wiadomosci i hasla w postaci BITOWEJ*/
	bitwiseMessageLengthB = converObj.intToBits(bitwiseMessageLength);
	bitwisePasswordLengthB = converObj.intToBits(bitwisePasswordLength);


	/*Umieszcza w atrybucie vector<SDL_Color>pixelsArray wyznaczona liczbe pikseli z bmp o sciezce char*img */
	makePixelsArray(img);

	/*ktory bit wiadomosci, ktory pixel oraz ktory bit hasla*/
	int w = 0, p = 0, h = 0;

	/*kodowanie hasla, 32 bity z 11 pikseli (33bitow)*/
	while (1)
	{
		changePix(pixelsArray[p].g, bitwiseMessageLengthB[w++], 1);
		changePix(pixelsArray[p++].b, bitwiseMessageLengthB[w++], 1);
		/*jesli ostatni bit to wyjscie z petli*/
		if (w == bitwiseMessageLengthB.size())  break;
		changePix(pixelsArray[p].r, bitwiseMessageLengthB[w++], 1);
	}

	w = 0; h = 0; p = 11;
	/*kodowanie tresci wiadomosci*/
	while (1)
	{
		changePix(pixelsArray[p].r, messageB[w++], passwordB[h++]);
		if (h == passwordB.size()) 	h = 0;
		if (w == bitwiseMessageLength)	break;
		changePix(pixelsArray[p].g, messageB[w++], passwordB[h++]);
		if (h == passwordB.size())	h = 0;
		if (w == bitwiseMessageLength)	break;
		changePix(pixelsArray[p].b, messageB[w++], passwordB[h++]);
		if (h == passwordB.size()) 	h = 0;
		if (w == bitwiseMessageLength)	break;
		p++;
	}
	saveCoded(img);
}

//----------------------------------------
void Steganography::decode(vector<bool> passwordB, char * img_path)
{}

//----------------------------------------

/*DOROBIC OBSLUGE BLEDOW !!!!*/
void Steganography::saveCoded(char *img)
{

	string tempPath = "";

	cout << "Podaj nazwe pliku bmp do stworzenia" << endl;
	cout << "->"; cin >> tempPath; cout << endl;

	char *newBmpPath = converObj.stringToChar(tempPath);

	if (!tempPath.find(".bmp"))
		strcat(newBmpPath, ".bmp");

	//wczytanie do nowej bitmapy pikseli z pixelsArray
	SDL_Surface *bmp = imgObj.loadBitMap(img);
	int loop_cond = ((bitwiseMessageLength + 32) / 3) + 1;
	int j = 1;

	//wypelnienie zmienionymi pixelami
	for (int i = bmp->w - 1, y = 0; y < loop_cond; i--, y++)
	{
		if (i + 1 == 0)
		{
			j += 1;
			i = bmp->w - 1;
			imgObj.setPixel(i, bmp->h - j, pixelsArray[y].r, pixelsArray[y].g, pixelsArray[y].b);
		}
		else
			imgObj.setPixel(i, bmp->h - j, pixelsArray[y].r, pixelsArray[y].g, pixelsArray[y].b);
	}

	//zapis
	SDL_SaveBMP(bmp, newBmpPath);

	cout << "Zakonczono kodowanie wiadomosci. Rezultat zostal zapisany w pliku '" << newBmpPath << "'" << endl;
}
//----------------------------------------
void Steganography::makePixelsArray(char *img)
{
	SDL_Surface *bmp = imgObj.loadBitMap(img);

	int loop_cond = ((bitwiseMessageLength + 32) / 3) + 1;
	int j = 0;

	/*pobiera piksele od dolnego prawego w lewo */
	/*W razie potrzeby przechodzi wiersz wyzej*/
	/* y - liczba pobranych pikseli,piksele do pobrania warunkiem zakonczenia petli*/
	for (int i = bmp->w, y = 0; y < loop_cond; i--, ++y)
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

Steganography::Steganography(Image &obj, Conversion &con) :bitwiseMessageLength(0), converObj(con), bitwisePasswordLength(0), imgObj(obj)
{}


Steganography::~Steganography()
{}