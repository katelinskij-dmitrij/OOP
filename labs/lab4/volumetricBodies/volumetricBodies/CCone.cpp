#include "CCone.h"

CCone::CCone(double density, double radius, double height) : CBody(TYPENAME_CONE, density)
{
	ValidateBodyArguments(radius, height);
	m_radius = radius;
	m_height = height;
}

void CCone::ValidateBodyArguments(double radius, double height)const
{
	if (radius < 0)
	{
		throw invalid_argument("Radius must be > 0\n");
	}
	else if (height < 0)
	{
		throw invalid_argument("Height must be > 0\n");
	}
}

double CCone::GetBaseRadius()const
{
	return m_radius;
}

double CCone::GetHeight()const
{
	return m_height;
}

double CCone::GetVolume()
{
	return (m_height / 3) * (SimplePow(m_radius, 2) * 3.14);
}

void CCone::ConvertBodyToString(ostream &output)const
{
	output << "Radius: " << GetBaseRadius() << endl;
	output << "Height: " << GetHeight() << endl;
}