
// MFCprojectDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCproject.h"
#include "MFCprojectDlg.h"
#include "afxdialogex.h"
#include "CarsRentProgram.h"
#include "CarsForRent.h"
#include "DataManagment.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCprojectDlg dialog



CMFCprojectDlg::CMFCprojectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCPROJECT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCprojectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCprojectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCprojectDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCprojectDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDCANCEL, &CMFCprojectDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDCANCEL2, &CMFCprojectDlg::OnBnClickedCancel2)
	ON_BN_CLICKED(IDCANCEL3, &CMFCprojectDlg::OnBnClickedCancel3)
END_MESSAGE_MAP()


// CMFCprojectDlg message handlers

BOOL CMFCprojectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCprojectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCprojectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCprojectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCprojectDlg::OnBnClickedButton1()
{
	CarsRentProgram dlg;
	dlg.DoModal();
}

void CMFCprojectDlg::OnBnClickedButton3()
{
	CarsForRent dlg;
	dlg.DoModal();
}

void CMFCprojectDlg::OnBnClickedCancel()
{
	Car* car;
	for (int i = 0; i < DataManagment::Carslist.size(); i++)
	{
		car = DataManagment::Carslist[i];
		delete car;
	}
	DataManagment::Carslist.clear();
	CDialogEx::OnCancel();
}


void CMFCprojectDlg::OnBnClickedCancel2()
{
	//Save
	CFile file;
	file.Open(L"DataManagmentInfo.data", CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&file, CArchive::store);
	DataManagment::Serialize(ar);
	ar.Close();
	file.Close();
	MessageBox(L"The Data Saved Successfully", L"System Message", MB_ICONASTERISK);
}


void CMFCprojectDlg::OnBnClickedCancel3()
{
	//Load
	Car* car;
	for (int i = 0; i < DataManagment::Carslist.size(); i++)
	{
		car = DataManagment::Carslist[i];
		delete car;
	}
	DataManagment::Carslist.clear();
	CFile file;
	file.Open(L"DataManagmentInfo.data", CFile::modeRead);
	CArchive ar(&file, CArchive::load);
	DataManagment::Serialize(ar);
	ar.Close();
	file.Close();
	MessageBox(L"The Data Was Loaded Successfully", L"System Message", MB_ICONASTERISK);
}