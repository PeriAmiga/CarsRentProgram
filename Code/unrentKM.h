#pragma once


// unrentKM dialog

class unrentKM : public CDialogEx
{
	DECLARE_DYNAMIC(unrentKM)

public:
	unrentKM(CWnd* pParent = nullptr);   // standard constructor
	virtual ~unrentKM();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	double KilometerPassed;
	afx_msg void OnBnClickedOk();
	double getKilometerPassed();
};
