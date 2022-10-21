
namespace CI_lab2
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
            this.components = new System.ComponentModel.Container();
            this.cmb_ports = new System.Windows.Forms.ComboBox();
            this.btn_refresh = new System.Windows.Forms.Button();
            this.lbl_status = new System.Windows.Forms.Label();
            this.txtBox_tData = new System.Windows.Forms.TextBox();
            this.btn_send = new System.Windows.Forms.Button();
            this.lbl_send = new System.Windows.Forms.Label();
            this.btn_turnON = new System.Windows.Forms.Button();
            this.btn_turnOFF = new System.Windows.Forms.Button();
            this.bar_fanSpeed = new System.Windows.Forms.TrackBar();
            this.lbl_temp = new System.Windows.Forms.Label();
            this.txtBox_rData = new System.Windows.Forms.TextBox();
            this.btn_read = new System.Windows.Forms.Button();
            this.lbl_tmp = new System.Windows.Forms.Label();
            this.txtBox_rTemp = new System.Windows.Forms.TextBox();
            this.lbl_read = new System.Windows.Forms.Label();
            this.bindingSource1 = new System.Windows.Forms.BindingSource(this.components);
            this.btn_connect = new System.Windows.Forms.Button();
            this.btn_disconnect = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.bar_fanSpeed)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.bindingSource1)).BeginInit();
            this.SuspendLayout();
            // 
            // cmb_ports
            // 
            this.cmb_ports.FormattingEnabled = true;
            this.cmb_ports.Location = new System.Drawing.Point(94, 21);
            this.cmb_ports.Name = "cmb_ports";
            this.cmb_ports.Size = new System.Drawing.Size(318, 24);
            this.cmb_ports.TabIndex = 0;
            // 
            // btn_refresh
            // 
            this.btn_refresh.Location = new System.Drawing.Point(205, 53);
            this.btn_refresh.Name = "btn_refresh";
            this.btn_refresh.Size = new System.Drawing.Size(96, 34);
            this.btn_refresh.TabIndex = 3;
            this.btn_refresh.Text = "Refresh";
            this.btn_refresh.UseVisualStyleBackColor = true;
            this.btn_refresh.Click += new System.EventHandler(this.btn_resfresh_Click);
            // 
            // lbl_status
            // 
            this.lbl_status.AutoSize = true;
            this.lbl_status.Font = new System.Drawing.Font("Montserrat", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_status.Location = new System.Drawing.Point(490, 18);
            this.lbl_status.Name = "lbl_status";
            this.lbl_status.Size = new System.Drawing.Size(160, 27);
            this.lbl_status.TabIndex = 4;
            this.lbl_status.Text = "Disconnected";
            // 
            // txtBox_tData
            // 
            this.txtBox_tData.Location = new System.Drawing.Point(94, 152);
            this.txtBox_tData.Multiline = true;
            this.txtBox_tData.Name = "txtBox_tData";
            this.txtBox_tData.Size = new System.Drawing.Size(318, 44);
            this.txtBox_tData.TabIndex = 5;
            this.txtBox_tData.KeyDown += new System.Windows.Forms.KeyEventHandler(this.txtBox_tData_KeyDown);
            // 
            // btn_send
            // 
            this.btn_send.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btn_send.Location = new System.Drawing.Point(205, 211);
            this.btn_send.Name = "btn_send";
            this.btn_send.Size = new System.Drawing.Size(96, 31);
            this.btn_send.TabIndex = 6;
            this.btn_send.Text = "Send";
            this.btn_send.UseVisualStyleBackColor = true;
            this.btn_send.Click += new System.EventHandler(this.btn_send_Click);
            // 
            // lbl_send
            // 
            this.lbl_send.AutoSize = true;
            this.lbl_send.Font = new System.Drawing.Font("Montserrat", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_send.Location = new System.Drawing.Point(202, 120);
            this.lbl_send.Name = "lbl_send";
            this.lbl_send.Size = new System.Drawing.Size(102, 24);
            this.lbl_send.TabIndex = 7;
            this.lbl_send.Text = "Send Data";
            // 
            // btn_turnON
            // 
            this.btn_turnON.BackColor = System.Drawing.Color.DarkSeaGreen;
            this.btn_turnON.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btn_turnON.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btn_turnON.Location = new System.Drawing.Point(469, 76);
            this.btn_turnON.Name = "btn_turnON";
            this.btn_turnON.Size = new System.Drawing.Size(83, 57);
            this.btn_turnON.TabIndex = 8;
            this.btn_turnON.Text = "TurnOn";
            this.btn_turnON.UseVisualStyleBackColor = false;
            this.btn_turnON.Click += new System.EventHandler(this.btn_turnON_Click);
            // 
            // btn_turnOFF
            // 
            this.btn_turnOFF.BackColor = System.Drawing.Color.Salmon;
            this.btn_turnOFF.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btn_turnOFF.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btn_turnOFF.Location = new System.Drawing.Point(582, 76);
            this.btn_turnOFF.Name = "btn_turnOFF";
            this.btn_turnOFF.Size = new System.Drawing.Size(86, 57);
            this.btn_turnOFF.TabIndex = 9;
            this.btn_turnOFF.Text = "TurnOff";
            this.btn_turnOFF.UseVisualStyleBackColor = false;
            this.btn_turnOFF.Click += new System.EventHandler(this.btn_turnOFF_Click);
            // 
            // bar_fanSpeed
            // 
            this.bar_fanSpeed.Location = new System.Drawing.Point(455, 343);
            this.bar_fanSpeed.Maximum = 9;
            this.bar_fanSpeed.Name = "bar_fanSpeed";
            this.bar_fanSpeed.Size = new System.Drawing.Size(220, 56);
            this.bar_fanSpeed.TabIndex = 10;
            this.bar_fanSpeed.Scroll += new System.EventHandler(this.bar_scrollSpeed);
            // 
            // lbl_temp
            // 
            this.lbl_temp.AutoSize = true;
            this.lbl_temp.Font = new System.Drawing.Font("Montserrat", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_temp.Location = new System.Drawing.Point(521, 308);
            this.lbl_temp.Name = "lbl_temp";
            this.lbl_temp.Size = new System.Drawing.Size(105, 24);
            this.lbl_temp.TabIndex = 11;
            this.lbl_temp.Text = "Fan Speed";
            // 
            // txtBox_rData
            // 
            this.txtBox_rData.Location = new System.Drawing.Point(94, 304);
            this.txtBox_rData.Name = "txtBox_rData";
            this.txtBox_rData.ReadOnly = true;
            this.txtBox_rData.Size = new System.Drawing.Size(318, 22);
            this.txtBox_rData.TabIndex = 12;
            // 
            // btn_read
            // 
            this.btn_read.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btn_read.Location = new System.Drawing.Point(205, 343);
            this.btn_read.Name = "btn_read";
            this.btn_read.Size = new System.Drawing.Size(96, 31);
            this.btn_read.TabIndex = 13;
            this.btn_read.Text = "Read";
            this.btn_read.UseVisualStyleBackColor = true;
            this.btn_read.Click += new System.EventHandler(this.btn_read_Click);
            // 
            // lbl_tmp
            // 
            this.lbl_tmp.AutoSize = true;
            this.lbl_tmp.Font = new System.Drawing.Font("Montserrat ExtraBold", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_tmp.ForeColor = System.Drawing.Color.IndianRed;
            this.lbl_tmp.Location = new System.Drawing.Point(501, 172);
            this.lbl_tmp.Name = "lbl_tmp";
            this.lbl_tmp.Size = new System.Drawing.Size(129, 24);
            this.lbl_tmp.TabIndex = 14;
            this.lbl_tmp.Text = "Temperature";
            // 
            // txtBox_rTemp
            // 
            this.txtBox_rTemp.Location = new System.Drawing.Point(469, 211);
            this.txtBox_rTemp.Multiline = true;
            this.txtBox_rTemp.Name = "txtBox_rTemp";
            this.txtBox_rTemp.ReadOnly = true;
            this.txtBox_rTemp.Size = new System.Drawing.Size(199, 75);
            this.txtBox_rTemp.TabIndex = 15;
            // 
            // lbl_read
            // 
            this.lbl_read.AutoSize = true;
            this.lbl_read.Font = new System.Drawing.Font("Montserrat", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_read.Location = new System.Drawing.Point(190, 270);
            this.lbl_read.Name = "lbl_read";
            this.lbl_read.Size = new System.Drawing.Size(126, 24);
            this.lbl_read.TabIndex = 16;
            this.lbl_read.Text = "Receive Data";
            // 
            // btn_connect
            // 
            this.btn_connect.Location = new System.Drawing.Point(94, 53);
            this.btn_connect.Name = "btn_connect";
            this.btn_connect.Size = new System.Drawing.Size(96, 34);
            this.btn_connect.TabIndex = 17;
            this.btn_connect.Text = "Connect";
            this.btn_connect.UseVisualStyleBackColor = true;
            this.btn_connect.Click += new System.EventHandler(this.btn_connect_Click);
            // 
            // btn_disconnect
            // 
            this.btn_disconnect.Location = new System.Drawing.Point(316, 53);
            this.btn_disconnect.Name = "btn_disconnect";
            this.btn_disconnect.Size = new System.Drawing.Size(96, 34);
            this.btn_disconnect.TabIndex = 18;
            this.btn_disconnect.Text = "Disconnect";
            this.btn_disconnect.UseVisualStyleBackColor = true;
            this.btn_disconnect.Click += new System.EventHandler(this.btn_disconnect_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.AutoValidate = System.Windows.Forms.AutoValidate.EnablePreventFocusChange;
            this.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.ClientSize = new System.Drawing.Size(702, 529);
            this.Controls.Add(this.btn_disconnect);
            this.Controls.Add(this.btn_connect);
            this.Controls.Add(this.lbl_read);
            this.Controls.Add(this.txtBox_rTemp);
            this.Controls.Add(this.lbl_tmp);
            this.Controls.Add(this.btn_read);
            this.Controls.Add(this.txtBox_rData);
            this.Controls.Add(this.lbl_temp);
            this.Controls.Add(this.bar_fanSpeed);
            this.Controls.Add(this.btn_turnOFF);
            this.Controls.Add(this.btn_turnON);
            this.Controls.Add(this.lbl_send);
            this.Controls.Add(this.btn_send);
            this.Controls.Add(this.txtBox_tData);
            this.Controls.Add(this.lbl_status);
            this.Controls.Add(this.btn_refresh);
            this.Controls.Add(this.cmb_ports);
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.bar_fanSpeed)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.bindingSource1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox cmb_ports;
        
        private System.Windows.Forms.Button btn_refresh;
        private System.Windows.Forms.Label lbl_status;
        private System.Windows.Forms.TextBox txtBox_tData;
        private System.Windows.Forms.Button btn_send;
        private System.Windows.Forms.Label lbl_send;
        private System.Windows.Forms.Button btn_turnON;
        private System.Windows.Forms.Button btn_turnOFF;
        private System.Windows.Forms.TrackBar bar_fanSpeed;
        private System.Windows.Forms.Label lbl_temp;
        private System.Windows.Forms.TextBox txtBox_rData;
        private System.Windows.Forms.Button btn_read;
        private System.Windows.Forms.Label lbl_tmp;
        private System.Windows.Forms.TextBox txtBox_rTemp;
        private System.Windows.Forms.Label lbl_read;
        private System.Windows.Forms.BindingSource bindingSource1;
        private System.Windows.Forms.Button btn_connect;
        private System.Windows.Forms.Button btn_disconnect;
    }
}

