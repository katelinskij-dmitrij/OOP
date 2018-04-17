#include "CSphere.h"

CSphere::CSphere(double density, double radius) : CBody(TYPENAME_SPHERE, density)
{
	ValidateBodyArguments(radius);
	m_radius = radius;
}

void CSphere::ValidateBodyArguments(double radius)const
{
	if (radius < 0)
	{
		throw invalid_argument("Radius must be > 0\n");
	}
}

double CSphere::GetRadius()const
{
	return m_radius;
}

double CSphere::GetVolume()
{
	return (4 / 3) * 3.14 * SimplePow(GetRadius(), 3);
}

void CSphere::ConvertBodyToString(ostream &output)const
{
	output << "Radius: " << GetRadius() << endl;
}