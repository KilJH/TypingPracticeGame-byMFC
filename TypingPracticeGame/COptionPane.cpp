#include "stdafx.h"
#include "COptionPane.h"


COptionPane::COptionPane()
{
}


COptionPane::~COptionPane()
{
}
BEGIN_MESSAGE_MAP(COptionPane, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()


int COptionPane::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	if (!m_ctrlOption.Create(IDD_DIALOG_OPTION, this)) {
		TRACE0("옵션 윈도우를 만들지 못했습니다.\n");
		return -1;
	}
	m_ctrlOption.ShowWindow(SW_SHOW);


	return 0;
}


void COptionPane::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if (m_ctrlOption.GetSafeHwnd()) {
		m_ctrlOption.MoveWindow(0, 0, cx, cy);
		m_ctrlOption.SetFocus();
	}
}
