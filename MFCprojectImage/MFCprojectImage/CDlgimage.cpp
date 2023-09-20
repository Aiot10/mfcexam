// CDlgimage.cpp: 구현 파일
//

#include "pch.h"
#include "MFCprojectImage.h"
#include "afxdialogex.h"
#include "CDlgimage.h"


// CDlgimage 대화 상자

IMPLEMENT_DYNAMIC(CDlgimage, CDialogEx)

CDlgimage::CDlgimage(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CDlgimage, pParent)
{

}

CDlgimage::~CDlgimage()
{
}

void CDlgimage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgimage, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlgimage 메시지 처리기


BOOL CDlgimage::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	
	MoveWindow(0, 0, 640, 480);

	Initimage();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDlgimage::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.

	if (m_image)
	{
		m_image.Draw(dc, 0, 0);
	}

	
}
void CDlgimage::Initimage()
{
	int nWidth = 640;
	int nHeight = 480;
	int nBpp = 24; // 24 비트 컬러

	m_image.Create(nWidth, -nHeight, nBpp);

	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	for (int j = 0; j < nHeight; j++) {
		for (int i = 0; i < nWidth; i++) {
			
			fm[j * nPitch + i * 3 + 0] = 255; // Blue 
			fm[j * nPitch + i * 3 + 1] = 255; // Green 
			fm[j * nPitch + i * 3 + 2] = 255; // Red 
		}
	}

}



