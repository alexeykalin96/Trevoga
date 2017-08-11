namespace Trevoga
{
    partial class Form2
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
            this.checkBox1 = new System.Windows.Forms.CheckBox();
            this.checkBox2 = new System.Windows.Forms.CheckBox();
            this.checkBox3 = new System.Windows.Forms.CheckBox();
            this.checkBox4 = new System.Windows.Forms.CheckBox();
            this.checkBox5 = new System.Windows.Forms.CheckBox();
            this.Buttons = new System.Windows.Forms.GroupBox();
            this.SaveButtons = new System.Windows.Forms.Button();
            this.Close = new System.Windows.Forms.Button();
            this.Buttons.SuspendLayout();
            this.SuspendLayout();
            // 
            // checkBox1
            // 
            this.checkBox1.AutoSize = true;
            this.checkBox1.Location = new System.Drawing.Point(20, 30);
            this.checkBox1.Name = "checkBox1";
            this.checkBox1.Size = new System.Drawing.Size(72, 17);
            this.checkBox1.TabIndex = 0;
            this.checkBox1.Text = "Кнопка 1";
            this.checkBox1.UseVisualStyleBackColor = true;
            // 
            // checkBox2
            // 
            this.checkBox2.AutoSize = true;
            this.checkBox2.Location = new System.Drawing.Point(20, 54);
            this.checkBox2.Name = "checkBox2";
            this.checkBox2.Size = new System.Drawing.Size(72, 17);
            this.checkBox2.TabIndex = 1;
            this.checkBox2.Text = "Кнопка 2";
            this.checkBox2.UseVisualStyleBackColor = true;
            // 
            // checkBox3
            // 
            this.checkBox3.AutoSize = true;
            this.checkBox3.Location = new System.Drawing.Point(20, 78);
            this.checkBox3.Name = "checkBox3";
            this.checkBox3.Size = new System.Drawing.Size(72, 17);
            this.checkBox3.TabIndex = 2;
            this.checkBox3.Text = "Кнопка 3";
            this.checkBox3.UseVisualStyleBackColor = true;
            // 
            // checkBox4
            // 
            this.checkBox4.AutoSize = true;
            this.checkBox4.Location = new System.Drawing.Point(20, 102);
            this.checkBox4.Name = "checkBox4";
            this.checkBox4.Size = new System.Drawing.Size(72, 17);
            this.checkBox4.TabIndex = 3;
            this.checkBox4.Text = "Кнопка 4";
            this.checkBox4.UseVisualStyleBackColor = true;
            // 
            // checkBox5
            // 
            this.checkBox5.AutoSize = true;
            this.checkBox5.Location = new System.Drawing.Point(20, 126);
            this.checkBox5.Name = "checkBox5";
            this.checkBox5.Size = new System.Drawing.Size(72, 17);
            this.checkBox5.TabIndex = 4;
            this.checkBox5.Text = "Кнопка 5";
            this.checkBox5.UseVisualStyleBackColor = true;
            // 
            // Buttons
            // 
            this.Buttons.Controls.Add(this.checkBox5);
            this.Buttons.Controls.Add(this.checkBox4);
            this.Buttons.Controls.Add(this.checkBox1);
            this.Buttons.Controls.Add(this.checkBox3);
            this.Buttons.Controls.Add(this.checkBox2);
            this.Buttons.Location = new System.Drawing.Point(12, 12);
            this.Buttons.Name = "Buttons";
            this.Buttons.Size = new System.Drawing.Size(260, 163);
            this.Buttons.TabIndex = 5;
            this.Buttons.TabStop = false;
            this.Buttons.Text = "Выберете активные кнопки";
            // 
            // SaveButtons
            // 
            this.SaveButtons.Location = new System.Drawing.Point(12, 192);
            this.SaveButtons.Name = "SaveButtons";
            this.SaveButtons.Size = new System.Drawing.Size(75, 23);
            this.SaveButtons.TabIndex = 6;
            this.SaveButtons.Text = "Сохранить";
            this.SaveButtons.UseVisualStyleBackColor = true;
            this.SaveButtons.Click += new System.EventHandler(this.SaveButtons_Click);
            // 
            // Close
            // 
            this.Close.Location = new System.Drawing.Point(197, 192);
            this.Close.Name = "Close";
            this.Close.Size = new System.Drawing.Size(75, 23);
            this.Close.TabIndex = 7;
            this.Close.Text = "Закрыть";
            this.Close.UseVisualStyleBackColor = true;
            this.Close.Click += new System.EventHandler(this.Close_Click);
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 227);
            this.ControlBox = false;
            this.Controls.Add(this.Close);
            this.Controls.Add(this.SaveButtons);
            this.Controls.Add(this.Buttons);
            this.Name = "Form2";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Настроить кнопки";
            this.Load += new System.EventHandler(this.Form2_Load);
            this.Buttons.ResumeLayout(false);
            this.Buttons.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.CheckBox checkBox1;
        private System.Windows.Forms.CheckBox checkBox2;
        private System.Windows.Forms.CheckBox checkBox3;
        private System.Windows.Forms.CheckBox checkBox4;
        private System.Windows.Forms.CheckBox checkBox5;
        private System.Windows.Forms.GroupBox Buttons;
        private System.Windows.Forms.Button SaveButtons;
        private System.Windows.Forms.Button Close;
    }
}