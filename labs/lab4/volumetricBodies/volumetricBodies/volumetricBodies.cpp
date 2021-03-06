// volumetricBodies.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "LaunchProgram.h"

int main()
{
	string inputString;
	vector<shared_ptr<CBody>> bodiesArray;
	LaunchProgram LaunchProgram(cin, cout, bodiesArray);
	LaunchProgram.ShowHelpUsage();
	while (getline(cin, inputString))
	{
		try
		{
			LaunchProgram.ProcessInputCommand(inputString);
		}
		catch (const invalid_argument& e)
		{
			cout << e.what() << endl;
		}
	}
	LaunchProgram.PrintVolumeBodies();
	LaunchProgram.PrintMaxMassBody();
	LaunchProgram.PrintMinWeightBody();
	return 0;
}