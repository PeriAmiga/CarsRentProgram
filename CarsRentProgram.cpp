// CarsRentProgram.cpp : implementation file
//

#include "pch.h"
#include "MFCproject.h"
#include "MFCprojectDlg.h"
#include "CarsRentProgram.h"
#include "afxdialogex.h"
#include "Audi.h"
#include "Tesla.h"
#include "Toyota.h"
#include "DataManagment.h"

// CarsRentProgram dialog


IMPLEMENT_DYNAMIC(CarsRentProgram, CDialogEx)
CarsRentProgram::CarsRentProgram(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, LiscensePlate(_T("")), year(int()), KM(double())
{
}

CarsRentProgram::~CarsRentProgram()
{
}

void CarsRentProgram::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, LiscensePlate);
	DDX_Text(pDX, IDC_EDIT2, year);
	DDX_Text(pDX, IDC_EDIT3, KM);
}


BEGIN_MESSAGE_MAP(CarsRentProgram, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO1, &CarsRentProgram::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO4, &CarsRentProgram::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO2, &CarsRentProgram::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CarsRentProgram::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_BUTTON1, &CarsRentProgram::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &CarsRentProgram::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON2, &CarsRentProgram::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_RADIO27, &CarsRentProgram::OnBnClickedRadio27)
	ON_BN_CLICKED(IDC_RADIO28, &CarsRentProgram::OnBnClickedRadio28)
	ON_BN_CLICKED(IDC_RADIO29, &CarsRentProgram::OnBnClickedRadio29)
	ON_BN_CLICKED(IDC_RADIO24, &CarsRentProgram::OnBnClickedRadio24)
	ON_EN_CHANGE(IDC_EDIT2, &CarsRentProgram::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &CarsRentProgram::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_RADIO7, &CarsRentProgram::OnBnClickedRadio7)
	ON_BN_CLICKED(IDC_RADIO8, &CarsRentProgram::OnBnClickedRadio8)
END_MESSAGE_MAP()


// CarsRentProgram message handlers
void CarsRentProgram::OnBnClickedRadio27()
{
	// TODO: Add your control notification handler code here
}


void CarsRentProgram::OnBnClickedRadio28()
{
	// TODO: Add your control notification handler code here
}


void CarsRentProgram::OnBnClickedRadio29()
{
	// TODO: Add your control notification handler code here
}

void CarsRentProgram::OnBnClickedRadio1()
{
	EnableFuelCarType(TRUE);
	EnableFuelType(TRUE);
	EnableElectricCarType(FALSE);
	EnableHybridCarType(FALSE);
	GetDlgItem(IDC_RADIO27)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO28)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO29)->EnableWindow(TRUE);
	CarType = L"Fuel";
}

void CarsRentProgram::OnBnClickedRadio4()
{

}

void CarsRentProgram::OnBnClickedRadio2()
{
	EnableFuelCarType(FALSE);
	EnableFuelType(FALSE);
	EnableElectricCarType(TRUE);
	EnableHybridCarType(FALSE);
	GetDlgItem(IDC_RADIO27)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO28)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO29)->EnableWindow(TRUE);
	CarType = L"Electric";
}

void CarsRentProgram::OnBnClickedRadio3()
{
	EnableFuelCarType(FALSE);
	EnableFuelType(TRUE);
	EnableElectricCarType(FALSE);
	EnableHybridCarType(TRUE);
	GetDlgItem(IDC_RADIO27)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO28)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO29)->EnableWindow(TRUE);
	CarType = L"Hybrid";
}

void CarsRentProgram::EnableFuelType(bool flag)
{
	GetDlgItem(IDC_RADIO24)->EnableWindow(flag);
	GetDlgItem(IDC_RADIO25)->EnableWindow(flag);
	GetDlgItem(IDC_RADIO26)->EnableWindow(flag);
	if (flag == false)
	{
		((CButton*)GetDlgItem(IDC_RADIO24))->SetCheck(BST_UNCHECKED);
		((CButton*)GetDlgItem(IDC_RADIO25))->SetCheck(BST_UNCHECKED);
		((CButton*)GetDlgItem(IDC_RADIO26))->SetCheck(BST_UNCHECKED);
	}
}

