// InsertDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TypingPracticeGame.h"
#include "InsertDlg.h"
#include "afxdialogex.h"
#include <locale.h> 


// CInsertDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CInsertDlg, CDialogEx)

CInsertDlg::CInsertDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_INSERT, pParent)
	, m_strWord(_T(""))
	, m_bLang(false)
{

}

CInsertDlg::~CInsertDlg()
{
}

void CInsertDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_WORD, m_listWord);
	DDX_Text(pDX, IDC_EDIT_WORD, m_strWord);
}


BEGIN_MESSAGE_MAP(CInsertDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_INSERT, &CInsertDlg::OnBnClickedButtonInsert)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CInsertDlg::OnBnClickedButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY, &CInsertDlg::OnBnClickedButtonModify)
	ON_BN_CLICKED(IDC_RADIO_INKOR, &CInsertDlg::OnBnClickedRadioInkor)
	ON_BN_CLICKED(IDC_RADIO_INENG, &CInsertDlg::OnBnClickedRadioIneng)
END_MESSAGE_MAP()


// CInsertDlg �޽��� ó�����Դϴ�.


BOOL CInsertDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	setlocale(LC_ALL, "korean");

	((CButton*)GetDlgItem(IDC_RADIO_INKOR))->SetCheck(1);

	fileK.Open(_T("word_KOR.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite);

	CString wordKor = _T("");
	int dwCount = 0;

	while (fileK.ReadString(wordKor)) {
		m_listWord.AddString(wordKor);
	}


	fileK.Close();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CInsertDlg::OnBnClickedButtonInsert()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_bLang == 0) {
		fileK.Open(_T("word_KOR.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite);
		UpdateData(TRUE);
		if (m_strWord.IsEmpty() == FALSE) {
			if (m_strWord.Find(_T(" "))>-1) {
				AfxMessageBox(_T("���ڿ��� ������ �ֽ��ϴ�."));
			}
			else {
				m_listWord.AddString(m_strWord);

				fileK.SeekToEnd();
				fileK.WriteString(m_strWord + _T("\n"));

				m_strWord.Empty();
			}
		}
		else {
			AfxMessageBox(_T("����Ʈ ���ڿ� ���ڿ��� �����ϴ�."));
		}
		UpdateData(FALSE);
		fileK.Close();
	}
	else {
		fileE.Open(_T("word_ENG.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite);
		UpdateData(TRUE);
		if (m_strWord.IsEmpty() == FALSE) {
			if (m_strWord.Find(_T(" "))>-1) {
				AfxMessageBox(_T("���ڿ��� ������ �ֽ��ϴ�."));
			}
			else {
				m_listWord.AddString(m_strWord);

				fileE.SeekToEnd();
				fileE.WriteString(m_strWord + _T("\n"));

				m_strWord.Empty();
			}
		}
		else {
			AfxMessageBox(_T("����Ʈ ���ڿ� ���ڿ��� �����ϴ�."));
		}
		UpdateData(FALSE);
		fileE.Close();
	}
}


BOOL CInsertDlg::DestroyWindow()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	//fileK.Close();
	//fileE.Close();

	return CDialogEx::DestroyWindow();
}


void CInsertDlg::OnBnClickedButtonDelete()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_bLang == 0) {
		fileK.Open(_T("word_KOR.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite);
		int index = m_listWord.GetCurSel();
		CString delWord;
		CString fullString, word;
		if (index != CB_ERR) {
			m_listWord.GetText(index, delWord);

			while (fileK.ReadString(word)) {
				fullString += word + _T("\n");
			}

			int pos = fullString.Find(delWord);
			fullString.Delete(pos, delWord.GetLength() + 1);

			fileK.Close();
			fileK.Open(_T("word_KOR.txt"), CFile::modeCreate | CFile::modeReadWrite);
			//fileK.Flush();
			fileK.SeekToBegin();
			fileK.WriteString(fullString);


			m_listWord.DeleteString(index);

			fileK.Close();
		}
		else {
			AfxMessageBox(_T("�޺� �ڽ����� ������ �������� �����ϼ���."));
		}
	}
	else {
		fileE.Open(_T("word_ENG.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite);
		int index = m_listWord.GetCurSel();
		CString delWord;
		CString fullString, word;
		if (index != CB_ERR) {
			m_listWord.GetText(index, delWord);

			while (fileE.ReadString(word)) {
				fullString += word + _T("\n");
			}

			int pos = fullString.Find(delWord);
			fullString.Delete(pos, delWord.GetLength() + 1);

			fileE.Close();
			fileE.Open(_T("word_ENG.txt"), CFile::modeCreate | CFile::modeReadWrite);
			//fileE.Flush();
			fileE.SeekToBegin();
			fileE.WriteString(fullString);


			m_listWord.DeleteString(index);

			fileE.Close();
		}
		else {
			AfxMessageBox(_T("�޺� �ڽ����� ������ �������� �����ϼ���."));
		}
	}
}


void CInsertDlg::OnBnClickedButtonModify()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	
	int index = m_listWord.GetCurSel();
	CString modWord;
	CString fullString, word;
	if (m_bLang == 0) {
		fileK.Open(_T("word_KOR.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite);
		if (index != CB_ERR) {
			UpdateData(TRUE);
			if (m_strWord.IsEmpty() == FALSE) {
				if (m_strWord.Find(_T(" "))>-1) {
					AfxMessageBox(_T("���ڿ��� ������ �ֽ��ϴ�."));
				}
				else {
					m_listWord.GetText(index, modWord);

					while (fileK.ReadString(word)) {
						fullString += word + _T("\n");
					}

					fullString.Replace(modWord, m_strWord);

					fileK.Flush();
					fileK.SeekToBegin();                  //����
					fileK.WriteString(fullString);


					m_listWord.DeleteString(index);           //����Ʈ �ڽ�
					m_listWord.InsertString(index, m_strWord);
					m_strWord.Empty();
					UpdateData(FALSE);
				}
			}
			else
			{
				AfxMessageBox(_T("����Ʈ ���ڿ� ���ڿ��� �����ϴ�."));
			}
		}
		else {
			AfxMessageBox(_T("�޺� �ڽ����� ������ �������� �����ϼ���."));
		}

		fileK.Close();
	}
	else {
		fileE.Open(_T("word_ENG.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite);
		if (index != CB_ERR) {
			UpdateData(TRUE);
			if (m_strWord.IsEmpty() == FALSE) {
				if (m_strWord.Find(_T(" "))>-1) {
					AfxMessageBox(_T("���ڿ��� ������ �ֽ��ϴ�."));
				}
				else {
					m_listWord.GetText(index, modWord);

					while (fileE.ReadString(word)) {
						fullString += word + _T("\n");
					}

					fullString.Replace(modWord, m_strWord);

					fileE.Flush();
					fileE.SeekToBegin();                  //����
					fileE.WriteString(fullString);


					m_listWord.DeleteString(index);           //����Ʈ �ڽ�
					m_listWord.InsertString(index, m_strWord);
					m_strWord.Empty();
					UpdateData(FALSE);
				}
			}
			else
			{
				AfxMessageBox(_T("����Ʈ ���ڿ� ���ڿ��� �����ϴ�."));
			}
		}
		else {
			AfxMessageBox(_T("�޺� �ڽ����� ������ �������� �����ϼ���."));
		}

		fileE.Close();
	}
}


void CInsertDlg::OnBnClickedRadioInkor()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_bLang = 0;

	m_listWord.ResetContent();

	fileK.Open(_T("word_KOR.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite);

	CString wordKor = _T("");
	int dwCount = 0;

	while (fileK.ReadString(wordKor)) {
		m_listWord.AddString(wordKor);
	}


	fileK.Close();

	Invalidate();
}


void CInsertDlg::OnBnClickedRadioIneng()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_bLang = 1;
	m_listWord.ResetContent();
	fileE.Open(_T("word_ENG.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite);

	CString wordEng = _T("");
	int dwCount = 0;

	while (fileE.ReadString(wordEng)) {
		m_listWord.AddString(wordEng);
	}


	fileE.Close();

	Invalidate();
}
