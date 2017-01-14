#include "Interface.h"

//----------------------------------------
//Wypelnia wektor plikami o danym rozszerzeniu i je wypisuje
void Interface::filesList(char *extension)
{
	
	list.clear();

	//adres katalogu z plikami
	char q[MAX_PATH];
	std::string dirpath = getPathdir(q);

	//wyszukiwanie plikow w katalogu projektu z danym rozszerzeniem
	_finddata_t found_file;

	//jesli nie ma zadnych
	if ((found = _findfirst(extension, &found_file)) == -1)
	{
		std::cerr << "W folderze: " << dirpath << " nie ma zadnych plikow " << extension << ". Program zakonczy dzialanie." << std::endl;
		system("pause");
		exit(1);
	}

	//jesli jest przynajmniej jeden, dodaje sie do wektora
	else
	{
		//wypis pierwszego
		list.push_back(found_file.name);

		std::cout << "Pliki znajdujace sie w katalogu: " << std::endl << dirpath << std::endl;
		std::cout << /*list.size() << " - " <<*/ found_file.name << std::endl;
		rep++;

		//wypis i dodanie reszty (jesli istnieje)
		while (found = _findnext(found, &found_file) != -1)
		{
			list.push_back(found_file.name);
			std::cout << /*list.size() << " - " << */found_file.name << std::endl;
		}
	}
}

//----------------------------------------
//Po wprowadzeniu nazwy pliku sprawdza, czy zawiera ona rozszerzenie
void Interface::lookforExtension(std::string &text, std::string search)
{
	size_t found = text.find(search);

	if (found == std::string::npos) // jesli nie ma -> dodaje
	{
		text += search;
	}
	else return;
}

//----------------------------------------
//Zwraca adres katalogu z programem
std::string Interface::getPathdir(char* maxpath)
{
	GetModuleFileName(NULL, maxpath, MAX_PATH);
	std::string::size_type pos = std::string(maxpath).find_last_of("\\/");
	return std::string(maxpath).substr(0, pos);
}

//----------------------------------------
//Menu zwracajace wybrana opcje
void Interface::viewMenu()
{
	rep = 0;

	std::cout << "========KODOWANIE WIADOMOSCI W BITMAPIE========" << std::endl;

	while (choice != 1 && choice != 2 && choice != 3 && rep < 3)
	{
		std::cout << "Wybierz opcje?" << std::endl;
		std::cout << "1 - zakodowac wiadomosc" << std::endl;
		std::cout << "2 - odkodowac wiadomosc" <<std::endl;
		std::cout << "3 - wyjscie" << std::endl;
		std::cout << "->"; std::cin >> choice;
		rep++;
	}

	//limit powtorzen
	if (rep == 3)
		choice = 3;

	
}

//----------------------------------------
//Zwraca wiadomosc
std::string Interface::getMessage()
{
	rep = 0;
	//wyszukiwanie txt w folderze
	this->filesList("*.txt");

	while (rep < 3)
	{
		
		std::cout << "Podaj nazwe pliku z wiadomoscia:" << std::endl;
		std::cout << "->"; std::cin >> messageF;
		std::cout << std::endl;

		
		this->lookforExtension(messageF, ".txt");

		file.open(messageF);
		if (file)
		{
			std::string msg;

			//odczyt z pliku
			while (file >> message)
			{
				file >> msg;
				message += msg;
				message += " ";
			}

			//jesli pusty
			if (message == "")
			{
				std::cerr << ("Blad! Plik jest pusty!") << std::endl;
				rep++;
			}
			//jesli nie jest pusty, konwersja do char
			else
			{
				//g_message = new char[message.length() + 1];
				//strcpy(g_message, message.c_str());
				//return g_message;
				return message;
			}
		}
		//jesli nie ma takiego pliku
		else
			rep++;
	}
	//jesli nie znalazl do konca
	if (message == "" && rep == 3)
	{
		std::cerr << "Blad otwierania pliku. Program zakonczy dzialanie." << std::endl;
		system("pause");
		exit(1);
	}
}

//----------------------------------------
//Zwraca haslo
std::string Interface::getPassword()
{
	rep = 0;

	while (password == "" && rep < 3)
	{
		std::cout << std::endl;
		std::cout << "Podaj haslo do kodowania:" << std::endl;
		std::cout << "->"; std::cin >> password;
		rep++;
	}

	//konwersja hasla do char
	if (password != "")
	{
		//g_pass = new char[password.length() + 1];
		//strcpy(g_pass, password.c_str());
		//return g_pass;
		return password;
	}

	//jesli ktos bardzo nie chce wpisac hasla
	else
	{
		std::cerr << "Blad wpisywania hasla. Program zakonczy dzialanie." << std::endl;
		system("pause");
		exit(1);
	}
}

int Interface::returnChoice() const
{
	return choice;
}

//----------------------------------------
//Zwraca nazwe pliku bmp w ktorym zostanie zakodowana wiadomosc
char *Interface::getImage()
{
	rep = 0;

	//wyszukiwanie bmp w folderze
	filesList("*.bmp");

	while (rep < 3)
	{
		//Nazwa pliku
		if (choice == 1)
			std::cout << std::endl << "Podaj nazwe pliku, w ktorym chcesz zapisac wiadomosc." << std::endl;
		else if (choice == 2)
			std::cout << std::endl << "Podaj nazwe pliku, z ktorego chcesz odkodowac wiadomosc." << std::endl;
		std::cout << "->"; std::cin >> bitM;
		std::cout << std::endl;

		//ewentualne dodanie rozszerzenia
		lookforExtension(bitM, ".bmp");

		//sprawdzanie czy taki plik znajduje sie w folderze
		for (int i = 0; i < list.size(); i++)
		{
			//jesli jest
			if (list[i] == bitM)
			{
				g_img = new char[bitM.length() + 1];
				strcpy(g_img, bitM.c_str());
				return g_img;
			}
		}
		rep++;
	}
	// limit powtorzen
	if (rep == 3)
	{
		std::cerr << "Nie wskazales zadnego z plikow .bmp. Program zakonczy dzialanie." << std::endl;
		system("pause");
		exit(1);
	}
}

//----------------------------------------
Interface::Interface() :bitM(""), messageF(""), message(""), choice(0), found(0)
{}

//----------------------------------------
Interface::~Interface()
{
	delete[] g_message;
	delete[] g_pass;
	delete[] g_img;
	_findclose(found);
	file.close();
}