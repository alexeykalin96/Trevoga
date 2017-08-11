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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            getAvailablePorts();
        }

        void getAvailablePorts()
        {
            String[] ports = SerialPort.GetPortNames();
            PortName.Items.AddRange(ports);
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void OpenPort_Click(object sender, EventArgs e)
        {
            try
            {
                if(PortName.Text == "")
                {
                    MessageBox.Show("Выберите имя порта");
                }
                else
                {
                    serialPort1.PortName = PortName.Text;
                    serialPort1.BaudRate = 9600;
                    serialPort1.Open();
                    textBox1.Text = "Порт " + PortName.Text + " открыт";
                    progressBar1.Value = 100;
                    OpenPort.Enabled = false;
                    ClosePort.Enabled = true;
                    SetButtons.Enabled = true;
                    SetSound.Enabled = true;
                    ComandString.Enabled = true;
                    serialPort1.WriteLine("<progrY>");
                }
            }
            catch
            {

            }
        }

        private void ClosePort_Click(object sender, EventArgs e)
        {
            serialPort1.WriteLine("<progrN>");
            serialPort1.Close();
            textBox1.Text = "Порт " + PortName.Text + " закрыт";
            progressBar1.Value = 0;
            OpenPort.Enabled = true;
            ClosePort.Enabled = false;
            SetButtons.Enabled = false;
            SetSound.Enabled = false;
            ComandString.Enabled = false;
        }

        private void SetButtons_Click(object sender, EventArgs e)
        {
            Form2 newForm2 = new Form2(this);
            newForm2.Show();
        }

        private void SetSound_Click(object sender, EventArgs e)
        {
            Form3 newForm3 = new Form3();
            newForm3.Show();
        }

        private void ComandString_Click(object sender, EventArgs e)
        {
            Form4 newForm4 = new Form4(this);
            newForm4.Show();
        }
    }
}
