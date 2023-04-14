#include "pch.h"
#include "Audi.h"


Audi::Audi(CString lp, Color color, int year, double kilometer, FuelType type) : Car(lp, color, year, kilometer), Fuel(lp, color, year, kilometer, type)
{
	setPricePerDay();
}

Audi::~Audi()
{
}

CString Audi::getModel()
{
	return CString("Audi");
}

void Audi::setPricePerDay()
{
	if (this->getFuelType() == nintyfive)
	{
		this->pricePerDay = 6.52 * 24 + 50;
	}
	if (this->getFuelType() == nintyeight)
	{
		this->pricePerDay = 8.58 * 24 + 50;
	}
	if (this->getFuelType() == Solar)
	{
		this->pricePerDay = 8.27 * 24 + 50;
	}
}