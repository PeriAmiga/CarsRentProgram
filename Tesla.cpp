#include "pch.h"
#include "Tesla.h"

Tesla::Tesla(CString lp, Color color, int year, double kilometer) : Car(lp, color, year, kilometer), Electric(lp, color, year, kilometer)
{
	setPricePerDay();
}

Tesla::~Tesla()
{
}

CString Tesla::getModel()
{
	return CString("Tesla");
}

void Tesla::setPricePerDay()
{
	this->pricePerDay = 0.13 * 24 + 200;
}