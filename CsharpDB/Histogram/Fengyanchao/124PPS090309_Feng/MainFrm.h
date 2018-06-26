// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__31BB02A6_10C9_4454_B4F9_7FD22DADFCBA__INCLUDED_)
#define AFX_MAINFRM_H__31BB02A6_10C9_4454_B4F9_7FD22DADFCBA__INCLUDED_

#include "LearnIing6.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


///------------------- zl start ------------

//#define COL_NUM    104 //50  //25 //4 //3 //2 //3 //4 //2 //25 //50 //104 //3 //4 //25 //50 //104 //2 //3 //4 //2 //3 //4 //25 			//zl for LSI SAME CASE
//#define WORKLOAD_NUM	100 //909  //100


class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes

	//double fCells[20382][104];		// for 104 dim
	//double fCells[20382*104/50][50];    //for 50 dim
	double fCells[20382*104/25][25];    //for 25 dim
	double tuple[COL_NUM+1][2000];
	double topt[COL_NUM][2000];

	double dAll_Den_Median;				//density of dedian for all Profile
	int	   iAllMeadian;
	float *vecs_mem, **vecs, v;        // buffer for vectors

	int * pAge, * pAgeHold;		//new float[10]
	int * pIncome, * pIncomeHold;	//new float[10]
	int * pWPY, * pWPYHold;

public:

    ProfileMP * Z;          //zl 	
	QUERY * Q;

public:

	struct struct_Census2D_Tuple
	{
		int			Age;
		int			Income;
	};

	struct Profile2D
	{
		int q[2];
		int N;			//	int Not NULL,
		float r;		//float Not NULL,
		int f;			//int Not NULL,
		int c;			//int Not NULL,
		int d;			//int Not NULL,
		int longTicks;	//int  NULL,
		int shortTicks;	//int  NULL,
	};
	Profile2D * pPf;          //zl 
	Profile2D * pPfHold;      //zl

	struct Profile3D
	{
		int q[3];
		int N;			//	int Not NULL,
		float r;		//float Not NULL,
		int f;			//int Not NULL,
		int c;			//int Not NULL,
		int d;			//int Not NULL,
		int longTicks;	//int  NULL,
		int shortTicks;	//int  NULL,
	};
	Profile3D * pPf3D;          //zl 
	Profile3D * pPf3DHold;      //zl

	struct Profile4D
	{
		int q[4];
		int N;			//	int Not NULL,
		float r;		//float Not NULL,
		int f;			//int Not NULL,
		int c;			//int Not NULL,
		int d;			//int Not NULL,
		int longTicks;	//int  NULL,
		int shortTicks;	//int  NULL,
	};
	Profile4D * pPf4D;          //zl 
	Profile4D * pPf4DHold;      //zl

	struct Profile104D
	{
		double q[104];
		int N;			//	int Not NULL,
		double r;		//float Not NULL,
		int f;			//int Not NULL,
		int c;			//int Not NULL,
		int d;			//int Not NULL,
		int longTicks;	//int  NULL,
		int shortTicks;	//int  NULL,
	};
	Profile104D * pPf104D;          //zl 
	Profile104D * pPf104DHold;      //zl

//-------------


//struct RECTANGLE
struct RECTANGLE
{
	//[ai, bi], the interval in the ith axis
	double * a; //a[i] means ai
	double * b; //b[i] means bi

	double v;  // volume of the rectangle
	//int suffix[200]; //the suffix of intersection, such as (1,3,4,5)
	//char suffix[200]; //the suffix of intersection, such as (1,3,4,5)
					 //that is to say, this rectangle is the intersection of
					 //the rectangles S1^S3^S4^S5 
	char suffix[2000];
	int suf1st;      // the first suffix that is 1 in (1,3,4,5)
	int sufend;      // the end suffix that is 5 in (1,3,4,5)
	int cn;          //class number or cluster number
	int bsn; //  bsn: Big Set Number, the number of a set that contain this set
};

