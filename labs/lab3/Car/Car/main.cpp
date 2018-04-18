#include "stdafx.h"
#include "Car.h"
#include "CarControl.h"

int main()
{
	CCar car;
	CCarControl virtualControl(car, cin, cout);

	while (!cin.eof())
	{
		cout << "Enter the command:\n";
		if (!virtualControl.HandleCommand())
		{
			cout << "Unknown command!\n";
		}
	}
	return 0;
}