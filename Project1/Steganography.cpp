#include "Steganography.h"

void Steganography::changePix(Uint8 & pix, bool number, bool number2)
{
	vector <bool> usint;
	//zamiana r/g/b na short int
	unsigned short a = (unsigned short)pix;
	//zamiana short int na bity
	usint = converObj.ushortToBits(a);
	//xor
	usint[7] = (number ^ number2);
	//zamiana 
	pix = (Uint8)converObj.bitsToUShort(usint); //z powrotem wstawiam do g
	cout << "value: " << (int)pix << endl;
}

//----------------------------------------
void Steganography::code(vector<bool> messageB, vector<bool> passwordB, char *img)
{

	//dlugosci (inty) wiadomo?ci i hasla w postaci BITOWEJ
	bitwiseMessageLength = messageB.size();
	bitwisePasswordLength = passwordB.size();

	//dlugosci (vector<bool>) wiadomosci i hasla w postaci BITOWEJ
	bitwiseMessageLengthB = converObj.intToBits(bitwiseMessageLength);
	bitwisePasswordLengthB = converObj.intToBits(bitwisePasswordLength);


	/*Umieszcza w atrybucie vector<SDL_Color>pixelsArray wyznaczona liczbe pikseli z bmp char*img */
	makePixelsArray(img);


	//pomocniczy wektor do metody ushortToBits
	int w = 0, k = 0, h = 0; //ktory bit wiadomosci, ktory pixel oraz ktory bit hasla
							 //cout << messageB.size() << endl;
							 //cout << messageLengthB.size() << endl;
							 //cout << pixelsArray.size();
							 //dlugosc wiadomosci czyli pierwsze 32 bity

	while (1)
	{
		//zaczynamy od green bo potrzeba 32 bity z 11 pikseli (33bitow)

		cout << "pixel number = " << k << endl << " green before = " << (int)pixelsArray[k].g << endl;
		changePix(pixelsArray[k].g, bitwiseMessageLengthB[w++], 1);
		cout << " green after = " << (int)pixelsArray[k].g << endl;
		//jesli ostatni bit rozmiaru zostal wpisany wyjdzie z while, jesli nie to robi dalej
		if (w == bitwiseMessageLengthB.size()) break;

		cout << " blue before = " << (int)pixelsArray[k].b << endl;
		changePix(pixelsArray[k].b, bitwiseMessageLengthB[w++], 1);
		cout << " blue after = " << (int)pixelsArray[k].b << endl;
		if (w == bitwiseMessageLengthB.size()) break;

		cout << " red before = " << (int)pixelsArray[k].r << endl;
		changePix(pixelsArray[k].r, bitwiseMessageLengthB[w++], 1);
		cout << " red after = " << (int)pixelsArray[k].r << endl;
		if (w == bitwiseMessageLengthB.size()) break;

		k++;
	}

	//tresc wiadomosci
	w = 0; h = 0; k = 12;
	while (1)
	{
		changePix(pixelsArray[k].r, messageB[w++], passwordB[h++]);
		if (h == passwordB.size()) h = 0;
		if (w == bitwiseMessageLengthB.size()) break;
		changePix(pixelsArray[k].b, messageB[w++], passwordB[h++]);
		if (h == passwordB.size()) h = 0;
		if (w == bitwiseMessageLengthB.size()) break;
		changePix(pixelsArray[k].g, messageB[w++], passwordB[h++]);
		if (h == passwordB.size()) h = 0;
		if (w == bitwiseMessageLengthB.size()) break;

		k++;
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
	
	if(!tempPath.find(".bmp"))
		strcat(newBmpPath, ".bmp");

	//wczytanie do nowej bitmapy pikseli z pixelsArray
	SDL_Surface *bmp = imgObj.loadBitMap(img);
	int loop_cond = ((bitwiseMessageLength + 32) / 3) + 1;
	int j = 0;
	
	for (int i = bmp->w, y = 0; y < loop_cond; i--, y++)
	{
		if (i + 1 == 0)
		{
			j += 1;
			i = bmp->w;
			imgObj.setPixel(i, bmp->h - j, 0, 0, 0);

		}
		else imgObj.setPixel(i, bmp->h - j, pixelsArray[y].r, pixelsArray[y].g, pixelsArray[y].b);
	}

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

Steganography::Steganography(Image &obj,Conversion &con) :bitwiseMessageLength(0),converObj(con),bitwisePasswordLength(0), imgObj(obj)
{}


Steganography::~Steganography()
{}