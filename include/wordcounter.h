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


class WordCounterWithUrls
{
private:
	std::map<std::wstring, std::vector<int>> words;
	std::set<std::wstring> urls;
	//std::map<int, std::wstring> lines;
public:
	WordCounterWithUrls() = default;
	~WordCounterWithUrls();
	void input(std::string filename);
	void output();
};