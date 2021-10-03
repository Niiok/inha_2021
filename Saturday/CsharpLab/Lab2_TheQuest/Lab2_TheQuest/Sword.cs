using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace Lab2_TheQuest
{
    class Sword : Weapon
    {
        public Sword(Game game, Point location)
        : base(game, location) { }

        public override string Name { get { return "Sword"; } }

        public override void Attack(Direction direction, Random random)
        {
            // Your code goes here

            Point dirVec = new Point(0, 0);

            switch (direction)
            {
                case Direction.Up:
                    dirVec.Y = 1;
                    break;
                case Direction.Right:
                    dirVec.X = 1;
                    break;
                case Direction.Left:
                    dirVec.X = -1;
                    break;
                case Direction.Down:
                    dirVec.Y = -1;
                    break;
            }

            foreach(var enemy in game.Enemies)
            {
                Point eneVec = new Point(enemy.Location.X - location.X, enemy.Location.Y - location.Y);

                if(dirVec.X * eneVec.X + dirVec.Y * eneVec.Y > 0)
                {
                    enemy.Hit(4, random);
                }
            }
            
        }
    }
}
