// unrentKM.cpp : implementation file
//

#include "pch.h"
#include "MFCproject.h"
#include "unrentKM.h"
#include "afxdialogex.h"


// unrentKM dialog

IMPLEMENT_DYNAMIC(unrentKM, CDialogEx)

unrentKM::unrentKM(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, KilometerPassed(0)
{

}

unrentKM::~unrentKM()
{
}

void unrentKM::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, KilometerPassed);
}


BEGIN_MESSAGE_MAP(unrentKM, CDialogEx)
	ON_BN_CLICKED(IDOK, &unrentKM::OnBnClickedOk)
END_MESSAGE_MAP()


// unrentKM message handlers


void unrentKM::OnBnClickedOk()
{
	UpdateData(TRUE);
	if (KilometerPassed <= 0)
	{ 
		MessageBox(L"You did not enter the KM that the driver has made", L"System Message", MB_ICONASTERISK);
		return;
	}
	CDialogEx::OnOK();
}

double unrentKM::getKilometerPassed()
{
	return KilometerPassed;
}