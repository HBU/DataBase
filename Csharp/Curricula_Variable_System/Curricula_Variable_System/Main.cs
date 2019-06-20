using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Curricula_Variable_System
{
    public partial class Main : Form
    {
        public Main()
        {
            InitializeComponent();
        }

        private void Main_FormClosed(object sender, FormClosedEventArgs e)
        {
            Application.Exit();
        }

        private void Main_Load(object sender, EventArgs e)
        {
            // TODO: 这行代码将数据加载到表“curricula_variable_systemDataSet.SC”中。您可以根据需要移动或删除它。
            this.sCTableAdapter.Fill(this.curricula_variable_systemDataSet.SC);
            // TODO: 这行代码将数据加载到表“curricula_variable_systemDataSet.Course”中。您可以根据需要移动或删除它。
            this.courseTableAdapter.Fill(this.curricula_variable_systemDataSet.Course);
            // TODO: 这行代码将数据加载到表“curricula_variable_systemDataSet.Student”中。您可以根据需要移动或删除它。
            this.studentTableAdapter.Fill(this.curricula_variable_systemDataSet.Student);
            // TODO: 这行代码将数据加载到表“curricula_variable_systemDataSet.SysLog”中。您可以根据需要移动或删除它。
            this.sysLogTableAdapter.Fill(this.curricula_variable_systemDataSet.SysLog);
            // TODO: 这行代码将数据加载到表“curricula_variable_systemDataSet.SysUser”中。您可以根据需要移动或删除它。
            this.sysUserTableAdapter.Fill(this.curricula_variable_systemDataSet.SysUser);

        }
    }
}
