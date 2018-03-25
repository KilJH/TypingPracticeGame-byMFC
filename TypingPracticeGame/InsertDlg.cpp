// InsertDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "TypingPracticeGame.h"
#include "InsertDlg.h"
#include "afxdialogex.h"
#include <locale.h> 


// CInsertDlg 대화 상자입니다.

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


// CInsertDlg 메시지 처리기입니다.


BOOL CInsertDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

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
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CInsertDlg::OnBnClickedButtonInsert()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bLang == 0) {
		fileK.Open(_T("word_KOR.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite);
		UpdateData(TRUE);
		if (m_strWord.IsEmpty() == FALSE) {
			if (m_strWord.Find(_T(" "))>-1) {
				AfxMessageBox(_T("문자열에 공백이 있습니다."));
			}
			else {
				m_listWord.AddString(m_strWord);

				fileK.SeekToEnd();
				fileK.WriteString(m_strWord + _T("\n"));

				m_strWord.Empty();
			}
		}
		else {
			AfxMessageBox(_T("에디트 상자에 문자열이 없습니다."));
		}
		UpdateData(FALSE);
		fileK.Close();
	}
	else {
		fileE.Open(_T("word_ENG.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite);
		UpdateData(TRUE);
		if (m_strWord.IsEmpty() == FALSE) {
			if (m_strWord.Find(_T(" "))>-1) {
				AfxMessageBox(_T("문자열에 공백이 있습니다."));
			}
			else {
				m_listWord.AddString(m_strWord);

				fileE.SeekToEnd();
				fileE.WriteString(m_strWord + _T("\n"));

				m_strWord.Empty();
			}
		}
		else {
			AfxMessageBox(_T("에디트 상자에 문자열이 없습니다."));
		}
		UpdateData(FALSE);
		fileE.Close();
	}
}


BOOL CInsertDlg::DestroyWindow()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	//fileK.Close();
	//fileE.Close();

	return CDialogEx::DestroyWindow();
}


void CInsertDlg::OnBnClickedButtonDelete()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
			AfxMessageBox(_T("콤보 박스에서 삭제할 아이템을 선택하세요."));
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
			AfxMessageBox(_T("콤보 박스에서 삭제할 아이템을 선택하세요."));
		}
	}
}


void CInsertDlg::OnBnClickedButtonModify()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	int index = m_listWord.GetCurSel();
	CString modWord;
	CString fullString, word;
	if (m_bLang == 0) {
		fileK.Open(_T("word_KOR.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite);
		if (index != CB_ERR) {
			UpdateData(TRUE);
			if (m_strWord.IsEmpty() == FALSE) {
				if (m_strWord.Find(_T(" "))>-1) {
					AfxMessageBox(_T("문자열에 공백이 있습니다."));
				}
				else {
					m_listWord.GetText(index, modWord);

					while (fileK.ReadString(word)) {
						fullString += word + _T("\n");
					}

					fullString.Replace(modWord, m_strWord);

					fileK.Flush();
					fileK.SeekToBegin();                  //파일
					fileK.WriteString(fullString);


					m_listWord.DeleteString(index);           //리스트 박스
					m_listWord.InsertString(index, m_strWord);
					m_strWord.Empty();
					UpdateData(FALSE);
				}
			}
			else
			{
				AfxMessageBox(_T("에디트 상자에 문자열이 없습니다."));
			}
		}
		else {
			AfxMessageBox(_T("콤보 박스에서 수정할 아이템을 선택하세요."));
		}

		fileK.Close();
	}
	else {
		fileE.Open(_T("word_ENG.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite);
		if (index != CB_ERR) {
			UpdateData(TRUE);
			if (m_strWord.IsEmpty() == FALSE) {
				if (m_strWord.Find(_T(" "))>-1) {
					AfxMessageBox(_T("문자열에 공백이 있습니다."));
				}
				else {
					m_listWord.GetText(index, modWord);

					while (fileE.ReadString(word)) {
						fullString += word + _T("\n");
					}

					fullString.Replace(modWord, m_strWord);

					fileE.Flush();
					fileE.SeekToBegin();                  //파일
					fileE.WriteString(fullString);


					m_listWord.DeleteString(index);           //리스트 박스
					m_listWord.InsertString(index, m_strWord);
					m_strWord.Empty();
					UpdateData(FALSE);
				}
			}
			else
			{
				AfxMessageBox(_T("에디트 상자에 문자열이 없습니다."));
			}
		}
		else {
			AfxMessageBox(_T("콤보 박스에서 수정할 아이템을 선택하세요."));
		}

		fileE.Close();
	}
}


void CInsertDlg::OnBnClickedRadioInkor()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
