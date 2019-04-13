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

namespace Login
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Button2_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            string username = textBoxUserName.Text.Trim();  //取出账号
            string password = textBoxPassWord.Text.Trim();  //取出密码

            //string connstr = ConfigurationManager.ConnectionStrings["connectionString"].ToString(); //读取连接字符串
            string myConnString = "Data Source=.;Initial Catalog=Test;Persist Security Info=True;User ID=sa;Password=sql";

            SqlConnection sqlConnection = new SqlConnection(myConnString);  //实例化连接对象
            sqlConnection.Open();

            string sql = "select userid,password from usertable where userid = '" + username + "' and password = '" + password + "'";                                            //编写SQL命令
            SqlCommand sqlCommand = new SqlCommand(sql, sqlConnection);

            SqlDataReader sqlDataReader = sqlCommand.ExecuteReader();

            if (sqlDataReader.HasRows)
            {
                MessageBox.Show("WELCOME！","notice",MessageBoxButtons.OK,MessageBoxIcon.Asterisk);             //登录成功
                label1.Text = "Log in :"+username;
                //Form2 form2 = new Form2();
                //form2.Show();
                //this.Hide();
            }
            else
            {
                MessageBox.Show("FAILED！", "notice", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            sqlConnection.Close();
        }
    }
}
