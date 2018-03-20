// vector2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

using namespace std;

void ReadVector(vector<double>& inputVector)
{
	double value;
	while (cin >> value)
	{
		inputVector.push_back(value);
	}
}

vector<double> ProcessVector(vector<double>& inputVector)
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
		inputVector[i] = round(inputVector[i] * minValue * 1000) / 1000;
	}
	return inputVector;
}

void PrintElements(vector<double>& inputVector)
{
	for (int i = 0; i < inputVector.size(); ++i)
	{
		cout << inputVector[i] << " ";
	}
	cout << endl;
}

int main()
{
	vector<double> inputVector;
	ReadVector(inputVector);
	ProcessVector(inputVector);
	sort(inputVector.begin(), inputVector.end());
	PrintElements(inputVector);
    return 0;
}