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
        int animationCycle = 3;

        public Form1()
        {
            InitializeComponent();
        }




        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            switch(e.KeyCode)
            {
                case Keys.Q:
                    Application.Exit();
                    break;
                case Keys.S:
                    if (gameOver)
                    {
                        // code to reset the game and restart the timers
                        return;
                    }
                    break;
                case Keys.Space:
                    game.FireShot();
                    break;
                default:
                    if (keysPressed.Contains(e.KeyCode))
                        keysPressed.Remove(e.KeyCode);
                    keysPressed.Add(e.KeyCode);
                    break;
            }
        }

        private void Form1_KeyUp(object sender, KeyEventArgs e)
        {
            if (keysPressed.Contains(e.KeyCode))
                keysPressed.Remove(e.KeyCode);
        }

        private void timer_animation_Tick(object sender, EventArgs e)
        {
            switch(animationCycle)
            {
                case 4:  animationCycle = -1; break;
                case 3:  animationCycle++; break;
                case 2:  animationCycle++; break;
                case 1:  animationCycle++; break;
                case -1: animationCycle--; break;
                case -2: animationCycle--; break;
                case -3: animationCycle--; break;
                case -4: animationCycle = 1; break;
            }

            game.Twinkle();
            Refresh();
        }

        private void timer_game_Tick(object sender, EventArgs e)
        {
            game.Go();
            foreach (Keys key in keysPressed)
            {
                switch(key)
                {
                    case Keys.Left:
                        game.MovePlayer(Direction.Left);
                        return;
                    case Keys.Right:
                        game.MovePlayer(Direction.Right);
                        return;
                }
            }
        }
    }
}
