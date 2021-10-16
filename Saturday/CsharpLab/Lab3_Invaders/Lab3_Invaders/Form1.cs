using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab3_Invaders
{
    enum Direction
    {
        Left,
        Right,
        Up,
        Down,
    }

    public partial class Form1 : Form
    {
        List<Keys> keysPressed = new List<Keys>();
        Game game = new Game();
        bool gameOver;

        public Form1()
        {
            InitializeComponent();
        }



        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Q)
                Application.Exit();
            if (gameOver)
                if (e.KeyCode == Keys.S)
                {
                    // code to reset the game and restart the timers
                    return;
                }
            if (e.KeyCode == Keys.Space)
                game.FireShot();
            if (keysPressed.Contains(e.KeyCode))
                keysPressed.Remove(e.KeyCode);
            keysPressed.Add(e.KeyCode);
        }

        private void Form1_KeyUp(object sender, KeyEventArgs e)
        {
            if (keysPressed.Contains(e.KeyCode))
                keysPressed.Remove(e.KeyCode);
        }

        private void timer_animation_Tick(object sender, EventArgs e)
        {

        }

        private void timer_game_Tick(object sender, EventArgs e)
        {
            game.Go();
            foreach (Keys key in keysPressed)
            {
                if (key == Keys.Left)
                {
                    game.MovePlayer(Direction.Left);
                    return;
                }
                else if (key == Keys.Right)
                {
                    game.MovePlayer(Direction.Right);
                    return;
                }
            }
        }
    }
}
