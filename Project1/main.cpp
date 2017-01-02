#include "Image.h"
#include "Interface.h"
#include "Steganography.h"
using namespace std;




/*mo¿liwe ¿e bêdzie musia³o zwróciæ jakiœ wskaŸnik na BMP czy coœ*/
void choice_1(Interface &inter, Image &im, Steganography &steg){ 
	

	/*struktura jeszcze do przemyœlenia ofc*/
	const char *message = inter.getMessage();
	char *img = inter.getImage();
	const char *password = inter.getPassword();
	
	//wywo³ania Steganography/Image
	SDL_Surface *bmp = im.LoadBitMap(img);


}
/*to pewnie bêdzie musia³o jako argument przyjmowaæ jeszcze wskaŸnik na BMP co by³ otworzony wczeœniej*/
/*generalnie chyba bêdzie siê wszystko dzia³o na jednym BMP, nie przewiduje ¿adnego tworzenia kopii czy coœ*/
void choice_2(Interface &inter, Image &im,Steganography &steg){ //do przemyœlenia jeszcze dok³adnie

	/*struktura jeszcze do przemyœlenia ofc*/
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
	
	while (choice > 2) { //nie mia³em innego pomys³u na zapêtlenie
		if (choice == 0)  //jeœli koduje 
			choice_1(interface, image, steganography);
		else if (choice == 2) { //jesli dekoduje 
			choice_2(interface, image, steganography);
			++choice; //aby wysz³o z pêtli, niedoskona³e, wiem 
		}
	}

	
	system("pause");
	return 0;
} 