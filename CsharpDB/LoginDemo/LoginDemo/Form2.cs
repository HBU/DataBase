using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LoginDemo
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            // TODO: 这行代码将数据加载到表“testDataSet.user”中。您可以根据需要移动或删除它。
            this.userTableAdapter.Fill(this.testDataSet.user);
        }

        private void button5_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form3 form3 = new Form3();
            form3.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //获取点击datagridview1的行的 行号
            int r = this.dataGridView1.CurrentRow.Index;
            //获取此行的 编号 的值
            string userID = this.dataGridView1.Rows[r].Cells[0].Value.ToString();
            //删除 datagridview1 的选中行
            DialogResult result = MessageBox.Show("确定删除用户："+userID+"?","Hello",MessageBoxButtons.OKCancel, MessageBoxIcon.Asterisk);
            if (result == DialogResult.OK)
            {
                this.userTableAdapter.DeleteQuery(userID);
                this.userTableAdapter.Fill(this.testDataSet.user);
            }        
        }

        private void button4_Click(object sender, EventArgs e)
        {
            if(textBox1.Text.Trim() == "")
                this.userTableAdapter.Fill(this.testDataSet.user);
            else
                this.userTableAdapter.FillBy(this.testDataSet.user,textBox1.Text);
        }


        private void button3_Click(object sender, EventArgs e)
        {
            //获取点击datagridview1的行的 行号
            int r = this.dataGridView1.CurrentRow.Index;
            //获取此行的 编号 的值
            string userID = this.dataGridView1.Rows[r].Cells[0].Value.ToString();
            Form4 form4 = new Form4(userID);            
            form4.Show();
        }

        private void Form2_FormClosed(object sender, FormClosedEventArgs e)
        {
            Application.Exit();
        }
    }
}
