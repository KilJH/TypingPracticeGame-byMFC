#pragma once


// CNameDlg ��ȭ �����Դϴ�.

class CNameDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CNameDlg)

public:
	CNameDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CNameDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_NAME };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonSubmit();
	CString m_strName;
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
