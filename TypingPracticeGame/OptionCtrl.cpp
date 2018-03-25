// OptionCtrl.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "OptionCtrl.h"
#include "afxdialogex.h"
#include "TypingPracticeGame.h"
#include "TypingPracticeGameView.h"
#include "MainFrm.h"


// COptionCtrl ��ȭ �����Դϴ�.

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


// COptionCtrl �޽��� ó�����Դϴ�.


BOOL COptionCtrl::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	SetDlgItemText(IDC_STATIC_SCORE, _T("0"));

	((CButton*)GetDlgItem(IDC_RADIO_KOR))->SetCheck(1);

	m_sliderSpeed.SetRange(5, 35);
	m_sliderSpeed.SetPos(10);
	

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void COptionCtrl::OnNMCustomdrawSliderSpeed(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	*pResult = 0;
}

void COptionCtrl::OnBnClickedButtonAddtext()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_dlgInsert.DoModal();
}


void COptionCtrl::OnBnClickedRadioKor()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CTypingPracticeGameView *pView = (CTypingPracticeGameView *)pFrame->GetActiveView();
	pView->m_bGameLang = 0;
}


void COptionCtrl::OnBnClickedRadioEng()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CTypingPracticeGameView *pView = (CTypingPracticeGameView *)pFrame->GetActiveView();
	pView->m_bGameLang = 1;
}


void COptionCtrl::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CTypingPracticeGameView *pView = (CTypingPracticeGameView *)pFrame->GetActiveView();
	pView->m_nSpeed = m_sliderSpeed.GetPos();
	KillTimer(0);
	pView->SetTimer(0, (int)(20000 / pView->m_nSpeed), NULL);

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void COptionCtrl::OnBnClickedButtonOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void COptionCtrl::OnBnClickedCheckBlank()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CTypingPracticeGameView *pView = (CTypingPracticeGameView *)pFrame->GetActiveView();
	//��Ʈ�� ���� �ָ� ��Ÿ�� ����...

	UpdateData(TRUE);
	pView->m_bBlankOn = m_bBlank;
	UpdateData(FALSE);
}
