#include "Interface.h"

//----------------------------------------
int Interface::ViewMenu() //wpisywanie nazw plików, na potem
{
	choice = 0;

	cout << "======KODOWANIE WIADOMOSCI W BITMAPIE======" << endl;

	while (choice != 1 && choice != 2 && choice != 3)
	{
		cout << "Co chcesz zrobic?" << endl;
		cout << "1 - zakodowac wiadomosc" << endl;
		cout << "2 - odkodowac wiadomosc" << endl;
		cout << "3 - wyjscie" << endl;
		cin >> choice;
	}
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
const char *Interface::GetMessage()
{
	cout << "Podaj nazwe pliku z wiadomoscia" << endl;
	cin >> messageF;
	cout << endl;

	//ewentualne dodanie rozszerzenia
	LookforExtension(messageF, ".txt");
	
	file.open(messageF);
	if (!file)
	{
		cerr << ("Error opening message txt") << endl;
		exit(1);
	}

	string msg;

	//odczyt z pliku
	while (file >> message) 
	{
		file >> msg;
		message += msg;
		message += " ";
	}

	//konwersja do char
	char *a = new char[message.length() + 1];
	strcpy(a, message.c_str());
	return a;
}

//----------------------------------------
const char *Interface::GetPassword()
{
	cout << endl;
	cout << "Podaj haslo do kodowania" << endl;
	cin >> password;

	//konwersja do char
	char *b = new char[password.length()+1];
	strcpy(b, password.c_str());
	return b;
}

//----------------------------------------
char *Interface::GetImage()
{
	cout << endl;
	cout << "Podaj nazwe pliku bmp, w ktorym chcesz ukryc wiadomosc" << endl;
	cin >> bitM;
	cout << endl;

	LookforExtension(bitM, ".bmp");
	char *c = new char[bitM.length() + 1];
	std::strcpy(c, bitM.c_str());
	return c;
}










/*ma to KONIECZNIE zwróciæ char*, nie dzia³a opcja z c_str() bo zwraca to zawsze const'a, ktorego nie da siê potem nigdzie zapisaæ, wymyœl coœ*/
/*jebnij po prostu na char* wszystko wraz z tym ¿e sprawdza czy jest ju¿ .bmp*/
/*wywo³anie w mainie*/
char  *Interface::getImage() 
											
{
	//c//har *a;
	//std::cout << "Podaj nazwe pliku bmp" << std::endl;
	//std::cin >> a;
	
	char *a = "Image.bmp"; //nazwa pliku 
	//const char *c = b.c_str();
	return a;
}

/*Wyœwietla najpierw opcje z wyborem czy kodowaæ czy dekodowaæ, wybór bêdzie returnowany do maina przez metody*/
/*wywo³anie w mainie*/
/*zmienna choice jako sk³adnik prywatny Interface*/
/*w mainie za³o¿y³em ¿e jesli choice == 1 to koduje, a jesli ==2 to dekoduje xd*/





/*wywo³anie w mainie*/




/*wywo³anie w mainie*/
const char *Interface::getPassword() {

	return "elo";
}



Interface::Interface():bitM(""),messageF(""),message(""),choice(1)
{}


Interface::~Interface()
{
	delete[] a;
	delete[] b;
	delete[] c;
}