void CarsRentProgram::EnableFuelCarType(bool flag)
{
	GetDlgItem(IDC_RADIO4)->EnableWindow(flag);
	if (flag == false)
	{
		((CButton*)GetDlgItem(IDC_RADIO4))->SetCheck(BST_UNCHECKED);
	}
}

void CarsRentProgram::EnableElectricCarType(bool flag)
{
	GetDlgItem(IDC_RADIO8)->EnableWindow(flag);
	if (flag == false)
	{
		((CButton*)GetDlgItem(IDC_RADIO8))->SetCheck(BST_UNCHECKED);
	}
}

void CarsRentProgram::EnableHybridCarType(bool flag)
{
	GetDlgItem(IDC_RADIO7)->EnableWindow(flag);
	if (flag == false)
	{
		((CButton*)GetDlgItem(IDC_RADIO7))->SetCheck(BST_UNCHECKED);
	}
}

void CarsRentProgram::OnBnClickedButton1()
{
	UpdateData(TRUE);
	Car* newCar;
	if (((CButton*)GetDlgItem(IDC_RADIO1))->GetCheck())
	{
		if (((CButton*)GetDlgItem(IDC_RADIO24))->GetCheck())
		{
			type = nintyfive;
		}
		if (((CButton*)GetDlgItem(IDC_RADIO25))->GetCheck())
		{
			type = nintyeight;
		}
		if (((CButton*)GetDlgItem(IDC_RADIO26))->GetCheck())
		{
			type = Solar;
		}
		if (((CButton*)GetDlgItem(IDC_RADIO27))->GetCheck())
		{
			color = blue;
		}
		if (((CButton*)GetDlgItem(IDC_RADIO28))->GetCheck())
		{
			color = black;
		}
		if (((CButton*)GetDlgItem(IDC_RADIO29))->GetCheck())
		{
			color = white;
		}
		for (auto it = DataManagment::Carslist.begin(); it != DataManagment::Carslist.end(); ++it)
		{
			if ((*it)->getLp().Compare(LiscensePlate) == 0)
			{
				MessageBox(L"Already exists car with this Liscense Plate Number, please enter another Number", L"System Message", MB_ICONASTERISK);
				return;
			}
		}
		if (FullfilAllTheParameters())
		{
			newCar = new Audi(LiscensePlate, color, year, KM, type);
		}
		else
		{
			if (year <= 2000)
			{
				MessageBox(L"You entered invalid year number, please enter a year above 2000", L"System Message", MB_ICONASTERISK);
				return;
			}
			MessageBox(L"You did not entered the data on the car, please complete all the data that needed", L"System Message", MB_ICONASTERISK);
			return;
		}
	}
	else if (((CButton*)GetDlgItem(IDC_RADIO2))->GetCheck())
	{
		if (((CButton*)GetDlgItem(IDC_RADIO27))->GetCheck())
		{
			color = blue;
		}
		if (((CButton*)GetDlgItem(IDC_RADIO28))->GetCheck())
		{
			color = black;
		}
		if (((CButton*)GetDlgItem(IDC_RADIO29))->GetCheck())
		{
			color = white;
		}
		for (auto it = DataManagment::Carslist.begin(); it != DataManagment::Carslist.end(); ++it)
		{
			if ((*it)->getLp().Compare(LiscensePlate) == 0)
			{
				MessageBox(L"Already exists car with this Liscense Plate Number, please enter another Number", L"System Message", MB_ICONASTERISK);
				return;
			}
		}
		if (FullfilAllTheParameters())
		{
			newCar = new Tesla(LiscensePlate, color, year, KM);
		}
		else
		{
			if (year <= 2000)
			{
				MessageBox(L"You entered invalid year number, please enter a year above 2000", L"System Message", MB_ICONASTERISK);
				return;
			}
			MessageBox(L"You did not entered the data on the car, please complete all the data that needed", L"System Message", MB_ICONASTERISK);
			return;
		}
		
	}
	else
	{
		if (((CButton*)GetDlgItem(IDC_RADIO24))->GetCheck())
		{
			type = nintyfive;
		}
		if (((CButton*)GetDlgItem(IDC_RADIO25))->GetCheck())
		{
			type = nintyeight;
		}
		if (((CButton*)GetDlgItem(IDC_RADIO26))->GetCheck())
		{
			type = Solar;
		}
		if (((CButton*)GetDlgItem(IDC_RADIO27))->GetCheck())
		{
			color = blue;
		}
		if (((CButton*)GetDlgItem(IDC_RADIO28))->GetCheck())
		{
			color = black;
		}
		if (((CButton*)GetDlgItem(IDC_RADIO29))->GetCheck())
		{
			color = white;
		}
		for (auto it = DataManagment::Carslist.begin(); it != DataManagment::Carslist.end(); ++it)
		{
			if ((*it)->getLp().Compare(LiscensePlate) == 0)
			{
				MessageBox(L"Already exists car with this Liscense Plate Number, please enter another Number", L"System Message", MB_ICONASTERISK);
				return;
			}
		}
		if (FullfilAllTheParameters())
		{
			newCar = new Toyota(LiscensePlate, color, year, KM, type);
		}
		else
		{
			if (year <= 2000)
			{
				MessageBox(L"You entered invalid year number, please enter a year above 2000", L"System Message", MB_ICONASTERISK);
				return;
			}
			MessageBox(L"You did not entered the data on the car, please complete all the data that needed", L"System Message", MB_ICONASTERISK);
			return;
		}
	}
	DataManagment::Carslist.push_back(newCar);
	MessageBox(L"The Car Created Successfuly", L"System Message", MB_ICONASTERISK);
	CDialogEx::OnOK();
}


