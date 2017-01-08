#include "Image.h"
#include "Interface.h"
#include "Steganography.h"
using namespace std;




/*mo¿liwe ¿e bêdzie musia³o zwróciæ jakiœ wskaŸnik na BMP czy coœ*/
void choice_1(Interface &inter, Image &im, Steganography &steg)
{ 
	const char *message = inter.GetMessage();
	const char *password = inter.GetPassword();
	char *img = inter.GetImage();
	
	//wywo³ania Steganography/Image
	SDL_Surface *bmp = im.LoadBitMap(img);


}
/*to pewnie bêdzie musia³o jako argument przyjmowaæ jeszcze wskaŸnik na BMP co by³ otworzony wczeœniej*/
/*generalnie chyba bêdzie siê wszystko dzia³o na jednym BMP, nie przewiduje ¿adnego tworzenia kopii czy coœ*/
void choice_2(Interface &inter, Image &im,Steganography &steg){ //do przemyœlenia jeszcze dok³adnie

	/*struktura jeszcze do przemyœlenia ofc*/
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