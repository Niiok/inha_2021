using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace Lab3_Invaders
{
    class Stars
    {
        private struct Star
        {
            public Point point;
            public Pen pen;
            public Star(Point point, Pen pen)
            {
                this.point = point;
                this.pen = pen;
            }
        }

        public void Draw(Graphics g)
        {

        }

        public void Twinkle(Random random)
        {

        }
    }
}
