#include "../include/libforfunctions.h"


void PrepareUrls(std::vector<std::wstring> &urls ) {
	std::wifstream domainfile("urldomains.txt");
	if (!domainfile) {
		std::wcerr << L"File not found: urldomains.txt" << std::endl;
		return;
	}
	std::wstringstream input;
	input << domainfile.rdbuf();
	domainfile.close();
	while (input) {
		std::wstring url;
		input >> url;
		std::transform(url.begin(), url.end(), url.begin(), ::tolower);
		url = L"." + url;
		//std::wcout << L"URL: " << url << std::endl;
		if (url.length() > 1) {
			urls.push_back(url);
		}
	}
}

void FixWord(std::wstring& word) {

	for (int i = 0; i < word.length(); i++) {
		wchar_t c = word[i];
		if (c == L'1' || c == L'2' || c == L'3' || c == L'4' || c == L'5' || c == L'6' || c == L'7' || c == L'8' || c == L'9' || c == L'0') {
			word.clear();
			//return word;
		}
		if (c == L'[') {
			word = word.substr(0, i);
			//return word;
		}
		if (c == L'/' || c == L'\\' || c == L':' || c == L'*' || c == L'?' || c == L'"' || c == L'<' || c == L'>' || c == L'|' || c == L'#'
			|| c == L'.' || c == L',' || c == L'!' || c == L'@' || c == L'$' || c == L'%' || c == L'^' || c == L'&' || c == L'(' || c == L')'
			|| c == L'-' || c == L'=' || c == L'_' || c == L'„' || c == L'“' || c == L'–') {
			word.erase(word.begin() + i);
			//word.replace(i, 1, L" ");
			i--;
		}
	}
	//return word;
}