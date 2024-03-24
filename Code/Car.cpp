#include "pch.h"
#include "Car.h"
#include "DataManagment.h"


int Car::countSumOfCars = 0;
int Car::countCarsonRent = 0;
Car::Car(CString lp, Color color, int year, double kilometer) : licensePlate(lp), color(color), year(year), kilometer(kilometer)
{
	countSumOfCars++;
}

Car::~Car()
{
	countSumOfCars--;
	if (this->renter != NULL)
	{
		delete this->renter;
	}
}

CString Car::getLp() const
{
	return this->licensePlate;
}

Color Car::getColor() const
{
	return this->color;
}

int Car::getYear() const
{
	return this->year;
}

bool Car::getIsRent() const
{
	return this->isRent;
}

double Car::getKilometer() const
{
	return this->kilometer;
}

double Car::getPricePerDay() const
{
	return this->pricePerDay;
}

int Car::getCountSumOfCars() const
{
	return countSumOfCars;
}

int Car::getCountCarsonRent() const
{
	return countCarsonRent;
}

CString Car::getTypeCar()
{
	return CString();
}

CString Car::getIDnumber() const
{
	return this->renter->id;
}

CString Car::getFirstName() const
{
	return this->renter->firstname;
}

CString Car::getLastName() const
{
	return this->renter->lastname;
}

person Car::getRenter()
{
	return *this->renter;
}

FuelType Car::getFuelType() const
{
	return FuelType();
}

void Car::setIsRent(bool rent, person& p)
{
	if (rent == true)
	{
		this->renter = new person;
		this->renter->firstname = p.firstname;
		this->renter->lastname = p.lastname;
		this->renter->id = p.id;
		this->isRent = true;
		countCarsonRent++;
	}
	else
	{
		this->isRent = false;
		countCarsonRent--;
		delete this->renter;
		this->renter = NULL;
	}
}

void Car::setKilometer(double km)
{
	this->kilometer = this->kilometer + km;
}