// volumetricBodiesTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../volumetricBodies/VolumetricBodies.h"
#include "../volumetricBodies/LaunchProgram.h"
#include "../volumetricBodies/AuxiliaryFunctions.h"

using namespace std;

TEST_CASE("Auxiliary Functions Tests")
{
	cout << "Auxiliary Functions Tests" << endl;
	CHECK(pow(10, 2) == SimplePow(10, 2));
	CHECK(pow(5, 3) == SimplePow(5, 3));
	CHECK(pow(2.75, 2) == SimplePow(2.75, 2));
}

CSphere sphere(10.0, 20.0);

TEST_CASE("Sphere Tests")
{
	cout << "Sphere Tests" << endl;
	CHECK(sphere.GetType() == TYPENAME_SPHERE);
	CHECK(sphere.GetDensity() == 10.0);
	CHECK(sphere.GetRadius() == 20.0);
	CHECK(sphere.GetVolume() == (4 / 3) * 3.14 * SimplePow(20.0, 3));
	CHECK(sphere.GetMass() == sphere.GetDensity() * sphere.GetVolume());
	string expectedString = "Type: sphere\n"
		"Density: 10.00\n"
		"Volume: 25120.00\n"
		"Mass: 251200.00\n"
		"Radius: 20.00\n";
	CHECK(sphere.ToString() == expectedString);
}

CCone cone(10.0, 20.0, 5.0);

TEST_CASE("Cone Tests")
{
	cout << "Cone Tests" << endl;
	CHECK(cone.GetType() == TYPENAME_CONE);
	CHECK(cone.GetDensity() == 10.0);
	CHECK(cone.GetBaseRadius() == 20.0);
	CHECK(cone.GetHeight() == 5.0);
	double expectedTesingVolume = (5.0 / 3) * (SimplePow(20.0, 2) * 3.14);
	CHECK(cone.GetVolume() == expectedTesingVolume);
	string expectedString = "Type: cone\n"
		"Density: 10.00\n"
		"Volume: 2093.33\n"
		"Mass: 20933.33\n"
		"Radius: 20.00\n"
		"Height: 5.00\n";
	CHECK(cone.ToString() == expectedString);
}

CParallelepiped parallelepiped(10.0, 20.0, 5.0, 15.0);

TEST_CASE("Parallelepiped Tests")
{
	cout << "Parallelepiped Tests" << endl;
	CHECK(parallelepiped.GetType() == TYPENAME_PARALLELEPIPED);
	CHECK(parallelepiped.GetDensity() == 10.0);
	CHECK(parallelepiped.GetWidth() == 20.0);
	CHECK(parallelepiped.GetHeight() == 5.0);
	CHECK(parallelepiped.GetDepth() == 15.0);
	CHECK(parallelepiped.GetVolume() == 20.0 * 5.0 * 15.0);
	CHECK(parallelepiped.GetMass() == (20.0 * 5.0 * 15.0) * 10);
	string expectedString = "Type: parallelepiped\n"
		"Density: 10.00\n"
		"Volume: 1500.00\n"
		"Mass: 15000.00\n"
		"Width: 20.00\n"
		"Height: 5.00\n"
		"Depth: 15.00\n";
	CHECK(parallelepiped.ToString() == expectedString);
}

CCylinder cylinder(10.0, 20.0, 5.0);

TEST_CASE("Cylinder Tests")
{
	cout << "Cylinder Tests" << endl;
	CHECK(cylinder.GetType() == TYPENAME_CYLINDER);
	CHECK(cylinder.GetDensity() == 10.0);
	CHECK(cylinder.GetBaseRadius() == 20.0);
	CHECK(cylinder.GetHeight() == 5.0);
	CHECK(cylinder.GetVolume() == 3.14 * SimplePow(20.0, 3) * 5.0);
	string expectedString = "Type: cylinder\n"
		"Density: 10.00\n"
		"Volume: 125600.00\n"
		"Mass: 1256000.00\n"
		"Radius: 20.00\n";
	CHECK(cylinder.ToString() == expectedString);
}

shared_ptr<CBody> cylinderPtr = make_shared<CCylinder>(1, 1, 2);
shared_ptr<CBody> conePtr = make_shared<CCone>(10, 2, 1);
shared_ptr<CBody> parallelepipedPtr = make_shared<CParallelepiped>(2, 2, 2, 2);
shared_ptr<CBody> spherePtr = make_shared<CSphere>(1, 2);
shared_ptr<CCompound> compoundPtr1 = make_shared<CCompound>();

