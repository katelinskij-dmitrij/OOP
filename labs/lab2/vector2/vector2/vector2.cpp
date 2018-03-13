// vector2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<double> inputVector;
	double inputValue;
	while (cin >> inputValue)
	{
		inputVector.push_back(inputValue);
	}
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
		double outputValue;
		inputVector[i] /= minValue;
	}
	for (int i = 0; i < inputVector.size(); ++i)
	{
		cout << inputVector[i] << " ";
	}
	cout << endl;
    return 0;
}