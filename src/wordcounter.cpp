#include "../include/wordcounter.h"

WordCounterWithUrls::~WordCounterWithUrls()
{
	words.clear();
	urls.clear();
}
std::wstring FixWord(std::wstring &word);
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
	// Prepare the output stream 
	std::wstring temp = input.str();
	for (int i = 0; i < temp.length(); i++) {
		wchar_t c = temp[i];
		if (c == L'-' || c == L'/' || c == L'–') {
			temp.replace(i, 1, L" ");
		}
	}
	std::wcout << L"File content: " << temp << std::endl; //debug
	input.clear();
	input.str(temp);

	while (input) {
		std::wstring word;
		input >> word;
		std::transform(word.begin(), word.end(), word.begin(),
			[](wchar_t c) { return std::tolower(c); });
		std::wcout << L"Word: " << word << std::endl;
		FixWord(word);
	}
	//MAKE LINE NUMBERS
	//std::wcout << L"File content: " << input.str() << std::endl;
}

std::wstring FixWord(std::wstring &word) {
	//std::array<wchar_t, 26> arr = { L'/' , L'\\' , L':' , L'*' , L'?' , L'"' , L'<' , L'>' , L'|' , L'#'
	//	, L'.' , L',' , L'!' , L'@' , L'$' , L'%' , L'^' , L'&' , L'(' , L')'
	//	, L'-' , L'=' , L'_' , L'„' , L'“' , L'–' };
	for (int i = 0; i < word.length(); i++) {
		wchar_t c = word[i];
		if (c == L'1' || c == L'2' || c == L'3' || c == L'4' || c == L'5' || c == L'6' || c == L'7' || c == L'8' || c == L'9' || c == L'0') {
			word.clear();
			return word;
		}
		if (c == L'[') {
			std::wcout << L"Fixed word: " << word.substr(0, i) << std::endl;
			word = word.substr(0, i);
			return word;
		}
		if (c == L'/' || c == L'\\' || c == L':' || c == L'*' || c == L'?' || c == L'"' || c == L'<' || c == L'>' || c == L'|' || c == L'#'
			|| c == L'.' || c == L',' || c == L'!' || c == L'@' || c == L'$' || c == L'%' || c == L'^' || c == L'&' || c == L'(' || c == L')'
			|| c == L'-' || c == L'=' || c == L'_' || c == L'„' || c == L'“' || c == L'–') {
			word.erase(word.begin()+i);
			//word.replace(i, 1, L" ");
			i--;
		}
	}
	std::wcout << L"Fixed word: " << word << std::endl;
	return word;
}