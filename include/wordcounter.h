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
#include <vector>
#include <set>
#include <iomanip>


class WordCounterWithUrls
{
private:
	std::map<std::wstring, std::vector<int>> _words;
	std::set<std::wstring> _urls;
	//std::map<int, std::wstring> lines;
public:
	WordCounterWithUrls() = default;
	~WordCounterWithUrls();
	void input(std::string filename);
	void output(std::wstring filename);
};