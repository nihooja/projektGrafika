#include "Image.h"
#include "Interface.h"
#include "Steganography.h"


void choice_1(Interface &inter,Image &im, Steganography &steg)
{ 
	string message = inter.getMessage();
	string password = inter.getPassword();
	char *img = inter.getImage();
	
	vector<bool>messageB = steg.stringToBits(message);
	vector<bool>passwordB = steg.stringToBits(password);

	steg.code(messageB, passwordB, img);
	
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
	char choice = interface_.viewMenu(); 

	if (choice == '1')  
		choice_1(interface_,image,steganography);
	
	else if (choice == '2') 
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