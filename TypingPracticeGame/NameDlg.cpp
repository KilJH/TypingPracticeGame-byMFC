// NameDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TypingPracticeGame.h"
#include "NameDlg.h"
#include "afxdialogex.h"
#include "TypingPracticeGameView.h"
#include "MainFrm.h"


// CNameDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CNameDlg, CDialogEx)

CNameDlg::CNameDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_NAME, pParent)
	, m_strName(_T(""))
{

}

CNameDlg::~CNameDlg()
{
}

void CNameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
}


BEGIN_MESSAGE_MAP(CNameDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SUBMIT, &CNameDlg::OnBnClickedButtonSubmit)
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()


// CNameDlg �޽��� ó�����Դϴ�.


BOOL CNameDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CTypingPracticeGameView *pView = (CTypingPracticeGameView *)pFrame->GetActiveView();
	
	CString score;
	score.Format(_T("����: %d"), pView->m_nScore);

	SetDlgItemText(IDC_STATIC_SCORE, score);
	

	

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CNameDlg::OnBnClickedButtonSubmit()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CStdioFile file;
	file.Open(_T("Score.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite); // �̸� ������ ���� ���� ����
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CTypingPracticeGameView *pView = (CTypingPracticeGameView *)pFrame->GetActiveView();

	CTime cTime = CTime::GetCurrentTime(); // ���� �ý������κ��� ��¥ �� �ð��� ��� �´�.

	CString strDate; // ��ȯ�Ǵ� ��¥�� �ð��� ������ CString ���� ����
	strDate.Format(_T("%04d��%02d��%02d��%02d��%02d��"), cTime.GetYear(), // ���� �⵵ ��ȯ
		cTime.GetMonth(), // ���� �� ��ȯ
		cTime.GetDay(), // ���� �� ��ȯ
		cTime.GetHour(), // ���� �ð� ��ȯ
		cTime.GetMinute()); // ���� �� ��ȯ


	CString scoreName;
	UpdateData(true);
	
	scoreName.Format(_T("%s %d %s"), m_strName, pView->m_nScore, strDate);

	file.SeekToEnd();
	file.WriteString(scoreName+"\n");

	file.Close();

	::SendMessage(this->m_hWnd, WM_CLOSE, NULL, NULL);
}


void CNameDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (nChar == VK_RETURN)
		return OnBnClickedButtonSubmit();

	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}


BOOL CNameDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE) return TRUE; // ����Ű�� ������� ���´�.

	return CDialogEx::PreTranslateMessage(pMsg);
}
