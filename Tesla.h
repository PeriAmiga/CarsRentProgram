#pragma once
#include "Electric.h"


class Tesla : public Electric
{
public:
	Tesla(CString lp, Color color, int year, double kilometer);
	~Tesla();

	//Getters
	CString getModel();
	void setPricePerDay();
};