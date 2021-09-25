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
            this.groupBox_attack = new System.Windows.Forms.GroupBox();
            this.button_attack_right = new System.Windows.Forms.Button();
            this.button_attack_left = new System.Windows.Forms.Button();
            this.button_attack_down = new System.Windows.Forms.Button();
            this.button_attack_up = new System.Windows.Forms.Button();
            this.groupBox_move = new System.Windows.Forms.GroupBox();
            this.button_move_right = new System.Windows.Forms.Button();
            this.button_move_left = new System.Windows.Forms.Button();
            this.button_move_down = new System.Windows.Forms.Button();
            this.button_move_up = new System.Windows.Forms.Button();
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.pictureBox_item1 = new System.Windows.Forms.PictureBox();
            this.pictureBox_player = new System.Windows.Forms.PictureBox();
            this.pictureBox_bat = new System.Windows.Forms.PictureBox();
            this.groupBox_attack.SuspendLayout();
            this.groupBox_move.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_item1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_player)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_bat)).BeginInit();
            this.SuspendLayout();
            // 
            // groupBox_attack
            // 
            this.groupBox_attack.Controls.Add(this.button_attack_right);
            this.groupBox_attack.Controls.Add(this.button_attack_left);
            this.groupBox_attack.Controls.Add(this.button_attack_down);
            this.groupBox_attack.Controls.Add(this.button_attack_up);
            this.groupBox_attack.Location = new System.Drawing.Point(614, 125);
            this.groupBox_attack.Name = "groupBox_attack";
            this.groupBox_attack.Padding = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.groupBox_attack.Size = new System.Drawing.Size(179, 100);
            this.groupBox_attack.TabIndex = 1;
            this.groupBox_attack.TabStop = false;
            this.groupBox_attack.Text = "Attack";
            // 
            // button_attack_right
            // 
            this.button_attack_right.Anchor = System.Windows.Forms.AnchorStyles.Right;
            this.button_attack_right.Location = new System.Drawing.Point(111, 43);
            this.button_attack_right.Name = "button_attack_right";
            this.button_attack_right.Size = new System.Drawing.Size(63, 20);
            this.button_attack_right.TabIndex = 3;
            this.button_attack_right.Text = "Right";
            this.button_attack_right.UseVisualStyleBackColor = true;
            this.button_attack_right.Click += new System.EventHandler(this.button_attack_right_Click);
            // 
            // button_attack_left
            // 
            this.button_attack_left.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.button_attack_left.Location = new System.Drawing.Point(6, 43);
            this.button_attack_left.Name = "button_attack_left";
            this.button_attack_left.Size = new System.Drawing.Size(63, 20);
            this.button_attack_left.TabIndex = 2;
            this.button_attack_left.Text = "Left";
            this.button_attack_left.UseVisualStyleBackColor = true;
            this.button_attack_left.Click += new System.EventHandler(this.button_attack_left_Click);
            // 
            // button_attack_down
            // 
            this.button_attack_down.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
            this.button_attack_down.Location = new System.Drawing.Point(58, 73);
            this.button_attack_down.Name = "button_attack_down";
            this.button_attack_down.Size = new System.Drawing.Size(63, 20);
            this.button_attack_down.TabIndex = 1;
            this.button_attack_down.Text = "Down";
            this.button_attack_down.UseVisualStyleBackColor = true;
            this.button_attack_down.Click += new System.EventHandler(this.button_attack_down_Click);
            // 
            // button_attack_up
            // 
            this.button_attack_up.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.button_attack_up.Location = new System.Drawing.Point(58, 13);
            this.button_attack_up.Name = "button_attack_up";
            this.button_attack_up.Size = new System.Drawing.Size(63, 20);
            this.button_attack_up.TabIndex = 0;
            this.button_attack_up.Text = "Up";
            this.button_attack_up.UseVisualStyleBackColor = true;
            this.button_attack_up.Click += new System.EventHandler(this.button_attack_up_Click);
            // 
            // groupBox_move
            // 
            this.groupBox_move.Controls.Add(this.button_move_right);
            this.groupBox_move.Controls.Add(this.button_move_left);
            this.groupBox_move.Controls.Add(this.button_move_down);
            this.groupBox_move.Controls.Add(this.button_move_up);
            this.groupBox_move.Location = new System.Drawing.Point(614, 12);
            this.groupBox_move.Name = "groupBox_move";
            this.groupBox_move.Padding = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.groupBox_move.Size = new System.Drawing.Size(179, 100);
            this.groupBox_move.TabIndex = 4;
            this.groupBox_move.TabStop = false;
            this.groupBox_move.Text = "Move";
            // 
            // button_move_right
            // 
            this.button_move_right.Anchor = System.Windows.Forms.AnchorStyles.Right;
            this.button_move_right.Location = new System.Drawing.Point(111, 43);
            this.button_move_right.Name = "button_move_right";
            this.button_move_right.Size = new System.Drawing.Size(63, 20);
            this.button_move_right.TabIndex = 3;
            this.button_move_right.Text = "Right";
            this.button_move_right.UseVisualStyleBackColor = true;
            this.button_move_right.Click += new System.EventHandler(this.button_move_right_Click);
            // 
            // button_move_left
            // 
            this.button_move_left.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.button_move_left.Location = new System.Drawing.Point(6, 43);
            this.button_move_left.Name = "button_move_left";
            this.button_move_left.Size = new System.Drawing.Size(63, 20);
            this.button_move_left.TabIndex = 2;
            this.button_move_left.Text = "Left";
            this.button_move_left.UseVisualStyleBackColor = true;
            this.button_move_left.Click += new System.EventHandler(this.button_move_left_Click);
            // 
            // button_move_down
            // 
            this.button_move_down.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
            this.button_move_down.Location = new System.Drawing.Point(58, 73);
            this.button_move_down.Name = "button_move_down";
            this.button_move_down.Size = new System.Drawing.Size(63, 20);
            this.button_move_down.TabIndex = 1;
            this.button_move_down.Text = "Down";
            this.button_move_down.UseVisualStyleBackColor = true;
            this.button_move_down.Click += new System.EventHandler(this.button_move_down_Click);
            // 
            // button_move_up
            // 
            this.button_move_up.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.button_move_up.Location = new System.Drawing.Point(58, 13);
            this.button_move_up.Name = "button_move_up";
            this.button_move_up.Size = new System.Drawing.Size(63, 20);
            this.button_move_up.TabIndex = 0;
            this.button_move_up.Text = "Up";
            this.button_move_up.UseVisualStyleBackColor = true;
            this.button_move_up.Click += new System.EventHandler(this.button_move_up_Click);
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.ColumnCount = 2;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 34.76563F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 65.23438F));
            this.tableLayoutPanel1.Location = new System.Drawing.Point(614, 268);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 4;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(179, 120);
            this.tableLayoutPanel1.TabIndex = 5;
            // 
            // pictureBox_item1
            // 
            this.pictureBox_item1.BackColor = System.Drawing.Color.Transparent;
            this.pictureBox_item1.Image = global::Lab2_TheQuest.Properties.Resources.potion_red;
            this.pictureBox_item1.Location = new System.Drawing.Point(83, 322);
            this.pictureBox_item1.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.pictureBox_item1.Name = "pictureBox_item1";
            this.pictureBox_item1.Size = new System.Drawing.Size(50, 50);
            this.pictureBox_item1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox_item1.TabIndex = 2;
            this.pictureBox_item1.TabStop = false;
            // 
            // pictureBox_player
            // 
            this.pictureBox_player.BackColor = System.Drawing.Color.Transparent;
            this.pictureBox_player.Image = global::Lab2_TheQuest.Properties.Resources.player;
            this.pictureBox_player.Location = new System.Drawing.Point(83, 75);
            this.pictureBox_player.Margin = new System.Windows.Forms.Padding(2);
            this.pictureBox_player.Name = "pictureBox_player";
            this.pictureBox_player.Size = new System.Drawing.Size(30, 30);
            this.pictureBox_player.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox_player.TabIndex = 3;
            this.pictureBox_player.TabStop = false;
            // 
            // pictureBox_bat
            // 
            this.pictureBox_bat.BackColor = System.Drawing.Color.Transparent;
            this.pictureBox_bat.Image = global::Lab2_TheQuest.Properties.Resources.bat;
            this.pictureBox_bat.Location = new System.Drawing.Point(135, 75);
            this.pictureBox_bat.Margin = new System.Windows.Forms.Padding(2);
            this.pictureBox_bat.Name = "pictureBox_bat";
            this.pictureBox_bat.Size = new System.Drawing.Size(30, 30);
            this.pictureBox_bat.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox_bat.TabIndex = 6;
            this.pictureBox_bat.TabStop = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = global::Lab2_TheQuest.Properties.Resources.dungeon600x400;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.ClientSize = new System.Drawing.Size(805, 400);
            this.Controls.Add(this.pictureBox_bat);
            this.Controls.Add(this.pictureBox_item1);
            this.Controls.Add(this.pictureBox_player);
            this.Controls.Add(this.tableLayoutPanel1);
            this.Controls.Add(this.groupBox_move);
            this.Controls.Add(this.groupBox_attack);
            this.Name = "Form1";
            this.Text = "The Quest";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBox_attack.ResumeLayout(false);
            this.groupBox_move.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_item1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_player)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_bat)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.GroupBox groupBox_attack;
        private System.Windows.Forms.Button button_attack_up;
        private System.Windows.Forms.Button button_attack_down;
        private System.Windows.Forms.Button button_attack_right;
        private System.Windows.Forms.Button button_attack_left;
        private System.Windows.Forms.GroupBox groupBox_move;
        private System.Windows.Forms.Button button_move_right;
        private System.Windows.Forms.Button button_move_left;
        private System.Windows.Forms.Button button_move_down;
        private System.Windows.Forms.Button button_move_up;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.PictureBox pictureBox_item1;
        private System.Windows.Forms.PictureBox pictureBox_player;
        private System.Windows.Forms.PictureBox pictureBox_bat;
    }
}

