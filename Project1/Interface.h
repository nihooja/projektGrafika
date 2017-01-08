#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <io.h>

using namespace std;

class Interface
{
	fstream file;

	string messageF; // nazwa pliku z wiadomoscia
	string bitM; // nazwa pliku bmp
	string message; //wiadomosc
	string password; 
	string getPathdir(char*);

	int choice; // do menu
	int rep; // do petli while
	long found; // do wyszukiwania bmp
	// do konwersji ze stringow
	char *a;
	char *b;
	char *c;

	void LookforExtension(string&, string);

public:
	
	int ViewMenu();
	
	const char *getPassword();
	const char *getMessage();
	char *getImage();

	Interface();
	~Interface();
};

