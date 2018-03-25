
// TypingPracticeGameView.cpp : CTypingPracticeGameView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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
	// 표준 인쇄 명령입니다.
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

// CTypingPracticeGameView 생성/소멸

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
	// TODO: 여기에 생성 코드를 추가합니다.

	m_strInput = _T("");
}

CTypingPracticeGameView::~CTypingPracticeGameView()
{
}

BOOL CTypingPracticeGameView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CTypingPracticeGameView 그리기

void CTypingPracticeGameView::OnDraw(CDC* pDC)
{
	CTypingPracticeGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	CRect rect;
	GetClientRect(&rect);
	
	if (m_bTimerRun == false) {
		pDC->DrawText(_T("게임을 시작하려면 Space를 눌러주세요"), rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		pDC->DrawText(m_strScore, rect, DT_SINGLELINE | DT_RIGHT | DT_BOTTOM); // 점수창
	}
	else {

		pDC->DrawText(m_strInput, rect, DT_SINGLELINE | DT_CENTER | DT_BOTTOM); // 입력창
		pDC->DrawText(m_strScore, rect, DT_SINGLELINE | DT_RIGHT | DT_BOTTOM); // 점수창

		if (m_bBlankEx) {
			for (int i = 0; i < m_nCount; i++) {
				pDC->TextOutW(m_pOutput[i].x, m_pOutput[i].y, m_strOutput[i]);
			}
		}
	}

	

}


// CTypingPracticeGameView 인쇄


void CTypingPracticeGameView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTypingPracticeGameView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CTypingPracticeGameView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CTypingPracticeGameView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CTypingPracticeGameView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	//ClientToScreen(&point);
	//OnContextMenu(this, point);
	GameOver();
	MessageBox(_T("게임 끝"));
}

void CTypingPracticeGameView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTypingPracticeGameView 진단

#ifdef _DEBUG
void CTypingPracticeGameView::AssertValid() const
{
	CView::AssertValid();
}

void CTypingPracticeGameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTypingPracticeGameDoc* CTypingPracticeGameView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTypingPracticeGameDoc)));
	return (CTypingPracticeGameDoc*)m_pDocument;
}
#endif //_DEBUG


// CTypingPracticeGameView 메시지 처리기


int CTypingPracticeGameView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	setlocale(LC_ALL, "korean");
	

	return 0;
}


void CTypingPracticeGameView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	
	if (nChar == VK_SPACE) {  // 게임시작키
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
			}  // 언어에 따라 파일에서 단어 저장

			m_strScore.Format(_T("점수: %d"), m_nScore = 0);
			SetTimer(0, (int)(20000 / m_nSpeed), NULL);
			m_bTimerRun = TRUE; // 게임 시작

			Invalidate();
		}
	}


	if (nChar == VK_RETURN) {  // 엔터입력
		if (m_bTimerRun == TRUE) {
			//if()// input이랑 나와있는 값이랑 비교해서 같으면 사라지고 어찌구
			for (int i = 0; i < m_nCount; i++) {
				if (m_strInput.Compare(m_strOutput[i]) == 0) {
					m_nScore += m_strInput.GetLength();
					m_strScore.Format(_T("점수: %d"), m_nScore); // 글자 수 만큼 점수 상승

					for (int j = i; j < m_nCount - 1; j++) {  // 맞추면 아웃풋배열 재정렬
						m_strOutput[j] = m_strOutput[j + 1];
						m_pOutput[j] = m_pOutput[j + 1];
					}

					m_strOutput[m_nCount - 1].Empty();
					m_pOutput[m_nCount - 1].SetPoint(0, 0);
					m_nCount--;  //카운트 하락
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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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

		if (m_nCount > 14) {  //게임오버 1
			GameOver();
			MessageBox(_T("GameOver!\n단어가 15개를 초과했습니다."));
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
			MessageBox(_T("GameOver!\n단어가 바닥에 닿았습니다."));
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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int nCharIndex;
	nCharIndex = m_strInput.GetLength();
	
	if (nChar != VK_RETURN && nChar != VK_SPACE) {  // 인풋에 시작의 스페이스, 엔터값이 안들어가게
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
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_dlgScore.DoModal();
}


void CTypingPracticeGameView::On32772()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_dlgInsert.DoModal();
}
