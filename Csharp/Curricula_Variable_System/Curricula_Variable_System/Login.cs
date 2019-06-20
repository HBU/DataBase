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

namespace Curricula_Variable_System
{
    public partial class Login : Form
    {
        public Login()
        {
            InitializeComponent();
        }

        private void LinkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            Register register = new Register();
            register.ShowDialog();
        }

        private void Button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            string username = textBox1.Text.Trim();  //取出账号
            string password = textBox2.Text.Trim();  //取出密码

            //string connstr = ConfigurationManager.ConnectionStrings["connectionString"].ToString(); //读取连接字符串
            string myConnString = "Data Source=.;Initial Catalog=curricula_variable_system;Persist Security Info=True;User ID=sa;Password=sql";

            SqlConnection sqlConnection = new SqlConnection(myConnString);  //实例化连接对象
            sqlConnection.Open();

            string sql = "select UserID,UserPassword from SysUser where UserID = '" + username + "' and UserPassword = '" + password + "'";                                            //编写SQL命令
            SqlCommand sqlCommand = new SqlCommand(sql, sqlConnection);

            SqlDataReader sqlDataReader = sqlCommand.ExecuteReader();

            if (sqlDataReader.HasRows)
            {
                MessageBox.Show("欢迎使用！");             //登录成功
                Main form2 = new Main();
                form2.Show();
                this.Hide();
            }
            else
            {
                MessageBox.Show("登录失败！");
            }
            sqlConnection.Close();
        }
    }
}
