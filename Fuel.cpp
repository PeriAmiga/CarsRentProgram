#include "pch.h"
#include "Car.h"
#include "Fuel.h"


int Fuel::countSumofFuelCars = 0;
Fuel::Fuel(CString lp, Color color, int year, double kilometer, FuelType type) : Car(lp, color, year, kilometer), fueltype(type)
{
	countSumofFuelCars++;
}

Fuel::~Fuel()
{
	countSumofFuelCars--;
}

FuelType Fuel::getFuelType() const
{
	return this->fueltype;
}

int Fuel::getCountSumofFuelCars() const
{
	return countSumofFuelCars;
}

CString Fuel::getTypeCar()
{
	return CString("Fuel");
}
