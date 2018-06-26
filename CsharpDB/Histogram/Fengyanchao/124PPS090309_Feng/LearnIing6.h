// LearnIing6.h : main header file for the LEARNIING6 application
//

#if !defined(AFX_LEARNIING6_H__A6AC88DA_DD34_4F03_9421_3BAEFCCC2FC5__INCLUDED_)
#define AFX_LEARNIING6_H__A6AC88DA_DD34_4F03_9421_3BAEFCCC2FC5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

#include "SQLEXT.H"
#include "math.h"
#include <fcntl.h>      /* Needed only for _O_RDWR definition */
#include <io.h>
#include <stdlib.h>
#include <stdio.h>

//#include "zlHeader.h"		//zl add

//#include  WINDEF.H
/////////////////////////////////////////////////////////////////////////////
// CLearnIing6App:
// See LearnIing6.cpp for the implementation of this class
//

//_______________ zl add start____

#define COL_NUM		     3//3 //4 //50 //25 //2 -- //3 //4 //25 //--//4 //104 //3 //2 //3 //4 //25 //50 //104 //2  	//zl for LSI SAME CASE
#define DIS_NUM           -1 //2 //-1 //2 //1 == L1; 2 == L2; -1 =Linf distances
#define WORKLOAD_NUM	2000 //400 //2000//1000//400    //... //100 //909  //100
#define MAX_SVR_MEM	    4 //4 //4 //8
#define THRESHOLD_KB   2000   //2000  //1261     //1310      //1410       //2000 
                              //<=4D  //25D      //50D       //104D       //2D 
#define TOP_N   100 //100 //20     

//#define THRESHOLD_KB          //2000  //1261     // 1310      //1410       //2000 
                                //<=4D  //25D      //50D       //104D         //2D 

extern	HENV    henv;
extern	HDBC    hdbc;
extern	HSTMT   hstmt;
extern	RETCODE retcode;

extern	UCHAR sz_DSN[20]; //= "DSN_MULTopN";
extern	UCHAR sz_UID[10]; //= "sa";
extern	UCHAR sz_PWD[10]; // = "123";

bool zlCloseDB();
bool zlOpenDB();

struct ZLRECT
{
	//[ai, bi], the interval in the ith axis
	//double * a; //a[i] means ai
	//double * b; //b[i] means bi

	double a[COL_NUM+1]; //a[i] means ai
	double b[COL_NUM+1]; //b[i] means bi


	double v;  // volume of the rectangle
	//int suffix[200]; //the suffix of intersection, such as (1,3,4,5)
	//char suffix[200]; //the suffix of intersection, such as (1,3,4,5)
					 //that is to say, this rectangle is the intersection of
					 //the rectangles S1^S3^S4^S5 
	//char suffix[2000];
	//char suffix[500];
	char suffix[1000];
	int suf1st;      // the first suffix that is 1 in (1,3,4,5)
	int sufend;      // the end suffix that is 5 in (1,3,4,5)
	int cn;          // class number or cluster number
	int bsn;         // bsn: Big Set Number, the number of a set that contain this set
	int tplNum;      // that is f,  the frequency of SCR , i.e., f = |SCR |,  the number of tuples in SCR;
};


struct TUPLE
{
	double	x[COL_NUM+1];	// the ith axis of tuple
	double	d;				// the distance  between this tuple and the query
	int		num;			// the number of this tuples in topN
	int     ID;				// the ID of the tuple
	bool	bIN;            // In the rectangle(S[i], or scr) or not
	//int     f;              // f  is the frequency of SCR , i.e., f = |SCR |,  the number of tuples in SCR;
	double  d_max;          // the L_inf distance  between this tuple and the query

};

struct RESULT_LEARNING
{
	double q[COL_NUM +1];
	int N;			//	int Not NULL,
	double r;		//float Not NULL,
	int f;			//int Not NULL,
	int	f_rst;
	int	shortTicks_rst;
	int shortTicks;	//int  NULL,
	int longTicks;	//int  NULL,
};

