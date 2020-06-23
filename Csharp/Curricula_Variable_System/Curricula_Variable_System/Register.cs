using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Security.Cryptography;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Curricula_Variable_System
{
    public partial class Register : Form
    {
        public Register()
        {
            InitializeComponent();
        }
        public Byte[] mybyte = new byte[0];

        private void Button1_Click(object sender, EventArgs e)
        {
            try
            {
                string connString = "Data Source=.;Initial Catalog=curricula_variable_system;Persist Security Info=True;User ID=sa;Password=sql";//数据库连接字符串
                SqlConnection connection = new SqlConnection(connString);//创建connection对象
                string sql = "insert into SysUser (UserID,   UserPassWord ,   UserSchoolID, UserMobile, UserBirthday , UserIdentity , UserPhoto ) " +
                                                        "values (@userid, @userpassword,@userschoolid,@usermobile,@userbirthday,@useridentity,@userphoto)";
                SqlCommand command = new SqlCommand(sql, connection);

                SqlParameter sqlParameter = new SqlParameter("@userid",textBox1.Text);
                command.Parameters.Add(sqlParameter);
                sqlParameter = new SqlParameter("@userpassword", EncryptWithMD5(textBox2.Text));
                command.Parameters.Add(sqlParameter);
                sqlParameter = new SqlParameter("@userschoolid", textBox3.Text);
                command.Parameters.Add(sqlParameter);
                sqlParameter = new SqlParameter("@usermobile", textBox4.Text);
                command.Parameters.Add(sqlParameter);
                sqlParameter = new SqlParameter("@userbirthday", dateTimePicker1.Value);
                command.Parameters.Add(sqlParameter);
                sqlParameter = new SqlParameter("@useridentity", comboBox1.Text);
                command.Parameters.Add(sqlParameter);
                sqlParameter = new SqlParameter("@userphoto", SqlDbType.VarBinary, mybyte.Length, ParameterDirection.Input, false, 0, 0, null, DataRowVersion.Current, mybyte);
                command.Parameters.Add(sqlParameter);

                //打开数据库连接
                connection.Open();
                command.ExecuteNonQuery();
                connection.Close();
                MessageBox.Show("register succeed");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }


            this.Close();
        }

        private void Button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void Button3_Click(object sender, EventArgs e)
        {
            //打开浏览图片对话框
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.ShowDialog();
            string picturePath = openFileDialog.FileName;//获取图片路径
            //文件的名称，每次必须更换图片的名称，这里很为不便
            //创建FileStream对象
            FileStream fs = new FileStream(picturePath, FileMode.Open, FileAccess.Read);
            //声明Byte数组
             mybyte = new byte[fs.Length];
            //读取数据
            fs.Read(mybyte, 0, mybyte.Length);            
            pictureBox1.Image = Image.FromStream(fs);
            fs.Close();
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

        private void TextBox1_Leave(object sender, EventArgs e)
        {
 

            if (textBox1.Text.Trim() != "")
            {
                //使用regex（正则表达式）进行格式设置 至少有数字、大写字母、小写字母各一个。最少3个字符、最长20个字符。
                Regex regex = new Regex(@"(?=.*[0-9])(?=.*[a-z])(?=.*[A-Z]).{3,20}");

                if (regex.IsMatch(textBox1.Text))//判断格式是否符合要求
                {
                            //MessageBox.Show("输入密码格式正确!");
                }
                else
                {
                    MessageBox.Show("至少有数字、大写字母、小写字母各一个。最少3个字符、最长20个字符！");
                    textBox1.Focus();
                }
            }
            else
            {
                MessageBox.Show("Please fill in the full information！");
            }

        }
    }
}
