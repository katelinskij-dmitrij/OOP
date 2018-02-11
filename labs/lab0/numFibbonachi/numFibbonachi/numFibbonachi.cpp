// numFibbonachi.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

int StringToInt(const char * str, bool & err)
{
	char * pLastChar = NULL;
	int param = strtol(str, &pLastChar, 10);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;

}

int FunctionFibonachi(int n)
{
	if (n == 1 || n == 0)
	{
		return n;
	}
	else if ((FunctionFibonachi(n - 2) > 0) && (FunctionFibonachi(n - 1) > (INT_MAX)))
	{
		cout << "Numbers overflow!\n";
		exit(0);
	}
	else
	{
		return FunctionFibonachi(n - 1) + FunctionFibonachi(n - 2);
	}
}

int main(int argc, char * argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count.\n"
			<< "Usage: numFibbonachi.exe <number>.\n";
		return 1;
	}
	for (int i = 1; i < argc; ++i)
	{
		bool err;
		int number = StringToInt(argv[i], err);
		if (err)
		{
			printf("Argument is not a number\n.", i);
			return 1;
		}
		if (number > 0)
		{
			for (int i = 1; i <= number; i++)
			{
				cout << FunctionFibonachi(i);
				if ((i % 5 == 0) && (i != 0) && (i != number))
				{ 
					cout << ",\n";  
				}
				else if (i != number)
				{
					cout << ", ";
				}
			}
			cout << endl;
		}
		else
		{
			cout << "Number is not correct.\n";
			return 1;
		}
	}
	return 0;
}