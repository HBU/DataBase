#if !defined(AFX_TABLENAME_H__4E76CFCB_054C_4BB9_889E_22492615C74B__INCLUDED_)
#define AFX_TABLENAME_H__4E76CFCB_054C_4BB9_889E_22492615C74B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TableName.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTableName dialog

class CTableName : public CDialog
{
// Construction
public:
	CTableName(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTableName)
	enum { IDD = IDD_TABLE_NAME_DLG };
	CString	m_DataSetTable;
	CString	m_TableName;
	CString	m_OutputTableName;
	CString	m_WorkloadTable;
	int		m_TopN; 
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTableName)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTableName)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TABLENAME_H__4E76CFCB_054C_4BB9_889E_22492615C74B__INCLUDED_)
