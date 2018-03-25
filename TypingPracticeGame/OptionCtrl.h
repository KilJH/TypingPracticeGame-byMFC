#pragma once
#include "afxcmn.h"
#include "InsertDlg.h"


// COptionCtrl 대화 상자입니다.

class COptionCtrl : public CDialogEx
{
	DECLARE_DYNAMIC(COptionCtrl)

public:
	COptionCtrl(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~COptionCtrl();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_OPTION };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnNMCustomdrawSliderSpeed(NMHDR *pNMHDR, LRESULT *pResult);
	CSliderCtrl m_sliderSpeed;
	int m_nScore;
//	bool m_bLang;
	afx_msg void OnBnClickedButtonAddtext();
	CInsertDlg m_dlgInsert;
	afx_msg void OnBnClickedRadioKor();
	afx_msg void OnBnClickedRadioEng();
//	bool m_bGameLang;
//	bool m_bGameLang;
//	int m_nSpeed;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnBnClickedButtonOk();
//	bool m_bBlank;
	afx_msg void OnBnClickedCheckBlank();
//	bool m_bBlank;
//	BOOL m_bBlank;
	BOOL m_bBlank;
};
