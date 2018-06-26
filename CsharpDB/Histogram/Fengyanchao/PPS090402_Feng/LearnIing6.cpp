// LearnIing6.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "LearnIing6.h"

#include "MainFrm.h"
#include "LearnIing6Doc.h"
#include "LearnIing6View.h"
#include "TableName.h"  //zl add 

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

////////////// zl veriable defination start //////////////////////

	HENV    henv;
	HDBC    hdbc;
	HSTMT   hstmt;
	RETCODE retcode;

	UCHAR sz_DSN[20]; //= "DSN_MULTopN";
	UCHAR sz_UID[10]; //= "sa";
	UCHAR sz_PWD[10]; // = "123";

////////////// zl veriable defination end //////////////////////


/////////////////////////////////////////////////////////////////////////////
// CLearnIing6App

BEGIN_MESSAGE_MAP(CLearnIing6App, CWinApp)
	//{{AFX_MSG_MAP(CLearnIing6App)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLearnIing6App construction

bool zlOpenDB()
{
    bool bReturn = false;
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

bool zlCloseDB()
{
	SQLFreeStmt(hstmt, SQL_DROP); //2005.3.7
	SQLDisconnect(hdbc);
	SQLFreeConnect(hdbc);
	SQLFreeEnv(henv);

	return true;
}




CLearnIing6App::CLearnIing6App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
    iSum_SCR_TuplesCount = 0;
	Q   = new RESULT_LEARNING[WORKLOAD_NUM +1];
	tpl = new TUPLE [10]; 
	t   = new TUPLE [10]; 
    Sum_v_T = new double [2];  
	scr_CLS = new ZLRECT [2]; 
	deepNum=0;
	it_list_cnt =0;
	clsNum = 1;
	issNum = 10000;
	iIO_Num = 0;
	scr = new ( TUPLE *[clsNum +1] );  
	for(int i = 0; i<=clsNum; i++)
			scr[i] = new TUPLE[2];

	//tuple = new ( TUPLE *[issNum +1] );  
	//for(i = 0; i<=issNum; i++)
			//tuple[i] = new TUPLE[2];


}

CLearnIing6App::~CLearnIing6App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
    delete [] tpl;
	delete [] t;
    delete [] Q;
    delete [] Sum_v_T ;  
	delete [] scr_CLS ;  

	for(int i = 1; i<=clsNum; i++)
		delete [] scr[i];
	delete [] scr;

	//for(i = 0; i<=issNum; i++)
		//delete []	tuple[i];
	//delete [] tuple ;  


    zlCloseDB();
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CLearnIing6App object

CLearnIing6App theApp;
int Numofworkld;


/////////////////////////////////////////////////////////////////////////////
// CLearnIing6App initialization

BOOL CLearnIing6App::InitInstance()
{

	strcpy((char *)sz_DSN , "DSN_Selectivity"); //DSN_QueryStream, DSN_MULTopN, DSN_Census2D
	strcpy((char *)sz_UID , "sa");
	strcpy((char *)sz_PWD , "123"); //txgstxh

	//get table names
	bool bReturn = false;
	CTableName InputTableName;
	int nResponse = InputTableName.DoModal();
	if (nResponse != IDOK)
		return bReturn;


    

////////////////////////////////////////////////
	SDWORD cbdMin[COL_NUM+1]; 
	SDWORD cbdMax[COL_NUM+1]; 
	char temp[512] = "";
    char szSql[20480] = "";
	bool brtn;
/////////////////////////////////

//configure the 'max server memory' to be 
	//5MB for Lsi50D, 
	//8MB for Lsi104D, and
	//4MB for the other datasets. 
//Note that 4MB is the smallest value for the 'max server memory' in Microsoft's SQL Server 2000.

//---Set the max memory: 4 for n<=25D; 8 for n= 50D and 104D
//* 2007.03.04 *
 //if( zlStartSQLservr() )
 {
	//AfxMessageBox(" zlStartSQLservr OKOK!");

	if(!zlOpenDB())
	{
		AfxMessageBox("zlOpenDB() err!");
		zlCloseDB();
	}

 }
 //strcpy(szSql, " SELECT * FROM Census2D_Top100_Profile2000_LRC ");
 //int iiiw =	zlExeSelect(0, szSql);

 //brtn = zlExeInsertTable(szSql);

strcpy(szSql, "USE master \
 EXEC sp_configure 'show advanced option', '1' \
 RECONFIGURE \
 EXEC sp_configure \
 EXEC sp_configure 'min server memory', '16' \
 RECONFIGURE WITH OVERRIDE \
 EXEC sp_configure 'max server memory', '128' \
 RECONFIGURE WITH OVERRIDE USE MulTopN ");
 //--- Note: here database is MulTopN, not QueryStream
   
 brtn = zlExeInsertTable(szSql);

if(!zlOpenDB())
{
	AfxMessageBox("zlOpenDB() err!");
	zlCloseDB();
}
//--- Note: here database is QueryStream


//* 2007.03.04 */
//--- Set the max memory 

 //strcpy(szSql, " SELECT * FROM Census2D_Top100_Profile2000_LRC ");
 //iiiw =	zlExeSelect(0, szSql);

 //brtn = zlExeInsertTable(szSql);


//AfxMessageBox("Please Press Menu LRC_Method !!!!!");

	/////-------------------///
	// select min_r = min(r), max_r=max(r) from Lsi_104D_T0020_B_Learning_P0954
	// min_r =4.6172599999999998E+35	max_r = 2.6505389999999999E+38
    
	// select min_r = min(r), max_r=max(r) from Lsi_104D_Top20_B_OPT
	// min_r =4.6172599999999998E+35	max_r = 2.6505389999999999E+38
    
	//--select min_r = min(r), max_r=max(r) from Lsi_050D_Top20_B_OPT
    //2.9585405002040003E+30	2.7410999999999999E+38
	
	//--select min_r = min(r), max_r=max(r) from Lsi_025D_Top20_B_OPT
	//2.6719500000000002E+24	1.9829800636436002E+38

	for(int i = 0; i <COL_NUM; i++)
	{
		//sprintf(temp, "SELECT MIN(attr%d) FROM  Lsi_104D ", i);
		sprintf(temp, "SELECT MIN(attr%d) FROM ", i);
	
		//[1]	-3.3708000000000e+038

		//sprintf(temp, "SELECT MIN(abs(attr%d)) FROM  Lsi_104D ", i);
			//[7]	1.2618000000000e-040
			//[8]	8.0154300000000e-043
	        //[9]	1.9146900000000e-040


		strcpy(szSql, temp);
		strcat(szSql, TableName);

		//----------
		SQLFreeStmt(hstmt, SQL_DROP);
		retcode = SQLAllocStmt(hdbc, &hstmt); ///Statement handle 
		if(retcode != SQL_SUCCESS)
			AfxMessageBox("1. Get m initial rectangles from DB, Error!" ); //return -1;
		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);	
		retcode = SQLExecDirect(hstmt, (unsigned char *)szSql, SQL_NTS);

		if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO ) 
		{    
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt, RowCountPtr);						 
			int iRowCount = * RowCountPtr;
			delete RowCountPtr;
					
			SQLBindCol(hstmt, 1, SQL_C_DOUBLE, &dMin[i+1],0, &cbdMin[i+1]); //SQL_C_SSHORT			
			
			//for(i = 0; i <COL_NUM; i++)
				//SQLBindCol(hstmt, COL_NUM+i+1, SQL_C_DOUBLE, &dMax[i],0, &cbdMax[i]); //SQL_C_SSHORT			

			retcode = SQLFetch(hstmt);
			
			if(iRowCount ==1 && (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) )
			{
			}
			else
			{
				AfxMessageBox("Err! select min from tablbe");
			}

		}
		//----------


	}
	for(i = 0; i <COL_NUM; i++)
	{
		//sprintf(temp, "SELECT MAX(attr%d) FROM  Lsi_104D ", i);
		sprintf(temp, "SELECT MAX(attr%d) FROM ", i);
		
		//	[1]	3.3708000000000e+038

		strcpy(szSql, temp);
		strcat(szSql, TableName);

		//----------
		SQLFreeStmt(hstmt, SQL_DROP);
		retcode = SQLAllocStmt(hdbc, &hstmt); ///Statement handle 
		if(retcode != SQL_SUCCESS)
			AfxMessageBox("1. Get m initial rectangles from DB, Error!" ); //return -1;
		SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
		SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);	
		retcode = SQLExecDirect(hstmt, (unsigned char *)szSql, SQL_NTS);

		if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO ) 
		{    
			SDWORD *  RowCountPtr = new SDWORD ;
			retcode = SQLRowCount(hstmt, RowCountPtr);						 
			int iRowCount = * RowCountPtr;
			delete RowCountPtr;
					
			//SQLBindCol(hstmt, 1, SQL_C_DOUBLE, &dMin[i],0, &cbdMin[i]); //SQL_C_SSHORT			
			
			//for(i = 0; i <COL_NUM; i++)
				//SQLBindCol(hstmt, COL_NUM+i+1, SQL_C_DOUBLE, &dMax[i],0, &cbdMax[i]); //SQL_C_SSHORT			
			SQLBindCol(hstmt, 1, SQL_C_DOUBLE, &dMax[i+1],0, &cbdMax[i+1]); //SQL_C_SSHORT			

			retcode = SQLFetch(hstmt);
			
			if(iRowCount ==1 && (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) )
			{
			}
			else
			{
				AfxMessageBox("Err! select max from tablbe");
			}

		}
		//----------

	}
		//AfxMessageBox("select min_max from tablbe!");

  //zlCloseDB();


//---Set the max memory 
//configure the 'max server memory' to be 
	//5MB for Lsi50D, 
	//8MB for Lsi104D, and
	//4MB for the other datasets. 
//Note that 4MB is the smallest value for the 'max server memory' in Microsoft's SQL Server 2000.

//* 2007.03.04 *
//4MB for  datasets <=25D, 8MB for 50D and 104D. 

/*
strcpy(szSql, "USE master \
 EXEC sp_configure 'show advanced option', '1' \
 RECONFIGURE \
 EXEC sp_configure \
 EXEC sp_configure 'min server memory', '0' \
 RECONFIGURE WITH OVERRIDE \
 EXEC sp_configure 'max server memory', '4' \
 RECONFIGURE WITH OVERRIDE USE MulTopN ");
 //--- Note: here database is MulTopN, not QueryStream

  brtn = zlExeInsertTable(szSql);

	if(!zlOpenDB())
	{
		AfxMessageBox("zlOpenDB() err!");
		zlCloseDB();
	}
*/

//* 2007.03.04 */
//--- Set the max memory 

  //AfxMessageBox("Please Press CN !!!!!");

		/////////----
					//CString cstrMarc;
					//cstrMarc = szSql;

					//CFile file;
					//if(file.Open("E:\\Paper2\\CLMB_census2D\\min_max .txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
					//{
					//	file.Write(cstrMarc, cstrMarc.GetLength() +1 );
					//}
					//file.Close();
		/////////----


//////////////////////////////////    zl                 ///////////////


	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CLearnIing6Doc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CLearnIing6View));
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it.
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

AfxMessageBox("Please Press Menu LRC_Method !!!!!");
	return TRUE;

}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CLearnIing6App::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CLearnIing6App message handlers
int CLearnIing6App::zlPartion_tt(ZLRECT Rect, int Dimention, ZLRECT * T, int T_Num, int PartNum)
{ //for test only

   PartNum =123456;
	return PartNum;
}


//for 2D
int CLearnIing6App::zlPartion( ZLRECT Rect, int Dimention, ZLRECT * T, int T_Num, int PartNum)
{
	int n = Dimention, m = T_Num;
	int i, j, k, idx[65];
	bool bInterable = false;
	char buffer[1024] = "";
	CString cstrMarc;
    int partmax;
    int partmin;
	int SumNum=0;
    bool  bpartion = true;
    // bool bfirst=true; 
	//ZLRECT part[13]; //we use 1-12
	ZLRECT part[65]; //we use 1-64
	ZLRECT scr;
  //  ZLRECT box[65];

	
	scr = Rect;

	//for(i=1; i<=12; i++)
	//{
		//part[i].a = new double[n+1];
		//part[i].b = new double[n+1];
	//}

	//int * a = new int[n+1];
	double * a = new double[n+1];

	double * d = new double[n+1];
	int alfa;


	//int bsn[1024 +1];
	//int bsn[WORKLOAD_NUM +1]; //the Big Set Number
	int * bsn = new int[m +1]; //the size of dataset used  

	//for(i=1; i<=1024; i++)
	//for(i=1; i<=WORKLOAD_NUM; i++)
	for(i=1; i<=m; i++)
	{
	   	bsn[i] = -1;
	}


	//int index[101][101];
	//int index[101][WORKLOAD_NUM +1];
	
	int * * index; 

	index = new (int *[101]);
	for(i= 0; i<=100; i++)
		//index[i] = new int[101];
		//index[i] = new int[WORKLOAD_NUM+1];
		index[i] = new int[m+1];

	for(i= 1; i<=100; i++)
	{
		//for(j=1; j<=100; j++)
		//for(j=1; j<=WORKLOAD_NUM; j++)
		for(j=1; j<=m; j++)
		{
			index[i][j] = 0;
		}
	}
	
   int l3 =0, l4=0;
   int Numcell =0;   //this is p



	
    //if(scr.b[1] - scr.a[1] <= scr.b[2] - scr.a[2] )
    if(scr.b[1] - scr.a[1] < scr.b[2] - scr.a[2] )
	{
		a[1] = scr.a[1]; 
		a[2] = scr.a[2]; 
        
        if(deepNum==0 )
		{
           l3 =4;
		   l4 = 10;             
		}
		else if(INT((scr.b[2] - scr.a[2] )/(scr.b[1] - scr.a[1] ))>40)
		{
           l3 =1;
		   l4 =40;
		   
		}else
		{
		
			l4=INT((scr.b[2] - scr.a[2] )/(scr.b[1] - scr.a[1] ));
			
			if(INT((scr.b[2] - scr.a[2] )/(scr.b[1] - scr.a[1] ))>20)
			{
             	l3=1;

			}
			else
			{
				l3=2;
			}

		}

		d[1] = (scr.b[1] - scr.a[1])/l3; 	
		d[2] = ( scr.b[2] - scr.a[2])/l4; 


	}
	else if(scr.b[1] - scr.a[1] > scr.b[2] - scr.a[2] )
	{
		a[1] = scr.a[1]; 
		a[2] = scr.a[2]; 

        if(deepNum==0)
		{
           l3 =10;
		   l4 = 4;             
		}
		else if(INT((scr.b[1] - scr.a[1] )/(scr.b[2] - scr.a[2] ))>40)
		{
		   
                l4 =1;
				l3 =40;
		   

		}else
		{
            
			l3=INT((scr.b[1] - scr.a[1] )/(scr.b[2] - scr.a[2] ));
			
			if(INT((scr.b[1] - scr.a[1] )/(scr.b[2] - scr.a[2] ))>20)
			{
             	l4=1;

			}
			else
			{
				l4=2;
			}
		}


		d[1] = (scr.b[1] - scr.a[1])/l3; 	
		d[2] = ( scr.b[2] - scr.a[2])/l4; 
	}
	else if(scr.b[1] - scr.a[1] == scr.b[2] - scr.a[2] )
	{
        l3 =4;
		l4 =4;
		d[1] = (scr.b[1] - scr.a[1])/l3; 	
		d[2] = ( scr.b[2] - scr.a[2])/l4; 
	}

   Numcell = l3*l4;

	for(i=1; i<=l3 ; i++)
	{
		for(j=1; j<=l4; j++)
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
				part[(i-1)*l4+j].a[k] = a[k]+ alfa*d[k];
				if(k!=l4)
				{
				part[(i-1)*l4+j].b[k] = a[k]+ alfa*d[k] + d[k];
				}
				else
				{
                  part[(i-1)*l4+j].b[k] =scr.b[k]; 
				}
			}
		}
	}
  

/*	for(k=1; k<=12; k++)
	{   
		 for(i=1; i<=n; i++ )
		  {
			 box[k].a[i] = part[k].b[i];
			 box[k].b[i] = part[k].b[i];
		  }
	
	}*/

	// we use the method of "Center IN " to clustering
	
	//ZLRECT * partT[101];
	//int clsNum =12; ////2005.3.24 , only for intersections

	double center =0.0;

	//for(i= 1; i<=12; i++)
	for(i= 1; i<=Numcell; i++)
	{
		sprintf(part[i].suffix, " Part[%i]: " , i ); 
		//?? for debug ? WHY part[i].suffix?  NOT partT[i].suffix
		// Yes, for debug!
	}



////// ~~~~~~~~ Finding all T[j]'s that center are in part[i].
	//for(i= 1; i<=12; i++)
	for(i= 1; i<=Numcell; i++)
	{
		idx[i]=0;
	}

////// ~~~~~~~~ Finding all T[j]'s that center are in part[i].
	//for(i= 1; i<=12; i++)
	for(j= 1; j <=m ; j++) // m is the number of T[i]'s
	{
    			
		if(T[j].bsn <=0 ) //?? add .cn !=0 , Not, repeat
		{				 //YES! do it here
			for(i= 1; i<=Numcell; i++)
			{
				for(k=1; k<=n; k++) //n is the number of dimensions 
				{
				
					center = (double)(T[j].a[k] + T[j].b[k])/2.0;

					 //the Center in the part[i]
					if( (part[i].a[k]<=center) && (center < part[i].b[k]) ) //the Center in the part[i]
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

					idx[i]++;   
					index[i][idx[i]] = j;   //idx = 2 to ...
					
					
					
					bsn[ index[i][idx[i]] ]=T[j].bsn; // save the old bsn of  T[j] , the cluster number

					T[j].bsn = PartNum +1; 
				
                  
					
				}//if(bInterable) //if intersectable					 
			}//if(T[j].cn <=0 )
         
			//################

		}//for(j= 1; j <=m ; j++)v
      


	}//for(i= 1; i<=12; i++)

	  partmax=idx[1];
      partmin=idx[2];
	   
       
         for (i=1;i<=Numcell;i++)
        {
          SumNum+=idx[i];
          partmin = min(partmin, idx[i]);
		  partmax = max(partmax, idx[i]);
        }
		 if (partmin==0)
		 {
			 partmin=1;
		 }


          if ((partmax - partmin)/(partmax+1) <1/13) 
		  {
			  bpartion=false; 

		  }
          else
		  {
			  bpartion=true;
		  }

	int j1=0,k1=0;
	
		if((!bpartion ))//&& SumNum<2100)///here, need to change, let m0= 2100, 1000
		{
			if(2<=SumNum )
            {

			     PartNum++; 

			}else
			{
				
				
				for(i=1;i<=Numcell;i++)
				{
					for(k =1; k<=idx[i]; k++ )
					{
						T[ index[i][k] ].bsn =1000000; //?????k=m
					}
				}
				
			}
		}
		else 
		{
          
		  for(i=1;i<=Numcell;i++)
		   {
				for(k =1; k<=idx[i]; k++ )
				{
					T[ index[i][k] ].bsn = bsn[ index[i][k] ];//?????k=m
				}
		   }
         for(i=1;i<Numcell;i++) 
			{
				for(j=2;j<=Numcell;j++)
				{
					if((part[i].a[1]==part[j].a[1]) &&(part[i].b[1]==part[j].b[1]))
					{
						if((part[i].a[2]==part[j].b[2])||(part[i].b[2]==part[j].a[2]))
						{
							if((idx[i]!=0)&&(idx[j]!=0))
							{   
								if((fabs((idx[i]-idx[j])/idx[i])<=1/15) &&(abs((idx[i]-idx[j])/idx[j])<=1/15))
								{
								for(j1=1;j1<=n;j1++)
								{

                                    part[i].a[j1]=min(part[i].a[j1],part[j].a[j1]);
                                    part[i].b[j1]=max(part[j].b[j1],part[i].b[j1]);
                                      
								}
							    idx[i]=idx[i]+idx[j]; 
								for( k1=j;k1<Numcell;k1++)
								{
									for(j1=1;j1<=n;j1++)
									{
									part[k1].a[j1]=part[k1+1].a[j1];
									part[k1].b[j1]=part[k1+1].b[j1];
									}
                                     idx[k1]=idx[k1+1];    
								}
								 Numcell--;
								}
							}
						}
					}
                
			 	if((part[i].a[2]==part[j].a[2]) &&(part[i].b[2]==part[j].b[2]))
					{
						if((part[i].a[1]==part[j].b[1])||(part[i].b[1]==part[j].a[1]))
						{
							if((idx[i]!=0)&&(idx[j]!=0))
							{    
								if((fabs((idx[i]-idx[j])/idx[i])<=1/15) &&(fabs((idx[i]-idx[j])/idx[j])<=1/15))
								{
								for(j1=1;j1<=n;j1++)
								{

								part[i].a[j1]=min(part[i].a[j1],part[j].a[j1]);
                                part[i].b[j1]=max(part[j].b[j1],part[i].b[j1]);
                               
								}
                                  idx[i]=idx[i]+idx[j]; 
                                for(k1=j;k1<Numcell;k1++)
								{
									
									for(j1=1;j1<=n;j1++)
									{
									part[k1].a[j1]=part[k1+1].a[j1];
									part[k1].b[j1]=part[k1+1].b[j1];
									}
									 idx[k1]=idx[k1+1];
								}
							    Numcell--;
								}
							}

						}
					}
				}
			}
		  deepNum++;
		   for (i=1;i<=Numcell;i++)
		   {
               if(idx[i]>=10)
			   {
				  PartNum = zlPartion(part[i], n, T, T_Num, PartNum);
			   }
		   }
		   
		}

  
		


	


//test ---1133--
	//CFile file;
	//if(file.Open("E:\\Paper2\\CLMB_census2D\\zlClusterPart.txt", CFile::modeCreate | CFile::modeReadWrite ) != 0)
	//{
	//	file.Write(cstrMarc, cstrMarc.GetLength() +1 );
	//}
	//file.Close();
