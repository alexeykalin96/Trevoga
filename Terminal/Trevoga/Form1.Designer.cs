namespace Trevoga
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.OpenPort = new System.Windows.Forms.Button();
            this.ClosePort = new System.Windows.Forms.Button();
            this.PortName = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.progressBar1 = new System.Windows.Forms.ProgressBar();
            this.label2 = new System.Windows.Forms.Label();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.SetButtons = new System.Windows.Forms.Button();
            this.SetSound = new System.Windows.Forms.Button();
            this.ComandString = new System.Windows.Forms.Button();
            this.Exit = new System.Windows.Forms.Button();
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.SuspendLayout();
            // 
            // OpenPort
            // 
            this.OpenPort.Image = ((System.Drawing.Image)(resources.GetObject("OpenPort.Image")));
            this.OpenPort.ImageAlign = System.Drawing.ContentAlignment.TopLeft;
            this.OpenPort.Location = new System.Drawing.Point(157, 23);
            this.OpenPort.Name = "OpenPort";
            this.OpenPort.Size = new System.Drawing.Size(132, 40);
            this.OpenPort.TabIndex = 0;
            this.OpenPort.Text = "      Соединиться";
            this.OpenPort.UseVisualStyleBackColor = true;
            this.OpenPort.Click += new System.EventHandler(this.OpenPort_Click);
            // 
            // ClosePort
            // 
            this.ClosePort.Enabled = false;
            this.ClosePort.Image = ((System.Drawing.Image)(resources.GetObject("ClosePort.Image")));
            this.ClosePort.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.ClosePort.Location = new System.Drawing.Point(325, 23);
            this.ClosePort.Name = "ClosePort";
            this.ClosePort.Size = new System.Drawing.Size(132, 40);
            this.ClosePort.TabIndex = 1;
            this.ClosePort.Text = "Отключиться";
            this.ClosePort.UseVisualStyleBackColor = true;
            this.ClosePort.Click += new System.EventHandler(this.ClosePort_Click);
            // 
            // PortName
            // 
            this.PortName.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.PortName.FormattingEnabled = true;
            this.PortName.Location = new System.Drawing.Point(22, 39);
            this.PortName.Name = "PortName";
            this.PortName.Size = new System.Drawing.Size(74, 21);
            this.PortName.TabIndex = 2;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(23, 23);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(61, 13);
            this.label1.TabIndex = 3;
            this.label1.Text = "Имя порта";
            // 
            // progressBar1
            // 
            this.progressBar1.ForeColor = System.Drawing.SystemColors.GrayText;
            this.progressBar1.Location = new System.Drawing.Point(306, 248);
            this.progressBar1.Name = "progressBar1";
            this.progressBar1.Size = new System.Drawing.Size(151, 23);
            this.progressBar1.TabIndex = 4;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(303, 222);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(93, 13);
            this.label2.TabIndex = 5;
            this.label2.Text = "Состояние порта";
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(22, 251);
            this.textBox1.Name = "textBox1";
            this.textBox1.ReadOnly = true;
            this.textBox1.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.textBox1.Size = new System.Drawing.Size(190, 20);
            this.textBox1.TabIndex = 6;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(23, 222);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(83, 13);
            this.label3.TabIndex = 7;
            this.label3.Text = "Монитор порта";
            // 
            // SetButtons
            // 
            this.SetButtons.Enabled = false;
            this.SetButtons.Image = ((System.Drawing.Image)(resources.GetObject("SetButtons.Image")));
            this.SetButtons.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.SetButtons.Location = new System.Drawing.Point(22, 80);
            this.SetButtons.Name = "SetButtons";
            this.SetButtons.Size = new System.Drawing.Size(176, 43);
            this.SetButtons.TabIndex = 8;
            this.SetButtons.Text = "Настроить кнопки";
            this.SetButtons.UseVisualStyleBackColor = true;
            this.SetButtons.Click += new System.EventHandler(this.SetButtons_Click);
            // 
            // SetSound
            // 
            this.SetSound.Enabled = false;
            this.SetSound.Image = ((System.Drawing.Image)(resources.GetObject("SetSound.Image")));
            this.SetSound.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.SetSound.Location = new System.Drawing.Point(22, 142);
            this.SetSound.Name = "SetSound";
            this.SetSound.Size = new System.Drawing.Size(176, 43);
            this.SetSound.TabIndex = 9;
            this.SetSound.Text = "Настроить звук";
            this.SetSound.UseVisualStyleBackColor = true;
            this.SetSound.Click += new System.EventHandler(this.SetSound_Click);
            // 
            // ComandString
            // 
            this.ComandString.Enabled = false;
            this.ComandString.Image = ((System.Drawing.Image)(resources.GetObject("ComandString.Image")));
            this.ComandString.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.ComandString.Location = new System.Drawing.Point(281, 80);
            this.ComandString.Name = "ComandString";
            this.ComandString.Size = new System.Drawing.Size(176, 42);
            this.ComandString.TabIndex = 10;
            this.ComandString.Text = "Командная строка";
            this.ComandString.UseVisualStyleBackColor = true;
            this.ComandString.Click += new System.EventHandler(this.ComandString_Click);
            // 
            // Exit
            // 
            this.Exit.Image = ((System.Drawing.Image)(resources.GetObject("Exit.Image")));
            this.Exit.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.Exit.Location = new System.Drawing.Point(281, 142);
            this.Exit.Name = "Exit";
            this.Exit.Size = new System.Drawing.Size(176, 43);
            this.Exit.TabIndex = 11;
            this.Exit.Text = "Выход";
            this.Exit.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(480, 280);
            this.Controls.Add(this.Exit);
            this.Controls.Add(this.ComandString);
            this.Controls.Add(this.SetSound);
            this.Controls.Add(this.SetButtons);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.progressBar1);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.PortName);
            this.Controls.Add(this.ClosePort);
            this.Controls.Add(this.OpenPort);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Тревожная кнопка";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button OpenPort;
        private System.Windows.Forms.Button ClosePort;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ProgressBar progressBar1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button SetButtons;
        private System.Windows.Forms.Button SetSound;
        private System.Windows.Forms.Button ComandString;
        private System.Windows.Forms.Button Exit;
        public System.IO.Ports.SerialPort serialPort1;
        private System.Windows.Forms.ComboBox PortName;
        public System.Windows.Forms.TextBox textBox1;
    }
}

