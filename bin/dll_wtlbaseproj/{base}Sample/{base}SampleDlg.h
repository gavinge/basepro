// {base}SampleDlg.h : ͷ�ļ�
//

#pragma once

#include <Shlwapi.h>
#pragma comment(lib,"shlwapi.lib")
#include "..\ExportInterface\C{base}Helper.h"

// C{base}SampleDlg �Ի���
class C{base}SampleDlg : public CDialog
{
// ����
public:
	C{base}SampleDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_{base}Sample_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	I{base} *m_p{base};
};