public:
	int iRowCnt_KBP;        // the row count of KB
	int iRowCnt_WordLoad;   // the row count of workload
	int iNumUpdateKB;
	int m_TopN;
	int iGetTopNTupleTime;
    bool bAddEP; // add EPSELON

	TUPLE * tpl; //search from Candidate Set
	TUPLE * t;   //TopN tuples
	ProfileMP Zprime;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	ZLRECT* CountCell(ZLRECT * T,int &PartNum,int m,int n);
	int LearningHD(int partNum,ZLRECT * T,int n,int m,ZLRECT * *pointcell);

	int zlGettheIntersection(ZLRECT *cell, QUERY   Q,int n);
	int zlExeSelect(QUERY Query);
	int zlSelectAllFromWorkload(char *WorkloadTableName);
	int zlExeSelectCount(QUERY Query, double r);
	bool zlInsertKBProfile(QUERY Qry);
	bool zlUpdate_c_KBProfile(ProfileMP Prf);	
	bool zlUpdateKBProfile(QUERY Qry);
	int zlGetTopNTuple(int QueryNum, int tuplesNum);
	double zlObtainSearchDistance(QUERY Query, int iQueryNum);
	int zlSelectAllFromKB(char * KBTableName);
	int zlClusterProfileRegions(int iCountOfQueries, char *DatasetTableName);
	bool zlClusterProfileRegions1(int iCountOfQueries, char *DatasetTableName);
	double CMainFrame::f(double x);
	//bool zlGetResults3To104D_before060309( int iCountOfQueries, char * InputTablename );
	bool zlGetResults3To104D( int iCountOfQueries, char * InputTablename );
	bool zlGetResults3To104D_C_N( int iCountOfQueries, char * InputTablename );
	bool zlGetResults3To104D_C_N_HighLarge( int iCountOfQueries, char * InputTablename );
	int c(int m, int i);
	double zlVolumeOfUnion(int iCountRt, int iDimension, ZLRECT *S);
	int zlClusterPart( ZLRECT ** T, int l,  ZLRECT * S, int m, int Current_clsNum, int dim_num);
	int zlExeSelect(char * TableName, char *szSql);
	void zlcode();
	bool zlOpenLsi_104Dim_File(char *filename);
	//bool zlCloseDB();
	//bool zlOpenDB();
		 
    void OnViewCluster100_old(); //buckup of OnViewCluster100
	void OnViewCluster100_BacK050413();
	
	HANDLE hReadFile;      //// Read File handle
	char ReadFileName[100]; //= "\\\\.\\D:\\users\\zhuliang\\DATA\\census-income.data"; //OK
	DWORD  dwBytesRead; //, dwBytesWritten, dwPos;

	CString m_DataSetTable;
	CString m_WorkloadTable;
	CString m_KBProfileTable;
	CString m_InsertTable;

/*
	HENV    henv;
	HDBC    hdbc;
	HSTMT   hstmt;
	RETCODE retcode;

	UCHAR sz_DSN[20]; //= "DSN_MULTopN";
	UCHAR sz_UID[10]; //= "sa";
	UCHAR sz_PWD[10]; // = "123";
*/
	bool zlCloseFileDB();
	bool zlOpenFileDB();
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnViewFileToDB();
	afx_msg void OnInsert();
	afx_msg void OnCovtypeInsert();
	afx_msg void OnDbgolumbiaInsert2d();
	afx_msg void On3dInsert();
	afx_msg void OnInsertCover4d();
	afx_msg void OnSelectAll();
	afx_msg void OnSelect2DWhere();
	afx_msg void OnGeneratProfile();
	afx_msg void OnGauss2d();
	afx_msg void OnGauss_3d();
	afx_msg void OnArray3d();
	afx_msg void OnCensus2dworkload();
	afx_msg void OnGauss2Dworkload();
	afx_msg void OnTop100census2dwl();
	afx_msg void OnViewTest();
	afx_msg void OnDataTop100Census2dWorkloadProfile();
	afx_msg void OnLearning_Census2D_Biased();
	afx_msg void OnInsertClmbCensus2D();
	afx_msg void OnClmbcensus3D();
	afx_msg void OnClmbCover4D();
	afx_msg void OnClmbGauss3D();
	afx_msg void OnClmbArray3D();
	afx_msg void OnClmbArray2D();
	afx_msg void OnArray2D32000smpl();
	afx_msg void OnCreateSmpl2000census2Dprofile();
	afx_msg void OnLearningTop100census2dbiasedfrom2000();
	afx_msg void OnLearningTop100Census2DBiasedFrom1000();
	afx_msg void OnLearningTop100census2DBiasedFrom0800();
	afx_msg void OnLearningTop100census2dbiasedfrom04000100();
	afx_msg void OnSmpl1459census2DProfileEuclSum();
	afx_msg void OnLearningTop100census2dBiasedfrm1459EuclSum();
	afx_msg void OnSmpl1459Census2DUniform();
	afx_msg void OnSmpl1654Census3D();
	afx_msg void OnSmpl1654census3DProfile();
	afx_msg void OnSmpl5810Cover4d();
	afx_msg void OnSmpl5810CoverProfile();
	afx_msg void OnSmpl5810cover4DProfile();
	afx_msg void OnSmpl5000Gauss3D_Array3D();
	afx_msg void OnSmpl5000Gauss3D_2160Array3DProfile();
	afx_msg void OnCensus2d_T0100_B_learning_P1459();
	afx_msg void On3DTop0100_B_LearningCensus3dGaussArray();
	afx_msg void On4Dcover_Learning();
	afx_msg void OnLsi_104D();
	afx_msg void OnHouse20D();
	afx_msg void OnLsi_smpl_Bworkload();
	afx_msg void OnLsiProfileOPTworkload();
	afx_msg void OnLsi104DLearning();
	afx_msg void OnViewCluster100();
	afx_msg void OnViewCluster2D100q();
	afx_msg void OnViewTestsmall();
	afx_msg void OnCensus2DWorkLoad();
	afx_msg void OnCensus2DResults();
	afx_msg void OnLsi104DBWorkLoad();
	afx_msg void OnResults3To4D();
	afx_msg void OnRun();
	afx_msg void OnClusterNaive();
	afx_msg void OnMenuLRC();
	afx_msg void OnMenuLRC_old(); 
	afx_msg void OnGeneraterCover4dworkload();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__31BB02A6_10C9_4454_B4F9_7FD22DADFCBA__INCLUDED_)
