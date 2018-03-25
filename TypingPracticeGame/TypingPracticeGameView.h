
// TypingPracticeGameView.h : CTypingPracticeGameView Ŭ������ �������̽�
//

#pragma once
#include "TypingPracticeGameDoc.h"
#include "NameDlg.h"
#include "ScoreDlg.h"
#include "InsertDlg.h"


class CTypingPracticeGameView : public CView
{
protected: // serialization������ ��������ϴ�.
	CTypingPracticeGameView();
	DECLARE_DYNCREATE(CTypingPracticeGameView)

// Ư���Դϴ�.
public:
	CTypingPracticeGameDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CTypingPracticeGameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
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

#ifndef _DEBUG  // TypingPracticeGameView.cpp�� ����� ����
inline CTypingPracticeGameDoc* CTypingPracticeGameView::GetDocument() const
   { return reinterpret_cast<CTypingPracticeGameDoc*>(m_pDocument); }
#endif

