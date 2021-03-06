#pragma once

#include "CBody.h"
#include <math.h>
#include <iostream>

class CCone : public CBody
{
public:
	CCone(double density, double radius, double height);
	double GetVolume() override;
	double GetHeight()const;
	double GetBaseRadius()const;

private:
	double m_radius;
	double m_height;
	void ValidateBodyArguments(double radius, double height)const;

protected:
	void ConvertBodyToString(ostream &output)const override;
};