//test ---1133--


	delete [] a ;
	delete [] d ;

	//delete [] scr.a;
	//delete [] scr.b;

	for(i= 0; i<=100; i++)
		delete [] index[i];
    delete [] index;
    
	delete [] bsn;

	return PartNum;
	

}

//to calculate the Diffensence between S and T , that is S-T = U(ss[i]) 
int CLearnIing6App::zlDiffRects(ZLRECT S, ZLRECT T, int Dimension )
{
	int p =0;
	int n = Dimension;
	int i;
    ZLRECT newS;
	double t=0;
    newS =S;

    p=1;
	for(i = 1; i<=n; i++)
	{
		if(newS.a[i]<T.a[i])
		{
			t=newS.b[i];
			newS.b[i] = T.a[i];
	
            ss[p] = newS;
			//memset(&ss[p], 0, sizeof(ZLRECT));
			//memcpy(&ss[p], &newS, sizeof(ZLRECT));

			newS.a[i]=T.a[i];
			newS.b[i]=t ;
			p++;
		}

		if(T.b[i]<newS.b[i])
		{
			t=newS.a[i];
			newS.a[i] = T.b[i];

            ss[p] = newS;
			//memset(&ss[p], 0, sizeof(ZLRECT));
			//memcpy(&ss[p], &newS, sizeof(ZLRECT));

			newS.b[i]=T.b[i];
			newS.a[i]=t ;
			p++;
		}

	}
	p--;

	return p;
}


// for 3_104D 
int CLearnIing6App::zlPartion3D(ZLRECT * Rect, int Dimention, ZLRECT * T, int T_Num, int PartNum)
{
		//CLibServerApp * pApp = (CLibServerApp * ) AfxGetApp();
	//bReturn = pApp->zlExeUpdateTable((char *)szSqlUpdate);			
   
	//----using T[j].bsn = i,  is in Part[i]

	int n = Dimention, m = T_Num;
	int h, i, j, k, idx;
	bool bInterable = false;
	//char buffer[1024] = "";
	char * buffer = new char[512];
	CString cstrMarc;

	//ZLRECT part[13]; //we use 1-12
	//ZLRECT scr;
	ZLRECT * part = new ZLRECT[13];
	ZLRECT * scr = new ZLRECT;

	int dim[4]; //dim[1], [2], [3] are the biggest value of all dimensens
	double dMaxInterval =0.0;

	//scr = Rect;
	memset(scr, 0, sizeof(ZLRECT));
	memcpy(scr, Rect, sizeof(ZLRECT));

	for(i=1; i<=12; i++)
	{
		memset(&part[i], 0, sizeof(ZLRECT));
		memcpy(&part[i], Rect, sizeof(ZLRECT));

		//part[i] = scr; //initial all part[i].a[j], and part[i].b[j]
					   // only there are 3 longest interval will be changed
					   // other n-3 ,say, 104-3 =101 dimension will NOT be changed
	}

	double * a = new double[n+1];
	double * d = new double[n+1];

	//int bsn[1024 +1];
	//int * bsn = new int[1024+1];
	int * bsn = new int[WORKLOAD_NUM+1];

	//for(i=1; i<=1024; i++)
	for(i=1; i<=WORKLOAD_NUM; i++)
	{
		bsn[i] = -1;
	}

	//int index[101][101];
	int * * index; 

	index = new (int *[101]);
	for(i= 0; i<=100; i++)
		//index[i] = new int[101];
		index[i] = new int[WORKLOAD_NUM+1];

	for(i= 1; i<=100; i++)
	{
		//for(j=1; j<=100; j++)
		for(j=1; j<=WORKLOAD_NUM; j++)
		{
			index[i][j] = 0;
		}
	}


	// search NO1 dimension
	dMaxInterval = scr->b[1] - scr->a[1];
	dim[1] =1;
    for(i = 2; i<=n; i++)
	{
		if(dMaxInterval < scr->b[i] - scr->a[i] )
		{
			dMaxInterval = scr->b[i] - scr->a[i];
			dim[1] =i;
		}

	}

	a[dim[1]] = scr->a[dim[1]]; 
	d[dim[1]] = (scr->b[dim[1]] - scr->a[dim[1]])/3;

	// search NO2 dimension
	if(dim[1] != 1)
	{
		dMaxInterval = scr->b[1] - scr->a[1];
		dim[2] =1;
	}
	else
	{
		dMaxInterval = scr->b[2] - scr->a[2];
		dim[2] =2;
	}

    for(i = 1; i<=n; i++)
	{  
		if(i != dim[1] )
		{
			if(dMaxInterval < scr->b[i] - scr->a[i] )
			{
				dMaxInterval = scr->b[i] - scr->a[i];
				dim[2] =i;
			}
		}
	}

	a[dim[2]] = scr->a[dim[2]]; 
	d[dim[2]] = (scr->b[dim[2]] - scr->a[dim[2]])/2;

	// search NO3 dimension
	for(i = 1; i<=n; i++)
	{
		if(dim[1] != i && dim[2] != i )
		{
			dMaxInterval = scr->b[i] - scr->a[i];
			dim[3] =i;
		}

	}

    for(i = 1; i<=n; i++)
	{  
		if(i != dim[1] && i != dim[2] )
		{
			if(dMaxInterval < scr->b[i] - scr->a[i] )
			{
				dMaxInterval = scr->b[i] - scr->a[i];
				dim[3] =i;
			}
		}
	}

	a[dim[3]] = scr->a[dim[3]]; 
	d[dim[3]] = (scr->b[dim[3]] - scr->a[dim[3]])/2;

	for(k =1; k<=2; k++)
	{
		for(j =1; j<=2; j++)
		{
			for(i =1; i<=3; i++)
			{
				//sprintf(temp, " , %02i", i+3*(j-1) + 6*(k-1) );
				//str += temp;
				for(h=1; h<=3; h++ ) //the Number of dimensions: NO1, NO2, NO3
				{					
					if(dim[h]== dim[1])
					{
						part[i+3*(j-1)+6*(k-1)].a[dim[1]] =  a[dim[1]] + (i-1) * d[dim[1]];
						part[i+3*(j-1)+6*(k-1)].b[dim[1]] =  a[dim[1]] + i * d[dim[1]];						
					}
					else if (dim[h]== dim[2]) 
					{
						part[i+3*(j-1)+6*(k-1)].a[dim[2]] =  a[dim[2]] + (j-1) * d[dim[2]];
						part[i+3*(j-1)+6*(k-1)].b[dim[2]] =  a[dim[2]] + j * d[dim[2]];
					}
					else if (dim[h]== dim[3])
					{
						part[i+3*(j-1)+6*(k-1)].a[dim[3]] =  a[dim[3]] + (k-1) * d[dim[3]];
						part[i+3*(j-1)+6*(k-1)].b[dim[3]] =  a[dim[3]] + k * d[dim[3]];
					}
				}
			}
		}
	}

///=================================================

	// we use the method of "Center IN " to clustering
	
	double center =0.0;

	//for(i= 1; i<=12; i++)  //?? 12
	//{
	//	sprintf(part[i].suffix, " Part[%i]: " , i ); 
	//}



////// ~~~~~~~~ Finding all T[j]'s that center are in part[i].
	for(i= 1; i<=12; i++)
	{
		idx=0;

		for(j= 1; j <=m ; j++) // m is the number of T[i]'s
		{
			//###########
			if(T[j].bsn <=0 ) //?? add .cn !=0 , Not, repeat
			{				 //YES! do it here
				for(k=1; k<=n; k++) //n is the number of dimensions 
				{
				
					center = (double)(T[j].a[k] + T[j].b[k])/2.0;

					if( (part[i].a[k]<=center) && (center<= part[i].b[k]) ) //the Center in the part[i]
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
					idx++;   
					index[i][idx] = j;   //idx = 2 to ...
					//sprintf(buffer, ",%i", j);
					//strcat(T[i].suffix, buffer);//for debug
					bsn[ index[i][idx] ]=T[j].bsn; // save the old bsn of  T[j] , the cluster number

					T[j].bsn = PartNum +1; 
					
				}//if(bInterable) //if intersectable					 
			}//if(T[j].cn <=0 )

			//################

		}//for(j= 1; j <=m ; j++)v

		//cstrMarc += part[i].suffix;	
		//cstrMarc += buffer; //T[i].suffix;
	    //cstrMarc += "\r\n";
		// up to now we obtain all T[j]'s that in Part[i], and it index: index[i][l]
			//call the function : zlClusterPart( ZLRECT ** T, ZLRECT ** S); 
		
		//if(idx>=8) //--2007.12.09
		if(idx>=21)   //--2007.12.09, for cover4D, let m0==40
		{

			for(k =1; k<=idx; k++ )
			{
				T[ index[i][k] ].bsn = bsn[ index[i][k] ];
			}
			// call this function again.
           PartNum = zlPartion3D(&part[i], n, T, T_Num, PartNum);

		}
		//else if( 1<=idx && idx<8)
		else if( 1<=idx && idx<21)
		{
			PartNum ++;
		}

//test ---1133--
	//CFile file;
	//if(file.Open("E:\\Paper2\\CLMB_census2D\\zlClusterPart.txt", CFile::modeCreate | CFile::modeReadWrite ) != 0)
	//{
	//	file.Write(cstrMarc, cstrMarc.GetLength() +1 );
	//}
	//file.Close();
//test ---1133--



	}//for(i= 1; i<=12; i++)


//test ---1133--
	//CFile file;
	//if(file.Open("E:\\Paper2\\CLMB_census2D\\zlClusterPart.txt", CFile::modeCreate | CFile::modeReadWrite ) != 0)
	//{
	//	file.Write(cstrMarc, cstrMarc.GetLength() +1 );
	//}
	//file.Close();
//test ---1133--


	delete [] a ;
	delete [] d ;
	delete [] buffer;
	delete [] part;
	delete scr;
	delete bsn;	
	for(i= 0; i<=100; i++)
		delete [] index[i];
    delete [] index;
///=================================================
	return PartNum;

}


int CLearnIing6App::zlClusterPart(ZLRECT **T, int l, ZLRECT *S, int m, int Current_clsNum, int dim_num, int PartNum, double xi)
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

	//double VFactor =  5.0 * pow(10, 37); //2005.05.02
	double VFactor;
	if(n==104)
	  VFactor = 5.0 * pow(10, 37);
	else if(n==50)
	  VFactor = pow(10, 34); // (30 +38)/2=34
	else if(n==25)
	  VFactor = pow(10, 31); // (24 +38)/2=31


	//int cn[1024 +1];
	int cn[WORKLOAD_NUM +1];

    int part_cn = -1;  

	ZLRECT * RT = new ZLRECT[m+1];
	ZLRECT scr;

	//for(i=1; i<=m; i++)
	//{
		//RT[i].a = new double[n+1];
		//RT[i].b = new double[n+1];
	//}
	//for(i=1; i<=1024; i++)
	for(i=1; i<=WORKLOAD_NUM; i++)
	{
		//cn[1024 +1] = -1;
		cn[i] = -1;
	}



	//scr.a = new double[n+1];
	//scr.b = new double[n+1];

	//int index[101][101];
	//int index[101][WORKLOAD_NUM +1];

	int * * index; 

	index = new (int *[101]);
	for(i= 0; i<=100; i++)
		//index[i] = new int[101];
		index[i] = new int[WORKLOAD_NUM+1];
/*
	for(i= 1; i<=100; i++)
	{
		//for(j=1; j<=100; j++)
		for(j=1; j<=WORKLOAD_NUM; j++)
		{
			index[i][j] = 0;
		}
	}
*/
/*
	for(i= 1; i<=iPartNum; i++)
	{
		if( T[i]->cn < 16000) // 16000 ===> 1000 
		{
			part_cn = T[i]->cn;
			break;
		}
	}
*/


	int i1,j1;

   // T (here) is PartT (in calling function) that in a Part of SCR, and 
   // S (here) is the T (in calling function) is all {T[i], i=1,,,T_m}

	for(i= 1; i<=l; i++) // there are l rectangles in some part, l<=10
	{   

		for(i1= 1; i1<=100; i1++)
		{
			for(j1=1; j1<=WORKLOAD_NUM; j1++)
			{
				index[i1][j1] = 0;
			}
		}
		//if( T[i]->cn <=0 )  //2005.3.16
		//if( T[i]->cn <=1000 ) //2005.3.16  // no clustering 
		//if( T[i]->cn <=12 ) //2005.3.24  // no clustering //2005.04.28
		if( T[i]->cn <= PartNum ) //2005.3.24  // no clustering //2005.04.28
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
                                // at this time, iclsNum >= PartNum +1
								// min(iclsNum) = PartNum, the initial value of iclsNum = PartNum;
			
			index[i][1] = i;
			//-- cannot using this way, because delete RT[], meanwhile it delete T[]
			//memset(&RT[idx], 0, sizeof(ZLRECT));
			//memcpy(&RT[idx], T[i], sizeof(ZLRECT) );

			//-- using the following way, the addresses are independent each other.
			//-- RT[]: the "train" with header T[i]; i.e.

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
				if(index[i][ll] <= 0 || idx >=10) // the last index[i][j] that is 0
					break;   //break for(ll = 1; ll<= m; ll++)
 			
				for(j=1; j<=m; j++)
				{
					//if(S[j].cn <=0)
					//if(S[j].cn <=1000)//2005.3.16
					//if(S[j].cn <=12)  //2005.3.24
					if(S[j].cn <= PartNum)  //2005.4.28 //S[j].cn no clustering 
					{
						//--- see the "train" , all RT[ll]'s,  do or not intersect with S[j]
						for( k=1; k<=n; k++) //n is the number of dimensions 
						{
							 //p = __max(T[index[i][ll]]->a[k], S[j].a[k]);
							 //q = __min(T[index[i][ll]]->b[k], S[j].b[k]);
							 p = __max(RT[ll].a[k], S[j].a[k]);
							 q = __min(RT[ll].b[k], S[j].b[k]);

							 //??? OR USE "CENTER IN". 

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
							{	
								bInterable = false;
								break; // break for j and then break for ll
							}
						}//if(bInterable) //if intersectable

					} //if(S[j].cn <=0)

				} //for(j= 1; j<=m; j++)

			} //for(ll =1; ll<=idx; ll++)

			// to calculte the volume of Union
			if(idx>=2)
			{

				////?maybe RT[i] need to asign new value for .sufend, .suf1st
				
				////cstrMarc += "T[i]: ";
				
				//sprintf(temp, "T[%02i]: ", i);
				//cstrMarc += temp;

				//cstrMarc += T[i]->suffix;
				//cstrMarc += "\r\n";
				//cstrMarc += "RT:   ";

				Sum_vi =0.0;
				for(k =1; k<=idx; k++)
				{
					Sum_vi = Sum_vi + RT[k].v;
				//---test----
					//cstrMarc += ",";
					//cstrMarc += RT[k].suffix;
					//RT[k].suf1st = k;
					//RT[k].sufend = k;
				//---test----
				}

				//-- obtain the scr of the current Train 
				for(int ii=1; ii<=n; ii++ )
				{
					scr.a[ii] = RT[1].a[ii];
					scr.b[ii] = RT[1].b[ii];

					for(k =1; k<=idx; k++ )
					{
						scr.a[ii] = min(scr.a[ii], RT[k].a[ii]);
						scr.b[ii] = max(scr.b[ii], RT[k].b[ii]);	
					}
				}

				scr.v = 1.0;
				if(n<25)
				{
					for(ii=1; ii<=n; ii++ )
						scr.v *= (scr.b[ii]-scr.a[ii]);
				}
				else
				{
					for(ii=1; ii<=n; ii++ )
						scr.v *= ( (scr.b[ii]-scr.a[ii])/VFactor );

				}
				
				//--obtain the Volume of the Union of the Trian 
				double Union_v = zlVolumeOfUnion(idx, n, RT);

				//cstrMarc += "\r\n";
				//sprintf(temp, "Sum_vi= %G , scr_v=%G, Union_v=%G ", Sum_vi, scr.v, Union_v);
				//cstrMarc += temp;

				//cstrMarc += "\r\n";
				//cstrMarc += "\r\n";


				//make a decision to give cluster number
				// by using 3 values : 1. Sum_vi, 2. scr_v,  and 3. Union_v 
				//---	a = Union_v/Sum_vi  <= 1, i.e. Union_v <= Sum_vi
	            //		b = Union_v/scr_v   <= 1  i.e. Union_v <= scr_v  
				//		c = scr_v/Sum_vi	non-determined	
				
				// if a ~~ 1 AND c >>> 1, i.e. the angles intersect,
	            // then we do not clustering. 
				// not clustering, and then restore the cluster number cn 
				
				//double c = scr.v/Sum_vi;

				//if( (Sum_vi <= 1.2*Union_v) && ( pow(1.8, n-1) * Sum_vi <= scr.v ) ) 
				//if(  pow(1.8, n-1) * Sum_vi <= scr.v  ) 
				//if(  2.0 <= (scr.v/Sum_vi) ) 
				//if(  (Sum_vi/Union_v <= 1.2) && (scr.v/Sum_vi) >= pow(2.0, n-1) ) 
				//if( (scr.v/Sum_vi) >= pow(2.0, n-1) ) 

				//if( (scr.v/Sum_vi) >= pow(4.0, n-1) ) 	//IF SCR/SUM >4	
				// 2007.02.21 double dpow = 4.0; //pow(4.0, n-1); 
				// 2007.02. 21 double da =(scr.v/Union_v);

				double c2 =0.0;
				c2 = xi ; //assigh a threshold to c2

				//if( (scr.v/Union_v) >= dpow) 	//IF SCR/Union_v >4	 then not Clustering 					
								
				//IF Union_v/SCR >= c(threshod), Then Intersect-,or C-Clustering 					
				if( (Union_v/scr.v) < c2) 	//IF Union_v/SCR < c2,	 then not Clustering 					
				//if( (Union_v/scr.v) <= c2) 	//IF Union_v/SCR < c2,	 then not Clustering 					
				{                            // Union_v = v(Union), SCR =v(SCR) c2 is in (0,1]
					//sprintf(temp, "scr_v[%02i]=%G, Sum_vi= %G, scr.v/Sum_vi=%G ",iclsNum, scr.v, Sum_vi, scr.v/Sum_vi);
					//cstrMarc += temp;
					//cstrMarc += "\r\n";

					iclsNum = iclsNumHold; //iclsNum--;
					T[i]->cn = part_cn;
					for(k =1+1; k<=idx; k++ )
					{
						S[ index[i][k] ].cn = cn[ index[i][k] ];
					}
				
				}

//test ---11--
	//sprintf(temp, "E:\\Paper2\\CLMB_census2D\\zlClusterPart\\zlClusterPart%02i.txt",iclsNum);
	//CFile file;
	//if(file.Open(temp, CFile::modeCreate | CFile::modeReadWrite ) != 0)
	//{
	//	file.Write(cstrMarc, cstrMarc.GetLength() +1 );
	//}
	//file.Close();
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
	//for(i=1; i<=m; i++)
	//{
	//	delete [] RT[i].a;
	//	delete [] RT[i].b;
	//}
	delete [] RT;

    for(i= 0; i<=100; i++)
	   delete [] index[i];
    delete [] index;
/////////////////////////////////////////////////////////////

	return iclsNum;

}

