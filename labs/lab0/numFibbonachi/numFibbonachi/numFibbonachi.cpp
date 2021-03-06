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
			cout << "Argument is not a number.\n";
			return 1;
		}
		if ((number >= 0) && (number < INT_MAX))
		{
			int oldValue = 0;
			int value = 1;
			int nums = 47;
			int hold;
			for (int i = 1; i <= nums; i++)
			{
				if (i == 1)
				{
					value = 0;
				}
				else if (i == 2)
				{
					value = 1;
				}
				else
				{
					hold = value;
					value += oldValue;
					oldValue = hold;
				}
				if (value <= number)
				{
					if ((i % 5 == 0) && (i != 0))
					{
						cout << ", " << value << ",\n";
					}
					else if (i % 5 != 1)
					{
						cout << ", " << value;
					}
					else
					{
						cout << value;
					}
				}
				else
				{
					cout << endl;
					return 0;
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
}