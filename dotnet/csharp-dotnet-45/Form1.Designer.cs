namespace FloatSample
{
    partial class Form1
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
            this.leaseBtn = new System.Windows.Forms.Button();
            this.dropBtn = new System.Windows.Forms.Button();
            this.statusLabel = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // leaseBtn
            // 
            this.leaseBtn.Location = new System.Drawing.Point(12, 49);
            this.leaseBtn.Name = "leaseBtn";
            this.leaseBtn.Size = new System.Drawing.Size(117, 23);
            this.leaseBtn.TabIndex = 0;
            this.leaseBtn.Text = "Lease License";
            this.leaseBtn.UseVisualStyleBackColor = true;
            this.leaseBtn.Click += new System.EventHandler(this.leaseBtn_Click);
            // 
            // dropBtn
            // 
            this.dropBtn.Location = new System.Drawing.Point(250, 49);
            this.dropBtn.Name = "dropBtn";
            this.dropBtn.Size = new System.Drawing.Size(117, 23);
            this.dropBtn.TabIndex = 1;
            this.dropBtn.Text = "Drop License";
            this.dropBtn.UseVisualStyleBackColor = true;
            this.dropBtn.Click += new System.EventHandler(this.dropBtn_Click);
            // 
            // statusLabel
            // 
            this.statusLabel.AutoSize = true;
            this.statusLabel.Location = new System.Drawing.Point(12, 133);
            this.statusLabel.Name = "statusLabel";
            this.statusLabel.Size = new System.Drawing.Size(40, 13);
            this.statusLabel.TabIndex = 2;
            this.statusLabel.Text = "Status:";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(379, 170);
            this.Controls.Add(this.statusLabel);
            this.Controls.Add(this.dropBtn);
            this.Controls.Add(this.leaseBtn);
            this.Name = "Form1";
            this.Text = "Float Client";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button leaseBtn;
        private System.Windows.Forms.Button dropBtn;
        private System.Windows.Forms.Label statusLabel;
    }
}

