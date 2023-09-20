
// MFCprojectImageDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCprojectImage.h"
#include "MFCprojectImageDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CMFCprojectImageDlg 대화 상자



CMFCprojectImageDlg::CMFCprojectImageDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCPROJECTIMAGE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCprojectImageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_Radius, m_myedit);
	DDX_Control(pDX, IDC_BTN_Find, m_fcenter);
}

BEGIN_MESSAGE_MAP(CMFCprojectImageDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_Circle, &CMFCprojectImageDlg::OnBnClickedBtnCircle)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_Find, &CMFCprojectImageDlg::OnBnClickedBtnFind)
END_MESSAGE_MAP()


// CMFCprojectImageDlg 메시지 처리기

BOOL CMFCprojectImageDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_myedit.SetCueBanner(_T("10~200사이의 숫자만 입력해주세요"), true);
	MoveWindow(0, 0, 900, 520);

	m_pDlgimage = new CDlgimage;
	m_pDlgimage->Create(IDD_CDlgimage, this);
	m_pDlgimage->ShowWindow(SW_SHOW);

	

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCprojectImageDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCprojectImageDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCprojectImageDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

#include<iostream>
//원 그리기
void CMFCprojectImageDlg::OnBnClickedBtnCircle()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_radius=GetDlgItemInt(IDC_EDIT_Radius);

	if (m_radius < 10 || m_radius>200)
	{
		AfxMessageBox(_T("범위내의 숫자를 입력해주세요."));
	    SetDlgItemText(IDC_EDIT_Radius, _T(""));
	}
	else
	{
		int nWidth = m_pDlgimage->m_image.GetWidth();
		int nHeight = m_pDlgimage->m_image.GetHeight();

		int CenterX = rand() % (nWidth - 2 * m_radius) + m_radius;
		int CenterY = rand() % (nHeight - 2 * m_radius) + m_radius;

		std::cout << CenterX << "좌표" << CenterY << std::endl;

		DrawCircle(0,0,0,CenterX,CenterY);

		m_pDlgimage->Invalidate();
			
		m_fcenter.ShowWindow(SW_SHOW);

	}
}


void CMFCprojectImageDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if (m_pDlgimage)       delete m_pDlgimage;
}


void CMFCprojectImageDlg::OnBnClickedBtnFind()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	unsigned char* fm = (unsigned char*)m_pDlgimage->m_image.GetBits();
	int nWidth = m_pDlgimage->m_image.GetWidth();
	int nHeight = m_pDlgimage->m_image.GetHeight();
	int nPitch = m_pDlgimage->m_image.GetPitch();


	int SUMX = 0;
	int SUMY = 0;
	int SUMCOUNT = 0;
	for (int j = 0; j < nHeight; j++)
	{
		for (int i = 0; i < nWidth; i++)
		{

			if (fm[j * nPitch + i * 3 + 0] == 0 && fm[j * nPitch + i * 3 + 1] == 0 && fm[j * nPitch + i * 3 + 2] == 0)
			{
				SUMX += i;
				SUMY += j;
				SUMCOUNT++;
			}
		}
	}

	int center_x = SUMX / SUMCOUNT;
	int center_y = SUMY / SUMCOUNT;
	std::cout << center_x << "중심좌표" << center_y << std::endl;


	DrawCircle(0, 255, 255, center_x, center_y);

	int linewidth = 1;
	int linelength = 5;


	for (int j = 0; j < nHeight; j++)
	{
		for (int i = 0; i < nWidth; i++)
		{

			if (i<= center_x+ linelength && i >= center_x- linelength && j<= center_y+ linewidth && j>= center_y- linewidth)
			{
				fm[j * nPitch + i * 3 + 0] = 0; // Blue 
				fm[j * nPitch + i * 3 + 1] = 0; // Green 
				fm[j * nPitch + i * 3 + 2] = 0; // Red 
			}
			if (i <= center_x + linewidth && i >= center_x - linewidth && j <= center_y + linelength && j >= center_y - linelength)
			{
				fm[j * nPitch + i * 3 + 0] = 0; // Blue 
				fm[j * nPitch + i * 3 + 1] = 0; // Green 
				fm[j * nPitch + i * 3 + 2] = 0; // Red 
			}
		}
	}

                      
	m_pDlgimage->Invalidate();
	
}
void CMFCprojectImageDlg::DrawCircle(int nblue,int ngreen,int nred,int CenterX,int CenterY)
{
	unsigned char* fm = (unsigned char*)m_pDlgimage->m_image.GetBits();
	int nWidth = m_pDlgimage->m_image.GetWidth();
	int nHeight = m_pDlgimage->m_image.GetHeight();
	int nPitch = m_pDlgimage->m_image.GetPitch();
	int linewidth = m_radius * 2;


	for (int j = 0; j < nHeight; j++)
	{
		for (int i = 0; i < nWidth; i++)
		{
			int dx = i - CenterX;
			int dy = j - CenterY;
			double squared = dx * dx + dy * dy;

			if (squared <= m_radius * m_radius + linewidth && squared >= m_radius * m_radius - linewidth)
			{
				fm[j * nPitch + i * 3 + 0] = nblue; // Blue 
				fm[j * nPitch + i * 3 + 1] = ngreen; // Green 
				fm[j * nPitch + i * 3 + 2] = nred; // Red 

			}
			else
			{
				fm[j * nPitch + i * 3 + 0] = 255; // Blue 
				fm[j * nPitch + i * 3 + 1] = 255; // Green 
				fm[j * nPitch + i * 3 + 2] = 255; // Red 

			}
		}
	}
}