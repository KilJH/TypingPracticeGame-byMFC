
// TypingPracticeGame.h : TypingPracticeGame ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CTypingPracticeGameApp:
// �� Ŭ������ ������ ���ؼ��� TypingPracticeGame.cpp�� �����Ͻʽÿ�.
//

class CTypingPracticeGameApp : public CWinAppEx
{
public:
	CTypingPracticeGameApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTypingPracticeGameApp theApp;