#include "OccurrenceWords.h"

map <string, int> FillOccurrenceWordsMap(istream & input, map <string, int> occurrenceWordsMap)
{
	string word;
	while (input >> word)
	{
		transform(word.begin(), word.end(), word.begin(), tolower);
		++occurrenceWordsMap[word];
	}
	return occurrenceWordsMap;
}
