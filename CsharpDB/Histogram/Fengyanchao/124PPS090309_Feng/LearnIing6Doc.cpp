// LearnIing6Doc.cpp : implementation of the CLearnIing6Doc class
//

#include "stdafx.h"
#include "LearnIing6.h"

#include "LearnIing6Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLearnIing6Doc

IMPLEMENT_DYNCREATE(CLearnIing6Doc, CDocument)

BEGIN_MESSAGE_MAP(CLearnIing6Doc, CDocument)
	//{{AFX_MSG_MAP(CLearnIing6Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLearnIing6Doc construction/destruction

CLearnIing6Doc::CLearnIing6Doc()
{
	// TODO: add one-time construction code here

}

CLearnIing6Doc::~CLearnIing6Doc()
{
}

BOOL CLearnIing6Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CLearnIing6Doc serialization

void CLearnIing6Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CLearnIing6Doc diagnostics

#ifdef _DEBUG
void CLearnIing6Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLearnIing6Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLearnIing6Doc commands
