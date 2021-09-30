using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace Lab2_TheQuest
{
    class BluePotion : Weapon
    {
        public BluePotion(Game game, Point location)
        : base(game, location) { }

        public override string Name { get { return "BluePotion"; } }

        public override void Attack(Direction direction, Random random)
        {
            // Your code goes here
        }
    }
}
