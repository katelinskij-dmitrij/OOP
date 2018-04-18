#pragma once
#include <map>
#include <functional>
#include "Car.h"

using namespace std;

using ActionMap = map<string, function<void(istream & args)>>;

class CCarControl
{
public:
	CCarControl(CCar & car, istream & input, ostream & output);
	bool HandleCommand();
private:
	void Info(istream & input);
	void EngineOn(istream & input);
	void EngineOff(istream & input);
	void SetGear(istream & input);
	void SetSpeed(istream & input);
	CCar & m_car;
	istream & m_input;
	ostream & m_output;
	ActionMap m_actionMap;
};