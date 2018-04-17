#pragma once

#include "ShapeTypes.h"
#include "AuxiliaryFunctions.h"
#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>

using namespace std;

class CBody
{
public:
	CBody(const string& figureType);
	CBody(const string& figureType, double density);

	virtual double GetDensity();
	virtual double GetVolume();
	virtual double GetMass();
	virtual string ToString() final;

	string GetType()const;

private:
	void ValidateBodyArguments(double density)const;

protected:
	string m_type;
	double m_density;
	double m_volume;

	virtual void ConvertBodyToString(ostream& output)const;
};