void CarsRentProgram::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CarsRentProgram::OnBnClickedButton2()
{
	CDialogEx::OnCancel();
}

void CarsRentProgram::OnBnClickedRadio24()
{
	// TODO: Add your control notification handler code here
}

void CarsRentProgram::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CarsRentProgram::OnEnChangeEdit3()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

bool CarsRentProgram::FullfilAllTheParameters() //Check if the user entered all the parameters that needed.
{
	UpdateData(TRUE);
	if (((CButton*)GetDlgItem(IDC_RADIO1))->GetCheck() || ((CButton*)GetDlgItem(IDC_RADIO2))->GetCheck() || ((CButton*)GetDlgItem(IDC_RADIO3))->GetCheck()) // if fuel or hybrid or electric is checked
	{
		if (((CButton*)GetDlgItem(IDC_RADIO4))->GetCheck() || ((CButton*)GetDlgItem(IDC_RADIO7))->GetCheck() || ((CButton*)GetDlgItem(IDC_RADIO8))->GetCheck()) // if audi or toyota or tesla is checked
		{
			if (((CButton*)GetDlgItem(IDC_RADIO27))->GetCheck() || ((CButton*)GetDlgItem(IDC_RADIO28))->GetCheck() || ((CButton*)GetDlgItem(IDC_RADIO29))->GetCheck()) // if blue or black or white is checked
			{
				if (((CButton*)GetDlgItem(IDC_RADIO2))->GetCheck()) //Check if Tesla, you don't need to enter type of fuel.
				{
					if ((LiscensePlate != L"") && (year > 2000))
					{
						return TRUE;
					}
					else
					{
						return FALSE;
					}
				}
				else if ((((CButton*)GetDlgItem(IDC_RADIO24))->GetCheck() || ((CButton*)GetDlgItem(IDC_RADIO25))->GetCheck() || ((CButton*)GetDlgItem(IDC_RADIO26))->GetCheck())) //Check if one of the fuel radio buttons is checked for fuel and hybrid.
				{
					if ((LiscensePlate != L"") && (year > 2000))
					{
						return TRUE;
					}
					else
					{
						return FALSE;
					}
				}
				else
				{
					return FALSE;
				}
			}
			else
			{
				return FALSE;
			}
		}
		else
		{
			return FALSE;
		}
	}
	else
	{
		return FALSE;
	}
}

void CarsRentProgram::OnBnClickedRadio7()
{

}


void CarsRentProgram::OnBnClickedRadio8()
{

}
