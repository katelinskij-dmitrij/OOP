#include "stdafx.h"
#include "Car.h"
#include "CarControl.h"

CCarControl::CCarControl(CCar &car, istream &input, ostream &output)
	: m_car(car)
	, m_input(input)
	, m_output(output)
	, m_actionMap({
		{ "EngineOn", bind(&CCarControl::EngineOn, this, placeholders::_1) },
		{ "EngineOff", bind(&CCarControl::EngineOff, this, placeholders::_1) },
		{ "SetGear", bind(&CCarControl::SetGear, this, placeholders::_1) },
		{ "SetSpeed", bind(&CCarControl::SetSpeed, this, placeholders::_1) },
		{ "Info", bind(&CCarControl::Info, this, placeholders::_1) }
		})
{
}

string GetDirectionString(Direction const & direction)
{
	string result;
	if (direction == Direction::FORWARDS)
	{
		result = "Forwards";
	}
	else if (direction == Direction::BACKWARDS)
	{
		result = "Backwards";
	}
	else
	{
		result = "None";
	}
	return result;
}

bool CCarControl::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);
	string action;
	strm >> action;
	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}
	return false;
}

bool CCarControl::EngineOn(istream &)
{
	bool callback = m_car.TurnOnEngine();
	if (callback)
	{
		m_output << "Car engine was turned on\n";
	}
	else
	{
		m_output << "Car engine is already turned on\n";
	}
	return true;
}

bool CCarControl::EngineOff(istream &)
{
	bool callback = m_car.TurnOffEngine();
	if (callback)
	{
		m_output << "Car engine was turned off\n";
	}
	else
	{
		m_output << "Car engine is already turned off or gear not neutral or car goes\n";
	}
	return true;
}

bool CCarControl::SetGear(istream &args)
{
	int gear;
	args >> gear;
	bool callback = m_car.SetGear(static_cast<Gear>(gear));
	if (callback)
	{
		m_output << "Gear was switched on " << static_cast<int>(m_car.GetGear()) << '\n';
	}
	else
	{
		m_output << "Can't switch gear on " << gear << '\n';
	}
	return true;
}

bool CCarControl::SetSpeed(istream &args)
{
	int speed;
	args >> speed;
	bool callback = m_car.SetSpeed(speed);
	if ((callback) && (m_car.IsEngineTurnOn()))
	{
		m_output << "Speed was changed on " << m_car.GetSpeed() << '\n';
	}
	else
	{
		m_output << "Speed is out of range for current gear or car engine is turned off\n";
	}
	return true;
}

bool CCarControl::Info(istream &)
{
	m_output << "Engine: " << ((m_car.IsEngineTurnOn()) ? "On" : "Off") << '\n'
		<< "Gear: " << static_cast<int>(m_car.GetGear()) << '\n'
		<< "Speed: " << m_car.GetSpeed() << '\n'
		<< "Direction: " << GetDirectionString(m_car.GetDirection()) << '\n';
	return true;
}