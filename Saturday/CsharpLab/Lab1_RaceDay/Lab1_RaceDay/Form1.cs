using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab1_RaceDay
{
    public partial class Form1 : Form
    {
        enum State
        {
            Before,
            Running,
            After
        }

        Guy[] guys = new Guy[3];
        Greyhound[] dogs = new Greyhound[4];

        int seedMoney = 50;
        int minBet = 5;
        State state = State.Before;   

        public Form1()
        {
            InitializeComponent();

            Random rand = new Random();

            dogs[0] = new Greyhound();
            dogs[0].MyPictureBox = pictureDog0;
            dogs[0].StartingPosition = pictureDog0.Location.X;
            //dogs[0].RacetrackLength = pictureBox0.Size.Width - pictureDog0.Size.Width;
            dogs[0].Randomizer = rand;

            dogs[1] = new Greyhound();
            dogs[1].MyPictureBox = pictureDog1;
            dogs[1].StartingPosition = pictureDog1.Location.X;
            dogs[1].Randomizer = rand;

            dogs[2] = new Greyhound();
            dogs[2].MyPictureBox = pictureDog2;
            dogs[2].StartingPosition = pictureDog2.Location.X;
            dogs[2].Randomizer = rand;

            dogs[3] = new Greyhound();
            dogs[3].MyPictureBox = pictureDog3;
            dogs[3].StartingPosition = pictureDog3.Location.X;
            dogs[3].Randomizer = rand;

            guys[0] = new Guy();
            guys[0].Name = "man1";
            guys[0].Cash = seedMoney;
            guys[0].MyLabel = labelGuy0;
            guys[0].MyRadioButton = radioButtonGuy0;

            guys[1] = new Guy();
            guys[1].Name = "man2";
            guys[1].Cash = seedMoney;
            guys[1].MyLabel = labelGuy1;
            guys[1].MyRadioButton = radioButtonGuy1;

            guys[2] = new Guy();
            guys[2].Name = "man3";
            guys[2].Cash = seedMoney;
            guys[2].MyLabel = labelGuy2;
            guys[2].MyRadioButton = radioButtonGuy2;


            numericUpDown2.Minimum = 1;
            numericUpDown2.Maximum = dogs.Length;   
            Reset();
        }

        private void Reset()
        {
            labelOnRadio.Text = $"Minimum bet: {minBet} bucks";
            label5.Text = "Bets";

            foreach (Guy guy in guys)
                guy.ClearBet();

            foreach (Greyhound dog in dogs)
            {
                dog.RacetrackLength = pictureBox0.Size.Width - dog.MyPictureBox.Size.Width;
                dog.TakeStartingPosition();
            }
        }

        private int Run()
        {
            int winner = -1;

            while (winner == -1)
            {
                pictureBox0.Update();

                for (int i = 0; i < dogs.Length; ++i)
                {
                    if (dogs[i].Run())
                    {
                        winner = i;
                        break;
                    }
                }
            }

            return winner;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            switch (state)
            {
                case State.Before:
                    button1.Text = "Running..";
                    button1.Enabled = false;
                    MessageBox.Show($"Winner is Dog #{Run() + 1}!");
                    button1.Text = "Reset";
                    button1.Enabled = true;
                    state = State.After;

                    break;

                case State.After:
                    Reset();
                    button1.Text = "Race !";
                    state = State.Before;
                    break;
            }
        }
    }
}
