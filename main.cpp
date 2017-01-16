#include "Image.h"
#include "Interface.h"
#include "Steganography.h"

void choice_1(Interface &inter,Image &im, Steganography &steg)
{ 
	string message = inter.getMessage();
	string password = inter.getPassword();
	vector<bool>messageB = steg.stringToBits(message);
	vector<bool>passwordB = steg.stringToBits(password);

	//przekazujê by sprawdziæ czy wiadomoœæ zmieœci siê w bmp
	char *img = inter.getImage((message.size() + 32) / 3 + 1);
	
	steg.code(messageB, passwordB, img);
}

void choice_2(Interface &inter,Image &im,Steganography &steg)
{ 
	//char *img = inter.getImage();
	//SDL_Surface *bmp = im.LoadBitMap(img);
}



int main(int argc, char ** argv)
{
	
	Image image(640, 480);
	Interface interface_(image);
	Steganography steganography(image);
	char choice = interface_.viewMenu(); 

	if (choice == '1')  
		choice_1(interface_,image,steganography);
	
	else if (choice == '2') 
		choice_2(interface_,image,steganography); 
	
	else
	{
		cout << "Program konczy dzialanie." << endl;
		system("pause");
		exit(0);
	}
	system("pause");
	return 0;
} 