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

namespace NewTable
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            SqlConnection con = new SqlConnection("Data Source=.;Initial Catalog=BlockIndex;User ID=sa;Password=sql");
            try
            {
                con.Open();
                string deleteStr = "Delete from Attr_Census3D_TestDavid";
                SqlCommand cmd = new SqlCommand(deleteStr, con);
                cmd.ExecuteNonQuery();
                double d = 1;
                string insertStr;
                for (int a = 0; a < 8; a++)
                {
                    for (int b = 0; b < 27; b++)
                    {
                        for(int c = 0; c<8; c++)
                        {
                            insertStr = "insert into Attr_Census3D_TestDavid values(" + a +"," + b + "," + c + ","+ d +")";
                            d++;
                            cmd = new SqlCommand(insertStr, con);
                            cmd.ExecuteNonQuery();
                        }

                    }
                }
            }
            catch
            {
                MessageBox.Show("输入数据违反要求!");
            }
            finally
            {
                con.Dispose();
            }
            MessageBox.Show("END");
        }
    }
}
