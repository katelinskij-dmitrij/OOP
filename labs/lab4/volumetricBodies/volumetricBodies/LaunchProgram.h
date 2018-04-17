#pragma once

#include <iostream>
#include <vector>
#include <regex>
#include <string>
#include <memory>
#include "VolumetricBodies.h"

using namespace std;

class LaunchProgram
{
public:
	LaunchProgram(istream& input, ostream& output, vector<shared_ptr<CBody>>& bodiesArray);
	void ProcessInputCommand(string inputCommand);
	void PrintVolumeBodies()const;
	void PrintMaxMassBody();
	void PrintMinWeightBody();
	void ShowHelpUsage()const;
	shared_ptr<CBody> GetMaxMassBody()const;
	shared_ptr<CBody> GetMinWeightBody()const;

private:
	vector<shared_ptr<CBody>>& m_bodiesArray;
	istream& m_input;
	ostream& m_output;
	void CreateSphere(vector<string> const& parameters);
	void CreateParallelepiped(vector<string> const& parameters);
	void CreateCone(vector<string> const& parameters);
	void CreateCylinder(vector<string> const& parameters);
	void CreateCompound();
	void CallCommand(vector<string>& splitCommand);
};