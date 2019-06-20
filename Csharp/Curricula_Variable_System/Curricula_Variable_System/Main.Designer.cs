namespace Curricula_Variable_System
{
    partial class Main
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.label2 = new System.Windows.Forms.Label();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.sysUserBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.curricula_variable_systemDataSet = new Curricula_Variable_System.curricula_variable_systemDataSet();
            this.sysUserTableAdapter = new Curricula_Variable_System.curricula_variable_systemDataSetTableAdapters.SysUserTableAdapter();
            this.dataGridView2 = new System.Windows.Forms.DataGridView();
            this.userIDDataGridViewTextBoxColumn1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dateAndTimeDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.userOperationDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.sysLogBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.sysLogTableAdapter = new Curricula_Variable_System.curricula_variable_systemDataSetTableAdapters.SysLogTableAdapter();
            this.dataGridView3 = new System.Windows.Forms.DataGridView();
            this.snoDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.snameDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.ssexDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.sageDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.sdeptDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.studentBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.studentTableAdapter = new Curricula_Variable_System.curricula_variable_systemDataSetTableAdapters.StudentTableAdapter();
            this.dataGridView4 = new System.Windows.Forms.DataGridView();
            this.cnoDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.cnameDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.cpnoDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.ccreditDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.courseBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.courseTableAdapter = new Curricula_Variable_System.curricula_variable_systemDataSetTableAdapters.CourseTableAdapter();
            this.dataGridView5 = new System.Windows.Forms.DataGridView();
            this.snoDataGridViewTextBoxColumn1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.cnoDataGridViewTextBoxColumn1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.gradeDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.sCBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.sCTableAdapter = new Curricula_Variable_System.curricula_variable_systemDataSetTableAdapters.SCTableAdapter();
            this.userIDDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.userPassWordDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.userSchoolIDDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.userMobileDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.userBirthdayDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.userIdentityDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.sysUserBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.curricula_variable_systemDataSet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.sysLogBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.studentBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView4)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.courseBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView5)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.sCBindingSource)).BeginInit();
            this.SuspendLayout();
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("宋体", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label2.Location = new System.Drawing.Point(236, 32);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(285, 21);
            this.label2.TabIndex = 1;
            this.label2.Text = "Curricula Variable System";
            // 
            // dataGridView1
            // 
            this.dataGridView1.AutoGenerateColumns = false;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.userIDDataGridViewTextBoxColumn,
            this.userPassWordDataGridViewTextBoxColumn,
            this.userSchoolIDDataGridViewTextBoxColumn,
            this.userMobileDataGridViewTextBoxColumn,
            this.userBirthdayDataGridViewTextBoxColumn,
            this.userIdentityDataGridViewTextBoxColumn});
            this.dataGridView1.DataSource = this.sysUserBindingSource;
            this.dataGridView1.Location = new System.Drawing.Point(12, 104);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowTemplate.Height = 23;
            this.dataGridView1.Size = new System.Drawing.Size(644, 150);
            this.dataGridView1.TabIndex = 2;
            // 
            // sysUserBindingSource
            // 
            this.sysUserBindingSource.DataMember = "SysUser";
            this.sysUserBindingSource.DataSource = this.curricula_variable_systemDataSet;
            // 
            // curricula_variable_systemDataSet
            // 
            this.curricula_variable_systemDataSet.DataSetName = "curricula_variable_systemDataSet";
            this.curricula_variable_systemDataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // sysUserTableAdapter
            // 
            this.sysUserTableAdapter.ClearBeforeFill = true;
            // 
            // dataGridView2
            // 
            this.dataGridView2.AutoGenerateColumns = false;
            this.dataGridView2.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView2.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.userIDDataGridViewTextBoxColumn1,
            this.dateAndTimeDataGridViewTextBoxColumn,
            this.userOperationDataGridViewTextBoxColumn});
            this.dataGridView2.DataSource = this.sysLogBindingSource;
            this.dataGridView2.Location = new System.Drawing.Point(12, 269);
            this.dataGridView2.Name = "dataGridView2";
            this.dataGridView2.RowTemplate.Height = 23;
            this.dataGridView2.Size = new System.Drawing.Size(644, 150);
            this.dataGridView2.TabIndex = 3;
            // 
            // userIDDataGridViewTextBoxColumn1
            // 
            this.userIDDataGridViewTextBoxColumn1.DataPropertyName = "UserID";
            this.userIDDataGridViewTextBoxColumn1.HeaderText = "UserID";
            this.userIDDataGridViewTextBoxColumn1.Name = "userIDDataGridViewTextBoxColumn1";
            // 
            // dateAndTimeDataGridViewTextBoxColumn
            // 
            this.dateAndTimeDataGridViewTextBoxColumn.DataPropertyName = "DateAndTime";
            this.dateAndTimeDataGridViewTextBoxColumn.HeaderText = "DateAndTime";
            this.dateAndTimeDataGridViewTextBoxColumn.Name = "dateAndTimeDataGridViewTextBoxColumn";
            // 
            // userOperationDataGridViewTextBoxColumn
            // 
            this.userOperationDataGridViewTextBoxColumn.DataPropertyName = "UserOperation";
            this.userOperationDataGridViewTextBoxColumn.HeaderText = "UserOperation";
            this.userOperationDataGridViewTextBoxColumn.Name = "userOperationDataGridViewTextBoxColumn";
            // 
            // sysLogBindingSource
            // 
            this.sysLogBindingSource.DataMember = "SysLog";
            this.sysLogBindingSource.DataSource = this.curricula_variable_systemDataSet;
            // 
            // sysLogTableAdapter
            // 
            this.sysLogTableAdapter.ClearBeforeFill = true;
            // 
            // dataGridView3
            // 
            this.dataGridView3.AutoGenerateColumns = false;
            this.dataGridView3.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView3.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.snoDataGridViewTextBoxColumn,
            this.snameDataGridViewTextBoxColumn,
            this.ssexDataGridViewTextBoxColumn,
            this.sageDataGridViewTextBoxColumn,
            this.sdeptDataGridViewTextBoxColumn});
            this.dataGridView3.DataSource = this.studentBindingSource;
            this.dataGridView3.Location = new System.Drawing.Point(766, 104);
            this.dataGridView3.Name = "dataGridView3";
            this.dataGridView3.RowTemplate.Height = 23;
            this.dataGridView3.Size = new System.Drawing.Size(546, 150);
            this.dataGridView3.TabIndex = 4;
            // 
            // snoDataGridViewTextBoxColumn
            // 
            this.snoDataGridViewTextBoxColumn.DataPropertyName = "Sno";
            this.snoDataGridViewTextBoxColumn.HeaderText = "Sno";
            this.snoDataGridViewTextBoxColumn.Name = "snoDataGridViewTextBoxColumn";
            // 
            // snameDataGridViewTextBoxColumn
            // 
            this.snameDataGridViewTextBoxColumn.DataPropertyName = "Sname";
            this.snameDataGridViewTextBoxColumn.HeaderText = "Sname";
            this.snameDataGridViewTextBoxColumn.Name = "snameDataGridViewTextBoxColumn";
            // 
            // ssexDataGridViewTextBoxColumn
            // 
            this.ssexDataGridViewTextBoxColumn.DataPropertyName = "Ssex";
            this.ssexDataGridViewTextBoxColumn.HeaderText = "Ssex";
            this.ssexDataGridViewTextBoxColumn.Name = "ssexDataGridViewTextBoxColumn";
            // 
            // sageDataGridViewTextBoxColumn
            // 
            this.sageDataGridViewTextBoxColumn.DataPropertyName = "Sage";
            this.sageDataGridViewTextBoxColumn.HeaderText = "Sage";
            this.sageDataGridViewTextBoxColumn.Name = "sageDataGridViewTextBoxColumn";
            // 
            // sdeptDataGridViewTextBoxColumn
            // 
            this.sdeptDataGridViewTextBoxColumn.DataPropertyName = "Sdept";
            this.sdeptDataGridViewTextBoxColumn.HeaderText = "Sdept";
            this.sdeptDataGridViewTextBoxColumn.Name = "sdeptDataGridViewTextBoxColumn";
            // 
            // studentBindingSource
            // 
            this.studentBindingSource.DataMember = "Student";
            this.studentBindingSource.DataSource = this.curricula_variable_systemDataSet;
            // 
            // studentTableAdapter
            // 
            this.studentTableAdapter.ClearBeforeFill = true;
            // 
            // dataGridView4
            // 
            this.dataGridView4.AutoGenerateColumns = false;
            this.dataGridView4.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView4.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.cnoDataGridViewTextBoxColumn,
            this.cnameDataGridViewTextBoxColumn,
            this.cpnoDataGridViewTextBoxColumn,
            this.ccreditDataGridViewTextBoxColumn});
            this.dataGridView4.DataSource = this.courseBindingSource;
            this.dataGridView4.Location = new System.Drawing.Point(766, 269);
            this.dataGridView4.Name = "dataGridView4";
            this.dataGridView4.RowTemplate.Height = 23;
            this.dataGridView4.Size = new System.Drawing.Size(546, 150);
            this.dataGridView4.TabIndex = 5;
            // 
            // cnoDataGridViewTextBoxColumn
            // 
            this.cnoDataGridViewTextBoxColumn.DataPropertyName = "Cno";
            this.cnoDataGridViewTextBoxColumn.HeaderText = "Cno";
            this.cnoDataGridViewTextBoxColumn.Name = "cnoDataGridViewTextBoxColumn";
            // 
            // cnameDataGridViewTextBoxColumn
            // 
            this.cnameDataGridViewTextBoxColumn.DataPropertyName = "Cname";
            this.cnameDataGridViewTextBoxColumn.HeaderText = "Cname";
            this.cnameDataGridViewTextBoxColumn.Name = "cnameDataGridViewTextBoxColumn";
            // 
            // cpnoDataGridViewTextBoxColumn
            // 
            this.cpnoDataGridViewTextBoxColumn.DataPropertyName = "Cpno";
            this.cpnoDataGridViewTextBoxColumn.HeaderText = "Cpno";
            this.cpnoDataGridViewTextBoxColumn.Name = "cpnoDataGridViewTextBoxColumn";
            // 
            // ccreditDataGridViewTextBoxColumn
            // 
            this.ccreditDataGridViewTextBoxColumn.DataPropertyName = "Ccredit";
            this.ccreditDataGridViewTextBoxColumn.HeaderText = "Ccredit";
            this.ccreditDataGridViewTextBoxColumn.Name = "ccreditDataGridViewTextBoxColumn";
            // 
            // courseBindingSource
            // 
            this.courseBindingSource.DataMember = "Course";
            this.courseBindingSource.DataSource = this.curricula_variable_systemDataSet;
            // 
            // courseTableAdapter
            // 
            this.courseTableAdapter.ClearBeforeFill = true;
            // 
            // dataGridView5
            // 
            this.dataGridView5.AutoGenerateColumns = false;
            this.dataGridView5.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView5.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.snoDataGridViewTextBoxColumn1,
            this.cnoDataGridViewTextBoxColumn1,
            this.gradeDataGridViewTextBoxColumn});
            this.dataGridView5.DataSource = this.sCBindingSource;
            this.dataGridView5.Location = new System.Drawing.Point(766, 434);
            this.dataGridView5.Name = "dataGridView5";
            this.dataGridView5.RowTemplate.Height = 23;
            this.dataGridView5.Size = new System.Drawing.Size(546, 150);
            this.dataGridView5.TabIndex = 6;
            // 
            // snoDataGridViewTextBoxColumn1
            // 
            this.snoDataGridViewTextBoxColumn1.DataPropertyName = "Sno";
            this.snoDataGridViewTextBoxColumn1.HeaderText = "Sno";
            this.snoDataGridViewTextBoxColumn1.Name = "snoDataGridViewTextBoxColumn1";
            // 
            // cnoDataGridViewTextBoxColumn1
            // 
            this.cnoDataGridViewTextBoxColumn1.DataPropertyName = "Cno";
            this.cnoDataGridViewTextBoxColumn1.HeaderText = "Cno";
            this.cnoDataGridViewTextBoxColumn1.Name = "cnoDataGridViewTextBoxColumn1";
            // 
            // gradeDataGridViewTextBoxColumn
            // 
            this.gradeDataGridViewTextBoxColumn.DataPropertyName = "Grade";
            this.gradeDataGridViewTextBoxColumn.HeaderText = "Grade";
            this.gradeDataGridViewTextBoxColumn.Name = "gradeDataGridViewTextBoxColumn";
            // 
            // sCBindingSource
            // 
            this.sCBindingSource.DataMember = "SC";
            this.sCBindingSource.DataSource = this.curricula_variable_systemDataSet;
            // 
            // sCTableAdapter
            // 
            this.sCTableAdapter.ClearBeforeFill = true;
            // 
            // userIDDataGridViewTextBoxColumn
            // 
            this.userIDDataGridViewTextBoxColumn.DataPropertyName = "UserID";
            this.userIDDataGridViewTextBoxColumn.HeaderText = "UserID";
            this.userIDDataGridViewTextBoxColumn.Name = "userIDDataGridViewTextBoxColumn";
            // 
            // userPassWordDataGridViewTextBoxColumn
            // 
            this.userPassWordDataGridViewTextBoxColumn.DataPropertyName = "UserPassWord";
            this.userPassWordDataGridViewTextBoxColumn.HeaderText = "UserPassWord";
            this.userPassWordDataGridViewTextBoxColumn.Name = "userPassWordDataGridViewTextBoxColumn";
            // 
            // userSchoolIDDataGridViewTextBoxColumn
            // 
            this.userSchoolIDDataGridViewTextBoxColumn.DataPropertyName = "UserSchoolID";
            this.userSchoolIDDataGridViewTextBoxColumn.HeaderText = "UserSchoolID";
            this.userSchoolIDDataGridViewTextBoxColumn.Name = "userSchoolIDDataGridViewTextBoxColumn";
            // 
            // userMobileDataGridViewTextBoxColumn
            // 
            this.userMobileDataGridViewTextBoxColumn.DataPropertyName = "UserMobile";
            this.userMobileDataGridViewTextBoxColumn.HeaderText = "UserMobile";
            this.userMobileDataGridViewTextBoxColumn.Name = "userMobileDataGridViewTextBoxColumn";
            // 
            // userBirthdayDataGridViewTextBoxColumn
            // 
            this.userBirthdayDataGridViewTextBoxColumn.DataPropertyName = "UserBirthday";
            this.userBirthdayDataGridViewTextBoxColumn.HeaderText = "UserBirthday";
            this.userBirthdayDataGridViewTextBoxColumn.Name = "userBirthdayDataGridViewTextBoxColumn";
            // 
            // userIdentityDataGridViewTextBoxColumn
            // 
            this.userIdentityDataGridViewTextBoxColumn.DataPropertyName = "UserIdentity";
            this.userIdentityDataGridViewTextBoxColumn.HeaderText = "UserIdentity";
            this.userIdentityDataGridViewTextBoxColumn.Name = "userIdentityDataGridViewTextBoxColumn";
            // 
            // Main
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1317, 744);
            this.Controls.Add(this.dataGridView5);
            this.Controls.Add(this.dataGridView4);
            this.Controls.Add(this.dataGridView3);
            this.Controls.Add(this.dataGridView2);
            this.Controls.Add(this.dataGridView1);
            this.Controls.Add(this.label2);
            this.Name = "Main";
            this.Text = "Main";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.Main_FormClosed);
            this.Load += new System.EventHandler(this.Main_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.sysUserBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.curricula_variable_systemDataSet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.sysLogBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.studentBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView4)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.courseBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView5)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.sCBindingSource)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.DataGridView dataGridView1;
        private curricula_variable_systemDataSet curricula_variable_systemDataSet;
        private System.Windows.Forms.BindingSource sysUserBindingSource;
        private curricula_variable_systemDataSetTableAdapters.SysUserTableAdapter sysUserTableAdapter;
        private System.Windows.Forms.DataGridView dataGridView2;
        private System.Windows.Forms.BindingSource sysLogBindingSource;
        private curricula_variable_systemDataSetTableAdapters.SysLogTableAdapter sysLogTableAdapter;
        private System.Windows.Forms.DataGridViewTextBoxColumn userIDDataGridViewTextBoxColumn1;
        private System.Windows.Forms.DataGridViewTextBoxColumn dateAndTimeDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn userOperationDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridView dataGridView3;
        private System.Windows.Forms.BindingSource studentBindingSource;
        private curricula_variable_systemDataSetTableAdapters.StudentTableAdapter studentTableAdapter;
        private System.Windows.Forms.DataGridViewTextBoxColumn snoDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn snameDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn ssexDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn sageDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn sdeptDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridView dataGridView4;
        private System.Windows.Forms.BindingSource courseBindingSource;
        private curricula_variable_systemDataSetTableAdapters.CourseTableAdapter courseTableAdapter;
        private System.Windows.Forms.DataGridViewTextBoxColumn cnoDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn cnameDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn cpnoDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn ccreditDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridView dataGridView5;
        private System.Windows.Forms.BindingSource sCBindingSource;
        private curricula_variable_systemDataSetTableAdapters.SCTableAdapter sCTableAdapter;
        private System.Windows.Forms.DataGridViewTextBoxColumn snoDataGridViewTextBoxColumn1;
        private System.Windows.Forms.DataGridViewTextBoxColumn cnoDataGridViewTextBoxColumn1;
        private System.Windows.Forms.DataGridViewTextBoxColumn gradeDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn userIDDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn userPassWordDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn userSchoolIDDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn userMobileDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn userBirthdayDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn userIdentityDataGridViewTextBoxColumn;
    }
}