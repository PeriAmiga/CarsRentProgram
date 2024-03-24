#pragma once
#include "Hybrid.h"


class Toyota : virtual public Hybrid
{
public:
	Toyota(CString lp, Color color, int year, double kilometer, FuelType type);
	~Toyota();

	//Getters
	CString getModel();
	void setPricePerDay();
};