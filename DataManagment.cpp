#include "pch.h"
#include "DataManagment.h"
#include "MFCprojectDlg.h"
#include "Car.h"
#include "Fuel.h"
#include "Electric.h"
#include "Hybrid.h"
#include "Audi.h"
#include "Toyota.h"
#include "Tesla.h"
#include <iostream>
#include <vector>
using namespace std;

vector<Car*> DataManagment::Carslist;

void DataManagment::Serialize(CArchive& ar)
{
	if (ar.IsStoring()) // Save
	{
		ar << Carslist.size();
		for (auto it = DataManagment::Carslist.begin(); it != DataManagment::Carslist.end(); ++it)
		{
			ar << (*it)->getTypeCar();
			ar << (*it)->getModel();
			if ((*it)->getModel().Compare(L"Tesla") != 0)
			{
				int fuel = (*it)->getFuelType();
				ar << fuel;
			}
			int color = (*it)->getColor();
			ar << color;
			ar << (*it)->getLp();
			ar << (*it)->getYear();
			ar << (*it)->getKilometer();
			ar << (*it)->getIsRent();
			if ((*it)->getIsRent())
			{
				person renter;
				renter = (*it)->getRenter();
				ar << renter.firstname;
				ar << renter.lastname;
				ar << renter.id;
			}
		}
	}
	else // Load
	{
		Car* car;
		int size;
		CString licensePlate;
		CString typecar;
		CString model;
		int typefuel;
		FuelType fuel;
		int color;
		Color CL;
		int year;
		bool isRent;
		double kilometer;
		person renter;

		ar >> size;
		for (int i = 0; i < size; i++)
		{
			ar >> typecar;
			ar >> model;
			if (model.Compare(L"Tesla") != 0)
			{
				ar >> typefuel;
				if (typefuel == 1)
				{
					fuel = nintyfive;
				}
				else if (typefuel == 2)
				{
					fuel = nintyeight;
				}
				else
				{
					fuel = Solar;
				}
			}
			ar >> color;
			if (color == 1)
			{
				CL = blue;
			}
			else if (color == 2)
			{
				CL = black;
			}
			else
			{
				CL = white;
			}
			ar >> licensePlate;
			ar >> year;
			ar >> kilometer;

			if (model.Compare(L"Audi") == 0)
			{
				car = new Audi(licensePlate, CL, year, kilometer, fuel);
			}
			else if (model.Compare(L"Toyota") == 0)
			{
				car = new Toyota(licensePlate, CL, year, kilometer, fuel);
			}
			else
			{
				car = new Tesla(licensePlate, CL, year, kilometer);
			}
			
			ar >> isRent;
			if (isRent)
			{
				ar >> renter.firstname;
				ar >> renter.lastname;
				ar >> renter.id;
				car->setIsRent(isRent, renter);
			}
			Carslist.push_back(car);
		}
	}
}