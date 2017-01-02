#include "Interface.h"

 char  *Interface::getImage()
{
	char *a = "Image.bmp"; //nazwa pliku 
	return a;
}

void Interface::viewMenu() //wpisywanie nazw plików, na potem
{

	int a = 0;
	
	std::cout << "======KODOWANIE WIADOMOSCI W BITMAPIE======" << std::endl;
	//std::cout << "Podaj nazwe pliku z wiadomoscia do ukrycia" << std::endl;
	//std::cin >> messageF;
	//std::cout << "Podajnazwe pliku bmp w ktorym chcesz ukryc wiadomosc" << std::endl;
	//std::cin >> bitM;

	std::cout << "Nacisnij enter zeby wyswietlic podana bitmape" << std::endl;
	getchar();
	
	
}
const char *Interface::getMessage()
{
	messageF = "message.txt"; //nazwa pliku 
	std::string a;
	file.open(messageF);
	if (!file) {

		std::cerr << ("error opening message txt") << std::endl;
		exit(1);
	}

	while (file >> message) {
		file >> a;
		message += a;

	}
	
	const char *c = message.c_str();
	return c;
}

Interface::Interface():bitM(""),messageF(""),message("")
{}


Interface::~Interface()
{}
