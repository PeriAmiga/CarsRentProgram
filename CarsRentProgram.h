#pragma once
#include "Car.h"
#include "Fuel.h"
#include "Electric.h"
#include "Hybrid.h"
#include "Audi.h"
#include "Toyota.h"
#include "Tesla.h"


// CarsRentProgram dialog

class CarsRentProgram : public CDialogEx
{
	DECLARE_DYNAMIC(CarsRentProgram)

public:
	CarsRentProgram(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CarsRentProgram();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedRadio2();

	void EnableFuelType(bool flag);
	void EnableFuelCarType(bool flag);
	void EnableElectricCarType(bool flag);
	void EnableHybridCarType(bool flag);
	CString LiscensePlate;
	int year;
	double KM;
	Color color;
	FuelType type;
	CString CarType;
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedRadio27();
	afx_msg void OnBnClickedRadio28();
	afx_msg void OnBnClickedRadio29();
	afx_msg void OnBnClickedRadio24();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit3();

	bool FullfilAllTheParameters();
	afx_msg void OnBnClickedRadio7();
	afx_msg void OnBnClickedRadio8();
};