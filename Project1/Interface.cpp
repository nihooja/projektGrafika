#include "Interface.h"

//----------------------------------------
int Interface::ViewMenu() //wpisywanie nazw plików, na potem
{
	rep = 0;

	cout << "======KODOWANIE WIADOMOSCI W BITMAPIE======" << endl;

	while (choice != 1 && choice != 2 && choice != 3 && rep < 3)
	{
		cout << "Wybierz opcje?" << endl;
		cout << "1 - zakodowac wiadomosc" << endl;
		cout << "2 - odkodowac wiadomosc" << endl;
		cout << "3 - wyjscie" << endl;
		cin >> choice;
		rep++;
	}

	if (rep == 3)
		choice = 3;

	return choice;
}

//----------------------------------------
void Interface::LookforExtension(string &text, string search)
{
	size_t found = text.find(search);

	if (found == string::npos) // nie wpisali
	{
		text += search;
	}
	else return;
}

//----------------------------------------
/*string getexepath()
{
	char result[MAX_PATH];
	string q = string(result, GetModuleFileName(NULL, result, MAX_PATH));
	cout << q;
	return q;
}
*/
//----------------------------------------
/*bool Interface::FindBmp(int argc, TCHAR *argv[])
{

	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;

	if (argc != 2)
	{
		_tprintf(TEXT("Usage: %s [target_file]\n"), argv[0]);
		return;
	}

	_tprintf(TEXT("Target file is %s\n"), argv[1]);
	hFind = FindFirstFile(argv[1], &FindFileData);
	if (hFind == INVALID_HANDLE_VALUE)
	{
		printf("FindFirstFile failed (%d)\n", GetLastError());
		return;
	}
	else
	{
		_tprintf(TEXT("The first file found is %s\n"),
			FindFileData.cFileName);
		FindClose(hFind);
	}
}*/
//----------------------------------------
const char *Interface::GetMessage()
{
	rep = 0;

	while (rep < 3)
	{
		//nazwa pliku
		cout << "Podaj nazwe pliku z wiadomoscia" << endl;
		cin >> messageF;
		cout << endl;

		//ewentualne dodanie rozszerzenia
		LookforExtension(messageF, ".txt");

		//otwieranie pliku
		file.open(messageF);
		if (file)
		{
			string msg;

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
				cerr << ("Blad! Plik jest pusty!") << endl;
				rep++;
			}
			//jesli nie jest pusty, konwersja do char
			else
			{	
				char *a = new char[message.length() + 1];
				strcpy(a, message.c_str());
				return a;
			}
		}
		//jesli nie ma takiego pliku
		else
			rep++;
	}

	//jesli nie znalazl do konca
	if (message == "" && rep == 3)
	{
		cerr << ("Blad otwierania pliku. Program zakonczy dzialanie.") << endl;
		system("pause");
		exit(1);
	}
}

//----------------------------------------
const char *Interface::GetPassword()
{
	rep = 0;
	while (password == "" && rep < 3)
	{
		cout << endl;
		cout << "Podaj haslo do kodowania" << endl;
		cin >> password;
		rep++;
	}

	//jesli ktos bardzo nie chce wpisac hasla
	if (password == "" && rep == 3)
	{
		cerr << ("Blad wpisywania hasla. Program zakonczy dzialanie.") << endl;
		system("pause");
		exit(1);
	}

	//konwersja hasla do char
	char *b = new char[password.length()+1];
	strcpy(b, password.c_str());
	return b;
}

//----------------------------------------
char *Interface::GetImage()
{
	rep = 0;

		//Nazwa pliku
		cout << "Podaj nazwe pliku bmp, w ktorym chcesz ukryc wiadomosc" << endl;
		cin >> bitM;
		cout << endl;

		//ewentualne dodanie rozszerzenia
		LookforExtension(bitM, ".bmp");

		char *c = new char[bitM.length() + 1];
		std::strcpy(c, bitM.c_str());
		return c;

}

//----------------------------------------
Interface::Interface()
{
	bitM = "";
	messageF = "";
	message = "";
	choice = 0;
//	found = false;
}

//----------------------------------------
Interface::~Interface()
{
	delete[] a;
	delete[] b;
	delete[] c;
}