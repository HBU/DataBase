// LearnIing6View.cpp : implementation of the CLearnIing6View class
//

#include "stdafx.h"
#include "LearnIing6.h"

#include "LearnIing6Doc.h"
#include "LearnIing6View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLearnIing6View

IMPLEMENT_DYNCREATE(CLearnIing6View, CView)

BEGIN_MESSAGE_MAP(CLearnIing6View, CView)
	//{{AFX_MSG_MAP(CLearnIing6View)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLearnIing6View construction/destruction

CLearnIing6View::CLearnIing6View()
{
	// TODO: add construction code here

}

CLearnIing6View::~CLearnIing6View()
{
}

BOOL CLearnIing6View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CLearnIing6View drawing

void CLearnIing6View::OnDraw(CDC* pDC)
{
	CLearnIing6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CLearnIing6View printing

BOOL CLearnIing6View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLearnIing6View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLearnIing6View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CLearnIing6View diagnostics

#ifdef _DEBUG
void CLearnIing6View::AssertValid() const
{
	CView::AssertValid();
}

void CLearnIing6View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLearnIing6Doc* CLearnIing6View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLearnIing6Doc)));
	return (CLearnIing6Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLearnIing6View message handlers


