#pragma once


// CSetlevel �Ի���

class CSetlevel : public CDialog
{
	DECLARE_DYNAMIC(CSetlevel)

public:
	CSetlevel(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSetlevel();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	// //���õл��ٶ�
	int m_level;
};
