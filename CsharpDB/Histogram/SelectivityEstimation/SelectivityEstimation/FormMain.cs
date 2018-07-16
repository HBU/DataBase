using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SelectivityEstimation
{
       public partial class FormMain : Form
    {
        static int COL_NUM ;//3 //4 //50 //25 //2 -- //3 //4 //25 //--//4 //104 //3 //2 //3 //4 //25 //50 //104 //2  	//zl for LSI SAME CASE
        //static long NUM_ID = 1000000;   //2000000  Cover10D,Cover4D,    //62D 500000
        static long iSizeofDataSetTable = 0;
        ZLRECT[] midRectNode = new ZLRECT[13];
        public class ZLRECT
        {
            public double[] a = new double[COL_NUM + 1]; //
            public double[] b = new double[COL_NUM + 1]; //b[i] means bi
            public double v ;  // volume of the rectangle
            //public char[] suffix = new char[1000];
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
            public NODE[] node ;
            public luTUPLE clTuplu = new luTUPLE() ;
        };
        public class NODE
        {
            public double[] x = new double[COL_NUM];  // the ith axis of date
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

        public FormMain()
        {
            InitializeComponent();
        }

         private void FormMain_Load(object sender, EventArgs e)
        {
            comboBox1.SelectedIndex = 0;
        }  
    
        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            comboBox2.SelectedIndex = comboBox1.SelectedIndex;
            comboBox3.SelectedIndex = comboBox1.SelectedIndex;       
            comboBox4.SelectedIndex = comboBox1.SelectedIndex;
            comboBox5.SelectedIndex = comboBox1.SelectedIndex;
            comboBox6.SelectedIndex = comboBox1.SelectedIndex;
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
                    MessageBox.Show("数据库连接成功:\n"  + conn );
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

        private void buttonRun_Click(object sender, EventArgs e)
        {
            if (comboBox1.SelectedIndex == 0) COL_NUM = 2;
            if (comboBox1.SelectedIndex == 1) COL_NUM = 3;
                        
           ////////////////////////////////////////////////////////////////////////////////////////////////////
          // 输出给定数据集的名称、元组数、列数
          ////////////////////////////////////////////////////////////////////////////////////////////////////
            string DataSetTable = comboBox1.Text;
            string select_all = "select count(*) from " + DataSetTable;
            iSizeofDataSetTable = DavidSelect(select_all);
            labelResult.Text = " DataSet:\"" + DataSetTable + "\"---SIZE:"+ iSizeofDataSetTable + "---COLUM:"+COL_NUM;            
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // 调用"划分函数"，进行数据清洗，得出干净数据集以及数据节点表
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            //定义变量
            double []dMin = new double[COL_NUM + 1];
            double []dMax = new double[COL_NUM + 1];
            int T_Num = 24;
            int PartNum = 0;
          //找数据表中的最大值最小值（根节点，总体范围）dMax,dMin
            string select_max = "select max(attr0) from " + DataSetTable;                
            dMax[0] = DavidSelect(select_max)+1;                
            string select_max1 = "select max(attr1) from " + DataSetTable;
            dMax[1] = DavidSelect(select_max1)+1;
            string select_min = "select min(attr0) from " + DataSetTable;
            dMin[0] = DavidSelect(select_min)-1; 
            string select_min1 = "select min(attr1) from " + DataSetTable;
            dMin[1] = DavidSelect(select_min1)-1;
            labelMaxMin.Text = "(" + dMax[0] + "," + dMax[1] + ")"+ "(" + dMin[0] + "," + dMin[1] + ")"; ;
            if(COL_NUM == 3)
            {
              string select_max2 = "select max(attr2) from " + DataSetTable;
              dMax[2] = DavidSelect(select_max2) + 1;
              string select_min2 = "select min(attr2) from " + DataSetTable;
              dMin[2] = DavidSelect(select_min2) - 1;
              labelMaxMin.Text = "(" + dMax[0] + "," + dMax[1] + "," + dMax[2] + ")" + "(" + dMin[0] + "," + dMin[1] + "," + dMin[2] + ")";
            }
            //定义变量结束

            MessageBox.Show("准备加载数据，时间较长，请耐心等待  ~");

            //测试时间函数 开始
            System.Diagnostics.Stopwatch stopwatch = new System.Diagnostics.Stopwatch(); // Stopwatch 方法 毫秒级
            stopwatch.Start();
            string select_time = "SELECT  * FROM   "+DataSetTable ;
            string conn = ConfigurationManager.ConnectionStrings["myconn"].ConnectionString;
            DataSet dataSet = new DataSet();
            SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(select_time,conn);
            sqlDataAdapter.Fill(dataSet,"TableName");
            stopwatch.Stop();
            long TheTime = stopwatch.ElapsedMilliseconds; //这里是输出的总运行秒数,精确到毫秒的                
            labelTime.Text = "Read "+ iSizeofDataSetTable+" turples to DataSet ,used time:" + TheTime + "ms";

            #region  切块

            #region//切块 1： rect加载数据
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

            #region//切块 2： 初始化midRectNode
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

            #region  //切块 3： tNode存取所有节点
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

            #region//切块 4： 第一次划分，划分为12块
            stopwatch.Restart();
            if (midRectNode[0].count > 5)//大于5是什么意思？
            {
                if (COL_NUM == 2)
                {
                    labelRect.Text = "2D Divided ~ ";
                    zlPartionpa2(rect, COL_NUM, T_Num, PartNum);//2D 切块函数，切为 3*4形状
                }
                if (COL_NUM == 3)
                {
                    labelRect.Text = "3D Divided ~ ";
                }

                //记录第二层节点以及各个节点的数量
                labelRect.Text += "\n============== Node[1]-[12] of Second Layer ==============";
                long TotalCount = 0;
                for (int tn = 1; tn <= 12; tn++)               
                {
                    for (int ti = 0; ti < COL_NUM; ti++)
                    {
                        tNode[tNum].a[ti] = midRectNode[tn].a[ti];
                        tNode[tNum].b[ti] = midRectNode[tn].b[ti];
                    }
                    tNode[tNum].count = midRectNode[tn].count;
                    tNode[tNum].nodeId = midRectNode[tn].nodeId;
                    TotalCount += tNode[tNum].count;
                    //string nodeIdPrint = tNode[tNum].nodeId;//查看该Node中包含的数据ID号集合
                    //if (nodeIdPrint == null)
                    //    nodeIdPrint = "Empty Data";
                    //else if (nodeIdPrint.Length > 30)
                    //    nodeIdPrint = nodeIdPrint.Substring(0, 30)+"......"+ nodeIdPrint.Substring(nodeIdPrint.Length - 30);

                    labelRect.Text += "\n------tNode["+tNum+"].count=" + tNode[tNum].count;                    
                    tNode[tNum].tfloor = 2;
                    tNum++;
                }
                labelRect.Text += "\n------Total Count=" + TotalCount;
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
                        RectNode[r].nodeId = midRectNode[r].nodeId;
                    }                    
                }                
            }
            else
            {                
                MessageBox.Show("完成划分，共划分1组");
            }
            stopwatch.Stop();
            TheTime = stopwatch.ElapsedMilliseconds; //这里是输出的总运行秒数,精确到毫秒的                
            labelTime.Text += "\nDivided to 12 blocks ,used time:" + TheTime + "ms";
            #endregion

            #endregion
        }

        //For 2D 
        int zlPartionpa2(ZLRECT[] Rect, int Dimention,  int T_Num, int PartNum)
        {
            labelRect.Text += "zlPartionpa2() implemented. \nDimention = "+Dimention+ ",T_Num="+ T_Num;
            int n = Dimention, m = T_Num;
            int h, i, j, k, idx;
            bool bInterable = false;
            string cstrMarc;
            ZLRECT[] part = new ZLRECT[13];
            ZLRECT[] scr = new ZLRECT[iSizeofDataSetTable];

            int[] dim = new int[3]; //dim[1], [2], [3] are the biggest value of all dimensens
            double dMaxInterval = 0.0;

            scr = Rect;
            for (i = 0; i < 12; i++)
            {
                    part[i]=Rect[i];
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
           
            labelRect.Text += "\nLong edge:" + d[dim[1]] * 4 + "---Short edge:" + d[dim[2]] * 3;

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

            labelRect.Text += "\nDivided long edge:" + Convert.ToInt32(d41) + "---" + Convert.ToInt32(d42) + "---" + Convert.ToInt32(d43) + "---" + Convert.ToInt32(d44);
            labelRect.Text += "\nDivided short edge:" + Convert.ToInt32(d31) + "---" + Convert.ToInt32(d32) + "---" + Convert.ToInt32(d33) ;

            int num1 = 0;            int num2 = 0;            int num3 = 0;            int num4 = 0;            int num5 = 0;            int num6 = 0;
            int num7 = 0;            int num8 = 0;            int num9 = 0;            int num10 = 0;          int num11 = 0;          int num12 = 0;

            int d1 = dim[1] - 1;//最长边
            int d2 = dim[2] - 1;//

            

            for (m = 0; m < midRectNode[0].count; m++)
            {
                if (Rect[m].x[d1] <= d41)// 00-41
                {
                    if (Rect[m].x[d2] <= d31)// 00-31
                    {
                        midRectNode[1].count++;      //计算第一块(00-41 , 00-31)中含有的元组个数
                        //for (int y = 0; y < COL_NUM; y++)       //放入第1块中的元组
                        //{
                        //    midRectNode[1].node[num1].x[y] = Rect[m].x[y];
                        //}
                        //midRectNode[1].nodeId += Rect[m].ID.ToString()+";";//放入第1块的各元组的ID集合
                        num1++;
                        midRectNode[1].count = num1;//统计放入第1块的元组ID数
                        //MessageBox.Show(midRectNode[1].nodeId);
                    }
                    else if (Rect[m].x[d2] <= d32 && Rect[m].x[d2] > d31)
                    {
                        midRectNode[5].count++;      //计算第7块中元组数目
                        //for (int y = 0; y < COL_NUM; y++)       //放入第5块中的元组
                        //{
                        //    midRectNode[5].node[num5].x[y] = Rect[m].x[y];
                        //}
                        //midRectNode[5].node[num5].ID = Rect[m].ID;
                        //midRectNode[5].nodeId += Rect[m].ID.ToString() + ";";
                        num5++;
                        midRectNode[5].count = num5;
                        //MessageBox.Show(midRectNode[5].nodeId);
                    }
                    else //if (Rect[m].x[d2] <= d33 && Rect[m].x[d2] > d32)
                    {
                        midRectNode[9].count++;      //计算第7块中元组数目

                        //for (int y = 0; y < COL_NUM; y++)       //放入第9块中的元组
                        //{
                        //    midRectNode[9].node[num9].x[y] = Rect[m].x[y];
                        //}
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

                        //for (int y = 0; y < COL_NUM; y++)       //放入第1块中的元组
                        //{
                        //    midRectNode[2].node[num2].x[y] = Rect[m].x[y];
                        //}
                        //midRectNode[2].node[num2].ID = Rect[m].ID;
                        //midRectNode[2].nodeId += Rect[m].ID.ToString() + ";";
                        num2++;
                        midRectNode[2].count = num2;
                    }
                    else if (Rect[m].x[d2] <= d32 && Rect[m].x[d2] > d31)
                    {
                        midRectNode[6].count++;      //计算第6块中元组数目

                        //for (int y = 0; y < COL_NUM; y++)       //放入第5块中的元组
                        //{
                        //    midRectNode[6].node[num6].x[y] = Rect[m].x[y];
                        //}
                        //midRectNode[6].node[num6].ID = Rect[m].ID;
                        //midRectNode[6].nodeId += Rect[m].ID.ToString() + ";";
                        num6++;
                        midRectNode[6].count = num6;
                    }
                    else //if (Rect[m].x[d2] <= d33 && Rect[m].x[d2] > d32)
                    {
                        midRectNode[10].count++;      //计算第10块中元组数目

                        //for (int y = 0; y < COL_NUM; y++)       //放入第9块中的元组
                        //{
                        //    midRectNode[10].node[num10].x[y] = Rect[m].x[y];
                        //}
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

                        //for (int y = 0; y < COL_NUM; y++)       //放入第3块中的元组
                        //{
                        //    midRectNode[3].node[num3].x[y] = Rect[m].x[y];
                        //}
                        //midRectNode[3].node[num3].ID = Rect[m].ID;
                        //midRectNode[3].nodeId += Rect[m].ID.ToString() + ";";
                        num3++;
                        midRectNode[3].count = num3;
                    }
                    else if (Rect[m].x[d2] <= d32 && Rect[m].x[d2] > d31)
                    {
                        midRectNode[7].count++;      //计算第7块中元组数目

                        //for (int y = 0; y < COL_NUM; y++)       //放入第7块中的元组
                        //{
                        //    midRectNode[7].node[num7].x[y] = Rect[m].x[y];
                        //}
                        //midRectNode[7].node[num7].ID = Rect[m].ID;
                        //midRectNode[7].nodeId += Rect[m].ID.ToString() + ";";
                        num7++;
                        midRectNode[7].count = num7;
                    }
                    else //if (Rect[m].x[d2] <= d33 && Rect[m].x[d2] > d32)
                    {
                        midRectNode[11].count++;      //计算第11块中元组数目

                        //for (int y = 0; y < COL_NUM; y++)       //放入第9块中的元组
                        //{
                        //    midRectNode[11].node[num11].x[y] = Rect[m].x[y];
                        //}
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

                        //for (int y = 0; y < COL_NUM; y++)       //放入第1块中的元组
                        //{
                        //    midRectNode[4].node[num4].x[y] = Rect[m].x[y];
                        //}
                        //midRectNode[4].node[num4].ID = Rect[m].ID;
                        //midRectNode[1].nodeId += Rect[m].ID.ToString() + ";";
                        num4++;
                        midRectNode[4].count = num4;
                    }
                    else if (Rect[m].x[d2] <= d32 && Rect[m].x[d2] > d31)
                    {
                        midRectNode[8].count++;      //计算第7块中元组数目

                        //for (int y = 0; y < COL_NUM; y++)       //放入第8块中的元组
                        //{
                        //    midRectNode[8].node[num8].x[y] = Rect[m].x[y];
                        //}
                        //midRectNode[8].node[num8].ID = Rect[m].ID;
                        //midRectNode[8].nodeId += Rect[m].ID.ToString() + ";";
                        num8++;
                        midRectNode[8].count = num8;
                    }
                    else //if (Rect[m].x[d2] <= d33 && Rect[m].x[d2] > d32)
                    {
                        midRectNode[12].count++;      //计算第7块中元组数目

                        //for (int y = 0; y < COL_NUM; y++)       //放入第12块中的元组
                        //{
                        //    midRectNode[12].node[num12].x[y] = Rect[m].x[y];
                        //}
                        //midRectNode[12].node[num12].ID = Rect[m].ID;
                        //midRectNode[12].nodeId += Rect[m].ID.ToString() + ";";
                        num12++;
                        midRectNode[12].count = num12;
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

            return PartNum;
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


    }
}
