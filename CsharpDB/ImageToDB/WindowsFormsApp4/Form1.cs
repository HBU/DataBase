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

namespace WindowsFormsApp4
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                string connString = "Data Source=.;Initial Catalog=TEST1;User ID=sa;Password=sql";//数据库连接字符串
                SqlConnection connection = new SqlConnection(connString);//创建connection对象


                string sql = "insert into Images (BLOBData) values (@blobdata)";
                SqlCommand command = new SqlCommand(sql, connection);
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
                fs.Close();
                //转换成二进制数据，并保存到数据库
                SqlParameter prm = new SqlParameter
              ("@blobdata", SqlDbType.VarBinary, mybyte.Length, ParameterDirection.Input, false, 0, 0, null, DataRowVersion.Current, mybyte);
                command.Parameters.Add(prm);
                //打开数据库连接
                connection.Open();
                command.ExecuteNonQuery();
                connection.Close();
                MessageBox.Show("图片已经导入到数据库，可在SQLserver查看。");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                string connString = "Data Source=.;Initial Catalog=TEST1;User ID=sa;Password=sql";//数据库连接字符串
                SqlConnection connection = new SqlConnection(connString);//创建connection对象

                //打开数据库连接
                connection.Open();
                //创建SQL语句
                string sql = "select BLODID,BLOBData from Images order by BLODID";
                //创建SqlCommand对象
                SqlCommand command = new SqlCommand(sql, connection);
                //创建DataAdapter对象
                SqlDataAdapter dataAdapter = new SqlDataAdapter(command);
                //创建DataSet对象
                DataSet dataSet = new DataSet();
                dataAdapter.Fill(dataSet, "BLOBTest");
                int c = dataSet.Tables["BLOBTest"].Rows.Count;
                if (c > 0)
                {
                    Byte[] mybyte = new byte[0];
                    mybyte = (Byte[])(dataSet.Tables["BLOBTest"].Rows[c - 1]["BLOBData"]);
                    MemoryStream ms = new MemoryStream(mybyte);
                    pictureBox1.Image = Image.FromStream(ms);
                }
                connection.Close();

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}
