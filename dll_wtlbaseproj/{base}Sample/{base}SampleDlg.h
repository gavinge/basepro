// {base}SampleDlg.h : 头文件
//

#pragma once

#include <Shlwapi.h>
#pragma comment(lib,"shlwapi.lib")
#include "..\ExportInterface\C{base}Helper.h"

// C{base}SampleDlg 对话框
class C{base}SampleDlg : public CDialog
{
// 构造
public:
	C{base}SampleDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_{base}Sample_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	I{base} *m_p{base};
};
