// LearnIing6View.h : interface of the CLearnIing6View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LEARNIING6VIEW_H__97EB174D_9EA5_4DE0_967A_07890B36321C__INCLUDED_)
#define AFX_LEARNIING6VIEW_H__97EB174D_9EA5_4DE0_967A_07890B36321C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CLearnIing6View : public CView
{
protected: // create from serialization only
	CLearnIing6View();
	DECLARE_DYNCREATE(CLearnIing6View)

// Attributes
public:
	CLearnIing6Doc* GetDocument();

// Operations
public:


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLearnIing6View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLearnIing6View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLearnIing6View)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in LearnIing6View.cpp
inline CLearnIing6Doc* CLearnIing6View::GetDocument()
   { return (CLearnIing6Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEARNIING6VIEW_H__97EB174D_9EA5_4DE0_967A_07890B36321C__INCLUDED_)
