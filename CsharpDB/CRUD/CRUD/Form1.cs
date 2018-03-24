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

namespace CRUD
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: 这行代码将数据加载到表“mrDavidDataSet.Student”中。您可以根据需要移动或删除它。
            this.studentTableAdapter.Fill(this.mrDavidDataSet.Student);

        }

        private void button5_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            String StuID = textBox1.Text.Trim();
            String StuName = textBox1.Text.Trim();
            String StuSex = textBox1.Text.Trim();
            String StuSdept = textBox1.Text.Trim();
            String StuAge = textBox1.Text.Trim();
            //此处应增加if语句，验证输入值是否为空，是否违反完整性规则
            studentTableAdapter.Insert(StuID,StuName,StuSex,Convert.ToInt16(StuSdept),StuAge);

            this.studentTableAdapter.Fill(this.mrDavidDataSet.Student);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            
            this.studentTableAdapter.Fill(this.mrDavidDataSet.Student);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            String StuID = textBox1.Text.Trim();
            String StuName = textBox1.Text.Trim();
            String StuSex = textBox1.Text.Trim();
            String StuSdept = textBox1.Text.Trim();
            String StuAge = textBox1.Text.Trim();
            
        }

        private void button2_Click(object sender, EventArgs e)
        {
            
            String Row = dataGridView1.Rows[0].Cells[1].ToString();
            MessageBox.Show(Row);
            this.studentTableAdapter.Fill(this.mrDavidDataSet.Student);
        }
    }
}
