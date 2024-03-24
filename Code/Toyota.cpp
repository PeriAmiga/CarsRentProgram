#include "pch.h"
#include "Toyota.h"


Toyota::Toyota(CString lp, Color color, int year, double kilometer, FuelType type) : Car(lp, color, year, kilometer), Fuel(lp, color, year, kilometer, type), Electric(lp, color, year, kilometer), Hybrid(lp, color, year, kilometer, type)
{
	setPricePerDay();
}

Toyota::~Toyota()
{
}

CString Toyota::getModel()
{
	return CString("Toyota");
}

void Toyota::setPricePerDay()
{
	if (this->getFuelType() == nintyfive)
	{
		this->pricePerDay = 6.52 * 24 + 100;
	}
	if (this->getFuelType() == nintyeight)
	{
		this->pricePerDay = 8.58 * 24 + 100;
	}
	if (this->getFuelType() == Solar)
	{
		this->pricePerDay = 8.27 * 24 + 100;
	}
}