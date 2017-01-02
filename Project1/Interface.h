#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

class Interface
{
	std::string bitM; // plik bmp
	std::string messageF; // plik z wiadomocia
	std::fstream file;
	std::string message; //wiadomosc

public:
	
	char *getImage(); //wczytuje nazwê pliku
	void viewMenu(); 
	const char *getMessage();
	Interface();
	~Interface();
};

