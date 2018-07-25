using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SelectivityEstimation
{
       public partial class FormMain : Form
    {
        static int COL_NUM ;
        static long iSizeofDataSetTable = 0;        
        public class ZLRECT
        {
            public double[] a = new double[COL_NUM + 1]; //
            public double[] b = new double[COL_NUM + 1]; //b[i] means bi
            public double v ;  // volume of the rectangle
            //public char[] suffix = new char[1000]; //Delete by David 2018.7.20
            public int suf1st;      // the first suffix that is 1 in (1,3,4,5)
            public int sufend;      // the end suffix that is 5 in (1,3,4,5)
            public int cn;          // class number or cluster number
            public int bsn;         // bsn: Big Set Number, the number of a set that contain this set
            public int tplNum;      // that is f,  the frequency of SCR , i.e., f = |SCR |,  the number of tuples in SCR;      
            public long count;  // 2018.3.18 lu
            public int[]x = new int[COL_NUM + 1];
            public int ID;
            public int tfloor;            
            public int dupcount;
            public int spaceSize;
            public string nodeId;
            public NODE[] node;
            public luTUPLE clTuplu = new luTUPLE() ;
        };
        public class NODE
        {
            public int[] x = new int[COL_NUM+1];  // the ith axis of date
            public int ID;         // the ID of the date
        };
        public class luTUPLE
        {
            public double[] x = new double[COL_NUM + 1];  // the ith axis of tuple
            public int num;            // the number of this tuples in topN
            public int ID;             // the ID of the tuple
            public int Tnum;
            public int[] Tid = new int[200];
            public double count;
        };
        public class MostVal
        {
            public double attrMax; // the biggest of attr val;
            public double attrMin; // the least of attr val;
            public double attrZeroZ;           // the most near zero from the right;
            public double attrZeroF;               //the most near zero from the left;
        };
        ZLRECT[] midRectNode = new ZLRECT[13];

        public FormMain()
        {
            InitializeComponent();
        }

         private void FormMain_Load(object sender, EventArgs e)
        {
            // 下拉菜单填充数据
            comboBox1.Items.Add("Attr_Census2D");
            comboBox1.Items.Add("Attr_Census3D");
            comboBox1.Items.Add("Attr_Cover4D");
            comboBox1.Items.Add("HW_20D_Clean");
            comboBox1.Items.Add("Attr_Census2D_Test");
            comboBox1.Items.Add("Attr_Census3D_TestDavid");         
            comboBox1.SelectedIndex = 0;
        }  
    
        private void buttonRun_Click(object sender, EventArgs e)
        {
            #region //初始化COL_NUM，校验数据集
            if (comboBox1.Text == "Attr_Census2D") COL_NUM = 2;
            if (comboBox1.Text == "Attr_Census3D") COL_NUM = 3;
            if (comboBox1.Text == "Attr_Cover4D") COL_NUM = 4;
            if (comboBox1.Text == "HW_20D_Clean") COL_NUM = 20;
            if (comboBox1.Text == "Attr_Census2D_Test") COL_NUM = 2;
            if (comboBox1.Text == "Attr_Census3D_TestDavid") COL_NUM = 3;
            string DataSetTable = comboBox1.Text;

            // 校验给定数据集的名称、元组数、列数            
            string select_all = "select count(*) from " + DataSetTable;
            iSizeofDataSetTable = DavidSelect(select_all);
            labelResult.Text = "DataSet:\"" + DataSetTable + "\"\nSIZE:" + iSizeofDataSetTable + "\nCOLUM:"+COL_NUM;
            #endregion

            #region//定义变量//找数据表中的最大值最小值（根节点，总体范围）dMax,dMin
            double[]dMin = new double[COL_NUM + 1];
            double []dMax = new double[COL_NUM + 1];
            int T_Num = 24;
            int PartNum = 0;    
            string Max3d="", Min3d="";
            for (int eee = 0; eee < COL_NUM; eee++)
            {
                string select_max = "select max(attr"+eee+") from " + DataSetTable;
                dMax[eee] = DavidSelect(select_max) + 1;
                Max3d += dMax[eee] + ",";
                string select_min = "select min(attr"+eee+") from " + DataSetTable;
                dMin[eee] = DavidSelect(select_min) - 1;
                Min3d += dMin[eee]+ ",";
            }
            labelMaxMin.Text = "(" + Max3d.Substring(0,Max3d.Length-1) + ")" + "\n" + "(" + Min3d.Substring(0,Min3d.Length - 1) + ")";
            #endregion

            #region //数据库数据加载到本地数据集，并记录时间 
            MessageBox.Show("加载数据，时间较长，请耐心等待  ~", "NOTICE", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            System.Diagnostics.Stopwatch stopwatch = new System.Diagnostics.Stopwatch(); // Stopwatch 方法 毫秒级
            stopwatch.Start();//开始
            string select_time = "";
            select_time = "SELECT  * FROM   " + DataSetTable;
         
            string conn = ConfigurationManager.ConnectionStrings["myconn"].ConnectionString;
            DataSet dataSet = new DataSet();
            SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(select_time,conn);
            sqlDataAdapter.Fill(dataSet,"TableName");
            stopwatch.Stop();//结束
            long TheTime = stopwatch.ElapsedMilliseconds; //这里是输出的总运行秒数,精确到毫秒的                
            labelTime.Text = "Read "+ iSizeofDataSetTable+" turples to DataSet ,used time:" + TheTime + "ms";
            #endregion

            #region//切块准备工作 1：本地数据集 复制到 数组 rect，并记录时间
            stopwatch.Restart();
            ZLRECT[] rect = new ZLRECT[iSizeofDataSetTable];
            for (int i = 0; i < iSizeofDataSetTable; i++)
            {
                rect[i] = new ZLRECT(); //初始化                   
            }

            for (int k = 0; k < iSizeofDataSetTable; k++)    //rect赋值(查询结果集DataSet 写到 数组rect)
            {
                for (int i = 0; i < COL_NUM; i++)
                {
                    rect[k].x[i] = Convert.ToInt32( dataSet.Tables["TableName"].Rows[k][i] );
                }
                rect[k].ID = Convert.ToInt32(dataSet.Tables["TableName"].Rows[k][COL_NUM]);
            }

            for (int i = 0; i < COL_NUM; i++)   //rect中a[i],b[i]赋值（a是最小值，b是最大值）
            {
                rect[0].a[i + 1] = dMin[i];
                rect[0].b[i + 1] = dMax[i];
            }

            stopwatch.Stop();
            TheTime = stopwatch.ElapsedMilliseconds; //这里是输出的总运行秒数,精确到毫秒的                
            labelTime.Text += "\nDataSet to Array(rect) ,used time:" + TheTime + "ms";
            #endregion

            #region//切块准备工作 2： 初始化midRectNode
            stopwatch.Restart();
            for (int i = 0; i < 13; i++)
            {
                midRectNode[i] = new ZLRECT(); //初始化                   
            }
            ZLRECT[] RectNode = new ZLRECT[13];
            for (int i = 0; i < 13; i++)
            {
                RectNode[i] = new ZLRECT(); //初始化                   
            }
            midRectNode[0].count = iSizeofDataSetTable;

            for (int t = 1; t <= 12; t++)
            {
                NODE[] MyNodes = new NODE[iSizeofDataSetTable];//初始化  
                midRectNode[t].node = MyNodes;
            }
            for (int i = 0; i < COL_NUM; i++)       //初始化midRectNode[s].a[i]、midRectNode[s].b[i]
            {
                midRectNode[0].a[i] = dMin[i];
                midRectNode[0].b[i] = dMax[i];
            }
            //MessageBox.Show("midRectNode loaded！");
            //labelRect.Text += "\tmidRectNode loaded.";
            stopwatch.Stop();
            TheTime = stopwatch.ElapsedMilliseconds; //这里是输出的总运行秒数,精确到毫秒的                
            labelTime.Text += "\nmidRectNode initialized ,used time:" + TheTime + "ms";
            #endregion

            #region  //切块准备工作 3： tNode存取所有节点
            stopwatch.Restart();
            int sumNode = 1 + 12 + 12 * 12 + 12 * 12 * 12 + 1;
            ZLRECT[] tNode = new ZLRECT[sumNode];
            for (int i = 0; i < sumNode; i++)
            {
                tNode[i] = new ZLRECT(); //初始化                   
            }
            int tNum = 0;
            for (int i = 0; i <= COL_NUM; i++)   //t[0]中a[i],b[i]赋值    根节点   t[0]
            {
                tNode[tNum].a[i] = dMin[i];
                tNode[tNum].b[i] = dMax[i];
            }
            tNode[tNum].count = iSizeofDataSetTable;
            tNode[tNum].tfloor = 1;                  //根节点为第一层t[tNum].tfloor = 1;  
            tNum++;
            //MessageBox.Show("tNode loaded！");
            //labelRect.Text += "\ttNode loaded.";
            for (int s = 1; s <= 12; s++)          //初始化midRectNode[s].count
            {
                midRectNode[s].count = 0;
            }
            stopwatch.Stop();
            TheTime = stopwatch.ElapsedMilliseconds; //这里是输出的总运行秒数,精确到毫秒的                
            labelTime.Text += "\ntNode initialized ,used time:" + TheTime + "ms";
            #endregion

            #region//调用"切块函数"切块：共划分三次，1 -> 12 -> 12*12 -> 12*12*12 = 1728 
            MessageBox.Show("开始切块，时间更长，更需耐心等待  ~", "NOTICE", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            stopwatch.Restart();// 开始计时
            ZLRECT[] LRect4 = new ZLRECT[12 * 12 * 12 + 1];   //第三层节点LRect3[1-12*12]
            if (midRectNode[0].count > 5)//大于5是什么意思？
            {
                #region //第一次划分，划分为12块 (第二层)
                if (COL_NUM == 2)
                {
                    zlPartionpa2(rect, COL_NUM, T_Num, PartNum);//2D 切块函数，切为 3*4形状
                }
                if (COL_NUM >= 3)
                {
                    zlPartion3DLu(rect, COL_NUM, T_Num, PartNum);
                }                
                string Layer2NameAndCount = "";//记录第二层节点以及各个节点的数量
                
                long TotalCount = 0;
                for (int tn = 1; tn <= 12; tn++)               
                {
                    string StringA = "", StringB = "";
                    Layer2NameAndCount += "\r\nID:" + tNum + "\t";
                    for (int ti = 0; ti < COL_NUM; ti++)
                    {
                        tNode[tNum].a[ti] = midRectNode[tn].a[ti];
                        StringA += Convert.ToInt32( tNode[tNum].a[ti] )+ ",";
                        tNode[tNum].b[ti] = midRectNode[tn].b[ti]; 
                        StringB += Convert.ToInt32(tNode[tNum].b[ti]) + ",";
                    }
                    Layer2NameAndCount += "(" + StringA.Substring(0,StringA.Length-1) + ")" +  "(" + StringB.Substring(0, StringB.Length - 1) + ")";

                    tNode[tNum].count = midRectNode[tn].count;
                    tNode[tNum].nodeId = midRectNode[tn].nodeId;
                    TotalCount += tNode[tNum].count;
                    //string nodeIdPrint = tNode[tNum].nodeId;//查看该Node中包含的数据ID号集合
                    //if (nodeIdPrint == null)
                    //    nodeIdPrint = "Empty Data";
                    //else if (nodeIdPrint.Length > 30)
                    //    nodeIdPrint = nodeIdPrint.Substring(0, 30)+"......"+ nodeIdPrint.Substring(nodeIdPrint.Length - 30);

                    Layer2NameAndCount += "\tcount=" + tNode[tNum].count;                    
                    tNode[tNum].tfloor = 2;
                    tNum++;
                }
                Layer2NameAndCount += "\r\nTotal Count=" + TotalCount;
                Layer2NameAndCount += "\r\n=============================" ;
                StreamWriter sw2 = new StreamWriter("D:\\Layer2.txt", false, Encoding.GetEncoding("gb2312"));
                sw2.WriteLine(Layer2NameAndCount);
                sw2.Close();
                //把midRectNode[1-12]中数据复制到RectNode【1-12】中
                for (int r = 1; r <= 12; r++)
                {                    
                    RectNode[r].node = new NODE[midRectNode[r].count];

                    for (int p = 0; p < COL_NUM; p++)
                    {
                        RectNode[r].a[p] = midRectNode[r].a[p];
                        RectNode[r].b[p] = midRectNode[r].b[p];                       
                    }
                    RectNode[r].count = midRectNode[r].count;

                    for (int n = 0; n < midRectNode[r].count; n++)
                    {
                         RectNode[r].node[n] = new NODE() ;                     
                        for (int w = 0; w < COL_NUM; w++)
                        {
                            RectNode[r].node[n].x[w] = midRectNode[r].node[n].x[w];
                            //tempNode += "\r\nX:" + RectNode[r].node[n].x[w];
                        }
                        RectNode[r].nodeId = midRectNode[r].nodeId;
                    }
                    //for (int n = 0; n < midRectNode[r].count; n++)
                    //{
                    //    RectNode[r].nodeId = midRectNode[r].nodeId;
                    //}                    
                }

                #endregion

                #region //第二次划分，划分为12 * 12 块 （第三层）
                //MessageBox.Show("第三层划分开始！");
                ZLRECT[] LRect3 = new ZLRECT[12 * 12 + 1];   //第三层节点LRect3[1-12*12]
                for (int i = 0; i < 12 * 12 + 1; i++)
                {
                    LRect3[i] = new ZLRECT(); //初始化                   
                }
                int numL3 = 1;                    //从1开始(第三层计数)
                string Layer3NameAndCount = "";
                long TotalCountOfLayer3 = 0;
                for (int x = 1; x <= 12; x++)
                {
                    //ZLRECT[] midRectNode = new ZLRECT[13];
                    for (int i = 0; i < 13; i++)
                    {
                        midRectNode[i] = new ZLRECT(); //初始化，被拆分的根节点                   
                    }
                    midRectNode[0].count = RectNode[x].count;      //初始化midRectNode[0].a[i]、midRectNode[0].b[i]
                    for (int m = 0; m < COL_NUM; m++)
                    {
                        midRectNode[0].a[m] = RectNode[x].a[m];
                        midRectNode[0].b[m] = RectNode[x].b[m];
                    }
                    for (int t = 1; t <= 12; t++)                //每次循环创建12个包含元组的midRectNode[t].node块
                    {
                        midRectNode[t].node = new NODE[RectNode[x].count];//RectNode[t] ?RectNode[x]? 18.7.23
                    }
                    ZLRECT[] rect3 = new ZLRECT[RectNode[x].count];
                    if (RectNode[x].count > 0)              //开始划分，块中有元组，Rectnode[x].count！=0;
                    {
                        //rect=rectNode[x]                        
                        for (int i = 0; i < RectNode[x].count; i++)
                        {
                            rect3[i] = new ZLRECT(); //初始化                   
                        }
                        for (int y = 0; y < RectNode[x].count; y++)      //rect 赋值
                        {
                            for (int z = 0; z < COL_NUM; z++)
                            {
                                rect3[y].a[z + 1] = RectNode[x].a[z];
                                rect3[y].b[z + 1] = RectNode[x].b[z];
                                rect3[y].x[z] = RectNode[x].node[y].x[z];
                            }
                            //rect3[y].ID = RectNode[x].node[y].ID;
                        }
                        //调用划分函数//zlPartionpa2(rect3, COL_NUM, T_Num, PartNum);   //调用划分函数
                        if (COL_NUM == 2)
                        {
                            zlPartionpa2(rect3, COL_NUM, T_Num, PartNum);//2D 切块函数，切为 3*4形状
                        }
                        if (COL_NUM >= 3)
                        {
                            zlPartion3DLu(rect3, COL_NUM, T_Num, PartNum);
                        }
                    }
                    else                   //只划分，块中没有元组，Rectnode[x].count=0; 
                    {
                        //块儿中没有元组，为什么要划分？划分的原则是什么？ David 2018.7.21 记录边界值？
                        rect3 = new ZLRECT[1];
                        rect3[0] = new ZLRECT();
                        //zlPartionpa2_empty(rect, COL_NUM, T_Num, PartNum);
                        if (COL_NUM == 2)
                        {
                            for (int z = 0; z < COL_NUM; z++)
                            {
                                rect3[0].a[z + 1] = RectNode[x].a[z];
                                rect3[0].b[z + 1] = RectNode[x].b[z];
                            }
                            zlPartionpa2_empty(rect3, COL_NUM, T_Num, PartNum);
                        }
                        if (COL_NUM >= 3)
                        {
                            for (int z = 0; z < COL_NUM; z++)
                            {
                                rect3[0].a[z+1] = RectNode[x].a[z];//   2018.7.25 David 划分count=0的空间
                                rect3[0].b[z+1] = RectNode[x].b[z];
                            }
                            zlPartion3DLuPa(rect3, COL_NUM, T_Num, PartNum);
                        }
                    }

                    //保存第三层节点LRect3[12*12]
                    
                    for (int r = 1; r <= 12; r++)                                            //保存第三层节点LRect3[12*12],midRectNode[r].count!=0时；              
                    {
                        if (midRectNode[r].count > 0)
                        {
                            LRect3[numL3].node = new NODE[midRectNode[r].count];
                            Layer3NameAndCount += "ID:" + numL3 + "\t";
                            string StringA = "", StringB = "";
                            for (int p = 0; p < COL_NUM; p++)
                            {
                                LRect3[numL3].a[p] = midRectNode[r].a[p];
                                LRect3[numL3].b[p] = midRectNode[r].b[p];
                                tNode[tNum].a[p] = midRectNode[r].a[p];             //存储第三层节点 t[13-12*12]
                                tNode[tNum].b[p] = midRectNode[r].b[p];
                                StringA += Convert.ToInt32(tNode[tNum].a[p]) + ",";
                                StringB += Convert.ToInt32(tNode[tNum].b[p]) + ",";
                            }
                            Layer3NameAndCount += "(" + StringA.Substring(0, StringA.Length - 1) + ")" + "(" + StringB.Substring(0, StringB.Length - 1) + ")";
                            LRect3[numL3].count = midRectNode[r].count;
                            TotalCountOfLayer3 += LRect3[numL3].count;
                            Layer3NameAndCount += "\t"+ LRect3[numL3].count + "\t";
                            if (numL3 % 4 == 0)
                            {
                                Layer3NameAndCount += "\r\n";
                            }
                            if (numL3 % 12 == 0)
                            {
                                Layer3NameAndCount += "\r\n";
                            }
                            tNode[tNum].count = midRectNode[r].count;                  //存储第三层节点 t[13-12*12]
                            tNode[tNum].tfloor = 3;                                                 

                            for (int n = 0; n < midRectNode[r].count; n++)
                            {
                                LRect3[numL3].node[n] = new NODE();
                                for (int w = 0; w < COL_NUM; w++)
                                {                                   
                                    LRect3[numL3].node[n].x[w] = midRectNode[r].node[n].x[w];
                                }
                                //LRect3[numL3].node[n].ID = midRectNode[r].node[n].ID;
                            }

                            numL3++;
                            tNum++;
                            
                            //保存第三层节点LRect3[12*12]
                        }//end if
                        else if (midRectNode[r].count == 0)
                        {
                            LRect3[numL3].node = new NODE[midRectNode[r].count];
                            Layer3NameAndCount += "ID:" + numL3 + "\t";
                            string StringA = "", StringB = "";
                            for (int p = 0; p < COL_NUM; p++)
                            {
                                LRect3[numL3].a[p] = midRectNode[r].a[p];
                                LRect3[numL3].b[p] = midRectNode[r].b[p];
                                tNode[tNum].a[p] = midRectNode[r].a[p];             //存储第三层节点 t[13-12*12]
                                tNode[tNum].b[p] = midRectNode[r].b[p];
                                StringA += Convert.ToInt32(tNode[tNum].a[p]) + ",";
                                StringB += Convert.ToInt32(tNode[tNum].b[p]) + ",";
                            }                            
                            Layer3NameAndCount += "(" + StringA.Substring(0, StringA.Length - 1) + ")" + "(" + StringB.Substring(0, StringB.Length - 1) + ")";
                            LRect3[numL3].count = midRectNode[r].count;                       
                            Layer3NameAndCount += "\t" + LRect3[numL3].count + "\t";
                            if (numL3 % 4 == 0)
                            {
                                Layer3NameAndCount += "\r\n";
                            }
                            if (numL3 % 12 == 0)
                            {
                                Layer3NameAndCount += "\r\n";
                            }
                            tNode[tNum].count = midRectNode[r].count;                  //存储第三层节点 t[13-12*12]
                            tNode[tNum].tfloor = 3;
                            numL3++;
                            tNum++;                            
                            //保存第三层节点LRect3[12*12]                           
                        }
                        else
                        {
                            MessageBox.Show(" 存储第三层节点时出错 !!!!!!");
                        }
                    }
                }
                Layer3NameAndCount += "\r\nTotalCountOfLayer3:" + TotalCountOfLayer3;
                StreamWriter sw3 = new StreamWriter("D:\\Layer3.txt", false, Encoding.GetEncoding("gb2312"));
                sw3.WriteLine(Layer3NameAndCount);
                sw3.Close();
                #endregion

                #region //第三次划分，划分为12 * 12 * 12 块 （第四层）
                //MessageBox.Show("第四层划分开始！");
                //LRect4 = new luRect[12 * 12 * 12 + 1];   //第四层节点LRect4[1-12*12*12]
                
                string Layer4NameAndCount = "";
                long TotalCountLayer4 = 0;
                for (int i = 0; i < 12 * 12 * 12 + 1; i++)
                {
                    LRect4[i] = new ZLRECT(); //初始化                   
                }
                int numL4 = 1;                    //从1开始

                for (int x = 1; x <= 144; x++)         //12*12=144第三层节点数目
                {
                    //midRectNode = new luRect[13];
                    for (int i = 0; i < 13; i++)
                    {
                        midRectNode[i] = new ZLRECT(); //初始化                   
                    }
                    midRectNode[0].count = LRect3[x].count;      //初始化midRectNode[0].a[i]、midRectNode[0].b[i]
                    for (int m = 0; m < COL_NUM; m++)
                    {
                        midRectNode[0].a[m] = LRect3[x].a[m];
                        midRectNode[0].b[m] = LRect3[x].b[m];
                    }
                    ZLRECT[] rect4 = new ZLRECT[LRect3[x].count];
                    for (int t = 1; t <= 12; t++)                //每次循环创建12个包含元组的midRectNode[t].node块
                    {
                        midRectNode[t].node = new NODE[LRect3[x].count];
                    }
                    if (LRect3[x].count > 0)              //开始划分，块中有元组，Rectnode[x].count！=0;
                    {
                        //rect=LRect3[x]
                        
                        for (int i = 0; i < LRect3[x].count; i++)
                        {
                            rect4[i] = new ZLRECT(); //初始化                   
                        }
                        for (int y = 0; y < LRect3[x].count; y++)      //rect 赋值
                        {
                            for (int z = 0; z < COL_NUM; z++)
                            {
                                rect4[y].a[z + 1] = LRect3[x].a[z];
                                rect4[y].b[z + 1] = LRect3[x].b[z];
                                rect4[y].x[z] = LRect3[x].node[y].x[z];
                            }
                           // rect[y].ID = LRect3[x].node[y].ID;
                        }
                        //调用划分函数                        zlPartionpa2(rect4, COL_NUM, T_Num, PartNum);   //调用划分函数   
                        if (COL_NUM == 2)
                        {
                            zlPartionpa2(rect4, COL_NUM, T_Num, PartNum);//2D 切块函数，切为 3*4形状
                        }
                        if (COL_NUM >= 3)
                        {
                            zlPartion3DLu(rect4, COL_NUM, T_Num, PartNum);
                        }
                    }
                    else                   //只划分，块中没有元组，Rectnode[x].count=0;
                    {
                        rect4 = new ZLRECT[1];
                        rect4[0] = new ZLRECT();

                        //zlPartionpa2_empty(rect4, COL_NUM, T_Num, PartNum);
                        if (COL_NUM == 2)
                        {
                            for (int z = 0; z < COL_NUM; z++)
                            {
                                rect4[0].a[z + 1] = LRect3[x].a[z];
                                rect4[0].b[z + 1] = LRect3[x].b[z];
                            }
                            zlPartionpa2_empty(rect4, COL_NUM, T_Num, PartNum);
                        }
                        if (COL_NUM >= 3)
                        {
                            for (int z = 0; z < COL_NUM; z++)
                            {
                                rect4[0].a[z+1] = LRect3[x].a[z];
                                rect4[0].b[z+1] = LRect3[x].b[z];
                            }
                            zlPartion3DLuPa(rect4, COL_NUM, T_Num, PartNum);
                        }
                    }

                    //保存第四层节点LRect4[12*12*12]
                    for (int r = 1; r <= 12; r++)                                            //保存第四层节点LRect3[12*12],midRectNode[r].count!=0时；              
                    {
                        if (midRectNode[r].count > 0)
                        {
                            LRect4[numL4].node = new NODE[midRectNode[r].count];
                            Layer4NameAndCount += "ID:" + numL4 + "\t";
                            string StringA = "", StringB = "";
                            for (int p = 0; p < COL_NUM; p++)
                            {
                                LRect4[numL4].a[p] = midRectNode[r].a[p];
                                LRect4[numL4].b[p] = midRectNode[r].b[p];
                                tNode[tNum].a[p] = midRectNode[r].a[p];             //存储第四层节点 t[13-12*12]
                                tNode[tNum].b[p] = midRectNode[r].b[p];
                                StringA += Convert.ToInt32(tNode[tNum].a[p]) + ",";
                                StringB += Convert.ToInt32(tNode[tNum].b[p]) + ",";
                            }
                            Layer4NameAndCount += "(" + StringA.Substring(0, StringA.Length - 1) + ")" + "(" + StringB.Substring(0, StringB.Length - 1) + ")";
                            LRect4[numL4].count = midRectNode[r].count;
                            TotalCountLayer4 += LRect4[numL4].count;
                            Layer4NameAndCount += "\t" + LRect4[numL4].count + "\t";

                            if (numL4 % 4 == 0)
                            {
                                Layer4NameAndCount += "\r\n";
                            }
                            if (numL4 % 12 == 0)
                            {
                                Layer4NameAndCount += "\r\n";
                            }
                            if (numL4 % 144 == 0)
                            {
                                Layer4NameAndCount += "\r\n";
                            }
                            tNode[tNum].count = midRectNode[r].count;                  //存储第四层节点 t[13-12*12]
                            tNode[tNum].tfloor = 4;

                            for (int n = 0; n < midRectNode[r].count; n++)
                            {
                                LRect4[numL4].node[n] = new NODE();
                                for (int w = 0; w < COL_NUM; w++)
                                {                                    
                                    LRect4[numL4].node[n].x[w] = midRectNode[r].node[n].x[w];
                                }
                                //LRect4[numL4].node[n].ID = midRectNode[r].node[n].ID;
                            }
                            numL4++;
                            tNum++;
                            
                            //保存第4层节点LRect3[12*12]

                        }//end if
                        else if (midRectNode[r].count == 0)
                        {
                            LRect4[numL4].node = new NODE[midRectNode[r].count];
                            Layer4NameAndCount += "ID:" + numL4 + "\t";
                            string StringA = "", StringB = "";
                            for (int p = 0; p < COL_NUM; p++)
                            {
                                LRect4[numL4].a[p] = midRectNode[r].a[p];
                                LRect4[numL4].b[p] = midRectNode[r].b[p];
                                tNode[tNum].a[p] = midRectNode[r].a[p];             //存储第四层节点 t[13-12*12]
                                tNode[tNum].b[p] = midRectNode[r].b[p];
                                StringA += Convert.ToInt32(tNode[tNum].a[p]) + ",";
                                StringB += Convert.ToInt32(tNode[tNum].b[p]) + ",";
                            }
                            Layer4NameAndCount += "(" + StringA.Substring(0, StringA.Length - 1) + ")" + "(" + StringB.Substring(0, StringB.Length - 1) + ")";
                            LRect4[numL4].count = midRectNode[r].count;
                            tNode[tNum].count = midRectNode[r].count;                  //存储第四层节点 t[13-12*12]
                            tNode[tNum].tfloor = 4;
                            Layer4NameAndCount +=  "\t" + LRect4[numL4].count + "\t";
                            if (numL4 % 4 == 0)
                            {
                                Layer4NameAndCount += "\r\n";
                            }
                            if (numL4 % 12 == 0)
                            {
                                Layer4NameAndCount += "\r\n";
                            }
                            if (numL4 % 144 == 0)
                            {
                                Layer4NameAndCount += "\r\n";
                            }
                            numL4++;
                            tNum++;
                            //保存第四层节点LRect4[12*12*12]
                        }
                        else
                        {
                            MessageBox.Show(" 存储第四层节点时出错 !!!!!!");
                        }
                    }                    
                }
                //MessageBox.Show(Layer4NameAndCount);
                Layer4NameAndCount += "\r\nTotalCountOfLayer4:" + TotalCountLayer4;
                StreamWriter sw4 = new StreamWriter("D:\\Layer4.txt", false, Encoding.GetEncoding("gb2312"));
                sw4.WriteLine(Layer4NameAndCount);
                sw4.Close();
                #endregion
            }
            else
            {                
                MessageBox.Show("完成划分，共划分1组");
            }
            stopwatch.Stop();//计时结束
            TheTime = stopwatch.ElapsedMilliseconds; //总运行秒数, 精确到毫秒
            labelRect.Text = "Divided to 12*12*12 blocks ,used time:" + TheTime + "ms";
            long sum1 = 0;
            for (int d = 1; d <= 1728; d++)
            {
                sum1 += LRect4[d].count;
            }
            MessageBox.Show("切块完毕！\n共"+ sum1 + "个元组。\n请在下列文件中查看结果: \nD:\\Layer2.txt，Layer3.txt，Layer4.txt " +
                "\n数据清洗，时间较长，请继续等待", "NOTICE", MessageBoxButtons.OK, MessageBoxIcon.Information);
            #endregion

            #region// 去重：进行数据清洗，得出干净数据集以及数据节点表
            stopwatch.Restart();//计时开始

            //DupRemove(LRect4);  //调用"去重函数"，进行数据清洗

            stopwatch.Stop();//计时结束
            TheTime = stopwatch.ElapsedMilliseconds; //总运行秒数, 精确到毫秒          
            labelDuplicated.Text = "Remove duplicated data ,used time:" + TheTime + "ms";
            long sum = 0;
            for (int d = 1; d <= 1728; d++)
            {
                sum += LRect4[d].count;
            }
            //CleanCount[CleanCountnum] = sum; // 什么作用？？2018.7.25
            //CleanCountnum++;
            MessageBox.Show("程序执行完毕 ~ \n去重前元组数：" + sum1 + "\n去重后元组数："+sum, "NOTICE", MessageBoxButtons.OK, MessageBoxIcon.Information);
            #endregion
        }

        //For 2D 
        int zlPartionpa2(ZLRECT[] Rect, int Dimention,  int T_Num, int PartNum)
        {
            //labelRect.Text += "zlPartionpa2() implemented. \nDimention = "+Dimention+ ",T_Num="+ T_Num;
            int n = Dimention;
            int m = 0;// T_Num;?
            int h, i, j, k, idx;
            bool bInterable = false;
            string cstrMarc;
            ZLRECT[] part = new ZLRECT[13];
            for (int iii = 0; iii < 13; iii++)
            {
                part[iii] = new ZLRECT();
            }
            //ZLRECT[] scr = new ZLRECT[iSizeofDataSetTable];
            ZLRECT[] scr;
            int[] dim = new int[3]; //dim[1], [2], [3] are the biggest value of all dimensens
            double dMaxInterval = 0.0;

            scr = Rect;

            //if (Rect.Length < 12 && Rect.Length > 0)                return 0; // Help by BoboLiu . 2018.7.23
            // 遗留问题，区域内有1-11个点怎么处理？

            for (i = 0; i < 12; i++)
            {
                for(int jjj = 0; jjj<COL_NUM;jjj++)
                {
                    part[i].a[jjj] = Rect[0].a[jjj]; //Fixed by LuWP . 2018.7.23
                    part[i].b[jjj] = Rect[0].b[jjj];
                    part[i].count = Rect[0].count;
                }
                               
            }
            for (j = 12; j > 0; j--)
            {
                part[j] = part[j - 1];
            }

            double[] a = new double[n + 1];
            double[] d = new double[n + 1];
            int alfa=0;

            // For 2D, 找出长短边，长边分四份，短边分三份
            double Line1, Line2;
            Line1 = scr[0].b[1] - scr[0].a[1];
            Line2 = scr[0].b[2] - scr[0].a[2];
            //dMaxInterval = scr[0].b[1] - scr[0].a[1];
            if(Line1 > Line2)
            {
                dim[1] = 1;dim[2] = 2;
            }
            else
            {
                dim[1] = 2; dim[2] = 1;
            }
            a[dim[1]] = scr[0].a[dim[1]];
            d[dim[1]] = (scr[0].b[dim[1]] - scr[0].a[dim[1]]) / 4;  //最大边分为4份
            a[dim[2]] = scr[0].a[dim[2]];
            d[dim[2]] = (scr[0].b[dim[2]] - scr[0].a[dim[2]]) / 3;   //第二条边分成3份
           
            //labelRect.Text += "\nLong edge:" + d[dim[1]] * 4 + "---Short edge:" + d[dim[2]] * 3;

            for (i = 1; i <= 3; i++)
            {
                for (j = 1; j <= 4; j++)
                {
                    for (k = 1; k <= n; k++)
                    {
                        switch (k)
                        {
                            case 1:
                                {
                                    alfa = i - 1;
                                    break;
                                }
                            case 2:
                                {
                                    alfa = j - 1;
                                    break;
                                }
                        }
                        part[(i - 1) * 4 + j].a[k] = a[k] + alfa * d[k];
                        part[(i - 1) * 4 + j].b[k] = a[k] + alfa * d[k] + d[k];
                    }
                }
            }

            for (m = 1; m <= 12; m++)
            {
                for (j = 0; j < COL_NUM; j++)
                {
                    midRectNode[m].a[j] = part[m].a[j + 1];
                    midRectNode[m].b[j] = part[m].b[j + 1];
                }
            }

            //第一条线分割
            double d41 = d[dim[1]] + midRectNode[0].a[dim[1] - 1];                
            double d42 = d[dim[1]] * 2 + midRectNode[0].a[dim[1] - 1];
            double d43 = d[dim[1]] * 3 + midRectNode[0].a[dim[1] - 1];
            double d44 = midRectNode[0].b[dim[1] - 1];
            //第二条线分割
            double d31 = d[dim[2]] + midRectNode[0].a[dim[2] - 1];                                    
            double d32 = d[dim[2]] * 2 + midRectNode[0].a[dim[2] - 1];
            double d33 = midRectNode[0].b[dim[2] - 1];

            //labelRect.Text += "\nDivided long edge:" + Convert.ToInt32(d41) + "---" + Convert.ToInt32(d42) + "---" + Convert.ToInt32(d43) + "---" + Convert.ToInt32(d44);
            //labelRect.Text += "\nDivided short edge:" + Convert.ToInt32(d31) + "---" + Convert.ToInt32(d32) + "---" + Convert.ToInt32(d33) ;
            //MessageBox.Show(labelRect.Text);
            int num1 = 0;            int num2 = 0;            int num3 = 0;            int num4 = 0;            int num5 = 0;            int num6 = 0;
            int num7 = 0;            int num8 = 0;            int num9 = 0;            int num10 = 0;          int num11 = 0;          int num12 = 0;

            int d1 = dim[1] - 1;//最长边
            int d2 = dim[2] - 1;//            

            for (m = 0; m < midRectNode[0].count; m++) //切成12块儿
            {
                if (Rect[m].x[d1] <= d41)// 00-41
                {
                    if (Rect[m].x[d2] <= d31)// 00-31
                    {
                        midRectNode[1].count++;      //计算第一块(00-41 , 00-31)中含有的元组个数
                        midRectNode[1].node[num1] = new NODE(); //循环外初始化才可以！！！Bug Fixed by LiuHB 2018.7.24.
                        for (int y = 0; y < COL_NUM; y++)       //放入第1块中的元组
                        {                            
                            midRectNode[1].node[num1].x[y] = Rect[m].x[y];// 此处，赋值，node.x = 1,2 丢失。Bug Find by LuWP 2018.7.24.
                        }
                        //midRectNode[1].nodeId += Rect[m].ID.ToString()+";";//放入第1块的各元组的ID集合
                        num1++;
                        midRectNode[1].count = num1;//统计放入第1块的元组ID数
                        //MessageBox.Show(midRectNode[1].nodeId);
                    }
                    else if (Rect[m].x[d2] <= d32 && Rect[m].x[d2] > d31)
                    {
                        midRectNode[5].count++;      //计算第7块中元组数目
                        midRectNode[5].node[num5] = new NODE();
                        for (int y = 0; y < COL_NUM; y++)       //放入第5块中的元组
                        {
                            midRectNode[5].node[num5].x[y] = Rect[m].x[y];
                        }
                        //midRectNode[5].node[num5].ID = Rect[m].ID;
                        //midRectNode[5].nodeId += Rect[m].ID.ToString() + ";";
                        num5++;
                        midRectNode[5].count = num5;
                        //MessageBox.Show(midRectNode[5].nodeId);
                    }
                    else //if (Rect[m].x[d2] <= d33 && Rect[m].x[d2] > d32)
                    {
                        midRectNode[9].count++;      //计算第7块中元组数目
                        midRectNode[9].node[num9] = new NODE();
                        for (int y = 0; y < COL_NUM; y++)       //放入第9块中的元组
                        {                            
                            midRectNode[9].node[num9].x[y] = Rect[m].x[y];
                        }
                        //midRectNode[9].node[num9].ID = Rect[m].ID;
                        //midRectNode[9].nodeId += Rect[m].ID.ToString() + ";";
                        num9++;
                        midRectNode[9].count = num9;
                    }
                }

                if (Rect[m].x[d1] > d41 && Rect[m].x[d1] <= d42)
                {
                    if (Rect[m].x[d2] <= d31)
                    {
                        midRectNode[2].count++;      //计算第2块中元组数目
                        midRectNode[2].node[num2] = new NODE();
                        for (int y = 0; y < COL_NUM; y++)       //放入第1块中的元组
                        {
                            
                            midRectNode[2].node[num2].x[y] = Rect[m].x[y];
                        }
                        //midRectNode[2].node[num2].ID = Rect[m].ID;
                        //midRectNode[2].nodeId += Rect[m].ID.ToString() + ";";
                        num2++;
                        midRectNode[2].count = num2;
                    }
                    else if (Rect[m].x[d2] <= d32 && Rect[m].x[d2] > d31)
                    {
                        midRectNode[6].count++;      //计算第6块中元组数目
                        midRectNode[6].node[num6] = new NODE();
                        for (int y = 0; y < COL_NUM; y++)       //放入第5块中的元组
                        {
                            
                            midRectNode[6].node[num6].x[y] = Rect[m].x[y];
                        }
                        //midRectNode[6].node[num6].ID = Rect[m].ID;
                        //midRectNode[6].nodeId += Rect[m].ID.ToString() + ";";
                        num6++;
                        midRectNode[6].count = num6;
                    }
                    else //if (Rect[m].x[d2] <= d33 && Rect[m].x[d2] > d32)
                    {
                        midRectNode[10].count++;      //计算第10块中元组数目
                        midRectNode[10].node[num10] = new NODE();
                        for (int y = 0; y < COL_NUM; y++)       //放入第9块中的元组
                        {
                            
                            midRectNode[10].node[num10].x[y] = Rect[m].x[y];
                        }
                        //midRectNode[10].node[num10].ID = Rect[m].ID;
                        //midRectNode[10].nodeId += Rect[m].ID.ToString() + ";";
                        num10++;
                        midRectNode[10].count = num10;
                    }
                }

                if (Rect[m].x[d1] > d42 && Rect[m].x[d1] <= d43)
                {
                    if (Rect[m].x[d2] <= d31)
                    {
                        midRectNode[3].count++;      //计算第一块中元组数目
                        midRectNode[3].node[num3] = new NODE();
                        for (int y = 0; y < COL_NUM; y++)       //放入第3块中的元组
                        {
                            
                            midRectNode[3].node[num3].x[y] = Rect[m].x[y];
                        }
                        //midRectNode[3].node[num3].ID = Rect[m].ID;
                        //midRectNode[3].nodeId += Rect[m].ID.ToString() + ";";
                        num3++;
                        midRectNode[3].count = num3;
                    }
                    else if (Rect[m].x[d2] <= d32 && Rect[m].x[d2] > d31)
                    {
                        midRectNode[7].count++;      //计算第7块中元组数目
                        midRectNode[7].node[num7] = new NODE();
                        for (int y = 0; y < COL_NUM; y++)       //放入第7块中的元组
                        {
                            
                            midRectNode[7].node[num7].x[y] = Rect[m].x[y];
                        }
                        //midRectNode[7].node[num7].ID = Rect[m].ID;
                        //midRectNode[7].nodeId += Rect[m].ID.ToString() + ";";
                        num7++;
                        midRectNode[7].count = num7;
                    }
                    else //if (Rect[m].x[d2] <= d33 && Rect[m].x[d2] > d32)
                    {
                        midRectNode[11].count++;      //计算第11块中元组数目
                        midRectNode[11].node[num11] = new NODE();
                        for (int y = 0; y < COL_NUM; y++)       //放入第9块中的元组
                        {
                           
                            midRectNode[11].node[num11].x[y] = Rect[m].x[y];
                        }
                        //midRectNode[11].node[num11].ID = Rect[m].ID;
                        //midRectNode[11].nodeId += Rect[m].ID.ToString() + ";";
                        num11++;
                        midRectNode[11].count = num11;
                    }
                }

                if (Rect[m].x[d1] > d43)
                {
                    if (Rect[m].x[d2] <= d31)
                    {
                        midRectNode[4].count++;      //计算第4块中元组数目
                        midRectNode[4].node[num4] = new NODE();
                        for (int y = 0; y < COL_NUM; y++)       //放入第1块中的元组
                        {
                            
                            midRectNode[4].node[num4].x[y] = Rect[m].x[y];
                        }
                        //midRectNode[4].node[num4].ID = Rect[m].ID;
                        //midRectNode[1].nodeId += Rect[m].ID.ToString() + ";";
                        num4++;
                        midRectNode[4].count = num4;
                    }
                    else if (Rect[m].x[d2] <= d32 && Rect[m].x[d2] > d31)
                    {
                        midRectNode[8].count++;      //计算第7块中元组数目
                        midRectNode[8].node[num8] = new NODE();
                        for (int y = 0; y < COL_NUM; y++)       //放入第8块中的元组
                        {
                           
                            midRectNode[8].node[num8].x[y] = Rect[m].x[y];
                        }
                        //midRectNode[8].node[num8].ID = Rect[m].ID;
                        //midRectNode[8].nodeId += Rect[m].ID.ToString() + ";";
                        num8++;
                        midRectNode[8].count = num8;
                    }
                    else //if (Rect[m].x[d2] <= d33 && Rect[m].x[d2] > d32)
                    {
                        midRectNode[12].count++;      //计算第7块中元组数目
                        midRectNode[12].node[num12] = new NODE();
                        for (int y = 0; y < COL_NUM; y++)       //放入第12块中的元组
                        {
                            
                            midRectNode[12].node[num12].x[y] = Rect[m].x[y];
                        }
                        //midRectNode[12].node[num12].ID = Rect[m].ID;
                        //midRectNode[12].nodeId += Rect[m].ID.ToString() + ";";
                        num12++;
                        midRectNode[12].count = num12;
                    }
                }
            }

            #region Count = ZERO
            if (num1 == 0)
            {
                midRectNode[1].count = 0;
            }
            if (num2 == 0)
            {
                midRectNode[2].count = 0;
            }
            if (num3 == 0)
            {
                midRectNode[3].count = 0;
            }
            if (num4 == 0)
            {
                midRectNode[4].count = 0;
            }
            if (num5 == 0)
            {
                midRectNode[5].count = 0;
            }
            if (num6 == 0)
            {
                midRectNode[6].count = 0;
            }
            if (num7 == 0)
            {
                midRectNode[7].count = 0;
            }
            if (num8 == 0)
            {
                midRectNode[8].count = 0;
            }
            if (num9 == 0)
            {
                midRectNode[9].count = 0;
            }
            if (num10 == 0)
            {
                midRectNode[10].count = 0;
            }
            if (num11 == 0)
            {
                midRectNode[11].count = 0;
            }
            if (num12 == 0)
            {
                midRectNode[12].count = 0;
            }
            #endregion
            //若num=0的时候需要判断,给midRectNode[i].count=0;
            int sumNumber = num1 + num2 + num3 + num4 + num5 + num6 + num7 + num8 + num9 + num10 + num11 + num12;

            return PartNum;
        }

        //For 2D 块中为空
        int zlPartionpa2_empty(ZLRECT[] Rect, int Dimention, int T_Num, int PartNum)
        {
            int n = Dimention, m = T_Num;
            int h, i, j, k, idx;
            bool bInterable = false;
            string cstrMarc;
            ZLRECT[] part = new ZLRECT[13];
            for (int iii = 0; iii < 13; iii++)
            {
                part[iii] = new ZLRECT();
            }
            //ZLRECT[] scr = new ZLRECT[iSizeofDataSetTable];
            ZLRECT[] scr;
            int[] dim = new int[3]; //dim[1], [2], [3] are the biggest value of all dimensens
            double dMaxInterval = 0.0;

            scr = Rect;

           // if (Rect.Length < 12 && Rect.Length > 0) return 0; // Help by BoboLiu . 2018.7.23

            for (i = 0; i < 12; i++)
            {
                for (int jjj = 0; jjj < COL_NUM; jjj++)
                {
                    part[i].a[jjj] = Rect[0].a[jjj];
                    part[i].b[jjj] = Rect[0].b[jjj];
                    part[i].count = Rect[0].count;
                }
            }
            for (j = 12; j > 0; j--)
            {
                part[j] = part[j - 1];
            }

            double[] a = new double[n + 1];
            double[] d = new double[n + 1];
            int alfa = 0;

            // For 2D, 找出长短边，长边分四份，短边分三份
            double Line1, Line2;
            Line1 = scr[0].b[1] - scr[0].a[1];
            Line2 = scr[0].b[2] - scr[0].a[2];
            //dMaxInterval = scr[0].b[1] - scr[0].a[1];
            if (Line1 > Line2)
            {
                dim[1] = 1; dim[2] = 2;
            }
            else
            {
                dim[1] = 2; dim[2] = 1;
            }
            a[dim[1]] = scr[0].a[dim[1]];
            d[dim[1]] = (scr[0].b[dim[1]] - scr[0].a[dim[1]]) / 4;  //最大边分为4份
            a[dim[2]] = scr[0].a[dim[2]];
            d[dim[2]] = (scr[0].b[dim[2]] - scr[0].a[dim[2]]) / 3;   //第二条边分成3份

            for (i = 1; i <= 3; i++)
            {
                for (j = 1; j <= 4; j++)
                {
                    for (k = 1; k <= n; k++)
                    {
                        switch (k)
                        {
                            case 1:
                                {
                                    alfa = i - 1;
                                    break;
                                }
                            case 2:
                                {
                                    alfa = j - 1;
                                    break;
                                }

                        }
                        part[(i - 1) * 4 + j].a[k] = a[k] + alfa * d[k];
                        part[(i - 1) * 4 + j].b[k] = a[k] + alfa * d[k] + d[k];
                    }
                }
            }



            for (int mi = 1; mi <= 12; mi++)
            {
                for (int jj = 0; jj < COL_NUM; jj++)
                {
                    midRectNode[mi].a[jj] = part[mi].a[jj + 1];
                    midRectNode[mi].b[jj] = part[mi].b[jj + 1];
                }

                midRectNode[mi].count = 0;
            }
            return 0;
        }

        //For 3D
        int zlPartion3DLu(ZLRECT[] Rect, int Dimention, int T_Num, int PartNum)
        {
            int n = Dimention, m = T_Num;
            int h, i, j, k, idx;
            bool bInterable = false;
            string cstrMarc;
            ZLRECT[] part = new ZLRECT[13];
            for (int iii = 0; iii < 13; iii++)
            {
                part[iii] = new ZLRECT();
            }
            ZLRECT[] scr;
            int[] dim = new int[4];
            double dMaxInterval = 0.0;
            scr = Rect;
            for (i = 0; i < 12; i++)
            {
                for (int jjj = 0; jjj < COL_NUM; jjj++)
                {
                    part[i].a[jjj] = Rect[0].a[jjj]; //Fixed by LuWP . 2018.7.23
                    part[i].b[jjj] = Rect[0].b[jjj];
                    part[i].count = Rect[0].count;
                }

            }
            for (j = 12; j > 0; j--)
            {
                part[j] = part[j - 1];
            }

            double[] a = new double[n + 1];
            double[] d = new double[n + 1];
            int alfa = 0;

            // For 3D, 找出最长边，分三份；其余两条边分两份
            // search NO1 dimension
            dMaxInterval = scr[0].b[1] - scr[0].a[1];
            dim[1] = 1;
            for (i = 2; i <= n; i++)
                {
                    if (dMaxInterval < scr[0].b[i] - scr[0].a[i])
                    {
                        dMaxInterval = scr[0].b[i] - scr[0].a[i];    //找最大边
                        dim[1] = i;             //最大边所在的列
                    }
                }

             a[dim[1]] = scr[0].a[dim[1]];
             d[dim[1]] = (scr[0].b[dim[1]] - scr[0].a[dim[1]]) / 3;  //最大边分为三份

             // search NO2 dimension
                if (dim[1] != 1)
                {
                    dMaxInterval = scr[0].b[1] - scr[0].a[1];
                    dim[2] = 1;
                }
                else
                {
                    dMaxInterval = scr[0].b[2] - scr[0].a[2];
                    dim[2] = 2;
                }

                for (i = 1; i <= n; i++)
                {
                    if (i != dim[1])
                    {
                        if (dMaxInterval < scr[0].b[i] - scr[0].a[i])
                        {
                            dMaxInterval = scr[0].b[i] - scr[0].a[i];
                            dim[2] = i;
                        }
                    }
                }

                a[dim[2]] = scr[0].a[dim[2]];
                d[dim[2]] = (scr[0].b[dim[2]] - scr[0].a[dim[2]]) / 2;

                // search NO3 dimension
                for (i = 1; i <= n; i++)
                {
                    if (dim[1] != i && dim[2] != i)
                    {
                        dMaxInterval = scr[0].b[i] - scr[0].a[i];
                        dim[3] = i;     //第三条边所在列
                    }

                }

                for (i = 1; i <= n; i++)
                {
                    if (i != dim[1] && i != dim[2])
                    {
                        if (dMaxInterval < scr[0].b[i] - scr[0].a[i])
                        {
                            dMaxInterval = scr[0].b[i] - scr[0].a[i];
                            dim[3] = i;
                        }
                    }
                }

                a[dim[3]] = scr[0].a[dim[3]];
                d[dim[3]] = (scr[0].b[dim[3]] - scr[0].a[dim[3]]) / 2;

                for (k = 1; k <= 2; k++)   //分成十二分
                {
                    for (j = 1; j <= 2; j++)
                    {
                        for (i = 1; i <= 3; i++)
                        {
                            //sprintf(temp, " , %02i", i+3*(j-1) + 6*(k-1) );
                            //str += temp;
                            for (h = 1; h <= 3; h++) //the Number of dimensions: NO1, NO2, NO3
                            {
                                if (dim[h] == dim[1])
                                {
                                    part[i + 3 * (j - 1) + 6 * (k - 1)].a[dim[1]] = a[dim[1]] + (i - 1) * d[dim[1]];
                                    part[i + 3 * (j - 1) + 6 * (k - 1)].b[dim[1]] = a[dim[1]] + i * d[dim[1]];

                                }
                                else if (dim[h] == dim[2])
                                {
                                    part[i + 3 * (j - 1) + 6 * (k - 1)].a[dim[2]] = a[dim[2]] + (j - 1) * d[dim[2]];
                                    part[i + 3 * (j - 1) + 6 * (k - 1)].b[dim[2]] = a[dim[2]] + j * d[dim[2]];
                                }
                                else if (dim[h] == dim[3])
                                {
                                    part[i + 3 * (j - 1) + 6 * (k - 1)].a[dim[3]] = a[dim[3]] + (k - 1) * d[dim[3]];
                                    part[i + 3 * (j - 1) + 6 * (k - 1)].b[dim[3]] = a[dim[3]] + k * d[dim[3]];
                                }
                            }
                        }
                    }
                }

                for (m = 1; m <= 12; m++)
                {
                    for (j = 0; j < COL_NUM; j++)
                    {
                        midRectNode[m].a[j] = part[m].a[j + 1];
                        midRectNode[m].b[j] = part[m].b[j + 1];
                    }
                }

                double d31 = d[dim[1]] + midRectNode[0].a[dim[1] - 1];                //第一条线分割
                double d32 = d[dim[1]] * 2 + midRectNode[0].a[dim[1] - 1];
                double d33 = midRectNode[0].b[dim[1] - 1];

                double d21 = d[dim[2]] + midRectNode[0].a[dim[2] - 1];                                    //第二条线分割
                double d22 = midRectNode[0].b[dim[2] - 1];

                double dd21 = d[dim[3]] + midRectNode[0].a[dim[3] - 1];                                    //第三条线分割
                double ddd21 = midRectNode[0].b[dim[3] - 1];

                int num1 = 0;
                int num2 = 0;
                int num3 = 0;
                int num4 = 0;
                int num5 = 0;
                int num6 = 0;
                int num7 = 0;
                int num8 = 0;
                int num9 = 0;
                int num10 = 0;
                int num11 = 0;
                int num12 = 0;

                int d1 = dim[1] - 1;//最长边
                int d2 = dim[2] - 1;//
                int d3 = dim[3] - 1;

                for (m = 0; m < midRectNode[0].count; m++)
                {
                    if (Rect[m].x[d1] <= d31)
                    {
                        if (Rect[m].x[d2] <= d21)
                        {
                            if (Rect[m].x[d3] <= dd21)
                            {
                                midRectNode[1].count++;      //计算第一块中元组数目
                                midRectNode[1].node[num1] = new NODE();
                                for (int y = 0; y < COL_NUM; y++)       //放入第一块中的元组
                                {
                                    midRectNode[1].node[num1].x[y] = Rect[m].x[y];
                                }
                                //midRectNode[1].node[num1].ID = Rect[m].ID;
                                num1++;
                                midRectNode[1].count = num1;
                            }
                            else
                            {
                                midRectNode[7].count++;      //计算第7块中元组数目
                            midRectNode[7].node[num7] = new NODE();
                            for (int y = 0; y < COL_NUM; y++)       //放入第7块中的元组
                                {
                                    midRectNode[7].node[num7].x[y] = Rect[m].x[y];
                                }
                               // midRectNode[7].node[num7].ID = Rect[m].ID;
                                num7++;
                                midRectNode[7].count = num7;
                            }
                        }
                        else
                        {
                            if (Rect[m].x[d3] <= dd21)
                            {
                                midRectNode[4].count++;      //计算第四块中元组数目
                            midRectNode[4].node[num4] = new NODE();
                            for (int y = 0; y < COL_NUM; y++)       //放入第4块中的元组
                                {
                                    midRectNode[4].node[num4].x[y] = Rect[m].x[y];
                                }
                                //midRectNode[4].node[num4].ID = Rect[m].ID;
                                num4++;
                                midRectNode[4].count = num4;

                            }
                            else
                            {
                                midRectNode[10].count++;      //计算第10块中元组数目
                            midRectNode[10].node[num10] = new NODE();
                            for (int y = 0; y < COL_NUM; y++)       //放入第10块中的元组
                                {
                                    midRectNode[10].node[num10].x[y] = Rect[m].x[y];
                                }
                                //midRectNode[10].node[num10].ID = Rect[m].ID;
                                num10++;
                                midRectNode[10].count = num10;
                            }
                        }
                    }

                    //--------------------
                    if (Rect[m].x[d1] > d31 && Rect[m].x[d1] <= d32)
                    {
                        if (Rect[m].x[d2] <= d21)
                        {
                            if (Rect[m].x[d3] <= dd21)
                            {
                                midRectNode[2].count++;      //计算第二块中元组数目
                            midRectNode[2].node[num2] = new NODE();
                            for (int y = 0; y < COL_NUM; y++)       //放入第2块中的元组
                                {
                                    midRectNode[2].node[num2].x[y] = Rect[m].x[y];
                                }
                                //midRectNode[2].node[num2].ID = Rect[m].ID;
                                num2++;
                                midRectNode[2].count = num2;
                            }
                            else
                            {
                                midRectNode[8].count++;      //计算第8块中元组数目
                            midRectNode[8].node[num8] = new NODE();
                            for (int y = 0; y < COL_NUM; y++)       //放入第8块中的元组
                                {
                                    midRectNode[8].node[num8].x[y] = Rect[m].x[y];
                                }
                             //   midRectNode[8].node[num8].ID = Rect[m].ID;
                                num8++;
                                midRectNode[8].count = num8;
                            }
                        }
                        else
                        {
                            if (Rect[m].x[d3] <= dd21)
                            {
                                midRectNode[5].count++;      //计算第5块中元组数目
                            midRectNode[5].node[num5] = new NODE();
                            for (int y = 0; y < COL_NUM; y++)       //放入第5块中的元组
                                {
                                    midRectNode[5].node[num5].x[y] = Rect[m].x[y];
                                }
                              //  midRectNode[5].node[num5].ID = Rect[m].ID;
                                num5++;
                                midRectNode[5].count = num5;
                            }
                            else
                            {
                                midRectNode[11].count++;      //计算第11块中元组数目
                            midRectNode[11].node[num11] = new NODE();
                            for (int y = 0; y < COL_NUM; y++)       //放入第11块中的元组
                                {
                                    midRectNode[11].node[num11].x[y] = Rect[m].x[y];
                                }
                               // midRectNode[11].node[num11].ID = Rect[m].ID;
                                num11++;
                                midRectNode[11].count = num11;
                            }
                        }
                    }
                    //--------------------

                    if (Rect[m].x[d1] > d32 && Rect[m].x[d1] <= d33)
                    {
                        if (Rect[m].x[d2] <= d21)
                        {
                            if (Rect[m].x[d3] <= dd21)
                            {
                                midRectNode[3].count++;      //计算第三块中元组数目
                            midRectNode[3].node[num3] = new NODE();
                            for (int y = 0; y < COL_NUM; y++)       //放入第3块中的元组
                                {
                                    midRectNode[3].node[num3].x[y] = Rect[m].x[y];
                                }
                            //    midRectNode[3].node[num3].ID = Rect[m].ID;
                                num3++;
                                midRectNode[3].count = num3;
                            }
                            else
                            {
                                midRectNode[9].count++;      //计算第9块中元组数目
                            midRectNode[9].node[num9] = new NODE();
                            for (int y = 0; y < COL_NUM; y++)       //放入第9块中的元组
                                {
                                    midRectNode[9].node[num9].x[y] = Rect[m].x[y];
                                }
                             //   midRectNode[9].node[num9].ID = Rect[m].ID;
                                num9++;
                                midRectNode[9].count = num9;
                            }
                        }
                        else
                        {
                            if (Rect[m].x[d3] <= dd21)
                            {
                                midRectNode[6].count++;      //计算第6块中元组数目
                            midRectNode[6].node[num6] = new NODE();
                            for (int y = 0; y < COL_NUM; y++)       //放入第6块中的元组
                                {
                                    midRectNode[6].node[num6].x[y] = Rect[m].x[y];
                                }
                               // midRectNode[6].node[num6].ID = Rect[m].ID;
                                num6++;
                                midRectNode[6].count = num6;
                            }
                            else
                            {
                                midRectNode[12].count++;      //计算第12块中元组数目
                            midRectNode[12].node[num12] = new NODE();
                            for (int y = 0; y < COL_NUM; y++)       //放入第12块中的元组
                                {
                                    midRectNode[12].node[num12].x[y] = Rect[m].x[y];
                                }
                              //  midRectNode[12].node[num12].ID = Rect[m].ID;
                                num12++;
                                midRectNode[12].count = num12;
                            }
                        }

                    }
                }

                if (num1 == 0)
                {
                    midRectNode[1].count = 0;
                }
                if (num2 == 0)
                {
                    midRectNode[2].count = 0;
                }
                if (num3 == 0)
                {
                    midRectNode[3].count = 0;
                }
                if (num4 == 0)
                {
                    midRectNode[4].count = 0;
                }
                if (num5 == 0)
                {
                    midRectNode[5].count = 0;
                }
                if (num6 == 0)
                {
                    midRectNode[6].count = 0;
                }
                if (num7 == 0)
                {
                    midRectNode[7].count = 0;
                }
                if (num8 == 0)
                {
                    midRectNode[8].count = 0;
                }
                if (num9 == 0)
                {
                    midRectNode[9].count = 0;
                }
                if (num10 == 0)
                {
                    midRectNode[10].count = 0;
                }
                if (num11 == 0)
                {
                    midRectNode[11].count = 0;
                }
                if (num12 == 0)
                {
                    midRectNode[12].count = 0;
                }




                //若num=0的时候需要判断,给midRectNode[i].count=0;
                int sumNumber = num1 + num2 + num3 + num4 + num5 + num6 + num7 + num8 + num9 + num10 + num11 + num12;


                ///=================================================
                return PartNum;

        }

        //For 3D 块中为空
        int zlPartion3DLuPa(ZLRECT[] Rect, int Dimention, int T_Num, int PartNum)
        {
            int n = Dimention, m = T_Num;
            int h, i, j, k, idx;
            bool bInterable = false;
            string cstrMarc;
            ZLRECT[] part = new ZLRECT[13];
            for (int iii = 0; iii < 13; iii++)
            {
                part[iii] = new ZLRECT();
            }
            ZLRECT[] scr;
            int[] dim = new int[4];
            double dMaxInterval = 0.0;
            scr = Rect;
            for (i = 0; i < 12; i++)
            {
                for (int jjj = 0; jjj < COL_NUM; jjj++)
                {
                    part[i].a[jjj] = Rect[0].a[jjj]; //Fixed by LuWP . 2018.7.23
                    part[i].b[jjj] = Rect[0].b[jjj];
                    part[i].count = Rect[0].count;
                }

            }
            for (j = 12; j > 0; j--)
            {
                part[j] = part[j - 1];
            }

            double[] a = new double[n + 1];
            double[] d = new double[n + 1];
            int alfa = 0;

            // For 3D, 找出最长边，分三份；其余两条边分两份
            // search NO1 dimension
            dMaxInterval = scr[0].b[1] - scr[0].a[1];
            dim[1] = 1;
            for (i = 2; i <= n; i++)
            {
                if (dMaxInterval < scr[0].b[i] - scr[0].a[i])
                {
                    dMaxInterval = scr[0].b[i] - scr[0].a[i];    //找最大边
                    dim[1] = i;             //最大边所在的列
                }
            }

            a[dim[1]] = scr[0].a[dim[1]];
            d[dim[1]] = (scr[0].b[dim[1]] - scr[0].a[dim[1]]) / 3;  //最大边分为三份

            // search NO2 dimension
            if (dim[1] != 1)
            {
                dMaxInterval = scr[0].b[1] - scr[0].a[1];
                dim[2] = 1;
            }
            else
            {
                dMaxInterval = scr[0].b[2] - scr[0].a[2];
                dim[2] = 2;
            }

            for (i = 1; i <= n; i++)
            {
                if (i != dim[1])
                {
                    if (dMaxInterval < scr[0].b[i] - scr[0].a[i])
                    {
                        dMaxInterval = scr[0].b[i] - scr[0].a[i];
                        dim[2] = i;
                    }
                }
            }

            a[dim[2]] = scr[0].a[dim[2]];
            d[dim[2]] = (scr[0].b[dim[2]] - scr[0].a[dim[2]]) / 2;

            // search NO3 dimension
            for (i = 1; i <= n; i++)
            {
                if (dim[1] != i && dim[2] != i)
                {
                    dMaxInterval = scr[0].b[i] - scr[0].a[i];
                    dim[3] = i;     //第三条边所在列
                }

            }

            for (i = 1; i <= n; i++)
            {
                if (i != dim[1] && i != dim[2])
                {
                    if (dMaxInterval < scr[0].b[i] - scr[0].a[i])
                    {
                        dMaxInterval = scr[0].b[i] - scr[0].a[i];
                        dim[3] = i;
                    }
                }
            }

            a[dim[3]] = scr[0].a[dim[3]];
            d[dim[3]] = (scr[0].b[dim[3]] - scr[0].a[dim[3]]) / 2;

            for (k = 1; k <= 2; k++)   //分成十二分
            {
                for (j = 1; j <= 2; j++)
                {
                    for (i = 1; i <= 3; i++)
                    {
                        //sprintf(temp, " , %02i", i+3*(j-1) + 6*(k-1) );
                        //str += temp;
                        for (h = 1; h <= 3; h++) //the Number of dimensions: NO1, NO2, NO3
                        {
                            if (dim[h] == dim[1])
                            {
                                part[i + 3 * (j - 1) + 6 * (k - 1)].a[dim[1]] = a[dim[1]] + (i - 1) * d[dim[1]];
                                part[i + 3 * (j - 1) + 6 * (k - 1)].b[dim[1]] = a[dim[1]] + i * d[dim[1]];

                            }
                            else if (dim[h] == dim[2])
                            {
                                part[i + 3 * (j - 1) + 6 * (k - 1)].a[dim[2]] = a[dim[2]] + (j - 1) * d[dim[2]];
                                part[i + 3 * (j - 1) + 6 * (k - 1)].b[dim[2]] = a[dim[2]] + j * d[dim[2]];
                            }
                            else if (dim[h] == dim[3])
                            {
                                part[i + 3 * (j - 1) + 6 * (k - 1)].a[dim[3]] = a[dim[3]] + (k - 1) * d[dim[3]];
                                part[i + 3 * (j - 1) + 6 * (k - 1)].b[dim[3]] = a[dim[3]] + k * d[dim[3]];
                            }
                        }
                    }
                }
            }

            for (m = 1; m <= 12; m++)
            {
                for (j = 0; j < COL_NUM; j++)
                {
                    midRectNode[m].a[j] = part[m].a[j + 1];
                    midRectNode[m].b[j] = part[m].b[j + 1];
                }
                midRectNode[m].count = 0;
            }
            return 0;
        }

        //Remove duplicated data
        void DupRemove(ZLRECT[] lurect)
        {
            int Cluster_lIdx = 0;
            //int itplIdx = 0;          // count for have been seen tuples, i.e., tpl[]	 
            //int iTopN = lurect[1].count;
            int i, j, k, k1;
            luTUPLE tt;
            int itplIdx = 0;

            for (int e = 1; e <= 1728; e++)
            {
                itplIdx = 0;
                if (lurect[e].count == 0)
                {
                    //LRect4[e].count = 0;
                    LRect4[e].spaceSize = 0;
                    continue;
                }
                else
                {                   
                    int iTopN = lurect[e].count; // count for have been seen tuples, i.e., tpl[]	
                    lutpl = new luTUPLE[lurect[e].count];   //candidate tuples for tpl[].bOK = true//iSizeofDataSetTable + 1

                    for (i = 0; i < (lurect[e].count); i++)         //干净数据集初始化为0
                    {
                        memset(&lutpl[i], 0, sizeof(luTUPLE));
                    }

                    for (int m = 0; m < lurect[e].count; m++)
                    {
                        for (int q = 0; q < COL_NUM; q++)      //将一条数据数据复制给tt
                        {
                            tt.x[q] = lurect[e].node[m].x[q];
                        }
                        tt.ID = lurect[e].node[m].ID;

                        bool jug = true;          //初始化为true

                        if (itplIdx == 0)           //干净数据集中没有数据时直接插入
                        {
                            lutpl[0] = tt;
                            lutpl[0].Tnum = 1;
                            lutpl[0].Tid[0] = tt.ID;
                            itplIdx++;
                            continue;
                        }
                        for (k = 0; k < itplIdx; k++)  //找到tpl[k].d>tt.d位置 
                        {
                            if (lutpl[k].x[0] > tt.x[0])                   ////=============================
                                break;
                        }
                        for (int k1 = k - 1; k1 >= 0; k1--)//向上遍历看是否存在和tt相同的点
                        {
                            if (lutpl[k1].x[0] == tt.x[0])//如果点的距离相等那么比较点的坐标 ////=============================
                            {
                                int a;
                                for (a = 1; a < COL_NUM; a++)
                                {
                                    if (lutpl[k1].x[a] != tt.x[a])
                                        break;
                                }
                                if (a == COL_NUM)
                                {
                                    jug = false;
                                    Cluster_lIdx = lutpl[k1].ID;
                                    break;
                                }
                            }
                            else
                            {
                                break;
                            }
                        }
                        if (jug)//没有相同的点，然后直接插入
                        {
                            for (int k1 = itplIdx; k1 > k; k1--)
                            {
                                lutpl[k1] = lutpl[k1 - 1];
                            }
                            lutpl[k] = tt;
                            //tpl[k].Tnum=1;
                            //tpl[k].Tid[0]=tt.ID;
                            lutpl[k].Tnum = 1;
                            lutpl[k].Tid[0] = tt.ID;
                            itplIdx++;
                            //iTopN--;
                        }
                        if (!jug)
                        {
                            for (int i = 0; i < itplIdx; i++)
                            {
                                if (lutpl[i].ID == Cluster_lIdx)
                                {
                                    lutpl[i].Tnum++;
                                    lutpl[i].Tid[lutpl[i].Tnum - 1] = tt.ID;
                                }
                            }
                        }
                    }
                    //-------------------------------------------
                    LRect4[e].clTuplu = new luTUPLE[itplIdx];
                    LRect4[e].spaceSize = itplIdx;
                    for (int p = 0; p < itplIdx; p++)
                    {
                        LRect4[e].clTuplu[p] = lutpl[p];
                    }
                    LRect4[e].count = itplIdx;
                }
            }
        }



        int DavidSelect(string sql)
        {
            String conn = ConfigurationManager.ConnectionStrings["myconn"].ConnectionString;
            SqlConnection sqlConnection = new SqlConnection(conn);  //实例化连接对象
            int result=0;
            sqlConnection.Open();
            SqlCommand sqlCommandMax = new SqlCommand(sql, sqlConnection);
            SqlDataReader sqlDataReaderMax = sqlCommandMax.ExecuteReader();
            while (sqlDataReaderMax.Read())
                result = Convert.ToInt32( sqlDataReaderMax[0]);
            sqlConnection.Close();
            return result;

        }
        
        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            //comboBox2.SelectedIndex = comboBox1.SelectedIndex;
            //comboBox3.SelectedIndex = comboBox1.SelectedIndex;       
            //comboBox4.SelectedIndex = comboBox1.SelectedIndex;
            //comboBox5.SelectedIndex = comboBox1.SelectedIndex;
            //comboBox6.SelectedIndex = comboBox1.SelectedIndex;
        }

        private void buttonClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            String conn = ConfigurationManager.ConnectionStrings["myconn"].ConnectionString;
            SqlConnection sqlConnection = new SqlConnection(conn);  //实例化连接对象
            try
            {
                sqlConnection.Open();
                if (sqlConnection.State == ConnectionState.Open)
                {
                    MessageBox.Show("数据库连接成功:\n" + conn);
                }
                else
                {
                    MessageBox.Show("连接失败！，请配置App.config文件的connectionStrings！");
                }
            }
            catch
            {
                MessageBox.Show("连接失败！，请配置App.config文件的connectionStrings！");
            }
            finally
            {
                sqlConnection.Close();
            }
        }

    }
}
