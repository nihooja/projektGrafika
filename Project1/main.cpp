#include "Image.h"
#include "Interface.h"
#include "Steganography.h"

/*mo�liwe �e b�dzie musia�o zwr�ci� jaki� wska�nik na BMP czy co�*/
void choice_1(Interface &inter, Image &im, Steganography &steg)
{ 
	const char *message = inter.getMessage();
	const char *password = inter.getPassword();
	char *img = inter.getImage();
	system("pause");
	//wywo�ania Steganography/Image
	SDL_Surface *bmp = im.LoadBitMap(img);

}
/*to pewnie b�dzie musia�o jako argument przyjmowa� jeszcze wska�nik na BMP co by� otworzony wcze�niej*/
/*generalnie chyba b�dzie si� wszystko dzia�o na jednym BMP, nie przewiduje �adnego tworzenia kopii czy co�*/
void choice_2(Interface &inter, Image &im,Steganography &steg)
{ //do przemy�lenia jeszcze dok�adnie

	/*struktura jeszcze do przemy�lenia ofc*/
	char *img = inter.getImage();
	SDL_Surface *bmp = im.LoadBitMap(img);
}
int main(int argc, char ** argv)
{
	
	Interface interface_0;
	Image image(640, 480);
	Steganography steganography;

	//wybranie opcji
	int choice = interface_0.ViewMenu(); 
	
	//koduje 
	if (choice == 1)  
		choice_1(interface_0, image, steganography);
	//dekoduje
	else if (choice == 2) 
		choice_2(interface_0, image, steganography); 
	//wyjscie z programu
	else
	{
		cout << endl << "Program konczy dzialanie";
		system("pause");
		exit(0);
	}

	system("pause");
	return 0;
} 