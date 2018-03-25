// ScoreDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TypingPracticeGame.h"
#include "ScoreDlg.h"
#include "afxdialogex.h"


// CScoreDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CScoreDlg, CDialogEx)

CScoreDlg::CScoreDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_SCORE, pParent)
{

}

CScoreDlg::~CScoreDlg()
{
}

void CScoreDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_SCORE, m_listScore);
}


BEGIN_MESSAGE_MAP(CScoreDlg, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_SCORE, &CScoreDlg::OnLvnItemchangedListScore)
END_MESSAGE_MAP()


// CScoreDlg �޽��� ó�����Դϴ�.


BOOL CScoreDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	LPWSTR list[] = { _T("�̸�"),_T("����"), _T("��¥") };
	int nWidth[] = { 80,80,200 };

	for (int i = 0; i < 3; i++) {
		m_listScore.InsertColumn(i, list[i], LVCFMT_CENTER, nWidth[i]);
	}

	CStdioFile file;
	file.Open(_T("Score.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeRead);
	m_listScore.GetItemCount();
	CString strName, strScore, strDate;
	CString temp;
	int i = 0;
	CString num;
	while (file.ReadString(temp)) {
		
		AfxExtractSubString(strName, temp, 0, ' ');
		AfxExtractSubString(strScore, temp, 1, ' ');
		AfxExtractSubString(strDate, temp, 2, ' ');
		//num.Format(_T("%d"), i);

		m_listScore.InsertItem(i,num);
		m_listScore.SetItem(i, 0, LVIF_TEXT, strName, 0, 0, 0, 0);
		m_listScore.SetItem(i, 1, LVIF_TEXT, strScore, 0, 0, 0, 0);
		m_listScore.SetItem(i, 2, LVIF_TEXT, strDate, 0, 0, 0, 0);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CScoreDlg::OnLvnItemchangedListScore(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	*pResult = 0;
}
