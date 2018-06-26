// TableName.cpp : implementation file
//

#include "stdafx.h"
#include "LearnIing6.h"
#include "TableName.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTableName dialog


CTableName::CTableName(CWnd* pParent /*=NULL*/)
	: CDialog(CTableName::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTableName)
	m_DataSetTable = _T("");
	m_TableName = _T("");
	m_OutputTableName = _T("");
	m_WorkloadTable = _T("");
	m_TopN = TOP_N; //20 ; //100;  //20; 100
	//}}AFX_DATA_INIT
}


void CTableName::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTableName)
	DDX_CBString(pDX, IDC_COMBO_DATASET, m_DataSetTable);
	DDX_CBString(pDX, IDC_COMBO_INPUT_TABLE, m_TableName);
	DDX_CBString(pDX, IDC_COMBO_OUTPUT_TABLE, m_OutputTableName);
	DDX_CBString(pDX, IDC_COMBO_WORKLOAD, m_WorkloadTable);
	DDX_Text(pDX, IDC_EDIT_TOPN, m_TopN);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTableName, CDialog)
	//{{AFX_MSG_MAP(CTableName)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTableName message handlers

void CTableName::OnOK() 
{
	// TODO: Add extra validation here
	/////////////////////////////
	UpdateData(true);

	CLearnIing6App * pApp = (CLearnIing6App * ) AfxGetApp();
  
	for(int i = 0; i<1024; i++)
	{
		pApp->TableName[i]        =0;
		pApp->szInputTableName[i] =0;
		pApp->szOutputTableName[i]=0;
	}
	strcpy( pApp->TableName , m_DataSetTable); // 
	strcpy( pApp->szInputTableName , m_TableName); // 
	strcpy( pApp->szOutputTableName , m_OutputTableName); // 
	
	strcpy(pApp->m_WorkloadTable, m_WorkloadTable);
    pApp->m_TopN =  m_TopN;
    //pApp->m = m_Num_Query;
	 
	//////////////////////////////

	CDialog::OnOK();
}

BOOL CTableName::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//1. DataSet Tables
	CComboBox * pComboDataSet = (CComboBox *) GetDlgItem(IDC_COMBO_DATASET);
	pComboDataSet->AddString("Attr_Census2D");
	pComboDataSet->AddString("Attr_Census3D");
	//pComboDataSet->AddString("Attr_Array3D");
	//pComboDataSet->AddString("Attr_Gauss3D");
	pComboDataSet->AddString("Attr_Cover4D");
	pComboDataSet->AddString("Lsi_025D");
	//pComboDataSet->AddString("Lsi_050D");
	pComboDataSet->AddString("Lsi_104D");

	pComboDataSet->SetCurSel(0);
	//pComboDataSet->SetCurSel(1);

	//2. Input Tables (KB Profile Tables) 
	CComboBox * pComboInputTable = (CComboBox *) GetDlgItem(IDC_COMBO_INPUT_TABLE);
	
	/*
	//pComboInputTable->AddString("Census2D_Top100_Profile2000_LRC1");
	///pComboInputTable->AddString("Census3D_Top100_Profile2000_LRC1");
	//pComboInputTable->AddString("Array3D_Top100_Profile2000_LRC1");
	pComboInputTable->AddString("Gauss3D_Top100_Profile2000_LRC1");
	pComboInputTable->AddString("Cover4D_Top100_Profile2000_LRC1");
	pComboInputTable->AddString("Lsi_025D_Top20_Profile2000_LRC1");
	pComboInputTable->AddString("Lsi_050D_Top20_Profile2000_LRC1");
	pComboInputTable->AddString("Lsi_104D_Top20_Profile2000_LRC1");
   */
	pComboInputTable->SetCurSel(1);

	//3. Output Tables (Insert Tables // that are our results)
	CComboBox * pComboOutputTable = (CComboBox *) GetDlgItem(IDC_COMBO_OUTPUT_TABLE);

	pComboOutputTable->AddString("Census2D_T0100_B_Learning_F_W1000_NM");
	pComboOutputTable->AddString("Census3D_T0100_B_Learning_F_W1000_NM");
    pComboOutputTable->AddString( "Cover4D_T0100_B_Learning_F_W1000_NM");
	pComboOutputTable->AddString("Lsi_025D_T0020_B_Learning_F_W1000_NM");
	pComboOutputTable->AddString("Lsi_104D_T0020_B_Learning_F_W1000_NM");

	pComboOutputTable->SetCurSel(0);

	//4. Workload Tables 
	// have 10000 queries
	CComboBox * pComboWorkload = (CComboBox *) GetDlgItem(IDC_COMBO_WORKLOAD);
	
	pComboWorkload->AddString("Census2D_WorkLoad_1_rf_Q1000");
	pComboWorkload->AddString("Census3D_WorkLoad");
    pComboWorkload->AddString("Cover4D_WorkLoad_1_rf_Q1000");
	pComboWorkload->AddString("Lsi_025D_WorkLoad_1_r_Q1000");
	pComboWorkload->AddString("Lsi_104D_WorkLoad_1_r_Q1000");



	pComboWorkload->SetCurSel(0);
 /////////////////////// body end ///////////////////////////////////
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
