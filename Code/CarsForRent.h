#pragma once


// CarsForRent dialog

class CarsForRent : public CDialogEx
{
	DECLARE_DYNAMIC(CarsForRent)

public:
	CarsForRent(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CarsForRent();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListBox ListofCars;
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnEnChangeEdit8();
	CString ColorShow;
	afx_msg void OnEnChangeEdit13();
	CString AvailableCars;
	CString CarsinRent;
	afx_msg void OnEnChangeEdit14();
	afx_msg void OnEnChangeEdit6();
	CString CarType;
	CString CarModel;
	CString RentStatus;
	CString LiscensePlate;
	CString Year;
	CString KM;
	CString CostPerDay;
	CString LastName;
	CString FirstName;
	CString IDnumber;
	afx_msg void OnEnChangeEdit10();
	void ClearEditBoxes();
	CButton RentButton;
	afx_msg void OnBnClickedButton3();
	CButton unrentButton;
	afx_msg void OnBnClickedButton1();
};