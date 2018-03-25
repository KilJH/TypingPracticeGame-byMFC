// NameDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "TypingPracticeGame.h"
#include "NameDlg.h"
#include "afxdialogex.h"
#include "TypingPracticeGameView.h"
#include "MainFrm.h"


// CNameDlg 대화 상자입니다.

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


// CNameDlg 메시지 처리기입니다.


BOOL CNameDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CTypingPracticeGameView *pView = (CTypingPracticeGameView *)pFrame->GetActiveView();
	
	CString score;
	score.Format(_T("점수: %d"), pView->m_nScore);

	SetDlgItemText(IDC_STATIC_SCORE, score);
	

	

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CNameDlg::OnBnClickedButtonSubmit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CStdioFile file;
	file.Open(_T("Score.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite); // 이름 저장을 위한 파일 생성
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CTypingPracticeGameView *pView = (CTypingPracticeGameView *)pFrame->GetActiveView();

	CTime cTime = CTime::GetCurrentTime(); // 현재 시스템으로부터 날짜 및 시간을 얻어 온다.

	CString strDate; // 반환되는 날짜와 시간을 저장할 CString 변수 선언
	strDate.Format(_T("%04d년%02d월%02d일%02d시%02d분"), cTime.GetYear(), // 현재 년도 반환
		cTime.GetMonth(), // 현재 월 반환
		cTime.GetDay(), // 현재 일 반환
		cTime.GetHour(), // 현재 시간 반환
		cTime.GetMinute()); // 현재 일 반환


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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nChar == VK_RETURN)
		return OnBnClickedButtonSubmit();

	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}


BOOL CNameDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE) return TRUE; // 엔터키로 종료됨을 막는다.

	return CDialogEx::PreTranslateMessage(pMsg);
}
