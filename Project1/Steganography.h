#pragma once
#include "Image.h"
/*dziedziczy po klasie Image, dzieki temu b�dzie mie� wszystkie metody co Image, bez pierdolenia si�*/
/*a b�dzie Image potrzebny bo jako� trzeba b�dzie na tym obrazie dzia�ac*/
/*A sama klasa Steganography niech zawiera tylko algorytmy koduj�ce i dekoduj�ce*/
class Steganography:Image
{
public:
	
	Steganography();
	~Steganography();
};

