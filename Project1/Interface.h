#pragma warning(disable:4996)
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <io.h>
#include "Image.h"
#include "File.h"
#include "Conversion.h"
using namespace std;

class Interface
{
	Image imgObj;
	File fileObj;
	Conversion converObj;
	
	vector <string> list; // tablica plikow w folderze
	char *g_img; // konwersja stringa z nazwa pliku bmp do char

public:

	char viewMenu();
	char *getImage(int = 0);
	string getPassword();
	string getMessage();

	Interface(Image &,File &,Conversion &);
	~Interface();
};
