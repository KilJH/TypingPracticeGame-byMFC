#pragma once
#include "afxcmn.h"


// CScoreDlg ��ȭ �����Դϴ�.

class CScoreDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CScoreDlg)

public:
	CScoreDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CScoreDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SCORE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnLvnItemchangedListScore(NMHDR *pNMHDR, LRESULT *pResult);
	CListCtrl m_listScore;
};
