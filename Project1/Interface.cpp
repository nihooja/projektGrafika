#include "Interface.h"

/*ma to KONIECZNIE zwr�ci� char*, nie dzia�a opcja z c_str() bo zwraca to zawsze const'a, ktorego nie da si� potem nigdzie zapisa�, wymy�l co�*/
/*jebnij po prostu na char* wszystko wraz z tym �e sprawdza czy jest ju� .bmp*/
/*wywo�anie w mainie*/
char  *Interface::getImage() 
											
{
	//c//har *a;
	//std::cout << "Podaj nazwe pliku bmp" << std::endl;
	//std::cin >> a;
	
	char *a = "Image.bmp"; //nazwa pliku 
	//const char *c = b.c_str();
	return a;
}

/*Wy�wietla najpierw opcje z wyborem czy kodowa� czy dekodowa�, wyb�r b�dzie returnowany do maina przez metody*/
/*wywo�anie w mainie*/
/*zmienna choice jako sk�adnik prywatny Interface*/
/*w mainie za�o�y�em �e jesli choice == 1 to koduje, a jesli ==2 to dekoduje xd*/


void Interface::viewMenu() 
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
/*wywo�anie w mainie*/
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
		message += " ";

	}
	
	const char *c = message.c_str();
	return c;
}

/*wywo�anie w mainie*/
const char *Interface::getPassword() {

	return "elo";
}

int Interface::retChoice() const
{
	return 0;
}



Interface::Interface():bitM(""),messageF(""),message(""),choice(1)
{}


Interface::~Interface()
{}
