#pragma once

#include "CBody.h"
#include <math.h>
#include <iostream>

class CSphere : public CBody
{
public:
	CSphere(double density, double radius);

	double GetRadius()const;
	double GetVolume() override;

private:
	double m_radius;

	void ValidateBodyArguments(double radius)const;


protected:
	void ConvertBodyToString(ostream &output)const override;
};