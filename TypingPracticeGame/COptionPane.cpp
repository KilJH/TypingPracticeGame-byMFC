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

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	if (!m_ctrlOption.Create(IDD_DIALOG_OPTION, this)) {
		TRACE0("�ɼ� �����츦 ������ ���߽��ϴ�.\n");
		return -1;
	}
	m_ctrlOption.ShowWindow(SW_SHOW);


	return 0;
}


void COptionPane::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	if (m_ctrlOption.GetSafeHwnd()) {
		m_ctrlOption.MoveWindow(0, 0, cx, cy);
		m_ctrlOption.SetFocus();
	}
}
