#include "stdafx.h"
#include "Car.h"
#include "CarControl.h"

CCarControl::CCarControl(CCar& car, istream& input, ostream& output)
	: m_car(car)
	, m_input(input)
	, m_output(output)
	, m_actionMap({ { "Info", bind(&CCarControl::Info, this, placeholders::_1) },
		{ "EngineOn", bind(&CCarControl::EngineOn, this, placeholders::_1) },
		{ "EngineOff", bind(&CCarControl::EngineOff, this, placeholders::_1) },
		{ "SetGear", bind(&CCarControl::SetGear, this, placeholders::_1) },
		{ "SetSpeed", bind(&CCarControl::SetSpeed, this, placeholders::_1) } })
{
}

bool CCarControl::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strstream(commandLine);
	string action;
	strstream >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		it->second(strstream);
		return true;
	}
	return false;
}

void CCarControl::Info(istream& input)
{
	string statusEngine = m_car.IsEngineTurnOn() ? "on" : "off";

	m_output << "Engine is turned " + statusEngine << endl;
	m_output << "Gear is " << static_cast<int>(m_car.GetGear()) << endl;
	m_output << "Direction is " << static_cast<int>(m_car.GetDirection()) << endl;
	m_output << "Speed is " << m_car.GetSpeed() << endl;
}

void CCarControl::EngineOn(istream& input)
{
	if (m_car.TurnOnEngine())
	{
		m_output << "Engine was turned on" << endl;
	}
	else
	{
		m_output << "Engine is already turned on" << endl;
	}
}

void CCarControl::EngineOff(istream& input)
{
	if (m_car.TurnOffEngine())
	{
		m_output << "Engine was turned off" << endl;
		return;
	}
	if (m_car.GetGear() != Gear::Neutral || m_car.GetSpeed() != 0)
	{
		m_output << "Engine was not turned off" << endl;
		return;
	}
	m_output << "Engine is already turned off" << endl;
}

void CCarControl::SetGear(istream& input)
{
	if (!m_car.IsEngineTurnOn())
	{
		m_output << "Error: Engine was not turned on" << endl;
		return;
	}
	int gear;
	input >> gear;
	if (!m_car.SetGear(static_cast<Gear>(gear)))
	{
		m_output << "Gear wasn't change" << endl;
		return;
	}
	m_output << "Gear was change" << endl;
}

void CCarControl::SetSpeed(istream& input)
{
	if (m_car.IsEngineTurnOn())
	{
		int speed;
		input >> speed;
		if (speed > 0)
		{
			if (m_car.SetSpeed(speed))
			{
				m_output << "Speed was change" << endl;
				return;
			}
		}
		m_output << "Speed wasn't change" << endl;
		return;

	}
	m_output << "Error: Engine was not turned on" << endl;
}