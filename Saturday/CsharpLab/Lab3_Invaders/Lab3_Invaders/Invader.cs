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

            switch(InvaderType)
            {
                case ShipType.Bug:
                    switch(animationCell)
                    {
                        case 0:
                            return new Bitmap(Properties.Resources.bug1);
                        case 1:
                            return new Bitmap(Properties.Resources.bug2);
                        case 2:
                            return new Bitmap(Properties.Resources.bug3);
                        case 3:
                            return new Bitmap(Properties.Resources.bug4);
                        default:
                            return null;
                    }
                case ShipType.Saucer:
                    switch(animationCell)
                    {
                        case 0:
                            return new Bitmap(Properties.Resources.flyingsaucer1);
                        case 1:
                            return new Bitmap(Properties.Resources.flyingsaucer2);
                        case 2:
                            return new Bitmap(Properties.Resources.flyingsaucer3);
                        case 3:
                            return new Bitmap(Properties.Resources.flyingsaucer4);
                        default:
                            return null;
                    }
                case ShipType.Satellite:
                    switch(animationCell)
                    {
                        case 0:
                            return new Bitmap(Properties.Resources.satellite1);
                        case 1:
                            return new Bitmap(Properties.Resources.satellite2);
                        case 2:
                            return new Bitmap(Properties.Resources.satellite3);
                        case 3:
                            return new Bitmap(Properties.Resources.satellite4);
                        default:
                            return null;
                    }
                case ShipType.Spaceship:
                    switch(animationCell)
                    {
                        case 0:
                            return new Bitmap(Properties.Resources.spaceship1);
                        case 1:
                            return new Bitmap(Properties.Resources.spaceship2);
                        case 2:
                            return new Bitmap(Properties.Resources.spaceship3);
                        case 3:
                            return new Bitmap(Properties.Resources.spaceship4);
                        default:
                            return null;
                    }
                case ShipType.Star:
                    switch(animationCell)
                    {
                        case 0:
                            return new Bitmap(Properties.Resources.star1);
                        case 1:
                            return new Bitmap(Properties.Resources.star2);
                        case 2:
                            return new Bitmap(Properties.Resources.star3);
                        case 3:
                            return new Bitmap(Properties.Resources.star4);
                        default:
                            return null;
                    }
                default:
                    return null;
            }
        }
    }
}
