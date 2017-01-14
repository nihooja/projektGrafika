#pragma warning(disable:4996)
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <io.h>

//ogarnij z ilu z tych zmiennych korzystasz tylko w jednej metodzie i wpierdol ich deklaracje do nich
//przyda³oby siê zredukowaæ ten rozpierdol tutaj bo tam Kamilek coœ siê podœmiechiwa³
//pierdó³ka ale mówiê 
class Interface
{
	std::fstream file;
	std::string messageF; // nazwa pliku z wiadomoscia
	std::string bitM; // nazwa pliku bmp
	std::string message; //wiadomosc
	std::string password; 
	std::string getPathdir(char*); //sciezka katalogu projektu
	std::vector <std::string> list; // tablica plikow w folderze
	int choice; // do menu
	int rep; // do prob wpisywania danych
	long found; // do wyszukiwania plikow w folderze 
	char *g_message;
	char *g_pass; 
	char *g_img; 

	void lookforExtension(std::string&, std::string); //dopisywanie rozszerzen
	void filesList(char*); // robi liste plikow w folderze

public:
	
	void viewMenu();
	std::string getPassword();
	int returnChoice()const;
	std::string getMessage();
	char *getImage();

	Interface();
	~Interface();
};

