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
            this.pictureBox_player = new System.Windows.Forms.PictureBox();
            this.pictureBox_bat = new System.Windows.Forms.PictureBox();
            this.pictureBox_item_red = new System.Windows.Forms.PictureBox();
            this.pictureBox_item_blue = new System.Windows.Forms.PictureBox();
            this.pictureBox_item_sword = new System.Windows.Forms.PictureBox();
            this.pictureBox_item_bow = new System.Windows.Forms.PictureBox();
            this.pictureBox_item_mace = new System.Windows.Forms.PictureBox();
            this.pictureBox_ghost = new System.Windows.Forms.PictureBox();
            this.pictureBox_ghoul = new System.Windows.Forms.PictureBox();
            this.pictureBox_sword = new System.Windows.Forms.PictureBox();
            this.pictureBox_bow = new System.Windows.Forms.PictureBox();
            this.pictureBox_mace = new System.Windows.Forms.PictureBox();
            this.pictureBox_potion_red = new System.Windows.Forms.PictureBox();
            this.pictureBox__item_blue = new System.Windows.Forms.PictureBox();
            this.groupBox_attack.SuspendLayout();
            this.groupBox_move.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_player)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_bat)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_item_red)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_item_blue)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_item_sword)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_item_bow)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_item_mace)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_ghost)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_ghoul)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_sword)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_bow)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_mace)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_potion_red)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox__item_blue)).BeginInit();
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
            this.pictureBox_bat.Location = new System.Drawing.Point(127, 75);
            this.pictureBox_bat.Margin = new System.Windows.Forms.Padding(2);
            this.pictureBox_bat.Name = "pictureBox_bat";
            this.pictureBox_bat.Size = new System.Drawing.Size(30, 30);
            this.pictureBox_bat.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox_bat.TabIndex = 6;
            this.pictureBox_bat.TabStop = false;
            // 
            // pictureBox_item_red
            // 
            this.pictureBox_item_red.BackColor = System.Drawing.Color.Transparent;
            this.pictureBox_item_red.Image = global::Lab2_TheQuest.Properties.Resources.potion_red;
            this.pictureBox_item_red.Location = new System.Drawing.Point(450, 320);
            this.pictureBox_item_red.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.pictureBox_item_red.Name = "pictureBox_item_red";
            this.pictureBox_item_red.Size = new System.Drawing.Size(50, 50);
            this.pictureBox_item_red.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox_item_red.TabIndex = 2;
            this.pictureBox_item_red.TabStop = false;
            // 
            // pictureBox_item_blue
            // 
            this.pictureBox_item_blue.BackColor = System.Drawing.Color.Transparent;
            this.pictureBox_item_blue.Image = global::Lab2_TheQuest.Properties.Resources.potion_blue;
            this.pictureBox_item_blue.Location = new System.Drawing.Point(368, 320);
            this.pictureBox_item_blue.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.pictureBox_item_blue.Name = "pictureBox_item_blue";
            this.pictureBox_item_blue.Size = new System.Drawing.Size(50, 50);
            this.pictureBox_item_blue.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox_item_blue.TabIndex = 7;
            this.pictureBox_item_blue.TabStop = false;
            // 
            // pictureBox_item_sword
            // 
            this.pictureBox_item_sword.BackColor = System.Drawing.Color.Transparent;
            this.pictureBox_item_sword.Image = global::Lab2_TheQuest.Properties.Resources.sword;
            this.pictureBox_item_sword.Location = new System.Drawing.Point(83, 320);
            this.pictureBox_item_sword.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.pictureBox_item_sword.Name = "pictureBox_item_sword";
            this.pictureBox_item_sword.Size = new System.Drawing.Size(50, 50);
            this.pictureBox_item_sword.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox_item_sword.TabIndex = 8;
            this.pictureBox_item_sword.TabStop = false;
            // 
            // pictureBox_item_bow
            // 
            this.pictureBox_item_bow.BackColor = System.Drawing.Color.Transparent;
            this.pictureBox_item_bow.Image = global::Lab2_TheQuest.Properties.Resources.bow;
            this.pictureBox_item_bow.Location = new System.Drawing.Point(139, 320);
            this.pictureBox_item_bow.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.pictureBox_item_bow.Name = "pictureBox_item_bow";
            this.pictureBox_item_bow.Size = new System.Drawing.Size(50, 50);
            this.pictureBox_item_bow.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox_item_bow.TabIndex = 9;
            this.pictureBox_item_bow.TabStop = false;
            // 
            // pictureBox_item_mace
            // 
            this.pictureBox_item_mace.BackColor = System.Drawing.Color.Transparent;
            this.pictureBox_item_mace.Image = global::Lab2_TheQuest.Properties.Resources.mace;
            this.pictureBox_item_mace.Location = new System.Drawing.Point(195, 320);
            this.pictureBox_item_mace.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.pictureBox_item_mace.Name = "pictureBox_item_mace";
            this.pictureBox_item_mace.Size = new System.Drawing.Size(50, 50);
            this.pictureBox_item_mace.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox_item_mace.TabIndex = 10;
            this.pictureBox_item_mace.TabStop = false;
            // 
            // pictureBox_ghost
            // 
            this.pictureBox_ghost.BackColor = System.Drawing.Color.Transparent;
            this.pictureBox_ghost.Image = global::Lab2_TheQuest.Properties.Resources.ghost;
            this.pictureBox_ghost.Location = new System.Drawing.Point(173, 75);
            this.pictureBox_ghost.Margin = new System.Windows.Forms.Padding(2);
            this.pictureBox_ghost.Name = "pictureBox_ghost";
            this.pictureBox_ghost.Size = new System.Drawing.Size(30, 30);
            this.pictureBox_ghost.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox_ghost.TabIndex = 11;
            this.pictureBox_ghost.TabStop = false;
            // 
            // pictureBox_ghoul
            // 
            this.pictureBox_ghoul.BackColor = System.Drawing.Color.Transparent;
            this.pictureBox_ghoul.Image = global::Lab2_TheQuest.Properties.Resources.ghoul;
            this.pictureBox_ghoul.Location = new System.Drawing.Point(215, 75);
            this.pictureBox_ghoul.Margin = new System.Windows.Forms.Padding(2);
            this.pictureBox_ghoul.Name = "pictureBox_ghoul";
            this.pictureBox_ghoul.Size = new System.Drawing.Size(30, 30);
            this.pictureBox_ghoul.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox_ghoul.TabIndex = 12;
            this.pictureBox_ghoul.TabStop = false;
            // 
            // pictureBox_sword
            // 
            this.pictureBox_sword.BackColor = System.Drawing.Color.Transparent;
            this.pictureBox_sword.Image = global::Lab2_TheQuest.Properties.Resources.sword;
            this.pictureBox_sword.Location = new System.Drawing.Point(277, 75);
            this.pictureBox_sword.Margin = new System.Windows.Forms.Padding(2);
            this.pictureBox_sword.Name = "pictureBox_sword";
            this.pictureBox_sword.Size = new System.Drawing.Size(30, 30);
            this.pictureBox_sword.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox_sword.TabIndex = 13;
            this.pictureBox_sword.TabStop = false;
            // 
            // pictureBox_bow
            // 
            this.pictureBox_bow.BackColor = System.Drawing.Color.Transparent;
            this.pictureBox_bow.Image = global::Lab2_TheQuest.Properties.Resources.bow;
            this.pictureBox_bow.Location = new System.Drawing.Point(332, 75);
            this.pictureBox_bow.Margin = new System.Windows.Forms.Padding(2);
            this.pictureBox_bow.Name = "pictureBox_bow";
            this.pictureBox_bow.Size = new System.Drawing.Size(30, 30);
            this.pictureBox_bow.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox_bow.TabIndex = 14;
            this.pictureBox_bow.TabStop = false;
            // 
            // pictureBox_mace
            // 
            this.pictureBox_mace.BackColor = System.Drawing.Color.Transparent;
            this.pictureBox_mace.Image = global::Lab2_TheQuest.Properties.Resources.mace;
            this.pictureBox_mace.Location = new System.Drawing.Point(388, 75);
            this.pictureBox_mace.Margin = new System.Windows.Forms.Padding(2);
            this.pictureBox_mace.Name = "pictureBox_mace";
            this.pictureBox_mace.Size = new System.Drawing.Size(30, 30);
            this.pictureBox_mace.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox_mace.TabIndex = 15;
            this.pictureBox_mace.TabStop = false;
            // 
            // pictureBox_potion_red
            // 
            this.pictureBox_potion_red.BackColor = System.Drawing.Color.Transparent;
            this.pictureBox_potion_red.Image = global::Lab2_TheQuest.Properties.Resources.potion_red;
            this.pictureBox_potion_red.Location = new System.Drawing.Point(320, 148);
            this.pictureBox_potion_red.Margin = new System.Windows.Forms.Padding(2);
            this.pictureBox_potion_red.Name = "pictureBox_potion_red";
            this.pictureBox_potion_red.Size = new System.Drawing.Size(30, 30);
            this.pictureBox_potion_red.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox_potion_red.TabIndex = 16;
            this.pictureBox_potion_red.TabStop = false;
            // 
            // pictureBox__item_blue
            // 
            this.pictureBox__item_blue.BackColor = System.Drawing.Color.Transparent;
            this.pictureBox__item_blue.Image = global::Lab2_TheQuest.Properties.Resources.potion_blue;
            this.pictureBox__item_blue.Location = new System.Drawing.Point(368, 138);
            this.pictureBox__item_blue.Margin = new System.Windows.Forms.Padding(2);
            this.pictureBox__item_blue.Name = "pictureBox__item_blue";
            this.pictureBox__item_blue.Size = new System.Drawing.Size(30, 30);
            this.pictureBox__item_blue.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox__item_blue.TabIndex = 17;
            this.pictureBox__item_blue.TabStop = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = global::Lab2_TheQuest.Properties.Resources.dungeon600x400;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.ClientSize = new System.Drawing.Size(805, 400);
            this.Controls.Add(this.pictureBox__item_blue);
            this.Controls.Add(this.pictureBox_potion_red);
            this.Controls.Add(this.pictureBox_mace);
            this.Controls.Add(this.pictureBox_bow);
            this.Controls.Add(this.pictureBox_sword);
            this.Controls.Add(this.pictureBox_ghoul);
            this.Controls.Add(this.pictureBox_ghost);
            this.Controls.Add(this.pictureBox_item_mace);
            this.Controls.Add(this.pictureBox_item_bow);
            this.Controls.Add(this.pictureBox_item_sword);
            this.Controls.Add(this.pictureBox_item_blue);
            this.Controls.Add(this.pictureBox_bat);
            this.Controls.Add(this.pictureBox_item_red);
            this.Controls.Add(this.pictureBox_player);
            this.Controls.Add(this.tableLayoutPanel1);
            this.Controls.Add(this.groupBox_move);
            this.Controls.Add(this.groupBox_attack);
            this.Name = "Form1";
            this.Text = "The Quest";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBox_attack.ResumeLayout(false);
            this.groupBox_move.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_player)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_bat)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_item_red)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_item_blue)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_item_sword)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_item_bow)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_item_mace)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_ghost)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_ghoul)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_sword)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_bow)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_mace)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_potion_red)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox__item_blue)).EndInit();
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
        private System.Windows.Forms.PictureBox pictureBox_player;
        private System.Windows.Forms.PictureBox pictureBox_bat;
        private System.Windows.Forms.PictureBox pictureBox_item_red;
        private System.Windows.Forms.PictureBox pictureBox_item_blue;
        private System.Windows.Forms.PictureBox pictureBox_item_sword;
        private System.Windows.Forms.PictureBox pictureBox_item_bow;
        private System.Windows.Forms.PictureBox pictureBox_item_mace;
        private System.Windows.Forms.PictureBox pictureBox_ghost;
        private System.Windows.Forms.PictureBox pictureBox_ghoul;
        private System.Windows.Forms.PictureBox pictureBox_sword;
        private System.Windows.Forms.PictureBox pictureBox_bow;
        private System.Windows.Forms.PictureBox pictureBox_mace;
        private System.Windows.Forms.PictureBox pictureBox_potion_red;
        private System.Windows.Forms.PictureBox pictureBox__item_blue;
    }
}

