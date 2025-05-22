#include "../include/libformain.h"



void main()
{
	_setmode(_fileno(stdout), _O_WTEXT);
	_setmode(_fileno(stderr), _O_WTEXT);
	WordCounterWithUrls wc;
	wc.input("text.txt");
}