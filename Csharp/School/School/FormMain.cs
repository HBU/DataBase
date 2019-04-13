using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace School
{
    public partial class FormMain : Form
    {
        public FormMain()
        {
            InitializeComponent();
        }

        //判断窗口类型是否存在
        private bool IsExist(string formType)
        {
            bool flag = false;
            foreach (Form item in Application.OpenForms)
            {
                if (formType == item.GetType().ToString())
                    flag = true;
            }
            return flag;
        }

        //显示窗口
        public void ShowOnce(Form form)
        {
            //窗口已存在，则获取该窗口焦点
            if (IsExist(form.GetType().ToString()))
            {
                foreach (Form item in Application.OpenForms)
                {
                    if (item.GetType().ToString() == form.GetType().ToString())
                    {
                        //每次判断需要新建一个实例，在此释放
                        form.Dispose();
                        item.Show();
                        //获取窗口焦点
                        item.Activate();
                    }
                }
            }
            else
            {
                //窗口不存在，打开新窗口
                form.Show();
                form.Activate();
            }
        }
        private void 关闭ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void 关于ToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            FormAbout formAbout = new FormAbout();
            formAbout.ShowDialog();
        }

        private void 学生ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FormStudent formStudent = new FormStudent() { MdiParent = this };
            //formStudent.MdiParent = this;
            ShowOnce(formStudent);
        }

        private void 课程ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FormCourse formCourse = new FormCourse() { MdiParent = this };
            //formCourse.MdiParent = this;
            ShowOnce(formCourse);
        }

        private void 选课ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FormSC formSC = new FormSC() { MdiParent = this };
            //formSC.MdiParent = this;
            ShowOnce(formSC);
        }
    }
}
