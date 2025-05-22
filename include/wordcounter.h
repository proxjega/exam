#pragma once
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <io.h>
#include <fcntl.h>
#include <locale>
#include <codecvt>
#include <algorithm>
#include <array>


class WordCounterWithUrls
{
private:
	std::map<std::wstring, int> words;
	std::map<std::wstring, int> urls;
	std::map<int, std::wstring> lines;
public:
	WordCounterWithUrls() = default;
	~WordCounterWithUrls();
	void input(std::string filename);
	void output();
};