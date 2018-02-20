// multmatrix.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

bool ReadMatrix(ifstream & inputFile, vector<vector<double>> & matrix)
{
	for (size_t i = 0; i < 3; ++i)
	{
		vector<double> row;
		for (size_t j = 0; j < 3; ++j)
		{
			if (!inputFile.eof())
			{
				double element;
				inputFile >> element;
				row.push_back(element);
			}
			else
			{
				return false;
			}
		}
		matrix.push_back(row);
	}
	return true;
}

void PrintMatrix(const vector<vector<double>> & matrix)
{
	for (size_t i = 0; i < matrix.size(); ++i)
	{
		for (size_t j = 0; j < matrix[i].size(); ++j)
		{
			cout << fixed << setprecision(3) << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Error: invalid arguments count.\n";
		cout << "Usage: multmatrix.exe <matrix file1> <matrix file1>\n";
		return 1;
	}

	ifstream inputFile1(argv[1]);
	if (!inputFile1.is_open())
	{
		cout << "Error: failed to open " << argv[1] << "for reading.\n";
		return 1;
	}

	ifstream inputFile2(argv[2]);
	if (!inputFile2.is_open())
	{
		cout << "Error: failed to open " << argv[2] << "for reading.\n";
		return 1;
	}

	vector<vector<double>> matrix1;
	if (!ReadMatrix(inputFile1, matrix1))
	{
		cout << "Error. The matrix is not read.\n";
		return 1;
	}

	vector<vector<double>> matrix2;
	if (!ReadMatrix(inputFile2, matrix2))
	{
		cout << "Error. The matrix is not read.\n";
		return 1;
	}
	vector<vector<double>> resultMatrix(3, vector<double>(3));
	for (size_t row = 0; row < 3; row++) 
	{
		for (size_t col = 0; col < 3; col++)
		{
			for (size_t inner = 0; inner < 3; inner++)
			{
				resultMatrix[row][col] += matrix1[row][inner] * matrix2[inner][col];
			}
		}
	}
	PrintMatrix(resultMatrix);
	return 0;
}