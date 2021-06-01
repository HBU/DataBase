using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;



/*  程序功能：
 *  加载时，从数据库读“省”的名字，写入combox1；combox1选项发生变化时，combox2填写内容
 
 * 首先要在SQLserver中完成以下操作：
 
1. 建立数据库 MrDavid
2. 建立基本表 city
    CREATE TABLE city(P_Name nchar(10) ,	C_Name nchar(10) ) 
3.插入内容：
    P_Name   C_Name
    河北         保定        
    河北        	石家庄       
    河北        	唐山        
    北京        	东城区       
    北京        	西城区       
    北京        	朝阳区       
    天津        	河东区       
    天津        	河西区       

注意事项：数据库连接字符串要改成自己的相应参数
*/



namespace ComboxTest
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            load_Pname();//加载窗体时，combox1填写内容
        }
        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            load_Cname();//combox1选项发生变化时，combox2填写内容
        }
        
        private void load_Pname()//从数据库读“省”的名字
        {
            ArrayList list = new ArrayList();
            string conn = "Data Source=.;Initial Catalog=MrDavid;;User ID=sa;Password=sql"; //此处换位自己的数据库相关参数
            string str = "select distinct P_Name from city ";
            SqlDataAdapter da = new SqlDataAdapter(str, conn);
            DataSet ds = new DataSet();
            da.Fill(ds);
            DataTable dt = ds.Tables[0];
            foreach (DataRow dr in dt.Rows)
            {                
                list.Add(dr[0].ToString().Trim());//dr[0]表示取结果的第一列，dr[1]就是第二列
            }
            comboBox1.DataSource = list;
        }

        private void load_Cname()//根据“省”的名字，从数据库读“市”的名字
        {
            String Pname = comboBox1.SelectedItem.ToString();
            ArrayList list = new ArrayList();
            string conn = "Data Source=.;Initial Catalog=MrDavid;;User ID=sa;Password=sql";//此处换位自己的数据库相关参数
            string str = "select C_Name from city where P_Name = '" + Pname + "'";
            SqlDataAdapter da = new SqlDataAdapter(str, conn);
            DataSet ds = new DataSet();
            da.Fill(ds);
            DataTable dt = ds.Tables[0];
            foreach (DataRow dr in dt.Rows)
            {
                list.Add(dr[0].ToString().Trim());
            }
            comboBox2.DataSource = list;
        }


    }
}
