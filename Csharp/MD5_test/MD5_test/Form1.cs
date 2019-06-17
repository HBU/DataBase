using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MD5_test
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        string username;  //取出账号
        string password;  //取出密码
        private void Button1_Click(object sender, EventArgs e)
        {
            username = textBox1.Text.Trim();  //取出账号
            password = textBox2.Text.Trim();  //取出密码

            //string connstr = ConfigurationManager.ConnectionStrings["connectionString"].ToString(); //读取连接字符串
            string myConnString = "Data Source=.;Initial Catalog=Test;Persist Security Info=True;User ID=sa;Password=sql";
            SqlConnection sqlConnection = new SqlConnection(myConnString);  //实例化连接对象
            sqlConnection.Open();
            password = EncryptWithMD5(password);
            string insertStr = "INSERT INTO  usertable32 (userid,password)    " + "VALUES ('" + username + "','" + password + "')";
            SqlCommand cmd = new SqlCommand(insertStr, sqlConnection);
            cmd.ExecuteNonQuery();
            sqlConnection.Close();
            MessageBox.Show("成功写入");
        }

        private void Button2_Click(object sender, EventArgs e)
        {
            string myConnString = "Data Source=.;Initial Catalog=Test;Persist Security Info=True;User ID=sa;Password=sql";
            username = textBox1.Text.Trim();  //取出账号
            SqlConnection sqlConnection = new SqlConnection(myConnString);  //实例化连接对象
            sqlConnection.Open();
            string sql = "select userid,password from usertable32 where userid = '" + username + "'";
            SqlCommand com = new SqlCommand(sql, sqlConnection);
            SqlDataReader read = com.ExecuteReader();
            while (read.Read())
            {
                string myUsername = read["userid"].ToString();
                string myPassword = read["password"].ToString();
                textBox3.Text = myUsername;
                textBox4.Text = myPassword;
            }
            sqlConnection.Close();
            MessageBox.Show("成功读取");
        }


        public static string EncryptWithMD5(string source)
        {
            byte[] sor = Encoding.UTF8.GetBytes(source);
            MD5 md5 = MD5.Create();
            byte[] result = md5.ComputeHash(sor);
            StringBuilder strbul = new StringBuilder(40);
            for (int i = 0; i < result.Length; i++)
            {
                strbul.Append(result[i].ToString("x2"));//加密结果"x2"结果为32位,"x3"结果为48位,"x4"结果为64位
            }
            return strbul.ToString();
        }


    }
}
