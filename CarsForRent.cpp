// CarsForRent.cpp : implementation file

#include "pch.h"
#include "MFCproject.h"
#include "CarsForRent.h"
#include "afxdialogex.h"
#include "DataManagment.h"
#include "Car.h"
#include "Audi.h"
#include "Tesla.h"
#include "Toyota.h"
#include "CarsRentProgram.h"
#include "unrentKM.h"
#include <vector>

// CarsForRent dialog

CStatic* ImageHolder1; // White Pic
CStatic* ImageHolder2; // Audi Pic
CStatic* ImageHolder3; // Toyota Pic
CStatic* ImageHolder4; // Tesla Pic

IMPLEMENT_DYNAMIC(CarsForRent, CDialogEx)

CarsForRent::CarsForRent(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, ColorShow(_T(""))
	, AvailableCars(_T(""))
	, CarsinRent(_T(""))
	, CarType(_T(""))
	, CarModel(_T(""))
	, RentStatus(_T(""))
	, LiscensePlate(_T(""))
	, Year(_T(""))
	, KM(_T(""))
	, CostPerDay(_T(""))
	, LastName(_T(""))
	, FirstName(_T(""))
	, IDnumber(_T(""))
{
}

CarsForRent::~CarsForRent()
{
}

void CarsForRent::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, ListofCars);
	GetDlgItem(IDC_EDIT8)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT13)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT14)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT6)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT7)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT9)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT3)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT4)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT5)->EnableWindow(FALSE);
	CString line;
	CString rentStatus;
	CString LP;
	for (int i = 0; i < DataManagment::Carslist.size(); i++)
	{
		rentStatus = (DataManagment::Carslist[i]->getIsRent()) ? L"True" : L"False";
		line = DataManagment::Carslist[i]->getLp() + L"   " + DataManagment::Carslist[i]->getModel() + L"   " + rentStatus;
		ListofCars.AddString(line);
	}
	DDX_Text(pDX, IDC_EDIT8, ColorShow);
	DDX_Text(pDX, IDC_EDIT13, AvailableCars);
	DDX_Text(pDX, IDC_EDIT14, CarsinRent);
	DDX_Text(pDX, IDC_EDIT6, CarType);
	DDX_Text(pDX, IDC_EDIT7, CarModel);
	DDX_Text(pDX, IDC_EDIT9, RentStatus);
	DDX_Text(pDX, IDC_EDIT1, LiscensePlate);
	DDX_Text(pDX, IDC_EDIT3, Year);
	DDX_Text(pDX, IDC_EDIT4, KM);
	DDX_Text(pDX, IDC_EDIT5, CostPerDay);
	DDX_Text(pDX, IDC_EDIT11, LastName);
	DDX_Text(pDX, IDC_EDIT10, FirstName);
	DDX_Text(pDX, IDC_EDIT12, IDnumber);
	DDX_Control(pDX, IDC_BUTTON3, RentButton);
	DDX_Control(pDX, IDC_BUTTON1, unrentButton);
}


BEGIN_MESSAGE_MAP(CarsForRent, CDialogEx)
	ON_LBN_SELCHANGE(IDC_LIST1, &CarsForRent::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON4, &CarsForRent::OnBnClickedButton4)
	ON_EN_CHANGE(IDC_EDIT8, &CarsForRent::OnEnChangeEdit8)
	ON_EN_CHANGE(IDC_EDIT13, &CarsForRent::OnEnChangeEdit13)
	ON_EN_CHANGE(IDC_EDIT14, &CarsForRent::OnEnChangeEdit14)
	ON_EN_CHANGE(IDC_EDIT6, &CarsForRent::OnEnChangeEdit6)
	ON_EN_CHANGE(IDC_EDIT10, &CarsForRent::OnEnChangeEdit10)
	ON_BN_CLICKED(IDC_BUTTON3, &CarsForRent::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CarsForRent::OnBnClickedButton1)
END_MESSAGE_MAP()


// CarsForRent message handlers


void CarsForRent::OnLbnSelchangeList1()
{
	int index = ListofCars.GetCaretIndex();
	if (index >= DataManagment::Carslist.size())
	{
		return;
	}
	Car* car = DataManagment::Carslist[index];
	switch (car->getColor())
	{
	case blue: ColorShow = L"Blue";
		break;
	case black: ColorShow = L"Black";
		break;
	case white: ColorShow = L"White";
		break;
	}
	CarType = car->getTypeCar();
	CarModel = car->getModel();
	if (CarModel.Compare(L"Audi") == 0)
	{
		ImageHolder2 = (CStatic*)GetDlgItem(IDC_INKPICTURE2);
		ImageHolder2->BringWindowToTop();
	}
	else if (CarModel.Compare(L"Toyota") == 0)
	{
		ImageHolder3 = (CStatic*)GetDlgItem(IDC_INKPICTURE3);
		ImageHolder3->BringWindowToTop();
	}
	else if (CarModel.Compare(L"Tesla") == 0)
	{
		ImageHolder4 = (CStatic*)GetDlgItem(IDC_INKPICTURE4);
		ImageHolder4->BringWindowToTop();
	}
	if (car->getIsRent() == TRUE)
	{
		RentStatus = L"True";
		FirstName = car->getFirstName();
		LastName = car->getLastName();
		IDnumber = car->getIDnumber();
	}
	else
	{
		RentStatus = L"False";
		FirstName = L"";
		LastName = L"";
		IDnumber = L"";
	}
	LiscensePlate = car->getLp();
	int year = car->getYear();
	Year.Format(L"%d", year);
	double KiloM = car->getKilometer();
	KM.Format(L"%.2lf", KiloM);
	double cost = car->getPricePerDay();
	CostPerDay.Format(L"%.2lf", cost);
	CString avlcars;
	CString CarsRent;
	int carsavl, rentcars;
	if (DataManagment::Carslist.size() != 0)
	{
		carsavl = DataManagment::Carslist[DataManagment::Carslist.size() - 1]->getCountSumOfCars() - DataManagment::Carslist[DataManagment::Carslist.size() - 1]->getCountCarsonRent();
		rentcars = DataManagment::Carslist[DataManagment::Carslist.size() - 1]->getCountCarsonRent();
	}
	else
	{
		carsavl = 0;
		rentcars = 0;
	}
	avlcars.Format(L"%d", carsavl);
	AvailableCars = avlcars;
	CarsRent.Format(L"%d", rentcars);
	CarsinRent = CarsRent;
	ListofCars.ResetContent();
	UpdateData(FALSE);
	ListofCars.SetCurSel(index);
}

