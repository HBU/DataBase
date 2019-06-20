using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
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

        private void Button1_Click(object sender, EventArgs e)
        {
            try
            {
                string connString = "Data Source=.;Initial Catalog=curricula_variable_system;Persist Security Info=True;User ID=sa;Password=sql";//数据库连接字符串
                SqlConnection connection = new SqlConnection(connString);//创建connection对象
                string sql = "insert into SysUser (UserID,   UserPassWord ,   UserSchoolID, UserMobile, UserBirthday , UserIdentity , UserPhoto ) " +
                                                        "values (@userid, @userpassword,@userschoolid,@usermobile,@userbirthday,@useridentity,@userphoto)";
                SqlCommand command = new SqlCommand(sql, connection);

                var ms = new MemoryStream();
                var bf = new BinaryFormatter();             
                bf.Serialize(ms, pictureBox1.Image);           // png 可以， jpg 出错 。。。     
                byte[] mybyte = ms.ToArray();
                ms.Close();

                SqlParameter sqlParameter = new SqlParameter("@userid",textBox1.Text);
                command.Parameters.Add(sqlParameter);
                sqlParameter = new SqlParameter("@userpassword", textBox2.Text);
                command.Parameters.Add(sqlParameter);
                sqlParameter = new SqlParameter("@userschoolid", textBox3.Text);
                command.Parameters.Add(sqlParameter);
                sqlParameter = new SqlParameter("@usermobile", textBox4.Text);
                command.Parameters.Add(sqlParameter);
                sqlParameter = new SqlParameter("@userbirthday", dateTimePicker1.Value);
                command.Parameters.Add(sqlParameter);
                sqlParameter = new SqlParameter("@useridentity", comboBox1.Text);
                command.Parameters.Add(sqlParameter);
                sqlParameter = new SqlParameter
              ("@userphoto", SqlDbType.VarBinary, mybyte.Length, ParameterDirection.Input, false, 0, 0, null, DataRowVersion.Current, mybyte);
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

        private void RichTextBox1_TextChanged(object sender, EventArgs e)
        {

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
            Byte[] mybyte = new byte[fs.Length];
            //读取数据
            fs.Read(mybyte, 0, mybyte.Length);            
            pictureBox1.Image = Image.FromStream(fs);
            fs.Close();
        }
    }
}
