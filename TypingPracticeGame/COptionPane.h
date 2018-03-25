#pragma once
#include "afxdockablepane.h"
#include "OptionCtrl.h"
#include "TypingPracticeGame.h"
class COptionPane :
	public CDockablePane
{
public:
	COptionPane();
	~COptionPane();
	COptionCtrl m_ctrlOption;
	DECLARE_MESSAGE_MAP()
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

