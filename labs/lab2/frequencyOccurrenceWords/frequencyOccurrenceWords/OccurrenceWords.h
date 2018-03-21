#pragma once
#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

map <string, int> ReadsAndSearchOccurrenceWords(istream & input, map <string, int> occurrenceWordsMap);