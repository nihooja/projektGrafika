#include "Steganography.h"

void Steganography::changePix(Uint8 pix, bool number, bool number2, vector<bool> usint)
{
	usint.clear();
	unsigned short a = pix;
	usint = ushortToBits(a); //zamieniam na binarny
	usint[0] = (number ^ 1); //zmieniam ostatni bit
	pix = (Uint8)bitsToUShort(usint); //z powrotem wstawiam do g
}

//----------------------------------------
void Steganography::code(vector<bool> messageB, vector<bool> passwordB, char *img)
{
	//sprawdzenie czy wiadomosc sie zmiesci jak nie to blad
	//BLABLABLA

	makePixelsArray(img); //tworzy pixelsArray
	vector<bool> messageLengthB = intToBits(messageLength); //calkowita dlugosc wiadomosci w bitach
	vector<bool> b; //pomocniczy wektor do metody ushortToBits
	int w = 0, k = 0, h = 0; //ktory bit wiadomosci, ktory pixel oraz ktory bit hasla

							 //dlugosc wiadomosci czyli pierwsze 32 bity
	while (1)
	{
		changePix(pixelsArray[k].g, messageLengthB[w++], 1, b); //jaki numer pixela/kolor, ktory bit dlugosci wiadomosci, wektor
																//jesli ostatni bit rozmiaru zostal wpisany wyjdzie z while, jesli nie to robi dalej
		if (w == messageLengthB.size()) break;
		changePix(pixelsArray[k].b, messageLengthB[w++], 1, b);
		if (w == messageLengthB.size()) break; //tu sie powinno skonczyc ale warunki zostawie wszedzie, potem musimy wymyslic jak sie ich pozbyc 
		changePix(pixelsArray[k].r, messageLengthB[w++], 1, b);
		if (w == messageLengthB.size()) break;

		k++;
	}

	//tresc wiadomosci
	w = 0; h = 0; k = 12;
	while (1)
	{
		changePix(pixelsArray[k].r, messageB[w++], passwordB[h++], b);
		if (h == passwordB.size()) h = 0;
		if (w == messageLengthB.size()) break;
		changePix(pixelsArray[k].b, messageB[w++], passwordB[h++], b);
		if (h == passwordB.size()) h = 0;
		if (w == messageLengthB.size()) break;
		changePix(pixelsArray[k].g, messageB[w++], passwordB[h++], b);
		if (h == passwordB.size()) h = 0;
		if (w == messageLengthB.size()) break;

		k++;
	}

	saveCoded(img);
	cout << "Zakonczono kodowanie wiadomosci" << endl;
}

//----------------------------------------
void Steganography::decode()
{


}

//----------------------------------------

/*Dorobi� obs�ug� b��d�w w �rodku!*/
void Steganography::saveCoded(char *img) 
{

	string bmpFile = "";
	cout << "Podaj nazwe pliku bmp do stworzenia" << endl;
	cin >> bmpFile; cout << endl;

	char *bmpFileChar = new char[bmpFile.length() + 1];
	strcpy(bmpFileChar, bmpFile.c_str());

	const char *newBmpPath = bmpFileChar;

	//wska�nik na adres bitmapy 
	SDL_Surface *bmp = SDL_LoadBMP(img);

	int a = (messageLength + 32) / 3 + 1;
	for (int i = 0; i < a; i++)
		imgObj.setPixel(i, 0, pixelsArray[i].r, pixelsArray[i].g, pixelsArray[i].b);

	SDL_SaveBMP(bmp, newBmpPath);
	imgObj.createWindow();
	imgObj.displayBitMap(bmpFileChar);

}

vector<bool> Steganography::stringToBits(string message)
{
	bitset<8> b;
	vector<bool> bitArray;
	messageLength = message.size();

	for (size_t i = 0; i < message.size(); ++i) {

		b = bitset<8>(message[i]);
		for (int j = 0; j < 8; ++j)
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
	for (int i = 0; i < 8; i++)
		a += (unsigned short)(vec[i] * pow(2, 7 - i));

	return a;
}

//----------------------------------------
void Steganography::makePixelsArray(char *img)
{
	int a = (messageLength + 32) / 3 + 1;
	SDL_Surface *bmp = imgObj.loadBitMap(img);
	
	/*Vector obiekt�w typu SDL_Color*/
	for (int i = 0; i<a; ++i)
		pixelsArray.push_back(imgObj.getPixel(i, 0));

}
void Steganography::modifyPixel(int pos, Uint8 R, Uint8 G, Uint8 B)
{	
	
	imgObj.setPixel(pos, 0, R, G, B);

}


Steganography::Steganography(Image &obj) :messageLength(0), imgObj(obj)
{

}


Steganography::~Steganography()
{


}