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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            comboBox1.SelectedIndex = 0;
        }
    
        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            comboBox2.SelectedIndex = comboBox1.SelectedIndex;
            comboBox3.SelectedIndex = comboBox1.SelectedIndex;           
        }

        private void button2_Click(object sender, EventArgs e)
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

        private void button1_Click(object sender, EventArgs e)
        {
            /**************************************
            *  0. Select all tuples from a given dataset
            *  1. Partion the domain of the dataset
            *  2. Get the histogram
            *  3. Select all queires from workload table 
            **************************************/
            
            String conn = ConfigurationManager.ConnectionStrings["myconn"].ConnectionString;
            SqlConnection sqlConnection = new SqlConnection(conn);  //实例化连接对象
            String ResultSize = "";
            try
            {
                sqlConnection.Open();
                // 0. Select all tuples from a given dataset
                String select_all = "select count(*) from " + comboBox1.Text;
                SqlCommand sqlCommand = new SqlCommand(select_all , sqlConnection);
                SqlDataReader sqlDataReader = sqlCommand.ExecuteReader();
                while (sqlDataReader.Read())
                    ResultSize = sqlDataReader[0].ToString();
                labelResult.Text = " \""+comboBox1.Text+"\"---"+ResultSize;
                // 1. Partion the domain of the dataset

                // 2. Get the histogram

                // 3. Select all queires from workload table

            }
            catch
            {
                MessageBox.Show("查询语句有误，请检查SQL语句!");
            }
            finally
            {
                sqlConnection.Close();
            }
        }

    }
}
