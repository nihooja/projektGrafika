#pragma once
#include "Image.h"
/*dziedziczy po klasie Image, dzieki temu bêdzie mieæ wszystkie metody co Image, bez pierdolenia siê*/
/*a bêdzie Image potrzebny bo jakoœ trzeba bêdzie na tym obrazie dzia³ac*/
/*A sama klasa Steganography niech zawiera tylko algorytmy koduj¹ce i dekoduj¹ce*/
class Steganography:Image
{
public:
	
	Steganography();
	~Steganography();
};

