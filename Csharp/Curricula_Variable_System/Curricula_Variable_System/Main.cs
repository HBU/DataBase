using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Curricula_Variable_System
{
    public partial class Main : Form
    {
        public Main()
        {
            InitializeComponent();
        }

        private void Main_FormClosed(object sender, FormClosedEventArgs e)
        {
            Application.Exit();
        }

        private void Main_Load(object sender, EventArgs e)
        {
 
            // TODO: 这行代码将数据加载到表“curricula_variable_systemDataSet.SC”中。您可以根据需要移动或删除它。
            this.sCTableAdapter.Fill(this.curricula_variable_systemDataSet.SC);
            // TODO: 这行代码将数据加载到表“curricula_variable_systemDataSet.Course”中。您可以根据需要移动或删除它。
            this.courseTableAdapter.Fill(this.curricula_variable_systemDataSet.Course);
            // TODO: 这行代码将数据加载到表“curricula_variable_systemDataSet.Student”中。您可以根据需要移动或删除它。
            this.studentTableAdapter.Fill(this.curricula_variable_systemDataSet.Student);
            // TODO: 这行代码将数据加载到表“curricula_variable_systemDataSet.SysLog”中。您可以根据需要移动或删除它。
            this.sysLogTableAdapter.Fill(this.curricula_variable_systemDataSet.SysLog);
            // TODO: 这行代码将数据加载到表“curricula_variable_systemDataSet.SysUser”中。您可以根据需要移动或删除它。
            this.sysUserTableAdapter.Fill(this.curricula_variable_systemDataSet.SysUser);         

        }

        private void Button1_Click(object sender, EventArgs e)
        {
            try
            {
                string connString = "Data Source=.;Initial Catalog=curricula_variable_system;Persist Security Info=True;User ID=sa;Password=sql";//数据库连接字符串
                SqlConnection connection = new SqlConnection(connString);//创建connection对象

                //打开数据库连接
                connection.Open();
                //创建SQL语句
                string sql = "select UserPhoto from SysUser where UserID = '" + textBox1.Text + "'";
                //创建SqlCommand对象
                SqlCommand command = new SqlCommand(sql, connection);
                //创建DataAdapter对象
                SqlDataAdapter dataAdapter = new SqlDataAdapter(command);
                //创建DataSet对象
                DataSet dataSet = new DataSet();
                dataAdapter.Fill(dataSet, "SysUser");
                int c = dataSet.Tables["SysUser"].Rows.Count;
                if (c > 0)
                {
                    Byte[] mybyte = new byte[0];
                    mybyte = (Byte[])(dataSet.Tables["SysUser"].Rows[c - 1]["UserPhoto"]);
                    MemoryStream ms = new MemoryStream(mybyte);
                    pictureBox1.Image = Image.FromStream(ms);
                }
                else
                    pictureBox1.Image = null;
                connection.Close();

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void Button2_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void Button3_Click(object sender, EventArgs e)
        {
            this.sysLogTableAdapter.Fill(this.curricula_variable_systemDataSet.SysLog);
        }
    }
}
