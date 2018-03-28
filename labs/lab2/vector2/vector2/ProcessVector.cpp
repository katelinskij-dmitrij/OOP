#include "ProcessVector.h"

std::vector<double> ProcessVector(std::vector<double>& inputVector)
{
	double minValue = inputVector[0];
	for (size_t t = 1; t < inputVector.size(); ++t)
	{
		if (inputVector[t] < minValue)
		{
			minValue = inputVector[t];
		}
	}
	for (size_t i = 0; i < inputVector.size(); ++i)
	{
		inputVector[i] = round(inputVector[i] * minValue * 1000) / 1000;
	}
	return inputVector;
}