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

namespace School
{
    public partial class FormStudent : Form
    {
        public FormStudent()
        {
            InitializeComponent();
        }

        private void FormStudent_Load(object sender, EventArgs e)
        {
            // TODO: 这行代码将数据加载到表“mrDavidDataSet.Student”中。您可以根据需要移动或删除它。
            this.studentTableAdapter.Fill(this.mrDavidDataSet.Student);
        }

 

        private void ButtonInsert_Click(object sender, EventArgs e)
        {
                String StuID = textBoxSno.Text.Trim();
                String StuName = textBoxSname.Text.Trim();
                String StuSex = textBoxSsex.Text.Trim();
                String StuSdept = textBoxSage.Text.Trim();
                String StuAge = textBoxSdept.Text.Trim();
                SqlConnection con = new SqlConnection("Data Source=.;Initial Catalog=MrDavid;User ID=sa;Password=sql");
                try
                {
                    con.Open();
                    string insertStr = "INSERT INTO  Student (Sno,Sname,Ssex,Sdept,Sage)    " +
                        "VALUES ('" + StuID + "','" + StuName + "','" + StuSex + "','" + StuSdept + "'," + StuAge + ")";
                    SqlCommand cmd = new SqlCommand(insertStr, con);
                    cmd.ExecuteNonQuery();
                }
                catch
                {
                    MessageBox.Show("输入数据违反要求!");
                }
                finally
                {
                    con.Dispose();
                }
                this.studentTableAdapter.Fill(this.mrDavidDataSet.Student);
           
        }

        private void ButtonDelete_Click(object sender, EventArgs e)
        {
            SqlConnection con = new SqlConnection("Data Source=.;Initial Catalog=MrDavid;User ID=sa;Password=sql");
            try
            {
                con.Open();
                string select_id = dataGridView1.SelectedRows[0].Cells[0].Value.ToString();//选择的当前行第一列的值，也就是ID
                string delete_by_id = "delete from Student where Sno=" + select_id;//sql删除语句
                SqlCommand cmd = new SqlCommand(delete_by_id, con);
                cmd.ExecuteNonQuery();
            }
            catch
            {
                MessageBox.Show("请正确选择行!");
            }
            finally
            {
                con.Dispose();
            }
            this.studentTableAdapter.Fill(this.mrDavidDataSet.Student);
        }

        private void ButtonUpdate_Click(object sender, EventArgs e)
        {
            String StuID = textBoxSno.Text.Trim();
            String StuName = textBoxSname.Text.Trim();

            SqlConnection con = new SqlConnection("Data Source=.;Initial Catalog=MrDavid;User ID=sa;Password=sql");
            try
            {
                con.Open();
                string insertStr = "UPDATE Student SET Sname = '" + StuName + "' WHERE Sno = '" + StuID + "'";
                SqlCommand cmd = new SqlCommand(insertStr, con);
                cmd.ExecuteNonQuery();
            }
            catch
            {
                MessageBox.Show("输入数据违反要求!");
            }
            finally
            {
                con.Dispose();
            }
            this.studentTableAdapter.Fill(this.mrDavidDataSet.Student);
        }

        private void ButtonQuery_Click(object sender, EventArgs e)
        {
            String StuID = textBoxSno.Text.Trim();
            String conn = "Data Source=.;Initial Catalog=MrDavid;User ID=sa;Password=sql";
            SqlConnection sqlConnection = new SqlConnection(conn);  //实例化连接对象
            try
            {
                sqlConnection.Open();
                String select_by_id = "select * from Student where Sno='" + StuID + "'";
                SqlCommand sqlCommand = new SqlCommand(select_by_id, sqlConnection);
                SqlDataReader sqlDataReader = sqlCommand.ExecuteReader();
                BindingSource bindingSource = new BindingSource() { DataSource = sqlDataReader };
                //bindingSource.DataSource = sqlDataReader;
                //https://developercommunity.visualstudio.com/content/problem/70962/bogus-ide0017-c-object-initialization-can-be-simpl.html
                dataGridView1.DataSource = bindingSource;
            }
            catch
            {
                MessageBox.Show("查询语句有误，请认真检查SQL语句!");
            }
            finally
            {
                sqlConnection.Close();
            }
        }

        private void ButtonClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }

    }
}
