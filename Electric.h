#pragma once
#include "Car.h"


class Electric : virtual  public Car
{
protected:
	static int countSumofElectricCars;

public:
	Electric(CString lp, Color color, int year, double kilometer);
	virtual ~Electric();

	//Getters
	int getCountSumofElectricCars() const;
	CString getTypeCar();
};