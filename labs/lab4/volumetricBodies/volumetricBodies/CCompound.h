#pragma once

#include "CBody.h"
#include "VolumetricBodies.h"
#include <iostream>
#include <vector>
#include <memory>

class CCompound : public CBody
{
public:
	CCompound();
	bool AddChildBody(shared_ptr<CBody> const& childBody);
	double GetMass() override;
	double GetVolume() override;

private:
	vector<shared_ptr<CBody>> m_childBodies;
	bool IsValidBody(shared_ptr<CBody> const& childBody)const;
	void SetCompoundDensity();

protected:
	void ConvertBodyToString(ostream &output)const override;
};