struct QUERY
{
	double	x[COL_NUM];	// the ith axis of Query
	int N;			//	int Not NULL,
	double r;		//the search distance obtained by learning,
	int f;			//the frequence onto search distance r
	//int c;			//int Not NULL,
	//int d;			//int Not NULL,
	int	f_rst;
	int shortTicks_rst;
	int longTicks;	//int  NULL,
	int shortTicks;	//int  NULL,
	//double dis_Q_Qp; //the distance from Q to Q', that is the max-distance, Qp mean Q'
	//double v;     // the Volume of the Square, /RGM - the geometric mean 
	//double density;   // the density of the profile
	
	//-----------
	int     ID;			// the ID of the Query
	double r_Opt;       // the search distance of Opt
	int   f_Opt;        // the frequence of Opt, onto  search distance r_Opt
	int ante_SizeKB;     // the size of KB befor the query OK, 
	int post_SizeKB;    // the size of KB After the query OK,
	int increment;      // increment for size of KB, is for case2b, and restart
	int case1;              //Fig2, Q=Qp
	int case2a;             //Fig3, Q is in the Z
	int case2b;				//Fig4. Q is not in the closest Z
	int adjust_case2a;      //whether or not adjust the case 2a, i.e Fig.3.
	int restart;            //whether or not restart
};

struct ProfileMP
{
	double x[COL_NUM]; //Q' = (x[0], x[1], ... x[COL_NUM-1])
	int N;			//	int Not NULL,
	double r;		//float Not NULL,
	int f;			//int Not NULL,
	int c;			//int Not NULL,
	int d;			//int Not NULL,
	int longTicks;	//int  NULL,
	int shortTicks;	//int  NULL,
	//--------
	double dis_Q_Qp; //the distance from Q to Q', that is the max-distance. 
                     // Qp mean Q'
	double v;     // the Volume of the Square, /RGM - the geometric mean 
	double density;   // the density of the profile
	int Sn;    //the number of n-Square, i.e. S[]; //2007.11.07
	int cn;    //the number of cluser              //2007.11.07
	int tid;   // the id of tuple                  //2009.2.14 zl
};


//ZLRECT ss[300]; // 300 > 2*k;  1<=k<=n
//_______________ zl add end ____



class CLearnIing6App : public CWinApp
{
public:

	ZLRECT				ss[300]; // 300 > 2*k;  1<=k<=n
	double				dMin[104+1]; 
	double				dMax[104+1]; 
    //RESULT_LEARNING		Q[WORKLOAD_NUM +1];
    RESULT_LEARNING	* Q;

	TUPLE * tpl; //search from scr_CLS
	TUPLE * t;   //in S[i];
	int tID[1000 +1];
	int Q_Num[WORKLOAD_NUM +1];
	//int * * t_Num;
    
	char				TableName[1024];
   	char				szInputTableName[1024];
   	char				szOutputTableName[1024];
    char	            m_WorkloadTable[512];
	int                 m_TopN;

	TUPLE * * tuple; //tuple[4][i]; the 4th ss , the ith tuples in ss[4]
					 

	TUPLE * * scr;   //scr[5][9] means the 5th scr , its 9 tuple
	
	// 2007.11.12
	double * Sum_v_T;  // the sum of vulumnd of all T[i]
	ZLRECT * scr_CLS;  // the SCR of each cluster 
    int clsNum; // the number of clusters
	int it_list_cnt; //the numuber of tuples in t_list
    int issNum;
	int iSum_SCR_TuplesCount;
    int iIO_Num;
	int case1;
   
	// 2007.11.12

	//--- tast
    int Qidx[WORKLOAD_NUM +1];
	int Qi;
    //--  test

