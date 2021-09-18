using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace Lab2_TheQuest
{
    abstract class Weapon : Mover
    {
        //protected Game game;

        private bool pickedUp;

        public bool PickedUp { get { return pickedUp; } }

        //private Point location;

        //public Point Location { get { return location; } }

        public Weapon(Game game, Point location) : base(game, location)
        {
            //this.game = game;
            //this.location = location;
            pickedUp = false;
        }

        public void PickUpWeapon() { pickedUp = true; }

        public abstract string Name { get; }

        public abstract void Attack(Direction direction, Random random);

        protected bool DamageEnemy(Direction direction, int radius, int damage, Random random)
        {
            Point target = game.PlayerLocation;
            for (int distance = 0; distance < radius; distance++)
            {
                foreach (Enemy enemy in game.Enemies)
                {
                    if (Nearby(enemy.Location, target, radius))
                    {
                        enemy.Hit(damage, random);
                        return true;
                    }
                }
                target = Move(direction, target, game.Boundaries);
            }
            return false;
        }
    }
}
