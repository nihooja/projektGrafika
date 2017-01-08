#include "Image.h"
#include "Interface.h"
#include "Steganography.h"
using namespace std;




/*mo�liwe �e b�dzie musia�o zwr�ci� jaki� wska�nik na BMP czy co�*/
void choice_1(Interface &inter, Image &im, Steganography &steg)
{ 
	const char *message = inter.GetMessage();
	const char *password = inter.GetPassword();
	char *img = inter.GetImage();
	
	//wywo�ania Steganography/Image
	SDL_Surface *bmp = im.LoadBitMap(img);


}
/*to pewnie b�dzie musia�o jako argument przyjmowa� jeszcze wska�nik na BMP co by� otworzony wcze�niej*/
/*generalnie chyba b�dzie si� wszystko dzia�o na jednym BMP, nie przewiduje �adnego tworzenia kopii czy co�*/
void choice_2(Interface &inter, Image &im,Steganography &steg){ //do przemy�lenia jeszcze dok�adnie

	/*struktura jeszcze do przemy�lenia ofc*/
	char *img = inter.GetImage();
	SDL_Surface *bmp = im.LoadBitMap(img);
}
int main(int argc, char ** argv)
{
	
	Interface interface;
	Image image(640, 480);
	Steganography steganography;

	//wybranie opcji
	int choice = interface.ViewMenu(); 
	
	//koduje 
	if (choice == 1)  
		choice_1(interface, image, steganography);
	//dekoduje
	else if (choice == 2) 
		choice_2(interface, image, steganography); 
	
	//wyjscie z programu
	else
	{
		system("pause");
		exit(0);
	}

	system("pause");
	return 0;
} 