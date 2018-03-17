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
    public partial class Form4 : Form
    {
        public Form4()
        {
            InitializeComponent();
        }
        public Form4(string str)
        {
            InitializeComponent();
            textBox1.Text = str;//这句必须放在InitializeComponent();的后面，否则会引起“空引用异常”
            textBox1.Enabled = false;
        }
        private void button1_Click(object sender, EventArgs e)
        {
            this.userTableAdapter1.UpdateQuery(textBox2.Text, textBox1.Text);
            this.Close();
        }
    }
}
