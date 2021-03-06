// compare.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
#include<iterator>

using namespace std;


int main(int argc, char * argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count.\n"
			<< "Usage: compare.exe <file1> <file2>.\n";
		return 1;
	}
	ifstream input1(argv[1]), input2(argv[2]);
	if (!input1 || !input2)
	{
		cout << "Files not found.\n";
		return 1;
	}
	if (!input1.is_open())
	{
		cout << "Failed to open " << argv[1] << " for reading.\n";
		return 1;
	}
	if (!input2.is_open())
	{
		cout << "Failed to open " << argv[2] << " for reading.\n";
		return 1;
	}
	string s1, s2;
	int counter = 0;
	while (getline(input1, s1) && getline(input2, s2))
	{
		counter++;
		if ((counter != 0) && (s1 != s2))
		{
			cout << "Files are different. Line number is " << counter << ".\n";
			return 1;
		}
	}
	cout << "Files are equal.\n";
	return 0;

}