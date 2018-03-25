#pragma once
#include "afxwin.h"
#include "afx.h"


// CInsertDlg ��ȭ �����Դϴ�.

class CInsertDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CInsertDlg)

public:
	CInsertDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CInsertDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_INSERT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_listWord;
	CString m_strWord;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonInsert();
	CStdioFile fileK;
	CStdioFile fileE;
	virtual BOOL DestroyWindow();
	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnBnClickedButtonModify();
	bool m_bLang;
	afx_msg void OnBnClickedRadioInkor();
	afx_msg void OnBnClickedRadioIneng();
};
