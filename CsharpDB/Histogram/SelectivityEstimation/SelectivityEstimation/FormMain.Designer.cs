namespace SelectivityEstimation
{
    partial class FormMain
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.buttonRUN = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.linkLabel1 = new System.Windows.Forms.LinkLabel();
            this.comboBox3 = new System.Windows.Forms.ComboBox();
            this.buttonClose = new System.Windows.Forms.Button();
            this.comboBox2 = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.labelResult = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.label12 = new System.Windows.Forms.Label();
            this.comboBox4 = new System.Windows.Forms.ComboBox();
            this.comboBox5 = new System.Windows.Forms.ComboBox();
            this.comboBox6 = new System.Windows.Forms.ComboBox();
            this.labelMaxMin = new System.Windows.Forms.Label();
            this.labelTime = new System.Windows.Forms.Label();
            this.labelRect = new System.Windows.Forms.Label();
            this.labelDuplicated = new System.Windows.Forms.Label();
            this.labelRD = new System.Windows.Forms.Label();
            this.labelDB = new System.Windows.Forms.Label();
            this.label13 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // buttonRUN
            // 
            this.buttonRUN.Font = new System.Drawing.Font("Cambria", 15F);
            this.buttonRUN.Location = new System.Drawing.Point(1010, 631);
            this.buttonRUN.Name = "buttonRUN";
            this.buttonRUN.Size = new System.Drawing.Size(88, 38);
            this.buttonRUN.TabIndex = 13;
            this.buttonRUN.Text = "RUN";
            this.buttonRUN.UseVisualStyleBackColor = true;
            this.buttonRUN.Click += new System.EventHandler(this.buttonRun_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Cambria", 26.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.ForeColor = System.Drawing.Color.MidnightBlue;
            this.label4.Location = new System.Drawing.Point(27, 20);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(345, 41);
            this.label4.TabIndex = 18;
            this.label4.Text = "Select DataSet Table";
            // 
            // linkLabel1
            // 
            this.linkLabel1.AutoSize = true;
            this.linkLabel1.Font = new System.Drawing.Font("Cambria", 13F);
            this.linkLabel1.Location = new System.Drawing.Point(30, 592);
            this.linkLabel1.Name = "linkLabel1";
            this.linkLabel1.Size = new System.Drawing.Size(180, 21);
            this.linkLabel1.TabIndex = 19;
            this.linkLabel1.TabStop = true;
            this.linkLabel1.Text = "Database connect test";
            this.linkLabel1.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.linkLabel1_LinkClicked);
            // 
            // comboBox3
            // 
            this.comboBox3.Enabled = false;
            this.comboBox3.Font = new System.Drawing.Font("Cambria", 15F);
            this.comboBox3.FormattingEnabled = true;
            this.comboBox3.Location = new System.Drawing.Point(30, 280);
            this.comboBox3.Name = "comboBox3";
            this.comboBox3.Size = new System.Drawing.Size(328, 31);
            this.comboBox3.TabIndex = 17;
            // 
            // buttonClose
            // 
            this.buttonClose.Font = new System.Drawing.Font("Cambria", 15F);
            this.buttonClose.Location = new System.Drawing.Point(1120, 631);
            this.buttonClose.Name = "buttonClose";
            this.buttonClose.Size = new System.Drawing.Size(88, 38);
            this.buttonClose.TabIndex = 14;
            this.buttonClose.Text = "CLOSE";
            this.buttonClose.UseVisualStyleBackColor = true;
            this.buttonClose.Click += new System.EventHandler(this.buttonClose_Click);
            // 
            // comboBox2
            // 
            this.comboBox2.Enabled = false;
            this.comboBox2.Font = new System.Drawing.Font("Cambria", 15F);
            this.comboBox2.FormattingEnabled = true;
            this.comboBox2.Location = new System.Drawing.Point(30, 198);
            this.comboBox2.Name = "comboBox2";
            this.comboBox2.Size = new System.Drawing.Size(328, 31);
            this.comboBox2.TabIndex = 16;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Cambria", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(30, 79);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(136, 23);
            this.label1.TabIndex = 10;
            this.label1.Text = "DataSet Table :";
            // 
            // comboBox1
            // 
            this.comboBox1.Font = new System.Drawing.Font("Cambria", 15F);
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Location = new System.Drawing.Point(30, 116);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(328, 31);
            this.comboBox1.TabIndex = 15;
            this.comboBox1.SelectedIndexChanged += new System.EventHandler(this.comboBox1_SelectedIndexChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Cambria", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(30, 161);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(148, 23);
            this.label2.TabIndex = 11;
            this.label2.Text = "Workload Table:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Cambria", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(30, 243);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(151, 23);
            this.label3.TabIndex = 12;
            this.label3.Text = "KB Profile Table:";
            // 
            // groupBox1
            // 
            this.groupBox1.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.groupBox1.Location = new System.Drawing.Point(388, 23);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(15, 561);
            this.groupBox1.TabIndex = 20;
            this.groupBox1.TabStop = false;
            // 
            // labelResult
            // 
            this.labelResult.AutoSize = true;
            this.labelResult.Font = new System.Drawing.Font("Cambria", 15F);
            this.labelResult.ForeColor = System.Drawing.SystemColors.ControlText;
            this.labelResult.Location = new System.Drawing.Point(436, 60);
            this.labelResult.Name = "labelResult";
            this.labelResult.Size = new System.Drawing.Size(0, 23);
            this.labelResult.TabIndex = 21;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Cambria", 15F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.ForeColor = System.Drawing.Color.SteelBlue;
            this.label6.Location = new System.Drawing.Point(436, 23);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(86, 23);
            this.label6.TabIndex = 23;
            this.label6.Text = "Dataset:";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Cambria", 15F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.ForeColor = System.Drawing.Color.SteelBlue;
            this.label5.Location = new System.Drawing.Point(436, 148);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(241, 23);
            this.label5.TabIndex = 25;
            this.label5.Text = "MaxPonint and MinPoint:";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Font = new System.Drawing.Font("Cambria", 15F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label8.ForeColor = System.Drawing.Color.SteelBlue;
            this.label8.Location = new System.Drawing.Point(436, 256);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(213, 23);
            this.label8.TabIndex = 26;
            this.label8.Text = "Load Data, Time used:";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Font = new System.Drawing.Font("Cambria", 15F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label9.ForeColor = System.Drawing.Color.SteelBlue;
            this.label9.Location = new System.Drawing.Point(436, 402);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(239, 23);
            this.label9.TabIndex = 27;
            this.label9.Text = "Divided Data, Time used:";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Font = new System.Drawing.Font("Cambria", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label10.Location = new System.Drawing.Point(30, 325);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(242, 23);
            this.label10.TabIndex = 28;
            this.label10.Text = "Clean DataSet Table[result]";
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Font = new System.Drawing.Font("Cambria", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label11.Location = new System.Drawing.Point(30, 407);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(199, 23);
            this.label11.TabIndex = 29;
            this.label11.Text = "Insert Table ( results):";
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Font = new System.Drawing.Font("Cambria", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label12.Location = new System.Drawing.Point(30, 489);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(234, 23);
            this.label12.TabIndex = 30;
            this.label12.Text = "Insert Candidate [results]:";
            // 
            // comboBox4
            // 
            this.comboBox4.Enabled = false;
            this.comboBox4.Font = new System.Drawing.Font("Cambria", 15F);
            this.comboBox4.FormattingEnabled = true;
            this.comboBox4.Location = new System.Drawing.Point(30, 362);
            this.comboBox4.Name = "comboBox4";
            this.comboBox4.Size = new System.Drawing.Size(328, 31);
            this.comboBox4.TabIndex = 31;
            // 
            // comboBox5
            // 
            this.comboBox5.Enabled = false;
            this.comboBox5.Font = new System.Drawing.Font("Cambria", 15F);
            this.comboBox5.FormattingEnabled = true;
            this.comboBox5.Location = new System.Drawing.Point(30, 444);
            this.comboBox5.Name = "comboBox5";
            this.comboBox5.Size = new System.Drawing.Size(328, 31);
            this.comboBox5.TabIndex = 32;
            // 
            // comboBox6
            // 
            this.comboBox6.Enabled = false;
            this.comboBox6.Font = new System.Drawing.Font("Cambria", 15F);
            this.comboBox6.FormattingEnabled = true;
            this.comboBox6.Location = new System.Drawing.Point(30, 526);
            this.comboBox6.Name = "comboBox6";
            this.comboBox6.Size = new System.Drawing.Size(328, 31);
            this.comboBox6.TabIndex = 33;
            // 
            // labelMaxMin
            // 
            this.labelMaxMin.AutoSize = true;
            this.labelMaxMin.Font = new System.Drawing.Font("Cambria", 15F);
            this.labelMaxMin.Location = new System.Drawing.Point(436, 185);
            this.labelMaxMin.Name = "labelMaxMin";
            this.labelMaxMin.Size = new System.Drawing.Size(0, 23);
            this.labelMaxMin.TabIndex = 34;
            // 
            // labelTime
            // 
            this.labelTime.AutoSize = true;
            this.labelTime.Font = new System.Drawing.Font("Cambria", 15F);
            this.labelTime.Location = new System.Drawing.Point(436, 297);
            this.labelTime.Name = "labelTime";
            this.labelTime.Size = new System.Drawing.Size(0, 23);
            this.labelTime.TabIndex = 35;
            // 
            // labelRect
            // 
            this.labelRect.AutoSize = true;
            this.labelRect.Font = new System.Drawing.Font("Cambria", 15F);
            this.labelRect.Location = new System.Drawing.Point(436, 443);
            this.labelRect.Name = "labelRect";
            this.labelRect.Size = new System.Drawing.Size(0, 23);
            this.labelRect.TabIndex = 36;
            // 
            // labelDuplicated
            // 
            this.labelDuplicated.AutoSize = true;
            this.labelDuplicated.Font = new System.Drawing.Font("Cambria", 15F);
            this.labelDuplicated.Location = new System.Drawing.Point(436, 535);
            this.labelDuplicated.Name = "labelDuplicated";
            this.labelDuplicated.Size = new System.Drawing.Size(0, 23);
            this.labelDuplicated.TabIndex = 38;
            // 
            // labelRD
            // 
            this.labelRD.AutoSize = true;
            this.labelRD.Font = new System.Drawing.Font("Cambria", 15F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelRD.ForeColor = System.Drawing.Color.SteelBlue;
            this.labelRD.Location = new System.Drawing.Point(436, 494);
            this.labelRD.Name = "labelRD";
            this.labelRD.Size = new System.Drawing.Size(344, 23);
            this.labelRD.TabIndex = 37;
            this.labelRD.Text = "Remove duplicated Data, Time used:";
            // 
            // labelDB
            // 
            this.labelDB.AutoSize = true;
            this.labelDB.Font = new System.Drawing.Font("Cambria", 15F);
            this.labelDB.Location = new System.Drawing.Point(436, 622);
            this.labelDB.Name = "labelDB";
            this.labelDB.Size = new System.Drawing.Size(0, 23);
            this.labelDB.TabIndex = 40;
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Font = new System.Drawing.Font("Cambria", 15F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label13.ForeColor = System.Drawing.Color.SteelBlue;
            this.label13.Location = new System.Drawing.Point(436, 581);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(425, 23);
            this.label13.TabIndex = 39;
            this.label13.Text = "Insert cleaned data into database, Time used:";
            // 
            // FormMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1231, 698);
            this.Controls.Add(this.labelDB);
            this.Controls.Add(this.label13);
            this.Controls.Add(this.labelDuplicated);
            this.Controls.Add(this.labelRD);
            this.Controls.Add(this.labelRect);
            this.Controls.Add(this.labelTime);
            this.Controls.Add(this.labelMaxMin);
            this.Controls.Add(this.comboBox6);
            this.Controls.Add(this.comboBox5);
            this.Controls.Add(this.comboBox4);
            this.Controls.Add(this.label12);
            this.Controls.Add(this.label11);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.labelResult);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.buttonRUN);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.linkLabel1);
            this.Controls.Add(this.comboBox3);
            this.Controls.Add(this.buttonClose);
            this.Controls.Add(this.comboBox2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.comboBox1);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label3);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "FormMain";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Selectivity Estimation";
            this.Load += new System.EventHandler(this.FormMain_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button buttonRUN;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.LinkLabel linkLabel1;
        private System.Windows.Forms.ComboBox comboBox3;
        private System.Windows.Forms.Button buttonClose;
        private System.Windows.Forms.ComboBox comboBox2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox comboBox1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label labelResult;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.ComboBox comboBox4;
        private System.Windows.Forms.ComboBox comboBox5;
        private System.Windows.Forms.ComboBox comboBox6;
        private System.Windows.Forms.Label labelMaxMin;
        private System.Windows.Forms.Label labelTime;
        private System.Windows.Forms.Label labelRect;
        private System.Windows.Forms.Label labelDuplicated;
        private System.Windows.Forms.Label labelRD;
        private System.Windows.Forms.Label labelDB;
        private System.Windows.Forms.Label label13;
    }
}

