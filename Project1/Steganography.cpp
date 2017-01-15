#include "Steganography.h"



void Steganography::code(vector<bool> messageB,vector<bool> passwordB,char *img)
{
	makePixelsArray(img); //tworzy vector pixeli, vector masz w atrybucie klasy pixelsArray, ka¿dy element to wynik getPixel() jak na labach 
	vector<bool> messageLengthB = intToBits(messageLength); //d³ugoœæ wiadomoœci w bitach
	//modifyPixel(pos,R,G,B); //do modyfikowania, jako 1 argument leci element pixelsArray
	
	//sprawdzenie czy wiadomosc sie zmiesci
	//BLABLABLA

	vector<bool> b;
	unsigned short a;
	int w = 0, k = 0;
	while (1)
	{
	a = pixelsArray[k].g; //pomijam r w pierwszym pixelu, bo uzywamy 11 pixeli czyli 33 bitow, a nam na rozmiar potrzeba tylko 32
	b = ushortToBits(a); //nie wiem czy vector czy char nie bedzie szybciej, to juz jak wolisz
	b[7] = messageLengthB[w++]; // jesli chodzi o rozmiar to ja bym po prostu podmienil a nie robil zadne xory
	//zamieniam b na int
	//BLABLABLA
	//podstawiam z powrotem za g
	pixelsArray[k].g = a;
	//warunek if(w==messageLengthB.size()) return;   -- nie wiem czy tak sie robi, ale to ma wyjsc z tego while
	// jak nie wyjdzie to to samo dla b i dla r, wiec mozna to jebnac do osobnej metody
	// na koncu tego while robimy k++;
	}

	//w = 0; k = 12; h = 0;
	while (1)
	{
		// to samo tylko ze
		//b[7] = messageB[w++] ^ passwordB[h]; 
		//h++
		//if(h+1>passwordB.size()) h == 0;   -- nie jestem pewien czy tu ma byc jeszcze to +1, no ale jak haslo sie skonczy to zaczyna od nowa
		
			
		
		//podstawienie ostatniego bitu w RED przez XOR
		//b[7] = ( ^ 
	}
	

}

void Steganography::decode()
{
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

vector<bool> Steganography::intToBits(int num)
{

	bitset<32> a(num);
	vector<bool> bitArray;

	for (int j = 0; j < 32; ++j)
			bitArray.push_back(a[j]);

	return bitArray;

	
}

vector<bool> Steganography::ushortToBits(unsigned short num)
{
	bitset<8> a(num);
	vector<bool> bitArray;

	for(int i = 0; i <8; i++)
		bitArray.push_back(a[i]);

	return bitArray;
}

void Steganography::makePixelsArray(char *img)
{
	
    SDL_Surface *image_pointer = returnImage();
	SDL_Surface *bmp = LoadBitMap(img,image_pointer);
	
	int a = (messageLength + 32)/ 3 + 1;

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
