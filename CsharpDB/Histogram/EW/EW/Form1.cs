using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace EW
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            String conn = "Data Source=.;Initial Catalog=Northwind;User ID=sa;Password=sql";
            String resultNum = "";
            String resultNumNest = "";
            SqlConnection sqlConnection = new SqlConnection(conn);  //实例化连接对象

            // 实际查询结果
            try
            {
                sqlConnection.Open();
                String select_by_id = "select count(*) from Products where SupplierID='" + 18 + "'";
                SqlCommand sqlCommand = new SqlCommand(select_by_id, sqlConnection);
                SqlDataReader sqlDataReader = sqlCommand.ExecuteReader();                
                while (sqlDataReader.Read())
                    resultNum = sqlDataReader[0].ToString();
                textBox7.Text = resultNum;
            }
            catch
            {
                MessageBox.Show("查询语句有误，请认真检查SQL语句!");
            }
            finally
            {
                sqlConnection.Close();
            }

            // 直方图估计结果
            try
            {
                sqlConnection.Open();
                String select_by_Nest = "select count(*) from Products where SupplierID > '16' and SupplierID < '20'";
                SqlCommand sqlCommandNest = new SqlCommand(select_by_Nest, sqlConnection);
                SqlDataReader sqlDataReaderNest = sqlCommandNest.ExecuteReader();                
                while (sqlDataReaderNest.Read())
                    resultNumNest = sqlDataReaderNest[0].ToString();
                textBox6.Text = resultNumNest;
            }
            catch
            {
                MessageBox.Show("查询语句有误，请认真检查SQL语句!");
            }
            finally
            {
                sqlConnection.Close();
            }

            //计算误差
            Double rn = Convert.ToDouble(resultNum);
            Double rnn = Convert.ToDouble(resultNumNest);
            Double errorValue = (rnn - rn) ;
            textBox5.Text = errorValue.ToString();

        }
    }
}
