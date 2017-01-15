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
	
	vector <string> list; // tablica plikow w folderze
	int rep; // do prob wpisywania danych	
	char *g_img; // konwersja stringa z nazwa pliku bmp do char

	void lookforExtension(string&, string); //dopisywanie rozszerzen
	void filesList(char*); // robi liste plikow w folderze
	string getPathdir(char*); //sciezka katalogu projektu
public:
	
	char viewMenu();
	char *getImage();

	string getPassword();
	string getMessage();
	
	Interface();
	~Interface();
};

