using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;

namespace Trevoga
{
    public partial class Form4 : Form
    {
        Form1 form1;
        public Form4(Form1 pointer)
        {
            InitializeComponent();
            this.form1 = pointer;
        }

        private void Form4_Load(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void SendComandClick(object sender, EventArgs e)
        {
            try
            {
                form1.serialPort1.WriteLine(textBox1.Text);
                textBox1.Text = "";
                System.Threading.Thread.Sleep(1000);
                string answer = form1.serialPort1.ReadExisting();
                if(answer != "")
                {
                    textBox2.Text += answer;
                    textBox2.Text += Environment.NewLine;
                }
            }
            catch
            {

            }

        }

        private void ClearMonitorPort_Click(object sender, EventArgs e)
        {
            textBox2.Text = "";
        }
    }
}
