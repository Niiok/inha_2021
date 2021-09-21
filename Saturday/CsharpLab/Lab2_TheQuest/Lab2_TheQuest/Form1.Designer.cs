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
            this.panel1 = new System.Windows.Forms.Panel();
            this.button_attack_down = new System.Windows.Forms.Button();
            this.button_attack_left = new System.Windows.Forms.Button();
            this.button_attack_right = new System.Windows.Forms.Button();
            this.groupBox_move = new System.Windows.Forms.GroupBox();
            this.button_move_right = new System.Windows.Forms.Button();
            this.button_move_left = new System.Windows.Forms.Button();
            this.button_move_down = new System.Windows.Forms.Button();
            this.button_move_up = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_background)).BeginInit();
            this.groupBox_attack.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.panel1.SuspendLayout();
            this.groupBox_move.SuspendLayout();
            this.SuspendLayout();
            // 
            // pictureBox_background
            // 
            this.pictureBox_background.Image = global::Lab2_TheQuest.Properties.Resources.dungeon600x400;
            this.pictureBox_background.Location = new System.Drawing.Point(0, 0);
            this.pictureBox_background.Margin = new System.Windows.Forms.Padding(9);
            this.pictureBox_background.Name = "pictureBox_background";
            this.pictureBox_background.Size = new System.Drawing.Size(600, 400);
            this.pictureBox_background.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox_background.TabIndex = 0;
            this.pictureBox_background.TabStop = false;
            // 
            // groupBox_attack
            // 
            this.groupBox_attack.Controls.Add(this.button_attack_right);
            this.groupBox_attack.Controls.Add(this.button_attack_left);
            this.groupBox_attack.Controls.Add(this.button_attack_down);
            this.groupBox_attack.Controls.Add(this.button_attack_up);
            this.groupBox_attack.Location = new System.Drawing.Point(621, 115);
            this.groupBox_attack.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.groupBox_attack.Name = "groupBox_attack";
            this.groupBox_attack.Padding = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.groupBox_attack.Size = new System.Drawing.Size(265, 100);
            this.groupBox_attack.TabIndex = 1;
            this.groupBox_attack.TabStop = false;
            this.groupBox_attack.Text = "Attack";
            // 
            // button_attack_up
            // 
            this.button_attack_up.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.button_attack_up.Location = new System.Drawing.Point(96, 9);
            this.button_attack_up.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.button_attack_up.Name = "button_attack_up";
            this.button_attack_up.Size = new System.Drawing.Size(75, 23);
            this.button_attack_up.TabIndex = 0;
            this.button_attack_up.Text = "Up";
            this.button_attack_up.UseVisualStyleBackColor = true;
            // 
            // pictureBox1
            // 
            this.pictureBox1.BackColor = System.Drawing.Color.Transparent;
            this.pictureBox1.Image = global::Lab2_TheQuest.Properties.Resources.potion_red;
            this.pictureBox1.Location = new System.Drawing.Point(81, 320);
            this.pictureBox1.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(50, 50);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox1.TabIndex = 2;
            this.pictureBox1.TabStop = false;
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.pictureBox1);
            this.panel1.Controls.Add(this.pictureBox_background);
            this.panel1.Location = new System.Drawing.Point(9, 9);
            this.panel1.Margin = new System.Windows.Forms.Padding(0);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(600, 400);
            this.panel1.TabIndex = 3;
            // 
            // button_attack_down
            // 
            this.button_attack_down.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
            this.button_attack_down.Location = new System.Drawing.Point(96, 73);
            this.button_attack_down.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.button_attack_down.Name = "button_attack_down";
            this.button_attack_down.Size = new System.Drawing.Size(75, 23);
            this.button_attack_down.TabIndex = 1;
            this.button_attack_down.Text = "Down";
            this.button_attack_down.UseVisualStyleBackColor = true;
            // 
            // button_attack_left
            // 
            this.button_attack_left.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.button_attack_left.Location = new System.Drawing.Point(6, 41);
            this.button_attack_left.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.button_attack_left.Name = "button_attack_left";
            this.button_attack_left.Size = new System.Drawing.Size(75, 23);
            this.button_attack_left.TabIndex = 2;
            this.button_attack_left.Text = "Left";
            this.button_attack_left.UseVisualStyleBackColor = true;
            // 
            // button_attack_right
            // 
            this.button_attack_right.Anchor = System.Windows.Forms.AnchorStyles.Right;
            this.button_attack_right.Location = new System.Drawing.Point(184, 41);
            this.button_attack_right.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.button_attack_right.Name = "button_attack_right";
            this.button_attack_right.Size = new System.Drawing.Size(75, 23);
            this.button_attack_right.TabIndex = 3;
            this.button_attack_right.Text = "Right";
            this.button_attack_right.UseVisualStyleBackColor = true;
            // 
            // groupBox_move
            // 
            this.groupBox_move.Controls.Add(this.button_move_right);
            this.groupBox_move.Controls.Add(this.button_move_left);
            this.groupBox_move.Controls.Add(this.button_move_down);
            this.groupBox_move.Controls.Add(this.button_move_up);
            this.groupBox_move.Location = new System.Drawing.Point(621, 11);
            this.groupBox_move.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.groupBox_move.Name = "groupBox_move";
            this.groupBox_move.Padding = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.groupBox_move.Size = new System.Drawing.Size(265, 100);
            this.groupBox_move.TabIndex = 4;
            this.groupBox_move.TabStop = false;
            this.groupBox_move.Text = "Move";
            // 
            // button_move_right
            // 
            this.button_move_right.Anchor = System.Windows.Forms.AnchorStyles.Right;
            this.button_move_right.Location = new System.Drawing.Point(184, 41);
            this.button_move_right.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.button_move_right.Name = "button_move_right";
            this.button_move_right.Size = new System.Drawing.Size(75, 23);
            this.button_move_right.TabIndex = 3;
            this.button_move_right.Text = "Right";
            this.button_move_right.UseVisualStyleBackColor = true;
            // 
            // button_move_left
            // 
            this.button_move_left.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.button_move_left.Location = new System.Drawing.Point(6, 41);
            this.button_move_left.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.button_move_left.Name = "button_move_left";
            this.button_move_left.Size = new System.Drawing.Size(75, 23);
            this.button_move_left.TabIndex = 2;
            this.button_move_left.Text = "Left";
            this.button_move_left.UseVisualStyleBackColor = true;
            // 
            // button_move_down
            // 
            this.button_move_down.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
            this.button_move_down.Location = new System.Drawing.Point(96, 73);
            this.button_move_down.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.button_move_down.Name = "button_move_down";
            this.button_move_down.Size = new System.Drawing.Size(75, 23);
            this.button_move_down.TabIndex = 1;
            this.button_move_down.Text = "Down";
            this.button_move_down.UseVisualStyleBackColor = true;
            // 
            // button_move_up
            // 
            this.button_move_up.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.button_move_up.Location = new System.Drawing.Point(96, 9);
            this.button_move_up.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.button_move_up.Name = "button_move_up";
            this.button_move_up.Size = new System.Drawing.Size(75, 23);
            this.button_move_up.TabIndex = 0;
            this.button_move_up.Text = "Up";
            this.button_move_up.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(898, 418);
            this.Controls.Add(this.groupBox_move);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.groupBox_attack);
            this.Name = "Form1";
            this.Text = "The Quest";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_background)).EndInit();
            this.groupBox_attack.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.panel1.ResumeLayout(false);
            this.groupBox_move.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox_background;
        private System.Windows.Forms.GroupBox groupBox_attack;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Button button_attack_up;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Button button_attack_down;
        private System.Windows.Forms.Button button_attack_right;
        private System.Windows.Forms.Button button_attack_left;
        private System.Windows.Forms.GroupBox groupBox_move;
        private System.Windows.Forms.Button button_move_right;
        private System.Windows.Forms.Button button_move_left;
        private System.Windows.Forms.Button button_move_down;
        private System.Windows.Forms.Button button_move_up;
    }
}

