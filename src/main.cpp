#include "../include/libformain.h"
#include "../include/includefunctions.h"


void main()
{
	_setmode(_fileno(stdout), _O_WTEXT);
	_setmode(_fileno(stderr), _O_WTEXT);
	WordCounterWithUrls wc;
	while (true)
	{
		std::wcout << L"Enter the filename to process (or 'exit' to quit): \n";
		system("dir /b *.txt");
		std::wstring filename;
		std::getline(std::wcin, filename);
		if (filename == L"exit") {
			break;
		}
		try {
			wc.input(std::string(filename.begin(), filename.end()));
		}
		catch (const std::runtime_error& e) {
			std::wcerr << L"Error: " << e.what() << std::endl;
			continue;
		}
		std::wcout << L"Processing file: " << filename << std::endl;
		std::wcout << L"Enter the filename to save the results (or 'exit' to quit): \n";
		std::wstring outputFilename;
		std::getline(std::wcin, outputFilename);
		if (outputFilename == L"exit") {
			break;
		}
		std::wcout << L"Saving results to: " << outputFilename << std::endl;
		wc.output(outputFilename);
		break;
	}
	
}