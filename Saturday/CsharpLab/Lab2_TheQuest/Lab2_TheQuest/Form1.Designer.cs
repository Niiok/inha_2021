namespace Lab2_TheQuest
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
            this.pictureBox_background = new System.Windows.Forms.PictureBox();
            this.groupBox_attack = new System.Windows.Forms.GroupBox();
            this.button_attack_up = new System.Windows.Forms.Button();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_background)).BeginInit();
            this.groupBox_attack.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // pictureBox_background
            // 
            this.pictureBox_background.Image = global::Lab2_TheQuest.Properties.Resources.dungeon600x400;
            this.pictureBox_background.Location = new System.Drawing.Point(0, 0);
            this.pictureBox_background.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.pictureBox_background.Name = "pictureBox_background";
            this.pictureBox_background.Size = new System.Drawing.Size(600, 400);
            this.pictureBox_background.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize;
            this.pictureBox_background.TabIndex = 0;
            this.pictureBox_background.TabStop = false;
            // 
            // groupBox_attack
            // 
            this.groupBox_attack.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.groupBox_attack.Controls.Add(this.button_attack_up);
            this.groupBox_attack.Location = new System.Drawing.Point(606, 11);
            this.groupBox_attack.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.groupBox_attack.Name = "groupBox_attack";
            this.groupBox_attack.Padding = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.groupBox_attack.Size = new System.Drawing.Size(175, 80);
            this.groupBox_attack.TabIndex = 1;
            this.groupBox_attack.TabStop = false;
            this.groupBox_attack.Text = "Attack";
            // 
            // button_attack_up
            // 
            this.button_attack_up.Location = new System.Drawing.Point(5, 57);
            this.button_attack_up.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.button_attack_up.Name = "button_attack_up";
            this.button_attack_up.Size = new System.Drawing.Size(66, 18);
            this.button_attack_up.TabIndex = 0;
            this.button_attack_up.Text = "Up";
            this.button_attack_up.UseVisualStyleBackColor = true;
            // 
            // pictureBox1
            // 
            this.pictureBox1.BackColor = System.Drawing.Color.Transparent;
            this.pictureBox1.Image = global::Lab2_TheQuest.Properties.Resources.potion_red;
            this.pictureBox1.Location = new System.Drawing.Point(67, 254);
            this.pictureBox1.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(50, 50);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize;
            this.pictureBox1.TabIndex = 2;
            this.pictureBox1.TabStop = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.groupBox_attack);
            this.Controls.Add(this.pictureBox_background);
            this.Name = "Form1";
            this.Text = "The Quest";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_background)).EndInit();
            this.groupBox_attack.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox_background;
        private System.Windows.Forms.GroupBox groupBox_attack;
        private System.Windows.Forms.Button button_attack_up;
        private System.Windows.Forms.PictureBox pictureBox1;
    }
}

