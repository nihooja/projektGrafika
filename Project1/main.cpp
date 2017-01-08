#include "Image.h"
#include "Interface.h"
#include "Steganography.h"

/*mo¿liwe ¿e bêdzie musia³o zwróciæ jakiœ wskaŸnik na BMP czy coœ*/
void choice_1(Interface &inter, Image &im, Steganography &steg)
{ 
	const char *message = inter.getMessage();
	const char *password = inter.getPassword();
	char *img = inter.getImage();
	system("pause");
	//wywo³ania Steganography/Image
	SDL_Surface *bmp = im.LoadBitMap(img);

}
/*to pewnie bêdzie musia³o jako argument przyjmowaæ jeszcze wskaŸnik na BMP co by³ otworzony wczeœniej*/
/*generalnie chyba bêdzie siê wszystko dzia³o na jednym BMP, nie przewiduje ¿adnego tworzenia kopii czy coœ*/
void choice_2(Interface &inter, Image &im,Steganography &steg)
{ //do przemyœlenia jeszcze dok³adnie

	/*struktura jeszcze do przemyœlenia ofc*/
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