using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace Lab2_TheQuest
{
    class Ghost : Enemy
    {
        public Ghost(Game game, Point location)
        : base(game, location, 6)
        { }
        public override void Move(Random random)
        {
            // Your code will go here


            if (NearPlayer())
                game.HitPlayer(4, random);
        }

    }
}
