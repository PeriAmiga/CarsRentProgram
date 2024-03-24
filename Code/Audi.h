#pragma once
#include "Fuel.h"


class Audi : virtual public Fuel
{
public:
	Audi(CString lp, Color color, int year, double kilometer, FuelType type);
	~Audi();

	//Getters
	CString getModel();
	void setPricePerDay();
};