#include "Steganography.h"

void Steganography::changePix(Uint8 pix, bool number, bool number2, vector<bool> usint)
{
	usint.clear();
	unsigned short a = (unsigned short)pix;
	usint = ushortToBits(a); //zamieniam na binarny
	usint[7] = (number ^ number2); //zmieniam ostatni bit
	pix = (Uint8)bitsToUShort(usint); //z powrotem wstawiam do g

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
	
	
	vector<bool> b; //pomocniczy wektor do metody ushortToBits
	int w = 0, k = 0, h = 0; //ktory bit wiadomosci, ktory pixel oraz ktory bit hasla
	Uint8 qwe = 0;			//cout << messageB.size() << endl;
							 //cout << messageLengthB.size() << endl;
							 //cout << pixelsArray.size();
							 //dlugosc wiadomosci czyli pierwsze 32 bity
	
	while (1)
	{
		qwe = pixelsArray[k].g;
		//int p = qwe;
		//cout << (int)p << endl;
		changePix(qwe, bitwiseMessageLengthB[w++], 1, b); //jaki numer pixela/kolor, ktory bit dlugosci wiadomosci, wektor
												   //cout << (int)p << endl;								   //jesli ostatni bit rozmiaru zostal wpisany wyjdzie z while, jesli nie to robi dalej
		if (w == bitwiseMessageLengthB.size()) break;
		changePix(pixelsArray[k].b, bitwiseMessageLengthB[w++], 1, b);
		if (w == bitwiseMessageLengthB.size()) break; //tu sie powinno skonczyc ale warunki zostawie wszedzie, potem musimy wymyslic jak sie ich pozbyc 
		changePix(pixelsArray[k].r, bitwiseMessageLengthB[w++], 1, b);
		if (w == bitwiseMessageLengthB.size()) break;

		k++;
	}

	//tresc wiadomosci
	w = 0; h = 0; k = 12;
	while (1)
	{
		changePix(pixelsArray[k].r, messageB[w++], passwordB[h++], b);
		if (h == passwordB.size()) h = 0;
		if (w == bitwiseMessageLengthB.size()) break;
		changePix(pixelsArray[k].b, messageB[w++], passwordB[h++], b);
		if (h == passwordB.size()) h = 0;
		if (w == bitwiseMessageLengthB.size()) break;
		changePix(pixelsArray[k].g, messageB[w++], passwordB[h++], b);
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

/*Dorobi? obs?ug? b??dów w ?rodku!*/
void Steganography::saveCoded(char *img)
{

	string bmpFile = "";
	cout << "Podaj nazwe pliku bmp do stworzenia" << endl;
	cout << "->"; cin >> bmpFile; cout << endl;

	char *bmpFileChar = new char[bmpFile.length() + 1];
	strcpy(bmpFileChar, bmpFile.c_str());

	char *newBmpPath = bmpFileChar;
	strcat(newBmpPath, ".bmp");

	//wczytanie do nowej bitmapy pikseli z pixelsArray
	SDL_Surface *bmp = imgObj.loadBitMap(img);
	int loop_cond = ((bitwiseMessageLength + 32) / 3) + 1;
	int j = 0;
	
	for (int i = bmp->w, y = 0; y < loop_cond; i--, ++y) {
		if (i + 1 == 0) {
			j += 1;
			i = bmp->w;
			imgObj.setPixel(i, bmp->h + j, pixelsArray[i].r, pixelsArray[i].g, pixelsArray[i].b);

		}
		else imgObj.setPixel(i, bmp->h + j, pixelsArray[i].r, pixelsArray[i].g, pixelsArray[i].b);
	}

	SDL_SaveBMP(bmp, newBmpPath);

	cout << "Zakonczono kodowanie wiadomosci. Rezultat zostal zapisany w pliku '" << newBmpPath << "'" << endl;
	

	SDL_Surface *bmp1 = imgObj.loadBitMap(img);
	Image imgObj2(640, 480);
	SDL_Surface *bmp2 = imgObj2.loadBitMap(newBmpPath);
	SDL_Color temp;
	SDL_Color temp2;

	for (int i = bmp1->w, j = 0; j < loop_cond; --i, ++j) {

		temp = imgObj.getPixel(i, bmp1->h);
		temp2 = imgObj2.getPixel(i, bmp2->h);
		Uint8 g1 = temp.g;
		Uint8 g2 = temp2.g;
		Uint8 r1 = temp.r;
		Uint8 r2 = temp2.r;
		Uint8 b1 = temp.b;
		Uint8 b2 = temp2.b;


		if (g1 != g2 || r1 != r2 || b1 != b2)
			cout << "rozne" << endl;
	}

}

vector<bool> Steganography::stringToBits(string str)
{
	bitset<8> b;
	vector<bool> bitArray;

	
	//cout << "message: " << message << endl << "size of message:" << messageLength << endl;
	for (size_t i = 0; i < str.size(); ++i)
	{
		b = bitset<8>(str.c_str()[i]);

		for (int j = 7; j >= 0; j--)
			bitArray.push_back(b[j]);
	}

	//cout << "size in bytes:" << bitArray.size() << endl;
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
	int j = 0;

	/*pobiera piksele od dolnego prawego w lewo */
	/*W razie potrzeby przechodzi wiersz wy?ej*/
	/* y - liczba pobranych pikseli,piksele do pobrania warunkiem zakonczenia p?tli*/
	for (int i = bmp->w, y = 0; y < loop_cond; i--, ++y)
	{
		if (i + 1 == 0)
		{
			j += 1;
			i = bmp->w;
			pixelsArray.push_back(imgObj.getPixel(i, bmp->h + j));
		}
		else pixelsArray.push_back(imgObj.getPixel(i, bmp->h + j));
	}
}



Steganography::Steganography(Image &obj) :bitwiseMessageLength(0),bitwisePasswordLength(0),imgObj(obj)
{}


Steganography::~Steganography()
{}