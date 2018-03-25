// OptionCtrl.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "OptionCtrl.h"
#include "afxdialogex.h"
#include "TypingPracticeGame.h"
#include "TypingPracticeGameView.h"
#include "MainFrm.h"


// COptionCtrl 대화 상자입니다.

IMPLEMENT_DYNAMIC(COptionCtrl, CDialogEx)

COptionCtrl::COptionCtrl(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_OPTION, pParent)
	, m_nScore(0)
	, m_bBlank(FALSE)
{

	//  m_nSpeed = 0;
}

COptionCtrl::~COptionCtrl()
{
}

void COptionCtrl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER_SPEED, m_sliderSpeed);
	//  DDX_Check(pDX, IDC_CHECK_BLANK, m_bBlank);
	//  DDX_Check(pDX, IDC_CHECK_BLANK, m_bBlank);
	DDX_Check(pDX, IDC_CHECK_BLANK, m_bBlank);
}


BEGIN_MESSAGE_MAP(COptionCtrl, CDialogEx)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_SPEED, &COptionCtrl::OnNMCustomdrawSliderSpeed)
	ON_BN_CLICKED(IDC_BUTTON_ADDTEXT, &COptionCtrl::OnBnClickedButtonAddtext)
	ON_BN_CLICKED(IDC_RADIO_KOR, &COptionCtrl::OnBnClickedRadioKor)
	ON_BN_CLICKED(IDC_RADIO_ENG, &COptionCtrl::OnBnClickedRadioEng)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_BUTTON_OK, &COptionCtrl::OnBnClickedButtonOk)
	ON_BN_CLICKED(IDC_CHECK_BLANK, &COptionCtrl::OnBnClickedCheckBlank)
END_MESSAGE_MAP()


// COptionCtrl 메시지 처리기입니다.


BOOL COptionCtrl::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetDlgItemText(IDC_STATIC_SCORE, _T("0"));

	((CButton*)GetDlgItem(IDC_RADIO_KOR))->SetCheck(1);

	m_sliderSpeed.SetRange(5, 35);
	m_sliderSpeed.SetPos(10);
	

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void COptionCtrl::OnNMCustomdrawSliderSpeed(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}

void COptionCtrl::OnBnClickedButtonAddtext()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_dlgInsert.DoModal();
}


void COptionCtrl::OnBnClickedRadioKor()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CTypingPracticeGameView *pView = (CTypingPracticeGameView *)pFrame->GetActiveView();
	pView->m_bGameLang = 0;
}


void COptionCtrl::OnBnClickedRadioEng()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CTypingPracticeGameView *pView = (CTypingPracticeGameView *)pFrame->GetActiveView();
	pView->m_bGameLang = 1;
}


void COptionCtrl::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CTypingPracticeGameView *pView = (CTypingPracticeGameView *)pFrame->GetActiveView();
	pView->m_nSpeed = m_sliderSpeed.GetPos();
	KillTimer(0);
	pView->SetTimer(0, (int)(20000 / pView->m_nSpeed), NULL);

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void COptionCtrl::OnBnClickedButtonOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void COptionCtrl::OnBnClickedCheckBlank()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CTypingPracticeGameView *pView = (CTypingPracticeGameView *)pFrame->GetActiveView();
	//컨트롤 변수 주면 런타임 오류...

	UpdateData(TRUE);
	pView->m_bBlankOn = m_bBlank;
	UpdateData(FALSE);
}
