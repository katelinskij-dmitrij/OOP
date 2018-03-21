// frequencyOccurrenceWordsTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../frequencyOccurrenceWords/OccurrenceWords.h"

using namespace std;

map <string, int> outputStringOne;
map <string, int> stringOneResult = { { "hello", 5 } };
string input1 = "hello Hello HELLO HEllo HELLo";
stringstream inputOne(input1);

map <string, int> outputStringTwo;
map <string, int> stringTwoResult = { { "best", 3 },
{ "fedya", 3 },
{ "in", 2 },
{ "is", 3 },
{ "programmer", 2 },
{ "the", 4 },
{ "world", 2 } };
string input2("Fedya FEDYA FedyA Is is IS the THe THE best BEST beST PROGRAMMER programmer in IN The WORLD world");
stringstream inputTwo(input2);

TEST_CASE("frequencyOccurrenceWords tests")
{
	outputStringOne = ReadsAndSearchOccurrenceWords(inputOne, outputStringOne);
	CHECK(outputStringOne == stringOneResult);
	outputStringTwo = ReadsAndSearchOccurrenceWords(inputTwo, outputStringTwo);
	CHECK(outputStringTwo == stringTwoResult);
}