////////////////// Using C-Clustering//////////////////////////
int CLearnIing6App::zlClusterPartLsi(ZLRECT **T, int l, ZLRECT *S, int m, 
		int Current_clsNum, int dim_num, int PartNum, double xi)
{
	int iclsNum = Current_clsNum ; 
	int iclsNumHold = Current_clsNum;
	int i, j, k, ll, idx;
	//double p;
	//double q;
	bool bInterable= false;
	int n = dim_num;
	char buffer[128] ="";
	CString cstrMarc = "";
	char temp[1000] = "";
	double Sum_vi = 0;

	//double VFactor =  5.0 * pow(10, 37); //2005.05.02
	double VFactor;
	if(n==104)
	  VFactor = 5.0 * pow(10, 37);
	else if(n==50)
	  VFactor = pow(10, 34); // (30 +38)/2 == 34
	else if(n==25)
	  VFactor = pow(10, 31); // (24 +38)/2=31


	//int cn[1024 +1];
	int cn[WORKLOAD_NUM +1];

    int part_cn = -1;  

	ZLRECT * RT = new ZLRECT[m+1];
	ZLRECT scr;

	//scr.a = new double[n+1];
	//scr.b = new double[n+1];


	double center =0.0;
    double Dalta =0.0;
    double ALFA = 1.0/6; 
	
    #define TRAINLONG 10 //8   //the long of the train
	
	//for(i=1; i<=m; i++)
	//{
		//RT[i].a = new double[n+1];
		//RT[i].b = new double[n+1];
	//}
	//for(i=1; i<=1024; i++)
	for(i=1; i<=WORKLOAD_NUM; i++)
	{
		//cn[1024 +1] = -1;
		cn[i] = -1;

	}


	//int index[101][101];
	//int index[101][WORKLOAD_NUM +1];
	int * * index; 

	index = new (int *[101]);
	for(i= 0; i<=100; i++)
		//index[i] = new int[101];
		index[i] = new int[WORKLOAD_NUM+1];
/*
	for(i= 1; i<=100; i++)
	{
		//for(j=1; j<=100; j++)
		for(j=1; j<=WORKLOAD_NUM; j++)
		{
			index[i][j] = 0;
		}
	}
*/
/*
	for(i= 1; i<=iPartNum; i++)
	{
		if( T[i]->cn < 16000) // 16000 ===> 1000 
		{
			part_cn = T[i]->cn;
			break;
		}
	}

*/

	int i1,j1;

	int FileNum = iclsNum * 10000;
	//l is the size number of {T[i]}

   // T (here) is PartT (in calling function) that in a Part of SCR, and 
   // S (here) is the T (in calling function) is all {T[i], i=1,,,T_m}

	for(i= 1; i<=l; i++) // there are l rectangles in some part 
	{   

		for(i1= 1; i1<=100; i1++)
		{
			for(j1=1; j1<=WORKLOAD_NUM; j1++)
			{
				index[i1][j1] = 0;
			}
		}

		//if( T[i]->cn <=0 )  //2005.3.16
		//if( T[i]->cn <=1000 ) //2005.3.16  // no clustering 
		//if( T[i]->cn <=12 ) //2005.3.24  // no clustering //2005.04.28
		if( T[i]->cn <= PartNum ) //2005.3.24  // no clustering //2005.04.28
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
                                // at this time, iclsNum >= PartNum +1
								// min(iclsNum) = PartNum, the initial value of iclsNum = PartNum;
			
			index[i][1] = i;
			//-- cannot using this way, because delete RT[], meanwhile it delete T[]
			//memset(&RT[idx], 0, sizeof(ZLRECT));
			//memcpy(&RT[idx], T[i], sizeof(ZLRECT) );

			//-- using the following way, the addresses are independent each other.
			//-- RT[]: the "train" with header T[i]; i.e.

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
				//if(index[i][ll] <= 0 || idx >=10) // the last index[i][j] that is 0 ;idx >=5)
				
				if(index[i][ll] <= 0 || idx >=TRAINLONG) // the last indes[i][j] that is 0 ;idx >=5)
					break;   //break for(ll = 1; ll<= m; ll++)
 			
				for(j=1; j<=m; j++)
				{
					//if(S[j].cn <=0)
					//if(S[j].cn <=1000)//2005.3.16
					//if(S[j].cn <=12)  //2005.3.24
					if(S[j].cn <= PartNum)  //2005.4.28 //S[j].cn no clustering 
					{
						//--- see the "train" , all RT[ll]'s,  do or not intersect with S[j]
						for( k=1; k<=n; k++) //n is the number of dimensions 
						{
							/*** 2005.5.15
							 p = __max(RT[ll].a[k], S[j].a[k]);
							 q = __min(RT[ll].b[k], S[j].b[k]);
							2005.5.15 ***/

							///// 2005.5.15 change //////	
							center = (double)(S[j].a[k] + S[j].b[k])/2.0;
							Dalta  = (double)(RT[ll].b[k] - RT[ll].a[k])*ALFA;
										
							///// 2005.5.15 change //////

							//???  here l ==8; but T[index[i][ll] =93 > 8 there is problem 
							// using RT to replace T and idx replace m in forloop is OK !!!
							
							//if(p<q) //the intersection is not empty, 
							
							//if( ( (RT[ll].a[k]+Dalta) <= center) && (center <= (RT[ll].b[k]-Dalta) ) ) //the (epcilong+ Center in) the part[i]
							if( ( (RT[ll].a[k]) <= center) && (center <= (RT[ll].b[k]) ) ) //the Center in the part[i]
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

							//if(idx>=10) //the max (the long of the train) is 10 or 5
							if(idx>=TRAINLONG) //the max (the long of the train) is 10 or 5
							{	
								bInterable = false;
								break; // break for j and then break for ll
							}
						}//if(bInterable) //if intersectable

					} //if(S[j].cn <=0)

				} //for(j= 1; j<=m; j++)

			} //for(ll =1; ll<=idx; ll++)

			// to calculte the volume of Union
			if(idx>=2)
			{

				////?maybe RT[i] need to asign new value for .sufend, .suf1st
				
				////cstrMarc += "T[i]: ";
				
				//sprintf(temp, "T[%02i]: ", i);
				//cstrMarc += temp;

				//cstrMarc += T[i]->suffix;
				//cstrMarc += "\r\n";
				//cstrMarc += "RT:   ";

				Sum_vi =0.0;
				for(k =1; k<=idx; k++)
				{
					Sum_vi = Sum_vi + RT[k].v;
				//---test----
					//cstrMarc += ",";
					//cstrMarc += RT[k].suffix;
					RT[k].suf1st = k;
					RT[k].sufend = k;
				//---test----
				}

				//-- obtain the scr of the current Train 
				for(int ii=1; ii<=n; ii++ )
				{
					scr.a[ii] = RT[1].a[ii];
					scr.b[ii] = RT[1].b[ii];

					for(k =1; k<=idx; k++ )
					{
						scr.a[ii] = min(scr.a[ii], RT[k].a[ii]);
						scr.b[ii] = max(scr.b[ii], RT[k].b[ii]);	
					}
				}

				scr.v = 1.0;
				if(n<25)
				{
					for(ii=1; ii<=n; ii++ )
						scr.v *= (scr.b[ii]-scr.a[ii]);
				}
				else
				{
					for(ii=1; ii<=n; ii++ )
						scr.v *= ( (scr.b[ii]-scr.a[ii])/VFactor );

				}
				
				//--obtain the Volume of the Union of the Trian 
				double Union_v = zlVolumeOfUnion(idx, n, RT);

				//cstrMarc += "\r\n";
				//sprintf(temp, "Sum_vi= %G , scr_v=%G, Union_v=%G ", Sum_vi, scr.v, Union_v);
				//cstrMarc += temp;

				//cstrMarc += "\r\n";
				//cstrMarc += "\r\n";


				//make a decision to give cluster number
				// by using 3 values : 1. Sum_vi, 2. scr_v,  and 3. Union_v 
				//---	a = Union_v/Sum_vi  <= 1, i.e. Union_v <= Sum_vi
	            //		b = Union_v/scr_v   <= 1  i.e. Union_v <= scr_v  
				//		c = scr_v/Sum_vi	non-determined	
				
				// if a ~~ 1 AND c >>> 1, i.e. the angles intersect,
	            // then we do not clustering. 
				// not clustering, and then restore the cluster number cn 
				
				//double c = scr.v/Sum_vi;

				//if( (Sum_vi <= 1.2*Union_v) && ( pow(1.8, n-1) * Sum_vi <= scr.v ) ) 
				//if(  pow(1.8, n-1) * Sum_vi <= scr.v  ) 
				//if(  2.0 <= (scr.v/Sum_vi) ) 
				//if(  (Sum_vi/Union_v <= 1.2) && (scr.v/Sum_vi) >= pow(2.0, n-1) ) 
				//if( (scr.v/Sum_vi) >= pow(2.0, n-1) ) 

				//if( (scr.v/Sum_vi) >= pow(4.0, n-1) ) 	//IF SCR/SUM >4	
				
				//double dpow = pow(4.0, n-1); 
				
				// 2007.02.21 double dpow = 2.0; 
				// 2007.02.21 double da =(scr.v/Union_v);
				double c2 = 0;
				c2 = xi ; //asigh a threshold to c2

				//if( (scr.v/Union_v) >= dpow) 	//IF SCR/Union_v >4	 then not Clustering 					
				if( (Union_v/scr.v) < c2) 	//IF Union_v/SCR < c2,	 then not Clustering 					
				//if( (Union_v/scr.v) <= c2) 	//IF Union_v/SCR < c2,	 then not Clustering 					
				{                            // Union_v = v(Union), SCR =v(SCR) c2 is in (0,1]

					//sprintf(temp, "scr_v[%02i]=%G, Sum_vi= %G, scr.v/Sum_vi=%G ",iclsNum, scr.v, Sum_vi, scr.v/Sum_vi);
					//cstrMarc += temp;
					//cstrMarc += "\r\n";


					iclsNum = iclsNumHold; //iclsNum--;
					T[i]->cn = part_cn;
					for(k =1+1; k<=idx; k++ )
					{
						S[ index[i][k] ].cn = cn[ index[i][k] ];
					}
				
				}

//test ---11--
	//FileNum ++;
	//CString cstrMarc1;
   /*
	if((scr.v/Union_v) >= dpow)
		sprintf(temp, "(scr.v/Union_v): %G >= dpow : %G  ", scr.v/Union_v, dpow);
	else
		sprintf(temp, "(scr.v/Union_v): %G <= dpow : %G  ", scr.v/Union_v, dpow);
    cstrMarc += temp;
   */
	//sprintf(temp, "E:\\Paper2\\CLMB_census2D\\zlClusterPart\\zlClusterPart%02i.txt", FileNum);
	//CFile file;
	//if(file.Open(temp, CFile::modeCreate | CFile::modeReadWrite ) != 0)
	//{
	//	file.Write(cstrMarc1, cstrMarc1.GetLength() +1 );
	//}
	//file.Close();
//test ---11--

			}
			else  //2005.3.23  when idx < 2
			{
				iclsNum = iclsNumHold;
				T[i]->cn = part_cn ;
			}//if(idx>=2)

		}//if( T[i]->cn <=0 )

	} //for(i= 1; i<=l; i++) // there are l rectangle in some part //

//test ---1133--
  /*
	if(! cstrMarc.IsEmpty() )
	{
		FileNum = + GetTickCount();
		sprintf(temp, "E:\\Paper2\\CLMB_census2D\\zlClusterPart\\zl\\zl%02i.txt", FileNum);
		CFile file;
		if(file.Open(temp, CFile::modeCreate | CFile::modeReadWrite ) != 0)
		{
			file.Write(cstrMarc, cstrMarc.GetLength() +1 );
		}
		file.Close();
	}
	*/
//test ---1133--



	//delete [] scr.a;
	//delete [] scr.b;
	//for(i=1; i<=m; i++)
	//{
	//	delete [] RT[i].a;
	//	delete [] RT[i].b;
	//}
	delete [] RT;
    for(i= 0; i<=100; i++)
	      delete [] index[i];
    delete [] index;
///////////////////////////////////////////////////////////////
	return iclsNum;
}
////////////Using C-Clustering end /////////////////////

/////////////////////Using Intersection-Clustering start//////////////////////////////
int CLearnIing6App::zlClusterPartLsi_InSe(ZLRECT **T, int l, ZLRECT *S, int m, 
		int Current_clsNum, int dim_num, int PartNum, double xi)
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

	//double VFactor =  5.0 * pow(10, 37); //2005.05.02
	double VFactor;
	if(n==104)
	  VFactor = 5.0 * pow(10, 37);
	else if(n==50)
	  VFactor = pow(10, 34); // (30 +38)/2 == 34
	else if(n==25)
	  VFactor = pow(10, 31); // (24 +38)/2=31


	int cn[1024 +1];
    int part_cn = -1;  

	ZLRECT * RT = new ZLRECT[m+1];

	double center =0.0;
    double Dalta =0.0;
    double ALFA = 1.0/6; 
	
    #define TRAINLONG 10 //8   //the long of the train
	
	//for(i=1; i<=m; i++)
	//{
		//RT[i].a = new double[n+1];
		//RT[i].b = new double[n+1];
	//}
	for(i=1; i<=1024; i++)
	{
		cn[i] = -1;
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


	int i1,j1;

	int FileNum = iclsNum * 10000;
	//l is the size number of {T[i]}
	for(i= 1; i<=l; i++) // there are l rectangles in some part 
	{   

		for(i1= 1; i1<=100; i1++)
		{
			for(j1=1; j1<=100; j1++)
			{
				index[i1][j1] = 0;
			}
		}

		//if( T[i]->cn <=0 )  //2005.3.16
		//if( T[i]->cn <=1000 ) //2005.3.16  // no clustering 
		//if( T[i]->cn <=12 ) //2005.3.24  // no clustering //2005.04.28
		if( T[i]->cn <= PartNum ) //2005.3.24  // no clustering //2005.04.28
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
                                // at this time, iclsNum >= PartNum +1
								// min(iclsNum) = PartNum, the initial value of iclsNum = PartNum;
			
			index[i][1] = i;
			//-- cannot using this way, because delete RT[], meanwhile it delete T[]
			//memset(&RT[idx], 0, sizeof(ZLRECT));
			//memcpy(&RT[idx], T[i], sizeof(ZLRECT) );

			//-- using the following way, the addresses are independent each other.
			//-- RT[]: the "train" with header T[i]; i.e.

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
				//if(index[i][ll] <= 0 || idx >=10) // the last index[i][j] that is 0 ;idx >=5)
				
				if(index[i][ll] <= 0 || idx >=TRAINLONG) // the last indes[i][j] that is 0 ;idx >=5)
					break;   //break for(ll = 1; ll<= m; ll++)
 			
				for(j=1; j<=m; j++)
				{
					//if(S[j].cn <=0)
					//if(S[j].cn <=1000)//2005.3.16
					//if(S[j].cn <=12)  //2005.3.24
					if(S[j].cn <= PartNum)  //2005.4.28 //S[j].cn no clustering 
					{
						//--- see the "train" , all RT[ll]'s,  do or not intersect with S[j]
						for( k=1; k<=n; k++) //n is the number of dimensions 
						{
							///*** 2005.5.15
							 p = __max(RT[ll].a[k], S[j].a[k]);
							 q = __min(RT[ll].b[k], S[j].b[k]);
							//2005.5.15 ***/

							///// 2005.5.15 change //////	
							//center = (double)(S[j].a[k] + S[j].b[k])/2.0;
							//Dalta  = (double)(RT[ll].b[k] - RT[ll].a[k])*ALFA;
										
							///// 2005.5.15 change //////

							//???  here l ==8; but T[index[i][ll] =93 > 8 there is problem 
							// using RT to replace T and idx replace m in forloop is OK !!!
							
							if(p<q) //the intersection is not empty, 
							
							//if( ( (RT[ll].a[k]+Dalta) <= center) && (center <= (RT[ll].b[k]-Dalta) ) ) //the (epcilong+ Center in) the part[i]
							//if( ( (RT[ll].a[k]) <= center) && (center <= (RT[ll].b[k]) ) ) //the Center in the part[i]
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

							//if(idx>=10) //the max (the long of the train) is 10 or 5
							if(idx>=TRAINLONG) //the max (the long of the train) is 10 or 5
							{	
								bInterable = false;
								break; // break for j and then break for ll
							}
						}//if(bInterable) //if intersectable

					} //if(S[j].cn <=0)

				} //for(j= 1; j<=m; j++)

			} //for(ll =1; ll<=idx; ll++)

			// to calculte the volume of Union
			if(idx>=2)
			{

				////?maybe RT[i] need to asign new value for .sufend, .suf1st
				
				////cstrMarc += "T[i]: ";
				
				//sprintf(temp, "T[%02i]: ", i);
				//cstrMarc += temp;

				//cstrMarc += T[i]->suffix;
				//cstrMarc += "\r\n";
				//cstrMarc += "RT:   ";

				Sum_vi =0.0;
				for(k =1; k<=idx; k++)
				{
					Sum_vi = Sum_vi + RT[k].v;
				//---test----
					//cstrMarc += ",";
					//cstrMarc += RT[k].suffix;
					RT[k].suf1st = k;
					RT[k].sufend = k;
				//---test----
				}

				//-- obtain the scr of the current Train 
				for(int ii=1; ii<=n; ii++ )
				{
					scr.a[ii] = RT[1].a[ii];
					scr.b[ii] = RT[1].b[ii];

					for(k =1; k<=idx; k++ )
					{
						scr.a[ii] = min(scr.a[ii], RT[k].a[ii]);
						scr.b[ii] = max(scr.b[ii], RT[k].b[ii]);	
					}
				}

				scr.v = 1.0;
				if(n<25)
				{
					for(ii=1; ii<=n; ii++ )
						scr.v *= (scr.b[ii]-scr.a[ii]);
				}
				else
				{
					for(ii=1; ii<=n; ii++ )
						scr.v *= ( (scr.b[ii]-scr.a[ii])/VFactor );

				}
				
				//--obtain the Volume of the Union of the Trian 
				double Union_v = zlVolumeOfUnion(idx, n, RT);

				//cstrMarc += "\r\n";
				//sprintf(temp, "Sum_vi= %G , scr_v=%G, Union_v=%G ", Sum_vi, scr.v, Union_v);
				//cstrMarc += temp;

				//cstrMarc += "\r\n";
				//cstrMarc += "\r\n";


				//make a decision to give cluster number
				// by using 3 values : 1. Sum_vi, 2. scr_v,  and 3. Union_v 
				//---	a = Union_v/Sum_vi  <= 1, i.e. Union_v <= Sum_vi
	            //		b = Union_v/scr_v   <= 1  i.e. Union_v <= scr_v  
				//		c = scr_v/Sum_vi	non-determined	
				
				// if a ~~ 1 AND c >>> 1, i.e. the angles intersect,
	            // then we do not clustering. 
				// not clustering, and then restore the cluster number cn 
				
				//double c = scr.v/Sum_vi;

				//if( (Sum_vi <= 1.2*Union_v) && ( pow(1.8, n-1) * Sum_vi <= scr.v ) ) 
				//if(  pow(1.8, n-1) * Sum_vi <= scr.v  ) 
				//if(  2.0 <= (scr.v/Sum_vi) ) 
				//if(  (Sum_vi/Union_v <= 1.2) && (scr.v/Sum_vi) >= pow(2.0, n-1) ) 
				//if( (scr.v/Sum_vi) >= pow(2.0, n-1) ) 

				//if( (scr.v/Sum_vi) >= pow(4.0, n-1) ) 	//IF SCR/SUM >4	
				
				//double dpow = pow(4.0, n-1); 
				
				double dpow = 2.0; 
				double da =(scr.v/Union_v);
				double c2 = 0;
				c2 = xi ; //asigh a threshold to c2

				//if( (scr.v/Union_v) >= dpow) 	//IF SCR/Union_v >4	 then not Clustering 					
				if( (Union_v/scr.v) < c2) 	//IF Union_v/SCR < c2,	 then not Clustering 					
				//if( (Union_v/scr.v) <= c2) 	//IF Union_v/SCR < c2,	 then not Clustering 					
				{                            // Union_v = v(Union), SCR =v(SCR) c2 is in (0,1]

					//sprintf(temp, "scr_v[%02i]=%G, Sum_vi= %G, scr.v/Sum_vi=%G ",iclsNum, scr.v, Sum_vi, scr.v/Sum_vi);
					//cstrMarc += temp;
					//cstrMarc += "\r\n";


					iclsNum = iclsNumHold; //iclsNum--;
					T[i]->cn = part_cn;
					for(k =1+1; k<=idx; k++ )
					{
						S[ index[i][k] ].cn = cn[ index[i][k] ];
					}
				
				}

//test ---11--
	//FileNum ++;
	//CString cstrMarc1;
   /*
	if((scr.v/Union_v) >= dpow)
		sprintf(temp, "(scr.v/Union_v): %G >= dpow : %G  ", scr.v/Union_v, dpow);
	else
		sprintf(temp, "(scr.v/Union_v): %G <= dpow : %G  ", scr.v/Union_v, dpow);
    cstrMarc += temp;
   */
	//sprintf(temp, "E:\\Paper2\\CLMB_census2D\\zlClusterPart\\zlClusterPart%02i.txt", FileNum);
	//CFile file;
	//if(file.Open(temp, CFile::modeCreate | CFile::modeReadWrite ) != 0)
	//{
	//	file.Write(cstrMarc1, cstrMarc1.GetLength() +1 );
	//}
	//file.Close();
//test ---11--

			}
			else  //2005.3.23  when idx < 2
			{
				iclsNum = iclsNumHold;
				T[i]->cn = part_cn ;
			}//if(idx>=2)

		}//if( T[i]->cn <=0 )

	} //for(i= 1; i<=l; i++) // there are l rectangle in some part //

//test ---1133--
  /*
	if(! cstrMarc.IsEmpty() )
	{
		FileNum = + GetTickCount();
		sprintf(temp, "E:\\Paper2\\CLMB_census2D\\zlClusterPart\\zl\\zl%02i.txt", FileNum);
		CFile file;
		if(file.Open(temp, CFile::modeCreate | CFile::modeReadWrite ) != 0)
		{
			file.Write(cstrMarc, cstrMarc.GetLength() +1 );
		}
		file.Close();
	}
	*/
//test ---1133--



	//delete [] scr.a;
	//delete [] scr.b;
	//for(i=1; i<=m; i++)
	//{
	//	delete [] RT[i].a;
	//	delete [] RT[i].b;
	//}
	delete [] RT;

	return iclsNum;
}
//////////////////////// Using Intersection-Clustering End //////////////////////////

