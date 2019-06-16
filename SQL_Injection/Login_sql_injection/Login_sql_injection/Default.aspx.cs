using System;
using System.Collections.Generic;
using System.Data;
using System.Data.OleDb;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Login_sql_injection
{
    public partial class Default : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            string name = TextBox1.Text;
            string pwd = TextBox2.Text;
            UserLogin(name, pwd);            
        }

    
        private void UserLogin(string _loginname, string _loginpwd)
        {
           SqlConnection conn = new SqlConnection
            {
                ConnectionString = "User ID=sa;Initial Catalog=Test;Data Source= (local);Password=sql"
            };

            SqlCommand cmd;

            if (CheckBox1.Checked)
            {
                string sql = "select * from usertable Where userid='" + _loginname + "' and password='" + _loginpwd + "'"; //创建查询语句
                cmd = new SqlCommand(sql, conn);
            }
            else
            {
                string sql = "select * from usertable where userid=@username and password=@password"; //使用参数控制传递，避免SQL注入
                cmd = new SqlCommand(sql, conn);
                cmd.Parameters.Add("@username", SqlDbType.VarChar, 10);
                cmd.Parameters["@username"].Value = _loginname;
                cmd.Parameters.Add("@password", SqlDbType.VarChar, 10);
                cmd.Parameters["@password"].Value = _loginpwd;
            }

            try
            {
                // 打开连接
                if (conn.State == ConnectionState.Closed)
                {
                    conn.Open();
                }
                
                SqlDataReader sqlDataReader = cmd.ExecuteReader();    //从数据库中读取数据流存入reader中                                              
                if (sqlDataReader.Read()) //从sdr中读取下一行数据,如果没有数据,sdr.Read()返回flase 
                {
                    Label3.Text = "Succeed ,welcome:" + sqlDataReader[0] + "You password is:" + sqlDataReader[1];
                }
                else
                {
                    Label3.Text = "输入账号或密码错误";
                }
                sqlDataReader.Close();

            }
            catch (Exception ee)
            {
                Response.Write("The connection is fair" + ee.ToString());
            }
            finally
            {
                conn.Close();
            }

        }
    }
}