#include "pch.h"
#include "Hybrid.h"


int Hybrid::countSumofHybridCars = 0;
Hybrid::Hybrid(CString lp, Color color, int year, double kilometer, FuelType type) : Car(lp, color, year, kilometer), Fuel(lp, color, year, kilometer, type), Electric(lp, color, year, kilometer)
{
	countSumofElectricCars--;
	countSumofFuelCars--;
	countSumofHybridCars++;
}

Hybrid::~Hybrid()
{
	countSumofElectricCars++;
	countSumofFuelCars++;
	countSumofHybridCars--;
}

int Hybrid::getCountSumofHybridCars() const
{
	return countSumofHybridCars;
}

CString Hybrid::getTypeCar()
{
	return CString("Hybrid");
}
