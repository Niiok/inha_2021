namespace Lab1_RaceDay
{
    partial class Form1
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this.pictureBox0 = new System.Windows.Forms.PictureBox();
            this.pictureDog0 = new System.Windows.Forms.PictureBox();
            this.pictureDog1 = new System.Windows.Forms.PictureBox();
            this.pictureDog2 = new System.Windows.Forms.PictureBox();
            this.pictureDog3 = new System.Windows.Forms.PictureBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.numericUpDown2 = new System.Windows.Forms.NumericUpDown();
            this.label1 = new System.Windows.Forms.Label();
            this.numericUpDown1 = new System.Windows.Forms.NumericUpDown();
            this.label6 = new System.Windows.Forms.Label();
            this.button2 = new System.Windows.Forms.Button();
            this.raceButton = new System.Windows.Forms.Button();
            this.label5 = new System.Windows.Forms.Label();
            this.labelOnRadio = new System.Windows.Forms.Label();
            this.labelGuy2 = new System.Windows.Forms.Label();
            this.labelGuy1 = new System.Windows.Forms.Label();
            this.radioButtonGuy2 = new System.Windows.Forms.RadioButton();
            this.radioButtonGuy1 = new System.Windows.Forms.RadioButton();
            this.radioButtonGuy0 = new System.Windows.Forms.RadioButton();
            this.labelGuy0 = new System.Windows.Forms.Label();
            this.raceBox = new System.Windows.Forms.GroupBox();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox0)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureDog0)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureDog1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureDog2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureDog3)).BeginInit();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).BeginInit();
            this.raceBox.SuspendLayout();
            this.SuspendLayout();
            // 
            // pictureBox0
            // 
            this.pictureBox0.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.pictureBox0.Image = global::Lab1_RaceDay.Properties.Resources.racetrack;
            this.pictureBox0.Location = new System.Drawing.Point(6, 12);
            this.pictureBox0.Name = "pictureBox0";
            this.pictureBox0.Size = new System.Drawing.Size(600, 200);
            this.pictureBox0.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox0.TabIndex = 1;
            this.pictureBox0.TabStop = false;
            // 
            // pictureDog0
            // 
            this.pictureDog0.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left)));
            this.pictureDog0.Image = global::Lab1_RaceDay.Properties.Resources.dog;
            this.pictureDog0.Location = new System.Drawing.Point(16, 22);
            this.pictureDog0.Name = "pictureDog0";
            this.pictureDog0.Size = new System.Drawing.Size(75, 20);
            this.pictureDog0.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureDog0.TabIndex = 2;
            this.pictureDog0.TabStop = false;
            // 
            // pictureDog1
            // 
            this.pictureDog1.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left)));
            this.pictureDog1.Image = global::Lab1_RaceDay.Properties.Resources.dog;
            this.pictureDog1.Location = new System.Drawing.Point(16, 69);
            this.pictureDog1.Name = "pictureDog1";
            this.pictureDog1.Size = new System.Drawing.Size(75, 20);
            this.pictureDog1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureDog1.TabIndex = 3;
            this.pictureDog1.TabStop = false;
            // 
            // pictureDog2
            // 
            this.pictureDog2.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left)));
            this.pictureDog2.Image = global::Lab1_RaceDay.Properties.Resources.dog;
            this.pictureDog2.Location = new System.Drawing.Point(16, 125);
            this.pictureDog2.Name = "pictureDog2";
            this.pictureDog2.Size = new System.Drawing.Size(75, 20);
            this.pictureDog2.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureDog2.TabIndex = 4;
            this.pictureDog2.TabStop = false;
            // 
            // pictureDog3
            // 
            this.pictureDog3.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left)));
            this.pictureDog3.Image = global::Lab1_RaceDay.Properties.Resources.dog;
            this.pictureDog3.Location = new System.Drawing.Point(16, 174);
            this.pictureDog3.Name = "pictureDog3";
            this.pictureDog3.Size = new System.Drawing.Size(75, 20);
            this.pictureDog3.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureDog3.TabIndex = 5;
            this.pictureDog3.TabStop = false;
            // 
            // groupBox1
            // 
            this.groupBox1.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBox1.Controls.Add(this.numericUpDown2);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.numericUpDown1);
            this.groupBox1.Controls.Add(this.label6);
            this.groupBox1.Controls.Add(this.button2);
            this.groupBox1.Controls.Add(this.raceButton);
            this.groupBox1.Controls.Add(this.label5);
            this.groupBox1.Controls.Add(this.labelOnRadio);
            this.groupBox1.Controls.Add(this.labelGuy2);
            this.groupBox1.Controls.Add(this.labelGuy1);
            this.groupBox1.Controls.Add(this.radioButtonGuy2);
            this.groupBox1.Controls.Add(this.radioButtonGuy1);
            this.groupBox1.Controls.Add(this.radioButtonGuy0);
            this.groupBox1.Controls.Add(this.labelGuy0);
            this.groupBox1.Font = new System.Drawing.Font("굴림", 14F);
            this.groupBox1.Location = new System.Drawing.Point(12, 236);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(612, 225);
            this.groupBox1.TabIndex = 6;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Betting Parlot";
            // 
            // numericUpDown2
            // 
            this.numericUpDown2.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.numericUpDown2.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.numericUpDown2.Location = new System.Drawing.Point(407, 200);
            this.numericUpDown2.Maximum = new decimal(new int[] {
            4,
            0,
            0,
            0});
            this.numericUpDown2.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericUpDown2.Name = "numericUpDown2";
            this.numericUpDown2.Size = new System.Drawing.Size(50, 25);
            this.numericUpDown2.TabIndex = 13;
            this.numericUpDown2.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // label1
            // 
            this.label1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("굴림", 14F);
            this.label1.Location = new System.Drawing.Point(212, 200);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(189, 19);
            this.label1.TabIndex = 12;
            this.label1.Text = "bucks on dog number";
            // 
            // numericUpDown1
            // 
            this.numericUpDown1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.numericUpDown1.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.numericUpDown1.Increment = new decimal(new int[] {
            5,
            0,
            0,
            0});
            this.numericUpDown1.Location = new System.Drawing.Point(156, 200);
            this.numericUpDown1.Name = "numericUpDown1";
            this.numericUpDown1.Size = new System.Drawing.Size(50, 25);
            this.numericUpDown1.TabIndex = 11;
            // 
            // label6
            // 
            this.label6.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("굴림", 14F);
            this.label6.Location = new System.Drawing.Point(6, 200);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(45, 19);
            this.label6.TabIndex = 10;
            this.label6.Text = "Bets";
            // 
            // button2
            // 
            this.button2.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.button2.Location = new System.Drawing.Point(100, 200);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(50, 25);
            this.button2.TabIndex = 9;
            this.button2.Text = "Bets";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.OnBetButton_Click);
            // 
            // button1
            // 
            this.raceButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.raceButton.Font = new System.Drawing.Font("굴림", 16F, System.Drawing.FontStyle.Bold);
            this.raceButton.Location = new System.Drawing.Point(478, 186);
            this.raceButton.Name = "button1";
            this.raceButton.Size = new System.Drawing.Size(128, 32);
            this.raceButton.TabIndex = 8;
            this.raceButton.Text = "Race !";
            this.raceButton.UseVisualStyleBackColor = true;
            this.raceButton.Click += new System.EventHandler(this.OnRaceButton_Click);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("굴림", 16F, System.Drawing.FontStyle.Bold);
            this.label5.Location = new System.Drawing.Point(296, 35);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(55, 22);
            this.label5.TabIndex = 7;
            this.label5.Text = "Bets";
            // 
            // labelOnRadio
            // 
            this.labelOnRadio.AutoSize = true;
            this.labelOnRadio.Font = new System.Drawing.Font("굴림", 16F, System.Drawing.FontStyle.Bold);
            this.labelOnRadio.Location = new System.Drawing.Point(6, 35);
            this.labelOnRadio.Name = "labelOnRadio";
            this.labelOnRadio.Size = new System.Drawing.Size(163, 22);
            this.labelOnRadio.TabIndex = 6;
            this.labelOnRadio.Text = "Minimum Bet : ";
            // 
            // labelGuy2
            // 
            this.labelGuy2.AutoSize = true;
            this.labelGuy2.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.labelGuy2.Location = new System.Drawing.Point(300, 120);
            this.labelGuy2.MinimumSize = new System.Drawing.Size(294, 21);
            this.labelGuy2.Name = "labelGuy2";
            this.labelGuy2.Size = new System.Drawing.Size(294, 21);
            this.labelGuy2.TabIndex = 5;
            this.labelGuy2.Text = "empty";
            // 
            // labelGuy1
            // 
            this.labelGuy1.AutoSize = true;
            this.labelGuy1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.labelGuy1.Location = new System.Drawing.Point(300, 90);
            this.labelGuy1.MinimumSize = new System.Drawing.Size(294, 21);
            this.labelGuy1.Name = "labelGuy1";
            this.labelGuy1.Size = new System.Drawing.Size(294, 21);
            this.labelGuy1.TabIndex = 4;
            this.labelGuy1.Text = "empty";
            // 
            // radioButtonGuy2
            // 
            this.radioButtonGuy2.AutoSize = true;
            this.radioButtonGuy2.Location = new System.Drawing.Point(6, 120);
            this.radioButtonGuy2.Name = "radioButtonGuy2";
            this.radioButtonGuy2.Size = new System.Drawing.Size(129, 23);
            this.radioButtonGuy2.TabIndex = 3;
            this.radioButtonGuy2.TabStop = true;
            this.radioButtonGuy2.Text = "radioButton3";
            this.radioButtonGuy2.UseVisualStyleBackColor = true;
            // 
            // radioButtonGuy1
            // 
            this.radioButtonGuy1.AutoSize = true;
            this.radioButtonGuy1.Location = new System.Drawing.Point(6, 90);
            this.radioButtonGuy1.Name = "radioButtonGuy1";
            this.radioButtonGuy1.Size = new System.Drawing.Size(129, 23);
            this.radioButtonGuy1.TabIndex = 2;
            this.radioButtonGuy1.TabStop = true;
            this.radioButtonGuy1.Text = "radioButton2";
            this.radioButtonGuy1.UseVisualStyleBackColor = true;
            // 
            // radioButtonGuy0
            // 
            this.radioButtonGuy0.AutoSize = true;
            this.radioButtonGuy0.Location = new System.Drawing.Point(6, 60);
            this.radioButtonGuy0.Name = "radioButtonGuy0";
            this.radioButtonGuy0.Size = new System.Drawing.Size(129, 23);
            this.radioButtonGuy0.TabIndex = 1;
            this.radioButtonGuy0.TabStop = true;
            this.radioButtonGuy0.Text = "radioButton1";
            this.radioButtonGuy0.UseVisualStyleBackColor = true;
            // 
            // labelGuy0
            // 
            this.labelGuy0.AutoSize = true;
            this.labelGuy0.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.labelGuy0.Location = new System.Drawing.Point(300, 60);
            this.labelGuy0.MinimumSize = new System.Drawing.Size(294, 21);
            this.labelGuy0.Name = "labelGuy0";
            this.labelGuy0.Size = new System.Drawing.Size(294, 21);
            this.labelGuy0.TabIndex = 0;
            this.labelGuy0.Text = "empty";
            // 
            // raceBox
            // 
            this.raceBox.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.raceBox.Controls.Add(this.pictureDog3);
            this.raceBox.Controls.Add(this.pictureDog0);
            this.raceBox.Controls.Add(this.pictureDog2);
            this.raceBox.Controls.Add(this.pictureDog1);
            this.raceBox.Controls.Add(this.pictureBox0);
            this.raceBox.Location = new System.Drawing.Point(12, 12);
            this.raceBox.Name = "raceBox";
            this.raceBox.Size = new System.Drawing.Size(612, 218);
            this.raceBox.TabIndex = 7;
            this.raceBox.TabStop = false;
            this.raceBox.Text = "Race";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(636, 473);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.raceBox);
            this.Name = "Form1";
            this.Text = "A Day at the Races";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox0)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureDog0)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureDog1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureDog2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureDog3)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).EndInit();
            this.raceBox.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox0;
        private System.Windows.Forms.PictureBox pictureDog0;
        private System.Windows.Forms.PictureBox pictureDog1;
        private System.Windows.Forms.PictureBox pictureDog2;
        private System.Windows.Forms.PictureBox pictureDog3;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.RadioButton radioButtonGuy0;
        private System.Windows.Forms.Label labelGuy0;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button raceButton;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label labelOnRadio;
        private System.Windows.Forms.Label labelGuy2;
        private System.Windows.Forms.Label labelGuy1;
        private System.Windows.Forms.RadioButton radioButtonGuy2;
        private System.Windows.Forms.RadioButton radioButtonGuy1;
        private System.Windows.Forms.NumericUpDown numericUpDown1;
        private System.Windows.Forms.GroupBox raceBox;
        private System.Windows.Forms.NumericUpDown numericUpDown2;
        private System.Windows.Forms.Label label1;
    }
}