////////////// Using 3+C-Clustering start ////////////////
int CLearnIing6App::zlClusterPartLsi_Plus(ZLRECT **T, int l, ZLRECT *S, int m, 
						int Current_clsNum, int dim_num, int PartNum, double xi)
{
	int iclsNum = Current_clsNum ; 
	int iclsNumHold = Current_clsNum;
	int i, j, k, ll, idx;
	//double p;
	//double q;
	bool bInterable= false;
	int n = dim_num;
	char buffer[128] ="";
	CString cstrMarc = "";
	char temp[1000] = "";
	double Sum_vi = 0;

	//double VFactor =  5.0 * pow(10, 37); //2005.05.02
	double VFactor;
	if(n==104)
	  VFactor = 5.0 * pow(10, 37);
	else if(n==50)
	  VFactor = pow(10, 34); // (30 +38)/2 == 34
	else if(n==25)
	  VFactor = pow(10, 31); // (24 +38)/2=31


	int cn[1024 +1];
    int part_cn = -1;  

	ZLRECT * RT = new ZLRECT[m+1];

	double center =0.0;
    double Dalta =0.0;
    double ALFA = 1.0/6; 
	
    #define TRAINLONG 10 //8   //the long of the train
	
	//for(i=1; i<=m; i++)
	//{
		//RT[i].a = new double[n+1];
		//RT[i].b = new double[n+1];
	//}
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


	int i1,j1;

	int FileNum = iclsNum * 10000;
	//l is the size number of {T[i]}
	for(i= 1; i<=l; i++) // there are l rectangles in some part 
	{   

		for(i1= 1; i1<=100; i1++)
		{
			for(j1=1; j1<=100; j1++)
			{
				index[i1][j1] = 0;
			}
		}

		//if( T[i]->cn <=0 )  //2005.3.16
		//if( T[i]->cn <=1000 ) //2005.3.16  // no clustering 
		//if( T[i]->cn <=12 ) //2005.3.24  // no clustering //2005.04.28
		if( T[i]->cn <= PartNum ) //2005.3.24  // no clustering //2005.04.28
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
                                // at this time, iclsNum >= PartNum +1
								// min(iclsNum) = PartNum, the initial value of iclsNum = PartNum;
			
			index[i][1] = i;
			//-- cannot using this way, because delete RT[], meanwhile it delete T[]
			//memset(&RT[idx], 0, sizeof(ZLRECT));
			//memcpy(&RT[idx], T[i], sizeof(ZLRECT) );

			//-- using the following way, the addresses are independent each other.
			//-- RT[]: the "train" with header T[i]; i.e.

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
				//if(index[i][ll] <= 0 || idx >=10) // the last index[i][j] that is 0 ;idx >=5)
				
				if(index[i][ll] <= 0 || idx >=TRAINLONG) // the last indes[i][j] that is 0 ;idx >=5)
					break;   //break for(ll = 1; ll<= m; ll++)
 			
				for(j=1; j<=m; j++)
				{
					//if(S[j].cn <=0)
					//if(S[j].cn <=1000)//2005.3.16
					//if(S[j].cn <=12)  //2005.3.24
					if(S[j].cn <= PartNum)  //2005.4.28 //S[j].cn no clustering 
					{
						//--- see the "train" , all RT[ll]'s,  do or not intersect with S[j]
						for( k=1; k<=n; k++) //n is the number of dimensions 
						{
							/*** 2005.5.15
							 p = __max(RT[ll].a[k], S[j].a[k]);
							 q = __min(RT[ll].b[k], S[j].b[k]);
							2005.5.15 ***/

							///// 2005.5.15 change //////	
							center = (double)(S[j].a[k] + S[j].b[k])/2.0;
							Dalta  = (double)(RT[ll].b[k] - RT[ll].a[k])*ALFA;
										
							///// 2005.5.15 change //////

							//???  here l ==8; but T[index[i][ll] =93 > 8 there is problem 
							// using RT to replace T and idx replace m in forloop is OK !!!
							
							//if(p<q) //the intersection is not empty, 
							
							if( ( (RT[ll].a[k]+Dalta) <= center) && (center <= (RT[ll].b[k]-Dalta) ) ) //the (epcilong+ Center in) the part[i]
							//if( ( (RT[ll].a[k]) <= center) && (center <= (RT[ll].b[k]) ) ) //the Center in the part[i]
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

							//if(idx>=10) //the max (the long of the train) is 10 or 5
							if(idx>=TRAINLONG) //the max (the long of the train) is 10 or 5
							{	
								bInterable = false;
								break; // break for j and then break for ll
							}
						}//if(bInterable) //if intersectable

					} //if(S[j].cn <=0)

				} //for(j= 1; j<=m; j++)

			} //for(ll =1; ll<=idx; ll++)

			// to calculte the volume of Union
			if(idx>=2)
			{

				////?maybe RT[i] need to asign new value for .sufend, .suf1st
				
				////cstrMarc += "T[i]: ";
				
				//sprintf(temp, "T[%02i]: ", i);
				//cstrMarc += temp;

				//cstrMarc += T[i]->suffix;
				//cstrMarc += "\r\n";
				//cstrMarc += "RT:   ";

				Sum_vi =0.0;
				for(k =1; k<=idx; k++)
				{
					Sum_vi = Sum_vi + RT[k].v;
				//---test----
					//cstrMarc += ",";
					//cstrMarc += RT[k].suffix;
					RT[k].suf1st = k;
					RT[k].sufend = k;
				//---test----
				}

				//-- obtain the scr of the current Train 
				for(int ii=1; ii<=n; ii++ )
				{
					scr.a[ii] = RT[1].a[ii];
					scr.b[ii] = RT[1].b[ii];

					for(k =1; k<=idx; k++ )
					{
						scr.a[ii] = min(scr.a[ii], RT[k].a[ii]);
						scr.b[ii] = max(scr.b[ii], RT[k].b[ii]);	
					}
				}

				scr.v = 1.0;
				if(n<25)
				{
					for(ii=1; ii<=n; ii++ )
						scr.v *= (scr.b[ii]-scr.a[ii]);
				}
				else
				{
					for(ii=1; ii<=n; ii++ )
						scr.v *= ( (scr.b[ii]-scr.a[ii])/VFactor );

				}
				
				//--obtain the Volume of the Union of the Trian 
				double Union_v = zlVolumeOfUnion(idx, n, RT);

				//cstrMarc += "\r\n";
				//sprintf(temp, "Sum_vi= %G , scr_v=%G, Union_v=%G ", Sum_vi, scr.v, Union_v);
				//cstrMarc += temp;

				//cstrMarc += "\r\n";
				//cstrMarc += "\r\n";


				//make a decision to give cluster number
				// by using 3 values : 1. Sum_vi, 2. scr_v,  and 3. Union_v 
				//---	a = Union_v/Sum_vi  <= 1, i.e. Union_v <= Sum_vi
	            //		b = Union_v/scr_v   <= 1  i.e. Union_v <= scr_v  
				//		c = scr_v/Sum_vi	non-determined	
				
				// if a ~~ 1 AND c >>> 1, i.e. the angles intersect,
	            // then we do not clustering. 
				// not clustering, and then restore the cluster number cn 
				
				//double c = scr.v/Sum_vi;

				//if( (Sum_vi <= 1.2*Union_v) && ( pow(1.8, n-1) * Sum_vi <= scr.v ) ) 
				//if(  pow(1.8, n-1) * Sum_vi <= scr.v  ) 
				//if(  2.0 <= (scr.v/Sum_vi) ) 
				//if(  (Sum_vi/Union_v <= 1.2) && (scr.v/Sum_vi) >= pow(2.0, n-1) ) 
				//if( (scr.v/Sum_vi) >= pow(2.0, n-1) ) 

				//if( (scr.v/Sum_vi) >= pow(4.0, n-1) ) 	//IF SCR/SUM >4	
				
				//double dpow = pow(4.0, n-1); 
				
				double dpow = 2.0; 
				double da =(scr.v/Union_v);
				double c2 = 0;
				c2 = xi ; //asigh a threshold to c2

				//if( (scr.v/Union_v) >= dpow) 	//IF SCR/Union_v >4	 then not Clustering 					
				if( (Union_v/scr.v) < c2) 	//IF Union_v/SCR < c2,	 then not Clustering 					
				//if( (Union_v/scr.v) <= c2) 	//IF Union_v/SCR < c2,	 then not Clustering 					
				{                            // Union_v = v(Union), SCR =v(SCR) c2 is in (0,1]

					//sprintf(temp, "scr_v[%02i]=%G, Sum_vi= %G, scr.v/Sum_vi=%G ",iclsNum, scr.v, Sum_vi, scr.v/Sum_vi);
					//cstrMarc += temp;
					//cstrMarc += "\r\n";


					iclsNum = iclsNumHold; //iclsNum--;
					T[i]->cn = part_cn;
					for(k =1+1; k<=idx; k++ )
					{
						S[ index[i][k] ].cn = cn[ index[i][k] ];
					}
				
				}

//test ---11--
	//FileNum ++;
	//CString cstrMarc1;
   /*
	if((scr.v/Union_v) >= dpow)
		sprintf(temp, "(scr.v/Union_v): %G >= dpow : %G  ", scr.v/Union_v, dpow);
	else
		sprintf(temp, "(scr.v/Union_v): %G <= dpow : %G  ", scr.v/Union_v, dpow);
    cstrMarc += temp;
   */
	//sprintf(temp, "E:\\Paper2\\CLMB_census2D\\zlClusterPart\\zlClusterPart%02i.txt", FileNum);
	//CFile file;
	//if(file.Open(temp, CFile::modeCreate | CFile::modeReadWrite ) != 0)
	//{
	//	file.Write(cstrMarc1, cstrMarc1.GetLength() +1 );
	//}
	//file.Close();
//test ---11--

			}
			else  //2005.3.23  when idx < 2
			{
				iclsNum = iclsNumHold;
				T[i]->cn = part_cn ;
			}//if(idx>=2)

		}//if( T[i]->cn <=0 )

	} //for(i= 1; i<=l; i++) // there are l rectangle in some part //

//test ---1133--
  /*
	if(! cstrMarc.IsEmpty() )
	{
		FileNum = + GetTickCount();
		sprintf(temp, "E:\\Paper2\\CLMB_census2D\\zlClusterPart\\zl\\zl%02i.txt", FileNum);
		CFile file;
		if(file.Open(temp, CFile::modeCreate | CFile::modeReadWrite ) != 0)
		{
			file.Write(cstrMarc, cstrMarc.GetLength() +1 );
		}
		file.Close();
	}
	*/
//test ---1133--



	//delete [] scr.a;
	//delete [] scr.b;
	//for(i=1; i<=m; i++)
	//{
	//	delete [] RT[i].a;
	//	delete [] RT[i].b;
	//}
	delete [] RT;

	return iclsNum;
}
///////////////Using 3+C-Clustering   end///////////////

double CLearnIing6App::zlVolumeOfUnion(int iCountRt, int iDimension, ZLRECT *S)
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
	//CString cstrMarc = "";
	//char temp[1000] = "";

		//for(i=1; i<=m; i++)
		//{	
			//sprintf(temp, "S%02i: ", i);
			//cstrMarc += temp;
			
			//for(j=1; j<=n; j++)
			//{
			//	sprintf(temp, "[%i, %i] ", (int)S[i].a[j], (int)S[i].b[j] );
			//	cstrMarc += temp;

			//}

			//sprintf(temp, " v = %.15G: ", S[i].v );
			//cstrMarc += temp;

			//cstrMarc += "\r\n";
		//}

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
	//for(j =1; j<=iNum_Intersection; j++)
	//{
		//rt[1][j].a = new double[n+1];
		//rt[1][j].b = new double[n+1];
	//}

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
						 //sprintf(temp, "V%02i: ", h);
						 //cstrMarc += temp;
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
								rt[h][j].v *= ( (q-p)/VFactor );
							
							bInterable = true;
						} //if(p<q)
						else //the intersection is empty or p=q
						{
							rt[h][j].v = 1.0; //where the last l, where some (q-p)>0 
							bInterable = false;
							break; //for i
						}
					} //for(i=1; i<=n, i++)
					
					if(bInterable) //if intersectionable
					{
						bInterable = false; //add this line 2005.5.15 maybe not necessary
						strcpy( rt[h][j].suffix, rt[h-1][k].suffix);
						sprintf(buffer, ",%i", l);
						strcat(rt[h][j].suffix, buffer);
						
						rt[h][j].suf1st = rt[h-1][k].suf1st;
						rt[h][j].sufend = l;
						
						v[h] +=rt[h][j].v; //obtain v[h]

						//--- for debug---------------------------------------------
							 //cstrMarc += ":::: ";

							 //cstrMarc += rt[h][j].suffix;
							 //cstrMarc += ": ";
							 //sprintf(temp, "v = %.15G; ", v[h]);
							 //cstrMarc += temp;

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
							//cstrMarc += "\r\n";
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

		//CFile file;

		//if(file.Open("E:\\Paper2\\CLMB_census2D\\Intersection.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
		//{
		//	file.Write(cstrMarc, cstrMarc.GetLength() +1 );
		//}
		//file.Close();

	//------1 end ---

	//delete memory by operater new
	//for (i = 1; i <=m; i++)
		//delete [] rt[i];
	delete [] rt;

	delete [] v;

//~~~~~~  end ~~~~~

	return Totall_v;
}

int CLearnIing6App::c(int m, int i)
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

/*****
bool CLearnIing6App::zlOpenDB()
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

bool CLearnIing6App::zlCloseDB()
{
	SQLFreeStmt(hstmt, SQL_DROP); //2005.3.7
	SQLDisconnect(hdbc);
	SQLFreeConnect(hdbc);
	SQLFreeEnv(henv);

	return true;
}

*****/
//int CLearnIing6App::zlExeSelect(char *TableName, char *szSql)

