// vector2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "ProcessVector.h"

using namespace std;

void ReadVector(vector<double>& inputVector)
{
	double value;
	while (cin >> value)
	{
		inputVector.push_back(value);
	}
}

void PrintElements(vector<double>& inputVector)
{
	for (size_t i = 0; i < inputVector.size(); ++i)
	{
		cout << inputVector[i] << " ";
	}
	cout << endl;
}

int main()
{
	cout.setf(ios::fixed);
	cout.precision(3);
	vector<double> inputVector;
	ReadVector(inputVector);
	ProcessVector(inputVector);
	sort(inputVector.begin(), inputVector.end());
	PrintElements(inputVector);
    return 0;
}