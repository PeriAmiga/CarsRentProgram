#pragma once
#include "Car.h"
#include "Fuel.h"
#include "Electric.h"


class Hybrid : virtual public Fuel, virtual public Electric
{
private:
	static int countSumofHybridCars;

public:
	Hybrid(CString lp, Color color, int year, double kilometer, FuelType type);
	virtual ~Hybrid();

	int getCountSumofHybridCars() const;
	CString getTypeCar();
};