void CarsForRent::OnBnClickedButton4()
{
	if (DataManagment::Carslist.empty())
	{
		MessageBox(L"You do not have data to delete", L"System Message", MB_ICONASTERISK);
		return;
	}
	Car* car;
	int index = ListofCars.GetCaretIndex();
	vector<Car*>::iterator it;
	it = DataManagment::Carslist.begin() + index;
	car = DataManagment::Carslist[index];
	DataManagment::Carslist.erase(it);
	delete car;
	ClearEditBoxes();
	ImageHolder1 = (CStatic*)GetDlgItem(IDC_INKPICTURE1);
	ImageHolder1->BringWindowToTop();
	ListofCars.ResetContent();
	UpdateData(FALSE);
}

void CarsForRent::OnEnChangeEdit8()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CarsForRent::OnEnChangeEdit13()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CarsForRent::OnEnChangeEdit14()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CarsForRent::OnEnChangeEdit6()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CarsForRent::OnEnChangeEdit10()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void CarsForRent::ClearEditBoxes()
{
	ColorShow = L"";
	AvailableCars = L"";
	CarsinRent = L"";
	CarType = L"";
	CarModel = L"";
	RentStatus = L"";
	LiscensePlate = L"";
	Year = L"";
	KM = L"";
	CostPerDay = L"";
	LastName = L"";
	FirstName = L"";
	IDnumber = L"";
}

void CarsForRent::OnBnClickedButton3()
{
	if (DataManagment::Carslist.empty())
	{
		MessageBox(L"You do not have car to rent", L"System Message", MB_ICONASTERISK);
		return;
	}
	UpdateData(TRUE);
	person* newrenter = new person;
	newrenter->firstname = FirstName;
	newrenter->lastname = LastName;
	newrenter->id = IDnumber;
	Car* car;
	int index = ListofCars.GetCaretIndex();
	car = DataManagment::Carslist[index];
	if (car->getIsRent() == FALSE)
	{
		if ((FirstName == L"") || (LastName == L"") || (IDnumber == L"")) // Check if not all the renter data is given.
		{
			ListofCars.ResetContent();
			UpdateData(FALSE);
			MessageBox(L"You did not entered the data on the renter, please complete all the data that needed", L"System Message", MB_ICONASTERISK);
			return;
		}
		car->setIsRent(TRUE, *newrenter);
		ListofCars.ResetContent();
		ClearEditBoxes();
		ImageHolder1 = (CStatic*)GetDlgItem(IDC_INKPICTURE1);
		ImageHolder1->BringWindowToTop();
		UpdateData(FALSE);
		ListofCars.SetCurSel(index);
		MessageBox(L"The Car was successfully rented", L"System Message", MB_ICONASTERISK);
	}
	else
	{
		ListofCars.ResetContent();
		UpdateData(FALSE);
		ListofCars.SetCurSel(index);
		MessageBox(L"The Car is already rented", L"System Message", MB_ICONASTERISK);
	}
}

void CarsForRent::OnBnClickedButton1()
{
	if (DataManagment::Carslist.empty())
	{
		MessageBox(L"You do not have car to unrent", L"System Message", MB_ICONASTERISK);
		return;
	}
	Car* car;
	int index = ListofCars.GetCaretIndex();
	car = DataManagment::Carslist[index];
	if (car->getIsRent() == TRUE)
	{
		car->setIsRent(FALSE, car->getRenter());
		unrentKM dlg;
		dlg.DoModal();
		car->setKilometer(dlg.getKilometerPassed());
		MessageBox(L"The Car was successfully unrented", L"System Message", MB_ICONASTERISK);
		ClearEditBoxes();
		ImageHolder1 = (CStatic*)GetDlgItem(IDC_INKPICTURE1);
		ImageHolder1->BringWindowToTop();
		ListofCars.ResetContent();
		UpdateData(FALSE);
	}
	else
	{
		MessageBox(L"The Car is not rented", L"System Message", MB_ICONASTERISK);
	}
}