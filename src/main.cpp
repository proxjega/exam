#include "../include/libformain.h"
#include "../include/includefunctions.h"


void main()
{
	_setmode(_fileno(stdout), _O_WTEXT);
	_setmode(_fileno(stderr), _O_WTEXT);
	WordCounterWithUrls wc;
	//wc.input("text.txt");
	std::vector<std::wstring> urls;
	PrepareUrls(urls);
	for (const auto& url : urls) {
		std::wcout << L"URL: " << url << std::endl;
	}
}