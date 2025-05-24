#include "../include/wordcounter.h"
#include "../include/includefunctions.h"
WordCounterWithUrls::~WordCounterWithUrls()
{
	words.clear();
	urls.clear();
}

void WordCounterWithUrls::input(std::string filename) {
	std::wifstream file(filename);
	file.imbue(std::locale(file.getloc(), new std::codecvt_utf8<wchar_t>));
	if (!file) {
		std::wcerr << L"File not found";
		return;
	}
	std::wstringstream input;
	input << file.rdbuf();
	file.close();
	// BEFORE THAT EXTRACT AND DELETE LINKS
	
	// Preparing the output stream 
	std::wstring temp = input.str();
	
	//removing uneccessary characters + lowercase
	for (int i = 0; i < temp.length(); i++) {
		wchar_t &c = temp[i];
		if (c == L'-' || c == L'/' || c == L'–') {
			temp.replace(i, 1, L" ");
			continue;
		}
		c = std::tolower(c);
	}
	std::wcout << L"File content: " << temp << std::endl; //debug
	input.clear();
	input.str(temp);
	temp.clear();

	while (input) {
		std::wstring word;
		input >> word;

		std::wcout << L"Word: " << word << std::endl;
		FixWord(word);
	}
	//MAKE LINE NUMBERS
	//std::wcout << L"File content: " << input.str() << std::endl;
}