int CLearnIing6App::zlExeSelect(int PreTuplesNum, char *szSql)
{
	//if(!zlOpenDB())
	{
		//AfxMessageBox("zlOpenDB() err!");
		//zlCloseDB();
	}

	int iRowCnt = -1;
    int iTupleNum;

	double  fCol[COL_NUM+1];		//Elevation
	SDWORD cbCol[COL_NUM+1]; 	
	SDWORD sColID =0; 
	SDWORD cbColID =0; 
	int iQryIdx =1;  //---pApp->tpl[i] is based 1
	char tmp[512];
	int i;


			/////////----
				/*	CString cstrMarc1;
					cstrMarc1 = szSql;
					CFile file;
					//if(file.Open("E:\\Paper2\\Lsi_050D\\AppSelect.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
					//if(file.Open("E:\\Paper2\\Lsi_104D\\AppSelect.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
					//if(file.Open("E:\\Paper2\\Lsi_025D\\AppSelect.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
					if(file.Open("E:\\Paper2\\COVER4D\\AppSelect.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
					//if(file.Open("E:\\Paper2\\Gauss3D\\AppSelect.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
					//if(file.Open("E:\\Paper2\\Array3D\\AppSelect.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
					//if(file.Open("E:\\Paper2\\Census3D\\AppSelect.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
					//if(file.Open("E:\\Paper2\\Census2D\\AppSelect.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)

					{
						file.Write(cstrMarc1, cstrMarc1.GetLength() +1 );
					}
					file.Close();*/
		/////////----

	/////////////////////////////////////////////////////
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
			
	       long lStartTimer =0;  
		   long lEndTimer =0;   



	       lStartTimer  = GetTickCount();

	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
	{  //	retcode = SQLExecDirect
	

		int iRowCount;
		SDWORD *  RowCountPtr = new SDWORD ;
		retcode = SQLRowCount(hstmt, RowCountPtr);						 
		iRowCount = * RowCountPtr;
		delete RowCountPtr;
		iRowCnt = iRowCount;
		iTupleNum = iRowCount;


		if(iRowCnt <=0)
			return iRowCnt;

		delete [] tpl;
		tpl = new TUPLE[iRowCount+1 +PreTuplesNum];

		//t_Num[0] = new int[iRowCount+1+PreTuplesNum];
		//tuple[0] = new TUPLE[iRowCount+1+PreTuplesNum];

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
				
				for(i = 1; i<=COL_NUM; i++)
				{
					tpl[iQryIdx].x[i] = fCol[i-1];
				}
				
				tpl[iQryIdx].ID		= sColID;
				//tpl[iQryIdx].bIN    = true;
				//tuple[0][iQryIdx] = tpl[iQryIdx];  //save the index of tpl[i]
		
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

lEndTimer =GetTickCount() - lStartTimer ;

	//----- body-----------------
	return iRowCnt;

}

int CLearnIing6App::zlExeSelect2(int PreTuplesNum, char *szSql, int l)
{
	//if(!zlOpenDB())
	{
		//AfxMessageBox("zlOpenDB() err!");
		//zlCloseDB();
	}

	int iRowCnt = -1;
    int iTupleNum;

	double  fCol[COL_NUM+1];		//Elevation
	SDWORD cbCol[COL_NUM+1]; 	
	SDWORD sColID =0; 
	SDWORD cbColID =0; 
	int iQryIdx =1;  //---pApp->tpl[i] is based 1
	char tmp[512];
	int i;


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
		int iRowCount;
		SDWORD *  RowCountPtr = new SDWORD ;
		retcode = SQLRowCount(hstmt, RowCountPtr);						 
		iRowCount = * RowCountPtr;
		delete RowCountPtr;
		iRowCnt = iRowCount;
		iTupleNum = iRowCount;


		if(iRowCnt <=0)
			return iRowCnt;

		//delete [] tpl;
		//tpl = new TUPLE[iRowCount+1 +PreTuplesNum];

		//t_Num[0] = new int[iRowCount+1+PreTuplesNum];
		
		delete [] tuple[l];		
		tuple[l] = new TUPLE[iRowCount+1 +PreTuplesNum];

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
				
				for(i = 1; i<=COL_NUM; i++)
				{
					//tpl[iQryIdx].x[i] = fCol[i-1];
				    tuple[l][iQryIdx].x[i] = fCol[i-1];
				}
				
				//tpl[iQryIdx].ID		= sColID;
				//tpl[iQryIdx].bIN    = true;
				//tuple[0][iQryIdx] = tpl[iQryIdx];  //save the index of tpl[i]
			    tuple[l][iQryIdx].ID		= sColID;
	
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


int CLearnIing6App::zlGetTopNTuple(int QueryNum, ZLRECT *S, int tuplesNum)
{
	int iCandidateNum =-1;

///////////////// Get TopN tuples Start //////////////

	//1. Obtain all distance From Query to tuples
    //#define  DIS_NUM   -1 //2 // 1 == L1; 2 == L2; -1 =Linf

	int iRowCnt = tuplesNum;
	double x[COL_NUM +1];
	
	//double a, b;
    //double EPCINO = 0.0000000000001; //13_0
	double EPCINO = 0.00000000000001; //14_0

    //double EPCINO = 0.000000000000001; //15_0

	int iTopN =Q[QueryNum].N ;
	//double r[2000];
	//double dis[2000];
	double r[100+1];     //
	double dis[100+1];

	double ftmp =0 ;
	int tIndex[100+1]; //or 2000
	//int tID[100];
	int iNumTmp;
	int i,j,k, ii, jj, kk;
	long lStartTimer = GetTickCount();
	long lEndTimer;

	delete [] t;
	t = new TUPLE[iRowCnt +1];

	/*********
	bool bInRect =false;
    k=0;

	for(i = 1; i<=iRowCnt; i++)
	{

		bInRect =false;
		for(j = 1; j<=COL_NUM; j++)
		{								//3.26363E+37 fabs(
			if(S[QueryNum].a[j] == 0.0)
				a=tpl[i].x[j];
			else if(tpl[i].x[j] == 0)
				a = - S[QueryNum].a[j];
			else
				a = fabs(tpl[i].x[j]/S[QueryNum].a[j]) -1;

			if(tpl[i].x[j] == 0.0)
				b = - S[QueryNum].b[j];
			else if ( S[QueryNum].b[j] ==0 )
				b =  - tpl[i].x[j];
			else
				b = fabs( S[QueryNum].b[j]/tpl[i].x[j] - 1 );
         
			//if( (S[QueryNum].a[j] <= tpl[i].x[j] && tpl[i].x[j] <= S[QueryNum].b[j]) || ( -EPCINO <=a && b <= EPCINO ) )
			if( (S[QueryNum].a[j] <= tpl[i].x[j] || -EPCINO <=a ) && ( tpl[i].x[j] <= S[QueryNum].b[j] || b <= EPCINO ) )			
			{	
				bInRect =true;
			}
			else
			{
				bInRect =false;
				break;   //for j
			}
		}
		if(bInRect)
		{
			k++;
			t[k] = tpl[i];
			t[k].num = k;
		}
	}
	*********/
	/*********
	bool bInRect =true;
    k=0;

	lStartTimer = GetTickCount();
	for(i = 1; i<=iRowCnt; i++)
	{

		bInRect =true;
		for(j = 1; j<=COL_NUM; j++)
		{
			if(S[QueryNum].a[j] == 0.0)
				a = tpl[i].x[j];
			else if(tpl[i].x[j] == 0)
				a = - S[QueryNum].a[j];
			else
				a = (tpl[i].x[j]-S[QueryNum].a[j])/fabs(S[QueryNum].a[j])  ;

			if(tpl[i].x[j] == 0.0)
				b = - S[QueryNum].b[j];
			else if ( S[QueryNum].b[j] ==0 )
				b =  tpl[i].x[j];
			else
				b = (tpl[i].x[j] -S[QueryNum].b[j])/fabs(S[QueryNum].b[j]);

			//if( (S[QueryNum].a[j] <= tpl[i].x[j] && tpl[i].x[j] <= S[QueryNum].b[j]) )
			if( (a < -EPCINO  ) ||  EPCINO < b  )			
			//if( (S[QueryNum].a[j] > tpl[i].x[j] ||(a < -EPCINO  )) || (tpl[i].x[j] > S[QueryNum].b[j]) ||EPCINO < b )		
			{	
				bInRect =false;
				break;   //for j
			}
		}
		if(bInRect)
		{
			k++;
			t[k] = tpl[i];
			t[k].num = k;
		}
	}
	************/
	double S_a[COL_NUM +1], S_b[COL_NUM +1] ;  ;
	bool bInRect =true;
    k=0;

	if(COL_NUM > 24 )
	{
		for(j = 1; j<=COL_NUM; j++)
		{
			if(S[QueryNum].a[j] ==0.0)
			   S[QueryNum].a[j] = EPCINO;
			if(S[QueryNum].b[j] ==0.0)
			   S[QueryNum].b[j] = EPCINO;

			S_a[j] = S[QueryNum].a[j] - fabs(EPCINO*S[QueryNum].a[j]); 
			S_b[j] = S[QueryNum].b[j] + fabs(EPCINO*S[QueryNum].b[j]); 
			//S_a[j] = 0.99999999999999 * S[QueryNum].a[j]; 
			//S_b[j] = 1.00000000000001 * S[QueryNum].b[j]; 
		}
	}
	else
	{
		for(j = 1; j<=COL_NUM; j++)
		{
			S_a[j] = S[QueryNum].a[j]; 
			S_b[j] = S[QueryNum].b[j]; 
		}
	}

	lStartTimer = GetTickCount();
	for(i = 1; i<=iRowCnt; i++)
	{

		bInRect =true;
		for(j = 1; j<=COL_NUM; j++)
		{
			if(  tpl[i].x[j]< S_a[j]  ||  S_b[j] <tpl[i].x[j]  )		
			{	
				bInRect =false;
				break;   //for j
			}
			///////test ////
			else
				bInRect =true;
			///////test ////

		}
		if(bInRect)
		{
			k++;
			t[k] = tpl[i];
			t[k].num = k;
		}
	}
	lEndTimer = GetTickCount()-lStartTimer;
	CString str = "";
	char temp[512] ="";

	sprintf(temp, "1. QueryNum = %i; iCandidateNum = %i; Ticks = %i; ", QueryNum, k, lEndTimer);
	str += temp;
	str += "\r\n";
   //if(k>3000)
	//AfxMessageBox(temp);	



	iCandidateNum = k;
	//In this function: iRowCnt >= iTopN;
	if(iCandidateNum < iTopN)
	{
		//str += "zlGetTopNTuple: iCandidateNum < iTopN ";
		//str += "\r\n";
		//sprintf(temp, "1. QueryNum = %i; iCandidateNum = %i; Ticks = %i; ", QueryNum, k, lEndTimer);
		//str += temp;
		//str += "\r\n";

		//AfxMessageBox(temp);	
		return iCandidateNum; 
		//Q[QueryNum].r := __max( distance from Q[QueryNum] to 
		 // tpl[1],..., tpl[iTopN]) caller will do this work.
	}

	if(iCandidateNum <= 0)
	{
		str += "zlGetTopNTuple: iCandidateNum < iTopN ";
		str += "\r\n";
		sprintf(temp, "1. QueryNum = %i; iCandidateNum = %i; Ticks = %i; ", QueryNum, k, lEndTimer);
		str += temp;
		str += "\r\n";

		AfxMessageBox(temp);	
		return iCandidateNum; 
		//Q[QueryNum].r := __max( distance from Q[QueryNum] to 
		 // tpl[1],..., tpl[iTopN]) caller will do this work.
	}

	//calculate the distance from Q[QueryNum] to t[j], save it in t[j].d
	for(k = 1; k<=iCandidateNum; k++)
	{

		for(j = 1; j<=COL_NUM; j++)
			x[j] = fabs( t[k].x[j] - Q[QueryNum].q[j] );

		switch (DIS_NUM)
		{
			case 1:
			{
				//---for Sum distance, L1
				t[k].d = x[1];
		 		for(j = 2; j<=COL_NUM; j++)
					t[k].d += x[j];
				break;
			}
			case 2:
			{
				//----for Eucl distance, L2
				t[k].d = x[1]*x[1];
		 		for(j = 2; j<=COL_NUM; j++)
					t[k].d += x[j]*x[j];
				t[k].d = sqrt( t[k].d );

				break;
			}
			case -1:
			{
				//----for Max distance, Linf
				t[k].d = x[1];
				for(j = 2; j<=COL_NUM; j++)
					t[k].d = (double)__max(t[k].d, x[j]);				
				break;
			}//switch (DIS_NUM)
		} 

	}//for(k = 1; k<=iRowCnt; k++)

		//iTopN = Q[i].N;

	//sorting the distance of the FIRST iTopN tuples
	// saved in r[j];

	for(j=1; j<=iTopN; j++)
	{
		dis[j]=t[j].d;
	}

	for(j=1; j<=iTopN; j++)
	{
		r[j] = dis[j];

		   for( k= j+1; k<=iTopN; k++)
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

		for(j=1; j<=iTopN; j++)
		{
			dis[j] = t[t[j].num].d;  //t[tIndex[j]].d;
			//tID[j] = t[tIndex[j]].ID;
		}

			int debug1 =1;
		//-----debug1----

////////////
	//2. select TopN tuples from all tuples with size iCandidateNum
			
	//lStartTimer = GetTickCount(); //2005.05.13
      
	for(ii = iTopN +1 ; ii<=iCandidateNum; ii++)
	{
		if(t[ii].d < r[iTopN])		
		{
			for(jj=1;jj<=iTopN;jj++)
			{
				if( t[ii].d < r[jj]) // t[ii] insert the jj seat
				{
					
					iNumTmp = t[iTopN].num;

					for(kk = iTopN ; kk>jj; kk--)
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

	for(j=1; j<=iTopN; j++)
	{
		dis[j] = t[t[j].num].d;  //t[tIndex[j]].d;
		//tID[j] = t[t[j].num].ID; //t[t[j].num].ID is the topN tuples ID;
	}

		 debug1 =12;
	//-----debug1----

///////////////// Get TopN tuples End //////////////
	
	
	//----- body-----------------
	return iCandidateNum;

}

int CLearnIing6App::zlGetTopNTuple_High(int QueryNum, ZLRECT *S, int tuplesNum)
{

	Qi++;                 //only for test 
	Qidx[Qi]=QueryNum;    //only for test
	//----------test ------------
    //if(QueryNum == 2)
		//int iiias=1;
    //----------test --------
	int iCandidateNum =-1;

///////////////// Get TopN tuples Start //////////////
    int bsn;
	int i,j,k, ii, jj, kk;

	//if S[QueryNum].tplNum <=0 call this function
	bsn = 0; 
	//1. Obtain all distance From Query to tuples
    //#define  DIS_NUM    -1 //2 //distance Number: 1 == L1; 2 == L2; -1 =Linf

	int iRowCnt = tuplesNum;
	double x[COL_NUM +1];
	
	//double a, b;
    //double EPCINO = 0.0000000000001; //13_0
    double EPCINO = 0.000000000000001; //15_0

	int iTopN =Q[QueryNum].N ;
	//double r[2000];
	//double dis[2000];
	double r[100+1];     //
	double dis[100+1];

	double ftmp =0 ;
	int tIndex[100+1]; //or 2000
	//int tID[100];
	int iNumTmp;
	long lStartTimer = GetTickCount();
	long lEndTimer;

	delete [] t;
	t = new TUPLE[iRowCnt +1]; //the tuples in S[QueryNum]

	double S_a[COL_NUM +1], S_b[COL_NUM +1] ;  ;
	bool bInRect =true;
    k=0;
	if(COL_NUM >24)
	{
		for(j = 1; j<=COL_NUM; j++)
		{
			if(S[QueryNum].a[j] ==0.0)
			   S[QueryNum].a[j] = EPCINO;
			if(S[QueryNum].b[j] ==0.0)
			   S[QueryNum].b[j] = EPCINO;

			S_a[j] = S[QueryNum].a[j] - fabs(EPCINO*S[QueryNum].a[j]); 
			S_b[j] = S[QueryNum].b[j] + fabs(EPCINO*S[QueryNum].b[j]); 
		}
	}
	else
	{
		for(j = 1; j<=COL_NUM; j++)
		{
			S_a[j] = S[QueryNum].a[j]; 
			S_b[j] = S[QueryNum].b[j]; 
		}

	}

	for(i = 1; i<=iRowCnt; i++)
	{

		bInRect = true;
		for(j = 1; j<=COL_NUM; j++)
		{

			if(  tuple[bsn][i].x[j]< S_a[j] || S_b[j] < tuple[bsn][i].x[j]  )
			{	
				bInRect =false;
				break;   //for j
			}

		}
		if(bInRect)
		{
			k++;
			t[k] = tuple[bsn][i];
			t[k].num = k;
		}
	}


lEndTimer = GetTickCount()-lStartTimer;

	iCandidateNum = k;
	S[QueryNum].tplNum = iCandidateNum;

	//In this function: iRowCnt >= iTopN;
	if(iCandidateNum < iTopN)
	{
		
		//AfxMessageBox("iCandidateNum < iTopN");	
		return iCandidateNum; 
	
		//Q[QueryNum].r := __max( distance from Q[QueryNum] to 
		 // tuple[bsn][1],..., tuple[bsn][iTopN]) caller will do this work.
	}
	if(iCandidateNum <=0)
	{
		
		AfxMessageBox("0==iCandidateNum < iTopN ");	
		return iCandidateNum; 
	
		//Q[QueryNum].r := __max( distance from Q[QueryNum] to 
		 // tuple[bsn][1],..., tuple[bsn][iTopN]) caller will do this work.
	}
	
	//calculate the distance from Q[QueryNum] to t[j], save it in t[j].d
	for(k = 1; k<=iCandidateNum; k++)
	{

		for(j = 1; j<=COL_NUM; j++)
			x[j] = fabs( t[k].x[j] - Q[QueryNum].q[j] );

		switch (DIS_NUM)
		{
			case 1:
			{
				//---for Sum distance, L1
				t[k].d = x[1];
		 		for(j = 2; j<=COL_NUM; j++)
					t[k].d += x[j];
				break;
			}
			case 2:
			{
				//----for Eucl distance, L2
				t[k].d = x[1]*x[1];
		 		for(j = 2; j<=COL_NUM; j++)
					t[k].d += x[j]*x[j];
				t[k].d = sqrt( t[k].d );

				break;
			}
			case -1:
			{
				//----for Max distance, Linf
				t[k].d = x[1];
				for(j = 2; j<=COL_NUM; j++)
					t[k].d = (double)__max(t[k].d, x[j]);				
				break;
			}//switch (DIS_NUM)
		} 

	}//for(k = 1; k<=iRowCnt; k++)

		//iTopN = Q[i].N;

	//sorting the distance of the FIRST iTopN tuples
	// saved in r[j];

	for(j=1; j<=iTopN; j++)
	{
		dis[j]=t[j].d;
	}

	for(j=1; j<=iTopN; j++)
	{
		r[j] = dis[j];

		   for( k= j+1; k<=iTopN; k++)
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

		//for(j=1; j<=iTopN; j++)
		//{
			//dis[j] = t[t[j].num].d;  //t[tIndex[j]].d;
			//tID[j] = t[tIndex[j]].ID;
		//}

			//int debug1 =1;
		//-----debug1----

////////////
	//2. select TopN tuples from all tuples with size iCandidateNum
			
	//lStartTimer = GetTickCount(); //2005.05.13
      
	for(ii = iTopN +1 ; ii<=iCandidateNum; ii++)
	{
		if(t[ii].d < r[iTopN])		
		{
			for(jj=1;jj<=iTopN;jj++)
			{
				if( t[ii].d < r[jj]) // t[ii] insert the jj seat
				{
					
					iNumTmp = t[iTopN].num;

					for(kk = iTopN ; kk>jj; kk--)
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
/*
	//delete [] tuple[QueryNum];
    //tuple[QueryNum] = new TUPLE[iCandidateNum+1];

	//for(k = 1; k<=iCandidateNum; k++)
	//{
		//tuple[QueryNum][k] = t[k];
	//}
*/
	//-----debug12----

	//for(j=1; j<=iTopN; j++)
	//{
		////dis[j] = t[t[j].num].d;  //t[tIndex[j]].d;
		////tID[j] = t[t[j].num].ID; //t[tIndex[j]];


		////Q[QueryNum]'s TopN tuples are as follows
		//k = tuple[QueryNum][j].num; //.num : the number in sorting topNsequence
		//dis[j] = tuple[QueryNum][k].d;  //t[tIndex[j]].d;
		//tID[j] = tuple[QueryNum][k].ID;

		//tuple[QueryNum][tuple[QueryNum][j].num].ID
	//}

		 //debug1 =12;
	//-----debug1----

///////////////// Get TopN tuples End //////////////
	
	
	//----- body-----------------
	return iCandidateNum;

}

int CLearnIing6App::zlGetTopNTuple_Mul(int QueryNum, ZLRECT *S, int tuplesNum)
{

	Qi++;                 //only for test 
	Qidx[Qi]=QueryNum;    //only for test
	//----------test ------------
    //if(QueryNum == 2)
		//int iiias=1;
    //----------test --------
	int iCandidateNum =-1;

///////////////// Get TopN tuples Start //////////////
    int bsn;
	int i,j,k, ii, jj, kk;

	//if S[QueryNum].tplNum <=0 call this function

	 if( S[QueryNum].bsn  > 123456 ) // 1000.  S[i] is a not subset of another .		
			bsn = 0;
     else if( S[QueryNum].bsn <= 123456 ) //1000.  S[i] is a subset of another .		
	 {
		bsn = S[QueryNum].bsn; // the number of big set that contains S[QueryNum] 
		if( S[S[QueryNum].bsn].tplNum <=0)
		{
			//zlGetTopNTuple(S[QueryNum].bsn ); //IMportant
			tuplesNum = zlGetTopNTuple_Mul(S[QueryNum].bsn, S, tuplesNum);

		}
		if(S[QueryNum].v == S[S[QueryNum].bsn].v) //if two queries are identity 
		{
			delete [] tuple[QueryNum];
			tuple[QueryNum] = new TUPLE[ S[S[QueryNum].bsn].tplNum +1];

			for(i=1; i<=S[S[QueryNum].bsn].tplNum; i++)
			    tuple[QueryNum][i] = tuple[S[QueryNum].bsn][i];

			return S[S[QueryNum].bsn].tplNum;			

		}
		else if(S[S[QueryNum].bsn].tplNum >=0)
			tuplesNum = S[S[QueryNum].bsn].tplNum;

	 }


	//1. Obtain all distance From Query to tuples
    //#define  DIS_NUM    -1 //2 //distance Number: 1 == L1; 2 == L2; -1 =Linf

	int iRowCnt = tuplesNum;
	double x[COL_NUM +1];
	
	//double a, b;
    //double EPCINO = 0.0000000000001; //13_0
    double EPCINO = 0.000000000000001; //15_0

	int iTopN =Q[QueryNum].N ;
	//double r[2000];
	//double dis[2000];
	double r[100+1];     //
	double dis[100+1];

	double ftmp =0 ;
	int tIndex[100+1]; //or 2000
	//int tID[100];
	int iNumTmp;
	long lStartTimer = GetTickCount();
	long lEndTimer;

	delete [] t;
	t = new TUPLE[iRowCnt +1]; //the tuples in S[QueryNum]


	/*************
	bool bInRect =false;
    k=0;

	for(i = 1; i<=iRowCnt; i++)
	{

		bInRect =false;
		for(j = 1; j<=COL_NUM; j++)
		{
			if(S[QueryNum].a[j] == 0.0)
				//a=tpl[i].x[j];
				a = tuple[bsn][i].x[j];
			else if(tuple[bsn][i].x[j] == 0)
				a = - S[QueryNum].a[j];
			else
				a = fabs(tuple[bsn][i].x[j]/S[QueryNum].a[j]) -1;

			if(tuple[bsn][i].x[j] == 0.0)
				b = - S[QueryNum].b[j];
			else if ( S[QueryNum].b[j] ==0 )
				b =  - tuple[bsn][i].x[j];
			else
				b = fabs( S[QueryNum].b[j]/tuple[bsn][i].x[j] - 1 );

			//if( (S[QueryNum].a[j] <= tuple[bsn][i].x[j] && tuple[bsn][i].x[j] <= S[QueryNum].b[j]) )
			if( (S[QueryNum].a[j] <= tuple[bsn][i].x[j] || -EPCINO <=a ) && ( tuple[bsn][i].x[j] <= S[QueryNum].b[j] || b <= EPCINO ) )			
			{	
				bInRect =true;
			}
			else
			{
				bInRect =false;
				break;   //for j
			}
		}
		if(bInRect)
		{
			k++;
			t[k] = tuple[bsn][i];
			t[k].num = k;
		}
	}
	****************/
	/****************
	double S_a[COL_NUM +1], S_b[COL_NUM +1] ;  ;

	bool bInRect =true;
    k=0;

	for(i = 1; i<=iRowCnt; i++)
	{

		bInRect =true;
		for(j = 1; j<=COL_NUM; j++)
		{
			if(S[QueryNum].a[j] == 0.0)
				a = tuple[bsn][i].x[j];
			else if(tuple[bsn][i].x[j] == 0)
				a = - S[QueryNum].a[j];
			else
				a = (tuple[bsn][i].x[j]-S[QueryNum].a[j])/fabs(S[QueryNum].a[j])  ;

			if(tuple[bsn][i].x[j] == 0.0)
				b = - S[QueryNum].b[j];
			else if ( S[QueryNum].b[j] ==0 )
				b =  tuple[bsn][i].x[j];
			else
				b = (tuple[bsn][i].x[j] -S[QueryNum].b[j])/fabs(S[QueryNum].b[j]);

			//if( (S[QueryNum].a[j] <= tuple[bsn][i].x[j] && tuple[bsn][i].x[j] <= S[QueryNum].b[j]) )
			if( (a < -EPCINO  ) ||  EPCINO < b  )			
			{	
				bInRect =false;
				break;   //for j
			}

		}
		if(bInRect)
		{
			k++;
			t[k] = tuple[bsn][i];
			t[k].num = k;
		}
	}
****************/
	double S_a[COL_NUM +1], S_b[COL_NUM +1] ;  ;
	bool bInRect =true;
    k=0;
	if(COL_NUM >24)
	{
		for(j = 1; j<=COL_NUM; j++)
		{
			if(S[QueryNum].a[j] ==0.0)
			   S[QueryNum].a[j] = EPCINO;
			if(S[QueryNum].b[j] ==0.0)
			   S[QueryNum].b[j] = EPCINO;

			S_a[j] = S[QueryNum].a[j] - fabs(EPCINO*S[QueryNum].a[j]); 
			S_b[j] = S[QueryNum].b[j] + fabs(EPCINO*S[QueryNum].b[j]); 
		}
	}
	else
	{
		for(j = 1; j<=COL_NUM; j++)
		{
			S_a[j] = S[QueryNum].a[j]; 
			S_b[j] = S[QueryNum].b[j]; 
		}

	}

	for(i = 1; i<=iRowCnt; i++)
	{

		bInRect = true;
		for(j = 1; j<=COL_NUM; j++)
		{

			if(  tuple[bsn][i].x[j]< S_a[j] || S_b[j] < tuple[bsn][i].x[j]  )
			{	
				bInRect =false;
				break;   //for j
			}

		}
		if(bInRect)
		{
			k++;
			t[k] = tuple[bsn][i];
			t[k].num = k;
		}
	}


lEndTimer = GetTickCount()-lStartTimer;

	iCandidateNum = k;
	S[QueryNum].tplNum = iCandidateNum;

	//In this function: iRowCnt >= iTopN;
	if(iCandidateNum < iTopN)
	{
		
		//AfxMessageBox("iCandidateNum < iTopN");	
		return iCandidateNum; 
	
		//Q[QueryNum].r := __max( distance from Q[QueryNum] to 
		 // tuple[bsn][1],..., tuple[bsn][iTopN]) caller will do this work.
	}
	if(iCandidateNum <=0)
	{
		
		AfxMessageBox("0==iCandidateNum < iTopN ");	
		return iCandidateNum; 
	
		//Q[QueryNum].r := __max( distance from Q[QueryNum] to 
		 // tuple[bsn][1],..., tuple[bsn][iTopN]) caller will do this work.
	}
	
	//calculate the distance from Q[QueryNum] to t[j], save it in t[j].d
	for(k = 1; k<=iCandidateNum; k++)
	{

		for(j = 1; j<=COL_NUM; j++)
			x[j] = fabs( t[k].x[j] - Q[QueryNum].q[j] );

		switch (DIS_NUM)
		{
			case 1:
			{
				//---for Sum distance, L1
				t[k].d = x[1];
		 		for(j = 2; j<=COL_NUM; j++)
					t[k].d += x[j];
				break;
			}
			case 2:
			{
				//----for Eucl distance, L2
				t[k].d = x[1]*x[1];
		 		for(j = 2; j<=COL_NUM; j++)
					t[k].d += x[j]*x[j];
				t[k].d = sqrt( t[k].d );

				break;
			}
			case -1:
			{
				//----for Max distance, Linf
				t[k].d = x[1];
				for(j = 2; j<=COL_NUM; j++)
					t[k].d = (double)__max(t[k].d, x[j]);				
				break;
			}//switch (DIS_NUM)
		} 

	}//for(k = 1; k<=iRowCnt; k++)

		//iTopN = Q[i].N;

	//sorting the distance of the FIRST iTopN tuples
	// saved in r[j];

	for(j=1; j<=iTopN; j++)
	{
		dis[j]=t[j].d;
	}

	for(j=1; j<=iTopN; j++)
	{
		r[j] = dis[j];

		   for( k= j+1; k<=iTopN; k++)
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
		for(j=1; j<=iTopN; j++)
		{
			dis[j] = t[t[j].num].d;  //t[tIndex[j]].d;
			//tID[j] = t[tIndex[j]].ID;
		}

			int debug1 =1;
		//-----debug1----
*/
////////////
	//2. select TopN tuples from all tuples with size iCandidateNum
			
	//lStartTimer = GetTickCount(); //2005.05.13
      
	for(ii = iTopN +1 ; ii<=iCandidateNum; ii++)
	{
		if(t[ii].d < r[iTopN])		
		{
			for(jj=1;jj<=iTopN;jj++)
			{
				if( t[ii].d < r[jj]) // t[ii] insert the jj seat
				{
					
					iNumTmp = t[iTopN].num;

					for(kk = iTopN ; kk>jj; kk--)
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

	delete [] tuple[QueryNum];
    tuple[QueryNum] = new TUPLE[iCandidateNum+1];

	for(k = 1; k<=iCandidateNum; k++)
	{
		tuple[QueryNum][k] = t[k];
	}

	//-----debug12----
/*
	for(j=1; j<=iTopN; j++)
	{
		//dis[j] = t[t[j].num].d;  //t[tIndex[j]].d;
		//tID[j] = t[t[j].num].ID; //t[tIndex[j]];


		//Q[QueryNum]'s TopN tuples are as follows
		k = tuple[QueryNum][j].num; //.num : the number in sorting topNsequence
		dis[j] = tuple[QueryNum][k].d;  //t[tIndex[j]].d;
		tID[j] = tuple[QueryNum][k].ID;

		//tuple[QueryNum][tuple[QueryNum][j].num].ID
	}

		 debug1 =12;
*/
	//-----debug1----

///////////////// Get TopN tuples End //////////////
	
	
	//----- body-----------------
	return iCandidateNum;

}

int CLearnIing6App::zlExeSelect_High(int PreTuplesNum, int PreScrNum, char *szSql, ZLRECT * scr_CLS, int CurScrNum)
{
//	if(!zlOpenDB())
	{
		//AfxMessageBox("zlOpenDB() err!");
		//zlCloseDB();
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


			/////////----
			/*		CString cstrMarc1;
					cstrMarc1 = szSql;
					CFile file;
					//if(file.Open("E:\\Paper2\\Lsi_050D\\AppSelect.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
					if(file.Open("E:\\Paper2\\Lsi_104D\\AppSelect.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
					//if(file.Open("E:\\Paper2\\Lsi_025D\\AppSelect.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
					//if(file.Open("E:\\Paper2\\COVER4D\\AppSelect.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
					//if(file.Open("E:\\Paper2\\Gauss3D\\AppSelect.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
					//if(file.Open("E:\\Paper2\\Array3D\\AppSelect.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
					//if(file.Open("E:\\Paper2\\Census3D\\AppSelect.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
					//if(file.Open("E:\\Paper2\\Census2D\\AppSelect.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
					{
						file.Write(cstrMarc1, cstrMarc1.GetLength() +1 );
					}
					file.Close(); 
					*/
		/////////----

	/////////////////////////////////////////////////////
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
		iTupleNum = iRowCount;


		//if(iRowCnt <=0)
			//return iRowCnt;

		TUPLE * tmp_tpl = new TUPLE[iRowCount+1 +PreTuplesNum];
		
		//delete [] tpl;
		//tpl = new TUPLE[iRowCount+1 +PreTuplesNum];

		////t_Num[0] = new int[iRowCount+1+PreTuplesNum];
		//delete [] tuple[0];
		//tuple[0] = new TUPLE[iRowCount+1+PreTuplesNum];

		//delete [] scr[CurScrNum];
		//scr[CurScrNum] = new TUPLE[iRowCount+1+PreTuplesNum];
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
				iQryIdx++;
			
				for(i = 1; i<=COL_NUM; i++)
				{
					//tpl[iQryIdx].x[i] = fCol[i-1];
					tmp_tpl[iQryIdx].x[i] = fCol[i-1];

				}				
				//tpl[iQryIdx].ID		= sColID;
				tmp_tpl[iQryIdx].ID		= sColID;

				//tuple[0][iQryIdx]		= tpl[iQryIdx];  //save the tpl[i]
				//scr[CurScrNum][iQryIdx] = tpl[iQryIdx]; 
				
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


		/// get tuples have been selected
		int k = iQryIdx;
        /*
		if(PreTuplesNum>0 && PreScrNum>0 )
		{

			double EPCINO = 0.000000000000001; //15_0

 			double scr_CLS_a[COL_NUM +1], scr_CLS_b[COL_NUM +1] ;  ;
			bool bInRect =true;
			int j;
			if(COL_NUM > 24)
			{
				for(j = 1; j<=COL_NUM; j++)
				{
					if(scr_CLS[CurScrNum].a[j] ==0.0)
					   scr_CLS[CurScrNum].a[j] = EPCINO;
					if(scr_CLS[CurScrNum].b[j] ==0.0)
					   scr_CLS[CurScrNum].b[j] = EPCINO;

					scr_CLS_a[j] = scr_CLS[CurScrNum].a[j] - fabs(EPCINO*scr_CLS[CurScrNum].a[j]); 
					scr_CLS_b[j] = scr_CLS[CurScrNum].b[j] + fabs(EPCINO*scr_CLS[CurScrNum].b[j]); 
				}
			}
			else
			{
				for(j = 1; j<=COL_NUM; j++)
				{
					scr_CLS_a[j] = scr_CLS[CurScrNum].a[j]; 
					scr_CLS_b[j] = scr_CLS[CurScrNum].b[j]; 
				}

			}
			for(i = 1; i<= PreTuplesNum; i++)
			{

				bInRect =true;
				for(j = 1; j<=COL_NUM; j++)
				{

					if(  scr[PreScrNum][i].x[j]< scr_CLS_a[j] || scr_CLS_b[j] < scr[PreScrNum][i].x[j]  )
					{	
						bInRect =false;
						break;   //for j
					}

				}
				if(bInRect)
				{
					k++;
					//tpl[k] = scr[PreScrNum][i];
					//tuple[0][k]		= scr[PreScrNum][i];  //save the tpl[i]
					//scr[CurScrNum][k] = scr[PreScrNum][i]; 
					//tmp_tpl[k] = scr[PreScrNum][i];
				}
			}
		}//if(PreTuplesNum>0 && PreScrNum>0 )
        */
		iRowCnt = k;

		//delete [] tpl;
		//tpl = new TUPLE[k+1];

		delete [] tuple[0];
		tuple[0] = new TUPLE[k+1];

		//delete [] scr[CurScrNum];
		//scr[CurScrNum] = new TUPLE[k+1];
		for(i=1; i <=k; i++)
		{
			//tpl[i]				= tmp_tpl[i];
			tuple[0][i]			= tmp_tpl[i]; 
			//scr[CurScrNum][i]	= tmp_tpl[i]; 
		}

		delete [] tmp_tpl;
//================
	}

	//zlCloseDB();
	//----- body-----------------

	return iRowCnt;

}

int CLearnIing6App::zlGetCandidateSet(QUERY Query, double r)
{
    int n = COL_NUM;

    QUERY Q = Query;
    ZLRECT S; //the search n-square of Q  

	int j, k, jj, i; 
	int l = 0 ;
	double p, q;
	int iMinTupleNum = 0, ituples_cnt = 0; 
	int iInterIdx = 0;
	bool bInterable = false;
    int iBSRIdx = 0;  //BSR is Best Super Region
    bool bBSRable = false;
    bool bS_in_scr_CLS = false;

    //int issNum = 10000;
    //int issNumOld = issNum;  //--2007.11.28 , member variable
	issNum = 10000;    //the initial value
	int SEC = 8; // SECTION 

	int Idx[WORKLOAD_NUM+1];
    int SuperSetIdx[WORKLOAD_NUM+1];

	for(j=1; j<=WORKLOAD_NUM; j++)
	{
		Idx[j]=0;
		SuperSetIdx[j]=0;
	}


	CLearnIing6App * pApp = (CLearnIing6App * ) AfxGetApp();
	char temp[1024] = "";
    double VFactor;
	if(n==104)
	  VFactor = 5.0 * pow(10, 37);
	else if(n==50)
	  VFactor = pow(10, 34); // (30 +38)/2=34
	else if(n==25)
	  VFactor = pow(10, 31); // (24 +38)/2=31

	//Form the search square S
	//S.a[j], j is based 1, but  Q.x[j] is based 0
	//for(j= 1; j <=n; j++)
	//{
		//S.a[j] = Q.x[j-1] - r ; 
		//S.b[j] = Q.x[j-1] + r; 
	//}

//-------------------------
	for(j= 1; j <=n; j++)
	{
		S.a[j] = Q.x[j-1] - r ; 
		if(S.a[j] < dMin[j])
			S.a[j] = dMin[j];

		S.b[j] = Q.x[j-1] + r; 
		if(S.b[j] >dMax[j])
			S.b[j] = dMax[j];
	}
//-----------------

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
   
    //From ¦®, find out all regions that intersect with S(Q, r),  
	//denote as {SCR k  | SCR k  S(Q, r)   , k = 1,¡­, K }
	//-------------------------------------------
				
	//1. Finding {scr_CLS[k]} that is super sets if S or intersection with S
	int iInsctNum = 0 ;

	for(j = 1; j<=clsNum; j++)   // when i=5, j = 1,2,3,4 if iStart =1
	{
		if(scr_CLS[j].tplNum > 0 )
		{
            //-- 1.1 find out all regions SCR such that contain S(Q, r)
			for(k=1; k<=n; k++)
			{
				if( (S.a[k]<scr_CLS[j].a[k]) || (scr_CLS[j].b[k]<S.b[k] ))
				{    //No, not contain
					bBSRable = false;
					break;
				}
				else  //Yes, contain
				{
					bBSRable = true;
				}
			} //for(k=1; k<=n; k++)

            if(bBSRable) //if there is best super region 
			{
					iBSRIdx = j;
					iMinTupleNum = scr_CLS[j].tplNum;
					SuperSetIdx[j] = j;
					bBSRable = false;
					bS_in_scr_CLS = true;
			}

            //-- 1.2 if there is no region SCR is the super set of S(Q, r)
			//  then Finding {scr_CLS[k]} that intersection with S
			if(!bS_in_scr_CLS)
			{
				//--
				for(k=1; k<=n; k++) //n is the number of dimensions 
				{
					p = __max(S.a[k], scr_CLS[j].a[k]); // here we use "intersect"
					q = __min(S.b[k], scr_CLS[j].b[k]);

					if(p<q) //the intersection is not empty
					{	
						bInterable = true; //must intersect for all dimensions
					} 
					else //the intersection is empty or p=q
					{
						bInterable = false; // it is enough there is a dimensions
						break;   //break k, because there is i0 such that p[i0] >=q[i0]  
					}

				}//for(k=1; k<=n; k++)

				if(bInterable) //if intersectable
				{
					//iMinTupleNum = __min(iMinTupleNum, S[j].tplNum);
					iInterIdx = j;
					iMinTupleNum = scr_CLS[j].tplNum;
					Idx[j] = j;
					bInterable = false;
					iInsctNum++;
				}
				//--
			}

		}
	}


	if( bS_in_scr_CLS) 
	{//-- Find out the SBR, best super region
		 for(j = 1; j<=clsNum; j++)    
		 {
			 if(SuperSetIdx[j] >0)
			 {
				 if(scr_CLS[ SuperSetIdx[j] ].tplNum < iMinTupleNum)
				 {
					iMinTupleNum =  scr_CLS[ SuperSetIdx[j] ].tplNum;
					iBSRIdx = SuperSetIdx[j];					
				 }
			 }				
		 }
	}
	else//--Finging the scr_CLS[k] with smallestscr_CLS[k].tplNum, its index is iInterIdx
	{	 
		 for(j = 1; j<=clsNum; j++)    
		 {
			 if(Idx[j] >0)
			 {
				 if(scr_CLS[ Idx[j] ].tplNum < iMinTupleNum)
				 {
					iMinTupleNum =  scr_CLS[ Idx[j] ].tplNum;
					iInterIdx = Idx[j];					
				 }
			 }				
		 }
	}
// Whether or not S is the subset of "the smallest SCR": scr_CLS[iInterIdx] 

//-- get tuples ---
	if(bS_in_scr_CLS) //S is the subset of "the smallest SCR": scr_CLS[iInterIdx]
	{
        S.bsn =  iBSRIdx; //
		scr_CLS[0] = S;
		ituples_cnt= zlGet_S_ScrTuple_LRC(scr_CLS, 0); //---pApp->tpl[i] is based 1
	    memset(&scr_CLS[0],0, sizeof(ZLRECT));
	}
	else      // S is not in scr_CLS
	{
		char * szSql = new char[8092000];
	    strcpy(szSql, "");
		//2. Calculas the S - scr_CLS[iInterIdx]. if there is a S[k] that intersection with our S[i]	
		 // int issNum =0;
		 
		 if(iInterIdx >0) //S intersection with scr_CLS,
		 {
			 S.bsn = iInterIdx; // -- play a role of S^scr_CLS[iInterIdx]
			 issNum = zlDiffRects(S, scr_CLS[iInterIdx], n);			
		 }//if(iInterIdx >0)

	
		 //3. if the number of S-S[k] < SEC, select * from S-scr_CLS[iInterIdx]
		 //   issNum > 0 and small enough, ie. issNum< SEC,  select the S[i]-S[k]
		 //  iInterIdx ==0 means S is not intersection with scr_CLS		 
		 //if( (0 < issNum)  && (issNum <= SEC) )
		 
		 ///===============================
		 //bool bFirst = true; //the first pApp->ss[l], which has no super set
         int iCnt_ss_bsn = 0;
		 if( (0 < issNum)  && (issNum <= SEC) && (issNum <=iInsctNum) )
		 {		

			for(l = 1; l<=issNum; l++)
			{
			   //---initial 0 for each l
               	iBSRIdx = 0;
				iMinTupleNum = 0;
				for(j=1; j<=WORKLOAD_NUM; j++)
				{
					SuperSetIdx[j]=0;
				}
				bBSRable = false;
				bS_in_scr_CLS = false;	

				//--
				 for(j = 1; j<=clsNum; j++)    
				 {
					 ss[l].bsn = -1;
					 if(Idx[j] >0)
					 {
							//-- 1.1 find out all regions SCR such that contain S(Q, r)
							for(k=1; k<=n; k++)
							{
								if( (ss[l].a[k]<scr_CLS[j].a[k]) || (scr_CLS[j].b[k]<ss[l].b[k] ))
								{    //No, not contain
									bBSRable = false;
									break;
								}
								else  //Yes, contain
								{
									bBSRable = true;
								}
							} //for(k=1; k<=n; k++)
							if(bBSRable) //if there is best super region 
							{
									iBSRIdx = j;
									iMinTupleNum = scr_CLS[j].tplNum;
									SuperSetIdx[j] = j;
									bBSRable = false;
									bS_in_scr_CLS = true;
							}
							if( bS_in_scr_CLS) 
							{//-- Find out the SBR, best super region
								 for(j = 1; j<=clsNum; j++)    
								 {
									 if(SuperSetIdx[j] >0)
									 {
										 if(scr_CLS[ SuperSetIdx[j] ].tplNum < iMinTupleNum)
										 {
											iMinTupleNum =  scr_CLS[ SuperSetIdx[j] ].tplNum;
											iBSRIdx = SuperSetIdx[j];					
										 }
									 }				
								 }

				                 ss[l].bsn = iBSRIdx;
								 iCnt_ss_bsn ++;
								
							}


					 }	//if(Idx[j] >0)			
				 }

				//--//--//--
			}
		 }

		 if( (issNum - iCnt_ss_bsn) < 2  )
		 {
			tuple = new ( TUPLE *[issNum +1] );  
			for(i = 0; i<=issNum; i++)
					tuple[i] = new TUPLE[2];

			iIO_Num = iIO_Num + 100000;
		    int iNobsnIdx = -1; // the index, that has no bsn.

			scr_CLS[0] = S;  //save in tuple[0], S acts as ss[0]
			ituples_cnt += zlGet_S_ScrTuple_LRC2(scr_CLS, 0, 0); //---pApp->tpl[i] is based 1
			ss[0].tplNum = scr_CLS[0].tplNum;
			memset(&scr_CLS[0],0, sizeof(ZLRECT));							    		         

			for(l = 1; l<=issNum; l++)
			{
				if(ss[l].bsn >0 )
				{

					ss[l].v =1;
					if(n < 25)
					{
						for(jj=1; jj<=n; jj++)
						{
							ss[l].v *= (ss[l].b[jj] - ss[l].a[jj]);
						}
					}
					else
					{
						for(jj=1; jj<=n; jj++)
						{
							ss[l].v *= ( (ss[l].b[jj] - ss[l].a[jj])/VFactor );
						}
						
					}

					scr_CLS[0] = pApp->ss[l];
					ituples_cnt += zlGet_S_ScrTuple_LRC2(scr_CLS,0, l); //---pApp->tpl[i] is based 1
					ss[l].tplNum = scr_CLS[0].tplNum;
					memset(&scr_CLS[0],0, sizeof(ZLRECT));							    

				}
				else
				{
					iNobsnIdx = l;

				}

			}
         
			if(iNobsnIdx >0 )
			{
				l = iNobsnIdx;
				strcpy(	szSql, 	" SELECT * FROM ");
				strcat(	szSql, 	TableName );
				strcat(	szSql, 	" where " );
									//Write the SQL 
								// "<=" is replaced by "<" , that can remove repeat tuples //2007.11.18
				strcat(	szSql, 	"( ( ");							
						for(j=1; j<=COL_NUM-1; j++)
						{
							sprintf(temp, " %.15G <= attr%d AND attr%d <= %.15G ", ss[l].a[j], j-1, j-1, ss[l].b[j]);
							strcat(	szSql, temp	);
							strcat(	szSql, ") AND (" );
						}
						sprintf(temp, " %.15G <= attr%d AND attr%d <= %.15G ", ss[l].a[COL_NUM],COL_NUM-1,COL_NUM-1, ss[l].b[COL_NUM]);
						strcat(	szSql, temp	);
				strcat(	szSql, ") ) "	);

                 ss[l].tplNum = zlExeSelect2(0, szSql, iNobsnIdx);
				 ituples_cnt +=  ss[l].tplNum ;					
				 iIO_Num ++;

			}

		    delete [] tpl;
		    tpl = new TUPLE[ituples_cnt+1];
			int itplIdx = 0;
    
			char cID[581012];
			memset(cID,'\0',581012);

			for(l = 0; l<=issNum; l++)
			{
				if(ss[l].tplNum >0)
				{

					for(i=1; i<=ss[l].tplNum; i++)
					{
						if(cID[ tuple[l][i].ID ] ==0)
						{
                             cID[ tuple[l][i].ID ] = 1; //remove repeat tuples
						     itplIdx ++; //tpl's index is based 1
                             tpl[itplIdx] = tuple[l][i];
						}
					}
				}
	
			}

			ituples_cnt = itplIdx;
			for(i = 0; i<=issNum; i++)
				delete []tuple[i];
			delete [] tuple; 

		}		 
		///===============================
		else  
		{
						////////////////////////////////////////////////////////////////
						strcpy(	szSql, 	" SELECT * FROM ");
						strcat(	szSql, 	TableName );
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
						ituples_cnt =  zlExeSelect(0, szSql);
						iIO_Num ++;					
		}

	    delete [] szSql;

	}
    //-------------------------------------------
    return ituples_cnt;
}


//zlExeSelect_LRC //2007.11.10
int CLearnIing6App::zlExeSelect_LRC(int PreTuplesNum, int PreScrNum, char *szSql, ZLRECT * scr_CLS, int CurScrNum)
{
	//if(!zlOpenDB())
	//{
		//AfxMessageBox("zlOpenDB() err!");
		//zlCloseDB();
	//}

	int iRowCnt = -1;
    int iTupleNum;

	double  fCol[COL_NUM+1];		//Elevation
	SDWORD cbCol[COL_NUM+1]; 	
	SDWORD sColID =0; 
	SDWORD cbColID =0; 
	int iQryIdx = 0;
	char tmp[512];
	int i;


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
	
		int iRowCount;
		SDWORD *  RowCountPtr = new SDWORD ;
		retcode = SQLRowCount(hstmt, RowCountPtr);						 
		iRowCount = * RowCountPtr;
		delete RowCountPtr;
		iRowCnt = iRowCount;
		iTupleNum = iRowCount;


		//if(iRowCnt <=0)
			//return iRowCnt;

		TUPLE * tmp_tpl = new TUPLE[iRowCount+1 +PreTuplesNum];
		
		//delete [] tpl;
		//tpl = new TUPLE[iRowCount+1 +PreTuplesNum];

		////t_Num[0] = new int[iRowCount+1+PreTuplesNum];
		//delete [] tuple[0];
		//tuple[0] = new TUPLE[iRowCount+1+PreTuplesNum];

		//delete [] scr[CurScrNum];
		//scr[CurScrNum] = new TUPLE[iRowCount+1+PreTuplesNum];
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
				iQryIdx++;
			
				for(i = 1; i<=COL_NUM; i++)
				{
					//tpl[iQryIdx].x[i] = fCol[i-1];
					tmp_tpl[iQryIdx].x[i] = fCol[i-1];

				}				
				//tpl[iQryIdx].ID		= sColID;
				tmp_tpl[iQryIdx].ID		= sColID;

				//tuple[0][iQryIdx]		= tpl[iQryIdx];  //save the tpl[i]
				//scr[CurScrNum][iQryIdx] = tpl[iQryIdx]; 
				
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


		/// get tuples have been selected
		int k = iQryIdx;

		if(PreTuplesNum>0 && PreScrNum>0 )
		{

			double EPCINO = 0.000000000000001; //15_0

 			double scr_CLS_a[COL_NUM +1], scr_CLS_b[COL_NUM +1] ;  ;
			bool bInRect =true;
			int j;
			if(COL_NUM > 24)
			{
				for(j = 1; j<=COL_NUM; j++)
				{
					if(scr_CLS[CurScrNum].a[j] ==0.0)
					   scr_CLS[CurScrNum].a[j] = EPCINO;
					if(scr_CLS[CurScrNum].b[j] ==0.0)
					   scr_CLS[CurScrNum].b[j] = EPCINO;

					scr_CLS_a[j] = scr_CLS[CurScrNum].a[j] - fabs(EPCINO*scr_CLS[CurScrNum].a[j]); 
					scr_CLS_b[j] = scr_CLS[CurScrNum].b[j] + fabs(EPCINO*scr_CLS[CurScrNum].b[j]); 
				}
			}
			else
			{
				for(j = 1; j<=COL_NUM; j++)
				{
					scr_CLS_a[j] = scr_CLS[CurScrNum].a[j]; 
					scr_CLS_b[j] = scr_CLS[CurScrNum].b[j]; 
				}

			}
			for(i = 1; i<= PreTuplesNum; i++)
			{

				bInRect =true;
				for(j = 1; j<=COL_NUM; j++)
				{

					if(  scr[PreScrNum][i].x[j]< scr_CLS_a[j] || scr_CLS_b[j] < scr[PreScrNum][i].x[j]  )
					{	
						bInRect =false;
						break;   //for j
					}

				}
				if(bInRect)
				{
					k++;
					//tpl[k] = scr[PreScrNum][i];
					//tuple[0][k]		= scr[PreScrNum][i];  //save the tpl[i]
					//scr[CurScrNum][k] = scr[PreScrNum][i]; 
					tmp_tpl[k] = scr[PreScrNum][i];
				}
			}
		}//if(PreTuplesNum>0 && PreScrNum>0 )

		iRowCnt = k;

		//delete [] tpl;
		//tpl = new TUPLE[k+1];

		//delete [] tuple[0];
		//tuple[0] = new TUPLE[k+1];

		delete [] scr[CurScrNum];
		scr[CurScrNum] = new TUPLE[k+1];
	
		for(i=1; i <=k; i++)
		{						
			//tpl[i]				= tmp_tpl[i];
			//tuple[0][i]			= tmp_tpl[i]; 
			scr[CurScrNum][i]	= tmp_tpl[i]; 
		}
        
		delete [] tmp_tpl;
//================
	}

	//zlCloseDB();
	//----- body-----------------

	return iRowCnt;

}

int CLearnIing6App::zlExeSelect_Mul_LRC(int PreTuplesNum, int PreScrNum, char *szSql, ZLRECT * scr_CLS, int CurScrNum)
{
	//if(!zlOpenDB())
	{
	//	AfxMessageBox("zlOpenDB() err!");
		//zlCloseDB();
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
	
		int iRowCount;
		SDWORD *  RowCountPtr = new SDWORD ;
		retcode = SQLRowCount(hstmt, RowCountPtr);						 
		iRowCount = * RowCountPtr;
		delete RowCountPtr;
		iRowCnt = iRowCount;
		iTupleNum = iRowCount;


		//if(iRowCnt <=0)
			//return iRowCnt;

		TUPLE * tmp_tpl = new TUPLE[iRowCount+1 +PreTuplesNum];
		
		//delete [] tpl;
		//tpl = new TUPLE[iRowCount+1 +PreTuplesNum];

		////t_Num[0] = new int[iRowCount+1+PreTuplesNum];
		//delete [] tuple[0];
		//tuple[0] = new TUPLE[iRowCount+1+PreTuplesNum];

		//delete [] scr[CurScrNum];
		//scr[CurScrNum] = new TUPLE[iRowCount+1+PreTuplesNum];
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
				iQryIdx++;
			
				for(i = 1; i<=COL_NUM; i++)
				{
					//tpl[iQryIdx].x[i] = fCol[i-1];
					tmp_tpl[iQryIdx].x[i] = fCol[i-1];

				}				
				//tpl[iQryIdx].ID		= sColID;
				tmp_tpl[iQryIdx].ID		= sColID;

				//tuple[0][iQryIdx]		= tpl[iQryIdx];  //save the tpl[i]
				//scr[CurScrNum][iQryIdx] = tpl[iQryIdx]; 
				
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


		/// get tuples have been selected
		int k = iQryIdx;

		if(PreTuplesNum>0 && PreScrNum>0 )
		{

			double EPCINO = 0.000000000000001; //15_0

 			double scr_CLS_a[COL_NUM +1], scr_CLS_b[COL_NUM +1] ;  ;
			bool bInRect =true;
			int j;
			if(COL_NUM > 24)
			{
				for(j = 1; j<=COL_NUM; j++)
				{
					if(scr_CLS[CurScrNum].a[j] ==0.0)
					   scr_CLS[CurScrNum].a[j] = EPCINO;
					if(scr_CLS[CurScrNum].b[j] ==0.0)
					   scr_CLS[CurScrNum].b[j] = EPCINO;

					scr_CLS_a[j] = scr_CLS[CurScrNum].a[j] - fabs(EPCINO*scr_CLS[CurScrNum].a[j]); 
					scr_CLS_b[j] = scr_CLS[CurScrNum].b[j] + fabs(EPCINO*scr_CLS[CurScrNum].b[j]); 
				}
			}
			else
			{
				for(j = 1; j<=COL_NUM; j++)
				{
					scr_CLS_a[j] = scr_CLS[CurScrNum].a[j]; 
					scr_CLS_b[j] = scr_CLS[CurScrNum].b[j]; 
				}

			}
			for(i = 1; i<= PreTuplesNum; i++)
			{

				bInRect =true;
				for(j = 1; j<=COL_NUM; j++)
				{

					if(  scr[PreScrNum][i].x[j]< scr_CLS_a[j] || scr_CLS_b[j] < scr[PreScrNum][i].x[j]  )
					{	
						bInRect =false;
						break;   //for j
					}

				}
				if(bInRect) 
				{
					k++;
					//tpl[k] = scr[PreScrNum][i];
					//tuple[0][k]		= scr[PreScrNum][i];  //save the tpl[i]
					//scr[CurScrNum][k] = scr[PreScrNum][i]; 
					tmp_tpl[k] = scr[PreScrNum][i];
						
				}
			}
		}//if(PreTuplesNum>0 && PreScrNum>0 )

		iRowCnt = k;

		delete [] tpl;
		tpl = new TUPLE[k+1];

		//delete [] tuple[0];
		//tuple[0] = new TUPLE[k+1];

		//delete [] scr[CurScrNum];
		//scr[CurScrNum] = new TUPLE[k+1];
		for(i=1; i <=k; i++)
		{
			tpl[i]				= tmp_tpl[i];
			//tuple[0][i]			= tmp_tpl[i]; 
			//scr[CurScrNum][i]	= tmp_tpl[i]; 
		}
		delete [] tmp_tpl;
//================
	}

	//zlCloseDB();
	//----- body-----------------

	return iRowCnt;

}


int CLearnIing6App::zlExeSelect_Mul(int PreTuplesNum, int PreScrNum, char *szSql, ZLRECT * scr_CLS, int CurScrNum)
{
	//if(!zlOpenDB())
	{
		//AfxMessageBox("zlOpenDB() err!");
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


			/////////----
			/*		CString cstrMarc1;
					cstrMarc1 = szSql;
					CFile file;
					//if(file.Open("E:\\Paper2\\Lsi_050D\\AppSelect.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
					if(file.Open("E:\\Paper2\\Lsi_104D\\AppSelect.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
					//if(file.Open("E:\\Paper2\\Lsi_025D\\AppSelect.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
					//if(file.Open("E:\\Paper2\\COVER4D\\AppSelect.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
					//if(file.Open("E:\\Paper2\\Gauss3D\\AppSelect.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
					//if(file.Open("E:\\Paper2\\Array3D\\AppSelect.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
					//if(file.Open("E:\\Paper2\\Census3D\\AppSelect.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
					//if(file.Open("E:\\Paper2\\Census2D\\AppSelect.txt",CFile::modeCreate | CFile::modeReadWrite ) != 0)
					{
						file.Write(cstrMarc1, cstrMarc1.GetLength() +1 );
					}
					file.Close(); 
					*/
		/////////----

	/////////////////////////////////////////////////////
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
		iTupleNum = iRowCount;


		//if(iRowCnt <=0)
			//return iRowCnt;

		TUPLE * tmp_tpl = new TUPLE[iRowCount+1 +PreTuplesNum];
		
		//delete [] tpl;
		//tpl = new TUPLE[iRowCount+1 +PreTuplesNum];

		////t_Num[0] = new int[iRowCount+1+PreTuplesNum];
		//delete [] tuple[0];
		//tuple[0] = new TUPLE[iRowCount+1+PreTuplesNum];

		//delete [] scr[CurScrNum];
		//scr[CurScrNum] = new TUPLE[iRowCount+1+PreTuplesNum];
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
				iQryIdx++;
			
				for(i = 1; i<=COL_NUM; i++)
				{
					//tpl[iQryIdx].x[i] = fCol[i-1];
					tmp_tpl[iQryIdx].x[i] = fCol[i-1];

				}				
				//tpl[iQryIdx].ID		= sColID;
				tmp_tpl[iQryIdx].ID		= sColID;

				//tuple[0][iQryIdx]		= tpl[iQryIdx];  //save the tpl[i]
				//scr[CurScrNum][iQryIdx] = tpl[iQryIdx]; 
				
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


		/// get tuples have been selected
		int k = iQryIdx;

		if(PreTuplesNum>0 && PreScrNum>0 )
		{

			double EPCINO = 0.000000000000001; //15_0

 			double scr_CLS_a[COL_NUM +1], scr_CLS_b[COL_NUM +1] ;  ;
			bool bInRect =true;
			int j;
			if(COL_NUM > 24)
			{
				for(j = 1; j<=COL_NUM; j++)
				{
					if(scr_CLS[CurScrNum].a[j] ==0.0)
					   scr_CLS[CurScrNum].a[j] = EPCINO;
					if(scr_CLS[CurScrNum].b[j] ==0.0)
					   scr_CLS[CurScrNum].b[j] = EPCINO;

					scr_CLS_a[j] = scr_CLS[CurScrNum].a[j] - fabs(EPCINO*scr_CLS[CurScrNum].a[j]); 
					scr_CLS_b[j] = scr_CLS[CurScrNum].b[j] + fabs(EPCINO*scr_CLS[CurScrNum].b[j]); 
				}
			}
			else
			{
				for(j = 1; j<=COL_NUM; j++)
				{
					scr_CLS_a[j] = scr_CLS[CurScrNum].a[j]; 
					scr_CLS_b[j] = scr_CLS[CurScrNum].b[j]; 
				}

			}
			for(i = 1; i<= PreTuplesNum; i++)
			{

				bInRect =true;
				for(j = 1; j<=COL_NUM; j++)
				{

					if(  scr[PreScrNum][i].x[j]< scr_CLS_a[j] || scr_CLS_b[j] < scr[PreScrNum][i].x[j]  )
					{	
						bInRect =false;
						break;   //for j
					}

				}
				if(bInRect)
				{
					k++;
					//tpl[k] = scr[PreScrNum][i];
					//tuple[0][k]		= scr[PreScrNum][i];  //save the tpl[i]
					//scr[CurScrNum][k] = scr[PreScrNum][i]; 
					tmp_tpl[k] = scr[PreScrNum][i];
				}
			}
		}//if(PreTuplesNum>0 && PreScrNum>0 )

		iRowCnt = k;

		delete [] tpl;
		tpl = new TUPLE[k+1];

		delete [] tuple[0];
		tuple[0] = new TUPLE[k+1];

		delete [] scr[CurScrNum];
		scr[CurScrNum] = new TUPLE[k+1];
		for(i=1; i <=k; i++)
		{
			tpl[i]				= tmp_tpl[i];
			tuple[0][i]			= tmp_tpl[i]; 
			scr[CurScrNum][i]	= tmp_tpl[i]; 
		}

		delete [] tmp_tpl;
//================
	}

	//zlCloseDB();
	//----- body-----------------

	return iRowCnt;

}

int CLearnIing6App::zlGet_S_ScrTuple_LRC(ZLRECT * scr_CLS, int CurScrNum)
{
    int bsn;
	int tuplesNum;
    int i;
	//if S[CurScrNum].tplNum <=0 call this function

	 if( scr_CLS[CurScrNum].bsn == 0 ) //1000 scr_CLS[i] is not a subset of another .		
		bsn = 0;
     else //if( scr_CLS[CurScrNum].bsn > 0  ) //1000, bsn ==k, scr_CLS[i] is a subset of another (scr_CLS[k]).		
	 {
		bsn = scr_CLS[CurScrNum].bsn; 

		// up to new we get scr_CLS[bsn].tplNum;
		if(scr_CLS[CurScrNum].v == scr_CLS[bsn].v) //if two queries are identity 
		{
	
			delete [] tpl;		
			tpl = new TUPLE[ scr_CLS[bsn].tplNum +1]; ///itself

			for(i=1; i<=scr_CLS[bsn].tplNum; i++)
			{
				tpl[i] = scr[bsn][i];
			}
			scr_CLS[CurScrNum].tplNum = scr_CLS[bsn].tplNum;

			return scr_CLS[scr_CLS[CurScrNum].bsn].tplNum;			

		}
		else if(scr_CLS[bsn].tplNum >0)
			tuplesNum = scr_CLS[scr_CLS[CurScrNum].bsn].tplNum;

	 }


	TUPLE * tmp_tpl = new TUPLE[tuplesNum +1]; //the tuples in S[QueryNum]
	int k =0;

	double EPCINO = 0.000000000000001; //15_0

 	double scr_CLS_a[COL_NUM +1], scr_CLS_b[COL_NUM +1] ;  ;
	bool bInRect =true;
	int j;
	
	if(COL_NUM>24)
	{
		for(j = 1; j<=COL_NUM; j++)
		{
			if(scr_CLS[CurScrNum].a[j] ==0.0)
			   scr_CLS[CurScrNum].a[j] = EPCINO;
			if(scr_CLS[CurScrNum].b[j] ==0.0)
			   scr_CLS[CurScrNum].b[j] = EPCINO;

			scr_CLS_a[j] = scr_CLS[CurScrNum].a[j] - fabs(EPCINO*scr_CLS[CurScrNum].a[j]); 
			scr_CLS_b[j] = scr_CLS[CurScrNum].b[j] + fabs(EPCINO*scr_CLS[CurScrNum].b[j]); 
		}
	}
	else
	{
		for(j = 1; j<=COL_NUM; j++)
		{
			scr_CLS_a[j] = scr_CLS[CurScrNum].a[j]; 
			scr_CLS_b[j] = scr_CLS[CurScrNum].b[j];
		}
	}
//int asdf;
	for(i = 1; i<= scr_CLS[bsn].tplNum; i++)
	{
		bInRect =true;
		for(j = 1; j<=COL_NUM; j++)
		{

			if(  scr[bsn][i].x[j]< scr_CLS_a[j] || scr_CLS_b[j] < scr[bsn][i].x[j]  )
			{	
				bInRect =false;
				break;   //for j
			}

		}
		if(bInRect)
		{
			k++;
			tmp_tpl[k] = scr[bsn][i];
		}
	}

	delete [] tpl;
	tpl = new TUPLE[ k +1];  

	//delete [] tuple[0];    
	//tuple[0] = new TUPLE[ k+1];

	//delete [] scr[CurScrNum];
	//scr[CurScrNum] = new TUPLE[ k +1];

	for(i=1; i<=k; i++)
	{
		tpl[i] = tmp_tpl[i];
		//tuple[0][i] = tmp_tpl[i];
		//scr[CurScrNum][i] = tmp_tpl[i];

	}
	scr_CLS[CurScrNum].tplNum = k;

	delete [] tmp_tpl;	
	/////////////////////////////////////////
    return scr_CLS[CurScrNum].tplNum; 
}

int CLearnIing6App::zlGet_S_ScrTuple_LRC2(ZLRECT * scr_CLS, int CurScrNum, int l)
{
    int bsn;
	int tuplesNum;
    int i;
	//if S[CurScrNum].tplNum <=0 call this function

	 if( scr_CLS[CurScrNum].bsn == 0 ) //1000 scr_CLS[i] is not a subset of another .		
		bsn = 0;
     else //if( scr_CLS[CurScrNum].bsn > 0  ) //1000, bsn ==k, scr_CLS[i] is a subset of another (scr_CLS[k]).		
	 {
		bsn = scr_CLS[CurScrNum].bsn; 

		// up to new we get scr_CLS[bsn].tplNum;
		if(scr_CLS[CurScrNum].v == scr_CLS[bsn].v) //if two queries are identity 
		{
	
			//delete [] tpl;		
			//tpl = new TUPLE[ scr_CLS[bsn].tplNum +1]; ///itself
			delete [] tuple[l];    
			tuple[l] = new TUPLE[ scr_CLS[bsn].tplNum +1];

			for(i=1; i<=scr_CLS[bsn].tplNum; i++)
			{
				tuple[l][i] = scr[bsn][i];
			}
			scr_CLS[CurScrNum].tplNum = scr_CLS[bsn].tplNum;

			return scr_CLS[scr_CLS[CurScrNum].bsn].tplNum;			

		}
		else if(scr_CLS[bsn].tplNum >0)
			tuplesNum = scr_CLS[scr_CLS[CurScrNum].bsn].tplNum;

	 }


	TUPLE * tmp_tpl = new TUPLE[tuplesNum +1]; //the tuples in S[QueryNum]
	int k =0;

	double EPCINO = 0.000000000000001; //15_0

 	double scr_CLS_a[COL_NUM +1], scr_CLS_b[COL_NUM +1] ;  ;
	bool bInRect =true;
	int j;
	
	if(COL_NUM>24)
	{
		for(j = 1; j<=COL_NUM; j++)
		{
			if(scr_CLS[CurScrNum].a[j] ==0.0)
			   scr_CLS[CurScrNum].a[j] = EPCINO;
			if(scr_CLS[CurScrNum].b[j] ==0.0)
			   scr_CLS[CurScrNum].b[j] = EPCINO;

			scr_CLS_a[j] = scr_CLS[CurScrNum].a[j] - fabs(EPCINO*scr_CLS[CurScrNum].a[j]); 
			scr_CLS_b[j] = scr_CLS[CurScrNum].b[j] + fabs(EPCINO*scr_CLS[CurScrNum].b[j]); 
		}
	}
	else
	{
		for(j = 1; j<=COL_NUM; j++)
		{
			scr_CLS_a[j] = scr_CLS[CurScrNum].a[j]; 
			scr_CLS_b[j] = scr_CLS[CurScrNum].b[j];
		}
	}
//int asdf;
	for(i = 1; i<= scr_CLS[bsn].tplNum; i++)
	{
		bInRect =true;
		for(j = 1; j<=COL_NUM; j++)
		{
            //left is open, and right is closed
			if(  scr[bsn][i].x[j] < scr_CLS_a[j] || scr_CLS_b[j] < scr[bsn][i].x[j]  )
			{	
				bInRect =false;
				break;   //for j
			}

		}
		if(bInRect)
		{
			k++;
			tmp_tpl[k] = scr[bsn][i];
		}
	}

	delete [] tuple[l];    
	tuple[l] = new TUPLE[ scr_CLS[bsn].tplNum +1];

	//delete [] tpl;
	//tpl = new TUPLE[ k +1];  

	//delete [] tuple[0];    
	//tuple[0] = new TUPLE[ k+1];

	//delete [] scr[CurScrNum];
	//scr[CurScrNum] = new TUPLE[ k +1];

	for(i=1; i<=k; i++)
	{
		//tpl[i] = tmp_tpl[i];
		tuple[l][i] = tmp_tpl[i];
		//scr[CurScrNum][i] = tmp_tpl[i];

	}
	scr_CLS[CurScrNum].tplNum = k;

	delete [] tmp_tpl;	
	/////////////////////////////////////////
    return scr_CLS[CurScrNum].tplNum; 
}


int CLearnIing6App::zlGetScrTuple(ZLRECT * scr_CLS, int CurScrNum)
{
    int bsn;
	int tuplesNum;
    int i;
	//if S[CurScrNum].tplNum <=0 call this function

	 if( scr_CLS[CurScrNum].bsn == 0 ) //1000 scr_CLS[i] is not a subset of another .		
		bsn = 0;
     else //if( scr_CLS[CurScrNum].bsn > 0  ) //1000, bsn ==k, scr_CLS[i] is a subset of another (scr_CLS[k]).		
	 {
		bsn = scr_CLS[CurScrNum].bsn; 
		//if( scr_CLS[scr_CLS[CurScrNum].bsn].tplNum <=0)
		if( scr_CLS[bsn].tplNum <=0)
		{
			//zlGetTopNTuple(scr_CLS[CurScrNum].bsn ); //IMportant
			tuplesNum = zlGetScrTuple(scr_CLS, bsn);

		}

		// up to new we get scr_CLS[bsn].tplNum;
		if(scr_CLS[CurScrNum].v == scr_CLS[bsn].v) //if two queries are identity 
		{
			//tuple[CurScrNum] = new TUPLE[ scr_CLS[scr_CLS[CurScrNum].bsn].tplNum +1];
			
			//tpl = new TUPLE[ scr_CLS[bsn].tplNum +1]; itself

			//delete [] tuple[0];   itself
			//tuple[0] = new TUPLE[ scr_CLS[bsn].tplNum +1];
			
			delete [] scr[CurScrNum];
			scr[CurScrNum] = new TUPLE[ scr_CLS[bsn].tplNum +1];

			for(i=1; i<=scr_CLS[bsn].tplNum; i++)
			{
			    //tuple[0][i] = scr[bsn][i];
				scr[CurScrNum][i] = scr[bsn][i];
			}
			scr_CLS[CurScrNum].tplNum = scr_CLS[bsn].tplNum;

			return scr_CLS[scr_CLS[CurScrNum].bsn].tplNum;			

		}
		else if(scr_CLS[bsn].tplNum >0)
			tuplesNum = scr_CLS[scr_CLS[CurScrNum].bsn].tplNum;

	 }


	TUPLE * tmp_tpl = new TUPLE[tuplesNum +1]; //the tuples in S[QueryNum]
	int k =0;

	double EPCINO = 0.000000000000001; //15_0

 	double scr_CLS_a[COL_NUM +1], scr_CLS_b[COL_NUM +1] ;  ;
	bool bInRect =true;
	int j;
	
	if(COL_NUM>24)
	{
		for(j = 1; j<=COL_NUM; j++)
		{
			if(scr_CLS[CurScrNum].a[j] ==0.0)
			   scr_CLS[CurScrNum].a[j] = EPCINO;
			if(scr_CLS[CurScrNum].b[j] ==0.0)
			   scr_CLS[CurScrNum].b[j] = EPCINO;

			scr_CLS_a[j] = scr_CLS[CurScrNum].a[j] - fabs(EPCINO*scr_CLS[CurScrNum].a[j]); 
			scr_CLS_b[j] = scr_CLS[CurScrNum].b[j] + fabs(EPCINO*scr_CLS[CurScrNum].b[j]); 
		}
	}
	else
	{
		for(j = 1; j<=COL_NUM; j++)
		{
			scr_CLS_a[j] = scr_CLS[CurScrNum].a[j]; 
			scr_CLS_b[j] = scr_CLS[CurScrNum].b[j];
		}
	}
//int asdf;
	for(i = 1; i<= scr_CLS[bsn].tplNum; i++)
	{
        //test
		//if(i>=18155)
		//{
		//	 asdf = 0;
		//}
		//test
		bInRect =true;
		for(j = 1; j<=COL_NUM; j++)
		{

			if(  scr[bsn][i].x[j]< scr_CLS_a[j] || scr_CLS_b[j] < scr[bsn][i].x[j]  )
			{	
				bInRect =false;
				break;   //for j
			}

		}
		if(bInRect)
		{
			k++;
			tmp_tpl[k] = scr[bsn][i];
			//tuple[0][k]		= scr[bsn][i];  //save the tpl[i]
			//scr[CurScrNum][k] = scr[bsn][i]; 
		}
	}

	delete [] tpl;
	tpl = new TUPLE[ k +1];  

	delete [] tuple[0];    
	tuple[0] = new TUPLE[ k+1];

	delete [] scr[CurScrNum];
	scr[CurScrNum] = new TUPLE[ k +1];

	for(i=1; i<=k; i++)
	{
		tpl[i] = tmp_tpl[i];
		tuple[0][i] = tmp_tpl[i];
		scr[CurScrNum][i] = tmp_tpl[i];

	}
	scr_CLS[CurScrNum].tplNum = k;

	delete [] tmp_tpl;	
	/////////////////////////////////////////
    return scr_CLS[CurScrNum].tplNum; 
}

int CLearnIing6App::zlExeSelect_Mul_S(int PreTuplesNum, int PreS_Num, char *szSql, ZLRECT *S, int CurS_Num)
{
	//if(!zlOpenDB())
	{
		//AfxMessageBox("zlOpenDB() err!");
		//zlCloseDB();
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

	/////////////////////////////////////////////////////
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
		iTupleNum = iRowCount;


		//if(iRowCnt <=0)
			//return iRowCnt;

		TUPLE * tmp_tpl = new TUPLE[iRowCount +PreTuplesNum +1]; 
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
				iQryIdx++;
			
				for(i = 1; i<=COL_NUM; i++)
				{
					tmp_tpl[iQryIdx].x[i] = fCol[i-1];
				}				
				tmp_tpl[iQryIdx].ID		= sColID;
				
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


		/// get tuples have been selected
		int k = iQryIdx;

		if(PreTuplesNum>0 && PreS_Num>0 )
		{

			double EPCINO = 0.000000000000001; //15_0

 			double S_a[COL_NUM +1], S_b[COL_NUM +1] ;  ;
			bool bInRect =true;
			int j;
			if(COL_NUM > 24)
			{
				for(j = 1; j<=COL_NUM; j++)
				{
					if(S[CurS_Num].a[j] ==0.0)
					   S[CurS_Num].a[j] = EPCINO;
					if(S[CurS_Num].b[j] ==0.0)
					   S[CurS_Num].b[j] = EPCINO;

					S_a[j] = S[CurS_Num].a[j] - fabs(EPCINO*S[CurS_Num].a[j]); 
					S_b[j] = S[CurS_Num].b[j] + fabs(EPCINO*S[CurS_Num].b[j]); 
				}			
			}
			else
			{
				for(j = 1; j<=COL_NUM; j++)
				{
					S_a[j] = S[CurS_Num].a[j];
					S_b[j] = S[CurS_Num].b[j];
				}			
			}
			for(i = 1; i<= PreTuplesNum; i++)
			{

				bInRect =true;
				for(j = 1; j<=COL_NUM; j++)
				{

					if(  tuple[PreS_Num][i].x[j]< S_a[j] || S_b[j] < tuple[PreS_Num][i].x[j]  )
					{	
						bInRect =false;
						break;   //for j
					}

				}
				if(bInRect)
				{
					k++;
					tmp_tpl[k] = tuple[PreS_Num][i];
				}
			}
		}//if(PreTuplesNum>0 && PreScrNum>0 )

		//iRowCnt = iTupleNum + k;
		iRowCnt = k;

		delete [] tpl;
		//tpl = new TUPLE[k+1 +iTupleNum];
		tpl = new TUPLE[k+1];

		delete [] tuple[CurS_Num]; //2007.03.08
		tuple[CurS_Num] = new TUPLE[k+1];

		//for(i=1; i<=iRowCnt; i++ )
		for(i=1; i<=k; i++ )
		{
			tpl[i] = tmp_tpl[i];
			tuple[CurS_Num][i]= tmp_tpl[i];  //save the tmp_tpl[i]
		}
		S[CurS_Num].tplNum = k;

		delete [] tmp_tpl;
//================
	}

	//zlCloseDB();
	//----- body-----------------

	return iRowCnt;
	//return k;
}

int CLearnIing6App::zlGetTopNTuple_S(int QueryNum, ZLRECT *S, int tuplesNum)
{
	Qi++;                 //only for test 
	Qidx[Qi]=QueryNum;    //only for test

	int iCandidateNum =-1;

///////////////// Get TopN tuples Start //////////////

	//1. Obtain all distance From Query to tuples
    //#define  DIS_NUM  -1 //2 //1 == L1; 2 == L2; -1 =Linf

	int iRowCnt = tuplesNum;
	double x[COL_NUM +1];
	
	int iTopN =Q[QueryNum].N ;
	//double r[2000];
	//double dis[2000];
	double r[100+1];     //
	double dis[100+1];

	double ftmp =0 ;
	int tIndex[100+1]; //or 2000
	//int tID[100];
	int iNumTmp;
	int i,j,k, ii, jj, kk;
	long lStartTimer = GetTickCount();
	long lEndTimer;

	delete [] t;
	t = new TUPLE[iRowCnt +1];

	lStartTimer = GetTickCount();
	for(i = 1; i<=iRowCnt; i++)
	{
		t[i] = tpl[i];
		t[i].num = i;
	}

	lEndTimer = GetTickCount()-lStartTimer;
	CString str = "";
	char temp[512] ="";

	sprintf(temp, "1. QueryNum = %i; iCandidateNum = %i; Ticks = %i; ", QueryNum, iRowCnt, lEndTimer);
	str += temp;
	str += "\r\n";
   //if(tuplesNum>3000)
	//AfxMessageBox(temp);	

	iCandidateNum = tuplesNum;
	//In this function: iRowCnt >= iTopN;
	if(iCandidateNum < iTopN)
	{
		//str += "zlGetTopNTuple: iCandidateNum < iTopN ";
		//str += "\r\n";
		//sprintf(temp, "1. QueryNum = %i; iCandidateNum = %i; Ticks = %i; ", QueryNum, tuplesNum, lEndTimer);
		//str += temp;
		//str += "\r\n";

		//AfxMessageBox(temp);	
		return iCandidateNum; 
		//Q[QueryNum].r := __max( distance from Q[QueryNum] to 
		 // tpl[1],..., tpl[iTopN]) caller will do this work.
	}
	if(iCandidateNum <= 0)
	{
		str += "zlGetTopNTuple: iCandidateNum < iTopN ";
		str += "\r\n";
		sprintf(temp, "1. QueryNum = %i; iCandidateNum = %i; Ticks = %i; ", QueryNum, tuplesNum, lEndTimer);
		str += temp;
		str += "\r\n";

		AfxMessageBox(temp);	
		return iCandidateNum; 
		//Q[QueryNum].r := __max( distance from Q[QueryNum] to 
		 // tpl[1],..., tpl[iTopN]) caller will do this work.
	}

	//calculate the distance from Q[QueryNum] to t[j], save it in t[j].d
	for(k = 1; k<=iCandidateNum; k++)
	{
		for(j = 1; j<=COL_NUM; j++)
			x[j] = fabs( t[k].x[j] - Q[QueryNum].q[j] );

		switch (DIS_NUM)
		{
			case 1:
			{
				//---for Sum distance, L1
				t[k].d = x[1];
		 		for(j = 2; j<=COL_NUM; j++)
					t[k].d += x[j];
				break;
			}
			case 2:
			{
				//----for Eucl distance, L2
				t[k].d = x[1]*x[1];
		 		for(j = 2; j<=COL_NUM; j++)
					t[k].d += x[j]*x[j];
				t[k].d = sqrt( t[k].d );

				break;
			}
			case -1:
			{
				//----for Max distance, Linf
				t[k].d = x[1];
				for(j = 2; j<=COL_NUM; j++)
					t[k].d = (double)__max(t[k].d, x[j]);				
				break;
			}//switch (DIS_NUM)
		} 

	}//for(k = 1; k<=iRowCnt; k++)

		//iTopN = Q[i].N;

	//sorting the distance of the FIRST iTopN tuples
	// saved in r[j];

	for(j=1; j<=iTopN; j++)
	{
		dis[j]=t[j].d;
	}

	for(j=1; j<=iTopN; j++)
	{
		r[j] = dis[j];

		   for( k= j+1; k<=iTopN; k++)
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
		for(j=1; j<=iTopN; j++)
		{
			dis[j] = t[t[j].num].d;  //t[tIndex[j]].d;
			//tID[j] = t[tIndex[j]].ID;
		}

			int debug1 =1;
	*/
		//-----debug1----

////////////
	//2. select TopN tuples from all tuples with size iCandidateNum
			
	//lStartTimer = GetTickCount(); //2005.05.13
      
	for(ii = iTopN +1 ; ii<=iCandidateNum; ii++)
	{
		if(t[ii].d < r[iTopN])		
		{
			for(jj=1;jj<=iTopN;jj++)
			{
				if( t[ii].d < r[jj]) // t[ii] insert the jj seat
				{
					
					iNumTmp = t[iTopN].num;

					for(kk = iTopN ; kk>jj; kk--)
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
	for(j=1; j<=iTopN; j++)
	{
		dis[j] = t[t[j].num].d;  //t[tIndex[j]].d;
		//tID[j] = t[t[j].num].ID; //t[t[j].num].ID is the topN tuples ID;
	}

	debug1 =12;
*/
	//-----debug1----

///////////////// Get TopN tuples End //////////////
	
	
	//----- body-----------------
	return iCandidateNum;
}

int CLearnIing6App::zlGet_S_Tuple(ZLRECT *S, int CurS_Num)
{
    int bsn;
	int tuplesNum;
    int i;
	//if S[CurS_Num].tplNum <=0 call this function

	 if( S[CurS_Num].bsn >123456  ) //1000 S[k] is not a subset of another .		
		bsn = 0;
     else //if( S[CurS_Num].bsn < 1000 ) //S[k] is a subset of another .		
	 {
		bsn = S[CurS_Num].bsn; 
		//if( S[S[CurS_Num].bsn].tplNum <=0)
		if( S[bsn].tplNum <=0)
		{
			//zlGetTopNTuple(S[CurS_Num].bsn ); //IMportant
			tuplesNum = zlGet_S_Tuple(S, bsn);
		}

		// up to new we get S[bsn].tplNum;
		if(S[CurS_Num].v == S[bsn].v) //if two queries are identity 
		{
			//tuple[CurS_Num] = new TUPLE[ S[S[CurS_Num].bsn].tplNum +1];
			
			//tpl = new TUPLE[ S[bsn].tplNum +1]; itself

			//delete [] tuple[0];   itself
			//tuple[0] = new TUPLE[ S[bsn].tplNum +1];
			
			//---- add 2005.08.07 start ----
			delete [] tpl;
			tpl = new TUPLE[S[bsn].tplNum +1];  

			//---- add 2005.08.07 end ----

			delete [] tuple[CurS_Num]; //2007.03.08
			tuple[CurS_Num] = new TUPLE[ S[bsn].tplNum +1];

			for(i=1; i<=S[bsn].tplNum; i++)
			{
			    //tuple[0][i] = tuple[bsn][i];
				tuple[CurS_Num][i] = tuple[bsn][i];
				tpl[i] = tuple[bsn][i]; // add 2005.08.07
			}
			S[CurS_Num].tplNum = S[bsn].tplNum;



			return S[S[CurS_Num].bsn].tplNum;			
			//???$$$
		}
		else if(S[bsn].tplNum >0)
			tuplesNum = S[S[CurS_Num].bsn].tplNum;

	 }


	TUPLE * tmp_tpl = new TUPLE[tuplesNum +1]; //the tuples in S[QueryNum]
	int k =0;

	double EPCINO = 0.000000000000001; //15_0

 	double S_a[COL_NUM +1], S_b[COL_NUM +1] ;  ;
	bool bInRect =true;
	int j;
	if(COL_NUM > 24)
	{
		for(j = 1; j<=COL_NUM; j++)
		{
			if(S[CurS_Num].a[j] ==0.0)
			   S[CurS_Num].a[j] = EPCINO;
			if(S[CurS_Num].b[j] ==0.0)
			   S[CurS_Num].b[j] = EPCINO;

			S_a[j] = S[CurS_Num].a[j] - fabs(EPCINO*S[CurS_Num].a[j]); 
			S_b[j] = S[CurS_Num].b[j] + fabs(EPCINO*S[CurS_Num].b[j]); 
		}
	}
	else
	{
		for(j = 1; j<=COL_NUM; j++)
		{
			S_a[j] = S[CurS_Num].a[j]; 
			S_b[j] = S[CurS_Num].b[j]; 
		}
	}
	for(i = 1; i<= S[bsn].tplNum; i++)
	{

		bInRect =true;
		for(j = 1; j<=COL_NUM; j++)
		{

			if(  tuple[bsn][i].x[j]< S_a[j] || S_b[j] < tuple[bsn][i].x[j]  )
			{	
				bInRect =false;
				break;   //for j
			}

		}
		if(bInRect)
		{
			k++;
			tmp_tpl[k] = tuple[bsn][i];
			//tuple[0][k]		= tuple[bsn][i];  //save the tpl[i]
			//tuple[CurS_Num][k] = tuple[bsn][i]; 
		}
	}

	delete [] tpl;
	tpl = new TUPLE[ k +1];  

	delete [] tuple[CurS_Num]; //2007.03.08
	tuple[CurS_Num] = new TUPLE[ k +1];

	for(i=1; i<=k; i++)
	{
		tpl[i] = tmp_tpl[i];
		tuple[CurS_Num][i] = tmp_tpl[i];
	}
	S[CurS_Num].tplNum = k;

	delete [] tmp_tpl;	
	/////////////////////////////////////////
    return S[CurS_Num].tplNum; 
}



CLearnIing6App::zlother()
{
	return true;
/*
  	//2005.07.31
	char szSqlAllLearningRows[1024] = "";
    //strcpy(szSqlAllLearningRows, " SELECT * FROM " );
	//strcat(szSqlAllLearningRows, " Lsi_104D ");
    strcpy(szSqlAllLearningRows, " insert Temp_cover4D values (1,2,3,4,5) " );

	//int istrSelectLenth = cStrInsert.GetLength() + 1;
	bool bReturn = zlExeInsertTable(szSqlAllLearningRows);			

    strcpy(szSqlAllLearningRows, " insert Temp_cover4D values (1,3,5,7,9) " );

	//int istrSelectLenth = cStrInsert.GetLength() + 1;
    bReturn = zlExeInsertTable(szSqlAllLearningRows);			


/////////////////////////////
	char szSqlDelete[512] = "";     
    strcpy(szSqlDelete, " delete from Temp_cover4D Where ID%2 =0 ");
	
//	if(!zlOpenDB())
	{
		//AfxMessageBox("zlOpenDB() err!");
		//zlCloseDB();
	}

	SQLFreeStmt(hstmt, SQL_DROP);
	retcode = SQLAllocStmt(hdbc, &hstmt); ///Statement handle 
	if(retcode != SQL_SUCCESS)
		AfxMessageBox("1. Get m initial rectangles from DB, Error!" ); //return -1;

	SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
	SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
	
	retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlDelete, SQL_NTS);

	//zlCloseDB();
/////////////
*/

//---Set the max memory 

    char szSql[1024] = "";
	bool brtn;


strcpy(szSql, "USE master \
 EXEC sp_configure 'show advanced option', '1' \
 RECONFIGURE \
 EXEC sp_configure \
 EXEC sp_configure 'min server memory', '0' \
 RECONFIGURE WITH OVERRIDE \
 EXEC sp_configure 'max server memory', '16' \
 RECONFIGURE WITH OVERRIDE USE MulTopN ");

  brtn = zlExeInsertTable(szSql);
//--- Set the max memory 




////////------

	double  fCol[104 +1];		//Elevation
	SDWORD cbCol[104+1]; 
    double pCol[104+1];
    int i; 
	int iRowCount =0 ;

	UCHAR szSqlAllRows[] = "SELECT * FROM Lsi_025D"; //all dataset

 	//if(!zlOpenDB())
	{
		//AfxMessageBox("zlOpenDB() err!");
		//zlCloseDB();
	}

	SQLFreeStmt(hstmt, SQL_DROP);
	retcode = SQLAllocStmt(hdbc, &hstmt); ///Statement handle 
	if(retcode != SQL_SUCCESS)
		AfxMessageBox("1. Get m initial rectangles from DB, Error!" ); //return -1;

	SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
	SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
	
	retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlAllRows, SQL_NTS);
		if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) 
		{    //	retcode = SQLExecDirect for census2Dg
			//int iRowCount;
			//SDWORD *  RowCountPtr = new SDWORD ;
			//retcode = SQLRowCount(hstmt, RowCountPtr);						 
			//iRowCount = * RowCountPtr;
			//iTupleNum = iRowCount;
			//delete RowCountPtr;
			
//==================
			for(i = 0; i <104+1; i++)
			{
				fCol[i] =0.0;
				cbCol[i] = 0; 
			}
			// Bind columns 1,2,3,4 ,.., 105
				for(i = 0; i <104; i++)
						SQLBindCol(hstmt, i+1, SQL_C_DOUBLE, &fCol[i],0, &cbCol[i]); //SQL_C_SSHORT
				
			//SQLBindCol(hstmt, COL_NUM+1, SQL_C_SLONG, &sColID,0, &cbColID); //SQL_C_SSHORT
					
			while (TRUE) 
			{
				retcode = SQLFetch(hstmt);
				
				if (retcode == SQL_ERROR)
				{
					//wsprintf(tmp, "%ld", iRowCount);
					AfxMessageBox("zlother SQLFetch Error !!!!!!");							//break; //99.8.26
				}
				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
				{	

					for(i = 0; i<104; i++)
					{
						pCol[i] = fCol[i]; 
					}
						
				} 
				else 
				{
					break;
				}

				iRowCount++;
			}   ///while (TRUE)
			
		}//	retcode = SQLExecDirect  for census2Dg

	//zlCloseDB();

//configure the 'max server memory' to be 
	//5MB for Lsi50D, 
	//8MB for Lsi104D, and
	//4MB for the other datasets. 
//Note that 4MB is the smallest value for the 'max server memory' in Microsoft's SQL Server 2000.


strcpy(szSql, "USE master \
 EXEC sp_configure 'show advanced option', '1' \
 RECONFIGURE \
 EXEC sp_configure \
 EXEC sp_configure 'min server memory', '0' \
 RECONFIGURE WITH OVERRIDE \
 EXEC sp_configure 'max server memory', 'MAX_SVR_MEM' \
 RECONFIGURE WITH OVERRIDE USE MulTopN ");

  brtn = zlExeInsertTable(szSql);

////////------

}

bool CLearnIing6App::zlExeInsertTable(char *szSqlInsert)
{
	bool bReturn = false;
	CString strMessage;
	strMessage.Empty();

	//if(!zlOpenDB())
	{
	//	AfxMessageBox("zlOpenDB() err!");
		//zlCloseDB();
	}

//////
	SQLFreeStmt(hstmt, SQL_DROP);
	retcode = SQLAllocStmt(hdbc, &hstmt); ///Statement handle 
	if(retcode != SQL_SUCCESS)
		return false; //-1;

	SQLSetStmtOption(hstmt, SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY);
	SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN);
	retcode = SQLExecDirect(hstmt, (unsigned char *)szSqlInsert, SQL_NTS);  //2005.02.07
/////


	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) 
	{  //	retcode = SQLExecDirect
		//AfxMessageBox("Update Recode Seccess!");
		bReturn = TRUE;
	}
	else
	{
		//cancel the following box in the end
		strMessage = "szSqlInsert Recode Fail!";
		strMessage += "\r\n";
		strMessage += szSqlInsert;

		//AfxMessageBox("szSqlInsert Recode Fail!");
		; //AfxMessageBox(strMessage);

	} //	retcode = SQLExecDirect 

   //zlCloseDB();
   return bReturn;
}

bool CLearnIing6App::zlStartSQLservr()
{
	
	char cmd[512] = ""; 
	//--- home
	strcpy(cmd, "i:\\Program Files\\Microsoft SQL Server\\MSSQL\\Binn\\sqlservr.exe"); 
	//--- new cumpos
	//strcpy(cmd, "d:\\Program Files\\Microsoft SQL Server\\MSSQL\\Binn\\sqlservr.exe"); 

	memset(&info,0,sizeof(info)); 
	info.cb=sizeof(info); 
	info.wShowWindow = SW_HIDE; // SW_MINIMIZE; //0; //SW_SHOWDEFAULT; //SW_HIDE//SW_MINIMIZE

									   //TRUE
	if(!CreateProcess(NULL,cmd,NULL,NULL,FALSE ,NORMAL_PRIORITY_CLASS,NULL,NULL,&info,&pinfo)) 
	{ 
 		AfxMessageBox(" SQL Server is not start"); 
	} 
	
    if(WaitForSingleObject(pinfo.hProcess,15000) == WAIT_FAILED) //INFINITE
	{
        char temp[128];
        sprintf(temp, "WaitForSingleObject FAILED: err=%d\n", GetLastError());
 		AfxMessageBox(temp); 

        return false;
    }
	else
	{
       return true;
	}

	//return true;
/*	if (WaitForSingleObject(process,INFINITE)==STAUTE_WAIT_0) 

     cout<<¡±Slave:Master completed\n¡±; 
   else 
      cout<<¡±Slave:Unexpected error\n¡±; 
*/

}

BOOL CLearnIing6App::zlEndSQLservr()
{
  /*
   Sleep(4000);//3000
   BOOL ret1, ret2, ret3;
   ret1 = TerminateProcess(pinfo.hProcess, 0);
   ret2 = CloseHandle(pinfo.hThread);
   ret3 = CloseHandle(pinfo.hProcess);
   return (ret1 && ret2 && ret3);
   ***/
	return true;
}

int CLearnIing6App::zlExeSelectQ_r_LRC(QUERY Query, double r)
{
	
	//if(!zlOpenDB())
	//{
	//	AfxMessageBox("zlOpenDB() err!");
		//zlCloseDB();
	//}
    
	int iRowCnt = -1;
    int iTupleNum;

	double fCol[COL_NUM+1];		//Elevation
	SDWORD cbCol[COL_NUM+1]; 	
	SDWORD sColID =0; 
	SDWORD cbColID =0; 
	int iQryIdx = 1; //pApp->tpl[] is based 1
	char tmp[512];
	char temp[1024];
	int i, j;
    
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
		strcat(	szSql, 	 TableName);     //m_DataSetTable
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

		if(iRowCnt <=0)
		{
	        delete [] szSql;
			return iRowCnt;
        }
		delete [] tpl;
		tpl = new TUPLE[iRowCount+1]; //pApp->tpl[] is based 1

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
				
				for(i = 0; i<COL_NUM; i++)  //pApp->tpl[] is based 1
				{
					tpl[iQryIdx].x[i+1] = fCol[i];
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
