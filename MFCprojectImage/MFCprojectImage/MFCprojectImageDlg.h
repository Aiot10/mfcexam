
// MFCprojectImageDlg.h: 헤더 파일
//
#include"CDlgimage.h"
#pragma once


// CMFCprojectImageDlg 대화 상자
class CMFCprojectImageDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCprojectImageDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	CDlgimage* m_pDlgimage;
	int m_radius;

	

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCPROJECTIMAGE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:

	CEdit m_myedit;
	afx_msg void OnBnClickedBtnCircle();
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedBtnFind();
	CButton m_fcenter;
	void DrawCircle(int nblue,int ngreen,int nred,int CenterX,int CenterY);
};
