#pragma once
#include "afxcmn.h"


// CScoreDlg 대화 상자입니다.

class CScoreDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CScoreDlg)

public:
	CScoreDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CScoreDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SCORE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnLvnItemchangedListScore(NMHDR *pNMHDR, LRESULT *pResult);
	CListCtrl m_listScore;
};
