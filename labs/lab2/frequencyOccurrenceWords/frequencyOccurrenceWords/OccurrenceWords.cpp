#include "OccurrenceWords.h"

map <string, int> ReadsAndSearchOccurrenceWords(istream & input, map <string, int> occurrenceWordsMap)
{
	string word;

	cout << "Enter the words: " << endl;
	while (input >> word)
	{
		transform(word.begin(), word.end(), word.begin(), ::tolower);
		++occurrenceWordsMap[word];
	}
	return occurrenceWordsMap;
}
