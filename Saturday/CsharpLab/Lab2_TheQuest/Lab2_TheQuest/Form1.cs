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
    public partial class Form1 : Form
    {
        private Game game;
        private Random random = new Random();

        public Form1()
        {
            InitializeComponent();
        }

        void UpdateCharacters()
        {
            // map picture move
            // inventory refresh

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
    }
}
