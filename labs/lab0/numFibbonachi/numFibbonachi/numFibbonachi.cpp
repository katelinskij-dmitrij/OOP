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

int FunctionFibonachi(int number)

{
	int oldValue = 0;
	int value = 1;
	int hold;
	for (int n = 1; n < number; n++)
	{
		hold = value;
		value += oldValue;
		oldValue = hold;
		if ((oldValue > 0) && (value > (INT_MAX - oldValue))) 
		{
			cout << "Numbers overflow!\n";
			exit(1);
		}
	}
	return(value);
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
		if ((number > 0) && (number <= INT_MAX))
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