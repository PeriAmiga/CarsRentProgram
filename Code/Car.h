#pragma once
#include <iostream>
#include <CString>
using namespace std;


enum Color
{
	blue = 1, black, white
};

enum FuelType
{
	nintyfive = 1, nintyeight, Solar
};

typedef struct Person
{
	CString firstname;
	CString lastname;
	CString id;
}person;


class Car : public CObject
{
private:
	const CString licensePlate;
	const Color color;
	const int year;
	bool isRent = false;
	double kilometer;
	static int countSumOfCars;
	static int countCarsonRent;
	person* renter = NULL;

protected:
	double pricePerDay;
	

public:
	Car(CString lp, Color color, int year, double kilimoter);
	virtual ~Car();

	//Getters
	CString getLp() const;
	Color getColor() const;
	int getYear() const;
	bool getIsRent() const;
	double getKilometer() const;
	double getPricePerDay() const;
	int getCountSumOfCars() const;
	int getCountCarsonRent() const;
	virtual CString getModel() = 0;
	virtual CString getTypeCar();
	CString getIDnumber() const;
	CString getFirstName() const;
	CString getLastName() const;
	person getRenter();
	FuelType getFuelType() const;

	//Setter
	void setIsRent(bool rent, person& p);
	void setKilometer(double km);
	virtual void setPricePerDay() = 0;
};