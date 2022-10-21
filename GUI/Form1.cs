using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CI_lab2
{
    public partial class Form1 : Form
    {
        SerialPort serialPort;

        private string data_rx = "";
        private bool start_Receive = false;

        private const int BAUD_RATE = 9600;
        private const int DATA_BITS = 8;
        private const String STATUS_CONNECTED = "Connected";
        private const String STATUS_DISCONNECTED = "Disconnected";
        private const char LED_ON = '#';
        private const char LED_OFF = '$';
        private const int MAX_TEMP = 9;
        private const int TICK_FREQ = 1;

        public Form1()
        {
            InitializeComponent();
            lbl_status.ForeColor = Color.Red;
            /* bar_fanSpeed */
            bar_fanSpeed.Maximum = MAX_TEMP;
            bar_fanSpeed.TickFrequency = TICK_FREQ;

            lbl_temp.Text = bar_fanSpeed.Value.ToString();
            refreshPorts();
        }

        private void btn_disconnect_Click(object sender, EventArgs e)
        {
            disconnectPort();
        }

        private void btn_resfresh_Click(object sender, EventArgs e)
        {
            refreshPorts();
        }

        private void btn_connect_Click(object sender, EventArgs e)
        {
            serialPort = new SerialPort(cmb_ports.SelectedItem.ToString());
            initConfig();
            connectPort();
        }

        private void initConfig()
        {
            serialPort.StopBits = StopBits.One;
            serialPort.BaudRate = BAUD_RATE;
            serialPort.DataBits = DATA_BITS;
        }

        private void connectPort()
        {
            try
            {
                if (!serialPort.IsOpen)
                {
                    serialPort.Open();
                    serialPort.DataReceived += new SerialDataReceivedEventHandler(rxData_Handler);
                    lbl_status.Text = STATUS_CONNECTED;
                    lbl_status.ForeColor = Color.Green;
                }
            }
            catch (Exception e)
            {

            }
        }
        private void disconnectPort()
        {
            if (serialPort == null)
            {
                return;
            }
            try
            {
                if (serialPort.IsOpen)
                {
                    serialPort.Close();
                    lbl_status.Text = STATUS_DISCONNECTED;
                    lbl_status.ForeColor = Color.Red;
                }
            }
            catch (Exception e)
            {

            }
        }
        private void refreshPorts()
        {
            cmb_ports.DataSource = SerialPort.GetPortNames();
        }






        private void btn_send_Click(object sender, EventArgs e)
        {
            String data = txtBox_tData.Text.ToString();
            sendSerialData(data);
        }

        private void sendSerialData(String data)
        {
            serialPort.Write(data);
        }

        private void btn_turnON_Click(object sender, EventArgs e)
        {
            sendSerialData(LED_ON.ToString());
        }

        private void btn_turnOFF_Click(object sender, EventArgs e)
        {
            sendSerialData(LED_OFF.ToString());
        }

        private void bar_scrollSpeed(object sender, EventArgs e)
        {
            if (serialPort == null)
            {
                return;
            }
            lbl_temp.Text = bar_fanSpeed.Value.ToString();
            sendSerialData(bar_fanSpeed.Value.ToString());
        }

        private void btn_read_Click(object sender, EventArgs e)
        {
            txtBox_rData.Text = data_rx;
            data_rx = "";
        }

        private void txtBox_tData_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                String data = txtBox_tData.Text.ToString();
                sendSerialData(data);
            }
        }

        private void rxData_Handler(object sender, SerialDataReceivedEventArgs e)
        {
            SerialPort tmp_serialPort = (SerialPort)sender;
            string tmpData = tmp_serialPort.ReadExisting();

            /* Frame Handler */
            if (tmpData.Contains("#"))
                start_Receive = true;
            else if (tmpData.Contains("$"))
            {
                start_Receive = false;
                string current_time = DateTime.Now.ToString("hh:mm tt") + " : ";
                /***** Invoking inside a handler thread *****/
                txtBox_rTemp.Invoke((Action)(() => txtBox_rTemp.Text += current_time + data_rx + Environment.NewLine));
                current_time = "";
                data_rx = "";
            }
            else
            {
                if (start_Receive == true)
                    data_rx += tmpData;
                else;
            }
        }
    }
}
