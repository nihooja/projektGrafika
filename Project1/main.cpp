#include "Image.h"
#include "Interface.h"

using namespace std;


int main(int argc, char ** argv)
{
	
	Interface interface;
	interface.viewMenu(); 
	const char *message = interface.getMessage(); //treœæ wiadomoœci
	char *img = interface.getImage(); //nazwa pliku z bmp
	std::cout << "elo" << std::endl;
	Image image(640, 480);
	SDL_Surface *bmp = image.LoadBitMap(img);
	
	
	system("pause");
	return 0;
} 