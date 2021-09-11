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

            PictureBox[] dogPictures = { pictureDog0, pictureDog1, pictureDog2, pictureDog3 };
            RadioButton[] guyRadios = {radioButtonGuy0, radioButtonGuy1, radioButtonGuy2 };
            Label[] guyLabels = {labelGuy0, labelGuy1, labelGuy2 };

            KeyValuePair<string, int>[] guyInfos =
                {
                new KeyValuePair<string, int>("", seedMoney),
                new KeyValuePair<string, int>("", seedMoney),
                new KeyValuePair<string, int>("", seedMoney)
            };


            for (int i = dogs.Length - 1; i >= 0; --i)            
                dogs[i] = new Greyhound(dogPictures[i], rand);

            for (int i = guys.Length - 1; i >= 0; --i)
                guys[0] = new Guy(guyInfos[0], guyRadios[0], guyLabels[0]);


            Reset();
        }

        private void Reset()
        {
            numericUpDown1.Increment = minBet;

            numericUpDown2.Minimum = 1;
            numericUpDown2.Maximum = dogs.Length;

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
