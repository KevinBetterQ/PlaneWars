#pragma once


// CSetlevel 对话框

class CSetlevel : public CDialog
{
	DECLARE_DYNAMIC(CSetlevel)

public:
	CSetlevel(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSetlevel();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// //设置敌机速度
	int m_level;
};
