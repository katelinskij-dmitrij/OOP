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

map <string, int> outputStringThree;
map <string, int> stringThreeResult = { { "hello", 5 } };
string input3 = "hello \t Hello \n HELLO\n HEllo\t HELLo \n\n";
stringstream inputThree(input3);

map <string, int> outputStringFour;
map <string, int> stringFourResult = {};
string input4 = "\t \n \n \t \n\n";
stringstream inputFour(input4);

TEST_CASE("frequencyOccurrenceWords tests")
{
	outputStringOne = FillOccurrenceWordsMap(inputOne, outputStringOne);
	CHECK(outputStringOne == stringOneResult);
	outputStringTwo = FillOccurrenceWordsMap(inputTwo, outputStringTwo);
	CHECK(outputStringTwo == stringTwoResult);
	outputStringThree = FillOccurrenceWordsMap(inputThree, outputStringThree);
	CHECK(outputStringThree == stringThreeResult);
	outputStringFour = FillOccurrenceWordsMap(inputFour, outputStringFour);
	CHECK(outputStringFour == stringFourResult);
}