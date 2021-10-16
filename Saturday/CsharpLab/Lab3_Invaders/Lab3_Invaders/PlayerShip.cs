using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace Lab3_Invaders
{
    class PlayerShip
    {
        public Point Location;
        public Rectangle Area;
        public bool Alive;

        public void Draw(Graphics g)
        {
            if (!Alive)
            {
                //Reset the deadShipHeight field and draw the ship.
            }
            else
            {
                //Check the deadShipHeight field. If it's greater than zero, decrease it by 1
                //and use DrawImage() to draw the ship a little flatter.
            }
        }

        public void Move(Direction direction)
        {

        }
    }
}
