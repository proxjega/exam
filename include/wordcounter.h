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
	std::set<std::wstring> _foundwords;
	//std::map<int, std::wstring> lines;
public:
	WordCounterWithUrls() = default;
	~WordCounterWithUrls();
	std::map<std::wstring, std::vector<int>> getWords() const { return _words; }
	std::set<std::wstring> getUrls() const { return _urls; }
	void setWords(const std::map<std::wstring, std::vector<int>>& words) { _words = words; }
	void setUrls(const std::set<std::wstring>& urls) { _urls = urls; }
	void input(std::string filename);
	void output(std::wstring filename);
};