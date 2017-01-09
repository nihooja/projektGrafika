#pragma warning(disable:4996)
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <io.h>
using namespace std;

class Interface
{
	fstream file;

	string messageF; // nazwa pliku z wiadomoscia
	string bitM; // nazwa pliku bmp
	string message; //wiadomosc
	string password; 
	string getPathdir(char*); //sciezka katalogu projektu

	vector <string> list; // tablica plikow w folderze

	int choice; // do menu
	int rep; // do prob wpisywania danych
	long found; // do wyszukiwania plikow w folderze 

	char *a; //getmessage
	char *b; //getpassword
	char *c; //getimage

	void LookforExtension(string&, string); //dopisywanie rozszerzen
	void FilesList(char*); // robi liste plikow w folderze

public:
	
	int ViewMenu();
	
	const char *getPassword();
	const char *getMessage();
	char *getImage();

	Interface();
	~Interface();
};

