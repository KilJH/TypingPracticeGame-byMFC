
// TypingPracticeGameView.cpp : CTypingPracticeGameView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "TypingPracticeGame.h"
#endif

//#include "TypingPracticeGameDoc.h"
#include "TypingPracticeGameView.h"
#include <stdlib.h>
#include <time.h>
#include <locale.h> 

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTypingPracticeGameView

IMPLEMENT_DYNCREATE(CTypingPracticeGameView, CView)

BEGIN_MESSAGE_MAP(CTypingPracticeGameView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTypingPracticeGameView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
	ON_WM_CHAR()
	ON_COMMAND(ID_32771, &CTypingPracticeGameView::On32771)
	ON_COMMAND(ID_32772, &CTypingPracticeGameView::On32772)
END_MESSAGE_MAP()

// CTypingPracticeGameView ����/�Ҹ�

CTypingPracticeGameView::CTypingPracticeGameView()
	: m_bTimerRun(false)
	, m_bGameLang(false)
	, m_nWord(0)
	, gameWord(NULL)
	, m_nSpeed(10)
	, m_nScore(0)
	, m_strScore(_T(""))
	, m_nCount(0)
	, m_bBlankOn(false)
	, m_bBlankEx(true)
	, m_bGameOver(false)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

	m_strInput = _T("");
}

CTypingPracticeGameView::~CTypingPracticeGameView()
{
}

BOOL CTypingPracticeGameView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CTypingPracticeGameView �׸���

void CTypingPracticeGameView::OnDraw(CDC* pDC)
{
	CTypingPracticeGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	CRect rect;
	GetClientRect(&rect);
	
	if (m_bTimerRun == false) {
		pDC->DrawText(_T("������ �����Ϸ��� Space�� �����ּ���"), rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		pDC->DrawText(m_strScore, rect, DT_SINGLELINE | DT_RIGHT | DT_BOTTOM); // ����â
	}
	else {

		pDC->DrawText(m_strInput, rect, DT_SINGLELINE | DT_CENTER | DT_BOTTOM); // �Է�â
		pDC->DrawText(m_strScore, rect, DT_SINGLELINE | DT_RIGHT | DT_BOTTOM); // ����â

		if (m_bBlankEx) {
			for (int i = 0; i < m_nCount; i++) {
				pDC->TextOutW(m_pOutput[i].x, m_pOutput[i].y, m_strOutput[i]);
			}
		}
	}

	

}


// CTypingPracticeGameView �μ�


void CTypingPracticeGameView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTypingPracticeGameView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CTypingPracticeGameView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CTypingPracticeGameView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CTypingPracticeGameView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	//ClientToScreen(&point);
	//OnContextMenu(this, point);
	GameOver();
	MessageBox(_T("���� ��"));
}

void CTypingPracticeGameView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTypingPracticeGameView ����

#ifdef _DEBUG
void CTypingPracticeGameView::AssertValid() const
{
	CView::AssertValid();
}

void CTypingPracticeGameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTypingPracticeGameDoc* CTypingPracticeGameView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTypingPracticeGameDoc)));
	return (CTypingPracticeGameDoc*)m_pDocument;
}
#endif //_DEBUG


// CTypingPracticeGameView �޽��� ó����


int CTypingPracticeGameView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	setlocale(LC_ALL, "korean");
	

	return 0;
}


