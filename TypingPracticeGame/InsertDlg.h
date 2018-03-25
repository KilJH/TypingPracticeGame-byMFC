#pragma once
#include "afxwin.h"
#include "afx.h"


// CInsertDlg 대화 상자입니다.

class CInsertDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CInsertDlg)

public:
	CInsertDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CInsertDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_INSERT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