  /*
	HENV    henv;
	HDBC    hdbc;
	HSTMT   hstmt;
	RETCODE retcode;

	UCHAR sz_DSN[20]; //= "DSN_MULTopN";
	UCHAR sz_UID[10]; //= "sa";
	UCHAR sz_PWD[10]; // = "123";
*/
	double Ratio_elapsed_time;//= Region Clustering Method/Naive Method
	double c2;  //the threshol of I, C, C+  clustering
	double CETA; //THE threshold of Sumcluster
	int m ; // the number of Top-N Queries, m=1,2,...,100
    bool bfirst; 
    STARTUPINFO info;  //for start -End SQL server
	PROCESS_INFORMATION pinfo; //for start -End SQL server

public:
	//LRC : 2007.11.11
	int zlExeSelectQ_r_LRC(QUERY Query, double r);
	int zlGetCandidateSet(QUERY Query, double r);
	int zlExeSelect_LRC(int PreTuplesNum,int PreScrNum, char *szSql, ZLRECT * scr_CLS, int CurScrNum); //2007.11.10
	int zlGet_S_ScrTuple_LRC( ZLRECT * scr_CLS, int CurScrNum);
	int zlGet_S_ScrTuple_LRC2( ZLRECT * scr_CLS, int CurScrNum, int l);
    int zlExeSelect_Mul_LRC(int PreTuplesNum, int PreScrNum, char *szSql, ZLRECT * scr_CLS, int CurScrNum);

	BOOL zlEndSQLservr();
	bool zlStartSQLservr();
	bool zlExeInsertTable(char *szSqlInsert);
	int zlother();
	int zlGet_S_Tuple(ZLRECT * S, int CurS_Num);
	int zlGetTopNTuple_S(int QueryNum, ZLRECT *S, int tuplesNum);
	int zlExeSelect_Mul_S(int PreTuplesNum, int PreS_Num, char *szSql, ZLRECT * S, int CurS_Num);
	int zlGetScrTuple( ZLRECT * scr_CLS, int CurScrNum);
    int zlExeSelect_High(int PreTuplesNum, int PreScrNum, char *szSql, ZLRECT * scr_CLS, int CurScrNum);	
    int zlGetTopNTuple_High(int QueryNum, ZLRECT *S, int tuplesNum);
	int zlExeSelect_Mul(int PreTuplesNum,int PreScrNum, char *szSql, ZLRECT * scr_CLS, int CurScrNum);
	int zlGetTopNTuple_Mul(int QueryNum, ZLRECT *S, int tuplesNum);
	int zlGetTopNTuple(int QueryNum, ZLRECT * S, int tuplesNum);
	//int zlExeSelect(char *TableName, char *szSql); 
	int zlExeSelect(int PreTuplesNum, char *szSql);
	int zlExeSelect2(int PreTuplesNum, char *szSql, int l);

	//bool zlCloseDB();
	//bool zlOpenDB();
	int c(int m, int i);
	double zlVolumeOfUnion(int iCountRt, int iDimension, ZLRECT *S);
	int zlClusterPart(ZLRECT * * T, int l,  ZLRECT * S, int m, int Current_clsNum, int dim_num, int PartNum, double xi);
	
	int zlClusterPartLsi(ZLRECT * * T, int l,  ZLRECT * S, int m, int Current_clsNum, int dim_num, int PartNum, double xi);
		int zlClusterPartLsi_InSe(ZLRECT * * T, int l,  ZLRECT * S, int m, int Current_clsNum, int dim_num, int PartNum, double xi);
	    int zlClusterPartLsi_Plus(ZLRECT * * T, int l,  ZLRECT * S, int m, int Current_clsNum, int dim_num, int PartNum, double xi);

		int zlPartion3D(ZLRECT * Rect, int Dimention, ZLRECT * T, int T_Num, int PartNum,int deepNum);

	int zlDiffRects(ZLRECT S, ZLRECT T, int Dimension );
	int zlPartion(ZLRECT Rect, int Dimention, ZLRECT * T, int T_Num, int PartNum);	
	int zlPartion_tt(ZLRECT Rect, int Dimention, ZLRECT * T, int T_Num, int PartNum);	

	
	CLearnIing6App();
    ~CLearnIing6App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLearnIing6App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CLearnIing6App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};



/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEARNIING6_H__A6AC88DA_DD34_4F03_9421_3BAEFCCC2FC5__INCLUDED_)
