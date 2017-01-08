#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
//#include <windows.h>
//#include <tchar.h> 

using namespace std;

class Interface
{
	fstream file;

	string messageF; // nazwa pliku z wiadomoscia
	string bitM; // nazwa pliku bmp
	string message; //wiadomosc
	string password; 
//	string getexepath;

	int choice; // do menu
	int rep; // do petli while

	// do konwersji ze stringow
	char *a;
	char *b;
	char *c;

//	bool found;

public:
	
	int ViewMenu();
	
	const char *GetPassword();
	const char *GetMessage();
	char *GetImage();

	void LookforExtension(string&, string);

//	bool FindBmp(int argc, TCHAR * argv[]);

	Interface();
	~Interface();
};

