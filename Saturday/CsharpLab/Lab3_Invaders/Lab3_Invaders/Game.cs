using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace Lab3_Invaders
{
    class Game
    {
        private int score = 0;
        private int livesLeft = 2;
        private int wave = 0;
        private int framesSkipped = 0;
        private Rectangle boundaries;
        private Random random;
        private Direction invaderDirection;
        private List<Invader> invaders;
        private PlayerShip playerShip;
        private List<Shot> playerShots;
        private List<Shot> invaderShots;
        private Stars stars;
        public event EventHandler GameOver;
        // etc...

        public void Draw(Graphics g, int animationCell)
        {
            stars.Draw(g);
            foreach (Invader invader in invaders)
                invader.Draw(g, animationCell);
            playerShip.Draw(g);
            foreach (Shot shot in playerShots)
                shot.Draw(g);
            foreach (Shot shot in invaderShots)
                shot.Draw(g);
        }

        public void Twinkle()
        {
        }

        public void MovePlayer(Direction direction)
        {

        }

        public void FireShot()
        {

        }

        public void Go()
        {

        }
    }
}
