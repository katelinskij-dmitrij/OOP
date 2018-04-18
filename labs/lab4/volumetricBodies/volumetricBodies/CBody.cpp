#include "CBody.h"

CBody::CBody(const std::string& type) : m_type(type),
	m_density(0.0)
{
}

CBody::CBody(const string& figureType, double density) : m_type(figureType)
{
	ValidateBodyArguments(density);
	m_density = density;
}

void CBody::ValidateBodyArguments(double density)const
{
	if (density < 0)
	{
		throw invalid_argument("Density must be > 0\n");
	}
}

double CBody::GetDensity()
{
	return m_density;
}

double CBody::GetVolume()
{
	return m_volume;
}

double CBody::GetMass()
{
	return GetDensity() * GetVolume();
}

void CBody::ConvertBodyToString(ostream&)const
{
}

string CBody::ToString()
{
	ostringstream output;
	output << fixed << showpoint;
	output << setprecision(2);
	output << "Type: " << m_type << endl;
	output << "Density: " << GetDensity() << endl;
	output << "Volume: " << GetVolume() << endl;
	output << "Mass: " << GetMass() << endl;
	ConvertBodyToString(output);
	return output.str();
}

string CBody::GetType()const
{
	return m_type;
}