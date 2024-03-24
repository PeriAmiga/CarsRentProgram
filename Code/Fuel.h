#pragma once
#include "Car.h"


class Fuel : virtual public Car
{
private:
	const FuelType fueltype;

protected:
	static int countSumofFuelCars;

public:
	Fuel(CString lp, Color color, int year, double kilometer, FuelType type);
	virtual ~Fuel();

	//Getters
	FuelType getFuelType() const;
	int getCountSumofFuelCars() const;
	CString getTypeCar();
};