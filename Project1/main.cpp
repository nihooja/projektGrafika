#include "Image.h"
#include "Interface.h"
#include "Steganography.h"
using namespace std;




/*mo�liwe �e b�dzie musia�o zwr�ci� jaki� wska�nik na BMP czy co�*/
void choice_1(Interface &inter, Image &im, Steganography &steg){ 
	

	/*struktura jeszcze do przemy�lenia ofc*/
	const char *message = inter.getMessage();
	char *img = inter.getImage();
	const char *password = inter.getPassword();
	
	//wywo�ania Steganography/Image
	SDL_Surface *bmp = im.LoadBitMap(img);


}
/*to pewnie b�dzie musia�o jako argument przyjmowa� jeszcze wska�nik na BMP co by� otworzony wcze�niej*/
/*generalnie chyba b�dzie si� wszystko dzia�o na jednym BMP, nie przewiduje �adnego tworzenia kopii czy co�*/
void choice_2(Interface &inter, Image &im,Steganography &steg){ //do przemy�lenia jeszcze dok�adnie

	/*struktura jeszcze do przemy�lenia ofc*/
	char *img = inter.getImage();
	SDL_Surface *bmp = im.LoadBitMap(img);
}
int main(int argc, char ** argv)
{
	
	Interface interface;
	Image image(640, 480);
	Steganography steganography;
	interface.viewMenu(); 
	
	int choice = interface.retChoice();  
	
	while (choice > 2) { //nie mia�em innego pomys�u na zap�tlenie
		if (choice == 0)  //je�li koduje 
			choice_1(interface, image, steganography);
		else if (choice == 2) { //jesli dekoduje 
			choice_2(interface, image, steganography);
			++choice; //aby wysz�o z p�tli, niedoskona�e, wiem 
		}
	}

	
	system("pause");
	return 0;
} 