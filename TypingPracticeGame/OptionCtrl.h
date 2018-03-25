#pragma once
#include "afxcmn.h"
#include "InsertDlg.h"


// COptionCtrl ��ȭ �����Դϴ�.

class COptionCtrl : public CDialogEx
{
	DECLARE_DYNAMIC(COptionCtrl)

public:
	COptionCtrl(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~COptionCtrl();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_OPTION };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
