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
        enumTotal
    }

    class Invader
    {
        static Bitmap[][] bitmaps_;

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
            if (bitmaps_ == null)
                InvaderImageInit();

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

            return bitmaps_[(int)InvaderType][animationCell];
        }

        void InvaderImageInit()
        {
            if (bitmaps_ == null)
            {
                bitmaps_ = new Bitmap[(int)ShipType.enumTotal][];
                for (int i = 0; i < (int)ShipType.enumTotal; ++i)
                    bitmaps_[i] = new Bitmap[4];

                bitmaps_[(int)ShipType.Bug][0] = new Bitmap(Properties.Resources.bug1);
                bitmaps_[(int)ShipType.Bug][1] = new Bitmap(Properties.Resources.bug2);
                bitmaps_[(int)ShipType.Bug][2] = new Bitmap(Properties.Resources.bug3);
                bitmaps_[(int)ShipType.Bug][3] = new Bitmap(Properties.Resources.bug4);

                bitmaps_[(int)ShipType.Saucer][0] = new Bitmap(Properties.Resources.flyingsaucer1);
                bitmaps_[(int)ShipType.Saucer][1] = new Bitmap(Properties.Resources.flyingsaucer2);
                bitmaps_[(int)ShipType.Saucer][2] = new Bitmap(Properties.Resources.flyingsaucer3);
                bitmaps_[(int)ShipType.Saucer][3] = new Bitmap(Properties.Resources.flyingsaucer4);

                bitmaps_[(int)ShipType.Satellite][0] = new Bitmap(Properties.Resources.satellite1);
                bitmaps_[(int)ShipType.Satellite][1] = new Bitmap(Properties.Resources.satellite2);
                bitmaps_[(int)ShipType.Satellite][2] = new Bitmap(Properties.Resources.satellite3);
                bitmaps_[(int)ShipType.Satellite][3] = new Bitmap(Properties.Resources.satellite4);

                bitmaps_[(int)ShipType.Spaceship][0] = new Bitmap(Properties.Resources.spaceship1);
                bitmaps_[(int)ShipType.Spaceship][1] = new Bitmap(Properties.Resources.spaceship2);
                bitmaps_[(int)ShipType.Spaceship][2] = new Bitmap(Properties.Resources.spaceship3);
                bitmaps_[(int)ShipType.Spaceship][3] = new Bitmap(Properties.Resources.spaceship4);

                bitmaps_[(int)ShipType.Star][0] = new Bitmap(Properties.Resources.star1);
                bitmaps_[(int)ShipType.Star][1] = new Bitmap(Properties.Resources.star2);
                bitmaps_[(int)ShipType.Star][2] = new Bitmap(Properties.Resources.star3);
                bitmaps_[(int)ShipType.Star][3] = new Bitmap(Properties.Resources.star4);
            }
        }
    }
}
