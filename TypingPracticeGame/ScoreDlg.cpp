// ScoreDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "TypingPracticeGame.h"
#include "ScoreDlg.h"
#include "afxdialogex.h"


// CScoreDlg 대화 상자입니다.

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


// CScoreDlg 메시지 처리기입니다.


BOOL CScoreDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	LPWSTR list[] = { _T("이름"),_T("점수"), _T("날짜") };
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
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CScoreDlg::OnLvnItemchangedListScore(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}
