#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class CVector3D
{
public:
	CVector3D();

	CVector3D(double x0, double y0, double z0);

	double GetLength()const;
	void Normalize();
	static double DotProduct(CVector3D const& v1, CVector3D const& v2);
	static CVector3D CrossProduct(CVector3D const& v1, CVector3D const& v2);
	static CVector3D Normalize(CVector3D const& v);

	CVector3D const operator +(CVector3D const& vector3)const;
	CVector3D const operator -(CVector3D const& vector3)const;
	CVector3D const operator *(double scalar) const;
	CVector3D const operator /(double scalar) const;
	CVector3D const operator -() const;
	CVector3D const operator +() const;
	CVector3D const operator +=(CVector3D const& vector3);
	CVector3D const operator -=(CVector3D const& vector3);
	CVector3D const operator /=(double scalar);
	CVector3D const operator *=(double scalar);
	bool operator ==(CVector3D const& vector3) const;
	bool operator !=(CVector3D const& vector3) const;

	double x, y, z;
};

CVector3D const operator *(double scalar, CVector3D const& vector3);
ostream& operator <<(ostream& stream, CVector3D const& vector3);
istream& operator >>(istream& stream, CVector3D& vector3);