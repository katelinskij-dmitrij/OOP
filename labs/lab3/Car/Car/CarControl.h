#pragma once

#include <map>
#include <utility>
#include <iostream>
#include <string>
#include <sstream>
#include <functional>

using namespace std;
using namespace std::placeholders;

class CCar;

class CCarControl
{
public:
	CCarControl(CCar& car, istream& input, ostream& output);
	bool HandleCommand();
private:
	bool EngineOn(istream& args);
	bool EngineOff(istream& args);
	bool Info(istream& args);
	bool SetGear(istream& args);
	bool SetSpeed(istream& args);
private:
	typedef map<string, function<bool(istream& args)>> ActionMap;

	CCar& m_car;
	istream& m_input;
	ostream& m_output;

	const ActionMap m_actionMap;
};
