// vector2Tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

std::vector<double> ProcessVector(std::vector<double>& inputVector);

std::vector<double> vectorOne = { 2, 4, 2 };
std::vector<double> vectorOneResult = { 4, 8, 4 };

std::vector<double> vectorTwo = { 10, 9, 20, 2, 3, 30, 6, 5 };
std::vector<double> vectorTwoResult = { 20, 18, 40, 4, 6, 60, 12, 10 };

std::vector<double> vectorThree = { 2.2, 4, 8, 16 };
std::vector<double> vectorThreeResult = { 4.84, 8.8, 17.6, 35.2};

TEST_CASE("vector2 tests")
{
	ProcessVector(vectorOne);
	CHECK(vectorOne == vectorOneResult);
	ProcessVector(vectorTwo);
	CHECK(vectorTwo == vectorTwoResult);
	ProcessVector(vectorThree);
	CHECK(vectorThree == vectorThreeResult);
}

std::vector<double> ProcessVector(std::vector<double>& inputVector)
{
	double minValue = inputVector[0];
	for (int t = 1; t < inputVector.size(); ++t)
	{
		if (inputVector[t] < minValue)
		{
			minValue = inputVector[t];
		}
	}
	for (int i = 0; i < inputVector.size(); ++i)
	{
		inputVector[i] = std::round(inputVector[i] * minValue * 1000) / 1000;
	}
	return inputVector;
}