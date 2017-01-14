#include "Image.h"
#include "Interface.h"
#include "Steganography.h"


void choice_1(Interface &inter,Image &im, Steganography &steg)
{ 
	std::string message = inter.getMessage();
	std::string password = inter.getPassword();
	char *img = inter.getImage();
	steg.bitMessage(message);
	steg.bitPassword(password);

	//char *img = inter.getImage();
	//SDL_Surface *bmp = im.LoadBitMap(img);

}

void choice_2(Interface &inter,Image &im,Steganography &steg)
{ 
	char *img = inter.getImage();
	//SDL_Surface *bmp = im.LoadBitMap(img);
}



int main(int argc, char ** argv)
{
	
	Interface interface_;
	Image image(640, 480);
	Steganography steganography;
	interface_.viewMenu(); 
	int choice = interface_.returnChoice();

	if (choice == 1)  
		choice_1(interface_,image,steganography);
	
	else if (choice == 2) 
		choice_2(interface_,image,steganography); 
	//wyjscie z programu
	else
	{
		std::cout << "Program konczy dzialanie." << std::endl;
		system("pause");
		exit(0);
	}

	system("pause");
	return 0;
} 