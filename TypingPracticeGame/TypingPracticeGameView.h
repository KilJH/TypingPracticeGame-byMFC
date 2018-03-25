
// TypingPracticeGameView.h : CTypingPracticeGameView 클래스의 인터페이스
//

#pragma once
#include "TypingPracticeGameDoc.h"
#include "NameDlg.h"
#include "ScoreDlg.h"
#include "InsertDlg.h"


class CTypingPracticeGameView : public CView
{
protected: // serialization에서만 만들어집니다.
	CTypingPracticeGameView();
	DECLARE_DYNCREATE(CTypingPracticeGameView)

// 특성입니다.
public:
	CTypingPracticeGameDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CTypingPracticeGameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	bool m_bTimerRun;
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	bool m_bGameLang;
	int m_nWord;
	CString* gameWord;
//	CString input;
	CString m_strInput;
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	int m_nSpeed;
	int m_nScore;
	CString m_strScore;
//	CString* m_strOutput;
//	CPoint* m_pOutput;
	CString m_strOutput[15];
	CPoint m_pOutput[15];
	int m_nCount;
	void GameOver();
	bool m_bBlankOn;
	bool m_bBlankEx;
	CNameDlg m_dlgName;
	bool m_bGameOver;
	afx_msg void On32771();
	CScoreDlg m_dlgScore;
	afx_msg void On32772();
	CInsertDlg m_dlgInsert;
};

#ifndef _DEBUG  // TypingPracticeGameView.cpp의 디버그 버전
inline CTypingPracticeGameDoc* CTypingPracticeGameView::GetDocument() const
   { return reinterpret_cast<CTypingPracticeGameDoc*>(m_pDocument); }
#endif

