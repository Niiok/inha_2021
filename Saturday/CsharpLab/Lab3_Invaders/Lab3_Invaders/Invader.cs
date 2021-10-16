using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace Lab3_Invaders
{
    enum ShipType
    {
        Bug,
        Saucer,
        Satellite,
        Spaceship,
        Star,
    }

    class Invader
    {
        private const int HorizontalInterval = 10;
        private const int VerticalInterval = 40;
        private Bitmap image;
        public Point Location { get; private set; }
        public ShipType InvaderType { get; private set; }
        public Rectangle Area
        {
            get
            {
                return new Rectangle(Location, image.Size);
            }
        }
        public int Score { get; private set; }
        public Invader(ShipType invaderType, Point location, int score)
        {
            this.InvaderType = invaderType;
            this.Location = location;
            this.Score = score;
            image = InvaderImage(0);
        }
        // Additional methods will go here

        public void Move(Direction direction)
        {
            // This method needs to move the ship in the
            // specified direction
        }

        public void Draw(Graphics g, int animationCell)
        {
            // This method needs to draw the image of
            // the ship, using the correct animation cell
        }

        private Bitmap InvaderImage(int animationCell)
        {
            // This is mostly a convenience method, and
            // returns the right bitmap for the specified cell
            return new Bitmap(Properties.Resources.bug1);
        }
    }
}