TEST_CASE("Compound Tests")
{
	cout << "Compound Tests" << endl;
	SECTION("Add Valid Simple Bodies Childs")
	{
		cout << "Add Valid Simple Bodies Childs" << endl;
		CHECK(compoundPtr1->AddChildBody(cylinderPtr));
		CHECK(compoundPtr1->AddChildBody(conePtr));
		CHECK(compoundPtr1->AddChildBody(parallelepipedPtr));
		CHECK(compoundPtr1->AddChildBody(spherePtr));
	}
	SECTION("Add Compound To Childs")
	{
		cout << "Add Compound To Childs" << endl;
		CCompound testingCompound;
		shared_ptr<CBody> testingCompoundPtr = make_shared<CCompound>(testingCompound);
		CHECK(testingCompound.AddChildBody(cylinderPtr));
		CHECK(testingCompound.AddChildBody(conePtr));
		CHECK(compoundPtr1->AddChildBody(testingCompoundPtr));
	}
	SECTION("Get Mass On Empty Bodies Array")
	{
		cout << "Get Mass On Empty Bodies Array" << endl;
		shared_ptr<CCompound> compoundPtr2 = make_shared<CCompound>();
		CHECK(compoundPtr2->GetMass() == 0);
	}
	SECTION("Get Min Weight In Water On Empty Bodies Array")
	{
		cout << "Get Min Weight In Water On Empty Bodies Array" << endl;
		shared_ptr<CCompound> compoundPtr2 = make_shared<CCompound>();
		CHECK(compoundPtr2->GetMass() == 0);
	}
	SECTION("Get Mass On Fill Bodies Array")
	{
		cout << "Get Mass On Fill Bodies Array" << endl;
		shared_ptr<CCompound> compoundPtr3 = make_shared<CCompound>();
		compoundPtr3->AddChildBody(cylinderPtr);
		CHECK(compoundPtr3->GetMass() == cylinderPtr->GetMass());
		compoundPtr3->AddChildBody(conePtr);
		CHECK(compoundPtr3->GetMass() == conePtr->GetMass() + cylinderPtr->GetMass());
	}
	SECTION("Empty Compound Volume Is Zero")
	{
		cout << "Empty Compound Volume Is Zero" << endl;
		shared_ptr<CCompound> compoundPtr4 = make_shared<CCompound>();
		CHECK(compoundPtr4->GetVolume() == 0);
	}
	SECTION("Compound Volume With One Body EQVolume")
	{
		cout << "Compound Volume With One Body EQVolume" << endl;
		shared_ptr<CCompound> compoundPtr5 = make_shared<CCompound>();
		compoundPtr5->AddChildBody(parallelepipedPtr);
		CHECK(compoundPtr5->GetVolume() == parallelepipedPtr->GetVolume());
	}
	SECTION("Compound Volume With Two Body EQMass And Volume")
	{
		cout << "Compound Volume With Two Body EQMass And Volume" << endl;
		shared_ptr<CCompound> compoundPtr6 = make_shared<CCompound>();
		compoundPtr6->AddChildBody(parallelepipedPtr);
		compoundPtr6->AddChildBody(cylinderPtr);
		CHECK(compoundPtr6->GetVolume() == parallelepipedPtr->GetVolume() + cylinderPtr->GetVolume());
	}
	SECTION("Empty Compound Density Is Zero")
	{
		cout << "Empty Compound Density Is Zero" << endl;
		shared_ptr<CCompound> compoundPtr7 = make_shared<CCompound>();
		CHECK(compoundPtr7->GetDensity() == 0);
	}
	SECTION("Compound Density With One Body EQDensity")
	{
		cout << "Compound Density With One Body EQDensity" << endl;
		shared_ptr<CCompound> compoundPtr8 = make_shared<CCompound>();
		compoundPtr8->AddChildBody(parallelepipedPtr);
		CHECK(compoundPtr8->GetDensity() == parallelepipedPtr->GetDensity());
	}
	SECTION("Compound Density With Two Body EQMass And Volume Division")
	{
		cout << "Compound Density With Two Body EQMass And Volume Division" << endl;
		shared_ptr<CCompound> compoundPtr9 = make_shared<CCompound>();
		compoundPtr9->AddChildBody(cylinderPtr);
		compoundPtr9->AddChildBody(parallelepipedPtr);
		double expectedDensity = (cylinderPtr->GetMass() + parallelepipedPtr->GetMass()) /
			(cylinderPtr->GetVolume() + parallelepipedPtr->GetVolume());
		CHECK(compoundPtr9->GetDensity() == expectedDensity);
	}
	SECTION("Empty Compound To String")
	{
		cout << "Empty Compound To String" << endl;
		shared_ptr<CCompound> compoundPtr10 = make_shared<CCompound>();
		string expectedString =
			"Type: compound\n"
			"Density: 0.00\n"
			"Volume: 0.00\n"
			"Mass: 0.00\n"
			"Childs (0): \n"
			"No childs \n";
		CHECK(compoundPtr10->ToString() == expectedString);
	}
	SECTION("Compound To String")
	{
		cout << "Compound To String" << endl;
		shared_ptr<CCompound> compoundPtr11 = make_shared<CCompound>();
		compoundPtr11->AddChildBody(spherePtr);
		string expectedString =
			"Type: compound\n"
			"Density: 1.00\n"
			"Volume: 25.12\n"
			"Mass: 25.12\n"
			"Childs (1): \n"
			"Type: sphere\n"
			"Density: 1.00\n"
			"Volume: 25.12\n"
			"Mass: 25.12\n"
			"Radius: 2.00\n\n";
		CHECK(compoundPtr11->ToString() == expectedString);
		compoundPtr11->AddChildBody(cylinderPtr);
		expectedString =
			"Type: compound\n"
			"Density: 1.00\n"
			"Volume: 31.40\n"
			"Mass: 31.40\n"
			"Childs (2): \n"
			"Type: sphere\n"
			"Density: 1.00\n"
			"Volume: 25.12\n"
			"Mass: 25.12\n"
			"Radius: 2.00\n\n"
			"Type: cylinder\n"
			"Density: 1.00\n"
			"Volume: 6.28\n"
			"Mass: 6.28\n"
			"Radius: 1.00\n\n";
		CHECK(compoundPtr11->ToString() == expectedString);
	}
}