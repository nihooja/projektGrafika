#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

class Interface
{
	string bitM; // nazwa pliku bmp
	string messageF; // plik z wiadomoscia
	string password;
	fstream file;
	string message; //wiadomosc
	int choice;
	
	// do konwersji ze stringow
	char *a;
	char *b;
	char *c;

public:
	
	int ViewMenu();
	
	const char *GetPassword();
	const char *GetMessage();
	char *GetImage();

	void LookforExtension(string&, string);
	
	Interface();
	//~Interface();
};