void CTypingPracticeGameView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	
	if (nChar == VK_SPACE) {  // ���ӽ���Ű
		if (m_bTimerRun == FALSE) {
			if (m_bGameLang == 0) {
				CStdioFile file;
				file.Open(_T("word_KOR.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeRead);

				CString word = _T("");

				while (file.ReadString(word)) {
					m_nWord++;
				}
				gameWord = new CString[m_nWord];

				int n = 0;
				file.SeekToBegin();
				while (file.ReadString(word)) {
					gameWord[n++] = word;
				}
				file.Close();
			}
			else {
				CStdioFile file;
				file.Open(_T("word_ENG.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeRead);

				CString word = _T("");

				while (file.ReadString(word)) {
					m_nWord++;
				}

				gameWord = new CString[m_nWord];

				int n = 0;
				file.SeekToBegin();
				while (file.ReadString(word)) {
					gameWord[n++] = word;
				}
				file.Close();
			}  // �� ���� ���Ͽ��� �ܾ� ����

			m_strScore.Format(_T("����: %d"), m_nScore = 0);
			SetTimer(0, (int)(20000 / m_nSpeed), NULL);
			m_bTimerRun = TRUE; // ���� ����

			Invalidate();
		}
	}


	if (nChar == VK_RETURN) {  // �����Է�
		if (m_bTimerRun == TRUE) {
			//if()// input�̶� �����ִ� ���̶� ���ؼ� ������ ������� ���
			for (int i = 0; i < m_nCount; i++) {
				if (m_strInput.Compare(m_strOutput[i]) == 0) {
					m_nScore += m_strInput.GetLength();
					m_strScore.Format(_T("����: %d"), m_nScore); // ���� �� ��ŭ ���� ���

					for (int j = i; j < m_nCount - 1; j++) {  // ���߸� �ƿ�ǲ�迭 ������
						m_strOutput[j] = m_strOutput[j + 1];
						m_pOutput[j] = m_pOutput[j + 1];
					}

					m_strOutput[m_nCount - 1].Empty();
					m_pOutput[m_nCount - 1].SetPoint(0, 0);
					m_nCount--;  //ī��Ʈ �϶�
					break;
				}
			}


			m_strInput.Empty();

			Invalidate();
		}
	}


	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CTypingPracticeGameView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (m_bTimerRun == TRUE) {
		CRect rect;
		GetClientRect(rect);
		CClientDC dc(this);

		if (m_bBlankOn) {
			if (m_bBlankEx == 0)
				m_bBlankEx = 1;
			else
				m_bBlankEx = 0;
		}
		else {
			m_bBlankEx = 1;
		}

		srand((unsigned)time(NULL));
		m_strOutput[m_nCount] = gameWord[rand() % m_nWord];
		m_pOutput[m_nCount++].x = rand() % rect.Width();

		if (m_nCount > 14) {  //���ӿ��� 1
			GameOver();
			MessageBox(_T("GameOver!\n�ܾ 15���� �ʰ��߽��ϴ�."));
			if (m_bGameOver == true) {

				m_dlgName.DoModal();
				m_bGameOver = false;
			}
		}

		for (int i = 0; i < m_nCount; i++) {
			m_pOutput[i].y += 20;
		}
		
		if (m_pOutput[0].y > rect.bottom)
		{

			GameOver();
			MessageBox(_T("GameOver!\n�ܾ �ٴڿ� ��ҽ��ϴ�."));
			if (m_bGameOver == true) {

				m_dlgName.DoModal();
				m_bGameOver = false;
			}
		}

		//OutputDebugString(output);

		Invalidate();
	}

	CView::OnTimer(nIDEvent);
}


void CTypingPracticeGameView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	int nCharIndex;
	nCharIndex = m_strInput.GetLength();
	
	if (nChar != VK_RETURN && nChar != VK_SPACE) {  // ��ǲ�� ������ �����̽�, ���Ͱ��� �ȵ���
		if (nChar == VK_BACK)
			m_strInput.Delete(nCharIndex - 1.1);
		else
			m_strInput += (WCHAR)nChar;

		Invalidate();
	}

	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CTypingPracticeGameView::GameOver()
{
	KillTimer(0);
	m_bTimerRun = FALSE;
	m_nCount = 0;
	for (int i = 0; i < 15; i++) {
		m_strOutput[i].Empty();
		m_pOutput[i].SetPoint(0, 0);
	}
	delete [] gameWord;
	m_nWord = 0;
	m_bGameOver = true;

	Invalidate();

}


void CTypingPracticeGameView::On32771()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_dlgScore.DoModal();
}


void CTypingPracticeGameView::On32772()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_dlgInsert.DoModal();
}
