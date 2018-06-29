// MainFrm.cpp : implementation of the CMainFrame class

#include "stdafx.h"
#include "LearnIing6.h"
#include "MainFrm.h"
#include "TableName.h"  //zl add 

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_VIEW_FILETODB, OnViewFileToDB)
	ON_COMMAND(ID_VIEW_INSERT, OnInsert)
	ON_COMMAND(ID_VIEW_COVTYPE, OnCovtypeInsert)
	ON_COMMAND(ID_DBGOLUMBIA_INSERT2D, OnDbgolumbiaInsert2d)
	ON_COMMAND(ID_3D_INSERT, On3dInsert)
	ON_COMMAND(ID_INSERT_COVER4D, OnInsertCover4d)
	ON_COMMAND(ID_SELECT_ALL, OnSelectAll)
	ON_COMMAND(ID_SELECT2D_WHERE, OnSelect2DWhere)
	ON_COMMAND(ID_GENERATER_GENERATPROFILE, OnGeneratProfile)
	ON_COMMAND(ID_GAUSS2D, OnGauss2d)
	ON_COMMAND(ID_GAUSS_3D, OnGauss_3d)
	ON_COMMAND(ID_ARRAY3D, OnArray3d)
	ON_COMMAND(ID_GENERATER_CENSUS2DWORKLOAD, OnCensus2dworkload)
	ON_COMMAND(ID_GAUSS2DWORKLOAD, OnGauss2Dworkload)
	ON_COMMAND(ID_TOP100CENSUS2DWL, OnTop100census2dwl)
	ON_COMMAND(ID_VIEW_TEST, OnViewTest)
	ON_COMMAND(ID_DATA_TOP100_CENSUS2D_WORKLOAD_PROFILE, OnDataTop100Census2dWorkloadProfile)
	ON_COMMAND(ID_LEARNING_CENSUS2DBIASED, OnLearning_Census2D_Biased)
	ON_COMMAND(ID_CLMBCENSUS2D, OnInsertClmbCensus2D)
	ON_COMMAND(ID_CLMBCENSUS3D, OnClmbcensus3D)
	ON_COMMAND(ID_CLMBCOVER4D, OnClmbCover4D)
	ON_COMMAND(ID_CLMBGAUSS3D, OnClmbGauss3D)
	ON_COMMAND(ID_CLMBARRAY3D, OnClmbArray3D)
	ON_COMMAND(ID_CLMBARRAY2D, OnClmbArray2D)
	ON_COMMAND(ID_ARRAY2D32000SMPL, OnArray2D32000smpl)
	ON_COMMAND(ID_SMPL2000CENSUS2DPROFILE, OnCreateSmpl2000census2Dprofile)
	ON_COMMAND(ID_LEARNING_TOP100CENSUS2DBIASEDFROM2000, OnLearningTop100census2dbiasedfrom2000)
	ON_COMMAND(ID_LEARNING_TOP100CENSUS2DBIASEDFROM1000, OnLearningTop100Census2DBiasedFrom1000)
	ON_COMMAND(ID_LEARNING_TOP100CENSUS2DBIASEDFROM0800, OnLearningTop100census2DBiasedFrom0800)
	ON_COMMAND(ID_LEARNING_TOP100CENSUS2DBIASEDFROM04000100, OnLearningTop100census2dbiasedfrom04000100)
	ON_COMMAND(ID_SMPL1459CENSUS2DPROFILEEUCLSUM, OnSmpl1459census2DProfileEuclSum)
	ON_COMMAND(ID_LEARNING_TOP100CENSUS2DBIASEDFRM1459EUCLSUM, OnLearningTop100census2dBiasedfrm1459EuclSum)
	ON_COMMAND(ID_SMPL1459CENSUS2DUNIFORM, OnSmpl1459Census2DUniform)
	ON_COMMAND(ID_SMPL1654CENSUS3D, OnSmpl1654Census3D)
	ON_COMMAND(ID_SMPL1654CENSUS3DPROFILE, OnSmpl1654census3DProfile)
	ON_COMMAND(ID_SMPL5810COVER4D, OnSmpl5810Cover4d)
	ON_COMMAND(ID_SMPL5810COVERPROFILE, OnSmpl5810cover4DProfile)
	ON_COMMAND(ID_SMPL5000GAUSS3DARRAY3D, OnSmpl5000Gauss3D_Array3D)
	ON_COMMAND(ID_SMPL5000GAUSS3DARRAY3DPROFILE3DISTANCE, OnSmpl5000Gauss3D_2160Array3DProfile)
	ON_COMMAND(ID_LEARNING_CENSUS2DT0100BLEARNINGP1459, OnCensus2d_T0100_B_learning_P1459)
	ON_COMMAND(ID_3DT0100_B_LEARNING_CENSUS3D_GAUSS_ARRAY, On3DTop0100_B_LearningCensus3dGaussArray)
	ON_COMMAND(ID_4DCOVER_LEARNING, On4Dcover_Learning)
	ON_COMMAND(ID_LSI104D, OnLsi_104D)
	ON_COMMAND(ID_HOUSE20D, OnHouse20D)
	ON_COMMAND(ID_GENERATOR_LSISMPLBWORKLOAD, OnLsi_smpl_Bworkload)
	ON_COMMAND(ID_LSIPROFILEOPTWORKLOAD, OnLsiProfileOPTworkload)
	ON_COMMAND(ID_LSI104DLEARNING, OnLsi104DLearning)
	ON_COMMAND(ID_VIEW_CLUSTER_100, OnViewCluster100)
	ON_COMMAND(ID_VIEW_CLUSTER2D100q, OnViewCluster2D100q)
	ON_COMMAND(ID_VIEW_TESTSMALL, OnViewTestsmall)
	ON_COMMAND(ID_CENSUS2DWORKLOAD, OnCensus2DWorkLoad)
	ON_COMMAND(ID_CENSUS2DRESULTS, OnCensus2DResults)
	ON_COMMAND(ID_LSI104DBWORKLOAD, OnLsi104DBWorkLoad)
	ON_COMMAND(ID_RESULTS3TO4D, OnResults3To4D)
	ON_COMMAND(ID_RUN, OnRun)
	ON_COMMAND(ID_CM_NM, OnClusterNaive)
	ON_COMMAND(ID_MENU_LRC, OnMenuLRC)
	ON_COMMAND(ID_GENERATER_COVER4DWORKLOAD, OnGeneraterCover4dworkload)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	//strcpy(ReadFileName, "\\\\.\\D:\\users\\zhuliang\\DATA\\census-income.data"); //OK
	//strcpy(ReadFileName, "\\\\.\\D:\\users\\zhuliang\\DATA\\adult.data"); //OK
	//strcpy(ReadFileName, "\\\\.\\D:\\users\\zhuliang\\DATA\\covtype"); //OK
	//strcpy(ReadFileName, "\\\\.\\D:\\users\\zhuliang\\DATA\\census2d.data");


	//strcpy((char *)sz_DSN , "DSN_QueryStream");
	//strcpy((char *)sz_UID , "sa");
	//strcpy((char *)sz_PWD , "123");

	m_strTitle = "???½çÃæ";

	//if(!zlOpenDB())
	//{
		//AfxMessageBox("zlOpenDB() err!");
		//zlCloseDB();
	//}

	Z = new ProfileMP[10000];
	Q =  new QUERY[10];
	tpl = new TUPLE [10]; 
	t = new TUPLE [10]; 
	bAddEP = false;

}

CMainFrame::~CMainFrame()
{
	    delete [] Z;
	    delete [] Q;
        delete [] t;
        delete [] tpl;

		//zlCloseDB();
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

////////////////////////////////////////////////////////////////////////
/////// For LRC


bool CMainFrame::zlUpdate_c_KBProfile(ProfileMP Prf)
{			       
	bool bReturn =false;

    char szCondition[1024] = "";
    char szc[1024] = "";
	CLearnIing6App * pApp = (CLearnIing6App * ) AfxGetApp();

///////////////

	sprintf_s(szc," c = %ld ", Prf.c);
	sprintf_s(szCondition," WHERE c = %ld AND d = %ld", Prf.c-1, Prf.d);

  /////////////
	CString cStrUpdate;
	cStrUpdate.Empty();
		
	cStrUpdate = " UPDATE ";
	cStrUpdate += m_KBProfileTable;
	cStrUpdate += " SET " ;						
	cStrUpdate += szc;						
	cStrUpdate += szCondition;						


	int istrSelectLenth = cStrUpdate.GetLength() + 1;

	bReturn = pApp->zlExeInsertTable(cStrUpdate.GetBuffer(istrSelectLenth) );			

///////////////

	if(!bReturn)
		AfxMessageBox("_c_, pApp->zlExeInsertTable ---- ERROR !!!!!");

	/////////// ---------- body end ---------------

	return bReturn;
}

double CMainFrame::zlObtainSearchDistance(QUERY Query, int iQueryNum)
{

	////////////for each query find the closed profiles
	//evaluate all distance from New_query Q to Profile Z 
	// dis[i] = d(Q,Q') = dmax(Q,Q') = max(|qi-q'i|)
	// MAX Distance is useful, others not; but pPf104D[i].r may be any distance. 
	int i, j, k;
	//double x[COL_NUM];
	double dSearchDis =0, rd = 0;   // the search distance of Q
    int iSizeProfile = iRowCnt_KBP;

	//double * dis = new double[iSizeProfile]; //dQQ
	//double * r = new double[iSizeProfile];   // sorting dis[i]

	//Q[iQueryNum].ante_SizeKB = iRowCnt_KBP;

	//1. compute all distancse from Q to all Z[i], i= 0,..., iSizeProfile-1
	        		
	long shortTicks = GetTickCount();

	for(i = 0; i<iSizeProfile; i++) // 
	{
		  //for(j = 0; j<COL_NUM; j++)
			//x[j] = fabs( Z[i].x[j] - Query.x[j] );
		  
		  //----for Max distance, only use this distace 
          Z[i].dis_Q_Qp = fabs( Z[i].x[0] - Query.x[0] );

		  for(j = 1; j<COL_NUM; j++)
			//Z[i].dis_Q_Qp = (double)__max(Z[i].dis_Q_Qp, x[j]);
			Z[i].dis_Q_Qp = (double)__max(Z[i].dis_Q_Qp, fabs( Z[i].x[j] - Query.x[j] ));

		  //dis[i] = Z[i].dis_Q_Qp;
	}

	//----- 2. Find out Q', denote Zp, that is the closest to Q, denote Query, 
	//     and Get RGM - the geometric mean

    int iNum_Zp =0; // the index of Z[i] that is closest to Q
	ProfileMP Zp ; // the Z[i] that is closest ot Q
	double rmin = Z[0].r; // the min r of Z[i].r
	double rmax = Z[0].r;  // the max r of Z[i].r
	double	rgm =0.0, RGM = 0.0; //RGM= 2*sqrt(rmin*rmax); //rgm : 2* r 

	Zp = Z[0];
	for(i = 1; i<iSizeProfile; i++) // 
	{
        if(Z[i].dis_Q_Qp<Zp.dis_Q_Qp)
		{
			Zp = Z[i];
			iNum_Zp = i;
		}
		//if(Z[i].r< rmin) 
			//rmin = Z[i].r;
		//if(Z[i].r > rmax)
			//rmax = Z[i].r;
	}

	//rgm = sqrt(rmin*rmax);
	//RGM= 2*rgm;
    
	//double VFactor =  5.0 * pow(10, 37);  
	int n;  //the dimension of dataset

	n = COL_NUM;
	
	if(n==104)
	  rgm = 5.0 * pow(10, 37);
	else if(n==50)
	  rgm = pow(10, 34); // (30 +38)/2=34
	else if(n==25)
	  rgm = pow(10, 31); // (24 +38)/2=31
	else
       rgm = 1;

	RGM= 2*rgm;


    Zprime = Zp; //be used to recompute the search distance

	//--------- 3. Get mean of ALL density, and median of ALL density 
    ////// mean of ALL density
	char cDblToStr[1024] = "";
    double rou=0; // the density p 
    ProfileMP * Ztmp = new ProfileMP[iSizeProfile+1];
    //ProfileMP Zt;


	for(j=0; j<iSizeProfile; j++)
	{					
		Z[j].v =1;
		for( k =0; k<COL_NUM; k++)
			Z[j].v *= (Z[j].r/rgm);	
		
		//for( k =0; k<1024; k++)
			//cDblToStr[k] = 0;

		//sprintf_s(cDblToStr,"%.13f",  Z[j].v);
		//sprintf_s(cDblToStr,"%.0f",  Z[j].v);
		//int ilen = strlen(cDblToStr);

		//if(strcmp(cDblToStr,"1.#INF000000000") == 0)
		//{
		 // ;	//AfxMessageBox( strcat(cDblToStr,"_ All density") );
		   ///---2006.10.18 add start 	
		   // rou += 0;
		//	Z[j].density = 0;
		//	Ztmp[j] = Z[j];
		   ///---2006.10.18 add end 	

		//}
		//else
		//{
			rou += Z[j].f/Z[j].v;
			Z[j].density = Z[j].f/Z[j].v;
			Ztmp[j] = Z[j];
		//}
	}
	rou = rou/iSizeProfile;	
	int iTopN = m_TopN; //20 //???
	double rd_AllMean = RGM*pow( 2*iTopN/rou, 1.0/COL_NUM )/2; //search distance by mean

	///---2006.10.18 add start 
//	if(strcmp(cDblToStr,"1.#INF000000000") == 0)
//	{
//       rd_AllMean=0.0;
//	   for(j=0; j<iSizeProfile; j++)
//	   {
//		   rd_AllMean += Z[j].r;
//	   }
//	   	rd_AllMean = rd_AllMean/iSizeProfile;	
		//AfxMessageBox( strcat(cDblToStr,"_ All density") );
//	}
	///---2006.10.18 add end 


	///// median of ALL density 
/* 2007.01.22
	for(j=0; j<iSizeProfile; j++)
	{
		for(k = j+1; k <iSizeProfile; k++)
		{
			if(Ztmp[k].density < Ztmp[j].density)
			{
                Zt = Ztmp[j]; Ztmp[j] =Ztmp[k]; Ztmp[k] = Zt; 
			}
		}
	}
2007.01.22 */				
	iAllMeadian = iSizeProfile/2;				
	dAll_Den_Median = Ztmp[iAllMeadian].density;
	//double rd_ADM = pow(2.0*iTopN/Ztmp[iAllMeadian].f , 1.0/COL_NUM)*Ztmp[iAllMeadian].r;
	double rd_ADM = pow(2*iTopN/Ztmp[iAllMeadian].f , 1/COL_NUM)*Ztmp[iAllMeadian].r;
		   //rd_ADM = pow(2*iTopN/freAMD[iAllMeadian] , 1/COL_NUM)*rAMD[iAllMeadian];



    //----------To computer search distance r
	if(Zp.dis_Q_Qp == 0) // if Q=Q'; case of Fig.2
	{
		dSearchDis = Zp.r;
		Q[iQueryNum].r = Zp.r;
		Q[iQueryNum].case1 = 1;
		Z[iNum_Zp].c ++;
		//UPDATE table profile
		if(!zlUpdate_c_KBProfile(Z[iNum_Zp]))
		   AfxMessageBox( "zlUpdate_c_KBProfile(Z[iNum_Zp])) ERROR " );

	}
	else
	{
		int iKnum = 0; // the size of the set {Z[j]; that contains Q}
		ProfileMP * Z_ctn_Q = new ProfileMP[iSizeProfile]; // Z_ctn_Q[i] contains Q
		double PowDisQQp =1.0 ; //denominator; //·ÖÄ¸dinf(Q,Qi)^^a 
		//double * w;
		double Sum_w =0.0, Sum_wp = 0.0; 

		int iMeadian = iKnum/2;
		rou = 0;
	
		if(Zp.dis_Q_Qp <= Zp.r) // case of Fig.3 
		{
			Q[iQueryNum].case2a = 1;

			// Find all Z that contains Q 
			iKnum =0;
			for(j=0; j<iSizeProfile; j++) 
			{

			  if(Z[j].dis_Q_Qp<= Z[j].r)
			  {
				Z_ctn_Q[iKnum] = Z[j];
				iKnum++;
			  }
			}

		}
		else  ////case of Fig.4  
		{   
			Q[iQueryNum].case2b = 1;

			// let h=Zp.r + Zp.dis_Q_Qp;
			//Find out all {Z1, ..., Zk} in KB that intersect S(Q,h)
            iKnum = 0;
			for(j=0; j<iSizeProfile; j++) 
			{

			  if(Z[j].dis_Q_Qp < Zp.r + Zp.dis_Q_Qp) //	if(r[j] < rOrder[0] + r[0]) 
			  {
				Z_ctn_Q[iKnum] = Z[j];
				iKnum++;
			  }
			}

		}
  

		//--- Get w[j];
		//w = new double[iKnum];		                
        Sum_wp =0.0; Sum_w =0.0;
		for(j=0; j<iKnum; j++) 
		{
          PowDisQQp = 1;
		  for(k =0; k<(COL_NUM*3/4); k++)
			PowDisQQp *= (RGM/Z_ctn_Q[j].dis_Q_Qp); //l[j]

		  //w[j] = Z_ctn_Q[j].v * PowDisQQp;

		  //Sum_wp += w[j]*Z_ctn_Q[j].density;
		  Sum_wp += PowDisQQp*Z_ctn_Q[j].f; // lVrou += l[j]* fpf[j];
		  //Sum_w += w[j];   //	lV += l[j]*V[j];
		  Sum_w += (Z_ctn_Q[j].v * PowDisQQp);   //	lV += l[j]*V[j];

		}
        //Get density
		rou = Sum_wp/Sum_w;  //lVrou/lV; 
		//delete [] w;

        //------------  Get search distance -----------------
		if( rou > 0 )
		{
			rd = RGM*pow( 2*iTopN/rou, 1.0/COL_NUM )/2; 
			if (iTopN != Zp.N )
			{
				rd = rd*pow(iTopN/Zp.N, 1.0/COL_NUM);							
			}
		}
		else
		{
			rd = rd_ADM;
		}

		//In the Case of Fig.3 and 4, adjustment r the search distance
		// In fact we only adjustment in Fig.4
		// rOrder[0] means Zp.r; r[0] means Zp.dis_Q_Qp ; pPf104D[0] means Zp
		// {r[j], j=0; j<iSizeProfile} are sorting of dis[i] =  d(Q,Q'), to identify the closest Q' to Q
        // r[j] means Ztemp
        /////////////////////////////
		double rOrder[1], r[1];
        rOrder[0] = Zp.r; r[0] = Zp.dis_Q_Qp;
		int adjust_case2a = 0;      
        // --- only for Fig.4 in old program  start -----
	if(	Q[iQueryNum].case2b == 1)
	{
		if (iTopN == Zp.N ) 
		{					
			if ( (rd < Zp.r) ||(rd < r[0]))  //r[0] = dmaxQQp;
			{
				rd = __max ( __max(rd_ADM,rd_AllMean) , rd);
				rd =  rd/2.0 + (r[0] + Zp.r)/2.0;
				adjust_case2a = 1;
			}

			if (rd > r[0] + rOrder[0])
			{
				rd = r[0] + rOrder[0];
				adjust_case2a = 2;
			}
		}
		else				
		{
			if ( (rd < rOrder[0])*pow(iTopN/Zp.N, 1.0/COL_NUM) ||(rd < r[0]))  //r[0] = dmaxQQp;
			{
				rd = __max ( __max(rd_ADM,rd_AllMean) , rd);
				rd =  rd/2.0 + (r[0] + rOrder[0]*pow(iTopN/Zp.N, 1.0/COL_NUM) )/2.0;							
				adjust_case2a = 3;
			}

			if (rd > r[0] + rOrder[0]*pow(iTopN/Zp.N, 1.0/COL_NUM))
			{
				rd = r[0] + rOrder[0]*pow(iTopN/Zp.N, 1.0/COL_NUM);
				adjust_case2a = 4;
			}

		}//if (iTopN == pPf104D[0].N )  //pPf104D[0] means Zp
	}
    // --- only for Fig.4 in old program  End  -----

   /////////////////

        dSearchDis = rd;
		Q[iQueryNum].r = rd;;
		Q[iQueryNum].adjust_case2a = adjust_case2a;

		delete [] Z_ctn_Q;
	}

    delete [] Ztmp;
   //-------- body end ------

	//-- test 
	
	//shortTicks = GetTickCount() - shortTicks;
	//char temp[200];
	//sprintf_s(temp, " get distance, Ticks = %i ",  shortTicks);
	//AfxMessageBox(temp);
	//-- test 


    return dSearchDis;
}

int CMainFrame::zlGetTopNTuple(int QueryNum, int tuplesNum)
{
    
	iGetTopNTupleTime = GetTickCount();
	int iCandidateNum  = -1;
	int iFrequence_Opt = -1;

	CLearnIing6App * pApp = (CLearnIing6App * ) AfxGetApp();

///////////////// Get TopN tuples Start //////////////

	//1. Obtain all distance From Query to tuples
    //#define DIS_NUM   2 //-1 //2 //-1 //2 ////: 1 == L1; 2 == L2; -1 =Linf

	int iRowCnt = tuplesNum;
	double x[COL_NUM +1];
	
	int iTopN = m_TopN; //Q[QueryNum].N ;

    int iDimension = COL_NUM;

	//double r[2000];
	//double dis[2000];
	double r[100+1];     //
	double dis[100+1];

	double ftmp =0 ;
	int tIndex[100+1]; //or 2000

	//int tID[101];
	//int tnum[101];

	int iNumTmp;
	int i,j,k, ii, jj, kk;
	//long lStartTimer = GetTickCount();
	//long lEndTimer;

	delete [] t;
	t = new TUPLE[iRowCnt];

	//lStartTimer = GetTickCount();
    //pApp->tpl[i] is based 1,  but CMainFrame->tpl[i] is based 0
/*
	for(i = 0; i<iRowCnt; i++)
	{
		for(j = 0; j<COL_NUM; j++)
            t[i]. x[j] = pApp->tpl[i+1].x[j+1];

	    t[i].d = pApp->tpl[i+1].d;
	    t[i].num = pApp->tpl[i+1].num;
	    t[i].ID = pApp->tpl[i+1].ID;
	    t[i].bIN = pApp->tpl[i+1].bIN;
	    //t[i].f = pApp->tpl[i+1].f;
	    t[i].d_max = pApp->tpl[i+1].d_max;
		
		t[i].num = i;
	}
*/

	for(i = 0; i<iRowCnt; i++)
	{
		t[i] = tpl[i];
		t[i].num = i;
	}

	//lEndTimer = GetTickCount()-lStartTimer;
	CString str = "";
	char temp[512] ="";

	//sprintf_s(temp, "1. QueryNum = %i; iCandidateNum = %i; Ticks = %i; ", QueryNum, iRowCnt, lEndTimer);
	//str += temp;
	//str += "\r\n";
   //if(tuplesNum>3000)
	//AfxMessageBox(temp);	

	iCandidateNum = tuplesNum;
	//In this function: iRowCnt >= iTopN;
	/*
	if(iCandidateNum < iTopN)
	{
		str += "zlGetTopNTuple: iCandidateNum < iTopN ";
		str += "\r\n";
		//sprintf_s(temp, "1. QueryNum = %i; iCandidateNum = %i; Ticks = %i; ", QueryNum, tuplesNum, lEndTimer);
		str += temp;
		str += "\r\n";

		//AfxMessageBox(temp);	
		return iCandidateNum; 
		//Q[QueryNum].r := __max( distance from Q[QueryNum] to 
		 // tpl[1],..., tpl[iTopN]) caller will do this work.
	}
	*/
	//calculate the distance from Q[QueryNum] to t[j], save it in t[j].d
	for(k = 0; k<iCandidateNum; k++)
	{
		for(j = 0; j<COL_NUM; j++)
			x[j] = fabs( t[k].x[j] - Q[QueryNum].x[j] );

		switch (DIS_NUM)
		{
			case 1:
			{
				//---for Sum distance, L1
				t[k].d = x[0];
		 		for(j = 1; j<COL_NUM; j++)
					t[k].d += x[j];
				break;
			}
			case 2:
			{
				//----for Eucl distance, L2
				t[k].d = x[0]*x[0];
		 		for(j = 1; j<COL_NUM; j++)
					t[k].d += x[j]*x[j];
				t[k].d = sqrt( t[k].d );

				break;
			}
			case -1:
			{
				//----for Max distance, Linf
				t[k].d = x[0];
				for(j = 1; j<COL_NUM; j++)
					t[k].d = (double)__max(t[k].d, x[j]);				
				break;
			}//switch (DIS_NUM)
		} 
        
		if(iDimension >=25)
		{
			t[k].d_max = x[0];
			for(j = 1; j<COL_NUM; j++)
				t[k].d_max = (double)__max(t[k].d_max, x[j]);
		}
		else
          t[k].d_max = t[k].d;
	}//for(k = 1; k<=iRowCnt; k++)

		//iTopN = Q[i].N;

	//sorting the distance of the FIRST iTopN tuples
	// saved in r[j];

	for(j=0; j<iTopN; j++)
	{
		dis[j]=t[j].d;
	}

	for(j=0; j<iTopN; j++)
	{
		r[j] = dis[j];

		   for( k= j+1; k<iTopN; k++)
			{
				if(dis[k] < r[j]) 
				{ 
					ftmp = r[j];    r[j] = dis[k];  dis[k] = ftmp;
					iNumTmp = t[j].num; t[j].num = t[k].num;  t[k].num =iNumTmp; 
					//tIndex[j]=k;		
				}
			}
		tIndex[j] = t[j].num;
	}
		
		//-----debug1----   
       /*

		for(j=0; j<iTopN; j++)
		{
			dis[j] = t[t[j].num].d;  //t[tIndex[j]].d;
			tID[j] = t[tIndex[j]].ID;
		    tnum[j] = t[j].num;
		}

		int debug1 =1;
        */
//////////////		
/*	tnum	0x0012cc34
	[0]	11       //t[0].11, t[11] sit 0
	[1]	18       //t[1].18, t[18] sit 1
	[2]	17
	[3]	16
	[4]	15
	[5]	8
	[6]	9
	[7]	10
	[8]	19
	[9]	1
	[10]	0
	[11]	2
	[12]	3
	[13]	14
	[14]	13
	[15]	12
	[16]	6
	[17]	7
	[18]	5
	[19]	4
	*/
//////////////
		//-----debug1----

////////////
	//2. select TopN tuples from all tuples with size iCandidateNum
			
	//lStartTimer = GetTickCount(); //2005.05.13
      
	for(ii = iTopN ; ii<iCandidateNum; ii++)
	{
		if(t[ii].d < r[iTopN -1])		
		{
			for(jj=0;jj<iTopN;jj++)
			{
				if( t[ii].d < r[jj]) // t[ii] insert the jj seat
				{
					
					iNumTmp = t[iTopN-1].num;

					for(kk = iTopN-1 ; kk>jj; kk--)
					{
						r[kk] = r[kk-1];

						t[kk].num = t[kk-1].num;
					}
					r[jj]= t[ii].d;

					t[jj].num = t[ii].num;
					t[ii].num = iNumTmp;
					break;
				}
			}
		}
	}

	//-----debug12----
   /* 
	for(j=0; j<iTopN; j++)
	{
		dis[j] = t[t[j].num].d;  //t[tIndex[j]].d;
		tID[j] = t[t[j].num].ID; //t[t[j].num].ID is the topN tuples ID;
		tnum[j] = t[j].num;      //t[j].num means the number num tuple sit jth seat
		                         //i.e.,NO. num tuple is the top j tuples
	}
   */
		 //debug1 =12;
	 
	//-----debug1----


   //--------- Get the r_Opt and the Frequence_Opt
   	double r_Opt = 0; 
	
	for(j = 0; j<iTopN; j++)
	{
		r_Opt =  (double)__max(t[t[j].num].d_max, r_Opt);
	}

	Q[QueryNum].r_Opt = r_Opt;

iGetTopNTupleTime = GetTickCount()- iGetTopNTupleTime;

    iFrequence_Opt =  zlExeSelectCount(Q[QueryNum], r_Opt);

	if(bAddEP || iFrequence_Opt<m_TopN )
	{
		//AfxMessageBox(" bAddEP || iFrequence_Opt<m_TopN ");	

		bAddEP = false;
		double EPCINO = 0.000000000000001; //15_0
		              //5.0249400000000001E+37

		char cDblToStr[1024] = "";
		sprintf_s(cDblToStr,"%.0f",  r_Opt);

		int ilen = strlen(cDblToStr);
		r_Opt = r_Opt + EPCINO* pow(10, (ilen-1) );
		Q[QueryNum].r_Opt = r_Opt;
		iFrequence_Opt =  zlExeSelectCount(Q[QueryNum], r_Opt);
		//if(iFrequence_Opt < m_TopN)
		    //AfxMessageBox("iFrequence_Opt < m_TopN 222 ");	
    }


///////////////// Get TopN tuples End //////////////
	
	
	//----- body-----------------
	return iFrequence_Opt;
}

int CMainFrame::zlExeSelectCount(QUERY Query, double r)
{

	int iRowCnt = -1;
	char temp[512] ="";
    int j = 0;
	
	//if(!zlOpenDB())
	{
		//AfxMessageBox("zlOpenDB() err!");
		//zlCloseDB();
	}

	char * szSql = new char[8092000];
	strcpy(szSql, "");

    	strcpy(	szSql, 	" SELECT * FROM ");
		strcat(	szSql, 	m_DataSetTable );
		strcat(	szSql, 	" where ( ( ");
			
			for(j=0; j<COL_NUM-1; j++)
			{
				sprintf_s(temp, " %.15G <= attr%d AND attr%d <= %.15G ", Query.x[j]-r,j,j, Query.x[j]+r);
				strcat(	szSql, temp	);
				strcat(	szSql, ") AND (" );
			}

			sprintf_s(temp, " %.15G <= attr%d AND attr%d <= %.15G ", Query.x[COL_NUM-1]-r,COL_NUM-1,COL_NUM-1, Query.x[COL_NUM-1]+r);
			strcat(	szSql, temp	);

		strcat(	szSql, ") ) "	);

	/////////////////////////////////////////////////////
	SQLFreeStmt(hstmt, SQL_DROP);
	retcode = SQLAllocStmt(hdbc, &hstmt); ///Statement handle 
	if(retcode != SQL_SUCCESS)
		return -1;

	SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
	SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);

	retcode = SQLExecDirect(hstmt, (unsigned char *)szSql, SQL_NTS);  //2005.02.07

	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
	{  //	retcode = SQLExecDirect
		
		SDWORD *  RowCountPtr = new SDWORD ;
		retcode = SQLRowCount(hstmt, RowCountPtr);						 
		iRowCnt = * RowCountPtr;
		delete RowCountPtr;
	}

	delete [] szSql;
	//zlCloseDB();
	//----- body  end -----------------
	return iRowCnt;
}

int CMainFrame::zlSelectAllFromWorkload(char *WorkloadTableName)
{
	//if(!zlOpenDB())
	{
	//	AfxMessageBox("zlOpenDB() err!");
	//	zlCloseDB();
	}
   
	int iRowCnt = -1;
    int iTupleNum;

	double  fCol[COL_NUM+1];		//Elevation
	SDWORD cbCol[COL_NUM+1]; 	
	SDWORD sColID =0; 
	SDWORD cbColID =0; 
	int iQryIdx = 0;
	char tmp[512];
	int i;

	int		sN,  sf,  sf_rst,  sshortTicks_rst,  sshortTicks,  slongTicks;
	SDWORD  cbN, cbf, cbf_rst, cbshortTicks_rst, cbshortTicks, cblongTicks;
	double	sr;	
	SDWORD  cbr;
	sf_rst = 0;  sshortTicks_rst=0;


	/////////////////////////////////////////////////////
	SQLFreeStmt(hstmt, SQL_DROP);
	retcode = SQLAllocStmt(hdbc, &hstmt); ///Statement handle 
	if(retcode != SQL_SUCCESS)
		return -1;

	SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
	SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
	
	char szLocalSql[2048] = ""; 
	strcpy(szLocalSql, "SELECT * FROM ");	
	strcat(szLocalSql, WorkloadTableName);	


	retcode = SQLExecDirect(hstmt, (unsigned char *)szLocalSql, SQL_NTS);  //2005.02.07
	//retcode = SQLExecDirect(hstmt, (unsigned char *)szSql, SQL_NTS);  //2005.02.07		
	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
	{  //	retcode = SQLExecDirect
	
		int iRowCount;
		SDWORD *  RowCountPtr = new SDWORD ;
		retcode = SQLRowCount(hstmt, RowCountPtr);						 
		iRowCount = * RowCountPtr;
		delete RowCountPtr;
		iRowCnt = iRowCount;
		iTupleNum = iRowCount;
        iRowCnt_WordLoad = iRowCount;

		if(iRowCnt <=0)
			return iRowCnt;

		delete [] Q;
		Q = new QUERY[iRowCount+1];

//==================
		for( i = 0; i <COL_NUM+1; i++)
		{
			fCol[i] =0.0;
			cbCol[i] = 0; 
		}
		// Bind columns 1,2,3,4 ,.., 105
			for(i = 0; i <COL_NUM; i++)
					SQLBindCol(hstmt, i+1, SQL_C_DOUBLE, &fCol[i],0, &cbCol[i]); //SQL_C_SSHORT			
			//2007.12.5 -- SQLBindCol(hstmt, COL_NUM+1, SQL_C_SLONG, &sColID,0, &cbColID); //SQL_C_SSHORT
			//2007.12.5 --		
			SQLBindCol(hstmt, COL_NUM+1, SQL_C_SLONG, &sN,0, &cbN); //SQL_C_SSHORT
			SQLBindCol(hstmt, COL_NUM+2, SQL_C_DOUBLE, &sr,0, &cbr); //SQL_C_SSHORT
			SQLBindCol(hstmt, COL_NUM+3, SQL_C_SLONG, &sf,0, &cbf); //SQL_C_SSHORT

			SQLBindCol(hstmt, COL_NUM+4, SQL_C_SLONG, &sf_rst,0, &cbf_rst); //SQL_C_SSHORT
			SQLBindCol(hstmt, COL_NUM+5, SQL_C_SLONG, &sshortTicks_rst,0, &cbshortTicks_rst); //SQL_C_SSHORT
			SQLBindCol(hstmt, COL_NUM+6, SQL_C_SLONG, &sshortTicks,0, &cbshortTicks); //SQL_C_SSHORT
			SQLBindCol(hstmt, COL_NUM+7, SQL_C_SLONG, &slongTicks,0, &cblongTicks); //SQL_C_SSHORT
            //2007.12.5 --
		while (TRUE) 
		{
			retcode = SQLFetch(hstmt);

			if (retcode == SQL_ERROR)
			{
				//show_error();
				wsprintf(tmp, "%ld", iRowCount);
				//int i = iRowCount;
				AfxMessageBox("SQLFetch Error !!!!!!");
						//break; //99.8.26
			}

			if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
			{
				
				for(i = 0; i<COL_NUM; i++)
				{
					Q[iQryIdx].x[i] = fCol[i];   //iQryIdx is based 0
				}
				
				/** //2007.12.5
				//2007.12.5 --Q[iQryIdx].ID		= sColID;
				Q[iQryIdx].N        = m_TopN;
////////////
				Q[iQryIdx].r =0;
				Q[iQryIdx].f =0;
				Q[iQryIdx].f_rst=0 ;
				Q[iQryIdx].shortTicks_rst=0;
				Q[iQryIdx].shortTicks=0;
				Q[iQryIdx].longTicks=0;
                //2007.12.5 **/
				Q[iQryIdx].N		= sN;
				Q[iQryIdx].r		= (float) sr;
				Q[iQryIdx].f		= sf;
				Q[iQryIdx].f_rst	= sf_rst;
				Q[iQryIdx].shortTicks_rst = sshortTicks_rst;
				Q[iQryIdx].longTicks = slongTicks;	 
				Q[iQryIdx].shortTicks = sshortTicks; 

				Q[iQryIdx].ID=0;
				Q[iQryIdx].r_Opt=0;
				Q[iQryIdx].f_Opt=0;
				Q[iQryIdx].ante_SizeKB=0;
				Q[iQryIdx].post_SizeKB=0;
				Q[iQryIdx].increment=0;
				Q[iQryIdx].case1=0;
				Q[iQryIdx].case2a=0;
				Q[iQryIdx].case2b=0;
				Q[iQryIdx].adjust_case2a=0;
				Q[iQryIdx].restart=0;

/////////////

				iQryIdx++;

				if(retcode == SQL_SUCCESS_WITH_INFO)
				{
					wsprintf(tmp, "%ld", retcode);
					AfxMessageBox(tmp);
				}
					
			} 
			else 
			{
				break;
			}

		}   ///while (TRUE)
//================
	}
	//zlCloseDB();
	//----- body-----------------
	return iRowCnt;
}

///////////////////////////////////////////////////////////////////
/////////////////////For LRC end //////////////////////////////////

void CMainFrame::OnViewFileToDB() 
{
	
	//AfxMessageBox("This is OnViewFileToDB!");
	char buffer[800] = "";
	//char buffer[81920] = "";
	CString CStrBuff = "";
	CString CStrBuffMeg = "";
	CString CStrInsert = ""; 
	char	cTmp[100] = "";
	char	cTmp1[100] = "";
	char	cTmp2[10000] = "";
	char	cAttribute[15][50]= { "","","","","","","","","","","","","","",""};
	//CString cAttribute[15];
	
	int i,j,istart = 0;
	int iBreadCount = 0, itest, iErr =0 ;
	int iTuplesNum = 0;

	
	//---------  create Read File start --------
	//SQLFreeStmt(hstmt, SQL_DROP);
	//zlCloseFileDB();

	//strcpy(ReadFileName, "\\\\.\\D:\\users\\zhuliang\\DATA\\adult.data"); //OK
	strcpy(ReadFileName, "\\\\.\\D:\\users\\zhuliang\\DATA\\Dataset.data"); //OK

	if(!zlOpenFileDB())
	{
		AfxMessageBox("zlOpenFileDB() err!");
		zlCloseFileDB();
	}else
	{// read file  and convert it to database 
	
		//++++++ to do start +++++++++++++
		do 
		{
			if (ReadFile(hReadFile, buffer, 800,//80000, 
					&dwBytesRead, NULL)) 
			{ 
				CStrBuff += buffer;
				int iLen = CStrBuff.GetLength();

			  for(i=0; i < iLen; i++)
			  {
				  if(CStrBuff[i]==10)
					  iTuplesNum++;
			  }

			  iBreadCount = 0;
			  while ( iBreadCount<iTuplesNum ) 
			  {
					

				for (i = 0; i < 15; i++)
				{// for i
					
					int k= 0;
					for (k = 0; k<50; k++)
					    cAttribute[i][k] =0;

					k= 0;

					for(j = istart; j < iLen; j++)
					{ //for j

						if( (CStrBuff[j] == ',') || CStrBuff[j] == 10 )
						{
							if(CStrBuff[j] == 10)
							{
								iBreadCount ++;
							}

							break;
							
						}else
						{
							cAttribute[i][k] = CStrBuff[j];

						}

						k++;
 
					}//for j
				
					istart = j+1;

				} //for i


				for (i = 0; i < 15; i++)
				{
					//if( strcmp(cAttribute[i], "")==0)
					//{
					//	sprintf(cTmp,"J = %d",j);
					//	AfxMessageBox(cTmp);
					//}
					
					
					strcpy(cTmp, (char *)&(cAttribute[i]));
					CStrBuffMeg += cTmp;
					//AfxMessageBox(cTmp);

					strcpy(cTmp ,"");

				}//
				//itest = CStrBuffMeg.GetLength();

				//AfxMessageBox("insert");

				//CStrInsert += " INSERT Adult VALUES( ";	
				CStrInsert += " INSERT Adult1 VALUES( ";	
	    
				CStrInsert += cAttribute[0];
				CStrInsert += ", '";
				CStrInsert += cAttribute[1];
				CStrInsert += "',";

		
				CStrInsert += cAttribute[2];
				CStrInsert += ",'";

				CStrInsert += cAttribute[3];
				CStrInsert += "',";
				CStrInsert += cAttribute[4];
				CStrInsert += ",'";
				CStrInsert += cAttribute[5];
				CStrInsert += "','";

				CStrInsert += cAttribute[6];
				CStrInsert += "','";
				CStrInsert += cAttribute[7];
				CStrInsert += "','";
				CStrInsert += cAttribute[8];
				CStrInsert += "','";
				CStrInsert += cAttribute[9];
				CStrInsert +=  "',";
				CStrInsert += cAttribute[10];
				CStrInsert += ",";
				CStrInsert += cAttribute[11];
				CStrInsert += ",";
				CStrInsert += cAttribute[12];
				CStrInsert +=  ",'";
				CStrInsert += cAttribute[13];
				CStrInsert += "','";
				CStrInsert += cAttribute[14];
				CStrInsert += "')";

			    int iSqlLen = CStrInsert.GetLength();

				char * szSqlInsert = new char [iSqlLen + 1];
				strcpy(szSqlInsert , "");
				strcat(szSqlInsert , CStrInsert);

			//	int iResponse = AfxMessageBox(szSqlInsert, MB_OKCANCEL,0 );

			//	if (iResponse == IDOK)
				{	
					
					//char szSmpl0[] = " INSERT Adult VALUES(222,'BBB', 33333,'SS',11,'FFF','FFGG','HHH','JJJ','KK',22,33,44,'III','EEE')"; //Adult
					//retcode = SQLExecDirect(hstmt, (unsigned char *)szSmpl0, SQL_NTS);

					retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlInsert, SQL_NTS);



					if (retcode == SQL_SUCCESS) 
					{  //	retcode = SQLExecDirect
						//AfxMessageBox("Insert new Recode Seccess!");
						//bReturn = TRUE;
					}
					else
					{
					//	AfxMessageBox("Insert new Recode Error!");
						iErr++;
						itest = 1;

					} //	retcode = SQLExecDirect 
				}

					CStrInsert = "";
					delete [] szSqlInsert; 

			}//while ( iBreadCount<iTuplesNum ) 



			CStrBuff = CStrBuff.Right(iLen - j-1);
			j=0;
			istart =0;
			iTuplesNum =0;

			
			//Sleep(100);
			} //if (ReadFile(hReadFile, buffer, 5000, 


		} while (dwBytesRead >0); 

		//++++++++++ to do end +++++++++

	}// read file  and convert it to database 

	sprintf_s(cTmp,"Err Num = %d", iErr);
    AfxMessageBox(cTmp);
	AfxMessageBox("Insert new Recode OK!!!!!!!!!!!!!!!!!!!");

	SQLFreeStmt(hstmt, SQL_DROP);

	zlCloseFileDB();

}

bool CMainFrame::zlOpenFileDB()
{
    bool bReturn;

		//1---------  create Read File start --------
	hReadFile = 0;
	if( hReadFile != 0 )
         CloseHandle(hReadFile);
	Sleep(30);

		hReadFile = CreateFile(ReadFileName,//ReadFileName,  // filename  
					GENERIC_READ | GENERIC_WRITE, // open for read-write 
					0,                            // do not share 
					NULL,                         // no security 
					OPEN_EXISTING,//CREATE_ALWAYS,                // overwrite existing file
					FILE_ATTRIBUTE_NORMAL,        // normal file 
					NULL);                        // no attr. template 

     // Do some error checking.
     if ((DWORD)hReadFile == 0xFFFFFFFF)
     {
		 AfxMessageBox("Create File Handle error ! ");
		 CloseHandle(hReadFile);
	 }

	//1---------  create Read File end --------

	 //2!!!!!!!!!!!!!Open DB start!!!!!!!!!!!!!!!!

			retcode = SQLAllocEnv(&henv);              // Environment handle 
			if (retcode == SQL_SUCCESS) 
			{
				retcode = SQLAllocConnect(henv, &hdbc); // Connection handle 
				if (retcode == SQL_SUCCESS) 
				{
					// Set login timeout to 10 seconds. 
					SQLSetConnectOption(hdbc, SQL_LOGIN_TIMEOUT, 10);

					// Connect to data source 
					retcode = SQLConnect(hdbc, sz_DSN, SQL_NTS, sz_UID, SQL_NTS, sz_PWD, SQL_NTS);
					if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
					{				// Process data after successful connection
					
						retcode = SQLAllocStmt(hdbc, &hstmt); ///Statement handle 
						if (retcode == SQL_SUCCESS) 
						{          // if Statement handle start
							bReturn = true;
							//AfxMessageBox("Open DB Error!");
						}			// if Statement handle start
						else
						{
							AfxMessageBox("Open DataBase error ! ");

							SQLDisconnect(hdbc);
							SQLFreeConnect(hdbc);
							SQLFreeEnv(henv);
						
						    bReturn = false;
						}


					}   /// if Statement handle end 
				
				}  // Process data after successful connection. end 
			
			}

	//2!!!!!!!!!!!!!Open DB end!!!!!!!!!!!!!!!!

  
	return bReturn; // true;
}

bool CMainFrame::zlCloseFileDB()
{
	
	SQLDisconnect(hdbc);
	SQLFreeConnect(hdbc);
	SQLFreeEnv(henv);

	CloseHandle(hReadFile);


	


	return true;
}

void CMainFrame::OnInsert() 
{
			

		//********************************************
			 AfxMessageBox( "insert 88888888888888888");
			 
			HENV    henv;
			HDBC    hdbc;
			HSTMT   hstmt;
			RETCODE retcode;
			bool bReturn = false; //99.8.26

			UCHAR sz_DSN[] = "DSN_MULTopN";
			UCHAR sz_UID[] = "sa";
			UCHAR sz_PWD[] = "123";   //txgstxh

			retcode = SQLAllocEnv(&henv);              // Environment handle 
			if (retcode == SQL_SUCCESS) 
			{
				retcode = SQLAllocConnect(henv, &hdbc); // Connection handle 
				if (retcode == SQL_SUCCESS) 
				{
					// Set login timeout to 10 seconds. 
					SQLSetConnectOption(hdbc, SQL_LOGIN_TIMEOUT, 10);

					// Connect to data source 
					retcode = SQLConnect(hdbc, sz_DSN, SQL_NTS, sz_UID, SQL_NTS, sz_PWD, SQL_NTS);
					if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
					{				// Process data after successful connection
						 
						retcode = SQLAllocStmt(hdbc, &hstmt); ///Statement handle 
						if (retcode == SQL_SUCCESS) 
						{                        // if Statement handle start


//--------------------------- insert  start ------------------------

					//	char szSmpl0[] = " INSERT Census2DTable VALUES(111, 33333)"; //Adult
				
						char szSmpl0[] = " INSERT Adult VALUES(111,'AA', 33333,'SS',11,'FFF','FFGG','HHH','JJJ','KK',22,33,44,'III','EEE')"; //Adult


						char * szSqlInsert = new char [500 + 1];

						strcpy(szSqlInsert , szSmpl0);

						int iResponse = AfxMessageBox("INSERT?", MB_OKCANCEL,0 );
						if (iResponse == IDOK)
						{					
							retcode = SQLExecDirect(hstmt, (unsigned char *)szSmpl0, SQL_NTS);

							if (retcode == SQL_SUCCESS) 
							{  //	retcode = SQLExecDirect
								AfxMessageBox("Insert new User Seccess!");
							}
							else
							{
								AfxMessageBox("Insert new User Error!");

							} //	retcode = SQLExecDirect 
						}
						//delete [] szSqlInsert; 


					//--------------------------- insert end ---------------------------



					SQLFreeStmt(hstmt, SQL_DROP);
				}   /// if Statement handle end 
				SQLDisconnect(hdbc);
			}  // Process data after successful connection. end 
			SQLFreeConnect(hdbc);
		}
		SQLFreeEnv(henv);
	}
	
	 // ***********************************/
	

}

void CMainFrame::OnCovtypeInsert() 
{
	
	//AfxMessageBox("This is OnViewFileToDB!");

	char buffer[81920] = "";
	CString CStrBuff = "";
	CString CStrBuffMeg = "";
	CString CStrInsert = ""; 
	char	cTmp[100] = "";
	char	cTmp1[100] = "";
	char	cTmp2[10000] = "";
	char	cAttribute[55][50]= { "","","","","","","","","","","","","","","", //15
								  "","","","","","","","","","","","","","","", 
								  "","","","","","","","","","","","","","","",
								  "","","","","","","","","",""};
	//CString cAttribute[15];
	
	int i,j,istart = 0;
	int iBreadCount = 0, itest, iErr =0 ;
	int iTuplesNum = 0;

	
	//---------  create Read File start --------
	//SQLFreeStmt(hstmt, SQL_DROP);
	//zlCloseFileDB();
	if(!zlOpenFileDB())
	{
		AfxMessageBox("zlOpenFileDB() err!");
		zlCloseFileDB();
	}else
	{// read file  and convert it to database 
	
		//++++++ to do start +++++++++++++
		do 
		{
			if (ReadFile(hReadFile, buffer, 80000, 
					&dwBytesRead, NULL)) 
			{ 
				CStrBuff += buffer;
				int iLen = CStrBuff.GetLength();

			  for(i=0; i < iLen; i++)
			  {
				  if(CStrBuff[i]==10)
					  iTuplesNum++;
			  }

			  iBreadCount = 0;
			  while ( iBreadCount<iTuplesNum ) 
			  {
					

				for (i = 0; i < 55; i++)
				{// for i
					
					int k= 0;
					for (k = 0; k<50; k++)
					    cAttribute[i][k] =0;

					k= 0;

					for(j = istart; j < iLen; j++)
					{ //for j

						if( (CStrBuff[j] == ',') || CStrBuff[j] == 10 )
						{
							if(CStrBuff[j] == 10)
							{
								iBreadCount ++;
							}

							break;
							
						}else
						{
							cAttribute[i][k] = CStrBuff[j];

						}

						k++;
 
					}//for j
				
					istart = j+1;

				} //for i



				//CStrInsert += " INSERT Adult VALUES( ";	
				//CStrInsert += " INSERT Adult1 VALUES( ";
				
	    		CStrInsert += " INSERT cover4DTable1 VALUES( ";	

				CStrInsert += cAttribute[0];
				CStrInsert += ",";
				CStrInsert += cAttribute[1];
				CStrInsert += ",";
				CStrInsert += cAttribute[2];
				CStrInsert += ",";
				CStrInsert += cAttribute[5];
				CStrInsert += ")";

			    int iSqlLen = CStrInsert.GetLength();

				char * szSqlInsert = new char [iSqlLen + 1];
				strcpy(szSqlInsert , "");
				strcat(szSqlInsert , CStrInsert);

			//	int iResponse = AfxMessageBox(szSqlInsert, MB_OKCANCEL,0 );

			//	if (iResponse == IDOK)
				{	
					
					//char szSmpl0[] = " INSERT Adult VALUES(222,'BBB', 33333,'SS',11,'FFF','FFGG','HHH','JJJ','KK',22,33,44,'III','EEE')"; //Adult
					//retcode = SQLExecDirect(hstmt, (unsigned char *)szSmpl0, SQL_NTS);

					retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlInsert, SQL_NTS);



					if (retcode == SQL_SUCCESS) 
					{  //	retcode = SQLExecDirect
						//AfxMessageBox("Insert new Recode Seccess!");
						//bReturn = TRUE;
					}
					else
					{
					//	AfxMessageBox("Insert new Recode Error!");
						iErr++;
						itest = 1;

					} //	retcode = SQLExecDirect 
				}

					CStrInsert = "";
					delete [] szSqlInsert; 

			}//while ( iBreadCount<iTuplesNum ) 



			CStrBuff = CStrBuff.Right(iLen - j-1);
			j=0;
			istart =0;
			iTuplesNum =0;

			
			//Sleep(100);
			} //if (ReadFile(hReadFile, buffer, 5000, 


		} while (dwBytesRead >0); 

		//++++++++++ to do end +++++++++

	}// read file  and convert it to database 

	sprintf_s(cTmp,"Err Num = %d, dwBytesRead = %d", iErr, dwBytesRead);
    AfxMessageBox(cTmp);
	AfxMessageBox("Insert new Recode OK!!!!!!!!!!!!!!!!!!!");

	SQLFreeStmt(hstmt, SQL_DROP);

	zlCloseFileDB();

	
}

void CMainFrame::OnDbgolumbiaInsert2d() 
{
		//AfxMessageBox("This is OnViewFileToDB!");
	//char buffer[80] = "";

	char buffer[81920] = "";
	CString CStrBuff = "";
	CString CStrBuffMeg = "";
	CString CStrInsert = ""; 
	char	cTmp[100] = "";
	char	cTmp1[100] = "";
	char	cTmp2[10000] = "";
	char	cAttribute[3][50]= { "","",""};
	//CString cAttribute[15];
	
	int i,j,istart = 0;
	int iBreadCount = 0, itest, iErr =0 ;
	int iTuplesNum = 0;

	bool bFirst = true;
	//---------  create Read File start --------
	//SQLFreeStmt(hstmt, SQL_DROP);
	//zlCloseFileDB();

	strcpy(ReadFileName, "\\\\.\\D:\\users\\zhuliang\\DATA\\census2d.data");
	if(!zlOpenFileDB())
	{
		AfxMessageBox("zlOpenFileDB() err!");
		zlCloseFileDB();
	}else
	{// read file  and convert it to database 
	
		//++++++ to do start +++++++++++++
		do 
		{
			if (ReadFile(hReadFile, buffer,80000, 
					&dwBytesRead, NULL)) 
			{ 
				CStrBuff += buffer;
				int iLen = CStrBuff.GetLength();

			  for(i=0; i < iLen; i++)
			  {
				  if(CStrBuff[i]==10)
					  iTuplesNum++;
			  }

			  iBreadCount = 0;
			  while ( iBreadCount<iTuplesNum ) 
			  {
					

				for (i = 0; i < 3; i++)
				{// for i
					
					int k= 0;
					for (k = 0; k<50; k++)
					    cAttribute[i][k] =0;

					k= 0;

					for(j = istart; j < iLen; j++)
					{ //for j

						if(CStrBuff[j] == 13 || CStrBuff[j+1] == 10 )
						{						
							iBreadCount ++;							
							j++;
							break;
							
						}else
						{
							
							if(bFirst == true)
							{
								itest =1;
								while(CStrBuff[j] == 32)
								{
									j++;
								}
								bFirst=false;
							}
								
							if (CStrBuff[j] != 32)
							{
							  cAttribute[i][k] = CStrBuff[j];
							}else
							{
								bFirst=true;
								break;
							}

						}

						k++;
 
					}//for j
				
					istart = j+1;

				} //for i



				//CStrInsert += " INSERT Adult VALUES( ";	
				//CStrInsert += " INSERT Adult1 VALUES( ";
				
	    		CStrInsert += " INSERT census2Dg VALUES( ";		    		
			
				//CStrInsert += " INSERT census2DTable VALUES( ";	

				CStrInsert += cAttribute[0];
				CStrInsert += ",";
				CStrInsert += cAttribute[1];
				CStrInsert += ")";

			    int iSqlLen = CStrInsert.GetLength();

				char * szSqlInsert = new char [iSqlLen + 1];
				strcpy(szSqlInsert , "");
				strcat(szSqlInsert , CStrInsert);

			//	int iResponse = AfxMessageBox(szSqlInsert, MB_OKCANCEL,0 );

			//	if (iResponse == IDOK)
				{	
					
					//char szSmpl0[] = " INSERT Adult VALUES(222,'BBB', 33333,'SS',11,'FFF','FFGG','HHH','JJJ','KK',22,33,44,'III','EEE')"; //Adult
					//retcode = SQLExecDirect(hstmt, (unsigned char *)szSmpl0, SQL_NTS);

					retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlInsert, SQL_NTS);



					if (retcode == SQL_SUCCESS) 
					{  //	retcode = SQLExecDirect
						//AfxMessageBox("Insert new Recode Seccess!");
						//bReturn = TRUE;
					}
					else
					{
					//	AfxMessageBox("Insert new Recode Error!");
						iErr++;
						itest = 1;

					} //	retcode = SQLExecDirect 
				}

					bFirst = true;				
					CStrInsert = "";
					delete [] szSqlInsert; 

			}//while ( iBreadCount<iTuplesNum ) 



			CStrBuff = CStrBuff.Right(iLen - j-1);
			j=0;
			istart =0;
			iTuplesNum =0;

			
			//Sleep(100);
			} //if (ReadFile(hReadFile, buffer, 5000, 


		} while (dwBytesRead >0); 

		//++++++++++ to do end +++++++++

	}// read file  and convert it to database 

	sprintf_s(cTmp,"Err Num = %d, dwBytesRead = %d", iErr, dwBytesRead);
    AfxMessageBox(cTmp);
	AfxMessageBox("Insert new Recode OK!!!!!!!!!!!!!!!!!!!");

	SQLFreeStmt(hstmt, SQL_DROP);

	zlCloseFileDB();


	
}

void CMainFrame::On3dInsert() 
{

			//AfxMessageBox("This is OnViewFileToDB!");
	//char buffer[80] = "";

	char buffer[81920] = "";
	CString CStrBuff = "";
	CString CStrBuffMeg = "";
	CString CStrInsert = ""; 
	char	cTmp[100] = "";
	char	cTmp1[100] = "";
	char	cTmp2[10000] = "";
	char	cAttribute[4][50]= { "","","",""};
	//CString cAttribute[15];
	
	int i,j,istart = 0;
	int iBreadCount = 0, itest, iErr =0 ;
	int iTuplesNum = 0;

	bool bFirst = true;
	//---------  create Read File start --------
	//SQLFreeStmt(hstmt, SQL_DROP);
	//zlCloseFileDB();

	strcpy(ReadFileName, "\\\\.\\D:\\users\\zhuliang\\DATA\\census3d.data");
	if(!zlOpenFileDB())
	{
		AfxMessageBox("zlOpenFileDB() err!");
		zlCloseFileDB();
	}else
	{// read file  and convert it to database 
	
		//++++++ to do start +++++++++++++
		do 
		{
			if (ReadFile(hReadFile, buffer, 80000, 
					&dwBytesRead, NULL)) 
			{ 
				CStrBuff += buffer;
				int iLen = CStrBuff.GetLength();

			  for(i=0; i < iLen; i++)
			  {
				  if(CStrBuff[i]==10)
					  iTuplesNum++;
			  }

			  iBreadCount = 0;
			  while ( iBreadCount<iTuplesNum ) 
			  {
					

				for (i = 0; i < 4; i++)
				{// for i
					
					int k= 0;
					for (k = 0; k<50; k++)
					    cAttribute[i][k] =0;

					k= 0;

					for(j = istart; j < iLen; j++)
					{ //for j

						if(CStrBuff[j] == 13 || CStrBuff[j+1] == 10 )
						{						
							iBreadCount ++;							
							j++;
							break;
							
						}else
						{
							
							if(bFirst == true)
							{
								itest =1;
								while(CStrBuff[j] == 32)
								{
									j++;
								}
								bFirst=false;
							}
								
							if (CStrBuff[j] != 32)
							{
							  cAttribute[i][k] = CStrBuff[j];
							}else
							{
								bFirst=true;
								break;
							}

						}

						k++;
 
					}//for j
				
					istart = j+1;

				} //for i



				//CStrInsert += " INSERT Adult VALUES( ";	
				//CStrInsert += " INSERT Adult1 VALUES( ";
				
	    		CStrInsert += " INSERT census3Dg VALUES( ";	

				CStrInsert += cAttribute[0];
				CStrInsert += ",";
				CStrInsert += cAttribute[1];
				CStrInsert += ",";
				CStrInsert += cAttribute[2];

				CStrInsert += ")";

			    int iSqlLen = CStrInsert.GetLength();

				char * szSqlInsert = new char [iSqlLen + 1];
				strcpy(szSqlInsert , "");
				strcat(szSqlInsert , CStrInsert);

			//	int iResponse = AfxMessageBox(szSqlInsert, MB_OKCANCEL,0 );

			//	if (iResponse == IDOK)
				{	
					
					//char szSmpl0[] = " INSERT Adult VALUES(222,'BBB', 33333,'SS',11,'FFF','FFGG','HHH','JJJ','KK',22,33,44,'III','EEE')"; //Adult
					//retcode = SQLExecDirect(hstmt, (unsigned char *)szSmpl0, SQL_NTS);

					retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlInsert, SQL_NTS);



					if (retcode == SQL_SUCCESS) 
					{  //	retcode = SQLExecDirect
						//AfxMessageBox("Insert new Recode Seccess!");
						//bReturn = TRUE;
					}
					else
					{
					//	AfxMessageBox("Insert new Recode Error!");
						iErr++;
						itest = 1;

					} //	retcode = SQLExecDirect 
				}

					bFirst = true;				
					CStrInsert = "";
					delete [] szSqlInsert; 

			}//while ( iBreadCount<iTuplesNum ) 



			CStrBuff = CStrBuff.Right(iLen - j-1);
			j=0;
			istart =0;
			iTuplesNum =0;

			
			//Sleep(100);
			} //if (ReadFile(hReadFile, buffer, 5000, 


		} while (dwBytesRead >0); 

		//++++++++++ to do end +++++++++

	}// read file  and convert it to database 

	sprintf_s(cTmp,"Err Num = %d, dwBytesRead = %d", iErr, dwBytesRead);
    AfxMessageBox(cTmp);
	AfxMessageBox("Insert new Recode OK!!!!!!!!!!!!!!!!!!!");

	SQLFreeStmt(hstmt, SQL_DROP);

	zlCloseFileDB();

}

void CMainFrame::OnInsertCover4d() 
{

	char buffer[81920] = "";
	CString CStrBuff = "";
	CString CStrBuffMeg = "";
	CString CStrInsert = ""; 
	char	cTmp[100] = "";
	char	cTmp1[100] = "";
	char	cTmp2[10000] = "";
	char	cAttribute[5][50]= { "","","","",""};
	//CString cAttribute[15];
	
	int i,j,istart = 0;
	int iBreadCount = 0, itest, iErr =0 ;
	int iTuplesNum = 0;

	bool bFirst = true;
	//---------  create Read File start --------
	//SQLFreeStmt(hstmt, SQL_DROP);
	//zlCloseFileDB();

	strcpy(ReadFileName, "\\\\.\\D:\\users\\zhuliang\\DATA\\cover1236.data");
	if(!zlOpenFileDB())
	{
		AfxMessageBox("zlOpenFileDB() err!");
		zlCloseFileDB();
	}else
	{// read file  and convert it to database 
	
		//++++++ to do start +++++++++++++
		do 
		{
			if (ReadFile(hReadFile, buffer, 80000, 
					&dwBytesRead, NULL)) 
			{ 
				CStrBuff += buffer;
				int iLen = CStrBuff.GetLength();

			  for(i=0; i < iLen; i++)
			  {
				  if(CStrBuff[i]==10)
					  iTuplesNum++;
			  }

			  iBreadCount = 0;
			  while ( iBreadCount<iTuplesNum ) 
			  {
					

				for (i = 0; i < 5; i++)
				{// for i
					
					int k= 0;
					for (k = 0; k<50; k++)
					    cAttribute[i][k] =0;

					k= 0;

					for(j = istart; j < iLen; j++)
					{ //for j

						if(CStrBuff[j] == 13 || CStrBuff[j+1] == 10 )
						{						
							iBreadCount ++;							
							j++;
							break;
							
						}else
						{
							
							if(bFirst == true)
							{
								itest =1;
								while(CStrBuff[j] == 32)
								{
									j++;
								}
								bFirst=false;
							}
								
							if (CStrBuff[j] != 32)
							{
							  cAttribute[i][k] = CStrBuff[j];
							}else
							{
								bFirst=true;
								break;
							}

						}

						k++;
 
					}//for j
				
					istart = j+1;

				} //for i



				//CStrInsert += " INSERT Adult VALUES( ";	
				//CStrInsert += " INSERT Adult1 VALUES( ";
				
	    		CStrInsert += " INSERT cover4Dg VALUES( ";	

				CStrInsert += cAttribute[0];
				CStrInsert += ",";
				CStrInsert += cAttribute[1];
				CStrInsert += ",";
				CStrInsert += cAttribute[2];
				CStrInsert += ",";
				CStrInsert += cAttribute[3];

				CStrInsert += ")";

			    int iSqlLen = CStrInsert.GetLength();

				char * szSqlInsert = new char [iSqlLen + 1];
				strcpy(szSqlInsert , "");
				strcat(szSqlInsert , CStrInsert);

			//	int iResponse = AfxMessageBox(szSqlInsert, MB_OKCANCEL,0 );

			//	if (iResponse == IDOK)
				{	
					
					//char szSmpl0[] = " INSERT Adult VALUES(222,'BBB', 33333,'SS',11,'FFF','FFGG','HHH','JJJ','KK',22,33,44,'III','EEE')"; //Adult
					//retcode = SQLExecDirect(hstmt, (unsigned char *)szSmpl0, SQL_NTS);

					retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlInsert, SQL_NTS);



					if (retcode == SQL_SUCCESS) 
					{  //	retcode = SQLExecDirect
						//AfxMessageBox("Insert new Recode Seccess!");
						//bReturn = TRUE;
					}
					else
					{
					//	AfxMessageBox("Insert new Recode Error!");
						iErr++;
						itest = 1;

					} //	retcode = SQLExecDirect 
				}

					bFirst = true;				
					CStrInsert = "";
					delete [] szSqlInsert; 

			}//while ( iBreadCount<iTuplesNum ) 



			CStrBuff = CStrBuff.Right(iLen - j-1);
			j=0;
			istart =0;
			iTuplesNum =0;

			
			//Sleep(100);
			} //if (ReadFile(hReadFile, buffer, 5000, 


		} while (dwBytesRead >0); 

		//++++++++++ to do end +++++++++

	}// read file  and convert it to database 

	sprintf_s(cTmp,"Err Num = %d, dwBytesRead = %d", iErr, dwBytesRead);
    AfxMessageBox(cTmp);
	AfxMessageBox("Insert new Recode OK!!!!!!!!!!!!!!!!!!!");

	SQLFreeStmt(hstmt, SQL_DROP);

	zlCloseFileDB();	
}

void CMainFrame::OnSelectAll() 
{
	long lStartTimer; //= GetTickCount();
	long lEndTimer;
	int i,iErr = 0;
	char tmp[100] = "";
	CString CStrInsert = ""; 

	HSTMT   hstmt_SelectAllTimer;

	for( i= 0; i<1000; i++)
	{

		//if(!zlOpenDB())
		//{
			//AfxMessageBox("zlOpenDB() err!");
			//zlCloseDB();
		//}else
		{
			retcode = SQLAllocStmt(hdbc, &hstmt_SelectAllTimer); ///Statement handle 

			lStartTimer = GetTickCount();

			UCHAR szSqlAllRows[] = "SELECT * FROM census2Dg"; //discounts, authors, Census2DTable						
			SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
			SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
			retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);

			lEndTimer = GetTickCount() - lStartTimer;
			wsprintf(tmp, "%ld", lEndTimer);

			
			

			//SQLFreeStmt(hstmt, SQL_DROP);

	    	CStrInsert += " INSERT DATA_SelectAllcensus2Dg1 VALUES( ";	
			CStrInsert += tmp;
			CStrInsert += ")";

			int iSqlLen = CStrInsert.GetLength();

			char * szSqlInsert = new char [iSqlLen + 1];
			strcpy(szSqlInsert , "");
			strcat(szSqlInsert , CStrInsert);

				
			retcode = SQLExecDirect(hstmt_SelectAllTimer, (unsigned char *)szSqlInsert, SQL_NTS);


			if (retcode == SQL_SUCCESS) 
			{  //	retcode = SQLExecDirect
				//AfxMessageBox("Insert new Recode Seccess!");
				//bReturn = TRUE;
			}
			else
			{
			//	AfxMessageBox("Insert new Recode Error!");
				iErr++;

			} //	retcode = SQLExecDirect 
		
			CStrInsert = "";
			delete [] szSqlInsert; 

			//SQLFreeStmt(hstmt, SQL_DROP);


		}


		SQLFreeStmt(hstmt, SQL_DROP);
		SQLFreeStmt(hstmt_SelectAllTimer, SQL_DROP);


		//zlCloseDB();

		//Sleep(10000);

	} //for( i= 0; i<1000, i++)

		//wsprintf(tmp, "timer = %ld , MSG =%ld ", lEndTimer, msg.message );
		wsprintf(tmp, "SELECT * FROM census2Dg, timer = %ld, ierr = %d", lEndTimer,iErr );

		AfxMessageBox(tmp);



}


/*********
bool CMainFrame::zlOpenDB()
{
    bool bReturn;

	//1!!!!!!!!!!!!!Open DB start!!!!!!!!!!!!!!!!

	retcode = SQLAllocEnv(&henv);              //1 Environment handle 
	if (retcode == SQL_SUCCESS) 
	{
		retcode = SQLAllocConnect(henv, &hdbc); //2 Connection handle 
		if (retcode == SQL_SUCCESS) 
		{
			// Set login timeout to 10 seconds. 
			SQLSetConnectOption(hdbc, SQL_LOGIN_TIMEOUT, 10);

			//3 Connect to data source 
			retcode = SQLConnect(hdbc, sz_DSN, SQL_NTS, sz_UID, SQL_NTS, sz_PWD, SQL_NTS);
			if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
			{				// Process data after successful connection
			
				retcode = SQLAllocStmt(hdbc, &hstmt); ///4 Statement handle 
				if (retcode == SQL_SUCCESS) 
				{          // if Statement handle start
					bReturn = true;
					//AfxMessageBox("Open DB Error!");
				}			// if Statement handle start
				else
				{
					AfxMessageBox("Open DataBase error ! ");

					SQLDisconnect(hdbc);
					SQLFreeConnect(hdbc);
					SQLFreeEnv(henv);
				
					bReturn = false;
				}


			}   /// if Statement handle end 
		
		}  // Process data after successful connection. end 
	
	}

	//1!!!!!!!!!!!!!Open DB end!!!!!!!!!!!!!!!!

  
	return bReturn; // true;
}

bool CMainFrame::zlCloseDB()
{
	
	SQLFreeStmt(hstmt, SQL_DROP); //2005.3.7

	SQLDisconnect(hdbc);
	SQLFreeConnect(hdbc);
	SQLFreeEnv(henv);


	return true;
}

********/
void CMainFrame::OnSelect2DWhere() 
{
	long lStartTimer; //= GetTickCount();
	long lEndTimer;
		

	//if(!zlOpenDB())
	//{
	//	AfxMessageBox("zlOpenDB() err!");
//		zlCloseDB();
//	}else
	{  
		
		lStartTimer = GetTickCount();

		UCHAR szSqlAllRows[] = "SELECT * FROM census2Dg  WHERE (40 <= Age AND Age<= 50) AND (3000 <= Income  AND Income <= 4000) "; //discounts, authors, Census2DTable
					
		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);

		retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);


		lEndTimer = GetTickCount() - lStartTimer;
		char tmp[100];
		//wsprintf(tmp, "timer = %ld , MSG =%ld ", lEndTimer, msg.message );
		wsprintf(tmp, "SELECT * FROM census2Dg, timer = %ld", lEndTimer );

		AfxMessageBox(tmp);

	}

	//zlCloseDB();
}

void CMainFrame::OnGeneratProfile() 
{

	//long lStartTimer; //= GetTickCount();
	//long lEndTimer;
	/***************************
	Age			int NOT NULL,
	Income 		int Not NULL,
	N			int Not NULL,
	r			float Not NULL,
	f			int Not NULL,
	c			int Not NULL,
	d			int Not NULL,

	***************************/

	
	
	int i,iErr = 0;
	char tmp[100] = "";
	CString CStrInsert = ""; 
	
	SWORD  sAge;
	SDWORD cbAge;

	SDWORD sIncome;
	SDWORD cbIncome;


	HSTMT   hstmt_Generet2DProfile;

	srand( (unsigned)time( NULL ) );


		//if(!zlOpenDB())
		//{
	//		AfxMessageBox("zlOpenDB() err!");
	//		zlCloseDB();
	//	}else
		{
			retcode = SQLAllocStmt(hdbc, &hstmt_Generet2DProfile); ///Statement handle 

			//lStartTimer = GetTickCount();

			UCHAR szSqlAllRows[] = "SELECT * FROM census2DTable1"; //discounts, authors, Census2DTable						
			SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
			SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
			retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);

			//lEndTimer = GetTickCount() - lStartTimer;
			//wsprintf(tmp, "%ld", lEndTimer);

			//1111111111111 read data base 111111111111111

			if (retcode == SQL_SUCCESS) 
			{    //	retcode = SQLExecDirect
				int iRowCount, iTupleNum, iSpan, iSampleNum, iStartRowNum, iTotalNum;
				SDWORD *  RowCountPtr = new SDWORD ;
				retcode = SQLRowCount(hstmt, RowCountPtr);						 
				iRowCount = * RowCountPtr;
				iTupleNum = iRowCount;
				iSpan = (int) (iRowCount/100);
				iSampleNum =0;
				delete RowCountPtr;
				
				// Bind columns 2,3.
				SQLBindCol(hstmt, 2, SQL_C_SSHORT, &sAge, 0, &cbAge);
				SQLBindCol(hstmt, 3, SQL_C_SLONG, &sIncome,0, &cbIncome); //SQL_C_SSHORT

				int * pAge = new  int[iRowCount];//new float[10]
				int * pIncome = new  int[iRowCount];//new float[10]

				iRowCount = 0;
				iStartRowNum = 0;
				iTotalNum = 0;
				while (TRUE) 
				{
					
						int iRandom = rand()%100;
						for (i = iStartRowNum; i < iSampleNum + iRandom; i++)
						{
					      retcode = SQLFetch(hstmt);
						  iRowCount ++ ; 
						}

					if (retcode == SQL_ERROR)
					{
						//show_error();

						wsprintf(tmp, "%ld", iRowCount);
						//int i = iRowCount;
						AfxMessageBox("SQLFetch Error !!!!!!");
								//break; //99.8.26
					}

					if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO ||iRowCount>= iSampleNum)
							//if (retcode == SQL_SUCCESS)
					{	

						char cAge[20] = "", cIncome[20] = "", cTupleNum[20] ="";

						sprintf(cAge,"%d",sAge);
						sprintf(cIncome,"%ld",sIncome);
						sprintf(cTupleNum,"%ld",iRowCount);

						
						CStrInsert += " INSERT DATA_GeneratProfile2D VALUES( ";	
						CStrInsert += cAge;
						CStrInsert += ",";
						CStrInsert += cIncome;
						CStrInsert += ",";
						CStrInsert += cTupleNum;
						CStrInsert += ")";

						int iSqlLen = CStrInsert.GetLength();

						char * szSqlInsert = new char [iSqlLen + 1];
						strcpy(szSqlInsert , "");
						strcat(szSqlInsert , CStrInsert);
							
						retcode = SQLExecDirect(hstmt_Generet2DProfile, (unsigned char *)szSqlInsert, SQL_NTS);


						if (retcode == SQL_SUCCESS) 
						{  //	retcode = SQLExecDirect
							//AfxMessageBox("Insert new Recode Seccess!");
							//bReturn = TRUE;
							iTotalNum ++;
						}
						else
						{
						//	AfxMessageBox("Insert new Recode Error!");
							iErr++;

						} //	retcode = SQLExecDirect 
					
						CStrInsert = "";
						delete [] szSqlInsert; 

						iStartRowNum = iRowCount;
						iSampleNum += iSpan ;
					} 
					else 
					{
						break;
					}

					if(iTotalNum >=100)
						break;


				}   ///while (TRUE)

						
					

						delete [] pAge;//new float[10]
						delete [] pIncome;//new float[10]

			}//	retcode = SQLExecDirect



		//111111111111111111 read data base end111111111111


		}


	SQLFreeStmt(hstmt, SQL_DROP);
	SQLFreeStmt(hstmt_Generet2DProfile, SQL_DROP);
//	zlCloseDB();

	AfxMessageBox("Insert Generet2DProfile OK!");	


}

void CMainFrame::OnGauss2d() 
{
	char buffer[81920] = "";
	CString CStrBuff = "";
	CString CStrBuffMeg = "";
	CString CStrInsert = ""; 
	char	cTmp[100] = "";
	char	cTmp1[100] = "";
	char	cTmp2[10000] = "";
	char	cAttribute[3][50]= { "","",""};
	//CString cAttribute[15];
	
	int i,j,istart = 0;
	int iBreadCount = 0, itest, iErr =0 ;
	int iTuplesNum = 0;

	bool bFirst = true;
	//---------  create Read File start --------
	//SQLFreeStmt(hstmt, SQL_DROP);
	//zlCloseFileDB();

	strcpy(ReadFileName, "\\\\.\\D:\\users\\zhuliang\\DATA\\gauss_d2_N500000_z100_p50_r10000_s100_seed1234.data");
	if(!zlOpenFileDB())
	{
		AfxMessageBox("zlOpenFileDB() err!");
		zlCloseFileDB();
	}else
	{// read file  and convert it to database 
	
		//++++++ to do start +++++++++++++
		do 
		{
			if (ReadFile(hReadFile, buffer, 80000, 
					&dwBytesRead, NULL)) 
			{ 
				CStrBuff += buffer;
				int iLen = CStrBuff.GetLength();

			  for(i=0; i < iLen; i++)
			  {
				  if(CStrBuff[i]==10)
					  iTuplesNum++;
			  }

			  iBreadCount = 0;
			  while ( iBreadCount<iTuplesNum ) 
			  {
					

				for (i = 0; i < 3; i++)
				{// for i
					
					int k= 0;
					for (k = 0; k<50; k++)
					    cAttribute[i][k] =0;

					k= 0;

					for(j = istart; j < iLen; j++)
					{ //for j

						if(CStrBuff[j] == 13 || CStrBuff[j+1] == 10 )
						{						
							iBreadCount ++;							
							j++;
							break;
							
						}else
						{
							
							if(bFirst == true)
							{
								itest =1;
								while(CStrBuff[j] == 32)
								{
									j++;
								}
								bFirst=false;
							}
								
							if (CStrBuff[j] != 32)
							{
							  cAttribute[i][k] = CStrBuff[j];
							}else
							{
								bFirst=true;
								break;
							}

						}

						k++;
 
					}//for j
				
					istart = j+1;

				} //for i



				//CStrInsert += " INSERT Adult VALUES( ";	
				//CStrInsert += " INSERT Adult1 VALUES( ";
				
	    		CStrInsert += " INSERT Gauss2Dg VALUES( ";	

				CStrInsert += cAttribute[0];
				CStrInsert += ",";
				CStrInsert += cAttribute[1];

				CStrInsert += ")";

			    int iSqlLen = CStrInsert.GetLength();

				char * szSqlInsert = new char [iSqlLen + 1];
				strcpy(szSqlInsert , "");
				strcat(szSqlInsert , CStrInsert);

			//	int iResponse = AfxMessageBox(szSqlInsert, MB_OKCANCEL,0 );

			//	if (iResponse == IDOK)
				{	
					
					//char szSmpl0[] = " INSERT Adult VALUES(222,'BBB', 33333,'SS',11,'FFF','FFGG','HHH','JJJ','KK',22,33,44,'III','EEE')"; //Adult
					//retcode = SQLExecDirect(hstmt, (unsigned char *)szSmpl0, SQL_NTS);

					retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlInsert, SQL_NTS);



					if (retcode == SQL_SUCCESS) 
					{  //	retcode = SQLExecDirect
						//AfxMessageBox("Insert new Recode Seccess!");
						//bReturn = TRUE;
					}
					else
					{
					//	AfxMessageBox("Insert new Recode Error!");
						iErr++;
						itest = 1;

					} //	retcode = SQLExecDirect 
				}

					bFirst = true;				
					CStrInsert = "";
					delete [] szSqlInsert; 

			}//while ( iBreadCount<iTuplesNum ) 



			CStrBuff = CStrBuff.Right(iLen - j-1);
			j=0;
			istart =0;
			iTuplesNum =0;

			
			//Sleep(100);
			} //if (ReadFile(hReadFile, buffer, 5000, 


		} while (dwBytesRead >0); 

		//++++++++++ to do end +++++++++

	}// read file  and convert it to database 

	sprintf(cTmp,"Err Num = %d, dwBytesRead = %d", iErr, dwBytesRead);
    AfxMessageBox(cTmp);
	AfxMessageBox("Insert new Recode OK!!!!!!!!!!!!!!!!!!!");

	SQLFreeStmt(hstmt, SQL_DROP);

	zlCloseFileDB();	
}

void CMainFrame::OnGauss_3d() 
{
	char buffer[81920] = "";
	CString CStrBuff = "";
	CString CStrBuffMeg = "";
	CString CStrInsert = ""; 
	char	cTmp[100] = "";
	char	cTmp1[100] = "";
	char	cTmp2[10000] = "";
	char	cAttribute[4][50]= { "","","",""};
	//CString cAttribute[15];
	
	int i,j,istart = 0;
	int iBreadCount = 0, itest, iErr =0 ;
	int iTuplesNum = 0;

	bool bFirst = true;
	//---------  create Read File start --------
	//SQLFreeStmt(hstmt, SQL_DROP);
	//zlCloseFileDB();

	strcpy(ReadFileName, "\\\\.\\D:\\users\\zhuliang\\DATA\\gauss_d3_N500000_z100_p50_r10000_s100_seed1234.data");
	if(!zlOpenFileDB())
	{
		AfxMessageBox("zlOpenFileDB() err!");
		zlCloseFileDB();
	}else
	{// read file  and convert it to database 
	
		//++++++ to do start +++++++++++++
		do 
		{
			if (ReadFile(hReadFile, buffer, 80000, 
					&dwBytesRead, NULL)) 
			{ 
				CStrBuff += buffer;
				int iLen = CStrBuff.GetLength();

			  for(i=0; i < iLen; i++)
			  {
				  if(CStrBuff[i]==10)
					  iTuplesNum++;
			  }

			  iBreadCount = 0;
			  while ( iBreadCount<iTuplesNum ) 
			  {
					

				for (i = 0; i < 4; i++)
				{// for i
					
					int k= 0;
					for (k = 0; k<50; k++)
					    cAttribute[i][k] =0;

					k= 0;

					for(j = istart; j < iLen; j++)
					{ //for j

						if(CStrBuff[j] == 13 || CStrBuff[j+1] == 10 )
						{						
							iBreadCount ++;							
							j++;
							break;
							
						}else
						{
							
							if(bFirst == true)
							{
								itest =1;
								while(CStrBuff[j] == 32)
								{
									j++;
								}
								bFirst=false;
							}
								
							if (CStrBuff[j] != 32)
							{
							  cAttribute[i][k] = CStrBuff[j];
							}else
							{
								bFirst=true;
								break;
							}

						}

						k++;
 
					}//for j
				
					istart = j+1;

				} //for i



				//CStrInsert += " INSERT Adult VALUES( ";	
				//CStrInsert += " INSERT Adult1 VALUES( ";
				
	    		CStrInsert += " INSERT Gauss_3Dg VALUES( ";	

				CStrInsert += cAttribute[0];
				CStrInsert += ",";
				CStrInsert += cAttribute[1];
				CStrInsert += ",";
				CStrInsert += cAttribute[2];

				CStrInsert += ")";

			    int iSqlLen = CStrInsert.GetLength();

				char * szSqlInsert = new char [iSqlLen + 1];
				strcpy(szSqlInsert , "");
				strcat(szSqlInsert , CStrInsert);

			//	int iResponse = AfxMessageBox(szSqlInsert, MB_OKCANCEL,0 );

			//	if (iResponse == IDOK)
				{	
					
					//char szSmpl0[] = " INSERT Adult VALUES(222,'BBB', 33333,'SS',11,'FFF','FFGG','HHH','JJJ','KK',22,33,44,'III','EEE')"; //Adult
					//retcode = SQLExecDirect(hstmt, (unsigned char *)szSmpl0, SQL_NTS);

					retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlInsert, SQL_NTS);



					if (retcode == SQL_SUCCESS) 
					{  //	retcode = SQLExecDirect
						//AfxMessageBox("Insert new Recode Seccess!");
						//bReturn = TRUE;
					}
					else
					{
					//	AfxMessageBox("Insert new Recode Error!");
						iErr++;
						itest = 1;

					} //	retcode = SQLExecDirect 
				}

					bFirst = true;				
					CStrInsert = "";
					delete [] szSqlInsert; 

			}//while ( iBreadCount<iTuplesNum ) 



			CStrBuff = CStrBuff.Right(iLen - j-1);
			j=0;
			istart =0;
			iTuplesNum =0;

			
			//Sleep(100);
			} //if (ReadFile(hReadFile, buffer, 5000, 


		} while (dwBytesRead >0); 

		//++++++++++ to do end +++++++++

	}// read file  and convert it to database 

	sprintf(cTmp,"Err Num = %d, dwBytesRead = %d", iErr, dwBytesRead);
    AfxMessageBox(cTmp);
	AfxMessageBox("Insert new Recode OK!!!!!!!!!!!!!!!!!!!");

	SQLFreeStmt(hstmt, SQL_DROP);

	zlCloseFileDB();
	
}

void CMainFrame::OnArray3d() 
{
	char buffer[81920] = "";
	CString CStrBuff = "";
	CString CStrBuffMeg = "";
	CString CStrInsert = ""; 
	char	cTmp[100] = "";
	char	cTmp1[100] = "";
	char	cTmp2[10000] = "";
	char	cAttribute[4][50]= { "","","",""};
	//CString cAttribute[15];
	
	int i,j,istart = 0;
	int iBreadCount = 0, itest, iErr =0 ;
	int iTuplesNum = 0;

	bool bFirst = true;
	//---------  create Read File start --------
	//SQLFreeStmt(hstmt, SQL_DROP);
	//zlCloseFileDB();

	strcpy(ReadFileName, "\\\\.\\D:\\users\\zhuliang\\DATA\\array_d3_N500000_z100_r10000_n60_seed1234.data");
	if(!zlOpenFileDB())
	{
		AfxMessageBox("zlOpenFileDB() err!");
		zlCloseFileDB();
	}else
	{// read file  and convert it to database 
	
		//++++++ to do start +++++++++++++
		do 
		{
			if (ReadFile(hReadFile, buffer, 80000, 
					&dwBytesRead, NULL)) 
			{ 
				CStrBuff += buffer;
				int iLen = CStrBuff.GetLength();

			  for(i=0; i < iLen; i++)
			  {
				  if(CStrBuff[i]==10)
					  iTuplesNum++;
			  }

			  iBreadCount = 0;
			  while ( iBreadCount<iTuplesNum ) 
			  {
					

				for (i = 0; i < 4; i++)
				{// for i
					
					int k= 0;
					for (k = 0; k<50; k++)
					    cAttribute[i][k] =0;

					k= 0;

					for(j = istart; j < iLen; j++)
					{ //for j

						if(CStrBuff[j] == 13 || CStrBuff[j+1] == 10 )
						{						
							iBreadCount ++;							
							j++;
							break;
							
						}else
						{
							
							if(bFirst == true)
							{
								itest =1;
								while(CStrBuff[j] == 32)
								{
									j++;
								}
								bFirst=false;
							}
								
							if (CStrBuff[j] != 32)
							{
							  cAttribute[i][k] = CStrBuff[j];
							}else
							{
								bFirst=true;
								break;
							}

						}

						k++;
 
					}//for j
				
					istart = j+1;

				} //for i



				//CStrInsert += " INSERT Adult VALUES( ";	
				//CStrInsert += " INSERT Adult1 VALUES( ";
				
	    		CStrInsert += " INSERT Array3Dg VALUES( ";	

				CStrInsert += cAttribute[0];
				CStrInsert += ",";
				CStrInsert += cAttribute[1];
				CStrInsert += ",";
				CStrInsert += cAttribute[2];

				CStrInsert += ")";

			    int iSqlLen = CStrInsert.GetLength();

				char * szSqlInsert = new char [iSqlLen + 1];
				strcpy(szSqlInsert , "");
				strcat(szSqlInsert , CStrInsert);

			//	int iResponse = AfxMessageBox(szSqlInsert, MB_OKCANCEL,0 );

			//	if (iResponse == IDOK)
				{	
					
					//char szSmpl0[] = " INSERT Adult VALUES(222,'BBB', 33333,'SS',11,'FFF','FFGG','HHH','JJJ','KK',22,33,44,'III','EEE')"; //Adult
					//retcode = SQLExecDirect(hstmt, (unsigned char *)szSmpl0, SQL_NTS);

					retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlInsert, SQL_NTS);



					if (retcode == SQL_SUCCESS) 
					{  //	retcode = SQLExecDirect
						//AfxMessageBox("Insert new Recode Seccess!");
						//bReturn = TRUE;
					}
					else
					{
					//	AfxMessageBox("Insert new Recode Error!");
						iErr++;
						itest = 1;

					} //	retcode = SQLExecDirect 
				}

					bFirst = true;				
					CStrInsert = "";
					delete [] szSqlInsert; 

			}//while ( iBreadCount<iTuplesNum ) 



			CStrBuff = CStrBuff.Right(iLen - j-1);
			j=0;
			istart =0;
			iTuplesNum =0;

			
			//Sleep(100);
			} //if (ReadFile(hReadFile, buffer, 5000, 


		} while (dwBytesRead >0); 

		//++++++++++ to do end +++++++++

	}// read file  and convert it to database 

	sprintf(cTmp,"Err Num = %d, dwBytesRead = %d", iErr, dwBytesRead);
    AfxMessageBox(cTmp);
	AfxMessageBox("Insert new Recode to Array3Dg OK!!!!!!!!!!!!!!!!!!!");

	SQLFreeStmt(hstmt, SQL_DROP);

	zlCloseFileDB();

}

void CMainFrame::OnCensus2dworkload() 
{
	//long lStartTimer; //= GetTickCount();
	//long lEndTimer;
	int i,iErr = 0;
	char tmp[100] = "";
	CString CStrInsert = ""; 
	
	SWORD  sAge;
	SDWORD cbAge;

	SDWORD sIncome;
	SDWORD cbIncome;


	HSTMT   hstmt_Generet2DWorkload;

	srand( (unsigned)time( NULL ) );


	//	if(!zlOpenDB())
	//	{
	//		AfxMessageBox("zlOpenDB() err!");
	//		zlCloseDB();
	//	}else
		{
			retcode = SQLAllocStmt(hdbc, &hstmt_Generet2DWorkload); ///Statement handle 

			//lStartTimer = GetTickCount();

			// 2005.4.6 UCHAR szSqlAllRows[] = "SELECT * FROM census2Dg"; //discounts, authors, Census2DTable						
			
			UCHAR szSqlAllRows[] = "SELECT * FROM CLMB_census2D"; // (// 2005.4.6 )discounts, authors, Census2DTable						
			
			SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
			SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
			retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);

			//lEndTimer = GetTickCount() - lStartTimer;
			//wsprintf(tmp, "%ld", lEndTimer);

			//1111111111111 read data base 111111111111111

			if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) 
			{    //	retcode = SQLExecDirect
				int iRowCount, iTupleNum, iSpan, iSampleNum, iStartRowNum, iTotalNum;
				SDWORD *  RowCountPtr = new SDWORD ;
				retcode = SQLRowCount(hstmt, RowCountPtr);						 
				iRowCount = * RowCountPtr;
				iTupleNum = iRowCount;
				iSpan = (int) (iRowCount/100);
				iSampleNum =0;
				delete RowCountPtr;
				
				// Bind columns 1,2.
				SQLBindCol(hstmt, 1, SQL_C_SSHORT, &sAge, 0, &cbAge);
				SQLBindCol(hstmt, 2, SQL_C_SLONG, &sIncome,0, &cbIncome); //SQL_C_SSHORT

				int * pAge = new  int[iRowCount];//new float[10]
				int * pIncome = new  int[iRowCount];//new float[10]

				iRowCount = 0;
				iStartRowNum = 0;
				iTotalNum = 0;
				while (TRUE) 
				{
					
						int iRandom = rand()%100;
						for (i = iStartRowNum; i < iSampleNum + iRandom; i++)
						{
					      retcode = SQLFetch(hstmt);
						  iRowCount ++ ; 
						}

					if (retcode == SQL_ERROR)
					{
						//show_error();

						wsprintf(tmp, "%ld", iRowCount);
						//int i = iRowCount;
						AfxMessageBox("SQLFetch Error !!!!!!");
								//break; //99.8.26
					}

					if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO ||iRowCount>= iSampleNum)
							//if (retcode == SQL_SUCCESS)
					{	

						char cAge[20] = "", cIncome[20] = "", cTupleNum[20] ="";

						sprintf(cAge,"%d",sAge);
						sprintf(cIncome,"%ld",sIncome);
						sprintf(cTupleNum,"%ld",iRowCount);

						
						CStrInsert += " INSERT DATA_Census2Dg_B_workload VALUES( ";	
						//CStrInsert += " INSERT DATA_Census2Dg_B_workload1 VALUES( ";	
						//CStrInsert += " INSERT DATA_Census2Dg_B_workload2 VALUES( ";	
						
						CStrInsert += cAge;
						CStrInsert += ",";
						CStrInsert += cIncome;
						//CStrInsert += ",";
						//CStrInsert += cTupleNum;
						CStrInsert += ")";

						int iSqlLen = CStrInsert.GetLength();

						char * szSqlInsert = new char [iSqlLen + 1];
						strcpy(szSqlInsert , "");
						strcat(szSqlInsert , CStrInsert);
							
						retcode = SQLExecDirect(hstmt_Generet2DWorkload, (unsigned char *)szSqlInsert, SQL_NTS);


						if (retcode == SQL_SUCCESS) 
						{  //	retcode = SQLExecDirect
							//AfxMessageBox("Insert new Recode Seccess!");
							//bReturn = TRUE;
							iTotalNum ++;
						}
						else
						{
						//	AfxMessageBox("Insert new Recode Error!");
							iErr++;

						} //	retcode = SQLExecDirect 
					
						CStrInsert = "";
						delete [] szSqlInsert; 

						iStartRowNum = iRowCount;
						iSampleNum += iSpan ;
					} 
					else 
					{
						break;
					}

					if(iTotalNum >=100)
						break;


				}   ///while (TRUE)

						
					

						delete [] pAge;//new float[10]
						delete [] pIncome;//new float[10]

			}//	retcode = SQLExecDirect



		//111111111111111111 read data base end111111111111


		}


	SQLFreeStmt(hstmt, SQL_DROP);
	SQLFreeStmt(hstmt_Generet2DWorkload, SQL_DROP);
//	zlCloseDB();

	AfxMessageBox("Insert DATA_Census2Dg_B_workload OK!");
	
}

void CMainFrame::OnGauss2Dworkload() 
{

	//create sample of profiles
	//Menu :Generator- Gauss2DWorkLoad
    // 2005.4.6 USE IT

	int i,iErr = 0;
	char tmp[100] = "";
	CString CStrInsert = ""; 
	
	SWORD  sAge;
	SDWORD cbAge;

	SDWORD sIncome;
	SDWORD cbIncome;
	
	//int iSizeSmpl = 1459; //250; // 200;//400; //800; //1000; //2000; 
						 ////||||100, 200, 400, 800, 1000,2000. 
						  // size of census2Dg = 145,917; CLMB_census = 210,138.
						  // Date 2003.3.24

	int iSizeSmpl = 178; //730; //365; 

	//int iSizeSmpl = 80; //20; //for having same queries 20%, 50%, 80%.
	//int iSizeSmpl = 50; //50; //for having same queries 20%, 50%, 80%.
	//int iSizeSmpl = 20;//80; //for having same queries 20%, 50%, 80%.

	HSTMT   hstmt_Generet2DWorkload;

	srand( (unsigned)time( NULL ) );


		if(!zlOpenDB())
		{
			AfxMessageBox("zlOpenDB() err!");
			zlCloseDB();
		}else
		{
			retcode = SQLAllocStmt(hdbc, &hstmt_Generet2DWorkload); ///Statement handle 

			//lStartTimer = GetTickCount();

			//UCHAR szSqlAllRows[] = "SELECT * FROM Gauss2Dg"; //discounts, authors, Census2DTable						
			//UCHAR szSqlAllRows[] = "SELECT * FROM Census2Dg"; //discounts, authors, Census2DTable						
			UCHAR szSqlAllRows[] = "SELECT * FROM CLMB_Census2D"; //discounts, authors, Census2DTable						
		
			//UCHAR szSqlAllRows[] = "SELECT * FROM Census2D_smpl0178"; //take x% from it 
			//UCHAR szSqlAllRows[] = "SELECT * FROM DATA_Census2Dg_B_workload"; //take (100-x)% from it 
		
			

			SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
			SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
			retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);

			//lEndTimer = GetTickCount() - lStartTimer;
			//wsprintf(tmp, "%ld", lEndTimer);

			//1111111111111 read data base 111111111111111

			if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO ) 
			{    //	retcode = SQLExecDirect
				int iRowCount, iTupleNum, iSpan, iSampleNum, iStartRowNum, iTotalNum;
				SDWORD *  RowCountPtr = new SDWORD ;
				retcode = SQLRowCount(hstmt, RowCountPtr);						 
				iRowCount = * RowCountPtr;
				iTupleNum = iRowCount;
				iSpan = (int) (iRowCount/iSizeSmpl);
				iSampleNum = 1;
				delete RowCountPtr;
				
				// Bind columns 1,2.
				SQLBindCol(hstmt, 1, SQL_C_SSHORT, &sAge, 0, &cbAge);
				SQLBindCol(hstmt, 2, SQL_C_SLONG, &sIncome,0, &cbIncome); //SQL_C_SSHORT

				int * pAge = new  int[iRowCount];//new float[10]
				int * pIncome = new  int[iRowCount];//new float[10]

				iRowCount = 0;
				iStartRowNum = 0;
				iTotalNum = 0;
				while (TRUE) 
				{
					
						//int iRandom = rand()%(iSpan-1);
						int iRandom= 0;
						if (iSpan == 1)
							iRandom = 1;
						else 
						{
							iRandom = rand()%(iSpan-1);
						}
						for (i = iStartRowNum; i < iSampleNum + iRandom; i++)
						{
					      retcode = SQLFetch(hstmt);
						  iRowCount ++ ; 
						}

					if (retcode == SQL_ERROR)
					{
						//show_error();

						wsprintf(tmp, "%ld", iRowCount);
						//int i = iRowCount;
						AfxMessageBox("SQLFetch Error !!!!!!");
								//break; //99.8.26
					}

					if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO ||iRowCount>= iSampleNum)
							//if (retcode == SQL_SUCCESS)
					{	

						char cAge[20] = "", cIncome[20] = "", cTupleNum[20] ="";

						if(sAge <0)
							int ieie=0;

						sprintf(cAge,"%d",sAge);
						sprintf(cIncome,"%ld",sIncome);
						sprintf(cTupleNum,"%ld",iRowCount);

						
						//CStrInsert += " INSERT DATA_Gauss2Dg_workload VALUES( ";	
						//CStrInsert += " INSERT smpl2000_Census2D VALUES( ";
						//CStrInsert += " INSERT smpl1000_Census2D VALUES( ";
						//CStrInsert += " INSERT smpl0800_Census2D VALUES( ";
						//CStrInsert += " INSERT smpl0400_Census2D VALUES( ";
						//CStrInsert += " INSERT smpl0200_Census2D VALUES( ";
						//CStrInsert += " INSERT smpl0100_Census2D VALUES( ";
						//CStrInsert += " INSERT smpl0250_Census2D VALUES( ";
						//CStrInsert += " INSERT smpl1459_Census2D VALUES( ";
						
						//CStrInsert += " INSERT smpl0730_Census2D VALUES( ";
						//CStrInsert += " INSERT smpl0365_Census2D VALUES( ";
						CStrInsert += " INSERT Census2D_smpl0178 VALUES( ";
						
						//CStrInsert += " INSERT Census2D_20PC_workload VALUES( ";
						//CStrInsert += " INSERT Census2D_50PC_workload VALUES( ";
						//CStrInsert += " INSERT Census2D_80PC_workload VALUES( ";
			
						CStrInsert += cAge;
						CStrInsert += ",";
						CStrInsert += cIncome;
						//CStrInsert += ",";
						//CStrInsert += cTupleNum;
						CStrInsert += ")";

						int iSqlLen = CStrInsert.GetLength();

						char * szSqlInsert = new char [iSqlLen + 1];
						strcpy(szSqlInsert , "");
						strcat(szSqlInsert , CStrInsert);
							
						retcode = SQLExecDirect(hstmt_Generet2DWorkload, (unsigned char *)szSqlInsert, SQL_NTS);


						if (retcode == SQL_SUCCESS) 
						{  //	retcode = SQLExecDirect
							//AfxMessageBox("Insert new Recode Seccess!");
							//bReturn = TRUE;
							iTotalNum ++;
						}
						else
						{
						//	AfxMessageBox("Insert new Recode Error!");
							iErr++;

						} //	retcode = SQLExecDirect 
					
						CStrInsert = "";
						delete [] szSqlInsert; 

						iStartRowNum = iRowCount;
						iSampleNum += iSpan ;
					} 
					else 
					{
						break;
					}

					if(iTotalNum >=iSizeSmpl)
						break;


				}   ///while (TRUE)			
					
						delete [] pAge;//new float[10]
						delete [] pIncome;//new float[10]

			}//	retcode = SQLExecDirect



		//111111111111111111 read data base end111111111111


		}


	SQLFreeStmt(hstmt, SQL_DROP);
	SQLFreeStmt(hstmt_Generet2DWorkload, SQL_DROP);
	zlCloseDB();

	AfxMessageBox("Insert hstmt_Generet2DWorkload OK!");

	
}

void CMainFrame::OnTop100census2dwl() 
{
	int i,iErr = 0;
	char tmp[100] = "";
	CString CStrInsert = ""; 
	
	SWORD  sAge;
	SDWORD cbAge;

	SDWORD sIncome;
	SDWORD cbIncome;


	HSTMT   hstmt_Generet2DWorkload;

	srand( (unsigned)time( NULL ) );


		if(!zlOpenDB())
		{
			AfxMessageBox("zlOpenDB() err!");
			zlCloseDB();
		}else
		{
			retcode = SQLAllocStmt(hdbc, &hstmt_Generet2DWorkload); ///Statement handle 

			//lStartTimer = GetTickCount();

			UCHAR szSqlAllRows[] = "SELECT * FROM census2Dg"; //discounts, authors, Census2DTable						
			SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
			SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
			retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);

			//lEndTimer = GetTickCount() - lStartTimer;
			//wsprintf(tmp, "%ld", lEndTimer);

			//1111111111111 read data base 111111111111111

			if (retcode == SQL_SUCCESS) 
			{    //	retcode = SQLExecDirect
				int iRowCount, iTupleNum, iSpan, iSampleNum, iStartRowNum, iTotalNum;
				SDWORD *  RowCountPtr = new SDWORD ;
				retcode = SQLRowCount(hstmt, RowCountPtr);						 
				iRowCount = * RowCountPtr;
				iTupleNum = iRowCount;
				iSpan = (int) (iRowCount/100);
				iSampleNum =0;
				delete RowCountPtr;
				
				// Bind columns 1,2.
				SQLBindCol(hstmt, 1, SQL_C_SSHORT, &sAge, 0, &cbAge);
				SQLBindCol(hstmt, 2, SQL_C_SLONG, &sIncome,0, &cbIncome); //SQL_C_SSHORT

				int * pAge = new  int[iRowCount];//new float[10]
				int * pIncome = new  int[iRowCount];//new float[10]

				iRowCount = 0;
				iStartRowNum = 0;
				iTotalNum = 0;
				while (TRUE) 
				{
					
						int iRandom = rand()%100;
						for (i = iStartRowNum; i < iSampleNum + iRandom; i++)
						{
					      retcode = SQLFetch(hstmt);
						  iRowCount ++ ; 
						}

					if (retcode == SQL_ERROR)
					{
						//show_error();

						wsprintf(tmp, "%ld", iRowCount);
						//int i = iRowCount;
						AfxMessageBox("SQLFetch Error !!!!!!");
								//break; //99.8.26
					}

					if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO ||iRowCount>= iSampleNum)
							//if (retcode == SQL_SUCCESS)
					{	

						char cAge[20] = "", cIncome[20] = "", cTupleNum[20] ="";

						sprintf(cAge,"%d",sAge);
						sprintf(cIncome,"%ld",sIncome);
						sprintf(cTupleNum,"%ld",iRowCount);

						
						CStrInsert += " INSERT DATA_Top100_Census2D_WorkLoad VALUES( ";	
						CStrInsert += cAge;
						CStrInsert += ",";
						CStrInsert += cIncome;
						//CStrInsert += ",";
						//CStrInsert += cTupleNum;
						CStrInsert += ")";

						int iSqlLen = CStrInsert.GetLength();

						char * szSqlInsert = new char [iSqlLen + 1];
						strcpy(szSqlInsert , "");
						strcat(szSqlInsert , CStrInsert);
							
						retcode = SQLExecDirect(hstmt_Generet2DWorkload, (unsigned char *)szSqlInsert, SQL_NTS);


						if (retcode == SQL_SUCCESS) 
						{  //	retcode = SQLExecDirect
							//AfxMessageBox("Insert new Recode Seccess!");
							//bReturn = TRUE;
							iTotalNum ++;
						}
						else
						{
						//	AfxMessageBox("Insert new Recode Error!");
							iErr++;

						} //	retcode = SQLExecDirect 
					
						CStrInsert = "";
						delete [] szSqlInsert; 

						iStartRowNum = iRowCount;
						iSampleNum += iSpan ;
					} 
					else 
					{
						break;
					}

					if(iTotalNum >=100)
						break;


				}   ///while (TRUE)

						
					

						delete [] pAge;//new float[10]
						delete [] pIncome;//new float[10]

			}//	retcode = SQLExecDirect



		//111111111111111111 read data base end111111111111


		}


	SQLFreeStmt(hstmt, SQL_DROP);
	SQLFreeStmt(hstmt_Generet2DWorkload, SQL_DROP);
	zlCloseDB();

	AfxMessageBox("Insert hstmt_Generet2DWorkload OK!");
	
}


void CMainFrame::OnViewTest() 
{

}


void CMainFrame::OnDataTop100Census2dWorkloadProfile() 
{
	// select * from DATA_Top100_Census2D_WorkLoad	
	/*********************		
	Age	int NOT NULL,
	Income 	int Not NULL,
	N	int Not NULL,
	r	float Not NULL,
	f	int Not NULL,
	c	int Not NULL,
	d	int Not NULL,
	***************************/
	
/*****************************
* 1. read all tuples from census2Dg store a buffer
* 2. Read all tuple from DATA_Top100_Census2D_WorkLoad 
* 3. evaluate r, f, c, -d,
* 4. insert zeta into DATA_Top100_Census2D_Profile
******************************/

	int N, f, c, d; 

	int i,j, k, iErr = 0;
	char tmp[100] = "";
	CString CStrSelect = ""; 
	CString CStrInsert = "";

	int longTicks =0, shortTicks =0;
	
	SWORD  sAge;
	SDWORD cbAge;

	SDWORD sIncome;
	SDWORD cbIncome;


	HSTMT   hstmt_Census2D_WorkLoad; //for queries workload
	HSTMT   hstmt_Census2D_Profile;  //for insert Profile

	int iTupleNum;//,iStartRowNum, iTotalNum;

	int * q1, *q2, *q1Hold, *q2Hold;
	
	float rd, dis[100], r[100]; 
	int tuple1[100],tuple2[100];
	

//struct_Census2D_Tuple


	if(!zlOpenDB())
	{
		AfxMessageBox("zlOpenDB() err!");
		zlCloseDB();
	}else
	{
		retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_WorkLoad); ///queries Statement handle 
		retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_Profile); /// Profile Statement handle 

		//1. read all tuples from census2Dg store a buffer
		//1111111111111 read data base from census2Dg 111111111111111	

		//UCHAR szSqlAllRows[] = "select  * from census2dg where (15 - 9 <=age and age<=15+ 9 ) and (15- 9 <=Income and Income <=15+ 9 )";
		
		//----------------------------------------------------
		//UCHAR szSqlAllRows[] = "SELECT * FROM census2Dg"; //discounts, authors, Census2DTable						
		UCHAR szSqlAllRows[] = "SELECT * FROM CLMB_census2D"; //discounts, authors, Census2DTable						

		//------------------------------------------------------


		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		
		longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);
		longTicks = GetTickCount() - longTicks;

		//lEndTimer = GetTickCount() - lStartTimer;
		//wsprintf(tmp, "%ld", lEndTimer);


		if (retcode == SQL_SUCCESS) 
		{    //	retcode = SQLExecDirect for census2Dg
			int iRowCount;
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt, RowCountPtr);						 
			iRowCount = * RowCountPtr;
			iTupleNum = iRowCount;
			delete RowCountPtr;
			
			// Bind columns 1,2.
			SQLBindCol(hstmt, 1, SQL_C_SSHORT, &sAge, 0, &cbAge);
			SQLBindCol(hstmt, 2, SQL_C_SLONG, &sIncome,0, &cbIncome); //SQL_C_SSHORT

			pAge = new  int[iRowCount];//buffer, new float[10]
			pIncome = new  int[iRowCount];//buffer , new float[10]
			pAgeHold = pAge;
			pIncomeHold = pIncome;
			iRowCount =0;
			while (TRUE) 
			{
				retcode = SQLFetch(hstmt);

				if (retcode == SQL_ERROR)
				{
					//show_error();

					wsprintf(tmp, "%ld", iRowCount);
					//int i = iRowCount;
					AfxMessageBox("SQLFetch Error !!!!!!");
							//break; //99.8.26
				}

				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
						//if (retcode == SQL_SUCCESS)
				{	

					*pAge		= sAge;
					*pIncome	= sIncome;

					pAge++;
					pIncome++;

					if(retcode == SQL_SUCCESS_WITH_INFO)
					{
						wsprintf(tmp, "%ld", retcode);
						AfxMessageBox(tmp);

					}
						
				} 
				else 
				{
					break;
				}

			}   ///while (TRUE)

			pAge = pAgeHold ;
			pIncome = pIncomeHold ;
	
		}//	retcode = SQLExecDirect  for census2Dg

	//111111111111111111 read data base  census2Dg end   111111111111

	//2. Read all tuple from DATA_Top100_Census2D_WorkLoad
		sAge = 0;cbAge = 0;sIncome = 0;cbIncome= 0;

		UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Top100_Census2D_WorkLoad"; //discounts, authors, Census2DTable						
		
		SQLSetStmtOption(hstmt_Census2D_WorkLoad, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt_Census2D_WorkLoad, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		retcode = SQLExecDirect(hstmt_Census2D_WorkLoad, szSqlAllQueryRows, SQL_NTS);

		//lEndTimer = GetTickCount() - lStartTimer;
		//wsprintf(tmp, "%ld", lEndTimer);


		if (retcode == SQL_SUCCESS) 
		{    //	retcode = SQLExecDirect for census2Dg
			int iRowCount;
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt_Census2D_WorkLoad, RowCountPtr);						 
			iRowCount = * RowCountPtr;
			delete RowCountPtr;
			
			// Bind columns 1,2.
			SQLBindCol(hstmt_Census2D_WorkLoad, 1, SQL_C_SSHORT, &sAge, 0, &cbAge);
			SQLBindCol(hstmt_Census2D_WorkLoad, 2, SQL_C_SLONG, &sIncome,0, &cbIncome); //SQL_C_SSHORT

			q1 = new  int[iRowCount];//buffer, new float[10]
			q2 = new  int[iRowCount];//buffer , new float[10]
			q1Hold = q1; q2Hold= q2;
			

			while (TRUE) 
			{
				retcode = SQLFetch(hstmt_Census2D_WorkLoad);

				if (retcode == SQL_ERROR)
				{
					//show_error();

					wsprintf(tmp, "%ld", iRowCount);
					//int i = iRowCount;
					AfxMessageBox("SQLFetch Error !!!!!!");
							//break; //99.8.26
				}

				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
						//if (retcode == SQL_SUCCESS)
				{	
					*q1	= sAge;
					*q2	= sIncome;

					q1++;
					q2++;
				} 
				else 
				{
					break;
				}

			}   ///while (TRUE)
			
			q1= q1Hold; q2= q2Hold;
				
		}//	retcode = SQLExecDirect  for query q1,q2.
	
	//3. evaluate r, f, -c, -d,

		float ftmp=0;
		int itmp = 0,qnum =0; 
		int topt1[100],topt2[100];


		do
		{
			for(i = 0; i<100; i++)
			{
			  dis[i] = (float)max( abs(pAge[i]- q1[qnum]), abs(pIncome[i]-q2[qnum]) );
			  tuple1[i] = pAge[i];
			  tuple2[i] = pIncome[i];
			}
			i=0;
			
			for(i=0; i<100; i++)
			{
				r[i] = dis[i];
				topt1[i] = tuple1[i] ; topt2[i]=tuple2[i] ;
				for( j= i+1; j<100; j++)
				{
					if(dis[j] < r[i]) 
					{ ftmp = r[i];    r[i] = dis[j];  dis[j] = ftmp;
					  itmp = topt1[i]; topt1[i]= tuple1[j]; tuple1[j]= itmp;
					  itmp = topt2[i]; topt2[i]= tuple2[j]; tuple2[j]= itmp;
					}
				}
			}
			
			i=0;
			for(i=100; i<iTupleNum; i++)
			{
				ftmp = (float)max( abs(pAge[i]- q1[qnum]), abs(pIncome[i]-q2[qnum]) );
				if(ftmp < r[99])
				{
					for(j=0;j<100;j++)
					{
						if(ftmp<r[j])
						{
							for(k=99; k>j; k--)
							{
								r[k] = r[k-1];
								topt1[k] = topt1[k-1];
								topt2[k] = topt2[k-1];
							}
							r[j]=ftmp;
							topt1[j] = pAge[i];
							topt2[j] = pIncome[i];
							break;
						}
					}
				}
			}
		
		//int N, rd,f, c, d; 	
			
//////////////////
		SQLFreeStmt(hstmt, SQL_DROP);
		retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 

		Sleep(100);
		
		//UCHAR szSqlAllRows[] = "SELECT * FROM census2Dg"; //discounts, authors, Census2DTable						
		UCHAR szSqlAllRows[] = "SELECT * FROM CLMB_census2D"; //discounts, authors, Census2DTable						

		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		
		longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);
		longTicks = GetTickCount() - longTicks;

//////////////////////////
			
			
			
			
			
			
			CTime CurTime = CTime::GetCurrentTime();         

			N = 100; rd = r[99]; c = -1; d = - CurTime.GetTime();
			


			char cAgeLeft[20] = "", cAgeRight[20] = "", cIncomeLeft[20] = "", cIncomeRight[20] ="";
			
			sprintf(cAgeLeft,"%f", (float)(q1[qnum] - rd) );
			sprintf(cAgeRight,"%f", (float)(q1[qnum] + rd));
			sprintf(cIncomeLeft,"%f", (float)(q2[qnum] - rd));
			sprintf(cIncomeRight,"%f",(float)(q2[qnum] + rd));

			//CStrSelect += "select  * from census2dg where (";
			CStrSelect += "select  * from CLMB_census2D where (";
			
			CStrSelect += cAgeLeft;
			CStrSelect += "<= age AND age <=";
			CStrSelect += cAgeRight;
			CStrSelect += ") AND (";
			CStrSelect += cIncomeLeft;
			CStrSelect += "<= Income AND Income <=";
			CStrSelect += cIncomeRight;
			CStrSelect += ")"; 

			int iSqlLen = CStrSelect.GetLength();
			char * szSqlSquareRows = new char [iSqlLen + 1];	
			strcpy(szSqlSquareRows , "");
			strcat(szSqlSquareRows , CStrSelect);
	
			SQLFreeStmt(hstmt, SQL_DROP);
			retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 
			Sleep(2000);


			//szSqlSquareRows= "select  * from census2dg where ";// (15 - 9 <=age and age<=15+ 9 ) and (15- 9 <=Income and Income <=15+ 9 )";
			SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
			SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
			
			shortTicks = GetTickCount();
			retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlSquareRows, SQL_NTS);
			shortTicks = GetTickCount() - shortTicks;

			//lEndTimer = GetTickCount() - lStartTimer;
			//wsprintf(tmp, "%ld", lEndTimer);

			if (retcode == SQL_SUCCESS) 
			{    //	retcode = SQLExecDirect for census2Dg
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt, RowCountPtr);						 
			f = * RowCountPtr;
			delete RowCountPtr;

			}
			CStrSelect = "";
			delete [] szSqlSquareRows;

	//4. insert zeta into DATA_Top100_Census2D_Profile
		
			if (f!= 0)
			{   
				char	cAttribute[10][50]= { "","","","","","","","","",""};

				
				sprintf(cAttribute[0],"%ld", q1[qnum] );
				sprintf(cAttribute[1],"%ld", q2[qnum] );
				sprintf(cAttribute[2],"%ld", N);
				sprintf(cAttribute[3],"%f",  (float)rd);
				sprintf(cAttribute[4],"%ld", f );
				sprintf(cAttribute[5],"%ld", c );
				sprintf(cAttribute[6],"%ld", d);
				sprintf(cAttribute[7],"%ld", longTicks);
				sprintf(cAttribute[8],"%ld", shortTicks);

				//---------tables---------------
				//CStrInsert += " INSERT DATA_Top100_Census2D_Profile VALUES( ";	
				CStrInsert += " INSERT Top100_Census2D_Profile VALUES( ";	

				CStrInsert += cAttribute[0];
				CStrInsert += ",";
				CStrInsert += cAttribute[1];
				CStrInsert += ",";
				CStrInsert += cAttribute[2];
				CStrInsert += ",";
				CStrInsert += cAttribute[3];
				CStrInsert += ",";
				CStrInsert += cAttribute[4];
				CStrInsert += ",";
				CStrInsert += cAttribute[5];
				CStrInsert += ",";
				CStrInsert += cAttribute[6];
				CStrInsert += ",";
				CStrInsert += cAttribute[7];
				CStrInsert += ",";
				CStrInsert += cAttribute[8];
				CStrInsert += ")";


			    int iSqlLen = CStrInsert.GetLength();

				char * szSqlInsert = new char [iSqlLen + 1];
				strcpy(szSqlInsert , "");
				strcat(szSqlInsert , CStrInsert);

				SQLFreeStmt(hstmt_Census2D_Profile, SQL_DROP);
				retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_Profile); /// Profile Statement handle 

				retcode = SQLExecDirect(hstmt_Census2D_Profile, (unsigned char *)szSqlInsert, SQL_NTS);

				if (retcode == SQL_SUCCESS) 
				{  //	retcode = SQLExecDirect
					//AfxMessageBox("Insert new hstmt_Census2D_Profile  OKKKKKKKKKKK!");
					Sleep(300);
						//bReturn = TRUE;
				}
				else
				{
					AfxMessageBox("Insert hstmt_Census2D_Profile Error!");

					i= 0;


				} //	retcode = SQLExecDirect 
				
				f=0;

				CStrInsert = "";
				delete [] szSqlInsert;
			}
		

			qnum++;
		}while(qnum <100); //100);

	}//if(!zlOpenDB())



	delete [] pAge;//new float[10]
	delete [] pIncome;//new float[10]
	delete [] q1;//new float[10]
	delete [] q2;//new float[10]


	SQLFreeStmt(hstmt, SQL_DROP);
	SQLFreeStmt(hstmt_Census2D_WorkLoad, SQL_DROP);
	SQLFreeStmt(hstmt_Census2D_Profile, SQL_DROP);

	zlCloseDB();

	AfxMessageBox("Insert hstmt_Generet2DWorkload OK!");


}

void CMainFrame::OnLearning_Census2D_Biased() 
{
	/////////////////////////////////////////////////////
	// learning from Profile100
	//
	// --Read: DATA_Top100_Census2D_Profile, as Profile
	// Read:  Top100_Census2D_Profile, as Profile
	// Read: DATA_Census2Dg_B_workload, as Biased Query workload
	// write:DATA_Top100_Census2D_Learning
	// Top100, distance = max,Type = Biased 
	/////////////////////////////////////////////////////
	int N, f, c, d; 

	int i,j, iErr = 0;
	char tmp[100] = "";
	CString CStrSelect = ""; 
	CString CStrInsert = "";

	int longTicks =0, shortTicks =0;
	
	SWORD  sAge;
	SDWORD cbAge;

	SDWORD sIncome;
	SDWORD cbIncome;
	SDWORD sN,sr,sf,sc,sd;
	SDWORD cbN,cbr,cbf,cbc,cbd;


	HSTMT   hstmt_Census2D_WorkLoad; //for queries workload
	HSTMT   hstmt_Census2D_Profile;  //for insert Profile

	//int iTupleNum;//,iStartRowNum, iTotalNum;

	int * q1, *q2, *q1Hold, *q2Hold; //for queries workload
	
	//float rd, dis[100], r[100]; 
	//int tuple1[100],tuple2[100];
	
	float rd, dis[2000], r[2000]; 
	int tuple1[2000],tuple2[2000];

	int iSizeProfile = 2000;

//struct_Census2D_Tuple


	if(!zlOpenDB())
	{
		AfxMessageBox("zlOpenDB() err!");
		zlCloseDB();
	}else
	{
		retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_WorkLoad); ///queries Statement handle 
		retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_Profile); /// Profile Statement handle 

		//1. read all tuples from Profile set store a buffer
		//1111111111111 read database from DATA_Top100_Census2D_Profile 111111111111111	
		
		//---------------
		//UCHAR szSqlAllRows[] = "SELECT * FROM DATA_Top100_Census2D_Profile"; //discounts, authors, Census2DTable						
		UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile"; //discounts, authors, Census2DTable						

		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		
		//longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);
		//longTicks = GetTickCount() - longTicks;

		//lEndTimer = GetTickCount() - lStartTimer;
		//wsprintf(tmp, "%ld", lEndTimer);


		if (retcode == SQL_SUCCESS) 
		{    //	retcode = SQLExecDirect for DATA_Top100_Census2D_Profile
			int iRowCount;
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt, RowCountPtr);						 
			iRowCount = * RowCountPtr;
			// iTupleNum = iRowCount; // here only size of profile, 100,200, ...,2000
			delete RowCountPtr;
			
			// Bind columns 1,2.
			SQLBindCol(hstmt, 1, SQL_C_SSHORT, &sAge, 0, &cbAge);
			SQLBindCol(hstmt, 2, SQL_C_SLONG, &sIncome,0, &cbIncome); //SQL_C_SSHORT
			SQLBindCol(hstmt, 3, SQL_C_SLONG, &sN,0, &cbN); //SQL_C_SSHORT
			SQLBindCol(hstmt, 4, SQL_C_SLONG, &sr,0, &cbr); //SQL_C_SSHORT
			SQLBindCol(hstmt, 5, SQL_C_SLONG, &sf,0, &cbf); //SQL_C_SSHORT
			SQLBindCol(hstmt, 6, SQL_C_SLONG, &sc,0, &cbc); //SQL_C_SSHORT
			SQLBindCol(hstmt, 7, SQL_C_SLONG, &sd,0, &cbd); //SQL_C_SSHORT

			pPf = new Profile2D[iRowCount];
			pPfHold = pPf;

			pAge = new  int[iRowCount];//buffer, new float[10]
			pIncome = new  int[iRowCount];//buffer , new float[10]
			pAgeHold = pAge;
			pIncomeHold = pIncome;
			iRowCount =0;
			while (TRUE) 
			{
				retcode = SQLFetch(hstmt);

				if (retcode == SQL_ERROR)
				{
					//show_error();
					wsprintf(tmp, "%ld", iRowCount);
					//int i = iRowCount;
					AfxMessageBox("SQLFetch Error !!!!!!");
							//break; //99.8.26
				}

				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
				{	
					*pAge		= sAge;
					*pIncome	= sIncome;
					
					pPf->q[0]	= sAge;				
					pPf->q[1]	= sIncome;
					pPf->N		= sN;
					pPf->r		= (float) sr;
					pPf->f		= sf;
					pPf->c		= sc;
					pPf->d		= sd;

					pAge++;
					pIncome++;

					pPf++;

					if(retcode == SQL_SUCCESS_WITH_INFO)
					{
						wsprintf(tmp, "%ld", retcode);
						AfxMessageBox(tmp);
					}
						
				} 
				else 
				{
					break;
				}

			}   ///while (TRUE)

			pAge = pAgeHold ;
			pIncome = pIncomeHold ;
			pPf	= pPfHold;
		}//	retcode = SQLExecDirect  for DATA_Top100_Census2D_Profile

	//111111111111111111 read data base  DATA_Top100_Census2D_Profile end   111111111111

	//2. Read all Queries from DATA_Census2Dg_B_workload
		sAge = 0;cbAge = 0;sIncome = 0;cbIncome= 0;

		UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Census2Dg_B_workload"; //discounts, authors, Census2DTable						
		
		SQLSetStmtOption(hstmt_Census2D_WorkLoad, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt_Census2D_WorkLoad, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		retcode = SQLExecDirect(hstmt_Census2D_WorkLoad, szSqlAllQueryRows, SQL_NTS);

		//lEndTimer = GetTickCount() - lStartTimer;
		//wsprintf(tmp, "%ld", lEndTimer);


		if (retcode == SQL_SUCCESS) 
		{    //	retcode = SQLExecDirect for census2Dg
			int iRowCount;
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt_Census2D_WorkLoad, RowCountPtr);						 
			iRowCount = * RowCountPtr;
			delete RowCountPtr;
			
			// Bind columns 1,2.
			SQLBindCol(hstmt_Census2D_WorkLoad, 1, SQL_C_SSHORT, &sAge, 0, &cbAge);
			SQLBindCol(hstmt_Census2D_WorkLoad, 2, SQL_C_SLONG, &sIncome,0, &cbIncome); //SQL_C_SSHORT

			q1 = new  int[iRowCount];//buffer, new float[10]
			q2 = new  int[iRowCount];//buffer , new float[10]
			q1Hold = q1; q2Hold= q2;
			

			while (TRUE) 
			{
				retcode = SQLFetch(hstmt_Census2D_WorkLoad);
				if (retcode == SQL_ERROR)
				{
					//show_error();
					wsprintf(tmp, "%ld", iRowCount);
					//int i = iRowCount;
					AfxMessageBox("SQLFetch Error !!!!!!");
							//break; //99.8.26
				}
				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
				{	
					*q1	= sAge;
					*q2	= sIncome;

					q1++;
					q2++;
				} 
				else 
				{
					break;
				}

			}   ///while (TRUE)
			
			q1= q1Hold; q2= q2Hold;
				
		}//	retcode = SQLExecDirect  for query q1,q2.
	
	
	//3. evaluate r, f, -c, -d,

		float ftmp=0;
		int itmp = 0,qnum =0; 
		int topt1[100],topt2[100];
		float rr[100],rOrder[100];

		do
		{
			////////////for each query find the closed profiles
			//evaluate all distance from New_query(q1[qnum],q2[qnum]) to Profile Point (pAge[i],pIncome[i] )
			// dis[i] = d(Q,Q')
			for(i = 0; i<100; i++)
			{
			  dis[i] = (float)max( abs(pAge[i]- q1[qnum]), abs(pIncome[i]-q2[qnum]) ); 
		  
			  tuple1[i] = pAge[i];
			  tuple2[i] = pIncome[i];
			  rr[i] = pPf[i].r;  //best search radius in Profile
			}

			i=0;

			//order all distance
			// r[i]'s are sorting d(Q,Q'), to ifentify the closest Q' to Q
			for(i=0; i<100; i++)
			{
				r[i] = dis[i];  //d(Q,Q')
				topt1[i] = tuple1[i] ; topt2[i]=tuple2[i] ; //profile points
				rOrder[i] = rr[i];  //radius order
				for( j= i+1; j<100; j++)
				{
					if(dis[j] < r[i]) 
					{ ftmp = r[i];			r[i] = dis[j];		 dis[j] = ftmp;
					  ftmp = rOrder[i];		rOrder[i] = rr[j];	 rr[j] = ftmp;
					  itmp = topt1[i];		topt1[i]= tuple1[j]; tuple1[j]= itmp;
					  itmp = topt2[i];		topt2[i]= tuple2[j]; tuple2[j]= itmp;
					}
				}
			}
					
		//int N, rd,f, c, d; 
		//evaluate search distance
		
		int qp1 = topt1[0], qp2= topt2[0]; //Q'(qp1,qp2), the closest proples to Q(q1,q2)
		if(r[0] == 0) // if Q=Q'
		{//if(r[0] == 0)
			rd = rOrder[0];
			int itest = 0; //use to test 
		}
		else
		{
			int dmaxQQp = max(  abs( qp1 - q1[qnum]), abs(qp2 - q2[qnum])  ); //i.e.r[0]
			if(dmaxQQp <= rOrder[0])  //case of Fig.3 //rou = N/4*r*r
			{
				float dQQ[100],rpf[100];
				
				int iKnum = 0;
				float frou[100],l[100],V[100], lV=0, lVrou =0, rou = 0;

				for(j=0; j<100; j++)
				{
					frou[j] =0;l[j] =0;V[j] = 0;
					dQQ[100] =0;rpf[j] = 0;			
				}

				for(j=0; j<100; j++)
				{
					if( r[j] <= rOrder[j]  ) //d(Q,Qpf) < rpf
					{
						dQQ[j] = r[j];
						rpf[j] = rOrder[j];
						iKnum++;

					}
						
				}

				for(j=0; j<iKnum; j++)
				{
					frou[j] = 25/(rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
					l[j] = 1/dQQ[j];
					V[j] = 4*rpf[j]*rpf[j];
					lV += l[j]*V[j]; 
					lVrou += 100*l[j];  //l[j]*V[j]*frou[j];

				}

				rou = lVrou/lV;

				rd = (float)sqrt(100/rou)/2; //sqrt( double x );
			
				if (rd > dmaxQQp + rOrder[0])
					rd = dmaxQQp + rOrder[0];


				int iMeadian = iKnum/2;
				//rd = rOrder[iMeadian];

			}else
			{
				int dmaxQQp = max(  abs( qp1 - q1[qnum]), abs(qp2 - q2[qnum])  );
				if(dmaxQQp <= 2*rOrder[0])  //h<2r'
				{
					//case of Fig.4 //rou = N/4*r*r
					
					float dQQ[100],rpf[100];
					
					int iKnum = 0;
					float frou[100],l[100],V[100], lV=0, lVrou =0, rou = 0;

					for(j=0; j<100; j++)
					{
						frou[j] =0;l[j] =0;V[j] = 0;
						dQQ[100] =0;rpf[j] = 0;			
					}

				
					for(j=0; j<100; j++)
					{
						if(r[j] < rOrder[0] + dmaxQQp)
						{
							dQQ[j] = r[j];
							rpf[j] = rOrder[j];
							iKnum++;
						}						
					}

					for(j=0; j<iKnum; j++)
					{
						frou[j] = 25/(rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
						l[j] = 1/dQQ[j];
						V[j] = 4*rpf[j]*rpf[j];
						lV += l[j]*V[j]; 
						lVrou += 100*l[j];  //l[j]*V[j]*frou[j];

					}

					rou = lVrou/lV;

					rd = (float)sqrt(100/rou)/2; //sqrt( double x );
					if (rd > dmaxQQp + rOrder[0])
						rd = dmaxQQp + rOrder[0];
					int ite = 0;
				}else{

					rd = dmaxQQp + rOrder[0];

				}//if(dmaxQQp <= 2*rOrder[0])

			}//if(dmaxQQp <= rOrder[0])


		}//if(r[0] == 0)
			
//////////////////
		SQLFreeStmt(hstmt, SQL_DROP);
		retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 

		Sleep(100);
		//UCHAR szSqlAllRows[] = "SELECT * FROM census2Dg"; //discounts, authors, Census2DTable						
		UCHAR szSqlAllRows[] = "SELECT * FROM CLMB_census2D"; //discounts, authors, Census2DTable						

		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		
		longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);
		longTicks = GetTickCount() - longTicks;

//////////////////////////


			
			CTime CurTime = CTime::GetCurrentTime();         

			N = 100; c = -1; d = - CurTime.GetTime();
			


			char cAgeLeft[20] = "", cAgeRight[20] = "", cIncomeLeft[20] = "", cIncomeRight[20] ="";
			
			sprintf(cAgeLeft,"%f", (float)(q1[qnum] - rd) );
			sprintf(cAgeRight,"%f", (float)(q1[qnum] + rd));
			sprintf(cIncomeLeft,"%f", (float)(q2[qnum] - rd));
			sprintf(cIncomeRight,"%f",(float)(q2[qnum] + rd));

			CStrSelect += "select  * from CLMB_census2d where (";
			CStrSelect += cAgeLeft;
			CStrSelect += "<= age AND age <=";
			CStrSelect += cAgeRight;
			CStrSelect += ") AND (";
			CStrSelect += cIncomeLeft;
			CStrSelect += "<= Income AND Income <=";
			CStrSelect += cIncomeRight;
			CStrSelect += ")"; 

			int iSqlLen = CStrSelect.GetLength();
			char * szSqlSquareRows = new char [iSqlLen + 1];	
			strcpy(szSqlSquareRows , "");
			strcat(szSqlSquareRows , CStrSelect);
	
			SQLFreeStmt(hstmt, SQL_DROP);
			retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 
			Sleep(200);

			SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
			SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
			
			shortTicks = GetTickCount();
			retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlSquareRows, SQL_NTS);
			shortTicks = GetTickCount() - shortTicks;

			//lEndTimer = GetTickCount() - lStartTimer;
			//wsprintf(tmp, "%ld", lEndTimer);

			if (retcode == SQL_SUCCESS) 
			{    //	retcode = SQLExecDirect for census2Dg
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt, RowCountPtr);						 
			f = * RowCountPtr;
			delete RowCountPtr;

			}
			CStrSelect = "";
			delete [] szSqlSquareRows;

	//4. insert zeta into DATA_Top100_Census2D_Profile
		
			if (f!= 0)
			{   
				char	cAttribute[10][50]= { "","","","","","","","","",""};

				
				sprintf(cAttribute[0],"%ld", q1[qnum] );
				sprintf(cAttribute[1],"%ld", q2[qnum] );
				sprintf(cAttribute[2],"%ld", N);
				sprintf(cAttribute[3],"%f",  (float)rd);
				sprintf(cAttribute[4],"%ld", f );
				//sprintf(cAttribute[5],"%ld", c );
				//sprintf(cAttribute[6],"%ld", d);
				sprintf(cAttribute[5],"%ld", longTicks);
				sprintf(cAttribute[6],"%ld", shortTicks);


				//CStrInsert += " INSERT DATA_Top100_Census2D_Learning VALUES( ";	
				CStrInsert += " INSERT Top100Census2D_LearningFrmPf100 VALUES( ";	

				CStrInsert += cAttribute[0];
				CStrInsert += ",";
				CStrInsert += cAttribute[1];
				CStrInsert += ",";
				CStrInsert += cAttribute[2];
				CStrInsert += ",";
				CStrInsert += cAttribute[3];
				CStrInsert += ",";
				CStrInsert += cAttribute[4];
				CStrInsert += ",";
				CStrInsert += cAttribute[5];
				CStrInsert += ",";
				CStrInsert += cAttribute[6];
				//CStrInsert += ",";
				//CStrInsert += cAttribute[7];
				//CStrInsert += ",";
				//CStrInsert += cAttribute[8];
				CStrInsert += ")";


			    int iSqlLen = CStrInsert.GetLength();

				char * szSqlInsert = new char [iSqlLen + 1];
				strcpy(szSqlInsert , "");
				strcat(szSqlInsert , CStrInsert);

				SQLFreeStmt(hstmt_Census2D_Profile, SQL_DROP);
				retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_Profile); /// Profile Statement handle 

				retcode = SQLExecDirect(hstmt_Census2D_Profile, (unsigned char *)szSqlInsert, SQL_NTS);

				if (retcode == SQL_SUCCESS) 
				{  //	retcode = SQLExecDirect
					//AfxMessageBox("Insert new hstmt_Census2D_Learning  OKKKKKKKKKKK!");
					Sleep(3000);
						//bReturn = TRUE;
				}
				else
				{
					AfxMessageBox("Insert DATA_Top100_Census2D_Learning Error!");

					i= 0;

				} //	retcode = SQLExecDirect 
				
				f=0;

				CStrInsert = "";
				delete [] szSqlInsert;
			}
		

			qnum++;
		}while(qnum <100); //100);

	}//if(!zlOpenDB())



	delete [] pAge;//new float[10]
	delete [] pIncome;//new float[10]
	delete [] pPf;
	delete [] q1;//new float[10]
	delete [] q2;//new float[10]


	SQLFreeStmt(hstmt, SQL_DROP);
	SQLFreeStmt(hstmt_Census2D_WorkLoad, SQL_DROP);
	SQLFreeStmt(hstmt_Census2D_Profile, SQL_DROP);

	zlCloseDB();

	AfxMessageBox("Insert hstmt_Generet2DWorkload OK!");


	
}

void CMainFrame::OnInsertClmbCensus2D() 
{

	//////////////////////////////////////////////////////
	// Create dataset CLMB_census2D
	// 3 attributes
	//
	//
	// 2003/03/22
	//////////////////////////////////////////////////////


		//AfxMessageBox("This is OnViewFileToDB!");
	//char buffer[80] = "";

	char buffer[81920] = "";
	CString CStrBuff = "";
	CString CStrBuffMeg = "";
	CString CStrInsert = ""; 
	char	cTmp[100] = "";
	char	cTmp1[100] = "";
	char	cTmp2[10000] = "";
	char	cAttribute[3][50]= { "","",""};
	//CString cAttribute[15];
	
	int i,j,istart = 0;
	int iBreadCount = 0, itest, iErr =0 ;
	int iTuplesNum = 0;

	bool bFirst = true;
	//---------  create Read File start --------
	//SQLFreeStmt(hstmt, SQL_DROP);
	//zlCloseFileDB();

	strcpy(ReadFileName, "\\\\.\\D:\\users\\zhuliang\\DATA\\census2d.data");
	if(!zlOpenFileDB())
	{
		AfxMessageBox("zlOpenFileDB() err!");
		zlCloseFileDB();
	}else
	{// read file  and convert it to database 
	
		//++++++ to do start +++++++++++++
		do 
		{
			if (ReadFile(hReadFile, buffer, 80000, 
					&dwBytesRead, NULL)) 
			{ 
				CStrBuff += buffer;
				int iLen = CStrBuff.GetLength();

			  for(i=0; i < iLen; i++)
			  {
				  if(CStrBuff[i]==10)
					  iTuplesNum++;
			  }

			  iBreadCount = 0;
			  while ( iBreadCount<iTuplesNum ) 
			  {
					

				for (i = 0; i < 3; i++)
				{// for i
					
					int k= 0;
					for (k = 0; k<50; k++)
					    cAttribute[i][k] =0;

					k= 0;

					for(j = istart; j < iLen; j++)
					{ //for j

						if(CStrBuff[j] == 13 )//|| CStrBuff[j+1] == 10 )
						{						
							iBreadCount ++;							
							j++;
							break;
							
						}else
						{
							
							if(bFirst == true)
							{
								itest =1;
								while(CStrBuff[j] == 32)
								{
									j++;
								}
								bFirst=false;
							}
								
							if (CStrBuff[j] != 32)
							{
							  cAttribute[i][k] = CStrBuff[j];
							}else
							{
								bFirst=true;
								break;
							}

						}

						k++;
 
					}//for j
				
					istart = j+1;

				} //for i



				//CStrInsert += " INSERT Adult VALUES( ";	
				//CStrInsert += " INSERT Adult1 VALUES( ";
				
	    		CStrInsert += " INSERT CLMB_census2D VALUES( ";	

				CStrInsert += cAttribute[0];
				CStrInsert += ",";
				CStrInsert += cAttribute[1];
				CStrInsert += ")";

			    int iSqlLen = CStrInsert.GetLength();

				char * szSqlInsert = new char [iSqlLen + 1];
				strcpy(szSqlInsert , "");
				strcat(szSqlInsert , CStrInsert);

				//get the number of frequency
				int dwFrequency;
				
				{
					BYTE ret;
					char c;
					char s[4] ="";
					int bt;
					int ii,count;
					CString str = "";
					

					str += cAttribute[2];				
					str.TrimLeft( );
					str.TrimRight( );
					str.MakeUpper();


					dwFrequency = 0; bt = 0; count = 0;

					for( ii= str.GetLength(); ii>0; ii--)
					{
						c = 0;s[0] = 0;
						strcpy(s,str.Mid(ii-1,1));
						c = s[0];

						if(c >= '0' && c <= '9')
							ret = c-'0';
						else
							ret = 0;

						bt = ret;
						for(int jj=1; jj<=count; jj++)
							bt = bt*10;

						dwFrequency += bt;
						count++;
					}

				}

				
				for(int ifreq = 0; ifreq < dwFrequency; ifreq++)
				{	
					
					//char szSmpl0[] = " INSERT Adult VALUES(222,'BBB', 33333,'SS',11,'FFF','FFGG','HHH','JJJ','KK',22,33,44,'III','EEE')"; //Adult
					//retcode = SQLExecDirect(hstmt, (unsigned char *)szSmpl0, SQL_NTS);

					retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlInsert, SQL_NTS);

					if (retcode == SQL_SUCCESS) 
					{  //	retcode = SQLExecDirect
						//AfxMessageBox("Insert new Recode Seccess!");
						//bReturn = TRUE;
					}
					else
					{
						//AfxMessageBox("Insert new Recode Error!");
						
						iErr++;
						itest = 1;
						Sleep(100);
					} //	retcode = SQLExecDirect 

				}//for(int ifreq = 0; ifreq<dwFrequency; ifreq++)

					bFirst = true;				
					CStrInsert = "";
					delete [] szSqlInsert; 

			}//while ( iBreadCount<iTuplesNum ) 



			CStrBuff = CStrBuff.Right(iLen - j-1);
			j=0;
			istart =0;
			iTuplesNum =0;

			
			//Sleep(100);
			} //if (ReadFile(hReadFile, buffer, 5000, 


		} while (dwBytesRead >0); 

		//++++++++++ to do end +++++++++

	}// read file  and convert it to database 

	sprintf(cTmp,"Err Num = %d, dwBytesRead = %d", iErr, dwBytesRead);
    AfxMessageBox(cTmp);
	AfxMessageBox("Insert new Recode OK!!!!!!!!!!!!!!!!!!!");

	SQLFreeStmt(hstmt, SQL_DROP);

	zlCloseFileDB();




}

void CMainFrame::OnClmbcensus3D() 
{

	//2005.08.07 reuse it.
	//Menu: InsertColumbiaDB --> CLMB_census3D
	//////////////////////////////////////////////////////
	// Create dataset CLMB_census3D
	// 4 attributes, ONE of them IS id
	//
	//
	// 2003/03/22
	//////////////////////////////////////////////////////
	
	char buffer[81920] = "";
	CString CStrBuff = "";
	CString CStrBuffMeg = "";
	CString CStrInsert = ""; 
	char	cTmp[100] = "";
	char	cTmp1[100] = "";
	char	cTmp2[10000] = "";
	char	cAttribute[4][50]= { "","","",""};
	//CString cAttribute[15];
	
	int i,j,istart = 0;
	int iBreadCount = 0, itest, iErr =0 ;
	int iTuplesNum = 0;

	bool bFirst = true;
	//---------  create Read File start --------
	//SQLFreeStmt(hstmt, SQL_DROP);
	//zlCloseFileDB();

	strcpy(ReadFileName, "\\\\.\\D:\\users\\zhuliang\\DATA\\census3d.data");
	if(!zlOpenFileDB())
	{
		AfxMessageBox("zlOpenFileDB() err!");
		zlCloseFileDB();
	}else
	{// read file  and convert it to database 
	
		//++++++ to do start +++++++++++++
		do 
		{
			if (ReadFile(hReadFile, buffer, 80000, 
					&dwBytesRead, NULL)) 
			{ 
				CStrBuff += buffer;
				int iLen = CStrBuff.GetLength();

			  for(i=0; i < iLen; i++)
			  {
				  if(CStrBuff[i]==10)
					  iTuplesNum++;
			  }

			  iBreadCount = 0;
			  while ( iBreadCount<iTuplesNum ) 
			  {
					

				for (i = 0; i < 4; i++)
				{// for i
					
					int k= 0;
					for (k = 0; k<50; k++)
					    cAttribute[i][k] =0;

					k= 0;

					for(j = istart; j < iLen; j++)
					{ //for j

						if(CStrBuff[j] == 13 || CStrBuff[j+1] == 10 )
						{						
							iBreadCount ++;							
							j++;
							break;
							
						}else
						{
							
							if(bFirst == true)
							{
								itest =1;
								while(CStrBuff[j] == 32)
								{
									j++;
								}
								bFirst=false;
							}
								
							if (CStrBuff[j] != 32)
							{
							  cAttribute[i][k] = CStrBuff[j];
							}else
							{
								bFirst=true;
								break;
							}

						}

						k++;
 
					}//for j
				
					istart = j+1;

				} //for i



				//CStrInsert += " INSERT Adult VALUES( ";	
				//CStrInsert += " INSERT Adult1 VALUES( ";
				
	    		CStrInsert += " INSERT CLMB_census3D VALUES( ";	

				CStrInsert += cAttribute[0];
				CStrInsert += ",";
				CStrInsert += cAttribute[1];
				CStrInsert += ",";
				CStrInsert += cAttribute[2];
				CStrInsert += ")";

			    int iSqlLen = CStrInsert.GetLength();

				char * szSqlInsert = new char [iSqlLen + 1];
				strcpy(szSqlInsert , "");
				strcat(szSqlInsert , CStrInsert);

				//get the number of frequency
				int dwFrequency;
				
				{
					BYTE ret;
					char c;
					char s[4] ="";
					int bt;
					int ii,count;
					CString str = "";
					

					str += cAttribute[3];				
					str.TrimLeft( );
					str.TrimRight( );
					str.MakeUpper();


					dwFrequency = 0; bt = 0; count = 0;

					for( ii= str.GetLength(); ii>0; ii--)
					{
						c = 0;s[0] = 0;
						strcpy(s,str.Mid(ii-1,1));
						c = s[0];

						if(c >= '0' && c <= '9')
							ret = c-'0';
						else
							ret = 0;

						bt = ret;
						for(int jj=1; jj<=count; jj++)
							bt = bt*10;

						dwFrequency += bt;
						count++;
					}

				}

				
				for(int ifreq = 0; ifreq < dwFrequency; ifreq++)
				{	
					
					//char szSmpl0[] = " INSERT Adult VALUES(222,'BBB', 33333,'SS',11,'FFF','FFGG','HHH','JJJ','KK',22,33,44,'III','EEE')"; //Adult
					//retcode = SQLExecDirect(hstmt, (unsigned char *)szSmpl0, SQL_NTS);

					retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlInsert, SQL_NTS);

					if (retcode == SQL_SUCCESS) 
					{  //	retcode = SQLExecDirect
						//AfxMessageBox("Insert new Recode Seccess!");
						//bReturn = TRUE;
					}
					else
					{
						//AfxMessageBox("Insert new Recode Error!");
						
						iErr++;
						itest = 1;
						Sleep(100);
					} //	retcode = SQLExecDirect 

				}//for(int ifreq = 0; ifreq<dwFrequency; ifreq++)

					bFirst = true;				
					CStrInsert = "";
					delete [] szSqlInsert; 

			}//while ( iBreadCount<iTuplesNum ) 



			CStrBuff = CStrBuff.Right(iLen - j-1);
			j=0;
			istart =0;
			iTuplesNum =0;

			
			//Sleep(100);
			} //if (ReadFile(hReadFile, buffer, 5000, 


		} while (dwBytesRead >0); 

		//++++++++++ to do end +++++++++

	}// read file  and convert it to database 

	sprintf(cTmp,"Err Num = %d, dwBytesRead = %d", iErr, dwBytesRead);
    AfxMessageBox(cTmp);
	AfxMessageBox("Insert new Recode OK!!!!!!!!!!!!!!!!!!!");

	SQLFreeStmt(hstmt, SQL_DROP);

	zlCloseFileDB();






	/***************************************************
	char buffer[81920] = "";
	CString CStrBuff = "";
	CString CStrBuffMeg = "";
	CString CStrInsert = ""; 
	char	cTmp[100] = "";
	char	cTmp1[100] = "";
	char	cTmp2[10000] = "";
	char	cAttribute[4][50]= { "","","",""};
	//CString cAttribute[15];
	
	int i,j,istart = 0;
	int iBreadCount = 0, itest, iErr =0 ;
	int iTuplesNum = 0;

	bool bFirst = true;
	//---------  create Read File start --------
	//SQLFreeStmt(hstmt, SQL_DROP);
	//zlCloseFileDB();

	strcpy(ReadFileName, "\\\\.\\D:\\users\\zhuliang\\DATA\\census3d.data");
	if(!zlOpenFileDB())
	{
		AfxMessageBox("zlOpenFileDB() err!");
		zlCloseFileDB();
	}else
	{// read file  and convert it to database 
	
		//++++++ to do start +++++++++++++
		do 
		{
			if (ReadFile(hReadFile, buffer, 80000, 
					&dwBytesRead, NULL)) 
			{ 
				CStrBuff += buffer;
				int iLen = CStrBuff.GetLength();

			  for(i=0; i < iLen; i++)
			  {
				  if(CStrBuff[i]==10)
					  iTuplesNum++;
			  }

			  iBreadCount = 0;
			  while ( iBreadCount<iTuplesNum ) 
			  {
					

				for (i = 0; i < 4; i++)
				{// for i
					
					int k= 0;
					for (k = 0; k<50; k++)
					    cAttribute[i][k] =0;

					k= 0;

					for(j = istart; j < iLen; j++)
					{ //for j

						if(CStrBuff[j] == 13 || CStrBuff[j+1] == 10 )
						{						
							iBreadCount ++;							
							j++;
							break;
							
						}else
						{
							
							if(bFirst == true)
							{
								itest =1;
								while(CStrBuff[j] == 32)
								{
									j++;
								}
								bFirst=false;
							}
								
							if (CStrBuff[j] != 32)
							{
							  cAttribute[i][k] = CStrBuff[j];
							}else
							{
								bFirst=true;
								break;
							}

						}

						k++;
 
					}//for j
				
					istart = j+1;

				} //for i


				
	    		CStrInsert += " INSERT CLMB_census3D VALUES( ";	

				CStrInsert += cAttribute[0];
				CStrInsert += ",";
				CStrInsert += cAttribute[1];
				CStrInsert += ",";
				CStrInsert += cAttribute[2];

				CStrInsert += ")";

			    int iSqlLen = CStrInsert.GetLength();

				char * szSqlInsert = new char [iSqlLen + 1];
				strcpy(szSqlInsert , "");
				strcat(szSqlInsert , CStrInsert);

				//get the number of frequency
				int dwFrequency;
				
				{
					BYTE ret;
					char c;
					char s[4] ="";
					int bt;
					int ii,count;
					CString str = "";
					

					str += cAttribute[3];				
					str.TrimLeft( );
					str.TrimRight( );
					str.MakeUpper();


					dwFrequency = 0; bt = 0; count = 0;

					for( ii= str.GetLength(); ii>0; ii--)
					{
						c = 0;s[0] = 0;
						strcpy(s,str.Mid(ii-1,1));
						c = s[0];

						if(c >= '0' && c <= '9')
							ret = c-'0';
						else
							ret = 0;

						bt = ret;
						for(int jj=1; jj<=count; jj++)
							bt = bt*10;

						dwFrequency += bt;
						count++;
					}

				}

				
				for(int ifreq = 0; ifreq < dwFrequency; ifreq++)
				{	
										//char szSmpl0[] = " INSERT Adult VALUES(222,'BBB', 33333,'SS',11,'FFF','FFGG','HHH','JJJ','KK',22,33,44,'III','EEE')"; //Adult
					//retcode = SQLExecDirect(hstmt, (unsigned char *)szSmpl0, SQL_NTS);

					retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlInsert, SQL_NTS);

					if (retcode == SQL_SUCCESS) 
					{  //	retcode = SQLExecDirect
						//AfxMessageBox("Insert new Recode Seccess!");
						//bReturn = TRUE;
					}
					else
					{
					//	AfxMessageBox("Insert new Recode Error!");
						iErr++;
						itest = 1;
						Sleep(100);

					} //	retcode = SQLExecDirect 
				}//for(int ifreq = 0; ifreq < dwFrequency; ifreq++)

					bFirst = true;				
					CStrInsert = "";
					delete [] szSqlInsert; 

			}//while ( iBreadCount<iTuplesNum ) 



			CStrBuff = CStrBuff.Right(iLen - j-1);
			j=0;
			istart =0;
			iTuplesNum =0;

			
			//Sleep(100);
			} //if (ReadFile(hReadFile, buffer, 5000, 


		} while (dwBytesRead >0); 

		//++++++++++ to do end +++++++++

	}// read file  and convert it to database 

	sprintf(cTmp,"Err Num = %d, dwBytesRead = %d", iErr, dwBytesRead);
    AfxMessageBox(cTmp);
	AfxMessageBox("Insert new Recode OK!!!!!!!!!!!!!!!!!!!");

	SQLFreeStmt(hstmt, SQL_DROP);

	zlCloseFileDB();

	********************************/
}

void CMainFrame::OnClmbCover4D() 
{
	//2005.08.02 reuse this function
	//Menu: InsertColumbiaDB --> CLMB_cover4D
	
	char buffer[81920] = "";
	CString CStrBuff = "";
	CString CStrBuffMeg = "";
	CString CStrInsert = ""; 
	char	cTmp[100] = "";
	char	cTmp1[100] = "";
	char	cTmp2[10000] = "";
	char	cAttribute[5][50]= { "","","","",""};
	//CString cAttribute[15];
	
	int i,j,istart = 0;
	int iBreadCount = 0, itest, iErr =0 ;
	int iTuplesNum = 0;
	int dwFrequency =1;

	bool bFirst = true;
	//---------  create Read File start --------
	//SQLFreeStmt(hstmt, SQL_DROP);
	//zlCloseFileDB();

	strcpy(ReadFileName, "\\\\.\\D:\\users\\zhuliang\\DATA\\cover1236.data");
	if(!zlOpenFileDB())
	{
		AfxMessageBox("zlOpenFileDB() err!");
		zlCloseFileDB();
	}else
	{// read file  and convert it to database 
	
		//++++++ to do start +++++++++++++
		do 
		{
			if (ReadFile(hReadFile, buffer, 80000, 
					&dwBytesRead, NULL)) 
			{ 
				CStrBuff += buffer;
				int iLen = CStrBuff.GetLength();

			  for(i=0; i < iLen; i++)
			  {
				  if(CStrBuff[i]==10)
					  iTuplesNum++;
			  }

			  iBreadCount = 0;
			  while ( iBreadCount<iTuplesNum ) 
			  {
					

				for (i = 0; i < 5; i++)
				{// for i
					
					int k= 0;
					for (k = 0; k<50; k++)
					    cAttribute[i][k] =0;

					k= 0;

					for(j = istart; j < iLen; j++)
					{ //for j

						if(CStrBuff[j] == 13 || CStrBuff[j+1] == 10 )
						{						
							iBreadCount ++;							
							j++;
							break;
							
						}else
						{
							
							if(bFirst == true)
							{
								itest =1;
								while(CStrBuff[j] == 32)
								{
									j++;
								}
								bFirst=false;
							}
								
							if (CStrBuff[j] != 32)
							{
							  cAttribute[i][k] = CStrBuff[j];
							}else
							{
								bFirst=true;
								break;
							}

						}

						k++;
 
					}//for j
				
					istart = j+1;

				} //for i



				//CStrInsert += " INSERT Adult VALUES( ";	
				//CStrInsert += " INSERT Adult1 VALUES( ";
				
	    		CStrInsert += " INSERT CLMB_cover4D VALUES( ";	

				CStrInsert += cAttribute[0];
				CStrInsert += ",";
				CStrInsert += cAttribute[1];
				CStrInsert += ",";
				CStrInsert += cAttribute[2];
				CStrInsert += ",";
				CStrInsert += cAttribute[3];

				CStrInsert += ")";

			    int iSqlLen = CStrInsert.GetLength();

				char * szSqlInsert = new char [iSqlLen + 1];
				strcpy(szSqlInsert , "");
				strcat(szSqlInsert , CStrInsert);

				//get the number of frequency
				dwFrequency = 1;
				
				{
					BYTE ret;
					char c;
					char s[4] ="";
					int bt;
					int ii,count;
					CString str = "";
					

					str += cAttribute[4];				
					str.TrimLeft( );
					str.TrimRight( );
					str.MakeUpper();


					dwFrequency = 0; bt = 0; count = 0;

					for( ii= str.GetLength(); ii>0; ii--)
					{
						c = 0;s[0] = 0;
						strcpy(s,str.Mid(ii-1,1));
						c = s[0];

						if(c >= '0' && c <= '9')
							ret = c-'0';
						else
							ret = 0;

						bt = ret;
						for(int jj=1; jj<=count; jj++)
							bt = bt*10;

						dwFrequency += bt;
						count++;
					}

				}

				
				for(int ifreq = 0; ifreq < dwFrequency; ifreq++)
				{	
					
					//char szSmpl0[] = " INSERT Adult VALUES(222,'BBB', 33333,'SS',11,'FFF','FFGG','HHH','JJJ','KK',22,33,44,'III','EEE')"; //Adult
					//retcode = SQLExecDirect(hstmt, (unsigned char *)szSmpl0, SQL_NTS);

					retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlInsert, SQL_NTS);



					if (retcode == SQL_SUCCESS) 
					{  //	retcode = SQLExecDirect
						//AfxMessageBox("Insert new Recode Seccess!");
						//bReturn = TRUE;
					}
					else
					{
					//	AfxMessageBox("Insert new Recode Error!");
						iErr++;
						itest = 1;
						//Sleep(100);

						/* 
						580919 DINSTINC

						  
							3474  90  25 2136  1 err
						INSERT CLMB_cover4D VALUES( 2808,99,11,474)
 			                   2808  99  11 474  1
                               2808  99  11 474  1*/

					} //	retcode = SQLExecDirect 

					if(dwFrequency >1)
					{
						break;
					}
				}

					bFirst = true;				
					CStrInsert = "";
					delete [] szSqlInsert; 

			}//while ( iBreadCount<iTuplesNum ) 



			CStrBuff = CStrBuff.Right(iLen - j-1);
			j=0;
			istart =0;
			iTuplesNum =0;

			
			//Sleep(100);
			} //if (ReadFile(hReadFile, buffer, 5000, 


		} while (dwBytesRead >0); 

		//++++++++++ to do end +++++++++

	}// read file  and convert it to database 

	sprintf(cTmp,"Err Num = %d, dwBytesRead = %d", iErr, dwBytesRead);
    AfxMessageBox(cTmp);
	AfxMessageBox("Insert new Recode OK!!!!!!!!!!!!!!!!!!!");

	SQLFreeStmt(hstmt, SQL_DROP);

	zlCloseFileDB();	


}

void CMainFrame::OnClmbGauss3D() 
{
	//2005.08.04 reuse this function
	//Menu: InsertColumbiaDB --> CLMB_Gauss3D 
	char buffer[81920] = "";
	CString CStrBuff = "";
	CString CStrBuffMeg = "";
	CString CStrInsert = ""; 
	char	cTmp[100] = "";
	char	cTmp1[100] = "";
	char	cTmp2[10000] = "";
	char	cAttribute[4][50]= { "","","",""};
	//CString cAttribute[15];
	
	int i,j,istart = 0;
	int iBreadCount = 0, itest, iErr =0 ;
	int iTuplesNum = 0;

	bool bFirst = true;
	//---------  create Read File start --------
	//SQLFreeStmt(hstmt, SQL_DROP);
	//zlCloseFileDB();

	strcpy(ReadFileName, "\\\\.\\D:\\users\\zhuliang\\DATA\\gauss_d3_N500000_z100_p50_r10000_s100_seed1234.data");
	if(!zlOpenFileDB())
	{
		AfxMessageBox("zlOpenFileDB() err!");
		zlCloseFileDB();
	}else
	{// read file  and convert it to database 
	
		//++++++ to do start +++++++++++++
		do 
		{
			if (ReadFile(hReadFile, buffer, 80000, 
					&dwBytesRead, NULL)) 
			{ 
				CStrBuff += buffer;
				int iLen = CStrBuff.GetLength();

			  for(i=0; i < iLen; i++)
			  {
				  if(CStrBuff[i]==10)
					  iTuplesNum++;
			  }

			  iBreadCount = 0;
			  while ( iBreadCount<iTuplesNum ) 
			  {
					

				for (i = 0; i < 4; i++)
				{// for i
					
					int k= 0;
					for (k = 0; k<50; k++)
					    cAttribute[i][k] =0;

					k= 0;

					for(j = istart; j < iLen; j++)
					{ //for j

						if(CStrBuff[j] == 13 || CStrBuff[j+1] == 10 )
						{						
							iBreadCount ++;							
							j++;
							break;
							
						}else
						{
							
							if(bFirst == true)
							{
								itest =1;
								while(CStrBuff[j] == 32)
								{
									j++;
								}
								bFirst=false;
							}
								
							if (CStrBuff[j] != 32)
							{
							  cAttribute[i][k] = CStrBuff[j];
							}else
							{
								bFirst=true;
								break;
							}

						}

						k++;
 
					}//for j
				
					istart = j+1;

				} //for i



				//CStrInsert += " INSERT Adult VALUES( ";	
				//CStrInsert += " INSERT Adult1 VALUES( ";
				
	    		CStrInsert += " INSERT CLMB_Gauss3D VALUES( ";	//504321 TUPLES 2005.08.04


				CStrInsert += cAttribute[0];
				CStrInsert += ",";
				CStrInsert += cAttribute[1];
				CStrInsert += ",";
				CStrInsert += cAttribute[2];

				CStrInsert += ")";

			    int iSqlLen = CStrInsert.GetLength();

				char * szSqlInsert = new char [iSqlLen + 1];
				strcpy(szSqlInsert , "");
				strcat(szSqlInsert , CStrInsert);

				//get the number of frequency
				int dwFrequency;
				
				{
					BYTE ret;
					char c;
					char s[4] ="";
					int bt;
					int ii,count;
					CString str = "";
					

					str += cAttribute[3];				
					str.TrimLeft( );
					str.TrimRight( );
					str.MakeUpper();


					dwFrequency = 0; bt = 0; count = 0;

					for( ii= str.GetLength(); ii>0; ii--)
					{
						c = 0;s[0] = 0;
						strcpy(s,str.Mid(ii-1,1));
						c = s[0];

						if(c >= '0' && c <= '9')
							ret = c-'0';
						else
							ret = 0;

						bt = ret;
						for(int jj=1; jj<=count; jj++)
							bt = bt*10;

						dwFrequency += bt;
						count++;
					}

				}

				
				for(int ifreq = 0; ifreq < dwFrequency; ifreq++)
				{	
					
					//char szSmpl0[] = " INSERT Adult VALUES(222,'BBB', 33333,'SS',11,'FFF','FFGG','HHH','JJJ','KK',22,33,44,'III','EEE')"; //Adult
					//retcode = SQLExecDirect(hstmt, (unsigned char *)szSmpl0, SQL_NTS);

					retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlInsert, SQL_NTS);



					if (retcode == SQL_SUCCESS) 
					{  //	retcode = SQLExecDirect
						//AfxMessageBox("Insert new Recode Seccess!");
						//bReturn = TRUE;
					}
					else
					{
					//	AfxMessageBox("Insert new Recode Error!");
						iErr++;
						itest = 1;

					} //	retcode = SQLExecDirect 
				}

					bFirst = true;				
					CStrInsert = "";
					delete [] szSqlInsert; 

			}//while ( iBreadCount<iTuplesNum ) 



			CStrBuff = CStrBuff.Right(iLen - j-1);
			j=0;
			istart =0;
			iTuplesNum =0;

			
			//Sleep(100);
			} //if (ReadFile(hReadFile, buffer, 5000, 


		} while (dwBytesRead >0); 

		//++++++++++ to do end +++++++++

	}// read file  and convert it to database 

	sprintf(cTmp,"Err Num = %d, dwBytesRead = %d", iErr, dwBytesRead);
    AfxMessageBox(cTmp);
	AfxMessageBox("Insert new Recode OK!!!!!!!!!!!!!!!!!!!");

	SQLFreeStmt(hstmt, SQL_DROP);

	zlCloseFileDB();
	

}

void CMainFrame::OnClmbArray3D() 
{
    //2005.08.05
	//Menu: InsertColumbiaDB --> CLMB_Array3D
	char buffer[81920] = "";
	CString CStrBuff = "";
	CString CStrBuffMeg = "";
	CString CStrInsert = ""; 
	char	cTmp[100] = "";
	char	cTmp1[100] = "";
	char	cTmp2[10000] = "";
	char	cAttribute[4][50]= { "","","",""};
	//CString cAttribute[15];
	
	int i,j,istart = 0;
	int iBreadCount = 0, itest, iErr =0 ;
	int iTuplesNum = 0;

	bool bFirst = true;
	//---------  create Read File start --------
	//SQLFreeStmt(hstmt, SQL_DROP);
	//zlCloseFileDB();

	strcpy(ReadFileName, "\\\\.\\D:\\users\\zhuliang\\DATA\\array_d3_N500000_z100_r10000_n60_seed1234.data");
	if(!zlOpenFileDB())
	{
		AfxMessageBox("zlOpenFileDB() err!");
		zlCloseFileDB();
	}else
	{// read file  and convert it to database 
	
		//++++++ to do start +++++++++++++
		do 
		{
			if (ReadFile(hReadFile, buffer, 80000, 
					&dwBytesRead, NULL)) 
			{ 
				CStrBuff += buffer;
				int iLen = CStrBuff.GetLength();

			  for(i=0; i < iLen; i++)
			  {
				  if(CStrBuff[i]==10)
					  iTuplesNum++;
			  }

			  iBreadCount = 0;
			  while ( iBreadCount<iTuplesNum ) 
			  {
					

				for (i = 0; i < 4; i++)
				{// for i
					
					int k= 0;
					for (k = 0; k<50; k++)
					    cAttribute[i][k] =0;

					k= 0;

					for(j = istart; j < iLen; j++)
					{ //for j

						if(CStrBuff[j] == 13 || CStrBuff[j+1] == 10 )
						{						
							iBreadCount ++;							
							j++;
							break;
							
						}else
						{
							
							if(bFirst == true)
							{
								itest =1;
								while(CStrBuff[j] == 32)
								{
									j++;
								}
								bFirst=false;
							}
								
							if (CStrBuff[j] != 32)
							{
							  cAttribute[i][k] = CStrBuff[j];
							}else
							{
								bFirst=true;
								break;
							}

						}

						k++;
 
					}//for j
				
					istart = j+1;

				} //for i


				
	    		CStrInsert += " INSERT CLMB_Array3D VALUES( ";	

				CStrInsert += cAttribute[0];
				CStrInsert += ",";
				CStrInsert += cAttribute[1];
				CStrInsert += ",";
				CStrInsert += cAttribute[2];

				CStrInsert += ")";

			    int iSqlLen = CStrInsert.GetLength();

				char * szSqlInsert = new char [iSqlLen + 1];
				strcpy(szSqlInsert , "");
				strcat(szSqlInsert , CStrInsert);

			//	int iResponse = AfxMessageBox(szSqlInsert, MB_OKCANCEL,0 );

				//get the number of frequency
				int dwFrequency;
				
				{
					BYTE ret;
					char c;
					char s[4] ="";
					int bt;
					int ii,count;
					CString str = "";
					

					str += cAttribute[3];				
					str.TrimLeft( );
					str.TrimRight( );
					str.MakeUpper();


					dwFrequency = 0; bt = 0; count = 0;

					for( ii= str.GetLength(); ii>0; ii--)
					{
						c = 0;s[0] = 0;
						strcpy(s,str.Mid(ii-1,1));
						c = s[0];

						if(c >= '0' && c <= '9')
							ret = c-'0';
						else
							ret = 0;

						bt = ret;
						for(int jj=1; jj<=count; jj++)
							bt = bt*10;

						dwFrequency += bt;
						count++;
					}

				}

				
				for(int ifreq = 0; ifreq < dwFrequency; ifreq++)
				{	
					
					//char szSmpl0[] = " INSERT Adult VALUES(222,'BBB', 33333,'SS',11,'FFF','FFGG','HHH','JJJ','KK',22,33,44,'III','EEE')"; //Adult
					//retcode = SQLExecDirect(hstmt, (unsigned char *)szSmpl0, SQL_NTS);

					retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlInsert, SQL_NTS);



					if (retcode == SQL_SUCCESS) 
					{  //	retcode = SQLExecDirect
						//AfxMessageBox("Insert new Recode Seccess!");
						//bReturn = TRUE;
					}
					else
					{
					//	AfxMessageBox("Insert new Recode Error!");
						iErr++;
						itest = 1;

					} //	retcode = SQLExecDirect 
				}

					bFirst = true;				
					CStrInsert = "";
					delete [] szSqlInsert; 

			}//while ( iBreadCount<iTuplesNum ) 



			CStrBuff = CStrBuff.Right(iLen - j-1);
			j=0;
			istart =0;
			iTuplesNum =0;

			
			//Sleep(100);
			} //if (ReadFile(hReadFile, buffer, 5000, 


		} while (dwBytesRead >0); 

		//++++++++++ to do end +++++++++

	}// read file  and convert it to database 

	sprintf(cTmp,"Err Num = %d, dwBytesRead = %d", iErr, dwBytesRead);
    AfxMessageBox(cTmp);
	AfxMessageBox("Insert new Recode to Array3Dg OK!!!!!!!!!!!!!!!!!!!");

	SQLFreeStmt(hstmt, SQL_DROP);

	zlCloseFileDB();


}

void CMainFrame::OnClmbArray2D() 
{
	char buffer[81920] = "";
	CString CStrBuff = "";
	CString CStrBuffMeg = "";
	CString CStrInsert = ""; 
	char	cTmp[100] = "";
	char	cTmp1[100] = "";
	char	cTmp2[10000] = "";
	char	cAttribute[3][50]= { "","",""};
	//CString cAttribute[15];
	
	int i,j,istart = 0;
	int iBreadCount = 0, itest, iErr =0 ;
	int iTuplesNum = 0;

	bool bFirst = true;
	//---------  create Read File start --------
	//SQLFreeStmt(hstmt, SQL_DROP);
	//zlCloseFileDB();

	strcpy(ReadFileName, "\\\\.\\D:\\users\\zhuliang\\DATA\\array_d2_N500000_z100_r10000_n300_seed1234.data");
	if(!zlOpenFileDB())
	{
		AfxMessageBox("zlOpenFileDB() err!");
		zlCloseFileDB();
	}else
	{// read file  and convert it to database 
	
		//++++++ to do start +++++++++++++
		do 
		{
			if (ReadFile(hReadFile, buffer, 80000, 
					&dwBytesRead, NULL)) 
			{ 
				CStrBuff += buffer;
				int iLen = CStrBuff.GetLength();

			  for(i=0; i < iLen; i++)
			  {
				  if(CStrBuff[i]==10)
					  iTuplesNum++;
			  }

			  iBreadCount = 0;
			  while ( iBreadCount<iTuplesNum ) 
			  {
					

				for (i = 0; i < 3; i++)
				{// for i
					
					int k= 0;
					for (k = 0; k<50; k++)
					    cAttribute[i][k] =0;

					k= 0;

					for(j = istart; j < iLen; j++)
					{ //for j

						if(CStrBuff[j] == 13 || CStrBuff[j+1] == 10 )
						{						
							iBreadCount ++;							
							j++;
							break;
							
						}else
						{
							
							if(bFirst == true)
							{
								itest =1;
								while(CStrBuff[j] == 32)
								{
									j++;
								}
								bFirst=false;
							}
								
							if (CStrBuff[j] != 32)
							{
							  cAttribute[i][k] = CStrBuff[j];
							}else
							{
								bFirst=true;
								break;
							}

						}

						k++;
 
					}//for j
				
					istart = j+1;

				} //for i
				
	    		CStrInsert += " INSERT CLMB_Array2D VALUES( ";	

				CStrInsert += cAttribute[0];
				CStrInsert += ",";
				CStrInsert += cAttribute[1];

				CStrInsert += ")";

			    int iSqlLen = CStrInsert.GetLength();

				char * szSqlInsert = new char [iSqlLen + 1];
				strcpy(szSqlInsert , "");
				strcat(szSqlInsert , CStrInsert);

				//get the number of frequency
				int dwFrequency;
				
				{
					BYTE ret;
					char c;
					char s[4] ="";
					int bt;
					int ii,count;
					CString str = "";
					

					str += cAttribute[2];				
					str.TrimLeft( );
					str.TrimRight( );
					str.MakeUpper();


					dwFrequency = 0; bt = 0; count = 0;

					for( ii= str.GetLength(); ii>0; ii--)
					{
						c = 0;s[0] = 0;
						strcpy(s,str.Mid(ii-1,1));
						c = s[0];

						if(c >= '0' && c <= '9')
							ret = c-'0';
						else
							ret = 0;

						bt = ret;
						for(int jj=1; jj<=count; jj++)
							bt = bt*10;

						dwFrequency += bt;
						count++;
					}

				}

				
				for(int ifreq = 0; ifreq < dwFrequency; ifreq++)

				{	
					
					//char szSmpl0[] = " INSERT Adult VALUES(222,'BBB', 33333,'SS',11,'FFF','FFGG','HHH','JJJ','KK',22,33,44,'III','EEE')"; //Adult
					//retcode = SQLExecDirect(hstmt, (unsigned char *)szSmpl0, SQL_NTS);

					retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlInsert, SQL_NTS);



					if (retcode == SQL_SUCCESS) 
					{  //	retcode = SQLExecDirect
						//AfxMessageBox("Insert new Recode Seccess!");
						//bReturn = TRUE;
					}
					else
					{
					//	AfxMessageBox("Insert new Recode Error!");
						iErr++;
						itest = 1;

					} //	retcode = SQLExecDirect 
				}

					bFirst = true;				
					CStrInsert = "";
					delete [] szSqlInsert; 

			}//while ( iBreadCount<iTuplesNum ) 



			CStrBuff = CStrBuff.Right(iLen - j-1);
			j=0;
			istart =0;
			iTuplesNum =0;

			
			//Sleep(100);
			} //if (ReadFile(hReadFile, buffer, 5000, 


		} while (dwBytesRead >0); 

		//++++++++++ to do end +++++++++

	}// read file  and convert it to database 

	sprintf(cTmp,"Err Num = %d, dwBytesRead = %d", iErr, dwBytesRead);
    AfxMessageBox(cTmp);
	AfxMessageBox("Insert new Recode OK!!!!!!!!!!!!!!!!!!!");

	SQLFreeStmt(hstmt, SQL_DROP);

	zlCloseFileDB();
	
}

void CMainFrame::OnArray2D32000smpl() 
{
	// TODO: Add your command handler code here
	
}

void CMainFrame::OnCreateSmpl2000census2Dprofile() 
{
	//Create census2D profile with	2000 sample
	//								1000 samples
	//								0800 samples
	//								0400 samples
	//								0200 samples
	//								0100 samples
	//								0250 samples

/*****************************
* 1. read all tuples from census2D store a buffer
* 2. Read all tuple from DATA_Top100_Census2D_WorkLoad 
* 3. evaluate r, f, c, -d,
* 4. insert zeta into DATA_Top100_Census2D_Profile
******************************/
// Menu: Smpl2000_Census2D_Profile

	int N, f, c, d = 0; 

	int i,j, k, iErr = 0;
	char tmp[100] = "";
	CString CStrSelect = ""; 
	CString CStrInsert = "";

	int longTicks =0, shortTicks =0;
	
	SWORD  sAge;
	SDWORD cbAge;

	SDWORD sIncome;
	SDWORD cbIncome;


	HSTMT   hstmt_Census2D_WorkLoad; //for queries workload
	HSTMT   hstmt_Census2D_Profile;  //for insert Profile

	int iTupleNum;//,iStartRowNum, iTotalNum;

	int * q1, *q2, *q1Hold, *q2Hold;
	
	int iSizeSmpl = 1459; //250; //200; //400; //800; //1000; //2000;
	int iTopN = 1000; //250;//50; //50; 100; 250; 1000
	
	//float rd, dis[100], r[100]; 
	//int tuple1[100],tuple2[100];
	
	float rd, dis[2000], r[2000]; 
	int tuple1[2000],tuple2[2000];


//struct_Census2D_Tuple


	if(!zlOpenDB())
	{
		AfxMessageBox("zlOpenDB() err!");
		zlCloseDB();
	}else
	{
		retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_WorkLoad); ///queries Statement handle 
		retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_Profile); /// Profile Statement handle 

		//1. read all tuples from census2Dg store a buffer
		//1111111111111 read data base from census2Dg 111111111111111	

		//UCHAR szSqlAllRows[] = "select  * from census2dg where (15 - 9 <=age and age<=15+ 9 ) and (15- 9 <=Income and Income <=15+ 9 )";
		
		//----------------------------------------------------
		//UCHAR szSqlAllRows[] = "SELECT * FROM census2Dg"; //discounts, authors, Census2DTable						
		UCHAR szSqlAllRows[] = "SELECT * FROM CLMB_census2D"; //discounts, authors, Census2DTable						

		//------------------------------------------------------


		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		
		longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);
		longTicks = GetTickCount() - longTicks;

		//lEndTimer = GetTickCount() - lStartTimer;
		//wsprintf(tmp, "%ld", lEndTimer);


		if (retcode == SQL_SUCCESS) 
		{    //	retcode = SQLExecDirect for census2Dg
			int iRowCount;
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt, RowCountPtr);						 
			iRowCount = * RowCountPtr;
			iTupleNum = iRowCount;
			delete RowCountPtr;
			
			// Bind columns 1,2.
			SQLBindCol(hstmt, 1, SQL_C_SSHORT, &sAge, 0, &cbAge);
			SQLBindCol(hstmt, 2, SQL_C_SLONG, &sIncome,0, &cbIncome); //SQL_C_SSHORT

			pAge = new  int[iRowCount];//buffer, new float[10]
			pIncome = new  int[iRowCount];//buffer , new float[10]
			pAgeHold = pAge;
			pIncomeHold = pIncome;
			iRowCount =0;
			while (TRUE) 
			{
				retcode = SQLFetch(hstmt);

				if (retcode == SQL_ERROR)
				{
					//show_error();

					wsprintf(tmp, "%ld", iRowCount);
					//int i = iRowCount;
					AfxMessageBox("SQLFetch Error !!!!!!");
							//break; //99.8.26
				}

				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
						//if (retcode == SQL_SUCCESS)
				{	

					*pAge		= sAge;
					*pIncome	= sIncome;

					pAge++;
					pIncome++;

					if(retcode == SQL_SUCCESS_WITH_INFO)
					{
						wsprintf(tmp, "%ld", retcode);
						AfxMessageBox(tmp);

					}
						
				} 
				else 
				{
					break;
				}

			}   ///while (TRUE)

			pAge = pAgeHold ;
			pIncome = pIncomeHold ;
	
		}//	retcode = SQLExecDirect  for census2Dg

	//111111111111111111 read data base  census2Dg end   111111111111

	//2. Read all tuple from smpl_DB_tables : DATA_Top100_Census2D_WorkLoad ,100 smpl
										//	  smpl2000_Census2D				 2000 smpl
		
		sAge = 0;cbAge = 0;sIncome = 0;cbIncome= 0;

		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Top100_Census2D_WorkLoad"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl2000_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl1000_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl0800_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl0400_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl0200_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl0100_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl0250_Census2D"; //discounts, authors, Census2DTable						
		UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl1459_Census2D"; //discounts, authors, Census2DTable						
		
		SQLSetStmtOption(hstmt_Census2D_WorkLoad, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt_Census2D_WorkLoad, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		retcode = SQLExecDirect(hstmt_Census2D_WorkLoad, szSqlAllQueryRows, SQL_NTS);

		//lEndTimer = GetTickCount() - lStartTimer;
		//wsprintf(tmp, "%ld", lEndTimer);


		if (retcode == SQL_SUCCESS) 
		{    //	retcode = SQLExecDirect for census2Dg
			int iRowCount;
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt_Census2D_WorkLoad, RowCountPtr);						 
			iRowCount = * RowCountPtr;
			delete RowCountPtr;
			
			// Bind columns 1,2.
			SQLBindCol(hstmt_Census2D_WorkLoad, 1, SQL_C_SSHORT, &sAge, 0, &cbAge);
			SQLBindCol(hstmt_Census2D_WorkLoad, 2, SQL_C_SLONG, &sIncome,0, &cbIncome); //SQL_C_SSHORT

			q1 = new  int[iRowCount];//buffer, new float[10]
			q2 = new  int[iRowCount];//buffer , new float[10]
			q1Hold = q1; q2Hold= q2;
			

			while (TRUE) 
			{
				retcode = SQLFetch(hstmt_Census2D_WorkLoad);

				if (retcode == SQL_ERROR)
				{
					//show_error();

					wsprintf(tmp, "%ld", iRowCount);
					//int i = iRowCount;
					AfxMessageBox("SQLFetch Error !!!!!!");
							//break; //99.8.26
				}

				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
						//if (retcode == SQL_SUCCESS)
				{	
					*q1	= sAge;
					*q2	= sIncome;

					q1++;
					q2++;
				} 
				else 
				{
					break;
				}

			}   ///while (TRUE)
			
			q1= q1Hold; q2= q2Hold;
				
		}//	retcode = SQLExecDirect  for query q1,q2.
	
	//3. evaluate r, f, -c, -d,

		float ftmp=0;
		int itmp = 0,qnum =0; 
		int topt1[1000],topt2[1000];


		do
		{
			//take first 100 as Top100
			//for(i = 0; i<100; i++)
			for(i = 0; i<iTopN; i++)
			{
			  dis[i] = (float)max( abs(pAge[i]- q1[qnum]), abs(pIncome[i]-q2[qnum]) );
			  tuple1[i] = pAge[i];
			  tuple2[i] = pIncome[i];
			}
			i=0;
			
			//for(i=0; i<100; i++)
			for(i=0; i<iTopN; i++)
			{
				r[i] = dis[i];
				topt1[i] = tuple1[i] ; topt2[i]=tuple2[i] ;
				//for( j= i+1; j<100; j++)
				for( j= i+1; j<iTopN; j++)
				{
					if(dis[j] < r[i]) 
					{ ftmp = r[i];    r[i] = dis[j];  dis[j] = ftmp;
					  itmp = topt1[i]; topt1[i]= tuple1[j]; tuple1[j]= itmp;
					  itmp = topt2[i]; topt2[i]= tuple2[j]; tuple2[j]= itmp;
					}
				}
			}
			
			i=0;
			//2. select top100 (topN)from all tuples with size iTupleNum
			//for(i=100; i<iTupleNum; i++)
			for(i = iTopN; i<iTupleNum; i++)
			{
				ftmp = (float)max( abs(pAge[i]- q1[qnum]), abs(pIncome[i]-q2[qnum]) );
				//if(ftmp < r[99])
				if(ftmp < r[iTopN - 1])		
				{
					//for(j=0;j<100;j++)
					for(j=0;j<iTopN;j++)
					{
						if(ftmp<r[j])
						{
							//for(k=99; k>j; k--)
							for(k=iTopN - 1; k>j; k--)
							{
								r[k] = r[k-1];
								topt1[k] = topt1[k-1];
								topt2[k] = topt2[k-1];
							}
							r[j]=ftmp;
							topt1[j] = pAge[i];
							topt2[j] = pIncome[i];
							break;
						}
					}
				}
			}
		
		//int N, rd,f, c, d; 	
			
//////////////////
			/*************************
		SQLFreeStmt(hstmt, SQL_DROP);
		retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 

		Sleep(100);
		
		//UCHAR szSqlAllRows[] = "SELECT * FROM census2Dg"; //discounts, authors, Census2DTable						
		UCHAR szSqlAllRows[] = "SELECT * FROM CLMB_census2D"; //discounts, authors, Census2DTable						

		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		
		longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);
		longTicks = GetTickCount() - longTicks;
		***********************/
//////////////////////////
				
						
			
			CTime CurTime = CTime::GetCurrentTime();         

			//N = 100; rd = r[99]; //r[99] means the distance from last_tuple (top100) to the query
			N = iTopN; rd = r[iTopN-1]; //r[99] means the distance from last_tuple (top100) to the query
		
			c = -1; d--; //d = - CurTime.GetTime(); d++;
			
			char cAgeLeft[20] = "", cAgeRight[20] = "", cIncomeLeft[20] = "", cIncomeRight[20] ="";
			
			sprintf(cAgeLeft,"%f", (float)(q1[qnum] - rd) );
			sprintf(cAgeRight,"%f", (float)(q1[qnum] + rd));
			sprintf(cIncomeLeft,"%f", (float)(q2[qnum] - rd));
			sprintf(cIncomeRight,"%f",(float)(q2[qnum] + rd));

			//CStrSelect += "select  * from census2dg where (";
			CStrSelect += "select  * from CLMB_census2D where (";
			
			CStrSelect += cAgeLeft;
			CStrSelect += "<= age AND age <=";
			CStrSelect += cAgeRight;
			CStrSelect += ") AND (";
			CStrSelect += cIncomeLeft;
			CStrSelect += "<= Income AND Income <=";
			CStrSelect += cIncomeRight;
			CStrSelect += ")"; 

			int iSqlLen = CStrSelect.GetLength();
			char * szSqlSquareRows = new char [iSqlLen + 1];	
			strcpy(szSqlSquareRows , "");
			strcat(szSqlSquareRows , CStrSelect);
			//Sleep(200);
	
			SQLFreeStmt(hstmt, SQL_DROP);
			retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 


			//szSqlSquareRows= "select  * from census2dg where ";// (15 - 9 <=age and age<=15+ 9 ) and (15- 9 <=Income and Income <=15+ 9 )";
			SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
			SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
			
			shortTicks = GetTickCount();
			retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlSquareRows, SQL_NTS);
			shortTicks = GetTickCount() - shortTicks;

			//lEndTimer = GetTickCount() - lStartTimer;
			//wsprintf(tmp, "%ld", lEndTimer);

			if (retcode == SQL_SUCCESS) 
			{    //	retcode = SQLExecDirect for census2Dg
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt, RowCountPtr);						 
			f = * RowCountPtr;
			delete RowCountPtr;

			}
			CStrSelect = "";
			delete [] szSqlSquareRows;

	//4. insert zeta into the Profiles: DATA_Top100_Census2D_Profile
									//	Top100_Census2D_Profile2000
		
			if (f!= 0)
			{   
				char	cAttribute[10][50]= { "","","","","","","","","",""};

				
				sprintf(cAttribute[0],"%ld", q1[qnum] );
				sprintf(cAttribute[1],"%ld", q2[qnum] );
				sprintf(cAttribute[2],"%ld", N);
				sprintf(cAttribute[3],"%f",  (float)rd);
				sprintf(cAttribute[4],"%ld", f );
				sprintf(cAttribute[5],"%ld", c );
				sprintf(cAttribute[6],"%ld", d);
				sprintf(cAttribute[7],"%ld", longTicks);
				sprintf(cAttribute[8],"%ld", shortTicks);

				//---------tables---------------
				//CStrInsert += " INSERT DATA_Top100_Census2D_Profile VALUES( ";	
				//CStrInsert += " INSERT Top100_Census2D_Profile VALUES( ";	
				//CStrInsert += " INSERT Top100_Census2D_Profile2000 VALUES( ";	
				//CStrInsert += " INSERT Top100_Census2D_Profile1000 VALUES( ";	
				//CStrInsert += " INSERT Top100_Census2D_Profile0800 VALUES( ";	
				//CStrInsert += " INSERT Top100_Census2D_Profile0400 VALUES( ";	
				//CStrInsert += " INSERT Top100_Census2D_Profile0200 VALUES( ";	
				//CStrInsert += " INSERT Top100_Census2D_Profile0250 VALUES( ";	
				//CStrInsert += " INSERT Top100_Census2D_Profile1459 VALUES( ";	
				
				//CStrInsert += " INSERT Top50_Census2D_Profile1459 VALUES( ";	
				//CStrInsert += " INSERT Top250_Census2D_Profile1459 VALUES( ";	
				CStrInsert += " INSERT Top1000_Census2D_Profile1459 VALUES( ";	
				
				CStrInsert += cAttribute[0];
				CStrInsert += ",";
				CStrInsert += cAttribute[1];
				CStrInsert += ",";
				CStrInsert += cAttribute[2];
				CStrInsert += ",";
				CStrInsert += cAttribute[3];
				CStrInsert += ",";
				CStrInsert += cAttribute[4];
				CStrInsert += ",";
				CStrInsert += cAttribute[5];
				CStrInsert += ",";
				CStrInsert += cAttribute[6];
				CStrInsert += ",";
				CStrInsert += cAttribute[7];
				CStrInsert += ",";
				CStrInsert += cAttribute[8];
				CStrInsert += ")";


			    int iSqlLen = CStrInsert.GetLength();

				char * szSqlInsert = new char [iSqlLen + 1];
				strcpy(szSqlInsert , "");
				strcat(szSqlInsert , CStrInsert);

				//Sleep(100);

				SQLFreeStmt(hstmt_Census2D_Profile, SQL_DROP);
				retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_Profile); /// Profile Statement handle 
				
				SQLSetStmtOption(hstmt_Census2D_Profile, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
				SQLSetStmtOption(hstmt_Census2D_Profile, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
				

				retcode = SQLExecDirect(hstmt_Census2D_Profile, (unsigned char *)szSqlInsert, SQL_NTS);

				if (retcode == SQL_SUCCESS) 
				{  //	retcode = SQLExecDirect
					//AfxMessageBox("Insert new hstmt_Census2D_Profile  OKKKKKKKKKKK!");
					//Sleep(200);
						//bReturn = TRUE;
				}
				else
				{
					AfxMessageBox("Insert hstmt_Census2D_Profile Error!");

					i= 0;


				} //	retcode = SQLExecDirect 
				
				f=0;

				CStrInsert = "";
				delete [] szSqlInsert;
			}
		

			qnum++;
		}while(qnum <iSizeSmpl); //100);

	}//if(!zlOpenDB())



	delete [] pAge;//new float[10]
	delete [] pIncome;//new float[10]
	delete [] q1;//new float[10]
	delete [] q2;//new float[10]


	SQLFreeStmt(hstmt, SQL_DROP);
	SQLFreeStmt(hstmt_Census2D_WorkLoad, SQL_DROP);
	SQLFreeStmt(hstmt_Census2D_Profile, SQL_DROP);

	zlCloseDB();

	AfxMessageBox("Insert hstmt_Generet2D_profile OK!");
	
}

void CMainFrame::OnLearningTop100census2dbiasedfrom2000() 
{
	//Learning: Top100 census2d biased from profile with 2000 smpl
	
	// --Read: DATA_Top100_Census2D_Profile, as Profile
	// Read:  Top100_Census2D_Profile, as Profile
	// Read: DATA_Census2Dg_B_workload, as Biased Query workload
	// write:DATA_Top100_Census2D_Learning
	// Top100, distance = max,Type = Biased 
	/////////////////////////////////////////////////////
	int N, f, c, d; 

	int i,j, iErr = 0;
	char tmp[100] = "";
	CString CStrSelect = ""; 
	CString CStrInsert = "";

	int longTicks =0, shortTicks =0;
	
	SWORD  sAge;
	SDWORD cbAge;

	SDWORD sIncome;
	SDWORD cbIncome;
	SDWORD sN,sr,sf,sc,sd;
	SDWORD cbN,cbr,cbf,cbc,cbd;


	HSTMT   hstmt_Census2D_WorkLoad; //for queries workload
	HSTMT   hstmt_Census2D_Profile;  //for insert Profile

	//int iTupleNum;//,iStartRowNum, iTotalNum;

	int * q1, *q2, *q1Hold, *q2Hold; //for queries workload
	
	//float rd, dis[100], r[100]; 
	//int tuple1[100],tuple2[100];
	
	double rd =0.0, dis[2000], r[2000];  //rd is the final radius distance of Q; dis[]= d(Q,Q'), r[] id dis[];
	int tuple1[2000],tuple2[2000];

	double rr[2000],rOrder[2000]; 

	int iSizeProfile = 2000;

	int iInsertOK = 0, iInsertERR = 0, irderr = 0;

//struct_Census2D_Tuple


	if(!zlOpenDB())
	{
		AfxMessageBox("zlOpenDB() err!");
		zlCloseDB();
	}else
	{
		retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_WorkLoad); ///queries Statement handle 
		retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_Profile); /// Profile Statement handle 

		//1. read all tuples from Profile set store a buffer
		//1111111111111 read database from profiles :DATA_Top100_Census2D_Profile 111111111111111	
												//   Top100_Census2D_Profile2000
		//---------------
		//UCHAR szSqlAllRows[] = "SELECT * FROM DATA_Top100_Census2D_Profile"; //discounts, authors, Census2DTable						
		UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile2000"; //discounts, authors, Census2DTable						

		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		
		//longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);
		//longTicks = GetTickCount() - longTicks;

		//lEndTimer = GetTickCount() - lStartTimer;
		//wsprintf(tmp, "%ld", lEndTimer);


		if (retcode == SQL_SUCCESS) 
		{    //	retcode = SQLExecDirect for DATA_Top100_Census2D_Profile
			int iRowCount;
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt, RowCountPtr);						 
			iRowCount = * RowCountPtr;
			iSizeProfile = iRowCount; // here only size of profile, 100,200, ...,2000
			delete RowCountPtr;
			
			// Bind columns 1,2.
			SQLBindCol(hstmt, 1, SQL_C_SSHORT, &sAge, 0, &cbAge);
			SQLBindCol(hstmt, 2, SQL_C_SLONG, &sIncome,0, &cbIncome); //SQL_C_SSHORT
			SQLBindCol(hstmt, 3, SQL_C_SLONG, &sN,0, &cbN); //SQL_C_SSHORT
			SQLBindCol(hstmt, 4, SQL_C_SLONG, &sr,0, &cbr); //SQL_C_SSHORT
			SQLBindCol(hstmt, 5, SQL_C_SLONG, &sf,0, &cbf); //SQL_C_SSHORT
			SQLBindCol(hstmt, 6, SQL_C_SLONG, &sc,0, &cbc); //SQL_C_SSHORT
			SQLBindCol(hstmt, 7, SQL_C_SLONG, &sd,0, &cbd); //SQL_C_SSHORT

			pPf = new Profile2D[iRowCount];
			pPfHold = pPf;

			pAge = new  int[iRowCount];//buffer, new double[10]
			pIncome = new  int[iRowCount];//buffer , new double[10]
			pAgeHold = pAge;
			pIncomeHold = pIncome;
			iRowCount =0;
			while (TRUE) 
			{
				retcode = SQLFetch(hstmt);

				if (retcode == SQL_ERROR)
				{
					//show_error();
					wsprintf(tmp, "%ld", iRowCount);
					//int i = iRowCount;
					AfxMessageBox("SQLFetch Error !!!!!!");
							//break; //99.8.26
				}

				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
				{	
					*pAge		= sAge;
					*pIncome	= sIncome;
					
					pPf->q[0]	= sAge;				
					pPf->q[1]	= sIncome;
					pPf->N		= sN;
					pPf->r		= (float) sr;
					pPf->f		= sf;
					pPf->c		= sc;
					pPf->d		= sd;

					pAge++;
					pIncome++;

					pPf++;

					if(retcode == SQL_SUCCESS_WITH_INFO)
					{
						wsprintf(tmp, "%ld", retcode);
						AfxMessageBox(tmp);
					}
						
				} 
				else 
				{
					break;
				}

			}   ///while (TRUE)

			pAge = pAgeHold ;
			pIncome = pIncomeHold ;
			pPf	= pPfHold;
		}//	retcode = SQLExecDirect  for DATA_Top100_Census2D_Profile

	//111111111111111111 read data base  DATA_Top100_Census2D_Profile end   111111111111

	//2. Read all Queries from DATA_Census2Dg_B_workload
		sAge = 0;cbAge = 0;sIncome = 0;cbIncome= 0;

		UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Census2Dg_B_workload"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Census2Dg_B_workload1"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Census2Dg_B_workload2"; //discounts, authors, Census2DTable						
		
		SQLSetStmtOption(hstmt_Census2D_WorkLoad, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt_Census2D_WorkLoad, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		retcode = SQLExecDirect(hstmt_Census2D_WorkLoad, szSqlAllQueryRows, SQL_NTS);

		//lEndTimer = GetTickCount() - lStartTimer;
		//wsprintf(tmp, "%ld", lEndTimer);


		if (retcode == SQL_SUCCESS) 
		{    //	retcode = SQLExecDirect for census2Dg
			int iRowCount;
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt_Census2D_WorkLoad, RowCountPtr);						 
			iRowCount = * RowCountPtr;
			delete RowCountPtr;
			
			// Bind columns 1,2.
			SQLBindCol(hstmt_Census2D_WorkLoad, 1, SQL_C_SSHORT, &sAge, 0, &cbAge);
			SQLBindCol(hstmt_Census2D_WorkLoad, 2, SQL_C_SLONG, &sIncome,0, &cbIncome); //SQL_C_SSHORT

			q1 = new  int[iRowCount];//buffer, new double[10]
			q2 = new  int[iRowCount];//buffer , new double[10]
			q1Hold = q1; q2Hold= q2;
			

			while (TRUE) 
			{
				retcode = SQLFetch(hstmt_Census2D_WorkLoad);
				if (retcode == SQL_ERROR)
				{
					//show_error();
					wsprintf(tmp, "%ld", iRowCount);
					//int i = iRowCount;
					AfxMessageBox("SQLFetch Error !!!!!!");
							//break; //99.8.26
				}
				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
				{	
					*q1	= sAge;
					*q2	= sIncome;

					q1++;
					q2++;
				} 
				else 
				{
					break;
				}

			}   ///while (TRUE)
			
			q1= q1Hold; q2= q2Hold;
				
		}//	retcode = SQLExecDirect  for query q1,q2.
	
	
	//3. evaluate r, f, -c, -d,

		double ftmp=0;
		int itmp = 0,qnum =0; 
		int topt1[2000],topt2[2000];
		int frequ[2000],freOrder[2000];

		for(i=0; i<2000; i++)
		{
			topt1[i]=0; topt2[i] =0; frequ[i]=0; freOrder[i] =0;
		}

		do
		{
			////////////for each query find the closed profiles
			//evaluate all distance from New_query(q1[qnum],q2[qnum]) to Profile Point (pAge[i],pIncome[i] )
			// dis[i] = d(Q,Q')
			for(i = 0; i<iSizeProfile; i++)
			{
			  dis[i] = (double)max( abs(pAge[i]- q1[qnum]), abs(pIncome[i]-q2[qnum]) ); 
		  
			  tuple1[i] = pAge[i];
			  tuple2[i] = pIncome[i];
			  rr[i] = pPf[i].r;  //best search radius in Profile
			  frequ[i] = pPf[i].f; 		
			}

			i=0;

			//order all distance
			// r[i]'s are sorting d(Q,Q'), to identify the closest Q' to Q
			for(i=0; i<iSizeProfile; i++)
			{
				r[i] = dis[i];  //d(Q,Q')
				topt1[i] = tuple1[i] ; topt2[i]=tuple2[i] ; //profile points
				rOrder[i] = rr[i];  //radius order
				freOrder[i] = frequ[i];

				for( j= i+1; j<iSizeProfile; j++)
				{
					if(dis[j] < r[i]) 
					{ ftmp = r[i];			r[i] = dis[j];		 dis[j] = ftmp;
					  ftmp = rOrder[i];		rOrder[i] = rr[j];	 rr[j] = ftmp;
					  itmp = freOrder[i];   freOrder[i]= frequ[j]; frequ[j] = itmp;
					  //itmp = freOrder[i];   freOrder[i]= freOrder[j]; freOrder[j] = itmp;

					  itmp = topt1[i];		topt1[i]= tuple1[j]; tuple1[j]= itmp;
					  itmp = topt2[i];		topt2[i]= tuple2[j]; tuple2[j]= itmp;

					}
				}
			}
					
		//int N, rd,f, c, d; 
		//evaluate search distance
		
		int qp1 = topt1[0], qp2= topt2[0]; //Q'(qp1,qp2), the closest proples to Q(q1,q2)
		int iKnum = 0,fpf[2000];
		double frou[2000],l[2000],V[2000], lV=0, lVrou =0, rou = 0;
		double dQQ[2000],rpf[2000];
		int dmaxQQp;

		if(r[0] == 0) // if Q=Q'
		{//if(r[0] == 0)
			rd = rOrder[0];
			int itest = 0; //use to test 
		}
		else
		{
			dmaxQQp = max(  abs( qp1 - q1[qnum]), abs(qp2 - q2[qnum])  ); //i.e.r[0]
			if(dmaxQQp <= rOrder[0])  //case of Fig.3 //rou = N/4*r*r
			{
				iKnum = 0;
				
				for(j=0; j<iSizeProfile; j++)
				{
					frou[j] =0;l[j] =0;V[j] = 0;
					dQQ[j] =0;rpf[j] = 0;fpf[j]=0;
				}

				for(j=0; j<iSizeProfile; j++) //Find set K= (all squares Q in it)
				{
					if( r[j] <= rOrder[j]  ) //d(Q,Qpf) < rpf
					{
						dQQ[iKnum] = r[j];
						rpf[iKnum] = rOrder[j];
						fpf[iKnum] = freOrder[j];

						//dQQ[j] = r[j];
						//rpf[j] = rOrder[j];
						//fpf[j] = freOrder[j];


						iKnum++;

					}
						
				}


				/*************************
				for(j=0; j<iKnum; j++)
				{
					frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
					l[j] = 1/dQQ[j];
					V[j] = 4*rpf[j]*rpf[j];
					lV += l[j]*V[j]; 
					lVrou += fpf[j]*l[j];  //l[j]*V[j]*frou[j];

				}

				rou = lVrou/lV;

				rd = (double)sqrt(100/rou)/2; //sqrt( double x );
			
				if (rd > dmaxQQp + rOrder[0])
				{
					rd = dmaxQQp + rOrder[0];

				}
				*******************/
				//---------- alternative test -----------------
				int iMeadian = iKnum/2;
				rou = 0;
				lVrou = 0; lV = 0;

				//rd = rOrder[iMeadian];
				////========
				//	rd =0;
				//	for (int k = 0; k< iKnum; k++)
				//	{	rd += rpf[k];}
				//	rd = rd/iKnum ;

				///===========
			/**************************

				for(j=0; j<iKnum; j++)
				{
					frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
					rou += frou[j];
				}

				rou = rou/iKnum;

				//rd = (double)sqrt(100/rou)/2; //sqrt( double x );
				rd = (double)sqrt(2* 100/rou)/2; //sqrt( double x );


				

				// median 

				for(j=0; j<iKnum; j++)
				{
					frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
					//rou += frou[j];
				}


				double rouOrder[2000],ftmp =0;

				for(j=0; j<iKnum; j++)
				{
					rouOrder[j] = frou[j]; 
						for(int k = j+1; k <iKnum; k++)
						{
							if(frou[k]< rouOrder[j])
							{
								ftmp = rouOrder[j]; rouOrder[j] = frou[k]; frou[k] = ftmp;
							}
						}
				}


				rou = rouOrder[iMeadian];

				//rou = rou/iKnum;

				//rd = (double)sqrt(100/rou)/2; //sqrt( double x );
				rd = (double)sqrt(3* 100/rou)/2; //sqrt( double x );
			**************/
			// ////////////// lvp
					for(j=0; j<iKnum; j++)
					{
						frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
						//l[j] = 1/dQQ[j];
						//l[j] = 1/(dQQ[j]* dQQ[j]* dQQ[j]);
						l[j] = 1/(dQQ[j]* dQQ[j]);

						V[j] = 4*rpf[j]*rpf[j];
						//lV += l[j]*V[j]; 
						//lVrou += fpf[j]*l[j];  //l[j]*V[j]*frou[j];
						
						//lV += ( 4*rpf[j]*rpf[j]/(dQQ[j]* dQQ[j]* dQQ[j]) );      //l[j]*V[j]; 						
						//lVrou += ( fpf[j]/(dQQ[j]* dQQ[j]* dQQ[j]) );
						lV += ( 4*rpf[j]*rpf[j]/(dQQ[j]* dQQ[j]) );      //l[j]*V[j]; 						
						lVrou += ( fpf[j]/(dQQ[j]* dQQ[j]) );


					}

					rou = lVrou/lV;
					rd = (double)sqrt(2*100/rou)/2; //sqrt( double x );
	
				
					if ( (rd < rOrder[0]) ||(rd < dmaxQQp))
					{
						rd = rd + rd/2;  //rOrder[0] ; + rd/n n-dimension
						//irderr ++;
					}
	
					if (rd > dmaxQQp + rOrder[0])
					{
						rd = dmaxQQp + rOrder[0];
						//irderr ++;
					}
				if (rd < dmaxQQp)
				{
				//	rd = rOrder[0];
					irderr ++;
				}

				//------------Fig 3.----------------



			}else
			{
				dmaxQQp = max(  abs( qp1 - q1[qnum]), abs(qp2 - q2[qnum])  );
				if(dmaxQQp <= 2*rOrder[0])  //h<2r'
				{
					//case of Fig.4 //rou = N/4*r*r				
					iKnum = 0;
					for(j=0; j<2000; j++)
					{
						frou[j] =0;l[j] =0;V[j] = 0;
						dQQ[j] =0;rpf[j] = 0; fpf[j]=0;			
					}

				
					for(j=0; j<iSizeProfile; j++)
					{
						if(r[j] < rOrder[0] + dmaxQQp)
						{
							dQQ[iKnum] = r[j];
							rpf[iKnum] = rOrder[j];
							fpf[iKnum] = freOrder[j];

						//dQQ[j] = r[j];
						//rpf[j] = rOrder[j];
						//fpf[j] = freOrder[j];



							iKnum++;
						}						
					}

					/**********************
					for(j=0; j<iKnum; j++)
					{
						frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
						l[j] = 1/dQQ[j];
						V[j] = 4*rpf[j]*rpf[j];
						lV += l[j]*V[j]; 
						lVrou += fpf[j]*l[j];  //l[j]*V[j]*frou[j];

					}

					rou = lVrou/lV;

					rd = (double)sqrt(100/rou)/2; //sqrt( double x );
					if (rd > dmaxQQp + rOrder[0])
						rd = dmaxQQp + rOrder[0];

				************************/
				//---------- alternative test -----------------
				lVrou = 0; lV = 0;
				rou = 0;
				int iMeadian = iKnum/2;
				//rd = rOrder[iMeadian];
				////111 ====== Mean ==
				//	rd =0;
				//	for (int k = 0; k< iKnum; k++)
				//	{	rd += rpf[k];}
				//	rd = rd/iKnum ;
				//	rd = rpf[iKnum/2];
			/*****************

				for(j=0; j<iKnum; j++)
				{
					frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
					rou += frou[j];
				}

				rou = rou/iKnum;

				//rd = (double)sqrt(100/rou)/2; //sqrt( double x );
				rd = (double)sqrt(2* 100/rou)/2; //sqrt( double x );


				///222======= median ====
				
				for(j=0; j<iKnum; j++)
				{
					frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
					//rou += frou[j];
				} 
				
				double rouOrder[2000],ftmp =0;

				for(j=0; j<iKnum; j++)
				{
					rouOrder[j] = frou[j] ;
						for(int k = j+1; k <iKnum; k++)
						{
							if(frou[k]< rouOrder[j])
							{
								ftmp = rouOrder[j]; rouOrder[j] = frou[k]; frou[k] = ftmp;
							}
						}
				}


				rou = rouOrder[iMeadian];

				//rd = (double)sqrt(100/rou)/2; //sqrt( double x );
				rd = (double)sqrt(3*100/rou)/2; //sqrt( double x );
		****************/

			
					for(j=0; j<iKnum; j++)
					{
						frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
						//l[j] = 1/dQQ[j];
						l[j] = 1/(dQQ[j]* dQQ[j]);
						//l[j] = 1/(dQQ[j]* dQQ[j]* dQQ[j]);
						
						V[j] = 4*rpf[j]*rpf[j];
						//lV += l[j]*V[j]; 

						//lV += (4*rpf[j]*rpf[j]/(dQQ[j]* dQQ[j]* dQQ[j]) );      //l[j]*V[j]; 
						/////lVrou += fpf[j]*l[j];  //l[j]*V[j]*frou[j];
						//lVrou += (fpf[j]/(dQQ[j]* dQQ[j]* dQQ[j]));

						lV += (4*rpf[j]*rpf[j]/(dQQ[j]* dQQ[j]) );      //l[j]*V[j]; 
						lVrou += (fpf[j]/(dQQ[j]* dQQ[j]));


					}

					rou = lVrou/lV;

					//rd = (double)sqrt(100/rou)/2; //sqrt( double x );
					rd = (double)sqrt(2*100/rou)/2; //sqrt( double x );
		
				
				if ( (rd < rOrder[0]) ||(rd < dmaxQQp))
				{
						rd = rd + rd/2;  //rOrder[0] ; + rd/n n-dimension
						//irderr ++;
				}
				if (rd > dmaxQQp + rOrder[0])
				{
					rd = dmaxQQp + rOrder[0];
					//irderr ++;

				}

				if (rd < dmaxQQp)
				{
				//	rd = rOrder[0];
					irderr ++;
				}

				//-----------------fig. 4 -^^^^^^---------- 
			
					int itest = 0;
				}else{

					rd = dmaxQQp + rOrder[0];

				}//if(dmaxQQp <= 2*rOrder[0])

			}//if(dmaxQQp <= rOrder[0])


		}//if(r[0] == 0)

		
		//rd = rOrder[0];
	/*		
//////////////////
		SQLFreeStmt(hstmt, SQL_DROP);
		retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 

		Sleep(100);
		//UCHAR szSqlAllRows[] = "SELECT * FROM census2Dg"; //discounts, authors, Census2DTable						
		UCHAR szSqlAllRows[] = "SELECT * FROM CLMB_census2D"; //discounts, authors, Census2DTable						

		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		
		longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);
		longTicks = GetTickCount() - longTicks;

//////////////////////////
*/

			
			CTime CurTime = CTime::GetCurrentTime();         

			N = 100; c = -1; d = - CurTime.GetTime();
			


			char cAgeLeft[20] = "", cAgeRight[20] = "", cIncomeLeft[20] = "", cIncomeRight[20] ="";
			
			sprintf(cAgeLeft,"%f", (double)(q1[qnum] - rd) );
			sprintf(cAgeRight,"%f", (double)(q1[qnum] + rd));
			sprintf(cIncomeLeft,"%f", (double)(q2[qnum] - rd));
			sprintf(cIncomeRight,"%f",(double)(q2[qnum] + rd));

			CStrSelect += "select  * from CLMB_census2d where (";
			CStrSelect += cAgeLeft;
			CStrSelect += "<= age AND age <=";
			CStrSelect += cAgeRight;
			CStrSelect += ") AND (";
			CStrSelect += cIncomeLeft;
			CStrSelect += "<= Income AND Income <=";
			CStrSelect += cIncomeRight;
			CStrSelect += ")"; 

			int iSqlLen = CStrSelect.GetLength();
			char * szSqlSquareRows = new char [iSqlLen + 1];	
			strcpy(szSqlSquareRows , "");
			strcat(szSqlSquareRows , CStrSelect);
	
			SQLFreeStmt(hstmt, SQL_DROP);
			retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 
			//Sleep(200);

			SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
			SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
			
			shortTicks = GetTickCount();
			retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlSquareRows, SQL_NTS);
			shortTicks = GetTickCount() - shortTicks;

			//lEndTimer = GetTickCount() - lStartTimer;
			//wsprintf(tmp, "%ld", irderr ++;);

			if (retcode == SQL_SUCCESS) 
			{    //	retcode = SQLExecDirect for census2Dg
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt, RowCountPtr);						 
			f = * RowCountPtr;
			delete RowCountPtr;

			}
			CStrSelect = "";
			delete [] szSqlSquareRows;

	//4. insert zeta into DATA_Top100_Census2D_Profile
			if(f<100)
			{
				i = 0;
				//AfxMessageBox("f==0!!!!!!!!!!!!!!!!!!!!!!");
			}
		
			if (f!= 0)
			{   
				char	cAttribute[10][50]= { "","","","","","","","","",""};

				
				sprintf(cAttribute[0],"%ld", q1[qnum] );
				sprintf(cAttribute[1],"%ld", q2[qnum] );
				sprintf(cAttribute[2],"%ld", N);
				sprintf(cAttribute[3],"%f",  (double)rd);
				sprintf(cAttribute[4],"%ld", f );
				//sprintf(cAttribute[5],"%ld", c );
				//sprintf(cAttribute[6],"%ld", d);
				sprintf(cAttribute[5],"%ld", longTicks);
				sprintf(cAttribute[6],"%ld", shortTicks);


				//CStrInsert += " INSERT DATA_Top100_Census2D_Learning VALUES( ";	
				//CStrInsert += " INSERT Top100Census2D_LearningFrmPf100 VALUES( ";	
				CStrInsert += " INSERT Top100_Census2D_LearningFrm2000 VALUES( ";
				CStrInsert += cAttribute[0];
				CStrInsert += ",";
				CStrInsert += cAttribute[1];
				CStrInsert += ",";
				CStrInsert += cAttribute[2];
				CStrInsert += ",";
				CStrInsert += cAttribute[3];
				CStrInsert += ",";
				CStrInsert += cAttribute[4];
				CStrInsert += ",";
				CStrInsert += cAttribute[5];
				CStrInsert += ",";
				CStrInsert += cAttribute[6];
				//CStrInsert += ",";
				//CStrInsert += cAttribute[7];
				//CStrInsert += ",";
				//CStrInsert += cAttribute[8];
				CStrInsert += ")";


			    int iSqlLen = CStrInsert.GetLength();

				char * szSqlInsert = new char [iSqlLen + 1];
				strcpy(szSqlInsert , "");
				strcat(szSqlInsert , CStrInsert);

				SQLFreeStmt(hstmt_Census2D_Profile, SQL_DROP);
				retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_Profile); /// Profile Statement handle 

				retcode = SQLExecDirect(hstmt_Census2D_Profile, (unsigned char *)szSqlInsert, SQL_NTS);

				if (retcode == SQL_SUCCESS) 
				{  //	retcode = SQLExecDirect
					//AfxMessageBox("Insert new hstmt_Census2D_Learning  OKKKKKKKKKKK!");
					//Sleep(300);
					iInsertOK++;

					//bReturn = TRUE;
				}
				else
				{
					AfxMessageBox("Insert DATA_Top100_Census2D_Learning Error!");
					iInsertERR++;
					i= 0;

				} //	retcode = SQLExecDirect 
				
				f=0;

				CStrInsert = "";
				delete [] szSqlInsert;
			}
		

			qnum++;
		}while(qnum <100); //100);

	}//if(!zlOpenDB())



	delete [] pAge;//new double[10]
	delete [] pIncome;//new double[10]
	delete [] pPf;
	delete [] q1;//new double[10]
	delete [] q2;//new double[10]


	SQLFreeStmt(hstmt, SQL_DROP);
	SQLFreeStmt(hstmt_Census2D_WorkLoad, SQL_DROP);
	SQLFreeStmt(hstmt_Census2D_Profile, SQL_DROP);

	zlCloseDB();
	wsprintf(tmp, " irderr = %d", irderr);

AfxMessageBox(tmp);

	AfxMessageBox("Insert hstmt_Generet2DWorkload OK!");

}


//////////////////////////////////////////////////////////
//
//		function
//
/////////////////////////////////////////////////////////

void CMainFrame::OnLearningTop100Census2DBiasedFrom1000() 
{
	
	//Learning: Top100 census2d biased from profile with 1000 smpl
	
	// --Read: DATA_Top100_Census2D_Profile, as Profile
	// Read:  Top100_Census2D_Profile, as Profile
	// Read: DATA_Census2Dg_B_workload, as Biased Query workload
	// write:DATA_Top100_Census2D_Learning
	// Top100, distance = max,Type = Biased 
	/////////////////////////////////////////////////////
	

	int N, f, c, d; 

	int i,j, iErr = 0;
	char tmp[100] = "";
	CString CStrSelect = ""; 
	CString CStrInsert = "";

	int longTicks =0, shortTicks =0;
	
	SWORD  sAge;
	SDWORD cbAge;

	SDWORD sIncome;
	SDWORD cbIncome;
	SDWORD sN,sr,sf,sc,sd;
	SDWORD cbN,cbr,cbf,cbc,cbd;


	HSTMT   hstmt_Census2D_WorkLoad; //for queries workload
	HSTMT   hstmt_Census2D_Profile;  //for insert Profile

	//int iTupleNum;//,iStartRowNum, iTotalNum;

	int * q1, *q2, *q1Hold, *q2Hold; //for queries workload
	
	//float rd, dis[100], r[100]; 
	//int tuple1[100],tuple2[100];
	
	double rd =0.0, dis[2000], r[2000];  //rd is the final radius distance of Q; dis[]= d(Q,Q'), r[] id dis[];
	int tuple1[2000],tuple2[2000];

	double rr[2000],rOrder[2000]; 

	int iSizeProfile = 1000; //2000;
	int iTopN = 100;

	int iInsertOK = 0, iInsertERR = 0, irderr = 0;

//struct_Census2D_Tuple


	if(!zlOpenDB())
	{
		AfxMessageBox("zlOpenDB() err!");
		zlCloseDB();
	}else
	{
		retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_WorkLoad); ///queries Statement handle 
		retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_Profile); /// Profile Statement handle 

		//1. read all tuples from Profile set store a buffer
		//1111111111111 read database from profiles :DATA_Top100_Census2D_Profile 111111111111111	
												//   Top100_Census2D_Profile2000
		//---------------
		//UCHAR szSqlAllRows[] = "SELECT * FROM DATA_Top100_Census2D_Profile"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile2000"; //discounts, authors, Census2DTable						
		UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile1000"; //discounts, authors, Census2DTable						

		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		
		longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);
		longTicks = GetTickCount() - longTicks;

		//lEndTimer = GetTickCount() - lStartTimer;
		//wsprintf(tmp, "%ld", lEndTimer);


		if (retcode == SQL_SUCCESS) 
		{    //	retcode = SQLExecDirect for DATA_Top100_Census2D_Profile
			int iRowCount;
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt, RowCountPtr);						 
			iRowCount = * RowCountPtr;
			iSizeProfile = iRowCount; // here only size of profile, 100,200, ...,2000
			delete RowCountPtr;
			
			// Bind columns 1,2.
			SQLBindCol(hstmt, 1, SQL_C_SSHORT, &sAge, 0, &cbAge);
			SQLBindCol(hstmt, 2, SQL_C_SLONG, &sIncome,0, &cbIncome); //SQL_C_SSHORT
			SQLBindCol(hstmt, 3, SQL_C_SLONG, &sN,0, &cbN); //SQL_C_SSHORT
			SQLBindCol(hstmt, 4, SQL_C_SLONG, &sr,0, &cbr); //SQL_C_SSHORT
			SQLBindCol(hstmt, 5, SQL_C_SLONG, &sf,0, &cbf); //SQL_C_SSHORT
			SQLBindCol(hstmt, 6, SQL_C_SLONG, &sc,0, &cbc); //SQL_C_SSHORT
			SQLBindCol(hstmt, 7, SQL_C_SLONG, &sd,0, &cbd); //SQL_C_SSHORT

			pPf = new Profile2D[iRowCount];
			pPfHold = pPf;

			pAge = new  int[iRowCount];//buffer, new double[10]
			pIncome = new  int[iRowCount];//buffer , new double[10]
			pAgeHold = pAge;
			pIncomeHold = pIncome;
			iRowCount =0;
			while (TRUE) 
			{
				retcode = SQLFetch(hstmt);

				if (retcode == SQL_ERROR)
				{
					//show_error();
					wsprintf(tmp, "%ld", iRowCount);
					//int i = iRowCount;
					AfxMessageBox("SQLFetch Error !!!!!!");
							//break; //99.8.26
				}

				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
				{	
					*pAge		= sAge;
					*pIncome	= sIncome;
					
					pPf->q[0]	= sAge;				
					pPf->q[1]	= sIncome;
					pPf->N		= sN;
					pPf->r		= (float) sr;
					pPf->f		= sf;
					pPf->c		= sc;
					pPf->d		= sd;

					pAge++;
					pIncome++;

					pPf++;

					if(retcode == SQL_SUCCESS_WITH_INFO)
					{
						wsprintf(tmp, "%ld", retcode);
						AfxMessageBox(tmp);
					}
						
				} 
				else 
				{
					break;
				}

			}   ///while (TRUE)

			pAge = pAgeHold ;
			pIncome = pIncomeHold ;
			pPf	= pPfHold;
		}//	retcode = SQLExecDirect  for DATA_Top100_Census2D_Profile

	//111111111111111111 read data base  DATA_Top100_Census2D_Profile end   111111111111

	//2. Read all Queries from DATA_Census2Dg_B_workload
		sAge = 0;cbAge = 0;sIncome = 0;cbIncome= 0;

		UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Census2Dg_B_workload"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Census2Dg_B_workload1"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Census2Dg_B_workload2"; //discounts, authors, Census2DTable						
		
		SQLSetStmtOption(hstmt_Census2D_WorkLoad, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt_Census2D_WorkLoad, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		retcode = SQLExecDirect(hstmt_Census2D_WorkLoad, szSqlAllQueryRows, SQL_NTS);

		//lEndTimer = GetTickCount() - lStartTimer;
		//wsprintf(tmp, "%ld", lEndTimer);


		if (retcode == SQL_SUCCESS) 
		{    //	retcode = SQLExecDirect for census2Dg
			int iRowCount;
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt_Census2D_WorkLoad, RowCountPtr);						 
			iRowCount = * RowCountPtr;
			delete RowCountPtr;
			
			// Bind columns 1,2.
			SQLBindCol(hstmt_Census2D_WorkLoad, 1, SQL_C_SSHORT, &sAge, 0, &cbAge);
			SQLBindCol(hstmt_Census2D_WorkLoad, 2, SQL_C_SLONG, &sIncome,0, &cbIncome); //SQL_C_SSHORT

			q1 = new  int[iRowCount];//buffer, new double[10]
			q2 = new  int[iRowCount];//buffer , new double[10]
			q1Hold = q1; q2Hold= q2;
			

			while (TRUE) 
			{
				retcode = SQLFetch(hstmt_Census2D_WorkLoad);
				if (retcode == SQL_ERROR)
				{
					//show_error();
					wsprintf(tmp, "%ld", iRowCount);
					//int i = iRowCount;
					AfxMessageBox("SQLFetch Error !!!!!!");
							//break; //99.8.26
				}
				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
				{	
					*q1	= sAge;
					*q2	= sIncome;

					q1++;
					q2++;
				} 
				else 
				{
					break;
				}

			}   ///while (TRUE)
			
			q1= q1Hold; q2= q2Hold;
				
		}//	retcode = SQLExecDirect  for query q1,q2.
	
	
	//3. evaluate r, f, -c, -d,

		double ftmp=0;
		int itmp = 0,qnum =0; 
		int topt1[2000],topt2[2000];
		int frequ[2000],freOrder[2000];

		for(i=0; i<2000; i++)
		{
			topt1[i]=0; topt2[i] =0; frequ[i]=0; freOrder[i] =0;
		}

		do
		{
			////////////for each query find the closed profiles
			//evaluate all distance from New_query(q1[qnum],q2[qnum]) to Profile Point (pAge[i],pIncome[i] )
			// dis[i] = d(Q,Q')
			for(i = 0; i<iSizeProfile; i++)
			{
			  dis[i] = (double)max( abs(pAge[i]- q1[qnum]), abs(pIncome[i]-q2[qnum]) ); 
		  
			  tuple1[i] = pAge[i];
			  tuple2[i] = pIncome[i];
			  rr[i] = pPf[i].r;  //best search radius in Profile
			  frequ[i] = pPf[i].f; 		
			}

			i=0;

			//order all distance
			// r[i]'s are sorting d(Q,Q'), to identify the closest Q' to Q
			for(i=0; i<iSizeProfile; i++)
			{
				r[i] = dis[i];  //d(Q,Q')
				topt1[i] = tuple1[i] ; topt2[i]=tuple2[i] ; //profile points
				rOrder[i] = rr[i];  //radius order
				freOrder[i] = frequ[i];

				for( j= i+1; j<iSizeProfile; j++)
				{
					if(dis[j] < r[i]) 
					{ ftmp = r[i];			r[i] = dis[j];		 dis[j] = ftmp;
					  ftmp = rOrder[i];		rOrder[i] = rr[j];	 rr[j] = ftmp;
					  itmp = freOrder[i];   freOrder[i]= frequ[j]; frequ[j] = itmp;

					  itmp = topt1[i];		topt1[i]= tuple1[j]; tuple1[j]= itmp;
					  itmp = topt2[i];		topt2[i]= tuple2[j]; tuple2[j]= itmp;

					}
				}
			}
					
		//int N, rd,f, c, d; 
		//evaluate search distance
		
		int qp1 = topt1[0], qp2= topt2[0]; //Q'(qp1,qp2), the closest proples to Q(q1,q2)
		int iKnum = 0,fpf[2000];
		double frou[2000],l[2000],V[2000], lV=0, lVrou =0, rou = 0;
		double dQQ[2000],rpf[2000];
		int dmaxQQp;

		if(r[0] == 0) // if Q=Q'
		{//if(r[0] == 0)
			rd = rOrder[0];
			int itest = 0; //use to test 
		}
		else
		{
			dmaxQQp = max(  abs( qp1 - q1[qnum]), abs(qp2 - q2[qnum])  ); //i.e.r[0]
			if(dmaxQQp <= rOrder[0])  //case of Fig.3 //rou = N/4*r*r
			{
				iKnum = 0;
				
				for(j=0; j<iSizeProfile; j++)
				{
					frou[j] =0;l[j] =0;V[j] = 0;
					dQQ[j] =0;rpf[j] = 0;fpf[j]=0;
				}

				for(j=0; j<iSizeProfile; j++) //Find set K= (all squares Q in it)
				{
					if( r[j] <= rOrder[j]  ) //d(Q,Qpf) < rpf
					{
						dQQ[iKnum] = r[j];
						rpf[iKnum] = rOrder[j];
						fpf[iKnum] = freOrder[j];

						iKnum++;

					}
						
				}


				/*************************
				for(j=0; j<iKnum; j++)
				{
					frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
					l[j] = 1/dQQ[j];
					V[j] = 4*rpf[j]*rpf[j];
					lV += l[j]*V[j]; 
					lVrou += fpf[j]*l[j];  //l[j]*V[j]*frou[j];

				}

				rou = lVrou/lV;

				rd = (double)sqrt(100/rou)/2; //sqrt( double x );
			
				if (rd > dmaxQQp + rOrder[0])
				{
					rd = dmaxQQp + rOrder[0];

				}
				*******************/


				//---------- alternative test -----------------
				int iMeadian = iKnum/2;
				rou = 0;
				lVrou = 0; lV = 0;

				//rd = rOrder[iMeadian];
				////========
				//	rd =0;
				//	for (int k = 0; k< iKnum; k++)
				//	{	rd += rpf[k];}
				//	rd = rd/iKnum ;

				///===========
			/**************************

				for(j=0; j<iKnum; j++)
				{
					frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
					rou += frou[j];
				}

				rou = rou/iKnum;

				//rd = (double)sqrt(100/rou)/2; //sqrt( double x );
				rd = (double)sqrt(2* 100/rou)/2; //sqrt( double x );


				

				// median 

				for(j=0; j<iKnum; j++)
				{
					frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
					//rou += frou[j];
				}


				double rouOrder[2000],ftmp =0;

				for(j=0; j<iKnum; j++)
				{
					rouOrder[j] = frou[j]; 
						for(int k = j+1; k <iKnum; k++)
						{
							if(frou[k]< rouOrder[j])
							{
								ftmp = rouOrder[j]; rouOrder[j] = frou[k]; frou[k] = ftmp;
							}
						}
				}


				rou = rouOrder[iMeadian];

				//rou = rou/iKnum;

				//rd = (double)sqrt(100/rou)/2; //sqrt( double x );
				rd = (double)sqrt(3* 100/rou)/2; //sqrt( double x );
			**************/
			// ////////////// lvp
					for(j=0; j<iKnum; j++)
					{
						frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
						//l[j] = 1/dQQ[j];
						//l[j] = 1/(dQQ[j]* dQQ[j]* dQQ[j]);
						l[j] = 1/(dQQ[j]* dQQ[j]);

						V[j] = 4*rpf[j]*rpf[j];
						//lV += l[j]*V[j]; 
						//lVrou += fpf[j]*l[j];  //l[j]*V[j]*frou[j];
						
						//lV += ( 4*rpf[j]*rpf[j]/(dQQ[j]* dQQ[j]* dQQ[j]) );      //l[j]*V[j]; 						
						//lVrou += ( fpf[j]/(dQQ[j]* dQQ[j]* dQQ[j]) );
						lV += ( 4*rpf[j]*rpf[j]/(dQQ[j]* dQQ[j]) );      //l[j]*V[j]; 						
						lVrou += ( fpf[j]/(dQQ[j]* dQQ[j]) );


					}

					rou = lVrou/lV;
					rd = (double)sqrt(2*100/rou)/2; //sqrt( double x );
	
				
					if ( (rd < rOrder[0]) ||(rd < dmaxQQp))
					{
						rd = rd + rd/2;  //rOrder[0] ; + rd/n n-dimension
						//irderr ++;
					}
	
					if (rd > dmaxQQp + rOrder[0])
					{
						rd = dmaxQQp + rOrder[0];
						//irderr ++;
					}
				if (rd < dmaxQQp)
				{
				//	rd = rOrder[0];
					irderr ++;
				}

				//------------Fig 3.----------------



			}else
			{
				dmaxQQp = max(  abs( qp1 - q1[qnum]), abs(qp2 - q2[qnum])  );
				if(dmaxQQp <= 2*rOrder[0])  //h<2r'
				{
					//case of Fig.4 //rou = N/4*r*r				
					iKnum = 0;
					for(j=0; j<2000; j++)
					{
						frou[j] =0;l[j] =0;V[j] = 0;
						dQQ[j] =0;rpf[j] = 0; fpf[j]=0;			
					}

				
					for(j=0; j<iSizeProfile; j++)
					{
						if(r[j] < rOrder[0] + dmaxQQp)
						{
							dQQ[iKnum] = r[j];
							rpf[iKnum] = rOrder[j];
							fpf[iKnum] = freOrder[j];

							iKnum++;
						}						
					}

					/**********************
					for(j=0; j<iKnum; j++)
					{
						frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
						l[j] = 1/dQQ[j];
						V[j] = 4*rpf[j]*rpf[j];
						lV += l[j]*V[j]; 
						lVrou += fpf[j]*l[j];  //l[j]*V[j]*frou[j];

					}

					rou = lVrou/lV;

					rd = (double)sqrt(100/rou)/2; //sqrt( double x );
					if (rd > dmaxQQp + rOrder[0])
						rd = dmaxQQp + rOrder[0];

				************************/

				//---------- alternative test -----------------
				lVrou = 0; lV = 0;
				rou = 0;
				int iMeadian = iKnum/2;
				//rd = rOrder[iMeadian];
				////111 ====== Mean ==
				//	rd =0;
				//	for (int k = 0; k< iKnum; k++)
				//	{	rd += rpf[k];}
				//	rd = rd/iKnum ;
				//	rd = rpf[iKnum/2];
			/*****************

				for(j=0; j<iKnum; j++)
				{
					frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
					rou += frou[j];
				}

				rou = rou/iKnum;

				//rd = (double)sqrt(100/rou)/2; //sqrt( double x );
				rd = (double)sqrt(2* 100/rou)/2; //sqrt( double x );


				///222======= median ====
				
				for(j=0; j<iKnum; j++)
				{
					frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
					//rou += frou[j];
				} 
				
				double rouOrder[2000],ftmp =0;

				for(j=0; j<iKnum; j++)
				{
					rouOrder[j] = frou[j] ;
						for(int k = j+1; k <iKnum; k++)
						{
							if(frou[k]< rouOrder[j])
							{
								ftmp = rouOrder[j]; rouOrder[j] = frou[k]; frou[k] = ftmp;
							}
						}
				}


				rou = rouOrder[iMeadian];

				//rd = (double)sqrt(100/rou)/2; //sqrt( double x );
				rd = (double)sqrt(3*100/rou)/2; //sqrt( double x );
		****************/

			
					for(j=0; j<iKnum; j++)
					{
						frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
						//l[j] = 1/dQQ[j];
						l[j] = 1/(dQQ[j]* dQQ[j]);
						//l[j] = 1/(dQQ[j]* dQQ[j]* dQQ[j]);
						
						V[j] = 4*rpf[j]*rpf[j];
						//lV += l[j]*V[j]; 

						//lV += (4*rpf[j]*rpf[j]/(dQQ[j]* dQQ[j]* dQQ[j]) );      //l[j]*V[j]; 
						/////lVrou += fpf[j]*l[j];  //l[j]*V[j]*frou[j];
						//lVrou += (fpf[j]/(dQQ[j]* dQQ[j]* dQQ[j]));

						lV += (4*rpf[j]*rpf[j]/(dQQ[j]* dQQ[j]) );      //l[j]*V[j]; 
						lVrou += (fpf[j]/(dQQ[j]* dQQ[j]));


					}

					rou = lVrou/lV;

					//rd = (double)sqrt(100/rou)/2; //sqrt( double x );
					rd = (double)sqrt(2*100/rou)/2; //sqrt( double x );
		
				
				if ( (rd < rOrder[0]) ||(rd < dmaxQQp))
				{
						rd = rd + rd/2;  //rOrder[0] ; + rd/n n-dimension
						//irderr ++;
				}
				if (rd > dmaxQQp + rOrder[0])
				{
					rd = dmaxQQp + rOrder[0];
					//irderr ++;

				}

				if (rd < dmaxQQp)
				{
				//	rd = rOrder[0];
					irderr ++;
				}

				//-----------------fig. 4 -^^^^^^---------- 
			
					int itest = 0;
				}else{

					rd = dmaxQQp + rOrder[0];

				}//if(dmaxQQp <= 2*rOrder[0])

			}//if(dmaxQQp <= rOrder[0])


		}//if(r[0] == 0)

		
		//rd = rOrder[0];
	/************************		
//////////////////
		SQLFreeStmt(hstmt, SQL_DROP);
		retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 

		Sleep(100);
		//UCHAR szSqlAllRows[] = "SELECT * FROM census2Dg"; //discounts, authors, Census2DTable						
		UCHAR szSqlAllRows[] = "SELECT * FROM CLMB_census2D"; //discounts, authors, Census2DTable						

		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		
		longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);
		longTicks = GetTickCount() - longTicks;

//////////////////////////
*******************/

			
			CTime CurTime = CTime::GetCurrentTime();         

			N = 100; c = -1; d = - CurTime.GetTime();
			


			char cAgeLeft[20] = "", cAgeRight[20] = "", cIncomeLeft[20] = "", cIncomeRight[20] ="";
			
			sprintf(cAgeLeft,"%f", (double)(q1[qnum] - rd) );
			sprintf(cAgeRight,"%f", (double)(q1[qnum] + rd));
			sprintf(cIncomeLeft,"%f", (double)(q2[qnum] - rd));
			sprintf(cIncomeRight,"%f",(double)(q2[qnum] + rd));

			CStrSelect += "select  * from CLMB_census2d where (";
			CStrSelect += cAgeLeft;
			CStrSelect += "<= age AND age <=";
			CStrSelect += cAgeRight;
			CStrSelect += ") AND (";
			CStrSelect += cIncomeLeft;
			CStrSelect += "<= Income AND Income <=";
			CStrSelect += cIncomeRight;
			CStrSelect += ")"; 

			int iSqlLen = CStrSelect.GetLength();
			char * szSqlSquareRows = new char [iSqlLen + 1];	
			strcpy(szSqlSquareRows , "");
			strcat(szSqlSquareRows , CStrSelect);
	
			SQLFreeStmt(hstmt, SQL_DROP);
			retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 
			//Sleep(200);

			SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
			SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
			
			shortTicks = GetTickCount();
			retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlSquareRows, SQL_NTS);
			shortTicks = GetTickCount() - shortTicks;

			//lEndTimer = GetTickCount() - lStartTimer;
			//wsprintf(tmp, "%ld", irderr ++;);

			if (retcode == SQL_SUCCESS) 
			{    //	retcode = SQLExecDirect for census2Dg
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt, RowCountPtr);						 
			f = * RowCountPtr;
			delete RowCountPtr;

			}
			CStrSelect = "";
			delete [] szSqlSquareRows;

	//4. insert zeta into DATA_Top100_Census2D_Profile
			if(f<100)
			{
				i = 0;
				//AfxMessageBox("f==0!!!!!!!!!!!!!!!!!!!!!!");
			}
		
			if (f!= 0)
			{   
				char	cAttribute[10][50]= { "","","","","","","","","",""};

				
				sprintf(cAttribute[0],"%ld", q1[qnum] );
				sprintf(cAttribute[1],"%ld", q2[qnum] );
				sprintf(cAttribute[2],"%ld", N);
				sprintf(cAttribute[3],"%f",  (double)rd);
				sprintf(cAttribute[4],"%ld", f );
				//sprintf(cAttribute[5],"%ld", c );
				//sprintf(cAttribute[6],"%ld", d);
				sprintf(cAttribute[5],"%ld", longTicks);
				sprintf(cAttribute[6],"%ld", shortTicks);


				//CStrInsert += " INSERT DATA_Top100_Census2D_Learning VALUES( ";	
				//CStrInsert += " INSERT Top100Census2D_LearningFrmPf100 VALUES( ";	
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm2000 VALUES( ";
				CStrInsert += " INSERT Top100_Census2D_LearningFrm1000 VALUES( ";
									   
				CStrInsert += cAttribute[0];
				CStrInsert += ",";
				CStrInsert += cAttribute[1];
				CStrInsert += ",";
				CStrInsert += cAttribute[2];
				CStrInsert += ",";
				CStrInsert += cAttribute[3];
				CStrInsert += ",";
				CStrInsert += cAttribute[4];
				CStrInsert += ",";
				CStrInsert += cAttribute[5];
				CStrInsert += ",";
				CStrInsert += cAttribute[6];
				//CStrInsert += ",";
				//CStrInsert += cAttribute[7];
				//CStrInsert += ",";
				//CStrInsert += cAttribute[8];
				CStrInsert += ")";


			    int iSqlLen = CStrInsert.GetLength();

				char * szSqlInsert = new char [iSqlLen + 1];
				strcpy(szSqlInsert , "");
				strcat(szSqlInsert , CStrInsert);

				SQLFreeStmt(hstmt_Census2D_Profile, SQL_DROP);
				retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_Profile); /// Profile Statement handle 

				retcode = SQLExecDirect(hstmt_Census2D_Profile, (unsigned char *)szSqlInsert, SQL_NTS);

				if (retcode == SQL_SUCCESS) 
				{  //	retcode = SQLExecDirect
					//AfxMessageBox("Insert new hstmt_Census2D_Learning  OKKKKKKKKKKK!");
					//Sleep(300);
					iInsertOK++;

					//bReturn = TRUE;
				}
				else
				{
					AfxMessageBox("Insert DATA_Top100_Census2D_Learning Error!");
					iInsertERR++;
					i= 0;

				} //	retcode = SQLExecDirect 
				
				f=0;

				CStrInsert = "";
				delete [] szSqlInsert;
			}
		

			qnum++;
		}while(qnum <iTopN); //100);

	}//if(!zlOpenDB())



	delete [] pAge;//new double[10]
	delete [] pIncome;//new double[10]
	delete [] pPf;
	delete [] q1;//new double[10]
	delete [] q2;//new double[10]


	SQLFreeStmt(hstmt, SQL_DROP);
	SQLFreeStmt(hstmt_Census2D_WorkLoad, SQL_DROP);
	SQLFreeStmt(hstmt_Census2D_Profile, SQL_DROP);

	zlCloseDB();
	wsprintf(tmp, " irderr = %d", irderr);

AfxMessageBox(tmp);

	AfxMessageBox("Insert hstmt_Generet2DWorkload OK!");

}





void CMainFrame::OnLearningTop100census2DBiasedFrom0800() 
{
	//Learning: Top100 census2d biased from profile with 0800 smpl
	
	// --Read: DATA_Top100_Census2D_Profile, as Profile
	// Read:  Top100_Census2D_Profile, as Profile
	// Read: DATA_Census2Dg_B_workload, as Biased Query workload
	// write:DATA_Top100_Census2D_Learning
	// Top100, distance = max,Type = Biased 
	/////////////////////////////////////////////////////
	

	int N, f, c, d; 

	int i,j, iErr = 0;
	char tmp[100] = "";
	CString CStrSelect = ""; 
	CString CStrInsert = "";

	int longTicks =0, shortTicks =0;
	
	SWORD  sAge;
	SDWORD cbAge;

	SDWORD sIncome;
	SDWORD cbIncome;
	SDWORD sN,sr,sf,sc,sd;
	SDWORD cbN,cbr,cbf,cbc,cbd;


	HSTMT   hstmt_Census2D_WorkLoad; //for queries workload
	HSTMT   hstmt_Census2D_Profile;  //for insert Profile

	//int iTupleNum;//,iStartRowNum, iTotalNum;

	int * q1, *q2, *q1Hold, *q2Hold; //for queries workload
	
	//float rd, dis[100], r[100]; 
	//int tuple1[100],tuple2[100];
	
	double rd =0.0, dis[2000], r[2000];  //rd is the final radius distance of Q; dis[]= d(Q,Q'), r[] id dis[];
	int tuple1[2000],tuple2[2000];

	double rr[2000],rOrder[2000]; 

	int iSizeProfile = 800; //1000; //2000;
	int iTopN = 100;

	int iInsertOK = 0, iInsertERR = 0, irderr = 0;

//struct_Census2D_Tuple


	if(!zlOpenDB())
	{
		AfxMessageBox("zlOpenDB() err!");
		zlCloseDB();
	}else
	{
		retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_WorkLoad); ///queries Statement handle 
		retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_Profile); /// Profile Statement handle 

		//1. read all tuples from Profile set store a buffer
		//1111111111111 read database from profiles :DATA_Top100_Census2D_Profile 111111111111111	
												//   Top100_Census2D_Profile2000
		//---------------
		//UCHAR szSqlAllRows[] = "SELECT * FROM DATA_Top100_Census2D_Profile"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile2000"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile1000"; //discounts, authors, Census2DTable						
		UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile0800"; //discounts, authors, Census2DTable						

		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		
		longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);
		longTicks = GetTickCount() - longTicks;

		//lEndTimer = GetTickCount() - lStartTimer;
		//wsprintf(tmp, "%ld", lEndTimer);


		if (retcode == SQL_SUCCESS) 
		{    //	retcode = SQLExecDirect for DATA_Top100_Census2D_Profile
			int iRowCount;
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt, RowCountPtr);						 
			iRowCount = * RowCountPtr;
			iSizeProfile = iRowCount; // here only size of profile, 100,200, ...,2000
			delete RowCountPtr;
			
			// Bind columns 1,2.
			SQLBindCol(hstmt, 1, SQL_C_SSHORT, &sAge, 0, &cbAge);
			SQLBindCol(hstmt, 2, SQL_C_SLONG, &sIncome,0, &cbIncome); //SQL_C_SSHORT
			SQLBindCol(hstmt, 3, SQL_C_SLONG, &sN,0, &cbN); //SQL_C_SSHORT
			SQLBindCol(hstmt, 4, SQL_C_SLONG, &sr,0, &cbr); //SQL_C_SSHORT
			SQLBindCol(hstmt, 5, SQL_C_SLONG, &sf,0, &cbf); //SQL_C_SSHORT
			SQLBindCol(hstmt, 6, SQL_C_SLONG, &sc,0, &cbc); //SQL_C_SSHORT
			SQLBindCol(hstmt, 7, SQL_C_SLONG, &sd,0, &cbd); //SQL_C_SSHORT

			pPf = new Profile2D[iRowCount];
			pPfHold = pPf;

			pAge = new  int[iRowCount];//buffer, new double[10]
			pIncome = new  int[iRowCount];//buffer , new double[10]
			pAgeHold = pAge;
			pIncomeHold = pIncome;
			iRowCount =0;
			while (TRUE) 
			{
				retcode = SQLFetch(hstmt);

				if (retcode == SQL_ERROR)
				{
					//show_error();
					wsprintf(tmp, "%ld", iRowCount);
					//int i = iRowCount;
					AfxMessageBox("SQLFetch Error !!!!!!");
							//break; //99.8.26
				}

				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
				{	
					*pAge		= sAge;
					*pIncome	= sIncome;
					
					pPf->q[0]	= sAge;				
					pPf->q[1]	= sIncome;
					pPf->N		= sN;
					pPf->r		= (float) sr;
					pPf->f		= sf;
					pPf->c		= sc;
					pPf->d		= sd;

					pAge++;
					pIncome++;

					pPf++;

					if(retcode == SQL_SUCCESS_WITH_INFO)
					{
						wsprintf(tmp, "%ld", retcode);
						AfxMessageBox(tmp);
					}
						
				} 
				else 
				{
					break;
				}

			}   ///while (TRUE)

			pAge = pAgeHold ;
			pIncome = pIncomeHold ;
			pPf	= pPfHold;
		}//	retcode = SQLExecDirect  for DATA_Top100_Census2D_Profile

	//111111111111111111 read data base  DATA_Top100_Census2D_Profile end   111111111111

	//2. Read all Queries from DATA_Census2Dg_B_workload
		sAge = 0;cbAge = 0;sIncome = 0;cbIncome= 0;

		UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Census2Dg_B_workload"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Census2Dg_B_workload1"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Census2Dg_B_workload2"; //discounts, authors, Census2DTable						
		
		SQLSetStmtOption(hstmt_Census2D_WorkLoad, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt_Census2D_WorkLoad, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		retcode = SQLExecDirect(hstmt_Census2D_WorkLoad, szSqlAllQueryRows, SQL_NTS);

		//lEndTimer = GetTickCount() - lStartTimer;
		//wsprintf(tmp, "%ld", lEndTimer);


		if (retcode == SQL_SUCCESS) 
		{    //	retcode = SQLExecDirect for census2Dg
			int iRowCount;
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt_Census2D_WorkLoad, RowCountPtr);						 
			iRowCount = * RowCountPtr;
			delete RowCountPtr;
			
			// Bind columns 1,2.
			SQLBindCol(hstmt_Census2D_WorkLoad, 1, SQL_C_SSHORT, &sAge, 0, &cbAge);
			SQLBindCol(hstmt_Census2D_WorkLoad, 2, SQL_C_SLONG, &sIncome,0, &cbIncome); //SQL_C_SSHORT

			q1 = new  int[iRowCount];//buffer, new double[10]
			q2 = new  int[iRowCount];//buffer , new double[10]
			q1Hold = q1; q2Hold= q2;
			

			while (TRUE) 
			{
				retcode = SQLFetch(hstmt_Census2D_WorkLoad);
				if (retcode == SQL_ERROR)
				{
					//show_error();
					wsprintf(tmp, "%ld", iRowCount);
					//int i = iRowCount;
					AfxMessageBox("SQLFetch Error !!!!!!");
							//break; //99.8.26
				}
				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
				{	
					*q1	= sAge;
					*q2	= sIncome;

					q1++;
					q2++;
				} 
				else 
				{
					break;
				}

			}   ///while (TRUE)
			
			q1= q1Hold; q2= q2Hold;
				
		}//	retcode = SQLExecDirect  for query q1,q2.
	
	
	//3. evaluate r, f, -c, -d,

		double ftmp=0;
		int itmp = 0,qnum =0; 
		int topt1[2000],topt2[2000];
		int frequ[2000],freOrder[2000];

		for(i=0; i<2000; i++)
		{
			topt1[i]=0; topt2[i] =0; frequ[i]=0; freOrder[i] =0;
		}

		do
		{
			////////////for each query find the closed profiles
			//evaluate all distance from New_query(q1[qnum],q2[qnum]) to Profile Point (pAge[i],pIncome[i] )
			// dis[i] = d(Q,Q')
			for(i = 0; i<iSizeProfile; i++)
			{
			  dis[i] = (double)max( abs(pAge[i]- q1[qnum]), abs(pIncome[i]-q2[qnum]) ); 
		  
			  tuple1[i] = pAge[i];
			  tuple2[i] = pIncome[i];
			  rr[i] = pPf[i].r;  //best search radius in Profile
			  frequ[i] = pPf[i].f; 		
			}

			i=0;

			//order all distance
			// r[i]'s are sorting d(Q,Q'), to identify the closest Q' to Q
			for(i=0; i<iSizeProfile; i++)
			{
				r[i] = dis[i];  //d(Q,Q')
				topt1[i] = tuple1[i] ; topt2[i]=tuple2[i] ; //profile points
				rOrder[i] = rr[i];  //radius order
				freOrder[i] = frequ[i];

				for( j= i+1; j<iSizeProfile; j++)
				{
					if(dis[j] < r[i]) 
					{ ftmp = r[i];			r[i] = dis[j];		 dis[j] = ftmp;
					  ftmp = rOrder[i];		rOrder[i] = rr[j];	 rr[j] = ftmp;
					  itmp = freOrder[i];   freOrder[i]= frequ[j]; frequ[j] = itmp;

					  itmp = topt1[i];		topt1[i]= tuple1[j]; tuple1[j]= itmp;
					  itmp = topt2[i];		topt2[i]= tuple2[j]; tuple2[j]= itmp;

					}
				}
			}
					
		//int N, rd,f, c, d; 
		//evaluate search distance
		
		int qp1 = topt1[0], qp2= topt2[0]; //Q'(qp1,qp2), the closest proples to Q(q1,q2)
		int iKnum = 0,fpf[2000];
		double frou[2000],l[2000],V[2000], lV=0, lVrou =0, rou = 0;
		double dQQ[2000],rpf[2000];
		int dmaxQQp;

		if(r[0] == 0) // if Q=Q'
		{//if(r[0] == 0)
			rd = rOrder[0];
			int itest = 0; //use to test 
		}
		else
		{
			dmaxQQp = max(  abs( qp1 - q1[qnum]), abs(qp2 - q2[qnum])  ); //i.e.r[0]
			if(dmaxQQp <= rOrder[0])  //case of Fig.3 //rou = N/4*r*r
			{
				iKnum = 0;
				
				for(j=0; j<iSizeProfile; j++)
				{
					frou[j] =0;l[j] =0;V[j] = 0;
					dQQ[j] =0;rpf[j] = 0;fpf[j]=0;
				}

				for(j=0; j<iSizeProfile; j++) //Find set K= (all squares Q in it)
				{
					if( r[j] <= rOrder[j]  ) //d(Q,Qpf) < rpf
					{
						dQQ[iKnum] = r[j];
						rpf[iKnum] = rOrder[j];
						fpf[iKnum] = freOrder[j];

						iKnum++;

					}
						
				}


				/*************************
				for(j=0; j<iKnum; j++)
				{
					frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
					l[j] = 1/dQQ[j];
					V[j] = 4*rpf[j]*rpf[j];
					lV += l[j]*V[j]; 
					lVrou += fpf[j]*l[j];  //l[j]*V[j]*frou[j];

				}

				rou = lVrou/lV;

				rd = (double)sqrt(100/rou)/2; //sqrt( double x );
			
				if (rd > dmaxQQp + rOrder[0])
				{
					rd = dmaxQQp + rOrder[0];

				}
				*******************/


				//---------- alternative test -----------------
				int iMeadian = iKnum/2;
				rou = 0;
				lVrou = 0; lV = 0;

				//rd = rOrder[iMeadian];
				////========
				//	rd =0;
				//	for (int k = 0; k< iKnum; k++)
				//	{	rd += rpf[k];}
				//	rd = rd/iKnum ;

				///===========
			/**************************

				for(j=0; j<iKnum; j++)
				{
					frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
					rou += frou[j];
				}

				rou = rou/iKnum;

				//rd = (double)sqrt(100/rou)/2; //sqrt( double x );
				rd = (double)sqrt(2* 100/rou)/2; //sqrt( double x );


				

				// median 

				for(j=0; j<iKnum; j++)
				{
					frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
					//rou += frou[j];
				}


				double rouOrder[2000],ftmp =0;

				for(j=0; j<iKnum; j++)
				{
					rouOrder[j] = frou[j]; 
						for(int k = j+1; k <iKnum; k++)
						{
							if(frou[k]< rouOrder[j])
							{
								ftmp = rouOrder[j]; rouOrder[j] = frou[k]; frou[k] = ftmp;
							}
						}
				}


				rou = rouOrder[iMeadian];

				//rou = rou/iKnum;

				//rd = (double)sqrt(100/rou)/2; //sqrt( double x );
				rd = (double)sqrt(3* 100/rou)/2; //sqrt( double x );
			**************/
			// ////////////// lvp
					for(j=0; j<iKnum; j++)
					{
						frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
						//l[j] = 1/dQQ[j];
						//l[j] = 1/(dQQ[j]* dQQ[j]* dQQ[j]);
						l[j] = 1/(dQQ[j]* dQQ[j]);

						V[j] = 4*rpf[j]*rpf[j];
						//lV += l[j]*V[j]; 
						//lVrou += fpf[j]*l[j];  //l[j]*V[j]*frou[j];
						
						//lV += ( 4*rpf[j]*rpf[j]/(dQQ[j]* dQQ[j]* dQQ[j]) );      //l[j]*V[j]; 						
						//lVrou += ( fpf[j]/(dQQ[j]* dQQ[j]* dQQ[j]) );
						lV += ( 4*rpf[j]*rpf[j]/(dQQ[j]* dQQ[j]) );      //l[j]*V[j]; 						
						lVrou += ( fpf[j]/(dQQ[j]* dQQ[j]) );


					}

					rou = lVrou/lV;
					rd = (double)sqrt(2*100/rou)/2; //sqrt( double x );
	
				
					if ( (rd < rOrder[0]) ||(rd < dmaxQQp))
					{
						rd = rd + rd/2;  //rOrder[0] ; + rd/n n-dimension
						//irderr ++;
					}
	
					if (rd > dmaxQQp + rOrder[0])
					{
						rd = dmaxQQp + rOrder[0];
						//irderr ++;
					}
				if (rd < dmaxQQp)
				{
				//	rd = rOrder[0];
					irderr ++;
				}

				//------------Fig 3.----------------



			}else
			{
				dmaxQQp = max(  abs( qp1 - q1[qnum]), abs(qp2 - q2[qnum])  );
				if(dmaxQQp <= 2*rOrder[0])  //h<2r'
				{
					//case of Fig.4 //rou = N/4*r*r				
					iKnum = 0;
					for(j=0; j<2000; j++)
					{
						frou[j] =0;l[j] =0;V[j] = 0;
						dQQ[j] =0;rpf[j] = 0; fpf[j]=0;			
					}

				
					for(j=0; j<iSizeProfile; j++)
					{
						if(r[j] < rOrder[0] + dmaxQQp)
						{
							dQQ[iKnum] = r[j];
							rpf[iKnum] = rOrder[j];
							fpf[iKnum] = freOrder[j];

							iKnum++;
						}						
					}

					/**********************
					for(j=0; j<iKnum; j++)
					{
						frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
						l[j] = 1/dQQ[j];
						V[j] = 4*rpf[j]*rpf[j];
						lV += l[j]*V[j]; 
						lVrou += fpf[j]*l[j];  //l[j]*V[j]*frou[j];

					}

					rou = lVrou/lV;

					rd = (double)sqrt(100/rou)/2; //sqrt( double x );
					if (rd > dmaxQQp + rOrder[0])
						rd = dmaxQQp + rOrder[0];

				************************/

				//---------- alternative test -----------------
				lVrou = 0; lV = 0;
				rou = 0;
				int iMeadian = iKnum/2;
				//rd = rOrder[iMeadian];
				////111 ====== Mean ==
				//	rd =0;
				//	for (int k = 0; k< iKnum; k++)
				//	{	rd += rpf[k];}
				//	rd = rd/iKnum ;
				//	rd = rpf[iKnum/2];

			/*****************

				for(j=0; j<iKnum; j++)
				{
					frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
					rou += frou[j];
				}

				rou = rou/iKnum;

				//rd = (double)sqrt(100/rou)/2; //sqrt( double x );
				rd = (double)sqrt(2* 100/rou)/2; //sqrt( double x );


				///222======= median ====
				
				for(j=0; j<iKnum; j++)
				{
					frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
					//rou += frou[j];
				} 
				
				double rouOrder[2000],ftmp =0;

				for(j=0; j<iKnum; j++)
				{
					rouOrder[j] = frou[j] ;
						for(int k = j+1; k <iKnum; k++)
						{
							if(frou[k]< rouOrder[j])
							{
								ftmp = rouOrder[j]; rouOrder[j] = frou[k]; frou[k] = ftmp;
							}
						}
				}


				rou = rouOrder[iMeadian];

				//rd = (double)sqrt(100/rou)/2; //sqrt( double x );
				rd = (double)sqrt(3*100/rou)/2; //sqrt( double x );

		****************/

			
					for(j=0; j<iKnum; j++)
					{
						frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
						//l[j] = 1/dQQ[j];
						l[j] = 1/(dQQ[j]* dQQ[j]);
						//l[j] = 1/(dQQ[j]* dQQ[j]* dQQ[j]);
						
						V[j] = 4*rpf[j]*rpf[j];
						//lV += l[j]*V[j]; 

						//lV += (4*rpf[j]*rpf[j]/(dQQ[j]* dQQ[j]* dQQ[j]) );      //l[j]*V[j]; 
						/////lVrou += fpf[j]*l[j];  //l[j]*V[j]*frou[j];
						//lVrou += (fpf[j]/(dQQ[j]* dQQ[j]* dQQ[j]));

						lV += (4*rpf[j]*rpf[j]/(dQQ[j]* dQQ[j]) );      //l[j]*V[j]; 
						lVrou += (fpf[j]/(dQQ[j]* dQQ[j]));


					}

					rou = lVrou/lV;

					//rd = (double)sqrt(100/rou)/2; //sqrt( double x );
					rd = (double)sqrt(2*100/rou)/2; //sqrt( double x );
		
				
				if ( (rd < rOrder[0]) ||(rd < dmaxQQp))
				{
						rd = rd + rd/2;  //rOrder[0] ; + rd/n n-dimension
						//irderr ++;
				}
				if (rd > dmaxQQp + rOrder[0])
				{
					rd = dmaxQQp + rOrder[0];
					//irderr ++;

				}

				if (rd < dmaxQQp)
				{
				//	rd = rOrder[0];
					irderr ++;
				}

				//-----------------fig. 4 -^^^^^^---------- 
			
					int itest = 0;
				}else{

					rd = dmaxQQp + rOrder[0];

				}//if(dmaxQQp <= 2*rOrder[0])

			}//if(dmaxQQp <= rOrder[0])


		}//if(r[0] == 0)

		
		//rd = rOrder[0];
	/************************		
//////////////////
		SQLFreeStmt(hstmt, SQL_DROP);
		retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 

		Sleep(100);
		//UCHAR szSqlAllRows[] = "SELECT * FROM census2Dg"; //discounts, authors, Census2DTable						
		UCHAR szSqlAllRows[] = "SELECT * FROM CLMB_census2D"; //discounts, authors, Census2DTable						

		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		
		longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);
		longTicks = GetTickCount() - longTicks;

//////////////////////////
*******************/

			
			CTime CurTime = CTime::GetCurrentTime();         

			N = 100; c = -1; d = - CurTime.GetTime();
			


			char cAgeLeft[20] = "", cAgeRight[20] = "", cIncomeLeft[20] = "", cIncomeRight[20] ="";
			
			sprintf(cAgeLeft,"%f", (double)(q1[qnum] - rd) );
			sprintf(cAgeRight,"%f", (double)(q1[qnum] + rd));
			sprintf(cIncomeLeft,"%f", (double)(q2[qnum] - rd));
			sprintf(cIncomeRight,"%f",(double)(q2[qnum] + rd));

			CStrSelect += "select  * from CLMB_census2d where (";
			CStrSelect += cAgeLeft;
			CStrSelect += "<= age AND age <=";
			CStrSelect += cAgeRight;
			CStrSelect += ") AND (";
			CStrSelect += cIncomeLeft;
			CStrSelect += "<= Income AND Income <=";
			CStrSelect += cIncomeRight;
			CStrSelect += ")"; 

			int iSqlLen = CStrSelect.GetLength();
			char * szSqlSquareRows = new char [iSqlLen + 1];	
			strcpy(szSqlSquareRows , "");
			strcat(szSqlSquareRows , CStrSelect);
	
			SQLFreeStmt(hstmt, SQL_DROP);
			retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 
			//Sleep(200);

			SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
			SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
			
			shortTicks = GetTickCount();
			retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlSquareRows, SQL_NTS);
			shortTicks = GetTickCount() - shortTicks;

			//lEndTimer = GetTickCount() - lStartTimer;
			//wsprintf(tmp, "%ld", irderr ++;);

			if (retcode == SQL_SUCCESS) 
			{    //	retcode = SQLExecDirect for census2Dg
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt, RowCountPtr);						 
			f = * RowCountPtr;
			delete RowCountPtr;

			}
			CStrSelect = "";
			delete [] szSqlSquareRows;

	//4. insert zeta into DATA_Top100_Census2D_Profile
			if(f<100)
			{
				i = 0;
				//AfxMessageBox("f==0!!!!!!!!!!!!!!!!!!!!!!");
			}
		
			if (f!= 0)
			{   
				char	cAttribute[10][50]= { "","","","","","","","","",""};

				
				sprintf(cAttribute[0],"%ld", q1[qnum] );
				sprintf(cAttribute[1],"%ld", q2[qnum] );
				sprintf(cAttribute[2],"%ld", N);
				sprintf(cAttribute[3],"%f",  (double)rd);
				sprintf(cAttribute[4],"%ld", f );
				//sprintf(cAttribute[5],"%ld", c );
				//sprintf(cAttribute[6],"%ld", d);
				sprintf(cAttribute[5],"%ld", longTicks);
				sprintf(cAttribute[6],"%ld", shortTicks);


				//CStrInsert += " INSERT DATA_Top100_Census2D_Learning VALUES( ";	
				//CStrInsert += " INSERT Top100Census2D_LearningFrmPf100 VALUES( ";	
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm2000 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm1000 VALUES( ";
				CStrInsert += " INSERT Top100_Census2D_LearningFrm0800 VALUES( ";
									  
				CStrInsert += cAttribute[0];
				CStrInsert += ",";
				CStrInsert += cAttribute[1];
				CStrInsert += ",";
				CStrInsert += cAttribute[2];
				CStrInsert += ",";
				CStrInsert += cAttribute[3];
				CStrInsert += ",";
				CStrInsert += cAttribute[4];
				CStrInsert += ",";
				CStrInsert += cAttribute[5];
				CStrInsert += ",";
				CStrInsert += cAttribute[6];
				//CStrInsert += ",";
				//CStrInsert += cAttribute[7];
				//CStrInsert += ",";
				//CStrInsert += cAttribute[8];
				CStrInsert += ")";


			    int iSqlLen = CStrInsert.GetLength();

				char * szSqlInsert = new char [iSqlLen + 1];
				strcpy(szSqlInsert , "");
				strcat(szSqlInsert , CStrInsert);

				SQLFreeStmt(hstmt_Census2D_Profile, SQL_DROP);
				retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_Profile); /// Profile Statement handle 

				retcode = SQLExecDirect(hstmt_Census2D_Profile, (unsigned char *)szSqlInsert, SQL_NTS);

				if (retcode == SQL_SUCCESS) 
				{  //	retcode = SQLExecDirect
					//AfxMessageBox("Insert new hstmt_Census2D_Learning  OKKKKKKKKKKK!");
					//Sleep(300);
					iInsertOK++;

					//bReturn = TRUE;
				}
				else
				{
					AfxMessageBox("Insert DATA_Top100_Census2D_Learning Error!");
					iInsertERR++;
					i= 0;

				} //	retcode = SQLExecDirect 
				
				f=0;

				CStrInsert = "";
				delete [] szSqlInsert;
			}
		

			qnum++;
		}while(qnum <iTopN); //100);

	}//if(!zlOpenDB())



	delete [] pAge;//new double[10]
	delete [] pIncome;//new double[10]
	delete [] pPf;
	delete [] q1;//new double[10]
	delete [] q2;//new double[10]


	SQLFreeStmt(hstmt, SQL_DROP);
	SQLFreeStmt(hstmt_Census2D_WorkLoad, SQL_DROP);
	SQLFreeStmt(hstmt_Census2D_Profile, SQL_DROP);

	zlCloseDB();
	wsprintf(tmp, " irderr = %d", irderr);

	AfxMessageBox(tmp);

	AfxMessageBox("Insert hstmt_Generet2DLearning  OK!");
	
}




void CMainFrame::OnLearningTop100census2dbiasedfrom04000100() 
{
	//Learning: Top100 census2d biased from profile with 0400,200, 100 smpl
	
	// --Read: DATA_Top100_Census2D_Profile, as Profile
	// Read:  Top100_Census2D_Profile, as Profile
	// Read: DATA_Census2Dg_B_workload, as Biased Query workload
	// write:DATA_Top100_Census2D_Learning
	// Top100, distance = max,Type = Biased 
	//	                           = Uniform
	/////////////////////////////////////////////////////
	

	int N, f, c, d; 

	int i,j, iErr = 0;
	char tmp[100] = "";
	CString CStrSelect = ""; 
	CString CStrInsert = "";

	int longTicks =0, shortTicks =0;
	
	SWORD  sAge;
	SDWORD cbAge;

	SDWORD sIncome;
	SDWORD cbIncome;
	SDWORD sN,sr,sf,sc,sd;
	SDWORD cbN,cbr,cbf,cbc,cbd;


	HSTMT   hstmt_Census2D_WorkLoad; //for queries workload
	HSTMT   hstmt_Census2D_Profile;  //for insert Profile

	//int iTupleNum;//,iStartRowNum, iTotalNum;

	int * q1, *q2, *q1Hold, *q2Hold; //for queries workload
	
	double rd =0.0, dis[2000], r[2000];  //rd is the final radius distance of Q; dis[]= d(Q,Q'), r[] id dis[];
	int tuple1[2000],tuple2[2000];

	double rr[2000],rOrder[2000]; 

	int iSizeProfile = 1459;//250; //100; //200; //400; //800; //1000; //2000;
	//int iSizeProfile = 250; //100; //200; //400; //800; //1000; //2000;

	int iTopN = 100;

	int iInsertOK = 0, iInsertERR = 0, irderr = 0;

//struct_Census2D_Tuple


	if(!zlOpenDB())
	{
		AfxMessageBox("zlOpenDB() err!");
		zlCloseDB();
	}else
	{
		retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_WorkLoad); ///queries Statement handle 
		retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_Profile); /// Profile Statement handle 

		//1. read all tuples from Profile set store a buffer
		//1111111111111 read database from profiles :DATA_Top100_Census2D_Profile 111111111111111	
												//   Top100_Census2D_Profile2000
		//---------------
		//UCHAR szSqlAllRows[] = "SELECT * FROM DATA_Top100_Census2D_Profile"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile2000"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile1000"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile0800"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile0400"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile0200"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile0100"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile0250"; //discounts, authors, Census2DTable						
		UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile1459"; //discounts, authors, Census2DTable						
	
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top50_Census2D_Profile1459"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top250_Census2D_Profile1459"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top1000_Census2D_Profile1459"; //discounts, authors, Census2DTable						

		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		
		longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);
		longTicks = GetTickCount() - longTicks;

		//lEndTimer = GetTickCount() - lStartTimer;
		//wsprintf(tmp, "%ld", lEndTimer);


		if (retcode == SQL_SUCCESS) 
		{    //	retcode = SQLExecDirect for DATA_Top100_Census2D_Profile
			int iRowCount;
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt, RowCountPtr);						 
			iRowCount = * RowCountPtr;
			iSizeProfile = iRowCount; // here only size of profile, 100,200, ...,2000
			delete RowCountPtr;
			
			// Bind columns 1,2.
			SQLBindCol(hstmt, 1, SQL_C_SSHORT, &sAge, 0, &cbAge);
			SQLBindCol(hstmt, 2, SQL_C_SLONG, &sIncome,0, &cbIncome); //SQL_C_SSHORT
			SQLBindCol(hstmt, 3, SQL_C_SLONG, &sN,0, &cbN); //SQL_C_SSHORT
			SQLBindCol(hstmt, 4, SQL_C_SLONG, &sr,0, &cbr); //SQL_C_SSHORT
			SQLBindCol(hstmt, 5, SQL_C_SLONG, &sf,0, &cbf); //SQL_C_SSHORT
			SQLBindCol(hstmt, 6, SQL_C_SLONG, &sc,0, &cbc); //SQL_C_SSHORT
			SQLBindCol(hstmt, 7, SQL_C_SLONG, &sd,0, &cbd); //SQL_C_SSHORT

			pPf = new Profile2D[iRowCount];
			pPfHold = pPf;

			pAge = new  int[iRowCount];//buffer, new double[10]
			pIncome = new  int[iRowCount];//buffer , new double[10]
			pAgeHold = pAge;
			pIncomeHold = pIncome;
			iRowCount =0;
			while (TRUE) 
			{
				retcode = SQLFetch(hstmt);

				if (retcode == SQL_ERROR)
				{
					//show_error();
					wsprintf(tmp, "%ld", iRowCount);
					//int i = iRowCount;
					AfxMessageBox("SQLFetch Error !!!!!!");
							//break; //99.8.26
				}

				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
				{	
					*pAge		= sAge;
					*pIncome	= sIncome;
					
					pPf->q[0]	= sAge;				
					pPf->q[1]	= sIncome;
					pPf->N		= sN;
					pPf->r		= (float) sr;
					pPf->f		= sf;
					pPf->c		= sc;
					pPf->d		= sd;

					pAge++;
					pIncome++;

					pPf++;

					if(retcode == SQL_SUCCESS_WITH_INFO)
					{
						wsprintf(tmp, "%ld", retcode);
						AfxMessageBox(tmp);
					}
						
				} 
				else 
				{
					break;
				}

			}   ///while (TRUE)

			pAge = pAgeHold ;
			pIncome = pIncomeHold ;
			pPf	= pPfHold;
		}//	retcode = SQLExecDirect  for DATA_Top100_Census2D_Profile

	//111111111111111111 read data base  DATA_Top100_Census2D_Profile end   111111111111

	//2. Read all Queries from DATA_Census2Dg_B_workload
		sAge = 0;cbAge = 0;sIncome = 0;cbIncome= 0;

		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Census2Dg_B_workload"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Census2Dg_B_workload1"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Census2Dg_B_workload2"; //discounts, authors, Census2DTable						
		
		UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Census2Dg_U_workload"; //discounts, authors, Census2DTable						
		
		SQLSetStmtOption(hstmt_Census2D_WorkLoad, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt_Census2D_WorkLoad, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		retcode = SQLExecDirect(hstmt_Census2D_WorkLoad, szSqlAllQueryRows, SQL_NTS);

		//lEndTimer = GetTickCount() - lStartTimer;
		//wsprintf(tmp, "%ld", lEndTimer);


		if (retcode == SQL_SUCCESS) 
		{    //	retcode = SQLExecDirect for census2Dg
			int iRowCount;
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt_Census2D_WorkLoad, RowCountPtr);						 
			iRowCount = * RowCountPtr;
			delete RowCountPtr;
			
			// Bind columns 1,2.
			SQLBindCol(hstmt_Census2D_WorkLoad, 1, SQL_C_SSHORT, &sAge, 0, &cbAge);
			SQLBindCol(hstmt_Census2D_WorkLoad, 2, SQL_C_SLONG, &sIncome,0, &cbIncome); //SQL_C_SSHORT

			q1 = new  int[iRowCount];//buffer, new double[10]
			q2 = new  int[iRowCount];//buffer , new double[10]
			q1Hold = q1; q2Hold= q2;
			

			while (TRUE) 
			{
				retcode = SQLFetch(hstmt_Census2D_WorkLoad);
				if (retcode == SQL_ERROR)
				{
					//show_error();
					wsprintf(tmp, "%ld", iRowCount);
					//int i = iRowCount;
					AfxMessageBox("SQLFetch Error !!!!!!");
							//break; //99.8.26
				}
				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
				{	
					*q1	= sAge;
					*q2	= sIncome;

					q1++;
					q2++;
				} 
				else 
				{
					break;
				}

			}   ///while (TRUE)
			
			q1= q1Hold; q2= q2Hold;
				
		}//	retcode = SQLExecDirect  for query q1,q2.
	
	
	//3. evaluate r, f, -c, -d,

		double ftmp=0;
		int itmp = 0,qnum =0; 
		int topt1[2000],topt2[2000];
		int frequ[2000],freOrder[2000];

		for(i=0; i<2000; i++)
		{
			topt1[i]=0; topt2[i] =0; frequ[i]=0; freOrder[i] =0;
		}

		do
		{
			////////////for each query find the closed profiles
			//evaluate all distance from New_query(q1[qnum],q2[qnum]) to Profile Point (pAge[i],pIncome[i] )
			// dis[i] = d(Q,Q')
			for(i = 0; i<iSizeProfile; i++)
			{
			  dis[i] = (double)max( abs(pAge[i]- q1[qnum]), abs(pIncome[i]-q2[qnum]) ); 
		  
			  tuple1[i] = pAge[i];
			  tuple2[i] = pIncome[i];
			  rr[i] = pPf[i].r;  //best search radius in Profile
			  frequ[i] = pPf[i].f; 		
			}

			i=0;

			//order all distance
			// r[i]'s are sorting d(Q,Q'), to identify the closest Q' to Q
			for(i=0; i<iSizeProfile; i++)
			{
				r[i] = dis[i];  //d(Q,Q')
				topt1[i] = tuple1[i] ; topt2[i]=tuple2[i] ; //profile points
				rOrder[i] = rr[i];  //radius order
				freOrder[i] = frequ[i];

				for( j= i+1; j<iSizeProfile; j++)
				{
					if(dis[j] < r[i]) 
					{ ftmp = r[i];			r[i] = dis[j];		 dis[j] = ftmp;
					  ftmp = rOrder[i];		rOrder[i] = rr[j];	 rr[j] = ftmp;
					  itmp = freOrder[i];   freOrder[i]= frequ[j]; frequ[j] = itmp;

					  itmp = topt1[i];		topt1[i]= tuple1[j]; tuple1[j]= itmp;
					  itmp = topt2[i];		topt2[i]= tuple2[j]; tuple2[j]= itmp;

					}
				}
			}
					
		//int N, rd,f, c, d; 
		//evaluate search distance
		
		int qp1 = topt1[0], qp2= topt2[0]; //Q'(qp1,qp2), the closest proples to Q(q1,q2)
		int iKnum = 0,fpf[2000];
		double frou[2000],l[2000],V[2000], lV=0, lVrou =0, rou = 0;
		double dQQ[2000],rpf[2000];
		int dmaxQQp;

		if(r[0] == 0) // if Q=Q'
		{//if(r[0] == 0)
			rd = rOrder[0];
			//rd = 2*rOrder[0];
			//rd = rOrder[0]/2;
			//rd = rOrder[0]/10;

			int itest = 0; //use to test 
		}
		else
		{
			dmaxQQp = max(  abs( qp1 - q1[qnum]), abs(qp2 - q2[qnum])  ); //i.e.r[0]
			if(dmaxQQp <= rOrder[0])  //case of Fig.3 //rou = N/4*r*r
			{
				iKnum = 0;
				
				for(j=0; j<iSizeProfile; j++)
				{
					frou[j] =0;l[j] =0;V[j] = 0;
					dQQ[j] =0;rpf[j] = 0;fpf[j]=0;
				}

				for(j=0; j<iSizeProfile; j++) //Find set K= (all squares Q in it)
				{
					if( r[j] <= rOrder[j]  ) //d(Q,Qpf) < rpf
					{
						dQQ[iKnum] = r[j];
						rpf[iKnum] = rOrder[j];
						fpf[iKnum] = freOrder[j];

						iKnum++;

					}
						
				}


				/*************************
				for(j=0; j<iKnum; j++)
				{
					frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
					l[j] = 1/dQQ[j];
					V[j] = 4*rpf[j]*rpf[j];
					lV += l[j]*V[j]; 
					lVrou += fpf[j]*l[j];  //l[j]*V[j]*frou[j];

				}

				rou = lVrou/lV;

				rd = (double)sqrt(100/rou)/2; //sqrt( double x );
			
				if (rd > dmaxQQp + rOrder[0])
				{
					rd = dmaxQQp + rOrder[0];

				}
				*******************/


				//---------- alternative test -----------------
				int iMeadian = iKnum/2;
				rou = 0;
				lVrou = 0; lV = 0;

				//rd = rOrder[iMeadian];
				////========
				//	rd =0;
				//	for (int k = 0; k< iKnum; k++)
				//	{	rd += rpf[k];}
				//	rd = rd/iKnum ;

				///===========
			/**************************

				for(j=0; j<iKnum; j++)
				{
					frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
					rou += frou[j];
				}

				rou = rou/iKnum;

				//rd = (double)sqrt(100/rou)/2; //sqrt( double x );
				rd = (double)sqrt(2* 100/rou)/2; //sqrt( double x );


				

				// median 

				for(j=0; j<iKnum; j++)
				{
					frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
					//rou += frou[j];
				}


				double rouOrder[2000],ftmp =0;

				for(j=0; j<iKnum; j++)
				{
					rouOrder[j] = frou[j]; 
						for(int k = j+1; k <iKnum; k++)
						{
							if(frou[k]< rouOrder[j])
							{
								ftmp = rouOrder[j]; rouOrder[j] = frou[k]; frou[k] = ftmp;
							}
						}
				}


				rou = rouOrder[iMeadian];

				//rou = rou/iKnum;

				//rd = (double)sqrt(100/rou)/2; //sqrt( double x );
				rd = (double)sqrt(3* 100/rou)/2; //sqrt( double x );
			**************/
			// ////////////// lvp
					for(j=0; j<iKnum; j++)
					{
						frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
						//l[j] = 1/dQQ[j];
						//l[j] = 1/(dQQ[j]* dQQ[j]* dQQ[j]);
						l[j] = 1/(dQQ[j]* dQQ[j]);

						V[j] = 4*rpf[j]*rpf[j];
						//lV += l[j]*V[j]; 
						//lVrou += fpf[j]*l[j];  //l[j]*V[j]*frou[j];
						
						//lV += ( 4*rpf[j]*rpf[j]/(dQQ[j]* dQQ[j]* dQQ[j]) );      //l[j]*V[j]; 						
						//lVrou += ( fpf[j]/(dQQ[j]* dQQ[j]* dQQ[j]) );
						lV += ( 4*rpf[j]*rpf[j]/(dQQ[j]* dQQ[j]) );      //l[j]*V[j]; 						
						lVrou += ( fpf[j]/(dQQ[j]* dQQ[j]) );


					}

					rou = lVrou/lV;
					rd = (double)sqrt(2*100/rou)/2; //sqrt( double x );
	
					if ( (rd < rOrder[0]) ||(rd < dmaxQQp))
					{
						rd = rd + rd/2;  //rOrder[0] ; + rd/n n-dimension
						//irderr ++;
					}
	
					if (rd > dmaxQQp + rOrder[0])
					{
						rd = dmaxQQp + rOrder[0];
						//irderr ++;
					}
					if (rd < dmaxQQp)
					{
					//	rd = rOrder[0];
						irderr ++;
					}

				//------------Fig 3.^^^^^----------------



			}else
			{
				dmaxQQp = max(  abs( qp1 - q1[qnum]), abs(qp2 - q2[qnum])  );
				if(dmaxQQp <= 2*rOrder[0])  //h<2r'
				{
					//case of Fig.4 //rou = N/4*r*r				
					iKnum = 0;
					for(j=0; j<2000; j++)
					{
						frou[j] =0;l[j] =0;V[j] = 0;
						dQQ[j] =0;rpf[j] = 0; fpf[j]=0;			
					}

				
					for(j=0; j<iSizeProfile; j++)
					{
						if(r[j] < rOrder[0] + dmaxQQp)
						{
							dQQ[iKnum] = r[j];
							rpf[iKnum] = rOrder[j];
							fpf[iKnum] = freOrder[j];

							iKnum++;
						}						
					}

					/**********************
					for(j=0; j<iKnum; j++)
					{
						frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
						l[j] = 1/dQQ[j];
						V[j] = 4*rpf[j]*rpf[j];
						lV += l[j]*V[j]; 
						lVrou += fpf[j]*l[j];  //l[j]*V[j]*frou[j];

					}

					rou = lVrou/lV;

					rd = (double)sqrt(100/rou)/2; //sqrt( double x );
					if (rd > dmaxQQp + rOrder[0])
						rd = dmaxQQp + rOrder[0];

				************************/

				//---------- alternative test -----------------
				lVrou = 0; lV = 0;
				rou = 0;
				int iMeadian = iKnum/2;
				//rd = rOrder[iMeadian];
				////111 ====== Mean ==
				//	rd =0;
				//	for (int k = 0; k< iKnum; k++)
				//	{	rd += rpf[k];}
				//	rd = rd/iKnum ;
				//	rd = rpf[iKnum/2];

			/*****************

				for(j=0; j<iKnum; j++)
				{
					frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
					rou += frou[j];
				}

				rou = rou/iKnum;

				//rd = (double)sqrt(100/rou)/2; //sqrt( double x );
				rd = (double)sqrt(2* 100/rou)/2; //sqrt( double x );


				///222======= median ====
				
				for(j=0; j<iKnum; j++)
				{
					frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
					//rou += frou[j];
				} 
				
				double rouOrder[2000],ftmp =0;

				for(j=0; j<iKnum; j++)
				{
					rouOrder[j] = frou[j] ;
						for(int k = j+1; k <iKnum; k++)
						{
							if(frou[k]< rouOrder[j])
							{
								ftmp = rouOrder[j]; rouOrder[j] = frou[k]; frou[k] = ftmp;
							}
						}
				}


				rou = rouOrder[iMeadian];

				//rd = (double)sqrt(100/rou)/2; //sqrt( double x );
				rd = (double)sqrt(3*100/rou)/2; //sqrt( double x );

		*****************/

			
					for(j=0; j<iKnum; j++)
					{
						frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
						//l[j] = 1/dQQ[j];
						l[j] = 1/(dQQ[j]* dQQ[j]);
						//l[j] = 1/(dQQ[j]* dQQ[j]* dQQ[j]);
						
						V[j] = 4*rpf[j]*rpf[j];
						//lV += l[j]*V[j]; 

						//lV += (4*rpf[j]*rpf[j]/(dQQ[j]* dQQ[j]* dQQ[j]) );      //l[j]*V[j]; 
						/////lVrou += fpf[j]*l[j];  //l[j]*V[j]*frou[j];
						//lVrou += (fpf[j]/(dQQ[j]* dQQ[j]* dQQ[j]));

						lV += (4*rpf[j]*rpf[j]/(dQQ[j]* dQQ[j]) );      //l[j]*V[j]; 
						lVrou += (fpf[j]/(dQQ[j]* dQQ[j]));


					}

					rou = lVrou/lV;

					//rd = (double)sqrt(100/rou)/2; //sqrt( double x );
					rd = (double)sqrt(2*100/rou)/2; //sqrt( double x );
		
				if ( (rd < rOrder[0]) ||(rd < dmaxQQp))
				{
						rd = rd + rd/2;  //rOrder[0] ; + rd/n n-dimension
						//irderr ++;
				}
				if (rd > dmaxQQp + rOrder[0])
				{
					rd = dmaxQQp + rOrder[0];
					//irderr ++;

				}

				if (rd < dmaxQQp)
				{
				//	rd = rOrder[0];
					irderr ++;
				}

				//-----------------fig. 4 -^^^^^^---------- 
			
					int itest = 0;
				}else{

					rd = dmaxQQp + rOrder[0];

				}//if(dmaxQQp <= 2*rOrder[0])

			}//if(dmaxQQp <= rOrder[0])


		}//if(r[0] == 0)

		
		//rd = rOrder[0];
	/************************		
//////////////////
		SQLFreeStmt(hstmt, SQL_DROP);
		retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 

		Sleep(100);
		//UCHAR szSqlAllRows[] = "SELECT * FROM census2Dg"; //discounts, authors, Census2DTable						
		UCHAR szSqlAllRows[] = "SELECT * FROM CLMB_census2D"; //discounts, authors, Census2DTable						

		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		
		longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);
		longTicks = GetTickCount() - longTicks;

//////////////////////////
*******************/

			
			CTime CurTime = CTime::GetCurrentTime();         

			N = 100; c = -1; d = - CurTime.GetTime();
			


			char cAgeLeft[20] = "", cAgeRight[20] = "", cIncomeLeft[20] = "", cIncomeRight[20] ="";
			
			sprintf(cAgeLeft,"%f", (double)(q1[qnum] - rd) );
			sprintf(cAgeRight,"%f", (double)(q1[qnum] + rd));
			sprintf(cIncomeLeft,"%f", (double)(q2[qnum] - rd));
			sprintf(cIncomeRight,"%f",(double)(q2[qnum] + rd));

			CStrSelect += "select  * from CLMB_census2d where (";
			CStrSelect += cAgeLeft;
			CStrSelect += "<= age AND age <=";
			CStrSelect += cAgeRight;
			CStrSelect += ") AND (";
			CStrSelect += cIncomeLeft;
			CStrSelect += "<= Income AND Income <=";
			CStrSelect += cIncomeRight;
			CStrSelect += ")"; 

			int iSqlLen = CStrSelect.GetLength();
			char * szSqlSquareRows = new char [iSqlLen + 1];	
			strcpy(szSqlSquareRows , "");
			strcat(szSqlSquareRows , CStrSelect);
	
			SQLFreeStmt(hstmt, SQL_DROP);
			retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 
			//Sleep(200);

			SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
			SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
			
			shortTicks = GetTickCount();
			retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlSquareRows, SQL_NTS);
			shortTicks = GetTickCount() - shortTicks;

			//lEndTimer = GetTickCount() - lStartTimer;
			//wsprintf(tmp, "%ld", irderr ++;);

			if (retcode == SQL_SUCCESS) 
			{    //	retcode = SQLExecDirect for census2Dg
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt, RowCountPtr);						 
			f = * RowCountPtr;
			delete RowCountPtr;

			}
			CStrSelect = "";
			delete [] szSqlSquareRows;

	//4. insert zeta into DATA_Top100_Census2D_Profile
			//if(f<100)
			if(f<iTopN)
			{
				i = 0;
				//AfxMessageBox("f==0!!!!!!!!!!!!!!!!!!!!!!");
			}
		
			if (f!= 0)
			{   
				char	cAttribute[10][50]= { "","","","","","","","","",""};

				
				sprintf(cAttribute[0],"%ld", q1[qnum] );
				sprintf(cAttribute[1],"%ld", q2[qnum] );
				sprintf(cAttribute[2],"%ld", N);
				sprintf(cAttribute[3],"%f",  (double)rd);
				sprintf(cAttribute[4],"%ld", f );
				//sprintf(cAttribute[5],"%ld", c );
				//sprintf(cAttribute[6],"%ld", d);
				sprintf(cAttribute[5],"%ld", longTicks);
				sprintf(cAttribute[6],"%ld", shortTicks);


				//CStrInsert += " INSERT DATA_Top100_Census2D_Learning VALUES( ";	
				//CStrInsert += " INSERT Top100Census2D_LearningFrmPf100 VALUES( ";	
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm2000 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm1000 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm0800 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm0400 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm0200 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm0100 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm0250 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm1459 VALUES( ";
		
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm1459_Top50 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm1459_Top250 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm1459_Top1000 VALUES( ";
				
				CStrInsert += " INSERT Top100_U_Census2D_LearningFrm1459 VALUES( ";

				CStrInsert += cAttribute[0];
				CStrInsert += ",";
				CStrInsert += cAttribute[1];
				CStrInsert += ",";
				CStrInsert += cAttribute[2];
				CStrInsert += ",";
				CStrInsert += cAttribute[3];
				CStrInsert += ",";
				CStrInsert += cAttribute[4];
				CStrInsert += ",";
				CStrInsert += cAttribute[5];
				CStrInsert += ",";
				CStrInsert += cAttribute[6];
				//CStrInsert += ",";
				//CStrInsert += cAttribute[7];
				//CStrInsert += ",";
				//CStrInsert += cAttribute[8];
				CStrInsert += ")";


			    int iSqlLen = CStrInsert.GetLength();

				char * szSqlInsert = new char [iSqlLen + 1];
				strcpy(szSqlInsert , "");
				strcat(szSqlInsert , CStrInsert);

				SQLFreeStmt(hstmt_Census2D_Profile, SQL_DROP);
				retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_Profile); /// Profile Statement handle 

				retcode = SQLExecDirect(hstmt_Census2D_Profile, (unsigned char *)szSqlInsert, SQL_NTS);

				if (retcode == SQL_SUCCESS) 
				{  //	retcode = SQLExecDirect
					//AfxMessageBox("Insert new hstmt_Census2D_Learning  OKKKKKKKKKKK!");
					//Sleep(300);
					iInsertOK++;

					//bReturn = TRUE;
				}
				else
				{
					AfxMessageBox("Insert DATA_Top100_Census2D_Learning Error!");
					iInsertERR++;
					i= 0;

				} //	retcode = SQLExecDirect 
				
				f=0;

				CStrInsert = "";
				delete [] szSqlInsert;
			}
		

			qnum++;
		}while(qnum <iTopN); //100);

	}//if(!zlOpenDB())



	delete [] pAge;//new double[10]
	delete [] pIncome;//new double[10]
	delete [] pPf;
	delete [] q1;//new double[10]
	delete [] q2;//new double[10]


	SQLFreeStmt(hstmt, SQL_DROP);
	SQLFreeStmt(hstmt_Census2D_WorkLoad, SQL_DROP);
	SQLFreeStmt(hstmt_Census2D_Profile, SQL_DROP);

	zlCloseDB();
	wsprintf(tmp, " irderr = %d", irderr);

	AfxMessageBox(tmp);

	AfxMessageBox("Insert hstmt_Generet2DLearning  OK!");	
	
}

void CMainFrame::OnSmpl1459census2DProfileEuclSum() 
{
	//Create census2D profile with	1459 samples
	// with distance functions:EUCL, SUM
    // 2005.4.6 USE This
/*****************************
* 1. read all tuples from census2D store a buffer
* 2. Read all tuple from DATA_Top100_Census2D_WorkLoad 
* 3. evaluate r, f, c, -d,
* 4. insert zeta into DATA_Top100_Census2D_Profile
******************************/
//Change: 
	// 1. int iSizeSmpl = 100;

// Menu: Smpl1459_Census2D_Profile_EUCL_SUM

	long lStartTimer = GetTickCount();
	long lEndTimer;


	int N, f, c, d = 0; 

	int i,j, k, iErr = 0;
	char tmp[100] = "";
	CString CStrSelect = ""; 
	CString CStrInsert = "";

	int longTicks =0, shortTicks =0;
	
	SWORD  sAge;
	SDWORD cbAge;

	SDWORD sIncome;
	SDWORD cbIncome;


	HSTMT   hstmt_Census2D_WorkLoad; //for queries workload
	HSTMT   hstmt_Census2D_Profile;  //for insert Profile

	int iTupleNum;//,iStartRowNum, iTotalNum;

	int * q1, *q2, *q1Hold, *q2Hold;
	
	//int iSizeSmpl = 1459; //250; //200; //400; //800; //1000; //2000;
	
	int iSizeSmpl = 100; // for OPT of workload	
	//int iSizeSmpl = 178; //  FOR profile sets

	int iTopN = 100; //1000; 250; //50; //100; //250;//50; //50; 100; 250; 1000
	
	//float rd, dis[100], r[100]; 
	//int tuple1[100],tuple2[100];
	
	double rd, dis[2000], r[2000], x[105]; 
	int tuple1[2000],tuple2[2000];


//struct_Census2D_Tuple


	if(!zlOpenDB())
	{
		AfxMessageBox("zlOpenDB() err!");
		 ;
	}else
	{
		retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_WorkLoad); ///queries Statement handle 
		retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_Profile); /// Profile Statement handle 

		//1. read all tuples from census2Dg store a buffer
		//1111111111111 read data base from census2Dg 111111111111111	

		//UCHAR szSqlAllRows[] = "select  * from census2dg where (15 - 9 <=age and age<=15+ 9 ) and (15- 9 <=Income and Income <=15+ 9 )";
		
		//----------------------------------------------------
		//UCHAR szSqlAllRows[] = "SELECT * FROM census2Dg"; //discounts, authors, Census2DTable						
		UCHAR szSqlAllRows[] = "SELECT * FROM CLMB_census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = " SELECT * FROM CLMB_census2D where Census2DID <=24431 "; //discounts, authors, Census2DTable						

		//------------------------------------------------------


		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		
		longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);
		longTicks = GetTickCount() - longTicks;

		//lEndTimer = GetTickCount() - lStartTimer;
		//wsprintf(tmp, "%ld", lEndTimer);


		if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO ) 
		{    //	retcode = SQLExecDirect for census2Dg
			int iRowCount;
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt, RowCountPtr);						 
			iRowCount = * RowCountPtr;
			iTupleNum = iRowCount;
			delete RowCountPtr;
			
			// Bind columns 1,2.
			SQLBindCol(hstmt, 1, SQL_C_SSHORT, &sAge, 0, &cbAge);
			SQLBindCol(hstmt, 2, SQL_C_SLONG, &sIncome,0, &cbIncome); //SQL_C_SSHORT

			pAge = new  int[iRowCount];//buffer, new float[10]
			pIncome = new  int[iRowCount];//buffer , new float[10]
			pAgeHold = pAge;
			pIncomeHold = pIncome;
			iRowCount =0;
			while (TRUE) 
			{
				retcode = SQLFetch(hstmt);

				if (retcode == SQL_ERROR)
				{
					//show_error();

					wsprintf(tmp, "%ld", iRowCount);
					//int i = iRowCount;
					AfxMessageBox("SQLFetch Error !!!!!!");
							//break; //99.8.26
				}

				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
						//if (retcode == SQL_SUCCESS)
				{	

					*pAge		= sAge;
					*pIncome	= sIncome;

					pAge++;
					pIncome++;

					if(retcode == SQL_SUCCESS_WITH_INFO)
					{
						wsprintf(tmp, "%ld", retcode);
						AfxMessageBox(tmp);

					}
						
				} 
				else 
				{
					break;
				}

			}   ///while (TRUE)

			pAge = pAgeHold ;
			pIncome = pIncomeHold ;
	
		}//	retcode = SQLExecDirect  for census2Dg

	//111111111111111111 read data base  census2Dg end   111111111111

	//2. Read all tuple from smpl_DB_tables : DATA_Top100_Census2D_WorkLoad ,100 smpl
										//	  smpl2000_Census2D				 2000 smpl
		
		sAge = 0;cbAge = 0;sIncome = 0;cbIncome= 0;

		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Top100_Census2D_WorkLoad"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl2000_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl1000_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl0800_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl0400_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl0200_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl0100_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl0250_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl1459_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl0730_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl0365_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Census2D_smpl0178"; //discounts, authors, Census2DTable						

		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Census2Dg_B_workload"; //OPT OF WORKLOAD ,biased				
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Census2Dg_U_workload"; //OPT OF WORKLOAD ,biased				
		
		//2005.08.07
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Census2D_B_WorkLoad"; //OPT OF WORKLOAD ,biased				
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Census2D_B_WorkLoad_1"; //OPT OF WORKLOAD ,biased				
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Census2D_B_WorkLoad_2"; //OPT OF WORKLOAD ,biased				
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Census2D_B_WorkLoad_3"; //06.03.23				
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Census2D_B_WorkLoad_4"; //06.03.23					
		UCHAR szSqlAllQueryRows[] = "SELECT * FROM Census2D_B_WorkLoad_5"; //06.03.23				
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Census2D_smpl0178"; //OPT OF WORKLOAD ,biased				


		
		SQLSetStmtOption(hstmt_Census2D_WorkLoad, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt_Census2D_WorkLoad, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		retcode = SQLExecDirect(hstmt_Census2D_WorkLoad, szSqlAllQueryRows, SQL_NTS);

		//lEndTimer = GetTickCount() - lStartTimer;
		//wsprintf(tmp, "%ld", lEndTimer);


		if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) 
		{    //	retcode = SQLExecDirect for census2Dg
			int iRowCount;
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt_Census2D_WorkLoad, RowCountPtr);						 
			iRowCount = * RowCountPtr;
			delete RowCountPtr;
			
			// Bind columns 1,2.
			SQLBindCol(hstmt_Census2D_WorkLoad, 1, SQL_C_SSHORT, &sAge, 0, &cbAge);
			SQLBindCol(hstmt_Census2D_WorkLoad, 2, SQL_C_SLONG, &sIncome,0, &cbIncome); //SQL_C_SSHORT

			q1 = new  int[iRowCount];//buffer, new float[10]
			q2 = new  int[iRowCount];//buffer , new float[10]
			q1Hold = q1; q2Hold= q2;
			

			while (TRUE) 
			{
				retcode = SQLFetch(hstmt_Census2D_WorkLoad);

				if (retcode == SQL_ERROR)
				{
					//show_error();

					wsprintf(tmp, "%ld", iRowCount);
					//int i = iRowCount;
					AfxMessageBox("SQLFetch Error !!!!!!");
							//break; //99.8.26
				}

				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
						//if (retcode == SQL_SUCCESS)
				{	
					*q1	= sAge;
					*q2	= sIncome;

					q1++;
					q2++;
				} 
				else 
				{
					break;
				}

			}   ///while (TRUE)
			
			q1= q1Hold; q2= q2Hold;
				
		}//	retcode = SQLExecDirect  for query q1,q2.
	
	//3. evaluate r, f, -c, -d,

		double ftmp=0;
		int itmp = 0,qnum =0; 
		int topt1[1000],topt2[1000];


		do
		{
//gotoid:
			lStartTimer = GetTickCount();

			//take first 100 as Top100
			//for(i = 0; i<100; i++)
			for(i = 0; i<iTopN; i++)
			{
			  x[1] = abs(pAge[i]- q1[qnum]); x[2] = abs(pIncome[i]-q2[qnum]);
			  
			  //---- 3 DISTANCES
			  dis[i] = (float)max( abs(pAge[i]- q1[qnum]), abs(pIncome[i]-q2[qnum]) ); //MAX distance
			  //dis[i] = (double)sqrt( x[1]*x[1] + x[2] * x[2] ); // EUCL distance
			  //dis[i] = (double)( x[1] + x[2] ); //SUM distance 

			  tuple1[i] = pAge[i];
			  tuple2[i] = pIncome[i];
			}
			i=0;
			
			//for(i=0; i<100; i++)
			for(i=0; i<iTopN; i++)
			{
				r[i] = dis[i];
				topt1[i] = tuple1[i] ; topt2[i]=tuple2[i] ;
				//for( j= i+1; j<100; j++)
				for( j= i+1; j<iTopN; j++)
				{
					if(dis[j] < r[i]) 
					{ ftmp = r[i];    r[i] = dis[j];  dis[j] = ftmp;
					  itmp = topt1[i]; topt1[i]= tuple1[j]; tuple1[j]= itmp;
					  itmp = topt2[i]; topt2[i]= tuple2[j]; tuple2[j]= itmp;
					}
				}
			}
			
			i=0;
			//2. select top100 (topN)from all tuples with size iTupleNum
			//for(i=100; i<iTupleNum; i++)
			for(i = iTopN; i<iTupleNum; i++)
			{
				x[1] = abs(pAge[i]- q1[qnum]); x[2] = abs(pIncome[i]-q2[qnum]);

				//------ 3 distances 
				ftmp = (float)max( abs(pAge[i]- q1[qnum]), abs(pIncome[i]-q2[qnum]) ); //max distace			
				//ftmp = (double)sqrt( x[1]*x[1] + x[2] * x[2] ); //Eucl distance
				//ftmp = (double)( x[1] + x[2] ); // sum distance

				
				if(ftmp <0)
					int itest = 0;
				//if(ftmp < r[99])
				if(ftmp < r[iTopN - 1])		
				{
					//for(j=0;j<100;j++)
					for(j=0;j<iTopN;j++)
					{
						if(ftmp<r[j])
						{
							//for(k=99; k>j; k--)
							for(k=iTopN - 1; k>j; k--)
							{
								r[k] = r[k-1];
								topt1[k] = topt1[k-1];
								topt2[k] = topt2[k-1];
							}
							r[j]=ftmp;
							topt1[j] = pAge[i];
							topt2[j] = pIncome[i];
							break;
						}
					}
				}
			}
		
			lEndTimer = GetTickCount() -lStartTimer ;

         ////--------2004.5.10 ------    
			/*
			char temp[1024] = "";
			sprintf(temp, " qnum = %d, lEndTimer = %d",qnum, lEndTimer); 
			AfxMessageBox(temp);
			qnum++;
			if(qnum >=iSizeSmpl )
				break;
			goto gotoid;	
            */
			//Finding Top100 Tuples from all size of census2d (210318), using time:
			//lEndTimer == 15, 0, or 16
			//Caution: this the chip of thread from one to other
			
			//So, we can see it has no time.
			//Finding Top100 Tuples from all size of census2d (24431), using time:
			//lEndTimer == 15, 0, or 16


         /// --------- 2004.5.10 ---------


		//int N, rd,f, c, d; 	
			
//////////////////
			/***********
		SQLFreeStmt(hstmt, SQL_DROP);
		retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 
		
		//UCHAR szSqlAllRows[] = "SELECT * FROM census2Dg"; //discounts, authors, Census2DTable						
		UCHAR szSqlAllRows[] = "SELECT * FROM CLMB_census2D"; //discounts, authors, Census2DTable						

		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		
		longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);
		longTicks = GetTickCount() - longTicks;
		**************/
/////////////////////////
			
			CTime CurTime = CTime::GetCurrentTime();         

			//N = 100; rd = r[99]; //r[99] means the distance from last_tuple (top100) to the query
			N = iTopN; 
			
			//rd = r[iTopN-1]; //r[99] means the distance from last_tuple (top100) to the query
		
			c = -1; d--; //d = - CurTime.GetTime(); d++;
			
			for(i = 0; i<iTopN; i++)
			{
			  dis[i] = (float)max( abs(topt1[i]- q1[qnum]), abs(topt2[i]-q2[qnum]) ); //MAX distance
			  
			}
			
			//find the square's radius, which is the max of all distance from Q to top-N tuples
			rd = dis[0];
				
			for( j= 1; j<iTopN; j++)
			{
				if(dis[j] > rd) 
				{ 
					ftmp = rd; rd = dis[j];  dis[j] = ftmp;
				}
			}
			
			char cAgeLeft[20] = "", cAgeRight[20] = "", cIncomeLeft[20] = "", cIncomeRight[20] ="";
			
			sprintf(cAgeLeft,"%f", (float)(q1[qnum] - rd) );
			sprintf(cAgeRight,"%f", (float)(q1[qnum] + rd));
			sprintf(cIncomeLeft,"%f", (float)(q2[qnum] - rd));
			sprintf(cIncomeRight,"%f",(float)(q2[qnum] + rd));

			CStrSelect += "select  * from CLMB_census2D where (";
			
			CStrSelect += cAgeLeft;
			CStrSelect += "<= age AND age <=";
			CStrSelect += cAgeRight;
			CStrSelect += ") AND (";
			CStrSelect += cIncomeLeft;
			CStrSelect += "<= Income AND Income <=";
			CStrSelect += cIncomeRight;
			CStrSelect += ")"; 

			int iSqlLen = CStrSelect.GetLength();
			char * szSqlSquareRows = new char [iSqlLen + 1];	
			strcpy(szSqlSquareRows , "");
			strcat(szSqlSquareRows , CStrSelect);
			//Sleep(200);
	
			SQLFreeStmt(hstmt, SQL_DROP);
			retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 


			//szSqlSquareRows= "select  * from census2dg where ";// (15 - 9 <=age and age<=15+ 9 ) and (15- 9 <=Income and Income <=15+ 9 )";
			SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
			SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
			
			shortTicks = GetTickCount();
			retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlSquareRows, SQL_NTS);
			shortTicks = GetTickCount() - shortTicks;

			//lEndTimer = GetTickCount() - lStartTimer;
			//wsprintf(tmp, "%ld", lEndTimer);

			if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) //2005.4.6 add ||
			{    //	retcode = SQLExecDirect for census2Dg
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt, RowCountPtr);						 
			f = * RowCountPtr;
			delete RowCountPtr;

			}
			CStrSelect = "";
			delete [] szSqlSquareRows;

	//4. insert zeta into the Profiles: DATA_Top100_Census2D_Profile
									//	Top100_Census2D_Profile2000
		
			if (f!= 0)
			{   
				char	cAttribute[10][50]= { "","","","","","","","","",""};

				
				sprintf(cAttribute[0],"%ld", q1[qnum] );
				sprintf(cAttribute[1],"%ld", q2[qnum] );
				sprintf(cAttribute[2],"%ld", N);
				sprintf(cAttribute[3],"%f",  (float)rd);
				sprintf(cAttribute[4],"%ld", f );
				sprintf(cAttribute[5],"%ld", c );
				sprintf(cAttribute[6],"%ld", d);
				sprintf(cAttribute[7],"%ld", longTicks);
				sprintf(cAttribute[8],"%ld", shortTicks);

				//---------tables---------------
				//CStrInsert += " INSERT DATA_Top100_Census2D_Profile VALUES( ";	
				//CStrInsert += " INSERT Top100_Census2D_Profile VALUES( ";	
				//CStrInsert += " INSERT Top100_Census2D_Profile2000 VALUES( ";	
				//CStrInsert += " INSERT Top100_Census2D_Profile1000 VALUES( ";	
				//CStrInsert += " INSERT Top100_Census2D_Profile0800 VALUES( ";	
				//CStrInsert += " INSERT Top100_Census2D_Profile0400 VALUES( ";	
				//CStrInsert += " INSERT Top100_Census2D_Profile0200 VALUES( ";	
				//CStrInsert += " INSERT Top100_Census2D_Profile0250 VALUES( ";	
				//CStrInsert += " INSERT Top100_Census2D_Profile1459 VALUES( ";	
				//CStrInsert += " INSERT Top100_Census2D_Profile0730 VALUES( ";	
				//CStrInsert += " INSERT Top100_Census2D_Profile0365 VALUES( ";	
				//CStrInsert += " INSERT Census2D_Top100_Profile0178 VALUES( ";	
				//CStrInsert += " INSERT Census2D_Top100_P0178_EUCL VALUES( ";	
				//CStrInsert += " INSERT Census2D_Top100_P0178_SUM VALUES( ";	

				//CStrInsert += " INSERT Top50_Census2D_Profile1459 VALUES( ";	
				//CStrInsert += " INSERT Top250_Census2D_Profile1459 VALUES( ";	
				//CStrInsert += " INSERT Top1000_Census2D_Profile1459 VALUES( ";	
			
				//CStrInsert += " INSERT Top100_Census2D_Profile1459_EUCL VALUES( ";	
				//CStrInsert += " INSERT Top100_Census2D_Profile1459_SUM VALUES( ";	
			
				//CStrInsert += " INSERT Census2D_T0100_B_OPT VALUES( ";	
				//CStrInsert += " INSERT Census2D_T0100_U_OPT VALUES( ";	
				//CStrInsert += " INSERT Census2D_T0100_B_OPT_EUCL VALUES( ";	
				//CStrInsert += " INSERT Census2D_T0100_B_OPT_SUM VALUES( ";	
				//CStrInsert += " INSERT Census2D_T0050_B_OPT VALUES( ";	
				//CStrInsert += " INSERT Census2D_T0250_B_OPT VALUES( ";	
				//CStrInsert += " INSERT Census2D_T1000_B_OPT VALUES( ";	
				
				//2005.08.07
				//CStrInsert += " INSERT Census2D_T0100_OPT VALUES( ";	
				//CStrInsert += " INSERT Census2D_T0100_OPT_1 VALUES( ";	
				//CStrInsert += " INSERT Census2D_T0100_OPT_2 VALUES( ";	
				//CStrInsert += " INSERT Census2D_T0100_OPT_3 VALUES( ";	//06.03.23	
				//CStrInsert += " INSERT Census2D_T0100_OPT_4 VALUES( ";	//06.03.23
				CStrInsert += " INSERT Census2D_T0100_OPT_5 VALUES( ";	//06.03.23
				//CStrInsert += " INSERT Census2D_Top100_Profile0178 VALUES( ";	


				CStrInsert += cAttribute[0];
				CStrInsert += ",";
				CStrInsert += cAttribute[1];
				CStrInsert += ",";
				CStrInsert += cAttribute[2];
				CStrInsert += ",";
				CStrInsert += cAttribute[3];
				CStrInsert += ",";
				CStrInsert += cAttribute[4];
				CStrInsert += ",";
				CStrInsert += cAttribute[5];
				CStrInsert += ",";
				CStrInsert += cAttribute[6];
				CStrInsert += ",";
				CStrInsert += cAttribute[7];
				CStrInsert += ",";
				CStrInsert += cAttribute[8];
				CStrInsert += ")";


			    int iSqlLen = CStrInsert.GetLength();

				char * szSqlInsert = new char [iSqlLen + 1];
				strcpy(szSqlInsert , "");
				strcat(szSqlInsert , CStrInsert);

				//Sleep(100);

				SQLFreeStmt(hstmt_Census2D_Profile, SQL_DROP);
				retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_Profile); /// Profile Statement handle 
				
				SQLSetStmtOption(hstmt_Census2D_Profile, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
				SQLSetStmtOption(hstmt_Census2D_Profile, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
				

				retcode = SQLExecDirect(hstmt_Census2D_Profile, (unsigned char *)szSqlInsert, SQL_NTS);

				if (retcode == SQL_SUCCESS) 
				{  //	retcode = SQLExecDirect
					//AfxMessageBox("Insert new hstmt_Census2D_Profile  OKKKKKKKKKKK!");
					//Sleep(200);
						//bReturn = TRUE;
				}
				else
				{
					AfxMessageBox("Insert hstmt_Census2D_Profile Error!");

					i= 0;


				} //	retcode = SQLExecDirect 
				
				f=0;

				CStrInsert = "";
				delete [] szSqlInsert;
			}
		

			qnum++;

		}while(qnum <iSizeSmpl); //100);

	}//if(!zlOpenDB())



	delete [] pAge;//new float[10]
	delete [] pIncome;//new float[10]
	delete [] q1;//new float[10]
	delete [] q2;//new float[10]


	//SQLFreeStmt(hstmt, SQL_DROP);
	SQLFreeStmt(hstmt_Census2D_WorkLoad, SQL_DROP);
	SQLFreeStmt(hstmt_Census2D_Profile, SQL_DROP);

	zlCloseDB();

	AfxMessageBox("Insert hstmt_Generet2D_profile OK!");

}

void CMainFrame::OnLearningTop100census2dBiasedfrm1459EuclSum() 
{

	//Learning: Top100 census2d biased from profile with 1459 smpl, 
	
	// --Read: DATA_Top100_Census2D_Profile, as Profile
	// Read:  Top100_Census2D_Profile, as Profile
	// Read: DATA_Census2Dg_B_workload, as Biased Query workload
	// write:DATA_Top100_Census2D_Learning
	// Top100, distance = EUCL, SUM ,Type = Biased 
	// 
	// add 2 attributes f_rst, shortTicks_rst, 2003/4/5
	/////////////////////////////////////////////////////
	

	int N, f, c, d; 

	int i,j, iErr = 0;
	char tmp[100] = "";
	CString CStrSelect = ""; 
	CString CStrInsert = "";

	int longTicks =0, shortTicks =0;
	//int f_rst= 0, shortTicks_rst = 0; //2003/4/5

	SWORD  sAge;
	SDWORD cbAge;

	SDWORD sIncome;
	SDWORD cbIncome;
	SDWORD sN,sr,sf,sc,sd;
	SDWORD cbN,cbr,cbf,cbc,cbd;


	HSTMT   hstmt_Census2D_WorkLoad; //for queries workload
	HSTMT   hstmt_Census2D_Profile;  //for insert Profile

	//int iTupleNum;//,iStartRowNum, iTotalNum;

	int * q1, *q2, *q1Hold, *q2Hold; //for queries workload
	
	double rd =0.0, dis[2000], r[2000];  //rd is the final radius distance of Q; dis[]= d(Q,Q'), r[] id dis[];
	int tuple1[2000],tuple2[2000];

	double rr[2000],rOrder[2000]; 
	//double x[105];

	int iSizeProfile = 1459;//250; //100; //200; //400; //800; //1000; //2000;
	//int iSizeProfile = 250; //100; //200; //400; //800; //1000; //2000;

	int iTopN = 100;

	int iInsertOK = 0, iInsertERR = 0, irderr = 0;

//struct_Census2D_Tuple


	if(!zlOpenDB())
	{
		AfxMessageBox("zlOpenDB() err!");
		zlCloseDB();
	}else
	{
		retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_WorkLoad); ///queries Statement handle 
		retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_Profile); /// Profile Statement handle 

		//1. read all tuples from Profile set store a buffer
		//1111111111111 read database from profiles :DATA_Top100_Census2D_Profile 111111111111111	
												//   Top100_Census2D_Profile2000
		//---------------
		//UCHAR szSqlAllRows[] = "SELECT * FROM DATA_Top100_Census2D_Profile"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile2000"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile1000"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile0800"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile0400"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile0200"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile0100"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile0250"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile1459"; //discounts, authors, Census2DTable						
	
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top50_Census2D_Profile1459"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top250_Census2D_Profile1459"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top1000_Census2D_Profile1459"; //discounts, authors, Census2DTable						
	
		UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile1459_EUCL"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile1459_SUM"; //discounts, authors, Census2DTable						

		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		
		longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);
		longTicks = GetTickCount() - longTicks;

		//lEndTimer = GetTickCount() - lStartTimer;
		//wsprintf(tmp, "%ld", lEndTimer);


		if (retcode == SQL_SUCCESS) 
		{    //	retcode = SQLExecDirect for DATA_Top100_Census2D_Profile
			int iRowCount;
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt, RowCountPtr);						 
			iRowCount = * RowCountPtr;
			iSizeProfile = iRowCount; // here only size of profile, 100,200, ...,2000
			delete RowCountPtr;
			
			// Bind columns 1,2.
			SQLBindCol(hstmt, 1, SQL_C_SSHORT, &sAge, 0, &cbAge);
			SQLBindCol(hstmt, 2, SQL_C_SLONG, &sIncome,0, &cbIncome); //SQL_C_SSHORT
			SQLBindCol(hstmt, 3, SQL_C_SLONG, &sN,0, &cbN); //SQL_C_SSHORT
			SQLBindCol(hstmt, 4, SQL_C_SLONG, &sr,0, &cbr); //SQL_C_SSHORT
			SQLBindCol(hstmt, 5, SQL_C_SLONG, &sf,0, &cbf); //SQL_C_SSHORT
			SQLBindCol(hstmt, 6, SQL_C_SLONG, &sc,0, &cbc); //SQL_C_SSHORT
			SQLBindCol(hstmt, 7, SQL_C_SLONG, &sd,0, &cbd); //SQL_C_SSHORT

			pPf = new Profile2D[iRowCount];
			pPfHold = pPf;

			pAge = new  int[iRowCount];//buffer, new double[10]
			pIncome = new  int[iRowCount];//buffer , new double[10]
			pAgeHold = pAge;
			pIncomeHold = pIncome;
			iRowCount =0;
			while (TRUE) 
			{
				retcode = SQLFetch(hstmt);

				if (retcode == SQL_ERROR)
				{
					//show_error();
					wsprintf(tmp, "%ld", iRowCount);
					//int i = iRowCount;
					AfxMessageBox("SQLFetch Error !!!!!!");
							//break; //99.8.26
				}

				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
				{	
					*pAge		= sAge;
					*pIncome	= sIncome;
					
					pPf->q[0]	= sAge;				
					pPf->q[1]	= sIncome;
					pPf->N		= sN;
					pPf->r		= (float) sr;
					pPf->f		= sf;
					pPf->c		= sc;
					pPf->d		= sd;

					pAge++;
					pIncome++;

					pPf++;

					if(retcode == SQL_SUCCESS_WITH_INFO)
					{
						wsprintf(tmp, "%ld", retcode);
						AfxMessageBox(tmp);
					}
						
				} 
				else 
				{
					break;
				}

			}   ///while (TRUE)

			pAge = pAgeHold ;
			pIncome = pIncomeHold ;
			pPf	= pPfHold;
		}//	retcode = SQLExecDirect  for DATA_Top100_Census2D_Profile

	//111111111111111111 read data base  DATA_Top100_Census2D_Profile end   111111111111

	//2. Read all Queries from DATA_Census2Dg_B_workload
		sAge = 0;cbAge = 0;sIncome = 0;cbIncome= 0;

		UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Census2Dg_B_workload"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Census2Dg_B_workload1"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Census2Dg_B_workload2"; //discounts, authors, Census2DTable						
		
		SQLSetStmtOption(hstmt_Census2D_WorkLoad, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt_Census2D_WorkLoad, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		retcode = SQLExecDirect(hstmt_Census2D_WorkLoad, szSqlAllQueryRows, SQL_NTS);

		//lEndTimer = GetTickCount() - lStartTimer;
		//wsprintf(tmp, "%ld", lEndTimer);


		if (retcode == SQL_SUCCESS) 
		{    //	retcode = SQLExecDirect for census2Dg
			int iRowCount;
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt_Census2D_WorkLoad, RowCountPtr);						 
			iRowCount = * RowCountPtr;
			delete RowCountPtr;
			
			// Bind columns 1,2.
			SQLBindCol(hstmt_Census2D_WorkLoad, 1, SQL_C_SSHORT, &sAge, 0, &cbAge);
			SQLBindCol(hstmt_Census2D_WorkLoad, 2, SQL_C_SLONG, &sIncome,0, &cbIncome); //SQL_C_SSHORT

			q1 = new  int[iRowCount];//buffer, new double[10]
			q2 = new  int[iRowCount];//buffer , new double[10]
			q1Hold = q1; q2Hold= q2;
			

			while (TRUE) 
			{
				retcode = SQLFetch(hstmt_Census2D_WorkLoad);
				if (retcode == SQL_ERROR)
				{
					//show_error();
					wsprintf(tmp, "%ld", iRowCount);
					//int i = iRowCount;
					AfxMessageBox("SQLFetch Error !!!!!!");
							//break; //99.8.26
				}
				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
				{	
					*q1	= sAge;
					*q2	= sIncome;

					q1++;
					q2++;
				} 
				else 
				{
					break;
				}

			}   ///while (TRUE)
			
			q1= q1Hold; q2= q2Hold;
				
		}//	retcode = SQLExecDirect  for query q1,q2.
	
	
//////////////////
		SQLFreeStmt(hstmt, SQL_DROP);
		retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 

		//Sleep(100);
		//UCHAR szSqlAllRows[] = "SELECT * FROM census2Dg"; //discounts, authors, Census2DTable						
		UCHAR szSqlAllRowsFrmcensus2D[] = "SELECT * FROM CLMB_census2D"; //discounts, authors, Census2DTable						

		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		
		longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, szSqlAllRowsFrmcensus2D, SQL_NTS);
		longTicks = GetTickCount() - longTicks;

//////////////////////////



	//3. evaluate r, f, -c, -d,

		double ftmp=0;
		int itmp = 0,qnum =0; 
		int topt1[2000],topt2[2000];
		int frequ[2000],freOrder[2000];

		for(i=0; i<2000; i++)
		{
			topt1[i]=0; topt2[i] =0; frequ[i]=0; freOrder[i] =0;
		}

		do
		{
			////////////for each query find the closed profiles
			//evaluate all distance from New_query(q1[qnum],q2[qnum]) to Profile Point (pAge[i],pIncome[i] )
			// dis[i] = d(Q,Q') = dmax(Q,Q') = max(qi-q'i|)

			for(i = 0; i<iSizeProfile; i++)
			{
			  dis[i] = (double)max( abs(pAge[i]- q1[qnum]), abs(pIncome[i]-q2[qnum]) );
				
			  //x[1] = abs(pAge[i]- q1[qnum]); x[2] = abs(pIncome[i]-q2[qnum]);
			  //dis[i] = (double)sqrt( x[1]*x[1] + x[2]*x[2] ); 
			  //dis[i] = (double)( x[1] + x[2] ); 

			  tuple1[i] = pAge[i];
			  tuple2[i] = pIncome[i];
			  rr[i] = pPf[i].r;  //best search radius in Profile
			  frequ[i] = pPf[i].f; 		
			}

			i=0;

			//order all distance
			// r[i]'s are sorting d(Q,Q'), to identify the closest Q' to Q
			for(i=0; i<iSizeProfile; i++)
			{
				r[i] = dis[i];  //d(Q,Q')
				topt1[i] = tuple1[i] ; topt2[i]=tuple2[i] ; //profile points
				rOrder[i] = rr[i];  //radius order
				freOrder[i] = frequ[i];

				for( j= i+1; j<iSizeProfile; j++)
				{
					if(dis[j] < r[i]) 
					{ ftmp = r[i];			r[i] = dis[j];		 dis[j] = ftmp;
					  ftmp = rOrder[i];		rOrder[i] = rr[j];	 rr[j] = ftmp;
					  itmp = freOrder[i];   freOrder[i]= frequ[j]; frequ[j] = itmp;

					  itmp = topt1[i];		topt1[i]= tuple1[j]; tuple1[j]= itmp;
					  itmp = topt2[i];		topt2[i]= tuple2[j]; tuple2[j]= itmp;

					}
				}
			}
					
		//int N, rd,f, c, d; 
		//evaluate search distance
		
		int qp1 = topt1[0], qp2= topt2[0]; //Q'(qp1,qp2), the closest proples to Q(q1,q2)
		int iKnum = 0,fpf[2000];
		double frou[2000],l[2000],V[2000], lV=0, lVrou =0, rou = 0;
		double dQQ[2000],rpf[2000];
		double dmaxQQp;

		if(r[0] == 0) // if Q=Q'
		{//if(r[0] == 0)
			rd = rOrder[0];
			//rd = 2*rOrder[0];
			//rd = rOrder[0]/2;
			//rd = rOrder[0]/10;

			int itest = 0; //use to test 
		}
		else
		{
			dmaxQQp = max(  abs( qp1 - q1[qnum]), abs(qp2 - q2[qnum])  ); //i.e.r[0]
			//x[1] = abs( qp1 - q1[qnum]); x[2] = abs(qp2 - q2[qnum]); 
			//dmaxQQp = (double)sqrt( x[1]*x[1] + x[2]*x[2] ); 
			//dmaxQQp = (double)( x[1] + x[2] ); 

			if(dmaxQQp <= rOrder[0])  //case of Fig.3 //rou = N/4*r*r
			{
				iKnum = 0;
				
				for(j=0; j<iSizeProfile; j++)
				{
					frou[j] =0;l[j] =0;V[j] = 0;
					dQQ[j] =0;rpf[j] = 0;fpf[j]=0;
				}

				for(j=0; j<iSizeProfile; j++) //Find set K= (all squares Q in it)
				{
					if( r[j] <= rOrder[j]  ) //d(Q,Qpf) < rpf
					{
						dQQ[iKnum] = r[j];
						rpf[iKnum] = rOrder[j];
						fpf[iKnum] = freOrder[j];

						iKnum++;

					}
						
				}


				/*************************
				for(j=0; j<iKnum; j++)
				{
					frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
					l[j] = 1/dQQ[j];
					V[j] = 4*rpf[j]*rpf[j];
					lV += l[j]*V[j]; 
					lVrou += fpf[j]*l[j];  //l[j]*V[j]*frou[j];

				}

				rou = lVrou/lV;

				rd = (double)sqrt(100/rou)/2; //sqrt( double x );
			
				if (rd > dmaxQQp + rOrder[0])
				{
					rd = dmaxQQp + rOrder[0];

				}
				*******************/


				//---------- alternative test -----------------
				int iMeadian = iKnum/2;
				rou = 0;
				lVrou = 0; lV = 0;

				//rd = rOrder[iMeadian];
				////========
				//	rd =0;
				//	for (int k = 0; k< iKnum; k++)
				//	{	rd += rpf[k];}
				//	rd = rd/iKnum ;

				///===========
			/**************************

				for(j=0; j<iKnum; j++)
				{
					frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
					rou += frou[j];
				}

				rou = rou/iKnum;

				//rd = (double)sqrt(100/rou)/2; //sqrt( double x );
				rd = (double)sqrt(2* 100/rou)/2; //sqrt( double x );


				

				// median 

				for(j=0; j<iKnum; j++)
				{
					frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
					//rou += frou[j];
				}


				double rouOrder[2000],ftmp =0;

				for(j=0; j<iKnum; j++)
				{
					rouOrder[j] = frou[j]; 
						for(int k = j+1; k <iKnum; k++)
						{
							if(frou[k]< rouOrder[j])
							{
								ftmp = rouOrder[j]; rouOrder[j] = frou[k]; frou[k] = ftmp;
							}
						}
				}


				rou = rouOrder[iMeadian];

				//rou = rou/iKnum;

				//rd = (double)sqrt(100/rou)/2; //sqrt( double x );
				rd = (double)sqrt(3* 100/rou)/2; //sqrt( double x );
			**************/
			// ////////////// lvp
					for(j=0; j<iKnum; j++)
					{
						frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
						//l[j] = 1/dQQ[j];
						//l[j] = 1/(dQQ[j]* dQQ[j]* dQQ[j]);
						l[j] = 1/(dQQ[j]* dQQ[j]);

						V[j] = 4*rpf[j]*rpf[j];
						//lV += l[j]*V[j]; 
						//lVrou += fpf[j]*l[j];  //l[j]*V[j]*frou[j];
						
						//lV += ( 4*rpf[j]*rpf[j]/(dQQ[j]* dQQ[j]* dQQ[j]) );      //l[j]*V[j]; 						
						//lVrou += ( fpf[j]/(dQQ[j]* dQQ[j]* dQQ[j]) );
						lV += ( 4*rpf[j]*rpf[j]/(dQQ[j]* dQQ[j]) );      //l[j]*V[j]; 						
						lVrou += ( fpf[j]/(dQQ[j]* dQQ[j]) );


					}

					rou = lVrou/lV;
					rd = (double)sqrt(2*100/rou)/2; //sqrt( double x );
	
					if ( (rd < rOrder[0]) ||(rd < dmaxQQp))
					{
						rd = rd + rd/2;  //rOrder[0] ; + rd/n n-dimension
						//irderr ++;
					}
	
					if (rd > dmaxQQp + rOrder[0])
					{
						rd = dmaxQQp + rOrder[0];
						//irderr ++;
					}

					if (rd < dmaxQQp)
					{
					//	rd = rOrder[0];
						irderr ++;
					}

				//------------Fig 3.^^^^^----------------



			}else
			{
				dmaxQQp = max(  abs( qp1 - q1[qnum]), abs(qp2 - q2[qnum])  );
				//x[1] = abs( qp1 - q1[qnum]); x[2] = abs(qp2 - q2[qnum]); 
				//dmaxQQp = (double)sqrt( x[1]*x[1] + x[2]*x[2] ); 
				//dmaxQQp = (double)( x[1] + x[2] ); 

				if(dmaxQQp <= 2*rOrder[0])  //h<2r'
				{
					//case of Fig.4 //rou = N/4*r*r				
					iKnum = 0;
					for(j=0; j<2000; j++)
					{
						frou[j] =0;l[j] =0;V[j] = 0;
						dQQ[j] =0;rpf[j] = 0; fpf[j]=0;			
					}

				
					for(j=0; j<iSizeProfile; j++)
					{
						if(r[j] < rOrder[0] + dmaxQQp)
						{
							dQQ[iKnum] = r[j];
							rpf[iKnum] = rOrder[j];
							fpf[iKnum] = freOrder[j];

							iKnum++;
						}						
					}

					/**********************
					for(j=0; j<iKnum; j++)
					{
						frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
						l[j] = 1/dQQ[j];
						V[j] = 4*rpf[j]*rpf[j];
						lV += l[j]*V[j]; 
						lVrou += fpf[j]*l[j];  //l[j]*V[j]*frou[j];

					}

					rou = lVrou/lV;

					rd = (double)sqrt(100/rou)/2; //sqrt( double x );
					if (rd > dmaxQQp + rOrder[0])
						rd = dmaxQQp + rOrder[0];

				************************/

				//---------- alternative test -----------------
				lVrou = 0; lV = 0;
				rou = 0;
				int iMeadian = iKnum/2;
				//rd = rOrder[iMeadian];
				////111 ====== Mean ==
				//	rd =0;
				//	for (int k = 0; k< iKnum; k++)
				//	{	rd += rpf[k];}
				//	rd = rd/iKnum ;
				//	rd = rpf[iKnum/2];

			/*****************

				for(j=0; j<iKnum; j++)
				{
					frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
					rou += frou[j];
				}

				rou = rou/iKnum;

				//rd = (double)sqrt(100/rou)/2; //sqrt( double x );
				rd = (double)sqrt(2* 100/rou)/2; //sqrt( double x );


				///222======= median ====
				
				for(j=0; j<iKnum; j++)
				{
					frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
					//rou += frou[j];
				} 
				
				double rouOrder[2000],ftmp =0;

				for(j=0; j<iKnum; j++)
				{
					rouOrder[j] = frou[j] ;
						for(int k = j+1; k <iKnum; k++)
						{
							if(frou[k]< rouOrder[j])
							{
								ftmp = rouOrder[j]; rouOrder[j] = frou[k]; frou[k] = ftmp;
							}
						}
				}


				rou = rouOrder[iMeadian];

				//rd = (double)sqrt(100/rou)/2; //sqrt( double x );
				rd = (double)sqrt(3*100/rou)/2; //sqrt( double x );

		*****************/

			
					for(j=0; j<iKnum; j++)
					{
						frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
						//l[j] = 1/dQQ[j];
						l[j] = 1/(dQQ[j]* dQQ[j]);
						//l[j] = 1/(dQQ[j]* dQQ[j]* dQQ[j]);
						
						V[j] = 4*rpf[j]*rpf[j];
						//lV += l[j]*V[j]; 

						//lV += (4*rpf[j]*rpf[j]/(dQQ[j]* dQQ[j]* dQQ[j]) );      //l[j]*V[j]; 
						/////lVrou += fpf[j]*l[j];  //l[j]*V[j]*frou[j];
						//lVrou += (fpf[j]/(dQQ[j]* dQQ[j]* dQQ[j]));

						lV += (4*rpf[j]*rpf[j]/(dQQ[j]* dQQ[j]) );      //l[j]*V[j]; 
						lVrou += (fpf[j]/(dQQ[j]* dQQ[j]));


					}

					rou = lVrou/lV;

					//rd = (double)sqrt(100/rou)/2; //sqrt( double x );
					rd = (double)sqrt(2*100/rou)/2; //sqrt( double x );
		
				if ( (rd < rOrder[0]) ||(rd < dmaxQQp))
				{
						rd = rd + rd/2;  //rOrder[0] ; + rd/n n-dimension
						//irderr ++;
				}
				if (rd > dmaxQQp + rOrder[0])
				{
					rd = dmaxQQp + rOrder[0];
					//irderr ++;

				}

				if (rd < dmaxQQp)
				{
				//	rd = rOrder[0];
					irderr ++;
				}

				//-----------------fig. 4 -^^^^^^---------- 
			
					int itest = 0;
				}else{

					rd = dmaxQQp + rOrder[0];

				}//if(dmaxQQp <= 2*rOrder[0])

			}//if(dmaxQQp <= rOrder[0])


		}//if(r[0] == 0)

		
		//rd = rOrder[0];
	/************************		
//////////////////
		SQLFreeStmt(hstmt, SQL_DROP);
		retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 

		Sleep(100);
		//UCHAR szSqlAllRows[] = "SELECT * FROM census2Dg"; //discounts, authors, Census2DTable						
		UCHAR szSqlAllRows[] = "SELECT * FROM CLMB_census2D"; //discounts, authors, Census2DTable						

		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		
		longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);
		longTicks = GetTickCount() - longTicks;

//////////////////////////
*******************/

			
			CTime CurTime = CTime::GetCurrentTime();         

			N = 100; c = -1; d = - CurTime.GetTime();
			


			char cAgeLeft[20] = "", cAgeRight[20] = "", cIncomeLeft[20] = "", cIncomeRight[20] ="";
			
			sprintf(cAgeLeft,"%f", (double)(q1[qnum] - rd) );
			sprintf(cAgeRight,"%f", (double)(q1[qnum] + rd));
			sprintf(cIncomeLeft,"%f", (double)(q2[qnum] - rd));
			sprintf(cIncomeRight,"%f",(double)(q2[qnum] + rd));

			CStrSelect += "select  * from CLMB_census2d where (";
			CStrSelect += cAgeLeft;
			CStrSelect += "<= age AND age <=";
			CStrSelect += cAgeRight;
			CStrSelect += ") AND (";
			CStrSelect += cIncomeLeft;
			CStrSelect += "<= Income AND Income <=";
			CStrSelect += cIncomeRight;
			CStrSelect += ")"; 

			int iSqlLen = CStrSelect.GetLength();
			char * szSqlSquareRows = new char [iSqlLen + 1];	
			strcpy(szSqlSquareRows , "");
			strcat(szSqlSquareRows , CStrSelect);
	
			SQLFreeStmt(hstmt, SQL_DROP);
			retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 
			//Sleep(200);

			SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
			SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
			
			shortTicks = GetTickCount();
			retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlSquareRows, SQL_NTS);
			shortTicks = GetTickCount() - shortTicks;

			//lEndTimer = GetTickCount() - lStartTimer;
			//wsprintf(tmp, "%ld", irderr ++;);

			if (retcode == SQL_SUCCESS) 
			{    //	retcode = SQLExecDirect for census2Dg
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt, RowCountPtr);						 
			f = * RowCountPtr;
			delete RowCountPtr;

			}
			CStrSelect = "";
			delete [] szSqlSquareRows;

	//4. insert zeta into DATA_Top100_Census2D_Profile
			//if(f<100)
			if(f<iTopN)
			{
				i = 0;
				//AfxMessageBox("f==0!!!!!!!!!!!!!!!!!!!!!!");
			}
		
			if (f!= 0)
			{   
				char	cAttribute[10][50]= { "","","","","","","","","",""};

				
				sprintf(cAttribute[0],"%ld", q1[qnum] );
				sprintf(cAttribute[1],"%ld", q2[qnum] );
				sprintf(cAttribute[2],"%ld", N);
				sprintf(cAttribute[3],"%f",  (double)rd);
				sprintf(cAttribute[4],"%ld", f );
				//sprintf(cAttribute[5],"%ld", c );
				//sprintf(cAttribute[6],"%ld", d);
				sprintf(cAttribute[5],"%ld", longTicks);
				sprintf(cAttribute[6],"%ld", shortTicks);


				//CStrInsert += " INSERT DATA_Top100_Census2D_Learning VALUES( ";	
				//CStrInsert += " INSERT Top100Census2D_LearningFrmPf100 VALUES( ";	
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm2000 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm1000 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm0800 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm0400 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm0200 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm0100 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm0250 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm1459 VALUES( ";
		
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm1459_Top50 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm1459_Top250 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm1459_Top1000 VALUES( ";

				CStrInsert += " INSERT Top100_Census2D_LearningFrm1459_EUCL VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm1459_SUM VALUES( ";

				CStrInsert += cAttribute[0];
				CStrInsert += ",";
				CStrInsert += cAttribute[1];
				CStrInsert += ",";
				CStrInsert += cAttribute[2];
				CStrInsert += ",";
				CStrInsert += cAttribute[3];
				CStrInsert += ",";
				CStrInsert += cAttribute[4];
				CStrInsert += ",";
				CStrInsert += cAttribute[5];
				CStrInsert += ",";
				CStrInsert += cAttribute[6];
				//CStrInsert += ",";
				//CStrInsert += cAttribute[7];
				//CStrInsert += ",";
				//CStrInsert += cAttribute[8];
				CStrInsert += ")";


			    int iSqlLen = CStrInsert.GetLength();

				char * szSqlInsert = new char [iSqlLen + 1];
				strcpy(szSqlInsert , "");
				strcat(szSqlInsert , CStrInsert);

				SQLFreeStmt(hstmt_Census2D_Profile, SQL_DROP);
				retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_Profile); /// Profile Statement handle 

				retcode = SQLExecDirect(hstmt_Census2D_Profile, (unsigned char *)szSqlInsert, SQL_NTS);

				if (retcode == SQL_SUCCESS) 
				{  //	retcode = SQLExecDirect
					//AfxMessageBox("Insert new hstmt_Census2D_Learning  OKKKKKKKKKKK!");
					//Sleep(300);
					iInsertOK++;

					//bReturn = TRUE;
				}
				else
				{
					AfxMessageBox("Insert DATA_Top100_Census2D_Learning Error!");
					iInsertERR++;
					i= 0;

				} //	retcode = SQLExecDirect 
				
				f=0;

				CStrInsert = "";
				delete [] szSqlInsert;
			}
		

			qnum++;
		}while(qnum <iTopN); //100);

	}//if(!zlOpenDB())



	delete [] pAge;//new double[10]
	delete [] pIncome;//new double[10]
	delete [] pPf;
	delete [] q1;//new double[10]
	delete [] q2;//new double[10]


	SQLFreeStmt(hstmt, SQL_DROP);
	SQLFreeStmt(hstmt_Census2D_WorkLoad, SQL_DROP);
	SQLFreeStmt(hstmt_Census2D_Profile, SQL_DROP);

	zlCloseDB();
	wsprintf(tmp, " irderr = %d", irderr);

	AfxMessageBox(tmp);

	AfxMessageBox("Insert hstmt_Generet2DLearning  OK!");	
	
}

void CMainFrame::OnSmpl1459Census2DUniform() 
{
	//create sample of profiles 
	//Menu :Generator- Smpl1459_Census2D_Uniform

	// ---- Census 2d
	// Age in [15,90]; Income in [-25897,347998] 
	
	//--- Census3D
     // Age :  15   ,       90        
	 // Income  -25897 ,     347998      
	 // Wpy :  0  ,         52

	//---/********* Gauss 3D **************/

	//----------- ----------- ----------- ----------- ----------- ----------- 
	//0           9999        0           9999        315         9999

	/***** Array 3D ***************/

	//----------- ----------- ----------- ----------- ----------- ----------- 
	//56          9937        396         9937        61          9425

  ///************* Cover 4D **************/

                                                                                                
	//----------- ----------- ----------- ----------- ----------- ----------- ----------- ----------- 
	///1859        3858        0           360         0           66          0           7117



	int iErr = 0,iTotalNum = 0;
	char tmp[100] = "";
	CString CStrInsert = ""; 
	
	SWORD  sAge;

	SDWORD sIncome;
	SDWORD sWPY;
	//SDWORD sDis;

	//int iSizeSmpl = 100; //1459; //250; // 200;//400; //800; //1000; //2000; 
						 ////||||100, 200, 400, 800, 1000,2000. 
						  // size of census2Dg = 145,917; CLMB_census = 210,138.
						  // Date 2003.3.24
	int iSizeSmpl = 218;

	HSTMT   hstmt_Generet2DWorkload;

	srand( (unsigned)time( NULL ) );


		if(!zlOpenDB())
		{
			AfxMessageBox("zlOpenDB() err!");
			zlCloseDB();
		}else
		{
			retcode = SQLAllocStmt(hdbc, &hstmt_Generet2DWorkload); ///Statement handle 

			//int * pAge = new  int[1459];	//new float[10]
			//int * pIncome = new  int[1459];		//new float[10]
		
			while (TRUE) 
			{
				// Age in [15,90]; Income in [-25897,347998]
				int iRandom = 0;
				iRandom = rand();
				iRandom *= rand();
              /********* Census 3D (2d)
				sAge = 0;
				sAge = 15 + rand()%(90 - 15 +1);
				sIncome = 0;
				sIncome = - 25897 + iRandom%(347998 + 25897 +1);
				sWPY = 0; 				
				sWPY = 0 + iRandom%(52 - 0 +1); 
				*****/

			  //--- Gauss 3d ----
				sAge = 0;
				sAge = 0 + rand()%(9999 - 0 +1);
				sIncome = 0;
				sIncome = 0 + rand()%(9999 - 0 +1);
				sWPY = 0; 				
				sWPY = 315 + rand()%(9999 - 315 +1);
				
			/********

			  //--- Array 3d ----
				sAge = 0;
				sAge = 56 + rand()%(9937 - 56 +1);
				sIncome = 0;
				sIncome = 396 + rand()%(9937 - 396 +1);;
				sWPY = 0; 				
				sWPY = 61 + rand()%(9425 - 61 +1);; 
			  //--- Cover 4d ----
				sAge = 0;
				sAge = 1859 + rand()%(3858 - 1859 +1);
				sIncome = 0;
				sIncome = 0 + rand()%(360 - 0 +1);
				sWPY = 0; 				
				sWPY = 0 + rand()%(66 - 0 +1);
				sDis =0; 
				sDis = 0 + rand()%(7117 - 0 +1);
				********/


				char cAge[20] = "", cIncome[20] = "",  cWPY[20] = "" , cTupleNum[20] ="";
				char cDis[20] = "";
			
				sprintf(cAge,"%d",sAge);
				sprintf(cIncome,"%ld",sIncome);
				sprintf(cWPY,"%ld",sWPY);
				//sprintf(cDis,"%ld",sDis);

				//sprintf(cTupleNum,"%ld",iRowCount);

				//CStrInsert += " INSERT smpl1459_Census2D VALUES( ";
				//CStrInsert += " INSERT DATA_Census2Dg_U_workload VALUES( ";
				//CStrInsert += " INSERT Census3D_U_WorkLoad VALUES( ";
				//CStrInsert += " INSERT Gauss3D_U_WorkLoad VALUES( ";
				//CStrInsert += " INSERT Array3D_U_WorkLoad VALUES( ";
				//CStrInsert += " INSERT Cover4D_U_WorkLoad VALUES( ";

				 CStrInsert += " INSERT Gauss3D_U_smpl0218 VALUES( ";

				
				CStrInsert += cAge;
				CStrInsert += ",";
				CStrInsert += cIncome;

				CStrInsert += ",";
				CStrInsert += cWPY;

				//CStrInsert += ",";
				//CStrInsert += cDis;

				CStrInsert += ")";

				int iSqlLen = CStrInsert.GetLength();

				char * szSqlInsert = new char [iSqlLen + 1];
				strcpy(szSqlInsert , "");
				strcat(szSqlInsert , CStrInsert);
							
				retcode = SQLExecDirect(hstmt_Generet2DWorkload, (unsigned char *)szSqlInsert, SQL_NTS);


				if (retcode == SQL_SUCCESS) 
				{  //	retcode = SQLExecDirect
							//AfxMessageBox("Insert new Recode Seccess!");
							//bReturn = TRUE;
					iTotalNum ++;
				}
				else
				{
						//	AfxMessageBox("Insert new Recode Error!");
						iErr++;

				} //	retcode = SQLExecDirect 
					
				CStrInsert = "";
				delete [] szSqlInsert; 


				if(iTotalNum >=iSizeSmpl)
						break;


			
				}//////while (TRUE)		
			
					//	delete [] pAge;//new float[10]
					//	delete [] pIncome;//new float[10]


		//111111111111111111 read data base end111111111111


		}//if(!zlOpenDB())


	//SQLFreeStmt(hstmt, SQL_DROP);
	SQLFreeStmt(hstmt_Generet2DWorkload, SQL_DROP);
	zlCloseDB();

	AfxMessageBox("Insert hstmt_Generet2DWorkload OK!");
	
}

void CMainFrame::OnSmpl1654Census3D() 
{
	//create sample of profiles of Census3D 
	//Menu :Generator- Smpl1654Census3D
	// 1% of 165428 if Census3Dg is 1654
	/* 0.5% of 165428 = 827 */
	/* 0.25% of 165428 = 414 */
	// 250*7/8 = 218.75 = 218

	int i,iErr = 0;
	char tmp[100] = "";
	CString CStrInsert = ""; 
	
	SWORD  sAge;
	SDWORD cbAge;

	SDWORD sIncome;
	SDWORD cbIncome;

	SDWORD sWPY;
	SDWORD cbWPY;

	
	int iSizeSmpl = 218; //100; //414; //827;//1654; 

	HSTMT   hstmt_Generet2DWorkload;

	srand( (unsigned)time( NULL ) );


		if(!zlOpenDB())
		{
			AfxMessageBox("zlOpenDB() err!");
			zlCloseDB();
		}else
		{
			retcode = SQLAllocStmt(hdbc, &hstmt_Generet2DWorkload); ///Statement handle 

			//lStartTimer = GetTickCount();

			//UCHAR szSqlAllRows[] = "SELECT * FROM Gauss2Dg"; //discounts, authors, Census2DTable						
			//UCHAR szSqlAllRows[] = "SELECT * FROM Census2Dg"; //discounts, authors, Census2DTable						
			UCHAR szSqlAllRows[] = "SELECT * FROM Census3Dg"; //discounts, authors, Census2DTable						
			
			SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
			SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
			retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);

			//lEndTimer = GetTickCount() - lStartTimer;
			//wsprintf(tmp, "%ld", lEndTimer);

			//1111111111111 read data base 111111111111111

			if (retcode == SQL_SUCCESS) 
			{    //	retcode = SQLExecDirect
				int iRowCount, iTupleNum, iSpan, iSampleNum, iStartRowNum, iTotalNum;
				SDWORD *  RowCountPtr = new SDWORD ;
				retcode = SQLRowCount(hstmt, RowCountPtr);						 
				iRowCount = * RowCountPtr;
				iTupleNum = iRowCount;
				iSpan = (int) (iRowCount/iSizeSmpl);
				iSampleNum =0;
				delete RowCountPtr;
				
				// Bind columns 1,2,3
				SQLBindCol(hstmt, 1, SQL_C_SSHORT, &sAge, 0, &cbAge);
				SQLBindCol(hstmt, 2, SQL_C_SLONG, &sIncome,0, &cbIncome); //SQL_C_SSHORT
				SQLBindCol(hstmt, 3, SQL_C_SLONG, &sWPY,0, &cbWPY); //SQL_C_SSHORT

				//int * pAge = new  int[iRowCount];//new float[10]
				//int * pIncome = new  int[iRowCount];//new float[10]
				//int * pWPY = new int [iRowCount] //, * pWPYHold;

				iRowCount = 0;
				iStartRowNum = 0;
				iTotalNum = 0;
				
				while (TRUE) 
				{
					
					int iRandom = rand()%(iSpan-1);
					for (i = iStartRowNum; i < iSampleNum + iRandom; i++)
					{
					      retcode = SQLFetch(hstmt);
						  iRowCount ++ ; 
					}

					if (retcode == SQL_ERROR)
					{
						//show_error();

						wsprintf(tmp, "%ld", iRowCount);
						//int i = iRowCount;
						AfxMessageBox("SQLFetch Error !!!!!!");
								//break; //99.8.26
					}

					if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO ||iRowCount>= iSampleNum)
							//if (retcode == SQL_SUCCESS)
					{	

						char cAge[20] = "", cIncome[20] = "", cWPY[20] = "",cTupleNum[20] ="";

						sprintf(cAge,"%d",sAge);
						sprintf(cIncome,"%ld",sIncome);
						sprintf(cWPY,"%ld",sWPY);

						sprintf(cTupleNum,"%ld",iRowCount);

						
						//CStrInsert += " INSERT DATA_Gauss2Dg_workload VALUES( ";	
						//CStrInsert += " INSERT smpl2000_Census2D VALUES( ";
						//CStrInsert += " INSERT smpl1000_Census2D VALUES( ";
						//CStrInsert += " INSERT smpl0800_Census2D VALUES( ";
						//CStrInsert += " INSERT smpl0400_Census2D VALUES( ";
						//CStrInsert += " INSERT smpl0200_Census2D VALUES( ";
						//CStrInsert += " INSERT smpl0100_Census2D VALUES( ";
						//CStrInsert += " INSERT smpl0250_Census2D VALUES( ";
						//CStrInsert += " INSERT smpl1459_Census2D VALUES( ";
						//CStrInsert += " INSERT smpl0827_Census3D VALUES( ";
						//CStrInsert += " INSERT smpl0414_Census3D VALUES( ";
						
						CStrInsert += " INSERT smpl0218_Census3D VALUES( ";
						
						//CStrInsert += " INSERT DATA_Census3Dg_B_workload VALUES( ";
				
						
						CStrInsert += cAge;
						CStrInsert += ",";
						CStrInsert += cIncome;
						CStrInsert += ",";
						CStrInsert += cWPY;
		
						//CStrInsert += ",";
						//CStrInsert += cTupleNum;
						CStrInsert += ")";

						int iSqlLen = CStrInsert.GetLength();

						char * szSqlInsert = new char [iSqlLen + 1];
						strcpy(szSqlInsert , "");
						strcat(szSqlInsert , CStrInsert);
							
						retcode = SQLExecDirect(hstmt_Generet2DWorkload, (unsigned char *)szSqlInsert, SQL_NTS);


						if (retcode == SQL_SUCCESS) 
						{  //	retcode = SQLExecDirect
							//AfxMessageBox("Insert new Recode Seccess!");
							//bReturn = TRUE;
							iTotalNum ++;
						}
						else
						{
						//	AfxMessageBox("Insert new Recode Error!");
							iErr++;

						} //	retcode = SQLExecDirect 
					
						CStrInsert = "";
						delete [] szSqlInsert; 

						iStartRowNum = iRowCount;
						iSampleNum += iSpan ;
					} 
					else 
					{
						break;
					}

					if(iTotalNum >=iSizeSmpl)
						break;


				}   ///while (TRUE)			
					
						//delete [] pAge;//new float[10]
						//delete [] pIncome;//new float[10]

			}//	retcode = SQLExecDirect



		//111111111111111111 read data base end111111111111


		}


	SQLFreeStmt(hstmt, SQL_DROP);
	SQLFreeStmt(hstmt_Generet2DWorkload, SQL_DROP);
	zlCloseDB();

	AfxMessageBox("Insert hstmt_Generet2DWorkload OK!");

	
}

void CMainFrame::OnSmpl1654census3DProfile() 
{
	//2005.08.07 reuse it

	//Create census3D profile with	1654 samples
	// with distance functions: MAX, EUCL, SUM

	//Create census3D profile with	827,414 samples
	/*****************************
	* 1. read all tuples from : CLMB_census3D store a buffer
	* 2. Read all tuple from  : smpl1654_Census3D 
	* 3. evaluate r, f, c, -d,
	* 4. insert zeta into	  : Top100_Census3D_Profile1654 
	******************************/
	// Menu: Creat_TopNProfile --> Smpl1654_Census3D_Profile 

	int N, f, c, d = 0; 

	int i,j, k, iErr = 0;
	char tmp[100] = "";
	CString CStrSelect = ""; 
	CString CStrInsert = "";

	int longTicks =0, shortTicks =0;
	
	SWORD  sAge;
	SDWORD cbAge;

	SDWORD sIncome;
	SDWORD cbIncome;

	SDWORD sWPY;
	SDWORD cbWPY;


	HSTMT   hstmt_Census2D_WorkLoad; //for queries workload
	HSTMT   hstmt_Census2D_Profile;  //for insert Profile

	int iTupleNum;//,iStartRowNum, iTotalNum;

	int * q1, *q2, *q3,*q1Hold, *q2Hold, *q3Hold;
	
	//int iSizeSmpl = 218;//827; //1654; //250; //200; //400; //800; //1000; //2000;
	int iTopN = 100; //250;//50; //50; 100; 250; 1000
	//int iTopN = 1000;// 250;//50; //50; 100; 250; 1000
	int iSizeSmpl = 100; //for Opt

	//float rd, dis[100], r[100]; 
	//int tuple1[100],tuple2[100];
	
	double rd, dis[2000], r[2000], x[105]; 
	int tuple1[2000],tuple2[2000],tuple3[2000];


	if(!zlOpenDB())
	{
		AfxMessageBox("zlOpenDB() err!");
		zlCloseDB();
	}else
	{
		retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_WorkLoad); ///queries Statement handle 
		retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_Profile); /// Profile Statement handle 

		//1. read all tuples from census2Dg store a buffer
		//1111111111111 read data base from census2Dg 111111111111111	

		//UCHAR szSqlAllRows[] = "select  * from census2dg where (15 - 9 <=age and age<=15+ 9 ) and (15- 9 <=Income and Income <=15+ 9 )";
		
		//----------------------------------------------------
		UCHAR szSqlAllRows[] = "SELECT * FROM CLMB_census3D"; //discounts, authors, Census2DTable						

		//------------------------------------------------------


		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		
		longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);
		longTicks = GetTickCount() - longTicks;

		//lEndTimer = GetTickCount() - lStartTimer;
		//wsprintf(tmp, "%ld", lEndTimer);


		if (retcode == SQL_SUCCESS  || retcode == SQL_SUCCESS_WITH_INFO) 
		{    //	retcode = SQLExecDirect for census2Dg
			int iRowCount;
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt, RowCountPtr);						 
			iRowCount = * RowCountPtr;
			iTupleNum = iRowCount;
			delete RowCountPtr;
			
			// Bind columns 1,2,3
			SQLBindCol(hstmt, 1, SQL_C_SSHORT, &sAge, 0, &cbAge);
			SQLBindCol(hstmt, 2, SQL_C_SLONG, &sIncome,0, &cbIncome); //SQL_C_SSHORT
			SQLBindCol(hstmt, 3, SQL_C_SLONG, &sWPY,0, &cbWPY); //SQL_C_SSHORT

			pAge = new  int[iRowCount];//buffer, new float[10]
			pIncome = new  int[iRowCount];//buffer , new float[10]
			pWPY = new  int[iRowCount];
			
			pAgeHold = pAge;
			pIncomeHold = pIncome;
			pWPYHold = pWPY;

			iRowCount =0;
			while (TRUE) 
			{
				retcode = SQLFetch(hstmt);

				if (retcode == SQL_ERROR)
				{
					//show_error();

					wsprintf(tmp, "%ld", iRowCount);
					//int i = iRowCount;
					AfxMessageBox("SQLFetch Error !!!!!!");
							//break; //99.8.26
				}

				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
						//if (retcode == SQL_SUCCESS)
				{	

					*pAge		= sAge;
					*pIncome	= sIncome;
					*pWPY		= sWPY;
					pAge++;
					pIncome++;
					pWPY++;

					if(retcode == SQL_SUCCESS_WITH_INFO)
					{
						wsprintf(tmp, "%ld", retcode);
						AfxMessageBox(tmp);

					}
						
				} 
				else 
				{
					break;
				}

			}   ///while (TRUE)

			pAge = pAgeHold ;
			pIncome = pIncomeHold ;
			pWPY = pWPYHold ;

	
		}//	retcode = SQLExecDirect  for census2Dg

	//111111111111111111 read data base  census2Dg end   111111111111

	//2. Read all tuple from smpl_DB_tables : DATA_Top100_Census2D_WorkLoad ,100 smpl
										//	  smpl2000_Census2D				 2000 smpl
		
		sAge = 0;cbAge = 0;sIncome = 0;cbIncome= 0;sWPY = 0; cbWPY = 0;

		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Top100_Census2D_WorkLoad"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl2000_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl1000_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl0800_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl0400_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl0200_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl0100_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl0250_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl1459_Census2D"; //discounts, authors, Census2DTable						
		
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl1654_Census3D"; // Census3D 						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl0827_Census3D"; // 				
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl0414_Census3D"; // 				
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl0218_Census3D"; // 				

		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Census3Dg_B_workload"; // 				
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Census3D_U_WorkLoad"; // 				

		// --2005.08.07 		
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Census3D_smpl0218"; //2005.08.07 				
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Census3D_B_WorkLoad"; //2005.08.07 				
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Census3D_B_WorkLoad_1"; //2005.08.07 				
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Census3D_B_WorkLoad_2"; //2005.08.07 				
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Census3D_B_WorkLoad_3"; //2006.03.23 				
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Census3D_B_WorkLoad_4"; //2006.03.23 								
		UCHAR szSqlAllQueryRows[] = "SELECT * FROM Census3D_B_WorkLoad_5"; //2006.03.23 								

		SQLSetStmtOption(hstmt_Census2D_WorkLoad, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt_Census2D_WorkLoad, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		retcode = SQLExecDirect(hstmt_Census2D_WorkLoad, szSqlAllQueryRows, SQL_NTS);

		//lEndTimer = GetTickCount() - lStartTimer;
		//wsprintf(tmp, "%ld", lEndTimer);


		if (retcode == SQL_SUCCESS  || retcode == SQL_SUCCESS_WITH_INFO) 
		{    //	retcode = SQLExecDirect for census2Dg
			int iRowCount;
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt_Census2D_WorkLoad, RowCountPtr);						 
			iRowCount = * RowCountPtr;
			delete RowCountPtr;
			
			// Bind columns 1,2,3
			SQLBindCol(hstmt_Census2D_WorkLoad, 1, SQL_C_SSHORT, &sAge, 0, &cbAge);
			SQLBindCol(hstmt_Census2D_WorkLoad, 2, SQL_C_SLONG, &sIncome,0, &cbIncome); //SQL_C_SSHORT
			SQLBindCol(hstmt_Census2D_WorkLoad, 3, SQL_C_SLONG, &sWPY,0, &cbWPY); //SQL_C_SSHORT

			q1 = new  int[iRowCount];//buffer, new float[10]
			q2 = new  int[iRowCount];//buffer , new float[10]
			q3 = new  int[iRowCount];//buffer , new float[10]
		
			q1Hold = q1; q2Hold= q2; q3Hold = q3;
			

			while (TRUE) 
			{
				retcode = SQLFetch(hstmt_Census2D_WorkLoad);

				if (retcode == SQL_ERROR)
				{
					//show_error();

					wsprintf(tmp, "%ld", iRowCount);
					//int i = iRowCount;
					AfxMessageBox("SQLFetch Error !!!!!!");
							//break; //99.8.26
				}

				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
						//if (retcode == SQL_SUCCESS)
				{	
					*q1	= sAge;*q2	= sIncome;*q3 = sWPY;
					q1++;		q2++;			q3++;
					
				} 
				else 
				{
					break;
				}

			}   ///while (TRUE)
			
			q1= q1Hold; q2= q2Hold;q3= q3Hold;
				
		}//	retcode = SQLExecDirect  for query q1,q2.
	
	//3. evaluate r, f, -c, -d,

		double ftmp=0;
		int itmp = 0,qnum =0; 
		int topt1[1000],topt2[1000],topt3[1000];


		do
		{
			//take first 100 as Top100
			//for(i = 0; i<100; i++)
			for(i = 0; i<iTopN; i++)
			{
			  
			  x[1]=abs(pAge[i]- q1[qnum]);x[2]=abs(pIncome[i]-q2[qnum]);x[3]=abs(pWPY[i]-q3[qnum]);
			  
			  //---- 3 distances
			  dis[i] = (double)max( x[1], x[2]); dis[i] = (double)max(dis[i], x[3]);//MAX distance
			  //dis[i] = (double)sqrt( x[1]*x[1] + x[2]*x[2] + x[3]*x[3]);  //EUCL distance
			  //dis[i] = (double)( x[1] + x[2] + x[3]); //SUM distance 

			  tuple1[i] = pAge[i];
			  tuple2[i] = pIncome[i];
			  tuple3[i] = pWPY[i];

			}
			i=0;

			//sorting the first 100 tuples
			for(i=0; i<iTopN; i++)
			{
				r[i] = dis[i];
				topt1[i] = tuple1[i] ; topt2[i]=tuple2[i] ; topt3[i]=tuple3[i] ;
				for( j= i+1; j<iTopN; j++)
				{
					if(dis[j] < r[i]) 
					{ ftmp = r[i];    r[i] = dis[j];  dis[j] = ftmp;
					  itmp = topt1[i]; topt1[i]= tuple1[j]; tuple1[j]= itmp;
					  itmp = topt2[i]; topt2[i]= tuple2[j]; tuple2[j]= itmp;
					  itmp = topt3[i]; topt3[i]= tuple3[j]; tuple3[j]= itmp;

					}
				}
			}
			
			i=0;
			//2. select top100 (topN)from all tuples with size iTupleNum
			for(i = iTopN; i<iTupleNum; i++)
			{
			  
				x[1]=abs(pAge[i]- q1[qnum]);x[2]=abs(pIncome[i]-q2[qnum]);x[3]=abs(pWPY[i]-q3[qnum]);
				
				//---- 3 distances
				ftmp = (double)max( x[1], x[2]); ftmp = (double)max(ftmp, x[3]);//MAX distance
				//ftmp = (double)sqrt( x[1]*x[1] + x[2]*x[2] + x[3]*x[3]); //EUCL distance
				//ftmp = (double)( x[1] + x[2] + x[3]); //SUM distance 

				if(ftmp <0)
					int itest = 0;
				//if(ftmp < r[99])
				if(ftmp < r[iTopN - 1])		
				{
					for(j=0;j<iTopN;j++)
					{
						if(ftmp<r[j])
						{
							//for(k=99; k>j; k--)
							for(k=iTopN - 1; k>j; k--)
							{
								r[k] = r[k-1];
								topt1[k] = topt1[k-1];
								topt2[k] = topt2[k-1];
								topt3[k] = topt3[k-1];
							}
							r[j]=ftmp;
							topt1[j] = pAge[i];
							topt2[j] = pIncome[i];
							topt3[j] = pWPY[i];
							break;
						}
					}
				}
			}
		
		//int N, rd,f, c, d; 	
			
//////////////////
			/*************************
		SQLFreeStmt(hstmt, SQL_DROP);
		retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 

		Sleep(100);
		
		//UCHAR szSqlAllRows[] = "SELECT * FROM census2Dg"; //discounts, authors, Census2DTable						
		UCHAR szSqlAllRows[] = "SELECT * FROM CLMB_census2D"; //discounts, authors, Census2DTable						

		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		
		longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);
		longTicks = GetTickCount() - longTicks;
		***********************/
//////////////////////////
				
						
			
			CTime CurTime = CTime::GetCurrentTime();         

			//N = 100; rd = r[99]; //r[99] means the distance from last_tuple (top100) to the query
			N = iTopN; 
			
			//rd = r[iTopN-1]; //r[99] means the distance from last_tuple (top100) to the query
		
			c = -1; d--; //d = - CurTime.GetTime(); d++;
			
			for(i = 0; i<iTopN; i++)
			{
			  dis[i] =(float)max( ( max( abs(topt1[i]- q1[qnum]),abs(topt2[i]-q2[qnum]))), abs(topt3[i]-q3[qnum]) ); //MAX distance
			  
			}
			
			//find the square's radius, which is the max of all distance from Q to top-N tuples
			rd = dis[0];
				
			for( j= 1; j<iTopN; j++)
			{
				if(dis[j] > rd) 
				{ 
					ftmp = rd; rd = dis[j];  dis[j] = ftmp;
				}
			}
			

			char cAgeLeft[20] = "", cAgeRight[20] = "", cIncomeLeft[20] = "", cIncomeRight[20] ="";
			char cWPYLeft[20] = "", cWPYRight[20] = "";
		
			sprintf(cAgeLeft,		"%f",	(float)(q1[qnum] - rd)	);
			sprintf(cAgeRight,		"%f",	(float)(q1[qnum] + rd)	);
			sprintf(cIncomeLeft,	"%f",	(float)(q2[qnum] - rd)	);
			sprintf(cIncomeRight,	"%f",	(float)(q2[qnum] + rd)	);
			sprintf(cWPYLeft,		"%f",	(float)(q3[qnum] - rd)	);
			sprintf(cWPYRight,		"%f",	(float)(q3[qnum] + rd)	);


			//CStrSelect += "select  * from census2dg where (";
			CStrSelect += "select  * from CLMB_census3D where (";
			
			CStrSelect += cAgeLeft;
			CStrSelect += "<= age AND age <=";
			CStrSelect += cAgeRight;

			CStrSelect += ") AND (";
			CStrSelect += cIncomeLeft;
			CStrSelect += "<= Income AND Income <=";
			CStrSelect += cIncomeRight;

			CStrSelect += ") AND (";
			CStrSelect += cWPYLeft;
			CStrSelect += "<= WeeksPerYear AND WeeksPerYear <=";   //WeeksPerYear
			CStrSelect += cWPYRight;

			CStrSelect += ")"; 

			int iSqlLen = CStrSelect.GetLength();
			char * szSqlSquareRows = new char [iSqlLen + 1];	
			strcpy(szSqlSquareRows , "");
			strcat(szSqlSquareRows , CStrSelect);
			//Sleep(200);
	
			SQLFreeStmt(hstmt, SQL_DROP);
			retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 


			//szSqlSquareRows= "select  * from census2dg where ";// (15 - 9 <=age and age<=15+ 9 ) and (15- 9 <=Income and Income <=15+ 9 )";
			SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
			SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
			
			shortTicks = GetTickCount();
			retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlSquareRows, SQL_NTS);
			shortTicks = GetTickCount() - shortTicks;

			//lEndTimer = GetTickCount() - lStartTimer;
			//wsprintf(tmp, "%ld", lEndTimer);

			if (retcode == SQL_SUCCESS) 
			{    //	retcode = SQLExecDirect for census2Dg
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt, RowCountPtr);						 
			f = * RowCountPtr;
			delete RowCountPtr;

			}
			CStrSelect = "";
			delete [] szSqlSquareRows;

	//4. insert zeta into the Profiles: DATA_Top100_Census2D_Profile
									//	Top100_Census2D_Profile2000
									// Top100_Census3D_Profile1654
		
			if (f!= 0)
			{   
				char	cAttribute[10][50]= { "","","","","","","","","",""};

				
				sprintf(cAttribute[0],	"%ld", q1[qnum] );
				sprintf(cAttribute[1],	"%ld", q2[qnum] );
				sprintf(cAttribute[1+1],"%ld", q3[qnum] );

				sprintf(cAttribute[2+1],"%ld", N);
				sprintf(cAttribute[3+1],"%f",  (float)rd);
				sprintf(cAttribute[4+1],"%ld", f );
				sprintf(cAttribute[5+1],"%ld", c );
				sprintf(cAttribute[6+1],"%ld", d);
				sprintf(cAttribute[7+1],"%ld", longTicks);
				sprintf(cAttribute[8+1],"%ld", shortTicks);

				//---------tables---------------
				
				//CStrInsert += " INSERT Top100_Census3D_Profile1654 VALUES( ";	
				//CStrInsert += " INSERT Top100_Census3D_Profile1654_EUCL VALUES( ";	
				//CStrInsert += " INSERT Top100_Census3D_Profile1654_SUM VALUES( ";	
	
				//CStrInsert += " INSERT Top100_Census3D_Profile0827 VALUES( ";	
				//CStrInsert += " INSERT Top100_Census3D_Profile0414 VALUES( ";	
				//CStrInsert += " INSERT Top100_Census3D_Profile0218 VALUES( ";	
				
				//CStrInsert += " INSERT Census3D_P0218_EUCL VALUES( ";	
				//CStrInsert += " INSERT Census3D_P0218_SUM VALUES( ";	
		
				//CStrInsert += " INSERT Census3D_T0100_B_OPT VALUES( ";	
				//CStrInsert += " INSERT Census3D_T0100_U_OPT VALUES( ";	
				//CStrInsert += " INSERT Census3D_T0100_B_OPT_EUCL VALUES( ";	
				//CStrInsert += " INSERT Census3D_T0100_B_OPT_SUM VALUES( ";	
				//CStrInsert += " INSERT Census3D_T0050_B_OPT VALUES( ";	
				//CStrInsert += " INSERT Census3D_T0250_B_OPT VALUES( ";	
				//CStrInsert += " INSERT Census3D_T1000_B_OPT VALUES( ";	
				
				//--- 2005.08.07	
				//CStrInsert += " INSERT Census3D_Top100_Profile0218 VALUES( "; //2005.08.07	
				//CStrInsert += " INSERT Census3D_T0100_OPT VALUES( ";	//2005.08.07
				//CStrInsert += " INSERT Census3D_T0100_OPT_1 VALUES( ";	//2005.08.07
				//CStrInsert += " INSERT Census3D_T0100_OPT_2 VALUES( ";	//2005.08.07
				//CStrInsert += " INSERT Census3D_T0100_OPT_3 VALUES( ";	//2006.03.23
				//CStrInsert += " INSERT Census3D_T0100_OPT_4 VALUES( ";	//2006.03.23
				CStrInsert += " INSERT Census3D_T0100_OPT_5 VALUES( ";	//2006.03.23

				
				CStrInsert += cAttribute[0];
				CStrInsert += ",";
				CStrInsert += cAttribute[1];
				CStrInsert += ",";
				CStrInsert += cAttribute[1+1];
				CStrInsert += ",";
				
				CStrInsert += cAttribute[2+1];
				CStrInsert += ",";
				CStrInsert += cAttribute[3+1];
				CStrInsert += ",";
				CStrInsert += cAttribute[4+1];
				CStrInsert += ",";
				CStrInsert += cAttribute[5+1];
				CStrInsert += ",";
				CStrInsert += cAttribute[6+1];
				CStrInsert += ",";
				CStrInsert += cAttribute[7+1];
				CStrInsert += ",";
				CStrInsert += cAttribute[8+1];
				CStrInsert += ")";


			    int iSqlLen = CStrInsert.GetLength();

				char * szSqlInsert = new char [iSqlLen + 1];
				strcpy(szSqlInsert , "");
				strcat(szSqlInsert , CStrInsert);

				//Sleep(100);

				SQLFreeStmt(hstmt_Census2D_Profile, SQL_DROP);
				retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_Profile); /// Profile Statement handle 
				
				SQLSetStmtOption(hstmt_Census2D_Profile, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
				SQLSetStmtOption(hstmt_Census2D_Profile, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
				

				retcode = SQLExecDirect(hstmt_Census2D_Profile, (unsigned char *)szSqlInsert, SQL_NTS);

				if (retcode == SQL_SUCCESS) 
				{  //	retcode = SQLExecDirect
					//AfxMessageBox("Insert new hstmt_Census2D_Profile  OKKKKKKKKKKK!");
					//Sleep(200);
						//bReturn = TRUE;
				}
				else
				{
					AfxMessageBox("Insert hstmt_Census2D_Profile Error!");

					i= 0;


				} //	retcode = SQLExecDirect 
				
				f=0;

				CStrInsert = "";
				delete [] szSqlInsert;
			}
		

			qnum++;
		}while(qnum <iSizeSmpl); //100);

	}//if(!zlOpenDB())



	delete [] pAge;//new float[10]
	delete [] pIncome;//new float[10]
	delete [] pWPY;//new float[10]

	delete [] q1;//new float[10]
	delete [] q2;//new float[10]
	delete [] q3;//new float[10]

	//SQLFreeStmt(hstmt, SQL_DROP);
	SQLFreeStmt(hstmt_Census2D_WorkLoad, SQL_DROP);
	SQLFreeStmt(hstmt_Census2D_Profile, SQL_DROP);

	zlCloseDB();

	AfxMessageBox("Insert hstmt_Generet2D_profile OK!");

}

void CMainFrame::OnSmpl5810Cover4d() 
{
	//2005.08.03 reuse it
    //Menu: Generator --> Smpl5810_Cover4D

	//create sample of profiles of cover4D 
	//Menu :Generator- Smpl5810_cover4D
	// 1% of 581010 if CLMB_cover4D is 5810
	int i,iErr = 0;
	char tmp[100] = "";
	CString CStrInsert = ""; 
	
	SDWORD  sEle;		//Elevation
	SDWORD cbEle; 

	SDWORD sAsp;		//Aspect
	SDWORD cbAsp;

	SDWORD sSlo;		//Slope
	SDWORD cbSlo;
                      
	SDWORD sDTR;		//Distance_To_Roadways
	SDWORD cbDTR;

	//int iSizeSmpl = 5810; //250; // 200;//400; //800; //1000; //2000; 
						 ////||||100, 200, 400, 800, 1000,2000. 
						  // size of census2Dg = 145,917; CLMB_census = 210,138.
						  // Date 2003.3.24
	//int iSizeSmpl = 872;//436;//218;
	//int iSizeSmpl = 100; // for workload
	int iSizeSmpl = 250;

	HSTMT   hstmt_Generet2DWorkload;

	srand( (unsigned)time( NULL ) );


		if(!zlOpenDB())
		{
			AfxMessageBox("zlOpenDB() err!");
			zlCloseDB();
		}else
		{
			retcode = SQLAllocStmt(hdbc, &hstmt_Generet2DWorkload); ///Statement handle 

			//lStartTimer = GetTickCount();

			//UCHAR szSqlAllRows[] = "SELECT * FROM Gauss2Dg"; //discounts, authors, Census2DTable						
			//UCHAR szSqlAllRows[] = "SELECT * FROM Census2Dg"; //discounts, authors, Census2DTable						
			//UCHAR szSqlAllRows[] = "SELECT * FROM Census3Dg"; //discounts, authors, Census2DTable						
			
			UCHAR szSqlAllRows[] = "SELECT * FROM CLMB_cover4D"; //discounts, authors, Census2DTable						
			
			SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
			SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
			retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);

			//lEndTimer = GetTickCount() - lStartTimer;
			//wsprintf(tmp, "%ld", lEndTimer);

			//1111111111111 read data base 111111111111111

			if (retcode == SQL_SUCCESS) 
			{    //	retcode = SQLExecDirect
				int iRowCount, iTupleNum, iSpan, iSampleNum, iStartRowNum, iTotalNum;
				SDWORD *  RowCountPtr = new SDWORD ;
				retcode = SQLRowCount(hstmt, RowCountPtr);						 
				iRowCount = * RowCountPtr;
				iTupleNum = iRowCount;
				iSpan = (int) (iRowCount/iSizeSmpl);
				iSampleNum =0;
				delete RowCountPtr;
				
				// Bind columns 1,2,3
				SQLBindCol(hstmt, 1, SQL_C_SLONG, &sEle, 0, &cbEle);
				SQLBindCol(hstmt, 2, SQL_C_SLONG, &sAsp,0, &cbAsp); //SQL_C_SSHORT
				SQLBindCol(hstmt, 3, SQL_C_SLONG, &sSlo,0, &cbSlo); //SQL_C_SSHORT
				SQLBindCol(hstmt, 4, SQL_C_SLONG, &sDTR,0, &cbDTR); //SQL_C_SSHORT


				iRowCount = 0;
				iStartRowNum = 0;
				iTotalNum = 0;
				
				while (TRUE) 
				{
					
					int iRandom = rand()%(iSpan-1);
					for (i = iStartRowNum; i < iSampleNum + iRandom; i++)
					{
					      retcode = SQLFetch(hstmt);
						  iRowCount ++ ; 
					}

					if (retcode == SQL_ERROR)
					{
						//show_error();

						wsprintf(tmp, "%ld", iRowCount);
						//int i = iRowCount;
						AfxMessageBox("SQLFetch Error !!!!!!");
								//break; //99.8.26
					}

					if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO ||iRowCount>= iSampleNum)
							//if (retcode == SQL_SUCCESS)
					{	

						char c1[20] = "", c2[20] = "", c3[20] = "", c4[20] = "",cTupleNum[20] ="";

						sprintf(c1,"%ld",sEle);
						sprintf(c2,"%ld",sAsp);
						sprintf(c3,"%ld",sSlo);
						sprintf(c4,"%ld",sDTR);

						sprintf(cTupleNum,"%ld",iRowCount);

						
						//CStrInsert += " INSERT DATA_Gauss2Dg_workload VALUES( ";	
						//CStrInsert += " INSERT smpl2000_Census2D VALUES( ";
						//CStrInsert += " INSERT smpl1000_Census2D VALUES( ";
						//CStrInsert += " INSERT smpl0800_Census2D VALUES( ";
						//CStrInsert += " INSERT smpl0400_Census2D VALUES( ";
						//CStrInsert += " INSERT smpl0200_Census2D VALUES( ";
						//CStrInsert += " INSERT smpl0100_Census2D VALUES( ";
						//CStrInsert += " INSERT smpl0250_Census2D VALUES( ";
						//CStrInsert += " INSERT smpl1459_Census2D VALUES( ";
					
						//CStrInsert += " INSERT smpl1654_Census3D VALUES( ";
						//CStrInsert += " INSERT smpl5810_Cover4D VALUES( ";
						
						//CStrInsert += " INSERT Cover4D_smpl0218 VALUES( ";
						//CStrInsert += " INSERT Cover4D_smpl0436 VALUES( ";
						//CStrInsert += " INSERT Cover4D_smpl0872 VALUES( ";
						
						//CStrInsert += " INSERT Cover4D_B_workload VALUES( ";
						CStrInsert += " INSERT Cover4D_smpl0250 VALUES( ";
						
					
						CStrInsert += c1;
						CStrInsert += ",";
						CStrInsert += c2;
						CStrInsert += ",";
						CStrInsert += c3;
						CStrInsert += ",";
						CStrInsert += c4;

						//CStrInsert += ",";
						//CStrInsert += cTupleNum;
						CStrInsert += ")";

						int iSqlLen = CStrInsert.GetLength();

						char * szSqlInsert = new char [iSqlLen + 1];
						strcpy(szSqlInsert , "");
						strcat(szSqlInsert , CStrInsert);
							
						retcode = SQLExecDirect(hstmt_Generet2DWorkload, (unsigned char *)szSqlInsert, SQL_NTS);


						if (retcode == SQL_SUCCESS) 
						{  //	retcode = SQLExecDirect
							//AfxMessageBox("Insert new Recode Seccess!");
							//bReturn = TRUE;
							iTotalNum ++;
						}
						else
						{
						//	AfxMessageBox("Insert new Recode Error!");
							iErr++;

						} //	retcode = SQLExecDirect 
					
						CStrInsert = "";
						delete [] szSqlInsert; 

						iStartRowNum = iRowCount;
						iSampleNum += iSpan ;
					} 
					else 
					{
						break;
					}

					if(iTotalNum >=iSizeSmpl)
						break;

				}   ///while (TRUE)			

			}//	retcode = SQLExecDirect



		//111111111111111111 read data base end111111111111


		}


	//SQLFreeStmt(hstmt, SQL_DROP);
	SQLFreeStmt(hstmt_Generet2DWorkload, SQL_DROP);
	zlCloseDB();

	AfxMessageBox("Insert hstmt_Generet2DWorkload OK!");

}

void CMainFrame::OnSmpl5810cover4DProfile() 
{
	
	//2005.08.04 reuse it.
	//Menu: Creat_TopNProfile --> Smpl5810_Cover4D_Profile

	//Create cover4d profile with	5810 samples
	// with distance functions: MAX, EUCL, SUM

	/*****************************
	* 1. read all tuples from : CLMB_coverD store a buffer
	* 2. Read all tuple from  : smpl5810_cover4D 
	* 3. evaluate r, f, c, -d,
	* 4. insert zeta into	  : Top100_Cover4D_Profile5810 
	******************************/
	// Menu: Smpl5810_coverD_Profile 

	int N, f, c, d = 0; 

	int i,j, k, iErr = 0;
	char tmp[100] = "";
	CString CStrSelect = ""; 
	CString CStrInsert = "";

	int longTicks =0, shortTicks =0;
	
	SDWORD sCol1,sCol2,sCol3,sCol4;
	SDWORD cbCol1,cbCol2,cbCol3,cbCol4;


	HSTMT   hstmt_Census2D_WorkLoad; //for queries workload
	HSTMT   hstmt_Census2D_Profile;  //for insert Profile

	int iTupleNum;//,iStartRowNum, iTotalNum;

	int * pCol1, *pCol2, *pCol3,*pCol4,
		*pCol1Hold, *pCol2Hold, *pCol3Hold, *pCol4Hold;

	int * q1, *q2, *q3,*q4,*q1Hold, *q2Hold, *q3Hold , *q4Hold;
	
	//int iSizeSmpl = 5810; //250; //200; //400; //800; //1000; //2000;
	int iTopN = 100; //1000; //250; //50;//100; //250;//50; //50; 100; 250; 1000
	
	//int iSizeSmpl = 872; //436; //218; 

	int iSizeSmpl = 100; // FOR OPT
	//int iSizeSmpl = 250; // for profile sets

	double rd, dis[2000], r[2000], x[106]; 
	int tuple1[2000],tuple2[2000],tuple3[2000],tuple4[2000];


	if(!zlOpenDB())
	{
		AfxMessageBox("zlOpenDB() err!");
		zlCloseDB();
	}else
	{
		retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_WorkLoad); ///queries Statement handle 
		retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_Profile); /// Profile Statement handle 

		//1. read all tuples from census2Dg store a buffer
		//1111111111111 read data base from census2Dg 111111111111111	

		//UCHAR szSqlAllRows[] = "select  * from census2dg where (15 - 9 <=age and age<=15+ 9 ) and (15- 9 <=Income and Income <=15+ 9 )";
		
		//----------------------------------------------------
		UCHAR szSqlAllRows[] = "SELECT * FROM CLMB_cover4D"; //discounts, authors, Census2DTable						

		//------------------------------------------------------


		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		
		longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);
		longTicks = GetTickCount() - longTicks;

		//lEndTimer = GetTickCount() - lStartTimer;
		//wsprintf(tmp, "%ld", lEndTimer);


		if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) 
		{    //	retcode = SQLExecDirect for census2Dg
			int iRowCount;
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt, RowCountPtr);						 
			iRowCount = * RowCountPtr;
			iTupleNum = iRowCount;
			delete RowCountPtr;
			
			// Bind columns 1,2,3,4
			SQLBindCol(hstmt, 1, SQL_C_SLONG, &sCol1,0, &cbCol1);
			SQLBindCol(hstmt, 2, SQL_C_SLONG, &sCol2,0, &cbCol2); //SQL_C_SSHORT
			SQLBindCol(hstmt, 3, SQL_C_SLONG, &sCol3,0, &cbCol3); //SQL_C_SSHORT
			SQLBindCol(hstmt, 4, SQL_C_SLONG, &sCol4,0, &cbCol4); //SQL_C_SSHORT

			//pAge = new  int[iRowCount];//buffer, new float[10]
			//pIncome = new  int[iRowCount];//buffer , new float[10]
			//pWPY = new  int[iRowCount];
			
			//pAgeHold = pAge;
			//pIncomeHold = pIncome;
			//pWPYHold = pWPY;

			pCol1 = new  int[iRowCount]; pCol2 = new  int[iRowCount];
			pCol3 = new  int[iRowCount]; pCol4 = new  int[iRowCount];
			pCol1Hold = pCol1; pCol2Hold = pCol2;
			pCol3Hold = pCol3; pCol4Hold = pCol4;

			iRowCount =0;
			while (TRUE) 
			{
				retcode = SQLFetch(hstmt);

				if (retcode == SQL_ERROR)
				{
					//show_error();

					wsprintf(tmp, "%ld", iRowCount);
					//int i = iRowCount;
					AfxMessageBox("SQLFetch Error !!!!!!");
							//break; //99.8.26
				}

				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
						//if (retcode == SQL_SUCCESS)
				{	

					*pCol1 = sCol1;*pCol2 = sCol2;*pCol3 = sCol3;*pCol4 = sCol4;
					pCol1++;		pCol2++;	   pCol3++;	      pCol4++;

					if(retcode == SQL_SUCCESS_WITH_INFO)
					{
						wsprintf(tmp, "%ld", retcode);
						AfxMessageBox(tmp);

					}
						
				} 
				else 
				{
					break;
				}

			}   ///while (TRUE)

			pCol1 = pCol1Hold;  pCol2= pCol2Hold;
			pCol3 = pCol3Hold ; pCol4= pCol4Hold ;
	
		}//	retcode = SQLExecDirect  for census2Dg

	//111111111111111111 read data base  census2Dg end   111111111111

	//2. Read all tuple from smpl_DB_tables : DATA_Top100_Census2D_WorkLoad ,100 smpl
										//	  smpl2000_Census2D				 2000 smpl
		
		 sCol1=0;sCol2=0;sCol3=0;sCol4=0;
	     cbCol1=0;cbCol2=0;cbCol3=0;cbCol4=0;


		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Top100_Census2D_WorkLoad"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl2000_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl1000_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl0800_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl0400_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl0200_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl0100_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl0250_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl1459_Census2D"; //discounts, authors, Census2DTable						
		
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl1654_Census3D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl5810_Cover4D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Cover4D_smpl0218"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Cover4D_smpl0436"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Cover4D_smpl0872"; //discounts, authors, Census2DTable						
		
		 //UCHAR szSqlAllQueryRows[] = "SELECT * FROM Cover4D_smpl0250"; //discounts, authors, Census2DTable						
		 //UCHAR szSqlAllQueryRows[] = "SELECT * FROM Cover4D_B_workload"; //discounts, authors, Census2DTable						
		 //UCHAR szSqlAllQueryRows[] = "SELECT * FROM Cover4D_B_workload_1"; //2005.08.04						
		 //UCHAR szSqlAllQueryRows[] = "SELECT * FROM Cover4D_B_workload_2"; //2005.08.04							
		 //UCHAR szSqlAllQueryRows[] = "SELECT * FROM Cover4D_B_workload_3"; //2006.03.23				
		 //UCHAR szSqlAllQueryRows[] = "SELECT * FROM Cover4D_B_workload_4"; //2006.03.23				
		 UCHAR szSqlAllQueryRows[] = "SELECT * FROM Cover4D_B_workload_5"; //2006.03.23				

		 //UCHAR szSqlAllQueryRows[] = "SELECT * FROM Cover4D_U_WorkLoad"; //discounts, authors, Census2DTable						
		
		SQLSetStmtOption(hstmt_Census2D_WorkLoad, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt_Census2D_WorkLoad, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		retcode = SQLExecDirect(hstmt_Census2D_WorkLoad, szSqlAllQueryRows, SQL_NTS);

		//lEndTimer = GetTickCount() - lStartTimer;
		//wsprintf(tmp, "%ld", lEndTimer);


		if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) 
		{    //	retcode = SQLExecDirect for census2Dg
			int iRowCount;
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt_Census2D_WorkLoad, RowCountPtr);						 
			iRowCount = * RowCountPtr;
			delete RowCountPtr;
			
			// Bind columns 1,2,3,4
			SQLBindCol(hstmt_Census2D_WorkLoad, 1, SQL_C_SLONG, &sCol1,0, &cbCol1);
			SQLBindCol(hstmt_Census2D_WorkLoad, 2, SQL_C_SLONG, &sCol2,0, &cbCol2); //SQL_C_SSHORT
			SQLBindCol(hstmt_Census2D_WorkLoad, 3, SQL_C_SLONG, &sCol3,0, &cbCol3); //SQL_C_SSHORT
			SQLBindCol(hstmt_Census2D_WorkLoad, 4, SQL_C_SLONG, &sCol4,0, &cbCol4); //SQL_C_SSHORT

			q1 = new  int[iRowCount];//buffer, new float[10]
			q2 = new  int[iRowCount];//buffer , new float[10]
			q3 = new  int[iRowCount];//buffer , new float[10]
			q4 = new  int[iRowCount];//buffer , new float[10]
		
			q1Hold = q1; q2Hold= q2; q3Hold = q3;q4Hold = q4;
			

			while (TRUE) 
			{
				retcode = SQLFetch(hstmt_Census2D_WorkLoad);

				if (retcode == SQL_ERROR)
				{
					//show_error();

					wsprintf(tmp, "%ld", iRowCount);
					//int i = iRowCount;
					AfxMessageBox("SQLFetch Error !!!!!!");
							//break; //99.8.26
				}

				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
						//if (retcode == SQL_SUCCESS)
				{	
					*q1	= sCol1;*q2	= sCol2;*q3 = sCol3;*q4 = sCol4;
					q1++;		q2++;		q3++;		q4++;
					
				} 
				else 
				{
					break;
				}

			}   ///while (TRUE)
			
			q1= q1Hold; q2= q2Hold;q3= q3Hold;q4= q4Hold;
				
		}//	retcode = SQLExecDirect  for query q1,q2.
	
	//3. evaluate r, f, -c, -d,

//////////////////
		SQLFreeStmt(hstmt, SQL_DROP);
		retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 
		
		//UCHAR szSqlAllRows[] = "SELECT * FROM census2Dg"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM CLMB_census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM CLMB_Cover4D"; //discounts, authors, Census2DTable						

		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		
		longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);
		longTicks = GetTickCount() - longTicks;
//////////////////////////



		double ftmp=0;
		int itmp = 0,qnum =0; 
		int topt1[1000],topt2[1000],topt3[1000],topt4[1000];

		do
		{
			//take first 100 as Top100
			//for(i = 0; i<100; i++)
			for(i = 0; i<iTopN; i++)
			{			  
			  x[1]=abs(pCol1[i]- q1[qnum]);x[2]=abs(pCol2[i]-q2[qnum]);
			  x[3]=abs(pCol3[i]- q3[qnum]);x[4]=abs(pCol4[i]-q4[qnum]);
			  
			  //--- 3 distances
			  dis[i] = (double)max( x[1], x[2]); dis[i] = (double)max(dis[i], x[3]);
			  dis[i] = (double)max(dis[i], x[4]);//MAX distance

			  //dis[i] = (double)sqrt( x[1]*x[1] + x[2]*x[2] + x[3]*x[3] + x[4]*x[4]);  //EUCL distance
			  //dis[i] = (double)( x[1] + x[2] + x[3]+ x[4]); //SUM distance 

			  tuple1[i] = pCol1[i];
			  tuple2[i] = pCol2[i];
			  tuple3[i] = pCol3[i];
			  tuple4[i] = pCol4[i];
			}
			i=0;

			//sorting the first 100 tuples
			//for(i=0; i<100; i++), 
			for(i=0; i<iTopN; i++)
			{
				r[i] = dis[i];
				topt1[i]=tuple1[i];topt2[i]=tuple2[i];topt3[i]=tuple3[i];topt4[i]=tuple4[i];
				//for( j= i+1; j<100; j++)
				for( j= i+1; j<iTopN; j++)
				{
					if(dis[j] < r[i]) 
					{ ftmp = r[i];    r[i] = dis[j];  dis[j] = ftmp;
					  itmp = topt1[i]; topt1[i]= tuple1[j]; tuple1[j]= itmp;
					  itmp = topt2[i]; topt2[i]= tuple2[j]; tuple2[j]= itmp;
					  itmp = topt3[i]; topt3[i]= tuple3[j]; tuple3[j]= itmp;
					  itmp = topt4[i]; topt4[i]= tuple4[j]; tuple4[j]= itmp;
					}
				}
			}
			
			i=0;
			//2. select top100 (topN)from all tuples with size iTupleNum
			//for(i=100; i<iTupleNum; i++)
			for(i = iTopN; i<iTupleNum; i++)
			{
				x[1]=abs(pCol1[i]- q1[qnum]);x[2]=abs(pCol2[i]-q2[qnum]);
				x[3]=abs(pCol3[i]- q3[qnum]);x[4]=abs(pCol4[i]-q4[qnum]);
			  
			  	//--- 3 distances
				ftmp = (double)max( x[1], x[2]); ftmp = (double)max(ftmp, x[3]);
				ftmp = (double)max(ftmp, x[4]);//MAX distance

				//ftmp = (double)sqrt( x[1]*x[1] + x[2]*x[2] + x[3]*x[3] + x[4]*x[4]);//EUCL Distance
				//ftmp = (double)( x[1] + x[2] + x[3]+ x[4]); //SUM distance 

				if(ftmp <0)
					int itest = 0;
				//if(ftmp < r[99])
				if(ftmp < r[iTopN - 1])		
				{
					//for(j=0;j<100;j++)
					for(j=0;j<iTopN;j++)
					{
						if(ftmp<r[j])
						{
							//for(k=99; k>j; k--)
							for(k=iTopN - 1; k>j; k--)
							{
								r[k] = r[k-1];
								topt1[k] = topt1[k-1];
								topt2[k] = topt2[k-1];
								topt3[k] = topt3[k-1];
								topt4[k] = topt4[k-1];
							}
							r[j]=ftmp;
							topt1[j] = pCol1[i];
							topt2[j] = pCol2[i];
							topt3[j] = pCol3[i];
							topt4[j] = pCol4[i];
							break;
						}
					}
				}
			}
		
		//int N, rd,f, c, d; 	
			
//////////////////
			/****
		SQLFreeStmt(hstmt, SQL_DROP);
		retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 
		
		//UCHAR szSqlAllRows[] = "SELECT * FROM census2Dg"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM CLMB_census2D"; //discounts, authors, Census2DTable						
		UCHAR szSqlAllRows[] = "SELECT * FROM CLMB_Cover4D"; //discounts, authors, Census2DTable						

		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		
		longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);
		longTicks = GetTickCount() - longTicks;
		******/
//////////////////////////
				
						
			
			CTime CurTime = CTime::GetCurrentTime();         

			//N = 100; rd = r[99]; //r[99] means the distance from last_tuple (top100) to the query
			N = iTopN; 
			
			//rd = r[iTopN-1]; //r[99] means the distance from last_tuple (top100) to the query
		
			c = -1; d--; //d = - CurTime.GetTime(); d++;
			
			ftmp = 0;
			for(i = 0; i<iTopN; i++)
			{
			  	ftmp = (double) max( abs(topt1[i]- q1[qnum]),abs(topt2[i]-q2[qnum]) );
				ftmp = (double)max(ftmp, abs(topt3[i]-q3[qnum]));
				ftmp = (double)max(ftmp, abs(topt4[i]-q4[qnum]));
				dis[i] =(float)ftmp;
				ftmp = 0;
			}
			
			//find the square's radius, which is the max of all distance from Q to top-N tuples
			rd = dis[0];
				
			for( j= 1; j<iTopN; j++)
			{
				if(dis[j] > rd) 
				{ 
					ftmp = rd; rd = dis[j];  dis[j] = ftmp;
				}
			}
			

			char cLeft1[20] = "", cRight1[20] = "", cLeft2[20] = "", cRight2[20] ="";
			char cLeft3[20] = "", cRight3[20] = "", cLeft4[20] = "", cRight4[20] = "";
		
			sprintf(cLeft1,		"%f",	(float)(q1[qnum] - rd)	);
			sprintf(cRight1,	"%f",	(float)(q1[qnum] + rd)	);
			sprintf(cLeft2,		"%f",	(float)(q2[qnum] - rd)	);
			sprintf(cRight2,	"%f",	(float)(q2[qnum] + rd)	);
			sprintf(cLeft3,		"%f",	(float)(q3[qnum] - rd)	);
			sprintf(cRight3,	"%f",	(float)(q3[qnum] + rd)	);
			sprintf(cLeft4,		"%f",	(float)(q4[qnum] - rd)	);
			sprintf(cRight4,	"%f",	(float)(q4[qnum] + rd)	);


			//CStrSelect += "select  * from census2dg where (";
			CStrSelect += "select  * from CLMB_cover4D where (";
			
			CStrSelect += cLeft1;
			CStrSelect += "<= Elevation AND Elevation <=";
			CStrSelect += cRight1;

			CStrSelect += ") AND (";
			CStrSelect += cLeft2;
			CStrSelect += "<= Aspect AND Aspect <=";
			CStrSelect += cRight2;

			CStrSelect += ") AND (";
			CStrSelect += cLeft3;
			CStrSelect += "<= Slope AND Slope <=";   //Slope
			CStrSelect += cRight3;
			
			CStrSelect += ") AND (";
			CStrSelect += cLeft4;
			CStrSelect += "<= Distance_To_Roadways AND Distance_To_Roadways <=";   //Distance_To_Roadways
			CStrSelect += cRight4;

			CStrSelect += ")"; 

			int iSqlLen = CStrSelect.GetLength();
			char * szSqlSquareRows = new char [iSqlLen + 1];	
			strcpy(szSqlSquareRows , "");
			strcat(szSqlSquareRows , CStrSelect);
			//Sleep(200);
	
			SQLFreeStmt(hstmt, SQL_DROP);
			retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 


			//szSqlSquareRows= "select  * from census2dg where ";// (15 - 9 <=age and age<=15+ 9 ) and (15- 9 <=Income and Income <=15+ 9 )";
			SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
			SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
			
			shortTicks = GetTickCount();
			retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlSquareRows, SQL_NTS);
			shortTicks = GetTickCount() - shortTicks;

			//lEndTimer = GetTickCount() - lStartTimer;
			//wsprintf(tmp, "%ld", lEndTimer);

			if (retcode == SQL_SUCCESS) 
			{    //	retcode = SQLExecDirect for census2Dg
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt, RowCountPtr);						 
			f = * RowCountPtr;
			delete RowCountPtr;

			}
			CStrSelect = "";
			delete [] szSqlSquareRows;

	//4. insert zeta into the Profiles: DATA_Top100_Census2D_Profile
									//	Top100_Census2D_Profile2000
									// Top100_Census3D_Profile1654
		
			if (f!= 0)
			{   
				char	cAttribute[11][50]= { "","","","","","","","","",""};

				
				sprintf(cAttribute[0],		"%ld", q1[qnum] );
				sprintf(cAttribute[1],		"%ld", q2[qnum] );
				sprintf(cAttribute[1+1],	"%ld", q3[qnum] );
				sprintf(cAttribute[1+1+1],	"%ld", q4[qnum] );

				sprintf(cAttribute[2+1+1],"%ld", N);
				sprintf(cAttribute[3+1+1],"%f",  (float)rd);
				sprintf(cAttribute[4+1+1],"%ld", f );
				sprintf(cAttribute[5+1+1],"%ld", c );
				sprintf(cAttribute[6+1+1],"%ld", d);
				sprintf(cAttribute[7+1+1],"%ld", longTicks);
				sprintf(cAttribute[8+1+1],"%ld", shortTicks);

				//---------tables---------------
								
				//CStrInsert += " INSERT Top100_cover4D_Profile5810 VALUES( ";	
				//CStrInsert += " INSERT Top100_cover4D_Profile5810_EUCL VALUES( ";	
				//CStrInsert += " INSERT Top100_cover4D_Profile5810_SUM VALUES( ";	
						
				//CStrInsert += " INSERT Cover4D_Top100_Profile0218 VALUES( ";	
				//CStrInsert += " INSERT Cover4D_Top100_Profile0436 VALUES( ";	
				//CStrInsert += " INSERT Cover4D_Top100_Profile0872 VALUES( ";	
				
				//CStrInsert += " INSERT Cover4D_Top100_Profile0250 VALUES( ";					
				//CStrInsert += " INSERT Cover4D_Top100_P0250_EUCL VALUES( ";					
				//CStrInsert += " INSERT Cover4D_Top100_P0250_SUM VALUES( ";					
				
				//CStrInsert += " INSERT Cover4D_T0100_OPT VALUES( ";					
				//CStrInsert += " INSERT Cover4D_T0100_OPT_1 VALUES( ";	//2005.08.04
				//CStrInsert += " INSERT Cover4D_T0100_OPT_2 VALUES( ";	//2005.08.04
				//CStrInsert += " INSERT Cover4D_T0100_OPT_3 VALUES( ";	//2006.03.23
				//CStrInsert += " INSERT Cover4D_T0100_OPT_4 VALUES( ";	//2006.03.23
				CStrInsert += " INSERT Cover4D_T0100_OPT_5 VALUES( ";	//2006.03.23

				//CStrInsert += " INSERT Cover4D_T0100_U_OPT VALUES( ";	
				//CStrInsert += " INSERT Cover4D_T0100_OPT_EUCL VALUES( ";	
				//CStrInsert += " INSERT Cover4D_T0100_OPT_SUM VALUES( ";	
				//CStrInsert += " INSERT Cover4D_T0050_OPT VALUES( ";	
				//CStrInsert += " INSERT Cover4D_T0250_OPT VALUES( ";					
				//CStrInsert += " INSERT Cover4D_T1000_OPT VALUES( ";	
						 
				CStrInsert += cAttribute[0];
				CStrInsert += ",";
				CStrInsert += cAttribute[1];
				CStrInsert += ",";
				CStrInsert += cAttribute[1+1];
				CStrInsert += ",";
				CStrInsert += cAttribute[1+1+1];
				CStrInsert += ",";

				CStrInsert += cAttribute[2+1+1];
				CStrInsert += ",";
				CStrInsert += cAttribute[3+1+1];
				CStrInsert += ",";
				CStrInsert += cAttribute[4+1+1];
				CStrInsert += ",";
				CStrInsert += cAttribute[5+1+1];
				CStrInsert += ",";
				CStrInsert += cAttribute[6+1+1];
				CStrInsert += ",";
				CStrInsert += cAttribute[7+1+1];
				CStrInsert += ",";
				CStrInsert += cAttribute[8+1+1];
				CStrInsert += ")";


			    int iSqlLen = CStrInsert.GetLength();

				char * szSqlInsert = new char [iSqlLen + 1];
				strcpy(szSqlInsert , "");
				strcat(szSqlInsert , CStrInsert);

				//Sleep(100);

				SQLFreeStmt(hstmt_Census2D_Profile, SQL_DROP);
				retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_Profile); /// Profile Statement handle 
				
				SQLSetStmtOption(hstmt_Census2D_Profile, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
				SQLSetStmtOption(hstmt_Census2D_Profile, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
				

				retcode = SQLExecDirect(hstmt_Census2D_Profile, (unsigned char *)szSqlInsert, SQL_NTS);

				if (retcode == SQL_SUCCESS) 
				{  //	retcode = SQLExecDirect
					//AfxMessageBox("Insert new hstmt_Census2D_Profile  OKKKKKKKKKKK!");
					//Sleep(200);
						//bReturn = TRUE;
				}
				else
				{
					AfxMessageBox("Insert hstmt_Census2D_Profile Error!");
					i= 0;

				} //	retcode = SQLExecDirect 
				
				f=0;

				CStrInsert = "";
				delete [] szSqlInsert;
			}
		

			qnum++;
		}while(qnum <iSizeSmpl); //100);

	}//if(!zlOpenDB())



	delete [] pCol1;//new float[10]
	delete [] pCol2;//new float[10]
	delete [] pCol3;//new float[10]
	delete [] pCol4;//new float[10]

	delete [] q1;//new float[10]
	delete [] q2;//new float[10]
	delete [] q3;//new float[10]
	delete [] q4;//new float[10]

	//SQLFreeStmt(hstmt, SQL_DROP);
	SQLFreeStmt(hstmt_Census2D_WorkLoad, SQL_DROP);
	SQLFreeStmt(hstmt_Census2D_Profile, SQL_DROP);

	zlCloseDB();

	AfxMessageBox("Insert hstmt_Generet2D_profile OK!");
}

void CMainFrame::OnSmpl5000Gauss3D_Array3D() 
{
	//create sample of profiles of Gauss3D, Array3d
	//Menu :Generator- Smpl5000 Gauss 3D
	
	// 1% of 165428 if Census3Dg is 1654
	//smplGauss3D_0872, 0436, 0218
	//DATA_Gauss3D_B_workload, 100
	//DATA_Array3D_B_workload, 100

	int i,iErr = 0;
	char tmp[100] = "";
	CString CStrInsert = ""; 
	
	SWORD  sAge;
	SDWORD cbAge;

	SDWORD sIncome;
	SDWORD cbIncome;

	SDWORD sWPY;
	SDWORD cbWPY;

	//int iSizeSmpl = 218; //436; //872; // FOR GAUSS
	//int iSizeSmpl = 872; //436; //218; // FOR ARRAY
	
	//int iSizeSmpl = 2160; //5000; //250; // 200;//400; //800; //1000; //2000; 
						 ////||||100, 200, 400, 800, 1000,2000. 
						  // size of census2Dg = 145,917; CLMB_census = 210,138.
						  // Date 2003.3.24
	int iSizeSmpl = 100; // for workload, GAUSS, ARRAY

	HSTMT   hstmt_Generet2DWorkload;

	srand( (unsigned)time( NULL ) );


		if(!zlOpenDB())
		{
			AfxMessageBox("zlOpenDB() err!");
			zlCloseDB();
		}else
		{
			retcode = SQLAllocStmt(hdbc, &hstmt_Generet2DWorkload); ///Statement handle 

			//lStartTimer = GetTickCount();

			//UCHAR szSqlAllRows[] = "SELECT * FROM Gauss2Dg"; //discounts, authors, Census2DTable						
			//UCHAR szSqlAllRows[] = "SELECT * FROM Census2Dg"; //discounts, authors, Census2DTable						
			//UCHAR szSqlAllRows[] = "SELECT * FROM Census3Dg"; //discounts, authors, Census2DTable						
		
			//UCHAR szSqlAllRows[] = "SELECT * FROM CLMB_Gauss3D"; //discounts, authors, Census2DTable						
			UCHAR szSqlAllRows[] = "SELECT * FROM Array3Dg"; //discounts, authors, Census2DTable						
											   
			
			SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
			SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
			retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);

			//lEndTimer = GetTickCount() - lStartTimer;
			//wsprintf(tmp, "%ld", lEndTimer);

			//1111111111111 read data base 111111111111111

			if (retcode == SQL_SUCCESS) 
			{    //	retcode = SQLExecDirect
				int iRowCount, iTupleNum, iSpan, iSampleNum, iStartRowNum, iTotalNum;
				SDWORD *  RowCountPtr = new SDWORD ;
				retcode = SQLRowCount(hstmt, RowCountPtr);						 
				iRowCount = * RowCountPtr;
				iTupleNum = iRowCount;
				iSpan = (int) (iRowCount/iSizeSmpl);
				iSampleNum =0;
				delete RowCountPtr;
				
				// Bind columns 1,2,3
				SQLBindCol(hstmt, 1, SQL_C_SSHORT, &sAge, 0, &cbAge);
				SQLBindCol(hstmt, 2, SQL_C_SLONG, &sIncome,0, &cbIncome); //SQL_C_SSHORT
				SQLBindCol(hstmt, 3, SQL_C_SLONG, &sWPY,0, &cbWPY); //SQL_C_SSHORT

				//int * pAge = new  int[iRowCount];//new float[10]
				//int * pIncome = new  int[iRowCount];//new float[10]
				//int * pWPY = new int [iRowCount] //, * pWPYHold;

				iRowCount = 0;
				iStartRowNum = 0;
				iTotalNum = 0;
				
				while (TRUE) 
				{
					
					int iRandom = rand()%(iSpan-1);
					for (i = iStartRowNum; i < iSampleNum + iRandom; i++)
					{
					      retcode = SQLFetch(hstmt);
						  iRowCount ++ ; 
					}

					if (retcode == SQL_ERROR)
					{
						//show_error();

						wsprintf(tmp, "%ld", iRowCount);
						//int i = iRowCount;
						AfxMessageBox("SQLFetch Error !!!!!!");
								//break; //99.8.26
					}

					if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO ||iRowCount>= iSampleNum)
							//if (retcode == SQL_SUCCESS)
					{	

						char cAge[20] = "", cIncome[20] = "", cWPY[20] = "",cTupleNum[20] ="";

						sprintf(cAge,"%d",sAge);
						sprintf(cIncome,"%ld",sIncome);
						sprintf(cWPY,"%ld",sWPY);

						sprintf(cTupleNum,"%ld",iRowCount);

						
						//CStrInsert += " INSERT DATA_Gauss2Dg_workload VALUES( ";	
						//CStrInsert += " INSERT smpl2000_Census2D VALUES( ";
						//CStrInsert += " INSERT smpl1000_Census2D VALUES( ";
						//CStrInsert += " INSERT smpl0800_Census2D VALUES( ";
						//CStrInsert += " INSERT smpl0400_Census2D VALUES( ";
						//CStrInsert += " INSERT smpl0200_Census2D VALUES( ";
						//CStrInsert += " INSERT smpl0100_Census2D VALUES( ";
						//CStrInsert += " INSERT smpl0250_Census2D VALUES( ";
						//CStrInsert += " INSERT smpl1459_Census2D VALUES( ";
						//CStrInsert += " INSERT smpl1654_Census3D VALUES( ";
						//CStrInsert += " INSERT smpl5000_Gauss3D VALUES( ";
						
						//CStrInsert += " INSERT smplGauss3D_0218 VALUES( ";
						
						//CStrInsert += " INSERT smpl2160_Array3D VALUES( ";
						//CStrInsert += " INSERT Array3D_smpl0218 VALUES( ";
						//CStrInsert += " INSERT Array3D_smpl0436 VALUES( ";
						//CStrInsert += " INSERT Array3D_smpl0872 VALUES( ";
						CStrInsert += " INSERT Array3Dg_B_workload VALUES( ";
						
			
						//CStrInsert += " INSERT DATA_Gauss3D_B_workload VALUES( ";

						
						
						CStrInsert += cAge;
						CStrInsert += ",";
						CStrInsert += cIncome;
						CStrInsert += ",";
						CStrInsert += cWPY;
		
						//CStrInsert += ",";
						//CStrInsert += cTupleNum;
						CStrInsert += ")";

						int iSqlLen = CStrInsert.GetLength();

						char * szSqlInsert = new char [iSqlLen + 1];
						strcpy(szSqlInsert , "");
						strcat(szSqlInsert , CStrInsert);
							
						retcode = SQLExecDirect(hstmt_Generet2DWorkload, (unsigned char *)szSqlInsert, SQL_NTS);


						if (retcode == SQL_SUCCESS) 
						{  //	retcode = SQLExecDirect
							//AfxMessageBox("Insert new Recode Seccess!");
							//bReturn = TRUE;
							iTotalNum ++;
						}
						else
						{
						//	AfxMessageBox("Insert new Recode Error!");
							iErr++;

						} //	retcode = SQLExecDirect 
					
						CStrInsert = "";
						delete [] szSqlInsert; 

						iStartRowNum = iRowCount;
						iSampleNum += iSpan ;
					} 
					else 
					{
						break;
					}

					if(iTotalNum >=iSizeSmpl)
						break;


				}   ///while (TRUE)			
					
						//delete [] pAge;//new float[10]
						//delete [] pIncome;//new float[10]

			}//	retcode = SQLExecDirect



		//111111111111111111 read data base end111111111111


		}


	SQLFreeStmt(hstmt, SQL_DROP);
	SQLFreeStmt(hstmt_Generet2DWorkload, SQL_DROP);
	zlCloseDB();

	AfxMessageBox("Insert hstmt_Generet2DWorkload OK!");
	
}

void CMainFrame::OnSmpl5000Gauss3D_2160Array3DProfile() 
{

	//2005.08.04 reuse this function
	//$$
	//Create Gauss3D and Array3D profile with	5000, 2160 samples
	// with distance functions: MAX, EUCL, SUM
	// Menu: Creat_TopNProfile --> smpl5000_Gauss3D_Array3D_Profile(3 distance)

	/*****************************
	* 1. read all tuples from : CLMB_census3D store a buffer
	* 2. Read all tuple from  : smpl1654_Census3D 
	* 3. evaluate r, f, c, -d,
	* 4. insert zeta into	  : Top100_Census3D_Profile1654 
	******************************/

	int N, f, c, d = 0; 

	int i,j, k, iErr = 0;
	char tmp[100] = "";
	CString CStrSelect = ""; 
	CString CStrInsert = "";

	int longTicks =0, shortTicks =0;
	
	SWORD  sAge;
	SDWORD cbAge;

	SDWORD sIncome;
	SDWORD cbIncome;

	SDWORD sWPY;
	SDWORD cbWPY;


	HSTMT   hstmt_Census2D_WorkLoad; //for queries workload
	HSTMT   hstmt_Census2D_Profile;  //for insert Profile

	int iTupleNum;//,iStartRowNum, iTotalNum;

	int * q1, *q2, *q3,*q1Hold, *q2Hold, *q3Hold;
	
	//int iSizeSmpl = 2160; //5000; // 1654; //250; //200; //400; //800; //1000; //2000;
	//int iTopN = 1000; //250; //50; //100; //250;//50; //50; 100; 250; 1000
	
	//int iSizeSmpl = 218; //436;  //872; for Gauss Profile sets
	int iSizeSmpl = 100; //for workload

	//int iSizeSmpl = 218; //872;//436;//218; // for Array

	int iTopN = 100; //1000; //250; //50;

	//int iSizeSmpl = 100; //for workload
	//int iSizeSmpl = 218; //for Uniform Profiles
	
	double rd, dis[2000], r[2000], x[105]; 
	int tuple1[2000],tuple2[2000],tuple3[2000];


	if(!zlOpenDB())
	{
		AfxMessageBox("zlOpenDB() err!");
		zlCloseDB();
	}else
	{
		retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_WorkLoad); ///queries Statement handle 
		retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_Profile); /// Profile Statement handle 

		//1. read all tuples from census2Dg store a buffer
		//1111111111111 read data base from census2Dg 111111111111111	

		//UCHAR szSqlAllRows[] = "select  * from census2dg where (15 - 9 <=age and age<=15+ 9 ) and (15- 9 <=Income and Income <=15+ 9 )";
		
		//----------------------------------------------------
		
		UCHAR szSqlAllRows[] = "SELECT * FROM CLMB_Gauss3D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM CLMB_Array3D"; //discounts, authors, Census2DTable						

		//------------------------------------------------------


		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		
		longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);
		longTicks = GetTickCount() - longTicks;

		//lEndTimer = GetTickCount() - lStartTimer;
		//wsprintf(tmp, "%ld", lEndTimer);


		if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) 
		{    //	retcode = SQLExecDirect for census2Dg
			int iRowCount;
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt, RowCountPtr);						 
			iRowCount = * RowCountPtr;
			iTupleNum = iRowCount;
			delete RowCountPtr;
			
			// Bind columns 1,2,3
			SQLBindCol(hstmt, 1, SQL_C_SSHORT, &sAge, 0, &cbAge);
			SQLBindCol(hstmt, 2, SQL_C_SLONG, &sIncome,0, &cbIncome); //SQL_C_SSHORT
			SQLBindCol(hstmt, 3, SQL_C_SLONG, &sWPY,0, &cbWPY); //SQL_C_SSHORT

			pAge = new  int[iRowCount];//buffer, new float[10]
			pIncome = new  int[iRowCount];//buffer , new float[10]
			pWPY = new  int[iRowCount];
			
			pAgeHold = pAge;
			pIncomeHold = pIncome;
			pWPYHold = pWPY;

			iRowCount =0;
			while (TRUE) 
			{
				retcode = SQLFetch(hstmt);

				if (retcode == SQL_ERROR)
				{
					//show_error();

					wsprintf(tmp, "%ld", iRowCount);
					//int i = iRowCount;
					AfxMessageBox("SQLFetch Error !!!!!!");
							//break; //99.8.26
				}

				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
						//if (retcode == SQL_SUCCESS)
				{	

					*pAge		= sAge;
					*pIncome	= sIncome;
					*pWPY		= sWPY;
					pAge++;
					pIncome++;
					pWPY++;

					if(retcode == SQL_SUCCESS_WITH_INFO)
					{
						wsprintf(tmp, "%ld", retcode);
						AfxMessageBox(tmp);

					}
						
				} 
				else 
				{
					break;
				}

			}   ///while (TRUE)

			pAge = pAgeHold ;
			pIncome = pIncomeHold ;
			pWPY = pWPYHold ;

	
		}//	retcode = SQLExecDirect  for census2Dg

	//111111111111111111 read data base  census2Dg end   111111111111

	//2. Read all tuple from smpl_DB_tables : DATA_Top100_Census2D_WorkLoad ,100 smpl
										//	  smpl2000_Census2D				 2000 smpl
		
		sAge = 0;cbAge = 0;sIncome = 0;cbIncome= 0;sWPY = 0; cbWPY = 0;

		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Top100_Census2D_WorkLoad"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl2000_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl1000_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl0800_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl0400_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl0200_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl0100_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl0250_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl1459_Census2D"; //discounts, authors, Census2DTable						
		
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl1654_Census3D"; //discounts, authors, Census2DTable						
		
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl5000_Gauss3D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smplGauss3D_0872"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smplGauss3D_0436"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smplGauss3D_0218"; //discounts, authors, Census2DTable						
		
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Gauss3D_B_workload"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Gauss3D_U_WorkLoad"; //discounts, authors, Census2DTable						
		
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Gauss3D_U_smpl0218"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Gauss3D_smpl0218"; //2005.08.04				
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Gauss3D_B_WorkLoad"; //2005.08.04				
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Gauss3D_B_WorkLoad_1"; //2005.08.04				
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Gauss3D_B_WorkLoad_2"; //2005.08.04				
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Gauss3D_B_WorkLoad_3"; //2006.03.23				
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Gauss3D_B_WorkLoad_4"; //2006.03.23				
		UCHAR szSqlAllQueryRows[] = "SELECT * FROM Gauss3D_B_WorkLoad_5"; //2006.03.23				

		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Array3D_smpl0218"; //2005.08.04				
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Array3D_B_WorkLoad"; //2005.08.04				
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Array3D_B_WorkLoad_1"; //2005.08.04				
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Array3D_B_WorkLoad_2"; //2005.08.04				
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Array3D_B_WorkLoad_3"; //2006.03.23				
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Array3D_B_WorkLoad_4"; //2006.03.23				
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Array3D_B_WorkLoad_5"; //2006.03.23				
		
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl2160_Array3D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Array3D_smpl0218"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Array3D_smpl0436"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Array3D_smpl0872"; //discounts, authors, Census2DTable						
		
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Array3Dg_B_workload"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Array3D_U_WorkLoad"; //discounts, authors, Census2DTable						
	
		SQLSetStmtOption(hstmt_Census2D_WorkLoad, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt_Census2D_WorkLoad, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		retcode = SQLExecDirect(hstmt_Census2D_WorkLoad, szSqlAllQueryRows, SQL_NTS);

		//lEndTimer = GetTickCount() - lStartTimer;
		//wsprintf(tmp, "%ld", lEndTimer);


		if (retcode == SQL_SUCCESS  || retcode == SQL_SUCCESS_WITH_INFO) 
		{    //	retcode = SQLExecDirect for census2Dg
			int iRowCount;
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt_Census2D_WorkLoad, RowCountPtr);						 
			iRowCount = * RowCountPtr;
			delete RowCountPtr;
			
			// Bind columns 1,2,3
			SQLBindCol(hstmt_Census2D_WorkLoad, 1, SQL_C_SSHORT, &sAge, 0, &cbAge);
			SQLBindCol(hstmt_Census2D_WorkLoad, 2, SQL_C_SLONG, &sIncome,0, &cbIncome); //SQL_C_SSHORT
			SQLBindCol(hstmt_Census2D_WorkLoad, 3, SQL_C_SLONG, &sWPY,0, &cbWPY); //SQL_C_SSHORT

			q1 = new  int[iRowCount];//buffer, new float[10]
			q2 = new  int[iRowCount];//buffer , new float[10]
			q3 = new  int[iRowCount];//buffer , new float[10]
		
			q1Hold = q1; q2Hold= q2; q3Hold = q3;
			

			while (TRUE) 
			{
				retcode = SQLFetch(hstmt_Census2D_WorkLoad);

				if (retcode == SQL_ERROR)
				{
					//show_error();

					wsprintf(tmp, "%ld", iRowCount);
					//int i = iRowCount;
					AfxMessageBox("SQLFetch Error !!!!!!");
							//break; //99.8.26
				}

				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
						//if (retcode == SQL_SUCCESS)
				{	
					*q1	= sAge;*q2	= sIncome;*q3 = sWPY;
					q1++;		q2++;			q3++;
					
				} 
				else 
				{
					break;
				}

			}   ///while (TRUE)
			
			q1= q1Hold; q2= q2Hold;q3= q3Hold;
				
		}//	retcode = SQLExecDirect  for query q1,q2.
	
	//3. evaluate r, f, -c, -d,

		double ftmp=0;
		int itmp = 0,qnum =0; 
		int topt1[1000],topt2[1000],topt3[1000];


		do
		{
			//take first 100 as Top100 ( OR Top-N)
			for(i = 0; i<iTopN; i++)
			{
			  
			  x[1]=abs(pAge[i]- q1[qnum]);x[2]=abs(pIncome[i]-q2[qnum]);x[3]=abs(pWPY[i]-q3[qnum]);
			  
			  //--- 3 Distances
			  dis[i] = (double)max( x[1], x[2]); dis[i] = (double)max(dis[i], x[3]);//MAX distance
			  //dis[i] = (double)sqrt( x[1]*x[1] + x[2]*x[2] + x[3]*x[3]);  //EUCL distance
			  //dis[i] = (double)( x[1] + x[2] + x[3]); //SUM distance 

			  tuple1[i] = pAge[i];
			  tuple2[i] = pIncome[i];
			  tuple3[i] = pWPY[i];

			}
			i=0;

			//sorting the first 100 tuples
			for(i=0; i<iTopN; i++)
			{
				r[i] = dis[i];
				topt1[i] = tuple1[i] ; topt2[i]=tuple2[i] ; topt3[i]=tuple3[i] ;
				for( j= i+1; j<iTopN; j++)
				{
					if(dis[j] < r[i]) 
					{ ftmp = r[i];    r[i] = dis[j];  dis[j] = ftmp;
					  itmp = topt1[i]; topt1[i]= tuple1[j]; tuple1[j]= itmp;
					  itmp = topt2[i]; topt2[i]= tuple2[j]; tuple2[j]= itmp;
					  itmp = topt3[i]; topt3[i]= tuple3[j]; tuple3[j]= itmp;

					}
				}
			}
			
			i=0;
			//2. select top100 (topN)from all tuples with size iTupleNum
			//for(i=100; i<iTupleNum; i++)
			for(i = iTopN; i<iTupleNum; i++)
			{
			  
				x[1]=abs(pAge[i]- q1[qnum]);x[2]=abs(pIncome[i]-q2[qnum]);x[3]=abs(pWPY[i]-q3[qnum]);
				
				//--- 3 Distances
				ftmp = (double)max( x[1], x[2]); ftmp = (double)max(ftmp, x[3]);//MAX distance
				//ftmp = (double)sqrt( x[1]*x[1] + x[2]*x[2] + x[3]*x[3]); //EUCL distance
				//ftmp = (double)( x[1] + x[2] + x[3]); //SUM distance 

				if(ftmp <0)
					int itest = 0;
				//if(ftmp < r[iTopN - 1])	 //2005.08.05	
				if(0<ftmp && ftmp < r[iTopN - 1])		//2005.08.05, gurantee not all same tuples are topN tuples
				{
					for(j=0;j<iTopN;j++)
					{
						if(ftmp<r[j])
						{
							for(k=iTopN - 1; k>j; k--)
							{
								r[k] = r[k-1];
								topt1[k] = topt1[k-1];
								topt2[k] = topt2[k-1];
								topt3[k] = topt3[k-1];
							}
							r[j]=ftmp;
							topt1[j] = pAge[i];
							topt2[j] = pIncome[i];
							topt3[j] = pWPY[i];
							break;
						}
					}
				}
			}
		
		//int N, rd,f, c, d; 	
			
//////////////////
			/*************************
		SQLFreeStmt(hstmt, SQL_DROP);
		retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 

		
		//UCHAR szSqlAllRows[] = "SELECT * FROM census2Dg"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM CLMB_census2D"; //discounts, authors, Census2DTable						
		
		//UCHAR szSqlAllRows[] = "SELECT * FROM CLMB_Array3D"; //discounts, authors, Census2DTable						

		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		
		longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);
		longTicks = GetTickCount() - longTicks;
		////***********************/
//////////////////////////
				
						
			
			CTime CurTime = CTime::GetCurrentTime();         

			//N = 100; rd = r[99]; //r[99] means the distance from last_tuple (top100) to the query
			N = iTopN; 
			
			//rd = r[iTopN-1]; //r[99] means the distance from last_tuple (top100) to the query
		
			c = -1; d--; //d = - CurTime.GetTime(); d++;
			
			for(i = 0; i<iTopN; i++)
			{
			  //dis[i] =(float)max( ( max( abs(topt1[i]- q1[qnum]),abs(topt2[i]-q2[qnum]))), abs(topt3[i]-q3[qnum]) ); //MAX distance
			  
				dis[i] = (float)max( abs(topt1[i]- q1[qnum]),abs(topt2[i]-q2[qnum]) );
				dis[i] = (float)max( dis[i], abs(topt3[i]-q3[qnum]) ); //MAX distance
			  
			}
			
			//find the square's radius, which is the max of all distance from Q to top-N tuples
			rd = dis[0];
				
			for( j= 1; j<iTopN; j++)
			{
				if(dis[j] > rd) 
				{ 
					ftmp = rd; rd = dis[j];  dis[j] = ftmp;
				}
			}
			

			char cAgeLeft[20] = "", cAgeRight[20] = "", cIncomeLeft[20] = "", cIncomeRight[20] ="";
			char cWPYLeft[20] = "", cWPYRight[20] = "";
		
			sprintf(cAgeLeft,		"%f",	(float)(q1[qnum] - rd)	);
			sprintf(cAgeRight,		"%f",	(float)(q1[qnum] + rd)	);
			sprintf(cIncomeLeft,	"%f",	(float)(q2[qnum] - rd)	);
			sprintf(cIncomeRight,	"%f",	(float)(q2[qnum] + rd)	);
			sprintf(cWPYLeft,		"%f",	(float)(q3[qnum] - rd)	);
			sprintf(cWPYRight,		"%f",	(float)(q3[qnum] + rd)	);


			
			////*********** GAUSS ***********	
			CStrSelect += "select  * from CLMB_Gauss3D where (";
			CStrSelect += cAgeLeft;
			CStrSelect += "<= q1 AND q1 <=";
			CStrSelect += cAgeRight;

			CStrSelect += ") AND (";
			CStrSelect += cIncomeLeft;
			CStrSelect += "<= q2 AND q2 <=";
			CStrSelect += cIncomeRight;

			CStrSelect += ") AND (";
			CStrSelect += cWPYLeft;
			CStrSelect += "<= q3 AND q3 <=";   //WeeksPerYear
			CStrSelect += cWPYRight;

			CStrSelect += ")"; 
			//****************************/


			/**************  ARRAY ********	
			CStrSelect += "select  * from CLMB_Array3D where (";

			CStrSelect += cAgeLeft;
			CStrSelect += "<= Aq1 AND Aq1 <=";
			CStrSelect += cAgeRight;

			CStrSelect += ") AND (";
			CStrSelect += cIncomeLeft;
			CStrSelect += "<= Aq2 AND Aq2 <=";
			CStrSelect += cIncomeRight;

			CStrSelect += ") AND (";
			CStrSelect += cWPYLeft;
			CStrSelect += "<= Aq3 AND Aq3 <=";   //WeeksPerYear
			CStrSelect += cWPYRight;

			CStrSelect += ")"; 
			****************************/

			int iSqlLen = CStrSelect.GetLength();
			char * szSqlSquareRows = new char [iSqlLen + 1];	
			strcpy(szSqlSquareRows , "");
			strcat(szSqlSquareRows , CStrSelect);
	
			SQLFreeStmt(hstmt, SQL_DROP);
			retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 


			//szSqlSquareRows= "select  * from census2dg where ";// (15 - 9 <=age and age<=15+ 9 ) and (15- 9 <=Income and Income <=15+ 9 )";
			SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
			SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
			
			shortTicks = GetTickCount();
			retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlSquareRows, SQL_NTS);
			shortTicks = GetTickCount() - shortTicks;

			//lEndTimer = GetTickCount() - lStartTimer;
			//wsprintf(tmp, "%ld", lEndTimer);

			if (retcode == SQL_SUCCESS) 
			{    //	retcode = SQLExecDirect for census2Dg
				SDWORD *  RowCountPtr = new SDWORD ;
				retcode = SQLRowCount(hstmt, RowCountPtr);						 
				f = * RowCountPtr;
				delete RowCountPtr;
			}
			CStrSelect = "";
			delete [] szSqlSquareRows;

	//4. insert zeta into the Profiles: DATA_Top100_Census2D_Profile
									//	Top100_Census2D_Profile2000
									// Top100_Census3D_Profile1654
		
			if (f!= 0)
			{   
				char	cAttribute[10][50]= { "","","","","","","","","",""};

				
				sprintf(cAttribute[0],	"%ld", q1[qnum] );
				sprintf(cAttribute[1],	"%ld", q2[qnum] );
				sprintf(cAttribute[1+1],"%ld", q3[qnum] );

				sprintf(cAttribute[2+1],"%ld", N);
				sprintf(cAttribute[3+1],"%f",  (float)rd);
				sprintf(cAttribute[4+1],"%ld", f );
				sprintf(cAttribute[5+1],"%ld", c );
				sprintf(cAttribute[6+1],"%ld", d);
				sprintf(cAttribute[7+1],"%ld", longTicks);
				sprintf(cAttribute[8+1],"%ld", shortTicks);

				//---------tables---------------
				//CStrInsert += " INSERT DATA_Top100_Census2D_Profile VALUES( ";	
				//CStrInsert += " INSERT Top100_Census2D_Profile VALUES( ";	
				//CStrInsert += " INSERT Top100_Census2D_Profile2000 VALUES( ";	
				//CStrInsert += " INSERT Top100_Census2D_Profile1000 VALUES( ";	
				//CStrInsert += " INSERT Top100_Census2D_Profile0800 VALUES( ";	
				//CStrInsert += " INSERT Top100_Census2D_Profile0400 VALUES( ";	
				//CStrInsert += " INSERT Top100_Census2D_Profile0200 VALUES( ";	
				//CStrInsert += " INSERT Top100_Census2D_Profile0250 VALUES( ";	
				//CStrInsert += " INSERT Top100_Census2D_Profile1459 VALUES( ";	
				
				//CStrInsert += " INSERT Top50_Census2D_Profile1459 VALUES( ";	
				//CStrInsert += " INSERT Top250_Census2D_Profile1459 VALUES( ";	
				//CStrInsert += " INSERT Top1000_Census2D_Profile1459 VALUES( ";	
				
				//CStrInsert += " INSERT Top100_Census2D_Profile1459_EUCL VALUES( ";	
				//CStrInsert += " INSERT Top100_Census2D_Profile1459_SUM VALUES( ";	
				
				//CStrInsert += " INSERT Top100_Census3D_Profile1654 VALUES( ";	
				//CStrInsert += " INSERT Top100_Census3D_Profile1654_EUCL VALUES( ";	
				//CStrInsert += " INSERT Top100_Census3D_Profile1654_SUM VALUES( ";	
		
				//CStrInsert += " INSERT Top100_Gauss3D_Profile5000 VALUES( ";	
				//CStrInsert += " INSERT Top100_Gauss3D_Profile5000_EUCL VALUES( ";	
				//CStrInsert += " INSERT Top100_Gauss3D_Profile5000_SUM VALUES( ";	
				
				//CStrInsert += " INSERT Top100_Array3D_Profile2160 VALUES( ";	
				//CStrInsert += " INSERT Top100_Array3D_Profile2160_EUCL VALUES( ";	
				//CStrInsert += " INSERT Top100_Array3D_Profile2160_SUM  VALUES( ";	
				
				//CStrInsert += " INSERT Top100_Gauss3D_Profile0872  VALUES( ";	
				//CStrInsert += " INSERT Top100_Gauss3D_Profile0436  VALUES( ";	
				//CStrInsert += " INSERT Top100_Gauss3D_Profile0218  VALUES( ";	
				//CStrInsert += " INSERT Gauss3D_T0100_B_OPT  VALUES( ";					
				//CStrInsert += " INSERT Gauss3D_T0100_U_OPT  VALUES( ";	
				//CStrInsert += " INSERT Gauss3D_T0100_U_P0218  VALUES( ";	

				//CStrInsert += " INSERT Gauss3D_T0100_B_OPT_EUCL  VALUES( ";					
				//CStrInsert += " INSERT Gauss3D_T0100_B_OPT_SUM  VALUES( ";					

				//CStrInsert += " INSERT Gauss3D_P0218_EUCL  VALUES( ";									
				//CStrInsert += " INSERT Gauss3D_P0218_SUM  VALUES( ";					

				//CStrInsert += " INSERT Gauss3D_T0050_B_OPT  VALUES( ";					
				//CStrInsert += " INSERT Gauss3D_T0250_B_OPT  VALUES( ";					
				//CStrInsert += " INSERT Gauss3D_T1000_B_OPT  VALUES( ";					

				//CStrInsert += " INSERT Gauss3D_Top100_Profile0218  VALUES( ";					
				//CStrInsert += " INSERT Gauss3D_T0100_OPT  VALUES( ";					
				//CStrInsert += " INSERT Gauss3D_T0100_OPT_1  VALUES( ";					
				//CStrInsert += " INSERT Gauss3D_T0100_OPT_2  VALUES( ";					
				//CStrInsert += " INSERT Gauss3D_T0100_OPT_3  VALUES( ";					
				//CStrInsert += " INSERT Gauss3D_T0100_OPT_4  VALUES( ";					
				CStrInsert += " INSERT Gauss3D_T0100_OPT_5  VALUES( ";					

				//CStrInsert += " INSERT Array3D_Top100_Profile0218  VALUES( ";					
				//CStrInsert += " INSERT Array3D_T0100_OPT  VALUES( ";					
				//CStrInsert += " INSERT Array3D_T0100_OPT_1  VALUES( ";					
				//CStrInsert += " INSERT Array3D_T0100_OPT_2  VALUES( ";					
				//CStrInsert += " INSERT Array3D_T0100_OPT_3  VALUES( ";					
				//CStrInsert += " INSERT Array3D_T0100_OPT_4  VALUES( ";					
				//CStrInsert += " INSERT Array3D_T0100_OPT_5  VALUES( ";					

				//CStrInsert += " INSERT Array3D_Top100_Profile0218  VALUES( ";	
				//CStrInsert += " INSERT Array3D_Top100_Profile0436  VALUES( ";	
				//CStrInsert += " INSERT Array3D_Top100_Profile0872 VALUES( ";	
				//CStrInsert += " INSERT Array3D_T0100_B_OPT VALUES( ";	
				//CStrInsert += " INSERT Array3D_T0100_U_OPT VALUES( ";	
				
				//CStrInsert += " INSERT Array3D_P0218_EUCL  VALUES( ";									
				//CStrInsert += " INSERT Array3D_P0218_SUM  VALUES( ";										
				//CStrInsert += " INSERT Array3D_T0100_B_OPT_EUCL  VALUES( ";									
				//CStrInsert += " INSERT Array3D_T0100_B_OPT_SUM  VALUES( ";									
				//CStrInsert += " INSERT Array3D_T0050_B_OPT  VALUES( ";									
				//CStrInsert += " INSERT Array3D_T0250_B_OPT  VALUES( ";									
				//CStrInsert += " INSERT Array3D_T1000_B_OPT  VALUES( ";									

				CStrInsert += cAttribute[0];
				CStrInsert += ",";
				CStrInsert += cAttribute[1];
				CStrInsert += ",";
				CStrInsert += cAttribute[1+1];
				CStrInsert += ",";
				
				CStrInsert += cAttribute[2+1];
				CStrInsert += ",";
				CStrInsert += cAttribute[3+1];
				CStrInsert += ",";
				CStrInsert += cAttribute[4+1];
				CStrInsert += ",";
				CStrInsert += cAttribute[5+1];
				CStrInsert += ",";
				CStrInsert += cAttribute[6+1];
				CStrInsert += ",";
				CStrInsert += cAttribute[7+1];
				CStrInsert += ",";
				CStrInsert += cAttribute[8+1];
				CStrInsert += ")";


			    int iSqlLen = CStrInsert.GetLength();

				char * szSqlInsert = new char [iSqlLen + 1];
				strcpy(szSqlInsert , "");
				strcat(szSqlInsert , CStrInsert);


				SQLFreeStmt(hstmt_Census2D_Profile, SQL_DROP);
				retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_Profile); /// Profile Statement handle 
				
				SQLSetStmtOption(hstmt_Census2D_Profile, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
				SQLSetStmtOption(hstmt_Census2D_Profile, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
				

				retcode = SQLExecDirect(hstmt_Census2D_Profile, (unsigned char *)szSqlInsert, SQL_NTS);

				if (retcode == SQL_SUCCESS) 
				{  //	retcode = SQLExecDirect
					//AfxMessageBox("Insert new hstmt_Census2D_Profile  OKKKKKKKKKKK!");
					//Sleep(200);
						//bReturn = TRUE;
				}
				else
				{
					AfxMessageBox("Insert hstmt_Census2D_Profile Error!");
					i= 0;
				} //	retcode = SQLExecDirect 
				
				f=0;

				CStrInsert = "";
				delete [] szSqlInsert;
			}
		

			qnum++;
		}while(qnum <iSizeSmpl); //100);

	}//if(!zlOpenDB())

	delete [] pAge;//new float[10]
	delete [] pIncome;//new float[10]
	delete [] pWPY;//new float[10]

	delete [] q1;//new float[10]
	delete [] q2;//new float[10]
	delete [] q3;//new float[10]

	//SQLFreeStmt(hstmt, SQL_DROP);
	SQLFreeStmt(hstmt_Census2D_WorkLoad, SQL_DROP);
	SQLFreeStmt(hstmt_Census2D_Profile, SQL_DROP);

	zlCloseDB();

	AfxMessageBox("Insert hstmt_Generet2D_profile OK!");
}

void CMainFrame::OnCensus2d_T0100_B_learning_P1459() 
{
	
	//Learning: Top100 census2d biased from profile with 1459 smpl, 
	
	// --Read: DATA_Top100_Census2D_Profile, as Profile
	// Read:  Top100_Census2D_Profile, as Profile
	// Read: DATA_Census2Dg_B_workload, as Biased Query workload
	// write:DATA_Top100_Census2D_Learning
	// Top100, distance = EUCL, SUM ,Type = Biased 
	// 
	// add 2 attributes f_rst, shortTicks_rst, 2003/4/5
	//
	/////////////////////////////////////////////////////
	

	int N, f = 0, c =0, d = 0; 

	int i,j, iErr = 0;
	char tmp[100] = "";
	CString CStrSelect = ""; 
	CString CStrInsert = "";

	int longTicks =0, shortTicks =0;
	int f_rst= 0, shortTicks_rst = 0; //2003/4/5

	SWORD  sAge;
	SDWORD cbAge;

	SDWORD sIncome;
	SDWORD cbIncome;
	SDWORD sN,sr,sf,sc,sd;
	SDWORD cbN,cbr,cbf,cbc,cbd;


	HSTMT   hstmt_Census2D_WorkLoad; //for queries workload
	HSTMT   hstmt_Census2D_Profile;  //for insert Profile

	//int iTupleNum;//,iStartRowNum, iTotalNum;

	int * q1, *q2, *q1Hold, *q2Hold; //for queries workload
	
	double rd =0.0, dis[2000], r[2000];  //rd is the final radius distance of Q; dis[]= d(Q,Q'), r[] id dis[];
	int tuple1[2000],tuple2[2000];

	double rr[2000],rOrder[2000]; 
	//double x[105];

	int iSizeProfile = 178; //365; //730; //1459;
	//int iSizeProfile = 250; //100; //200; //400; //800; //1000; //2000;

	int iTopN = 100;

	int iInsertOK = 0, iInsertERR = 0, irderr = 0;


	if(!zlOpenDB())
	{
		AfxMessageBox("zlOpenDB() err!");
		zlCloseDB();
	}else
	{
		retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_WorkLoad); ///queries Statement handle 
		retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_Profile); /// Profile Statement handle 

		//1. read all tuples from Profile set store a buffer
		//1111111111111 read database from profiles :DATA_Top100_Census2D_Profile 111111111111111	
												//   Top100_Census2D_Profile2000
		//---------------
		//UCHAR szSqlAllRows[] = "SELECT * FROM DATA_Top100_Census2D_Profile"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile2000"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile1000"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile0800"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile0400"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile0200"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile0100"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile0250"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile1459"; //discounts, authors, Census2DTable						
	
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top50_Census2D_Profile1459"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top250_Census2D_Profile1459"; //discounts, authors, Census2DTable								
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top1000_Census2D_Profile1459"; //discounts, authors, Census2DTable						
		
		 //UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile1459"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile1459_EUCL"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile1459_SUM"; //discounts, authors, Census2DTable						
		 
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile0730"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile0365"; //discounts, authors, Census2DTable						
		UCHAR szSqlAllRows[] = "SELECT * FROM Census2D_Top100_Profile0178"; //discounts, authors, Census2DTable						



		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		
		longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);
		longTicks = GetTickCount() - longTicks;

		//lEndTimer = GetTickCount() - lStartTimer;
		//wsprintf(tmp, "%ld", lEndTimer);


		if (retcode == SQL_SUCCESS) 
		{    //	retcode = SQLExecDirect for DATA_Top100_Census2D_Profile
			int iRowCount;
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt, RowCountPtr);						 
			iRowCount = * RowCountPtr;
			iSizeProfile = iRowCount; // here only size of profile, 100,200, ...,2000
			delete RowCountPtr;
			
			// Bind columns 1,2.
			SQLBindCol(hstmt, 1, SQL_C_SSHORT, &sAge, 0, &cbAge);
			SQLBindCol(hstmt, 2, SQL_C_SLONG, &sIncome,0, &cbIncome); //SQL_C_SSHORT
			SQLBindCol(hstmt, 3, SQL_C_SLONG, &sN,0, &cbN); //SQL_C_SSHORT
			SQLBindCol(hstmt, 4, SQL_C_SLONG, &sr,0, &cbr); //SQL_C_SSHORT
			SQLBindCol(hstmt, 5, SQL_C_SLONG, &sf,0, &cbf); //SQL_C_SSHORT
			SQLBindCol(hstmt, 6, SQL_C_SLONG, &sc,0, &cbc); //SQL_C_SSHORT
			SQLBindCol(hstmt, 7, SQL_C_SLONG, &sd,0, &cbd); //SQL_C_SSHORT

			pPf = new Profile2D[iRowCount];
			pPfHold = pPf;

			pAge = new  int[iRowCount];//buffer, new double[10]
			pIncome = new  int[iRowCount];//buffer , new double[10]
			pAgeHold = pAge;
			pIncomeHold = pIncome;
			iRowCount =0;
			while (TRUE) 
			{
				retcode = SQLFetch(hstmt);

				if (retcode == SQL_ERROR)
				{
					//show_error();
					wsprintf(tmp, "%ld", iRowCount);
					//int i = iRowCount;
					AfxMessageBox("SQLFetch Error !!!!!!");
							//break; //99.8.26
				}

				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
				{	
					*pAge		= sAge;
					*pIncome	= sIncome;
					
					pPf->q[0]	= sAge;				
					pPf->q[1]	= sIncome;
					pPf->N		= sN;
					pPf->r		= (float) sr;
					pPf->f		= sf;
					pPf->c		= sc;
					pPf->d		= sd;

					pAge++;
					pIncome++;

					pPf++;

					if(retcode == SQL_SUCCESS_WITH_INFO)
					{
						wsprintf(tmp, "%ld", retcode);
						AfxMessageBox(tmp);
					}
						
				} 
				else 
				{
					break;
				}

			}   ///while (TRUE)

			pAge = pAgeHold ;
			pIncome = pIncomeHold ;
			pPf	= pPfHold;
		}//	retcode = SQLExecDirect  for DATA_Top100_Census2D_Profile

	//111111111111111111 read data base  DATA_Top100_Census2D_Profile end   111111111111

	//2. Read all Queries from DATA_Census2Dg_B_workload
		sAge = 0;cbAge = 0;sIncome = 0;cbIncome= 0;

		UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Census2Dg_B_workload"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Census2Dg_B_workload1"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Census2Dg_B_workload2"; //discounts, authors, Census2DTable						
		
		SQLSetStmtOption(hstmt_Census2D_WorkLoad, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt_Census2D_WorkLoad, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		retcode = SQLExecDirect(hstmt_Census2D_WorkLoad, szSqlAllQueryRows, SQL_NTS);

		//lEndTimer = GetTickCount() - lStartTimer;
		//wsprintf(tmp, "%ld", lEndTimer);


		if (retcode == SQL_SUCCESS) 
		{    //	retcode = SQLExecDirect for census2Dg
			int iRowCount;
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt_Census2D_WorkLoad, RowCountPtr);						 
			iRowCount = * RowCountPtr;
			delete RowCountPtr;
			
			// Bind columns 1,2.
			SQLBindCol(hstmt_Census2D_WorkLoad, 1, SQL_C_SSHORT, &sAge, 0, &cbAge);
			SQLBindCol(hstmt_Census2D_WorkLoad, 2, SQL_C_SLONG, &sIncome,0, &cbIncome); //SQL_C_SSHORT

			q1 = new  int[iRowCount];//buffer, new double[10]
			q2 = new  int[iRowCount];//buffer , new double[10]
			q1Hold = q1; q2Hold= q2;
			

			while (TRUE) 
			{
				retcode = SQLFetch(hstmt_Census2D_WorkLoad);
				if (retcode == SQL_ERROR)
				{
					//show_error();
					wsprintf(tmp, "%ld", iRowCount);
					//int i = iRowCount;
					AfxMessageBox("SQLFetch Error !!!!!!");
							//break; //99.8.26
				}
				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
				{	
					*q1	= sAge;
					*q2	= sIncome;

					q1++;
					q2++;
				} 
				else 
				{
					break;
				}

			}   ///while (TRUE)
			
			q1= q1Hold; q2= q2Hold;
				
		}//	retcode = SQLExecDirect  for query q1,q2.
	
	



	//3. evaluate r, f, -c, -d,

		double ftmp=0;
		int itmp = 0,qnum =0; 
		int topt1[2000],topt2[2000];
		int frequ[2000],freOrder[2000];

		for(i=0; i<2000; i++)
		{
			topt1[i]=0; topt2[i] =0; frequ[i]=0; freOrder[i] =0;
		}

//////////////////
		SQLFreeStmt(hstmt, SQL_DROP);
		retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 

		//Sleep(100);
		//UCHAR szSqlAllRows[] = "SELECT * FROM census2Dg"; //discounts, authors, Census2DTable						
		UCHAR szSqlAllRowsFrmcensus2D[] = "SELECT * FROM CLMB_census2D"; //discounts, authors, Census2DTable						

		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		
		longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, szSqlAllRowsFrmcensus2D, SQL_NTS);
		longTicks = GetTickCount() - longTicks;

//////////////////////////
		do
		{

//////////////////
		/**************
		SQLFreeStmt(hstmt, SQL_DROP);
		retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 

		//Sleep(100);
		//UCHAR szSqlAllRows[] = "SELECT * FROM census2Dg"; //discounts, authors, Census2DTable						
		UCHAR szSqlAllRowsFrmcensus2D[] = "SELECT * FROM CLMB_census2D"; //discounts, authors, Census2DTable						

		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		
		longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, szSqlAllRowsFrmcensus2D, SQL_NTS);
		longTicks = GetTickCount() - longTicks;
		******************/

//////////////////////////

			////////////for each query find the closed profiles
			//evaluate all distance from New_query(q1[qnum],q2[qnum]) to Profile Point: 
			//														(pAge[i],pIncome[i] )
			// dis[i] = d(Q,Q') = dmax(Q,Q') = max(|qi-q'i|)

			for(i = 0; i<iSizeProfile; i++)
			{
			  dis[i] = (double)max( abs(pAge[i]- q1[qnum]), abs(pIncome[i]-q2[qnum]) );

			  tuple1[i] = pAge[i];
			  tuple2[i] = pIncome[i];
			  rr[i] = pPf[i].r;  //best search radius in Profile
			  frequ[i] = pPf[i].f; 		
			}

			i=0;

			//order all distance
			// r[i]'s are sorting of dis[i] =  d(Q,Q'), to identify the closest Q' to Q
			for(i=0; i<iSizeProfile; i++)
			{
				r[i] = dis[i];  //d(Q,Q')
				topt1[i] = tuple1[i] ; topt2[i]=tuple2[i] ; //profile points
				rOrder[i] = rr[i];  //radius order
				freOrder[i] = frequ[i];

				for( j= i+1; j<iSizeProfile; j++)
				{
					if(dis[j] < r[i]) 
					{ ftmp = r[i];			r[i] = dis[j];		 dis[j] = ftmp;
					  ftmp = rOrder[i];		rOrder[i] = rr[j];	 rr[j] = ftmp;
					  itmp = freOrder[i];   freOrder[i]= frequ[j]; frequ[j] = itmp;

					  itmp = topt1[i];		topt1[i]= tuple1[j]; tuple1[j]= itmp;
					  itmp = topt2[i];		topt2[i]= tuple2[j]; tuple2[j]= itmp;

					}
				}
			}
					
		//int N, rd,f, c, d; 
		//evaluate search distance
		
		int qp1 = topt1[0], qp2= topt2[0]; //Q'(qp1,qp2), the closest proples to Q(q1,q2)
		int iKnum = 0,fpf[2000];
		double frou[2000],l[2000],V[2000], lV=0, lVrou =0, rou = 0;
		double dQQ[2000],rpf[2000];
		double dmaxQQp;

		if(r[0] == 0) // if Q=Q'
		{//if(r[0] == 0)
			rd = rOrder[0];
			//rd = 2*rOrder[0];
			//rd = rOrder[0]/2;
			//rd = rOrder[0]/10;

			int itest = 0; //use to test 
		}
		else
		{
			dmaxQQp = max(  abs( qp1 - q1[qnum]), abs(qp2 - q2[qnum])  ); //i.e.r[0]

			if(dmaxQQp <= rOrder[0])  //case of Fig.3 //rou = N/4*r*r
			{
				iKnum = 0;
				
				for(j=0; j<iSizeProfile; j++)
				{
					frou[j] =0;l[j] =0;V[j] = 0;
					dQQ[j] =0;rpf[j] = 0;fpf[j]=0;
				}

				for(j=0; j<iSizeProfile; j++) //Find set K= (all squares Q in it)
				{
					if( r[j] <= rOrder[j]  ) //d(Q,Qpf) < rpf
					{
						dQQ[iKnum] = r[j];
						rpf[iKnum] = rOrder[j];
						fpf[iKnum] = freOrder[j];

						iKnum++;

					}
						
				}


				//---------- alternative test -----------------
				int iMeadian = iKnum/2;
				rou = 0;
				lVrou = 0; lV = 0;

			// ////////////// lvp
				/***********************
					for(j=0; j<iKnum; j++)
					{
						//l[j] = 1.0/(dQQ[j]* dQQ[j]);
						//l[j] = 1.0/(dQQ[j]);
						l[j] = 1.0;

						frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
						V[j] = 4*rpf[j]*rpf[j];
											
						lV += l[j]*V[j];
						lVrou += l[j]* fpf[j];   // (fpf[j]/(dQQ[j]* dQQ[j]* dQQ[j]));


					}
					rou = lVrou/lV;

					//////////mean of density 
					for(j=0; j<iKnum; j++)
					{
						frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);;
					    rou += frou[j]; 
					}
					rou = rou/iKnum;

					//////////mean of ALL density 
					for(j=0; j<iSizeProfile; j++)
					{
						frou[j] = freOrder[j]/(4*rOrder[j]*rOrder[j]);;
					    rou += frou[j]; 
					}
					rou = rou/iSizeProfile;
					***********************/

					//////////median of ALL density 

					for(j=0; j<iSizeProfile; j++)
					{
						frou[j] = freOrder[j]/(4*rOrder[j]*rOrder[j]);;
					    //rou += frou[j]; 
					}

					iMeadian = iSizeProfile/2;
					rou = frou[iMeadian];


					rd = (double)sqrt(2*100/rou)/2; //sqrt( double x );
	
					if ( (rd < rOrder[0]) ||(rd < dmaxQQp))
					{
						//rd = rd + rd/2;  //rOrder[0] ; + rd/n n-dimension
						rd = rd + max(rd, rOrder[0])/(2.0-1.0);  //rOrder[0] ; + rd/(n-1) n-dimension
						//irderr ++;
					}
	
					if (rd > dmaxQQp + rOrder[0])
					{
						rd = dmaxQQp + rOrder[0];
						//irderr ++;
					}

					if (rd < dmaxQQp)
					{
					//	rd = rOrder[0];
						irderr ++;
					}

				//------------Fig 3.^^^^^----------------



			}else
			{
				dmaxQQp = max(  abs( qp1 - q1[qnum]), abs(qp2 - q2[qnum])  );

				//if(dmaxQQp <= 2*rOrder[0])  //h<2r'
				{
					//case of Fig.4 //rou = N/4*r*r				
					iKnum = 0;
					for(j=0; j<2000; j++)
					{
						frou[j] =0;l[j] =0;V[j] = 0;
						dQQ[j] =0;rpf[j] = 0; fpf[j]=0;			
					}

				
					for(j=0; j<iSizeProfile; j++)
					{
						if(r[j] < rOrder[0] + dmaxQQp)
						{
							dQQ[iKnum] = r[j];
							rpf[iKnum] = rOrder[j];
							fpf[iKnum] = freOrder[j];

							iKnum++;
						}						
					}


				//---------- alternative test -----------------
				lVrou = 0; lV = 0;
				rou = 0;
				int iMeadian = iKnum/2;

					/*************************
					for(j=0; j<iKnum; j++)
					{
						//l[j] = 1.0/(dQQ[j]* dQQ[j]);
						//l[j] = 1.0/(dQQ[j]);
						l[j] = 1.0;

						frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);//100/(4*rpf[j]*rpf[j]);
						V[j] = 4*rpf[j]*rpf[j];
											
						lV += l[j]*V[j];
						lVrou += l[j]* fpf[j];   // (fpf[j]/(dQQ[j]* dQQ[j]* dQQ[j]));

					}
					rou = lVrou/lV;

					//////////mean of density 
					for(j=0; j<iKnum; j++)
					{
						frou[j] = fpf[j]/(4*rpf[j]*rpf[j]);;
					    rou += frou[j]; 
					}
					rou = rou/iKnum;

					//////////mean of ALL density 
					for(j=0; j<iSizeProfile; j++)
					{
						frou[j] = freOrder[j]/(4*rOrder[j]*rOrder[j]);;
					    rou += frou[j]; 
					}
					rou = rou/iSizeProfile;
					*********************/

					//////////median of ALL density 

					for(j=0; j<iSizeProfile; j++)
					{
						frou[j] = freOrder[j]/(4*rOrder[j]*rOrder[j]);;
					    //rou += frou[j]; 
					}

					iMeadian = iSizeProfile/2;
					rou = frou[iMeadian];


					rd = (double)sqrt(2*100/rou)/2; //sqrt( double x );
		
				if ( (rd < rOrder[0]) ||(rd < dmaxQQp))
				{
						//rd = rd + rd/2;  //rOrder[0] ; + rd/n n-dimension
						rd = rd + max(rd, rOrder[0])/(2.0-1.0);  //rOrder[0] ; + rd/(n-1) n-dimension
	
					//irderr ++;
				}
				if (rd > dmaxQQp + rOrder[0])
				{
					rd = dmaxQQp + rOrder[0];
					//irderr ++;

				}

				if (rd < dmaxQQp)
				{
				//	rd = rOrder[0];
					irderr ++;
				}

				//-----------------fig. 4 -^^^^^^ end ---------- 
			
					int itest = 0;
				//}else{                         //2003.4.11

					//rd = dmaxQQp + rOrder[0]; //2003.4.11

				}//if(dmaxQQp <= 2*rOrder[0])

			}//if(dmaxQQp <= rOrder[0])


		}//if(r[0] == 0)

		
		//rd = rOrder[0];

			
			CTime CurTime = CTime::GetCurrentTime();         

			//N = 100; c = -1; d = - CurTime.GetTime();
			
			N = iTopN; c = -1; d-- ;

			char cAgeLeft[20] = "", cAgeRight[20] = "", cIncomeLeft[20] = "", cIncomeRight[20] ="";
			
			sprintf(cAgeLeft,"%f", (double)(q1[qnum] - rd) );
			sprintf(cAgeRight,"%f", (double)(q1[qnum] + rd));
			sprintf(cIncomeLeft,"%f", (double)(q2[qnum] - rd));
			sprintf(cIncomeRight,"%f",(double)(q2[qnum] + rd));

			CStrSelect += "select  * from CLMB_census2d where (";
			CStrSelect += cAgeLeft;
			CStrSelect += "<= age AND age <=";
			CStrSelect += cAgeRight;
			CStrSelect += ") AND (";
			CStrSelect += cIncomeLeft;
			CStrSelect += "<= Income AND Income <=";
			CStrSelect += cIncomeRight;
			CStrSelect += ")"; 

			int iSqlLen = CStrSelect.GetLength();
			char * szSqlSquareRows = new char [iSqlLen + 1];	
			strcpy(szSqlSquareRows , "");
			strcat(szSqlSquareRows , CStrSelect);
	
			SQLFreeStmt(hstmt, SQL_DROP);
			retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 
			//Sleep(200);

			SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
			SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
			
			shortTicks = GetTickCount();
			retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlSquareRows, SQL_NTS);
			shortTicks = GetTickCount() - shortTicks;

			//lEndTimer = GetTickCount() - lStartTimer;
			//wsprintf(tmp, "%ld", irderr ++;);

			if (retcode == SQL_SUCCESS) 
			{    //	retcode = SQLExecDirect for census2Dg
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt, RowCountPtr);						 
			f = * RowCountPtr;
			delete RowCountPtr;

			}
			CStrSelect = "";
			delete [] szSqlSquareRows;

	//4. insert zeta into DATA_Top100_Census2D_Profile
			//if(f<100)
			if(f<iTopN)
			{
				rd = dmaxQQp + rOrder[0];
				for (i = 0; i< 20; i++)
				{
					cAgeLeft[i] = 0; cAgeRight[i] = 0;
					cIncomeLeft[i] = 0; cIncomeRight[i] =0;
				}

				sprintf(cAgeLeft,"%f", (double)(q1[qnum] - rd) );
				sprintf(cAgeRight,"%f", (double)(q1[qnum] + rd));
				sprintf(cIncomeLeft,"%f", (double)(q2[qnum] - rd));
				sprintf(cIncomeRight,"%f",(double)(q2[qnum] + rd));

				CStrSelect = "";
				CStrSelect += "select  * from CLMB_census2D where (";
				CStrSelect += cAgeLeft;
				CStrSelect += "<= age AND age <=";
				CStrSelect += cAgeRight;
				CStrSelect += ") AND (";
				CStrSelect += cIncomeLeft;
				CStrSelect += "<= Income AND Income <=";
				CStrSelect += cIncomeRight;
				CStrSelect += ")"; 

				int iSqlLen = CStrSelect.GetLength();
				char * szSqlSquareRows_rst = new char [iSqlLen + 1];	
				strcpy(szSqlSquareRows_rst , "");
				strcat(szSqlSquareRows_rst , CStrSelect);
		
				SQLFreeStmt(hstmt, SQL_DROP);
				retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 

				SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
				SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
				
				shortTicks_rst = GetTickCount();
				retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlSquareRows_rst, SQL_NTS);
				shortTicks_rst = GetTickCount() - shortTicks_rst;

				if (retcode == SQL_SUCCESS) 
				{    //	retcode = SQLExecDirect for census2Dg
					SDWORD *  RowCountPtr = new SDWORD ;
					retcode = SQLRowCount(hstmt, RowCountPtr);						 
					f_rst = * RowCountPtr;
					delete RowCountPtr;

				}
				CStrSelect = "";
				delete [] szSqlSquareRows_rst;
						
			} //if(f<iTopN)
		
			if (f>0)
			{   
				char	cAttribute[10][50]= { "","","","","","","","","",""};

				
				sprintf(cAttribute[0],"%ld", q1[qnum] );
				sprintf(cAttribute[1],"%ld", q2[qnum] );
				sprintf(cAttribute[2],"%ld", N);
				sprintf(cAttribute[3],"%f",  (double)rd);
				sprintf(cAttribute[4],"%ld", f );
				if(f_rst > 0)
				{
					sprintf(cAttribute[5],"%ld", f_rst );
					sprintf(cAttribute[6],"%ld", shortTicks_rst);
					f_rst = 0;
				}else
				{
					sprintf(cAttribute[5],"NULL");
					sprintf(cAttribute[6],"NULL");

				}
				sprintf(cAttribute[7],"%ld", shortTicks);
				sprintf(cAttribute[8],"%ld", longTicks);


				//CStrInsert += " INSERT DATA_Top100_Census2D_Learning VALUES( ";	
				//CStrInsert += " INSERT Top100Census2D_LearningFrmPf100 VALUES( ";	
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm2000 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm1000 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm0800 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm0400 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm0200 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm0100 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm0250 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm1459 VALUES( ";
		
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm1459_Top50 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm1459_Top250 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm1459_Top1000 VALUES( ";

				//CStrInsert += " INSERT Top100_Census2D_LearningFrm1459_EUCL VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm1459_SUM VALUES( ";
			
				//CStrInsert += " INSERT dbo.Census2D_T0100_B_Learning_P0730 VALUES( ";
				//CStrInsert += " INSERT dbo.Census2D_T0100_B_Learning_P0365 VALUES( ";
				CStrInsert += " INSERT Census2D_T0100_B_Learning_P0178 VALUES( ";

				CStrInsert += cAttribute[0];
				CStrInsert += ",";
				CStrInsert += cAttribute[1];
				CStrInsert += ",";
				CStrInsert += cAttribute[2];
				CStrInsert += ",";
				CStrInsert += cAttribute[3];
				CStrInsert += ",";
				CStrInsert += cAttribute[4];
				CStrInsert += ",";
				CStrInsert += cAttribute[5];
				CStrInsert += ",";
				CStrInsert += cAttribute[6];
				CStrInsert += ",";
				CStrInsert += cAttribute[7];
				CStrInsert += ",";
				CStrInsert += cAttribute[8];
				CStrInsert += ")";


			    int iSqlLen = CStrInsert.GetLength();

				char * szSqlInsert = new char [iSqlLen + 1];
				strcpy(szSqlInsert , "");
				strcat(szSqlInsert , CStrInsert);

				SQLFreeStmt(hstmt_Census2D_Profile, SQL_DROP);
				retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_Profile); /// Profile Statement handle 

				retcode = SQLExecDirect(hstmt_Census2D_Profile, (unsigned char *)szSqlInsert, SQL_NTS);

				if (retcode == SQL_SUCCESS) 
				{  //	retcode = SQLExecDirect
					//AfxMessageBox("Insert new hstmt_Census2D_Learning  OKKKKKKKKKKK!");
					//Sleep(300);
					iInsertOK++;

					//bReturn = TRUE;
				}
				else
				{
					AfxMessageBox("Insert DATA_Top100_Census2D_Learning Error!");
					iInsertERR++;
					i= 0;

				} //	retcode = SQLExecDirect 
				
				f=0;

				CStrInsert = "";
				delete [] szSqlInsert;
			}
		

			qnum++;
		}while(qnum <iTopN); //100);

	}//if(!zlOpenDB())



	delete [] pAge;//new double[10]
	delete [] pIncome;//new double[10]
	delete [] pPf;
	delete [] q1;//new double[10]
	delete [] q2;//new double[10]


	SQLFreeStmt(hstmt, SQL_DROP);
	SQLFreeStmt(hstmt_Census2D_WorkLoad, SQL_DROP);
	SQLFreeStmt(hstmt_Census2D_Profile, SQL_DROP);

	zlCloseDB();
	wsprintf(tmp, " irderr = %d", irderr);

	AfxMessageBox(tmp);

	AfxMessageBox("Insert hstmt_Generet2DLearning  OK!");	

}

void CMainFrame::On3DTop0100_B_LearningCensus3dGaussArray() 
{
	//Learning: Top100 3D biased from profile of Census3D, Gauss3D, Array3D
	//Census3D, 1654 smpl, 827 smpl, 414 smpl, 218
	//Gauss3D, 872, 436 , 218 smpl

	// --Read: DATA_Top100_Census2D_Profile, as Profile
	// Read:  Top100_Census2D_Profile, as Profile
	// Read: DATA_Census2Dg_B_workload, as Biased Query workload
	// write:DATA_Top100_Census2D_Learning
	// Top100, distance = EUCL, SUM ,Type = Biased 
	// 
	// add 2 attributes f_rst, shortTicks_rst, 2003/4/5
	//
	/////////////////////////////////////////////////////
	

	int N, f = 0, c =0, d = 0; 

	int i,j, iErr = 0;
	char tmp[100] = "";
	CString CStrSelect = "", CStrSelectHead = ""; 
	CString CStrSelect1 = "", CStrSelect1Head = ""; 

	
	CString CStrInsert = "", CStrInsertHead = "";

	int longTicks =0, shortTicks =0;
	int f_rst= 0, shortTicks_rst = 0; //2003/4/5

	SWORD  sAge;
	SDWORD cbAge;

	SDWORD sIncome;
	SDWORD cbIncome;
	
	SDWORD sWPY;
	SDWORD cbWPY;

	SDWORD sN,sr,sf,sc,sd;
	SDWORD cbN,cbr,cbf,cbc,cbd;


	HSTMT   hstmt_Census2D_WorkLoad; //for queries workload
	HSTMT   hstmt_Census2D_Profile;  //for insert Profile

	//int iTupleNum;//,iStartRowNum, iTotalNum;

	int * q1, *q2, *q3, *q1Hold, *q2Hold, *q3Hold; //for queries workload
	
	double rd =0.0, dis[2000], r[2000];  //rd is the final radius distance of Q; dis[]= d(Q,Q'), r[] id dis[];
	int tuple1[2000],tuple2[2000], tuple3[2000];

	double rr[2000],rOrder[2000]; 
	double x[105];

	//int iSizeProfile = 872; //436; //218;	 //for Gauss
	//int iSizeProfile = 872; //436; //218;	 //for Array
	
	int iSizeProfile = 0;  //for All

	int iTopN = 100;

	int iInsertOK = 0, iInsertERR = 0, irderr = 0;

	///---000
	
	//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census3D_Profile0414"; //Census3D	
	//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census3D_Profile0218"; //Census3D	
	
	//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Gauss3D_Profile0218"; //Gauss3D	
	//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Gauss3D_Profile0436"; //Gauss3D	
	//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Gauss3D_Profile0872"; //Gauss3D	
	
	UCHAR szSqlAllRows[] = "SELECT * FROM Array3D_Top100_Profile0218"; //Array3D	
	//UCHAR szSqlAllRows[] = "SELECT * FROM Array3D_Top100_Profile0436"; //Array3D	
	//UCHAR szSqlAllRows[] = "SELECT * FROM Array3D_Top100_Profile0872"; //Array3D	
	
	///---111									  
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Census3Dg_B_workload"; //workload						
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Gauss3D_B_workload"; //workload						
	
	UCHAR szSqlAllQueryRows[] = "SELECT * FROM Array3Dg_B_workload"; //Array workload						

	///------222
	//UCHAR szSqlAllRowsFrmcensus2D[] = "SELECT * FROM CLMB_census3D"; //census2D				
	
	//UCHAR szSqlAllRowsFrmcensus2D[] = "SELECT * FROM CLMB_Gauss3D"; //Gauss3D				
	
	UCHAR szSqlAllRowsFrmcensus2D[] = "SELECT * FROM CLMB_Array3D"; //Array3D				
	
	//---------333
	//CStrSelectHead += "select  * from CLMB_Gauss3D where (";
	CStrSelectHead += "select  * from CLMB_Array3D where (";

	//-----------3.1
	//CStrSelect1Head	+= "select  * from CLMB_Gauss3D where (";
	CStrSelect1Head	+= "select  * from CLMB_Array3D where (";
	
	//-----------444
	//CStrInsert += " INSERT dbo.Census3D_T0100_B_Learning_P0414 VALUES( ";
	//CStrInsert += " INSERT dbo.Census3D_T0100_B_Learning_P0218 VALUES( ";
	
	//CStrInsertHead += " INSERT Gauss3D_T0100_B_Learning_P0218 VALUES( ";  //Gauss3D
	//CStrInsertHead += " INSERT Gauss3D_T0100_B_Learning_P0436 VALUES( ";
	//CStrInsertHead += " INSERT Gauss3D_T0100_B_Learning_P0872 VALUES( ";
							 
	CStrInsertHead += " INSERT Array3D_T0100_B_Learning_P0218 VALUES( ";   // Array3D
	//CStrInsertHead += " INSERT Array3D_T0100_B_Learning_P0436 VALUES( ";
	//CStrInsertHead += " INSERT Array3D_T0100_B_Learning_P0872 VALUES( ";

	if(!zlOpenDB())
	{
		AfxMessageBox("zlOpenDB() err!");
		zlCloseDB();
	}else
	{
		retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_WorkLoad); ///queries Statement handle 
		retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_Profile); /// Profile Statement handle 

		//1. read all tuples from Profile set store a buffer
		//1111111111111 read database from profiles :DATA_Top100_Census2D_Profile 111111111111111	
												//   Top100_Census2D_Profile2000
		//0---------------
		//UCHAR szSqlAllRows[] = "SELECT * FROM DATA_Top100_Census2D_Profile"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile2000"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile1000"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile0800"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile0400"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile0200"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile0100"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile0250"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile1459"; //discounts, authors, Census2DTable						
	
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top50_Census2D_Profile1459"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top250_Census2D_Profile1459"; //discounts, authors, Census2DTable								
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top1000_Census2D_Profile1459"; //discounts, authors, Census2DTable						
		
		 //UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile1459"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile1459_EUCL"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile1459_SUM"; //discounts, authors, Census2DTable						
		 
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile0730"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile0365"; //discounts, authors, Census2DTable						
		
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census3D_Profile1654"; //Census3D
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census3D_Profile0827"; //Census3D
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census3D_Profile0414"; //Census3D



		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		
		longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);
		longTicks = GetTickCount() - longTicks;

		//lEndTimer = GetTickCount() - lStartTimer;
		//wsprintf(tmp, "%ld", lEndTimer);


		if (retcode == SQL_SUCCESS) 
		{    //	retcode = SQLExecDirect for DATA_Top100_Census2D_Profile
			int iRowCount;
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt, RowCountPtr);						 
			iRowCount = * RowCountPtr;
			iSizeProfile = iRowCount; // here only size of profile, 100,200, ...,2000
			delete RowCountPtr;
			
			// Bind columns 1,2.
			SQLBindCol(hstmt, 1, SQL_C_SSHORT, &sAge, 0, &cbAge);
			SQLBindCol(hstmt, 2, SQL_C_SLONG, &sIncome,0, &cbIncome); //SQL_C_SSHORT
			SQLBindCol(hstmt, 3, SQL_C_SLONG, &sWPY,0, &cbWPY); //SQL_C_SSHORT

			SQLBindCol(hstmt, 4, SQL_C_SLONG, &sN,0, &cbN); //SQL_C_SSHORT
			SQLBindCol(hstmt, 5, SQL_C_SLONG, &sr,0, &cbr); //SQL_C_SSHORT
			SQLBindCol(hstmt, 6, SQL_C_SLONG, &sf,0, &cbf); //SQL_C_SSHORT
			SQLBindCol(hstmt, 7, SQL_C_SLONG, &sc,0, &cbc); //SQL_C_SSHORT
			SQLBindCol(hstmt, 8, SQL_C_SLONG, &sd,0, &cbd); //SQL_C_SSHORT

			pPf3D = new Profile3D[iRowCount];
			pPf3DHold = pPf3D;

			pAge = new  int[iRowCount];//buffer, new float[10]
			pIncome = new  int[iRowCount];//buffer , new float[10]
			pWPY = new  int[iRowCount];
			
			pAgeHold = pAge;
			pIncomeHold = pIncome;
			pWPYHold = pWPY;
		
			iRowCount =0;
			while (TRUE) 
			{
				retcode = SQLFetch(hstmt);

				if (retcode == SQL_ERROR)
				{
					//show_error();
					wsprintf(tmp, "%ld", iRowCount);
					//int i = iRowCount;
					AfxMessageBox("SQLFetch Error !!!!!!");
							//break; //99.8.26
				}

				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
				{	
					*pAge		= sAge;
					*pIncome	= sIncome;
					*pWPY		= sWPY;
					pAge++;
					pIncome++;
					pWPY++;
					
					pPf3D->q[0]	= sAge;				
					pPf3D->q[1]	= sIncome;
					pPf3D->q[2] = sWPY;
					pPf3D->N		= sN;
					pPf3D->r		= (float) sr;
					pPf3D->f		= sf;
					pPf3D->c		= sc;
					pPf3D->d		= sd;

					pPf3D++;

					if(retcode == SQL_SUCCESS_WITH_INFO)
					{
						wsprintf(tmp, "%ld", retcode);
						AfxMessageBox(tmp);
					}
						
				} 
				else 
				{
					break;
				}

			}   ///while (TRUE)

			pAge = pAgeHold ;
			pIncome = pIncomeHold ;
			pWPY = pWPYHold ;

			pPf3D	= pPf3DHold;
		}//	retcode = SQLExecDirect  for DATA_Top100_Census2D_Profile

	//111111111111111111 read data base  DATA_Top100_Census2D_Profile end   111111111111

	//2. Read all Queries from DATA_Census2Dg_B_workload
		sAge = 0;cbAge = 0;sIncome = 0;cbIncome= 0;sWPY = 0; cbWPY = 0;
		//1
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Census2Dg_B_workload"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Census2Dg_B_workload1"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Census2Dg_B_workload2"; //discounts, authors, Census2DTable						
	
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Census3Dg_B_workload"; //discounts, authors, Census2DTable						
		
		SQLSetStmtOption(hstmt_Census2D_WorkLoad, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt_Census2D_WorkLoad, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		retcode = SQLExecDirect(hstmt_Census2D_WorkLoad, szSqlAllQueryRows, SQL_NTS);

		//lEndTimer = GetTickCount() - lStartTimer;
		//wsprintf(tmp, "%ld", lEndTimer);


		if (retcode == SQL_SUCCESS) 
		{    //	retcode = SQLExecDirect for census2Dg
			int iRowCount;
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt_Census2D_WorkLoad, RowCountPtr);						 
			iRowCount = * RowCountPtr;
			delete RowCountPtr;
						
			SQLBindCol(hstmt_Census2D_WorkLoad, 1, SQL_C_SSHORT, &sAge, 0, &cbAge);
			SQLBindCol(hstmt_Census2D_WorkLoad, 2, SQL_C_SLONG, &sIncome,0, &cbIncome); //SQL_C_SSHORT
			SQLBindCol(hstmt_Census2D_WorkLoad, 3, SQL_C_SLONG, &sWPY,0, &cbWPY); //SQL_C_SSHORT

			q1 = new  int[iRowCount];//buffer, new float[10]
			q2 = new  int[iRowCount];//buffer , new float[10]
			q3 = new  int[iRowCount];//buffer , new float[10]
		
			q1Hold = q1; q2Hold= q2; q3Hold = q3;


			while (TRUE) 
			{
				retcode = SQLFetch(hstmt_Census2D_WorkLoad);
				if (retcode == SQL_ERROR)
				{
					//show_error();
					wsprintf(tmp, "%ld", iRowCount);
					//int i = iRowCount;
					AfxMessageBox("SQLFetch Error !!!!!!");
							//break; //99.8.26
				}
				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
				{	
					*q1	= sAge;*q2	= sIncome;*q3 = sWPY;
					q1++;		q2++;			q3++;
				} 
				else 
				{
					break;
				}

			}   ///while (TRUE)
			
			q1= q1Hold; q2= q2Hold;q3= q3Hold;
				
		}//	retcode = SQLExecDirect  for query q1,q2.
	
	
	//3. evaluate r, f, -c, -d,

		double ftmp=0;
		int itmp = 0,qnum =0; 
		int topt1[2000],topt2[2000],topt3[2000];
		int frequ[2000],freOrder[2000];

		for(i=0; i<2000; i++)
		{
			topt1[i]=0; topt2[i] =0; topt3[i] = 0;
			frequ[i]=0; freOrder[i] =0;
		}

//////////////////
		SQLFreeStmt(hstmt, SQL_DROP);
		retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 
		//2
		//UCHAR szSqlAllRows[] = "SELECT * FROM census2Dg"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRowsFrmcensus2D[] = "SELECT * FROM CLMB_census2D"; //census2D				
		//UCHAR szSqlAllRowsFrmcensus2D[] = "SELECT * FROM CLMB_census3D"; //census3D						
		//UCHAR szSqlAllRowsFrmcensus2D[] = "SELECT * FROM CLMB_Array3D"; //census3D						

		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		
		longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, szSqlAllRowsFrmcensus2D, SQL_NTS);
		longTicks = GetTickCount() - longTicks;

//////////////////////////



		do
		{

//////////////////
		/***********
		SQLFreeStmt(hstmt, SQL_DROP);
		retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 
		//2
		//UCHAR szSqlAllRows[] = "SELECT * FROM census2Dg"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRowsFrmcensus2D[] = "SELECT * FROM CLMB_census2D"; //census2D				
		//UCHAR szSqlAllRowsFrmcensus2D[] = "SELECT * FROM CLMB_census3D"; //census3D						
		UCHAR szSqlAllRowsFrmcensus2D[] = "SELECT * FROM CLMB_Array3D"; //census3D						

		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		
		longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, szSqlAllRowsFrmcensus2D, SQL_NTS);
		longTicks = GetTickCount() - longTicks;
		**************/

//////////////////////////

			////////////for each query find the closed profiles
			//evaluate all distance from New_query(q1[qnum],q2[qnum]) to Profile Point: 
			//														(pAge[i],pIncome[i] )
			// dis[i] = d(Q,Q') = dmax(Q,Q') = max(|qi-q'i|)

			for(i = 0; i<iSizeProfile; i++)
			{
			  x[1]=abs(pAge[i]- q1[qnum]);x[2]=abs(pIncome[i]-q2[qnum]);x[3]=abs(pWPY[i]-q3[qnum]);
			  dis[i] = (double)max( x[1], x[2]); dis[i] = (double)max(dis[i], x[3]);//MAX distance

			  tuple1[i] = pAge[i];
			  tuple2[i] = pIncome[i];
			  tuple3[i] = pWPY[i];							  
			  
			  rr[i] = pPf3D[i].r;  //best search radius in Profile
			  frequ[i] = pPf3D[i].f; 		
			}

			i=0;

			//order all distance
			// r[i]'s are sorting of dis[i] =  d(Q,Q'), to identify the closest Q' to Q
			for(i=0; i<iSizeProfile; i++)
			{
				r[i] = dis[i];  //d(Q,Q')
				topt1[i] = tuple1[i] ; topt2[i]=tuple2[i] ; topt3[i]=tuple3[i] ;//profile points
				rOrder[i] = rr[i];  //radius order
				freOrder[i] = frequ[i];

				for( j= i+1; j<iSizeProfile; j++)
				{
					if(dis[j] < r[i]) 
					{ ftmp = r[i];			r[i] = dis[j];			dis[j] = ftmp;
					  ftmp = rOrder[i];		rOrder[i] = rr[j];		rr[j] = ftmp;
					  itmp = freOrder[i];   freOrder[i]= frequ[j]; frequ[j] = itmp;

					  itmp = topt1[i];		topt1[i]= tuple1[j]; tuple1[j]= itmp;
					  itmp = topt2[i];		topt2[i]= tuple2[j]; tuple2[j]= itmp;
					  itmp = topt3[i];		topt3[i]= tuple3[j]; tuple3[j]= itmp;

					}
				}
			}
					
		//int N, rd,f, c, d; 
		//evaluate search distance
		
		int qp1 = topt1[0], qp2= topt2[0], qp3= topt3[0];; //Q'(qp1,qp2), the closest proples to Q(q1,q2)
		int iKnum = 0,fpf[2000];
		double frou[2000],l[2000],V[2000], lV=0, lVrou =0, rou = 0;
		double dQQ[2000],rpf[2000];
		double dmaxQQp;

		if(r[0] == 0) // if Q=Q'
		{//if(r[0] == 0)
			rd = rOrder[0];
			//rd = 2*rOrder[0];
			//rd = rOrder[0]/2;
			//rd = rOrder[0]/10;

			int itest = 0; //use to test 
		}
		else
		{
			 x[1]=abs(qp1 - q1[qnum]);x[2]=abs(qp2 - q2[qnum]);x[3]=abs(qp3-q3[qnum]);
			 dmaxQQp = (double)max( x[1], x[2]); dmaxQQp= (double)max(dmaxQQp, x[3]);//MAX distance		
			//dmaxQQp  //i.e.r[0]

			if(dmaxQQp <= rOrder[0])  //case of Fig.3 //rou = N/4*r*r
			{
				iKnum = 0;
				
				for(j=0; j<iSizeProfile; j++)
				{
					frou[j] =0;l[j] =0;V[j] = 0;
					dQQ[j] =0;rpf[j] = 0;fpf[j]=0;
				}

				for(j=0; j<iSizeProfile; j++) //Find set K= (all squares Q in it)
				{
					if( r[j] <= rOrder[j]  ) //d(Q,Qpf) < rpf
					{
						dQQ[iKnum] = r[j];
						rpf[iKnum] = rOrder[j];
						fpf[iKnum] = freOrder[j];

						iKnum++;

					}
						
				}


				//---------- alternative test -----------------
				int iMeadian = iKnum/2;
				rou = 0;
				lVrou = 0; lV = 0;

					// /////  -----Fig 3.---- ////
				/******************
				///// lvp
					for(j=0; j<iKnum; j++)
					{
						//l[j] = 1.0/(dQQ[j]* dQQ[j]* dQQ[j]);		//or d*d*d								
						l[j] = 1.0/(dQQ[j]* dQQ[j]);		//or d*d								
						//l[j] = 1.0/(dQQ[j]);		//or d								
						//l[j] = 1.0;		//or 								
		
						V[j] = (2*rpf[j])*(2*rpf[j])*(2*rpf[j]);
						frou[j] = (double) fpf[j]/V[j];//100/(4*rpf[j]*rpf[j]);
						lV +=  l[j]*V[j]; 
						lVrou += l[j]*fpf[j];				
					}
					rou = lVrou/lV;

					//////////mean of density 
					for(j=0; j<iKnum; j++)
					{
						frou[j] = fpf[j]/( (2*rpf[j])*(2*rpf[j])*(2*rpf[j]) );
					    rou += frou[j]; 
					}
					rou = rou/iKnum;
					
					////////meadian of density
					for(j=0; j<iKnum; j++)
					{
						frou[j] = fpf[j]/( (2*rpf[j])*(2*rpf[j])*(2*rpf[j]) );
					}
					rou = frou[iMeadian];
					*****/


					//////////mean of ALL density 
					for(j=0; j<iSizeProfile; j++)
					{
						frou[j] = freOrder[j]/(8 *rOrder[j]*rOrder[j]*rOrder[j]);
					    rou += frou[j]; 
					}
					rou = rou/iSizeProfile;

					//////////median of ALL density 

					for(j=0; j<iSizeProfile; j++)
					{
						frou[j] = freOrder[j]/(8 *rOrder[j]*rOrder[j]*rOrder[j]);;
					}

					double rouOrder[2000],ftmp =0;

					for(j=0; j<iSizeProfile; j++)
					{
						rouOrder[j] = frou[j]; 
						for(int k = j+1; k <iSizeProfile; k++)
						{
							if(frou[k]< rouOrder[j])
							{
								ftmp = rouOrder[j]; rouOrder[j] = frou[k]; frou[k] = ftmp;
							}
						}
					}					
					iMeadian = iSizeProfile/2;
					rou = rouOrder[iMeadian];
					
					
					rd = (double)pow( 2*100/rou, 1.0/3.0 )/2; 

					if ( (rd < rOrder[0]) ||(rd < dmaxQQp))
					{
						//rd = rd + rd/(3.0-1.0);  //rOrder[0] ; + rd/(n-1),  n-dimension
						rd = rd + max(rd, rOrder[0])/(3.0-1.0);  //rOrder[0] ; + rd/(n-1) n-dimension

						///irderr ++;
					}
	
					if (rd > dmaxQQp + rOrder[0])
					{
						rd = dmaxQQp + rOrder[0];
						//irderr ++;
					}

					if (rd < dmaxQQp)
					{
					//	rd = rOrder[0];
						irderr ++;
					}

				//------------Fig 3.^^^^^----------------

			}else
			{
				x[1]=abs(qp1 - q1[qnum]);x[2]=abs(qp2 - q2[qnum]);x[3]=abs(qp3-q3[qnum]);
				dmaxQQp = (double)max( x[1], x[2]); dmaxQQp= (double)max(dmaxQQp, x[3]);//MAX distance		

				//if(dmaxQQp <= 2*rOrder[0])  //h<2r'
				{
					//case of Fig.4 //rou = N/4*r*r				
					iKnum = 0;
					for(j=0; j<2000; j++)
					{
						frou[j] =0;l[j] =0;V[j] = 0;
						dQQ[j] =0;rpf[j] = 0; fpf[j]=0;			
					}

					for(j=0; j<iSizeProfile; j++)
					{
						if(r[j] < rOrder[0] + dmaxQQp)
						{
							dQQ[iKnum] = r[j];
							rpf[iKnum] = rOrder[j];
							fpf[iKnum] = freOrder[j];

							iKnum++;
						}						
					}

					/////////////////////////////////////////////////////////
					//double x = 2.0, y = 3.0, z;
					//	z = pow( x, y );
					//printf( "%.1f to the power of %.1f is %.1f\n", x, y, z );
					//Output
					//2.0 to the power of 3.0 is 8.0
					/////////////////////////////////////////////

				//---------- alternative test -----------------
				lVrou = 0; lV = 0;
				rou = 0;
				int iMeadian = iKnum/2;

					/****************
					for(j=0; j<iKnum; j++)
					{
						//l[j] = 1.0/(dQQ[j]* dQQ[j]* dQQ[j]);		//or d*d*d								
						l[j] = 1.0/(dQQ[j]* dQQ[j]);		//or d*d								
						//l[j] = 1.0/(dQQ[j]);		//or d								
						//l[j] = 1.0;		//or 								
						
						V[j] = (2*rpf[j])*(2*rpf[j])*(2*rpf[j]);
						frou[j] = (double) fpf[j]/V[j]; //100/(4*rpf[j]*rpf[j]);
						lV +=  l[j]*V[j]; 
						lVrou += l[j]*fpf[j];				
					}
					rou = lVrou/lV;
					//****************

					///****************
					//////////mean of density 
					for(j=0; j<iKnum; j++)
					{
						frou[j] = fpf[j]/( (2*rpf[j])*(2*rpf[j])*(2*rpf[j]) );
					    rou += frou[j]; 
					}
					rou = rou/iKnum;
					
					for(j=0; j<iKnum; j++)
					{
						frou[j] = fpf[j]/( (2*rpf[j])*(2*rpf[j])*(2*rpf[j]) );
					}
					rou = frou[iMeadian];
					*********************/

					//////////mean of ALL density 
					for(j=0; j<iSizeProfile; j++)
					{
						frou[j] = freOrder[j]/(8 *rOrder[j]*rOrder[j]*rOrder[j]);;
					    rou += frou[j]; 
					}
					rou = rou/iSizeProfile;

					//////////median of ALL density 

					for(j=0; j<iSizeProfile; j++)
					{
						frou[j] = freOrder[j]/(8 *rOrder[j]*rOrder[j]*rOrder[j]);;
					}

					double rouOrder[2000],ftmp =0;

					for(j=0; j<iSizeProfile; j++)
					{
						rouOrder[j] = frou[j]; 
						for(int k = j+1; k <iSizeProfile; k++)
						{
							if(frou[k]< rouOrder[j])
							{
								ftmp = rouOrder[j]; rouOrder[j] = frou[k]; frou[k] = ftmp;
							}
						}
					}					
					iMeadian = iSizeProfile/2;
					rou = rouOrder[iMeadian];

					rd = (double)pow( 2*100/rou, 1.0/3.0 )/2; 
		
				if ( (rd < rOrder[0]) ||(rd < dmaxQQp))
				{
						//rd = rd + rd/(3.0-1.0);  //rOrder[0] ; + rd/(n-1) n-dimension
						rd = rd + max(rd, rOrder[0])/(3.0-1.0);  //rOrder[0] ; + rd/(n-1) n-dimension
						//irderr ++;
				}
				if (rd > dmaxQQp + rOrder[0])
				{
					rd = dmaxQQp + rOrder[0];
					//irderr ++;
				}

				if (rd < dmaxQQp)
				{
				//	rd = rOrder[0];
					irderr ++;
				}

				//-----------------fig. 4 -^^^^^^ end ---------- 
			
					int itest = 0;
				//}else{                        //2003.04.11

					//rd = dmaxQQp + rOrder[0];//2003.04.11

				}//if(dmaxQQp <= 2*rOrder[0])

			}//if(dmaxQQp <= rOrder[0])


		}//if(r[0] == 0)

		
		//rd = rOrder[0];

			
			CTime CurTime = CTime::GetCurrentTime();         

			//N = 100; c = -1; d = - CurTime.GetTime();
			
			N = iTopN; c = -1; d-- ;

			char cAgeLeft[20] = "", cAgeRight[20] = "", cIncomeLeft[20] = "", cIncomeRight[20] ="";
			char cWPYLeft[20] = "", cWPYRight[20] = "";
		
			sprintf(cAgeLeft,		"%f",	(double)(q1[qnum] - rd) );
			sprintf(cAgeRight,		"%f",	(double)(q1[qnum] + rd));
			sprintf(cIncomeLeft,	"%f",	(double)(q2[qnum] - rd));
			sprintf(cIncomeRight,	"%f",	(double)(q2[qnum] + rd));
			sprintf(cWPYLeft,		"%f",	(double)(q3[qnum] - rd)	);
			sprintf(cWPYRight,		"%f",	(double)(q3[qnum] + rd)	);
			//3
			CStrSelect += CStrSelectHead; //"select  * from CLMB_census3D where (";
			/*******
			CStrSelect += cAgeLeft;
			CStrSelect += "<= age AND age <=";
			CStrSelect += cAgeRight;
			
			CStrSelect += ") AND (";
			CStrSelect += cIncomeLeft;
			CStrSelect += "<= Income AND Income <=";
			CStrSelect += cIncomeRight;
			
			CStrSelect += ") AND (";
			CStrSelect += cWPYLeft;
			CStrSelect += "<= WeeksPerYear AND WeeksPerYear <=";   //WeeksPerYear
			CStrSelect += cWPYRight;
			///*******
			CStrSelect += cAgeLeft;
			CStrSelect += "<= q1 AND q1 <=";
			CStrSelect += cAgeRight;
			
			CStrSelect += ") AND (";
			CStrSelect += cIncomeLeft;
			CStrSelect += "<= q2 AND q2 <=";
			CStrSelect += cIncomeRight;
			
			CStrSelect += ") AND (";
			CStrSelect += cWPYLeft;
			CStrSelect += "<= q3 AND q3 <=";   //WeeksPerYear
			CStrSelect += cWPYRight;
			*************/
			
			CStrSelect += cAgeLeft;
			CStrSelect += "<= Aq1 AND Aq1 <=";
			CStrSelect += cAgeRight;
			
			CStrSelect += ") AND (";
			CStrSelect += cIncomeLeft;
			CStrSelect += "<= Aq2 AND Aq2 <=";
			CStrSelect += cIncomeRight;
			
			CStrSelect += ") AND (";
			CStrSelect += cWPYLeft;
			CStrSelect += "<= Aq3 AND Aq3 <=";   //WeeksPerYear
			CStrSelect += cWPYRight;

			CStrSelect += ")"; 

			int iSqlLen = CStrSelect.GetLength();
			char * szSqlSquareRows = new char [iSqlLen + 1];	
			strcpy(szSqlSquareRows , "");
			strcat(szSqlSquareRows , CStrSelect);
	
			SQLFreeStmt(hstmt, SQL_DROP);
			retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 
			//Sleep(200);

			SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
			SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
			
			shortTicks = GetTickCount();
			retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlSquareRows, SQL_NTS);
			shortTicks = GetTickCount() - shortTicks;

			//lEndTimer = GetTickCount() - lStartTimer;
			//wsprintf(tmp, "%ld", irderr ++;);

			if (retcode == SQL_SUCCESS) 
			{    //	retcode = SQLExecDirect for census2Dg
				SDWORD *  RowCountPtr = new SDWORD ;
				retcode = SQLRowCount(hstmt, RowCountPtr);						 
				f = * RowCountPtr;
				delete RowCountPtr;

			}

			if(f<=0)
				int iiii = 0;

			CStrSelect = "";
			delete [] szSqlSquareRows;

	//4. insert zeta into DATA_Top100_Census2D_Profile
		
			if( f<iTopN )
			{
				rd = dmaxQQp + rOrder[0];
				for (i = 0; i< 20; i++)
				{
					cAgeLeft[i] = 0; cAgeRight[i] = 0;
					cIncomeLeft[i] = 0; cIncomeRight[i] =0;
					cWPYLeft[i] = 0, cWPYRight[i] = 0;
				}

				sprintf(cAgeLeft,		"%f",	(double)(q1[qnum] - rd) );
				sprintf(cAgeRight,		"%f",	(double)(q1[qnum] + rd));
				sprintf(cIncomeLeft,	"%f",	(double)(q2[qnum] - rd));
				sprintf(cIncomeRight,	"%f",	(double)(q2[qnum] + rd));
				sprintf(cWPYLeft,		"%f",	(double)(q3[qnum] - rd)	);
				sprintf(cWPYRight,		"%f",	(double)(q3[qnum] + rd)	);

				//3.1
				CStrSelect1 = "";				
				//CStrSelect += "select  * from CLMB_census2D where (";
				CStrSelect1 += CStrSelect1Head; //"select  * from CLMB_census3D where (";
				/************************
				CStrSelect1 += cAgeLeft;
				CStrSelect1 += "<= age AND age <=";
				CStrSelect1 += cAgeRight;
				
				CStrSelect1 += ") AND (";
				CStrSelect1 += cIncomeLeft;
				CStrSelect1 += "<= Income AND Income <=";
				CStrSelect1 += cIncomeRight;
				
				CStrSelect1 += ") AND (";
				CStrSelect1 += cWPYLeft;
				CStrSelect1 += "<= WeeksPerYear AND WeeksPerYear <=";   //WeeksPerYear
				CStrSelect1 += cWPYRight;
				////*******************

				CStrSelect1 += cAgeLeft;
				CStrSelect1 += "<= q1 AND q1 <=";
				CStrSelect1 += cAgeRight;
				
				CStrSelect1 += ") AND (";
				CStrSelect1 += cIncomeLeft;
				CStrSelect1 += "<= q2 AND q2 <=";
				CStrSelect1 += cIncomeRight;
				
				CStrSelect1 += ") AND (";
				CStrSelect1 += cWPYLeft;
				CStrSelect1 += "<= q3 AND q3 <=";   //WeeksPerYear
				CStrSelect1 += cWPYRight;
				*******************/
				CStrSelect1 += cAgeLeft;
				CStrSelect1 += "<= Aq1 AND Aq1 <=";
				CStrSelect1 += cAgeRight;
				
				CStrSelect1 += ") AND (";
				CStrSelect1 += cIncomeLeft;
				CStrSelect1 += "<= Aq2 AND Aq2 <=";
				CStrSelect1 += cIncomeRight;
				
				CStrSelect1 += ") AND (";
				CStrSelect1 += cWPYLeft;
				CStrSelect1 += "<= Aq3 AND Aq3 <=";   //WeeksPerYear
				CStrSelect1 += cWPYRight;

				CStrSelect1 += ")"; 

				int iSqlLen = CStrSelect1.GetLength();
				char * szSqlSquareRows_rst = new char [iSqlLen + 1];	
				strcpy(szSqlSquareRows_rst , "");
				strcat(szSqlSquareRows_rst , CStrSelect1);
		
				SQLFreeStmt(hstmt, SQL_DROP);
				retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 

				SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
				SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
				
				shortTicks_rst = GetTickCount();
				retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlSquareRows_rst, SQL_NTS);
				shortTicks_rst = GetTickCount() - shortTicks_rst;

				if (retcode == SQL_SUCCESS) 
				{    //	retcode = SQLExecDirect for census2Dg
					SDWORD *  RowCountPtr = new SDWORD ;
					retcode = SQLRowCount(hstmt, RowCountPtr);						 
					f_rst = * RowCountPtr;
					delete RowCountPtr;

				}

				if(f_rst<=0)
				  int iiiib = 0;

				CStrSelect1 = "";
				delete [] szSqlSquareRows_rst;
						
			} //if(f<iTopN)
		
			if (f>0)
			{   
				char	cAttribute[10][50]= { "","","","","","","","","",""};

				
				sprintf(cAttribute[0],	"%ld", q1[qnum] );
				sprintf(cAttribute[1],	"%ld", q2[qnum] );
				sprintf(cAttribute[1+1],"%ld", q3[qnum] );
				
				sprintf(cAttribute[2+1],"%ld", N);
				
				sprintf(cAttribute[3+1],"%f",  (double)rd);
				sprintf(cAttribute[4+1],"%ld", f );
				if(f_rst > 0)
				{
					sprintf(cAttribute[5+1],"%ld", f_rst );
					sprintf(cAttribute[6+1],"%ld", shortTicks_rst);
					f_rst = 0;
				}else
				{
					sprintf(cAttribute[5+1],"NULL");
					sprintf(cAttribute[6+1],"NULL");

				}
				sprintf(cAttribute[7+1],"%ld", shortTicks);
				sprintf(cAttribute[8+1],"%ld", longTicks);

				//4
				//CStrInsert += " INSERT DATA_Top100_Census2D_Learning VALUES( ";	
				//CStrInsert += " INSERT Top100Census2D_LearningFrmPf100 VALUES( ";	
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm2000 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm1000 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm0800 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm0400 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm0200 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm0100 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm0250 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm1459 VALUES( ";
		
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm1459_Top50 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm1459_Top250 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm1459_Top1000 VALUES( ";

				//CStrInsert += " INSERT Top100_Census2D_LearningFrm1459_EUCL VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm1459_SUM VALUES( ";
			
				//CStrInsert += " INSERT dbo.Census2D_T0100_B_Learning_P0730 VALUES( ";
				//CStrInsert += " INSERT dbo.Census2D_T0100_B_Learning_P0365 VALUES( ";
				
				//CStrInsert += " INSERT dbo.Census3D_T0100_B_Learning_P1654 VALUES( ";
				//CStrInsert += " INSERT dbo.Census3D_T0100_B_Learning_P0827 VALUES( ";
				//CStrInsert += " INSERT dbo.Census3D_T0100_B_Learning_P0414 VALUES( ";
				CStrInsert += CStrInsertHead; //" INSERT dbo.Census3D_T0100_B_Learning_P0218 VALUES( ";

				CStrInsert += cAttribute[0];
				CStrInsert += ",";
				CStrInsert += cAttribute[1];
				CStrInsert += ",";
				CStrInsert += cAttribute[2];
				CStrInsert += ",";
				CStrInsert += cAttribute[3];
				CStrInsert += ",";
				CStrInsert += cAttribute[4];
				CStrInsert += ",";
				CStrInsert += cAttribute[5];
				CStrInsert += ",";
				CStrInsert += cAttribute[6];
				CStrInsert += ",";
				CStrInsert += cAttribute[7];
				CStrInsert += ",";
				CStrInsert += cAttribute[8];
				CStrInsert += ",";
				CStrInsert += cAttribute[9];
			
				CStrInsert += ")";


			    int iSqlLen = CStrInsert.GetLength();

				char * szSqlInsert = new char [iSqlLen + 1];
				strcpy(szSqlInsert , "");
				strcat(szSqlInsert , CStrInsert);

				SQLFreeStmt(hstmt_Census2D_Profile, SQL_DROP);
				retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_Profile); /// Profile Statement handle 

				retcode = SQLExecDirect(hstmt_Census2D_Profile, (unsigned char *)szSqlInsert, SQL_NTS);

				if (retcode == SQL_SUCCESS) 
				{  //	retcode = SQLExecDirect
					//AfxMessageBox("Insert new hstmt_Census2D_Learning  OKKKKKKKKKKK!");
					//Sleep(300);
					iInsertOK++;

					//bReturn = TRUE;
				}
				else
				{
					AfxMessageBox("Insert DATA_Top100_Census2D_Learning Error!");
					iInsertERR++;
					i= 0;

				} //	retcode = SQLExecDirect 
				
				f=0;

				CStrInsert = "";
				delete [] szSqlInsert;
			}
		

			qnum++;
		}while(qnum <iTopN); //100);

	}//if(!zlOpenDB())


	delete [] pAge;//new double[10]
	delete [] pIncome;//new double[10]
	delete [] pWPY;//new float[10]

	delete [] pPf3D;
	delete [] q1;//new double[10]
	delete [] q2;//new double[10]
	delete [] q3;//new float[10]


	SQLFreeStmt(hstmt, SQL_DROP);
	SQLFreeStmt(hstmt_Census2D_WorkLoad, SQL_DROP);
	SQLFreeStmt(hstmt_Census2D_Profile, SQL_DROP);

	zlCloseDB();
	wsprintf(tmp, " irderr = %d", irderr);

	AfxMessageBox(tmp);

	AfxMessageBox("Insert hstmt_Generet2DLearning  OK!");	

}

void CMainFrame::On4Dcover_Learning() 
{
	//Learning: Top100 3D biased from profile of Census3D, Gauss3D, Array3D
	//Census3D, 1654 smpl, 827 smpl, 414 smpl, 218
	//Gauss3D, 872, 436 , 218 smpl

	// --Read: DATA_Top100_Census2D_Profile, as Profile
	// Read:  Top100_Census2D_Profile, as Profile
	// Read: DATA_Census2Dg_B_workload, as Biased Query workload
	// write:DATA_Top100_Census2D_Learning
	// Top100, distance = EUCL, SUM ,Type = Biased 
	// 
	// add 2 attributes f_rst, shortTicks_rst, 2003/4/5
	//
	/////////////////////////////////////////////////////
	

	int N, f = 0, c =0, d = 0; 

	int i,j, iErr = 0;
	char tmp[100] = "";
	CString CStrSelect = "", CStrSelectHead = ""; 
	CString CStrSelect1 = "", CStrSelect1Head = ""; 

	
	CString CStrInsert = "", CStrInsertHead = "";

	int longTicks =0, shortTicks =0;
	int f_rst= 0, shortTicks_rst = 0; //2003/4/5

	SDWORD sCol1,sCol2,sCol3,sCol4;
	SDWORD cbCol1,cbCol2,cbCol3,cbCol4;

	SDWORD sN,sr,sf,sc,sd;
	SDWORD cbN,cbr,cbf,cbc,cbd;


	HSTMT   hstmt_Census2D_WorkLoad; //for queries workload
	HSTMT   hstmt_Census2D_Profile;  //for insert Profile

	//int iTupleNum;//,iStartRowNum, iTotalNum;

	int iTupleNum = 0;//,iStartRowNum, iTotalNum;

	int * pCol1, *pCol2, *pCol3,*pCol4,
		*pCol1Hold, *pCol2Hold, *pCol3Hold, *pCol4Hold;

	int * q1, *q2, *q3,*q4,*q1Hold, *q2Hold, *q3Hold , *q4Hold;
	
	double rd =0.0, dis[2000], r[2000];  //rd is the final radius distance of Q; dis[]= d(Q,Q'), r[] id dis[];
	int tuple1[2000],tuple2[2000],tuple3[2000],tuple4[2000];

	double rr[2000],rOrder[2000]; 
	double x[106];

	//int iSizeProfile = 872; //436; //218;	 //for Gauss
	//int iSizeProfile = 872; //436; //218;	 //for Array
	int iSizeProfile = 0; 

	int iTopN = 100;

	int iInsertOK = 0, iInsertERR = 0, irderr = 0;
 ////// --- cancel this function, using LSI function
	//0
	//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census3D_Profile0414"; //Census3D	
	//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census3D_Profile0218"; //Census3D	
	
	//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Gauss3D_Profile0218"; //Gauss3D	
	//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Gauss3D_Profile0436"; //Gauss3D	
	//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Gauss3D_Profile0872"; //Gauss3D	
	
	//UCHAR szSqlAllRows[] = "SELECT * FROM Array3D_Top100_Profile0218"; //Array3D	
	//UCHAR szSqlAllRows[] = "SELECT * FROM Array3D_Top100_Profile0436"; //Array3D	
	//UCHAR szSqlAllRows[] = "SELECT * FROM Array3D_Top100_Profile0872"; //Array3D	
	
	// ???? 
	UCHAR szSqlAllRows[] = "SELECT * FROM Cover4D_Top100_Profile0218"; //Cover4D	
	
	//1									  
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Census3Dg_B_workload"; //workload						
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Gauss3D_B_workload"; //workload						
	
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Array3Dg_B_workload"; //Array workload						
	
	UCHAR szSqlAllQueryRows[] = "SELECT * FROM Cover4D_B_workload"; //Array workload						

	//2
	//UCHAR szSqlAllRowsFrmcensus2D[] = "SELECT * FROM CLMB_census3D"; //census2D				
	
	//UCHAR szSqlAllRowsFrmcensus2D[] = "SELECT * FROM CLMB_Gauss3D"; //Gauss3D				
	
	UCHAR szSqlAllRowsFrmcensus2D[] = "SELECT * FROM CLMB_cover4D"; //Array3D				
	
	//3
	//CStrSelectHead += "select  * from CLMB_Gauss3D where (";
	CStrSelectHead += "select  * from CLMB_cover4D where (";

	//3.1
	//CStrSelect1Head	+= "select  * from CLMB_Gauss3D where (";
	CStrSelect1Head	+= "select  * from CLMB_cover4D where (";
	
	//4
	//CStrInsert += " INSERT dbo.Census3D_T0100_B_Learning_P0414 VALUES( ";
	//CStrInsert += " INSERT dbo.Census3D_T0100_B_Learning_P0218 VALUES( ";
	
	//CStrInsertHead += " INSERT Gauss3D_T0100_B_Learning_P0218 VALUES( ";  //Gauss3D
	//CStrInsertHead += " INSERT Gauss3D_T0100_B_Learning_P0436 VALUES( ";
	//CStrInsertHead += " INSERT Gauss3D_T0100_B_Learning_P0872 VALUES( ";
							 
	//CStrInsertHead += " INSERT Array3D_T0100_B_Learning_P0218 VALUES( ";   // Array3D
	//CStrInsertHead += " INSERT Array3D_T0100_B_Learning_P0436 VALUES( ";
	
	//???? CStrInsertHead += " INSERT Cover4D_T0100_B_Learning_P0218 VALUES( ";

	if(!zlOpenDB())
	{
		AfxMessageBox("zlOpenDB() err!");
		zlCloseDB();
	}else
	{
		retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_WorkLoad); ///queries Statement handle 
		retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_Profile); /// Profile Statement handle 

		//1. read all tuples from Profile set store a buffer
		//1111111111111 read database from profiles :DATA_Top100_Census2D_Profile 111111111111111	
												//   Top100_Census2D_Profile2000
		//0---------------
		//UCHAR szSqlAllRows[] = "SELECT * FROM DATA_Top100_Census2D_Profile"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile2000"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile1000"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile0800"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile0400"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile0200"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile0100"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile0250"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile1459"; //discounts, authors, Census2DTable						
	
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top50_Census2D_Profile1459"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top250_Census2D_Profile1459"; //discounts, authors, Census2DTable								
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top1000_Census2D_Profile1459"; //discounts, authors, Census2DTable						
		
		 //UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile1459"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile1459_EUCL"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile1459_SUM"; //discounts, authors, Census2DTable						
		 
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile0730"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile0365"; //discounts, authors, Census2DTable						
		
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census3D_Profile1654"; //Census3D
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census3D_Profile0827"; //Census3D
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census3D_Profile0414"; //Census3D

		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		
		longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);
		longTicks = GetTickCount() - longTicks;

		//lEndTimer = GetTickCount() - lStartTimer;
		//wsprintf(tmp, "%ld", lEndTimer);


		if (retcode == SQL_SUCCESS) 
		{    //	retcode = SQLExecDirect for DATA_Top100_Census2D_Profile
			
			int iRowCount;
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt, RowCountPtr);						 
			iRowCount = * RowCountPtr;
			iTupleNum = iRowCount;
			iSizeProfile = iRowCount; // here only size of profile, 218, 436, 872, //100,200, ...,2000
			delete RowCountPtr;
			
			// Bind columns 1,2,3,4
			SQLBindCol(hstmt, 1, SQL_C_SLONG, &sCol1,0, &cbCol1);
			SQLBindCol(hstmt, 2, SQL_C_SLONG, &sCol2,0, &cbCol2); //SQL_C_SSHORT
			SQLBindCol(hstmt, 3, SQL_C_SLONG, &sCol3,0, &cbCol3); //SQL_C_SSHORT
			SQLBindCol(hstmt, 4, SQL_C_SLONG, &sCol4,0, &cbCol4); //SQL_C_SSHORT

			SQLBindCol(hstmt, 4+1, SQL_C_SLONG, &sN,0, &cbN); //SQL_C_SSHORT
			SQLBindCol(hstmt, 5+1, SQL_C_SLONG, &sr,0, &cbr); //SQL_C_SSHORT
			SQLBindCol(hstmt, 6+1, SQL_C_SLONG, &sf,0, &cbf); //SQL_C_SSHORT
			SQLBindCol(hstmt, 7+1, SQL_C_SLONG, &sc,0, &cbc); //SQL_C_SSHORT
			SQLBindCol(hstmt, 8+1, SQL_C_SLONG, &sd,0, &cbd); //SQL_C_SSHORT

			pCol1 = new  int[iRowCount]; pCol2 = new  int[iRowCount];
			pCol3 = new  int[iRowCount]; pCol4 = new  int[iRowCount];
			pCol1Hold = pCol1; pCol2Hold = pCol2;
			pCol3Hold = pCol3; pCol4Hold = pCol4;

			pPf4D = new Profile4D[iRowCount]; pPf4DHold = pPf4D;
			
			iRowCount =0;
			while (TRUE) 
			{
				retcode = SQLFetch(hstmt);

				if (retcode == SQL_ERROR)
				{
					//show_error();
					wsprintf(tmp, "%ld", iRowCount);
					//int i = iRowCount;
					AfxMessageBox("SQLFetch Error !!!!!!");
							//break; //99.8.26
				}

				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
				{	
					*pCol1 = sCol1;*pCol2 = sCol2;*pCol3 = sCol3;*pCol4 = sCol4;
					pCol1++;		pCol2++;	   pCol3++;	      pCol4++;
					
					pPf4D->q[0]	= sCol1;				
					pPf4D->q[1]	= sCol2;
					pPf4D->q[2] = sCol3;
					pPf4D->q[3] = sCol4;
					
					pPf4D->N		= sN;
					pPf4D->r		= (float) sr;
					pPf4D->f		= sf;
					pPf4D->c		= sc;
					pPf4D->d		= sd;

					pPf4D++;

					if(retcode == SQL_SUCCESS_WITH_INFO)
					{
						wsprintf(tmp, "%ld", retcode);
						AfxMessageBox(tmp);
					}
						
				} 
				else 
				{
					break;
				}

			}   ///while (TRUE)

			pCol1 = pCol1Hold;  pCol2= pCol2Hold;
			pCol3 = pCol3Hold ; pCol4= pCol4Hold ;

			pPf4D	= pPf4DHold;
		}//	retcode = SQLExecDirect  for DATA_Top100_Census2D_Profile

	//111111111111111111 read data base  DATA_Top100_Census2D_Profile end   111111111111

	//2. Read all Queries from DATA_Census2Dg_B_workload
		 sCol1=0;sCol2=0;sCol3=0;sCol4=0;
	     cbCol1=0;cbCol2=0;cbCol3=0;cbCol4=0;
		//1
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Census2Dg_B_workload"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Census2Dg_B_workload1"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Census2Dg_B_workload2"; //discounts, authors, Census2DTable						
	
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Census3Dg_B_workload"; //discounts, authors, Census2DTable						
		
		SQLSetStmtOption(hstmt_Census2D_WorkLoad, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt_Census2D_WorkLoad, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		retcode = SQLExecDirect(hstmt_Census2D_WorkLoad, szSqlAllQueryRows, SQL_NTS);

		//lEndTimer = GetTickCount() - lStartTimer;
		//wsprintf(tmp, "%ld", lEndTimer);


		if (retcode == SQL_SUCCESS) 
		{    //	retcode = SQLExecDirect for census2Dg
			int iRowCount;
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt_Census2D_WorkLoad, RowCountPtr);						 
			iRowCount = * RowCountPtr;
			delete RowCountPtr;
			
			// Bind columns 1,2,3,4
			SQLBindCol(hstmt_Census2D_WorkLoad, 1, SQL_C_SLONG, &sCol1,0, &cbCol1);
			SQLBindCol(hstmt_Census2D_WorkLoad, 2, SQL_C_SLONG, &sCol2,0, &cbCol2); //SQL_C_SSHORT
			SQLBindCol(hstmt_Census2D_WorkLoad, 3, SQL_C_SLONG, &sCol3,0, &cbCol3); //SQL_C_SSHORT
			SQLBindCol(hstmt_Census2D_WorkLoad, 4, SQL_C_SLONG, &sCol4,0, &cbCol4); //SQL_C_SSHORT

			q1 = new  int[iRowCount];//buffer, new float[10]
			q2 = new  int[iRowCount];//buffer , new float[10]
			q3 = new  int[iRowCount];//buffer , new float[10]
			q4 = new  int[iRowCount];//buffer , new float[10]
		
			q1Hold = q1; q2Hold= q2; q3Hold = q3;q4Hold = q4;


			while (TRUE) 
			{
				retcode = SQLFetch(hstmt_Census2D_WorkLoad);
				if (retcode == SQL_ERROR)
				{
					//show_error();
					wsprintf(tmp, "%ld", iRowCount);
					//int i = iRowCount;
					AfxMessageBox("SQLFetch Error !!!!!!");
							//break; //99.8.26
				}
				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
				{	
					*q1	= sCol1;*q2	= sCol2;*q3 = sCol3;*q4 = sCol4;
					q1++;		q2++;		q3++;		q4++;
				} 
				else 
				{
					break;
				}

			}   ///while (TRUE)
			
			q1= q1Hold; q2= q2Hold;q3= q3Hold;q4= q4Hold;
				
		}//	retcode = SQLExecDirect  for query q1,q2.
	
	
	//3. evaluate r, f, -c, -d,

		double ftmp=0;
		int itmp = 0,qnum =0; 
		int topt1[2000],topt2[2000],topt3[2000],topt4[2000];
		int frequ[2000],freOrder[2000];

		for(i=0; i<2000; i++)
		{
			topt1[i]=0; topt2[i] =0; topt3[i] = 0; topt4[i] = 0;
			frequ[i]=0; freOrder[i] =0;
		}

//////////////////
		SQLFreeStmt(hstmt, SQL_DROP);
		retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 
		//2
		//UCHAR szSqlAllRows[] = "SELECT * FROM census2Dg"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRowsFrmcensus2D[] = "SELECT * FROM CLMB_census2D"; //census2D				
		//UCHAR szSqlAllRowsFrmcensus2D[] = "SELECT * FROM CLMB_census3D"; //census3D						
		//UCHAR szSqlAllRowsFrmcensus2D[] = "SELECT * FROM CLMB_Array3D"; //census3D						

		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		
		longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, szSqlAllRowsFrmcensus2D, SQL_NTS);
		longTicks = GetTickCount() - longTicks;
//////////////////////////
		do
		{

//////////////////
		/**********************
		SQLFreeStmt(hstmt, SQL_DROP);
		retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 
		//2
		//UCHAR szSqlAllRows[] = "SELECT * FROM census2Dg"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRowsFrmcensus2D[] = "SELECT * FROM CLMB_census2D"; //census2D				
		//UCHAR szSqlAllRowsFrmcensus2D[] = "SELECT * FROM CLMB_census3D"; //census3D						
		//UCHAR szSqlAllRowsFrmcensus2D[] = "SELECT * FROM CLMB_Array3D"; //census3D						

		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		
		longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, szSqlAllRowsFrmcensus2D, SQL_NTS);
		longTicks = GetTickCount() - longTicks;
		*******************/
//////////////////////////

			////////////for each query find the closed profiles
			//evaluate all distance from New_query(q1[qnum],q2[qnum]) to Profile Point: 
			//														(pAge[i],pIncome[i] )
			// dis[i] = d(Q,Q') = dmax(Q,Q') = max(|qi-q'i|)

			for(i = 0; i<iSizeProfile; i++)
			{
			  x[1]=abs(pCol1[i]- q1[qnum]);x[2]=abs(pCol2[i]-q2[qnum]);
			  x[3]=abs(pCol3[i]- q3[qnum]);x[4]=abs(pCol4[i]-q4[qnum]);
			  
			  dis[i] = (double)max( x[1], x[2]); dis[i] = (double)max(dis[i], x[3]);//MAX distance
			  dis[i] = (double)max(dis[i], x[4]);
			  //dis[i] = (double)sqrt( x[1]*x[1] + x[2]*x[2] + x[3]*x[3] + x[4]*x[4]);  //EUCL distance
			  //dis[i] = (double)( x[1] + x[2] + x[3]+ x[4]); //SUM distance 

			  tuple1[i] = pCol1[i];
			  tuple2[i] = pCol2[i];
			  tuple3[i] = pCol3[i];
			  tuple4[i] = pCol4[i];

			  
			  rr[i] = pPf4D[i].r;  //best search radius in Profile
			  frequ[i] = pPf4D[i].f; 		
			}

			i=0;

			//order all distance
			// r[i]'s are sorting of dis[i] =  d(Q,Q'), to identify the closest Q' to Q
			for(i=0; i<iSizeProfile; i++)
			{
				r[i] = dis[i];  //d(Q,Q')
				topt1[i] = tuple1[i]; topt2[i]=tuple2[i]; topt3[i]=tuple3[i];topt4[i]=tuple4[i];//profile points
			
				rOrder[i] = rr[i];  //radius order
				freOrder[i] = frequ[i];

				for( j= i+1; j<iSizeProfile; j++)
				{
					if(dis[j] < r[i]) 
					{ ftmp = r[i];			r[i] = dis[j];			dis[j] = ftmp;
					  ftmp = rOrder[i];		rOrder[i] = rr[j];		rr[j] = ftmp;
					  itmp = freOrder[i];   freOrder[i]= frequ[j]; frequ[j] = itmp;

					  itmp = topt1[i];		topt1[i]= tuple1[j]; tuple1[j]= itmp;
					  itmp = topt2[i];		topt2[i]= tuple2[j]; tuple2[j]= itmp;
					  itmp = topt3[i];		topt3[i]= tuple3[j]; tuple3[j]= itmp;
					  itmp = topt4[i];		topt4[i]= tuple4[j]; tuple4[j]= itmp;

					}
				}
			}
					
		//int N, rd,f, c, d; 
		//evaluate search distance
		
		int qp1 = topt1[0], qp2= topt2[0], qp3= topt3[0],qp4= topt4[0]; //Q'(qp1,qp2), the closest proples to Q(q1,q2)
		int iKnum = 0,fpf[2000];
		double frou[2000],l[2000],V[2000], lV=0, lVrou =0, rou = 0;
		double dQQ[2000],rpf[2000];
		double dmaxQQp;

		if(r[0] == 0) // if Q=Q'
		{//if(r[0] == 0)
			rd = rOrder[0];
			//rd = 2*rOrder[0];
			//rd = rOrder[0]/2;
			//rd = rOrder[0]/10;

			int itest = 0; //use to test 
		}
		else
		{
			 x[1]=abs(qp1 - q1[qnum]);x[2]=abs(qp2 - q2[qnum]);x[3]=abs(qp3-q3[qnum]);x[4]=abs(qp4-q4[qnum]);
		
			 dmaxQQp = (double)max( x[1], x[2]); dmaxQQp= (double)max(dmaxQQp, x[3]);//MAX distance		
			 dmaxQQp= (double)max(dmaxQQp, x[4]);
			 //dmaxQQp  //i.e.r[0]

			if(dmaxQQp <= rOrder[0])  //case of Fig.3 //rou = N/4*r*r
			{
				iKnum = 0;
				
				for(j=0; j<iSizeProfile; j++)
				{
					frou[j] =0;l[j] =0;V[j] = 0;
					dQQ[j] =0;rpf[j] = 0;fpf[j]=0;
				}

				for(j=0; j<iSizeProfile; j++) //Find set K= (all squares Q in it)
				{
					if( r[j] <= rOrder[j]  ) //d(Q,Qpf) < rpf
					{
						dQQ[iKnum] = r[j];
						rpf[iKnum] = rOrder[j];
						fpf[iKnum] = freOrder[j];

						iKnum++;

					}
						
				}


				//---------- alternative test -----------------
				int iMeadian = iKnum/2;
				rou = 0;
				lVrou = 0; lV = 0;

			// ////////////// lvp
					/***************

					for(j=0; j<iKnum; j++)
					{
						//l[j] = 1.0/(dQQ[j]*dQQ[j]*dQQ[j]);		//or d*d*d								
						//l[j] = 1.0/(dQQ[j]*dQQ[j]);		//or d*d
						l[j] = 1.0/(dQQ[j]);		//or d														
						//l[j] = 1.0;		//or nondistance														

						V[j] = (2*rpf[j])*(2*rpf[j])*(2*rpf[j])*(2*rpf[j]);						
						lV += l[j]*V[j];
						lVrou += l[j]* fpf[j];   // (fpf[j]/(dQQ[j]* dQQ[j]* dQQ[j]));

						

						//frou[j] = fpf[j]/( (2*rpf[j])*(2*rpf[j])*(2*rpf[j])*(2*rpf[j]) );//100/(4*rpf[j]*rpf[j]);
						//l[j] = 1.0/(dQQ[j]*dQQ[j]*dQQ[j]*dQQ[j]);		//or d*d*d								
						//V[j] = (2*rpf[j])*(2*rpf[j])*(2*rpf[j])*(2*rpf[j]);

						//lV += ( (2*rpf[j])*(2*rpf[j])*(2*rpf[j])*(2*rpf[j])/(dQQ[j]*dQQ[j]*dQQ[j]*dQQ[j]) );      //l[j]*V[j]; 
						//lVrou += (fpf[j]/(dQQ[j]*dQQ[j]*dQQ[j]*dQQ[j]));
					}

					rou = lVrou/lV;


				//////////mean of density 
					for(j=0; j<iKnum; j++)
					{
						frou[j] = fpf[j]/( (2*rpf[j])*(2*rpf[j])*(2*rpf[j])*(2*rpf[j]) );
					    rou += frou[j]; 
					}

					rou = rou/iKnum;
					for(j=0; j<iKnum; j++)
					{
						frou[j] = fpf[j]/( (2*rpf[j])*(2*rpf[j])*(2*rpf[j])*(2*rpf[j]) );
					}

					rou = frou[iMeadian];

				


					//////////mean of ALL density 
					for(j=0; j<iSizeProfile; j++)
					{
						frou[j] = freOrder[j]/( 16*rOrder[j]*rOrder[j]*rOrder[j]*rOrder[j]);
					    rou += frou[j]; 
					}
					rou = rou/iSizeProfile;
					************/
					//////////median of ALL density 

					for(j=0; j<iSizeProfile; j++)
					{
						frou[j] = freOrder[j]/(16*rOrder[j]*rOrder[j]*rOrder[j]*rOrder[j]);;
					}
					
					double rouOrder[2000],ftmp =0;

					for(j=0; j<iSizeProfile; j++)
					{
						rouOrder[j] = frou[j]; 
						for(int k = j+1; k <iSizeProfile; k++)
						{
							if(frou[k]< rouOrder[j])
							{
								ftmp = rouOrder[j]; rouOrder[j] = frou[k]; frou[k] = ftmp;
							}
						}
					}					
					iMeadian = iSizeProfile/2;
					rou = rouOrder[iMeadian];


					rd = (double)pow( 2*100/rou, 1.0/4.0 )/2; 

					if ( (rd < rOrder[0]) ||(rd < dmaxQQp))
					{
						//rd = rd + rd/4;  //rOrder[0] ; + rd/n n-dimension
						rd = rd + max(rd, rOrder[0])/(4.0-1.0);  //rOrder[0] ; + rd/(n-1) n-dimension
						
						//irderr ++;
					}
	
					if (rd > dmaxQQp + rOrder[0])
					{
						rd = dmaxQQp + rOrder[0];
						//irderr ++;
					}

					if (rd < dmaxQQp)
					{
					//	rd = rOrder[0];
						irderr ++;
					}

				//------------Fig 3.^^^^^----------------

			}else
			{
				x[1]=abs(qp1 - q1[qnum]);x[2]=abs(qp2 - q2[qnum]);x[3]=abs(qp3-q3[qnum]);x[4]=abs(qp4-q4[qnum]);
		
				dmaxQQp = (double)max( x[1], x[2]); dmaxQQp= (double)max(dmaxQQp, x[3]);//MAX distance		
				dmaxQQp= (double)max(dmaxQQp, x[4]);

				//if(dmaxQQp <= 2*rOrder[0])  //h<2r' ////2003.04.11
				{
					//case of Fig.4 //rou = N/4*r*r				
					iKnum = 0;
					for(j=0; j<2000; j++)
					{
						frou[j] =0;l[j] =0;V[j] = 0;
						dQQ[j] =0;rpf[j] = 0; fpf[j]=0;			
					}

					for(j=0; j<iSizeProfile; j++)
					{
						if(r[j] < rOrder[0] + dmaxQQp)
						{
							dQQ[iKnum] = r[j];
							rpf[iKnum] = rOrder[j];
							fpf[iKnum] = freOrder[j];

							iKnum++;
						}						
					}

					/////////////////////////////////////////////////////////
					//double x = 2.0, y = 3.0, z;
					//	z = pow( x, y );
					//printf( "%.1f to the power of %.1f is %.1f\n", x, y, z );
					//Output
					//2.0 to the power of 3.0 is 8.0
					/////////////////////////////////////////////

				//---------- alternative test -----------------
				lVrou = 0; lV = 0;
				rou = 0;
				int iMeadian = iKnum/2;
				/*****************
					for(j=0; j<iKnum; j++)
					{
						//l[j] = 1.0/(dQQ[j]*dQQ[j]*dQQ[j]);		//or d*d*d								
						//l[j] = 1.0/(dQQ[j]*dQQ[j]);		//or d*d								
						l[j] = 1.0/(dQQ[j]);		//or d														
						//l[j] = 1.0;		//or nondistance														

						V[j] = (2*rpf[j])*(2*rpf[j])*(2*rpf[j])*(2*rpf[j]);						
						lV += l[j]*V[j];
						lVrou += l[j]* fpf[j];   // (fpf[j]/(dQQ[j]* dQQ[j]* dQQ[j]));
						
						//frou[j] = fpf[j]/( (2*rpf[j])*(2*rpf[j])*(2*rpf[j])*(2*rpf[j]) );//100/(4*rpf[j]*rpf[j]);
						//l[j] = 1.0/(dQQ[j]*dQQ[j]*dQQ[j]*dQQ[j]);		//or d*d*d								
						//V[j] = (2*rpf[j])*(2*rpf[j])*(2*rpf[j])*(2*rpf[j]);

						//lV += ( (2*rpf[j])*(2*rpf[j])*(2*rpf[j])*(2*rpf[j])/(dQQ[j]*dQQ[j]*dQQ[j]*dQQ[j]) );      //l[j]*V[j]; 
						//lVrou += (fpf[j]/(dQQ[j]*dQQ[j]*dQQ[j]*dQQ[j]));								
					}
					rou = lVrou/lV;
					*********************/

				/****************

					//////////mean of density 
					for(j=0; j<iKnum; j++)
					{
						frou[j] = fpf[j]/( (2*rpf[j])*(2*rpf[j])*(2*rpf[j])*(2*rpf[j]) );
					    rou += frou[j]; 
					}
					rou = rou/iKnum;

					///Meadian_density
					for(j=0; j<iKnum; j++)
					{
						frou[j] = fpf[j]/( (2*rpf[j])*(2*rpf[j])*(2*rpf[j])*(2*rpf[j]) );
					}
					rou = frou[iMeadian];
					


					//////////mean of ALL density 
					for(j=0; j<iSizeProfile; j++)
					{
						frou[j] = freOrder[j]/( 16*rOrder[j]*rOrder[j]*rOrder[j]*rOrder[j]);
					    rou += frou[j]; 
					}
					rou = rou/iSizeProfile;
					****************/

					//////////median of ALL density 

					for(j=0; j<iSizeProfile; j++)
					{
						frou[j] = freOrder[j]/(16*rOrder[j]*rOrder[j]*rOrder[j]*rOrder[j]);;
					}

					double rouOrder[2000],ftmp =0;

					for(j=0; j<iSizeProfile; j++)
					{
						rouOrder[j] = frou[j]; 
						for(int k = j+1; k <iSizeProfile; k++)
						{
							if(frou[k]< rouOrder[j])
							{
								ftmp = rouOrder[j]; rouOrder[j] = frou[k]; frou[k] = ftmp;
							}
						}
					}					
					iMeadian = iSizeProfile/2;
					rou = rouOrder[iMeadian];
					


					rd = (double)pow( 2*100/rou, 1.0/4.0 )/2; 
		
				if ( (rd < rOrder[0]) ||(rd < dmaxQQp))
				{
						//rd = rd + rd/4;  //rOrder[0] ; + rd/n n-dimension
						rd = rd + max(rd, rOrder[0])/(4.0-1.0);  //rOrder[0] ; + rd/(n-1) n-dimension
						//irderr ++;
				}
				if (rd > dmaxQQp + rOrder[0])
				{
					rd = dmaxQQp + rOrder[0];
					//irderr ++;
				}

				if (rd < dmaxQQp)
				{
				//	rd = rOrder[0];
					irderr ++;
				}

				//-----------------fig. 4 -^^^^^^ end ---------- 
			
					int itest = 0;
				//}else{  ////2003.04.11

					//rd = dmaxQQp + rOrder[0];  //2003.04.11

				}//if(dmaxQQp <= 2*rOrder[0])

			}//if(dmaxQQp <= rOrder[0])


		}//if(r[0] == 0)

		
		//rd = rOrder[0];

			
			CTime CurTime = CTime::GetCurrentTime();         

			//N = 100; c = -1; d = - CurTime.GetTime();
			
			N = iTopN; c = -1; d-- ;

			char cLeft1[20] = "", cRight1[20] = "", cLeft2[20] = "", cRight2[20] ="";
			char cLeft3[20] = "", cRight3[20] = "", cLeft4[20] = "", cRight4[20] = "";
		
			sprintf(cLeft1,		"%f",	(float)(q1[qnum] - rd)	);
			sprintf(cRight1,	"%f",	(float)(q1[qnum] + rd)	);
			sprintf(cLeft2,		"%f",	(float)(q2[qnum] - rd)	);
			sprintf(cRight2,	"%f",	(float)(q2[qnum] + rd)	);
			sprintf(cLeft3,		"%f",	(float)(q3[qnum] - rd)	);
			sprintf(cRight3,	"%f",	(float)(q3[qnum] + rd)	);
			sprintf(cLeft4,		"%f",	(float)(q4[qnum] - rd)	);
			sprintf(cRight4,	"%f",	(float)(q4[qnum] + rd)	);
			//3
			CStrSelect += CStrSelectHead; //"select  * from CLMB_census3D where (";

			CStrSelect += cLeft1;
			CStrSelect += "<= Elevation AND Elevation <=";
			CStrSelect += cRight1;

			CStrSelect += ") AND (";
			CStrSelect += cLeft2;
			CStrSelect += "<= Aspect AND Aspect <=";
			CStrSelect += cRight2;

			CStrSelect += ") AND (";
			CStrSelect += cLeft3;
			CStrSelect += "<= Slope AND Slope <=";   //Slope
			CStrSelect += cRight3;
			
			CStrSelect += ") AND (";
			CStrSelect += cLeft4;
			CStrSelect += "<= Distance_To_Roadways AND Distance_To_Roadways <=";   //Distance_To_Roadways
			CStrSelect += cRight4;

			CStrSelect += ")"; 

			int iSqlLen = CStrSelect.GetLength();
			char * szSqlSquareRows = new char [iSqlLen + 1];	
			strcpy(szSqlSquareRows , "");
			strcat(szSqlSquareRows , CStrSelect);
	
			SQLFreeStmt(hstmt, SQL_DROP);
			retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 

			SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
			SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
			
			shortTicks = GetTickCount();
			retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlSquareRows, SQL_NTS);
			shortTicks = GetTickCount() - shortTicks;

			//lEndTimer = GetTickCount() - lStartTimer;
			//wsprintf(tmp, "%ld", irderr ++;);

			if (retcode == SQL_SUCCESS) 
			{    //	retcode = SQLExecDirect for census2Dg
				SDWORD *  RowCountPtr = new SDWORD ;
				retcode = SQLRowCount(hstmt, RowCountPtr);						 
				f = * RowCountPtr;
				delete RowCountPtr;

			}

			if(f<=0)
				int iiii = 0;

			CStrSelect = "";
			delete [] szSqlSquareRows;

	//4. insert zeta into DATA_Top100_Census2D_Profile
		
			if( f<iTopN )
			{
				rd = dmaxQQp + rOrder[0];
				for (i = 0; i< 20; i++)
				{
					cLeft1[i] = 0; cRight1[i] = 0; cLeft2[i] = 0; cRight2[i] =0;
					cLeft3[i] = 0; cRight3[i] = 0; cLeft4[i] = 0; cRight4[i] =0;
				}
				sprintf(cLeft1,		"%f",	(float)(q1[qnum] - rd)	);
				sprintf(cRight1,	"%f",	(float)(q1[qnum] + rd)	);
				sprintf(cLeft2,		"%f",	(float)(q2[qnum] - rd)	);
				sprintf(cRight2,	"%f",	(float)(q2[qnum] + rd)	);
				sprintf(cLeft3,		"%f",	(float)(q3[qnum] - rd)	);
				sprintf(cRight3,	"%f",	(float)(q3[qnum] + rd)	);
				sprintf(cLeft4,		"%f",	(float)(q4[qnum] - rd)	);
				sprintf(cRight4,	"%f",	(float)(q4[qnum] + rd)	);

				//3.1
				CStrSelect = "";				
				CStrSelect += CStrSelectHead; //"select  * from CLMB_census3D where (";

				CStrSelect += cLeft1;
				CStrSelect += "<= Elevation AND Elevation <=";
				CStrSelect += cRight1;

				CStrSelect += ") AND (";
				CStrSelect += cLeft2;
				CStrSelect += "<= Aspect AND Aspect <=";
				CStrSelect += cRight2;

				CStrSelect += ") AND (";
				CStrSelect += cLeft3;
				CStrSelect += "<= Slope AND Slope <=";   //Slope
				CStrSelect += cRight3;
				
				CStrSelect += ") AND (";
				CStrSelect += cLeft4;
				CStrSelect += "<= Distance_To_Roadways AND Distance_To_Roadways <=";   //Distance_To_Roadways
				CStrSelect += cRight4;

				CStrSelect += ")"; 

				int iSqlLen = CStrSelect.GetLength();
				char * szSqlSquareRows_rst = new char [iSqlLen + 1];	
				strcpy(szSqlSquareRows_rst , "");
				strcat(szSqlSquareRows_rst , CStrSelect);
		
				SQLFreeStmt(hstmt, SQL_DROP);
				retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 

				SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
				SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
				
				shortTicks_rst = GetTickCount();
				retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlSquareRows_rst, SQL_NTS);
				shortTicks_rst = GetTickCount() - shortTicks_rst;

				if (retcode == SQL_SUCCESS) 
				{    //	retcode = SQLExecDirect for census2Dg
					SDWORD *  RowCountPtr = new SDWORD ;
					retcode = SQLRowCount(hstmt, RowCountPtr);						 
					f_rst = * RowCountPtr;
					delete RowCountPtr;

				}

				if(f_rst<=0)
				  int iiiib = 0;

				CStrSelect = "";
				delete [] szSqlSquareRows_rst;
						
			} //if(f<iTopN)
		
			if (f>0)
			{   
				char	cAttribute[11][50]= { "","","","","","","","","",""};
				
				sprintf(cAttribute[0],		"%ld", q1[qnum] );
				sprintf(cAttribute[1],		"%ld", q2[qnum] );
				sprintf(cAttribute[1+1],	"%ld", q3[qnum] );
				sprintf(cAttribute[1+1+1],	"%ld", q4[qnum] );

				sprintf(cAttribute[2+1+1],"%ld", N);
				sprintf(cAttribute[3+1+1],"%f",  (float)rd);
				sprintf(cAttribute[4+1+1],"%ld", f );
				if(f_rst > 0)
				{
					sprintf(cAttribute[5+1+1],"%ld", f_rst );
					sprintf(cAttribute[6+1+1],"%ld", shortTicks_rst);
					f_rst = 0;
				}else
				{
					sprintf(cAttribute[5+1+1],"NULL");
					sprintf(cAttribute[6+1+1],"NULL");

				}
				sprintf(cAttribute[7+1+1],"%ld", shortTicks);
				sprintf(cAttribute[8+1+1],"%ld", longTicks);

				//4
				//CStrInsert += " INSERT DATA_Top100_Census2D_Learning VALUES( ";	
				//CStrInsert += " INSERT Top100Census2D_LearningFrmPf100 VALUES( ";	
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm2000 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm1000 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm0800 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm0400 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm0200 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm0100 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm0250 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm1459 VALUES( ";
		
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm1459_Top50 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm1459_Top250 VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm1459_Top1000 VALUES( ";

				//CStrInsert += " INSERT Top100_Census2D_LearningFrm1459_EUCL VALUES( ";
				//CStrInsert += " INSERT Top100_Census2D_LearningFrm1459_SUM VALUES( ";
			
				//CStrInsert += " INSERT dbo.Census2D_T0100_B_Learning_P0730 VALUES( ";
				//CStrInsert += " INSERT dbo.Census2D_T0100_B_Learning_P0365 VALUES( ";
				
				//CStrInsert += " INSERT dbo.Census3D_T0100_B_Learning_P1654 VALUES( ";
				//CStrInsert += " INSERT dbo.Census3D_T0100_B_Learning_P0827 VALUES( ";
				//CStrInsert += " INSERT dbo.Census3D_T0100_B_Learning_P0414 VALUES( ";
				CStrInsert += CStrInsertHead; //" INSERT dbo.Census3D_T0100_B_Learning_P0218 VALUES( ";

				CStrInsert += cAttribute[0];
				CStrInsert += ",";
				CStrInsert += cAttribute[1];
				CStrInsert += ",";
				CStrInsert += cAttribute[2];
				CStrInsert += ",";
				CStrInsert += cAttribute[3];
				CStrInsert += ",";
				CStrInsert += cAttribute[4];
				CStrInsert += ",";
				CStrInsert += cAttribute[5];
				CStrInsert += ",";
				CStrInsert += cAttribute[6];
				CStrInsert += ",";
				CStrInsert += cAttribute[7];
				CStrInsert += ",";
				CStrInsert += cAttribute[8];
				CStrInsert += ",";
				CStrInsert += cAttribute[9];
				CStrInsert += ",";
				CStrInsert += cAttribute[10];
			
				CStrInsert += ")";


			    int iSqlLen = CStrInsert.GetLength();

				char * szSqlInsert = new char [iSqlLen + 1];
				strcpy(szSqlInsert , "");
				strcat(szSqlInsert , CStrInsert);

				SQLFreeStmt(hstmt_Census2D_Profile, SQL_DROP);
				retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_Profile); /// Profile Statement handle 

				retcode = SQLExecDirect(hstmt_Census2D_Profile, (unsigned char *)szSqlInsert, SQL_NTS);

				if (retcode == SQL_SUCCESS) 
				{  //	retcode = SQLExecDirect
					//AfxMessageBox("Insert new hstmt_Census2D_Learning  OKKKKKKKKKKK!");
					//Sleep(300);
					iInsertOK++;

					//bReturn = TRUE;
				}
				else
				{
					AfxMessageBox("Insert DATA_Top100_Census2D_Learning Error!");
					iInsertERR++;
					i= 0;

				} //	retcode = SQLExecDirect 
				
				f=0;

				CStrInsert = "";
				delete [] szSqlInsert;
			}
		

			qnum++;
		}while(qnum <iTopN); //100);

	}//if(!zlOpenDB())


	delete [] pCol1;//new float[10]
	delete [] pCol2;//new float[10]
	delete [] pCol3;//new float[10]
	delete [] pCol4;//new float[10]

	delete [] q1;//new float[10]
	delete [] q2;//new float[10]
	delete [] q3;//new float[10]
	delete [] q4;//new float[10]

	delete [] pPf4D;

	SQLFreeStmt(hstmt, SQL_DROP);
	SQLFreeStmt(hstmt_Census2D_WorkLoad, SQL_DROP);
	SQLFreeStmt(hstmt_Census2D_Profile, SQL_DROP);

	 ;
	wsprintf(tmp, " irderr = %d", irderr);

	AfxMessageBox(tmp);

	AfxMessageBox("Insert hstmt_Generet2DLearning  OK!");	
	
}

void CMainFrame::OnLsi_104D() 
{	
	//Menu: LSI_104D
	//for dimension: 104, 50, 25
	// the size of datasets are
	//20382 for 104
	//42394 for 50 , result is 42394
	//84789 for 25,	 result is 84789

	int i,j, iTotalNum = 0, iErr =0 ;
	int iDim = 104; //25; //50; //104;
	int iTuplesNum = 20000; //20382*104/iDim; 
   
	char Lsi_File[] = "\\\\.\\D:\\users\\zhuliang\\DATA\\lsidata"; // name of input file        
	CString CStrInsert = "";
	HSTMT   hstmt_Generet2DWorkload;
	char	cAttr[104][100];
	//char	cAttr[50][100];
	//char	cAttr[25][100];

	if( !zlOpenLsi_104Dim_File(Lsi_File) )
	{
		AfxMessageBox("zlOpenLsi_104Dim_File err!");
	}
	else
	{
		for(i=0; i<iTuplesNum;i++)
			for(j=0;j<iDim;j++)
				fCells[i][j] = (double) vecs[i][j]; 
		
	}


	if(!zlOpenDB())
	{
		AfxMessageBox("zlOpenDB() err!");
		zlCloseDB();
	}else
	{
		retcode = SQLAllocStmt(hdbc, &hstmt_Generet2DWorkload); ///Statement handle 
		
		for(int iRowNum = 0; iRowNum < iTuplesNum; iRowNum++)
		{
			// Attribute = 0
			for (i = 0; i < iDim; i++)
			{				
				for(j = 0; j<100; j++)
					cAttr[i][j] = 0;
			}
			// Attribute = Lsi value for per row
			for (j = 0; j < iDim; j++)
			{
				sprintf(cAttr[j], "%G", fCells[iRowNum][j]); //vecs[iRowNum][j]);
				if ( strcmp(cAttr[j], "1.#QNAN") ==0 )
				{
					sprintf(cAttr[j], "%G", 1.28495000); 
				}
					
				if ( strcmp(cAttr[j], "-1.#QNAN") == 0 )
				{
					sprintf(cAttr[j], "%G", -1.92271000); 
				}
			}

			///////////// insert 
			//CStrInsert += " INSERT Lsi104D VALUES( ";	
			//CStrInsert += " INSERT Lsi050D VALUES( ";	
			//CStrInsert += " INSERT Lsi025D VALUES( ";	
			CStrInsert += " INSERT Lsi_104D VALUES( ";	

			for (j = 0; j < iDim-1; j++)
			{
				CStrInsert += cAttr[j];
				CStrInsert += ",";
			}
			CStrInsert += cAttr[iDim-1];
			CStrInsert += ")";

			int iSqlLen = CStrInsert.GetLength();

			char * szSqlInsert = new char [iSqlLen + 1];
			strcpy(szSqlInsert , "");
			strcat(szSqlInsert , CStrInsert);
		
			SQLFreeStmt(hstmt_Generet2DWorkload, SQL_DROP);
			retcode = SQLAllocStmt(hdbc, &hstmt_Generet2DWorkload); /// Profile Statement handle 

			retcode = SQLExecDirect(hstmt_Generet2DWorkload, (unsigned char *)szSqlInsert, SQL_NTS);

			if (retcode == SQL_SUCCESS) 
			{  //	retcode = SQLExecDirect
				//AfxMessageBox("Insert new Recode Seccess!");
				//bReturn = TRUE;
				iTotalNum ++;
			}
			else
			{
				//	AfxMessageBox("Insert new Recode Error!");
				iErr++;

			} //	retcode = SQLExecDirect 
					
			CStrInsert = "";
			delete [] szSqlInsert; 

		}//for(int iRowNum = 0; iRowNum < iTuplesNum; iRowNum++)

	} //if(!zlOpenDB())

	SQLFreeStmt(hstmt_Generet2DWorkload, SQL_DROP);

	zlCloseDB(); 
	char ctmp[70] = "";
	sprintf(ctmp, "Insert OnLsi_104D iErr = %ld", iErr);
	AfxMessageBox(ctmp);
	AfxMessageBox("Insert OnLsi_104D  OK!");

}

bool CMainFrame::zlOpenLsi_104Dim_File(char *filename)
{
        char VecFile[128] = ""; // name of input file        
		int fd; // input file descriptor        
		int d;        // dimensions        
		int n;        // # vectors        
		//float *vecs_mem, **vecs, *v;        // buffer for vectors
	    bool breturn = false;
		int i;
		unsigned bytesread;		

		//... YOU NEED TO ASSIGN VALUES TO VecFile, d, n here ...
		d = 104; n = 20000;
		//d = 50; n = 20382*104/50;  //==42394
		//d = 25; n = 20382*104/25;  //==84789
	
		strcpy(VecFile, filename);

        // construct buffer            
		if ((vecs_mem = new float [d*n]) == NULL)        
		{             
			AfxMessageBox("Memory allocation failed for vecs_mem");
			breturn = false;
			exit(1);        
		}

        if ((vecs = new float* [n]) == NULL)         
		{           
			AfxMessageBox("Memory allocation failed for vecs");
			breturn = false;
			exit(1);        
		}

		vecs[0] = vecs_mem;  
		
		for (i=1; i < n; i++)        
		{          
			vecs[i] = vecs[i-1] + d;
        }       

        // open input file 
		fd = _open(VecFile,_O_RDONLY|_O_BINARY,0);            
		if (fd == -1)          
		{          
			AfxMessageBox("Can't open file ");	
			breturn = false;
			exit(1);           
		}

        // skip header; pos = _lseek( fh, 0L, SEEK_SET );           
		_lseek(fd, (long) 24, 0);


        // read n vectors into buffer ; if( ( bytesread = _read( fh, buffer, nbytes ) ) <= 0 )
		if ( (bytesread = _read(fd, (char *) vecs_mem, sizeof(float)*d*n ) )!= sizeof(float)*d*n ) 
		{                
			AfxMessageBox("Loading error!");
			breturn = false;
			exit(1);       
		}
		else
		{
			breturn = true;
		}


	return breturn;
}

void CMainFrame::zlcode()
{

/**************

        char VecFile[128]; // name of input file        
		int fd; // input file descriptor        
		int d;        // dimensions        
		int n;        // # vectors        
		float *vecs_mem, **vecs, *v;        // buffer for vectors
	
		int i;
		//... YOU NEED TO ASSIGN VALUES TO VecFile, d, n here ...

        // construct buffer            
		if ((vecs_mem = new float [d*n]) == NULL)        
		{             
			AfxMessageBox("Memory allocation failed for vecs_mem");
			exit(1);        
		}

        if ((vecs = new float* [n]) == NULL)         
		{           
			AfxMessageBox("Memory allocation failed for vecs");
			exit(1);        
		}

		vecs[0] = vecs_mem;  
		
		for (i=1; i < n; i++)        
		{          
			vecs[i] = vecs[i-1] + d;
        }       

        // open input file            
		fd = open(VecFile,O_RDONLY,0);            
		if (fd == -1)          
		{          
			AfxMessageBox("Can't open file ");	
			exit(1);           
		}

        // skip header             
		lseek(fd, (long) 24, 0);


        // read n vectors into buffer        
		if ( read(fd, (char *) vecs_mem, sizeof(float)*d*n ) != sizeof(float)*d*n ) 
		{                
			AfxMessageBox("Loading error!");
			exit(1);       
		}
**********/


}

void CMainFrame::OnHouse20D() 
{
	//AfxMessageBox("This is OnViewFileToDB!");
	//char buffer[3000] = "";
	char buffer[81920] = "";
	CString CStrBuff = "";
	CString CStrBuffMeg = "";
	CString CStrInsert = ""; 
	char	cTmp[100] = "";
	char	cTmp1[100] = "";
	char	cTmp2[10000] = "";

	int iDim = 138; //20;
	char	cAttribute[138][50]; //= { "","","","","","","","","","",
								 // "","","","","","","","","",""};
	//CString cAttribute[15];
	
	int i,j,istart = 0;
	int iBreadCount = 0, itest, iErr =0 ;
	int iTuplesNum = 0;

	
	//---------  create Read File start --------
	//SQLFreeStmt(hstmt, SQL_DROP);
	//zlCloseFileDB();

	//strcpy(ReadFileName, "\\\\.\\D:\\users\\zhuliang\\DATA\\adult.data"); //OK
	strcpy(ReadFileName, "\\\\.\\D:\\users\\zhuliang\\DATA\\Dataset.data"); //OK

	for(i = 0; i< 138; i++)
		for(j=0; j<50;j++)
			cAttribute[i][j]=0;

	if(!zlOpenFileDB())
	{
		AfxMessageBox("zlOpenFileDB() err!");
		zlCloseFileDB();
	}else
	{// read file  and convert it to database 
	
		//++++++ to do start +++++++++++++
		do 
		{
			if (ReadFile(hReadFile, buffer, 80000, 
					&dwBytesRead, NULL)) 
			{ 
				CStrBuff += buffer;
				CStrBuff.TrimLeft();
				int iLen = CStrBuff.GetLength();

			  for(i=0; i < iLen; i++)
			  {
				  if(CStrBuff[i]== 10)
					  iTuplesNum++;
			  }

			  iBreadCount = 0;
			  while ( iBreadCount < iTuplesNum-1 ) 
			  {
					
				for (i = 0; i < iDim; i++)
				{// for i
					
					int k= 0;
					for (k = 0; k<50; k++)
					    cAttribute[i][k] =0;

					k= 0;

					for(j = istart; j < iLen; j++)
					{ //for j
											
						if( (CStrBuff[j] == 9) || CStrBuff[j] == 10 )
						{
							if(CStrBuff[j] == 10)
							{
								iBreadCount ++;
								//j++;
							}
							if(CStrBuff[j] == 9)
								break;
							
						}else
						{
							cAttribute[i][k] = CStrBuff[j];
							k++;
						}

 
					}//for j
				
					istart = j+1;

				} //for i


					CStrInsert += " INSERT House138D VALUES( ";	
			
					for(i=0; i<iDim-1; i++)
					{
						CStrInsert += cAttribute[i];
						CStrInsert += ", ";
					}
					CStrInsert += cAttribute[iDim-1];

					CStrInsert += ")";

					int iSqlLen = CStrInsert.GetLength();

					char * szSqlInsert = new char [iSqlLen + 1];
					strcpy(szSqlInsert , "");
					strcat(szSqlInsert , CStrInsert);
		
					retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlInsert, SQL_NTS);


					if (retcode == SQL_SUCCESS) 
					{  //	retcode = SQLExecDirect
						//AfxMessageBox("Insert new Recode Seccess!");
						//bReturn = TRUE;
					}
					else
					{
					//	AfxMessageBox("Insert new Recode Error!");
						iErr++;
						itest = 1;

					} //	retcode = SQLExecDirect 
				
					CStrInsert = "";
					delete [] szSqlInsert; 

			}//while ( iBreadCount<iTuplesNum ) 



			CStrBuff = CStrBuff.Right(iLen -j-1);
			j=0;
			istart =0;
			iTuplesNum =0;
		
			//Sleep(100);
			} //if (ReadFile(hReadFile, buffer, 5000, 


		} while (dwBytesRead >0); 

		//++++++++++ to do end +++++++++

	}// read file  and convert it to database 

	sprintf(cTmp,"Err Num = %d", iErr);
    AfxMessageBox(cTmp);
	AfxMessageBox("Insert new Recode OK!!!!!!!!!!!!!!!!!!!");

	SQLFreeStmt(hstmt, SQL_DROP);
	zlCloseFileDB();	
}

void CMainFrame::OnLsi_smpl_Bworkload() 
{
	//Menu:  Generator --> Lsi(House)_smpl_Bworkload 
	//2005.08.02
	//create sample of profiles of LSI , HOUSE 
	//Menu :Generator- Smpl5810_cover4D
	// 1% of 581010 if CLMB_cover4D is 5810

	int i,j,iErr = 0;
	char tmp[100] = "";
	CString CStrInsert = ""; 
	
	double  fCol[COL_NUM+1];		//Elevation
	SDWORD cbCol[COL_NUM+1]; 

	int   iColID;	
	SDWORD cbColID; 


	//int iSizeSmpl = 5810; //250; // 200;//400; //800; //1000; //2000; 
						 ////||||100, 200, 400, 800, 1000,2000. 
						  // size of census2Dg = 145,917; CLMB_census = 210,138.
						  // Date 2003.3.24
	int iSizeSmpl = 833; //909; //954; //20000 * 5% * 104/(104+5)
	//int iSizeSmpl = 910; //867; //701;  //--- 22784 * 5% * n/(n+5) for house n = 8,16, 20; m= 701, 867,911(910)
	
	//int iSizeSmpl = 100; // for workload

	//int iSizeSmpl = 80; //20; // for workload
	//int iSizeSmpl = 50;// 50; // for workload
	//int iSizeSmpl = 20; //80; // for workload

	HSTMT   hstmt_Generet2DWorkload;

	//seed of random
	srand( (unsigned)time( NULL ) );


		if(!zlOpenDB())
		{
			AfxMessageBox("zlOpenDB() err!");
			zlCloseDB();
		}else
		{
			retcode = SQLAllocStmt(hdbc, &hstmt_Generet2DWorkload); ///Statement handle 
			
			//UCHAR szSqlAllRows[] = "SELECT * FROM Lsi_104D"; //discounts, authors, Census2DTable						
			//UCHAR szSqlAllRows[] = "SELECT * FROM Lsi_050D"; //discounts, authors, Census2DTable						
			UCHAR szSqlAllRows[] = "SELECT * FROM Lsi_025D"; //discounts, authors, Census2DTable						
			
			//UCHAR szSqlAllRows[] = "SELECT * FROM House08D"; //discounts, authors, Census2DTable						
			//UCHAR szSqlAllRows[] = "SELECT * FROM House16D"; //discounts, authors, Census2DTable						
			//UCHAR szSqlAllRows[] = "SELECT * FROM House20D"; //discounts, authors, Census2DTable						

			//UCHAR szSqlAllRows[] = "SELECT * FROM House16D_smpl867"; //discounts, authors, Census2DTable						
			//UCHAR szSqlAllRows[] = "SELECT * FROM House16D_B_WorkLoad"; //discounts, authors, Census2DTable						

			//UCHAR szSqlAllRows[] = "SELECT * FROM Lsi_104D_smpl954"; //discounts, authors, Census2DTable						
			//UCHAR szSqlAllRows[] = "SELECT * FROM Lsi_104D_B_WorkLoad"; //discounts, authors, Census2DTable						
				
			SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
			SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
			retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);

			//lEndTimer = GetTickCount() - lStartTimer;
			//wsprintf(tmp, "%ld", lEndTimer);

			//1111111111111 read data base 111111111111111

			if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) 
			{    //	retcode = SQLExecDirect
				int iRowCount, iTupleNum, iSpan, iSampleNum, iStartRowNum, iTotalNum;
				SDWORD *  RowCountPtr = new SDWORD ;
				retcode = SQLRowCount(hstmt, RowCountPtr);						 
				iRowCount = * RowCountPtr;
				iTupleNum = iRowCount;
				iSpan = (int) (iRowCount/iSizeSmpl);
				iSampleNum = 1;
				delete RowCountPtr;
				
				for(i = 0; i <COL_NUM; i++)
						SQLBindCol(hstmt, i+1, SQL_C_DOUBLE, &fCol[i],0, &cbCol[i]); //SQL_C_SSHORT
				
				SQLBindCol(hstmt, COL_NUM+1, SQL_C_SLONG, &iColID,0, &cbColID); //SQL_C_SSHORT

				iRowCount = 0;
				iStartRowNum = 0;
				iTotalNum = 0;
				
				while (TRUE) 
				{
					//int iRandom = rand()%(iSpan-1); 
					int iRandom= 0;
					if (iSpan == 1)
						iRandom = 1;
					else 
					{
						iRandom = rand()%(iSpan-1);
					}

					for (i = iStartRowNum; i < iSampleNum + iRandom; i++)
					{
					      retcode = SQLFetch(hstmt);
						  iRowCount ++ ; 
					}

					if (retcode == SQL_ERROR)
					{
						//show_error();

						wsprintf(tmp, "%ld", iRowCount);
						//int i = iRowCount;
						//AfxMessageBox("SQLFetch Error !!!!!!");
								//break; //99.8.26
					}

					if ( (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) ||(iRowCount>= iSampleNum) )
							//if (retcode == SQL_SUCCESS)
					{	


						char c[COL_NUM+1][100];
						for(i=0; i<COL_NUM+1;i++)
							for(j=0;j<100;j++)
								c[i][j] = 0;

						for(i=0; i< COL_NUM;i++)
								sprintf(c[i],"%G",fCol[i]);

						sprintf(c[COL_NUM],"%ld",iColID);

						
						//CStrInsert += " INSERT Lsi_104D_smpl954 VALUES( ";											   						
						//CStrInsert += " INSERT Lsi_104D_B_WorkLoad VALUES( ";

						//CStrInsert += " INSERT Lsi_050D_smpl909 VALUES( ";											   						
						//CStrInsert += " INSERT Lsi_050D_smpl954 VALUES( ";											   						
						//CStrInsert += " INSERT Lsi_050D_B_WorkLoad VALUES( ";
						
						CStrInsert += " INSERT Lsi_025D_smpl833 VALUES( ";											   						
						//CStrInsert += " INSERT Lsi_025D_B_WorkLoad VALUES( ";											   						

						//CStrInsert += " INSERT House08D_B_WorkLoad VALUES( ";											   						
						//CStrInsert += " INSERT House08D_smpl701 VALUES( ";
						
						//CStrInsert += " INSERT House16D_B_WorkLoad VALUES( ";											   						
						//CStrInsert += " INSERT House16D_smpl867 VALUES( ";
						
						//CStrInsert += " INSERT House20D_B_WorkLoad VALUES( ";											   										
						//CStrInsert += " INSERT House20D_smpl910 VALUES( ";

						//CStrInsert += " INSERT House16D_20PC_WorkLoad VALUES( ";
						//CStrInsert += " INSERT House16D_50PC_WorkLoad VALUES( ";
						//CStrInsert += " INSERT House16D_80PC_WorkLoad VALUES( ";

						//CStrInsert += " INSERT Lsi_104D_20PC_WorkLoad VALUES( ";
						//CStrInsert += " INSERT Lsi_104D_50PC_WorkLoad VALUES( ";
						//CStrInsert += " INSERT Lsi_104D_80PC_WorkLoad VALUES( ";

						for(i=0; i< COL_NUM;i++)
						{
							CStrInsert += c[i];
							CStrInsert += ",";

						}							
						CStrInsert += c[COL_NUM];;
						CStrInsert += ")";
	
						int iSqlLen = CStrInsert.GetLength();

						char * szSqlInsert = new char [iSqlLen + 1];
						strcpy(szSqlInsert , "");
						strcat(szSqlInsert , CStrInsert);
							
						retcode = SQLExecDirect(hstmt_Generet2DWorkload, (unsigned char *)szSqlInsert, SQL_NTS);


						if (retcode == SQL_SUCCESS) 
						{  //	retcode = SQLExecDirect
							//AfxMessageBox("Insert new Recode Seccess!");
							//bReturn = TRUE;
							iTotalNum ++;
						}
						else
						{
						//	AfxMessageBox("Insert new Recode Error!");
							iErr++;

						} //	retcode = SQLExecDirect 
					
						CStrInsert = "";
						delete [] szSqlInsert; 

						iStartRowNum = iRowCount;
						iSampleNum += iSpan ;
					} 
					else 
					{
						break;
					}

					if(iTotalNum >=iSizeSmpl)
						break;

				}   ///while (TRUE)			

			}//	retcode = SQLExecDirect



		//111111111111111111 read data base end111111111111


		}


	//SQLFreeStmt(hstmt, SQL_DROP);
	SQLFreeStmt(hstmt_Generet2DWorkload, SQL_DROP);
	zlCloseDB();

	AfxMessageBox("Insert Lsi_smpl_Bworkload OK!");	
}

void CMainFrame::OnLsiProfileOPTworkload() 
{
	//Menu: Creat_TopNProfile --> Lsi(House)_Profile_OPTworkload //2005.04.28 	
	//2005.05.13

	long lStartTimer =0, lEndTimer =0; //2005.05.13


	//Create cover4d profile with	5810 samples
	// with distance functions: MAX, EUCL, SUM

	/*****************************
	* 1. read all tuples from : CLMB_coverD store a buffer
	* 2. Read all tuple from  : smpl5810_cover4D 
	* 3. evaluate r, f, c, -d,
	* 4. insert zeta into	  : Top100_Cover4D_Profile5810 
	******************************/
    // Change:
		//1. int iSizeSmpl
	    //2. UCHAR szSqlAllRows[] 
	    //3. CStrSelect += "select  * from Lsi_104D where (" -- 2 place
        //4. insert
	    //5. COL_NUM

	int N, f, c, d = 0; 

	int i,j, k, iErr = 0;
	char tmp[100] = "";
	CString CStrSelect = ""; 
	CString CStrInsert = "";

	int longTicks =0, shortTicks =0;
	
	double  fCol[COL_NUM+1];		//Elevation
	SDWORD cbCol[COL_NUM+1]; 
	
	SDWORD sColID =0; 
	SDWORD cbColID =0; 

	HSTMT   hstmt;  //for insert Profile

	HSTMT   hstmt_Census2D_WorkLoad; //for queries workload
	HSTMT   hstmt_Census2D_Profile;  //for insert Profile

	int iTupleNum;//,iStartRowNum, iTotalNum;

	double *pCol[COL_NUM+1]; double *pColHold[COL_NUM+1];

	double *q[COL_NUM+1]; double * qHold[COL_NUM+1];

	int iTopN = 20; // for LSI
	//int iTopN = 100; // for House

	
	//int iSizeSmpl = 833; //909; //954;  //909;  ////833; //909; //954;  //-- for LSI
	//int iSizeSmpl = 910; //867; //701; //-- for House, 20d, 16D, 08D 

	int iSizeSmpl = 100; //for OPT of workload 

	double rd, dis[2000], r[2000], x[106]; 

	if(!zlOpenDB())
	{
		AfxMessageBox("zlOpenDB() err!");
		zlCloseDB();
	}else
	{
		retcode = SQLAllocStmt(hdbc, &hstmt); ///queries Statement handle 

		retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_WorkLoad); ///queries Statement handle 
		retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_Profile); /// Profile Statement handle 

		//1. read all tuples from census2Dg store a buffer
		//1111111111111 read data base from census2Dg 111111111111111	

		//UCHAR szSqlAllRows[] = "select  * from census2dg where (15 - 9 <=age and age<=15+ 9 ) and (15- 9 <=Income and Income <=15+ 9 )";
		
		//----------------------------------------------------
		//UCHAR szSqlAllRows[] = "SELECT * FROM census2Dg"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM CLMB_census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM CLMB_census3D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM CLMB_cover4D"; //discounts, authors, Census2DTable						
		
		//UCHAR szSqlAllRows[] = "SELECT * FROM Lsi050D"; //all dataset					
		
		UCHAR szSqlAllRows[] = "SELECT * FROM Lsi_104D"; //all dataset							
		//UCHAR szSqlAllRows[] = "SELECT * FROM Lsi_050D"; //all dataset			
		//UCHAR szSqlAllRows[] = "SELECT * FROM Lsi_025D"; //all dataset
		
		//UCHAR szSqlAllRows[] = "SELECT * FROM House08D"; //all dataset					
		//UCHAR szSqlAllRows[] = "SELECT * FROM House16D"; //all dataset					
		//UCHAR szSqlAllRows[] = "SELECT * FROM House20D"; //all dataset					
		//------------------------------------------------------


		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		
		longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);
		longTicks = GetTickCount() - longTicks;

		//lEndTimer = GetTickCount() - lStartTimer;
		//wsprintf(tmp, "%ld", lEndTimer);


		if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) 
		{    //	retcode = SQLExecDirect for census2Dg
			int iRowCount;
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt, RowCountPtr);						 
			iRowCount = * RowCountPtr;
			iTupleNum = iRowCount;
			delete RowCountPtr;
			
//==================
			for(i = 0; i <COL_NUM+1; i++)
			{
				fCol[i] =0.0;
				cbCol[i] = 0; 
			}
			// Bind columns 1,2,3,4 ,.., 105
				for(i = 0; i <COL_NUM; i++)
						SQLBindCol(hstmt, i+1, SQL_C_DOUBLE, &fCol[i],0, &cbCol[i]); //SQL_C_SSHORT
				
				//SQLBindCol(hstmt, COL_NUM+1, SQL_C_SLONG, &sColID,0, &cbColID); //SQL_C_SSHORT

				
			//need COL_NUM of columns
			for(i = 0; i<COL_NUM; i++)
			{
				pCol[i] = new  double[iRowCount]; 
				pColHold[i] = pCol[i]; 
			}
			
			iRowCount =0;
			while (TRUE) 
			{
				retcode = SQLFetch(hstmt);

				if (retcode == SQL_ERROR)
				{
					//show_error();

					wsprintf(tmp, "%ld", iRowCount);
					//int i = iRowCount;
					AfxMessageBox("SQLFetch Error !!!!!!");
							//break; //99.8.26
				}

				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
						//if (retcode == SQL_SUCCESS)
				{	

					for(i = 0; i<COL_NUM; i++)
					{
						*pCol[i] = fCol[i]; 
						pCol[i]++;
					}

					if(retcode == SQL_SUCCESS_WITH_INFO)
					{
						wsprintf(tmp, "%ld", retcode);
						AfxMessageBox(tmp);

					}
						
				} 
				else 
				{
					break;
				}

			}   ///while (TRUE)

			for(i = 0; i<COL_NUM; i++)
			{
				pCol[i] = pColHold[i]; 				
			}
//================
	
		}//	retcode = SQLExecDirect  for census2Dg

	//111111111111111111 read data base  census2Dg end   111111111111

	//2. Read all tuple from smpl_DB_tables : DATA_Top100_Census2D_WorkLoad ,100 smpl
										//	  smpl2000_Census2D				 2000 smpl
		for(i = 0; i<COL_NUM; i++)
		{
			fCol[i]  = 0.0;		//Elevation
			cbCol[i] = 0; 
		}

		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Top100_Census2D_WorkLoad"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl2000_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl1000_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl0800_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl0400_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl0200_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl0100_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl0250_Census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl1459_Census2D"; //discounts, authors, Census2DTable						
		
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl1654_Census3D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM smpl5810_Cover4D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Cover4D_smpl0218"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Cover4D_smpl0436"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Cover4D_smpl0872"; //discounts, authors, Census2DTable						
	
		// UCHAR szSqlAllQueryRows[] = "SELECT * FROM Cover4D_B_workload"; //discounts, authors, Census2DTable						
		
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Lsi_104D_smpl954"; // sampling 
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Lsi_104D_B_WorkLoad"; // sampling 
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Lsi_104D_B_WorkLoad_1"; // sampling 
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Lsi_104D_B_WorkLoad_2"; // sampling 
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Lsi_104D_B_WorkLoad_3"; //2006.03.23  
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Lsi_104D_B_WorkLoad_4"; //2006.03.23  
		UCHAR szSqlAllQueryRows[] = "SELECT * FROM Lsi_104D_B_WorkLoad_5"; //2006.03.23  

		/////*****UCHAR szSqlAllQueryRows[] = "SELECT * FROM Lsi_050D_smpl954"; // sampling 
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Lsi_050D_B_WorkLoad"; // sampling 
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Lsi_050D_B_WorkLoad_2"; // 2005.07.31 
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Lsi_050D_B_WorkLoad_3"; // 2006.03.23 
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Lsi_050D_B_WorkLoad_4"; // 2006.03.23 
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Lsi_050D_B_WorkLoad_5"; // 2006.03.23 

		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Lsi_050D_smpl909"; // sampling 

		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Lsi_025D_smpl833"; // sampling 
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Lsi_025D_B_WorkLoad"; // WorkLoad 
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Lsi_025D_B_WorkLoad_1"; // WorkLoad 2005.08.02 
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Lsi_025D_B_WorkLoad_2"; // WorkLoad 2005.08.02 
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Lsi_025D_B_WorkLoad_3"; // 2006.03.23 
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Lsi_025D_B_WorkLoad_4"; // 2006.03.23
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Lsi_025D_B_WorkLoad_5"; // 2006.03.23 
	
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM House08D_B_WorkLoad"; // WorkLoad 
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM House08D_smpl701"; // sampling 
		
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM House16D_B_WorkLoad"; // WorkLoad 
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM House16D_smpl867"; // sampling 
		
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM House20D_B_WorkLoad"; // WorkLoad 
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM House20D_smpl910"; // sampling 

		SQLSetStmtOption(hstmt_Census2D_WorkLoad, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt_Census2D_WorkLoad, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		retcode = SQLExecDirect(hstmt_Census2D_WorkLoad, szSqlAllQueryRows, SQL_NTS);

		if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) 
		{    //	retcode = SQLExecDirect for census2Dg
			int iRowCount;
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt_Census2D_WorkLoad, RowCountPtr);						 
			iRowCount = * RowCountPtr;
			delete RowCountPtr;
			
			// Bind columns 1,2,3,4, 104
			for(i = 0; i < COL_NUM; i++)
				SQLBindCol(hstmt_Census2D_WorkLoad, i+1, SQL_C_DOUBLE, &fCol[i],0, &cbCol[i]); //SQL_C_SSHORT
		
			for(i = 0; i < COL_NUM; i++)
			{
				q[i] = new  double[iRowCount];//buffer, new float[10]
				qHold[i] = q[i]; 
			}
		

			while (TRUE) 
			{
				retcode = SQLFetch(hstmt_Census2D_WorkLoad);

				if (retcode == SQL_ERROR)
				{
					//show_error();

					wsprintf(tmp, "%ld", iRowCount);
					//int i = iRowCount;
					AfxMessageBox("SQLFetch Error !!!!!!");
							//break; //99.8.26
				}

				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
						//if (retcode == SQL_SUCCESS)
				{	
					for(i = 0; i < COL_NUM; i++)
					{
						*q[i] =  fCol[i];//buffer, new float[10]
						 q[i]++; 
					}
					
				} 
				else 
				{
					break;
				}

			}   ///while (TRUE)

			for(i = 0; i < COL_NUM; i++)
			{
				q[i]=qHold[i]; 
			}
							
		}//	retcode = SQLExecDirect  for query q1,q2.
	
	//3. evaluate r, f, -c, -d,

		double ftmp=0;
		int qnum =0; 
		//int topt1[1000],topt2[1000],topt3[1000],topt4[1000];
		double topt[COL_NUM][1000];
		//int itmp = 0;
		double ftemp =0.0;
		
//////////////////
		SQLFreeStmt(hstmt, SQL_DROP);
		retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 
		
		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		
		longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);
		longTicks = GetTickCount() - longTicks;
//////////////////////////
		
		do
		{
//gotoid: //2005.05.13
			lStartTimer = GetTickCount(); //2005.05.13

			//take first 100 as Top100
			for(i = 0; i<iTopN; i++)
			{
			  for(j = 0; j<COL_NUM; j++)
				x[j]= fabs(pCol[j][i]- q[j][qnum]);

			/**********

			  //----for Max distance, Linf
			  dis[i] = x[0];
			  for(j = 1; j<COL_NUM; j++)
				dis[i] = (double)__max(dis[i], x[j]);
			**********/

			//**********
			  //----for Eucl distance, L2
			  dis[i] = x[0]*x[0];
		 	  for(j = 1; j<COL_NUM; j++)
				dis[i] += x[j]*x[j];
			  dis[i] = sqrt( dis[i] );

			//**********/

			/**********
			  //---for Sum distance, L1
			  dis[i] = x[0];
		 	  for(j = 1; j<COL_NUM; j++)
				dis[i] += x[j];

			  **********/

			  //------- assing values -
			  for(j = 0; j<COL_NUM; j++)
				 tuple[j][i] = pCol[j][i];

			}
			i=0;

			//sorting the first 100 tuples
			//for(i=0; i<100; i++), 
			for(i=0; i<iTopN; i++)
			{
				r[i] = dis[i];
				for(int k = 0; k<COL_NUM; k++)
					topt[k][i] = tuple[k][i];

				for( j= i+1; j<iTopN; j++)
				{
					if(dis[j] < r[i]) 
					{ 
						ftmp = r[i];    r[i] = dis[j];  dis[j] = ftmp;
						for(int k = 0; k<COL_NUM; k++)
						{
							ftemp = topt[k][i]; topt[k][i]= tuple[k][j]; tuple[k][j]= ftemp;
						}

					}
				}
			}
			
			i=0;

			//2. select TopN tuples from all tuples with size iTupleNum
			
			//lStartTimer = GetTickCount(); //2005.05.13

			for(i = iTopN; i<iTupleNum; i++)
			{
			  	for(j = 0; j<COL_NUM; j++)
					x[j]= fabs(pCol[j][i]- q[j][qnum]);

				/****************

				  //----for Max distance, Linf
				  ftmp = x[0];
				  for(j = 1; j<COL_NUM; j++)
					ftmp = (double)__max(ftmp, x[j]);
				**************/

				///****************
				  //----for Eucl distance, L2
				  ftmp = x[0]*x[0];
		 		  for(j = 1; j<COL_NUM; j++)
					ftmp += x[j]*x[j];
				  ftmp = sqrt( ftmp );
				//**************/

				/****************
				  //---for Sum distance, L1
				 ftmp = x[0];
		 		  for(j = 1; j<COL_NUM; j++)
					ftmp += x[j];
				**************/


				if(ftmp < r[iTopN - 1])		
				{
					for(j=0;j<iTopN;j++)
					{
						if(ftmp<r[j])
						{
							for(k=iTopN - 1; k>j; k--)
							{
								r[k] = r[k-1];
								for(int l=0; l < COL_NUM; l++)
									topt[l][k] = topt[l][k-1];
							}
							r[j]=ftmp;
							for(int l=0; l < COL_NUM; l++)
								topt[l][j] = pCol[l][i];
							break;
						}
					}
				}
			}
		
			lEndTimer = GetTickCount() -lStartTimer ;

         ////--------2004.5.10 ------ 
			/*
			char temp[1024] = "";
			sprintf(temp, " qnum = %d, lEndTimer = %d",qnum, lEndTimer); 
			AfxMessageBox(temp);
			qnum++;
			if(qnum >=iSizeSmpl )
				break;
			goto gotoid;	
			*/
			////-- Finding Top20 Tuples from all size of LSI_104D (20000), using time:
			////-- lEndTimer == 156, 157, or 172
			////-- Finding Top20 Tuples from all size of LSI_104D (600), using time:
			////-- lEndTimer == 15, 16, or 0
			
         /// --------- 2004.5.10 ---------





		//int N, rd,f, c, d; 	
			
//////////////////
			/***
		SQLFreeStmt(hstmt, SQL_DROP);
		retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 
		
		//UCHAR szSqlAllRows[] = "SELECT * FROM census2Dg"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM CLMB_census2D"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRows[] = "SELECT * FROM CLMB_Cover4D"; //all dataset
		
		UCHAR szSqlAllRows[] = "SELECT * FROM Lsi104D"; //all dataset

		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		
		longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);
		longTicks = GetTickCount() - longTicks;
		**********/
//////////////////////////
													
			CTime CurTime = CTime::GetCurrentTime();         

			//N = 100; rd = r[99]; //r[99] means the distance from last_tuple (top100) to the query
			N = iTopN; 
			
			//rd = r[iTopN-1]; //r[99] means the distance from last_tuple (top100) to the query
		
			c = -1; d--; //d = - CurTime.GetTime(); d++;
			
			ftmp = 0;
			for(i = 0; i<iTopN; i++)
			{
				
				for(j = 0; j<COL_NUM; j++)
					x[j]= fabs(topt[j][i]- q[j][qnum]);

				  //----for Max distance, only this distance 
				  ftmp = x[0];
				  for(j = 1; j<COL_NUM; j++)
					ftmp = (double)__max(ftmp, x[j]);

				dis[i] =(double)ftmp;
				ftmp = 0;
			}
			
			//find the square's radius, which is the max of all distance from Q to top-N tuples
			rd = dis[0];			
			for( j= 1; j<iTopN; j++)
			{
				if(dis[j] > rd) 
				{ 
					ftmp = rd; rd = dis[j];  dis[j] = ftmp;
				}
			}
			

			// test for max distance	
			if(rd != r[iTopN-1])
				int iosj=0;


			char cLeft[COL_NUM][50] , cRight[COL_NUM][50] , cAttr[COL_NUM][50] ;

			for(i=0; i<COL_NUM; i++)
				for(j=0; j<50; j++)
				{
					cLeft[i][j]		=0;
					cRight[i][j]	=0;
					cAttr[i][j]		=0;
				}

			for(i=0; i<COL_NUM; i++)
			{
				
				sprintf(cLeft[i],	"%.15G",	  (q[i][qnum] - rd)		);
				sprintf(cRight[i],	"%.15G",	  (q[i][qnum] + rd)	    );
				//sprintf(cLeft[i],		"%.15f",	  (q[i][qnum] - rd)		);
				//sprintf(cRight[i],	"%.15f",	  (q[i][qnum] + rd)	    );
			
				sprintf(cAttr[i],    "<= attr%d AND attr%d <=",            i,i  );
			}

			//CStrSelect += "select  * from census2dg where (";
			
			CStrSelect += "select  * from Lsi_104D where (";			
			//CStrSelect += "select  * from Lsi_050D where (";
			//CStrSelect += "select  * from Lsi_025D where (";

			//CStrSelect += "select  * from House08D where (";
			//CStrSelect += "select  * from House16D where (";
			//CStrSelect += "select  * from House20D where (";
		
			CStrSelect += cLeft[0];
			CStrSelect += "<= attr0 AND attr0 <=";
			CStrSelect += cRight[0];

			for(i=1; i<COL_NUM; i++)
			{
				CStrSelect += ") AND (";
				CStrSelect += cLeft[i];
				CStrSelect += cAttr[i];
				CStrSelect += cRight[i];
			}

			CStrSelect += ")"; 


			int iSqlLen = CStrSelect.GetLength();
			char * szSqlSquareRows = new char [iSqlLen + 1];	
			strcpy(szSqlSquareRows , "");
			strcat(szSqlSquareRows , CStrSelect);
	
			SQLFreeStmt(hstmt, SQL_DROP);
			retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 


			SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
			SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
			
			shortTicks = GetTickCount();
			retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlSquareRows, SQL_NTS);
			shortTicks = GetTickCount() - shortTicks;

			if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) 
			{    //	retcode = SQLExecDirect for census2Dg
				SDWORD *  RowCountPtr = new SDWORD ;
				retcode = SQLRowCount(hstmt, RowCountPtr);						 
				f = * RowCountPtr;
				delete RowCountPtr;
			}

			CStrSelect = "";
			delete [] szSqlSquareRows;

			if(f<iTopN )  // correct N-1, no useful
			{
				for(i=0; i<COL_NUM; i++)
					for(j=0; j<50; j++)
				{
					cLeft[i][j]		=0;
					cRight[i][j]	=0;
					cAttr[i][j]		=0;	
				}

			////----------
			   int  decimal, sign;
			   char *buffer;
			   double source = -1.234567E-38;//= q[0][qnum] - rd;
			   double dL=0, dR=0;
			   char cttt[1000] = "";
			   buffer = _fcvt( source, 17, &decimal, &sign );
			  
			   sprintf( cttt, "source: %2.10f   buffer: '%s'   decimal: %d   sign: %d\n",
						source, buffer, decimal, sign );

				for(i=0; i<COL_NUM; i++)
				{	
				/*********
					source = q[i][qnum] - rd;
					buffer = _fcvt( source, 17, &decimal, &sign );
					dL = 0.00001*pow(10,decimal-1);

					source = q[i][qnum] + rd;
					buffer = _fcvt( source, 17, &decimal, &sign );
					dR = 0.00001*pow(10,decimal-1);

					///left
					dL = q[i][qnum] - rd - dL;
					sprintf(cLeft[i],		"%G",	  dL);

					///right
					dR = q[i][qnum] + rd + dR;
					sprintf(cRight[i],		"%G",	  dR);
					**********/

					source = q[i][qnum] - rd;
					buffer = _fcvt( source, 17, &decimal, &sign );
					dL = 0.00001*pow(10,decimal-1);

					source = q[i][qnum] + rd;
					buffer = _fcvt( source, 17, &decimal, &sign );
					dR = 0.00001*pow(10,decimal-1);

  					rd = rd + __max(dL,dR);
					///left
					dL = q[i][qnum] - rd;
					sprintf(cLeft[i],		"%.15G",	  dL);

					///right
					dR = q[i][qnum] + rd;
					sprintf(cRight[i],		"%.15G",	  dR);

					//atttribute
					sprintf(cAttr[i],   "<= attr%d AND attr%d <=", i,i );

				}

				CStrSelect += "select  * from Lsi_104D where (";
				//CStrSelect += "select  * from Lsi_050D where (";
				//CStrSelect += "select  * from Lsi_025D where (";
			
				//CStrSelect += "select  * from House08D where (";
				//CStrSelect += "select  * from House16D where (";
				//CStrSelect += "select  * from House20D where (";
		
				CStrSelect += cLeft[0];
				CStrSelect += "<= attr0 AND attr0 <=";
				CStrSelect += cRight[0];

				for(i=1; i<COL_NUM; i++)
				{
					CStrSelect += ") AND (";
					CStrSelect += cLeft[i];
					CStrSelect += cAttr[i];
					CStrSelect += cRight[i];
				}

				CStrSelect += ")"; 

				int iSqlLen = CStrSelect.GetLength();
				char * szSqlSquareRows = new char [iSqlLen + 1];	
				strcpy(szSqlSquareRows , "");
				strcat(szSqlSquareRows , CStrSelect);
		
				SQLFreeStmt(hstmt, SQL_DROP);
				retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 


				SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
				SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
				
				////!!!
				shortTicks = GetTickCount();
				//lStartTimer = GetTickCount();
				   retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlSquareRows, SQL_NTS);
				shortTicks = GetTickCount() - shortTicks;
				//shortTicks = GetTickCount() - lStartTimer;		
				////!!!
				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) 
				{    //	retcode = SQLExecDirect for census2Dg
					SDWORD *  RowCountPtr = new SDWORD ;
					retcode = SQLRowCount(hstmt, RowCountPtr);						 
					f = * RowCountPtr;
					delete RowCountPtr;
				}

				CStrSelect = "";
				delete [] szSqlSquareRows;

			} //if(f<iTopN )

			//---test
			if(f<iTopN)
				int isj= 0;

	//4. insert zeta into the Profiles: DATA_Top100_Census2D_Profile
									//	Top100_Census2D_Profile2000
									// Top100_Census3D_Profile1654
		
			if (f!= 0)
			{   
				char	cAttribute[COL_NUM+7][50];
				for(i=0; i<COL_NUM + 7; i++)
					for(j=0; j< 50; j++)
						cAttribute[i][j]=0;

				for(i=0; i<COL_NUM ; i++)
					sprintf(cAttribute[i],	"%.15G", q[i][qnum] );


				sprintf(cAttribute[COL_NUM],  "%ld", N);
				sprintf(cAttribute[COL_NUM+1],"%.15G",  rd);
				sprintf(cAttribute[COL_NUM+2],"%ld", f );
				sprintf(cAttribute[COL_NUM+3],"%ld", c );
				sprintf(cAttribute[COL_NUM+4],"%ld", d);
				sprintf(cAttribute[COL_NUM+5],"%ld", longTicks);
				sprintf(cAttribute[COL_NUM+6],"%ld", shortTicks);

				//---------tables---------------
				//CStrInsert += " INSERT Cover4D_Top100_Profile0872 VALUES( ";	
				
				//CStrInsert += " INSERT Cover4D_T0100_OPT VALUES( ";	
				
				//CStrInsert += " INSERT Lsi104D_Top100_Profile972 VALUES( ";	
			
				//CStrInsert += " INSERT Lsi_104D_Top20_Profile954 VALUES( ";	
				//CStrInsert += " INSERT Lsi_104D_Top20_B_OPT VALUES( ";	
				//CStrInsert += " INSERT Lsi_104D_Top20_B_OPT_1 VALUES( ";	
				//CStrInsert += " INSERT Lsi_104D_Top20_B_OPT_2 VALUES( ";	
				//CStrInsert += " INSERT Lsi_104D_Top20_B_OPT_3 VALUES( ";	//2006.03.23
				//CStrInsert += " INSERT Lsi_104D_Top20_B_OPT_4 VALUES( ";	//2006.03.23
				CStrInsert += " INSERT Lsi_104D_Top20_B_OPT_5 VALUES( ";	//2006.03.23

				//CStrInsert += " INSERT Lsi_050D_Top20_Profile954 VALUES( ";	
				//CStrInsert += " INSERT Lsi_050D_Top20_B_OPT VALUES( ";	
				//CStrInsert += " INSERT Lsi_050D_Top20_B_OPT_2 VALUES( "; //2005.07.31	
				//CStrInsert += " INSERT Lsi_050D_Top20_B_OPT_3 VALUES( "; //2006.03.23
				//CStrInsert += " INSERT Lsi_050D_Top20_B_OPT_4 VALUES( "; //2006.03.23
				//CStrInsert += " INSERT Lsi_050D_Top20_B_OPT_5 VALUES( "; //2006.03.23
			
				//CStrInsert += " INSERT Lsi_050D_Top20_Profile909 VALUES( ";	
				//CStrInsert += " INSERT Lsi_050D_Top20_Profile909_L1 VALUES( ";	
				//CStrInsert += " INSERT Lsi_050D_Top20_Profile909_Linf VALUES( ";	
				
				//CStrInsert += " INSERT Lsi_050D_Top20_B_OPT_Linf VALUES( ";	
				//CStrInsert += " INSERT Lsi_050D_Top20_B_OPT_L1 VALUES( ";	
				
				//CStrInsert += " INSERT Lsi_025D_Top20Profile833 VALUES( ";	
				//CStrInsert += " INSERT Lsi_025D_Top20_Profile833 VALUES( ";	//2005.08.02

				//CStrInsert += " INSERT Lsi_025D_Top20_B_OPT VALUES( ";	
				//CStrInsert += " INSERT Lsi_025D_Top20_B_OPT_1 VALUES( ";	
				//CStrInsert += " INSERT Lsi_025D_Top20_B_OPT_2 VALUES( ";	 //
				//CStrInsert += " INSERT Lsi_025D_Top20_B_OPT_3 VALUES( ";	 //2006.03.23
				//CStrInsert += " INSERT Lsi_025D_Top20_B_OPT_4 VALUES( ";	 //2006.03.23
				//CStrInsert += " INSERT Lsi_025D_Top20_B_OPT_5 VALUES( ";	 //2006.03.23
				
				//CStrInsert += " INSERT House08D_Top100_B_OPT VALUES( ";	
				//CStrInsert += " INSERT House08D_Top100_Profile701 VALUES( ";	
				//CStrInsert += " INSERT House16D_Top100_B_OPT VALUES( ";	
				//CStrInsert += " INSERT House16D_Top100_Profile867 VALUES( ";	
				//CStrInsert += " INSERT House20D_Top100_B_OPT VALUES( ";	
				//CStrInsert += " INSERT House20D_Top100_Profile910 VALUES( ";	

				for(i=0; i< COL_NUM+7-1; i++)
				{
					CStrInsert += cAttribute[i];
					CStrInsert += ",";
				}
				CStrInsert += cAttribute[COL_NUM+7-1];
				CStrInsert += ")";


			    int iSqlLen = CStrInsert.GetLength();

				char * szSqlInsert = new char [iSqlLen + 1];
				strcpy(szSqlInsert , "");
				strcat(szSqlInsert , CStrInsert);

				SQLFreeStmt(hstmt_Census2D_Profile, SQL_DROP);
				retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_Profile); /// Profile Statement handle 
				
				SQLSetStmtOption(hstmt_Census2D_Profile, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
				SQLSetStmtOption(hstmt_Census2D_Profile, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
				

				retcode = SQLExecDirect(hstmt_Census2D_Profile, (unsigned char *)szSqlInsert, SQL_NTS);

				if (retcode == SQL_SUCCESS) 
				{  //	retcode = SQLExecDirect
					//AfxMessageBox("Insert new hstmt_Census2D_Profile  OKKKKKKKKKKK!");
					//Sleep(200);
						//bReturn = TRUE;
				}
				else
				{
					AfxMessageBox("Insert hstmt_Census2D_Profile Error!");
					i= 0;

				} //	retcode = SQLExecDirect 
				
				f=0;

				CStrInsert = "";
				delete [] szSqlInsert;
			}
		

			qnum++;
		}while(qnum <iSizeSmpl); //100);

	}//if(!zlOpenDB())


	for (i=0; i< COL_NUM; i++)
	{
		delete [] pCol[i];//new float[10]
		delete [] q[i];//new float[10]
	}

	//SQLFreeStmt(hstmt, SQL_DROP);
	SQLFreeStmt(hstmt_Census2D_WorkLoad, SQL_DROP);
	SQLFreeStmt(hstmt_Census2D_Profile, SQL_DROP);

	zlCloseDB();

	AfxMessageBox("Insert hstmt_Generet2D_profile OK!");
}


void CMainFrame::OnLsi104DLearning() 
{
	//Menu: Learning --> Lsi104D(House)_Learning(50,25) 
	//2005.5.13
   // Change: 
		// 1. At the start of  this body: 0,1,2,3,4
		// 2. COL_NUM
		// 3. int iTopN = 20;

	int N, f = 0, c =0, d = 0; 

	int i,j, iErr = 0;
	char tmp[100] = "";
	CString CStrSelect = "", CStrSelectHead = ""; 
	//CString CStrSelect1 = "", CStrSelect1Head = ""; 

	
	CString CStrInsert = "", CStrInsertHead = "";

	int longTicks =0, shortTicks =0;
	int f_rst= 0, shortTicks_rst = 0; //2003/4/5

	double  fCol[COL_NUM+1];		//Elevation
	SDWORD cbCol[COL_NUM+1]; 

	SDWORD sN,		sf,sc,sd;
	SDWORD cbN,cbr,cbf,cbc,cbd;
	double		sr;

	HSTMT   hstmt_Census2D_WorkLoad; //for queries workload
	HSTMT   hstmt_Census2D_Profile;  //for insert Profile

	//int iTupleNum;//,iStartRowNum, iTotalNum;

	int iTupleNum = 0;//,iStartRowNum, iTotalNum;

	double *pCol[COL_NUM+1]; double *pColHold[COL_NUM+1];

	double *q[COL_NUM+1];	 double * qHold[COL_NUM+1];
	
	double rd =0.0, dis[2000], r[2000];  //rd is the final radius distance of Q; dis[]= d(Q,Q'), r[] id dis[];
	//int tuple1[2000],tuple2[2000],tuple3[2000],tuple4[2000];

	double rr[2000],rOrder[2000]; 
	double x[106];

	//int iSizeProfile = 872; //436; //218;	 //for Gauss
	//int iSizeProfile = 872; //436; //218;	 //for Array
	int iSizeProfile = 0, iSizeWorkLoad =0;  //  will be assigned in the following

	//int iTopN = 20; //--for Lsi
	int iTopN = 100; //--for House, Census 2,3D, Gauss3D, Array3D
	
	/////int iTopN = 100; //1000; //250; //50; //1000; //250; //50; //100; //--for  Census 2,3D, Gauss3D,Arr3D, cov4D
	/////int iTopN = 1000; //250; //50;  //--for  Census 2,3D, Gauss3D,Arr3D, cov4D

	int iInsertOK = 0, iInsertERR = 0, irderr = 0;
	int iQryInx =0;  //2005.4.7 Query Index for RstLng[iQryInx]

	//--------0  select knowledge from KB Profile 
	///////***UCHAR szSqlAllRows[] = "SELECT * FROM Lsi104D_Top100_Profile972"; //Lsi 	
	///////***UCHAR szSqlAllRows[] = "SELECT * FROM Lsi_050D_Top20_Profile954"; //Lsi 
	//***UCHAR szSqlAllRows[] = "SELECT * FROM Array3D_Top100_Profile0436"; //Array3D	
	//***UCHAR szSqlAllRows[] = "SELECT * FROM Array3D_Top100_Profile0872"; //Array3D	

	//UCHAR szSqlAllRows[] = "SELECT * FROM Array3D_Top100_Profile0218"; //Array3D	
	
	//UCHAR szSqlAllRows[] = "SELECT * FROM Lsi_104D_Top20_Profile954"; //Lsi 

	//UCHAR szSqlAllRows[] = "SELECT * FROM Lsi_050D_Top20_Profile909"; //Lsi 
	//UCHAR szSqlAllRows[] = "SELECT * FROM Lsi_050D_Top20_Profile909_L1"; //Lsi 
	//UCHAR szSqlAllRows[] = "SELECT * FROM Lsi_050D_Top20_Profile909_Linf"; //Lsi 
	
	//////UCHAR szSqlAllRows[] = "SELECT * FROM Lsi_025D_Top20Profile833"; //Lsi 25dim 
	//UCHAR szSqlAllRows[] = "SELECT * FROM Lsi_025D_Top20_Profile833"; //2005.08.02
	
	//UCHAR szSqlAllRows[] = "SELECT * FROM House08D_Top100_Profile701"; //House 8dim 
	//UCHAR szSqlAllRows[] = "SELECT * FROM House16D_Top100_Profile867"; //House 16dim 
	//UCHAR szSqlAllRows[] = "SELECT * FROM House20D_Top100_Profile910"; //House 16dim 
	
	//UCHAR szSqlAllRows[] = "SELECT * FROM Census2D_Top100_Profile0178"; //census 2dim 
	//UCHAR szSqlAllRows[] = "SELECT * FROM Census2D_Top100_Profile0178"; ////2005.08.07 
											   
	//UCHAR szSqlAllRows[] = "SELECT * FROM Census2D_Top100_P0178_EUCL"; //census 2dim 
	//UCHAR szSqlAllRows[] = "SELECT * FROM Census2D_Top100_P0178_SUM"; //census 2dim 
	//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile0100"; //census 2dim 
	//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile0200"; //census 2dim 
	//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census2D_Profile2000"; //census 2dim 
	
	//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census3D_Profile0218"; //census 3dim 	
	//UCHAR szSqlAllRows[] = "SELECT * FROM Census3D_P0218_EUCL"; //
	//UCHAR szSqlAllRows[] = "SELECT * FROM Census3D_P0218_SUM"; //
	UCHAR szSqlAllRows[] = "SELECT * FROM Census3D_Top100_Profile0218"; //2005.08.06

	//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Gauss3D_Profile0218"; //
	//UCHAR szSqlAllRows[] = "SELECT * FROM Gauss3D_T0100_U_P0218"; //	
	//UCHAR szSqlAllRows[] = "SELECT * FROM Gauss3D_P0218_EUCL"; //
	//UCHAR szSqlAllRows[] = "SELECT * FROM Gauss3D_P0218_SUM"; //
	//UCHAR szSqlAllRows[] = "SELECT * FROM Gauss3D_Top100_Profile0218"; //2006.03.23 Gauss3D_Top100_Profile0218
										  
	//UCHAR szSqlAllRows[] = "SELECT * FROM Array3D_Top100_Profile0218"; //
	//UCHAR szSqlAllRows[] = "SELECT * FROM Array3D_P0218_EUCL"; //
	//UCHAR szSqlAllRows[] = "SELECT * FROM Array3D_P0218_SUM"; //
	//UCHAR szSqlAllRows[] = "SELECT * FROM Array3D_Top100_Profile0218"; //2005.08.06



	//UCHAR szSqlAllRows[] = "SELECT * FROM Cover4D_Top100_Profile0250"; //
	//UCHAR szSqlAllRows[] = "SELECT * FROM Cover4D_Top100_P0250_EUCL"; //
	//UCHAR szSqlAllRows[] = "SELECT * FROM Cover4D_Top100_P0250_SUM"; //
	

	//----------1	  select queris from Workload								  
	
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Cover4D_B_workload"; //Array workload						
	
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Lsi_104D_B_WorkLoad"; //Lsi workload						
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Lsi_104D_B_WorkLoad_1"; //Lsi workload						
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Lsi_104D_B_WorkLoad_2"; //Lsi workload						
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Lsi_104D_B_WorkLoad_3"; //Lsi workload						
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Lsi_104D_B_WorkLoad_4"; //Lsi workload						
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Lsi_104D_B_WorkLoad_5"; //Lsi workload						
	
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Lsi_050D_B_WorkLoad"; //Lsi workload						
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Lsi_050D_B_WorkLoad_2"; //Lsi workload						
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Lsi_050D_B_WorkLoad_3"; //Lsi workload						
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Lsi_050D_B_WorkLoad_4"; //Lsi workload						
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Lsi_050D_B_WorkLoad_5"; //Lsi workload						
	
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Lsi_025D_B_WorkLoad"; //Lsi workload						
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Lsi_025D_B_WorkLoad_1"; //Lsi workload						
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Lsi_025D_B_WorkLoad_2"; //Lsi workload						
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Lsi_025D_B_WorkLoad_3"; //2006.03.23						
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Lsi_025D_B_WorkLoad_4"; //Lsi workload						
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Lsi_025D_B_WorkLoad_5"; //Lsi workload						
	
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM House08D_B_WorkLoad"; //House workload						
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM House16D_B_WorkLoad"; //House workload						
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM House20D_B_WorkLoad"; //House workload						

	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Census2Dg_B_workload"; //census2D workload						
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Census2Dg_U_workload"; //census2D workload						
	
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Census3Dg_B_workload"; //census workload						
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Census3D_U_WorkLoad"; //census workload						
	
	//--2005.08.07
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Census3D_B_WorkLoad"; //2005.08.07				
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Census3D_B_WorkLoad_1"; //2005.08.07				
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Census3D_B_WorkLoad_2"; //2005.08.07				
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Census3D_B_WorkLoad_3"; //2006.03.23				
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Census3D_B_WorkLoad_4"; //2006.03.23				
	UCHAR szSqlAllQueryRows[] = "SELECT * FROM Census3D_B_WorkLoad_5"; //2006.03.23				
	
	//2005.08.07 @@@@		
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Census2D_B_WorkLoad"; //2005.08.07				
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Census2D_B_WorkLoad_1"; //2005.08.07				
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Census2D_B_WorkLoad_2"; //2005.08.07				
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Census2D_B_WorkLoad_3"; //2006.03.26				
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Census2D_B_WorkLoad_4"; //2006.03.26		
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Census2D_B_WorkLoad_5"; //2006.03.26				
	
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Gauss3D_B_workload"; //Gauss workload						
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Gauss3D_U_WorkLoad"; //Gauss workload						

	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Gauss3D_B_WorkLoad"; //2005.08.03				
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Gauss3D_B_WorkLoad_1"; //2005.08.03				
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Gauss3D_B_WorkLoad_2"; //2005.08.03					
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Gauss3D_B_WorkLoad_3"; //2006.03.23				
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Gauss3D_B_WorkLoad_4"; //2006.03.23				
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Gauss3D_B_WorkLoad_5"; //2006.03.23				
	
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Array3Dg_B_workload"; //census workload						
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Array3D_U_WorkLoad"; //census workload						
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Array3D_B_WorkLoad"; //2005.08.03				
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Array3D_B_WorkLoad_1"; //2005.08.03				
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Array3D_B_WorkLoad_2"; //2005.08.03				
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Array3D_B_WorkLoad_3"; //2006.03.23				
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Array3D_B_WorkLoad_4"; //2006.03.23				
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Array3D_B_WorkLoad_5"; //2006.03.23				

	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Cover4D_B_WorkLoad"; //Cover4D_B_WorkLoad					
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Cover4D_B_WorkLoad_1"; //2005.08.04					
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Cover4D_B_WorkLoad_2"; //2005.08.04					
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Cover4D_B_WorkLoad_3"; //2006.03.26					
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Cover4D_B_WorkLoad_4"; //2006.03.26					
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Cover4D_B_WorkLoad_5"; //2006.03.26					
	
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Cover4D_U_WorkLoad"; //Cover4D_U_WorkLoad	
	
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Census2D_20PC_workload"; //census workload						
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Census2D_50PC_workload"; //census workload						
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Census2D_80PC_workload"; //census workload						
	
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM House16D_20PC_WorkLoad"; //hOUSE 16 workload						
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM House16D_50PC_WorkLoad"; //hOUSE 16 workload						
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM House16D_80PC_WorkLoad"; //hOUSE 16 workload						
	
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Lsi_104D_20PC_WorkLoad"; //LSI 104 workload						
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Lsi_104D_50PC_WorkLoad"; //LSI 104 workload						
	//UCHAR szSqlAllQueryRows[] = "SELECT * FROM Lsi_104D_80PC_WorkLoad"; //LSI 104 workload						

	
	//----------2 select all tuples FROM  entire Table 
	
	//UCHAR szSqlAllRowsFrmcensus2D[] = "SELECT * FROM CLMB_cover4D"; //			
	
	//UCHAR szSqlAllRowsFrmcensus2D[] = "SELECT * FROM Lsi_104D"; //Lsi104D				
	//UCHAR szSqlAllRowsFrmcensus2D[] = "SELECT * FROM Lsi_050D"; //Lsi50D				
	//UCHAR szSqlAllRowsFrmcensus2D[] = "SELECT * FROM Lsi_025D"; //Lsi25D				
	
	//UCHAR szSqlAllRowsFrmcensus2D[] = "SELECT * FROM House08D"; //House 8d
	//UCHAR szSqlAllRowsFrmcensus2D[] = "SELECT * FROM House16D"; //House 16d
	//UCHAR szSqlAllRowsFrmcensus2D[] = "SELECT * FROM House20D"; //House 8d
	
	//UCHAR szSqlAllRowsFrmcensus2D[] = "SELECT * FROM ATTR_Census2D"; //Census2d
	UCHAR szSqlAllRowsFrmcensus2D[] = "SELECT * FROM ATTR_Census3D"; //census3d
	//UCHAR szSqlAllRowsFrmcensus2D[] = "SELECT * FROM ATTR_Gauss3D"; //	
	//UCHAR szSqlAllRowsFrmcensus2D[] = "SELECT * FROM ATTR_Array3D"; //

	//UCHAR szSqlAllRowsFrmcensus2D[] = "SELECT * FROM ATTR_Cover4D"; //
	
	//-------------3 select f (the frequence in n-square)	
	
	//CStrSelectHead += "select  * from Lsi_104D where (";
	//CStrSelectHead += "select  * from Lsi_050D where (";
	//CStrSelectHead += "select  * from Lsi_025D where (";

	//CStrSelectHead += "select  * from House08D where (";
	//CStrSelectHead += "select  * from House16D where (";
	//CStrSelectHead += "select  * from House20D where (";
	
	//CStrSelectHead += "select  * from ATTR_Gauss3D where (";
	//CStrSelectHead += "select  * from ATTR_Array3D where (";	
	//CStrSelectHead += "select  * from ATTR_Census2D where (";	
	CStrSelectHead += "select  * from ATTR_Census3D where (";
	//CStrSelectHead += "select  * from ATTR_Cover4D where (";
	
	//---------------4 Insert the results into the table
	//CStrInsertHead += " INSERT Array3D_T0100_B_Learning_P0218 VALUES( ";   // Array3D
	//CStrInsertHead += " INSERT Array3D_T0100_B_Learning_P0436 VALUES( ";
	
	//////**** CStrInsertHead += " INSERT Lsi104D_T0100_B_Learning_P0972 VALUES( ";
	//CStrInsertHead += " INSERT Lsi_104D_T0020_B_Learning_P0954 VALUES( ";	
	//CStrInsertHead += " INSERT Lsi_104D_T0020_B_Learning_P0954_1 VALUES( ";	
	//CStrInsertHead += " INSERT Lsi_104D_T0020_B_Learning_P0954_2 VALUES( ";	
	//CStrInsertHead += " INSERT Lsi_104D_T0020_B_Learning_P0954_3 VALUES( ";	
	//CStrInsertHead += " INSERT Lsi_104D_T0020_B_Learning_P0954_4 VALUES( ";	
	//CStrInsertHead += " INSERT Lsi_104D_T0020_B_Learning_P0954_5 VALUES( ";	
	
	//////**** CStrInsertHead += " INSERT Lsi_050D_T0020_B_Learning_P0954 VALUES( ";
	//CStrInsertHead += " INSERT Lsi_050D_T0020_B_Learning_P0909 VALUES( ";
	//CStrInsertHead += " INSERT Lsi_050D_T0020_B_Learning_P0909_2 VALUES( ";
	//CStrInsertHead += " INSERT Lsi_050D_T0020_B_Learning_P0909_3 VALUES( ";
	//CStrInsertHead += " INSERT Lsi_050D_T0020_B_Learning_P0909_4 VALUES( ";
	//CStrInsertHead += " INSERT Lsi_050D_T0020_B_Learning_P0909_5 VALUES( ";

	//CStrInsertHead += " INSERT Lsi_050D_T0020_B_Learning_P0909_L1 VALUES( ";
	//CStrInsertHead += " INSERT Lsi_050D_T0020_B_Learning_P0909_Linf VALUES( ";	
	//CStrInsertHead += " INSERT Lsi_025D_T0020_B_Learning_P0833 VALUES( ";
	//CStrInsertHead += " INSERT Lsi_025D_T0020_B_Learning_P0833_1 VALUES( ";
	//CStrInsertHead += " INSERT Lsi_025D_T0020_B_Learning_P0833_2 VALUES( ";
	//CStrInsertHead += " INSERT Lsi_025D_T0020_B_Learning_P0833_3 VALUES( ";
	//CStrInsertHead += " INSERT Lsi_025D_T0020_B_Learning_P0833_4 VALUES( ";
	//CStrInsertHead += " INSERT Lsi_025D_T0020_B_Learning_P0833_5 VALUES( ";

	
	//CStrInsertHead += " INSERT House08D_Top100_B_Learning_P0701 VALUES( ";
	//CStrInsertHead += " INSERT House16D_Top100_B_Learning_P0867 VALUES( ";
	//CStrInsertHead += " INSERT House20D_Top100_B_Learning_P0910 VALUES( ";

	//CStrInsertHead += " INSERT Census2D_T0100_U_Learning_P0178 VALUES( ";
	//CStrInsertHead += " INSERT Census2D_T0100_B_Learning_P0178 VALUES( ";
	//CStrInsertHead += " INSERT Census2D_T0100_B_Lng_P0178_EUCL VALUES( ";
	//CStrInsertHead += " INSERT Census2D_T0100_B_Lng_P0178_SUM VALUES( ";
	//CStrInsertHead += " INSERT Census2D_T0050_B_L_T100P0178 VALUES( ";	
	//CStrInsertHead += " INSERT Census2D_T0250_B_L_T100P0178 VALUES( ";	
	//CStrInsertHead += " INSERT Census2D_T1000_B_L_T100P0178 VALUES( ";	
	//CStrInsertHead += " INSERT Census2D_T0100_B_L_P0100 VALUES( ";	
	//CStrInsertHead += " INSERT Census2D_T0100_B_L_P0200 VALUES( ";	
	//CStrInsertHead += " INSERT Census2D_T0100_B_L_P2000 VALUES( ";	
	
	//2005.08.07 @@@@@
	//CStrInsertHead += " INSERT Census2D_T0100_B_Learning_P0178 VALUES( ";   //2005.08.05	
	//CStrInsertHead += " INSERT Census2D_T0100_B_Learning_P0178_1 VALUES( "; //2005.08.05	
	//CStrInsertHead += " INSERT Census2D_T0100_B_Learning_P0178_2 VALUES( "; //2005.08.05	
	//CStrInsertHead += " INSERT Census2D_T0100_B_Learning_P0178_3 VALUES( "; //2006.03.23	
	//CStrInsertHead += " INSERT Census2D_T0100_B_Learning_P0178_4 VALUES( "; //2006.03.23	
	//CStrInsertHead += " INSERT Census2D_T0100_B_Learning_P0178_5 VALUES( "; //2006.03.23	


	//CStrInsertHead += " INSERT Census3D_T0100_B_Learning_P0218 VALUES( ";
	//CStrInsertHead += " INSERT Census3D_T0100_U_Learning_P0218 VALUES( ";
	//CStrInsertHead += " INSERT Census3D_T0100_B_Lng_P0218_EUCL VALUES( ";	
	//CStrInsertHead += " INSERT Census3D_T0100_B_Lng_P0218_SUM VALUES( ";	
	//CStrInsertHead += " INSERT Census3D_T0050_B_L_T100P0218 VALUES( ";	
	//CStrInsertHead += " INSERT Census3D_T0250_B_L_T100P0218 VALUES( ";	
	//CStrInsertHead += " INSERT Census3D_T1000_B_L_T100P0218 VALUES( ";	

	//CStrInsertHead += " INSERT Gauss3D_T0100_B_Learning_P0218 VALUES( ";   //2005.08.05	
	//CStrInsertHead += " INSERT Gauss3D_T0100_B_Learning_P0218_1 VALUES( "; //2005.08.05	
	//CStrInsertHead += " INSERT Gauss3D_T0100_B_Learning_P0218_2 VALUES( "; //2005.08.05	
	//CStrInsertHead += " INSERT Gauss3D_T0100_B_Learning_P0218_3 VALUES( "; //2006.03.23	
	//CStrInsertHead += " INSERT Gauss3D_T0100_B_Learning_P0218_4 VALUES( "; //2006.03.23	
	//CStrInsertHead += " INSERT Gauss3D_T0100_B_Learning_P0218_5 VALUES( "; //2006.03.23	

	//CStrInsertHead += " INSERT Array3D_T0100_B_Learning_P0218 VALUES( ";   //2005.08.05	
	//CStrInsertHead += " INSERT Array3D_T0100_B_Learning_P0218_1 VALUES( "; //2005.08.05	
	//CStrInsertHead += " INSERT Array3D_T0100_B_Learning_P0218_2 VALUES( "; //2005.08.05	
	//CStrInsertHead += " INSERT Array3D_T0100_B_Learning_P0218_3 VALUES( "; //2006.03.23	
	//CStrInsertHead += " INSERT Array3D_T0100_B_Learning_P0218_4 VALUES( "; //2006.03.23	
	//CStrInsertHead += " INSERT Array3D_T0100_B_Learning_P0218_5 VALUES( "; //2006.03.23	

	//CStrInsertHead += " INSERT Census3D_T0100_B_Learning_P0218 VALUES( ";   //2005.08.05	
	//CStrInsertHead += " INSERT Census3D_T0100_B_Learning_P0218_1 VALUES( "; //2005.08.05	
	//CStrInsertHead += " INSERT Census3D_T0100_B_Learning_P0218_2 VALUES( "; //2005.08.05	
	//CStrInsertHead += " INSERT Census3D_T0100_B_Learning_P0218_3 VALUES( "; //2006.03.23	
	//CStrInsertHead += " INSERT Census3D_T0100_B_Learning_P0218_4 VALUES( "; //2006.03.23	
	CStrInsertHead += " INSERT Census3D_T0100_B_Learning_P0218_5 VALUES( "; //2006.03.23	
	
	//CStrInsertHead += " INSERT Gauss3D_T0100_U_Learning_P0218 VALUES( ";	
	//CStrInsertHead += " INSERT Gauss3D_T0100_U_Lng_U_P0218 VALUES( ";	
	//CStrInsertHead += " INSERT Gauss3D_T0100_B_Lng_P0218_EUCL VALUES( ";		
	//CStrInsertHead += " INSERT Gauss3D_T0100_B_Lng_P0218_SUM VALUES( ";	
	//CStrInsertHead += " INSERT Gauss3D_T0050_B_L_FT100P0218 VALUES( ";	
	//CStrInsertHead += " INSERT Gauss3D_T0250_B_L_FT100P0218 VALUES( ";	
	//CStrInsertHead += " INSERT Gauss3D_T1000_B_L_FT100P0218 VALUES( ";	

	//CStrInsertHead += " INSERT Array3D_T0100_B_Learning_P0218 VALUES( ";
	//CStrInsertHead += " INSERT Array3D_T0100_U_Learning_P0218 VALUES( ";
	//CStrInsertHead += " INSERT Array3D_T0100_B_Lng_P0218_EUCL VALUES( ";	
	//CStrInsertHead += " INSERT Array3D_T0100_B_Lng_P0218_SUM VALUES( ";	
	//CStrInsertHead += " INSERT Array3D_T0050_B_L_T100P0218 VALUES( ";	
	//CStrInsertHead += " INSERT Array3D_T0250_B_L_T100P0218 VALUES( ";	
	//CStrInsertHead += " INSERT Array3D_T1000_B_L_T100P0218 VALUES( ";	

	//CStrInsertHead += " INSERT Cover4D_T0100_B_Learning_P0250 VALUES( ";
	//CStrInsertHead += " INSERT Cover4D_T0100_B_Learning_P0250_1 VALUES( "; //2005.08.03
	//CStrInsertHead += " INSERT Cover4D_T0100_B_Learning_P0250_2 VALUES( "; //2005.08.03
	//CStrInsertHead += " INSERT Cover4D_T0100_B_Learning_P0250_3 VALUES( "; //2006.03.23
	//CStrInsertHead += " INSERT Cover4D_T0100_B_Learning_P0250_4 VALUES( "; //2006.03.23
	//CStrInsertHead += " INSERT Cover4D_T0100_B_Learning_P0250_5 VALUES( "; //2006.03.23

	//CStrInsertHead += " INSERT Cover4D_T0100_U_Learning_P0250 VALUES( ";
	//CStrInsertHead += " INSERT Cover4D_T0100_B_Lng_P0250_EUCL VALUES( ";
	//CStrInsertHead += " INSERT Cover4D_T0100_B_Lng_P0250_SUM VALUES( ";
	//CStrInsertHead += " INSERT Cover4D_T0050_B_L_T100P0250 VALUES( ";	
	//CStrInsertHead += " INSERT Cover4D_T0250_B_L_T100P0250 VALUES( ";	
	//CStrInsertHead += " INSERT Cover4D_T1000_B_L_T100P0250 VALUES( ";	

	//CStrInsertHead += " INSERT Census2D_T0100_20PC_Learning_P0178 VALUES( ";
	//CStrInsertHead += " INSERT Census2D_T0100_50PC_Learning_P0178 VALUES( ";
	//CStrInsertHead += " INSERT Census2D_T0100_80PC_Learning_P0178 VALUES( ";

	//CStrInsertHead += " INSERT House16D_Top100_20PC_Learning_P0867 VALUES( ";
	//CStrInsertHead += " INSERT House16D_Top100_50PC_Learning_P0867 VALUES( ";
	//CStrInsertHead += " INSERT House16D_Top100_80PC_Learning_P0867 VALUES( ";
	
	//CStrInsertHead += " INSERT Lsi_104D_T0020_20PC_Learning_P0954 VALUES( ";
	//CStrInsertHead += " INSERT Lsi_104D_T0020_50PC_Learning_P0954 VALUES( ";
	//CStrInsertHead += " INSERT Lsi_104D_T0020_80PC_Learning_P0954 VALUES( ";

	//----------- body ------
	if(!zlOpenDB())
	{
		AfxMessageBox("zlOpenDB() err!");
		zlCloseDB();
	}else
	{
		retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_WorkLoad); ///queries Statement handle 
		retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_Profile); /// Profile Statement handle 

		
//--------0  select knowledge from KB Profile 
//szSqlAllRows

		//1. read all tuples from Profile set store a buffer
		
		//1111111111111 read database from profiles :DATA_Top100_Census2D_Profile 111111111111111	
												//   Top100_Census2D_Profile2000
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census3D_Profile0827"; //Census3D
		//UCHAR szSqlAllRows[] = "SELECT * FROM Top100_Census3D_Profile0414"; //Census3D

		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		
		longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);
		longTicks = GetTickCount() - longTicks;

		if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO ) 
		{    //	retcode = SQLExecDirect for DATA_Top100_Census2D_Profile
			
			int iRowCount;
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt, RowCountPtr);						 
			iRowCount = * RowCountPtr;
			iTupleNum = iRowCount;
			iSizeProfile = iRowCount; // here only size of profile, 218, 436, 872, //100,200, ...,2000
			delete RowCountPtr;
			
			// Bind columns 1,2,3,4, ..., 104
			for(i = 0; i <COL_NUM+1; i++)
			{
				fCol[i] =0.0;
				cbCol[i] = 0; 
			}
			// Bind columns 1,2,3,4 ,.., COL_NUM
			for(i = 0; i <COL_NUM; i++)
					SQLBindCol(hstmt, i+1, SQL_C_DOUBLE, &fCol[i],0, &cbCol[i]); //SQL_C_SSHORT

			SQLBindCol(hstmt, COL_NUM+1, SQL_C_SLONG, &sN,0, &cbN); //SQL_C_SSHORT
			SQLBindCol(hstmt, COL_NUM+2, SQL_C_DOUBLE, &sr,0, &cbr); //SQL_C_SSHORT
			SQLBindCol(hstmt, COL_NUM+3, SQL_C_SLONG, &sf,0, &cbf); //SQL_C_SSHORT
			SQLBindCol(hstmt, COL_NUM+4, SQL_C_SLONG, &sc,0, &cbc); //SQL_C_SSHORT
			SQLBindCol(hstmt, COL_NUM+5, SQL_C_SLONG, &sd,0, &cbd); //SQL_C_SSHORT

			//need COL_NUM of columns
			for(i = 0; i<COL_NUM; i++)
			{
				pCol[i] = new  double[iRowCount]; 
				pColHold[i] = pCol[i]; 
			}

			pPf104D = new Profile104D[iRowCount]; pPf104DHold = pPf104D;
			
			iRowCount =0;
			while (TRUE) 
			{
				retcode = SQLFetch(hstmt);

				if (retcode == SQL_ERROR)
				{
					//show_error();
					wsprintf(tmp, "%ld", iRowCount);
					//int i = iRowCount;
					AfxMessageBox("SQLFetch Error !!!!!!");
							//break; //99.8.26
				}

				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
				{
					
					for(i = 0; i<COL_NUM; i++)
					{
						*pCol[i] = fCol[i]; 
						pCol[i]++;
						pPf104D->q[i] = fCol[i]; 
					}
					
					pPf104D->N		= sN;
					pPf104D->r		= (float) sr;
					pPf104D->f		= sf;
					pPf104D->c		= sc;
					pPf104D->d		= sd;

					pPf104D++;

					if(retcode == SQL_SUCCESS_WITH_INFO)
					{
						wsprintf(tmp, "%ld", retcode);
						AfxMessageBox(tmp);
					}
						
				} 
				else 
				{
					break;
				}

			}   ///while (TRUE)

			for(i = 0; i<COL_NUM; i++)
			{
				pCol[i] = pColHold[i]; 				
			}
			pPf104D	= pPf104DHold;

		}//	retcode = SQLExecDirect  for DATA_Top100_Census2D_Profile

	//111111111111111111 read data base  DATA_Top100_Census2D_Profile end   111111111111


//----------1	  select queris from Workload--------------------------
  //szSqlAllQueryRows

	//2. Read all Queries from DATA_Census2Dg_B_workload
		iQryInx =0;
		
		for(i = 0; i<COL_NUM; i++)
		{fCol[i]  = 0.0;	cbCol[i] = 0; }
									
		//1
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Census2Dg_B_workload"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Census2Dg_B_workload1"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Census2Dg_B_workload2"; //discounts, authors, Census2DTable						
	
		//UCHAR szSqlAllQueryRows[] = "SELECT * FROM DATA_Census3Dg_B_workload"; //discounts, authors, Census2DTable						
		
		SQLSetStmtOption(hstmt_Census2D_WorkLoad, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt_Census2D_WorkLoad, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		retcode = SQLExecDirect(hstmt_Census2D_WorkLoad, szSqlAllQueryRows, SQL_NTS);

		if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO ) 
		{    //	retcode = SQLExecDirect for census2Dg
			int iRowCount;
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt_Census2D_WorkLoad, RowCountPtr);						 
			iRowCount = * RowCountPtr;
			iSizeWorkLoad = iRowCount;
			delete RowCountPtr;
//__________
			// Bind columns 1,2,3,4, COL_NUM with worload
			for(i = 0; i < COL_NUM; i++)
				SQLBindCol(hstmt_Census2D_WorkLoad, i+1, SQL_C_DOUBLE, &fCol[i],0, &cbCol[i]); //SQL_C_SSHORT
		
			for(i = 0; i < COL_NUM; i++)
			{
				q[i] = new  double[iRowCount];
				qHold[i] = q[i]; 
			}

			while (TRUE) 
			{
				retcode = SQLFetch(hstmt_Census2D_WorkLoad);
				if (retcode == SQL_ERROR)
				{
					//show_error();
					wsprintf(tmp, "%ld", iRowCount);
					AfxMessageBox("SQLFetch Error !!!!!!");
							//break; //99.8.26
				}
				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
				{	
					for(i = 0; i < COL_NUM; i++)
					{
						*q[i] =  fCol[i];
						 q[i]++; 

						 ///////////2005.4.7 start /////////						 
						 //RstLng[iQryInx].q[i] = fCol[i];						 
						 ///////////2005.4.7 end////////////						 
					}

						 ///////////2005.4.7 start /////////
						 //RstLng[iQryInx].N = iTopN;	
						 //iQryInx ++;
						 ///////////2005.4.7 end////////////


				} 
				else 
				{
					break;
				}

			}///while (TRUE)
			
			for(i = 0; i < COL_NUM; i++)
			{
				q[i]=qHold[i]; 
			}
//______________				
		}//	retcode = SQLExecDirect  for query q1,q2.
	
	
	//3. evaluate r, f, -c, -d,

		double ftmp=0;
		int qnum =0; 
	//	double topt[COL_NUM][1000];
		int frequ[2000],freOrder[2000];  //frequency
		int itmp = 0;

		for(j=0;j<COL_NUM;j++)
			for(i=0;i<1000;i++)
				topt[j][i] = 0;

		for(i=0; i<2000; i++)
		{
			//topt1[i]=0; topt2[i] =0; topt3[i] = 0; topt4[i] = 0;
			frequ[i]=0; freOrder[i] =0;
		}

/////////// TEST START,  NO USEFUL ///////
		SQLFreeStmt(hstmt, SQL_DROP);
		retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 
		//2
		//UCHAR szSqlAllRows[] = "SELECT * FROM census2Dg"; //discounts, authors, Census2DTable						
		//UCHAR szSqlAllRowsFrmcensus2D[] = "SELECT * FROM CLMB_census2D"; //census2D				
		//UCHAR szSqlAllRowsFrmcensus2D[] = "SELECT * FROM CLMB_census3D"; //census3D						
		//UCHAR szSqlAllRowsFrmcensus2D[] = "SELECT * FROM CLMB_Array3D"; //census3D						

		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		
		longTicks = GetTickCount();
		    retcode = SQLExecDirect(hstmt, szSqlAllRowsFrmcensus2D, SQL_NTS);
		longTicks = GetTickCount() - longTicks;
////////// TEST START,  NO USEFUL ////////////////
		do
		{
/////////// TEST START,  NO USEFUL ; have useful : obtain longTicks ///////
		//SQLFreeStmt(hstmt, SQL_DROP);
		//retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 
		////2
		////UCHAR szSqlAllRows[] = "SELECT * FROM census2Dg"; //discounts, authors, Census2DTable						
		////UCHAR szSqlAllRowsFrmcensus2D[] = "SELECT * FROM CLMB_census2D"; //census2D				
		////UCHAR szSqlAllRowsFrmcensus2D[] = "SELECT * FROM CLMB_census3D"; //census3D						
		////UCHAR szSqlAllRowsFrmcensus2D[] = "SELECT * FROM CLMB_Array3D"; //census3D						

		//SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		//SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		
		//longTicks = GetTickCount();
		//    retcode = SQLExecDirect(hstmt, szSqlAllRowsFrmcensus2D, SQL_NTS);
		//longTicks = GetTickCount() - longTicks;
////////// TEST START,  NO USEFUL ////////////////



			////////////for each query find the closed profiles
			//evaluate all distance from New_query(q1[qnum],q2[qnum]) to Profile Point: 
			//														(pAge[i],pIncome[i] )
			// dis[i] = d(Q,Q') = dmax(Q,Q') = max(|qi-q'i|)
			// MAX Distance is useful, others not; but pPf104D[i].r may be any distance. 
			for(i = 0; i<iSizeProfile; i++)
			{
				  for(j = 0; j<COL_NUM; j++)
					x[j]= fabs(pCol[j][i]- q[j][qnum]);
				  
				  //----for Max distance, only use this distace 
				  dis[i] = x[0];
				  for(j = 1; j<COL_NUM; j++)
					dis[i] = (double)__max(dis[i], x[j]);

				  for(j = 0; j<COL_NUM; j++)
					 tuple[j][i] = pCol[j][i];
			  
				rr[i] = pPf104D[i].r;  //best search radius in Profile
				frequ[i] = pPf104D[i].f; 		
			}

			i=0;

			//order all distance
			// r[i]'s are sorting of dis[i] =  d(Q,Q'), to identify the closest Q' to Q
			for(i=0; i<iSizeProfile; i++)
			{
				r[i] = dis[i];  //d(Q,Q')
				for(int k = 0; k<COL_NUM; k++)
					topt[k][i] = tuple[k][i];
			
				rOrder[i] = rr[i];  //radius order
				freOrder[i] = frequ[i];

				for( j= i+1; j<iSizeProfile; j++)
				{
					if(dis[j] < r[i]) 
					{ ftmp = r[i];			r[i] = dis[j];			dis[j] = ftmp;
					  ftmp = rOrder[i];		rOrder[i] = rr[j];		rr[j] = ftmp;
					  itmp = freOrder[i];   freOrder[i]= frequ[j]; frequ[j] = itmp;

					  	for(int k = 0; k<COL_NUM; k++)
						{
							ftmp = topt[k][i]; topt[k][i]= tuple[k][j]; tuple[k][j]= ftmp;
						}

					}
				}
			} //for(i=0; i<iSizeProfile; i++)
					
		i=0;
		//int N, rd,f, c, d; 
		//evaluate search distance
		
		//int qp1 = topt1[0], qp2= topt2[0], qp3= topt3[0],qp4= topt4[0]; //Q'(qp1,qp2), the closest proples to Q(q1,q2)
		double qp[COL_NUM];
	
		for(j=0;j<COL_NUM;j++)
			 qp[j] = topt[j][0]; 

		int iKnum = 0,fpf[2000]; int iMeadian =0;
		double frou[2000],l[2000],V[2000], lV=0, lVrou =0, rou = 0;
		double dQQ[2000],rpf[2000];
		//double dmaxQQp;
		double rmin = rOrder[0], rmax = rOrder[iSizeProfile-1], rgm =0, RGM= 2*sqrt(rmin*rmax); //rgm : 2* r geometric mean
		double rd_ADM=0, rtmp[2000], rAMD[2000],rd_AllMean =0;

		int freAMD[2000],fretmp[2000];
		char cDblToStr[50] ="";
				for(j=0; j<iSizeProfile; j++)
				{
					rmin = __min(rmin, rOrder[j]);
					rmax = __max(rmax, rOrder[j]);
				}
				rgm = sqrt(rmin*rmax);
				RGM= 2*rgm;
				//rgm = 1.0; //sqrt(rmin*rmax);
				//RGM= 2*rgm;

			//////////mean of ALL density 
				for(j=0; j<iSizeProfile; j++)
				{					
					V[j] =1;
					for(int k =0; k<COL_NUM; k++)
						V[j] *= (rOrder[j]/rgm);	
					
					sprintf(cDblToStr,"%.13f",  V[j]);
					if(strcmp(cDblToStr,"1.#INF000000000") == 0)
					{
						AfxMessageBox( strcat(cDblToStr,"_ All density") );
					}

					rou += freOrder[j]/V[j];
				}
				rou = rou/iSizeProfile;
				
				rd_AllMean = RGM*pow( 2*iTopN/rou, 1.0/COL_NUM )/2; 

			//////////median of ALL density 

				for(j=0; j<iSizeProfile; j++)
				{	
					V[j] =1;
					for(int k =0; k<COL_NUM; k++)
						V[j] *= (rOrder[j]/rgm);	
					
					sprintf(cDblToStr,"%.13f",  V[j]);
					if(strcmp(cDblToStr,"1.#INF000000000") == 0)
					{
						AfxMessageBox( strcat(cDblToStr,"_ All density") );
					}

					frou[j] = freOrder[j]/V[j];
					fretmp[j] = freOrder[j];
					rtmp[j] = rOrder[j];
				}
					
				double rouOrder[2000],ftmp =0;

				for(j=0; j<iSizeProfile; j++)
				{
					rouOrder[j] = frou[j]; 
					freAMD[j]   = fretmp[j];
					rAMD[j]		= rtmp[j];
					for(int k = j+1; k <iSizeProfile; k++)
					{
						if(frou[k]< rouOrder[j])
						{
							ftmp = rouOrder[j]; rouOrder[j] = frou[k]; frou[k] = ftmp;
							itmp = freAMD[j]; freAMD[j] = fretmp[k]; fretmp[k]=itmp;
							ftmp = rAMD[j]	; rAMD[j]	= rtmp[k]; rtmp[k] = ftmp;
						}
					}
				}
				
				iAllMeadian = iSizeProfile/2;				
				dAll_Den_Median = rouOrder[iAllMeadian];
				rd_ADM = pow(2*iTopN/freAMD[iAllMeadian] , 1/COL_NUM)*rAMD[iAllMeadian];

				//rOrder[iAllMeadian];    //1.#INF000000000  // 1.#INF000000000
				//cDblToStr	0x001056e4 "1.#INF00000000000"

		if(r[0] == 0) // if Q=Q'
		{//if(r[0] == 0)
			rd = rOrder[0];
			int itest = 0; //use to test 
		}
		else
		{
			if(r[0]<= rOrder[0])  //case of Fig.3 //rou = N/4*r*r		
			{
				iKnum = 0;
				
				for(j=0; j<iSizeProfile; j++)
				{
					frou[j] =0;l[j] =0;V[j] = 0;
					dQQ[j] =0;rpf[j] = 0;fpf[j]=0;
				}

				for(j=0; j<iSizeProfile; j++) //Find set K that is (all squares Q in it)
				{
					if( r[j] <= rOrder[j]  ) //d(Q,Qpf) < rpf
					{
						dQQ[iKnum] = r[j];
						rpf[iKnum] = rOrder[j];
						fpf[iKnum] = freOrder[j];

						iKnum++;

					}
						
				}

				//---------- alternative test -----------------
				iMeadian = iKnum/2;
				rou = 0;
				lVrou = 0; lV = 0;

			// ////////////// lvp //////////////// ---Fig.3 --->>>>>
					for(j=0; j<iKnum; j++)
					{
						//l[j] = 1.0/(dQQ[j]*dQQ[j]*dQQ[j]);		//or d*d*d								
						//l[j] = 1.0/(dQQ[j]*dQQ[j]);		//or d*d
						//l[j] = 1.0/(dQQ[j]);		//or d														
						//l[j] = 1.0;		//or nondistance	
						
						V[j] = 1;	
						for(int k =0; k<COL_NUM; k++)
							V[j] *= (rpf[j]/rgm);
						

						sprintf(cDblToStr,"%.13f",  V[j]);
						if(strcmp(cDblToStr,"1.#INF000000000") == 0)
						{
							AfxMessageBox( strcat(cDblToStr,"_ fig.3 density Vj ") );
						}
						
						l[j] = 1.0;		
						//for(k =0; k<(COL_NUM); k++)
						//for(k =0; k<(COL_NUM-3); k++)
						for(int k =0; k<(COL_NUM*3/4); k++)
						//for(k =0; k<(COL_NUM/2); k++)
						//for(k =0; k<(2); k++)
						//for(k =0; k<(1); k++)
						//for(k =0; k<(0); k++)
							l[j] *= ( RGM/(dQQ[j]) );

						//l[j] *= pow( ( RGM/(dQQ[j]) ), 1/2);

						sprintf(cDblToStr,"%.13f",  l[j]);
						if(strcmp(cDblToStr,"1.#INF000000000") == 0)
						{
							AfxMessageBox( strcat(cDblToStr,"_ fig.3 density Lj ") );
						}
						
						lV += l[j]*V[j];
						lVrou += l[j]* fpf[j];   // (fpf[j]/(dQQ[j]* dQQ[j]* dQQ[j]));

					}

					rou = lVrou/lV;
				/************
					//////////mean of density 
					for(j=0; j<iKnum; j++)
					{	
						V[j] = 1;
						for(int k =0; k<COL_NUM; k++)
							V[j] *= (rpf[j]/rgm);
						sprintf(cDblToStr,"%.13f",  V[j]);
						if(strcmp(cDblToStr,"1.#INF000000000") == 0)
						{
							AfxMessageBox( strcat(cDblToStr,"_ fig.3 density Vj ") );
						}

						frou[j] = fpf[j]/( V[j]);
					    rou += frou[j]; 
					}
					rou = rou/iKnum;
					**************/
					/*******************
					///Median_density
					for(j=0; j<iKnum; j++)
					{
						V[j] = 1;
						for(int k =0; k<COL_NUM; k++)
							V[j] *= (rpf[j]/rgm);

						sprintf(cDblToStr,"%.13f",  V[j]);
						if(strcmp(cDblToStr,"1.#INF000000000") == 0)
						{
							AfxMessageBox( strcat(cDblToStr,"_ fig.3 density Vj ") );
						}

						frou[j] = fpf[j]/(V[j] );
					}

					double rouOrder[2000],ftmp =0;
					for(j=0; j<iKnum; j++)
					{
						rouOrder[j] = frou[j]; 
						for(int k = j+1; k <iKnum; k++)
						{
							if(frou[k]< rouOrder[j])
							{
								ftmp = rouOrder[j]; rouOrder[j] = frou[k]; frou[k] = ftmp;
							}
						}
					}					
					
					iMeadian = iKnum/2;
					rou = rouOrder[iMeadian];
				*****************/

				/****************

					//////////mean of ALL density 
					for(j=0; j<iSizeProfile; j++)
					{
						frou[j] = freOrder[j]/( 16*rOrder[j]*rOrder[j]*rOrder[j]*rOrder[j]);
					    rou += frou[j]; 
					}
					rou = rou/iSizeProfile;

					//////////median of ALL density 

					for(j=0; j<iSizeProfile; j++)
					{
						frou[j] = freOrder[j]/(16*rOrder[j]*rOrder[j]*rOrder[j]*rOrder[j]);;
					}
					
					double rouOrder[2000],ftmp =0;

					for(j=0; j<iSizeProfile; j++)
					{
						rouOrder[j] = frou[j]; 
						for(int k = j+1; k <iSizeProfile; k++)
						{
							if(frou[k]< rouOrder[j])
							{
								ftmp = rouOrder[j]; rouOrder[j] = frou[k]; frou[k] = ftmp;
							}
						}
					}					
					iMeadian = iSizeProfile/2;
					rou = rouOrder[iMeadian];
					************/

					if( rou > 0 )
					{
						//rd = RGM*pow( 2*iTopN/rou, 1.0/COL_NUM )/2; 
						rd = RGM*pow( 2*iTopN/rou, 1.0/COL_NUM )/2; 
						if (iTopN != pPf104D[0].N )
						{
							rd = rd*pow(iTopN/pPf104D[0].N, 1.0/COL_NUM);							
						}
					}
					else
						rd = rd_ADM;

				/********* temp ***	
					if (iTopN == pPf104D[0].N )
					{					
						if ( (rd < rOrder[0]) ||(rd < r[0]))  //r[0] = dmaxQQp;
						{
							//1
							//rd = __max(rd,rOrder[0]) ;
							//rd = __max(rd_ADM,rd_AllMean) ;
							//2
							//rd = ( __max(rd_ADM,rd_AllMean)  + rd)/2;
							//rd = rd*2/3 + (r[0] + rOrder[0])/3;
							//3
							//rd = sqrt( __max(rd_ADM,rd_AllMean) * rd);
							//rd = pow(rd*rd *(r[0] + rOrder[0]), 1/3);
							//4
							rd = __max ( __max(rd_ADM,rd_AllMean) , rd);
							rd =  rd/2.0 + (r[0] + rOrder[0])/2.0;							
							irderr ++;

						}
		
						if (rd > r[0] + rOrder[0])
						{
							rd = r[0] + rOrder[0];
						}
					}
					else				
					{
						if ( (rd < rOrder[0])*pow(iTopN/pPf104D[0].N, 1.0/COL_NUM) ||(rd < r[0]))  //r[0] = dmaxQQp;
						{
								rd = __max ( __max(rd_ADM,rd_AllMean) , rd);
								rd =  rd/2.0 + (r[0] + rOrder[0]*pow(iTopN/pPf104D[0].N, 1.0/COL_NUM) )/2.0;							
								irderr ++;

						}
			
						if (rd > r[0] + rOrder[0]*pow(iTopN/pPf104D[0].N, 1.0/COL_NUM))
						{
								rd = r[0] + rOrder[0]*pow(iTopN/pPf104D[0].N, 1.0/COL_NUM);
						}

					}//if (iTopN == pPf104D[0].N )
					******* temp ********/
				//------------Fig 3.^^^^^----------------

			}else
			{
				//x[1]=abs(qp1 - q1[qnum]);x[2]=abs(qp2 - q2[qnum]);x[3]=abs(qp3-q3[qnum]);x[4]=abs(qp4-q4[qnum]);
		
				//dmaxQQp = (double)max( x[1], x[2]); dmaxQQp= (double)max(dmaxQQp, x[3]);//MAX distance		
				//dmaxQQp= (double)max(dmaxQQp, x[4]);

				//if(dmaxQQp <= 2*rOrder[0])  //h<2r' ////2003.04.11
				{
					//case of Fig.4 //rou = N/4*r*r				
					iKnum = 0;
					for(j=0; j<2000; j++)
					{
						frou[j] =0;l[j] =0;V[j] = 0;
						dQQ[j] =0;rpf[j] = 0; fpf[j]=0;			
					}

					for(j=0; j<iSizeProfile; j++)
					{
						if(r[j] < rOrder[0] + r[0])
						{
							dQQ[iKnum] = r[j];
							rpf[iKnum] = rOrder[j];
							fpf[iKnum] = freOrder[j];

							iKnum++;
						}						
					}

					/////////////////////////////////////////////////////////
					//double x = 2.0, y = 3.0, z;
					//	z = pow( x, y );
					//printf( "%.1f to the power of %.1f is %.1f\n", x, y, z );
					//Output
					//2.0 to the power of 3.0 is 8.0
					/////////////////////////////////////////////

				//---------- alternative test ---------Fig.4 >>> --------
				lVrou = 0; lV = 0;
				rou = 0;
				int iMeadian = iKnum/2;

					for(j=0; j<iKnum; j++)
					{
						//l[j] = 1.0/(dQQ[j]*dQQ[j]*dQQ[j]);		//or d*d*d								
						//l[j] = 1.0/(dQQ[j]*dQQ[j]);		//or d*d
						//l[j] = 1.0/(dQQ[j]);		//or d														
						//l[j] = 1.0;		//or nondistance														

						V[j] = 1;
						for(int k =0; k<COL_NUM; k++)
							V[j] *= (rpf[j]/rgm);
						

						sprintf(cDblToStr,"%.13f",  V[j]);
						if(strcmp(cDblToStr,"1.#INF000000000") == 0)
						{
							AfxMessageBox( strcat(cDblToStr,"_ fig.4 density Vj ") );
						}

						l[j] = 1.0;	

						//for(k =0; k<(COL_NUM); k++)
						//for(k =0; k<(COL_NUM-3); k++)
						for(int k =0; k<(COL_NUM*3/4); k++)
						//for(k =0; k<(COL_NUM/2); k++)
						//for(k =0; k<(2); k++)
						//for(k =0; k<(1); k++)
						//for(k =0; k<(0); k++)
							l[j] *= ( RGM/(dQQ[j]) );

							//l[j] *= pow( ( RGM/(dQQ[j]) ), 1/2);

						sprintf(cDblToStr,"%.13f",  l[j]);
						if(strcmp(cDblToStr,"1.#INF000000000") == 0)
						{
							AfxMessageBox( strcat(cDblToStr,"_ fig.4 density Lj ") );
						}
						

						lV += l[j]*V[j];
						
						lVrou += l[j]* fpf[j];   // (fpf[j]/(dQQ[j]* dQQ[j]* dQQ[j]));
					}
					rou = lVrou/lV; //if rou == 0 then rd = rpf[iMeadian]
					
				/*******************
					//////////mean of density 
					for(j=0; j<iKnum; j++)
					{	
						V[j] = 1;
						for(int k =0; k<COL_NUM; k++)
							V[j] *= (rpf[j]/rgm);
						sprintf(cDblToStr,"%.13f",  V[j]);
						if(strcmp(cDblToStr,"1.#INF000000000") == 0)
						{
							AfxMessageBox( strcat(cDblToStr,"_ fig.4 density Vj ") );
						}

						frou[j] = fpf[j]/( V[j]);
					    rou += frou[j]; 
					}
					rou = rou/iKnum;
				******************/

				/*******************
					///Median_density
					for(j=0; j<iKnum; j++)
					{
						V[j] = 1;
						for(int k =0; k<COL_NUM; k++)
							V[j] *= (rpf[j]/rgm);

						sprintf(cDblToStr,"%.13f",  V[j]);
						if(strcmp(cDblToStr,"1.#INF000000000") == 0)
						{
							AfxMessageBox( strcat(cDblToStr,"_ fig.4 density Vj ") );
						}

						frou[j] = fpf[j]/(V[j] );
					}

					double rouOrder[2000],ftmp =0;
					for(j=0; j<iKnum; j++)
					{
						rouOrder[j] = frou[j]; 
						for(int k = j+1; k <iKnum; k++)
						{
							if(frou[k]< rouOrder[j])
							{
								ftmp = rouOrder[j]; rouOrder[j] = frou[k]; frou[k] = ftmp;
							}
						}
					}					
					iMeadian = iKnum/2;

					rou = rouOrder[iMeadian];
							*************/

				/****************

					//////////mean of ALL density 
					for(j=0; j<iSizeProfile; j++)
					{
						frou[j] = freOrder[j]/( 16*rOrder[j]*rOrder[j]*rOrder[j]*rOrder[j]);
					    rou += frou[j]; 
					}
					rou = rou/iSizeProfile;

					//////////median of ALL density 

					for(j=0; j<iSizeProfile; j++)
					{
						frou[j] = freOrder[j]/(16*rOrder[j]*rOrder[j]*rOrder[j]*rOrder[j]);;
					}

					double rouOrder[2000],ftmp =0;

					for(j=0; j<iSizeProfile; j++)
					{
						rouOrder[j] = frou[j]; 
						for(int k = j+1; k <iSizeProfile; k++)
						{
							if(frou[k]< rouOrder[j])
							{
								ftmp = rouOrder[j]; rouOrder[j] = frou[k]; frou[k] = ftmp;
							}
						}
					}					
					iMeadian = iSizeProfile/2;
					rou = rouOrder[iMeadian];
						****************/				
					if( rou > 0 )
					{
						rd = RGM*pow( 2*iTopN/rou, 1.0/COL_NUM )/2; 
						if (iTopN != pPf104D[0].N )
						{
							rd = rd*pow(iTopN/pPf104D[0].N, 1.0/COL_NUM);							
						}
					}
					else
						rd = rd_ADM;
				/*******************
					if ( (rd < rOrder[0]) ||(rd < r[0]))  //r[0] = dmaxQQp;
					{
						
						//rd = __max(rd,rOrder[0]) ;
						//rd = __max(rd_ADM,rd_AllMean) ;
						//rd = ( __max(rd_ADM,rd_AllMean)  + rd)/2;
						//rd = ( __max(rd_ADM,rd_AllMean)  + rd + rOrder[0])/3;
						
						//rd = ( __max(rd_ADM,rd_AllMean)  + rd)/2;
						//rd = rd*2/3 + (r[0] + rOrder[0])/3;

						//rd = sqrt( __max(rd_ADM,rd_AllMean) * rd);
						//rd = pow(rd*rd *(r[0] + rOrder[0]), 1/3);
						
						//1
						//rd = __max(rd,rOrder[0]) ;
						//rd = __max(rd_ADM,rd_AllMean) ;
						//2
						//rd = ( __max(rd_ADM,rd_AllMean)  + rd)/2;
						//rd = rd*2/3 + (r[0] + rOrder[0])/3;
						//3
						//rd = sqrt( __max(rd_ADM,rd_AllMean) * rd);
						//rd = pow(rd*rd *(r[0] + rOrder[0]), 1/3);
						//4
						rd = __max ( __max(rd_ADM,rd_AllMean) , rd);
						rd =  rd/2 + (r[0] + rOrder[0])/2;

						irderr ++;
					}
	
					if (rd > r[0] + rOrder[0])
					{
						rd = r[0] + rOrder[0];
					}

					if (rd < rOrder[0])
					{
						//irderr ++;
					}
			*****************/
					if (iTopN == pPf104D[0].N )
					{					
						if ( (rd < rOrder[0]) ||(rd < r[0]))  //r[0] = dmaxQQp;
						{
							//1
							//rd = __max(rd,rOrder[0]) ;
							//rd = __max(rd_ADM,rd_AllMean) ;
							//2
							//rd = ( __max(rd_ADM,rd_AllMean)  + rd)/2;
							//rd = rd*2/3 + (r[0] + rOrder[0])/3;
							//3
							//rd = sqrt( __max(rd_ADM,rd_AllMean) * rd);
							//rd = pow(rd*rd *(r[0] + rOrder[0]), 1/3);
							//4
							rd = __max ( __max(rd_ADM,rd_AllMean) , rd);
							rd =  rd/2.0 + (r[0] + rOrder[0])/2.0;							
							irderr ++;

						}
		
						if (rd > r[0] + rOrder[0])
						{
							rd = r[0] + rOrder[0];
						}
					}
					else				
					{
						if ( (rd < rOrder[0])*pow(iTopN/pPf104D[0].N, 1.0/COL_NUM) ||(rd < r[0]))  //r[0] = dmaxQQp;
						{

								rd = __max ( __max(rd_ADM,rd_AllMean) , rd);
								rd =  rd/2.0 + (r[0] + rOrder[0]*pow(iTopN/pPf104D[0].N, 1.0/COL_NUM) )/2.0;							
								irderr ++;

						}
			
						if (rd > r[0] + rOrder[0]*pow(iTopN/pPf104D[0].N, 1.0/COL_NUM))
						{
								rd = r[0] + rOrder[0]*pow(iTopN/pPf104D[0].N, 1.0/COL_NUM);
						}



					}//if (iTopN == pPf104D[0].N )

				//-----------------fig. 4 -^^^^^^ end ---------- 
			
					int itest = 0;
				//}else{  ////2003.04.11

					//rd = dmaxQQp + rOrder[0];  //2003.04.11

				}//if(dmaxQQp <= 2*rOrder[0])

			}//if(dmaxQQp <= rOrder[0])


		}//if(r[0] == 0)

		
		//rd = rOrder[0];

			
			CTime CurTime = CTime::GetCurrentTime();         

			//N = 100; c = -1; d = - CurTime.GetTime();
			
			N = iTopN; c = -1; d-- ;

			char cLeft[COL_NUM][50] , cRight[COL_NUM][50] , cAttr[COL_NUM][50] ;

			for(i=0; i<COL_NUM; i++)
				for(j=0; j<50; j++)
				{
					cLeft[i][j]		=0;
					cRight[i][j]	=0;
					cAttr[i][j]		=0;
				}

			for(i=0; i<COL_NUM; i++)
			{		
				sprintf(cLeft[i],		"%.15G",	  (q[i][qnum] - rd)		);
				sprintf(cRight[i],		"%.15G",	  (q[i][qnum] + rd)	    );
				//sprintf(cLeft[i],		"%.16G",	  (q[i][qnum] - rd)		);
				//sprintf(cRight[i],	"%.16G",	  (q[i][qnum] + rd)	    );
				
				sprintf(cAttr[i],    "<= attr%d AND attr%d <=",            i,i  );
			}
			//3
			CStrSelect += CStrSelectHead; //"select  * from CLMB_census3D where (";

			CStrSelect += cLeft[0];
			CStrSelect += "<= attr0 AND attr0 <=";
			CStrSelect += cRight[0];

			for(i=1; i<COL_NUM; i++)
			{
				CStrSelect += ") AND (";
				CStrSelect += cLeft[i];
				CStrSelect += cAttr[i];
				CStrSelect += cRight[i];
			}

			CStrSelect += ")"; 

			int iSqlLen = CStrSelect.GetLength();
			char * szSqlSquareRows = new char [iSqlLen + 1];	
			strcpy(szSqlSquareRows , "");
			strcat(szSqlSquareRows , CStrSelect);
	
			SQLFreeStmt(hstmt, SQL_DROP);
			retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 

			SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
			SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
			
			shortTicks = GetTickCount();
			retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlSquareRows, SQL_NTS);
			shortTicks = GetTickCount() - shortTicks;


			if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) 
			{    //	retcode = SQLExecDirect for census2Dg
				SDWORD *  RowCountPtr = new SDWORD ;
				retcode = SQLRowCount(hstmt, RowCountPtr);						 
				f = * RowCountPtr;
				delete RowCountPtr;

			}

			if(f<=0)
				int iiii = 0;

			CStrSelect = "";
			delete [] szSqlSquareRows;

	//4. insert zeta into DATA_Top100_Census2D_Profile
		
			if( f<iTopN )
			{
				if (iTopN <= pPf104D[0].N )
					rd = r[0] + rOrder[0];//dmaxQQp + rOrder[0];
				else
				{
					double dConst = pow(iTopN/pPf104D[0].N, 1.0/COL_NUM);
					//rd = r[0] + rOrder[0]* dConst;
					int ih = (int)iTopN/pPf104D[0].N;
					ih = ih/2;
					rd = r[ih] + rOrder[ih]* dConst;

				}

				for(i=0; i<COL_NUM; i++)
					for(j=0; j<50; j++)
					{
						cLeft[i][j]		=0;
						cRight[i][j]	=0;
						cAttr[i][j]		=0;

						//tmpL[i][j]		=0;
						//tmpR[i][j]		=0;
					}

				for(i=0; i<COL_NUM; i++)
				{		
					//sprintf(tmpL[i],		"%f",	(double) (q[i][qnum] - rd)	);
					//sprintf(tmpR[i],	    "%f",	(double) (q[i][qnum] + rd)	);
			
					sprintf(cLeft[i],		"%.15G",	  (q[i][qnum] - rd)		);
					sprintf(cRight[i],		"%.15G",	  (q[i][qnum] + rd)	    );
					//sprintf(cLeft[i],		"%.16G",	  (q[i][qnum] - rd)		);
					//sprintf(cRight[i],		"%.16G",	  (q[i][qnum] + rd)	    );
				
					sprintf(cAttr[i],    "<= attr%d AND attr%d <=",            i,i  );
				}

				//3.1
				CStrSelect = "";				
				CStrSelect += CStrSelectHead; //"select  * from CLMB_census3D where (";

				CStrSelect += cLeft[0];
				CStrSelect += "<= attr0 AND attr0 <=";
				CStrSelect += cRight[0];

				for(i=1; i<COL_NUM; i++)
				{
					CStrSelect += ") AND (";
					CStrSelect += cLeft[i];
					CStrSelect += cAttr[i];
					CStrSelect += cRight[i];
				}

				CStrSelect += ")"; 

				int iSqlLen = CStrSelect.GetLength();
				char * szSqlSquareRows_rst = new char [iSqlLen + 1];	
				strcpy(szSqlSquareRows_rst , "");
				strcat(szSqlSquareRows_rst , CStrSelect);
		
				SQLFreeStmt(hstmt, SQL_DROP);
				retcode = SQLAllocStmt(hdbc, &hstmt); /// Profile Statement handle 

				SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
				SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
				
				shortTicks_rst = GetTickCount();
				retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlSquareRows_rst, SQL_NTS);
				shortTicks_rst = GetTickCount() - shortTicks_rst;

				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) 
				{    //	retcode = SQLExecDirect for census2Dg
					SDWORD *  RowCountPtr = new SDWORD ;
					retcode = SQLRowCount(hstmt, RowCountPtr);						 
					f_rst = * RowCountPtr;
					delete RowCountPtr;

				}

				if(f_rst<=0)
				  int iiiib = 0;

				CStrSelect = "";
				delete [] szSqlSquareRows_rst;
						
			} //if(f<iTopN)
		
			if (f>=0)
			{   
				//------------
				char	cAttribute[COL_NUM+7][50];
				for(i=0; i<COL_NUM + 7; i++)
					for(j=0; j< 50; j++)
						cAttribute[i][j]=0;

				for(i=0; i<COL_NUM ; i++)
					sprintf(cAttribute[i],	"%G", q[i][qnum] );

				sprintf(cAttribute[COL_NUM],  "%ld", N);
				sprintf(cAttribute[COL_NUM+1],"%.15G",  rd);
				sprintf(cAttribute[COL_NUM+2],"%ld", f );
				if(f_rst > 0)
				{
					sprintf(cAttribute[COL_NUM+3],"%ld", f_rst );
					sprintf(cAttribute[COL_NUM+4],"%ld", shortTicks_rst);
					f_rst = 0;
					shortTicks_rst = 0;
				}else
				{
					sprintf(cAttribute[COL_NUM+3],"NULL");
					sprintf(cAttribute[COL_NUM+4],"NULL");

				}
				sprintf(cAttribute[COL_NUM+5],"%ld", shortTicks);
				sprintf(cAttribute[COL_NUM+6],"%ld", longTicks);


				///////////2005.4.7 start /////////
				//RstLng[qnum].N = N;	
				//RstLng[qnum].r = rd;	
				//RstLng[qnum].f = f;	
				//RstLng[qnum].f_rst = f_rst;	
				//RstLng[qnum].shortTicks_rst = shortTicks_rst;	
				//RstLng[qnum].shortTicks = shortTicks;	
				//RstLng[qnum].longTicks = longTicks;	

				///////////2005.4.7 end////////////


				//4
				//CStrInsert += " INSERT dbo.Census3D_T0100_B_Learning_P0827 VALUES( ";
				//CStrInsert += " INSERT dbo.Census3D_T0100_B_Learning_P0414 VALUES( ";
				CStrInsert += CStrInsertHead; //" INSERT dbo.Census3D_T0100_B_Learning_P0218 VALUES( ";
				for(i=0; i< COL_NUM+7-1; i++)
				{
					CStrInsert += cAttribute[i];
					CStrInsert += ",";
				}
				CStrInsert += cAttribute[COL_NUM+7-1];
				CStrInsert += ")";

			    int iSqlLen = CStrInsert.GetLength();

				char * szSqlInsert = new char [iSqlLen + 1];
				strcpy(szSqlInsert , "");
				strcat(szSqlInsert , CStrInsert);

				SQLFreeStmt(hstmt_Census2D_Profile, SQL_DROP);
				retcode = SQLAllocStmt(hdbc, &hstmt_Census2D_Profile); /// Profile Statement handle 

				retcode = SQLExecDirect(hstmt_Census2D_Profile, (unsigned char *)szSqlInsert, SQL_NTS);

				if (retcode == SQL_SUCCESS) 
				{  //	retcode = SQLExecDirect
					//AfxMessageBox("Insert new hstmt_Census2D_Learning  OKKKKKKKKKKK!");
					//Sleep(300);
					iInsertOK++;

					//bReturn = TRUE;
				}
				else
				{
					AfxMessageBox("Insert DATA_Top100_Census2D_Learning Error!");
					AfxMessageBox(szSqlInsert);

					CString cstrMarc;
					cstrMarc = szSqlInsert;

					CFile file;
					if(file.Open("E:\\Paper2\\CLMB_census2D\\szSqlInsert.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
					{
						file.Write(cstrMarc, cstrMarc.GetLength() +1 );
					}
					file.Close();
	
					iInsertERR++;
					i= 0;

				} //	retcode = SQLExecDirect 
				
				f=0;
				CStrInsert = "";
				delete [] szSqlInsert;

			}
			qnum++;

		}while(qnum <iSizeWorkLoad); //100);

	}//if(!zlOpenDB())


	for (i=0; i< COL_NUM; i++)
	{
		delete [] pCol[i];//new float[10]
		delete [] q[i];//new float[10]
	}

	delete [] pPf104D;

	//SQLFreeStmt(hstmt, SQL_DROP); // 2005.4.7 in zlCloseDB();//
	SQLFreeStmt(hstmt_Census2D_WorkLoad, SQL_DROP);
	SQLFreeStmt(hstmt_Census2D_Profile, SQL_DROP);

	zlCloseDB();
	wsprintf(tmp, " irderr = %d", irderr);

	AfxMessageBox(tmp);
	AfxMessageBox("Insert hstmt_Generet2DLearning  OK!");		
}

int CMainFrame::zlExeSelect(char *TableName, char *szSql)
{
	if(!zlOpenDB())
	{
		AfxMessageBox("zlOpenDB() err!");
		zlCloseDB();
	}

	int iRowCnt = -1;

	SQLFreeStmt(hstmt, SQL_DROP);
	retcode = SQLAllocStmt(hdbc, &hstmt); ///Statement handle 
	if(retcode != SQL_SUCCESS)
		return -1;

	SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
	SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
	
	//char szLocalSql[20480] = ""; //2005.02.07
	//strcpy(szLocalSql, szSql);	//2005.02.07

	//retcode = SQLExecDirect(hstmt, (unsigned char *)szLocalSql, SQL_NTS);  //2005.02.07
	retcode = SQLExecDirect(hstmt, (unsigned char *)szSql, SQL_NTS);  //2005.02.07

	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
	{  //	retcode = SQLExecDirect
	
		int iRowCount;
		SDWORD *  RowCountPtr = new SDWORD ;
		retcode = SQLRowCount(hstmt, RowCountPtr);						 
		iRowCount = * RowCountPtr;
		delete RowCountPtr;
		iRowCnt = iRowCount;
	}
	zlCloseDB();
	//----- body-----------------

	return iRowCnt;
}

void CMainFrame::OnViewCluster100_old() 
{
	
	if(!zlOpenDB())
	{
		AfxMessageBox("zlOpenDB() err!");
		zlCloseDB();
	}

	long lStartTimer = GetTickCount();
	long lEndTimer;

	int m = 100; //20; //10; //9;    //10;  //the number of rectangles 
	int n = 2;	//104;   //the dimensions of space
	double Totall_v =0.0; // Totall_v = v(U Si )
	int i, j;
	int old_m = m;

	//Seed the random-number generator with current time
	srand( (unsigned)time( NULL ) );
	
	int iRandom = rand()%100;

//char * * pGcdd;
//pGcdd = new ( char  (*[nPtrBufSize]) );
//	zlGetPartString(Marc->System.Gcdd, &pRtn, &nPtrBufSize, &nMaxStrSize)
//	bool CLibServerApp::zlGetPartString(char * inString, LPCHAR lpCharBuf, LPDWORD lpNumOfPtr, LPDWORD lpNumOfStr)
//the last 3 ones is return.
	
	ZLRECT * S = new ZLRECT[m+1]; //S[m+1];
	ZLRECT * T = new ZLRECT[m+1]; //T[m+1];
	//-- NOT use this definition: ZLRECT ** T = new ( ZLRECT (*[m+1]) ); //T[m+1];

	for(i=1; i<=m; i++)
	{
		//S[i].a = new double[n+1];
		//S[i].b = new double[n+1];

		//T[i].a = new double[n+1];
		//T[i].b = new double[n+1];
	}

	//1. Get m initial rectagles randomly from [15, 90]x[0, 347998]
	for(i=1; i<=m; i++)
	{

		for(j= 1; j <=1; j++)
		{
			// 15<= Age <= 90
			S[i].a[j] = rand()%90; 
			if(S[i].a[j] < 15)
				S[i].a[j] = 15;

			S[i].b[j] = S[i].a[j] + rand()%90 + 1; 
			if(S[i].b[j] >90)
				S[i].b[j] = 90;
		}

		for(j= 2; j <=n; j++)
		{
			//income is in [0, 347998]
			S[i].a[j] = rand()%350000;
			if(S[i].b[j]> 347998)
				S[i].b[j] = 347998;

			S[i].b[j] = S[i].a[j] + rand()%300 + 1; 
			if(S[i].b[j]> 350000)
				S[i].b[j] = 350000;
		}

		S[i].v =1;
		for(j=1; j<=n; j++)
		{
			S[i].v *= (S[i].b[j]-S[i].a[j]);

		}
		sprintf(S[i].suffix, "%d", i);
		S[i].suf1st = i;
		S[i].sufend = i;
		S[i].cn =0;
		S[i].bsn = i;
	}
	
	char temp[512] = "";
	CString cstrMarc = "";

//------test 1 start ------
for(i=1; i<=m; i++)
{
           
	//sprintf(temp, " S%02i: [%.2f, %.2f]x[%.2f, %.2f]: ",i, S[i].a[1], S[i].b[1], S[i].a[2], S[i].b[2] );
	//cstrMarc += temp;
	//cstrMarc += "\r\n";

}
	cstrMarc += "\r\n";
	cstrMarc += "\r\n";

//------test 1 end --------


	//2. Eliminating redundant squares temporarily
	bool rmvable =false;
    int l=1; 
	int k;

	for(i=1; i<=m; i++)
	{
		for(k=1; k<=m; k++)
		{
		   if(i != k)
		   {
				for(j=1; j<=n; j++)
				{
					 // if S[i] is the subset of S[k], 
					if( (S[k].a[j]<=S[i].a[j]) && (S[i].b[j]<=S[k].b[j] ))
					{
						rmvable = true;
					}
					else
					{
						rmvable = false;
						break; //break j, for next k
					}
				} //for(j= 1; j <=n; j++)
				
				if(rmvable) //there is a k such that Si is in Sk
				{
						//-------test 2---
							sprintf(temp, " S%ld cover, REMOVE S%i: [%.2f, %.2f]x[%.2f, %.2f]: ", k, i, S[i].a[1], S[i].b[1], S[i].a[2], S[i].b[2] );
							cstrMarc += temp;
							cstrMarc += "\r\n";

						//-------test 2---
					S[i].bsn = k;
					break;  // break k and then for next i
				}
		   } //if(i != k)

		}//for(k=1; i<=m; k++)

		if( (rmvable == false) || (l==1 && i==m && rmvable) ) //cannot be removed
		{
			//T[l] = S[i];
			// :==: is the same as :==:
			//memset(&T[l], 0, sizeof(ZLRECT));
			//memcpy(&T[l], &S[i], sizeof(ZLRECT));
			
			for(j= 1; j <=n; j++)
			{
				T[l].a[j] = S[i].a[j];
				T[l].b[j] = S[i].b[j]; 
			}
			T[l].v=S[i].v;

			sprintf(T[l].suffix, "%d", l);
			T[l].suf1st = l;
			T[l].sufend = l;
			T[l].cn = 0;
			T[l].bsn = l;
			//T[l]->bsn = l;
			S[i].bsn= 10000+l; // the remainder of S[i]: S[i].bsn = T[l].bsn +10000
							   // i.e. S[i] is the subset of T[l]
			l++;
		}
	}//for(i=1; i<=m; i++)


//------test 3 start ------
	cstrMarc += "\r\n";
	cstrMarc += "\r\n";

for(i=1; i<=l-1; i++)
{
           
	sprintf(temp, " T%02i: [%.2f, %.2f]x[%.2f, %.2f]: ",i, T[i].a[1], T[i].b[1], T[i].a[2], T[i].b[2] );
	cstrMarc += temp;
	cstrMarc += "\r\n";

}
	cstrMarc += "\r\n";
	cstrMarc += "\r\n";

//------test 3 end --------


	//3. Select * from 4 cases;
	//SELECT * FROM CLMB_census2D where (20 <= Age and Age <= 50) AND (3000 <= Income and Income <= 60000)
	
	
	
	char szSql[12048] ="";
	int  ituples_cnt = 0;
	char TableName[] = "CLUM_census2D";
	int iSum_TickCount = 0;

	//3.0 select * FROM  ALL TABLE: SELECT * FROM CLMB_census2D, 
	
	strcpy(	szSql, 	" SELECT * FROM CLMB_census2D ");
	lStartTimer = GetTickCount();
		ituples_cnt = zlExeSelect(TableName, szSql);
	lEndTimer = GetTickCount() - lStartTimer ;

	cstrMarc += "\r\n";
    sprintf(temp, "SELECT * FROM CLMB_census2D: GetTickCount = %ld", lEndTimer);
	cstrMarc += temp;
	cstrMarc += "\r\n";
	cstrMarc += "\r\n";



	//3.1 select * each reach rectangle of all m S[i], 
	
	//m = min(m,l-1);
/*
	for(i = 1; i<=m; i++) // there are m rectangles
	{
		strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ( ( ");
		
			sprintf(temp, " %.2f ", T[i].a[1] );
			strcat(	szSql, temp	);
			strcat(	szSql, "<= age AND age <=");
			sprintf(temp, " %.2f ", T[i].b[1] );
			strcat(	szSql, temp	);

			strcat(	szSql, ") AND (" );

			sprintf(temp, " %.2f ", T[i].a[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, 	"<= Income AND Income <=");
			sprintf(temp, " %.2f ", T[i].b[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, ") ) "	);

			lStartTimer = GetTickCount();
				ituples_cnt = zlExeSelect(TableName, szSql);
		    lEndTimer = GetTickCount() - lStartTimer ;
			
			iSum_TickCount += lEndTimer;

            sprintf(temp, " Rectagle%i: [%.2f, %.2f]x[%.2f, %.2f]: ",i, T[i].a[1], T[i].b[1], T[i].a[2], T[i].b[2] );
			cstrMarc += temp;
            sprintf(temp, " GetTickCount = %ld", lEndTimer);
			cstrMarc += temp;
			cstrMarc += "\r\n";


	}
*/
	// m = m ==100

	for(i = 1; i<=m; i++) // there are m the originial rectangles S[1] to S[100]
	{
		strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ( ( ");
		
			sprintf(temp, " %.2f ", S[i].a[1] );
			strcat(	szSql, temp	);
			strcat(	szSql, "<= age AND age <=");
			sprintf(temp, " %.2f ", S[i].b[1] );
			strcat(	szSql, temp	);

			strcat(	szSql, ") AND (" );

			sprintf(temp, " %.2f ", S[i].a[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, 	"<= Income AND Income <=");
			sprintf(temp, " %.2f ", S[i].b[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, ") ) "	);

			lStartTimer = GetTickCount();
				ituples_cnt = zlExeSelect(TableName, szSql);
		    lEndTimer = GetTickCount() - lStartTimer ;
			
			iSum_TickCount += lEndTimer;

            //sprintf(temp, " S%i: [%.2f, %.2f]x[%.2f, %.2f]: tuples_num = %ld ",i, T[i].a[1], T[i].b[1], T[i].a[2], T[i].b[2], ituples_cnt );
            sprintf(temp, " S%i: [%.2f, %.2f]x[%.2f, %.2f]: tuples_num = %ld ",i, S[i].a[1], S[i].b[1], S[i].a[2], S[i].b[2], ituples_cnt );
			cstrMarc += temp;
            sprintf(temp, " GetTickCount = %ld", lEndTimer);
			cstrMarc += temp;
			cstrMarc += "\r\n";
	}


	    sprintf(temp, "       Sum of Tick Count = %ld", iSum_TickCount);
		cstrMarc += temp;
		cstrMarc += "\r\n";

	//3.2 select * From UNION of l T[i]: from T[1] to T[l] generally l<=m , 

		cstrMarc += "\r\n";
		cstrMarc += " 2. select * From UNION ";

	strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ");

	m=l-1;  // for T[i]
	for(i = 1; i<=m; i++)
	{
		strcat(	szSql, 	" ( ( ");

			sprintf(temp, " %.2f", T[i].a[1] );
			strcat(	szSql, temp	);
			strcat(	szSql, "<= age AND age <=");
			sprintf(temp, " %.2f", T[i].b[1] );
			strcat(	szSql, temp	);

			strcat(	szSql, ") AND (" );

			sprintf(temp, " %.2f", T[i].a[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, 	"<= Income AND Income <=");
			sprintf(temp, " %.2f", T[i].b[2] );
			strcat(	szSql, temp	);
		strcat(	szSql, ") ) "	);

		if(i<m)
			strcat(	szSql, " OR " );
	}

	//AfxMessageBox(szSql);

	lStartTimer = GetTickCount();
		ituples_cnt = zlExeSelect(TableName, szSql);
	lEndTimer = GetTickCount() - lStartTimer ;
	
	iSum_TickCount += lEndTimer;

    sprintf(temp, " \r\n		The UNION¡¡spend TickCount = %ld", lEndTimer);
	cstrMarc += temp;
	cstrMarc += "\r\n";

	////3.0_1 select * FROM  ALL TABLE: SELECT * FROM CLMB_census2D, 
	
	//strcpy(	szSql, 	" SELECT * FROM CLMB_census2D ");
	//lStartTimer = GetTickCount();
	//	ituples_cnt = zlExeSelect(TableName, szSql);
	//lEndTimer = GetTickCount() - lStartTimer ;

	//cstrMarc += "\r\n";
    //sprintf(temp, "SELECT * FROM CLMB_census2D: GetTickCount = %ld", lEndTimer);
	//cstrMarc += temp;
	//cstrMarc += "\r\n";
	//cstrMarc += "\r\n";
	
	//3.3  select * From SCR, scr (Small Cover Rectagle,)

		cstrMarc += "\r\n";
		cstrMarc += " 3. select * From SCR ";


	ZLRECT scr;

	//scr.a = new double[n+1];
	//scr.b = new double[n+1];
	
	for(i=1; i<=n; i++ )
	{
		scr.a[i] = T[1].a[i];
		scr.b[i] = T[1].b[i];

		for(j=2; j<=m; j++ )
		{
			scr.a[i] = min(scr.a[i], T[j].a[i]);
			scr.b[i] = max(scr.b[i], T[j].b[i]);
		}
	}

///===========
//scr.a[1] = 15; scr.b[1]=90;
//scr.a[2] =0 ; scr.b[2]= 347998;   

//scr.a[2] =-25897 ; scr.b[2]= 347998;  //-25897	347998
///===========


		strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ( ( ");
		
			sprintf(temp, " %.2f ", scr.a[1] );
			strcat(	szSql, temp	);
			strcat(	szSql, "<= age AND age <=");
			sprintf(temp, " %.2f ", scr.b[1] );
			strcat(	szSql, temp	);

			strcat(	szSql, ") AND (" );

			sprintf(temp, " %.2f ", scr.a[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, 	"<= Income AND Income <=");
			sprintf(temp, " %.2f ", scr.b[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, ") ) "	);


//strcpy(	szSql, 	" SELECT * FROM CLMB_census2D Where ( (15 <=Age AND Age<=90) AND (0 <=Income and income <= 347998) ) ");

			lStartTimer = GetTickCount();
				ituples_cnt = zlExeSelect(TableName, szSql);
		    lEndTimer = GetTickCount() - lStartTimer ;
			
			iSum_TickCount += lEndTimer;

			cstrMarc += "\r\n";
            sprintf(temp, "scr: [%.2f, %.2f]x[%.2f, %.2f]: ", scr.a[1], scr.b[1], scr.a[2], scr.b[2] );
			cstrMarc += temp;
            sprintf(temp, " GetTickCount = %ld", lEndTimer);
			cstrMarc += temp;
			cstrMarc += "\r\n";
			cstrMarc += "\r\n";

//3.4  ----   division 12 = 4*3 partition  of scr ----
//            select * From each partition,

	ZLRECT part[13]; //we use 1-12

	for(i=1; i<=12; i++)
	{
		//part[i].a = new double[n+1];
		//part[i].b = new double[n+1];
	}

	//int * a = new int[n+1];
	double * a = new double[n+1];

	double * d = new double[n+1];
	int alfa;

	//a[1] =15; a[2] = -25897; 

	//d[1] = (90-15)/3; 	d[2] = ( 347998-(-25897) )/4; 

	a[1] = scr.a[1]; 
	a[2] = scr.a[2]; 

	d[1] = (scr.b[1] - scr.a[1])/3; 	
	d[2] = ( scr.b[2] - scr.a[2])/4; 


	//a[1] =10; a[2] = 100; 
	//d[1] = 10; 	d[2] = 100; 

	for(i=1; i<=3 ; i++)
	{
		for(j=1; j<=4; j++)
		{
			for(k = 1; k<=n; k++)
			{
				switch (k)
				{
					case 1:
						{
							alfa = i-1;
							break;
						}
					case 2:
						{
							alfa = j-1;
							break;
						}

				}
				part[(i-1)*4+j].a[k] = a[k]+ alfa*d[k];
				part[(i-1)*4+j].b[k] = a[k]+ alfa*d[k] + d[k];
			}
		}
	}


//------test 3.4 start ------
	cstrMarc += "\r\n";
	cstrMarc += "\r\n";

//for(i=1; i<=12; i++)
//{
           
//	sprintf(temp, " part%02i: [%.2f, %.2f]x[%.2f, %.2f]: ",i, part[i].a[1], part[i].b[1], part[i].a[2], part[i].b[2] );
//	cstrMarc += temp;
//	cstrMarc += "\r\n";

//}
//	cstrMarc += "\r\n";
//	cstrMarc += "\r\n";

//------test 3.3 end --------

	iSum_TickCount =0;

	for(i=1; i<=12; i++)
	{
		strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ( ( ");
		
			sprintf(temp, " %.2f ", part[i].a[1] );
			strcat(	szSql, temp	);
			strcat(	szSql, "<= age AND age <=");
			sprintf(temp, " %.2f ", part[i].b[1] );
			strcat(	szSql, temp	);

			strcat(	szSql, ") AND (" );

			sprintf(temp, " %.2f ", part[i].a[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, 	"<= Income AND Income <=");
			sprintf(temp, " %.2f ", part[i].b[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, ") ) "	);

			lStartTimer = GetTickCount();
				ituples_cnt = zlExeSelect(TableName, szSql);
		    lEndTimer = GetTickCount() - lStartTimer ;
			
			iSum_TickCount += lEndTimer;

			sprintf(temp, " part%02i: [%.2f, %.2f]x[%.2f, %.2f]: ",i, part[i].a[1], part[i].b[1], part[i].a[2], part[i].b[2] );
			cstrMarc += temp;
            sprintf(temp, "Num_tuples = %ld,  GetTickCount = %ld", ituples_cnt, lEndTimer);
			cstrMarc += temp;
			cstrMarc += "\r\n";
	}

	    sprintf(temp, "       Sum of Tick Count of all Part = %ld", iSum_TickCount);
		cstrMarc += temp;
		cstrMarc += "\r\n";

//3.5 ---- Find which rectangle intersect the partition of all 12 = 4*3 partitions ----

//dddddddddddd
	cstrMarc += "\r\n";
	cstrMarc += "\r\n";
//dddddddddddd

	int index[13][101];  // i= 1 to 12 intersect with part[i] : index[i][1]=5, index[i][2]=7,index[i][3]=8, index[i][4]=15,...
	double p, q;
	bool bInterable =false;

	char buffer[20] = "";

	for(i= 1; i<=12; i++)
	{
		sprintf(part[i].suffix, " Part[%i]: " , i );
	}

	for(i= 1; i<=12; i++)
	{
		l=0;

		for(j= 1; j <=m ; j++) // m is the number of T[i]'s
		{
			for(k=1; k<=n; k++) //n is the number of dimensions 
			{
				p = __max(part[i].a[k], T[j].a[k]);
				q = __min(part[i].b[k], T[j].b[k]);

				if(p<q) //the intersection is not empty
				{
					bInterable = true; //must intersect for all dimensions
				} //if(p<q)
				else //the intersection is empty or p=q
				{
					bInterable = false; // it is enough there is a dimensions
					break;   //break k, because there is i0 such that p[i0] >=q[i0]  
				}

			}//for(k=1; k<=n; k++)

			if(bInterable) //if intersectable
			{
				l++;
				index[i][l] = j;
				sprintf(buffer, ",%i", j);
				strcat(part[i].suffix, buffer);
			}

		}//for(j= 1; j <=m ; j++)v

		cstrMarc += part[i].suffix;						 
	    cstrMarc += "\r\n";

	}//for(i= 1; i<=12; i++)

	cstrMarc += "#################";
	cstrMarc += "\r\n";
    cstrMarc += "\r\n";


//3.6 ------------------- Clustering -----------------------
		
	ZLRECT * partT[101];
	int clsNum =0;


//----for test ----
	ZLRECT * pT = new ZLRECT [101];
//----for test ----

	for(i= 1; i<=12; i++)
	{
		sprintf(part[i].suffix, " Part[%i]: " , i ); 
		//?? for debug ? WHY part[i].suffix?  NOT partT[i].suffix
		// Yes, for debug!
	}

	for(i= 1; i<=12; i++)
	{
		for(j=1; j<=100; j++)
		{
			index[i][j] = 0;
		}
	}

	for(i= 1; i<=12; i++)
	{
		l=0;

		for(j= 1; j <=m ; j++) // m is the number of T[i]'s
		{
			//###########
			if(T[j].cn <=0 ) //?? add .cn !=0 , Not, repeat
			{				 //YES! do it here
				for(k=1; k<=n; k++) //n is the number of dimensions 
				{
					p = __max(part[i].a[k], T[j].a[k]);   //?? replace "intersect" by "center in"
					q = __min(part[i].b[k], T[j].b[k]);

					if(p<q) //the intersection is not empty
					{
						bInterable = true;
					} //if(p<q)
					else //the intersection is empty or p=q
					{
						bInterable = false;
						break;   //break k, because there is i0 such that p[i0] >=q[i0]  
					}

				}//for(k=1; k<=n; k++)

				if(bInterable) //if intersectable
				{
					l++;
					index[i][l] = j;
					sprintf(buffer, ",%i", j);
					strcat(part[i].suffix, buffer); // save the index j of T[j] 
													//that intersect with part[i]

					//T[j].cn = i;                  // do not change the value of .cn
													// also let it be 0; ?? or -1
													// change it in the proc zlClusterPart();

					partT[l] = &T[j]; // the address of (T[j]) assign to (partT[l]);
									  // there is only the ADDRESS. 

									  // NOT change .suf1st, .sufend, .cn, .bsn, ... 
									  // So, to call other 2 functions , 
									  // we need to pay attention to it.
									  // Where {partT[l]'s} are the subset of {T[j]'s}
									  // that intersect with part[i].
									  
									  // ?? whether or not change the values of 
									  // .suf1st, .sufend, .cn, .bsn, ... in partT[l]'s
				}//if(bInterable) //if intersectable					 
			}//if(T[j].cn <=0 )

			//################

		}//for(j= 1; j <=m ; j++)v

		cstrMarc += part[i].suffix;						 
	    cstrMarc += "\r\n";
		// up to now we obtain all T[j]'s that in Part[i], and it index: index[i][l]
			//call the function : zlClusterPart( ZLRECT ** T, ZLRECT ** S); 
		if(l>0)
		{
		  ///////- NOT use this one: clsNum = zlClusterPart( partT, l, S, m, clsNum, n ); 
		  
		  clsNum = zlClusterPart( partT, l, T, m, clsNum, n );  
			//- where m is the new one that the is the number of T[i]'s 
		    //-     old m ==100, but new m may be 98, 96
		    //- that is removed all subsets of S[i]'s
			//- partT[i] is only the address of some T[i]'s that intersect with part[i]
			
			//----------for tset
				//for(int ijk =1; ijk <=l; ijk ++)
				//{
				//	pT[ijk] = *partT[ijk];

				//	pT[ijk].suf1st = ijk;
				//	pT[ijk].sufend = ijk;
				//	//pT[ijk].cn = 0;
				//	//pT[ijk].bsn = l;


			//	}
			    //double all_v = zlVolumeOfUnion(l, 2, pT );
			//-----------for tset
		}
	}//for(i= 1; i<=12; i++)


//---------ttest----------
	cstrMarc += "\r\n";
	cstrMarc += "\r\n";
    int iclsNum =0;
	int iallNum =0;

	for(i=1; i<= clsNum; i++)
	{
		iclsNum =0;

		sprintf(temp, "cluster %02i : ", i);
		cstrMarc += temp;

		for(j=1; j<=m; j++)
		{
			if(T[j].cn == i)
			{
				sprintf(temp, ", %02i", j);
				cstrMarc += temp;
				iclsNum ++;
			}			
		}
		sprintf(temp, "; iclsNum = %02i ", iclsNum);
		cstrMarc += temp;
		iallNum = iallNum + iclsNum; 

		cstrMarc += "\r\n";

	}

		sprintf(temp, " iallNum = %02i ", iallNum);
		cstrMarc += temp;
		cstrMarc += "\r\n";

//---------ttest----------



	/***************

	for(i= 1; i<=12; i++)
	{
		l=0;

		for(j= 1; j <=m ; j++) // m is the number of T[i]'s
		{
			for(k=1; k<=n; k++) //n is the number of dimensions 
			{
				p = __max(part[i].a[k], T[j].a[k]);
				q = __min(part[i].b[k], T[j].b[k]);

				if(p<q) //the intersection is not empty
				{
					bInterable = true;
				} //if(p<q)
				else //the intersection is empty or p=q
				{
					bInterable = false;
					break;   //break k, because there is i0 such that p[i0] >=q[i0]  
				}

			}//for(k=1; k<=n; k++)

			if(bInterable)  //if intersectable: //the forst T[j] is intersected with part[i]
			{				//the forst T[j] is intersected with part[i]
				l++;
				index[i][l] = j;
				sprintf(buffer, ",%i", j);
				strcat(part[i].suffix, buffer);
				T[j].cn = i;   

				for(int ll =1; ll<=100; ll++)
				{
					if(index[i][ll] = 0) // the last indes[i][j] that is 0
						break;   //break for(int ll =1; ll<=100; ll++)

					//if T[i] is intersected with T[index[i][ll]]
					for(int jj=1; jj <=m; jj++) // find out all T[jj] that intersect with T[index[i][ll]]
					{
						if(T[jj].cn ==0 && jj !=ll ) // it do not belong to any cluster
						{
							//--- see it do or not intersect with T[jj]
							for(int kk=1; kk<=n; kk++) //n is the number of dimensions 
							{
								int p1 = __max(T[index[i][ll]].a[kk], T[jj].a[kk]);
								int q1 = __min(T[index[i][ll]].b[kk], T[jj].b[kk]);

								if(p1<q1) //the intersection is not empty
								{
									bInterable1 = true;
								} //if(p<q)
								else //the intersection is empty or p=q
								{
									bInterable1 = false;
									break;   //break k, because there is i0 such that p[i0] >=q[i0]  
								}

							}//for(kk=1; kk<=n; kk++)

							if(bInterable1) //if intersectable
							{
								l++;  // l or ll ???
								index[i][l] = jj;
								sprintf(buffer, ",%i", jj);
								strcat(part[i].suffix, buffer);
							}
							//---8888

						} //if(T[jj].cn ==0)
					
						
					}//for(int ij=1; ij <=m; ij++)

				}//for(int ll =1; ll<=100; ll++)

			}//if(bInterable)  //if intersectable: //the forst T[j] is intersected with part[i]


		}//for(j= 1; j <=m ; j++)v

		cstrMarc += part[i].suffix;						 
	    cstrMarc += "\r\n";

	}//for(i= 1; i<=12; i++)
***************/








	//---------------^^^^^ the algorithms ^^^^^^^------------
	
	for(i=1; i<=12; i++)
	{
		//delete [] part[i].a;
		//delete [] part[i].b;
	}

	CFile file;

	if(file.Open("E:\\Paper2\\CLMB_census2D\\cluster_100_census2D.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
	{
		file.Write(cstrMarc, cstrMarc.GetLength() +1 );
	}
	file.Close();

		
	AfxMessageBox("Test OK!");
	zlCloseDB();

	m = old_m;
	for(i=1; i<=m; i++)
	{
		//delete [] T[i].a ;
		//delete [] T[i].b ;
	}

	// delete m initial rectagles randomly from [15, 90]x[0, 350000]
	for(i=1; i<=m; i++)
	{
		//delete [] S[i].a ;
		//delete [] S[i].b ;
	}

	//delete [] scr.a ;
	//delete [] scr.b ;	
}//void CMainFrame::OnViewCluster100_old() 

//////////////////////////////////////////////
//////////////////////////////////////////////
//
//
//////////////////////////////////////////////
///////////////////////////////////////////////
void CMainFrame::OnViewCluster100() 
{
	
	if(!zlOpenDB())
	{
		AfxMessageBox("zlOpenDB() err!");
		zlCloseDB();
	}

	long lStartTimer = GetTickCount();
	long lEndTimer;

	long lALL_StartTimer = GetTickCount();
	long lALL_EndTimer;
	int  iALL_TickCount = 0;

	int m = 100; //20; //10; //9;    //10;  //the number of rectangles 
	int n = COL_NUM; //2;	//104;   //the dimensions of space
	double Totall_v =0.0; // Totall_v = v(U Si )
	int i, j;
	int old_m = m;
    RESULT_LEARNING RstLng[ WORKLOAD_NUM  +1];

	//Seed the random-number generator with current time
	srand( (unsigned)time( NULL ) );
	
	int iRandom = rand()%100;

	ZLRECT * S = new ZLRECT[m+1]; //S[m+1];
	ZLRECT * T = new ZLRECT[m+1]; //T[m+1];
	//-- NOT use the following definition: 
	//      ZLRECT ** T = new ( ZLRECT (*[m+1]) ); //T[m+1];

	//----------- 1. Get m initial rectangles from DB
	// [15, 90]x[-25897, 347998]: the domain of the table CLMB_census2D
    //15 <=	Age <= 90	
    //-25897 <= income <=347998
 
	int iQryIdx =1;

	int longTicks =0, shortTicks =0;
	int f_rst= 0, shortTicks_rst = 0; //2003/4/5
    char tmp[512] = "";
	double  fCol[COL_NUM+1];		//Elevation
	SDWORD cbCol[COL_NUM+1]; 

	int		sN,  sf,  sf_rst,  sshortTicks_rst,  sshortTicks,  slongTicks;
	SDWORD cbN, cbf, cbf_rst, cbshortTicks_rst, cbshortTicks, cblongTicks;
	double	sr;	
	SDWORD cbr;
	sf_rst =0;  sshortTicks_rst=0;

	UCHAR szSqlAllLearningRows[] = "SELECT * FROM Census2D_T0100_B_Learning_P0178"; //census 2dim 
	//UCHAR szSqlAllLearningRows[] = " SELECT * FROM Census2D_T0100_B_OPT "; //census 2dim 

	SQLFreeStmt(hstmt, SQL_DROP);
	retcode = SQLAllocStmt(hdbc, &hstmt); ///Statement handle 
	if(retcode != SQL_SUCCESS)
		AfxMessageBox("1. Get m initial rectangles from DB, Error!" ); //return -1;

	SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
	SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
	
	longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, szSqlAllLearningRows, SQL_NTS);
	longTicks = GetTickCount() - longTicks;

	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO ) 
	{    //	retcode = SQLExecDirect for DATA_Top100_Census2D_Profile
		
		int iRowCount;
		SDWORD *  RowCountPtr = new SDWORD ;
		retcode = SQLRowCount(hstmt, RowCountPtr);						 
		iRowCount = * RowCountPtr;
		//iTupleNum = iRowCount;
		//iSizeProfile = iRowCount; // here only size of profile, 218, 436, 872, //100,200, ...,2000
		delete RowCountPtr;
		
		// Bind columns 1,2,3,4, ..., 104
		for(i = 0; i <COL_NUM+1; i++)
		{
			fCol[i] =0.0;
			cbCol[i] = 0; 
		}
		// Bind columns 1,2,3,4 ,.., COL_NUM
		for(i = 0; i <COL_NUM; i++)
			SQLBindCol(hstmt, i+1, SQL_C_DOUBLE, &fCol[i],0, &cbCol[i]); //SQL_C_SSHORT

		SQLBindCol(hstmt, COL_NUM+1, SQL_C_SLONG, &sN,0, &cbN); //SQL_C_SSHORT
		SQLBindCol(hstmt, COL_NUM+2, SQL_C_DOUBLE, &sr,0, &cbr); //SQL_C_SSHORT
		SQLBindCol(hstmt, COL_NUM+3, SQL_C_SLONG, &sf,0, &cbf); //SQL_C_SSHORT

		SQLBindCol(hstmt, COL_NUM+4, SQL_C_SLONG, &sf_rst,0, &cbf_rst); //SQL_C_SSHORT
		SQLBindCol(hstmt, COL_NUM+5, SQL_C_SLONG, &sshortTicks_rst,0, &cbshortTicks_rst); //SQL_C_SSHORT
		SQLBindCol(hstmt, COL_NUM+6, SQL_C_SLONG, &sshortTicks,0, &cbshortTicks); //SQL_C_SSHORT
		SQLBindCol(hstmt, COL_NUM+7, SQL_C_SLONG, &slongTicks,0, &cblongTicks); //SQL_C_SSHORT
		
		iRowCount =0;
		while (TRUE) 
		{
			retcode = SQLFetch(hstmt);

			if (retcode == SQL_ERROR)
			{
				//show_error();
				wsprintf(tmp, "%ld", iRowCount);
				//int i = iRowCount;
				AfxMessageBox("SQLFetch Error !!!!!!");
						//break; //99.8.26
			}

			if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
			{
				
				for(i = 1; i<=COL_NUM; i++)
				{
					RstLng[iQryIdx].q[i] = fCol[i-1];
				}
				
				RstLng[iQryIdx].N		= sN;
				RstLng[iQryIdx].r		= (float) sr;
				RstLng[iQryIdx].f		= sf;
				RstLng[iQryIdx].f_rst = sf_rst;
				RstLng[iQryIdx].shortTicks_rst = sshortTicks_rst;
				RstLng[iQryIdx].longTicks = slongTicks;	 
				RstLng[iQryIdx].shortTicks = sshortTicks; 

				sf_rst =0;  
				sshortTicks_rst=0;

				iQryIdx++;

				if(retcode == SQL_SUCCESS_WITH_INFO)
				{
					wsprintf(tmp, "%ld", retcode);
					AfxMessageBox(tmp);
				}
					
			} 
			else 
			{
				break;
			}

		}   ///while (TRUE)
	}//	retcode = SQLExecDirect  for DATA_Top100_Census2D_Profile


//////////////////////// 11111111111111111 ///////////////////////
	//assigned the rectangles from RstLng[i]

lALL_StartTimer = GetTickCount();
	
	for(i=1; i<=m; i++)
	{
		for(j= 1; j <=1; j++)
		{
			// 15<= Age <= 90
			S[i].a[j] = RstLng[i].q[j] - RstLng[i].r ; 
			if(S[i].a[j] < 15)
				S[i].a[j] = 15;

			S[i].b[j] = RstLng[i].q[j] + RstLng[i].r; 
			if(S[i].b[j] >90)
				S[i].b[j] = 90;
		}

		for(j= 2; j <=n; j++)
		{
			//income is in [0, 347998]
			S[i].a[j] = RstLng[i].q[j] - RstLng[i].r;
			if(S[i].a[j] < -25897 )
				S[i].a[j] = -25897 ;

			S[i].b[j] = RstLng[i].q[j] + RstLng[i].r; 
			if(S[i].b[j]> 347998)
				S[i].b[j] = 347998;
		}

		S[i].v =1;
		for(j=1; j<=n; j++)
		{
			S[i].v *= (S[i].b[j]-S[i].a[j]);

		}
		sprintf(S[i].suffix, "%d", i);
		S[i].suf1st = i;
		S[i].sufend = i;
		S[i].cn =0;
		//S[i].bsn = i; //2005.4.8
		S[i].bsn = 0; //2005.4.8

	}

lALL_EndTimer = GetTickCount()-lALL_StartTimer;
iALL_TickCount += lALL_EndTimer;
	


	char temp[512] = "";
	CString cstrMarc = "";

//------test 1 start ------
for(i=1; i<=m; i++)
{
           
	//sprintf(temp, " S%02i: [%.2f, %.2f]x[%.2f, %.2f]: ",i, S[i].a[1], S[i].b[1], S[i].a[2], S[i].b[2] );
	//cstrMarc += temp;
	//cstrMarc += "\r\n";

}
	cstrMarc += "\r\n";
	cstrMarc += "\r\n";

//------test 1 end --------

///////////////// 222222222222222222222 //////////////////////////
//2. Eliminating redundant squares temporarily
lALL_StartTimer = GetTickCount();

	bool rmvable =false;
    int l=1; 
	int k;

	rmvable =false;
	for(i=1; i<=m; i++)
	{
		for(k=1; k<=m; k++)
		{
		   // for each i, see ?? S[i] in S[k], for all k:  i!=k and S[k] is not removed
		   // this wan can avoid the situation S[i] ==S[k]. say, S[8] == S[65]
           // then in the case of S[8] == S[65], the loop of () will be dead loop

		   //if(i != k )  // 2005.4.8
		   if( i != k && S[k].bsn == 0) // 2005.4.8 
		   {
				for(j=1; j<=n; j++)
				{
					 // if S[i] is the subset of S[k], 
					if( (S[k].a[j]<=S[i].a[j]) && (S[i].b[j]<=S[k].b[j] ))
					{
						rmvable = true;
					}
					else
					{
						rmvable = false;
						break; //break j, for next k
					}
				} //for(j= 1; j <=n; j++)
				
				if(rmvable) //there is a k such that Si is in Sk 
				{
						//-------test 2---
							sprintf(temp, " S[%ld] cover, REMOVE S[%i] = [%.2f, %.2f]x[%.2f, %.2f]: ", k, i, S[i].a[1], S[i].b[1], S[i].a[2], S[i].b[2] );
							cstrMarc += temp;
							cstrMarc += "\r\n";

						//-------test 2---
					S[i].bsn = k; // s[i] is in s[k], IMPORTANT. bsn = Big Set Number
					break;  // break k and then for next i
				}
		   } //if(i != k)

		}//for(k=1; i<=m; k++)

		if( (rmvable == false) || (l==1 && i==m && rmvable) ) //cannot be removed
		{
			//T[l] = S[i];
			// :==: is the same as :==:
			//memset(&T[l], 0, sizeof(ZLRECT));
			//memcpy(&T[l], &S[i], sizeof(ZLRECT));
			
			for(j= 1; j <=n; j++)
			{
				T[l].a[j] = S[i].a[j];
				T[l].b[j] = S[i].b[j]; 
			}
			T[l].v=S[i].v;

			sprintf(T[l].suffix, "%d", l);
			T[l].suf1st = l;
			T[l].sufend = l;
			T[l].cn = 0;
			//T[l].bsn = l;  // 2004.4.13
			T[l].bsn = 0;  // 2004.4.13

			S[i].bsn= 10000+l; // the remainder of S[i]: S[i].bsn = l +10000; 
							   // where l is the index of T[l]. i.e. S[i] is the subset of T[l]
			l++;
		}
	}//for(i=1; i<=m; i++)

lALL_EndTimer = GetTickCount()-lALL_StartTimer;
iALL_TickCount += lALL_EndTimer;

//------test 3 start ------
/****
	cstrMarc += "\r\n";
	cstrMarc += "\r\n";


for(i=1; i<=l-1; i++)
{
           
	sprintf(temp, " T%02i: [%.2f, %.2f]x[%.2f, %.2f]: ",i, T[i].a[1], T[i].b[1], T[i].a[2], T[i].b[2] );
	cstrMarc += temp;
	cstrMarc += "\r\n";

}
	cstrMarc += "\r\n";
	cstrMarc += "\r\n";
****/
//------test 3 end --------


	//3. Select * from 4 cases;
	//SELECT * FROM CLMB_census2D where (20 <= Age and Age <= 50) AND (3000 <= Income and Income <= 60000)
	
	
	
	char szSql[12048] = "";
	int  ituples_cnt = 0;
	char TableName[] = "CLUM_census2D";
	int iSum_TickCount = 0;
    int iSum_TuplesCount =0;
	//3.0 select * FROM  ALL TABLE: SELECT * FROM CLMB_census2D, 
	
	strcpy(	szSql, 	" SELECT * FROM CLMB_census2D ");
	lStartTimer = GetTickCount();
		ituples_cnt = zlExeSelect(TableName, szSql);
	lEndTimer = GetTickCount() - lStartTimer ;

	cstrMarc += "\r\n";
    sprintf(temp, "SELECT * FROM CLMB_census2D: \r\n GetTickCount = %ld", lEndTimer);
	cstrMarc += temp;
	cstrMarc += "\r\n";
	sprintf(temp, " All Size of Table = %ld", ituples_cnt);
	cstrMarc += temp;
	cstrMarc += "\r\n";
	cstrMarc += "\r\n";



//3.1 select * each reach rectangle of all m S[i], 
	
	//m = min(m,l-1);
/*
	for(i = 1; i<=m; i++) // there are m rectangles
	{
		strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ( ( ");
		
			sprintf(temp, " %.2f ", T[i].a[1] );
			strcat(	szSql, temp	);
			strcat(	szSql, "<= age AND age <=");
			sprintf(temp, " %.2f ", T[i].b[1] );
			strcat(	szSql, temp	);

			strcat(	szSql, ") AND (" );

			sprintf(temp, " %.2f ", T[i].a[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, 	"<= Income AND Income <=");
			sprintf(temp, " %.2f ", T[i].b[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, ") ) "	);

			lStartTimer = GetTickCount();
				ituples_cnt = zlExeSelect(TableName, szSql);
		    lEndTimer = GetTickCount() - lStartTimer ;
			
			iSum_TickCount += lEndTimer;

            sprintf(temp, " Rectagle%i: [%.2f, %.2f]x[%.2f, %.2f]: ",i, T[i].a[1], T[i].b[1], T[i].a[2], T[i].b[2] );
			cstrMarc += temp;
            sprintf(temp, " GetTickCount = %ld", lEndTimer);
			cstrMarc += temp;
			cstrMarc += "\r\n";


	}
*/
	// m = m ==100

	for(i = 1; i<=m; i++) // there are m the originial rectangles S[1] to S[100]
	{
		strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ( ( ");
		
			sprintf(temp, " %.2f ", S[i].a[1] );
			strcat(	szSql, temp	);
			strcat(	szSql, "<= age AND age <=");
			sprintf(temp, " %.2f ", S[i].b[1] );
			strcat(	szSql, temp	);

			strcat(	szSql, ") AND (" );

			sprintf(temp, " %.2f ", S[i].a[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, 	"<= Income AND Income <=");
			sprintf(temp, " %.2f ", S[i].b[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, ") ) "	);

			lStartTimer = GetTickCount();
				ituples_cnt = zlExeSelect(TableName, szSql);
		    lEndTimer = GetTickCount() - lStartTimer ;
			
			iSum_TickCount += lEndTimer;
			iSum_TuplesCount += ituples_cnt;

            //sprintf(temp, " S%i: [%.2f, %.2f]x[%.2f, %.2f]: tuples_num = %ld ",i, T[i].a[1], T[i].b[1], T[i].a[2], T[i].b[2], ituples_cnt );
            sprintf(temp, " S%i: [%.2f, %.2f]x[%.2f, %.2f]: tuples_num = %ld ",i, S[i].a[1], S[i].b[1], S[i].a[2], S[i].b[2], ituples_cnt );
			cstrMarc += temp;
            sprintf(temp, " GetTickCount = %ld", lEndTimer);
			cstrMarc += temp;
			cstrMarc += "\r\n";
	}


	    sprintf(temp, "       Sum of Tick Count = %ld", iSum_TickCount);
		cstrMarc += temp;
		cstrMarc += "\r\n";
		sprintf(temp, "       Sum of Tuples Count = %ld", iSum_TuplesCount);
		cstrMarc += temp;
		cstrMarc += "\r\n";


	//3.2 select * From UNION of l T[i]: from T[1] to T[l] generally l<=m , 

	cstrMarc += "\r\n";
	cstrMarc += " 2. select * From UNION ";

	strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ");

	m=l-1;  // for T[i]
	for(i = 1; i<=m; i++)
	{
		strcat(	szSql, 	" ( ( ");

			sprintf(temp, " %.2f", T[i].a[1] );
			strcat(	szSql, temp	);
			strcat(	szSql, "<= age AND age <=");
			sprintf(temp, " %.2f", T[i].b[1] );
			strcat(	szSql, temp	);

			strcat(	szSql, ") AND (" );

			sprintf(temp, " %.2f", T[i].a[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, 	"<= Income AND Income <=");
			sprintf(temp, " %.2f", T[i].b[2] );
			strcat(	szSql, temp	);
		strcat(	szSql, ") ) "	);

		if(i<m)
			strcat(	szSql, " OR " );
	}

	//AfxMessageBox(szSql);

	lStartTimer = GetTickCount();
		ituples_cnt = zlExeSelect(TableName, szSql);
	lEndTimer = GetTickCount() - lStartTimer ;
	
	//iSum_TickCount += lEndTimer;

    sprintf(temp, " \r\n		The UNION¡¡spend TickCount = %ld", lEndTimer);
	cstrMarc += temp;
	cstrMarc += "\r\n";
    sprintf(temp, " \r\n		The UNION¡¡Tuples Number = %ld", ituples_cnt);
	cstrMarc += temp;
	cstrMarc += "\r\n";

	////3.0_1 select * FROM  ALL TABLE: SELECT * FROM CLMB_census2D, 
	
	//strcpy(	szSql, 	" SELECT * FROM CLMB_census2D ");
	//lStartTimer = GetTickCount();
	//	ituples_cnt = zlExeSelect(TableName, szSql);
	//lEndTimer = GetTickCount() - lStartTimer ;

	//cstrMarc += "\r\n";
    //sprintf(temp, "SELECT * FROM CLMB_census2D: GetTickCount = %ld", lEndTimer);
	//cstrMarc += temp;
	//cstrMarc += "\r\n";
	//cstrMarc += "\r\n";

	
///////////////////////// 333333333333333333 /////////////////////////////////
//3.3  select * From SCR, scr (Small Cover Rectagle,)

	cstrMarc += "\r\n";
	cstrMarc += " 3. select * From SCR ";

lALL_StartTimer = GetTickCount();

	ZLRECT scr;

	//scr.a = new double[n+1];
	//scr.b = new double[n+1];
	
	for(i=1; i<=n; i++ )
	{
		scr.a[i] = T[1].a[i];
		scr.b[i] = T[1].b[i];

		for(j=2; j<=m; j++ )
		{
			scr.a[i] = min(scr.a[i], T[j].a[i]);
			scr.b[i] = max(scr.b[i], T[j].b[i]);
		}
	}

lALL_EndTimer = GetTickCount()-lALL_StartTimer;
iALL_TickCount += lALL_EndTimer;

///===========
//scr.a[1] = 15; scr.b[1]=90;
//scr.a[2] =0 ; scr.b[2]= 347998;   

//scr.a[2] =-25897 ; scr.b[2]= 347998;  //-25897	347998
///===========


		strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ( ( ");
		
			sprintf(temp, " %.2f ", scr.a[1] );
			strcat(	szSql, temp	);
			strcat(	szSql, "<= age AND age <=");
			sprintf(temp, " %.2f ", scr.b[1] );
			strcat(	szSql, temp	);

			strcat(	szSql, ") AND (" );

			sprintf(temp, " %.2f ", scr.a[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, 	"<= Income AND Income <=");
			sprintf(temp, " %.2f ", scr.b[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, ") ) "	);


//strcpy(	szSql, 	" SELECT * FROM CLMB_census2D Where ( (15 <=Age AND Age<=90) AND (0 <=Income and income <= 347998) ) ");

			lStartTimer = GetTickCount();
				ituples_cnt = zlExeSelect(TableName, szSql);
		    lEndTimer = GetTickCount() - lStartTimer ;
			
			iSum_TickCount += lEndTimer;

			cstrMarc += "\r\n";
            sprintf(temp, "The Biggest scr: [%.2f, %.2f]x[%.2f, %.2f]: ", scr.a[1], scr.b[1], scr.a[2], scr.b[2] );
			cstrMarc += temp;

            sprintf(temp, "\r\n    scr  GetTickCount = %ld", lEndTimer);
			cstrMarc += temp;
			cstrMarc += "\r\n";
			sprintf(temp, "\r\n    scr  Tuples Number = %ld", ituples_cnt);
			cstrMarc += temp;
			cstrMarc += "\r\n";

			cstrMarc += "\r\n";


///////////////////////// 44444444444444444444 ///////////////////////
//3.4  ----   division 12 = 4*3 partition  of scr ----
//            select * From each partition,

lALL_StartTimer = GetTickCount();

	ZLRECT part[101]; //we use 1-12
    char   buffer[1024] ="";
	int iPartNum = 0;

	int ilnum =0, iaaallNum =0;

	CLearnIing6App * pApp = (CLearnIing6App * ) AfxGetApp();
	iPartNum = pApp->zlPartion(scr, n, T, m, iPartNum);			

lALL_EndTimer = GetTickCount()-lALL_StartTimer;
iALL_TickCount += lALL_EndTimer;


	for(i= 1; i<=iPartNum; i++)
	{
		sprintf(part[i].suffix, " Part[%i]: " , i ); 
	}

	for(i= 1; i<=iPartNum; i++)
	{
		ilnum =0;
		for(j=1; j<=m; j++)
		{
			if(T[j].bsn == i)
			{
				sprintf(buffer, ",%i", j);
				strcat(part[i].suffix, buffer); 
				ilnum ++;
			}
		}
		sprintf(buffer, "   part[%i]: ilnum= %i   ", i, ilnum);
		cstrMarc += buffer;			

		cstrMarc += part[i].suffix;						 
	    cstrMarc += "\r\n";
	    cstrMarc += "\r\n";

       iaaallNum +=ilnum;

	}

		sprintf(buffer, "   iallNum = %i", iaaallNum);
		cstrMarc += buffer;						 
	    cstrMarc += "\r\n";




	CFile file;

	//if(file.Open("E:\\Paper2\\CLMB_census2D\\cluster_100_census2D_OPT_414.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
	//if(file.Open("E:\\Paper2\\CLMB_census2D\\cluster_100_census2D.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
	//{
	//	file.Write(cstrMarc, cstrMarc.GetLength() +1 );
	//}
	//file.Close();

    //AfxMessageBox("OnViewCluster100 OK!");

//return;










/********************************
	//ZLRECT part[13]; //we use 1-12

	for(i=1; i<=12; i++)
	{
		//part[i].a = new double[n+1];
		//part[i].b = new double[n+1];
	}

	//int * a = new int[n+1];
	double * a = new double[n+1];

	double * d = new double[n+1];
	int alfa;
	int ishort =0, ilong =0;
	//a[1] =15; a[2] = -25897; 

	//d[1] = (90-15)/3; 	d[2] = ( 347998-(-25897) )/4; 

	if(scr.b[1] - scr.a[1] <= scr.b[2] - scr.a[2] )
	{
		//ishort = 1;
		//ilong  = 2;
		a[1] = scr.a[1]; 
		a[2] = scr.a[2]; 

		d[1] = (scr.b[1] - scr.a[1])/3; 	
		d[2] = ( scr.b[2] - scr.a[2])/4; 

	}
	else
	{
		//ishort = 2;
		//ilong  = 1;
		a[2] = scr.a[1]; 
		a[1] = scr.a[2]; 

		d[2] = (scr.b[1] - scr.a[1])/3; 	
		d[1] = ( scr.b[2] - scr.a[2])/4; 
	}
	//a[1] = scr.a[1]; 
	//a[2] = scr.a[2]; 

	//d[1] = (scr.b[1] - scr.a[1])/3; 	
	//d[2] = ( scr.b[2] - scr.a[2])/4; 


	//a[1] =10; a[2] = 100; 
	//d[1] = 10; 	d[2] = 100; 

	for(i=1; i<=3 ; i++)
	{
		for(j=1; j<=4; j++)
		{
			for(k = 1; k<=n; k++)
			{
				switch (k)
				{
					case 1:
						{
							alfa = i-1;
							break;
						}
					case 2:
						{
							alfa = j-1;
							break;
						}

				}
				part[(i-1)*4+j].a[k] = a[k]+ alfa*d[k];
				part[(i-1)*4+j].b[k] = a[k]+ alfa*d[k] + d[k];
			}
		}
	}

***************************/




//------test 3.4 start ------
//	cstrMarc += "\r\n";
//	cstrMarc += "\r\n";
//	CString cstrPart ;

//for(i=1; i<=12; i++)
//{
           
//	sprintf(temp, " part[%02i]: [%.2f, %.2f]x[%.2f, %.2f]: ",i, part[i].a[1], part[i].b[1], part[i].a[2], part[i].b[2] );
//	cstrPart += temp;
//    cstrPart += "\r\n";

//}

//	AfxMessageBox(cstrPart);
//	cstrMarc += "\r\n";
//	cstrMarc += "\r\n";

//------test 3.3 end --------

	iSum_TickCount =0;
	iSum_TuplesCount =0;
/**************
	for(i=1; i<=12; i++)
	{
		strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ( ( ");
		
			sprintf(temp, " %.2f ", part[i].a[1] );
			strcat(	szSql, temp	);
			strcat(	szSql, "<= age AND age <=");
			sprintf(temp, " %.2f ", part[i].b[1] );
			strcat(	szSql, temp	);

			strcat(	szSql, ") AND (" );

			sprintf(temp, " %.2f ", part[i].a[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, 	"<= Income AND Income <=");
			sprintf(temp, " %.2f ", part[i].b[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, ") ) "	);

			lStartTimer = GetTickCount();
				ituples_cnt = zlExeSelect(TableName, szSql);
		    lEndTimer = GetTickCount() - lStartTimer ;
			
			iSum_TickCount += lEndTimer;
			iSum_TuplesCount += ituples_cnt;

			sprintf(temp, " part[%02i]: [%.2f, %.2f]x[%.2f, %.2f]: ",i, part[i].a[1], part[i].b[1], part[i].a[2], part[i].b[2] );
			cstrMarc += temp;
            sprintf(temp, "Num_tuples = %ld,  GetTickCount = %ld", ituples_cnt, lEndTimer);
			cstrMarc += temp;
			cstrMarc += "\r\n";
	}

	    sprintf(temp, "       Sum of Tick Count of all Part = %ld", iSum_TickCount);
		cstrMarc += temp;
		cstrMarc += "\r\n";
		sprintf(temp, "       Sum of Tuples Count = %ld", iSum_TuplesCount);
		cstrMarc += temp;
		cstrMarc += "\r\n";
********************/


//3.5 ---- Find which rectangle intersect the partition of all 12 = 4*3 partitions ----

//dddddddddddd
	cstrMarc += "\r\n";
	cstrMarc += "\r\n";
//dddddddddddd

	int index[101][101];  // i= 1 to 12 intersect with part[i] : index[i][1]=5, index[i][2]=7,index[i][3]=8, index[i][4]=15,...
	double p, q;
	bool bInterable =false;

	//char buffer[20] = "";

	//for(i= 1; i<=12; i++)
	for(i= 1; i<=iPartNum; i++)
	{
		sprintf(part[i].suffix, " Part[%i]: " , i );
	}

	cstrMarc += "#################";
	cstrMarc += "\r\n";
    cstrMarc += "\r\n";

//////////////////////////////////////////////////////////////////



/////////////////////// 555555555555555 /////////////////////
//3.6 ------------------- Clustering -----------------------
// we use the method of "Center IN " to clustering
	
	ZLRECT * partT[101];
	//int clsNum =0;  //2005.3.16
	//int clsNum =1000; ////2005.3.16 , only for intersections
	//int clsNum =12; ////2005.3.24 , only for intersections
	int clsNum = iPartNum; //2005.4.14

	double center =0.0;
//----for test ----
	ZLRECT * pT = new ZLRECT [101];
//----for test ----

	//for(i= 1; i<=12; i++)
	for(i= 1; i<=iPartNum; i++)
	{
		sprintf(part[i].suffix, " Part[%i]: " , i ); 
		//?? for debug ? WHY part[i].suffix?  NOT partT[i].suffix
		// Yes, for debug!
	}

lALL_StartTimer = GetTickCount();

	//for(i= 1; i<=12; i++)
	for(i= 1; i<=iPartNum; i++)
	{
		for(j=1; j<=100; j++)
		{
			index[i][j] = 0;
		}
	}


////// ~~~~~~~~ Finding all T[j]'s that center are in part[i].
	
	for(i= 1; i<=iPartNum; i++)
	{
		l=0;
		for(j= 1; j <=m ; j++) // m is the number of T[i]'s
		{
			if(T[j].bsn == i && T[j].cn <=0)
			{
					l++;
					index[i][l] = j;
					sprintf(buffer, ",%i", j);
					strcat(part[i].suffix, buffer); // save the index j of T[j] 

					T[j].cn = i;                   //2005.3.16, use it again.

					partT[l] = &T[j]; // the address of (T[j]) assign to (partT[l]);

			}
		}

		cstrMarc += part[i].suffix;						 
	    cstrMarc += "\r\n";

		if(l>0)
		{
		  clsNum = zlClusterPart( partT, l, T, m, clsNum, n );  
		}


	}
	
lALL_EndTimer = GetTickCount()-lALL_StartTimer;
iALL_TickCount += lALL_EndTimer;

	/******************************
	for(i= 1; i<=12; i++)
	{
		l=0;

		for(j= 1; j <=m ; j++) // m is the number of T[i]'s
		{
			//###########
			if(T[j].cn <=0 ) //?? add .cn !=0 , Not, repeat
			{				 //YES! do it here
				for(k=1; k<=n; k++) //n is the number of dimensions 
				{
					//p = __max(part[i].a[k], T[j].a[k]);   //?? replace "intersect" by "center in"
					//q = __min(part[i].b[k], T[j].b[k]);   //YES , using "Center in"	
					
					center = (double)(T[j].a[k] + T[j].b[k])/2.0;

					//if(p<q) //the intersection is not empty					
					if( (part[i].a[k]<=center) && (center<= part[i].b[k]) ) //the Center in the part[i]
					{
						bInterable = true;
					} //if(p<q)
					else //the intersection is empty or p=q
					{
						bInterable = false;
						break;   //break k, because there is i0 such that p[i0] >=q[i0]  
					}

				}//for(k=1; k<=n; k++)

				if(bInterable) //if intersectable
				{
					l++;
					index[i][l] = j;
					sprintf(buffer, ",%i", j);
					strcat(part[i].suffix, buffer); // save the index j of T[j] 
													//that intersect with part[i]

					//T[j].cn = i;                  // do not change the value of .cn
													// also let it be 0; ?? or -1
													// change it in the proc zlClusterPart();

					T[j].cn = i;                   //2005.3.16, use it again.
												   // change it to T[j].cn = 1000 +i when it intersect with some others


					partT[l] = &T[j]; // the address of (T[j]) assign to (partT[l]);
									  // there is only the ADDRESS. 

									  // NOT change .suf1st, .sufend, .cn, .bsn, ... 
									  // So, to call other 2 functions , 
									  // we need to pay attention to it.
									  // Where {partT[l]'s} are the subset of {T[j]'s}
									  // that intersect with part[i].
									  
									  // ?? whether or not change the values of 
									  // .suf1st, .sufend, .cn, .bsn, ... in partT[l]'s
				}//if(bInterable) //if intersectable					 
			}//if(T[j].cn <=0 )

			//################

		}//for(j= 1; j <=m ; j++)v

		cstrMarc += part[i].suffix;						 
	    cstrMarc += "\r\n";
		// up to now we obtain all T[j]'s that in Part[i], and it index: index[i][l]
			//call the function : zlClusterPart( ZLRECT ** T, ZLRECT ** S); 
		if(l>0)
		{
		  ///////- NOT use this one: clsNum = zlClusterPart( partT, l, S, m, clsNum, n ); 
		  //------ We use T at 3 para, not use S 

		  clsNum = zlClusterPart( partT, l, T, m, clsNum, n );  
			//- where m is the new one that the is the number of T[i]'s 
		    //-     old m ==100, but new m may be 98, 96
		    //- that is removed all subsets of S[i]'s
			//- partT[i] is only the address of some T[i]'s that intersect with part[i]
			
			//----------for tset
				//for(int ijk =1; ijk <=l; ijk ++)
				//{
				//	pT[ijk] = *partT[ijk];

				//	pT[ijk].suf1st = ijk;
				//	pT[ijk].sufend = ijk;
				//	//pT[ijk].cn = 0;
				//	//pT[ijk].bsn = l;


			//	}
			    //double all_v = zlVolumeOfUnion(l, 2, pT );
			//-----------for tset
		}
	}//for(i= 1; i<=12; i++)
****************/


//---------ttest start ----------
	cstrMarc += "\r\n";
	cstrMarc += "\r\n";
    int iclsNum =0;
	int iallNum =0;

	for(i=1; i<= clsNum; i++)
	{
		iclsNum =0;

		sprintf(temp, "cluster[%02i] : ", i);
		cstrMarc += temp;
		cstrMarc += "\r\n";

		for(j=1; j<=m; j++)
		{
			if(T[j].cn == i)
			{
				//sprintf(temp, ", %02i", j);
				sprintf(temp, " T[%02i],T[%02i].bsn =%02i;  ", j, j, T[j].bsn );
				cstrMarc += temp;
				iclsNum ++;
			}			
		}


		if(iclsNum >0)
		{
			cstrMarc += "\r\n";
			sprintf(temp, "    iclsNum = %02i ", iclsNum);
			cstrMarc += temp;
			iallNum = iallNum + iclsNum; 
			cstrMarc += "\r\n";
			cstrMarc += "\r\n";

		}

	}

		sprintf(temp, " iallNum = %02i ", iallNum);
		cstrMarc += temp;
		cstrMarc += "\r\n";

//---------ttest end ----------


//////////////////////// 666666666666666666 ////////////////////////////


// 3.7 ------------------- Clustering S[] -----------------------
//    obtain all cluster number of S[i] (where i=1 to 100)


//---------ttest S[] start ----------
	cstrMarc += "\r\n";
	cstrMarc += "\r\n";

    iclsNum =0;
	iallNum =0;

	//for(i=1; i<= clsNum; i++)
	{
		iclsNum =0;

		sprintf(temp, "Cluster[%02i] : ", i);
		cstrMarc += temp;

		//for(j=1; j<=m; j++)
		//for(j=0; j<=100; j++)
		for(j=1; j<=old_m; j++)
		{
			//if(S[j].cn == i)
			{
				sprintf(temp, " S[%02i],S[%02i].bsn =%02i;  ", j, j, S[j].bsn );
				cstrMarc += temp;
				iclsNum ++;
			}	
			cstrMarc += "\r\n";
		}
		sprintf(temp, "; iclsNum = %02i ", iclsNum);
		cstrMarc += temp;
		iallNum = iallNum + iclsNum; 

		cstrMarc += "\r\n";

	}

		sprintf(temp, " iallNum = %02i ", iallNum);
		cstrMarc += temp;
		cstrMarc += "\r\n";

//---------ttest S[] end ----------


lALL_StartTimer = GetTickCount();	
	


	for(i=1; i<= old_m; i++)
	{

		do 
		{
			if(S[i].bsn > 10000)
			{	
				S[i].cn = T[S[i].bsn-10000].cn;
				break;
			}
			else
			{
				k = S[i].bsn;
				S[i].bsn = S[k].bsn;
			}

		} while (true);

	}

	
lALL_EndTimer = GetTickCount()-lALL_StartTimer;
iALL_TickCount += lALL_EndTimer;


//---------ttest S[] start ----------
	cstrMarc += "\r\n";
	cstrMarc += "\r\n";

    iclsNum =0;
	iallNum =0;

		cstrMarc += "For S[i] ";
		cstrMarc += "\r\n";
		cstrMarc += "\r\n";

	for(i=1; i<= clsNum; i++)
	{
		iclsNum =0;


		sprintf(temp, "Cluster[%02i]: ", i);
		cstrMarc += temp;
		cstrMarc += "\r\n";

		//for(j=1; j<=m; j++)
		//for(j=0; j<=100; j++)
		for(j=1; j<=old_m; j++)
		{
			if(S[j].cn == i)
			{
				//sprintf(temp, " S[%02i],S[%02i].bsn =%02i;  ", j, j, S[j].bsn );
				sprintf(temp, "S[%02i], ", j  );
				cstrMarc += temp;
				iclsNum ++;
			}			
		}
		
		if(iclsNum >0)
		{
			cstrMarc += "\r\n";
			sprintf(temp, "    iclsNum = %02i ", iclsNum);
			cstrMarc += temp;
			iallNum = iallNum + iclsNum; 
			cstrMarc += "\r\n";
		}

	}

		sprintf(temp, " iallNum = %02i ", iallNum);
		cstrMarc += temp;
		cstrMarc += "\r\n";

//---------ttest S[] end ----------


///////////////////////////  77777777777777  ///////////////////////////

// 3.8 ------------------- obtain scr's according to the Clusters of  S[] -----------------------
//15 <=	Age <= 90	
//-25897 <= income <=	347998

lALL_StartTimer = GetTickCount();	
	

iSum_TickCount = 0;
iSum_TuplesCount =0;

	double * Sum_v_S = new double [100 +1];//[clsNum +1];
	ZLRECT * scr_CLS = new ZLRECT[100+1]; //[clsNum +1];  
	
	for(i=1; i<=clsNum; i++)
	//for(i=1; i<=100; i++)
	{
		//scr_CLS[i].a = new double[n+1];
		//scr_CLS[i].b = new double[n+1];
		scr_CLS[i].v = 1.0;
		
		Sum_v_S[i] = 0.0;
		for(k=1; k<=old_m; k++) //old_m ==100
		{
			if(S[k].cn ==i)
			{
				Sum_v_S[i] += S[k].v;
			}

		}

	}

	for(i=1; i<=clsNum; i++ )
	//for(i=1; i<=100; i++ )
	{
			scr_CLS[i].a[1] = 90;
			scr_CLS[i].b[1] = 15;
			scr_CLS[i].a[2] = 347998;
			scr_CLS[i].b[2] = -25897;

		for(j=1; j<=n; j++)
		{
			for(k=1; k<=old_m; k++) // old_m ==100
			{
				if(S[k].cn ==i)
				{
					scr_CLS[i].a[j] = min(scr_CLS[i].a[j], S[k].a[j]);
					scr_CLS[i].b[j] = max(scr_CLS[i].b[j], S[k].b[j]);

				}

			}
			//scr_CLS[i].v *= (scr_CLS[i].b[j]-scr_CLS[i].a[j]) ;
		}

		for(j=1; j<=n; j++)
		{
			scr_CLS[i].v *= (scr_CLS[i].b[j]-scr_CLS[i].a[j]) ;
		}


	}

	
lALL_EndTimer = GetTickCount()-lALL_StartTimer;
iALL_TickCount += lALL_EndTimer;



	int nonzearo =0;
	cstrMarc += "\r\n";
	for(i = 1; i<=clsNum; i++) // there are clsNum scr's of cluster scr_CLS[1] to scr_CLS[clsNum]
	//for(i = 1; i<=100; i++) // there are clsNum scr's of cluster scr_CLS[1] to scr_CLS[clsNum]
	{
		nonzearo =0;
		for(j=1; j<=old_m; j++)
		{
			if(S[j].cn ==i)
			{
				//sprintf(temp, " ,S[%02i] ", j );
				//cstrMarc += temp;
				nonzearo ++;
			}
		}
      if(nonzearo !=0)
	  {
		strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ( ( ");
		
			sprintf(temp, " %.2f ", scr_CLS[i].a[1] );
			strcat(	szSql, temp	);
			strcat(	szSql, "<= age AND age <=");
			sprintf(temp, " %.2f ", scr_CLS[i].b[1] );
			strcat(	szSql, temp	);

			strcat(	szSql, ") AND (" );

			sprintf(temp, " %.2f ", scr_CLS[i].a[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, 	"<= Income AND Income <=");
			sprintf(temp, " %.2f ", scr_CLS[i].b[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, ") ) "	);

			lStartTimer = GetTickCount();
				ituples_cnt = zlExeSelect(TableName, szSql);
		    lEndTimer = GetTickCount() - lStartTimer ;
			
			iSum_TickCount += lEndTimer;
			iSum_TuplesCount += ituples_cnt;

            //sprintf(temp, " S%i: [%.2f, %.2f]x[%.2f, %.2f]: tuples_num = %ld ",i, T[i].a[1], T[i].b[1], T[i].a[2], T[i].b[2], ituples_cnt );
            sprintf(temp, " scr_CLS%02i: [%.2f, %.2f]x[%.2f, %.2f], .v =%.2f : tuples_num = %ld ",i, scr_CLS[i].a[1], scr_CLS[i].b[1], scr_CLS[i].a[2], scr_CLS[i].b[2], scr_CLS[i].v, ituples_cnt );
			cstrMarc += temp;
            sprintf(temp, " GetTickCount = %ld", lEndTimer);
			cstrMarc += temp;
			cstrMarc += "\r\n";
	  }
	}


	    sprintf(temp, "       Sum of Tick Count = %ld", iSum_TickCount);
		cstrMarc += temp;
		cstrMarc += "\r\n";

		sprintf(temp, "       Sum of Tuples Count = %ld", iSum_TuplesCount);
		cstrMarc += temp;
		cstrMarc += "\r\n";
		cstrMarc += "\r\n";


/////////////////////////// 8888888888888888888 ///////////////////////////

// 3.9 ------------------- 2nd Clustering for obtained scr's  -----------------------
   	
lALL_StartTimer = GetTickCount();	
	
	for(i = 1; i<=clsNum; i++)
	{
		scr_CLS[i].bsn = 1; // means has elements S[i]
	}

	for(i = 1; i<=clsNum; i++) 
	{
		if(scr_CLS[i].v <= 4*Sum_v_S[i]  ) // CETA = 3, 4, 5,10 5*Sum_v_S[i] //10*Sum_v_S[i]
		{

			sprintf(temp, " scr_CLS[%02i].v = %.02f <<<=== 3*Sum_v_S[%02i] =%.02f;  ",i,scr_CLS[i].v, i, Sum_v_S[i] );
			cstrMarc += temp;
			cstrMarc += "\r\n";
			sprintf(temp, "						scr_CLS[%02i].v/Sum_v_S[%02i]= %.02f   ",i,i, scr_CLS[i].v/Sum_v_S[i] );
			cstrMarc += temp;
			cstrMarc += "\r\n";
			cstrMarc += "\r\n";

		}else // that is: scr_CLS[i].v/Sum_v_S[i]  > 5        //10
		{
            k=0;
			for(j=1; j<=old_m; j++)
			{
				if(S[j].cn == i)
				{
					S[j].cn =0;
					k++;
				}
				//idx[k]=j;
				//k++;
				//scr_CLS[i].bsn = 0; 
			}

			scr_CLS[i].bsn = 0; 
			scr_CLS[i].cn =k;


			sprintf(temp, " scr_CLS[%02i].v = %.02f >>>>>> 3*Sum_v_S[%02i] =%.02f ",i,scr_CLS[i].v, i, Sum_v_S[i] );
			cstrMarc += temp;
			cstrMarc += "\r\n";
			sprintf(temp, "						scr_CLS[%02i].v/Sum_v_S[%02i]= %.02f   ",i,i, scr_CLS[i].v/Sum_v_S[i] );
			cstrMarc += temp;
			cstrMarc += "\r\n";
			cstrMarc += "\r\n";
		}
	}

	//clustering again if one is the subset of another, then togather them 
////// ~~~~~~~~ Finding all scr_CLS[i]'s that center are in part[i].
   //3.9.1 for  scr_CLS[i] which =1
   //3.9.2 for S[i]'s whicn .cn =0

	rmvable =false;
	for(i=1; i<=clsNum; i++)
	{
		if(scr_CLS[i].bsn ==1)
		{
			for(j=1; j<=clsNum; j++)
			{
				if( (i != j) && scr_CLS[j].bsn ==1 )
				{
					for(k=1; k<=n; k++) //n is the number of dimensions 
					{
						
						center = (double)(scr_CLS[j].a[k] + scr_CLS[j].b[k])/2.0;
						//if the Center of scr_CLS[j] is in scr_CLS[i]
						if( (scr_CLS[i].a[k]<=center) && (center<= scr_CLS[i].b[k]) ) //the Center in the part[i]
						{
							bInterable = true;
						} //
						else // 
						{
							bInterable = false;
							break;   //break k,   
						}
					}//for(k=1; k<=n; k++)


				}//for(k=1; k<=n; k++)
				if(rmvable) //there is a k such that scr_CLS[i] is in scr_CLS[k] 
				{
						//-------test 2---
							sprintf(temp, " Center of scr_CLS[%ld] IN scr_CLS[%i]: [%.2f, %.2f]x[%.2f, %.2f]: ", j, i, scr_CLS[j].a[1], scr_CLS[j].b[1], scr_CLS[j].a[2], scr_CLS[j].b[2] );
							cstrMarc += temp;
							cstrMarc += "\r\n";

						//-------test 2---
					scr_CLS[j].bsn = 0; // the center of scr_CLS[j] is in scr_CLS[i], IMPORTANT
					for(l=1; l<=old_m; l++)
					{
						if(S[l].cn ==j)
							S[l].cn=i;
					}

					break;  // break k and then for next i
				}


			}//for(j=1; j<=clsNum; j++)
		}//if(scr_CLS[i].bsn ==1)
	}//(i=1; i<=clsNum; i++)


	for(i=1; i<=clsNum; i++)
	{
		if(scr_CLS[i].bsn ==1)
		{
			for(k=1; k<=old_m; k++)
			{
				
				if(S[k].cn ==0 )
				{
					for(j=1; j<=n; j++)
					{
						 // if S[k] is the subset of scr_CLS[i], 
						if( (scr_CLS[i].a[j]<=S[k].a[j]) && (S[k].b[j]<=scr_CLS[i].b[j] ))
						{
							rmvable = true;
						}
						else
						{
							rmvable = false;
							break; //break j, for next k
						}
					} //for(j= 1; j <=n; j++)
				
				
					if(rmvable) //there is a k such that scr_CLS[i] is in scr_CLS[k] 
					{
							//-------test 2---
								sprintf(temp, " scr_CLS[%ld] cover, REMOVE S[%i]= [%.2f, %.2f]x[%.2f, %.2f]: ", i, k, S[k].a[1], S[k].b[1], S[k].a[2], S[k].b[2] );
								cstrMarc += temp;
								cstrMarc += "\r\n";

							//-------test 2---

								S[k].cn = i;						

						break;  // break k and then for next i
					}
				}
			}
		}
	}

	
lALL_EndTimer = GetTickCount()-lALL_StartTimer;
iALL_TickCount += lALL_EndTimer;



// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!! for a scr_CLS[i] : if scr_CLS[i].bsn ==0, that is, if scr_CLS[%02i].v/Sum_v_S[%02i] > 5
// !!!!! and it contain >8 S[i]'s then part it 12 parts.
	 cstrMarc += "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
	 cstrMarc += "\r\n";


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

///////////////////////// 9999999999999999999 /////////////////////////////
// 3.10 ------------------- obtain 2nd SCR's according to the Clusters of  S[] -----------------------
//15 <=	Age <= 90	
//-25897 <= income <=	347998
	cstrMarc += "\r\n";
	cstrMarc += "\r\n";


lALL_StartTimer = GetTickCount();	
	

	iSum_TickCount = 0;
	iSum_TuplesCount =0;

	//double * Sum_v_S = new double [clsNum +1];
	//ZLRECT * scr_CLS = new ZLRECT[clsNum +1];  
	
	for(i=1; i<=clsNum; i++)
	{
		scr_CLS[i].v = 1.0;
		
		Sum_v_S[i] = 0.0;
		for(k=1; k<=old_m; k++) //old_m ==100
		{
			if(S[k].cn ==i)
			{
				Sum_v_S[i] += S[k].v;
			}

		}

	}

	for(i=1; i<=clsNum; i++ )
	{
			scr_CLS[i].a[1] = 90;
			scr_CLS[i].b[1] = 15;
			scr_CLS[i].a[2] = 347998;
			scr_CLS[i].b[2] = -25897;

		for(j=1; j<=n; j++)
		{
			for(k=1; k<=old_m; k++) // old_m ==100
			{
				if(S[k].cn ==i)
				{
					scr_CLS[i].a[j] = min(scr_CLS[i].a[j], S[k].a[j]);
					scr_CLS[i].b[j] = max(scr_CLS[i].b[j], S[k].b[j]);

				}

			}
			//scr_CLS[i].v *= (scr_CLS[i].b[j]-scr_CLS[i].a[j]) ;
		}

		for(j=1; j<=n; j++)
		{
			scr_CLS[i].v *= (scr_CLS[i].b[j]-scr_CLS[i].a[j]) ;
		}
		scr_CLS[i].bsn = 0; //2005.04.15

	}

 int allNonzero =0;
 nonzearo = 0;

	cstrMarc += "\r\n";
	for(i = 1; i<=clsNum; i++) // there are clsNum scr's of cluster scr_CLS[1] to scr_CLS[clsNum]
	{
			nonzearo = 0;
			sprintf(temp, " .bsn = %i, scr_CLS%02i: [%.2f, %.2f]x[%.2f, %.2f], .v =%.2f : ",scr_CLS[i].bsn, i, scr_CLS[i].a[1], scr_CLS[i].b[1], scr_CLS[i].a[2], scr_CLS[i].b[2], scr_CLS[i].v );
			cstrMarc += temp;	
	        cstrMarc += "\r\n";

			cstrMarc += "    Cover: ";

			for(j=1; j<=old_m; j++)
			{
				if(S[j].cn ==i)
				{
					sprintf(temp, " ,S[%02i] ", j );
					cstrMarc += temp;
					nonzearo ++;
				}
			}
	        cstrMarc += "\r\n";

       allNonzero += nonzearo;

      if(nonzearo !=0)
	  {
		  scr_CLS[i].bsn = 1;
		/***************
		strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ( ( ");
		
			sprintf(temp, " %.2f ", scr_CLS[i].a[1] );
			strcat(	szSql, temp	);
			strcat(	szSql, "<= age AND age <=");
			sprintf(temp, " %.2f ", scr_CLS[i].b[1] );
			strcat(	szSql, temp	);

			strcat(	szSql, ") AND (" );

			sprintf(temp, " %.2f ", scr_CLS[i].a[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, 	"<= Income AND Income <=");
			sprintf(temp, " %.2f ", scr_CLS[i].b[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, ") ) "	);

			lStartTimer = GetTickCount();
				ituples_cnt = zlExeSelect(TableName, szSql);
		    lEndTimer = GetTickCount() - lStartTimer ;
			
			iSum_TickCount += lEndTimer;
			iSum_TuplesCount += ituples_cnt;

            //sprintf(temp, " S%i: [%.2f, %.2f]x[%.2f, %.2f]: tuples_num = %ld ",i, T[i].a[1], T[i].b[1], T[i].a[2], T[i].b[2], ituples_cnt );
            sprintf(temp, "		tuples_num = %ld ", ituples_cnt );
			cstrMarc += temp;
			cstrMarc += "\r\n";

            sprintf(temp, "		GetTickCount = %ld", lEndTimer);
			cstrMarc += temp;
			cstrMarc += "\r\n";
			cstrMarc += "\r\n";
			**************/
	  }

	}
	// SUB SET
	//  if scr_CLS[i] is the subset of scr_CLS[k], label it and remove it
	for(i=1; i<=clsNum; i++)
	{
	  if(scr_CLS[i].bsn ==1)
	  {

		for(k=1; k<=clsNum; k++)
		{
		   if( (i != k) && scr_CLS[k].bsn ==1 )
		   {
				for(j=1; j<=n; j++)
				{
					 // if scr_CLS[i] is the subset of scr_CLS[k], 
					//if( (scr_CLS[k].a[j]<=scr_CLS[i].a[j]) && (scr_CLS[i].b[j]<=scr_CLS[k].b[j] ))
					//if the center of scr_CLS[i] is in scr_CLS[k],
					
					if( (scr_CLS[k].a[j]<=scr_CLS[i].a[j]) && (scr_CLS[i].b[j]<=scr_CLS[k].b[j] ))		
					{
						rmvable = true;
					}
					else
					{
						rmvable = false;
						break; //break j, for next k
					}
				} //for(j= 1; j <=n; j++)
				
				if(rmvable) //there is a k such that scr_CLS[i] is in scr_CLS[k] 
				{
						//-------test 2---
							sprintf(temp, " scr_CLS[%ld] cover, REMOVE scr_CLS[%i]: [%.2f, %.2f]x[%.2f, %.2f]: ", k, i, scr_CLS[i].a[1], scr_CLS[i].b[1], scr_CLS[i].a[2], scr_CLS[i].b[2] );
							cstrMarc += temp;
							cstrMarc += "\r\n";

						//-------test 2---
					scr_CLS[i].bsn = 0; // s[i] is in s[k], IMPORTANT
					for(l=1; l<=old_m; l++)
					{
						if(S[l].cn ==i)
							S[l].cn=k;
					}

					break;  // break k and then for next i
				}

		   } //if(i != k)

		}//for(k=1; i<=m; k++)
	  }

	}//for(i=1; i<=m; i++)
////??????????
	int iMinTupleNum = 0;
	int iStart =0;
	int iAllTuplesNum =0;
	int iInterIdx =0;

	for(i = 1; i<=clsNum; i++) // there are clsNum scr's of cluster scr_CLS[1] to scr_CLS[clsNum]
	{
		if(scr_CLS[i].bsn ==1)
		{
			strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ( ( ");
		
			sprintf(temp, " %.2f ", scr_CLS[i].a[1] );
			strcat(	szSql, temp	);
			strcat(	szSql, "<= age AND age <=");
			sprintf(temp, " %.2f ", scr_CLS[i].b[1] );
			strcat(	szSql, temp	);

			strcat(	szSql, ") AND (" );

			sprintf(temp, " %.2f ", scr_CLS[i].a[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, 	"<= Income AND Income <=");
			sprintf(temp, " %.2f ", scr_CLS[i].b[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, ") ) "	);

			lStartTimer = GetTickCount();
				ituples_cnt = zlExeSelect(TableName, szSql);
		    lEndTimer = GetTickCount() - lStartTimer ;
			
			iSum_TickCount += lEndTimer;
			iSum_TuplesCount += ituples_cnt;

			sprintf(temp, " scr_CLS[%02i]: [%.2f, %.2f]x[%.2f, %.2f], .v =%.2f : ",i, scr_CLS[i].a[1], scr_CLS[i].b[1], scr_CLS[i].a[2], scr_CLS[i].b[2], scr_CLS[i].v );
			cstrMarc += temp;	
	        cstrMarc += "\r\n";
            sprintf(temp, "		tuples_num = %ld ", ituples_cnt );
			cstrMarc += temp;
			cstrMarc += "\r\n";

            sprintf(temp, "		GetTickCount = %ld", lEndTimer);
			cstrMarc += temp;
			cstrMarc += "\r\n";
			cstrMarc += "\r\n";

			iMinTupleNum = ituples_cnt;
			iStart = i;
			scr_CLS[i].cn = ituples_cnt;
			iSum_TuplesCount += ituples_cnt;
			break;
		}

	}

	for(i = iStart+1; i<=clsNum; i++) // 
	{
		if(scr_CLS[i].bsn ==1 && i > iStart)
		{
			iInterIdx = 0;
			bInterable =false;

			 for(j = iStart; j<i; j++)   // when i=5, j = 1,2,3,4 if iStart =1
			 {
				//////////////
				if(scr_CLS[j].bsn ==1 )
				{

					for(k=1; k<=n; k++) //n is the number of dimensions 
					{
						p = __max(scr_CLS[i].a[k], scr_CLS[j].a[k]); // here we use "intersect"
						q = __min(scr_CLS[i].b[k], scr_CLS[j].b[k]);

						if(p<q) //the intersection is not empty
						{
							bInterable = true; //must intersect for all dimensions
						} //if(p<q)
						else //the intersection is empty or p=q
						{
							bInterable = false; // it is enough there is a dimensions
							break;   //break k, because there is i0 such that p[i0] >=q[i0]  
						}

					}//for(k=1; k<=n; k++)

					if(bInterable) //if intersectable
					{
						iMinTupleNum = __min(iMinTupleNum, scr_CLS[j].cn);
						iInterIdx = j;
						scr_CLS[i].cn = iMinTupleNum;
					}
				}
				////////////////

			 }

			if(iInterIdx ==0)   // if there is no one that is intersect with scr_CLS[i];
			{
				strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ( ( ");
				
					sprintf(temp, " %.2f ", scr_CLS[i].a[1] );
					strcat(	szSql, temp	);
					strcat(	szSql, "<= age AND age <=");
					sprintf(temp, " %.2f ", scr_CLS[i].b[1] );
					strcat(	szSql, temp	);

					strcat(	szSql, ") AND (" );

					sprintf(temp, " %.2f ", scr_CLS[i].a[2] );
					strcat(	szSql, temp	);
					strcat(	szSql, 	"<= Income AND Income <=");
					sprintf(temp, " %.2f ", scr_CLS[i].b[2] );
					strcat(	szSql, temp	);

				strcat(	szSql, ") ) "	);

					lStartTimer = GetTickCount();
						ituples_cnt = zlExeSelect(TableName, szSql);
					lEndTimer = GetTickCount() - lStartTimer ;
					
					iSum_TickCount += lEndTimer;
					iSum_TuplesCount += ituples_cnt;

					//sprintf(temp, " S%i: [%.2f, %.2f]x[%.2f, %.2f]: tuples_num = %ld ",i, T[i].a[1], T[i].b[1], T[i].a[2], T[i].b[2], ituples_cnt );
			sprintf(temp, " scr_CLS[%02i]: [%.2f, %.2f]x[%.2f, %.2f], .v =%.2f : ",i, scr_CLS[i].a[1], scr_CLS[i].b[1], scr_CLS[i].a[2], scr_CLS[i].b[2], scr_CLS[i].v );
			cstrMarc += temp;	
	        cstrMarc += "\r\n";
				
					sprintf(temp, "		tuples_num = %ld ", ituples_cnt );
					cstrMarc += temp;
					cstrMarc += "\r\n";

					sprintf(temp, "		GetTickCount = %ld", lEndTimer);
					cstrMarc += temp;
					cstrMarc += "\r\n";
					cstrMarc += "\r\n";

			}
			else  // if there is someone that is intersect with scr_CLS[i];
			{

////////////////////////////////////////////////
				strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ( ( ");
				
					sprintf(temp, " %.2f ", scr_CLS[i].a[1] );
					strcat(	szSql, temp	);
					strcat(	szSql, "<= age AND age <=");
					sprintf(temp, " %.2f ", scr_CLS[i].b[1] );
					strcat(	szSql, temp	);

					strcat(	szSql, ") AND (" );

					sprintf(temp, " %.2f ", scr_CLS[i].a[2] );
					strcat(	szSql, temp	);
					strcat(	szSql, 	"<= Income AND Income <=");
					sprintf(temp, " %.2f ", scr_CLS[i].b[2] );
					strcat(	szSql, temp	);

				strcat(	szSql, ") ) "	);

					lStartTimer = GetTickCount();
						ituples_cnt = zlExeSelect(TableName, szSql);
					lEndTimer = GetTickCount() - lStartTimer ;
					
					iSum_TickCount += lEndTimer;
					//iSum_TuplesCount += ituples_cnt;

					sprintf(temp, " SSSSSSSSS-T de scr_CLS[%i]: [%.2f, %.2f]x[%.2f, %.2f]: tuples_num = %ld ",i, scr_CLS[i].a[1], scr_CLS[i].b[1], scr_CLS[i].a[2], scr_CLS[i].b[2], ituples_cnt );
					
					//sprintf(temp, "		tuples_num = %ld ", ituples_cnt );
					cstrMarc += temp;
					cstrMarc += "\r\n";

					sprintf(temp, "		GetTickCount = %ld", lEndTimer);
					cstrMarc += temp;
					cstrMarc += "\r\n";
					cstrMarc += szSql;
					cstrMarc += "\r\n";

					cstrMarc += "\r\n";
//--------------------------------------------------

				strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ( ( ");
				
					sprintf(temp, " %.2f ", scr_CLS[iInterIdx].a[1] );
					strcat(	szSql, temp	);
					strcat(	szSql, "<= age AND age <=");
					sprintf(temp, " %.2f ", scr_CLS[iInterIdx].b[1] );
					strcat(	szSql, temp	);

					strcat(	szSql, ") AND (" );

					sprintf(temp, " %.2f ", scr_CLS[iInterIdx].a[2] );
					strcat(	szSql, temp	);
					strcat(	szSql, 	"<= Income AND Income <=");
					sprintf(temp, " %.2f ", scr_CLS[iInterIdx].b[2] );
					strcat(	szSql, temp	);

				strcat(	szSql, ") ) "	);

					lStartTimer = GetTickCount();
						ituples_cnt = zlExeSelect(TableName, szSql);
					lEndTimer = GetTickCount() - lStartTimer ;
					
					iSum_TickCount += lEndTimer;
					iSum_TuplesCount += ituples_cnt;

					sprintf(temp, "S - TTTTTT de scr_CLS[%i]: [%.2f, %.2f]x[%.2f, %.2f]: tuples_num = %ld ",iInterIdx, scr_CLS[iInterIdx].a[1], scr_CLS[iInterIdx].b[1], scr_CLS[iInterIdx].a[2], scr_CLS[iInterIdx].b[2], ituples_cnt );
					//sprintf(temp, "		tuples_num = %ld ", ituples_cnt );
					cstrMarc += temp;
					cstrMarc += "\r\n";

					sprintf(temp, "		GetTickCount = %ld", lEndTimer);
					cstrMarc += temp;
					cstrMarc += "\r\n";

					cstrMarc += szSql;
					cstrMarc += "\r\n";

					cstrMarc += "\r\n";





///////////////////////////////////////////////

				CLearnIing6App * pApp = (CLearnIing6App * ) AfxGetApp();
				int issNum = pApp->zlDiffRects(scr_CLS[i], scr_CLS[iInterIdx], 2);
				
				//````````````````````````
				//(a) Use between ¡­ and ¡­ 
				//	SELECT * FROM CLMB_census2D Where
				//	((Age between 15 and 85) AND (Income between 3000 and 113070))
				//	OR 		
				//	( (Age between 20 and 90) AND (Income between 2995 and 113065) ) 
 


				strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ");

				for(l = 1; l<=issNum; l++)
				{
					strcat(	szSql, 	" ( ( ");

						sprintf(temp, " Age between %f and %f", pApp->ss[l].a[1], pApp->ss[l].b[1]);
						strcat(	szSql, temp	);

						strcat(	szSql, ") AND (" );

						sprintf(temp, " Income between %f and %f", pApp->ss[l].a[2], pApp->ss[l].b[2]);
						strcat(	szSql, temp	);

					strcat(	szSql, ") ) "	);

					if(l<issNum)
						strcat(	szSql, " OR " );
				}

				AfxMessageBox(szSql);

				lStartTimer = GetTickCount();
					ituples_cnt = zlExeSelect(TableName, szSql);
				lEndTimer = GetTickCount() - lStartTimer ;
				
				iSum_TickCount += lEndTimer;
				iSum_TuplesCount += ituples_cnt;
			    scr_CLS[i].cn += ituples_cnt;


				sprintf(temp, " \r\n		The pApp->ss¡¡spend TickCount = %ld", lEndTimer);
				cstrMarc += temp;
				cstrMarc += "\r\n";
				sprintf(temp, " \r\n		The pApp->ss¡¡Tuples Number = %ld", ituples_cnt);				
				cstrMarc += temp;
				cstrMarc += "\r\n";
				cstrMarc += szSql;
				cstrMarc += "\r\n";

				cstrMarc += "-----------------------------\r\n";
				cstrMarc += "\r\n";


				//````````````````````````


			}


		}

	}




	int izero = 0;
	      	cstrMarc += "\r\n";	
			cstrMarc += "cluster0 : ";	

			for(j=1; j<=old_m; j++)
			{
				if(S[j].cn ==0)
				{
					sprintf(temp, " ,S[%02i] ", j );
					cstrMarc += temp;
					izero ++;
				}

			}
			cstrMarc += "\r\n";	
			cstrMarc += "\r\n";




	if(izero >0 )
	{
		for(i = 1; i<=old_m; i++) // there are m the originial rectangles S[1] to S[100]
		{

		        if(S[i].cn ==0)
				{
					strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ( ( ");
					
						sprintf(temp, " %.2f ", S[i].a[1] );
						strcat(	szSql, temp	);
						strcat(	szSql, "<= age AND age <=");
						sprintf(temp, " %.2f ", S[i].b[1] );
						strcat(	szSql, temp	);

						strcat(	szSql, ") AND (" );

						sprintf(temp, " %.2f ", S[i].a[2] );
						strcat(	szSql, temp	);
						strcat(	szSql, 	"<= Income AND Income <=");
						sprintf(temp, " %.2f ", S[i].b[2] );
						strcat(	szSql, temp	);
						strcat(	szSql, ") ) "	);

						lStartTimer = GetTickCount();
							ituples_cnt = zlExeSelect(TableName, szSql);
						lEndTimer = GetTickCount() - lStartTimer ;
						
						iSum_TickCount += lEndTimer;
						iSum_TuplesCount += ituples_cnt;

						//sprintf(temp, " S%i: [%.2f, %.2f]x[%.2f, %.2f]: tuples_num = %ld ",i, T[i].a[1], T[i].b[1], T[i].a[2], T[i].b[2], ituples_cnt );
						sprintf(temp, " S%i: [%.2f, %.2f]x[%.2f, %.2f]: \r\n tuples_num = %ld ",i, S[i].a[1], S[i].b[1], S[i].a[2], S[i].b[2], ituples_cnt );
						cstrMarc += temp;
						sprintf(temp, " GetTickCount = %ld", lEndTimer);
						cstrMarc += temp;
						cstrMarc += "\r\n";
				}
			}

	   }

	    sprintf(temp, "       Sum of Tick Count = %ld", iSum_TickCount);
		cstrMarc += temp;
		cstrMarc += "\r\n";

		sprintf(temp, "       Sum of Tuples Count = %ld", iSum_TuplesCount);
		cstrMarc += temp;
		cstrMarc += "\r\n";

		sprintf(temp, "       nonzero = %i, zero = %i", allNonzero , izero);
		cstrMarc += temp;
		cstrMarc += "\r\n";

	
lALL_EndTimer = GetTickCount()-lALL_StartTimer;
iALL_TickCount += lALL_EndTimer;

		sprintf(temp, "      iALL_TickCount = %i ,  ", iALL_TickCount );
		cstrMarc += temp;
		cstrMarc += "\r\n";

		sprintf(temp, "      iALL_TickCount - iSum_TickCount = %i ,  ", iALL_TickCount-iSum_TickCount );
		cstrMarc += temp;
		cstrMarc += "\r\n";




//---------------   the algorithms --------------------
//---------------^^^^^^^^^^^^^^^^^^^^^^^^^^------------
////////////////////////////////////////////////////////////////////////
	
		
//	CFile file;

	//if(file.Open("E:\\Paper2\\CLMB_census2D\\cluster_100_cen2D_OPT416.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
	if(file.Open("E:\\Paper2\\CLMB_census2D\\cluster_100_cen2D_416.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
	{
		file.Write(cstrMarc, cstrMarc.GetLength() +1 );
	}
	file.Close();

		
	AfxMessageBox("OnViewCluster100 OK!");
	zlCloseDB();





	delete [] Sum_v_S;

	for(i=1; i<=clsNum; i++)
	{
		//delete [] scr_CLS[i].a;
		//delete [] scr_CLS[i].b;
	}

	delete [] scr_CLS;

	for(i=1; i<=12; i++)
	{
		//delete [] part[i].a;
		//delete [] part[i].b;
	}

	m = old_m;
	for(i=1; i<=m; i++)
	{
		//delete [] T[i].a ;
		//delete [] T[i].b ;
	}

	// delete m initial rectagles randomly from [15, 90]x[0, 350000]
	for(i=1; i<=m; i++)
	{
		//delete [] S[i].a ;
		//delete [] S[i].b ;
	}

	//delete [] scr.a ;
	//delete [] scr.b ;	
}//void CMainFrame::OnViewCluster100() 



void CMainFrame::OnViewCluster100_BacK050413() 
{
	
	if(!zlOpenDB())
	{
		AfxMessageBox("zlOpenDB() err!");
		zlCloseDB();
	}

	long lStartTimer = GetTickCount();
	long lEndTimer;

	int m = 100; //20; //10; //9;    //10;  //the number of rectangles 
	int n = COL_NUM; //2;	//104;   //the dimensions of space
	double Totall_v =0.0; // Totall_v = v(U Si )
	int i, j;
	int old_m = m;
    RESULT_LEARNING RstLng[100 +1];

	//Seed the random-number generator with current time
	srand( (unsigned)time( NULL ) );
	
	int iRandom = rand()%100;

//char * * pGcdd;
//pGcdd = new ( char  (*[nPtrBufSize]) );
//	zlGetPartString(Marc->System.Gcdd, &pRtn, &nPtrBufSize, &nMaxStrSize)
//	bool CLibServerApp::zlGetPartString(char * inString, LPCHAR lpCharBuf, LPDWORD lpNumOfPtr, LPDWORD lpNumOfStr)
//the last 3 ones is return.
	
	ZLRECT * S = new ZLRECT[m+1]; //S[m+1];
	ZLRECT * T = new ZLRECT[m+1]; //T[m+1];
	//-- NOT use the following definition: 
	//      ZLRECT ** T = new ( ZLRECT (*[m+1]) ); //T[m+1];

	for(i=1; i<=m; i++)
	{
		//S[i].a = new double[n+1];
		//S[i].b = new double[n+1];

		//T[i].a = new double[n+1];
		//T[i].b = new double[n+1];
	}

/******
	//1. Get m initial rectagles randomly from [15, 90]x[0, 347998]: the table CLMB_census2D
	//The rand function returns a pseudorandom integer in the range 0 to RAND_MAX. 
  	//RAND_MAX is defined as the value 0x7fff = 32767.

	for(i=1; i<=m; i++)
	{

		for(j= 1; j <=1; j++)
		{
			// 15<= Age <= 90
			S[i].a[j] = rand()%90; 
			if(S[i].a[j] < 15)
				S[i].a[j] = 15;

			S[i].b[j] = S[i].a[j] + rand()%90 + 1; 
			if(S[i].b[j] >90)
				S[i].b[j] = 90;
		}

		for(j= 2; j <=n; j++)
		{
			//income is in [0, 347998]
			S[i].a[j] = rand()%350000;
			if(S[i].b[j]> 347998)
				S[i].b[j] = 347998;

			S[i].b[j] = S[i].a[j] + rand()%300 + 1; 
			if(S[i].b[j]> 350000)
				S[i].b[j] = 350000;
		}

		S[i].v =1;
		for(j=1; j<=n; j++)
		{
			S[i].v *= (S[i].b[j]-S[i].a[j]);

		}
		sprintf(S[i].suffix, "%d", i);
		S[i].suf1st = i;
		S[i].sufend = i;
		S[i].cn =0;
		S[i].bsn = i;
	}

  *****************/

	//----------- 1. Get m initial rectangles from DB
	// [15, 90]x[-25897, 347998]: the domain of the table CLMB_census2D
    //15 <=	Age <= 90	
    //-25897 <= income <=347998
 
	int iQryIdx =1;

	int longTicks =0, shortTicks =0;
	int f_rst= 0, shortTicks_rst = 0; //2003/4/5
    char tmp[512] = "";
	double  fCol[COL_NUM+1];		//Elevation
	SDWORD cbCol[COL_NUM+1]; 

	int		sN,  sf,  sf_rst,  sshortTicks_rst,  sshortTicks,  slongTicks;
	SDWORD cbN, cbf, cbf_rst, cbshortTicks_rst, cbshortTicks, cblongTicks;
	double	sr;	
	SDWORD cbr;
	sf_rst =0;  sshortTicks_rst=0;

	UCHAR szSqlAllLearningRows[] = "SELECT * FROM Census2D_T0100_B_Learning_P0178"; //census 2dim 
	//UCHAR szSqlAllLearningRows[] = " SELECT * FROM Census2D_T0100_B_OPT "; //census 2dim 

	SQLFreeStmt(hstmt, SQL_DROP);
	retcode = SQLAllocStmt(hdbc, &hstmt); ///Statement handle 
	if(retcode != SQL_SUCCESS)
		AfxMessageBox("1. Get m initial rectangles from DB, Error!" ); //return -1;

	SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
	SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
	
	longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, szSqlAllLearningRows, SQL_NTS);
	longTicks = GetTickCount() - longTicks;

	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO ) 
	{    //	retcode = SQLExecDirect for DATA_Top100_Census2D_Profile
		
		int iRowCount;
		SDWORD *  RowCountPtr = new SDWORD ;
		retcode = SQLRowCount(hstmt, RowCountPtr);						 
		iRowCount = * RowCountPtr;
		//iTupleNum = iRowCount;
		//iSizeProfile = iRowCount; // here only size of profile, 218, 436, 872, //100,200, ...,2000
		delete RowCountPtr;
		
		// Bind columns 1,2,3,4, ..., 104
		for(i = 0; i <COL_NUM+1; i++)
		{
			fCol[i] =0.0;
			cbCol[i] = 0; 
		}
		// Bind columns 1,2,3,4 ,.., COL_NUM
		for(i = 0; i <COL_NUM; i++)
			SQLBindCol(hstmt, i+1, SQL_C_DOUBLE, &fCol[i],0, &cbCol[i]); //SQL_C_SSHORT

		SQLBindCol(hstmt, COL_NUM+1, SQL_C_SLONG, &sN,0, &cbN); //SQL_C_SSHORT
		SQLBindCol(hstmt, COL_NUM+2, SQL_C_DOUBLE, &sr,0, &cbr); //SQL_C_SSHORT
		SQLBindCol(hstmt, COL_NUM+3, SQL_C_SLONG, &sf,0, &cbf); //SQL_C_SSHORT

		SQLBindCol(hstmt, COL_NUM+4, SQL_C_SLONG, &sf_rst,0, &cbf_rst); //SQL_C_SSHORT
		SQLBindCol(hstmt, COL_NUM+5, SQL_C_SLONG, &sshortTicks_rst,0, &cbshortTicks_rst); //SQL_C_SSHORT
		SQLBindCol(hstmt, COL_NUM+6, SQL_C_SLONG, &sshortTicks,0, &cbshortTicks); //SQL_C_SSHORT
		SQLBindCol(hstmt, COL_NUM+7, SQL_C_SLONG, &slongTicks,0, &cblongTicks); //SQL_C_SSHORT
		
		iRowCount =0;
		while (TRUE) 
		{
			retcode = SQLFetch(hstmt);

			if (retcode == SQL_ERROR)
			{
				//show_error();
				wsprintf(tmp, "%ld", iRowCount);
				//int i = iRowCount;
				AfxMessageBox("SQLFetch Error !!!!!!");
						//break; //99.8.26
			}

			if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
			{
				
				for(i = 1; i<=COL_NUM; i++)
				{
					RstLng[iQryIdx].q[i] = fCol[i-1];
				}
				
				RstLng[iQryIdx].N		= sN;
				RstLng[iQryIdx].r		= (float) sr;
				RstLng[iQryIdx].f		= sf;
				RstLng[iQryIdx].f_rst = sf_rst;
				RstLng[iQryIdx].shortTicks_rst = sshortTicks_rst;
				RstLng[iQryIdx].longTicks = slongTicks;	 
				RstLng[iQryIdx].shortTicks = sshortTicks; 

				sf_rst =0;  
				sshortTicks_rst=0;

				iQryIdx++;

				if(retcode == SQL_SUCCESS_WITH_INFO)
				{
					wsprintf(tmp, "%ld", retcode);
					AfxMessageBox(tmp);
				}
					
			} 
			else 
			{
				break;
			}

		}   ///while (TRUE)
	}//	retcode = SQLExecDirect  for DATA_Top100_Census2D_Profile


	//assigned the rectangles from RstLng[i]
	
	for(i=1; i<=m; i++)
	{
		for(j= 1; j <=1; j++)
		{
			// 15<= Age <= 90
			S[i].a[j] = RstLng[i].q[j] - RstLng[i].r ; 
			if(S[i].a[j] < 15)
				S[i].a[j] = 15;

			S[i].b[j] = RstLng[i].q[j] + RstLng[i].r; 
			if(S[i].b[j] >90)
				S[i].b[j] = 90;
		}

		for(j= 2; j <=n; j++)
		{
			//income is in [0, 347998]
			S[i].a[j] = RstLng[i].q[j] - RstLng[i].r;
			if(S[i].a[j] < -25897 )
				S[i].a[j] = -25897 ;

			S[i].b[j] = RstLng[i].q[j] + RstLng[i].r; 
			if(S[i].b[j]> 347998)
				S[i].b[j] = 347998;
		}

		S[i].v =1;
		for(j=1; j<=n; j++)
		{
			S[i].v *= (S[i].b[j]-S[i].a[j]);

		}
		sprintf(S[i].suffix, "%d", i);
		S[i].suf1st = i;
		S[i].sufend = i;
		S[i].cn =0;
		//S[i].bsn = i; //2005.4.8
		S[i].bsn = 0; //2005.4.8

	}
	


	char temp[512] = "";
	CString cstrMarc = "";

//------test 1 start ------
for(i=1; i<=m; i++)
{
           
	//sprintf(temp, " S%02i: [%.2f, %.2f]x[%.2f, %.2f]: ",i, S[i].a[1], S[i].b[1], S[i].a[2], S[i].b[2] );
	//cstrMarc += temp;
	//cstrMarc += "\r\n";

}
	cstrMarc += "\r\n";
	cstrMarc += "\r\n";

//------test 1 end --------


	//2. Eliminating redundant squares temporarily
	bool rmvable =false;
    int l=1; 
	int k;

	rmvable =false;
	for(i=1; i<=m; i++)
	{
		for(k=1; k<=m; k++)
		{
		   // for each i, see ?? S[i] in S[k], for all k:  i!=k and S[k] is not removed
		   // this wan can avoid the situation S[i] ==S[k]. say, S[8] == S[65]
           // then in the case of S[8] == S[65], the loop of () will be dead loop

		   //if(i != k )  // 2005.4.8
		   if( i != k && S[k].bsn == 0) // 2005.4.8 
		   {
				for(j=1; j<=n; j++)
				{
					 // if S[i] is the subset of S[k], 
					if( (S[k].a[j]<=S[i].a[j]) && (S[i].b[j]<=S[k].b[j] ))
					{
						rmvable = true;
					}
					else
					{
						rmvable = false;
						break; //break j, for next k
					}
				} //for(j= 1; j <=n; j++)
				
				if(rmvable) //there is a k such that Si is in Sk 
				{
						//-------test 2---
							sprintf(temp, " S[%ld] cover, REMOVE S[%i] = [%.2f, %.2f]x[%.2f, %.2f]: ", k, i, S[i].a[1], S[i].b[1], S[i].a[2], S[i].b[2] );
							cstrMarc += temp;
							cstrMarc += "\r\n";

						//-------test 2---
					S[i].bsn = k; // s[i] is in s[k], IMPORTANT. bsn = Big Set Number
					break;  // break k and then for next i
				}
		   } //if(i != k)

		}//for(k=1; i<=m; k++)

		if( (rmvable == false) || (l==1 && i==m && rmvable) ) //cannot be removed
		{
			//T[l] = S[i];
			// :==: is the same as :==:
			//memset(&T[l], 0, sizeof(ZLRECT));
			//memcpy(&T[l], &S[i], sizeof(ZLRECT));
			
			for(j= 1; j <=n; j++)
			{
				T[l].a[j] = S[i].a[j];
				T[l].b[j] = S[i].b[j]; 
			}
			T[l].v=S[i].v;

			sprintf(T[l].suffix, "%d", l);
			T[l].suf1st = l;
			T[l].sufend = l;
			T[l].cn = 0;
			T[l].bsn = l;
			//T[l]->bsn = l;
			S[i].bsn= 10000+l; // the remainder of S[i]: S[i].bsn = T[l].bsn +10000
							   // i.e. S[i] is the subset of T[l]
			l++;
		}
	}//for(i=1; i<=m; i++)


//------test 3 start ------
/****
	cstrMarc += "\r\n";
	cstrMarc += "\r\n";


for(i=1; i<=l-1; i++)
{
           
	sprintf(temp, " T%02i: [%.2f, %.2f]x[%.2f, %.2f]: ",i, T[i].a[1], T[i].b[1], T[i].a[2], T[i].b[2] );
	cstrMarc += temp;
	cstrMarc += "\r\n";

}
	cstrMarc += "\r\n";
	cstrMarc += "\r\n";
****/
//------test 3 end --------


	//3. Select * from 4 cases;
	//SELECT * FROM CLMB_census2D where (20 <= Age and Age <= 50) AND (3000 <= Income and Income <= 60000)
	
	
	
	char szSql[12048] ="";
	int  ituples_cnt = 0;
	char TableName[] = "CLUM_census2D";
	int iSum_TickCount = 0;
    int iSum_TuplesCount =0;
	//3.0 select * FROM  ALL TABLE: SELECT * FROM CLMB_census2D, 
	
	strcpy(	szSql, 	" SELECT * FROM CLMB_census2D ");
	lStartTimer = GetTickCount();
		ituples_cnt = zlExeSelect(TableName, szSql);
	lEndTimer = GetTickCount() - lStartTimer ;

	cstrMarc += "\r\n";
    sprintf(temp, "SELECT * FROM CLMB_census2D: \r\n GetTickCount = %ld", lEndTimer);
	cstrMarc += temp;
	cstrMarc += "\r\n";
	sprintf(temp, " All Size of Table = %ld", ituples_cnt);
	cstrMarc += temp;
	cstrMarc += "\r\n";
	cstrMarc += "\r\n";



//3.1 select * each reach rectangle of all m S[i], 
	
	//m = min(m,l-1);
/*
	for(i = 1; i<=m; i++) // there are m rectangles
	{
		strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ( ( ");
		
			sprintf(temp, " %.2f ", T[i].a[1] );
			strcat(	szSql, temp	);
			strcat(	szSql, "<= age AND age <=");
			sprintf(temp, " %.2f ", T[i].b[1] );
			strcat(	szSql, temp	);

			strcat(	szSql, ") AND (" );

			sprintf(temp, " %.2f ", T[i].a[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, 	"<= Income AND Income <=");
			sprintf(temp, " %.2f ", T[i].b[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, ") ) "	);

			lStartTimer = GetTickCount();
				ituples_cnt = zlExeSelect(TableName, szSql);
		    lEndTimer = GetTickCount() - lStartTimer ;
			
			iSum_TickCount += lEndTimer;

            sprintf(temp, " Rectagle%i: [%.2f, %.2f]x[%.2f, %.2f]: ",i, T[i].a[1], T[i].b[1], T[i].a[2], T[i].b[2] );
			cstrMarc += temp;
            sprintf(temp, " GetTickCount = %ld", lEndTimer);
			cstrMarc += temp;
			cstrMarc += "\r\n";


	}
*/
	// m = m ==100

	for(i = 1; i<=m; i++) // there are m the originial rectangles S[1] to S[100]
	{
		strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ( ( ");
		
			sprintf(temp, " %.2f ", S[i].a[1] );
			strcat(	szSql, temp	);
			strcat(	szSql, "<= age AND age <=");
			sprintf(temp, " %.2f ", S[i].b[1] );
			strcat(	szSql, temp	);

			strcat(	szSql, ") AND (" );

			sprintf(temp, " %.2f ", S[i].a[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, 	"<= Income AND Income <=");
			sprintf(temp, " %.2f ", S[i].b[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, ") ) "	);

			lStartTimer = GetTickCount();
				ituples_cnt = zlExeSelect(TableName, szSql);
		    lEndTimer = GetTickCount() - lStartTimer ;
			
			iSum_TickCount += lEndTimer;
			iSum_TuplesCount += ituples_cnt;

            //sprintf(temp, " S%i: [%.2f, %.2f]x[%.2f, %.2f]: tuples_num = %ld ",i, T[i].a[1], T[i].b[1], T[i].a[2], T[i].b[2], ituples_cnt );
            sprintf(temp, " S%i: [%.2f, %.2f]x[%.2f, %.2f]: tuples_num = %ld ",i, S[i].a[1], S[i].b[1], S[i].a[2], S[i].b[2], ituples_cnt );
			cstrMarc += temp;
            sprintf(temp, " GetTickCount = %ld", lEndTimer);
			cstrMarc += temp;
			cstrMarc += "\r\n";
	}


	    sprintf(temp, "       Sum of Tick Count = %ld", iSum_TickCount);
		cstrMarc += temp;
		cstrMarc += "\r\n";
		sprintf(temp, "       Sum of Tuples Count = %ld", iSum_TuplesCount);
		cstrMarc += temp;
		cstrMarc += "\r\n";


	//3.2 select * From UNION of l T[i]: from T[1] to T[l] generally l<=m , 

		cstrMarc += "\r\n";
		cstrMarc += " 2. select * From UNION ";

	strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ");

	m=l-1;  // for T[i]
	for(i = 1; i<=m; i++)
	{
		strcat(	szSql, 	" ( ( ");

			sprintf(temp, " %.2f", T[i].a[1] );
			strcat(	szSql, temp	);
			strcat(	szSql, "<= age AND age <=");
			sprintf(temp, " %.2f", T[i].b[1] );
			strcat(	szSql, temp	);

			strcat(	szSql, ") AND (" );

			sprintf(temp, " %.2f", T[i].a[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, 	"<= Income AND Income <=");
			sprintf(temp, " %.2f", T[i].b[2] );
			strcat(	szSql, temp	);
		strcat(	szSql, ") ) "	);

		if(i<m)
			strcat(	szSql, " OR " );
	}

	//AfxMessageBox(szSql);

	lStartTimer = GetTickCount();
		ituples_cnt = zlExeSelect(TableName, szSql);
	lEndTimer = GetTickCount() - lStartTimer ;
	
	//iSum_TickCount += lEndTimer;

    sprintf(temp, " \r\n		The UNION¡¡spend TickCount = %ld", lEndTimer);
	cstrMarc += temp;
	cstrMarc += "\r\n";
    sprintf(temp, " \r\n		The UNION¡¡Tuples Number = %ld", ituples_cnt);
	cstrMarc += temp;
	cstrMarc += "\r\n";

	////3.0_1 select * FROM  ALL TABLE: SELECT * FROM CLMB_census2D, 
	
	//strcpy(	szSql, 	" SELECT * FROM CLMB_census2D ");
	//lStartTimer = GetTickCount();
	//	ituples_cnt = zlExeSelect(TableName, szSql);
	//lEndTimer = GetTickCount() - lStartTimer ;

	//cstrMarc += "\r\n";
    //sprintf(temp, "SELECT * FROM CLMB_census2D: GetTickCount = %ld", lEndTimer);
	//cstrMarc += temp;
	//cstrMarc += "\r\n";
	//cstrMarc += "\r\n";
	
	//3.3  select * From SCR, scr (Small Cover Rectagle,)

		cstrMarc += "\r\n";
		cstrMarc += " 3. select * From SCR ";

	ZLRECT scr;

	//scr.a = new double[n+1];
	//scr.b = new double[n+1];
	
	for(i=1; i<=n; i++ )
	{
		scr.a[i] = T[1].a[i];
		scr.b[i] = T[1].b[i];

		for(j=2; j<=m; j++ )
		{
			scr.a[i] = min(scr.a[i], T[j].a[i]);
			scr.b[i] = max(scr.b[i], T[j].b[i]);
		}
	}

///===========
//scr.a[1] = 15; scr.b[1]=90;
//scr.a[2] =0 ; scr.b[2]= 347998;   

//scr.a[2] =-25897 ; scr.b[2]= 347998;  //-25897	347998
///===========


		strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ( ( ");
		
			sprintf(temp, " %.2f ", scr.a[1] );
			strcat(	szSql, temp	);
			strcat(	szSql, "<= age AND age <=");
			sprintf(temp, " %.2f ", scr.b[1] );
			strcat(	szSql, temp	);

			strcat(	szSql, ") AND (" );

			sprintf(temp, " %.2f ", scr.a[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, 	"<= Income AND Income <=");
			sprintf(temp, " %.2f ", scr.b[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, ") ) "	);


//strcpy(	szSql, 	" SELECT * FROM CLMB_census2D Where ( (15 <=Age AND Age<=90) AND (0 <=Income and income <= 347998) ) ");

			lStartTimer = GetTickCount();
				ituples_cnt = zlExeSelect(TableName, szSql);
		    lEndTimer = GetTickCount() - lStartTimer ;
			
			iSum_TickCount += lEndTimer;

			cstrMarc += "\r\n";
            sprintf(temp, "The Biggest scr: [%.2f, %.2f]x[%.2f, %.2f]: ", scr.a[1], scr.b[1], scr.a[2], scr.b[2] );
			cstrMarc += temp;

            sprintf(temp, "\r\n    scr  GetTickCount = %ld", lEndTimer);
			cstrMarc += temp;
			cstrMarc += "\r\n";
			sprintf(temp, "\r\n    scr  Tuples Number = %ld", ituples_cnt);
			cstrMarc += temp;
			cstrMarc += "\r\n";

			cstrMarc += "\r\n";

//3.4  ----   division 12 = 4*3 partition  of scr ----
//            select * From each partition,

	ZLRECT part[13]; //we use 1-12
	//ZLRECT part[13]; //we use 1-12

	for(i=1; i<=12; i++)
	{
		//part[i].a = new double[n+1];
		//part[i].b = new double[n+1];
	}

	//int * a = new int[n+1];
	double * a = new double[n+1];

	double * d = new double[n+1];
	int alfa;
	int ishort =0, ilong =0;
	//a[1] =15; a[2] = -25897; 

	//d[1] = (90-15)/3; 	d[2] = ( 347998-(-25897) )/4; 

	if(scr.b[1] - scr.a[1] <= scr.b[2] - scr.a[2] )
	{
		//ishort = 1;
		//ilong  = 2;
		a[1] = scr.a[1]; 
		a[2] = scr.a[2]; 

		d[1] = (scr.b[1] - scr.a[1])/3; 	
		d[2] = ( scr.b[2] - scr.a[2])/4; 

	}
	else
	{
		//ishort = 2;
		//ilong  = 1;
		a[2] = scr.a[1]; 
		a[1] = scr.a[2]; 

		d[2] = (scr.b[1] - scr.a[1])/3; 	
		d[1] = ( scr.b[2] - scr.a[2])/4; 
	}
	//a[1] = scr.a[1]; 
	//a[2] = scr.a[2]; 

	//d[1] = (scr.b[1] - scr.a[1])/3; 	
	//d[2] = ( scr.b[2] - scr.a[2])/4; 


	//a[1] =10; a[2] = 100; 
	//d[1] = 10; 	d[2] = 100; 

	for(i=1; i<=3 ; i++)
	{
		for(j=1; j<=4; j++)
		{
			for(k = 1; k<=n; k++)
			{
				switch (k)
				{
					case 1:
						{
							alfa = i-1;
							break;
						}
					case 2:
						{
							alfa = j-1;
							break;
						}

				}
				part[(i-1)*4+j].a[k] = a[k]+ alfa*d[k];
				part[(i-1)*4+j].b[k] = a[k]+ alfa*d[k] + d[k];
			}
		}
	}


//------test 3.4 start ------
//	cstrMarc += "\r\n";
//	cstrMarc += "\r\n";
//	CString cstrPart ;

//for(i=1; i<=12; i++)
//{
           
//	sprintf(temp, " part[%02i]: [%.2f, %.2f]x[%.2f, %.2f]: ",i, part[i].a[1], part[i].b[1], part[i].a[2], part[i].b[2] );
//	cstrPart += temp;
//    cstrPart += "\r\n";

//}

//	AfxMessageBox(cstrPart);
//	cstrMarc += "\r\n";
//	cstrMarc += "\r\n";

//------test 3.3 end --------

	iSum_TickCount =0;
	iSum_TuplesCount =0;

	for(i=1; i<=12; i++)
	{
		strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ( ( ");
		
			sprintf(temp, " %.2f ", part[i].a[1] );
			strcat(	szSql, temp	);
			strcat(	szSql, "<= age AND age <=");
			sprintf(temp, " %.2f ", part[i].b[1] );
			strcat(	szSql, temp	);

			strcat(	szSql, ") AND (" );

			sprintf(temp, " %.2f ", part[i].a[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, 	"<= Income AND Income <=");
			sprintf(temp, " %.2f ", part[i].b[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, ") ) "	);

			lStartTimer = GetTickCount();
				ituples_cnt = zlExeSelect(TableName, szSql);
		    lEndTimer = GetTickCount() - lStartTimer ;
			
			iSum_TickCount += lEndTimer;
			iSum_TuplesCount += ituples_cnt;

			sprintf(temp, " part[%02i]: [%.2f, %.2f]x[%.2f, %.2f]: ",i, part[i].a[1], part[i].b[1], part[i].a[2], part[i].b[2] );
			cstrMarc += temp;
            sprintf(temp, "Num_tuples = %ld,  GetTickCount = %ld", ituples_cnt, lEndTimer);
			cstrMarc += temp;
			cstrMarc += "\r\n";
	}

	    sprintf(temp, "       Sum of Tick Count of all Part = %ld", iSum_TickCount);
		cstrMarc += temp;
		cstrMarc += "\r\n";
		sprintf(temp, "       Sum of Tuples Count = %ld", iSum_TuplesCount);
		cstrMarc += temp;
		cstrMarc += "\r\n";


//3.5 ---- Find which rectangle intersect the partition of all 12 = 4*3 partitions ----

//dddddddddddd
	cstrMarc += "\r\n";
	cstrMarc += "\r\n";
//dddddddddddd

	int index[13][101];  // i= 1 to 12 intersect with part[i] : index[i][1]=5, index[i][2]=7,index[i][3]=8, index[i][4]=15,...
	//double p, q;
	bool bInterable =false;

	char buffer[20] = "";

	for(i= 1; i<=12; i++)
	{
		sprintf(part[i].suffix, " Part[%i]: " , i );
	}
/********************
	for(i= 1; i<=12; i++)
	{
		l=0;

		for(j= 1; j <=m ; j++) // m is the number of T[i]'s
		{
			for(k=1; k<=n; k++) //n is the number of dimensions 
			{
				p = __max(part[i].a[k], T[j].a[k]); // here we use "intersect"
				q = __min(part[i].b[k], T[j].b[k]);

				if(p<q) //the intersection is not empty
				{
					bInterable = true; //must intersect for all dimensions
				} //if(p<q)
				else //the intersection is empty or p=q
				{
					bInterable = false; // it is enough there is a dimensions
					break;   //break k, because there is i0 such that p[i0] >=q[i0]  
				}

			}//for(k=1; k<=n; k++)

			if(bInterable) //if intersectable
			{
				l++;
				index[i][l] = j;
				sprintf(buffer, ",%i", j);
				strcat(part[i].suffix, buffer);
			}

		}//for(j= 1; j <=m ; j++)v

		//cstrMarc += part[i].suffix;						 
	    //cstrMarc += "\r\n";

	}//for(i= 1; i<=12; i++)
********************/
	cstrMarc += "#################";
	cstrMarc += "\r\n";
    cstrMarc += "\r\n";


//3.6 ------------------- Clustering -----------------------
// we use the method of "Center IN " to clustering
	
	ZLRECT * partT[101];
	//int clsNum =0;  //2005.3.16
	//int clsNum =1000; ////2005.3.16 , only for intersections
	int clsNum =12; ////2005.3.24 , only for intersections

	double center =0.0;
//----for test ----
	ZLRECT * pT = new ZLRECT [101];
//----for test ----

	for(i= 1; i<=12; i++)
	{
		sprintf(part[i].suffix, " Part[%i]: " , i ); 
		//?? for debug ? WHY part[i].suffix?  NOT partT[i].suffix
		// Yes, for debug!
	}

	for(i= 1; i<=12; i++)
	{
		for(j=1; j<=100; j++)
		{
			index[i][j] = 0;
		}
	}


////// ~~~~~~~~ Finding all T[j]'s that center are in part[i].
	for(i= 1; i<=12; i++)
	{
		l=0;

		for(j= 1; j <=m ; j++) // m is the number of T[i]'s
		{
			//###########
			if(T[j].cn <=0 ) //?? add .cn !=0 , Not, repeat
			{				 //YES! do it here
				for(k=1; k<=n; k++) //n is the number of dimensions 
				{
					//p = __max(part[i].a[k], T[j].a[k]);   //?? replace "intersect" by "center in"
					//q = __min(part[i].b[k], T[j].b[k]);   //YES , using "Center in"	
					
					center = (double)(T[j].a[k] + T[j].b[k])/2.0;

					//if(p<q) //the intersection is not empty					
					if( (part[i].a[k]<=center) && (center<= part[i].b[k]) ) //the Center in the part[i]
					{
						bInterable = true;
					} //if(p<q)
					else //the intersection is empty or p=q
					{
						bInterable = false;
						break;   //break k, because there is i0 such that p[i0] >=q[i0]  
					}

				}//for(k=1; k<=n; k++)

				if(bInterable) //if intersectable
				{
					l++;
					index[i][l] = j;
					sprintf(buffer, ",%i", j);
					strcat(part[i].suffix, buffer); // save the index j of T[j] 
													//that intersect with part[i]

					//T[j].cn = i;                  // do not change the value of .cn
													// also let it be 0; ?? or -1
													// change it in the proc zlClusterPart();

					T[j].cn = i;                   //2005.3.16, use it again.
												   // change it to T[j].cn = 1000 +i when it intersect with some others


					partT[l] = &T[j]; // the address of (T[j]) assign to (partT[l]);
									  // there is only the ADDRESS. 

									  // NOT change .suf1st, .sufend, .cn, .bsn, ... 
									  // So, to call other 2 functions , 
									  // we need to pay attention to it.
									  // Where {partT[l]'s} are the subset of {T[j]'s}
									  // that intersect with part[i].
									  
									  // ?? whether or not change the values of 
									  // .suf1st, .sufend, .cn, .bsn, ... in partT[l]'s
				}//if(bInterable) //if intersectable					 
			}//if(T[j].cn <=0 )

			//################

		}//for(j= 1; j <=m ; j++)v

		cstrMarc += part[i].suffix;						 
	    cstrMarc += "\r\n";
		// up to now we obtain all T[j]'s that in Part[i], and it index: index[i][l]
			//call the function : zlClusterPart( ZLRECT ** T, ZLRECT ** S); 
		if(l>0)
		{
		  ///////- NOT use this one: clsNum = zlClusterPart( partT, l, S, m, clsNum, n ); 
		  //------ We use T at 3 para, not use S 

		  clsNum = zlClusterPart( partT, l, T, m, clsNum, n );  
			//- where m is the new one that the is the number of T[i]'s 
		    //-     old m ==100, but new m may be 98, 96
		    //- that is removed all subsets of S[i]'s
			//- partT[i] is only the address of some T[i]'s that intersect with part[i]
			
			//----------for tset
				//for(int ijk =1; ijk <=l; ijk ++)
				//{
				//	pT[ijk] = *partT[ijk];

				//	pT[ijk].suf1st = ijk;
				//	pT[ijk].sufend = ijk;
				//	//pT[ijk].cn = 0;
				//	//pT[ijk].bsn = l;


			//	}
			    //double all_v = zlVolumeOfUnion(l, 2, pT );
			//-----------for tset
		}
	}//for(i= 1; i<=12; i++)


//---------ttest start ----------
	cstrMarc += "\r\n";
	cstrMarc += "\r\n";
    int iclsNum =0;
	int iallNum =0;

	for(i=1; i<= clsNum; i++)
	{
		iclsNum =0;

		sprintf(temp, "cluster[%02i] : ", i);
		cstrMarc += temp;
		cstrMarc += "\r\n";

		for(j=1; j<=m; j++)
		{
			if(T[j].cn == i)
			{
				//sprintf(temp, ", %02i", j);
				sprintf(temp, " T[%02i],T[%02i].bsn =%02i;  ", j, j, T[j].bsn );
				cstrMarc += temp;
				iclsNum ++;
			}			
		}


		if(iclsNum >0)
		{
			cstrMarc += "\r\n";
			sprintf(temp, "    iclsNum = %02i ", iclsNum);
			cstrMarc += temp;
			iallNum = iallNum + iclsNum; 
			cstrMarc += "\r\n";
			cstrMarc += "\r\n";

		}

	}

		sprintf(temp, " iallNum = %02i ", iallNum);
		cstrMarc += temp;
		cstrMarc += "\r\n";

//---------ttest end ----------

// 3.7 ------------------- Clustering S[] -----------------------
//    obtain all cluster number of S[i] (where i=1 to 100)


//---------ttest S[] start ----------
	cstrMarc += "\r\n";
	cstrMarc += "\r\n";

    iclsNum =0;
	iallNum =0;

	//for(i=1; i<= clsNum; i++)
	{
		iclsNum =0;

		sprintf(temp, "Cluster[%02i] : ", i);
		cstrMarc += temp;

		//for(j=1; j<=m; j++)
		//for(j=0; j<=100; j++)
		for(j=1; j<=old_m; j++)
		{
			//if(S[j].cn == i)
			{
				sprintf(temp, " S[%02i],S[%02i].bsn =%02i;  ", j, j, S[j].bsn );
				cstrMarc += temp;
				iclsNum ++;
			}	
			cstrMarc += "\r\n";
		}
		sprintf(temp, "; iclsNum = %02i ", iclsNum);
		cstrMarc += temp;
		iallNum = iallNum + iclsNum; 

		cstrMarc += "\r\n";

	}

		sprintf(temp, " iallNum = %02i ", iallNum);
		cstrMarc += temp;
		cstrMarc += "\r\n";

//---------ttest S[] end ----------




	for(i=1; i<= old_m; i++)
	{

		do 
		{
			if(S[i].bsn > 10000)
			{	
				S[i].cn = T[S[i].bsn-10000].cn;
				break;
			}
			else
			{
				k = S[i].bsn;
				S[i].bsn = S[k].bsn;
			}

		} while (true);

	}



//---------ttest S[] start ----------
	cstrMarc += "\r\n";
	cstrMarc += "\r\n";

    iclsNum =0;
	iallNum =0;

		cstrMarc += "For S[i] ";
		cstrMarc += "\r\n";
		cstrMarc += "\r\n";

	for(i=1; i<= clsNum; i++)
	{
		iclsNum =0;


		sprintf(temp, "Cluster[%02i]: ", i);
		cstrMarc += temp;
		cstrMarc += "\r\n";

		//for(j=1; j<=m; j++)
		//for(j=0; j<=100; j++)
		for(j=1; j<=old_m; j++)
		{
			if(S[j].cn == i)
			{
				//sprintf(temp, " S[%02i],S[%02i].bsn =%02i;  ", j, j, S[j].bsn );
				sprintf(temp, "S[%02i], ", j  );
				cstrMarc += temp;
				iclsNum ++;
			}			
		}
		
		if(iclsNum >0)
		{
			cstrMarc += "\r\n";
			sprintf(temp, "    iclsNum = %02i ", iclsNum);
			cstrMarc += temp;
			iallNum = iallNum + iclsNum; 
			cstrMarc += "\r\n";
		}

	}

		sprintf(temp, " iallNum = %02i ", iallNum);
		cstrMarc += temp;
		cstrMarc += "\r\n";

//---------ttest S[] end ----------

// 3.8 ------------------- obtain scr's according to the Clusters of  S[] -----------------------
//15 <=	Age <= 90	
//-25897 <= income <=	347998

iSum_TickCount = 0;
iSum_TuplesCount =0;

	double * Sum_v_S = new double [100 +1];//[clsNum +1];
	ZLRECT * scr_CLS = new ZLRECT[100+1]; //[clsNum +1];  
	
	//for(i=1; i<=clsNum; i++)
	for(i=1; i<=100; i++)
	{
		//scr_CLS[i].a = new double[n+1];
		//scr_CLS[i].b = new double[n+1];
		scr_CLS[i].v = 1.0;
		
		Sum_v_S[i] = 0.0;
		for(k=1; k<=old_m; k++) //old_m ==100
		{
			if(S[k].cn ==i)
			{
				Sum_v_S[i] += S[k].v;
			}

		}

	}

	//for(i=1; i<=clsNum; i++ )
	for(i=1; i<=100; i++ )
	{
			scr_CLS[i].a[1] = 90;
			scr_CLS[i].b[1] = 15;
			scr_CLS[i].a[2] = 347998;
			scr_CLS[i].b[2] = -25897;

		for(j=1; j<=n; j++)
		{
			for(k=1; k<=old_m; k++) // old_m ==100
			{
				if(S[k].cn ==i)
				{
					scr_CLS[i].a[j] = min(scr_CLS[i].a[j], S[k].a[j]);
					scr_CLS[i].b[j] = max(scr_CLS[i].b[j], S[k].b[j]);

				}

			}
			//scr_CLS[i].v *= (scr_CLS[i].b[j]-scr_CLS[i].a[j]) ;
		}

		for(j=1; j<=n; j++)
		{
			scr_CLS[i].v *= (scr_CLS[i].b[j]-scr_CLS[i].a[j]) ;
		}


	}

	int nonzearo =0;
	cstrMarc += "\r\n";
	//for(i = 1; i<=clsNum; i++) // there are clsNum scr's of cluster scr_CLS[1] to scr_CLS[clsNum]
	for(i = 1; i<=100; i++) // there are clsNum scr's of cluster scr_CLS[1] to scr_CLS[clsNum]
	{
		nonzearo =0;
		for(j=1; j<=old_m; j++)
		{
			if(S[j].cn ==i)
			{
				//sprintf(temp, " ,S[%02i] ", j );
				//cstrMarc += temp;
				nonzearo ++;
			}
		}
      if(nonzearo !=0)
	  {
		strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ( ( ");
		
			sprintf(temp, " %.2f ", scr_CLS[i].a[1] );
			strcat(	szSql, temp	);
			strcat(	szSql, "<= age AND age <=");
			sprintf(temp, " %.2f ", scr_CLS[i].b[1] );
			strcat(	szSql, temp	);

			strcat(	szSql, ") AND (" );

			sprintf(temp, " %.2f ", scr_CLS[i].a[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, 	"<= Income AND Income <=");
			sprintf(temp, " %.2f ", scr_CLS[i].b[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, ") ) "	);

			lStartTimer = GetTickCount();
				ituples_cnt = zlExeSelect(TableName, szSql);
		    lEndTimer = GetTickCount() - lStartTimer ;
			
			iSum_TickCount += lEndTimer;
			iSum_TuplesCount += ituples_cnt;

            //sprintf(temp, " S%i: [%.2f, %.2f]x[%.2f, %.2f]: tuples_num = %ld ",i, T[i].a[1], T[i].b[1], T[i].a[2], T[i].b[2], ituples_cnt );
            sprintf(temp, " scr_CLS%02i: [%.2f, %.2f]x[%.2f, %.2f], .v =%.2f : tuples_num = %ld ",i, scr_CLS[i].a[1], scr_CLS[i].b[1], scr_CLS[i].a[2], scr_CLS[i].b[2], scr_CLS[i].v, ituples_cnt );
			cstrMarc += temp;
            sprintf(temp, " GetTickCount = %ld", lEndTimer);
			cstrMarc += temp;
			cstrMarc += "\r\n";
	  }
	}


	    sprintf(temp, "       Sum of Tick Count = %ld", iSum_TickCount);
		cstrMarc += temp;
		cstrMarc += "\r\n";

		sprintf(temp, "       Sum of Tuples Count = %ld", iSum_TuplesCount);
		cstrMarc += temp;
		cstrMarc += "\r\n";
		cstrMarc += "\r\n";

// 3.9 ------------------- 2nd Clustering for obtained scr's  -----------------------
   	
	//int idx[101]; 
	//k=1;

	//for(i=0; i<=100; i++)
	//	idx[i]=0;
	//for(i = 1; i<=clsNum; i++)
	for(i = 1; i<=100; i++) 	
	{
		scr_CLS[i].bsn = 1; // means has elements S[i]
	}




	//for(i = 1; i<=clsNum; i++) 
	for(i = 1; i<=100; i++) 
	{
		//if(scr_CLS[i].v <= 10*Sum_v_S[i]  )
		if(scr_CLS[i].v <= 5*Sum_v_S[i]  )
		{

			sprintf(temp, " scr_CLS[%02i].v = %.02f <<<=== 10*Sum_v_S[%02i] =%.02f;  ",i,scr_CLS[i].v, i, Sum_v_S[i] );
			cstrMarc += temp;
			cstrMarc += "\r\n";
			sprintf(temp, "						scr_CLS[%02i].v/Sum_v_S[%02i]= %.02f   ",i,i, scr_CLS[i].v/Sum_v_S[i] );
			cstrMarc += temp;
			cstrMarc += "\r\n";
			cstrMarc += "\r\n";

		}else // that is: scr_CLS[i].v/Sum_v_S[i]  > 5        //10
		{
            k=0;
			for(j=1; j<=old_m; j++)
			{
				if(S[j].cn == i)
				{
					S[j].cn =0;
					k++;
				}
				//idx[k]=j;
				//k++;
				//scr_CLS[i].bsn = 0; 
			}

			scr_CLS[i].bsn = 0; 
			//scr_CLS[i].cn =k;


			sprintf(temp, " scr_CLS[%02i].v = %.02f >>>>>> 5*Sum_v_S[%02i] =%.02f ",i,scr_CLS[i].v, i, Sum_v_S[i] );
			cstrMarc += temp;
			cstrMarc += "\r\n";
			sprintf(temp, "						scr_CLS[%02i].v/Sum_v_S[%02i]= %.02f   ",i,i, scr_CLS[i].v/Sum_v_S[i] );
			cstrMarc += temp;
			cstrMarc += "\r\n";
			cstrMarc += "\r\n";
		}
	}

	//clustering again if one is the subset of another, then togather them 
////// ~~~~~~~~ Finding all scr_CLS[i]'s that center are in part[i].
   //3.9.1 for  scr_CLS[i] which =1
   //3.9.2 for S[i]'s whicn .cn =0

	rmvable =false;
	//for(i=1; i<=clsNum; i++)
	for(i=1; i<=100; i++)
	{
		if(scr_CLS[i].bsn ==1)
		{
			for(j=1; j<=clsNum; j++)
			{
				if( (i != j) && scr_CLS[j].bsn ==1 )
				{
					for(k=1; k<=n; k++) //n is the number of dimensions 
					{
						
						center = (double)(scr_CLS[j].a[k] + scr_CLS[j].b[k])/2.0;
						//if the Center of scr_CLS[j] is in scr_CLS[i]
						if( (scr_CLS[i].a[k]<=center) && (center<= scr_CLS[i].b[k]) ) //the Center in the part[i]
						{
							bInterable = true;
						} //
						else // 
						{
							bInterable = false;
							break;   //break k,   
						}
					}//for(k=1; k<=n; k++)


				}//for(k=1; k<=n; k++)
				if(rmvable) //there is a k such that scr_CLS[i] is in scr_CLS[k] 
				{
						//-------test 2---
							sprintf(temp, " Center of scr_CLS[%ld] IN scr_CLS[%i]: [%.2f, %.2f]x[%.2f, %.2f]: ", j, i, scr_CLS[j].a[1], scr_CLS[j].b[1], scr_CLS[j].a[2], scr_CLS[j].b[2] );
							cstrMarc += temp;
							cstrMarc += "\r\n";

						//-------test 2---
					scr_CLS[j].bsn = 0; // the center of scr_CLS[j] is in scr_CLS[i], IMPORTANT
					for(l=1; l<=old_m; l++)
					{
						if(S[l].cn ==j)
							S[l].cn=i;
					}

					break;  // break k and then for next i
				}


			}//for(j=1; j<=clsNum; j++)
		}//if(scr_CLS[i].bsn ==1)
	}//(i=1; i<=clsNum; i++)

/**************************************************
	for(i=1; i<=clsNum; i++)
	{
		for(k=1; k<=clsNum; k++)
		{
		   if( (i != k) && scr_CLS[k].bsn ==1 )
		   {
				for(j=1; j<=n; j++)
				{
					 // if scr_CLS[i] is the subset of scr_CLS[k], 
					//if( (scr_CLS[k].a[j]<=scr_CLS[i].a[j]) && (scr_CLS[i].b[j]<=scr_CLS[k].b[j] ))
					//if the center of scr_CLS[i] is in scr_CLS[k],
					
					if( (scr_CLS[k].a[j]<=scr_CLS[i].a[j]) && (scr_CLS[i].b[j]<=scr_CLS[k].b[j] ))		
					{
						rmvable = true;
					}
					else
					{
						rmvable = false;
						break; //break j, for next k
					}
				} //for(j= 1; j <=n; j++)
				
				if(rmvable) //there is a k such that scr_CLS[i] is in scr_CLS[k] 
				{
						//-------test 2---
							sprintf(temp, " scr_CLS[%ld] cover, REMOVE scr_CLS[%i]: [%.2f, %.2f]x[%.2f, %.2f]: ", k, i, scr_CLS[i].a[1], scr_CLS[i].b[1], scr_CLS[i].a[2], scr_CLS[i].b[2] );
							cstrMarc += temp;
							cstrMarc += "\r\n";

						//-------test 2---
					scr_CLS[i].bsn = 0; // s[i] is in s[k], IMPORTANT
					for(l=1; l<=old_m; l++)
					{
						if(S[l].cn ==i)
							S[l].cn=k;
					}

					break;  // break k and then for next i
				}

		   } //if(i != k)

		}//for(k=1; i<=m; k++)

	}//for(i=1; i<=m; i++)
**************************************/

	//for(i=1; i<=clsNum; i++)
	for(i=1; i<=100; i++)
	{
		if(scr_CLS[i].bsn ==1)
		{
			for(k=1; k<=old_m; k++)
			{
				
				if(S[k].cn ==0 )
				{
					for(j=1; j<=n; j++)
					{
						 // if S[k] is the subset of scr_CLS[i], 
						if( (scr_CLS[i].a[j]<=S[k].a[j]) && (S[k].b[j]<=scr_CLS[i].b[j] ))
						{
							rmvable = true;
						}
						else
						{
							rmvable = false;
							break; //break j, for next k
						}
					} //for(j= 1; j <=n; j++)
				
				
					if(rmvable) //there is a k such that scr_CLS[i] is in scr_CLS[k] 
					{
							//-------test 2---
								sprintf(temp, " scr_CLS[%ld] cover, REMOVE S[%i]= [%.2f, %.2f]x[%.2f, %.2f]: ", i, k, S[k].a[1], S[k].b[1], S[k].a[2], S[k].b[2] );
								cstrMarc += temp;
								cstrMarc += "\r\n";

							//-------test 2---

								S[k].cn = i;						

						break;  // break k and then for next i
					}
				}
			}
		}
	}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!! for a scr_CLS[i] : if scr_CLS[i].bsn ==0, that is, if scr_CLS[%02i].v/Sum_v_S[%02i] > 5
// !!!!! and it contain >8 S[i]'s then part it 12 parts.
	 cstrMarc += "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
	 cstrMarc += "\r\n";

	for(i= 1; i<=12; i++)
	{
		l=0;
		sprintf(part[i].suffix, "Part[%d] \r\n", i);

		for(j= 1; j <=old_m ; j++) // m is the number of T[i]'s
		{
			//###########
			if(S[j].cn <=0 ) //?? add .cn !=0 , Not, repeat
			{				 //YES! do it here
				for(k=1; k<=n; k++) //n is the number of dimensions 
				{
					center = (double)(S[j].a[k] + S[j].b[k])/2.0;

					if( (part[i].a[k]<=center) && (center<= part[i].b[k]) ) //the Center in the part[i]
					{
						bInterable = true;
					} //if(p<q)
					else //the intersection is empty or p=q
					{
						bInterable = false;
						break;   //break k, because there is i0 such that p[i0] >=q[i0]  
					}

				}//for(k=1; k<=n; k++)

				if(bInterable) //if intersectable
				{
					l++;
					index[i][l] = j;
					sprintf(buffer, ",%i", j);
					strcat(part[i].suffix, buffer); // save the index j of T[j] 
													//that intersect with part[i]

					S[j].cn = 0; //10000+i; //???//i;                   //2005.3.16, use it again.
												   // change it to T[j].cn = 1000 +i when it intersect with some others
				}//if(bInterable) //if intersectable					 
			}//if(T[j].cn <=0 )

			//################

		}//for(j= 1; j <=m ; j++)v

		cstrMarc += part[i].suffix;						 
	    cstrMarc += "\r\n";

		if(l>8) //reparttion 12 parts
		{
           //clsNum = zlPartion(part[i], 2, S, old_m, clsNum);

		}

	}//for(i= 1; i<=12; i++)

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


// 3.10 ------------------- obtain 2nd SCR's according to the Clusters of  S[] -----------------------
//15 <=	Age <= 90	
//-25897 <= income <=	347998
								cstrMarc += "\r\n";
								cstrMarc += "\r\n";

iSum_TickCount = 0;
iSum_TuplesCount =0;

	//double * Sum_v_S = new double [clsNum +1];
	//ZLRECT * scr_CLS = new ZLRECT[clsNum +1];  
	
	for(i=1; i<=clsNum; i++)
	{
		//scr_CLS[i].a = new double[n+1];
		//scr_CLS[i].b = new double[n+1];
		scr_CLS[i].v = 1.0;
		
		Sum_v_S[i] = 0.0;
		for(k=1; k<=old_m; k++) //old_m ==100
		{
			if(S[k].cn ==i)
			{
				Sum_v_S[i] += S[k].v;
			}

		}

	}

	for(i=1; i<=clsNum; i++ )
	{
			scr_CLS[i].a[1] = 90;
			scr_CLS[i].b[1] = 15;
			scr_CLS[i].a[2] = 347998;
			scr_CLS[i].b[2] = -25897;

		for(j=1; j<=n; j++)
		{
			for(k=1; k<=old_m; k++) // old_m ==100
			{
				if(S[k].cn ==i)
				{
					scr_CLS[i].a[j] = min(scr_CLS[i].a[j], S[k].a[j]);
					scr_CLS[i].b[j] = max(scr_CLS[i].b[j], S[k].b[j]);

				}

			}
			//scr_CLS[i].v *= (scr_CLS[i].b[j]-scr_CLS[i].a[j]) ;
		}

		for(j=1; j<=n; j++)
		{
			scr_CLS[i].v *= (scr_CLS[i].b[j]-scr_CLS[i].a[j]) ;
		}


	}

 int allNonzero =0;
 nonzearo = 0;

	cstrMarc += "\r\n";
	for(i = 1; i<=clsNum; i++) // there are clsNum scr's of cluster scr_CLS[1] to scr_CLS[clsNum]
	{
			nonzearo = 0;
			sprintf(temp, " .bsn = %i, scr_CLS%02i: [%.2f, %.2f]x[%.2f, %.2f], .v =%.2f : ",scr_CLS[i].bsn, i, scr_CLS[i].a[1], scr_CLS[i].b[1], scr_CLS[i].a[2], scr_CLS[i].b[2], scr_CLS[i].v );
			cstrMarc += temp;	
	        cstrMarc += "\r\n";

			cstrMarc += "    Cover: ";

			for(j=1; j<=old_m; j++)
			{
				if(S[j].cn ==i)
				{
					sprintf(temp, " ,S[%02i] ", j );
					cstrMarc += temp;
					nonzearo ++;
				}
			}
	        cstrMarc += "\r\n";

       allNonzero += nonzearo;

      if(nonzearo !=0)
	  {
		strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ( ( ");
		
			sprintf(temp, " %.2f ", scr_CLS[i].a[1] );
			strcat(	szSql, temp	);
			strcat(	szSql, "<= age AND age <=");
			sprintf(temp, " %.2f ", scr_CLS[i].b[1] );
			strcat(	szSql, temp	);

			strcat(	szSql, ") AND (" );

			sprintf(temp, " %.2f ", scr_CLS[i].a[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, 	"<= Income AND Income <=");
			sprintf(temp, " %.2f ", scr_CLS[i].b[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, ") ) "	);

			lStartTimer = GetTickCount();
				ituples_cnt = zlExeSelect(TableName, szSql);
		    lEndTimer = GetTickCount() - lStartTimer ;
			
			iSum_TickCount += lEndTimer;
			iSum_TuplesCount += ituples_cnt;

            //sprintf(temp, " S%i: [%.2f, %.2f]x[%.2f, %.2f]: tuples_num = %ld ",i, T[i].a[1], T[i].b[1], T[i].a[2], T[i].b[2], ituples_cnt );
            sprintf(temp, "		tuples_num = %ld ", ituples_cnt );
			cstrMarc += temp;
			cstrMarc += "\r\n";

            sprintf(temp, "		GetTickCount = %ld", lEndTimer);
			cstrMarc += temp;
			cstrMarc += "\r\n";
			cstrMarc += "\r\n";
	  }

	}




	int izero = 0;
	      	cstrMarc += "\r\n";	
			cstrMarc += "cluster0 : ";	

			for(j=1; j<=old_m; j++)
			{
				if(S[j].cn ==0)
				{
					sprintf(temp, " ,S[%02i] ", j );
					cstrMarc += temp;
					izero ++;
				}

			}
			cstrMarc += "\r\n";	
			cstrMarc += "\r\n";




	if(izero >0 )
	{
		for(i = 1; i<=old_m; i++) // there are m the originial rectangles S[1] to S[100]
		{

		        if(S[i].cn ==0)
				{
					strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ( ( ");
					
						sprintf(temp, " %.2f ", S[i].a[1] );
						strcat(	szSql, temp	);
						strcat(	szSql, "<= age AND age <=");
						sprintf(temp, " %.2f ", S[i].b[1] );
						strcat(	szSql, temp	);

						strcat(	szSql, ") AND (" );

						sprintf(temp, " %.2f ", S[i].a[2] );
						strcat(	szSql, temp	);
						strcat(	szSql, 	"<= Income AND Income <=");
						sprintf(temp, " %.2f ", S[i].b[2] );
						strcat(	szSql, temp	);
						strcat(	szSql, ") ) "	);

						lStartTimer = GetTickCount();
							ituples_cnt = zlExeSelect(TableName, szSql);
						lEndTimer = GetTickCount() - lStartTimer ;
						
						iSum_TickCount += lEndTimer;
						iSum_TuplesCount += ituples_cnt;

						//sprintf(temp, " S%i: [%.2f, %.2f]x[%.2f, %.2f]: tuples_num = %ld ",i, T[i].a[1], T[i].b[1], T[i].a[2], T[i].b[2], ituples_cnt );
						sprintf(temp, " S%i: [%.2f, %.2f]x[%.2f, %.2f]: \r\n tuples_num = %ld ",i, S[i].a[1], S[i].b[1], S[i].a[2], S[i].b[2], ituples_cnt );
						cstrMarc += temp;
						sprintf(temp, " GetTickCount = %ld", lEndTimer);
						cstrMarc += temp;
						cstrMarc += "\r\n";
				}
			}

	   }

	    sprintf(temp, "       Sum of Tick Count = %ld", iSum_TickCount);
		cstrMarc += temp;
		cstrMarc += "\r\n";

		sprintf(temp, "       Sum of Tuples Count = %ld", iSum_TuplesCount);
		cstrMarc += temp;
		cstrMarc += "\r\n";

		sprintf(temp, "       nonzero = %i, zero = %i", allNonzero , izero);
		cstrMarc += temp;
		cstrMarc += "\r\n";








//---------------   the algorithms --------------------
//---------------^^^^^^^^^^^^^^^^^^^^^^^^^^------------
////////////////////////////////////////////////////////////////////////
	
		
	CFile file;

	//if(file.Open("E:\\Paper2\\CLMB_census2D\\cluster_100_census2D_OPT.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
	if(file.Open("E:\\Paper2\\CLMB_census2D\\cluster_100_census2D.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
	{
		file.Write(cstrMarc, cstrMarc.GetLength() +1 );
	}
	file.Close();

		
	AfxMessageBox("OnViewCluster100 OK!");
	zlCloseDB();





	delete [] Sum_v_S;

	for(i=1; i<=clsNum; i++)
	{
		//delete [] scr_CLS[i].a;
		//delete [] scr_CLS[i].b;
	}

	delete [] scr_CLS;

	for(i=1; i<=12; i++)
	{
	//	delete [] part[i].a;
	//	delete [] part[i].b;
	}

	m = old_m;
	for(i=1; i<=m; i++)
	{
		//delete [] T[i].a ;
		//delete [] T[i].b ;
	}

	// delete m initial rectagles randomly from [15, 90]x[0, 350000]
	for(i=1; i<=m; i++)
	{
		//delete [] S[i].a ;
		//delete [] S[i].b ;
	}

	//delete [] scr.a ;
	//delete [] scr.b ;	
}//void CMainFrame::OnViewCluster100_BacK050413() 


//	T[i] is only the address of some S[i]'s 
//	we want to find all S[i]'s that intersect with T[i].
//	{T[i] i =1, ... l} is the subset of {S[i], i = 1,...,m}, which center in a part[]
int CMainFrame::zlClusterPart(ZLRECT * * T, int l,  ZLRECT * S, int m, int Current_clsNum, int dim_num)
{
	int iclsNum = Current_clsNum ; 
	int iclsNumHold = Current_clsNum;
	int i, j, k, ll, idx;
	double p;
	double q;
	bool bInterable= false;
	int n = dim_num;
	char buffer[128] ="";
	CString cstrMarc = "";
	char temp[1000] = "";
	double Sum_vi = 0;

	int cn[1024 +1];
    int part_cn = -1;  

	ZLRECT * RT = new ZLRECT[m+1];

	for(i=1; i<=m; i++)
	{
		//RT[i].a = new double[n+1];
		//RT[i].b = new double[n+1];
	}
	for(i=1; i<=1024; i++)
	{
		cn[1024 +1] = -1;
	}



	int index[101][101];
	ZLRECT scr;

	//scr.a = new double[n+1];
	//scr.b = new double[n+1];

	for(i= 1; i<=100; i++)
	{
		for(j=1; j<=100; j++)
		{
			index[i][j] = 0;
		}
	}

	for(i= 1; i<=100; i++)
	{
		if( T[i]->cn < 1000)
		{
			part_cn = T[i]->cn;
			break;
		}
	}




	for(i= 1; i<=l; i++) // there are l rectangles in some part 
	{   
		//if( T[i]->cn <=0 )  //2005.3.16
		//if( T[i]->cn <=1000 ) //2005.3.16  // no clustering 
		if( T[i]->cn <=12 ) //2005.3.24  // no clustering 
		{
			idx = 1;          //mumber of train
			iclsNumHold = iclsNum; 
			iclsNum ++;

			part_cn = T[i]->cn; // save T[i]->cn
			//?? here := iclsNum; 
			//NO, becauseT[i]->cn has cn with part[i];
			//only when there is a S[j] intersect with it, then := iclsNum
			T[i]->cn = iclsNum; // T[i] is only the address, if its contents have been
								// changed, then the S[j] have been changed 
								//( T[i] == &S[j] )

								// when T[i]->cn has a nonzero value, 
								// then its S[j] has the same nonzero vlue
			
			index[i][1] = i;
			//-- cannot using this way, because delete RT[], meanwhile it delete T[]
			//memset(&RT[idx], 0, sizeof(ZLRECT));
			//memcpy(&RT[idx], T[i], sizeof(ZLRECT) );

			//-- using the following way, the addresses are independent each other.
			//-- RT[] the "train" with header T[i]; i.e.

			for(j=1; j<=n; j++)
			{
				RT[idx].a[j] = T[i]->a[j]; 
				RT[idx].b[j] = T[i]->b[j];
			}

			RT[idx].cn		=T[i]->cn;
			RT[idx].suf1st	=T[i]->suf1st;
			RT[idx].sufend	=T[i]->sufend;
			strcpy(RT[idx].suffix, T[i]->suffix);
			RT[idx].v		=T[i]->v;
			RT[idx].bsn		=T[i]->bsn;
			//where RT[idx].a = T[i]->a, the same pointer

			for(ll = 1; ll<= idx; ll++)
			{
				if(index[i][ll] <= 0) // the last indes[i][j] that is 0
					break;   //break for(ll = 1; ll<= m; ll++)
 			
				for(j=1; j<=m; j++)
				{
					//if(S[j].cn <=0)
					//if(S[j].cn <=1000)//2005.3.16
					if(S[j].cn <=12)  //2005.3.24
					{
						//--- see the "train" , all RT[ll]'s,  do or not intersect with S[j]
						for( k=1; k<=n; k++) //n is the number of dimensions 
						{
							 //p = __max(T[index[i][ll]]->a[k], S[j].a[k]);
							 //q = __min(T[index[i][ll]]->b[k], S[j].b[k]);
							 p = __max(RT[ll].a[k], S[j].a[k]);
							 q = __min(RT[ll].b[k], S[j].b[k]);

							//???  here l ==8; but T[index[i][ll] =93 > 8 there is problem 
							// using RT to replace T and idx replace m in forloop is OK !!!
							if(p<q) //the intersection is not empty, 
							{       //i.e. intersection 
								bInterable = true;
							} //if(p<q)
							else //the intersection is empty or p=q
							{
								bInterable = false;
								break;   //break k, because there is i0 such that p[i0] >=q[i0]  
							}

						}//for(k=1; k<=n; k++)

						if(bInterable) //if intersectable
						{
							idx++;   
							index[i][idx] = j;   //idx = 2 to ...
							sprintf(buffer, ",%i", j);
							strcat(T[i]->suffix, buffer);//for debug

							cn[ index[i][idx] ]=S[j].cn; // save the old cn ofS [j] , the cluster number

							S[j].cn = iclsNum;  

							for(int jj=1; jj<=n; jj++) // add S[j] to the end of the train.
							{
								RT[idx].a[jj] = S[j].a[jj]; 
								RT[idx].b[jj] = S[j].b[jj];
							}

							RT[idx].cn		= iclsNum;  //S[j].cn;
							RT[idx].suf1st	= S[j].suf1st;
							RT[idx].sufend	= S[j].sufend;
							strcpy(RT[idx].suffix, S[j].suffix);
							RT[idx].v		= S[j].v;
							RT[idx].bsn		= S[j].bsn;

							if(idx>=10) //the max (the long of the train) is 10 
								break; // break for j and then break for ll
						}

					} //if(S[j].cn <=0)

				} //for(j= 1; j<=m; j++)

			} //for(ll =1; ll<=idx; ll++)

			// to calculte the volume of Union
			if(idx>=2)
			{

				//?maybe RT[i] need to asign new value for .sufend, .suf1st
				
				//cstrMarc += "T[i]: ";
				sprintf(temp, "T[%02i]: ", i);
				cstrMarc += temp;

				cstrMarc += T[i]->suffix;
				cstrMarc += "\r\n";
				cstrMarc += "RT:   ";

				Sum_vi =0.0;
				for(k =1; k<=idx; k++)
				{
					Sum_vi = Sum_vi + RT[k].v;
				//---test----
					cstrMarc += ",";
					cstrMarc += RT[k].suffix;
					RT[k].suf1st = k;
					RT[k].sufend = k;
				//---test----
				}

				//-- obtain the scr of the current train 
				for(int ii=1; ii<=n; ii++ )
				{
					scr.a[ii] = RT[1].a[ii];
					scr.b[ii] = RT[1].b[ii];

					for(int k =1; k<=idx; k++ )
					{
						scr.a[ii] = min(scr.a[ii], RT[k].a[ii]);
						scr.b[ii] = max(scr.b[ii], RT[k].b[ii]);	
					}
				}

				scr.v = 1.0;
				for(int ii=1; ii<=n; ii++ )
				{
					scr.v *= (scr.b[ii]-scr.a[ii]);
				}
				
				//--obtain the Volume of the Union of the trian 
				double Union_v = zlVolumeOfUnion(idx, n, RT);

				cstrMarc += "\r\n";
				sprintf(temp, "Sum_vi= %G , scr_v=%G, Union_v=%G ", Sum_vi, scr.v, Union_v);
				cstrMarc += temp;

				cstrMarc += "\r\n";
				cstrMarc += "\r\n";


				//make a decision to give cluster number
				// by using 3 values : 1. Sum_vi, 2. scr_v,  and 3. Union_v 
				//---	a = Union_v/Sum_vi  <= 1, i.e. Union_v <= Sum_vi
	            //		b = Union_v/scr_v   <= 1  i.e. Union_v <= scr_v  
				//		c = scr_v/Sum_vi	non-determined	
				
				// if a ~~ 1 AND c >>> 1, i.e. the angles intersect,
	            // then we do not clustering. 
				// not clustering, and then restore the cluster number cn 
				
				double c = scr.v/Sum_vi;

				//if( (Sum_vi <= 1.2*Union_v) && ( pow(1.8, n-1) * Sum_vi <= scr.v ) ) 
				//if(  pow(1.8, n-1) * Sum_vi <= scr.v  ) 
				//if(  2.0 <= (scr.v/Sum_vi) ) 
				//if(  (Sum_vi/Union_v <= 1.2) && (scr.v/Sum_vi) >= pow(2.0, n-1) ) 
				//if( (scr.v/Sum_vi) >= pow(2.0, n-1) ) 

				//if( (scr.v/Sum_vi) >= pow(4.0, n-1) ) 	//IF SCR/SUM >4			
				if( (scr.v/Union_v) >= pow(4.0, n-1) ) 	//IF SCR/Union_v >4						
				{  

					sprintf(temp, "scr_v[%02i]=%G, Sum_vi= %G, scr.v/Sum_vi=%G ",iclsNum, scr.v, Sum_vi, scr.v/Sum_vi);
					cstrMarc += temp;
					cstrMarc += "\r\n";


					iclsNum = iclsNumHold; //iclsNum--;
					T[i]->cn = part_cn;
					for(k =1+1; k<=idx; k++ )
					{
						S[ index[i][k] ].cn = cn[ index[i][k] ];
					}
				
				}

//test ---11--
	sprintf(temp, "E:\\Paper2\\CLMB_census2D\\zlClusterPart\\zlClusterPart%02i.txt",iclsNum);
	CFile file;
	if(file.Open(temp, CFile::modeCreate | CFile::modeReadWrite ) != 0)
	{
		file.Write(cstrMarc, cstrMarc.GetLength() +1 );
	}
	file.Close();
//test ---11--

			}
			else  //2005.3.23
			{
				iclsNum = iclsNumHold;
				T[i]->cn = part_cn ;
			}//if(idx>=2)

		}//if( T[i]->cn <=0 )

	} //for(i= 1; i<=l; i++) // there are l rectangle in some part //

//test ---1133--
//	CFile file;
//	if(file.Open("E:\\Paper2\\CLMB_census2D\\zlClusterPart.txt", CFile::modeCreate | CFile::modeReadWrite ) != 0)
//	{
//		file.Write(cstrMarc, cstrMarc.GetLength() +1 );
//	}
//	file.Close();
//test ---1133--



	//delete [] scr.a;
	//delete [] scr.b;
	for(i=1; i<=m; i++)
	{
	//	delete [] RT[i].a;
	//	delete [] RT[i].b;
	}
	delete [] RT;

	return iclsNum;
	
}

double CMainFrame::zlVolumeOfUnion(int iCountRt, int iDimension, ZLRECT *S)
{
	int m = iCountRt; //5;    //10;  //the number of rectangles 
	int n = iDimension; //4;   //the dimensions of space
	int i, j, k, l, h; //for loop 

	double Totall_v =0.0;			// Totall_v = v(U Si )
	double * v = new double[m+1];	// vi=v[i];

    //double VFactor =  5.0 * pow(10, 37); //2005.05.02
	double VFactor;
	if(n==104)
	  VFactor = 5.0 * pow(10, 37);
	else if(n==50)
	  VFactor = pow(10, 34); // (30 +38)/2=34
	else if(n==25)
	  VFactor = pow(10, 31); // (24 +38)/2=31

	//--- for dubug -- start 1 ---
	CString cstrMarc = "";
	char temp[1000] = "";

		for(i=1; i<=m; i++)
		{	
			sprintf(temp, "S%02i: ", i);
			cstrMarc += temp;
			
			for(j=1; j<=n; j++)
			{
				sprintf(temp, "[%i, %i] ", (int)S[i].a[j], (int)S[i].b[j] );
				cstrMarc += temp;

			}

			sprintf(temp, " v = %.15G: ", S[i].v );
			cstrMarc += temp;

			cstrMarc += "\r\n";
		}

	//--- for dubug -- end 1 ---


	//1. from the paper  
	//Totall_v = v[1] - v[2] + v[3]... + (-1)^(m-1) v[m]
	// from formula (1) of the paper
	int isign =-1;

	for(i = 1; i<=m; i++)
	{
		 v[i] = 0.0;
	}

    // -- at the end of this function, we obtain Totall_v
	//for(i = 1; i<=m; i++)
	//{
		//isign *=-1;
		//Totall_v += isign* v[i];
	//}


	//2. how to obtain v[i]
	int iSize = sizeof(ZLRECT);

	ZLRECT * * rt; // all rectangles 
					  //rt[1][1] = v1_S1, rt[1][2] = v1_S2, rt[1][3] = v1_S3, ..., rt[1][j] = v1_Sj,
					  //rt[2][1] = v2_S1, rt[2][2] = v2_S2, rt[2][3] = v2_S3, ..., rt[2][j] = v2_Sj,
					  //rt[h][1] = vh_S1, rt[h][2] = vh_S2, rt[h][3] = vh_S3, ..., rt[h][j] = vh_Sj,
					  //rt[h][j] = vh_Sj means the j_th rectangle (after intersection) in the sum of vh. 
	
	rt = new (ZLRECT *[m+1] ); // map onto v1, v2, ..., vm 
	
	//for each i (1<= i<=m), vi have at most c(m,i) member reactangles.
	//for (i = 1; i <=m; i++)
	//{
		// c(m,i) is the number of all possible situation that take i elements from m 
		//rt[i] = new ZLRECT [c(m,i) +1 ];  //based 1, i.e.  for rt[i][j], j is from 1, to c(m,i)
	//}
	
	int iNum_Intersection = 0;

	for(i=1; i<=m; i++)
	{
		v[1] += S[i].v;
	}

	// for i=1
	i=1;
	iNum_Intersection = c(m, i);

	rt[1] = new ZLRECT [c(m,1) +1 ];  //based 1, i.e.  for rt[i][j], j is from 1, to c(m,i)
	for(j =1; j<=iNum_Intersection; j++)
	{
		//rt[1][j].a = new double[n+1];
		//rt[1][j].b = new double[n+1];
	}

	for(j =1; j<=iNum_Intersection; j++)
	{
		//rt[1][j] = S[j];
		//memset (&rt[1][j], 0, sizeof(ZLRECT));
		//memcpy(&rt[1][j], &S[j], sizeof(ZLRECT) ) ;

		for(i=1; i<=n; i++)
		{
			rt[1][j].a[i] = S[j].a[i];
			rt[1][j].b[i] = S[j].b[i];
		}
		rt[1][j].v = S[j].v;
		strcpy(rt[1][j].suffix, S[j].suffix);
		rt[1][j].suf1st = S[j].suf1st;
		rt[1][j].sufend = S[j].sufend;
		rt[1][j].cn = S[j].cn;
		rt[1][j].bsn = S[j].bsn;
	}

	char buffer[20];
	bool bInterable =false;

	//i=2;

	int iNum_Previous =  c(m, 1);
	double p, q;


	//~~~~~~  start ~~~~~
	int icmh; //the combination of take h from m

	for( h = 2; h<=m; h++)
	{
		j=1;

		//iNum_Previous = c(m, h-1); // see above : the definition
		icmh = c(m,h) +1 ;
		rt[h] = new ZLRECT [icmh]; //[c(m,h) +1 ];  //based 1, i.e.  for rt[i][j], j is from 1, to c(m,i)
		iNum_Intersection = icmh-1; // c(m, h);
		for(k =1; k<=iNum_Intersection; k++)
		{
			//rt[h][k].a = new double[n+1];
			//rt[h][k].b = new double[n+1];

			rt[h][k].v = 1.0;

		}	

		//---------------------------------debug----------
						 sprintf(temp, "V%02i: ", h);
						 cstrMarc += temp;
		//---------------------------------debug----------

		for(k = 1; k<=iNum_Previous; k++) //for each member of previous group V[h-1]
		{
			for(l = 2; l<=m; l++)
			{
				if(rt[h-1][k].sufend < l) // rt[h-1][k] ^ S[l] , for all k<l
				{
					for(i=1; i<=n; i++)
					{
						p = __max(rt[h-1][k].a[i], S[l].a[i]);
						q = __min(rt[h-1][k].b[i], S[l].b[i]);
						if(p<q) //the intersection is not empty
						{

							rt[h][j].a[i] = p;
							rt[h][j].b[i] = q;
							if(n<25)
								rt[h][j].v *= (q-p);
							else
								rt[h][j].v *= ((q-p)/VFactor); 

							bInterable = true;
						} //if(p<q)
						else //the intersection is empty or p=q
						{
							rt[h][j].v = 1.0; //where the last l, where some (q-p)>0 
							bInterable = false;
							break;
						}
					} //for(i=1; i<=n, i++)
					
					if(bInterable) //if intersectionable
					{
						strcpy( rt[h][j].suffix, rt[h-1][k].suffix);
						sprintf(buffer, ",%i", l);
						strcat(rt[h][j].suffix, buffer);
						
						rt[h][j].suf1st = rt[h-1][k].suf1st;
						rt[h][j].sufend = l;
						
						v[h] +=rt[h][j].v; //obtain v[h]

						//--- for debug---------------------------------------------
						 cstrMarc += ":::: ";

						 cstrMarc += rt[h][j].suffix;
						 cstrMarc += ": ";
						 sprintf(temp, "v = %.15G; ", v[h]);
						 cstrMarc += temp;

						//--- for debug---------------------------------------------

						j++;
					}
					else
					{
						
					}

				}//if(rt[1][k].sufend < l)

			}//for(l = 2, l<=m l++)

		} //for(k =1; k<=iNum_Previous; k++)
		
		for(k =1; k<=iNum_Previous; k++)
		{
			//delete [] rt[h-1][k].a;
			//delete [] rt[h-1][k].b;
		}  
		delete [] rt[h-1];

						//--- for debug
						cstrMarc += "\r\n";

						//--- for debug
		

		if(j>1)
		{
			iNum_Previous = j-1;
		}
		else //end 
		{
			break;
		}


	} //for(int h= 2; h<=m; h++)

//------ up to now, we obtain v[i];


	//we obtain Totall_v
	for(i = 1; i<=m; i++)
	{
		isign *=-1;
		Totall_v += isign * v[i];
	}

	//------1 start ---
	//write the results in the file

		//CString cstrMarc;
		//char temp[1000] = "";



		//AfxMessageBox(cstrMarc);

		CFile file;

		if(file.Open("E:\\Paper2\\CLMB_census2D\\Intersection.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
		{
			file.Write(cstrMarc, cstrMarc.GetLength() +1 );
		}
		file.Close();

	//------1 end ---
	//delete memory by operater new
	//for (i = 1; i <=m; i++)
		//delete [] rt[i];
	delete [] rt;
	delete [] v;

//~~~~~~  end ~~~~~

	return Totall_v;
}

int CMainFrame::c(int m, int i)
{
	__int64 iResult;
	unsigned __int64  iFenZi=1; //·Ö×Ó //unsigned __int64 
	unsigned __int64  iFenMu =1; //·ÖÄ¸
	int k;

	if (i > int(m/2) )
		  i = m-i;

	for(k=m; k>=m-i+1; k--)
		iFenZi *=k;

	for(k=i; k>=1; k--)
		iFenMu *=k;
	iResult = iFenZi/iFenMu;
	
    return (int) iResult;

}

void CMainFrame::OnViewCluster2D100q() 
{
	// Up to now, this function is only used to test Address.


	if(!zlOpenDB())
	{
		AfxMessageBox("zlOpenDB() err!");
		zlCloseDB();
	}

	long lStartTimer = GetTickCount();
	//long lEndTimer;

	int m = 100; //20; //10; //9;    //10;  //the number of rectangles 
	int n = 2;	//104;   //the dimensions of space
	double Totall_v =0.0; // Totall_v = v(U Si )
	int i, j;
	int old_m = m;

	//Seed the random-number generator with current time
	srand( (unsigned)time( NULL ) );
	
	int iRandom = rand()%100;

//char * * pGcdd;
//pGcdd = new ( char  (*[nPtrBufSize]) );
//	zlGetPartString(Marc->System.Gcdd, &pRtn, &nPtrBufSize, &nMaxStrSize)
//	bool CLibServerApp::zlGetPartString(char * inString, LPCHAR lpCharBuf, LPDWORD lpNumOfPtr, LPDWORD lpNumOfStr)
//the last 3 ones is return.
	
	ZLRECT * S = new ZLRECT[m+1]; //S[m+1];
	//ZLRECT * T = new ZLRECT[m+1]; //T[m+1];
	ZLRECT ** T = new ( ZLRECT (*[m+1]) ); //T[m+1];

	for(i=1; i<=m; i++)
	{
		//S[i].a = new double[n+1];
		//S[i].b = new double[n+1];

		////T[i].a = new double[n+1];
		////T[i].b = new double[n+1];
	}

	//1. Get m initial rectagles randomly from [15, 90]x[0, 347998]
	for(i=1; i<=m; i++)
	{

		for(j= 1; j <=1; j++)
		{
			// 15<= Age <= 90
			S[i].a[j] = rand()%90; 
			if(S[i].a[j] < 15)
				S[i].a[j] = 15;

			S[i].b[j] = S[i].a[j] + rand()%90 + 1; 
			if(S[i].b[j] >90)
				S[i].b[j] = 90;
		}

		for(j= 2; j <=n; j++)
		{
			//income is in [0, 347998]
			S[i].a[j] = rand()%350000;
			if(S[i].b[j]> 347998)
				S[i].b[j] = 347998;

			S[i].b[j] = S[i].a[j] + rand()%300 + 1; 
			if(S[i].b[j]> 350000)
				S[i].b[j] = 350000;
		}

		S[i].v =1;
		for(j=1; j<=n; j++)
		{
			S[i].v *= (S[i].b[j]-S[i].a[j]);

		}
		sprintf(S[i].suffix, "%d", i);
		S[i].suf1st = i;
		S[i].sufend = i;
		S[i].cn =0;
		S[i].bsn = i;
	}
	
	char temp[512] = "";
	CString cstrMarc = "";

//------test 1 start ------
for(i=1; i<=m; i++)
{
           
	//sprintf(temp, " S%02i: [%.2f, %.2f]x[%.2f, %.2f]: ",i, S[i].a[1], S[i].b[1], S[i].a[2], S[i].b[2] );
	//cstrMarc += temp;
	//cstrMarc += "\r\n";

}
	cstrMarc += "\r\n";
	cstrMarc += "\r\n";

//------test 1 end --------


	//2. Eliminating redundant squares temporarily
	bool rmvable =false;
    int l=1; 
	int k;

	for(i=1; i<=m; i++)
	{
		for(k=1; k<=m; k++)
		{
		   if(i != k)
		   {
				for(j=1; j<=n; j++)
				{
					 // if S[i] is the subset of S[k], 
					if( (S[k].a[j]<=S[i].a[j]) && (S[i].b[j]<=S[k].b[j] ))
					{
						rmvable = true;
					}
					else
					{
						rmvable = false;
						break; //break j, for next k
					}
				} //for(j= 1; j <=n; j++)
				
				if(rmvable) //there is a k such that Si is in Sk
				{
						//-------test 2---
							sprintf(temp, " S%ld cover, REMOVE S%i: [%.2f, %.2f]x[%.2f, %.2f]: ", k, i, S[i].a[1], S[i].b[1], S[i].a[2], S[i].b[2] );
							cstrMarc += temp;
							cstrMarc += "\r\n";

						//-------test 2---
					S[i].bsn = k;
					break;  // break k and then for next i
				}
		   } //if(i != k)

		}//for(k=1; i<=m; k++)

		if( (rmvable == false) || (l==1 && i==m && rmvable) ) //cannot be removed
		{
			T[l] = &S[i]; // T[l] is only the address of S[i]. 
						  //if the contence of T[l] has been changed.
						  // then, also has S[i] 


			//T[l] = S[i]; when 	
							  //ZLRECT * S = new ZLRECT[m+1]; //S[m+1];
							  //ZLRECT * T = new ZLRECT[m+1]; //T[m+1];

			// :==: is the same as :==:
			//memset(&T[l], 0, sizeof(ZLRECT));
			//memcpy(&T[l], &S[i], sizeof(ZLRECT));


			/*
			
			for(j= 1; j <=n; j++)
			{
				T[l].a[j] = S[i].a[j];
				T[l].b[j] = S[i].b[j]; 
			}
			T[l].v=S[i].v;

			sprintf(T[l].suffix, "%d", l);
			T[l].suf1st = l;
			T[l].sufend = l;
			T[l].cn = 0;
			*/
			//T[l].bsn = l;
			T[l]->bsn = l;
			S[i].bsn= 10000+l; // the remainder of S[i]: S[i].bsn = T[l].bsn +10000
			
			l++;
		}
	}//for(i=1; i<=m; i++)

//22222222222222222
	for(i=1; i<=m; i++)
	{
		//delete [] T[i].a ;
		//delete [] T[i].b ;
	}
	delete [] T;
//22222222222222222	
}

void CMainFrame::OnViewTestsmall() 
{
	ZLRECT S, T;
	S.a[1] = 10;
	S.b[1] = 30;
	S.a[2] = 100;
	S.b[2] = 300;

	T.a[1] = 20;
	T.b[1] = 40;
	T.a[2] = 200;
	T.b[2] = 400;

	ZLRECT Rect[30];

	int p=0;

	CLearnIing6App * pApp = (CLearnIing6App * ) AfxGetApp();
	p = pApp->zlDiffRects(S, T, 2);			
    
	for(int ii =1; ii<=p; ii++)
	{
		Rect[ii] = pApp->ss[ii];
	}

	int ww =0;

return;



/************
	if(!zlOpenDB())
	{
		AfxMessageBox("zlOpenDB() err!");
		zlCloseDB();
	}

	long lStartTimer = GetTickCount();
	long lEndTimer;
	
	char temp[512] = "";
	CString cstrMarc = "";
	char szSql[12048] ="";

	int  ituples_cnt = 0, iRowCnt = 0;
	char TableName[] = "CLUM_census2D";

	int i, j, m=2;
	long iSum_TickCount =0;
	int n =2;

	ZLRECT T[4];
	for(i =0; i<4; i++)
	{
		//T[i].a = new double[n+1];
	    //T[i].b = new double[n+1];
	}

	//// Age in [15,90]; Income in [-25897,347998]
	T[1].a[1]=15;
	T[1].b[1]=85;
	T[1].a[2]=3000;
	T[1].b[2]= 113070;//13070;//3070;

	T[2].a[1]=20;
	T[2].b[1]=90;
	T[2].a[2]=2995;
	T[2].b[2]=113065;//13065;//3065;



	//3. Select * from 4 cases;
	//SELECT * FROM CLMB_census2D where (20 <= Age and Age <= 50) AND (3000 <= Income and Income <= 60000)

		//3.0 select * FROM  ALL TABLE: SELECT * FROM CLMB_census2D, 

	strcpy(	szSql, 	" SELECT * FROM CLMB_census2D ");
	//lStartTimer = GetTickCount();
		//ituples_cnt = zlExeSelect(TableName, szSql);
	//lEndTimer = GetTickCount() - lStartTimer ;
	
	//----- SQLExecDirect body start -----------------

	SQLFreeStmt(hstmt, SQL_DROP);
	retcode = SQLAllocStmt(hdbc, &hstmt); ///Statement handle 
	if(retcode != SQL_SUCCESS)
		AfxMessageBox("retcode != SQL_SUCCESS"); //return -1;
	SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
	SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
	

	lStartTimer = GetTickCount();
		retcode = SQLExecDirect(hstmt, (unsigned char *)szSql, SQL_NTS);  //2005.02.07
	lEndTimer = GetTickCount() - lStartTimer ;

	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
	{  //	retcode = SQLExecDirect
	
		int iRowCount;
		SDWORD *  RowCountPtr = new SDWORD ;
		retcode = SQLRowCount(hstmt, RowCountPtr);						 
		iRowCount = * RowCountPtr;
		delete RowCountPtr;
		ituples_cnt = iRowCount;
	}
	//----- SQLExecDirect body end  -----------------


	cstrMarc += "\r\n";
    sprintf(temp, "SELECT * FROM CLMB_census2D: \r\n    GetTickCount = %ld; size = %ld ", lEndTimer, ituples_cnt);
	cstrMarc += temp;
	cstrMarc += "\r\n";
	cstrMarc += "\r\n";



	//3.1 select * each reach rectangle of all m , 
	//m = min(m,l-1);
	//		((Age between 15 and 85) AND (Income between 3000 and 3070))
	//		 		OR 
	//	( (Age between 20 and 90) AND (Income between 2995 and 3065) )
	
	

	for(i = 1; i<=m; i++) // there are m rectangles
	{
		strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ( ( ");
		
			sprintf(temp, " %.2f ", T[i].a[1] );
			strcat(	szSql, temp	);
			strcat(	szSql, "<= age AND age <=");
			sprintf(temp, " %.2f ", T[i].b[1] );
			strcat(	szSql, temp	);

			strcat(	szSql, ") AND (" );

			sprintf(temp, " %.2f ", T[i].a[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, 	"<= Income AND Income <=");
			sprintf(temp, " %.2f ", T[i].b[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, ") ) "	);

			//lStartTimer = GetTickCount();
			//	ituples_cnt = zlExeSelect(TableName, szSql);
		    //lEndTimer = GetTickCount() - lStartTimer ;
	//----- SQLExecDirect body start -----------------

	SQLFreeStmt(hstmt, SQL_DROP);
	retcode = SQLAllocStmt(hdbc, &hstmt); ///Statement handle 
	if(retcode != SQL_SUCCESS)
		AfxMessageBox("retcode != SQL_SUCCESS");//return -1;
	SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
	SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
	

	lStartTimer = GetTickCount();
		retcode = SQLExecDirect(hstmt, (unsigned char *)szSql, SQL_NTS);  //2005.02.07
	lEndTimer = GetTickCount() - lStartTimer ;

	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
	{  //	retcode = SQLExecDirect
	
		int iRowCount;
		SDWORD *  RowCountPtr = new SDWORD ;
		retcode = SQLRowCount(hstmt, RowCountPtr);						 
		iRowCount = * RowCountPtr;
		delete RowCountPtr;
		ituples_cnt = iRowCount;
	}
	//----- SQLExecDirect body end  -----------------
			
			iSum_TickCount += lEndTimer;

			cstrMarc += "\r\n";
			cstrMarc += szSql;
			cstrMarc += "\r\n";

            sprintf(temp, " Rectagle%i: [%.2f, %.2f]x[%.2f, %.2f]: ",i, T[i].a[1], T[i].b[1], T[i].a[2], T[i].b[2] );
			cstrMarc += temp;
            sprintf(temp, " \r\n  GetTickCount = %ld, Tuples# = %ld ", lEndTimer, ituples_cnt);
			cstrMarc += temp;
			cstrMarc += "\r\n";
	}

	    sprintf(temp, "       Sum of Tick Count = %ld", iSum_TickCount);
		cstrMarc += temp;
		cstrMarc += "\r\n";

	//3.2 select * From UNION, 

		cstrMarc += "\r\n";
		cstrMarc += " 2. select * From UNION ";

	//(1)
	strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ");

	for(i = 1; i<=m; i++)
	{
		strcat(	szSql, 	" ( ( ");

			sprintf(temp, " %.2f", T[i].a[1] );
			strcat(	szSql, temp	);
			strcat(	szSql, "<= age AND age <=");
			sprintf(temp, " %.2f", T[i].b[1] );
			strcat(	szSql, temp	);

			strcat(	szSql, ") AND (" );

			sprintf(temp, " %.2f", T[i].a[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, 	"<= Income AND Income <=");
			sprintf(temp, " %.2f", T[i].b[2] );
			strcat(	szSql, temp	);
		strcat(	szSql, ") ) "	);

		if(i<m)
			strcat(	szSql, " OR " );
	}

	//AfxMessageBox(szSql);

	//lStartTimer = GetTickCount();
	//	ituples_cnt = zlExeSelect(TableName, szSql);
	//lEndTimer = GetTickCount() - lStartTimer ;
	
	//iSum_TickCount += lEndTimer;

	//----- SQLExecDirect body start -----------------

	SQLFreeStmt(hstmt, SQL_DROP);
	retcode = SQLAllocStmt(hdbc, &hstmt); ///Statement handle 
	if(retcode != SQL_SUCCESS)
		AfxMessageBox("retcode != SQL_SUCCESS"); //return -1;
	SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
	SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
	

	lStartTimer = GetTickCount();
		retcode = SQLExecDirect(hstmt, (unsigned char *)szSql, SQL_NTS);  //2005.02.07
	lEndTimer = GetTickCount() - lStartTimer ;

	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
	{  //	retcode = SQLExecDirect
	
		int iRowCount;
		SDWORD *  RowCountPtr = new SDWORD ;
		retcode = SQLRowCount(hstmt, RowCountPtr);						 
		iRowCount = * RowCountPtr;
		delete RowCountPtr;
		ituples_cnt = iRowCount;
	}
	//----- SQLExecDirect body end  -----------------


	cstrMarc += "\r\n (1)";
	cstrMarc += szSql;
	cstrMarc += "\r\n";

    //sprintf(temp, " \r\n		The UNION¡¡spend TickCount = %ld", lEndTimer);
    sprintf(temp, " \r\n  GetTickCount = %ld, Tuples# = %ld ", lEndTimer, ituples_cnt);
	cstrMarc += temp;
	cstrMarc += "\r\n";

//////////////////////////////////////////////////////

//(a) Use between ¡­ and ¡­
//      SELECT * FROM CLMB_census2D Where 
//		((Age between 15 and 85) AND (Income between 3000 and 3070))
//			 		OR 
//		( (Age between 20 and 90) AND (Income between 2995 and 3065) )

	strcpy(	szSql, 	" SELECT * FROM CLMB_census2D Where \
		((Age between 15 and 85) AND (Income between 3000 and 113070)) \
			 		OR \
		( (Age between 20 and 90) AND (Income between 2995 and 113065) ) ");

	//----- SQLExecDirect body start -----------------

	SQLFreeStmt(hstmt, SQL_DROP);
	retcode = SQLAllocStmt(hdbc, &hstmt); ///Statement handle 
	if(retcode != SQL_SUCCESS)
		AfxMessageBox("retcode != SQL_SUCCESS"); //return -1;
	SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
	SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
	

	lStartTimer = GetTickCount();
		retcode = SQLExecDirect(hstmt, (unsigned char *)szSql, SQL_NTS);  //2005.02.07
	lEndTimer = GetTickCount() - lStartTimer ;

	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
	{  //	retcode = SQLExecDirect
	
		int iRowCount;
		SDWORD *  RowCountPtr = new SDWORD ;
		retcode = SQLRowCount(hstmt, RowCountPtr);						 
		iRowCount = * RowCountPtr;
		delete RowCountPtr;
		ituples_cnt = iRowCount;
	}
	//----- SQLExecDirect body end  -----------------


	cstrMarc += "\r\n (a) Use between ¡­ and ¡­ ";
	cstrMarc += "\r\n";
	cstrMarc += "\r\n";
	cstrMarc += szSql;
	cstrMarc += "\r\n";

    //sprintf(temp, " \r\n		The UNION¡¡spend TickCount = %ld", lEndTimer);
    sprintf(temp, " \r\n  GetTickCount = %ld, Tuples# = %ld ", lEndTimer, ituples_cnt);
	cstrMarc += temp;
	cstrMarc += "\r\n";
//(b) Use union 
   //   SELECT * FROM CLMB_census2D Where 
//	  (Age between 15 and 85) AND (Income between 3000 and 3070)
   //   union 
//	  SELECT * FROM CLMB_census2D Where 
//	  (Age between 20 and 90) AND (Income between 2995 and 3065)

	strcpy(	szSql, 	" SELECT * FROM CLMB_census2D Where \
	  ( (Age between 15 and 85) AND (Income between 3000 and 113070) )\
      union \
	  SELECT * FROM CLMB_census2D Where \
	  ( (Age between 20 and 90) AND (Income between 2995 and 113065) )" );

	//----- SQLExecDirect body start -----------------

	SQLFreeStmt(hstmt, SQL_DROP);
	retcode = SQLAllocStmt(hdbc, &hstmt); ///Statement handle 
	if(retcode != SQL_SUCCESS)
		AfxMessageBox("retcode != SQL_SUCCESS"); //return -1;
	SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
	SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
	

	lStartTimer = GetTickCount();
		retcode = SQLExecDirect(hstmt, (unsigned char *)szSql, SQL_NTS);  //2005.02.07
	lEndTimer = GetTickCount() - lStartTimer ;

	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
	{  //	retcode = SQLExecDirect
	
		int iRowCount;
		SDWORD *  RowCountPtr = new SDWORD ;
		retcode = SQLRowCount(hstmt, RowCountPtr);						 
		iRowCount = * RowCountPtr;
		delete RowCountPtr;
		ituples_cnt = iRowCount;
	}
	//----- SQLExecDirect body end  -----------------


	cstrMarc += "\r\n (b) Use union ";
	cstrMarc += "\r\n";
	cstrMarc += "\r\n";
	cstrMarc += szSql;
	cstrMarc += "\r\n";

    sprintf(temp, " \r\n  GetTickCount = %ld, Tuples# = %ld ", lEndTimer, ituples_cnt);
	cstrMarc += temp;
	cstrMarc += "\r\n";

//(c) Use union all (this will keep duplicates)
      //SELECT * FROM CLMB_census2D Where 
	  //(Age between 15 and 85) AND (Income between 3000 and 3070)
      //union all 
	  //SELECT * FROM CLMB_census2D Where 
	  //(Age between 20 and 90) AND (Income between 2995 and 3065)

	strcpy(	szSql, 	" SELECT * FROM CLMB_census2D Where\
	  ( (Age between 15 and 85) AND (Income between 3000 and 113070) )\
      union all \
	  SELECT * FROM CLMB_census2D Where \
	  ( (Age between 20 and 90) AND (Income between 2995 and 113065) )" );

	//----- SQLExecDirect body start -----------------

	SQLFreeStmt(hstmt, SQL_DROP);
	retcode = SQLAllocStmt(hdbc, &hstmt); ///Statement handle 
	if(retcode != SQL_SUCCESS)
		AfxMessageBox("retcode != SQL_SUCCESS"); //return -1;
	SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
	SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
	

	lStartTimer = GetTickCount();
		retcode = SQLExecDirect(hstmt, (unsigned char *)szSql, SQL_NTS);  //2005.02.07
	lEndTimer = GetTickCount() - lStartTimer ;

	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
	{  //	retcode = SQLExecDirect
	
		int iRowCount;
		SDWORD *  RowCountPtr = new SDWORD ;
		retcode = SQLRowCount(hstmt, RowCountPtr);						 
		iRowCount = * RowCountPtr;
		delete RowCountPtr;
		ituples_cnt = iRowCount;
	}
	//----- SQLExecDirect body end  -----------------


	cstrMarc += "\r\n (c) Use union all (this will keep duplicates) ";
	cstrMarc += "\r\n";
	cstrMarc += "\r\n";
	cstrMarc += szSql;
	cstrMarc += "\r\n";

    sprintf(temp, " \r\n  GetTickCount = %ld, Tuples# = %ld ", lEndTimer, ituples_cnt);
	cstrMarc += temp;
	cstrMarc += "\r\n";


///////////////////////////////////////////////

	//3.3  select * From SCR, scr (Small Cover Rectagle,)

	cstrMarc += "\r\n";
	cstrMarc += " 3. select * From SCR ";


	ZLRECT scr;

	//scr.a = new double[n+1];
	//scr.b = new double[n+1];
	
	for(i=1; i<=n; i++ )
	{
		scr.a[i] = T[1].a[i];
		scr.b[i] = T[1].b[i];

		for(j=2; j<=m; j++ )
		{
			scr.a[i] = min(scr.a[i], T[j].a[i]);
			scr.b[i] = max(scr.b[i], T[j].b[i]);
		}
	}

///===========
//scr.a[1] = 15; scr.b[1]=90;
//scr.a[2] =0 ; scr.b[2]= 347998;   

//scr.a[2] =-25897 ; scr.b[2]= 347998;  //-25897	347998
///===========


		strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ( ( ");
		
			sprintf(temp, " %.2f ", scr.a[1] );
			strcat(	szSql, temp	);
			strcat(	szSql, "<= age AND age <=");
			sprintf(temp, " %.2f ", scr.b[1] );
			strcat(	szSql, temp	);

			strcat(	szSql, ") AND (" );

			sprintf(temp, " %.2f ", scr.a[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, 	"<= Income AND Income <=");
			sprintf(temp, " %.2f ", scr.b[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, ") ) "	);


//strcpy(	szSql, 	" SELECT * FROM CLMB_census2D Where ( (15 <=Age AND Age<=90) AND (0 <=Income and income <= 347998) ) ");

			//lStartTimer = GetTickCount();
			//	ituples_cnt = zlExeSelect(TableName, szSql);
		    //lEndTimer = GetTickCount() - lStartTimer ;
			
	//----- SQLExecDirect body start -----------------

	SQLFreeStmt(hstmt, SQL_DROP);
	retcode = SQLAllocStmt(hdbc, &hstmt); ///Statement handle 
	if(retcode != SQL_SUCCESS)
		AfxMessageBox("retcode != SQL_SUCCESS"); //return -1;
	SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
	SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
	

	lStartTimer = GetTickCount();
		retcode = SQLExecDirect(hstmt, (unsigned char *)szSql, SQL_NTS);  //2005.02.07
	lEndTimer = GetTickCount() - lStartTimer ;

	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
	{  //	retcode = SQLExecDirect
	
		int iRowCount;
		SDWORD *  RowCountPtr = new SDWORD ;
		retcode = SQLRowCount(hstmt, RowCountPtr);						 
		iRowCount = * RowCountPtr;
		delete RowCountPtr;
		ituples_cnt = iRowCount;
	}
	//----- SQLExecDirect body end  -----------------

			cstrMarc += "\r\n";
			cstrMarc += szSql;
			cstrMarc += "\r\n";

			cstrMarc += "\r\n";
            sprintf(temp, "scr: [%.2f, %.2f]x[%.2f, %.2f]: ", scr.a[1], scr.b[1], scr.a[2], scr.b[2] );
			cstrMarc += temp;
			sprintf(temp, " \r\n  GetTickCount = %ld, Tuples# =  %ld", lEndTimer, ituples_cnt);
			cstrMarc += temp;
			cstrMarc += "\r\n";
			cstrMarc += "\r\n";


	//--------------- the test samll end ------------
	
	
	CFile file;

	if(file.Open("E:\\Paper2\\To_Meng_Big_Big.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
	{
		file.Write(cstrMarc, cstrMarc.GetLength() +1 );
	}
	file.Close();

		
	//delete [] scr.a;
	//delete [] scr.b;
	
	for(i =0; i<4; i++)
	{
		//delete [] T[i].a ;
	   // delete [] T[i].b ;
	}


	AfxMessageBox("Test samll OK!");
	zlCloseDB();

 ***************/
}

void CMainFrame::OnCensus2DWorkLoad() 
{
	//create sample of profiles
	//Menu :Generator- Gauss2DWorkLoad
    // 2005.4.6 USE IT

	int iErr = 0;
	char tmp[100] = "";
	CString CStrInsert = ""; 
	
	SWORD  sAge;
	SDWORD cbAge;

	SDWORD sIncome;
	SDWORD cbIncome;
	
	//int iSizeSmpl = 1459; //250; // 200;//400; //800; //1000; //2000; 
						 ////||||100, 200, 400, 800, 1000,2000. 
						  // size of census2Dg = 145,917; CLMB_census = 210,138.
						  // Date 2003.3.24

	//int iSizeSmpl = 178; //730; //365; 

	//int iSizeSmpl = 80; //20; //for having same queries 20%, 50%, 80%.
	//int iSizeSmpl = 50; //50; //for having same queries 20%, 50%, 80%.
	//int iSizeSmpl = 20;//80; //for having same queries 20%, 50%, 80%.
	int iSizeSmpl = 100; //for WorkLoad
	int iRowCount=0, iTotalNum =0;
	char cAge[20] = "", cIncome[20] = "";


	//Seed the random-number generator with current time
	srand( (unsigned)time( NULL ) );	
	int iRandom = rand();
	char szSQL[1024] = "";

		if(!zlOpenDB())
		{
			AfxMessageBox("zlOpenDB() err!");
			zlCloseDB();
		}else
		{
			///retcode = SQLAllocStmt(hdbc, &hstmt_Generet2DWorkload); ///Statement handle 

			//lStartTimer = GetTickCount();

			//UCHAR szSqlAllRows[] = "SELECT * FROM Gauss2Dg"; //discounts, authors, Census2DTable						
			//UCHAR szSqlAllRows[] = "SELECT * FROM Census2Dg"; //discounts, authors, Census2DTable						
			//UCHAR szSqlAllRows[] = "SELECT * FROM CLMB_Census2D"; //discounts, authors, Census2DTable						
		
			//UCHAR szSqlAllRows[] = "SELECT * FROM Census2D_smpl0178"; //take x% from it 
			//UCHAR szSqlAllRows[] = "SELECT * FROM DATA_Census2Dg_B_workload"; //take (100-x)% from it 
		
			

			//SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
			//SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
			//retcode = SQLExecDirect(hstmt, szSqlAllRows, SQL_NTS);


			//lEndTimer = GetTickCount() - lStartTimer;
			//wsprintf(tmp, "%ld", lEndTimer);

			//1111111111111 read data base 111111111111111

	
			do
			{
				iRowCount=0;	
				iRandom = rand();

			    strcpy(szSQL, " SELECT * FROM CLMB_Census2D WHERE Census2DID = ");
				sprintf(tmp, "%ld", (iRandom*10 + iRandom%10 )%210138+1 );
				strcat(szSQL, tmp);
				
				SQLFreeStmt(hstmt, SQL_DROP);
				retcode = SQLAllocStmt(hdbc, &hstmt); ///Statement handle 
				if(retcode != SQL_SUCCESS)
					AfxMessageBox("retcode != SQL_SUCCESS"); //return -1;

				SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
				SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
				

				retcode = SQLExecDirect(hstmt, (unsigned char *)szSQL, SQL_NTS);  //2005.02.07
				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO ) 
				{    //	retcode = SQLExecDirect
					SDWORD *  RowCountPtr = new SDWORD ;
					retcode = SQLRowCount(hstmt, RowCountPtr);						 
					iRowCount = * RowCountPtr;
					delete RowCountPtr;
					
					// Bind columns 1,2.
					SQLBindCol(hstmt, 1, SQL_C_SSHORT, &sAge, 0, &cbAge);
					SQLBindCol(hstmt, 2, SQL_C_SLONG, &sIncome,0, &cbIncome); //SQL_C_SSHORT
					
					retcode = SQLFetch(hstmt);

					
					if(iRowCount ==1 && retcode == SQL_SUCCESS )
					{
						sprintf(cAge,"%d",sAge);
						sprintf(cIncome,"%ld",sIncome);
						
						CStrInsert = "";
						CStrInsert += " INSERT DATA_Census2Dg_B_workload VALUES( ";
			
						CStrInsert += cAge;
						CStrInsert += ",";
						CStrInsert += cIncome;
						CStrInsert += ")";

						SQLFreeStmt(hstmt, SQL_DROP);
						retcode = SQLAllocStmt(hdbc, &hstmt); ///Statement handle 
						if(retcode != SQL_SUCCESS)
							AfxMessageBox("retcode != SQL_SUCCESS 222"); //return -1;

						SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
						SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
						retcode = SQLExecDirect(hstmt, (unsigned char *)CStrInsert.GetBuffer(CStrInsert.GetLength() +1), SQL_NTS);


						if (retcode == SQL_SUCCESS) 
							iTotalNum ++;
						else
							iErr++;
					}
				
				}
				if(iTotalNum >=iSizeSmpl)
					break;	
			}while(true);

		//111111111111111111 read data base end111111111111

		}


	//SQLFreeStmt(hstmt, SQL_DROP);
	zlCloseDB();

	AfxMessageBox("Insert hstmt_Generet2DWorkload OK!");
	
}


//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void CMainFrame::OnCensus2DResults() 
{
	if(!zlOpenDB())
	{
		AfxMessageBox("zlOpenDB() err!");
		zlCloseDB();
	}

	long lStartTimer = GetTickCount();
	long lEndTimer;

	long lALL_StartTimer = GetTickCount();
	long lALL_EndTimer;
	int  iALL_TickCount = 0;

	int m = 100; //20; //10; //9;    //10;  //the number of rectangles 
	int n = COL_NUM; //2;	//104;   //the dimensions of space
	double Totall_v =0.0; // Totall_v = v(U Si )
	int i, j;
	int old_m = m;
    RESULT_LEARNING RstLng[100 +1];

	//Seed the random-number generator with current time
	srand( (unsigned)time( NULL ) );
	
	int iRandom = rand()%100;

	ZLRECT * S = new ZLRECT[m+1]; //S[m+1];
	ZLRECT * T = new ZLRECT[m+1]; //T[m+1];
	//-- NOT use the following definition: 
	//      ZLRECT ** T = new ( ZLRECT (*[m+1]) ); //T[m+1];

//----------- 1. Get m initial rectangles from DB
	// [15, 90]x[-25897, 347998]: the domain of the table CLMB_census2D
    //15 <=	Age <= 90	
    //-25897 <= income <=347998
	//SELECT MIN(attr0), MIN(attr1), MAX(attr0), MAX(attr1) FROM Attr_Census2D

   //15	-25897	90	347998

	int iQryIdx =1;

	int longTicks =0, shortTicks =0;
	int f_rst= 0, shortTicks_rst = 0; //2003/4/5
    char tmp[512] = "";
	double  fCol[COL_NUM+1];		//Elevation
	SDWORD cbCol[COL_NUM+1]; 

	int		sN,  sf,  sf_rst,  sshortTicks_rst,  sshortTicks,  slongTicks;
	SDWORD cbN, cbf, cbf_rst, cbshortTicks_rst, cbshortTicks, cblongTicks;
	double	sr;	
	SDWORD cbr;
	sf_rst =0;  sshortTicks_rst=0;

	UCHAR szSqlAllLearningRows[] = "SELECT * FROM Census2D_T0100_B_Learning_P0178"; //census 2dim 
	//UCHAR szSqlAllLearningRows[] = " SELECT * FROM Census2D_T0100_B_OPT "; //census 2dim 

	SQLFreeStmt(hstmt, SQL_DROP);
	retcode = SQLAllocStmt(hdbc, &hstmt); ///Statement handle 
	if(retcode != SQL_SUCCESS)
		AfxMessageBox("1. Get m initial rectangles from DB, Error!" ); //return -1;

	SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
	SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
	
	longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, szSqlAllLearningRows, SQL_NTS);
	longTicks = GetTickCount() - longTicks;

	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO ) 
	{    //	retcode = SQLExecDirect for DATA_Top100_Census2D_Profile
		
		int iRowCount;
		SDWORD *  RowCountPtr = new SDWORD ;
		retcode = SQLRowCount(hstmt, RowCountPtr);						 
		iRowCount = * RowCountPtr;
		//iTupleNum = iRowCount;
		//iSizeProfile = iRowCount; // here only size of profile, 218, 436, 872, //100,200, ...,2000
		delete RowCountPtr;
		
		// Bind columns 1,2,3,4, ..., 104
		for(i = 0; i <COL_NUM+1; i++)
		{
			fCol[i] =0.0;
			cbCol[i] = 0; 
		}
		// Bind columns 1,2,3,4 ,.., COL_NUM
		for(i = 0; i <COL_NUM; i++)
			SQLBindCol(hstmt, i+1, SQL_C_DOUBLE, &fCol[i],0, &cbCol[i]); //SQL_C_SSHORT

		SQLBindCol(hstmt, COL_NUM+1, SQL_C_SLONG, &sN,0, &cbN); //SQL_C_SSHORT
		SQLBindCol(hstmt, COL_NUM+2, SQL_C_DOUBLE, &sr,0, &cbr); //SQL_C_SSHORT
		SQLBindCol(hstmt, COL_NUM+3, SQL_C_SLONG, &sf,0, &cbf); //SQL_C_SSHORT

		SQLBindCol(hstmt, COL_NUM+4, SQL_C_SLONG, &sf_rst,0, &cbf_rst); //SQL_C_SSHORT
		SQLBindCol(hstmt, COL_NUM+5, SQL_C_SLONG, &sshortTicks_rst,0, &cbshortTicks_rst); //SQL_C_SSHORT
		SQLBindCol(hstmt, COL_NUM+6, SQL_C_SLONG, &sshortTicks,0, &cbshortTicks); //SQL_C_SSHORT
		SQLBindCol(hstmt, COL_NUM+7, SQL_C_SLONG, &slongTicks,0, &cblongTicks); //SQL_C_SSHORT
		
		iRowCount =0;
		while (TRUE) 
		{
			retcode = SQLFetch(hstmt);

			if (retcode == SQL_ERROR)
			{
				//show_error();
				wsprintf(tmp, "%ld", iRowCount);
				//int i = iRowCount;
				AfxMessageBox("SQLFetch Error !!!!!!");
						//break; //99.8.26
			}

			if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
			{
				
				for(i = 1; i<=COL_NUM; i++)
				{
					RstLng[iQryIdx].q[i] = fCol[i-1];
				}
				
				RstLng[iQryIdx].N		= sN;
				RstLng[iQryIdx].r		= (float) sr;
				RstLng[iQryIdx].f		= sf;
				RstLng[iQryIdx].f_rst = sf_rst;
				RstLng[iQryIdx].shortTicks_rst = sshortTicks_rst;
				RstLng[iQryIdx].longTicks = slongTicks;	 
				RstLng[iQryIdx].shortTicks = sshortTicks; 

				sf_rst =0;  
				sshortTicks_rst=0;

				iQryIdx++;

				if(retcode == SQL_SUCCESS_WITH_INFO)
				{
					wsprintf(tmp, "%ld", retcode);
					AfxMessageBox(tmp);
				}
					
			} 
			else 
			{
				break;
			}

		}   ///while (TRUE)
	}//	retcode = SQLExecDirect  for DATA_Top100_Census2D_Profile


//////////////////////// 11111111111111111 ///////////////////////
	//assigned the rectangles from RstLng[i]

lALL_StartTimer = GetTickCount();
	
	for(i=1; i<=m; i++)
	{
		for(j= 1; j <=1; j++)
		{
			// 15<= Age <= 90
			S[i].a[j] = RstLng[i].q[j] - RstLng[i].r ; 
			if(S[i].a[j] < 15)
				S[i].a[j] = 15;

			S[i].b[j] = RstLng[i].q[j] + RstLng[i].r; 
			if(S[i].b[j] >90)
				S[i].b[j] = 90;
		}

		for(j= 2; j <=n; j++)
		{
			//income is in [0, 347998]
			S[i].a[j] = RstLng[i].q[j] - RstLng[i].r;
			if(S[i].a[j] < -25897 )
				S[i].a[j] = -25897 ;

			S[i].b[j] = RstLng[i].q[j] + RstLng[i].r; 
			if(S[i].b[j]> 347998)
				S[i].b[j] = 347998;
		}

		S[i].v =1;
		for(j=1; j<=n; j++)
		{
			S[i].v *= (S[i].b[j]-S[i].a[j]);

		}
		sprintf(S[i].suffix, "%d", i);
		S[i].suf1st = i;
		S[i].sufend = i;
		S[i].cn =0;
		//S[i].bsn = i; //2005.4.8
		S[i].bsn = 0; //2005.4.8

	}

lALL_EndTimer = GetTickCount()-lALL_StartTimer;
iALL_TickCount += lALL_EndTimer;
	


	char temp[512] = "";
	CString cstrMarc = "";

//------test 1 start ------
for(i=1; i<=m; i++)
{
           
	//sprintf(temp, " S%02i: [%.2f, %.2f]x[%.2f, %.2f]: ",i, S[i].a[1], S[i].b[1], S[i].a[2], S[i].b[2] );
	//cstrMarc += temp;
	//cstrMarc += "\r\n";

}
	cstrMarc += "\r\n";
	cstrMarc += "\r\n";

//------test 1 end --------

///////////////// 222222222222222222222 //////////////////////////
//2. Eliminating redundant squares temporarily
lALL_StartTimer = GetTickCount();

	bool rmvable =false;
    int l=1; 
	int k;

	rmvable =false;
	for(i=1; i<=m; i++)
	{
		for(k=1; k<=m; k++)
		{
		   // for each i, see ?? S[i] in S[k], for all k:  i!=k and S[k] is not removed
		   // this wan can avoid the situation S[i] ==S[k]. say, S[8] == S[65]
           // then in the case of S[8] == S[65], the loop of () will be dead loop

		   //if(i != k )  // 2005.4.8
		   if( i != k && S[k].bsn == 0) // 2005.4.8 
		   {
				for(j=1; j<=n; j++)
				{
					 // if S[i] is the subset of S[k], 
					if( (S[k].a[j]<=S[i].a[j]) && (S[i].b[j]<=S[k].b[j] ))
					{
						rmvable = true;
					}
					else
					{
						rmvable = false;
						break; //break j, for next k
					}
				} //for(j= 1; j <=n; j++)
				
				if(rmvable) //there is a k such that Si is in Sk 
				{
						//-------test 2---
							sprintf(temp, " S[%ld] cover, REMOVE S[%i] = [%.2f, %.2f]x[%.2f, %.2f]: ", k, i, S[i].a[1], S[i].b[1], S[i].a[2], S[i].b[2] );
							cstrMarc += temp;
							cstrMarc += "\r\n";

						//-------test 2---
					S[i].bsn = k; // s[i] is in s[k], IMPORTANT. bsn = Big Set Number
					break;  // break k and then for next i
				}
		   } //if(i != k)

		}//for(k=1; i<=m; k++)

		if( (rmvable == false) || (l==1 && i==m && rmvable) ) //cannot be removed
		{
			//T[l] = S[i];
			// :==: is the same as :==:
			//memset(&T[l], 0, sizeof(ZLRECT));
			//memcpy(&T[l], &S[i], sizeof(ZLRECT));
			
			for(j= 1; j <=n; j++)
			{
				T[l].a[j] = S[i].a[j];
				T[l].b[j] = S[i].b[j]; 
			}
			T[l].v=S[i].v;

			sprintf(T[l].suffix, "%d", l);
			T[l].suf1st = l;
			T[l].sufend = l;
			T[l].cn = 0;
			//T[l].bsn = l;  // 2004.4.13
			T[l].bsn = 0;  // 2004.4.13

			S[i].bsn= 10000+l; // the remainder of S[i]: S[i].bsn = l +10000; 
							   // where l is the index of T[l]. i.e. S[i] is the subset of T[l]
			l++;
		}
	}//for(i=1; i<=m; i++)

lALL_EndTimer = GetTickCount()-lALL_StartTimer;
iALL_TickCount += lALL_EndTimer;

//------test 3 start ------
/****
	cstrMarc += "\r\n";
	cstrMarc += "\r\n";


for(i=1; i<=l-1; i++)
{
           
	sprintf(temp, " T%02i: [%.2f, %.2f]x[%.2f, %.2f]: ",i, T[i].a[1], T[i].b[1], T[i].a[2], T[i].b[2] );
	cstrMarc += temp;
	cstrMarc += "\r\n";

}
	cstrMarc += "\r\n";
	cstrMarc += "\r\n";
****/
//------test 3 end --------


	//3. Select * from 4 cases;
	//SELECT * FROM CLMB_census2D where (20 <= Age and Age <= 50) AND (3000 <= Income and Income <= 60000)
	
	
	
	char szSql[12048] = "";
	int  ituples_cnt = 0;
	char TableName[] = "CLUM_census2D";
	int iSum_TickCount = 0;
    int iSum_TuplesCount =0;
	//3.0 select * FROM  ALL TABLE: SELECT * FROM CLMB_census2D, 
	
	strcpy(	szSql, 	" SELECT * FROM CLMB_census2D ");
	lStartTimer = GetTickCount();
		ituples_cnt = zlExeSelect(TableName, szSql);
	lEndTimer = GetTickCount() - lStartTimer ;

	cstrMarc += "\r\n";
    sprintf(temp, "SELECT * FROM CLMB_census2D: \r\n GetTickCount = %ld", lEndTimer);
	cstrMarc += temp;
	cstrMarc += "\r\n";
	sprintf(temp, " All Size of Table = %ld", ituples_cnt);
	cstrMarc += temp;
	cstrMarc += "\r\n";
	cstrMarc += "\r\n";



//3.1 select * each reach rectangle of all m S[i], 
	
	//m = min(m,l-1);
/*
	for(i = 1; i<=m; i++) // there are m rectangles
	{
		strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ( ( ");
		
			sprintf(temp, " %.2f ", T[i].a[1] );
			strcat(	szSql, temp	);
			strcat(	szSql, "<= age AND age <=");
			sprintf(temp, " %.2f ", T[i].b[1] );
			strcat(	szSql, temp	);

			strcat(	szSql, ") AND (" );

			sprintf(temp, " %.2f ", T[i].a[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, 	"<= Income AND Income <=");
			sprintf(temp, " %.2f ", T[i].b[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, ") ) "	);

			lStartTimer = GetTickCount();
				ituples_cnt = zlExeSelect(TableName, szSql);
		    lEndTimer = GetTickCount() - lStartTimer ;
			
			iSum_TickCount += lEndTimer;

            sprintf(temp, " Rectagle%i: [%.2f, %.2f]x[%.2f, %.2f]: ",i, T[i].a[1], T[i].b[1], T[i].a[2], T[i].b[2] );
			cstrMarc += temp;
            sprintf(temp, " GetTickCount = %ld", lEndTimer);
			cstrMarc += temp;
			cstrMarc += "\r\n";


	}
*/
	// m = m ==100

	for(i = 1; i<=m; i++) // there are m the originial rectangles S[1] to S[100]
	{
		strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ( ( ");
		
			sprintf(temp, " %.2f ", S[i].a[1] );
			strcat(	szSql, temp	);
			strcat(	szSql, "<= age AND age <=");
			sprintf(temp, " %.2f ", S[i].b[1] );
			strcat(	szSql, temp	);

			strcat(	szSql, ") AND (" );

			sprintf(temp, " %.2f ", S[i].a[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, 	"<= Income AND Income <=");
			sprintf(temp, " %.2f ", S[i].b[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, ") ) "	);

			lStartTimer = GetTickCount();
				ituples_cnt = zlExeSelect(TableName, szSql);
		    lEndTimer = GetTickCount() - lStartTimer ;
			
			iSum_TickCount += lEndTimer;
			iSum_TuplesCount += ituples_cnt;

            //sprintf(temp, " S%i: [%.2f, %.2f]x[%.2f, %.2f]: tuples_num = %ld ",i, T[i].a[1], T[i].b[1], T[i].a[2], T[i].b[2], ituples_cnt );
            sprintf(temp, " S%i: [%.2f, %.2f]x[%.2f, %.2f]: tuples_num = %ld ",i, S[i].a[1], S[i].b[1], S[i].a[2], S[i].b[2], ituples_cnt );
			cstrMarc += temp;
            sprintf(temp, " GetTickCount = %ld", lEndTimer);
			cstrMarc += temp;
			cstrMarc += "\r\n";
	}


	    sprintf(temp, "       Sum of Tick Count = %ld", iSum_TickCount);
		cstrMarc += temp;
		cstrMarc += "\r\n";
		sprintf(temp, "       Sum of Tuples Count = %ld", iSum_TuplesCount);
		cstrMarc += temp;
		cstrMarc += "\r\n";


	//3.2 select * From UNION of l T[i]: from T[1] to T[l] generally l<=m , 

	cstrMarc += "\r\n";
	cstrMarc += " 2. select * From UNION ";

	strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ");

	m=l-1;  // for T[i]
	for(i = 1; i<=m; i++)
	{
		strcat(	szSql, 	" ( ( ");

			sprintf(temp, " %.2f", T[i].a[1] );
			strcat(	szSql, temp	);
			strcat(	szSql, "<= age AND age <=");
			sprintf(temp, " %.2f", T[i].b[1] );
			strcat(	szSql, temp	);

			strcat(	szSql, ") AND (" );

			sprintf(temp, " %.2f", T[i].a[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, 	"<= Income AND Income <=");
			sprintf(temp, " %.2f", T[i].b[2] );
			strcat(	szSql, temp	);
		strcat(	szSql, ") ) "	);

		if(i<m)
			strcat(	szSql, " OR " );
	}

	//AfxMessageBox(szSql);

	lStartTimer = GetTickCount();
		ituples_cnt = zlExeSelect(TableName, szSql);
	lEndTimer = GetTickCount() - lStartTimer ;
	
	//iSum_TickCount += lEndTimer;

    sprintf(temp, " \r\n		The UNION¡¡spend TickCount = %ld", lEndTimer);
	cstrMarc += temp;
	cstrMarc += "\r\n";
    sprintf(temp, " \r\n		The UNION¡¡Tuples Number = %ld", ituples_cnt);
	cstrMarc += temp;
	cstrMarc += "\r\n";

	////3.0_1 select * FROM  ALL TABLE: SELECT * FROM CLMB_census2D, 
	
	//strcpy(	szSql, 	" SELECT * FROM CLMB_census2D ");
	//lStartTimer = GetTickCount();
	//	ituples_cnt = zlExeSelect(TableName, szSql);
	//lEndTimer = GetTickCount() - lStartTimer ;

	//cstrMarc += "\r\n";
    //sprintf(temp, "SELECT * FROM CLMB_census2D: GetTickCount = %ld", lEndTimer);
	//cstrMarc += temp;
	//cstrMarc += "\r\n";
	//cstrMarc += "\r\n";

	
///////////////////////// 333333333333333333 /////////////////////////////////
//3.3  select * From SCR, scr (Small Cover Rectagle,)

	cstrMarc += "\r\n";
	cstrMarc += " 3. select * From SCR ";

lALL_StartTimer = GetTickCount();

	ZLRECT scr;

	//scr.a = new double[n+1];
	//scr.b = new double[n+1];
	
	for(i=1; i<=n; i++ )
	{
		scr.a[i] = T[1].a[i];
		scr.b[i] = T[1].b[i];

		for(j=2; j<=m; j++ )
		{
			scr.a[i] = min(scr.a[i], T[j].a[i]);
			scr.b[i] = max(scr.b[i], T[j].b[i]);
		}
	}

lALL_EndTimer = GetTickCount()-lALL_StartTimer;
iALL_TickCount += lALL_EndTimer;

///===========
//scr.a[1] = 15; scr.b[1]=90;
//scr.a[2] =0 ; scr.b[2]= 347998;   

//scr.a[2] =-25897 ; scr.b[2]= 347998;  //-25897	347998
///===========


		strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ( ( ");
		
			sprintf(temp, " %.2f ", scr.a[1] );
			strcat(	szSql, temp	);
			strcat(	szSql, "<= age AND age <=");
			sprintf(temp, " %.2f ", scr.b[1] );
			strcat(	szSql, temp	);

			strcat(	szSql, ") AND (" );

			sprintf(temp, " %.2f ", scr.a[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, 	"<= Income AND Income <=");
			sprintf(temp, " %.2f ", scr.b[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, ") ) "	);


//strcpy(	szSql, 	" SELECT * FROM CLMB_census2D Where ( (15 <=Age AND Age<=90) AND (0 <=Income and income <= 347998) ) ");

			lStartTimer = GetTickCount();
				ituples_cnt = zlExeSelect(TableName, szSql);
		    lEndTimer = GetTickCount() - lStartTimer ;
			
			iSum_TickCount += lEndTimer;

			cstrMarc += "\r\n";
            sprintf(temp, "The Biggest scr: [%.2f, %.2f]x[%.2f, %.2f]: ", scr.a[1], scr.b[1], scr.a[2], scr.b[2] );
			cstrMarc += temp;

            sprintf(temp, "\r\n    scr  GetTickCount = %ld", lEndTimer);
			cstrMarc += temp;
			cstrMarc += "\r\n";
			sprintf(temp, "\r\n    scr  Tuples Number = %ld", ituples_cnt);
			cstrMarc += temp;
			cstrMarc += "\r\n";

			cstrMarc += "\r\n";


///////////////////////// 44444444444444444444 ///////////////////////
//3.4  ----   division 12 = 4*3 partition  of scr ----
//            select * From each partition,

lALL_StartTimer = GetTickCount();

	ZLRECT part[101]; //we use 1-12
    char   buffer[1024] ="";
	int iPartNum = 0;

	int ilnum =0, iaaallNum =0;

	CLearnIing6App * pApp = (CLearnIing6App * ) AfxGetApp();
	iPartNum = pApp->zlPartion(scr, n, T, m, iPartNum);			

lALL_EndTimer = GetTickCount()-lALL_StartTimer;
iALL_TickCount += lALL_EndTimer;



	for(i= 1; i<=iPartNum; i++)
	{
		sprintf(part[i].suffix, " Part[%i]: " , i ); 
	}

	for(i= 1; i<=iPartNum; i++)
	{
		ilnum =0;
		for(j=1; j<=m; j++)
		{
			if(T[j].bsn == i)
			{
				sprintf(buffer, ",%i", j);
				strcat(part[i].suffix, buffer); 
				ilnum ++;
			}
		}
		sprintf(buffer, "   part[%i]: ilnum= %i   ", i, ilnum);
		cstrMarc += buffer;			

		cstrMarc += part[i].suffix;						 
	    cstrMarc += "\r\n";
	    cstrMarc += "\r\n";

       iaaallNum +=ilnum;

	}

		sprintf(buffer, "   iallNum = %i", iaaallNum);
		cstrMarc += buffer;						 
	    cstrMarc += "\r\n";



	CFile file;

	//if(file.Open("E:\\Paper2\\CLMB_census2D\\cluster_100_census2D_OPT_414.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
	//if(file.Open("E:\\Paper2\\CLMB_census2D\\cluster_100_census2D.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
	//{
	//	file.Write(cstrMarc, cstrMarc.GetLength() +1 );
	//}
	//file.Close();

    //AfxMessageBox("OnViewCluster100 OK!");

//return;










/********************************
	//ZLRECT part[13]; //we use 1-12

	for(i=1; i<=12; i++)
	{
		//part[i].a = new double[n+1];
		//part[i].b = new double[n+1];
	}

	//int * a = new int[n+1];
	double * a = new double[n+1];

	double * d = new double[n+1];
	int alfa;
	int ishort =0, ilong =0;
	//a[1] =15; a[2] = -25897; 

	//d[1] = (90-15)/3; 	d[2] = ( 347998-(-25897) )/4; 

	if(scr.b[1] - scr.a[1] <= scr.b[2] - scr.a[2] )
	{
		//ishort = 1;
		//ilong  = 2;
		a[1] = scr.a[1]; 
		a[2] = scr.a[2]; 

		d[1] = (scr.b[1] - scr.a[1])/3; 	
		d[2] = ( scr.b[2] - scr.a[2])/4; 

	}
	else
	{
		//ishort = 2;
		//ilong  = 1;
		a[2] = scr.a[1]; 
		a[1] = scr.a[2]; 

		d[2] = (scr.b[1] - scr.a[1])/3; 	
		d[1] = ( scr.b[2] - scr.a[2])/4; 
	}
	//a[1] = scr.a[1]; 
	//a[2] = scr.a[2]; 

	//d[1] = (scr.b[1] - scr.a[1])/3; 	
	//d[2] = ( scr.b[2] - scr.a[2])/4; 


	//a[1] =10; a[2] = 100; 
	//d[1] = 10; 	d[2] = 100; 

	for(i=1; i<=3 ; i++)
	{
		for(j=1; j<=4; j++)
		{
			for(k = 1; k<=n; k++)
			{
				switch (k)
				{
					case 1:
						{
							alfa = i-1;
							break;
						}
					case 2:
						{
							alfa = j-1;
							break;
						}

				}
				part[(i-1)*4+j].a[k] = a[k]+ alfa*d[k];
				part[(i-1)*4+j].b[k] = a[k]+ alfa*d[k] + d[k];
			}
		}
	}

***************************/




//------test 3.4 start ------
//	cstrMarc += "\r\n";
//	cstrMarc += "\r\n";
//	CString cstrPart ;

//for(i=1; i<=12; i++)
//{
           
//	sprintf(temp, " part[%02i]: [%.2f, %.2f]x[%.2f, %.2f]: ",i, part[i].a[1], part[i].b[1], part[i].a[2], part[i].b[2] );
//	cstrPart += temp;
//    cstrPart += "\r\n";

//}

//	AfxMessageBox(cstrPart);
//	cstrMarc += "\r\n";
//	cstrMarc += "\r\n";

//------test 3.3 end --------

	iSum_TickCount =0;
	iSum_TuplesCount =0;
/**************
	for(i=1; i<=12; i++)
	{
		strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ( ( ");
		
			sprintf(temp, " %.2f ", part[i].a[1] );
			strcat(	szSql, temp	);
			strcat(	szSql, "<= age AND age <=");
			sprintf(temp, " %.2f ", part[i].b[1] );
			strcat(	szSql, temp	);

			strcat(	szSql, ") AND (" );

			sprintf(temp, " %.2f ", part[i].a[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, 	"<= Income AND Income <=");
			sprintf(temp, " %.2f ", part[i].b[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, ") ) "	);

			lStartTimer = GetTickCount();
				ituples_cnt = zlExeSelect(TableName, szSql);
		    lEndTimer = GetTickCount() - lStartTimer ;
			
			iSum_TickCount += lEndTimer;
			iSum_TuplesCount += ituples_cnt;

			sprintf(temp, " part[%02i]: [%.2f, %.2f]x[%.2f, %.2f]: ",i, part[i].a[1], part[i].b[1], part[i].a[2], part[i].b[2] );
			cstrMarc += temp;
            sprintf(temp, "Num_tuples = %ld,  GetTickCount = %ld", ituples_cnt, lEndTimer);
			cstrMarc += temp;
			cstrMarc += "\r\n";
	}

	    sprintf(temp, "       Sum of Tick Count of all Part = %ld", iSum_TickCount);
		cstrMarc += temp;
		cstrMarc += "\r\n";
		sprintf(temp, "       Sum of Tuples Count = %ld", iSum_TuplesCount);
		cstrMarc += temp;
		cstrMarc += "\r\n";
********************/


//3.5 ---- Find which rectangle intersect the partition of all 12 = 4*3 partitions ----
//         DO NOT USE intersect
//dddddddddddd
	cstrMarc += "\r\n";
	cstrMarc += "\r\n";
//dddddddddddd

	int index[101][101];  // i= 1 to 12 intersect with part[i] : index[i][1]=5, index[i][2]=7,index[i][3]=8, index[i][4]=15,...
	double p, q;
	bool bInterable =false;

	//char buffer[20] = "";

	//for(i= 1; i<=12; i++)
	for(i= 1; i<=iPartNum; i++)
	{
		sprintf(part[i].suffix, " Part[%i]: " , i );
	}

	cstrMarc += "#################";
	cstrMarc += "\r\n";
    cstrMarc += "\r\n";

//////////////////////////////////////////////////////////////////



/////////////////////// 555555555555555 /////////////////////
//3.6 ------------------- Clustering -----------------------
// we use the method of "Center IN " to clustering
	
	ZLRECT * partT[101];
	//int clsNum =0;  //2005.3.16
	//int clsNum =1000; ////2005.3.16 , only for intersections
	//int clsNum =12; ////2005.3.24 , only for intersections
	int clsNum = iPartNum; //2005.4.14

	double center =0.0;
//----for test ----
	//ZLRECT * pT = new ZLRECT [101];
//----for test ----

	//for(i= 1; i<=12; i++)
	for(i= 1; i<=iPartNum; i++)
	{
		sprintf(part[i].suffix, " Part[%i]: " , i ); 
		//?? for debug ? WHY part[i].suffix?  NOT partT[i].suffix
		// Yes, for debug!
	}

lALL_StartTimer = GetTickCount();

	//for(i= 1; i<=12; i++)
	for(i= 1; i<=iPartNum; i++)
	{
		for(j=1; j<=100; j++)
		{
			index[i][j] = 0;
		}
	}


////// ~~~~~~~~ Finding all T[j]'s that center are in part[i].
	
	for(i= 1; i<=iPartNum; i++)
	{
		l=0;
		for(j= 1; j <=m ; j++) // m is the number of T[i]'s
		{
			//T[j].bsn == i means T[j]-CENTER is IN  part[i]
			if(T[j].bsn == i && T[j].cn <=0)   
			{
					l++;
					index[i][l] = j;
					sprintf(buffer, ",%i", j);
					strcat(part[i].suffix, buffer); // save the index j of T[j] 

					T[j].cn = i;                   //2005.3.16, use it again.

					partT[l] = &T[j]; // the address of (T[j]) assign to (partT[l]);

			}
		}

		cstrMarc += part[i].suffix;						 
	    cstrMarc += "\r\n";

		if(l>0)
		{
		  //clsNum = zlClusterPart( partT, l, T, m, clsNum, n );  
		  
			AfxMessageBox( "threshold here");  //clsNum = pApp->zlClusterPart( partT, l, T, m, clsNum, n, iPartNum);  
			
		}


	}
	
lALL_EndTimer = GetTickCount()-lALL_StartTimer;
iALL_TickCount += lALL_EndTimer;

	/******************************
	for(i= 1; i<=12; i++)
	{
		l=0;

		for(j= 1; j <=m ; j++) // m is the number of T[i]'s
		{
			//###########
			if(T[j].cn <=0 ) //?? add .cn !=0 , Not, repeat
			{				 //YES! do it here
				for(k=1; k<=n; k++) //n is the number of dimensions 
				{
					//p = __max(part[i].a[k], T[j].a[k]);   //?? replace "intersect" by "center in"
					//q = __min(part[i].b[k], T[j].b[k]);   //YES , using "Center in"	
					
					center = (double)(T[j].a[k] + T[j].b[k])/2.0;

					//if(p<q) //the intersection is not empty					
					if( (part[i].a[k]<=center) && (center<= part[i].b[k]) ) //the Center in the part[i]
					{
						bInterable = true;
					} //if(p<q)
					else //the intersection is empty or p=q
					{
						bInterable = false;
						break;   //break k, because there is i0 such that p[i0] >=q[i0]  
					}

				}//for(k=1; k<=n; k++)

				if(bInterable) //if intersectable
				{
					l++;
					index[i][l] = j;
					sprintf(buffer, ",%i", j);
					strcat(part[i].suffix, buffer); // save the index j of T[j] 
													//that intersect with part[i]

					//T[j].cn = i;                  // do not change the value of .cn
													// also let it be 0; ?? or -1
													// change it in the proc zlClusterPart();

					T[j].cn = i;                   //2005.3.16, use it again.
												   // change it to T[j].cn = 1000 +i when it intersect with some others


					partT[l] = &T[j]; // the address of (T[j]) assign to (partT[l]);
									  // there is only the ADDRESS. 

									  // NOT change .suf1st, .sufend, .cn, .bsn, ... 
									  // So, to call other 2 functions , 
									  // we need to pay attention to it.
									  // Where {partT[l]'s} are the subset of {T[j]'s}
									  // that intersect with part[i].
									  
									  // ?? whether or not change the values of 
									  // .suf1st, .sufend, .cn, .bsn, ... in partT[l]'s
				}//if(bInterable) //if intersectable					 
			}//if(T[j].cn <=0 )

			//################

		}//for(j= 1; j <=m ; j++)v

		cstrMarc += part[i].suffix;						 
	    cstrMarc += "\r\n";
		// up to now we obtain all T[j]'s that in Part[i], and it index: index[i][l]
			//call the function : zlClusterPart( ZLRECT ** T, ZLRECT ** S); 
		if(l>0)
		{
		  ///////- NOT use this one: clsNum = zlClusterPart( partT, l, S, m, clsNum, n ); 
		  //------ We use T at 3 para, not use S 

		  clsNum = zlClusterPart( partT, l, T, m, clsNum, n );  
			//- where m is the new one that the is the number of T[i]'s 
		    //-     old m ==100, but new m may be 98, 96
		    //- that is removed all subsets of S[i]'s
			//- partT[i] is only the address of some T[i]'s that intersect with part[i]
			
			//----------for tset
				//for(int ijk =1; ijk <=l; ijk ++)
				//{
				//	pT[ijk] = *partT[ijk];

				//	pT[ijk].suf1st = ijk;
				//	pT[ijk].sufend = ijk;
				//	//pT[ijk].cn = 0;
				//	//pT[ijk].bsn = l;


			//	}
			    //double all_v = zlVolumeOfUnion(l, 2, pT );
			//-----------for tset
		}
	}//for(i= 1; i<=12; i++)
****************/


//---------ttest start ----------
	cstrMarc += "\r\n";
	cstrMarc += "\r\n";
    int iclsNum =0;
	int iallNum =0;

	for(i=1; i<= clsNum; i++)
	{
		iclsNum =0;

		sprintf(temp, "cluster[%02i] : ", i);
		cstrMarc += temp;
		cstrMarc += "\r\n";

		for(j=1; j<=m; j++)
		{
			if(T[j].cn == i)
			{
				//sprintf(temp, ", %02i", j);
				sprintf(temp, " T[%02i],T[%02i].bsn =%02i;  ", j, j, T[j].bsn );
				cstrMarc += temp;
				iclsNum ++;
			}			
		}


		if(iclsNum >0)
		{
			cstrMarc += "\r\n";
			sprintf(temp, "    iclsNum = %02i ", iclsNum);
			cstrMarc += temp;
			iallNum = iallNum + iclsNum; 
			cstrMarc += "\r\n";
			cstrMarc += "\r\n";

		}

	}

		sprintf(temp, " iallNum = %02i ", iallNum);
		cstrMarc += temp;
		cstrMarc += "\r\n";

//---------ttest end ----------


//////////////////////// 666666666666666666 ////////////////////////////


// 3.7 ------------------- Clustering S[] -----------------------
//    obtain all cluster number of S[i] (where i=1 to 100)


//---------ttest S[] start ----------
	cstrMarc += "\r\n";
	cstrMarc += "\r\n";

    iclsNum =0;
	iallNum =0;

	//for(i=1; i<= clsNum; i++)
	{
		iclsNum =0;

		sprintf(temp, "Cluster[%02i] : ", i);
		cstrMarc += temp;

		//for(j=1; j<=m; j++)
		//for(j=0; j<=100; j++)
		for(j=1; j<=old_m; j++)
		{
			//if(S[j].cn == i)
			{
				sprintf(temp, " S[%02i],S[%02i].bsn =%02i;  ", j, j, S[j].bsn );
				cstrMarc += temp;
				iclsNum ++;
			}	
			cstrMarc += "\r\n";
		}
		sprintf(temp, "; iclsNum = %02i ", iclsNum);
		cstrMarc += temp;
		iallNum = iallNum + iclsNum; 

		cstrMarc += "\r\n";

	}

		sprintf(temp, " iallNum = %02i ", iallNum);
		cstrMarc += temp;
		cstrMarc += "\r\n";

//---------ttest S[] end ----------


lALL_StartTimer = GetTickCount();	
	


	for(i=1; i<= old_m; i++)
	{

		do 
		{
			if(S[i].bsn > 10000)
			{	
				S[i].cn = T[S[i].bsn-10000].cn;
				break;
			}
			else
			{
				k = S[i].bsn;
				S[i].bsn = S[k].bsn;
			}

		} while (true);

	}

	
lALL_EndTimer = GetTickCount()-lALL_StartTimer;
iALL_TickCount += lALL_EndTimer;


//---------ttest S[] start ----------
	cstrMarc += "\r\n";
	cstrMarc += "\r\n";

    iclsNum =0;
	iallNum =0;

		cstrMarc += "For S[i] ";
		cstrMarc += "\r\n";
		cstrMarc += "\r\n";

	for(i=1; i<= clsNum; i++)
	{
		iclsNum =0;


		sprintf(temp, "Cluster[%02i]: ", i);
		cstrMarc += temp;
		cstrMarc += "\r\n";

		//for(j=1; j<=m; j++)
		//for(j=0; j<=100; j++)
		for(j=1; j<=old_m; j++)
		{
			if(S[j].cn == i)
			{
				//sprintf(temp, " S[%02i],S[%02i].bsn =%02i;  ", j, j, S[j].bsn );
				sprintf(temp, "S[%02i], ", j  );
				cstrMarc += temp;
				iclsNum ++;
			}			
		}
		
		if(iclsNum >0)
		{
			cstrMarc += "\r\n";
			sprintf(temp, "    iclsNum = %02i ", iclsNum);
			cstrMarc += temp;
			iallNum = iallNum + iclsNum; 
			cstrMarc += "\r\n";
		}

	}

		sprintf(temp, " iallNum = %02i ", iallNum);
		cstrMarc += temp;
		cstrMarc += "\r\n";

//---------ttest S[] end ----------


///////////////////////////  77777777777777  ///////////////////////////

// 3.8 ------------------- obtain all scr's of the Clusters of  S[]  according to the Clusters of  S[] -----------------------
//15 <=	Age <= 90	
//-25897 <= income <=	347998

lALL_StartTimer = GetTickCount();	
	

iSum_TickCount = 0;
iSum_TuplesCount =0;

	double * Sum_v_S = new double [100 +1];//[clsNum +1];
	ZLRECT * scr_CLS = new ZLRECT[100+1]; //[clsNum +1];  
	
	for(i=1; i<=clsNum; i++)
	//for(i=1; i<=100; i++)
	{
		//scr_CLS[i].a = new double[n+1];
		//scr_CLS[i].b = new double[n+1];
		scr_CLS[i].v = 1.0;
		
		Sum_v_S[i] = 0.0;
		for(k=1; k<=old_m; k++) //old_m ==100
		{
			if(S[k].cn ==i)
			{
				Sum_v_S[i] += S[k].v;
			}

		}

	}

	for(i=1; i<=clsNum; i++ )
	//for(i=1; i<=100; i++ )
	{
			scr_CLS[i].a[1] = 90;
			scr_CLS[i].b[1] = 15;
			scr_CLS[i].a[2] = 347998;
			scr_CLS[i].b[2] = -25897;

		for(j=1; j<=n; j++)
		{
			for(k=1; k<=old_m; k++) // old_m ==100
			{
				if(S[k].cn ==i)
				{
					scr_CLS[i].a[j] = min(scr_CLS[i].a[j], S[k].a[j]);
					scr_CLS[i].b[j] = max(scr_CLS[i].b[j], S[k].b[j]);

				}

			}
			//scr_CLS[i].v *= (scr_CLS[i].b[j]-scr_CLS[i].a[j]) ;
		}

		for(j=1; j<=n; j++)
		{
			scr_CLS[i].v *= (scr_CLS[i].b[j]-scr_CLS[i].a[j]) ;
		}


	}

	
lALL_EndTimer = GetTickCount()-lALL_StartTimer;
iALL_TickCount += lALL_EndTimer;



	int nonzearo =0;
	cstrMarc += "\r\n";
	for(i = 1; i<=clsNum; i++) // there are clsNum scr's of cluster scr_CLS[1] to scr_CLS[clsNum]
	//for(i = 1; i<=100; i++) // there are clsNum scr's of cluster scr_CLS[1] to scr_CLS[clsNum]
	{
		nonzearo =0;
		for(j=1; j<=old_m; j++)
		{
			if(S[j].cn ==i)
			{
				//sprintf(temp, " ,S[%02i] ", j );
				//cstrMarc += temp;
				nonzearo ++;
			}
		}
      if(nonzearo !=0)
	  {
		strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ( ( ");
		
			sprintf(temp, " %.2f ", scr_CLS[i].a[1] );
			strcat(	szSql, temp	);
			strcat(	szSql, "<= age AND age <=");
			sprintf(temp, " %.2f ", scr_CLS[i].b[1] );
			strcat(	szSql, temp	);

			strcat(	szSql, ") AND (" );

			sprintf(temp, " %.2f ", scr_CLS[i].a[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, 	"<= Income AND Income <=");
			sprintf(temp, " %.2f ", scr_CLS[i].b[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, ") ) "	);

			lStartTimer = GetTickCount();
				ituples_cnt = zlExeSelect(TableName, szSql);
		    lEndTimer = GetTickCount() - lStartTimer ;
			
			iSum_TickCount += lEndTimer;
			iSum_TuplesCount += ituples_cnt;

            //sprintf(temp, " S%i: [%.2f, %.2f]x[%.2f, %.2f]: tuples_num = %ld ",i, T[i].a[1], T[i].b[1], T[i].a[2], T[i].b[2], ituples_cnt );
            sprintf(temp, " scr_CLS%02i: [%.2f, %.2f]x[%.2f, %.2f], .v =%.2f : tuples_num = %ld ",i, scr_CLS[i].a[1], scr_CLS[i].b[1], scr_CLS[i].a[2], scr_CLS[i].b[2], scr_CLS[i].v, ituples_cnt );
			cstrMarc += temp;
            sprintf(temp, " GetTickCount = %ld", lEndTimer);
			cstrMarc += temp;
			cstrMarc += "\r\n";
	  }
	}


	    sprintf(temp, "       Sum of Tick Count = %ld", iSum_TickCount);
		cstrMarc += temp;
		cstrMarc += "\r\n";

		sprintf(temp, "       Sum of Tuples Count = %ld", iSum_TuplesCount);
		cstrMarc += temp;
		cstrMarc += "\r\n";
		cstrMarc += "\r\n";


/////////////////////////// 8888888888888888888 ///////////////////////////

// 3.9 ------------------- 2nd Clustering for obtained scr's  -----------------------
   	
//   scr_CLS[i].v <= 4 * Sum_v_S[i] 

lALL_StartTimer = GetTickCount();	
	


	for(i = 1; i<=clsNum; i++)
	{
		scr_CLS[i].bsn = 1; // means has elements S[i]
	}

	for(i = 1; i<=clsNum; i++) 
	{
		if(scr_CLS[i].v <= 4*Sum_v_S[i]  ) // CETA = 3, 4, 5,10 5*Sum_v_S[i] //10*Sum_v_S[i]
		{

			sprintf(temp, " scr_CLS[%02i].v = %.02f <<<=== 3*Sum_v_S[%02i] =%.02f;  ",i,scr_CLS[i].v, i, Sum_v_S[i] );
			cstrMarc += temp;
			cstrMarc += "\r\n";
			sprintf(temp, "						scr_CLS[%02i].v/Sum_v_S[%02i]= %.02f   ",i,i, scr_CLS[i].v/Sum_v_S[i] );
			cstrMarc += temp;
			cstrMarc += "\r\n";
			cstrMarc += "\r\n";

		}
		else // that is: scr_CLS[i].v/Sum_v_S[i]  > 4 //5        //10
		{
            k=0;
			for(j=1; j<=old_m; j++)
			{
				if(S[j].cn == i)
				{
					S[j].cn =0;
					k++;
				}
				//idx[k]=j;
				//k++;
				//scr_CLS[i].bsn = 0; 
			}

			scr_CLS[i].bsn = 0; 
			scr_CLS[i].cn =k;


			sprintf(temp, " scr_CLS[%02i].v = %.02f >>>>>> 4*Sum_v_S[%02i] =%.02f ",i,scr_CLS[i].v, i, Sum_v_S[i] );
			cstrMarc += temp;
			cstrMarc += "\r\n";
			sprintf(temp, "						scr_CLS[%02i].v/Sum_v_S[%02i]= %.02f   ",i,i, scr_CLS[i].v/Sum_v_S[i] );
			cstrMarc += temp;
			cstrMarc += "\r\n";
			cstrMarc += "\r\n";
		}
	}

	//clustering again if one is the subset of another, then togather them 
////// ~~~~~~~~ Finding all scr_CLS[i]'s that center are in part[i].
   //3.9.1 for  scr_CLS[i].bsn =1
   //3.9.2 for S[i]'s whicn .cn =0

	rmvable =false;
	for(i=1; i<=clsNum; i++)
	{
		if(scr_CLS[i].bsn ==1)
		{
			for(j=1; j<=clsNum; j++)
			{
				if( (i != j) && scr_CLS[j].bsn ==1 )
				{
					for(k=1; k<=n; k++) //n is the number of dimensions 
					{
						
						center = (double)(scr_CLS[j].a[k] + scr_CLS[j].b[k])/2.0;
						//if the Center of scr_CLS[j] is in scr_CLS[i]
						if( (scr_CLS[i].a[k]<=center) && (center<= scr_CLS[i].b[k]) ) //the Center in the part[i]
						{
							bInterable = true;
						} //
						else // 
						{
							bInterable = false;
							break;   //break k,   
						}
					}//for(k=1; k<=n; k++)


				}//for(k=1; k<=n; k++)
				if(rmvable) //there is a k such that scr_CLS[i] is in scr_CLS[k] 
				{
						//-------test 2---
							sprintf(temp, " Center of scr_CLS[%ld] IN scr_CLS[%i]: [%.2f, %.2f]x[%.2f, %.2f]: ", j, i, scr_CLS[j].a[1], scr_CLS[j].b[1], scr_CLS[j].a[2], scr_CLS[j].b[2] );
							cstrMarc += temp;
							cstrMarc += "\r\n";

						//-------test 2---
					scr_CLS[j].bsn = 0; // the center of scr_CLS[j] is in scr_CLS[i], IMPORTANT
					for(l=1; l<=old_m; l++)
					{
						if(S[l].cn ==j)
							S[l].cn=i;
					}

					break;  // break k and then for next i
				}


			}//for(j=1; j<=clsNum; j++)
		}//if(scr_CLS[i].bsn ==1)
	}//(i=1; i<=clsNum; i++)


   //3.9.2 for S[i]'s whicn .cn =0


	for(i=1; i<=clsNum; i++)
	{
		if(scr_CLS[i].bsn ==1)
		{
			for(k=1; k<=old_m; k++)
			{
				
				if(S[k].cn ==0 )
				{
					for(j=1; j<=n; j++)
					{
						 // if S[k] is the subset of scr_CLS[i], 
						if( (scr_CLS[i].a[j]<=S[k].a[j]) && (S[k].b[j]<=scr_CLS[i].b[j] ))
						{
							rmvable = true;
						}
						else
						{
							rmvable = false;
							break; //break j, for next k
						}
					} //for(j= 1; j <=n; j++)
				
				
					if(rmvable) //there is a k such that scr_CLS[i] is in scr_CLS[k] 
					{
							//-------test 2---
								sprintf(temp, " scr_CLS[%ld] cover, REMOVE S[%i]= [%.2f, %.2f]x[%.2f, %.2f]: ", i, k, S[k].a[1], S[k].b[1], S[k].a[2], S[k].b[2] );
								cstrMarc += temp;
								cstrMarc += "\r\n";

							//-------test 2---

								S[k].cn = i;						

						break;  // break k and then for next i
					}
				}
			}
		}
	}

	
lALL_EndTimer = GetTickCount()-lALL_StartTimer;
iALL_TickCount += lALL_EndTimer;



// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!! for a scr_CLS[i] : if scr_CLS[i].bsn ==0, that is, if scr_CLS[%02i].v/Sum_v_S[%02i] > 5
// !!!!! and it contain >8 S[i]'s then part it 12 parts.
	 cstrMarc += "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
	 cstrMarc += "\r\n";

///////////////////////// 9999999999999999999 /////////////////////////////
// 3.10 ------------------- obtain 2nd SCR's according to the  New Clusters of S[] -----------------------
//15 <=	Age <= 90	
//-25897 <= income <=	347998
	cstrMarc += "\r\n";
	cstrMarc += "\r\n";


lALL_StartTimer = GetTickCount();	
	

	iSum_TickCount = 0;
	iSum_TuplesCount =0;

	//double * Sum_v_S = new double [clsNum +1];
	//ZLRECT * scr_CLS = new ZLRECT[clsNum +1];  
	
	for(i=1; i<=clsNum; i++)
	{
		scr_CLS[i].v = 1.0;
		
		Sum_v_S[i] = 0.0;
		for(k=1; k<=old_m; k++) //old_m ==100
		{
			if(S[k].cn ==i)
			{
				Sum_v_S[i] += S[k].v;
			}

		}

	}

	for(i=1; i<=clsNum; i++ )
	{
			scr_CLS[i].a[1] = 90;
			scr_CLS[i].b[1] = 15;
			scr_CLS[i].a[2] = 347998;
			scr_CLS[i].b[2] = -25897;

		for(j=1; j<=n; j++)
		{
			for(k=1; k<=old_m; k++) // old_m ==100
			{
				if(S[k].cn ==i)
				{
					scr_CLS[i].a[j] = min(scr_CLS[i].a[j], S[k].a[j]);
					scr_CLS[i].b[j] = max(scr_CLS[i].b[j], S[k].b[j]);

				}

			}
			//scr_CLS[i].v *= (scr_CLS[i].b[j]-scr_CLS[i].a[j]) ;
		}

		for(j=1; j<=n; j++)
		{
			scr_CLS[i].v *= (scr_CLS[i].b[j]-scr_CLS[i].a[j]) ;
		}
		scr_CLS[i].bsn = 0; //2005.04.15

	}

 int allNonzero =0;
 nonzearo = 0;

	cstrMarc += "\r\n";
	for(i = 1; i<=clsNum; i++) // there are clsNum scr's of cluster scr_CLS[1] to scr_CLS[clsNum]
	{
			nonzearo = 0;
			sprintf(temp, " .bsn = %i, scr_CLS%02i: [%.2f, %.2f]x[%.2f, %.2f], .v =%.2f : ",scr_CLS[i].bsn, i, scr_CLS[i].a[1], scr_CLS[i].b[1], scr_CLS[i].a[2], scr_CLS[i].b[2], scr_CLS[i].v );
			cstrMarc += temp;	
	        cstrMarc += "\r\n";

			cstrMarc += "    Cover: ";

			for(j=1; j<=old_m; j++)
			{
				if(S[j].cn ==i)
				{
					sprintf(temp, " ,S[%02i] ", j );
					cstrMarc += temp;
					nonzearo ++;
				}
			}
	        cstrMarc += "\r\n";

       allNonzero += nonzearo;

      if(nonzearo !=0)
	  {
		  scr_CLS[i].bsn = 1;
		/***************
		strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ( ( ");
		
			sprintf(temp, " %.2f ", scr_CLS[i].a[1] );
			strcat(	szSql, temp	);
			strcat(	szSql, "<= age AND age <=");
			sprintf(temp, " %.2f ", scr_CLS[i].b[1] );
			strcat(	szSql, temp	);

			strcat(	szSql, ") AND (" );

			sprintf(temp, " %.2f ", scr_CLS[i].a[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, 	"<= Income AND Income <=");
			sprintf(temp, " %.2f ", scr_CLS[i].b[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, ") ) "	);

			lStartTimer = GetTickCount();
				ituples_cnt = zlExeSelect(TableName, szSql);
		    lEndTimer = GetTickCount() - lStartTimer ;
			
			iSum_TickCount += lEndTimer;
			iSum_TuplesCount += ituples_cnt;

            //sprintf(temp, " S%i: [%.2f, %.2f]x[%.2f, %.2f]: tuples_num = %ld ",i, T[i].a[1], T[i].b[1], T[i].a[2], T[i].b[2], ituples_cnt );
            sprintf(temp, "		tuples_num = %ld ", ituples_cnt );
			cstrMarc += temp;
			cstrMarc += "\r\n";

            sprintf(temp, "		GetTickCount = %ld", lEndTimer);
			cstrMarc += temp;
			cstrMarc += "\r\n";
			cstrMarc += "\r\n";
			**************/
	  }

	}
	// SUB SET
	//  if scr_CLS[i] is the subset of scr_CLS[k], label it and remove it
	for(i=1; i<=clsNum; i++)
	{
	  if(scr_CLS[i].bsn ==1)
	  {

		for(k=1; k<=clsNum; k++)
		{
		   if( (i != k) && scr_CLS[k].bsn ==1 )
		   {
				for(j=1; j<=n; j++)
				{
					 // if scr_CLS[i] is the subset of scr_CLS[k], 
					//if( (scr_CLS[k].a[j]<=scr_CLS[i].a[j]) && (scr_CLS[i].b[j]<=scr_CLS[k].b[j] ))
					//if the center of scr_CLS[i] is in scr_CLS[k],
					
					if( (scr_CLS[k].a[j]<=scr_CLS[i].a[j]) && (scr_CLS[i].b[j]<=scr_CLS[k].b[j] ))		
					{
						rmvable = true;
					}
					else
					{
						rmvable = false;
						break; //break j, for next k
					}
				} //for(j= 1; j <=n; j++)
				
				if(rmvable) //there is a k such that scr_CLS[i] is in scr_CLS[k] 
				{
						//-------test 2---
							sprintf(temp, " scr_CLS[%ld] cover, REMOVE scr_CLS[%i]: [%.2f, %.2f]x[%.2f, %.2f]: ", k, i, scr_CLS[i].a[1], scr_CLS[i].b[1], scr_CLS[i].a[2], scr_CLS[i].b[2] );
							cstrMarc += temp;
							cstrMarc += "\r\n";

						//-------test 2---
					scr_CLS[i].bsn = 0; // s[i] is in s[k], IMPORTANT
					for(l=1; l<=old_m; l++)
					{
						if(S[l].cn ==i)
							S[l].cn=k;
					}

					break;  // break k and then for next i
				}

		   } //if(i != k)

		}//for(k=1; i<=m; k++)
	  }

	}//for(i=1; i<=m; i++)

	


	int iMinTupleNum = 0;
	int iStart =0;
	int iAllTuplesNum =0;
	int iInterIdx =0;

	for(i = 1; i<=clsNum; i++) // there are clsNum scr's of cluster scr_CLS[1] to scr_CLS[clsNum]
	{
		if(scr_CLS[i].bsn ==1)
		{
			strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ( ( ");
		
			sprintf(temp, " %.2f ", scr_CLS[i].a[1] );
			strcat(	szSql, temp	);
			strcat(	szSql, "<= age AND age <=");
			sprintf(temp, " %.2f ", scr_CLS[i].b[1] );
			strcat(	szSql, temp	);

			strcat(	szSql, ") AND (" );

			sprintf(temp, " %.2f ", scr_CLS[i].a[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, 	"<= Income AND Income <=");
			sprintf(temp, " %.2f ", scr_CLS[i].b[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, ") ) "	);

			lStartTimer = GetTickCount();
				ituples_cnt = zlExeSelect(TableName, szSql);
		    lEndTimer = GetTickCount() - lStartTimer ;
			
			iSum_TickCount += lEndTimer;
			iSum_TuplesCount += ituples_cnt;

			sprintf(temp, " scr_CLS[%02i]: [%.2f, %.2f]x[%.2f, %.2f], .v =%.2f : ",i, scr_CLS[i].a[1], scr_CLS[i].b[1], scr_CLS[i].a[2], scr_CLS[i].b[2], scr_CLS[i].v );
			cstrMarc += temp;	
	        cstrMarc += "\r\n";
            sprintf(temp, "		tuples_num = %ld ", ituples_cnt );
			cstrMarc += temp;
			cstrMarc += "\r\n";

            sprintf(temp, "		GetTickCount = %ld", lEndTimer);
			cstrMarc += temp;
			cstrMarc += "\r\n";
			cstrMarc += "\r\n";

			iMinTupleNum = ituples_cnt;
			iStart = i;
			scr_CLS[i].cn = ituples_cnt;
			iSum_TuplesCount += ituples_cnt;
			break;
		}

	}

	for(i = iStart+1; i<=clsNum; i++) // 
	{
		if(scr_CLS[i].bsn ==1 && i > iStart)
		{
			iInterIdx = 0;
			bInterable =false;

			 for(j = iStart; j<i; j++)   // when i=5, j = 1,2,3,4 if iStart =1
			 {
				//////////////
				if(scr_CLS[j].bsn ==1 )
				{

					for(k=1; k<=n; k++) //n is the number of dimensions 
					{
						p = __max(scr_CLS[i].a[k], scr_CLS[j].a[k]); // here we use "intersect"
						q = __min(scr_CLS[i].b[k], scr_CLS[j].b[k]);

						if(p<q) //the intersection is not empty
						{
							bInterable = true; //must intersect for all dimensions
						} //if(p<q)
						else //the intersection is empty or p=q
						{
							bInterable = false; // it is enough there is a dimensions
							break;   //break k, because there is i0 such that p[i0] >=q[i0]  
						}

					}//for(k=1; k<=n; k++)

					if(bInterable) //if intersectable
					{
						iMinTupleNum = __min(iMinTupleNum, scr_CLS[j].cn);
						iInterIdx = j;
						scr_CLS[i].cn = iMinTupleNum;
					}
				}
				////////////////

			 }

			if(iInterIdx ==0)   // if there is no one that is intersect with scr_CLS[i];
			{
				strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ( ( ");
				
					sprintf(temp, " %.2f ", scr_CLS[i].a[1] );
					strcat(	szSql, temp	);
					strcat(	szSql, "<= age AND age <=");
					sprintf(temp, " %.2f ", scr_CLS[i].b[1] );
					strcat(	szSql, temp	);

					strcat(	szSql, ") AND (" );

					sprintf(temp, " %.2f ", scr_CLS[i].a[2] );
					strcat(	szSql, temp	);
					strcat(	szSql, 	"<= Income AND Income <=");
					sprintf(temp, " %.2f ", scr_CLS[i].b[2] );
					strcat(	szSql, temp	);

				strcat(	szSql, ") ) "	);

					lStartTimer = GetTickCount();
						ituples_cnt = zlExeSelect(TableName, szSql);
					lEndTimer = GetTickCount() - lStartTimer ;
					
					iSum_TickCount += lEndTimer;
					iSum_TuplesCount += ituples_cnt;

					//sprintf(temp, " S%i: [%.2f, %.2f]x[%.2f, %.2f]: tuples_num = %ld ",i, T[i].a[1], T[i].b[1], T[i].a[2], T[i].b[2], ituples_cnt );
			sprintf(temp, " scr_CLS[%02i]: [%.2f, %.2f]x[%.2f, %.2f], .v =%.2f : ",i, scr_CLS[i].a[1], scr_CLS[i].b[1], scr_CLS[i].a[2], scr_CLS[i].b[2], scr_CLS[i].v );
			cstrMarc += temp;	
	        cstrMarc += "\r\n";
				
					sprintf(temp, "		tuples_num = %ld ", ituples_cnt );
					cstrMarc += temp;
					cstrMarc += "\r\n";

					sprintf(temp, "		GetTickCount = %ld", lEndTimer);
					cstrMarc += temp;
					cstrMarc += "\r\n";
					cstrMarc += "\r\n";

			}
			else  // if there is someone that is intersect with scr_CLS[i];
			{

////////////////////////////////////////////////
				strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ( ( ");
				
					sprintf(temp, " %.2f ", scr_CLS[i].a[1] );
					strcat(	szSql, temp	);
					strcat(	szSql, "<= age AND age <=");
					sprintf(temp, " %.2f ", scr_CLS[i].b[1] );
					strcat(	szSql, temp	);

					strcat(	szSql, ") AND (" );

					sprintf(temp, " %.2f ", scr_CLS[i].a[2] );
					strcat(	szSql, temp	);
					strcat(	szSql, 	"<= Income AND Income <=");
					sprintf(temp, " %.2f ", scr_CLS[i].b[2] );
					strcat(	szSql, temp	);

				strcat(	szSql, ") ) "	);

					lStartTimer = GetTickCount();
						ituples_cnt = zlExeSelect(TableName, szSql);
					lEndTimer = GetTickCount() - lStartTimer ;
					
					//iSum_TickCount += lEndTimer;
					//iSum_TuplesCount += ituples_cnt;
					//SSSSSSSSS = scr_CLS[i] is the minuend set
					sprintf(temp, " SSSSSSSSS-T de scr_CLS[%i]: [%.2f, %.2f]x[%.2f, %.2f]: tuples_num = %ld ",i, scr_CLS[i].a[1], scr_CLS[i].b[1], scr_CLS[i].a[2], scr_CLS[i].b[2], ituples_cnt );
					
					//sprintf(temp, "		tuples_num = %ld ", ituples_cnt );
					cstrMarc += temp;
					cstrMarc += "\r\n";

					sprintf(temp, "		GetTickCount = %ld", lEndTimer);
					cstrMarc += temp;
					cstrMarc += "\r\n";
					cstrMarc += szSql;
					cstrMarc += "\r\n";

					cstrMarc += "\r\n";
//--------------------------------------------------

				strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ( ( ");
				
					sprintf(temp, " %.2f ", scr_CLS[iInterIdx].a[1] );
					strcat(	szSql, temp	);
					strcat(	szSql, "<= age AND age <=");
					sprintf(temp, " %.2f ", scr_CLS[iInterIdx].b[1] );
					strcat(	szSql, temp	);

					strcat(	szSql, ") AND (" );

					sprintf(temp, " %.2f ", scr_CLS[iInterIdx].a[2] );
					strcat(	szSql, temp	);
					strcat(	szSql, 	"<= Income AND Income <=");
					sprintf(temp, " %.2f ", scr_CLS[iInterIdx].b[2] );
					strcat(	szSql, temp	);

				strcat(	szSql, ") ) "	);

					lStartTimer = GetTickCount();
						ituples_cnt = zlExeSelect(TableName, szSql);
					lEndTimer = GetTickCount() - lStartTimer ;
					
					//iSum_TickCount += lEndTimer;
					//iSum_TuplesCount += ituples_cnt;
					//TTTTTT is the subtrahend set
					sprintf(temp, "S - TTTTTT de scr_CLS[%i]: [%.2f, %.2f]x[%.2f, %.2f]: tuples_num = %ld ",iInterIdx, scr_CLS[iInterIdx].a[1], scr_CLS[iInterIdx].b[1], scr_CLS[iInterIdx].a[2], scr_CLS[iInterIdx].b[2], ituples_cnt );
					//sprintf(temp, "		tuples_num = %ld ", ituples_cnt );
					cstrMarc += temp;
					cstrMarc += "\r\n";

					sprintf(temp, "		GetTickCount = %ld", lEndTimer);
					cstrMarc += temp;
					cstrMarc += "\r\n";

					cstrMarc += szSql;
					cstrMarc += "\r\n";

					cstrMarc += "\r\n";





///////////////////////////////////////////////

				CLearnIing6App * pApp = (CLearnIing6App * ) AfxGetApp();
				int issNum = pApp->zlDiffRects(scr_CLS[i], scr_CLS[iInterIdx], 2);
				
				//````````````````````````
				//(a) Use between ¡­ and ¡­ 
				//	SELECT * FROM CLMB_census2D Where
				//	((Age between 15 and 85) AND (Income between 3000 and 113070))
				//	OR 		
				//	( (Age between 20 and 90) AND (Income between 2995 and 113065) ) 
 


				strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ");

				for(l = 1; l<=issNum; l++)
				{
					strcat(	szSql, 	" ( ( ");

						sprintf(temp, " Age between %f and %f", pApp->ss[l].a[1], pApp->ss[l].b[1]);
						strcat(	szSql, temp	);

						strcat(	szSql, ") AND (" );

						sprintf(temp, " Income between %f and %f", pApp->ss[l].a[2], pApp->ss[l].b[2]);
						strcat(	szSql, temp	);

					strcat(	szSql, ") ) "	);

					if(l<issNum)
						strcat(	szSql, " OR " );
				}

				AfxMessageBox(szSql);

				lStartTimer = GetTickCount();
					ituples_cnt = zlExeSelect(TableName, szSql);
				lEndTimer = GetTickCount() - lStartTimer ;
				
				iSum_TickCount += lEndTimer;
				iSum_TuplesCount += ituples_cnt;
			    scr_CLS[i].cn += ituples_cnt;


				sprintf(temp, " \r\n		The pApp->ss¡¡spend TickCount = %ld", lEndTimer);
				cstrMarc += temp;
				cstrMarc += "\r\n";
				sprintf(temp, " \r\n		The pApp->ss¡¡Tuples Number = %ld", ituples_cnt);				
				cstrMarc += temp;
				cstrMarc += "\r\n";
				cstrMarc += szSql;
				cstrMarc += "\r\n";

				cstrMarc += "-----------------------------\r\n";
				cstrMarc += "\r\n";


				//````````````````````````


			}


		}

	}




	int izero = 0;
	      	cstrMarc += "\r\n";	
			cstrMarc += "cluster0 : ";	

			for(j=1; j<=old_m; j++)
			{
				if(S[j].cn ==0)
				{
					sprintf(temp, " ,S[%02i] ", j );
					cstrMarc += temp;
					izero ++;
				}

			}
			cstrMarc += "\r\n";	
			cstrMarc += "\r\n";




	if(izero >0 )
	{
		for(i = 1; i<=old_m; i++) // there are m the originial rectangles S[1] to S[100]
		{

		        if(S[i].cn ==0)
				{
					strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ( ( ");
					
						sprintf(temp, " %.2f ", S[i].a[1] );
						strcat(	szSql, temp	);
						strcat(	szSql, "<= age AND age <=");
						sprintf(temp, " %.2f ", S[i].b[1] );
						strcat(	szSql, temp	);

						strcat(	szSql, ") AND (" );

						sprintf(temp, " %.2f ", S[i].a[2] );
						strcat(	szSql, temp	);
						strcat(	szSql, 	"<= Income AND Income <=");
						sprintf(temp, " %.2f ", S[i].b[2] );
						strcat(	szSql, temp	);
						strcat(	szSql, ") ) "	);

						lStartTimer = GetTickCount();
							ituples_cnt = zlExeSelect(TableName, szSql);
						lEndTimer = GetTickCount() - lStartTimer ;
						
						iSum_TickCount += lEndTimer;
						iSum_TuplesCount += ituples_cnt;

						//sprintf(temp, " S%i: [%.2f, %.2f]x[%.2f, %.2f]: tuples_num = %ld ",i, T[i].a[1], T[i].b[1], T[i].a[2], T[i].b[2], ituples_cnt );
						sprintf(temp, " S%i: [%.2f, %.2f]x[%.2f, %.2f]: \r\n tuples_num = %ld ",i, S[i].a[1], S[i].b[1], S[i].a[2], S[i].b[2], ituples_cnt );
						cstrMarc += temp;
						sprintf(temp, " GetTickCount = %ld", lEndTimer);
						cstrMarc += temp;
						cstrMarc += "\r\n";
				}
			}

	   }

	    sprintf(temp, "       Sum of Tick Count = %ld", iSum_TickCount);
		cstrMarc += temp;
		cstrMarc += "\r\n";

		sprintf(temp, "       Sum of Tuples Count = %ld", iSum_TuplesCount);
		cstrMarc += temp;
		cstrMarc += "\r\n";

		sprintf(temp, "       nonzero = %i, zero = %i", allNonzero , izero);
		cstrMarc += temp;
		cstrMarc += "\r\n";

	
lALL_EndTimer = GetTickCount()-lALL_StartTimer;
iALL_TickCount += lALL_EndTimer;

		sprintf(temp, "      iALL_TickCount = %i ,  ", iALL_TickCount );
		cstrMarc += temp;
		cstrMarc += "\r\n";

		sprintf(temp, "      iALL_TickCount - iSum_TickCount = %i ,  ", iALL_TickCount-iSum_TickCount );
		cstrMarc += temp;
		cstrMarc += "\r\n";




//---------------   the algorithms --------------------
//---------------^^^^^^^^^^^^^^^^^^^^^^^^^^------------
////////////////////////////////////////////////////////////////////////
	
		
//	CFile file;

	//if(file.Open("E:\\Paper2\\CLMB_census2D\\cluster_100_cen2D_OPT416.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
	if(file.Open("E:\\Paper2\\CLMB_census2D\\cluster_100_cen2D_416.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
	{
		file.Write(cstrMarc, cstrMarc.GetLength() +1 );
	}
	file.Close();

		
	AfxMessageBox("OnViewCluster100 OK!");
	zlCloseDB();





	delete [] Sum_v_S;

	for(i=1; i<=clsNum; i++)
	{
		//delete [] scr_CLS[i].a;
		//delete [] scr_CLS[i].b;
	}

	delete [] scr_CLS;

	for(i=1; i<=12; i++)
	{
		//delete [] part[i].a;
		//delete [] part[i].b;
	}

	m = old_m;
	for(i=1; i<=m; i++)
	{
		//delete [] T[i].a ;
		//delete [] T[i].b ;
	}

	// delete m initial rectagles randomly from [15, 90]x[0, 350000]
	for(i=1; i<=m; i++)
	{
		//delete [] S[i].a ;
		//delete [] S[i].b ;
	}

	//delete [] scr.a ;
	//delete [] scr.b ;	
}


void CMainFrame::OnLsi104DBWorkLoad() 
{
	//2005.4.18 @
	//Menu: Multiple --> Lsi_104DBWorkLoad
	//create workload for all data sets 
    // change: 
		//1. #define COL_NUM 
	    //2. pApp, initInstance
        //3. int iSizeSmpl = 100;
	//change each time:
		//4. strcpy(szSQL, " SELECT * FROM Lsi_104D WHERE Lsi104DID = ");
        //5. sprintf(tmp, "%ld", (iRandom*10 + iRandom%10 )%20000 +1 );
        //6. CStrInsert += " INSERT Lsi_104D_B_WorkLoad_3 VALUES( ";


	int i,j,iErr = 0;
	char tmp[100] = "";
	CString CStrInsert = ""; 
	
	double  fCol[COL_NUM+1];		//Elevation
	SDWORD cbCol[COL_NUM+1]; 

	int   iColID;	
	SDWORD cbColID; 
	char c[COL_NUM+1][100];
	int iTotalNum = 0;
	char szSQL[20480] = "" ;
	//int iSizeSmpl = 5810; //250; // 200;//400; //800; //1000; //2000; 
						 ////||||100, 200, 400, 800, 1000,2000. 
						  // size of census2Dg = 145,917; CLMB_census = 210,138.
						  // Date 2003.3.24

	//for Samples of Profile
	//int iSizeSmpl = 909; //954; //833; //909; //954; //20000 * 5% * 104/(104+5)
	//int iSizeSmpl = 910; //867; //701;  //--- 22784 * 5% * n/(n+5) for house n = 8,16, 20; m= 701, 867,911(910)
	//int iSizeSmpl = 218;   // for 3D
	//int iSizeSmpl = 178;   // for 2D 

	// for workload
	int iSizeSmpl = 100; 

	//int iSizeSmpl = 80; //20; // for workload
	//int iSizeSmpl = 50; // 50; // for workload
	//int iSizeSmpl = 20; //80; // for workload

	//seed of random
	srand( (unsigned)time( NULL ) );
	int iRowCount=0;	
	int iRandom = rand();

		if(!zlOpenDB())
		{
			AfxMessageBox("zlOpenDB() err!");
			zlCloseDB();
		}else
		{
			//1111111111111 read data base 111111111111111

			do
			{
				iRowCount=0;	
				iRandom = rand(); 
				//The constant RAND_MAX is the maximum value 
				//that can be returned by the rand function. 
				//RAND_MAX is defined as the value 0x7fff =(32767)del.

			    //strcpy(szSQL, " SELECT * FROM Lsi_104D WHERE Lsi104DID = ");
			    //strcpy(szSQL, " SELECT * FROM Lsi_050D WHERE Lsi050DID = ");
			    //strcpy(szSQL, " SELECT * FROM Lsi_025D WHERE Lsi025DID = ");

			    //strcpy(szSQL, " SELECT * FROM Attr_Cover4D WHERE Cover4DID = ");
			    //strcpy(szSQL, " SELECT * FROM Attr_Gauss3D WHERE Gauss3DID = ");
			    //strcpy(szSQL, " SELECT * FROM Attr_Array3D WHERE Array3DID = ");
			    //strcpy(szSQL, " SELECT * FROM Attr_Census3D WHERE Census3DID = ");
			    //strcpy(szSQL, " SELECT * FROM Attr_Census2D WHERE Census2DID = ");
				
                // Lsi
				//sprintf(tmp, "%ld", (iRandom*10 + iRandom%10 )%20000 +1 );
				// Cover
				//sprintf(tmp, "%ld", (iRandom*20 +iRandom + iRandom%10 )%581010 +1 );
				// Gauss
				//sprintf(tmp, "%ld", (iRandom*20 +iRandom + iRandom%10 )%500000 +1 );
				// Array				
				//sprintf(tmp, "%ld", (iRandom*20 +iRandom + iRandom%10 )%507701 +1 );			
				// Census
				sprintf(tmp, "%ld", (iRandom*10 +iRandom + iRandom%10 )%210138 +1 );
				
				strcat(szSQL, tmp);
				
				SQLFreeStmt(hstmt, SQL_DROP);
				retcode = SQLAllocStmt(hdbc, &hstmt); ///Statement handle 
				if(retcode != SQL_SUCCESS)
					AfxMessageBox("retcode != SQL_SUCCESS"); //return -1;

				SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
				SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
				
				retcode = SQLExecDirect(hstmt, (unsigned char *)szSQL, SQL_NTS);  //2005.02.07
				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO ) 
				{    //	retcode = SQLExecDirect
					SDWORD *  RowCountPtr = new SDWORD ;
					retcode = SQLRowCount(hstmt, RowCountPtr);						 
					iRowCount = * RowCountPtr;
					delete RowCountPtr;
					
					// Bind columns 1,2.
					//SQLBindCol(hstmt, 1, SQL_C_SSHORT, &sAge, 0, &cbAge);
					//SQLBindCol(hstmt, 2, SQL_C_SLONG, &sIncome,0, &cbIncome); //SQL_C_SSHORT
					
					for(i = 0; i <COL_NUM; i++)
						SQLBindCol(hstmt, i+1, SQL_C_DOUBLE, &fCol[i],0, &cbCol[i]); //SQL_C_SSHORT
				
					SQLBindCol(hstmt, COL_NUM+1, SQL_C_SLONG, &iColID,0, &cbColID); //SQL_C_SSHORT


					retcode = SQLFetch(hstmt);
					
					if(iRowCount ==1 && (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) )
					{
						for(i=0; i<COL_NUM+1;i++)
							for(j=0;j<100;j++)
								c[i][j] = 0;

						for(i=0; i< COL_NUM;i++)
								sprintf(c[i],"%G",fCol[i]);

						sprintf(c[COL_NUM],"%ld",iColID);

						CStrInsert = "";
						//CStrInsert += " INSERT Lsi_104D_smpl954 VALUES( ";
						//CStrInsert += " INSERT Lsi_104D_B_WorkLoad VALUES( ";
						//CStrInsert += " INSERT Lsi_104D_B_WorkLoad_1 VALUES( ";
						//CStrInsert += " INSERT Lsi_104D_B_WorkLoad_2 VALUES( ";
						//CStrInsert += " INSERT Lsi_104D_B_WorkLoad_3 VALUES( ";
						//CStrInsert += " INSERT Lsi_104D_B_WorkLoad_4 VALUES( ";
						//CStrInsert += " INSERT Lsi_104D_B_WorkLoad_5 VALUES( ";						
						
						//CStrInsert += " INSERT Lsi_050D_smpl909  VALUES( ";
						//CStrInsert += " INSERT Lsi_050D_B_WorkLoad  VALUES( ";
						//CStrInsert += " INSERT Lsi_050D_B_WorkLoad_2  VALUES( ";
						//CStrInsert += " INSERT Lsi_050D_B_WorkLoad_3  VALUES( ";
						//CStrInsert += " INSERT Lsi_050D_B_WorkLoad_4  VALUES( ";
						//CStrInsert += " INSERT Lsi_050D_B_WorkLoad_5  VALUES( ";
						
						//CStrInsert += " INSERT Lsi_025D_B_WorkLoad VALUES( ";
						//CStrInsert += " INSERT Lsi_025D_B_WorkLoad_1 VALUES( ";
						//CStrInsert += " INSERT Lsi_025D_B_WorkLoad_2 VALUES( ";
						//CStrInsert += " INSERT Lsi_025D_B_WorkLoad_3 VALUES( ";
						//CStrInsert += " INSERT Lsi_025D_B_WorkLoad_4 VALUES( ";
						//CStrInsert += " INSERT Lsi_025D_B_WorkLoad_5 VALUES( ";
				
						//CStrInsert += " INSERT Cover4D_B_workload VALUES( ";
						//CStrInsert += " INSERT Cover4D_B_workload_1 VALUES( ";
						//CStrInsert += " INSERT Cover4D_B_workload_2 VALUES( ";
						//CStrInsert += " INSERT Cover4D_B_workload_3 VALUES( ";
						//CStrInsert += " INSERT Cover4D_B_workload_4 VALUES( ";
						//CStrInsert += " INSERT Cover4D_B_workload_5 VALUES( ";

						//CStrInsert += " INSERT Gauss3D_smpl0218 VALUES( ";
						//CStrInsert += " INSERT Gauss3D_B_WorkLoad VALUES( ";
						//CStrInsert += " INSERT Gauss3D_B_WorkLoad_1 VALUES( ";
						//CStrInsert += " INSERT Gauss3D_B_WorkLoad_2 VALUES( ";
						//CStrInsert += " INSERT Gauss3D_B_WorkLoad_3 VALUES( ";
						//CStrInsert += " INSERT Gauss3D_B_WorkLoad_4 VALUES( ";
						//CStrInsert += " INSERT Gauss3D_B_WorkLoad_5 VALUES( ";

						//CStrInsert += " INSERT Array3D_smpl0218 VALUES( ";
						//CStrInsert += " INSERT Array3D_B_WorkLoad VALUES( ";
						//CStrInsert += " INSERT Array3D_B_WorkLoad_1 VALUES( ";
						//CStrInsert += " INSERT Array3D_B_WorkLoad_2 VALUES( ";
						//CStrInsert += " INSERT Array3D_B_WorkLoad_3 VALUES( ";
						//CStrInsert += " INSERT Array3D_B_WorkLoad_4 VALUES( ";
						//CStrInsert += " INSERT Array3D_B_WorkLoad_5 VALUES( ";

						//CStrInsert += " INSERT Census3D_smpl0218 VALUES( ";
						//CStrInsert += " INSERT Census3D_B_WorkLoad VALUES( ";
						//CStrInsert += " INSERT Census3D_B_WorkLoad_1 VALUES( ";
						//CStrInsert += " INSERT Census3D_B_WorkLoad_2 VALUES( ";
						//CStrInsert += " INSERT Census3D_B_WorkLoad_3 VALUES( ";
						//CStrInsert += " INSERT Census3D_B_WorkLoad_4 VALUES( ";
						//CStrInsert += " INSERT Census3D_B_WorkLoad_5 VALUES( ";

						//CStrInsert += " INSERT Census2D_smpl0178 VALUES( ";
						//CStrInsert += " INSERT Census2D_B_WorkLoad VALUES( ";
						//CStrInsert += " INSERT Census2D_B_WorkLoad_1 VALUES( ";
						//CStrInsert += " INSERT Census2D_B_WorkLoad_2 VALUES( ";
						//CStrInsert += " INSERT Census2D_B_WorkLoad_3 VALUES( ";
						//CStrInsert += " INSERT Census2D_B_WorkLoad_4 VALUES( ";
						CStrInsert += " INSERT Census2D_B_WorkLoad_5 VALUES( ";



						for(i=0; i< COL_NUM;i++)
						{
							CStrInsert += c[i];
							CStrInsert += ",";

						}							
						CStrInsert += c[COL_NUM];;
						CStrInsert += ")";

						SQLFreeStmt(hstmt, SQL_DROP);
						retcode = SQLAllocStmt(hdbc, &hstmt); ///Statement handle 
						if(retcode != SQL_SUCCESS)
							AfxMessageBox("retcode != SQL_SUCCESS 222"); //return -1;

						SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
						SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
						retcode = SQLExecDirect(hstmt, (unsigned char *)CStrInsert.GetBuffer(CStrInsert.GetLength() +1), SQL_NTS);


						if (retcode == SQL_SUCCESS) 
							iTotalNum ++;
						else
							iErr++;
					}
				
				}
				if(iTotalNum >=iSizeSmpl)
					break;	
			}while(true);

		//111111111111111111 read data base end111111111111

		}


	//SQLFreeStmt(hstmt, SQL_DROP);
	zlCloseDB();

	AfxMessageBox("Insert Lsi_smpl_Bworkload OK!");
	
}

double CMainFrame::f(double x)
{
   bool bReturn;

   CLearnIing6App * pApp = (CLearnIing6App * ) AfxGetApp();
   //pApp->c2 = x;  //threshod of I,C, C+ clustering
   pApp->CETA = x;  //threshod of I,C, C+ clustering
   
   bReturn = zlGetResults3To104D(100, pApp->szInputTableName);
     
   if(bReturn)
	   return pApp->Ratio_elapsed_time;
   else
	   return -1;
}

void CMainFrame::OnRun() 
{
	OnResults3To4D(); 
}

void CMainFrame::OnClusterNaive() 
{
	bool bReturn = false;
	//CTableName InputTableName;
    //int i;

	//int nResponse = InputTableName.DoModal();

	//if (nResponse != IDOK)
	//	return bReturn;
	//else
	{
		CLearnIing6App * pApp = (CLearnIing6App * ) AfxGetApp();

		
 // in order to get threshold 
           
		  //if( WORKLOAD_NUM >=400 && COL_NUM >=25 )
		  //if( WORKLOAD_NUM >400 && COL_NUM >=25 )
               ;//bReturn = zlGetResults3To104D_C_N_HighLarge(pApp->m, pApp->szInputTableName);		  
		   //else
               pApp->m =251;
			   bReturn = zlGetResults3To104D_C_N(pApp->m, pApp->szInputTableName);

		AfxMessageBox("OK!!!!!!!!!!!!!!!!!!");
 	}
	
}

void CMainFrame::OnResults3To4D() 
{
	bool bReturn = false;
	//CTableName InputTableName;
    //int i;

	//int nResponse = InputTableName.DoModal();

	//if (nResponse != IDOK)
		//return bReturn;
	//else
	{
		CLearnIing6App * pApp = (CLearnIing6App * ) AfxGetApp();

		
 // in order to get threshold 
		
        bReturn = zlGetResults3To104D(pApp->m, pApp->szInputTableName);
		AfxMessageBox("OK!!!!!!!!!!!!!!!!!!");
 	}
}

//-- after memory = 512m 060320 ---------start --------------
bool CMainFrame::zlGetResults3To104D(int iCountOfQueries, char *InputTablename)
{  
	//This function: first RCM (Region Clustering Method), second NM(Naive Method)
	bool bReturn =false;
       AfxMessageBox("zlGetResults3To104D is deleted !!! ");


   //// bodu end ////	


	return bReturn;
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

//this function first RCM, Second do Naive Method
bool CMainFrame::zlGetResults3To104D_C_N(int iCountOfQueries, char *InputTablename)
{//2007.02.21
	bool bReturn =false;
	//int iiias=0; //for test 
	return true;
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

int CMainFrame::zlClusterProfileRegions(int iCountOfQueries, char *InputTablename)
{   
	bool bReturn =false;
	//int iiias=0; //for test 

	//For LSI_050D 
	//1 Group: lng, and OPT
	//int m = 1; //100;//80; // 40; //20; //10; // 4; //2; //1; //80; //the number of rectangles 
	//int m = 40;//80; //100; //40; //20;//10;//4;//2;//1; //the number of rectangles 
	//0 Group: lng, and OPT
	//int m = 1; //2; //4; //10; //20; //40;//80;//100;
	//int m = 1; // 2; // 4; //10; //20; //40; //80; //100;

	//2005.07.31
	int m; //the number of rectangles 
	
	int old_m;
	int m_T;  //the number of {T[i]}

	//int m = 1; //80; //40; //1; //2; //20; //10; //100;   /////20; //10; //9;    //10;  //the number of rectangles 
	int n = COL_NUM; //2;	//104;   //the dimensions of space
	double Totall_v =0.0; // Totall_v = v(U Si )
	int i, j;
	int iTableSize =0;

	double CETA = 1; //1;  //10; // the threshold for Sum_Cluster

	int SEC = 2; //= 21; // SECTION, for the T-S, that is the algorithm 
	                     //The Difference of Two Regions (DTR), i.e., pApp->zlDiffRects
	if(n==104)
	{
		//SEC = 2; //2; //5; //9 ;
		CETA = 1; //3; //2
	}
	else if(n==50)
	{
		//SEC = 21;
		CETA =1;
	}
	else if(n==25) 
	{
		//SEC = 10; //20; //40;
		CETA =1;
	}

	else if(n == 4) 
	{
		//SEC = 10; //20; //40;
		CETA =1;
	}
	else if(n == 3) 
	{
		//SEC = 10; //20; //40;
		CETA = 1; //2;
	}
	else if(n == 2) 
	{
       CETA = 2;
	}
 
///////// SEC, CETA //////////
    SEC = 2;  // all SEC = 2

	if(n == 2)
		 CETA = 2;
	else 
         CETA = 1;
///////// SEC, CETA  //////////

	long lStartTimer = GetTickCount();
	long lEndTimer;

	long lALL_StartTimer = GetTickCount();
	long lALL_EndTimer;
	int  iALL_TickCount = 0;


    //RESULT_LEARNING RstLng[WORKLOAD_NUM +1];

    RESULT_LEARNING * RstLng = new RESULT_LEARNING[WORKLOAD_NUM +1];

	char * szSql = new char[8092000]; //6579//8092000
	strcpy(szSql, "");

	char temp[512] = "";
	//CString cstrMarc = "";
	double VFactor;
	if(n==104)
	  VFactor = 5.0 * pow(10, 37);
	else if(n==50)
	  VFactor = pow(10, 34); // (30 +38)/2=34
	else if(n==25)
	  VFactor = pow(10, 31); // (24 +38)/2=31

	CFile file;

	//Seed the random-number generator with current time
	//srand( (unsigned)time( NULL ) );	
	//int iRandom = rand()%100;

	char TableName[1024] = "";
    char InsertTableName[512] = "";


	//ZLRECT * S = new ZLRECT[m+1]; //S[m+1];
	//ZLRECT * T = new ZLRECT[m+1]; //T[m+1];
	//-- NOT use the following definition: 
	//      ZLRECT ** T = new ( ZLRECT (*[m+1]) ); //T[m+1];


////////////////////////////////////////////////////////////////////////////////////	
//----------- 1. Get m initial rectangles from DB----------------------
//---------------------------------------------------------------------
//---------------------------------------------------------------------
	// [15, 90]x[-25897, 347998]: the domain of the table CLMB_census2D
    //15 <=	Age <= 90	
    //-25897 <= income <=347998
	
	//SELECT MIN(attr0), MIN(attr1), MAX(attr0), MAX(attr1) FROM Attr_Census2D
    //15	-25897	90	347998

	double dMin[COL_NUM+1]; 
	double dMax[COL_NUM+1];

	CLearnIing6App * pApp = (CLearnIing6App * ) AfxGetApp();

	strcpy(TableName, " ");
	strcat(TableName, pApp->TableName);
	strcat(TableName, " ");

	strcpy(InsertTableName, pApp->szOutputTableName);
     
///* 2007.03.04 *
	//if( !pApp->zlStartSQLservr() )
  	      //AfxMessageBox("pApp->zlStartSQLservr() 1111 Error ");
    //else
		//pApp->zlother();
//* 2007.03.04 */

    //Defination of Model and thredhold
    int iModle= 0; // modle of Clustering,
  
	if(n<=4 )
	{
		pApp->c2 = 0.0; // threshold of clustering c1,c2,c3
		iModle = 1;
		//CETA = 2; // threshold of clustering c0, for Sum-clustering
		CETA  = 500; //3; 
		pApp->CETA  = CETA;

	}
	else if(n>=25)
	{
		pApp->c2 = 0.0; // threshold of clustering c1,c2,c3
		iModle = 2;
		//CETA = 2; // threshold of clustering c0, for Sum-clustering
		CETA  = 5;
		pApp->CETA  = CETA;

	}
    /*******************
	if(strcmp(TableName, " Attr_Census2D ")==0 )
	{
		pApp->c2 = 0.25; // threshold of clustering c1,c2,c3
		iModle = 1;
		//CETA = 2; // threshold of clustering c0, for Sum-clustering
		CETA  = 1.5;
		pApp->CETA  = CETA;

	}
	if(strcmp(TableName, " Attr_Census3D ")==0 )
	{
 		iModle = 1;
		pApp->c2 = 0.25; // threshold of clustering c1,c2,c3
		CETA = 1.5; // threshold of clustering c0, for Sum-clustering
		pApp->CETA  = CETA;
	}
	if(strcmp(TableName, " Attr_Cover4D ")==0)
	{
		pApp->c2 = 0.25; // threshold of clustering c1,c2,c3
		iModle = 1;
		CETA = 1.5; //threshold of clustering c0, for Sum-clustering
  		pApp->CETA  = CETA;
   
	}
    //else if(strcmp(TableName, " Attr_Array3D ")==0 || strcmp(TableName, " Attr_Gauss3D ")==0 || strcmp(TableName,  " Lsi_025D ")==0 || strcmp(TableName, " Lsi_050D ")==0 )
    else if( strcmp(TableName, " Attr_Gauss3D ")==0 )
	{
		 //iModle = 2;
		 iModle = 1;  // 
	     pApp->c2 = 0.5; // threshold of clustering c1,c2,c3
		 //2007.02.21/   CETA =  1.956522; //3; //2; //3;    // threshold of clustering c0, for Sum-clustering
                   // = 1.956522  CETA =  2 is better than  CETA =  1 and  CETA =  3;
		 CETA =  2; //2007.02.21
		 pApp->CETA  = CETA;

		 //1.52 means  iModle = 1;  pApp->c2 = 0.5;CETA = 2; 
         //1.3752 
		 // conclusion: iModle = 1;   pApp->c2 = 0.5;   CETA =  2; //06.03.21
    }
    else if(strcmp(TableName, " Attr_Array3D ")==0)
	{
 	     CETA = 2; // threshold of clustering c0, for Sum-clustering
						   // CETA = 2 is  GOOD to Array3D, 
	     pApp->c2 = 0.5; // threshold of clustering c1,c2,c3
		 iModle = 2; 
		 pApp->CETA  = CETA;
		 		                   
    	 //pApp->c2 = 0.1; // threshold of clustering c1,c2,c3
		 // iModle = 1;	   //Modle 1 is NOT good to Array3D. So use iModle = 2.

	}
    else if(strcmp(TableName,  " Lsi_025D ")==0 )
	{
	     pApp->c2 = 0.25; // threshold of clustering c1,c2,c3
		 iModle = 2;	
   		 CETA = 1;      // threshold of clustering c0, for Sum-clustering
	 	 pApp->CETA  = CETA;
	}
	else if( strcmp(TableName, " Lsi_050D ")==0 )
	{
	     pApp->c2 = 0.1; // threshold of clustering c1,c2,c3
		 iModle = 2;	
		 CETA = 1;    // threshold of clustering c0, for Sum-clustering
    	 pApp->CETA  = CETA;
	}
    else if( strcmp(TableName, " Lsi_104D ")==0 )
	{
	     pApp->c2 = 0.0; // threshold of clustering c1,c2,c3 for LSI_104D
		 iModle = 2;
		 CETA = 1;
   		 pApp->CETA  = CETA;
	}
	*********/
 ////////////// set parameter end /////////////////////


	for(i = 0; i <COL_NUM+1; i++)
	{
		dMin[i] = pApp->dMin[i];
		dMax[i] = pApp->dMax[i];
	}

	int iQryIdx =1;

	int longTicks =0, shortTicks =0;
	int f_rst= 0, shortTicks_rst = 0; //2003/4/5
    char tmp[512] = "";
	double  fCol[COL_NUM+1];		//Elevation
	SDWORD  cbCol[COL_NUM+1]; 

	int		sN,  sf,  sf_rst,  sshortTicks_rst,  sshortTicks,  slongTicks;
	SDWORD  cbN, cbf, cbf_rst, cbshortTicks_rst, cbshortTicks, cblongTicks;
	double	sr;	
	SDWORD  cbr;
	sf_rst = 0;  sshortTicks_rst=0;


    //----the size of all is  100 (the size of workload) 

	//UCHAR szSqlAllLearningRows[] = "SELECT * FROM Census2D_T0100_B_Learning_P0178"; //census 2dim 
	//UCHAR szSqlAllLearningRows[] = " SELECT * FROM Census2D_T0100_B_OPT "; //census 2dim 
	
	//UCHAR szSqlAllLearningRows[] = " SELECT * FROM Lsi_104D_T0020_B_Learning_P0954 "; //Lsi_104D
	//UCHAR szSqlAllLearningRows[] = " SELECT * FROM Lsi_104D_Top20_B_OPT "; //Lsi_104D
	
	//--- Lsi_050D
	//UCHAR szSqlAllLearningRows[] = " SELECT * FROM Lsi_050D_T0020_B_Learning_P0909 "; //Lsi_050D
	//UCHAR szSqlAllLearningRows[] = " SELECT * FROM Lsi_050D_Top20_B_OPT "; //Lsi_050D
	
	//UCHAR szSqlAllLearningRows[] = " SELECT * FROM Lsi_050D_Top20_B_OPT_0 "; //Lsi_050D
	//UCHAR szSqlAllLearningRows[] = " SELECT * FROM Lsi_050D_T0020_B_Learning_P0909_0 "; //Lsi_050D
    
	//2005.07.31
	char szSqlAllLearningRows[1024] = "";
	strcpy(szSqlAllLearningRows, " SELECT * FROM " );
	strcat(szSqlAllLearningRows, InputTablename);
	/*******
	if( n< 24 )
		strcat(szSqlAllLearningRows, " where (99 < f and f < 2*N) or ( 99 < f and c > 1 ) "); //for Array3D, and Gause3D "or c > 1" 
		//strcat(szSqlAllLearningRows, " where (99 < f and f < 2*N) "); //for others

	else
		strcat(szSqlAllLearningRows, " where 19 < f and f < 5*N ");
    ********/
	//------
	// only for test SELECT * FROM Lsi_050D_Top20_Profile909
	//UCHAR szSqlAllLearningRows[] = " SELECT * FROM Lsi_050D_Top20_Profile909 "; //Lsi_050D
	//------

	//if(!zlOpenDB())
	//{
		//AfxMessageBox("zlOpenDB() err!");
		//zlCloseDB();
	//}

	SQLFreeStmt(hstmt, SQL_DROP);
	retcode = SQLAllocStmt(hdbc, &hstmt); ///Statement handle 
	if(retcode != SQL_SUCCESS)
		AfxMessageBox("1. Get m initial rectangles from DB, Error!" ); //return -1;

	SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
	SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
	
	longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlAllLearningRows, SQL_NTS);
	longTicks = GetTickCount() - longTicks;

	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO ) 
	{    //	retcode = SQLExecDirect for DATA_Top100_Census2D_Profile		
		int iRowCount;
		SDWORD *  RowCountPtr = new SDWORD ;
		retcode = SQLRowCount(hstmt, RowCountPtr);						 
		iRowCount = * RowCountPtr;
		//iTupleNum = iRowCount;
		//iSizeProfile = iRowCount; // here only size of profile, 218, 436, 872, //100,200, ...,2000
		delete RowCountPtr;
		
		// Bind columns 1,2,3,4, ..., 104
		for(i = 0; i <COL_NUM+1; i++)
		{
			fCol[i] =0.0;
			cbCol[i] = 0; 
		}
		// Bind columns 1,2,3,4 ,.., COL_NUM
		for(i = 0; i <COL_NUM; i++)
			SQLBindCol(hstmt, i+1, SQL_C_DOUBLE, &fCol[i],0, &cbCol[i]); //SQL_C_SSHORT

		SQLBindCol(hstmt, COL_NUM+1, SQL_C_SLONG, &sN,0, &cbN); //SQL_C_SSHORT
		SQLBindCol(hstmt, COL_NUM+2, SQL_C_DOUBLE, &sr,0, &cbr); //SQL_C_SSHORT
		SQLBindCol(hstmt, COL_NUM+3, SQL_C_SLONG, &sf,0, &cbf); //SQL_C_SSHORT

		SQLBindCol(hstmt, COL_NUM+4, SQL_C_SLONG, &sf_rst,0, &cbf_rst); //SQL_C_SSHORT
		SQLBindCol(hstmt, COL_NUM+5, SQL_C_SLONG, &sshortTicks_rst,0, &cbshortTicks_rst); //SQL_C_SSHORT
		SQLBindCol(hstmt, COL_NUM+6, SQL_C_SLONG, &sshortTicks,0, &cbshortTicks); //SQL_C_SSHORT
		SQLBindCol(hstmt, COL_NUM+7, SQL_C_SLONG, &slongTicks,0, &cblongTicks); //SQL_C_SSHORT
		
		iRowCount =0;
		//while (TRUE) 
	    while (iQryIdx <= WORKLOAD_NUM) 
		{
			retcode = SQLFetch(hstmt);

			if (retcode == SQL_ERROR)
			{
				//show_error();
				wsprintf(tmp, "%ld", iRowCount);
				//int i = iRowCount;
				AfxMessageBox("SQLFetch Error !!!!!!");
						//break; //99.8.26
			}

			if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
			{
				
				for(i = 1; i<=COL_NUM; i++)
				{
					RstLng[iQryIdx].q[i] = fCol[i-1];
				}
				//RstLng[WORKLOAD_NUM +1];
                //iQryIdx start from 1
				RstLng[iQryIdx].N		= sN;
				RstLng[iQryIdx].r		= (float) sr;
				RstLng[iQryIdx].f		= sf;
				RstLng[iQryIdx].f_rst	= sf_rst;
				RstLng[iQryIdx].shortTicks_rst = sshortTicks_rst;
				RstLng[iQryIdx].longTicks = slongTicks;	 
				RstLng[iQryIdx].shortTicks = sshortTicks; 

				sf_rst =0;  
				sshortTicks_rst=0;

				iQryIdx++;  //start from 1

				if(retcode == SQL_SUCCESS_WITH_INFO)
				{
					wsprintf(tmp, "%ld", retcode);
					AfxMessageBox(tmp);
				}
					
			} 
			else 
			{
				break;
			}

		}   ///while (TRUE)
	}//	retcode = SQLExecDirect  for DATA_Top100_Census2D_Profile

	//zlCloseDB();

   m = iQryIdx-1;
   old_m =m;
   ZLRECT * S = new ZLRECT[m+1]; //S[m+1];
   ZLRECT * T = new ZLRECT[m+1]; //T[m+1];

   //Save the queries in pApp->Q[i]
   for(i=1; i<=WORKLOAD_NUM; i++)
   {
		pApp->Q[i] = RstLng[i];  
   }

////////////////////////////////////////////////////////////////////////////////////	

double xi = 0.0; 
     
    xi = pApp->c2; // threshold of clustering c1,c2,c3
	//CETA = pApp->CETA; //3; //2; //3;    // threshold of clustering c0, for Sum-clustering


    lStartTimer = 0;
    lEndTimer =0;

	lALL_StartTimer = 0;
	lALL_EndTimer =0;
    iALL_TickCount = 0;


////////////////////////////////////////////////////////////////////////////////////	
//////////////////////// 11111111111111111 ///////////////////////
//		Assigned the rectangles S[i] from RstLng[i]; S[i]:= RstLng[i]
//      m = 100, 80,60, 40, 20,10 ?
//---------------------------------------------------------------------
//---------------------------------------------------------------------

lALL_StartTimer = GetTickCount();
	
	for(i=1; i<=m; i++)
	{
		for(j= 1; j <=n; j++)
		{
			S[i].a[j] = RstLng[i].q[j] - RstLng[i].r ; 
			if(S[i].a[j] < dMin[j])
				S[i].a[j] = dMin[j];

			S[i].b[j] = RstLng[i].q[j] + RstLng[i].r; 
			if(S[i].b[j] >dMax[j])
				S[i].b[j] = dMax[j];
		}

		S[i].v =1;
		if(n < 25)
		{
			for(j=1; j<=n; j++)
			{
				S[i].v *= (S[i].b[j]-S[i].a[j]);
			}
		}
		else
		{
			for(j=1; j<=n; j++)
			{
				S[i].v *= ( (S[i].b[j]-S[i].a[j])/VFactor );
			}
			
		}

		sprintf(S[i].suffix, "%d", i);
		S[i].suf1st = i;
		S[i].sufend = i;
		S[i].cn =0;
		//S[i].bsn = i; //2005.4.8
		S[i].bsn = 0;   //2005.4.8

	}

lALL_EndTimer = GetTickCount()-lALL_StartTimer;
iALL_TickCount += lALL_EndTimer;

delete [] RstLng;


//calculas the volume of the table.
double V_Lsi104D =1.0;
	
if(n>24)
{
	double S_v[WORKLOAD_NUM +1];//101

	for(j=1; j<=n; j++)
	{
		V_Lsi104D *= ( (dMax[j]-dMin[j])/VFactor );
	}

	for(i=1; i<=m; i++)
	{  
		S_v[i] = S[i].v;
	}
	//sprintf(temp, " V_Lsi104D = %.15G  ", V_Lsi104D );
	//cstrMarc += temp;
	//cstrMarc += "\r\n";
	//cstrMarc += "\r\n";
}

//------test 1 start ------
/*for(i=1; i<=m; i++)
{         
	sprintf(temp, " S[%02i].v = %.15G  ", i, S[i].v );
	cstrMarc += temp;
	cstrMarc += "\r\n";
}
	cstrMarc += "\r\n";
	cstrMarc += "\r\n";
*/
//------test 1 end --------
////////////////////////////////////////////////////////////////////////////////////	

////////////////////////////////////////////////////////////////////////////////////	
/////////////////     222222222222222222222        //////////////////////////
//		2. Eliminating redundant squares temporarily
//---------------------------------------------------------------------
//---------------------------------------------------------------------
lALL_StartTimer = GetTickCount();

	bool rmvable = false;
    int  l = 1; 
	int  k;

	/**********************
	rmvable =false;
	for(i=1; i<=m; i++)
	{ 
		rmvable =false;

		for(k=1; k<=m; k++)
		{
		   // for each i, see ?? S[i] in S[k], for all k:  i!=k and S[k] is not removed
		   // this wan can avoid the situation S[i] ==S[k]. say, S[8] == S[65]
           // then in the case of S[8] == S[65], the loop of () will be dead loop

		   //if(i != k )  // 2005.4.8
		   if( k != i  && S[k].bsn == 0) // 2005.4.8 
		   {
				for(j=1; j<=n; j++)
				{
					// if S[i] is the subset of S[k], 
					if( (S[k].a[j]<=S[i].a[j]) && (S[i].b[j]<=S[k].b[j] ))
					{
						rmvable = true;
					}
					else
					{
						rmvable = false;
						break; //break j, for next k
					}
				} //for(j= 1; j <=n; j++)
				
				if(rmvable) //there is a k such that Si is in Sk 
				{
						//-------test 2---
							sprintf(temp, " S[%ld] cover, REMOVE S[%i] = [%G, %.15G]x[%G, %G]: ", k, i, S[i].a[1], S[i].b[1], S[i].a[2], S[i].b[2] );
							cstrMarc += temp;
							cstrMarc += "\r\n";

						//-------test 2---
					S[i].bsn = k; // s[i] is in s[k], i.e. S[i] is the subset of s[k]. IMPORTANT. bsn = Big Set Number
					S[i].tplNum =S[i].bsn; //2005.5.17

					break;  // break k and then for next i
				}
		   } //if(i != k)

		}//for(k=1; i<=m; k++)

		if(l==1 && i==m && rmvable)  // forget the meaning of this conditions
		{                           // i==m ?? the last one S[m] is in S[k], k !=m
			AfxMessageBox("l==1 && i==m && rmvable");
		} //2005.5.14

		//if( (rmvable == false) || (l==1 && i==m && rmvable) ) //cannot be removed //2005.5.14
		if( (rmvable == false)  ) //cannot be removed //2005.5.14
		{
			//T[l] = S[i];
			// :==: is the same as :==:
			//memset(&T[l], 0, sizeof(ZLRECT));
			//memcpy(&T[l], &S[i], sizeof(ZLRECT));
			
			for(j= 1; j <=n; j++)
			{
				T[l].a[j] = S[i].a[j];
				T[l].b[j] = S[i].b[j]; 
			}
			T[l].v=S[i].v;

			sprintf(T[l].suffix, "%d", l);
			T[l].suf1st = l;
			T[l].sufend = l;
			T[l].cn = 0;
			//T[l].bsn = l;  // 2004.4.13
			T[l].bsn = 0;    // 2004.4.13

			S[i].bsn= 10000+l; // the remainder of S[i]: S[i].bsn = l +10000; 
							   // where l is the index of T[l]. i.e. S[i] is the (sub)set of T[l]
			S[i].tplNum =S[i].bsn; //2005.5.17

			l++;
		}//if( (rmvable == false) || (l==1 && i==m && rmvable) ) //cannot be removed
	
	}//for(i=1; i<=m; i++)
	*****************/

	int S_Idx[WORKLOAD_NUM +1 ];
	for(i=1; i<=WORKLOAD_NUM; i++)
		S_Idx[i]=0;

	int min_S_Idx = 0;
	double min_S_v =0.0;

	
	for(i=1; i<=m; i++)
	{ 
      if(S[i].bsn ==0)
	  {
		rmvable =false;

		//for(j=1; j<=100; j++)
		for(j=1; j<=WORKLOAD_NUM; j++)
		  S_Idx[j]=0;

		min_S_Idx =0;

		for(k=1; k<=m; k++)
		{
		   // for each i, see ?? S[i] in S[k], for all k:  i!=k and S[k] is not removed
		   // this way can avoid the situation S[i] ==S[k]. say, S[8] == S[65]
           // then in the case of S[8] == S[65], the loop of () will be dead loop

		   //if(i != k )  // 2005.4.8
		   //if( k != i  && S[k].bsn == 0) // 2005.4.8 
		   if( k != i  && S[k].bsn != i) // 2005.5.22 //finding S[i]'s all superset S[k] that is not itself and 
		   {                                          //S[k].bsn != i
				for(j=1; j<=n; j++)
				{
					// if S[i] is the subset of S[k], 
					if( (S[k].a[j]<=S[i].a[j]) && (S[i].b[j]<=S[k].b[j] ))
					{
						rmvable = true;
					}
					else
					{
						rmvable = false;
						break; //break j, for next k
					}
				} //for(j= 1; j <=n; j++)
				
				if(rmvable) //there is a k such that Si is in Sk 
				{
						//-------test 2---
							//sprintf(temp, " S[%ld] cover, REMOVE S[%i] = [%G, %.15G]x[%G, %G]: ", k, i, S[i].a[1], S[i].b[1], S[i].a[2], S[i].b[2] );
							//cstrMarc += temp;
							//cstrMarc += "\r\n";

						//-------test 2---
					//S[i].bsn = k; // s[i] is in s[k], i.e. S[i] is the subset of s[k]. IMPORTANT. bsn = Big Set Number
					//S[i].tplNum =S[i].bsn; //2005.5.17

					//break;  // break k and then for next i
					S_Idx[k]  = k;
					min_S_Idx = k;
					min_S_v   = S[k].v;
				}
		   } //if(i != k)

		}//for(k=1; i<=m; k++)

		////////
		for(k = 1; k<=old_m; k++)
		{
			if(S_Idx[k]>0)
			{
				 if(S[S_Idx[k] ].v <= min_S_v)  //?? pay attetion to must be <= 
				 {
					min_S_v = S[ S_Idx[k] ].v;
					min_S_Idx = S_Idx[k];
				 }
			}				
		}
		if(min_S_Idx >0 )
		{
			S[i].bsn = min_S_Idx; // s[i] is in s[k], i.e. S[i] is the subset of s[k]. IMPORTANT. bsn = Big Set Number
			S[i].tplNum =S[i].bsn; //2005.5.17
			//-------test 2---
				//sprintf(temp, " MIN S[%ld].v =%G cover, REMOVE S[%i]:  ", min_S_Idx, S[min_S_Idx].v, i );

				//cstrMarc += temp;
				//cstrMarc += "\r\n";
				//cstrMarc += "\r\n";
			//-------test 2---

			min_S_Idx =0;
			rmvable = true;
		}
		else
		{
			rmvable = false;
		}
		///////////

		/**** 07.03.04 
		if(l==1 && i==m && rmvable)  // forget the meaning of this conditions
		{                           // i==m ?? the last one S[m] is in S[k], k !=m
			AfxMessageBox("l==1 && i==m && rmvable");
		} //2005.5.14
        07.03.04 *****/
		//if( (rmvable == false) || (l==1 && i==m && rmvable) ) //cannot be removed //2005.5.14
		if( (rmvable == false)  ) //cannot be removed //2005.5.14
		{
			//T[l] = S[i];
			// :==: is the same as :==:
			//memset(&T[l], 0, sizeof(ZLRECT));
			//memcpy(&T[l], &S[i], sizeof(ZLRECT));
			
			for(j= 1; j <=n; j++)
			{
				T[l].a[j] = S[i].a[j];
				T[l].b[j] = S[i].b[j]; 
			}
			T[l].v=S[i].v;

			sprintf(T[l].suffix, "%d", l);
			T[l].suf1st = l;
			T[l].sufend = l;
			T[l].cn = 0;
			//T[l].bsn = l;  // 2004.4.13
			T[l].bsn = 0;    // 2004.4.13

			S[i].bsn= 123456+l; //10000+l;  here S[i] cannot be in some S[k]
								//ie. {S[i]} is the {T[l]}; i map l by 
			                    // the remainder of S[i]: S[i].bsn = l +10000; 
							    // where l is the index of T[l]. i.e. S[i] is the (sub)set of T[l]
			S[i].tplNum =S[i].bsn; //2005.5.17

			l++;
		}//if( (rmvable == false) || (l==1 && i==m && rmvable) ) //cannot be removed
	
	  } //if(S[i].bsn ==0)
	}//for(i=1; i<=m; i++)

	m_T = l-1;  // for T[i]; l-1 is the number of T[i]

lALL_EndTimer = GetTickCount()-lALL_StartTimer;
iALL_TickCount += lALL_EndTimer;
////////////////////////////////////////////////////////////////////////////////////	

////////////////////////////////////////////////////////////////////////////////////	
//3. Select * from 4 Cases;
//SELECT * FROM CLMB_census2D where (20 <= Age and Age <= 50) AND (3000 <= Income and Income <= 60000)
//---------------------------------------------------------------------
//---------------------------------------------------------------------
		
	int ituples_cnt = 0;
	int PreTuplesNum = 0;
	//char TableName[] = "CLUM_census2D";
	//char TableName[] = " Lsi_104D ";

	int iSum_TickCount = 0;
    int iSum_TuplesCount =0;
	int iCandidateNum = 0;

	//3.0 select * FROM  ALL TABLE: //SELECT * FROM CLMB_census2D, 
	//---------------------------------------------------------------------
/*
	strcpy(	szSql, 	" SELECT * FROM ");
	strcat(	szSql, 	TableName);

	lStartTimer = GetTickCount();
		PreTuplesNum = 0;
		//ituples_cnt = pApp->zlExeSelect(PreTuplesNum, szSql);
		bool brtn = pApp->zlExeInsertTable(szSql);
		//for(i =1; i<=m; i++)
			//iCandidateNum = pApp->zlGetTopNTuple(i, S, ituples_cnt);				

	lEndTimer = GetTickCount() - lStartTimer ;
    iTableSize = ituples_cnt;
*/


	//cstrMarc += "\r\n";
	//cstrMarc += TableName;
    //sprintf(temp, ": \r\n GetTickCount = %ld", lEndTimer);
	//cstrMarc += temp;
	//cstrMarc += "\r\n";
	//sprintf(temp, " All Size of Table = %ld", iTableSize);
	//cstrMarc += temp;
	//cstrMarc += "\r\n";
	//cstrMarc += "\r\n";

	//3.1 select * from each Search_Rectangle of all  {S[i]} with size m, 
	//---------------------------------------------------------------------
	//---------------------------------------------------------------------

	//m = min(m,l-1);

	// m = m ==100
       ////////////////////////
		/***
		char szSqltmp[] = " SELECT * FROM Lsi_104D ";
		SQLFreeStmt(hstmt, SQL_DROP);
		retcode = SQLAllocStmt(hdbc, &hstmt); ///Statement handle 
		if(retcode != SQL_SUCCESS)
			AfxMessageBox("1. Get m initial rectangles from DB, Error!" ); //return -1;

		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
		
		//longTicks = GetTickCount();
		retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlAllLearningRows, SQL_NTS);
		//longTicks = GetTickCount() - longTicks;
		***/



	  /////////////////////////////

   CString str1, str2, str3;

   //int N_Tuple, N_ALLTick,	N_ExtraTick, N_IO_Num;

/*
		///////////   GanRao start //////////		
		if(old_m < 40)
		{
			strcpy(	szSql, 	" SELECT * FROM ");
			strcat(	szSql, 	TableName );
			strcat(	szSql, 	" where ( ( ");			
				for(j=1; j<=COL_NUM-1; j++)
				{
					sprintf(temp, " %.15G <= attr%d AND attr%d <= %.15G ", S[old_m].a[j],j-1,j-1, S[old_m].b[j]);
					strcat(	szSql, temp	);
					strcat(	szSql, ") AND (" );
				}
				sprintf(temp, " %.15G <= attr%d AND attr%d <= %.15G ", S[old_m].a[COL_NUM],COL_NUM-1,COL_NUM-1, S[old_m].b[COL_NUM]);
				strcat(	szSql, temp	);

			strcat(	szSql, ") ) "	);

			ituples_cnt =  pApp->zlExeSelect(0, szSql);
			iCandidateNum = pApp->zlGetTopNTuple_S(i, S, ituples_cnt);	
		}
		/////////// GanRao end //////////	
*/

////// delete the first chaos  start    ////
/*	for(i = old_m; i<=old_m; i++) 
	{
		strcpy(	szSql, 	" SELECT * FROM ");
		strcat(	szSql, 	TableName );
		strcat(	szSql, 	" where ( ( ");
			
			for(j=1; j<=COL_NUM-1; j++)
			{
				sprintf(temp, " %.15G <= attr%d AND attr%d <= %.15G ", S[i].a[j],j-1,j-1, S[i].b[j]);
				strcat(	szSql, temp	);
				strcat(	szSql, ") AND (" );
			}

			sprintf(temp, " %.15G <= attr%d AND attr%d <= %.15G ", S[i].a[COL_NUM],COL_NUM-1,COL_NUM-1, S[i].b[COL_NUM]);
			strcat(	szSql, temp	);

		strcat(	szSql, ") ) "	);

		ituples_cnt =  pApp->zlExeSelect(0, szSql);
		iCandidateNum = pApp->zlGetTopNTuple_S(i, S, ituples_cnt);	
			
		pApp->zlother();
	} */
/////// delete the first chaos end /////
   //pApp->zlother();

///* 2007.03.04 *
//if( !pApp->zlEndSQLservr() )
    //AfxMessageBox("pApp->zlEndSQLservr() 1111 Error ");
//else
   //Sleep(2000);
//* 2007.03.04 */


//AfxMessageBox(" Region Clustering Method SSSSSStart !");
AfxGetMainWnd ( ) -> SetWindowText (_T("Region Clustering Method SSSSSStart !") ); 
//AfxGetMainWnd ( ) -> ShowWindow(SW_SHOW);
//AfxGetMainWnd ( ) -> UpdateWindow();
AfxGetMainWnd ( ) ->SetFocus( );

///* 2007.03.04 *
//if( pApp->zlStartSQLservr() )
//{
//    Sleep(2000);
//  	pApp->zlother();
//    Sleep(300);
//}
//* 2007.03.04 */

//AfxMessageBox(" Region Clustering Method SSSSSStart !");
//AfxGetMainWnd ( ) -> SetWindowText (_T("Region Clustering Method SSSSSStart !") ); 
//AfxGetMainWnd ( ) -> ShowWindow(SW_SHOW);
//AfxGetMainWnd ( ) -> UpdateWindow();
	
    //m_pMainWnd->ShowWindow(SW_SHOW);
	//m_pMainWnd->UpdateWindow();
	//3.2 select * From UNION of l T[i]: from T[1] to T[l] generally l<=m , 
    //---------------------------------------------------------------------

	m   = l-1;  // for T[i]
	m_T = l-1;  // for T[i]
/***********
	cstrMarc += "\r\n";
	cstrMarc += " 2. select * From UNION ";

	strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ");

	for(i = 1; i<=m; i++)
	{
		strcat(	szSql, 	" ( ( ");

			sprintf(temp, " %.2f", T[i].a[1] );
			strcat(	szSql, temp	);
			strcat(	szSql, "<= age AND age <=");
			sprintf(temp, " %.2f", T[i].b[1] );
			strcat(	szSql, temp	);

			strcat(	szSql, ") AND (" );

			sprintf(temp, " %.2f", T[i].a[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, 	"<= Income AND Income <=");
			sprintf(temp, " %.2f", T[i].b[2] );
			strcat(	szSql, temp	);
		strcat(	szSql, ") ) "	);

		if(i<m)
			strcat(	szSql, " OR " );
	}

	//AfxMessageBox(szSql);

	lStartTimer = GetTickCount();
		ituples_cnt = zlExeSelect(TableName, szSql);
	lEndTimer = GetTickCount() - lStartTimer ;
	
	//iSum_TickCount += lEndTimer;

    sprintf(temp, " \r\n		The UNION¡¡spend TickCount = %ld", lEndTimer);
	cstrMarc += temp;
	cstrMarc += "\r\n";
    sprintf(temp, " \r\n		The UNION¡¡Tuples Number = %ld", ituples_cnt);
	cstrMarc += temp;
	cstrMarc += "\r\n";
*************/
	////3.0_1 select * FROM  ALL TABLE: SELECT * FROM CLMB_census2D, 
	
	//strcpy(	szSql, 	" SELECT * FROM CLMB_census2D ");
	//lStartTimer = GetTickCount();
	//	ituples_cnt = zlExeSelect(TableName, szSql);
	//lEndTimer = GetTickCount() - lStartTimer ;

	//cstrMarc += "\r\n";
    //sprintf(temp, "SELECT * FROM CLMB_census2D: GetTickCount = %ld", lEndTimer);
	//cstrMarc += temp;
	//cstrMarc += "\r\n";
	//cstrMarc += "\r\n";

	
///////////////////////// 333333333333333333 /////////////////////////////////
//   3.3  select * From SCR, obtain the scr (Small Cover Rectagle,) of all T[i], i=1,l
//					where the scr is the BIGGEST one that contains all T[i]'s
//---------------------------------------------------------------------
//---------------------------------------------------------------------
	
	m=l-1;  // for T[i], at this moment, the size of {T[i]} is l-1 
	//cstrMarc += "\r\n";
	//cstrMarc += " 3. select * From SCR ";

lALL_StartTimer = GetTickCount();

	ZLRECT scr;  //This is the BIG scr that covers all T[i]

	for(i=1; i<=n; i++ )
	{
		scr.a[i] = T[1].a[i];
		scr.b[i] = T[1].b[i];

		for(j=2; j<=m; j++ )
		{
			scr.a[i] = min(scr.a[i], T[j].a[i]);
			scr.b[i] = max(scr.b[i], T[j].b[i]);
		}
	}

lALL_EndTimer = GetTickCount()-lALL_StartTimer;
iALL_TickCount += lALL_EndTimer;

///===========
//scr.a[1] = 15; scr.b[1]=90;
//scr.a[2] =0 ; scr.b[2]= 347998;   

//scr.a[2] =-25897 ; scr.b[2]= 347998;  //-25897	347998
///===========

/***********
		strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ( ( ");
		
			sprintf(temp, " %.2f ", scr.a[1] );
			strcat(	szSql, temp	);
			strcat(	szSql, "<= age AND age <=");
			sprintf(temp, " %.2f ", scr.b[1] );
			strcat(	szSql, temp	);

			strcat(	szSql, ") AND (" );

			sprintf(temp, " %.2f ", scr.a[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, 	"<= Income AND Income <=");
			sprintf(temp, " %.2f ", scr.b[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, ") ) "	);
*****************/
/*
		strcpy(	szSql, 	" SELECT * FROM ");
		strcat(	szSql, 	TableName );
		strcat(	szSql, 	" where ( ( ");
			
			for(j=1; j<=COL_NUM-1; j++)
			{
				sprintf(temp, " %.15G <= attr%d AND attr%d <= %.15G ", scr.a[j],j-1,j-1, scr.b[j]);
				strcat(	szSql, temp	);
				strcat(	szSql, ") AND (" );
			}

			sprintf(temp, " %.15G <= attr%d AND attr%d <= %.15G ", scr.a[COL_NUM],COL_NUM-1,COL_NUM-1, scr.b[COL_NUM]);
			strcat(	szSql, temp	);

		strcat(	szSql, ") ) "	);

		/////////----
					//CString cstrMarc1;
					//cstrMarc1 = szSql;

					//CFile file;
					//if(file.Open("E:\\Paper2\\CLMB_census2D\\Lsi_104D.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
					//{
						//file.Write(cstrMarc1, cstrMarc1.GetLength() +1 );
					//}
					//file.Close();
		/////////----

//strcpy(	szSql, 	" SELECT * FROM CLMB_census2D Where ( (15 <=Age AND Age<=90) AND (0 <=Income and income <= 347998) ) ");

			lStartTimer = GetTickCount();
				ituples_cnt = zlExeSelect(TableName, szSql);
		    lEndTimer = GetTickCount() - lStartTimer ;
			
			iSum_TickCount += lEndTimer;
*/
		/*	cstrMarc += "\r\n";
            //sprintf(temp, "The Biggest scr: [%.2f, %.2f]x[%.2f, %.2f]: ", scr.a[1], scr.b[1], scr.a[2], scr.b[2] );
			//cstrMarc += temp;

            sprintf(temp, "\r\n    scr  GetTickCount = %ld", lEndTimer);
			cstrMarc += temp;
			cstrMarc += "\r\n";
			sprintf(temp, "\r\n    scr  Tuples Number = %ld", ituples_cnt);
			cstrMarc += temp;
			cstrMarc += "\r\n";

			cstrMarc += "\r\n";
		*/
////////////////////////////////////////////////////////////////////////////////////	

////////////////////////////////////////////////////////////////////////////////////	
///////////////////////// 44444444444444444444 ///////////////////////
//3.4  ----   division the biggest scr into 12 = 4*3 partition or more ----
//            select * From each partition,
//---------------------------------------------------------------------
//---------------------------------------------------------------------
lALL_StartTimer = GetTickCount();
	//ZLRECT	part[101]; //we use 1-12
	int		iPartNum = 0;

    //char	buffer[1024] ="";

	//int ilnum =0, iaaallNum =0;

	if(n==2) //only for 2_dimensional
		iPartNum = pApp->zlPartion(scr, n, T, m, iPartNum);
		//iPartNum = pApp->zlPartion_tt(scr, n, T, m, iPartNum);

//	else	 //for 3,4, 25,50,and 104 dimensions
	//	iPartNum = pApp->zlPartion3D(&scr, n, T, m, iPartNum);
	//Get T[j].bsn =i means the center of T[j] is in part[i]

lALL_EndTimer = GetTickCount()-lALL_StartTimer;
iALL_TickCount += lALL_EndTimer;

int bsn[WORKLOAD_NUM +1 ];// 101
for(i=0; i<=WORKLOAD_NUM; i++)   //100
	bsn[i] =-100;



//--------------------test33 start ---------
//see How many T[j] does Part[i] contain ?  (== ilnum )
	
	//ZLRECT	part[101]; //we use 1-12
    ZLRECT * part = new ZLRECT[iPartNum +1];

    char	buffer[1024] = "";
	int ilnum =0, iaaallNum =0;

	for(i= 1; i<=iPartNum; i++)
	{
		sprintf(part[i].suffix, " Part[%i]: " , i ); 
	}

	for(i= 1; i<=iPartNum; i++)
	{
		ilnum =0;
		for(j=1; j<=m; j++)
		{
			if(T[j].bsn == i)
			{
				sprintf(buffer, ",%i", j);
				strcat(part[i].suffix, buffer); 
				ilnum ++;
			}
		}
		sprintf(buffer, "   part[%i]: ilnum= %i   ", i, ilnum);
		//cstrMarc += buffer;			

		//cstrMarc += part[i].suffix;						 
	    //cstrMarc += "\r\n";
	    //cstrMarc += "\r\n";

       iaaallNum +=ilnum;

	}

		sprintf(buffer, "   iallNum = %i", iaaallNum);
		//cstrMarc += buffer;						 
	    //cstrMarc += "\r\n";

	      //cstrMarc += "T[j].bsn <= 0  :";
	    //cstrMarc += "\r\n";


		ilnum =0;
		for(j=1; j<=m; j++)
		{
			bsn[j] = T[j].bsn;
			if(T[j].bsn <= 0)
			{
				sprintf(buffer, ",%i", j);
		        //cstrMarc += buffer;						 
	            //cstrMarc += "\r\n";

				////strcat(part[i].suffix, buffer); 
				ilnum ++;
			}
		}

		sprintf(buffer, "  The number of T[j].bsn <= 0:  %i", ilnum);
		//cstrMarc += buffer;						 
	    //cstrMarc += "\r\n";
//--------------------test33 end---------



	//CFile file;

	//if(file.Open("E:\\Paper2\\CLMB_census2D\\part.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
	////if(file.Open("E:\\Paper2\\CLMB_census2D\\cluster_100_census2D.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
	//{
	//	file.Write(cstrMarc, cstrMarc.GetLength() +1 );
	//}
	//file.Close();

    //AfxMessageBox("On part OK!");

//return;


//------test 3.4 start ------
//	cstrMarc += "\r\n";
//	cstrMarc += "\r\n";
//	CString cstrPart ;

//for(i=1; i<=12; i++)
//{
           
//	sprintf(temp, " part[%02i]: [%.2f, %.2f]x[%.2f, %.2f]: ",i, part[i].a[1], part[i].b[1], part[i].a[2], part[i].b[2] );
//	cstrPart += temp;
//    cstrPart += "\r\n";

//}

//	AfxMessageBox(cstrPart);
//	cstrMarc += "\r\n";
//	cstrMarc += "\r\n";

//------test 3.3 end --------

	//iSum_TickCount =0;
	//iSum_TuplesCount =0;
/**************
	for(i=1; i<=12; i++)
	{
		strcpy(	szSql, 	" SELECT * FROM CLMB_census2D where ( ( ");
		
			sprintf(temp, " %.2f ", part[i].a[1] );
			strcat(	szSql, temp	);
			strcat(	szSql, "<= age AND age <=");
			sprintf(temp, " %.2f ", part[i].b[1] );
			strcat(	szSql, temp	);

			strcat(	szSql, ") AND (" );

			sprintf(temp, " %.2f ", part[i].a[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, 	"<= Income AND Income <=");
			sprintf(temp, " %.2f ", part[i].b[2] );
			strcat(	szSql, temp	);
			strcat(	szSql, ") ) "	);

			lStartTimer = GetTickCount();
				ituples_cnt = zlExeSelect(TableName, szSql);
		    lEndTimer = GetTickCount() - lStartTimer ;
			
			iSum_TickCount += lEndTimer;
			iSum_TuplesCount += ituples_cnt;

			sprintf(temp, " part[%02i]: [%.2f, %.2f]x[%.2f, %.2f]: ",i, part[i].a[1], part[i].b[1], part[i].a[2], part[i].b[2] );
			cstrMarc += temp;
            sprintf(temp, "Num_tuples = %ld,  GetTickCount = %ld", ituples_cnt, lEndTimer);
			cstrMarc += temp;
			cstrMarc += "\r\n";
	}

	    sprintf(temp, "       Sum of Tick Count of all Part = %ld", iSum_TickCount);
		cstrMarc += temp;
		cstrMarc += "\r\n";
		sprintf(temp, "       Sum of Tuples Count = %ld", iSum_TuplesCount);
		cstrMarc += temp;
		cstrMarc += "\r\n";
********************/
////////////////////////////////////////////////////////////////////////////////////	

////////////////////////////////////////////////////////////////////////////////////	
//3.5 ---- Find which rectangle T[i] that Center IN the partition of all 12 = 4*3 partitions ----
//         DO NOT USE intersect, 
//	     We use "Center IN" method 
/////////////////////// 555555555555555 /////////////////////
//3.6 ------------------- Clustering -----------------------
// we use the method of "Center IN " to clustering: 
// see the function iPartNum = pApp->zlPartion3D(&scr, n, T, m, iPartNum);
// in this function, the method of "Center IN " has been used
//---------------------------------------------------------------------
//---------------------------------------------------------------------


	iSum_TickCount =0;
	iSum_TuplesCount =0;
	
	//cstrMarc += "\r\n";
	//cstrMarc += "\r\n";

	//int		index[101][101];  // i= 1 to 12 intersect with part[i] : index[i][1]=5, index[i][2]=7,index[i][3]=8, index[i][4]=15,...
	//int		index[WORKLOAD_NUM + 1][WORKLOAD_NUM+1];  //2007.02.21 i= 1 to 12 intersect with part[i] : index[i][1]=5, index[i][2]=7,index[i][3]=8, index[i][4]=15,...	
	int * * index; 
	index = new (int *[iPartNum+1]);
	for(i= 0; i<=iPartNum; i++)
		index[i] = new int[WORKLOAD_NUM+1];

	for(i= 1; i<=iPartNum; i++)
	{
		for(j=1; j<=WORKLOAD_NUM; j++)
		{
			index[i][j] = 0;
		}
	}


	//double	p, q;
	bool	bInterable =false;

	//for(i= 1; i<=12; i++)
	// renew the value of part[i].suffix
	
	/*  2007.02.21 
	for(i= 1; i<=iPartNum; i++)
	{
		sprintf(part[i].suffix, " Part[%i]: " , i );
	}
    */

	//cstrMarc += "\r\n";
    //cstrMarc += "\r\n";
	
	ZLRECT * partT[101];
	//int clsNum =0;  //2005.3.16
	//int clsNum =1000; ////2005.3.16 , only for intersections
	//int clsNum =12; ////2005.3.24 , only for intersections
	int clsNum = iPartNum; //2005.4.14

	double center =0.0;

	/*  2007.02.21 
	//for(i= 1; i<=12; i++)
	for(i= 1; i<=iPartNum; i++)
	{
		sprintf(part[i].suffix, " Part[%i]: " , i ); 
		//?? for debug ? WHY part[i].suffix?  NOT partT[i].suffix
		// Yes, for debug!
	}
    */
lALL_StartTimer = GetTickCount();

/*	
  //for(i= 1; i<=12; i++)
	for(i= 1; i<=iPartNum; i++)
	{
		//for(j=1; j<=100; j++)
		for(j=1; j<=WORKLOAD_NUM; j++)
		{
			index[i][j] = 0;
		}
	}
*/

////// ~~~~~~~~ Finding all T[j]'s that center are in part[i].
/////         and clustering by calling: pApp->zlClusterPart	

	
	for(i= 1; i<=iPartNum; i++)
	{
		l=0;
		for(j= 1; j <=m ; j++) // m is the number of T[i]'s
		{
			//T[j].bsn == i means T[j]-CENTER is IN  part[i]
			if(T[j].bsn == i && T[j].cn <=0)   
			{
					l++;
					index[i][l] = j;
					sprintf(buffer, ",%i", j);
					strcat(part[i].suffix, buffer); // save the index j of T[j] 

					T[j].cn = i;                   //2005.3.16, use it again.

					partT[l] = &T[j]; // the address of (T[j]) assign to (partT[l]);

			}
		}

		//cstrMarc += part[i].suffix;						 
	    //cstrMarc += "\r\n";

		if(l>0)
		{
		  //clsNum = zlClusterPart( partT, l, T, m, clsNum, n );  
		  //clsNum = pApp->zlClusterPart( partT, l, T, m, clsNum, n ); //2005.04.28
			
			//if( n == 2 )
			//if( n <= 4 )
				//clsNum = pApp->zlClusterPart( partT, l, T, m, clsNum, n, iPartNum);  			
			    // for threshold : Intersection

///////1. I:   //Census2D  //Census3D   //Cover4D 
		//clsNum = pApp->zlClusterPart( partT, l, T, m, clsNum, n, iPartNum, xi);  			

			//else
				//clsNum = pApp->zlClusterPartLsi( partT, l, T, m, clsNum, n, iPartNum);  			
			    // for threshold
                //Intersection:
				 ///////clsNum = pApp->zlClusterPartLsi_InSe( partT, l, T, m, clsNum, n, iPartNum, xi);  			

//////2  C:  //Array3D //Gauss3D //Lsi_025D //Lsi_050D //Lsi_104D
		//clsNum = pApp->zlClusterPartLsi( partT, l, T, m, clsNum, n, iPartNum, xi);  			
//////3  C+:
		//clsNum = pApp->zlClusterPartLsi_Plus( partT, l, T, m, clsNum, n, iPartNum, xi);  			
                
			//Conclusions: 
			//	           1. Cover4D uses: I-Clustering 
			//                threshold: [0, 0.25] , Intersect-Clustering
				
			//             2. Gauss3D need to use: C-clustering: zlClusterPartLsi. 
				              //Intersect:0.979218; C: 0.88092; C+:0.914235
				              //threshold: [,  ]

			//             3. Array3D use: C-clustering
			//				 //Intersect:0.889198; C:0.806674 ; C+ :.841225
			//             4. Census3D use: I-clustering
			//             5. Census2D use: I-clustering
		    //             6: Lsi_104D use : C-clustering
		    //             7: Lsi_050D use : 2. C-clustering
			//             8: Lsi_025D use : 2. C-clustering
        
         /**** 2007.12.09
	     //if(strcmp(TableName, " Attr_Census2D ")==0 || strcmp(TableName, " Attr_Census3D ")==0 || strcmp(TableName, " Attr_Cover4D ")==0)
		 if(iModle == 1)    
			clsNum = pApp->zlClusterPart( partT, l, T, m, clsNum, n, iPartNum, xi);  			
		 //else if(strcmp(TableName, " Attr_Array3D ")==0 || strcmp(TableName, " Attr_Gauss3D ")==0 || strcmp(TableName,  " Lsi_025D ")==0 || strcmp(TableName, " Lsi_050D ")==0 || strcmp(TableName, " Lsi_104D ")==0 )
		 else if(iModle == 2)   
		    clsNum = pApp->zlClusterPartLsi( partT, l, T, m, clsNum, n, iPartNum, xi);  					 
		 2007.12.09 ******/
		}
	}

	clsNum = iPartNum ; //2007.12.09
	
lALL_EndTimer = GetTickCount()-lALL_StartTimer;
iALL_TickCount += lALL_EndTimer;


////////////////////---------ttest start ----------///////////
// see cluster[i] contain: T[j]'s
	//cstrMarc += "\r\n";
	//cstrMarc += "\r\n";
    int iclsNum =0;
	int iallNum =0;


	for(i=1; i<= clsNum; i++)
	{
		iclsNum =0;

		sprintf(temp, "cluster[%02i] : ", i);
		//cstrMarc += temp;
		//cstrMarc += "\r\n";

		for(j=1; j<=m; j++)
		{
			if(T[j].cn == i)
			{
				//sprintf(temp, ", %02i", j);
				sprintf(temp, " T[%02i],T[%02i].bsn =%02i;  ", j, j, T[j].bsn );
				//cstrMarc += temp;
				iclsNum ++;
			}			
		}

		if(iclsNum >0)
		{
			//cstrMarc += "\r\n";
			sprintf(temp, "    iclsNum = %02i ", iclsNum);
			//cstrMarc += temp;
			iallNum = iallNum + iclsNum; 
			//cstrMarc += "\r\n";
			//cstrMarc += "\r\n";
		}

	}

		sprintf(temp, " iallNum = %02i ", iallNum);
		//cstrMarc += temp;
		//cstrMarc += "\r\n";
//////////////////---------ttest end ----------///////////
////////////////////////////////////////////////////////////////////////////////////	

////////////////////////////////////////////////////////////////////////////////////	
//					 Finding scr of each Cluster						//
//					 scr_CLS[i]

lALL_StartTimer = GetTickCount();		
iSum_TickCount = 0;
iSum_TuplesCount =0;

	double * Sum_v_T = new double [clsNum +1]; //[100 +1]; //
	ZLRECT * scr_CLS = new ZLRECT [clsNum +1]; //[100+1];   //  
	
	//delete [] Sum_v_T;

	//delete [] scr_CLS;
	for(i=1; i<=clsNum; i++)
	{
		scr_CLS[i].v = 1.0;
		
		Sum_v_T[i] = 0.0;
		for(k=1; k<= m_T; k++) //old_m ==100; m_T = l-1
		{
			if(T[k].cn ==i)
			{
				Sum_v_T[i] += T[k].v; //all T[k] with cluster num == i 
			}

		}

	}

	for(i=1; i<=clsNum; i++ )
	{
		for(j=1; j<=n; j++)
		{
		    scr_CLS[i].a[j] = dMax[j];
			scr_CLS[i].b[j] = dMin[j];
		}
		for(j=1; j<=n; j++)
		{
			for(k=1; k<=m_T; k++) // 
			{
				if(T[k].cn ==i)
				{
					scr_CLS[i].a[j] = min(scr_CLS[i].a[j], T[k].a[j]);
					scr_CLS[i].b[j] = max(scr_CLS[i].b[j], T[k].b[j]);
				}

			}
		}

		for(j=1; j<=n; j++)
		{
			if(n<25)
				scr_CLS[i].v *= (scr_CLS[i].b[j]-scr_CLS[i].a[j]) ;
			else
				scr_CLS[i].v *= ( (scr_CLS[i].b[j]-scr_CLS[i].a[j])/VFactor ) ;

		}
	}
	
lALL_EndTimer = GetTickCount()-lALL_StartTimer;
iALL_TickCount += lALL_EndTimer;
	
	//---TEST see the v of all scr_CLS[i]
		//double v [100];
		 double * v = new double [clsNum+1];

			for(i=1; i<=clsNum; i++ )
				v[i] = scr_CLS[i].v;
			v[0] = V_Lsi104D;
         delete [] v;
	//---TEST see the v of all scr_CLS[i]

	int nonzearo =0;
	//cstrMarc += "\r\n";
// not for T[i], But for T[i]; 2005.5.17
lALL_StartTimer = GetTickCount();	
	
	for(i = 1; i<=clsNum; i++)
	{
		//scr_CLS[i].bsn = 1; // means has elements T[i] //2005.5.22 
		scr_CLS[i].cn = 1; //2005.5.22 means "has elements T[i]", ie, nonempty
	}

	//?? see whether or not all T[j]'s (in part[i]) can be clustering 
	//for cen2D CETA = 4
	//int CETA = 1 ; //1;  //10; //For Lsi_050D, CETA = 1; OK
	//int CETA = 2 ; //1;  //10; // For Lsi_104D 
    // define at the head of function
  /***********
	for(i = 1; i<=iPartNum ; i++)   //2005.5.5
	{
		//?? add if (.bsn ==1)
		// CETA = 3, 4, 5,10
		if(scr_CLS[i].v <= CETA*Sum_v_T[i]  )  // 5*Sum_v_T[i] //10*Sum_v_T[i]
		{
			/// test ////
			//sprintf(temp, " scr_CLS[%02i].v = %G <<<=== %i*Sum_v_T[%02i] =%G;  ",i, scr_CLS[i].v, CETA, i, Sum_v_T[i] );
			//cstrMarc += temp;
			//cstrMarc += "\r\n";
			//sprintf(temp, "		scr_CLS[%02i].v/Sum_v_T[%02i]= %.02f   ",i,i, scr_CLS[i].v/Sum_v_T[i] );
			//cstrMarc += temp;
			//cstrMarc += "\r\n";
			//cstrMarc += "\r\n";
			/// test ////
		}
		else // that is: scr_CLS[i].v/Sum_v_T[i]  >CETA , Cancel this cluster
		{
            k=0;
			for(j=1; j<=m_T; j++)
			{
				if(T[j].cn == i)
				{
					T[j].cn =0;
					k++;
				}
			}

			//scr_CLS[i].bsn = 0; //2005.5.22
			scr_CLS[i].cn = 0; //2005.5.22 means empty, ie., no rectangle in it.

			//scr_CLS[i].cn =k;  // old. //2005.5.22 in the begining it has k T[i], //?? is that useful??

			/// test ////
			//sprintf(temp, " scr_CLS[%02i].v = %G >>>>>> %i*Sum_v_T[%02i] =%G ",i, scr_CLS[i].v, CETA, i, Sum_v_T[i] );
			//cstrMarc += temp;
			//cstrMarc += "\r\n";
			//sprintf(temp, "						scr_CLS[%02i].v/Sum_v_T[%02i]= %.02f   ",i,i, scr_CLS[i].v/Sum_v_T[i] );
			//cstrMarc += temp;
			//cstrMarc += "\r\n";
			//cstrMarc += "\r\n";
			/// test ////

		}
	}

  ********/
////////////////////////////////////////////////////////////////////////////////////	

////////////////////////////////////////////////////////////////////////////////////	
//clustering again if one is the subset of another, then togather them 
   //3.9.1 for  scr_CLS[i].bsn =1 change it to scr_CLS[i].cn =1 2005.5.22
   //3.9.2 for T[i].cn =0
//---------------------------------------------------------------------
//---------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////////	
	// see whethe or not there are SUBSET 
	//  if scr_CLS[i] is the SUBSET of scr_CLS[k], label it, //scr_CLS[i].bsn = 0; change it to scr_CLS[i].cn = 0 //2005.5.22
	//  and remove it

	int scr_CLS_Idx[WORKLOAD_NUM+1];  //101
	for(i=1; i<=WORKLOAD_NUM ; i++)  //100
		scr_CLS_Idx[i]=0;

	int min_scr_CLS_Idx = 0;
	double min_scr_CLS_v =0.0;


	// for dimension >24, for(i=1; i<=iPartNum; i++) there are lots of clustering 
	// only contain one T[i]; so remove it;

	//int bsn[101];  //has defined before
	int cn[WORKLOAD_NUM +1]; //101
	//--- test   ---
	for(i=0; i<WORKLOAD_NUM; i++)    //101
	{
		bsn[i] = -1;
		cn[i] = -1;
	}

	for(i=1; i<=clsNum; i++)
	{
		bsn[i] = scr_CLS[i].bsn;
		cn[i] = scr_CLS[i].cn;
	}
   	//--- test   ---

	///***
	//for(i=1; i<=clsNum; i++)
	for(i=1; i<=iPartNum; i++)
	{
	  rmvable = false;

	  for(j=1; j<= WORKLOAD_NUM; j++) //100
		  scr_CLS_Idx[j]=0;


	  //if(scr_CLS[i].bsn ==1) // scr_CLS[i].bsn = 3, means scr_CLS[i].bsn
							   // is the SUBSET of scr_CLS[3]

	  if(scr_CLS[i].cn ==1) // scr_CLS[i].cn ==1 means it is NOT empty. ie. 
	  {                     // there is T[j] that is in scr_CLS[i]

		for(k=1; k<=clsNum; k++)
		{
		   //if( (i != k) && scr_CLS[k].bsn ==1 )
		   if( (i != k) && scr_CLS[k].cn ==1 )
		   {
				for(j=1; j<=n; j++)
				{
					// if scr_CLS[i] is the subset of scr_CLS[k], 
					//if( (scr_CLS[k].a[j]<=scr_CLS[i].a[j]) && (scr_CLS[i].b[j]<=scr_CLS[k].b[j] ))
					//if the center of scr_CLS[i] is in scr_CLS[k],
					
					if( (scr_CLS[k].a[j]<=scr_CLS[i].a[j]) && (scr_CLS[i].b[j]<=scr_CLS[k].b[j] ))		
					{
						rmvable = true;
					}
					else
					{
						rmvable = false;
						break; //break j, for next k
					}
				} //for(j= 1; j <=n; j++)
				
				if(rmvable) //there is a k, such that scr_CLS[i] is in scr_CLS[k] 
				{
						//-------test 2---
							//sprintf(temp, " scr_CLS[%ld].v =%G cover, REMOVE scr_CLS[%i]: [%G, %G]x[%G, %G]: ", k, scr_CLS[k].v, i, scr_CLS[i].a[1], scr_CLS[i].b[1], scr_CLS[i].a[2], scr_CLS[i].b[2] );
							//cstrMarc += temp;
							//cstrMarc += "\r\n";

						//-------test 2---
					//scr_CLS[i].bsn = 0; // s[i] is in s[k], IMPORTANT
					//for(l=1; l<=old_m; l++)
					//{
						//if(T[l].cn ==i)
							//T[l].cn=k;
					//}

					scr_CLS_Idx[k]=k;
					min_scr_CLS_Idx=k;
					min_scr_CLS_v =scr_CLS[k].v;

					rmvable = false;
					

					//break;  //2005.5.15 not break, for k continue; break k and then for next i
				}

		   } //if(i != k)

		}//for(k=1; i<=m; k++)

		////////
			 for(k = 1; k<=clsNum; k++)
			 {
				 if(scr_CLS_Idx[k] >0)
				 {
					 if(scr_CLS[ scr_CLS_Idx[k] ].v <= min_scr_CLS_v)
					 {
						min_scr_CLS_v =  scr_CLS[ scr_CLS_Idx[k] ].v;
						min_scr_CLS_Idx = scr_CLS_Idx[k];
					 }
				 }
				
			 }
			if(min_scr_CLS_Idx >0 )
			{
				//scr_CLS[i].bsn = 0; 
				scr_CLS[i].cn = 0; 
				for(l=1; l<=m_T; l++)
				{
					if(T[l].cn ==i)
						T[l].cn = min_scr_CLS_Idx;
				}
				//-------test 2---
					//sprintf(temp, " MIN scr_CLS[%ld].v =%G cover, REMOVE scr_CLS[%i]: [%G, %G]x[%G, %G]: ", min_scr_CLS_Idx, scr_CLS[min_scr_CLS_Idx].v, i, scr_CLS[i].a[1], scr_CLS[i].b[1], scr_CLS[i].a[2], scr_CLS[i].b[2] );

					//cstrMarc += temp;
					//cstrMarc += "\r\n";
					//cstrMarc += "\r\n";
			//-------test 2---

				min_scr_CLS_Idx =0;
			}
		///////////

	  }
	}//for(i=1; i<=m; i++) 
    //***********/


	//Finding scr_CLS[i].bsn that save the index of its Supperset
    // say, scr_CLS[38].bsn = 36; means scr_CLS[38] is IN scr_CLS[36]
	
	//initial them to be 0
	for(i=1; i<=clsNum; i++)
	{
		scr_CLS[i].bsn = 0;
	}

	
	for(i=1; i<=clsNum; i++)
	{ 
      //if(scr_CLS[i].bsn ==0)
	  if(scr_CLS[i].bsn ==0 && scr_CLS[i].cn ==1 )
	  {
		rmvable =false;
		for(j=1; j<=WORKLOAD_NUM; j++) //100
		  scr_CLS_Idx[j]=0;
		min_scr_CLS_Idx =0;

		for(k=1; k<=clsNum; k++)
		{
		   // for each i, see ?? scr_CLS[i] in scr_CLS[k], for all k:  i!=k and scr_CLS[k] is not removed
		   // this way can avoid the situation scr_CLS[i] ==scr_CLS[k]. say, scr_CLS[8] == scr_CLS[65]
           // then in the case of scr_CLS[8] == scr_CLS[65], the loop of () will be dead loop

		   //if(i != k )  // 2005.4.8
		   //if( k != i  && scr_CLS[k].bsn == 0) // 2005.4.8 
		   if( k != i  && scr_CLS[k].bsn != i && scr_CLS[k].cn ==1) // 2005.5.22 //finding scr_CLS[i]'s all superset scr_CLS[k] that is not itself and 
		   {                                          //scr_CLS[k].bsn != i
				for(j=1; j<=n; j++)
				{
					// if scr_CLS[i] is the subset of scr_CLS[k], 
					if( (scr_CLS[k].a[j]<=scr_CLS[i].a[j]) && (scr_CLS[i].b[j]<=scr_CLS[k].b[j] ))
					{
						rmvable = true;
					}
					else
					{
						rmvable = false;
						break; //break j, for next k
					}
				} //for(j= 1; j <=n; j++)
				
				if(rmvable) //there is a k such that scr_CLSi is in scr_CLSk 
				{
						//-------test 2---
							//sprintf(temp, " scr_CLS[%ld] cover, REMOVE scr_CLS[%i] = [%G, %.15G]x[%G, %G]: ", k, i, scr_CLS[i].a[1], scr_CLS[i].b[1], scr_CLS[i].a[2], scr_CLS[i].b[2] );
							//cstrMarc += temp;
							//cstrMarc += "\r\n";

						//-------test 2---
					//scr_CLS[i].bsn = k; // s[i] is in s[k], i.e. scr_CLS[i] is the subset of s[k]. IMPORTANT. bsn = Big scr_CLSet Number
					//scr_CLS[i].tplNum =scr_CLS[i].bsn; //2005.5.17

					//break;  // break k and then for next i
					scr_CLS_Idx[k]=k;
					min_scr_CLS_Idx=k;
					min_scr_CLS_v =scr_CLS[k].v;
				}
		   } //if(i != k)

		}//for(k=1; i<=scr_CLS; k++)

		////////
		for(k = 1; k<=clsNum; k++)
		{
			if(scr_CLS_Idx[k]>0)
			{
				 if(scr_CLS[scr_CLS_Idx[k] ].v <= min_scr_CLS_v)
				 {
					min_scr_CLS_v = scr_CLS[ scr_CLS_Idx[k] ].v;
					min_scr_CLS_Idx = scr_CLS_Idx[k];
				 }
			}
				
		}
		if(min_scr_CLS_Idx >0 )
		{
			scr_CLS[i].bsn = min_scr_CLS_Idx; // scr_CLS[i] is in scr_CLS[k], i.e. scr_CLS[i] is the subset of s[k]. IMPORTANT. bsn = Big scr_CLSet Number
			scr_CLS[i].tplNum =scr_CLS[i].bsn; //2005.5.17
			//-------test 2---
				//sprintf(temp, " MIN scr_CLS[%ld].v =%G cover, REMOVE scr_CLS[%i]:  ", min_scr_CLS_Idx, scr_CLS[min_scr_CLS_Idx].v, i );

				//cstrMarc += temp;
				//cstrMarc += "\r\n";
				//cstrMarc += "\r\n";
			//-------test 2---

			min_scr_CLS_Idx =0;
		}
		///////////
	
	  } //if(scr_CLS[i].bsn ==0)
	}//for(i=1; i<=clsNum; i++)
////////////////////////////////////////////////////////////////////////////////////	


   //3.9.2 if  T[k].cn == 0 that is obtained from	"if( !(scr_CLS[i].v <= CETA*Sum_v_T[i])  )"
	rmvable =false;

	for(i=1; i<=WORKLOAD_NUM; i++) //100
		scr_CLS_Idx[i]=0;

	min_scr_CLS_Idx = 0;
	min_scr_CLS_v =0.0;

	for(k=1; k<=m_T; k++)
	{
				
	  if(T[k].cn ==0 )  
	  {

		rmvable = false;

		for(j=1; j<=WORKLOAD_NUM; j++) //100
			scr_CLS_Idx[j]=0;

		for(i=1; i<=clsNum; i++)
		{
			rmvable =false;

			//if(scr_CLS[i].bsn ==1) //2005.5.22
			if(scr_CLS[i].cn ==1)  //2005.5.22
			{
					for(j=1; j<=n; j++)
					{
						 // if T[k] is the subset of scr_CLS[i], 
						if( (scr_CLS[i].a[j]<=T[k].a[j]) && (T[k].b[j]<=scr_CLS[i].b[j] ))
						{
							rmvable = true;
						}
						else
						{
							rmvable = false;
							break; //break j, for next k
						}
					} //for(j= 1; j <=n; j++)
				
				
					if(rmvable) //there is a k such that scr_CLS[i] is in scr_CLS[k] 
					{
							//-------test 2---
								//sprintf(temp, " scr_CLS[%ld] cover, REMOVE T[%i]= [%.2f, %.2f]x[%.2f, %.2f]: ", i, k, T[k].a[1], T[k].b[1], T[k].a[2], T[k].b[2] );
								//cstrMarc += temp;
								//cstrMarc += "\r\n";

							//-------test 2---

						//T[k].cn = i;
						scr_CLS_Idx[i] = i;
						min_scr_CLS_Idx = i;
						min_scr_CLS_v = scr_CLS[i].v;

								
						rmvable =false;
						//break;  // 2005.5.15 not break, for next i countinoue; break k and then for next i
					}//if(rmvable)
				}//if(T[k].cn ==0 )
			}//for(i=1; i<=clsNum; i++)

		////////
			 for(i = 1; i<=clsNum; i++)
			 {
				 if(scr_CLS_Idx[i] >0)
				 {
					 if(scr_CLS[ scr_CLS_Idx[i] ].v <= min_scr_CLS_v)
					 {
						min_scr_CLS_v =  scr_CLS[ scr_CLS_Idx[i] ].v;
						min_scr_CLS_Idx = scr_CLS_Idx[i];
					 }
				 }
				
			 }
			if(min_scr_CLS_Idx >0 )
			{
				T[k].cn = min_scr_CLS_Idx;
				 //-------test 2---
					//sprintf(temp, " MIN scr_CLS[%ld].v =%G cover, REMOVE T[%i]= [%.2f, %.2f]x[%.2f, %.2f]: ", min_scr_CLS_Idx, scr_CLS[min_scr_CLS_Idx].v, k, T[k].a[1], T[k].b[1], T[k].a[2], T[k].b[2] );

					//cstrMarc += temp;
					//cstrMarc += "\r\n";
					//cstrMarc += "\r\n";
				//-------test 2---
				min_scr_CLS_Idx =0;
			}
		///////////


		}
	}//for(k=1; k<=m_T; k++)
	int allNonzero =0;
	nonzearo = 0;
	//cstrMarc += "\r\n";

lALL_EndTimer = GetTickCount()-lALL_StartTimer;
iALL_TickCount += lALL_EndTimer;
/////////////////////////////////////////////////////

//-- Finding Which scr_CLS[i] is NOT empty, that is, let scr_CLS[i].bsn =1
//						change it into let scr_CLS[i].cn =1 2005.5.22
//------------------------------------------------------------------------
//------------------------------------------------------------------------
	for(i = 1; i<=clsNum; i++) // there are clsNum scr's of cluster scr_CLS[1] to scr_CLS[clsNum]
	{
		nonzearo = 0;
		sprintf(temp, " scr_CLS%02i:  ", i);
		//cstrMarc += temp;	
	    //cstrMarc += "\r\n";

		//cstrMarc += "    Cover: ";

		for(j=1; j<=m_T; j++)
		{
			if(T[j].cn ==i)
			{
				sprintf(temp, " ,T[%02i] ", j );
				//cstrMarc += temp;
				nonzearo ++;
			}
		}
	    //cstrMarc += "\r\n";

       allNonzero += nonzearo;

	}
    //cstrMarc += "\r\n";
	sprintf(temp, " T[i] allNonzero = %02i ", allNonzero);
	//cstrMarc += temp;
	//cstrMarc += "\r\n";

	int scr_nonZeroNum = 0;
	int scr_ZeroNum = 0;
	for(i = 1; i<=clsNum; i++) // there are clsNum scr's of cluster scr_CLS[1] to scr_CLS[clsNum]
	{
		  //if(scr_CLS[i].bsn == 1)
		  if(scr_CLS[i].cn == 1)
		  {
			  scr_nonZeroNum ++;
		  }
		  //else if(scr_CLS[i].bsn == 0)
		  else if(scr_CLS[i].cn == 0)
		  {
			  scr_ZeroNum ++;
		  }
	}

    //cstrMarc += "\r\n";
	sprintf(temp, " scr_nonZeroNum = %02i ", scr_nonZeroNum);
	//cstrMarc += temp;
	//cstrMarc += "\r\n";
    //cstrMarc += "\r\n";
	sprintf(temp, " scr_ZeroNum = %02i ", scr_ZeroNum);
	//cstrMarc += temp;
	//cstrMarc += "\r\n";
	//cstrMarc += "\r\n";
////////////////////---------ttest start ----------///////////
// see cluster[i] contain: T[j]'s
	//cstrMarc += "\r\n";
	//cstrMarc += "\r\n";
    iclsNum =0;
	iallNum =0;

	for(i=1; i<= clsNum; i++)
	{
		iclsNum =0;

		sprintf(temp, "cluster[%02i] : ", i);
		//cstrMarc += temp;
		//cstrMarc += "\r\n";

		for(j=1; j<=m; j++)
		{
			if(T[j].cn == i)
			{
				//sprintf(temp, ", %02i", j);
				sprintf(temp, " T[%02i].cn =%02i ,T[%02i].bsn =%02i;  ", j, T[j].cn ,j, T[j].bsn );
				//cstrMarc += temp;
				iclsNum ++;
			}			
		}


		if(iclsNum >0)
		{
			//cstrMarc += "\r\n";
			sprintf(temp, "    iclsNum = %02i ", iclsNum);
			//cstrMarc += temp;
			iallNum = iallNum + iclsNum; 
			//cstrMarc += "\r\n";
			//cstrMarc += "\r\n";

		}

	}


	int iZeroNum =0;
	sprintf(temp, "cluster[%02i] : ", 0);
	//cstrMarc += temp;
	//cstrMarc += "\r\n";


	for(j=1; j<=m; j++)
	{
		if(T[j].cn == 0)
		{
			//sprintf(temp, ", %02i", j);
			sprintf(temp, " T[%02i].cn =%02i ,T[%02i].bsn =%02i;  ", j, T[j].cn ,j, T[j].bsn );
			//cstrMarc += temp;
			iZeroNum ++;
		}			
	}

    //cstrMarc += "\r\n";
	sprintf(temp, " iallNum NonZero = %02i ", iallNum);
	//cstrMarc += temp;
	//cstrMarc += "\r\n";
	sprintf(temp, " iZeroNum = %02i ", iZeroNum);
	//cstrMarc += temp;
	//cstrMarc += "\r\n";
	//cstrMarc += "\r\n";
//////////////////---------ttest T[] end ----------/////////// 
////////////////////////////////////////////////////////////////////////////////////	




////////////////////////////////////////////////////////////////////////////////////	
//////////////////////// 666666666666666666 ////////////////////////////
// 3.7 ------------------- Clustering S[] -----------------------
//    obtain all cluster number of S[i] (where i=1 to 100)
//---------------------------------------------------------------------
//---------------------------------------------------------------------
////////////////////////////---------ttest S[] start ----------//////////////////
	//cstrMarc += " 11111 ----    ttest S[] ==== start \r\n";
	//cstrMarc += "\r\n";

    iclsNum =0;
	iallNum =0;

	for(j=1; j<=old_m; j++)
	{
		sprintf(temp, " S[%02i].cn =%02i ,S[%02i].bsn =%02i;  ", j, S[j].cn,  j, S[j].bsn );
		//cstrMarc += temp;
		iclsNum ++;
		//cstrMarc += "\r\n";
	}
	sprintf(temp, "; iclsNum = %02i ", iclsNum);
	//cstrMarc += temp;
	iallNum = iallNum + iclsNum; 

	//cstrMarc += "\r\n";

	sprintf(temp, " iallNum = %02i ", iallNum);
	//cstrMarc += temp;
	//cstrMarc += "\r\n";
////////////////////////////////////---------ttest S[] end ----------////////////


lALL_StartTimer = GetTickCount();	
	
	for(i=1; i<= old_m; i++)
	{

		do 
		{
			//if(S[i].bsn > 10000)
		    if(S[i].bsn > 123456)  // there is not another one that contains S[i]
			{	
				//S[i].cn = T[S[i].bsn-10000].cn;
				S[i].cn = T[S[i].bsn-123456].cn;
				break;
			}
			else   // S[i] is in some s[k]
			{
				k = S[i].bsn;
				S[i].bsn = S[k].bsn; // S[i].bsn = S[ S[i].bsn ].bsn; 
			}
		} while (true);

	}


	for(i=1; i<= old_m; i++)
	{
		S[i].bsn = S[i].tplNum;
		S[i].tplNum = 0;  //it has its own task, after here 
	}

lALL_EndTimer = GetTickCount()-lALL_StartTimer;
iALL_TickCount += lALL_EndTimer;

//---------ttest S[] start ----------
	//cstrMarc += " 2 2222----    ttest S[] ==== start \r\n";
	//cstrMarc += "\r\n";

    iclsNum =0;
	iallNum =0;

		for(j=1; j<=old_m; j++)
		{
			//if(S[j].cn == i)
			{
				sprintf(temp, " S[%02i].cn =%02i ,S[%02i].bsn =%02i;  ", j, S[j].cn,  j, S[j].bsn );
				//cstrMarc += temp;
				iclsNum ++;
			}	
			//cstrMarc += "\r\n";
		}
		sprintf(temp, "; iclsNum = %02i ", iclsNum);
		//cstrMarc += temp;
		iallNum = iallNum + iclsNum; 

		//cstrMarc += "\r\n";

		sprintf(temp, " iallNum = %02i ", iallNum);
		//cstrMarc += temp;
		//cstrMarc += "\r\n";
//---------ttest S[] end ----------


/////////////////////---------ttest S[] start ----------///////////////
	//cstrMarc += "\r\n";
	//cstrMarc += "\r\n";

    iclsNum =0;
	iallNum =0;

		//cstrMarc += "For S[i] ===================== ";
		//cstrMarc += "\r\n";
		//cstrMarc += "\r\n";

	for(i=1; i<= clsNum; i++)
	{
		iclsNum =0;


		sprintf(temp, "Cluster[%02i]: ", i);
		//cstrMarc += temp;
		//cstrMarc += "\r\n";

		for(j=1; j<=old_m; j++)
		{
			if(S[j].cn == i)
			{
				//sprintf(temp, " S[%02i],S[%02i].bsn =%02i;  ", j, j, S[j].bsn );
				//sprintf(temp, "S[%02i], ", j  );
				sprintf(temp, " S[%02i].cn =%02i ,S[%02i].bsn =%02i;  ", j, S[j].cn,  j, S[j].bsn );
				//cstrMarc += temp;
				iclsNum ++;
			}			
		}
		
		if(iclsNum >0)
		{
			//cstrMarc += "\r\n";
			sprintf(temp, "    iclsNum = %02i ", iclsNum);
			//cstrMarc += temp;
			iallNum = iallNum + iclsNum; 
			//cstrMarc += "\r\n";
		}

	}

   iZeroNum =0;
   sprintf(temp, "Cluster[%02i]: ", 0);

	for(j=1; j<=old_m; j++)
	{
		if(S[j].cn == 0)
		{
			//sprintf(temp, " S[%02i],S[%02i].bsn =%02i;  ", j, j, S[j].bsn );
			//sprintf(temp, "S[%02i], ", j  );
			sprintf(temp, " S[%02i].cn =%02i ,S[%02i].bsn =%02i;  ", j, S[j].cn,  j, S[j].bsn );
			//cstrMarc += temp;
			iZeroNum ++;
		}			
	}

		//cstrMarc += "\r\n";
		sprintf(temp, " iallNum NonZero = %02i ", iallNum);
		//cstrMarc += temp;
		//cstrMarc += "\r\n";
		sprintf(temp, " iZeroNum = %02i ", iZeroNum);
		//cstrMarc += temp;
		//cstrMarc += "\r\n";
		//cstrMarc += "\r\n";

///////////////////---------ttest S[] end ----------////////////


//////////////////////////////////////////////////////////////////////////////
//					Up to Now. Clustering is OK								//
//					select the tuples from each clustering scr				//
//////////////////////////////////////////////////////////////////////////////
	
//------------------------------------------------------------------------
//------------------------------------------------------------------------
lALL_StartTimer = GetTickCount();
/*
pApp->Qi=0; //see: how many queries are dealed with.

	int iMinTupleNum = 0;
	int iStart =0;
	//int iAllTuplesNum =0;
	int iInterIdx =0;
    iSum_TuplesCount =0;
	iSum_TickCount =0;
	iCandidateNum =0;
    ituples_cnt =0;
    //int S_Idx[101];

	//pApp->tuple = new ( TUPLE *[100 +1] ); //tuple[4][i]; the 4th Query , the ith tuples in S[4]					 
	pApp->tuple = new ( TUPLE *[WORKLOAD_NUM +1] ); //tuple[4][i]; the 4th Query , the ith tuples in S[4]					 
	
	pApp->tuple[0] = new TUPLE[2];  //tuple[0] means the scr_CLS of {S[j]}
    for(i = 1; i<=WORKLOAD_NUM; i++)
 	    pApp->tuple[i] = new TUPLE[2];  

	//scr[5][9] means the 5th scr , and its 9 tuple
	pApp->scr = new ( TUPLE *[clsNum +1] );  
	for(i = 0; i<=clsNum; i++)
			pApp->scr[i] = new TUPLE[2];

  */  

//-------------------- new code start ------------

	//scr[5][9] means the 5th scr , and its 9 tuple
 	
    for(i = 1; i<=pApp->clsNum; i++)
			delete [] pApp->scr[i];
	delete [] pApp->scr;
   
	delete [] pApp->scr_CLS ;  
	pApp->scr_CLS = new ZLRECT [WORKLOAD_NUM +1];    
		
	for(i = 0; i<WORKLOAD_NUM +1; i++) 
	{
	  memset(&(pApp->scr_CLS[i]), 0, sizeof(ZLRECT));
	}

   //-- scr_CLS[i].cn ==1 means it is not Empty:        NON_empty
   //-- scr_CLS[i].bsn = 3, means scr_CLS[i].bsn  is the SUBSET of scr_CLS[3]

	for(i = 1; i<=clsNum; i++) // there are clsNum scr's of cluster scr_CLS[1] to scr_CLS[clsNum]
	{
		if(scr_CLS[i].cn ==1)
		{
            pApp->scr_CLS[i] = scr_CLS[i];
			pApp->scr_CLS[i].bsn =0;
		}	
	}

    int iS_num_start =1;
	iZeroNum =0;
	for(i = 1; i<WORKLOAD_NUM +1; i++) 
	{
		if(i==1092)
			int tt=8;

		if(pApp->scr_CLS[i].cn ==0 ) 
		{
			for(j = iS_num_start; j<=old_m; j++)
			{
				if(S[j].cn == 0)
				{
                    pApp->scr_CLS[i] = S[j];
                    S[j].cn = i;
                    pApp->scr_CLS[i].cn =1;
                    pApp->scr_CLS[i].bsn =0;
                    iS_num_start = j+1;
					iZeroNum++;
					break;

				}
			}

		}
	}

	int old_clsNum = clsNum;
    clsNum = clsNum + iZeroNum;
	pApp->clsNum = clsNum;  // the number of all pApp-> clusters
    
	pApp->scr = new ( TUPLE *[clsNum +1] );  
	for(i = 0; i<=clsNum; i++)
			pApp->scr[i] = new TUPLE[2];

	//for(i = 1; i<=clsNum; i++)
		//pApp->scr_CLS[i].tplNum = 0;     //scr_CLS[i].tplNum is the size of tuples in  scr_CLS[i]
	
	//1. Search 1st NON_subset scr_CLS[i], let it be the start.
	for(i = 1; i<=clsNum; i++) // there are clsNum scr's of cluster scr_CLS[1] to scr_CLS[clsNum]
	{
		//if(scr_CLS[i].bsn ==1) changed it if(scr_CLS[i].cn ==1)
		//before 2005.5.22, scr_CLS[i].bsn ==1 means it is not empty
		//now scr_CLS[i].bsn means the Big Set Number of its superset.
		//i.e. scr_CLS[i].bsn =k means scr_CLS[i] is IN scr_CLS[k] 
		// this work has been done in above section
				//"Finding scr_CLS[i].bsn that save the index of its Supperset"
				// "say, scr_CLS[38].bsn = 36; means scr_CLS[38] is IN scr_CLS[36]"

		//for each scr_CLS[i], retrieve all tuples in it //2007.11.10
		//------
		//1.scr_CLS[i].cn ==1 means it is not Empty:        NON_empty
		//2. scr_CLS[i].bsn ==0 means it has not superset:  NON_subset
		//if(scr_CLS[i].cn ==1 && scr_CLS[i].bsn ==0) 
		if(pApp->scr_CLS[i].cn ==1 && pApp->scr_CLS[i].bsn ==0)  
		{
			strcpy(	szSql, 	" SELECT * FROM ");
			strcat(	szSql, 	TableName );
			strcat(	szSql, 	" where ( ( ");
				
				for(j=1; j<=COL_NUM-1; j++)
				{
					sprintf(temp, " %.15G <= attr%d AND attr%d <= %.15G ", pApp->scr_CLS[i].a[j],j-1,j-1, pApp->scr_CLS[i].b[j]);
					strcat(	szSql, temp	);
					strcat(	szSql, ") AND (" );
				}

				sprintf(temp, " %.15G <= attr%d AND attr%d <= %.15G ", pApp->scr_CLS[i].a[COL_NUM],COL_NUM-1,COL_NUM-1, pApp->scr_CLS[i].b[COL_NUM]);
				strcat(	szSql, temp	);
			strcat(	szSql, ") ) "	);

			//select tuples from scr_CLS[i]
			
			ituples_cnt = pApp->zlExeSelect_LRC(0, 0, szSql, pApp->scr_CLS, i);
			if(ituples_cnt <=0)
			{
				AfxMessageBox(" pApp->zlExeSelect_LRC err!");

					CFile file;
                    CString cstrMarc;
                    cstrMarc = szSql;
					if(file.Open("E:\\StreamQueryTEST\\szSql.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
				    {
					    file.Write(cstrMarc, cstrMarc.GetLength() +1 );
					}
				    file.Close();
		    
			}

			pApp->iSum_SCR_TuplesCount += ituples_cnt;
			pApp->scr_CLS[i].tplNum = ituples_cnt;
		}
	}

//-------------------- new code end ------------

//lALL_EndTimer = GetTickCount()-lALL_StartTimer;
//iALL_TickCount += lALL_EndTimer;


	        int itplIdx =0;
			char cID[581012];
			memset(cID,'\0',581012);
             
			for(l = 1; l<= pApp->clsNum; l++)
			{
				if(pApp->scr_CLS[l].tplNum >0)
				{

					for(i=1; i<=pApp->scr_CLS[l].tplNum ; i++)
					{
						if(cID[ (pApp->scr[l][i].ID) ] ==0)
						{
                             cID[ (pApp->scr[l][i].ID) ] = 1; //remove repeat tuples
						     itplIdx ++; //tpl's index is based 1
                             
						}
					}
				}
	
			}

			pApp->it_list_cnt = itplIdx;



//---------------   the algorithms --------------------
//---------------^^^^^^^^^^^^^^^^^^^^^^^^^^------------

	//zlCloseDB();

	//delete [] pApp->tuple[0];
	//for(i = 1; i<=WORKLOAD_NUM; i++)
 	    //delete [] pApp->tuple[i];  
	
	//delete [] pApp->tuple;         //causion: for scr_CLs[i]
	
	delete [] Sum_v_T;  //ok
	delete [] scr_CLS;  //ok

	//for(i = 1; i<=clsNum; i++)  
			//delete [] pApp->scr[i];
	//delete [] pApp->scr;

	delete [] T;    
    delete [] S ;
    delete [] part; 
	delete [] szSql;
	
	for(i= 0; i<=iPartNum; i++)
		delete [] index[i];

	delete [] index;

	//if( pApp->zlEndSQLservr() == FALSE )
       //AfxMessageBox(" pApp->zlEndSQLservr() Error !");

   AfxGetMainWnd ( ) -> SetWindowText (_T(" OK ") ); 


//// bodu end ////	


	//return bReturn;
   return pApp->clsNum;
    // return old_m;

}
//-- after memory = 512m--------- end --------------


//this function first RCM, Second do Naive Method and to High-dim and large size queires
bool CMainFrame::zlGetResults3To104D_C_N_HighLarge(int iCountOfQueries, char *InputTablename)
{   //2007.02.21

	bool bReturn =false;	
//// bodu end ////	
	return bReturn;
}
//-- after memory = 512m--------- end --------------


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////// for LRC    //////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////Code by Fengyanchao 2010////////////////////////////////
////////////////////////////////////////////Code by David 2018.6.27 //////////////////////////////////

void CMainFrame::OnMenuLRC()  // for get histogram
{
    bool bReturn = false;
    int old_m = 0;
	CLearnIing6App * pApp = (CLearnIing6App * ) AfxGetApp();
	
	//Set the text of dialog 
	//m_DataSetTable = pApp->TableName; //Census2D
	m_DataSetTable = "Attr_Census2D";//Add by david
	m_InsertTable =  pApp->szOutputTableName;
	m_KBProfileTable =pApp->szInputTableName;
	m_WorkloadTable = pApp->m_WorkloadTable;
	m_TopN = pApp->m_TopN;
    
	double r =0.0; // the search distance of top-N query
	double EPCINO = 0.000000000000001; //15_0
    int iDimention = COL_NUM;
	int iUpdateCluster = 0; //update the cluster per 100 time

	int i,j, ii,jj,k;
	int ituples_cnt =0;
	int frequence_Opt =0;

	/**************************************
	*  0. select all tuples from a given dataset
	*  1. partion the domain of the dataset
	*  2. get the histogram
	*  3. Select all queires from workload table 
	**************************************/
	char temp[1024] = "";

	int iSizeofWorkload =0;

	int iCStrLenth = 0;  // the lenth of a CString object
    int iSizeofKB = 0;
	int	rst_time =0;  
	int	r_time = 0;  
	int	candidate_time = 0;   
	int	top_N_time = 0;  
	int	total_time= 0;  
    int KB_time =0;
	bool bUpdateRC = true;
    //bool bfirst=false;
    //int  LearningP=0;
    //ZLRECT S; //the search n-square of Q 
    int n = COL_NUM;
	double VFactor;
	if(n==104)
		VFactor = 5.0 * pow(10, 37);
	else if(n==50)
		VFactor = pow(10, 34); // (30 +38)/2=34
	else if(n==25)
		VFactor = pow(10, 31); // (24 +38)/2=31


    //----------------  0. select all tuples from a given dataset----------------
	// Here  we use the function zlSelectAllFromKB that is a old version one, in order to easy 
	/////------ Call function: int zlSelectAllFromKB(char * KBTableName)	
    /////------ We get Z[i] that is the member variable in this Class 
	//		iCStrLenth = m_KBProfileTable.GetLength() + 1;		
	//		iSizeofKB  = zlSelectAllFromKB(m_KBProfileTable.GetBuffer(iCStrLenth) );
	
	//-- here use : m_DataSetTable
	iCStrLenth = m_DataSetTable.GetLength() + 1;		
	iSizeofKB  = zlSelectAllFromKB(m_DataSetTable.GetBuffer(iCStrLenth) );
    // here: iSizeofKB is the size of DB, not KB, for this program, //2009.2.14
	
	if( iSizeofKB <= 0)
	{
		AfxMessageBox(" ¾¯¸æ: Call zlSelectAllFromKB( ) Error !!!!!!");
	}
	else
	{
		//sprintf_s(temp, " 2. iSizeofKB = %i, Ticks = %i ", iSizeofKB, shortTicks);
		sprintf_s(temp, " zlSelect All tuples ,  iSizeofKB = %i", iSizeofKB);
		//AfxMessageBox(temp);
	}
//1. partion the domain of the dataset
//  division the biggest scr into 12 = 4*3 partition or more ----
//            select * From each partition,


	ZLRECT scr;  //This is the BIG scr that covers all tuples, i.e., the domian rect 
	int		iPartNum = 1;
	int m; //the number of all tuple in a relation  

	double dMin[COL_NUM+1]; 
	double dMax[COL_NUM+1];
        scr.v=1;
   // get domain rect
	for(i=1; i<=n; i++ )
	{
		scr.a[i] = pApp->dMin[i]; 
		scr.b[i] = pApp->dMax[i];  

		dMin[i] = pApp->dMin[i];
		dMax[i] = pApp->dMax[i];
         if(scr.b[i] > scr.a[i])
			scr.v *=  scr.b[i]-scr.a[i];
		
	}
	double  v1=scr.v;
       
//		scr.a[2] = 0; 
//		scr.b[2] =160000 ;


   // get tuples in domain, but we use the old struct, 
	
    m = iSizeofKB; // the size of DB
    ZLRECT * T = new ZLRECT[m+1]; /////this should be golable

	pApp->clsNum =0;

	for(i=1; i<=m; i++)
	{
		for(j= 1; j <=n; j++)
		{
			T[i].a[j] = Z[i-1].x[j-1]; 
			T[i].b[j] = Z[i-1].x[j-1];
		}

		T[i].cn = 0;
		T[i].bsn = 0;
		T[i].tplNum = Z[i].tid;
		T[i].suf1st=0;
	}
  int deepNum=1;

	if(n==2) //only for 2_dimensional
		iPartNum = pApp->zlPartion(scr, n, T, m, iPartNum);
	else	 //for 3,4, 25,50,and 104 dimensions
		iPartNum = pApp->zlPartion3D(&scr, n, T, m, iPartNum,deepNum);

//int s1=0,s2=0,f1=0,f2=0,f3=0;

//2. get the histogram
int Num=iPartNum;

int ss=0;

    ZLRECT * cell ; // ;
cell=CountCell( T, iPartNum, m, n);
int iTplNum = pApp->clsNum;
 iTplNum =0;
for(k=1; k<=iPartNum; k++)
{
     iTplNum = iTplNum + cell[k].cn;
	
}
//int m1=0;

for(i=1;i<=Num;i++)
{
	if(cell->cn>100)
	{
	for(j=1;j<=m;j++)
	{   
		
		if(T[j].bsn==i)
		{
			T[j].bsn=-1;
			 ss++;
			 T[j].suf1st=-1;
		}
	}
	deepNum=i;
    //m1=cell[i].cn;
	
	iPartNum = pApp->zlPartion3D(&cell[i], n, T, m, iPartNum,deepNum);

	}
}




/*    int j0 =0;
    for(j=1;j<=m;j++)
	{  
	   if(T[j].bsn<=0)
	   {  
		  
		   if((T[j].a[3]<=dMax[3])&&(T[j].a[3]>=40)&&(T[j].a[2]>=160000)&&(T[j].a[2]<=dMax[2]))
		   {
               T[j].bsn=iPartNum+1;
	         	   
    
		   }
           if((T[j].a[3]>=dMin[3])&&(T[j].a[3]<=40)&&(T[j].a[2]>=160000)&&(T[j].a[2]<=dMax[2])&&(T[j].bsn<=0))
		   {
               T[j].bsn=iPartNum+2;
			  
		   }
		   if((T[j].a[2]>=dMin[2])&&(T[j].a[2]<=0)&&(T[j].bsn<=0)&&(T[j].a[3]>=40))
		   {
			   T[j].bsn=iPartNum+3;
			
				
		   }
           if((T[j].a[2]>=dMin[2])&&(T[j].a[2]<=0)&&(T[j].bsn<=0)&&(T[j].a[3]<=10))
		   {
			   T[j].bsn=iPartNum+4;
			
				
		   }
           if((T[j].a[2]>=dMin[2])&&(T[j].a[2]<=0)&&(T[j].bsn<=0)&&(T[j].a[3]<=40)&&(T[j].a[3]>=10))
		   {
			   T[j].bsn=iPartNum+5;
			
				
		   }
	   }
   }



 //iPartNum+=5;
    
 delete []cell;
/*for(i=1; i<=iPartNum; i++)
	{
		memset(&cell[i], 0, sizeof(ZLRECT));
	//	memcpy(&cell[i], Rect, sizeof(ZLRECT));
}*/
	cell=CountCell( T, iPartNum, m, n);
///////////
     

//--***debug****
//int iTplNum = pApp->clsNum;
  iTplNum =0;
for(k=1; k<=iPartNum; k++)
{
     iTplNum = iTplNum + cell[k].cn;
}
//--***debug****

//3. Select all queires from workload table 

////^^^^^^^
// 2.-----------  Select all queires from workload table ---------------
	//-----   Call function: int zlSelectAllFromWorkload(char * )
	// We get all queries in the workload:	Q[i], i=0,1, 2, ..., 9999

	iCStrLenth		= m_WorkloadTable.GetLength() + 1;
    iSizeofWorkload = zlSelectAllFromWorkload(m_WorkloadTable.GetBuffer(iCStrLenth) );

	if( iSizeofWorkload <= 0)
    {
		AfxMessageBox(" Call zlSelectAllFromWorkload Error !!!!!!");
	}
	else
	{
		sprintf_s(temp, " iSizeofWorkload = %i", iSizeofWorkload);
		AfxMessageBox(temp);
	}

   int	iEstimateNum=0;
   int	ituples_count=0;
  
//      iPartNum=LearningHD(iPartNum,T,n,m,&cell);
	
		 
		  
 //        cell=CountCell( T, iPartNum, m, n);

 //  int iTplNum = pApp->clsNum;
 iTplNum =0;
for(k=1; k<=iPartNum; k++)
{
    iTplNum = iTplNum + cell[k].cn;
}   


  int CircleNum,j1;
      if (n>4)
	  {
			CircleNum=2;
	  }
      else
	  {
			CircleNum=1;
	  }



  for (j1=1;j1<=CircleNum;j1++)
	{
	  for(i=1000; i<iSizeofWorkload; i++)  //1207 //iNumUpdateKB =902; 
	  {
       
		pApp->case1 = 0;
        pApp->iIO_Num ++;
		rst_time =0;  
		r_time = 0;  
		candidate_time = 0;   
		top_N_time = 0;  
		total_time= 0;  
        KB_time =0;

		Q[i].ante_SizeKB = 0 ; //iRowCnt_KBP;
        total_time = GetTickCount();  

//----------------- 3. get Selectivity Number for each query
        //--- call function: zlObtainSelectivityNum(int iQueryNum)
        		//shortTicks = GetTickCount();
        
		//r_time = GetTickCount();  
		//r = (int) zlObtainSelectivityNum(Q[i], i);  /// HERE r means iEstimateNum, that is, the Selectivity Number
        //r_time = GetTickCount() - r_time;  
        
       iEstimateNum = 0;
     int f_first = 0, f_rst =0;
     int f_Opt = 0;

     if ( n<=4)
	 {

     for(k=1; k<=iPartNum; k++)
	 {
		iEstimateNum += zlGettheIntersection(&cell[k], Q[i], n);
	 }
      
        //???? iEstimateNum = cell[k].cn * ( v(Q[i] ^ cell[k]) /cell[k].v)


//----------------- 4. Get candidate set for S of the query
        //  Like the Naive method 
	 
	
		 candidate_time = GetTickCount(); 
          ituples_cnt = zlExeSelect(Q[i]);
         candidate_time = GetTickCount() - candidate_time; 
		 f_Opt = ituples_cnt;
	
	 }else 
	 {
		 if(j1==1)

		 {
			 for(k=1; k<=iPartNum; k++)
			 {
				iEstimateNum += zlGettheIntersection(&cell[k], Q[i], n);
			 }

        //???? iEstimateNum = cell[k].cn * ( v(Q[i] ^ cell[k]) /cell[k].v)


//----------------- 4. Get candidate set for S of the query
        //  Like the Naive method 
	 
		 }else
		 {
		 candidate_time = GetTickCount(); 
          ituples_cnt = zlExeSelect(Q[i]);
         candidate_time = GetTickCount() - candidate_time;
          f_Opt=ituples_cnt;

         }

	 }

	   top_N_time = GetTickCount();
 

	//	top_N_time = GetTickCount() - top_N_time;
    //    total_time = GetTickCount() - total_time;  

		//------------- 5'. for unforgetten, Insert new Z into KB Profile
		//------------- 5'. for forgettable , we update the KB Profile
		///------------ , which including, Insert new Z, or raplace old one that priority is lowwest by new one
	   
	   KB_time = GetTickCount();

       KB_time = GetTickCount()- KB_time;
       

	    //--------------6. Insert the result into the table
		//---need add: (1) iIO_Num, (2) sum of size of tuples in all SCR, i.e., pApp->iSum_SCR_TuplesCount
        //--- (3)??

        // Call function: zlExeInsertTable()
        CString cStrInsert;
        cStrInsert.Empty();
        //char InsertValue[512];

///////////////////////////////
				       //shortTicks = GetTickCount();
        int est =INT(581010*(v/v1));
		char	cAttribute[COL_NUM+19+4+3][50];
		for(ii=0; ii<COL_NUM + 19+4+3; ii++)
			for(jj=0; jj< 50; jj++)
				cAttribute[ii][jj]=0;

		for(ii=0; ii<COL_NUM ; ii++)
			sprintf_s(cAttribute[ii],	"%G", Q[i].x[ii] );

	    sprintf_s(cAttribute[COL_NUM],  "%ld", m_TopN);
		sprintf_s(cAttribute[COL_NUM+1],"%.15G",  Q[i].r);    
	
		sprintf_s(cAttribute[COL_NUM+2],"%ld",  Q[i].f);

		sprintf_s(cAttribute[COL_NUM+3],"%ld", Q[i].f_rst ); //--2007.12.05
		sprintf_s(cAttribute[COL_NUM+4],"%ld", rst_time);   //--2007.12.05
        
		
		sprintf_s(cAttribute[COL_NUM+5],"%ld", iEstimateNum);    // r_time       //change 2007.11.05
		sprintf_s(cAttribute[COL_NUM+6],"%ld", iPartNum);    //change 2007.11.05

		sprintf_s(cAttribute[COL_NUM+7],"%ld", est);  //add   2007.11.05
		sprintf_s(cAttribute[COL_NUM+8],"%ld", total_time);  //add   2007.11.05
		sprintf_s(cAttribute[COL_NUM+9],"%ld", KB_time);     //add   2007.11.05

		sprintf_s(cAttribute[COL_NUM+7+3],"%ld",   Q[i].ID);
		sprintf_s(cAttribute[COL_NUM+8+3],"%.15G", Q[i].r_Opt);
		
		sprintf_s(cAttribute[COL_NUM+9+3],"%ld",  f_Opt);   //the real number

		sprintf_s(cAttribute[COL_NUM+10+3],"%ld", Q[i].ante_SizeKB);
		sprintf_s(cAttribute[COL_NUM+11+3],"%ld", Q[i].post_SizeKB);
		sprintf_s(cAttribute[COL_NUM+12+3],"%ld", Q[i].increment);
	
		sprintf_s(cAttribute[COL_NUM+13+3],"%ld", pApp->case1);

		sprintf_s(cAttribute[COL_NUM+14+3],"%ld", Q[i].case2a);
		sprintf_s(cAttribute[COL_NUM+15+3],"%ld", Q[i].case2b);
		sprintf_s(cAttribute[COL_NUM+16+3],"%ld", Q[i].adjust_case2a);
		sprintf_s(cAttribute[COL_NUM+17+3],"%ld", Q[i].restart);
		
        sprintf_s(cAttribute[COL_NUM+18+3],"%ld", iNumUpdateKB);
        sprintf_s(cAttribute[COL_NUM+18+3+1],"%ld", pApp->iIO_Num); //add. 2007.11.15
        sprintf_s(cAttribute[COL_NUM+18+3+2],"%ld", pApp->iSum_SCR_TuplesCount); //add. 2007.11.15
		sprintf_s(cAttribute[COL_NUM+19+3+3],"%ld", i+1); //add 2007.11.05 , Qnum

/////////////////////////////



		cStrInsert = " INSERT ";
		cStrInsert += m_InsertTable; 
		cStrInsert += " VALUES (";
       

		//for(j=0; j< COL_NUM+19-1; j++)
		for(j=0; j< COL_NUM+19+4+2-1; j++)  ////change 2007.11.05 
		{
			cStrInsert += cAttribute[j];
			cStrInsert += ",";
		}
		cStrInsert += cAttribute[COL_NUM+19+4+2];   //add 2007.11.05 , Qnum

		cStrInsert += " ) ";

		int istrSelectLenth = cStrInsert.GetLength() + 1;

		bReturn = pApp->zlExeInsertTable(cStrInsert.GetBuffer(istrSelectLenth) );			
       
		if(bReturn)
		{
			//Sleep(100);//AfxMessageBox("pApp->zlExeInsertTable ---- OK !");
		}
		else
		{			CFile file;
                    CString cstrMarc;
                    cstrMarc = cStrInsert;
					if(file.Open("E:\\StreamQueryTEST\\cStrInsert.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
				    {
					    file.Write(cstrMarc, cstrMarc.GetLength() +1 );
					}
				    file.Close();

			AfxMessageBox("OnMLRC, pApp->zlExeInsertTable ---- ERROR !!!!!");
		
		}
			//shortTicks = GetTickCount() - shortTicks;
	
	  }

    //delete [] szSql;
	///----------- body end ---------------

////^^^^^^^

  if(j1==1)
  {
    delete [] cell; //this should be golable
    delete [] T; //this should be golable
  }
}
   	AfxMessageBox("OnMenuLRC OK OK OK !!!!");
}


void CMainFrame::OnMenuLRC_old() //this is old, not used for selectivy
{
    bool bReturn = false;
    int old_m = 0;
	CLearnIing6App * pApp = (CLearnIing6App * ) AfxGetApp();
	
	m_DataSetTable = pApp->TableName; 
	m_InsertTable =  pApp->szOutputTableName;
	m_KBProfileTable =pApp->szInputTableName;
	m_WorkloadTable = pApp->m_WorkloadTable;
	m_TopN = pApp->m_TopN;
    
	//int iCStrLenth = 0;  // the lenth of a CString object
	//char temp[1024] = "";
	double r =0.0; // the search distance of top-N query
	double EPCINO = 0.000000000000001; //15_0
    int iDimention = COL_NUM;
	int iUpdateCluster = 0; //update the cluster per 100 time
	//char * szSql = new char[8092000];
	//strcpy(szSql, "");

	//int longTicks =0, shortTicks =0;
	//int shortTicks_rst = 0; //2003/4/5

	int i,j, ii,jj;
	//int iSizeofWorkload =0;
	//int iSizeofKB = 0;
	int ituples_cnt =0;
	int frequence_Opt =0;

	/************************
	*  0. select all profile from KB P
	*  1. cluster profile regions in KB P
	*  2. Select all queires from workload table
	*  For each query
	*  3. get search distance r for each query
	*  4. Get candidate set for S of the query
	*  5. Get top-N tuples from the candidate set
	*  //6. Select all from the dataset ?? // No useful in this case
	*  6. Insert the result into the table	
	*  7 maintain KB, and Buffer

	*	m_DataSetTable = TableName.m_DataSetTable;
	*	m_InsertTable = TableName.m_InsertTable;
	*	m_KBProfileTable = TableName.m_KBProfileTable;
	*	m_WorkloadTable = TableName.m_WorkloadTable;
	*	m_TopN = TableName.m_TopN;
	\**************************/

	//shortTicks = GetTickCount();
      //.....
	//shortTicks = GetTickCount() - shortTicks;
	
	char temp[1024] = "";

	int iSizeofWorkload =0;

	int iCStrLenth = 0;  // the lenth of a CString object
    int iSizeofKB = 0;
	int	rst_time =0;  
	int	r_time = 0;  
	int	candidate_time = 0;   
	int	top_N_time = 0;  
	int	total_time= 0;  
    int KB_time =0;
	bool bUpdateRC = true;

    ZLRECT S; //the search n-square of Q 
    int n = COL_NUM;
	double VFactor;
	if(n==104)
	  VFactor = 5.0 * pow(10, 37);
	else if(n==50)
	  VFactor = pow(10, 34); // (30 +38)/2=34
	else if(n==25)
	  VFactor = pow(10, 31); // (24 +38)/2=31


//0. ----------------  0. select all profile from KB P
	//--- call function: int zlSelectAllFromKB(char * KBTableName)	
    //--- we get Z[i] that is the member variable in this Class 
	iCStrLenth = m_KBProfileTable.GetLength() + 1;		
	iSizeofKB  = zlSelectAllFromKB(m_KBProfileTable.GetBuffer(iCStrLenth) );
	if( iSizeofKB <= 0)
	{
		AfxMessageBox(" Call zlSelectAllFromKB Error !!!!!!");
	}
	else
	{
		//sprintf_s(temp, " 2. iSizeofKB = %i, Ticks = %i ", iSizeofKB, shortTicks);
		sprintf_s(temp, " zlSelectAllFromKB,  iSizeofKB = %i", iSizeofKB);

		AfxMessageBox(temp);
	}
// 1.----------------  1. cluster profile regions in KB P,and retrieve tuples in SCR
    // call function: bool zlGetResults3To104D_C_N(int iCountOfQueries, char *InputTablename)
	// iCountOfQueries is the number of rectangles, 
	// InputTablename  is the Profile talbe name in old Miltiple queries   
	// call function:  zlClusterProfileRegions(int iCountOfQueries, char *DatasetTableName)
   	// zlClusterProfileRegions: 
	pApp->iSum_SCR_TuplesCount = 0;
	iCStrLenth = m_KBProfileTable.GetLength() + 1;		
	old_m = zlClusterProfileRegions(iSizeofKB, m_KBProfileTable.GetBuffer(iCStrLenth));

	//sprintf_s(temp, " zlClusterProfileRegions, old_m = %i", old_m );
	sprintf_s(temp, " zlClusterProfileRegions, pApp->clsnum = %i", old_m );

	AfxMessageBox(temp);

// 2.-----------  Select all queires from workload table ---------------
	//-----   Call function: int zlSelectAllFromWorkload(char * )
	// We get all queries in the workload:	Q[i], i=0,1, 2, ..., 9999
	iCStrLenth		= m_WorkloadTable.GetLength() + 1;
    iSizeofWorkload = zlSelectAllFromWorkload(m_WorkloadTable.GetBuffer(iCStrLenth) );

	if( iSizeofWorkload <= 0)
    {
		AfxMessageBox(" Call zlSelectAllFromWorkload Error !!!!!!");
	}
	else
	{
		sprintf_s(temp, " iSizeofWorkload = %i", iSizeofWorkload);
		AfxMessageBox(temp);
	}

    //--- set max memery ----


	//iNumUpdateKB = 4906;  //4981;   //1533;   //1753; //0; 
    //             //Gau3D  Arr3D    Cen3D   Cen2D     Cov4D
	
	iNumUpdateKB =0; 
    //ZLRECT S; //the search n-square of Q  
	//*  For each query

	//iNumUpdateKB = 3494;
	//pApp->iIO_Num = 21804381;
    //pApp->iSum_SCR_TuplesCount = 397036;

    //for(i=0; i<100; i++)
	for(i=0; i<iSizeofWorkload; i++)  
	//for(i=2594; i<iSizeofWorkload; i++)  //1207 //iNumUpdateKB =902; 
	{
		//if(i==1445)
			//int isahf=0;
		//if(i==2594)
			//int isahef=0;

		rst_time =0;  
		r_time = 0;  
		candidate_time = 0;   
		top_N_time = 0;  
		total_time= 0;  
        KB_time =0;
        iGetTopNTupleTime =0;

		Q[i].ante_SizeKB = iRowCnt_KBP;
        total_time = GetTickCount();  

	    //----------------- 3. get search distance for each query
        //--- call function: zlObtainSearchDistance(QUERY Query, int iQueryNum)
        		//shortTicks = GetTickCount();
        
		r_time = GetTickCount();  
		r = zlObtainSearchDistance(Q[i], i);
        r_time = GetTickCount() - r_time;  


		//----------------- 4. Get candidate set for S of the query
        //  Like the Naive method 

        candidate_time = GetTickCount(); 
		
		int f_first = 0, f_rst =0;
		if(Q[i].case1 == 1 && Zprime.cn > 0 )
		{
			//Q = Q[i];
		//-------------------------
			for(j= 1; j <=n; j++)
			{
				S.a[j] = Q[i].x[j-1] - r ; 
				if(S.a[j] < pApp->dMin[j])
					S.a[j] = pApp->dMin[j];

				S.b[j] = Q[i].x[j-1] + r; 
				if(S.b[j] > pApp->dMax[j])
					S.b[j] = pApp->dMax[j];
			}
			S.v =1;
			if(n < 25)
			{
				for(j=1; j<=n; j++)
				{
					S.v *= (S.b[j]-S.a[j]);
				}
			}
			else
			{
				for(j=1; j<=n; j++)
				{
					S.v *= ( (S.b[j]-S.a[j])/VFactor );
				}
				
			}
		   //-----------------

			S.bsn =  Zprime.cn;
			pApp->scr_CLS[0] = S;
			ituples_cnt= pApp->zlGet_S_ScrTuple_LRC(pApp->scr_CLS, 0); //---pApp->tpl[i] is based 1
			memset(&(pApp->scr_CLS[0]),0, sizeof(ZLRECT));

		}
		else
		{
		   ituples_cnt = pApp->zlGetCandidateSet(Q[i], r); //(QUERY Query, double r)
		}
  
		f_first = ituples_cnt;
		Q[i].f = ituples_cnt;

		if(ituples_cnt >= m_TopN)
		{
			//f_first = ituples_cnt;
			//Q[i].f = ituples_cnt;
			Q[i].r = r;
		}
		else
		{ // restart; recompute the search distance
		    rst_time = GetTickCount();  	
			r = Zprime.dis_Q_Qp + Zprime.r; 
			Q[i].r = r;
			Q[i].restart = 1;
			//Q[i].increment = 1;
		
			ituples_cnt = pApp->zlExeSelectQ_r_LRC(Q[i], r);

			if(ituples_cnt >= m_TopN)
			{   
				f_rst = ituples_cnt;
				Q[i].f = ituples_cnt;
				Q[i].r = r;
			}
			else if (iDimention > 24 )
			{
				bAddEP = true;
				char cDblToStr[1024] = "";
				sprintf_s(cDblToStr,"%.0f",  r);

		        int ilen = strlen(cDblToStr);

				r = r + EPCINO* pow(10, (ilen-1) );

			    ituples_cnt =  pApp->zlExeSelectQ_r_LRC(Q[i], r);
				f_rst = ituples_cnt;
				Q[i].f = ituples_cnt;
				Q[i].r = r;
				 //sprintf_s(temp, " recompute the search distance Error !! ituples_cnt = %i", ituples_cnt);
				 //AfxMessageBox(temp);
			}


            /*
			else
			{
				double dConst = pow(iTopN/pPf104D[0].N, 1.0/COL_NUM);
				//rd = r[0] + rOrder[0]* dConst;
				int ih = (int)iTopN/pPf104D[0].N;
				ih = ih/2;
				rd = r[ih] + rOrder[ih]* dConst;

			}
			*/
          	rst_time = GetTickCount() - rst_time;  

		}

       candidate_time = GetTickCount() - candidate_time;   


	    //------------- 5.Get top-N tuples from the candidate set 
        // Call funtion: zlGetTopNTuple(i, ituples_cnt);				
				//shortTicks = GetTickCount();
	    //pApp->tpl[i] is based 1,  but CMainFrame->tpl[i] is based 0
	  	delete [] tpl;
		tpl = new TUPLE[ituples_cnt+1];

		for(ii = 0; ii<ituples_cnt; ii++)
		{
			for(jj = 0; jj<COL_NUM; jj++)
				tpl[ii]. x[jj] = pApp->tpl[ii+1].x[jj+1];

			tpl[ii].d = pApp->tpl[ii+1].d;
			tpl[ii].num = pApp->tpl[ii+1].num;
			tpl[ii].ID = pApp->tpl[ii+1].ID;
			tpl[ii].bIN = pApp->tpl[ii+1].bIN;
			tpl[ii].d_max = pApp->tpl[ii+1].d_max;			
		}
 
	   //top_N_time = GetTickCount();
 
		frequence_Opt = zlGetTopNTuple(i, ituples_cnt);	
        Q[i].f_Opt = frequence_Opt;
		       //shortTicks = GetTickCount() - shortTicks;

		//-- test 
		//sprintf_s(temp, " 5.  frequence_Opt = %i, Ticks = %i ", frequence_Opt, shortTicks);
		//AfxMessageBox(temp);
       //-- test 
       //top_N_time = GetTickCount() - top_N_time;
	   top_N_time = iGetTopNTupleTime;

       total_time = GetTickCount() - total_time;  

		//------------- 5'. for unforgetten, Insert new Z into KB Profile
		//------------- 5'. for forgettable , we update the KB Profile
		///------------ , which including, Insert new Z, or raplace old one that priority is lowwest by new one
	   
	   KB_time = GetTickCount();
	   ///**************
	   if(  (Q[i].case2b >0) || (Q[i].restart >0) )
		{  
			if(iRowCnt_KBP < THRESHOLD_KB)
				bReturn = zlInsertKBProfile( Q[i]);
			else
				bReturn = zlUpdateKBProfile( Q[i]);	
			
			if(bReturn)
			{
				Q[i].increment = 1;
				iNumUpdateKB ++;
				iUpdateCluster ++;
			}
			//

	   }  
		//if( iRowCnt_KBP == (Q[i].ante_SizeKB + Q[i].increment ) )
		Q[i].post_SizeKB = iRowCnt_KBP;
		//**********/
        KB_time = GetTickCount()- KB_time;
       
		///*******************
        if(iRowCnt_KBP < THRESHOLD_KB)
		{
			if( (iRowCnt_KBP <= 200 && iUpdateCluster >=50) || iUpdateCluster >=200  )
			{
				//---set memory -----
				pApp->iSum_SCR_TuplesCount = 0;
				iCStrLenth = m_KBProfileTable.GetLength() + 1;		
				old_m = zlClusterProfileRegions(iRowCnt_KBP, m_KBProfileTable.GetBuffer(iCStrLenth));
				if(old_m >0 )
				  iUpdateCluster = 0;
			}

		}
		else if( bUpdateRC )
		{
             bUpdateRC =false;
			 pApp->iSum_SCR_TuplesCount = 0;
			 iCStrLenth = m_KBProfileTable.GetLength() + 1;		
			 old_m = zlClusterProfileRegions(iRowCnt_KBP, m_KBProfileTable.GetBuffer(iCStrLenth));
		}
        //*************/
        

	    //--------------6. Insert the result into the table
		//---need add: (1) iIO_Num, (2) sum of size of tuples in all SCR, i.e., pApp->iSum_SCR_TuplesCount
        //--- (3)??

        // Call function: zlExeInsertTable()
        CString cStrInsert;
        cStrInsert.Empty();
        //char InsertValue[512];

///////////////////////////////
				       //shortTicks = GetTickCount();

		char	cAttribute[COL_NUM+19+4+3][50];
		for(ii=0; ii<COL_NUM + 19+4+3; ii++)
			for(jj=0; jj< 50; jj++)
				cAttribute[ii][jj]=0;

		for(ii=0; ii<COL_NUM ; ii++)
			sprintf_s(cAttribute[ii],	"%G", Q[i].x[ii] );

		sprintf_s(cAttribute[COL_NUM],  "%ld", m_TopN);
		sprintf_s(cAttribute[COL_NUM+1],"%.15G",  Q[i].r);
		sprintf_s(cAttribute[COL_NUM+2],"%ld", f_first);

		if(f_rst > 0)
		{
			sprintf_s(cAttribute[COL_NUM+3],"%ld", f_rst );
			sprintf_s(cAttribute[COL_NUM+4],"%ld", rst_time);
			f_rst = 0;
		}else
		{
			sprintf_s(cAttribute[COL_NUM+3],"NULL");
			sprintf_s(cAttribute[COL_NUM+4],"NULL");

		}
		//sprintf_s(cAttribute[COL_NUM+5],"%ld", shortTicks);
		//sprintf_s(cAttribute[COL_NUM+6],"%ld", longTicks);
		sprintf_s(cAttribute[COL_NUM+5],"%ld", r_time);            //change 2007.11.05
		sprintf_s(cAttribute[COL_NUM+6],"%ld", candidate_time);    //change 2007.11.05

		sprintf_s(cAttribute[COL_NUM+7],"%ld", top_N_time);  //add   2007.11.05
		sprintf_s(cAttribute[COL_NUM+8],"%ld", total_time);  //add   2007.11.05
		sprintf_s(cAttribute[COL_NUM+9],"%ld", KB_time);     //add   2007.11.05

		sprintf_s(cAttribute[COL_NUM+7+3],"%ld",   Q[i].ID);
		sprintf_s(cAttribute[COL_NUM+8+3],"%.15G", Q[i].r_Opt);
		sprintf_s(cAttribute[COL_NUM+9+3],"%ld",  Q[i].f_Opt);
		sprintf_s(cAttribute[COL_NUM+10+3],"%ld", Q[i].ante_SizeKB);
		sprintf_s(cAttribute[COL_NUM+11+3],"%ld", Q[i].post_SizeKB);
		sprintf_s(cAttribute[COL_NUM+12+3],"%ld", Q[i].increment);
		sprintf_s(cAttribute[COL_NUM+13+3],"%ld", Q[i].case1);
		sprintf_s(cAttribute[COL_NUM+14+3],"%ld", Q[i].case2a);
		sprintf_s(cAttribute[COL_NUM+15+3],"%ld", Q[i].case2b);
		sprintf_s(cAttribute[COL_NUM+16+3],"%ld", Q[i].adjust_case2a);
		//sprintf_s(cAttribute[COL_NUM+17+3],"%ld", Q[i].restart);
		//iNumUpdateKB, this is a new one; add col in the table 
        //sprintf_s(cAttribute[COL_NUM+18+3],"%ld", iNumUpdateKB);
        //-- new use for this 2 col
		sprintf_s(cAttribute[COL_NUM+17+3],"%ld", pApp->clsNum);
        sprintf_s(cAttribute[COL_NUM+18+3],"%ld", pApp->it_list_cnt);

        sprintf_s(cAttribute[COL_NUM+18+3+1],"%ld", pApp->iIO_Num); //add. 2007.11.15
        sprintf_s(cAttribute[COL_NUM+18+3+2],"%ld", pApp->iSum_SCR_TuplesCount); //add. 2007.11.15
		sprintf_s(cAttribute[COL_NUM+19+3+3],"%ld", i+1); //add 2007.11.05 , Qnum

/////////////////////////////



		//	sprintf_s(InsertValue, "(%i,%i,%f,%f,%i,%i,%i,%i,%i,NULL,%i,%i,%i,%i,%f,%f,%f,%f)",
		//		     m, iModle, CETA, c2, iSum_TuplesCount, iALL_TickCount, (iALL_TickCount-iSum_TickCount), iSearchZero, (iCLSsearch+iSearchZero),
		//			 N_Tuple, N_ALLTick, N_ExtraTick,N_IO_Num,
		//			 C_Ex_All_Tick, C_N_Tuple, C_N_ALLTick, C_N_IO_Num);

		cStrInsert = " INSERT ";
		cStrInsert += m_InsertTable; 
		cStrInsert += " VALUES (";
        //cStrInsert += InsertValue;


		//for(j=0; j< COL_NUM+19-1; j++)
		for(j=0; j< COL_NUM+19+4+2-1; j++)  ////change 2007.11.05 
		{
			cStrInsert += cAttribute[j];
			cStrInsert += ",";
		}
		cStrInsert += cAttribute[COL_NUM+19+4+2];   //add 2007.11.05 , Qnum

		cStrInsert += " ) ";

		int istrSelectLenth = cStrInsert.GetLength() + 1;

		bReturn = pApp->zlExeInsertTable(cStrInsert.GetBuffer(istrSelectLenth) );			
       
		if(bReturn)
			;//AfxMessageBox("pApp->zlExeInsertTable ---- OK !");
		else
			AfxMessageBox("OnMLRC, pApp->zlExeInsertTable ---- ERROR !!!!!");
		 //shortTicks = GetTickCount() - shortTicks;

		//-- test 
		//sprintf_s(temp, " 6.  zlExeInsertTable Ticks = %i ", shortTicks);
		//AfxMessageBox(temp);
       //-- test 

		//longTicks =  GetTickCount() - longTicks;

       //-- test 
		//sprintf_s(temp, " All  Ticks = %i ", longTicks);
		//AfxMessageBox(temp);
       //-- test 
	
	  }

    //delete [] szSql;
	///----------- body end ---------------
   	AfxMessageBox("OnMenuLRC OK OK OK !!!!");

}

int CMainFrame::zlSelectAllFromKB(char *KBTableName)
{
	AfxMessageBox("½øÈëº¯Êý zlSelectAllFromKB!");
	/*
	if(!zlOpenDB())
	{
		AfxMessageBox("zlOpenDB() err!");
		//zlCloseDB();
	}
    */
	int iRowCnt = -1;
    int iTupleNum;

	double  fCol[COL_NUM+1];		//Elevation
	SDWORD cbCol[COL_NUM+1]; 	
	SDWORD sColID =0; 
	SDWORD cbColID =0; 
	int iQryIdx = 0;
	char tmp[512];
	int i;

	SDWORD sN,		sf,sc,sd;
	SDWORD cbN,cbr,cbf,cbc,cbd;
	double		sr;


	/////////////////////////////////////////////////////
	SQLFreeStmt(hstmt, SQL_DROP);
	retcode = SQLAllocStmt(hdbc, &hstmt); ///Statement handle 
	if(retcode != SQL_SUCCESS)
		return -1;

	SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
	SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
	
	char szLocalSql[2048] = ""; 
	strcpy(szLocalSql, "SELECT * FROM ");	
	strcat(szLocalSql, KBTableName);	

	retcode = SQLExecDirect(hstmt, (unsigned char *)szLocalSql, SQL_NTS);  //2005.02.07
	//retcode = SQLExecDirect(hstmt, (unsigned char *)szSql, SQL_NTS);  //2005.02.07
			
	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
	{  //	retcode = SQLExecDirect

		int iRowCount;
		SDWORD *  RowCountPtr = new SDWORD ;
		retcode = SQLRowCount(hstmt, RowCountPtr);						 
		iRowCount = * RowCountPtr;
		delete RowCountPtr;
		iRowCnt = iRowCount;
		iTupleNum = iRowCount;

        iRowCnt_KBP = iRowCount;//this is the Row Count of KB profile table

		if(iRowCnt <=0)
			return iRowCnt;

		delete [] Z;
        Z = new ProfileMP[iRowCount+1];

		for( i = 0; i <COL_NUM+1; i++)
		{
			fCol[i] =0.0;
			cbCol[i] = 0; 
		}
		// Bind columns 1,2,3,4 ,.., COL_NUM
			for(i = 0; i <COL_NUM; i++)
					SQLBindCol(hstmt, i+1, SQL_C_DOUBLE, &fCol[i],0, &cbCol[i]); //SQL_C_SSHORT			
		
		  SQLBindCol(hstmt, COL_NUM+1, SQL_C_SLONG, &sN,0, &cbN); // here is tid

			//SQLBindCol(hstmt, COL_NUM+1, SQL_C_SLONG, &sN,0, &cbN); //SQL_C_SSHORT
			//SQLBindCol(hstmt, COL_NUM+2, SQL_C_DOUBLE, &sr,0, &cbr); //SQL_C_SSHORT
			//SQLBindCol(hstmt, COL_NUM+3, SQL_C_SLONG, &sf,0, &cbf); //SQL_C_SSHORT
			//SQLBindCol(hstmt, COL_NUM+4, SQL_C_SLONG, &sc,0, &cbc); //SQL_C_SSHORT
			//SQLBindCol(hstmt, COL_NUM+5, SQL_C_SLONG, &sd,0, &cbd); //SQL_C_SSHORT
					
		iRowCount =0;

		while (TRUE) 
		{
			retcode = SQLFetch(hstmt);

			if (retcode == SQL_ERROR)
			{
				//show_error();
				wsprintf(tmp, "%ld", iRowCount);
				//int i = iRowCount;
				AfxMessageBox("SQLFetch Error !!!!!!");
						//break; //99.8.26
			}

			if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
			{
					for(i = 0; i<COL_NUM; i++)
					{
						Z[iQryIdx].x[i] = fCol[i];						
					}
					
					Z[iQryIdx].tid		= sN;
					//Z[iQryIdx].N		= sN;
					//Z[iQryIdx].r		= (float) sr;
					//Z[iQryIdx].f		= sf;
					//Z[iQryIdx].c		= sc;
					//Z[iQryIdx].d		= sd;

                   iQryIdx++;
				
				if(retcode == SQL_SUCCESS_WITH_INFO)
				{
					wsprintf(tmp, "%ld", retcode);
					AfxMessageBox(tmp);
				}
					
			} 
			else 
			{
				break;
			}

		}   ///while (TRUE)

	}

	//zlCloseDB();
	//----- body-----------------	
	return iRowCnt;

}

/********************
	Now, suppose P = { 1,  2, ¡­,  m}, m   1. Find out all profiles in P with Ni   fi < 2Ni, 
	denote {  1,   2, ¡­,   m0}, m0   m, and {S(Qi, ri), i = 1, ¡­, m0} are corresponding 
	profile regions.  Using the region clustering strategy in [], cluster the 
	regions {S(Qi, ri), i = 1, ¡­, m0},  we obtain the set of clusters {?i, i= 1, 2, ¡­, M}
	where M   m0. Then, for each cluster ?i, build its smallest containing region 
	SCRi = SCR(?i),  denote  ¦® = {SCR1 , SCR2, ¡­, SCRM}. Let   i. cn := k 
	if its profile regions is contained in SCRk . P and ¦® will be stored in main memory. 
	For each region SCRi , Retrieve all tuples in scr[i] it and save them in meory. 

*********************/


bool CMainFrame::zlClusterProfileRegions1(int iCountOfQueries, char *DatasetTableName)
{
   ///------------
	bool bReturn = false;

	int m; //the number of rectangles 
    m = iCountOfQueries;
	int old_m = m;
	int m_T;  //the number of {T[i]}

	int n = COL_NUM; //2; ...	104;   //the dimensions of space
	double Totall_v =0.0; // Totall_v = v(U Si )
	int i, j;
	int iTableSize =0;

	double CETA = 1; //1;  //10; // the threshold for Sum_Cluster

	int SEC = 2; //= 21; // SECTION, for the T-S, that is the algorithm 
	                     //The Difference of Two Regions (DTR), i.e., pApp->zlDiffRects
	if(n==104)
	{
		//SEC = 2; //2; //5; //9 ;
		CETA = 1; //3; //2
	}
	else if(n==50)
	{
		//SEC = 21;
		CETA =1;
	}
	else if(n==25) 
	{
		//SEC = 10; //20; //40;
		CETA =1;
	}

	else if(n == 4) 
	{
		//SEC = 10; //20; //40;
		CETA =1;
	}
	else if(n == 3) 
	{
		//SEC = 10; //20; //40;
		CETA = 1; //2;
	}
	else if(n == 2) 
	{
       CETA = 2;
	}
 
///////// SEC, CETA //////////
    SEC = 2;  // all SEC = 2

	if(n == 2)
		 CETA = 2;
	else 
         CETA = 1;
///////// SEC, CETA  //////////

	char * szSql = new char[80920]; //6579//8092000
	strcpy(szSql, "");

	char temp[512] = "";
	//CString cstrMarc = "";
	double VFactor;
	if(n==104)
	  VFactor = 5.0 * pow(10, 37);
	else if(n==50)
	  VFactor = pow(10, 34); // (30 +38)/2=34
	else if(n==25)
	  VFactor = pow(10, 31); // (24 +38)/2=31

	//CFile file;

	//Seed the random-number generator with current time
	//srand( (unsigned)time( NULL ) );	
	//int iRandom = rand()%100;

	char TableName[1024] = "";
	strcpy(TableName, " ");
	strcat(TableName, DatasetTableName);
	strcat(TableName, " ");

    //char InsertTableName[512] = "";
    
    RESULT_LEARNING * RstLng = new RESULT_LEARNING[WORKLOAD_NUM +1];

	ZLRECT * S = new ZLRECT[m+1]; //S[m+1];
	ZLRECT * T = new ZLRECT[m+1]; //T[m+1];
	//-- NOT use the following definition: 
	//      ZLRECT ** T = new ( ZLRECT (*[m+1]) ); //T[m+1];


////////////////////////////////////////////////////////////////////////////////////	
//----------- 1. Get m initial rectangles from DB----------------------
//---------------------------------------------------------------------
//---------------------------------------------------------------------
	// [15, 90]x[-25897, 347998]: the domain of the table CLMB_census2D
    //15 <=	Age <= 90	
    //-25897 <= income <=347998
	
	//SELECT MIN(attr0), MIN(attr1), MAX(attr0), MAX(attr1) FROM Attr_Census2D
    //15	-25897	90	347998

	double dMin[COL_NUM+1]; 
	double dMax[COL_NUM+1];
	CLearnIing6App * pApp = (CLearnIing6App * ) AfxGetApp();

	//strcpy(InsertTableName, pApp->szOutputTableName);
     
    //Defination of Model and thredhold
    int iModle= 0; // modle of Clustering,
  
	//if(strcmp(TableName, " Attr_Census2D ")==0 || strcmp(TableName, " Attr_Census3D ")==0 || strcmp(TableName, " Attr_Cover4D ")==0)
	if(strcmp(TableName, " Attr_Census2D ")==0 )
	{
		pApp->c2 = 0.25; // threshold of clustering c1,c2,c3
		iModle = 1;
		//CETA = 2; // threshold of clustering c0, for Sum-clustering
		CETA  = 1.5;
		pApp->CETA  = CETA;

	}
	if(strcmp(TableName, " Attr_Census3D ")==0 )
	{
 		iModle = 1;
		pApp->c2 = 0.25; // threshold of clustering c1,c2,c3
		CETA = 1.5; // threshold of clustering c0, for Sum-clustering
		pApp->CETA  = CETA;
	}
	if(strcmp(TableName, " Attr_Cover4D ")==0)
	{
		pApp->c2 = 0.25; // threshold of clustering c1,c2,c3
		iModle = 1;
		CETA = 1.5; //threshold of clustering c0, for Sum-clustering
  		pApp->CETA  = CETA;
   
	}
    else if( strcmp(TableName, " Attr_Gauss3D ")==0 )
	{
		 //iModle = 2;
		 iModle = 1;  // 
	     pApp->c2 = 0.5; // threshold of clustering c1,c2,c3
		 //2007.02.21/   CETA =  1.956522; //3; //2; //3;    // threshold of clustering c0, for Sum-clustering
                   // = 1.956522  CETA =  2 is better than  CETA =  1 and  CETA =  3;
		 CETA =  2; //2007.02.21
		 pApp->CETA  = CETA;

		 //1.52 means  iModle = 1;  pApp->c2 = 0.5;CETA = 2; 
         //1.3752 
		 // conclusion: iModle = 1;   pApp->c2 = 0.5;   CETA =  2; //06.03.21
    }
    else if(strcmp(TableName, " Attr_Array3D ")==0)
	{
 	     CETA = 2; // threshold of clustering c0, for Sum-clustering
						   // CETA = 2 is  GOOD to Array3D, 
	     pApp->c2 = 0.5; // threshold of clustering c1,c2,c3
		 iModle = 2; 
		 pApp->CETA  = CETA;
		 		                   
    	 //pApp->c2 = 0.1; // threshold of clustering c1,c2,c3
		 // iModle = 1;	   //Modle 1 is NOT good to Array3D. So use iModle = 2.

	}
    else if(strcmp(TableName,  " Lsi_025D ")==0 )
	{
	     pApp->c2 = 0.25; // threshold of clustering c1,c2,c3
		 iModle = 2;	
   		 CETA = 1;      // threshold of clustering c0, for Sum-clustering
	 	 pApp->CETA  = CETA;
	}
	else if( strcmp(TableName, " Lsi_050D ")==0 )
	{
	     pApp->c2 = 0.1; // threshold of clustering c1,c2,c3
		 iModle = 2;	
		 CETA = 1;    // threshold of clustering c0, for Sum-clustering
    	 pApp->CETA  = CETA;
	}
    else if( strcmp(TableName, " Lsi_104D ")==0 )
	{
	     pApp->c2 = 0.0; // threshold of clustering c1,c2,c3 for LSI_104D
		 iModle = 2;
		 CETA = 1;
   		 pApp->CETA  = CETA;
	}
 ////////////// set parameter end /////////////////////
    
	int iQryIdx = 1;
    int ii = 0;
	//int inN =0;
	//if(n < 25)
         //inN = 2*(Z[ii].N);
	//else if (n >=25) 
         //inN = 5*(Z[ii].N);

	//--- here, "iCountOfQueries" is the size of KB
	//--- Z[i] is based 0
    for(ii = 1; ii<=iCountOfQueries; ii++)
    {
         Z[ii-1].Sn = -1;  //Sn is the number of S[] above

		if( ( (Z[ii-1].f < 2*(Z[ii-1].N)) && (n < 25) ) || ( (Z[ii-1].f < 100) && (n >=25) ) )
		//if( Z[ii].f < inN )
		{
            Z[ii-1].Sn = iQryIdx;  //Sn is the number of S[] above
			for(i = 1; i<=COL_NUM; i++)
			{
				RstLng[iQryIdx].q[i] = Z[ii-1].x[i-1]; //fCol[i-1];
			}
			//RstLng[WORKLOAD_NUM +1];
			//iQryIdx start from 1
			RstLng[iQryIdx].N		= Z[ii-1].N;
			RstLng[iQryIdx].r		= Z[ii-1].r;
			RstLng[iQryIdx].f		= Z[ii-1].f;
			//RstLng[iQryIdx].f_rst	= Z[ii-1].f_rst;
			//RstLng[iQryIdx].shortTicks_rst = Z[ii-1].shortTicks_rst;
			RstLng[iQryIdx].longTicks = Z[ii-1].longTicks;	 
			RstLng[iQryIdx].shortTicks = Z[ii-1].shortTicks; 
  			iQryIdx++;  //start from 1

		}

    }
    m = iQryIdx-1;
	old_m = m;
   //Save the profiles in pApp->Q[i]
   //for(i=1; i<=WORKLOAD_NUM; i++)
   for(i=1; i<=m; i++)	   
   {
		pApp->Q[i] = RstLng[i];  //Z[i] is based 0;
   }

////////////////////////////////////////////////////////////////////////////////////	

double xi = 0.0; 
     
    xi = pApp->c2; // threshold of clustering c1,c2,c3
	//CETA = pApp->CETA; //3; //2; //3;    // threshold of clustering c0, for Sum-clustering

    //lStartTimer = 0;
    //lEndTimer =0;

	//lALL_StartTimer = 0;
	//lALL_EndTimer =0;
    //iALL_TickCount = 0;


////////////////////////////////////////////////////////////////////////////////////	
//////////////////////// 11111111111111111 ///////////////////////
//		Assigned the rectangles S[i] from RstLng[i]; S[i]:= RstLng[i]
//      m = 100, 80,60, 40, 20,10 ?
//---------------------------------------------------------------------
//---------------------------------------------------------------------

//lALL_StartTimer = GetTickCount();
	
	for(i=1; i<=m; i++)
	{
		for(j= 1; j <=n; j++)
		{
			S[i].a[j] = RstLng[i].q[j] - RstLng[i].r ; 

			S[i].b[j] = RstLng[i].q[j] + RstLng[i].r; 

		}

		S[i].v =1;
		if(n < 25)
		{
			for(j=1; j<=n; j++)
			{
				S[i].v *= (S[i].b[j]-S[i].a[j]);
			}
		}
		else
		{
			for(j=1; j<=n; j++)
			{
				S[i].v *= ( (S[i].b[j]-S[i].a[j])/VFactor );
			}
			
		}

		sprintf(S[i].suffix, "%d", i);
		S[i].suf1st = i;
		S[i].sufend = i;
		S[i].cn =0;
		//S[i].bsn = i; //2005.4.8
		S[i].bsn = 0;   //2005.4.8

	}

//lALL_EndTimer = GetTickCount()-lALL_StartTimer;
//iALL_TickCount += lALL_EndTimer;

delete [] RstLng;


//calculas the volume of the table.
double V_Lsi104D =1.0;
	
if(n>24)
{
	double S_v[WORKLOAD_NUM +1];//101

	for(j=1; j<=n; j++)
	{
		V_Lsi104D *= ( (dMax[j]-dMin[j])/VFactor );
	}

	for(i=1; i<=m; i++)
	{  
		S_v[i] = S[i].v;
	}
	//sprintf(temp, " V_Lsi104D = %.15G  ", V_Lsi104D );
	//cstrMarc += temp;
	//cstrMarc += "\r\n";
	//cstrMarc += "\r\n";
}


////////////////////////////////////////////////////////////////////////////////////	

////////////////////////////////////////////////////////////////////////////////////	
/////////////////     222222222222222222222        //////////////////////////
//		2. Eliminating redundant squares temporarily
//---------------------------------------------------------------------
//---------------------------------------------------------------------
//lALL_StartTimer = GetTickCount();

	bool rmvable = false;
    int  l = 1; 
	int  k;

	int S_Idx[WORKLOAD_NUM +1 ];
	for(i=1; i<=WORKLOAD_NUM; i++)
		S_Idx[i]=0;

	int min_S_Idx = 0;
	double min_S_v =0.0;

	
	for(i=1; i<=m; i++)
	{ 
      if(S[i].bsn ==0)
	  {
		rmvable =false;

		//for(j=1; j<=100; j++)
		for(j=1; j<=WORKLOAD_NUM; j++)
		  S_Idx[j]=0;

		min_S_Idx =0;

		for(k=1; k<=m; k++)
		{
		   // for each i, see ?? S[i] in S[k], for all k:  i!=k and S[k] is not removed
		   // this way can avoid the situation S[i] ==S[k]. say, S[8] == S[65]
           // then in the case of S[8] == S[65], the loop of () will be dead loop

		   //if(i != k )  // 2005.4.8
		   //if( k != i  && S[k].bsn == 0) // 2005.4.8 
		   if( k != i  && S[k].bsn != i) // 2005.5.22 //finding S[i]'s all superset S[k] that is not itself and 
		   {                                          //S[k].bsn != i
				for(j=1; j<=n; j++)
				{
					// if S[i] is the subset of S[k], 
					if( (S[k].a[j]<=S[i].a[j]) && (S[i].b[j]<=S[k].b[j] ))
					{
						rmvable = true;
					}
					else
					{
						rmvable = false;
						break; //break j, for next k
					}
				} //for(j= 1; j <=n; j++)
				
				if(rmvable) //there is a k such that Si is in Sk 
				{

					//break;  // break k and then for next i
					S_Idx[k]  = k;
					min_S_Idx = k;
					min_S_v   = S[k].v;
				}
		   } //if(i != k)

		}//for(k=1; i<=m; k++)

		////////
		for(k = 1; k<=old_m; k++)
		{
			if(S_Idx[k]>0)
			{
				 if(S[S_Idx[k] ].v <= min_S_v)  //?? pay attetion to must be <= 
				 {
					min_S_v = S[ S_Idx[k] ].v;
					min_S_Idx = S_Idx[k];
				 }
			}				
		}
		if(min_S_Idx >0 )
		{
			S[i].bsn = min_S_Idx; // s[i] is in s[k], i.e. S[i] is the subset of s[k]. IMPORTANT. bsn = Big Set Number
			S[i].tplNum =S[i].bsn; //2005.5.17

			min_S_Idx =0;
			rmvable = true;
		}
		else
		{
			rmvable = false;
		}
		///////////

		/**** 07.03.04 
		if(l==1 && i==m && rmvable)  // forget the meaning of this conditions
		{                           // i==m ?? the last one S[m] is in S[k], k !=m
			AfxMessageBox("l==1 && i==m && rmvable");
		} //2005.5.14
        07.03.04 *****/
		//if( (rmvable == false) || (l==1 && i==m && rmvable) ) //cannot be removed //2005.5.14
		if( (rmvable == false)  ) //cannot be removed //2005.5.14
		{
			//T[l] = S[i];
			// :==: is the same as :==:
			//memset(&T[l], 0, sizeof(ZLRECT));
			//memcpy(&T[l], &S[i], sizeof(ZLRECT));
			
			for(j= 1; j <=n; j++)
			{
				T[l].a[j] = S[i].a[j];
				T[l].b[j] = S[i].b[j]; 
			}
			T[l].v=S[i].v;

			sprintf(T[l].suffix, "%d", l);
			T[l].suf1st = l;
			T[l].sufend = l;
			T[l].cn = 0;
			//T[l].bsn = l;  // 2004.4.13
			T[l].bsn = 0;    // 2004.4.13

			S[i].bsn= 123456+l; //10000+l;  here S[i] cannot be in some S[k]
								//ie. {S[i]} is the {T[l]}; i map l by 
			                    // the remainder of S[i]: S[i].bsn = l +10000; 
							    // where l is the index of T[l]. i.e. S[i] is the (sub)set of T[l]
			S[i].tplNum =S[i].bsn; //2005.5.17

			l++;
		}//if( (rmvable == false) || (l==1 && i==m && rmvable) ) //cannot be removed
	
	  } //if(S[i].bsn ==0)
	}//for(i=1; i<=m; i++)

	m_T = l-1;  // for T[i]; l-1 is the number of T[i]

//lALL_EndTimer = GetTickCount()-lALL_StartTimer;
//iALL_TickCount += lALL_EndTimer;
////////////////////////////////////////////////////////////////////////////////////	

////////////////////////////////////////////////////////////////////////////////////	
//3. Select * from 4 Cases;
//SELECT * FROM CLMB_census2D where (20 <= Age and Age <= 50) AND (3000 <= Income and Income <= 60000)
//---------------------------------------------------------------------
//---------------------------------------------------------------------
		
	int ituples_cnt = 0;
	int PreTuplesNum = 0;

	int iSum_TickCount = 0;
    //int iSum_TuplesCount =0;
	int iCandidateNum = 0;

	//3.0 select * FROM  ALL TABLE: //SELECT * FROM CLMB_census2D, 
	//---------------------------------------------------------------------



	  /////////////////////////////

   CString str1, str2, str3;

   //int N_Tuple, N_ALLTick,	N_ExtraTick, N_IO_Num;

	m   = l-1;  // for T[i]
	m_T = l-1;  // for T[i]

	
///////////////////////// 333333333333333333 /////////////////////////////////
//   3.3  select * From SCR, obtain the scr (Small Cover Rectagle,) of all T[i], i=1,l
//					where the scr is the BIGGEST one that contains all T[i]'s
//---------------------------------------------------------------------
//---------------------------------------------------------------------
	
	m=l-1;  // for T[i], at this moment, the size of {T[i]} is l-1 

//lALL_StartTimer = GetTickCount();

	ZLRECT scr;  //This is the BIG scr that covers all T[i]

	for(i=1; i<=n; i++ )
	{
		scr.a[i] = T[1].a[i];
		scr.b[i] = T[1].b[i];

		for(j=2; j<=m; j++ )
		{
			scr.a[i] = min(scr.a[i], T[j].a[i]);
			scr.b[i] = max(scr.b[i], T[j].b[i]);
		}
	}

//lALL_EndTimer = GetTickCount()-lALL_StartTimer;
//iALL_TickCount += lALL_EndTimer;

///===========
//scr.a[1] = 15; scr.b[1]=90;
//scr.a[2] =0 ; scr.b[2]= 347998;   

//scr.a[2] =-25897 ; scr.b[2]= 347998;  //-25897	347998
///===========

////////////////////////////////////////////////////////////////////////////////////	

////////////////////////////////////////////////////////////////////////////////////	
///////////////////////// 44444444444444444444 ///////////////////////
//3.4  ----   division the biggest scr into 12 = 4*3 partition or more ----
//            select * From each partition,
//---------------------------------------------------------------------
//---------------------------------------------------------------------

//lALL_StartTimer = GetTickCount();
	//ZLRECT	part[101]; //we use 1-12
	int		iPartNum = 0;

	if(n==2) //only for 2_dimensional
		iPartNum = pApp->zlPartion(scr, n, T, m, iPartNum);
//	else	 //for 3,4, 25,50,and 104 dimensions
	//	iPartNum = pApp->zlPartion3D(&scr, n, T, m, iPartNum);
	//Get T[j].bsn =i means the center of T[j] is in part[i]

//lALL_EndTimer = GetTickCount()-lALL_StartTimer;
//iALL_TickCount += lALL_EndTimer;

int bsn[WORKLOAD_NUM +1 ];// 101
for(i=0; i<=WORKLOAD_NUM; i++)   //100
	bsn[i] =-100;

    ZLRECT * part = new ZLRECT[iPartNum +1];
    char	buffer[1024] = "";


////////////////////////////////////////////////////////////////////////////////////	

////////////////////////////////////////////////////////////////////////////////////	
//3.5 ---- Find which rectangle T[i] that Center IN the partition of all 12 = 4*3 partitions ----
//         DO NOT USE intersect, 
//	     We use "Center IN" method 
/////////////////////// 555555555555555 /////////////////////
//3.6 ------------------- Clustering -----------------------
// we use the method of "Center IN " to clustering: 
// see the function iPartNum = pApp->zlPartion3D(&scr, n, T, m, iPartNum);
// in this function, the method of "Center IN " has been used
//---------------------------------------------------------------------
//---------------------------------------------------------------------


	iSum_TickCount =0;
	//iSum_TuplesCount =0;
	
	//int		index[WORKLOAD_NUM + 1][WORKLOAD_NUM+1];  //2007.02.21 i= 1 to 12 intersect with part[i] : index[i][1]=5, index[i][2]=7,index[i][3]=8, index[i][4]=15,...	
	int * * index; 
	index = new (int *[iPartNum+1]);
	for(i= 0; i<=iPartNum; i++)
		index[i] = new int[WORKLOAD_NUM+1];

	for(i= 1; i<=iPartNum; i++)
	{
		for(j=1; j<=WORKLOAD_NUM; j++)
		{
			index[i][j] = 0;
		}
	}


	//double	p, q;
	bool	bInterable =false;
	
	ZLRECT * partT[101];
	//int clsNum =0;  //2005.3.16
	//int clsNum =1000; ////2005.3.16 , only for intersections
	//int clsNum =12; ////2005.3.24 , only for intersections
	int clsNum = iPartNum; //2005.4.14

	double center =0.0;

//lALL_StartTimer = GetTickCount();

////// ~~~~~~~~ Finding all T[j]'s that center are in part[i].
/////         and clustering by calling: pApp->zlClusterPart	

	
	for(i= 1; i<=iPartNum; i++)
	{
		l=0;
		for(j= 1; j <=m ; j++) // m is the number of T[i]'s
		{
			if(T[j].bsn == i && T[j].cn <=0)   
			{
					l++;
					index[i][l] = j;
					sprintf(buffer, ",%i", j);
					strcat(part[i].suffix, buffer); // save the index j of T[j] 

					T[j].cn = i;                   //2005.3.16, use it again.

					partT[l] = &T[j]; // the address of (T[j]) assign to (partT[l]);

			}
		}

		//cstrMarc += part[i].suffix;						 
	    //cstrMarc += "\r\n";

		if(l>0)
		{
		  //clsNum = zlClusterPart( partT, l, T, m, clsNum, n );  
		  //clsNum = pApp->zlClusterPart( partT, l, T, m, clsNum, n ); //2005.04.28
			
			//if( n == 2 )
			//if( n <= 4 )
				//clsNum = pApp->zlClusterPart( partT, l, T, m, clsNum, n, iPartNum);  			
			    // for threshold : Intersection

///////1. I:   //Census2D  //Census3D   //Cover4D 
		//clsNum = pApp->zlClusterPart( partT, l, T, m, clsNum, n, iPartNum, xi);  			

			//else
				//clsNum = pApp->zlClusterPartLsi( partT, l, T, m, clsNum, n, iPartNum);  			
			    // for threshold
                //Intersection:
				 ///////clsNum = pApp->zlClusterPartLsi_InSe( partT, l, T, m, clsNum, n, iPartNum, xi);  			

//////2  C:  //Array3D //Gauss3D //Lsi_025D //Lsi_050D //Lsi_104D
		//clsNum = pApp->zlClusterPartLsi( partT, l, T, m, clsNum, n, iPartNum, xi);  			
//////3  C+:
		//clsNum = pApp->zlClusterPartLsi_Plus( partT, l, T, m, clsNum, n, iPartNum, xi);  			
                
			//Conclusions: 
			//	           1. Cover4D uses: I-Clustering 
			//                threshold: [0, 0.25] , Intersect-Clustering
				
			//             2. Gauss3D need to use: C-clustering: zlClusterPartLsi. 
				              //Intersect:0.979218; C: 0.88092; C+:0.914235
				              //threshold: [,  ]

			//             3. Array3D use: C-clustering
			//				 //Intersect:0.889198; C:0.806674 ; C+ :.841225
			//             4. Census3D use: I-clustering
			//             5. Census2D use: I-clustering
		    //             6: Lsi_104D use : C-clustering
		    //             7: Lsi_050D use : 2. C-clustering
			//             8: Lsi_025D use : 2. C-clustering

	     //if(strcmp(TableName, " Attr_Census2D ")==0 || strcmp(TableName, " Attr_Census3D ")==0 || strcmp(TableName, " Attr_Cover4D ")==0)
		 if(iModle == 1)    
			clsNum = pApp->zlClusterPart( partT, l, T, m, clsNum, n, iPartNum, xi);  			
		 else if(iModle == 2)   
		    clsNum = pApp->zlClusterPartLsi( partT, l, T, m, clsNum, n, iPartNum, xi);  					 
		}
	}
	
//lALL_EndTimer = GetTickCount()-lALL_StartTimer;
//iALL_TickCount += lALL_EndTimer;



////////////////////////////////////////////////////////////////////////////////////	
//					 Finding scr of each Cluster						//
//					 scr_CLS[i]

//lALL_StartTimer = GetTickCount();		
//iSum_TickCount = 0;
//iSum_TuplesCount =0;

	//double * Sum_v_T = new double [clsNum +1]; //[100 +1]; //
	//ZLRECT * scr_CLS = new ZLRECT [clsNum +1]; //[100+1];   //  
	 delete []  pApp->Sum_v_T;    
     delete []  pApp->scr_CLS;
     pApp->Sum_v_T = new double [clsNum +1]; //[100 +1]; //
	 pApp->scr_CLS = new ZLRECT [clsNum +1]; //[100+1];   //  
	
	for(i=1; i<=clsNum; i++)
	{
		pApp->scr_CLS[i].v = 1.0;
		
		pApp->Sum_v_T[i] = 0.0;
		for(k=1; k<= m_T; k++) //old_m ==100; m_T = l-1
		{
			if(T[k].cn ==i)
			{
				pApp->Sum_v_T[i] += T[k].v; //all T[k] with cluster num == i 
			}

		}

	}

	for(i=1; i<=clsNum; i++ )
	{
		for(j=1; j<=n; j++)
		{
		    pApp->scr_CLS[i].a[j] = T[1].a[j]; //dMax[j];
			pApp->scr_CLS[i].b[j] = T[1].b[j]; //dMin[j];
		}

		for(j=1; j<=n; j++)
		{
			for(k=1; k<=m_T; k++) // 
			{
				if(T[k].cn ==i)
				{
					pApp->scr_CLS[i].a[j] = min(pApp->scr_CLS[i].a[j], T[k].a[j]);
					pApp->scr_CLS[i].b[j] = max(pApp->scr_CLS[i].b[j], T[k].b[j]);
				}

			}
		}

		for(j=1; j<=n; j++)
		{
			if(n<25)
				pApp->scr_CLS[i].v *= (pApp->scr_CLS[i].b[j] - pApp->scr_CLS[i].a[j]) ;
			else
				pApp->scr_CLS[i].v *= ( (pApp->scr_CLS[i].b[j] - pApp->scr_CLS[i].a[j])/VFactor ) ;

		}
	}
	
//lALL_EndTimer = GetTickCount()-lALL_StartTimer;
//iALL_TickCount += lALL_EndTimer;
	

	int nonzearo =0;
	//cstrMarc += "\r\n";
// not for T[i], But for T[i]; 2005.5.17
//lALL_StartTimer = GetTickCount();	
	
	for(i = 1; i<=clsNum; i++)
	{
		//scr_CLS[i].bsn = 1; // means has elements T[i] //2005.5.22 
		pApp->scr_CLS[i].cn = 1; //2005.5.22 means "has elements T[i]", ie, nonempty
	}

	//?? see whether or not all T[j]'s (in part[i]) can be clustering 
	//for cen2D CETA = 4
	//int CETA = 1 ; //1;  //10; //For Lsi_050D, CETA = 1; OK
	//int CETA = 2 ; //1;  //10; // For Lsi_104D 
    // define at the head of function

	for(i = 1; i<=iPartNum ; i++)   //2005.5.5
	{
		//?? add if (.bsn ==1)
		// CETA = 3, 4, 5,10
		if(pApp->scr_CLS[i].v <= CETA* (pApp->Sum_v_T[i])  )  // 5*Sum_v_T[i] //10*Sum_v_T[i]
		{
			/// test ////
			//sprintf(temp, " scr_CLS[%02i].v = %G <<<=== %i*Sum_v_T[%02i] =%G;  ",i, scr_CLS[i].v, CETA, i, Sum_v_T[i] );
			//cstrMarc += temp;
			//cstrMarc += "\r\n";
			//sprintf(temp, "		scr_CLS[%02i].v/Sum_v_T[%02i]= %.02f   ",i,i, scr_CLS[i].v/Sum_v_T[i] );
			//cstrMarc += temp;
			//cstrMarc += "\r\n";
			//cstrMarc += "\r\n";
			/// test ////
		}
		else // that is: scr_CLS[i].v/Sum_v_T[i]  >CETA , Cancel this cluster
		{
            k=0;
			for(j=1; j<=m_T; j++)
			{
				if(T[j].cn == i)
				{
					T[j].cn =0;
					k++;
				}
			}

			//scr_CLS[i].bsn = 0; //2005.5.22
			pApp->scr_CLS[i].cn = 0; //2005.5.22 means empty, ie., no rectangle in it.

			//scr_CLS[i].cn =k;  // old. //2005.5.22 in the begining it has k T[i], //?? is that useful??

			/// test ////
			//sprintf(temp, " scr_CLS[%02i].v = %G >>>>>> %i*Sum_v_T[%02i] =%G ",i, scr_CLS[i].v, CETA, i, Sum_v_T[i] );
			//cstrMarc += temp;
			//cstrMarc += "\r\n";
			//sprintf(temp, "						scr_CLS[%02i].v/Sum_v_T[%02i]= %.02f   ",i,i, scr_CLS[i].v/Sum_v_T[i] );
			//cstrMarc += temp;
			//cstrMarc += "\r\n";
			//cstrMarc += "\r\n";
			/// test ////

		}
	}

////////////////////////////////////////////////////////////////////////////////////	

////////////////////////////////////////////////////////////////////////////////////	
//clustering again if one is the subset of another, then togather them 
   //3.9.1 for  scr_CLS[i].bsn =1 change it to scr_CLS[i].cn =1 2005.5.22
   //3.9.2 for T[i].cn =0
//---------------------------------------------------------------------
//---------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////////	
	// see whethe or not there are SUBSET 
	//  if scr_CLS[i] is the SUBSET of scr_CLS[k], label it, //scr_CLS[i].bsn = 0; change it to scr_CLS[i].cn = 0 //2005.5.22
	//  and remove it

	int scr_CLS_Idx[WORKLOAD_NUM+1];  //101
	for(i=1; i<=WORKLOAD_NUM ; i++)  //100
		scr_CLS_Idx[i]=0;

	int min_scr_CLS_Idx = 0;
	double min_scr_CLS_v =0.0;


	// for dimension >24, for(i=1; i<=iPartNum; i++) there are lots of clustering 
	// only contain one T[i]; so remove it;

	//int bsn[101];  //has defined before
	int cn[WORKLOAD_NUM +1]; //101

	//--- test   ---
	for(i=0; i<WORKLOAD_NUM; i++)    //101
	{
		bsn[i] = -1;
		cn[i] = -1;
	}

	for(i=1; i<=clsNum; i++)
	{
		bsn[i] = pApp->scr_CLS[i].bsn;
		cn[i] = pApp->scr_CLS[i].cn;
	}
   	//--- test   ---

	///***
	//for(i=1; i<=clsNum; i++)
	for(i=1; i<=iPartNum; i++)
	{
	  rmvable = false;

	  for(j=1; j<= WORKLOAD_NUM; j++) //100
		  scr_CLS_Idx[j]=0;


	  //if(scr_CLS[i].bsn ==1) // scr_CLS[i].bsn = 3, means scr_CLS[i].bsn
							   // is the SUBSET of scr_CLS[3]

	  if(pApp->scr_CLS[i].cn ==1) // scr_CLS[i].cn ==1 means it is NOT empty. ie. 
	  {                     // there is T[j] that is in scr_CLS[i]

		for(k=1; k<=clsNum; k++)
		{
		   //if( (i != k) && scr_CLS[k].bsn ==1 )
		   if( (i != k) && pApp->scr_CLS[k].cn ==1 )
		   {
				for(j=1; j<=n; j++)
				{
					// if scr_CLS[i] is the subset of scr_CLS[k], 
					//if( (scr_CLS[k].a[j]<=scr_CLS[i].a[j]) && (scr_CLS[i].b[j]<=scr_CLS[k].b[j] ))
					//if the center of scr_CLS[i] is in scr_CLS[k],
					
					if( (pApp->scr_CLS[k].a[j]<=pApp->scr_CLS[i].a[j]) && (pApp->scr_CLS[i].b[j]<=pApp->scr_CLS[k].b[j] ))		
					{
						rmvable = true;
					}
					else
					{
						rmvable = false;
						break; //break j, for next k
					}
				} //for(j= 1; j <=n; j++)
				
				if(rmvable) //there is a k, such that scr_CLS[i] is in scr_CLS[k] 
				{

					scr_CLS_Idx[k]=k;
					min_scr_CLS_Idx=k;
					min_scr_CLS_v = pApp->scr_CLS[k].v;

					rmvable = false;
					
					//break;  //2005.5.15 not break, for k continue; break k and then for next i
				}

		   } //if(i != k)

		}//for(k=1; i<=m; k++)

		////////
			 for(k = 1; k<=clsNum; k++)
			 {
				 if(scr_CLS_Idx[k] >0)
				 {
					 if(pApp->scr_CLS[ scr_CLS_Idx[k] ].v <= min_scr_CLS_v)
					 {
						min_scr_CLS_v =  pApp->scr_CLS[ scr_CLS_Idx[k] ].v;
						min_scr_CLS_Idx = scr_CLS_Idx[k];
					 }
				 }
				
			 }
			if(min_scr_CLS_Idx >0 )
			{
				//scr_CLS[i].bsn = 0; 
				pApp->scr_CLS[i].cn = 0; 
				for(l=1; l<=m_T; l++)
				{
					if(T[l].cn ==i)
						T[l].cn = min_scr_CLS_Idx;
				}

				min_scr_CLS_Idx =0;
			}
		///////////

	  }
	}//for(i=1; i<=m; i++) 
    //***********/


	//Finding scr_CLS[i].bsn that save the index of its Supperset
    // say, scr_CLS[38].bsn = 36; means scr_CLS[38] is IN scr_CLS[36]
	
	//initial them to be 0
	for(i=1; i<=clsNum; i++)
	{
		pApp->scr_CLS[i].bsn = 0;
	}

	
	for(i=1; i<=clsNum; i++)
	{ 
      //if(scr_CLS[i].bsn ==0)
	  if(pApp->scr_CLS[i].bsn ==0 && pApp->scr_CLS[i].cn ==1 )
	  {
		rmvable =false;
		for(j=1; j<=WORKLOAD_NUM; j++) //100
		  scr_CLS_Idx[j]=0;
		min_scr_CLS_Idx =0;

		for(k=1; k<=clsNum; k++)
		{
		   // for each i, see ?? scr_CLS[i] in scr_CLS[k], for all k:  i!=k and scr_CLS[k] is not removed
		   // this way can avoid the situation scr_CLS[i] ==scr_CLS[k]. say, scr_CLS[8] == scr_CLS[65]
           // then in the case of scr_CLS[8] == scr_CLS[65], the loop of () will be dead loop

		   //if(i != k )  // 2005.4.8
		   //if( k != i  && scr_CLS[k].bsn == 0) // 2005.4.8 
		   if( k != i  && pApp->scr_CLS[k].bsn != i && pApp->scr_CLS[k].cn ==1) // 2005.5.22 //finding scr_CLS[i]'s all superset scr_CLS[k] that is not itself and 
		   {                                          //scr_CLS[k].bsn != i
				for(j=1; j<=n; j++)
				{
					// if scr_CLS[i] is the subset of scr_CLS[k], 
					if( (pApp->scr_CLS[k].a[j]<=pApp->scr_CLS[i].a[j]) && (pApp->scr_CLS[i].b[j] <= pApp->scr_CLS[k].b[j] ))
					{
						rmvable = true;
					}
					else
					{
						rmvable = false;
						break; //break j, for next k
					}
				} //for(j= 1; j <=n; j++)
				
				if(rmvable) //there is a k such that scr_CLSi is in scr_CLSk 
				{

					//break;  // break k and then for next i
					scr_CLS_Idx[k]=k;
					min_scr_CLS_Idx=k;
					min_scr_CLS_v = pApp->scr_CLS[k].v;
				}
		   } //if(i != k)

		}//for(k=1; i<=scr_CLS; k++)

		////////
		for(k = 1; k<=clsNum; k++)
		{
			if(scr_CLS_Idx[k]>0)
			{
				 if(pApp->scr_CLS[scr_CLS_Idx[k] ].v <= min_scr_CLS_v)
				 {
					min_scr_CLS_v = pApp->scr_CLS[ scr_CLS_Idx[k] ].v;
					min_scr_CLS_Idx = scr_CLS_Idx[k];
				 }
			}
				
		}
		if(min_scr_CLS_Idx >0 )
		{
			pApp->scr_CLS[i].bsn = min_scr_CLS_Idx; // scr_CLS[i] is in scr_CLS[k], i.e. scr_CLS[i] is the subset of s[k]. IMPORTANT. bsn = Big scr_CLSet Number
			pApp->scr_CLS[i].tplNum =pApp->scr_CLS[i].bsn; //2005.5.17
			min_scr_CLS_Idx =0;
		}
		///////////
	
	  } //if(scr_CLS[i].bsn ==0)
	}//for(i=1; i<=clsNum; i++)
////////////////////////////////////////////////////////////////////////////////////	


   //3.9.2 if  T[k].cn == 0 that is obtained from	"if( !(scr_CLS[i].v <= CETA*Sum_v_T[i])  )"
	rmvable =false;

	for(i=1; i<=WORKLOAD_NUM; i++) //100
		scr_CLS_Idx[i]=0;

	min_scr_CLS_Idx = 0;
	min_scr_CLS_v =0.0;

	for(k=1; k<=m_T; k++)
	{
				
	  if(T[k].cn ==0 )  
	  {

		rmvable = false;

		for(j=1; j<=WORKLOAD_NUM; j++) //100
			scr_CLS_Idx[j]=0;

		for(i=1; i<=clsNum; i++)
		{
			rmvable =false;

			//if(scr_CLS[i].bsn ==1) //2005.5.22
			if(pApp->scr_CLS[i].cn ==1)  //2005.5.22
			{
					for(j=1; j<=n; j++)
					{
						 // if T[k] is the subset of scr_CLS[i], 
						if( (pApp->scr_CLS[i].a[j]<=T[k].a[j]) && (T[k].b[j]<=pApp->scr_CLS[i].b[j] ))
						{
							rmvable = true;
						}
						else
						{
							rmvable = false;
							break; //break j, for next k
						}
					} //for(j= 1; j <=n; j++)
				
				
					if(rmvable) //there is a k such that scr_CLS[i] is in scr_CLS[k] 
					{

						//T[k].cn = i;
						scr_CLS_Idx[i] = i;
						min_scr_CLS_Idx = i;
						min_scr_CLS_v = pApp->scr_CLS[i].v;

								
						rmvable =false;
						//break;  // 2005.5.15 not break, for next i countinoue; break k and then for next i
					}//if(rmvable)
				}//if(T[k].cn ==0 )
			}//for(i=1; i<=clsNum; i++)

		////////
			 for(i = 1; i<=clsNum; i++)
			 {
				 if(scr_CLS_Idx[i] >0)
				 {
					 if(pApp->scr_CLS[ scr_CLS_Idx[i] ].v <= min_scr_CLS_v)
					 {
						min_scr_CLS_v =  pApp->scr_CLS[ scr_CLS_Idx[i] ].v;
						min_scr_CLS_Idx = scr_CLS_Idx[i];
					 }
				 }
				
			 }
			if(min_scr_CLS_Idx >0 )
			{
				T[k].cn = min_scr_CLS_Idx;
				min_scr_CLS_Idx =0;
			}
		///////////


		}
	}//for(k=1; k<=m_T; k++)
	int allNonzero =0;
	nonzearo = 0;
	//cstrMarc += "\r\n";

//lALL_EndTimer = GetTickCount()-lALL_StartTimer;
//iALL_TickCount += lALL_EndTimer;
/////////////////////////////////////////////////////

//-- Finding Which scr_CLS[i] is NOT empty, that is, let scr_CLS[i].bsn =1
//						change it into let scr_CLS[i].cn =1 2005.5.22
//------------------------------------------------------------------------
//------------------------------------------------------------------------
	for(i = 1; i<=clsNum; i++) // there are clsNum scr's of cluster scr_CLS[1] to scr_CLS[clsNum]
	{
		nonzearo = 0;
		sprintf(temp, " scr_CLS%02i:  ", i);
		//cstrMarc += temp;	
	    //cstrMarc += "\r\n";

		//cstrMarc += "    Cover: ";

		for(j=1; j<=m_T; j++)
		{
			if(T[j].cn ==i)
			{
				sprintf(temp, " ,T[%02i] ", j );
				//cstrMarc += temp;
				nonzearo ++;
			}
		}
	    //cstrMarc += "\r\n";

       allNonzero += nonzearo;

	}
    //cstrMarc += "\r\n";
	sprintf(temp, " T[i] allNonzero = %02i ", allNonzero);
	//cstrMarc += temp;
	//cstrMarc += "\r\n";

	int scr_nonZeroNum = 0;
	int scr_ZeroNum = 0;
	for(i = 1; i<=clsNum; i++) // there are clsNum scr's of cluster scr_CLS[1] to scr_CLS[clsNum]
	{
		  //if(scr_CLS[i].bsn == 1)
		  if(pApp->scr_CLS[i].cn == 1)
		  {
			  scr_nonZeroNum ++;
		  }
		  //else if(scr_CLS[i].bsn == 0)
		  else if(pApp->scr_CLS[i].cn == 0)
		  {
			  scr_ZeroNum ++;
		  }
	}

    //cstrMarc += "\r\n";
	//sprintf(temp, " scr_nonZeroNum = %02i ", scr_nonZeroNum);
	//cstrMarc += temp;
	//cstrMarc += "\r\n";
    //cstrMarc += "\r\n";
	//sprintf(temp, " scr_ZeroNum = %02i ", scr_ZeroNum);
	//cstrMarc += temp;
	//cstrMarc += "\r\n";
	//cstrMarc += "\r\n";
////////////////////////////////////////////////////////////////////////////////////	
//////////////////////// 666666666666666666 ////////////////////////////
// 3.7 ------------------- Clustering S[] -----------------------
//    obtain all cluster number of S[i] (where i=1 to old_m)
//---------------------------------------------------------------------
//---------------------------------------------------------------------

//lALL_StartTimer = GetTickCount();	
	
	for(i=1; i<= old_m; i++)
	{

		do 
		{
			//if(S[i].bsn > 10000)
		    if(S[i].bsn > 123456)  // there is not another one that contains S[i]
			{	
				//S[i].cn = T[S[i].bsn-10000].cn;
				S[i].cn = T[S[i].bsn-123456].cn;
				break;
			}
			else   // S[i] is in some s[k]
			{
				k = S[i].bsn;
				S[i].bsn = S[k].bsn; // S[i].bsn = S[ S[i].bsn ].bsn; 
			}
		} while (true);

	}


	for(i=1; i<= old_m; i++)
	{
		S[i].bsn = S[i].tplNum;
		S[i].tplNum = 0;  //it has its own task, after here 
	}

//lALL_EndTimer = GetTickCount()-lALL_StartTimer;
// iALL_TickCount += lALL_EndTimer;

 

//////////////////////////////////////////////////////////////////////////////
//					Up to Now. Clustering is OK								//
//					select the tuples from each clustering scr				//
//////////////////////////////////////////////////////////////////////////////

	//scr[5][9] means the 5th scr , and its 9 tuple

 	for(i = 1; i<=pApp->clsNum; i++)
			delete [] pApp->scr[i];
	delete [] pApp->scr;
    
	pApp->clsNum = clsNum; // the number of clusters

    pApp->scr = new ( TUPLE *[clsNum +1] );  
	for(i = 0; i<=clsNum; i++)
			pApp->scr[i] = new TUPLE[2];

	for(i = 1; i<=clsNum; i++)
		pApp->scr_CLS[i].tplNum = 0;     //scr_CLS[i].tplNum is the size of tuples in  scr_CLS[i]
	
	//1. Search 1st NON_subset scr_CLS[i], let it be the start.
	for(i = 1; i<=clsNum; i++) // there are clsNum scr's of cluster scr_CLS[1] to scr_CLS[clsNum]
	{
		//if(scr_CLS[i].bsn ==1) changed it if(scr_CLS[i].cn ==1)
		//before 2005.5.22, scr_CLS[i].bsn ==1 means it is not empty
		//now scr_CLS[i].bsn means the Big Set Number of its superset.
		//i.e. scr_CLS[i].bsn =k means scr_CLS[i] is IN scr_CLS[k] 
		// this work has been done in above section
				//"Finding scr_CLS[i].bsn that save the index of its Supperset"
				// "say, scr_CLS[38].bsn = 36; means scr_CLS[38] is IN scr_CLS[36]"

		//for each scr_CLS[i], retrieve all tuples in it //2007.11.10
		//------
		//1.scr_CLS[i].cn ==1 means it is not Empty:        NON_empty
		//2. scr_CLS[i].bsn ==0 means it has not superset:  NON_subset
		//if(scr_CLS[i].cn ==1 && scr_CLS[i].bsn ==0)  
		if(pApp->scr_CLS[i].cn ==1 && pApp->scr_CLS[i].bsn ==0)  
		{
			strcpy(	szSql, 	" SELECT * FROM ");
			strcat(	szSql, 	TableName );
			strcat(	szSql, 	" where ( ( ");
				
				for(j=1; j<=COL_NUM-1; j++)
				{
					sprintf(temp, " %.15G <= attr%d AND attr%d <= %.15G ", pApp->scr_CLS[i].a[j],j-1,j-1, pApp->scr_CLS[i].b[j]);
					strcat(	szSql, temp	);
					strcat(	szSql, ") AND (" );
				}

				sprintf(temp, " %.15G <= attr%d AND attr%d <= %.15G ", pApp->scr_CLS[i].a[COL_NUM],COL_NUM-1,COL_NUM-1, pApp->scr_CLS[i].b[COL_NUM]);
				strcat(	szSql, temp	);
			strcat(	szSql, ") ) "	);

			//select tuples from scr_CLS[i]
			
			ituples_cnt = pApp->zlExeSelect_LRC(0, 0, szSql, pApp->scr_CLS, i);

			pApp->iSum_SCR_TuplesCount += ituples_cnt;
			pApp->scr_CLS[i].tplNum = ituples_cnt;
		}
	}

//--- body end --------------
 return bReturn;

}

bool CMainFrame::zlInsertKBProfile(QUERY Qry)
{			       
	bool bReturn =false;

	CLearnIing6App * pApp = (CLearnIing6App * ) AfxGetApp();

	int c = 1;
	int d = GetTickCount();
	//int iFactor = d - d/2;
	int i, j, ii, jj;

	char	cAttribute[COL_NUM+7][50];

	for(ii=0; ii<COL_NUM + 7; ii++)
		for(jj=0; jj< 50; jj++)
			cAttribute[ii][jj]=0;

	for(ii=0; ii<COL_NUM ; ii++)
		sprintf(cAttribute[ii],	"%G", Qry.x[ii] );

	sprintf(cAttribute[COL_NUM],  "%ld", Qry.N);
	sprintf(cAttribute[COL_NUM+1],"%.15G", Qry.r_Opt);
	sprintf(cAttribute[COL_NUM+2],"%ld", Qry.f_Opt );
	sprintf(cAttribute[COL_NUM+3],"%ld", c); //c*iFactor
	sprintf(cAttribute[COL_NUM+4],"%ld", d);
	sprintf(cAttribute[COL_NUM+5],"%ld", Qry.longTicks);
	sprintf(cAttribute[COL_NUM+6],"%ld", Qry.shortTicks);

/////////////////////////////

	CString cStrInsert;
    cStrInsert.Empty();

	cStrInsert = " INSERT ";
	cStrInsert += m_KBProfileTable; //m_InsertTable; 
	cStrInsert += " VALUES (";
	for(j=0; j< COL_NUM+7-1; j++)
	{
		cStrInsert += cAttribute[j];
		cStrInsert += ",";
	}
	cStrInsert += cAttribute[COL_NUM+7-1];

	cStrInsert += " ) ";

	int istrSelectLenth = cStrInsert.GetLength() + 1;

	bReturn = pApp->zlExeInsertTable(cStrInsert.GetBuffer(istrSelectLenth) );			
   
	if(bReturn)
	{

		for(i = 0; i<COL_NUM; i++)
		{
			Z[iRowCnt_KBP].x[i] = Qry.x[i];						
		}
		
		Z[iRowCnt_KBP].N		= Qry.N;
		Z[iRowCnt_KBP].r		= Qry.r_Opt;
		Z[iRowCnt_KBP].f		= Qry.f_Opt;
		Z[iRowCnt_KBP].c		= c; //c*iFactor;
		Z[iRowCnt_KBP].d		= d;

		iRowCnt_KBP ++;
        //AfxMessageBox("pApp->zlExeInsertTable ---- OK !");
	}
	else
		AfxMessageBox("KB pApp->zlExeInsertTable ---- ERROR !!!!!");

	/////////// ---------- body end ---------------

	return bReturn;
}

bool CMainFrame::zlUpdateKBProfile(QUERY Qry)
{			       
	bool bReturn =false;
	CLearnIing6App * pApp = (CLearnIing6App * ) AfxGetApp();

	int c = 1;
	int d = GetTickCount();
	int iFactor = 60000; //the is 1 minute = 60000 ms //d - d/2;
	int i, j, ii, jj;

	char cAttribute[COL_NUM+7][50];
    char szCondition[1024] = "";

	double minPriorty = 0.0;
	int iminPrNum = -1;
	int w =0;  // the current system time 

//------- 1. Find out Z with minimun priority.  
    double temPry =0.0;

	w = GetTickCount();

	temPry = (c*iFactor)/(fabs(w-Z[0].d) +1);
    minPriorty = temPry;
    iminPrNum = 0;
	for(i = 1; i<iRowCnt_KBP; i++)
	{
		temPry = (c*iFactor)/(fabs(w-Z[i].d) +1);
		if(temPry <minPriorty)
		{
			minPriorty = temPry;
			iminPrNum = i;
		}
	}




///////////////
	for(ii=0; ii<COL_NUM + 7; ii++)
		for(jj=0; jj< 50; jj++)
			cAttribute[ii][jj]=0;

	for(ii=0; ii<COL_NUM ; ii++)
		sprintf(cAttribute[ii],	"attr%i = %G", ii, Qry.x[ii] );

	sprintf(cAttribute[COL_NUM],  "N = %ld", Qry.N);
	sprintf(cAttribute[COL_NUM+1],"r = %.15G", Qry.r_Opt);
	sprintf(cAttribute[COL_NUM+2],"f = %ld", Qry.f_Opt );
	sprintf(cAttribute[COL_NUM+3],"c = %ld", c);
	sprintf(cAttribute[COL_NUM+4],"d = %ld", d);
	sprintf(cAttribute[COL_NUM+5],"longTicks = %ld", Qry.longTicks);
	sprintf(cAttribute[COL_NUM+6],"shortTicks = %ld", Qry.shortTicks);

	sprintf(szCondition," WHERE c = %ld AND d = %ld", Z[iminPrNum].c, Z[iminPrNum].d);

  /////////////
	CString cStrUpdate;
	cStrUpdate.Empty();
		
	cStrUpdate = " UPDATE ";
	cStrUpdate += m_KBProfileTable;
	cStrUpdate += " SET " ;						

	for(j=0; j< COL_NUM+7-1; j++)
	{
		cStrUpdate += cAttribute[j];
		cStrUpdate += ",";
	}
	cStrUpdate += cAttribute[COL_NUM+7-1];

	cStrUpdate += szCondition;

	int istrSelectLenth = cStrUpdate.GetLength() + 1;

	bReturn = pApp->zlExeInsertTable(cStrUpdate.GetBuffer(istrSelectLenth) );			


///////////////

	if(bReturn)
	{

		for(i = 0; i<COL_NUM; i++)
		{
			Z[iminPrNum].x[i] = Qry.x[i];						
		}
		
		Z[iminPrNum].N		= Qry.N;
		Z[iminPrNum].r		= Qry.r_Opt;
		Z[iminPrNum].f		= Qry.f_Opt;
		Z[iminPrNum].c		= c; //c*iFactor;
		Z[iminPrNum].d		= d;

		//iRowCnt_KBP ++;
        //AfxMessageBox("pApp->zlExeInsertTable ---- OK !");
	}
	else
		AfxMessageBox("Update KBpApp->zlExeInsertTable ---- ERROR !!!!!");
       
	/////////// ---------- body end ---------------

	return bReturn;
}

int CMainFrame::zlExeSelect(QUERY Query)
{

	CLearnIing6App * pApp = (CLearnIing6App * ) AfxGetApp();

	int iRowCnt = -1;
    int iTupleNum;

	double fCol[COL_NUM+1];		//Elevation
	SDWORD cbCol[COL_NUM+1]; 	
	SDWORD sColID =0; 
	SDWORD cbColID =0; 
	int iQryIdx = 0;
	char tmp[512];
	char temp[1024];
	int i, j;

    ZLRECT S;
    int n = COL_NUM;
	double VFactor;
	if(n==104)
	  VFactor = 5.0 * pow(10, 37);
	else if(n==50)
	  VFactor = pow(10, 34); // (30 +38)/2=34
	else if(n==25)
	  VFactor = pow(10, 31); // (24 +38)/2=31

        //-------------------------
		if(n == 2 )
		{
			S.a[1] = Query.x[0] - Query.r ; 
			S.b[1] = Query.x[0] + Query.r; 
			S.a[2] = Query.x[1] - Query.f ; 
			S.b[2] = Query.x[1] + Query.f; 
		}
		else if(n == 3)
		{

			S.a[1] = Query.x[0] - Query.r ; 
			S.b[1] = Query.x[0] + Query.r; 
			S.a[2] = Query.x[1] - Query.f ; 
			S.b[2] = Query.x[1] + Query.f; 
			S.a[3] = Query.x[2] - Query.f_rst ; 
			S.b[3] = Query.x[2] + Query.f_rst; 

		}
		else 
		{
			for(j= 1; j <=n; j++)
			{
				S.a[j] = Query.x[j-1] - Query.r ; 
				S.b[j] = Query.x[j-1] + Query.r; 

			}

		}
		
		
		    for(j= 1; j <=n; j++)
			{

				if(S.a[j] < pApp->dMin[j])
					S.a[j] = pApp->dMin[j];

				if(S.b[j] > pApp->dMax[j])
					S.b[j] = pApp->dMax[j];
			}
			S.v =1;
			if(n < 25)
			{
				for(j=1; j<=n; j++)
				{
					S.v *= (S.b[j]-S.a[j]);
				}
			}
			else
			{
				for(j=1; j<=n; j++)
				{
					S.v *= ( (S.b[j]-S.a[j])/VFactor );
				}
				
			}
		   //-----------------

	/////////////////////////////////////////////////////
	SQLFreeStmt(hstmt, SQL_DROP);
	retcode = SQLAllocStmt(hdbc, &hstmt); ///Statement handle 
	if(retcode != SQL_SUCCESS)
	{
		return -1;
	}

	SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
	SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);

	char * szSql = new char[8092000];
	strcpy(szSql, "");

    	strcpy(	szSql, 	" SELECT * FROM ");
		strcat(	szSql, 	m_DataSetTable );
        /***
		strcat(	szSql, 	" where ( ( ");
			
			for(j=0; j<COL_NUM-1; j++)
			{
				sprintf(temp, " %.15G <= attr%d AND attr%d <= %.15G ", Query.x[j]-r,j,j, Query.x[j]+r);
				strcat(	szSql, temp	);
				strcat(	szSql, ") AND (" );
			}

			sprintf(temp, " %.15G <= attr%d AND attr%d <= %.15G ", Query.x[COL_NUM-1]-r,COL_NUM-1,COL_NUM-1, Query.x[COL_NUM-1]+r);
			strcat(	szSql, temp	);

		strcat(	szSql, ") ) "	);
		*****/
		//------
		strcat(	szSql, 	" where ( ( ");						
			for(j=1; j<=COL_NUM-1; j++)
			{
				sprintf(temp, " %.15G <= attr%d AND attr%d <= %.15G ", S.a[j],j-1,j-1, S.b[j]);
				strcat(	szSql, temp	);
				strcat(	szSql, ") AND (" );
			}
			sprintf(temp, " %.15G <= attr%d AND attr%d <= %.15G ", S.a[COL_NUM],COL_NUM-1,COL_NUM-1, S.b[COL_NUM]);
			strcat(	szSql, temp	);
		strcat(	szSql, ") ) "	);


		//-------

	retcode = SQLExecDirect(hstmt, (unsigned char *)szSql, SQL_NTS);  //2005.02.07

	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
	{  //	retcode = SQLExecDirect
		
		int iRowCount;
		SDWORD *  RowCountPtr = new SDWORD ;
		retcode = SQLRowCount(hstmt, RowCountPtr);						 
		iRowCount = * RowCountPtr;
		delete RowCountPtr;
		iRowCnt = iRowCount;
		iTupleNum = iRowCount;

		delete [] tpl;
		tpl = new TUPLE[iRowCount+1];

//==================
		for( i = 0; i <COL_NUM+1; i++)
		{
			fCol[i] =0.0;
			cbCol[i] = 0; 
		}
		// Bind columns 1,2,3,4 ,.., 105
			for(i = 0; i <COL_NUM; i++)
					SQLBindCol(hstmt, i+1, SQL_C_DOUBLE, &fCol[i],0, &cbCol[i]); //SQL_C_SSHORT			
			SQLBindCol(hstmt, COL_NUM+1, SQL_C_SLONG, &sColID,0, &cbColID); //SQL_C_SSHORT
					
		iRowCount =0;

		while (TRUE) 
		{
			retcode = SQLFetch(hstmt);

			if (retcode == SQL_ERROR)
			{
				//show_error();
				wsprintf(tmp, "%ld", iRowCount);
				//int i = iRowCount;
				AfxMessageBox("SQLFetch Error !!!!!!");
						//break; //99.8.26
			}

			if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
			{
				
				for(i = 0; i<COL_NUM; i++)
				{
					tpl[iQryIdx].x[i] = fCol[i];
				}
				
				tpl[iQryIdx].ID		= sColID;
		
				iQryIdx++;
				if(retcode == SQL_SUCCESS_WITH_INFO)
				{
					wsprintf(tmp, "%ld", retcode);
					AfxMessageBox(tmp);
				}
					
			} 
			else 
			{
				break;
			}

		}   ///while (TRUE)
//================
	}

	delete [] szSql;
	//zlCloseDB();
	//----- body  end -----------------
	return iRowCnt;

}

int CMainFrame::zlGettheIntersection(ZLRECT * cell, QUERY Query, int n)
{  

	CLearnIing6App * pApp = (CLearnIing6App * ) AfxGetApp();

	int  SectNum=0;
	double q=0.0, p=0.0;
	bool bInterable=false;
	bool bshink=false;
    int i, j;

    ZLRECT   sect;
	ZLRECT   S;
    double dBeta[COL_NUM+1];
    double dWight = 1;


	double VFactor;
	if(n==104)
	  VFactor = 5.0 * pow(10, 37);
	else if(n==50)
	  VFactor = pow(10, 34); // (30 +38)/2=34
	else if(n==25)
	  VFactor = pow(10, 31); // (24 +38)/2=31
  
	for( i=1; i<=n; i++)
	{   
	   dBeta[i] = 1;
    }


	//-------------------------
	if(n == 2 )
	{
		S.a[1] = Query.x[0] - Query.r ; 
		S.b[1] = Query.x[0] + Query.r; 
		S.a[2] = Query.x[1] - Query.f ; 
		S.b[2] = Query.x[1] + Query.f; 
	}
	else if(n == 3)
	{

		S.a[1] = Query.x[0] - Query.r ; 
		S.b[1] = Query.x[0] + Query.r; 
		S.a[2] = Query.x[1] - Query.f ; 
		S.b[2] = Query.x[1] + Query.f; 
		S.a[3] = Query.x[2] - Query.f_rst ; 
		S.b[3] = Query.x[2] + Query.f_rst; 

	}
	else 
	{
		for(j= 1; j <=n; j++)
		{
			S.a[j] = Query.x[j-1] - Query.r ; 
			S.b[j] = Query.x[j-1] + Query.r; 

		}

	}
	
	
		for(j= 1; j <=n; j++)
		{

			if(S.a[j] < pApp->dMin[j])
				S.a[j] = pApp->dMin[j];

			if(S.b[j] > pApp->dMax[j])
				S.b[j] = pApp->dMax[j];
		}
		S.v =1;
		if(n < 25)
		{
			for(j=1; j<=n; j++)
			{
				S.v *= (S.b[j]-S.a[j]);
			}
		}
		else
		{
			for(j=1; j<=n; j++)
			{
				S.v *= ( (S.b[j]-S.a[j])/VFactor );
			}
			
		}
	  //-----------------
     v=S.v;
    sect.v = 1;

    for( i=1; i<=n; i++)
	{
		p = max(cell->a[i], S.a[i]);
		q = min(cell->b[i], S.b[i]);
		if(p<q) //the intersection is not empty
		{

			sect.a[i] = p;
		    sect.b[i] = q;

			if(n<25)
			{
				sect.v *= (q-p);
			}
			else
			{
				sect.v *= (q-p)/VFactor;
			}


			bInterable = true;
		} //if(p<q)
		else if(q==p)
		{	
			if((cell->b[i] != cell->a[i]))//&&(cell->b[i] - cell->a[i]>1))
			{
			   dBeta[i] = 1.0 /(cell->b[i]-cell->a[i]);
			}

			bInterable=true;
			bshink=true;
			
		}else//the intersection is empty or p=q
		{
			sect.v = 0.0; //where the last l, where some (q-p)>0 
			bInterable = false;
			break;
		}
       
	} //for(i=1; i<=n, i++)
    
/*	for(i=1; i<=n; i++)
	{
	   dWight *=  dBeta[i];	
	} */



    if(bInterable)
	{
		if (bshink) 
		{
             dWight=sect.v/cell->v;
             SectNum =max(1, cell->cn * (dWight/cell->v));
		}
		else
		{
            if (sect.v!=0)
			{
             SectNum = cell->cn*(sect.v/cell->v);
			}
			else
			{
				SectNum++;
			}
		}
     cell->suf1st=2;
	}
	else
	{
		SectNum=0;
	}

	return SectNum;

}

int CMainFrame::LearningHD(int partNum, ZLRECT *T, int n, int m, ZLRECT **pointcell)
{    
	
		int i,iEstimateNum,ituples_count,k,j,i1,k1,j1,ma1,ma2,ma3,sum;
	int CirNum=partNum;
//	ZLRECT  *sect=new ZLRECT[2*n+1];
	ZLRECT S;
    int q,p;
	int lPartNum=partNum;
	bool bintersect=false,bInterable;
    CLearnIing6App * pApp = (CLearnIing6App * ) AfxGetApp();
	int idx[2*COL_NUM+1];
	double VFactor;
	if(n==104)
	  VFactor = 5.0 * pow(10, 37);
	else if(n==50)
	  VFactor = pow(10, 34); // (30 +38)/2=34
	else if(n==25)
	  VFactor = pow(10, 31); // (24 +38)/2=31
   double center;
	QUERY  Q1;
	ZLRECT sect;
	int varyNum=0;
for (i=1;i<300;i++)
	{

	//-------------------------
	if(n == 2 )
	{
		S.a[1] = Q[i].x[0] - Q[i].r ; 
		S.b[1] = Q[i].x[0] + Q[i].r; 
		S.a[2] = Q[i].x[1] - Q[i].f ; 
		S.b[2] = Q[i].x[1] + Q[i].f; 
	}
	else if(n == 3)
	{

		S.a[1] = Q[i].x[0] - Q[i].r ; 
		S.b[1] = Q[i].x[0] + Q[i].r; 
		S.a[2] = Q[i].x[1] - Q[i].f ; 
		S.b[2] = Q[i].x[1] + Q[i].f; 
		S.a[3] = Q[i].x[2] - Q[i].f_rst ; 
		S.b[3] = Q[i].x[2] + Q[i].f_rst; 

	}
	else if(n==4)
	{
        S.a[1] = Q[i].x[0] - Q[i].N ; 
		S.b[1] = Q[i].x[0] + Q[i].N; 
		S.a[2] = Q[i].x[1] - Q[i].r ; 
		S.b[2] = Q[i].x[1] + Q[i].r; 
		S.a[3] = Q[i].x[2] - Q[i].f ; 
		S.b[3] = Q[i].x[2] + Q[i].f; 
		S.a[4] = Q[i].x[3] - Q[i].f_rst ; 
		S.b[4] = Q[i].x[3] + Q[i].f_rst; 

	}else
	{
		for(j= 1; j <=n; j++)
		{
			S.a[j] = Q[i].x[j-1] - Q[i].r ; 
			S.b[j] = Q[i].x[j-1] + Q[i].r; 

		}

	}
	        
	
	
		iEstimateNum=0;
		ituples_count=0; 

		int count1;
		ituples_count = zlExeSelect(Q[i]);
		for(k=1;k<=CirNum;k++)
		{
      iEstimateNum += zlGettheIntersection(*pointcell+k-1, Q[i], n);
		}
		count1=abs(ituples_count-iEstimateNum);
   if (count1/(ituples_count+1)>=1 || count1/(iEstimateNum+1)>=1)
		
   {
		
			for(k=1;k<=CirNum;k++)
			{    
				if(((*pointcell)[k].suf1st==2 ) && ((*pointcell)[k].sufend ==0))
				{    sect.v=1;
				      ma1=0;
					  ma2=0;
					  ma3=0;
					for( j=1; j<=n; j++)
					{
						p = max((*pointcell)[k].a[j], S.a[j]);
						q = min((*pointcell)[k].b[j], S.b[j]);
						
						if(p<q) //the intersection is not empty
						{  
						  Q1.x[j-1]=(q-p)/2;
						  if(j==1){Q1.r=(q-p)/2+1;}
                          if(j==2){Q1.f=(q-p)/2+1;}
						  if(j==3){Q1.f_rst=(q-p)/2+1;}
						  sect.v*=q-p;
						  sect.a[j]=p;
						  sect.b[j]=q;
						  	bintersect=true;
						
						}
						else
						{
							break;
							bintersect=false;
						}
					}

						if(bintersect)
						{   
							ituples_count = zlExeSelect(Q1);
                           	iEstimateNum +=(*pointcell)[k].cn*(sect.v/(*pointcell)[k].v) ;
							count1=abs(ituples_count-iEstimateNum);
                           if (count1/(ituples_count+1)>=1 || count1/(iEstimateNum+1)>=1)
						   {
							   varyNum=pApp->zlDiffRects(((*pointcell)[k]),sect,n);
							   if(varyNum)
							   {  sum=0;
								   for(i1=1;i1<=n;i1++)
								   {
                                      (*pointcell)[k].a[i1]=sect.a[i1];

                                      (*pointcell)[k].b[i1]=sect.b[i1];

								       (*pointcell)[k].v=sect.v;
								   }
								   for(j=1;j<=n;j++)
								   {
									   idx[j]=0;
								   }

                            for(j1= 1; j1<= varyNum ; j1++)
							{
								pApp->ss[j1].v=1;
						                       
                               for(j= 1; j <=m ; j++) // m is the number of T[i]'s
							   {
								//###########
								if(T[j].bsn ==k ) //?? add .cn !=0 , Not, repeat
								{		ma1++;		 //YES! do it here
									
										
										for(k1=1; k1<=n; k1++) //n is the number of dimensions 
										{
											
											center = (double)(T[j].a[k1] + T[j].b[k1])/2.0;
											
											if( (pApp->ss[j1].a[k1]<=center) && (pApp->ss[j1].b[k1]) ) //the Center in the part[i]
											{
												bInterable = true;
											} 
											else 
											{
												bInterable = false;
												break;   //break k 
											}
											
										}//for(k=1; k<=n; k++)
										
										if(bInterable) //if intersectable
										{
											idx[j1]++;   
											if((j1==1)&&(!ituples_count))
											{
                                                 T[j].bsn =k;  
											}
											
											else{
                                              T[j].bsn = partNum+1;
											  ma2++;
											
											}
										}//if(bInterable) //if intersectable
									
									}// for(i= 1; i<=12; i++)
															
							   }//if(T[j].cn <=0 )
							   if(idx[j1]>1)
							   {
								   if((j1==1)&&(!ituples_count))
								   {
                                       (*pointcell)[k].v=1;
                                      for(i1=1;i1<=n;i1++)
								   {
                                      (*pointcell)[k].a[i1]=pApp->ss[j1].a[i1];

                                      (*pointcell)[k].b[i1]=pApp->ss[j1].b[i1];

								       (*pointcell)[k].v=pApp->ss[j1].b[i1]-pApp->ss[j1].a[i1];
								   }
								   }
								   else
								   {
								   partNum++;
								   }
								   
							   }	
							   sum+=idx[j1];
							   
							}
                            (*pointcell)[k].cn -=sum;
				
					       
							}
						   }
						}
						
					}
					
					
					
			 }
		 }
      }


	return partNum;

}

ZLRECT* CMainFrame::CountCell(ZLRECT *T, int &PartNum, int m, int n)
{
	
	ZLRECT *  cell = new ZLRECT[PartNum+1];
    int k,j,i;
	double dMin[COL_NUM+1]; 
	double dMax[COL_NUM+1];
   CLearnIing6App * pApp = (CLearnIing6App * ) AfxGetApp();
   // get domain rect
	for(i=1; i<=n; i++ )
	{
	
		dMin[i] = pApp->dMin[i];
		dMax[i] = pApp->dMax[i]+1;

	}
//	int k1=0;j1=0;
    double VFactor;
	if(n==104)
	  VFactor = 5.0 * pow(10, 37);
	else if(n==50)
	  VFactor = pow(10, 34); // (30 +38)/2=34
	else if(n==25)
	  VFactor = pow(10, 31); 

	for(k=1; k<=PartNum; k++)
	{
		  cell[k].cn = 0;   // the count number of the tuples that are in this cell[k]
		  cell[k].suf1st=0;
          cell[k].sufend=0;
		  for(i=1; i<=n; i++ )
		  {
			 cell[k].a[i] = dMax[i];
			 cell[k].b[i] = dMin[i];
		  }

			for(j=1 ; j<=m; j++ )	
			{
				if(T[j].bsn == k ) // T[j] is in the cell[k]	        
				{    

				   for(i=1; i<=n; i++ )
				   {
						cell[k].a[i] = min(cell[k].a[i], T[j].a[i]);
						cell[k].b[i] = max(cell[k].b[i], T[j].b[i]);
				   }//for i

				   cell[k].cn ++;

				}//if

			}//for j
	}//for k
/////////////
	//--get the v of each cell
	for(k=1; k<=PartNum; k++)
	{
        cell[k].v = 1; 
		if(n < 25)
		{
			for(j=1; j<=n; j++)
			{
				if(cell[k].b[j] > cell[k].a[j])
				    cell[k].v *= (cell[k].b[j]- cell[k].a[j]);
			}
		}
		else
		{
			for(j=1; j<=n; j++)
			{
				if(cell[k].b[j] > cell[k].a[j])
				     cell[k].v *= ( (cell[k].b[j]-cell[k].a[j])/VFactor );
			}
			
		}
	
	}
	for (i=1;i<=PartNum;i++)
	{
	if((cell[i].cn<5)&&((cell[i].cn/cell[i].v)<1/1000))
	{
       for(j=i;j<PartNum;j++)
	   {
	 
		   for(k=1;k<=n;k++)
		   {
			   cell[j].a[k]=cell[j+1].a[k];
			  cell[j].b[k]=cell[j+1].b[k];
              cell[j].v=cell[j+1].v;
			  cell[j].cn=cell[j=1].cn;
		   }
	   }
       PartNum--;
	}

	}	   

	return  cell;

}

void CMainFrame::OnGeneraterCover4dworkload() 
{
	// TODO: Add your command handler code here
	
	int i,j,iErr = 0;
	char tmp[100] = "";
	CString CStrInsert = ""; 
	
	double  fCol[COL_NUM+1];		//Elevation
	SDWORD cbCol[COL_NUM+1]; 
    int r1,r2,r3,r41;
	int   iColID;	
	SDWORD cbColID; 
	char c[COL_NUM+7][100];
	int iTotalNum = 0;
	char szSQL[20480] = "" ;
	
	int iSizeSmpl = 2000; 

	
	srand( (unsigned)time( NULL ) );
	int iRowCount=0;	
	int iRandom = rand();

		if(!zlOpenDB())
		{
			AfxMessageBox("zlOpenDB() err!");
			zlCloseDB();
		}else
		{
			//1111111111111 read data base 111111111111111

			do
			{
				iRowCount=0;	
				iRandom = rand();
				r1=rand()%((3006-1859)/2);
				r2=rand()%180;
				r3=rand()%32;
				
			
			    strcpy(szSQL, " SELECT * FROM Attr_Cover4D WHERE Cover4DID = ");
			    
				sprintf(tmp, "%ld", (iRandom*20 +iRandom + iRandom%10 )%300000  );
				
				
				strcat(szSQL, tmp);
				
				SQLFreeStmt(hstmt, SQL_DROP);
				retcode = SQLAllocStmt(hdbc, &hstmt); ///Statement handle 
				if(retcode != SQL_SUCCESS)
					AfxMessageBox("retcode != SQL_SUCCESS"); //return -1;

				SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
				SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
				
				retcode = SQLExecDirect(hstmt, (unsigned char *)szSQL, SQL_NTS);  //2005.02.07
				if ((retcode == SQL_SUCCESS) || retcode == SQL_SUCCESS_WITH_INFO ) 
				{    //	retcode = SQLExecDirect
					SDWORD *  RowCountPtr = new SDWORD;
					retcode = SQLRowCount(hstmt, RowCountPtr);						 
					iRowCount = * RowCountPtr;
					delete RowCountPtr;
					
					
					
					for(i = 0; i < COL_NUM; i++)
						SQLBindCol(hstmt, i+1, SQL_C_DOUBLE, &fCol[i],0, &cbCol[i]); //SQL_C_SSHORT
					
					SQLBindCol(hstmt, COL_NUM+1, SQL_C_DOUBLE, &iColID,0, &cbColID); //SQL_C_SSHORT


					retcode = SQLFetch(hstmt);
					
					if( iRowCount ==1 && (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) )
					{
						r41=(rand()%3250);
						for(i=0; i<COL_NUM+7;i++)
							for(j=0;j<100;j++)
								c[i][j] = 0;

						for(i=0; i< COL_NUM;i++)
								sprintf(c[i],"%G",fCol[i]);

						 sprintf(c[COL_NUM],"%ld",r1);
                         sprintf(c[COL_NUM+1],"%ld",r2);
                         sprintf(c[COL_NUM+2],"%ld",r3);
                         sprintf(c[COL_NUM+3],"%ld",r41);
                         sprintf(c[COL_NUM+4],"%ld",0);
                         sprintf(c[COL_NUM+5],"%ld",0); 
						 sprintf(c[COL_NUM+6],"%ld",0); 

						CStrInsert = "Insert into ";
						
                       CStrInsert += "Cover4D_WorkLoad_1_rf_Q1000 VALUES( ";


						for(i=0; i< COL_NUM+6;i++)
						{
							CStrInsert += c[i];
							CStrInsert += ",";

						}							
					    CStrInsert +=c[COL_NUM+6];
						CStrInsert += ")";

						SQLFreeStmt(hstmt, SQL_DROP);
						retcode = SQLAllocStmt(hdbc, &hstmt); ///Statement handle 
						if(retcode != SQL_SUCCESS)
							AfxMessageBox("retcode != SQL_SUCCESS 222"); //return -1;

						SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
						SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
						retcode = SQLExecDirect(hstmt, (unsigned char *)CStrInsert.GetBuffer(CStrInsert.GetLength() +1), SQL_NTS);


						if (retcode == SQL_SUCCESS||retcode == SQL_SUCCESS_WITH_INFO) 
							iTotalNum ++;
						else
							iErr++;
					}
				
				}
				if(iTotalNum >=iSizeSmpl)
					break;	
			}while(true);

		//111111111111111111 read data base end111111111111

		}


	//SQLFreeStmt(hstmt, SQL_DROP);
	zlCloseDB();

	AfxMessageBox("Insert Lsi_smpl_Bworkload OK!");
	
}
