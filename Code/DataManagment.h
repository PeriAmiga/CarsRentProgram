#pragma once
#include <vector>
#include "Car.h"
#include <iostream>
using namespace std;


class DataManagment : public CObject
{
public:
	static vector<Car*> Carslist;
	static void Serialize(CArchive& ar);
	DECLARE_SERIAL(DataManagment);
};