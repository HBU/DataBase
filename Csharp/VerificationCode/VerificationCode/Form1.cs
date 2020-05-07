using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace VerificationCode
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        Random random = new Random();
        String verificationCode = "";

        private void button1_Click(object sender, EventArgs e)
        {
            if (verificationCode == textBox1.Text.Trim())
                MessageBox.Show("Right！", "Notice", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
            else
                MessageBox.Show("Wrong！", "Notice", MessageBoxButtons.OK, MessageBoxIcon.Error);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //Ref: https://blog.csdn.net/abraham_ly/article/details/105463889
            verificationCode = "";
            for (int i = 0; i < 4; i++)
            {
                int type = random.Next(0, 2);
                if (type == 0)
                {
                    verificationCode += ((char)random.Next(65, 91)).ToString();
                }
                else
                {
                    verificationCode = verificationCode + random.Next(0, 10).ToString();
                }    
            }
            label1.Text = verificationCode;
        }
    }
}
