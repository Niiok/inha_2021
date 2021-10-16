using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace Lab3_Invaders
{
    class Shot
    {
        private const int moveInterval = 20;
        private const int width = 5;
        private const int height = 15;
        public Point Location { get; private set; }
        private Direction direction;
        private Rectangle boundaries;
        public Shot(Point location, Direction direction,
        Rectangle boundaries)
        {
            this.Location = location;
            this.direction = direction;
            this.boundaries = boundaries;
        }
        // Your code goes here

        public void Draw(Graphics g)
        {

        }
    }
}
