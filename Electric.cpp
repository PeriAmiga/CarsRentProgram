#include "pch.h"
#include "Car.h"
#include "Electric.h"


int Electric::countSumofElectricCars = 0;
Electric::Electric(CString lp, Color color, int year, double kilometer) : Car(lp, color, year, kilometer)
{
	countSumofElectricCars++;
}

Electric::~Electric()
{
	countSumofElectricCars--;
}


int Electric::getCountSumofElectricCars() const
{
	return countSumofElectricCars;
}

CString Electric::getTypeCar()
{
	return CString("Electric");
}
