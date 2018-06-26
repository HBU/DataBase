// LearnIing6Doc.h : interface of the CLearnIing6Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LEARNIING6DOC_H__0E549B4C_F818_4FE4_8E39_7CE7626198CD__INCLUDED_)
#define AFX_LEARNIING6DOC_H__0E549B4C_F818_4FE4_8E39_7CE7626198CD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CLearnIing6Doc : public CDocument
{
protected: // create from serialization only
	CLearnIing6Doc();
	DECLARE_DYNCREATE(CLearnIing6Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLearnIing6Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLearnIing6Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLearnIing6Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEARNIING6DOC_H__0E549B4C_F818_4FE4_8E39_7CE7626198CD__INCLUDED_)
