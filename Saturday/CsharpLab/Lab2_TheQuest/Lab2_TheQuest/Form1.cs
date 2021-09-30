using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab2_TheQuest
{
    public partial class label_ghoulHitPoint : Form
    {
        private Game game;
        private Random random = new Random();

        public label_ghoulHitPoint()
        {
            InitializeComponent();
        }

        void UpdateCharacters()
        {
            //pictureBox_bat.Visible = false;
            //pictureBox_bow.Visible = false;
            //pictureBox_ghost.Visible = false;
            //pictureBox_ghoul.Visible = false;
            //pictureBox_item_blue.Visible = false;
            //pictureBox_item_bow.Visible = false;
            //pictureBox_item_mace.Visible = false;
            //pictureBox_item_red.Visible = false;
            //pictureBox_item_sword.Visible = false;
            //pictureBox_mace.Visible = false;
            ////pictureBox_player.Visible = false;
            //pictureBox_potion_blue.Visible = false;
            //pictureBox_potion_red.Visible = false;
            //pictureBox_sword.Visible = false;


            pictureBox_player.Location = game.PlayerLocation;
            label_playerHitPoint.Text =
            game.PlayerHitPoints.ToString();

            bool showBat = false;
            bool showGhost = false;
            bool showGhoul = false;
            int enemiesShown = 0;

            foreach (Enemy enemy in game.Enemies)
            {
                if (enemy is Bat)
                {
                    pictureBox_bat.Location = enemy.Location;
                    label_batHitPoint.Text = enemy.HitPoints.ToString();
                    if (enemy.HitPoints > 0)
                    {
                        showBat = true;
                        enemiesShown++;
                    }
                }
            }
            pictureBox_sword.Visible = false;
            pictureBox_bow.Visible = false;
            pictureBox_potion_red.Visible = false;
            pictureBox_potion_blue.Visible = false;
            pictureBox_mace.Visible = false;
            Control weaponControl = null;
            switch (game.WeaponInRoom.Name)
            {
                case "Sword":
                    weaponControl = pictureBox_sword; break;
            }
            weaponControl.Location = game.WeaponInRoom.Location;
            if (game.WeaponInRoom.PickedUp)
            {
                weaponControl.Visible = false;
            }
            else
            {
                weaponControl.Visible = true;
            }
            if (game.PlayerHitPoints <= 0)
            {
                MessageBox.Show("You died");
                Application.Exit();
            }
            if (enemiesShown < 1)
            {
                MessageBox.Show("You have defeated the enemies on this level");
                game.NewLevel(random);
                UpdateCharacters();
            }

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            game = new Game(new Rectangle(78, 57, 420, 155));
            game.NewLevel(random);
            UpdateCharacters();
        }

        private void button_move_up_Click(object sender, EventArgs e)
        {
            game.Move(Direction.Up, random);
            UpdateCharacters();
        }

        private void button_move_left_Click(object sender, EventArgs e)
        {
            game.Move(Direction.Left, random);
            UpdateCharacters();
        }

        private void button_move_right_Click(object sender, EventArgs e)
        {
            game.Move(Direction.Right, random);
            UpdateCharacters();
        }

        private void button_move_down_Click(object sender, EventArgs e)
        {
            game.Move(Direction.Down, random);
            UpdateCharacters();
        }

        private void button_attack_up_Click(object sender, EventArgs e)
        {
            game.Attack(Direction.Up, random);
            UpdateCharacters();
        }

        private void button_attack_left_Click(object sender, EventArgs e)
        {
            game.Attack(Direction.Left, random);
            UpdateCharacters();
        }

        private void button_attack_right_Click(object sender, EventArgs e)
        {
            game.Attack(Direction.Right, random);
            UpdateCharacters();
        }

        private void button_attack_down_Click(object sender, EventArgs e)
        {
            game.Attack(Direction.Down, random);
            UpdateCharacters();
        }

        private void pictureBox_item_sword_Click(object sender, EventArgs e)
        {
            if (game.CheckPlayerInventory("Sword"))
            {
                game.Equip("Sword");
                pictureBox_item_sword.BorderStyle = BorderStyle.FixedSingle;
                pictureBox_item_bow.BorderStyle = BorderStyle.None;
                pictureBox_item_mace.BorderStyle = BorderStyle.None;
                pictureBox_item_blue.BorderStyle = BorderStyle.None;
                pictureBox_item_red.BorderStyle = BorderStyle.None;

                button_attack_up.Text = "Up";
                button_attack_left.Visible = true;
                button_attack_right.Visible = true;
                button_attack_down.Visible = true;
            }
        }

        private void pictureBox_item_bow_Click(object sender, EventArgs e)
        {
            if (game.CheckPlayerInventory("Bow"))
            {
                game.Equip("Bow");
                pictureBox_item_sword.BorderStyle = BorderStyle.None;
                pictureBox_item_bow.BorderStyle = BorderStyle.FixedSingle;
                pictureBox_item_mace.BorderStyle = BorderStyle.None;
                pictureBox_item_blue.BorderStyle = BorderStyle.None;
                pictureBox_item_red.BorderStyle = BorderStyle.None;

                button_attack_up.Text = "Up";
                button_attack_left.Visible = true;
                button_attack_right.Visible = true;
                button_attack_down.Visible = true;
            }
        }

        private void pictureBox_item_mace_Click(object sender, EventArgs e)
        {
            if (game.CheckPlayerInventory("Mace"))
            {
                game.Equip("Mace");
                pictureBox_item_sword.BorderStyle = BorderStyle.None;
                pictureBox_item_bow.BorderStyle = BorderStyle.None;
                pictureBox_item_mace.BorderStyle = BorderStyle.FixedSingle;
                pictureBox_item_blue.BorderStyle = BorderStyle.None;
                pictureBox_item_red.BorderStyle = BorderStyle.None;

                button_attack_up.Text = "Up";
                button_attack_left.Visible = true;
                button_attack_right.Visible = true;
                button_attack_down.Visible = true;
            }
        }

        private void pictureBox_item_blue_Click(object sender, EventArgs e)
        {
            if (game.CheckPlayerInventory("BluePotion"))
            {
                game.Equip("BluePotion");
                pictureBox_item_sword.BorderStyle = BorderStyle.None;
                pictureBox_item_bow.BorderStyle = BorderStyle.None;
                pictureBox_item_mace.BorderStyle = BorderStyle.None;
                pictureBox_item_blue.BorderStyle = BorderStyle.FixedSingle;
                pictureBox_item_red.BorderStyle = BorderStyle.None;

                button_attack_up.Text = "Drink";
                button_attack_left.Visible = false;
                button_attack_right.Visible = false;
                button_attack_down.Visible = false;
            }
        }

        private void pictureBox_item_red_Click(object sender, EventArgs e)
        {
            if (game.CheckPlayerInventory("RedPotion"))
            {
                game.Equip("RedPotion");
                pictureBox_item_sword.BorderStyle = BorderStyle.None;
                pictureBox_item_bow.BorderStyle = BorderStyle.None;
                pictureBox_item_mace.BorderStyle = BorderStyle.None;
                pictureBox_item_blue.BorderStyle = BorderStyle.None;
                pictureBox_item_red.BorderStyle = BorderStyle.FixedSingle;

                button_attack_up.Text = "Drink";
                button_attack_left.Visible = false;
                button_attack_right.Visible = false;
                button_attack_down.Visible = false;
            }
        }
    }
}
