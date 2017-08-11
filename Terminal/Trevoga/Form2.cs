using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Trevoga
{
    public partial class Form2 : Form
    {
        Form1 form1;
        public Form2(Form1 pointer)
        {
            InitializeComponent();
            this.form1 = pointer;
        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }

        private void Close_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void SaveButtons_Click(object sender, EventArgs e)
        {
            char[] buttons = new char[8];
            buttons[0] = '<';
            buttons[1] = '1';
            if (checkBox1.Checked == true)
            {
                buttons[2] = '1';
            }
            else
            {
                buttons[2] = '0';
            }

            if (checkBox2.Checked == true)
            {
                buttons[3] = '1';
            }
            else
            {
                buttons[3] = '0';
            }

            if (checkBox3.Checked == true)
            {
                buttons[4] = '1';
            }
            else
            {
                buttons[4] = '0';
            }

            if (checkBox4.Checked == true)
            {
                buttons[5] = '1';
            }
            else
            {
                buttons[5] = '0';
            }

            if (checkBox5.Checked == true)
            {
                buttons[6] = '1';
            }
            else
            {
                buttons[6] = '0';
            }
            buttons[7] = '>';

            form1.serialPort1.DiscardInBuffer();
            string buttonsCommand = new string(buttons);
            form1.serialPort1.WriteLine(buttonsCommand);
            System.Threading.Thread.Sleep(1000);
            string answer = form1.serialPort1.ReadExisting();
            if(answer != "")
            {
                MessageBox.Show(answer);
            }
        }
    }
}
