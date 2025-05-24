#include "../include/wordcounter.h"
#include "../include/includefunctions.h"
WordCounterWithUrls::~WordCounterWithUrls()
{
	_words.clear();
	_urls.clear();
}

void WordCounterWithUrls::input(std::string filename) {
	std::wifstream file(filename);
	file.imbue(std::locale(file.getloc(), new std::codecvt_utf8<wchar_t>));
	if (!file) {
		throw std::runtime_error("File not found: " + filename);
		return;
	}
	std::wstringstream input;
	input << file.rdbuf();
	file.close();
	std::vector<std::wstring> urldomains;
	PrepareUrls(urldomains);
	// extracting URLs from the input stream
	int counter = 0;
	for (std::wstring line; std::getline(input, line); counter++) {
		std::transform(line.begin(), line.end(), line.begin(), 
			[](wchar_t c) { return std::tolower(c, std::locale());});
		std::wstring inputAfterUrls;
		std::wstringstream lineinput(line);
		while (lineinput) {
			std::wstring word;
			lineinput >> word;
			if (word.length() < 2) {
				continue; //skip short words
			}
			for (const auto& urldomain : urldomains) {
				if (word.find(urldomain) != std::wstring::npos) {
					if (word.find(L"[") != std::wstring::npos) {
						word = word.substr(0, word.find(L"["));
					}
					_urls.insert(word);
					word.clear();
				}
			}
			inputAfterUrls += word + L" "; // Collecting words after URLs are removed
		}

		// Preparing the output stream : removing uneccessary characters
		for (int i = 0; i < inputAfterUrls.length(); i++) {
			wchar_t& c = inputAfterUrls[i];
			if (c == L'-' || c == L'/' || c == L'–') {
				inputAfterUrls.replace(i, 1, L" ");
				continue;
			}
		}
		//std::wcout << L"File content after url removal and preparation: " << inputAfterUrls << std::endl; //debug
		lineinput.clear();
		lineinput.str(inputAfterUrls);
		inputAfterUrls.clear();

		while (lineinput) {
			std::wstring word;
			lineinput >> word;

			//std::wcout << L"Word: " << word << std::endl; //debug
			FixWord(word);
			//std::wcout << L"Fixed word: " << word << std::endl; //debug
			if (word.empty()) {
				continue; 
			}
			if (_words[word].size() == 0) _words[word].push_back(1);
			else _words[word][0]++; 
			_words[word].push_back(counter); 
		}
	}

	
}

void WordCounterWithUrls::output(std::wstring filename) {
	std::wofstream outputFile(filename);
	outputFile.imbue(std::locale(outputFile.getloc(), new std::codecvt_utf8<wchar_t>));
	for (const auto& pair : _words) {
		outputFile << L"Word: " << pair.first << L", Count: " << pair.second[0] << L", Lines: ";
		for (size_t i = 1; i < pair.second.size(); ++i) {
			outputFile << pair.second[i] << (i < pair.second.size() - 1 ? L", " : L"");
		}
		outputFile << std::endl;
	}
	for (const auto& url : _urls) {
		outputFile << L"URL found: " << url << std::endl; //debug
	}
}



