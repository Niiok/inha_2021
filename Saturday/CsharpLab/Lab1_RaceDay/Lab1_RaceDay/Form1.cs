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
                new KeyValuePair<string, int>("Joe", seedMoney),
                new KeyValuePair<string, int>("Ash", seedMoney),
                new KeyValuePair<string, int>("Smith", seedMoney)
            };


            for (int i = dogs.Length - 1; i >= 0; --i)            
                dogs[i] = new Greyhound(dogPictures[i], rand);

            for (int i = guys.Length - 1; i >= 0; --i)
                guys[i] = new Guy(guyInfos[i], guyRadios[i], guyLabels[i]);


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
            {
                guy.ClearBet();
                guy.UpdateLabels();
            }

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

                int i = 0;

                for (; i < dogs.Length; ++i)
                    if (dogs[i].Run())
                    {
                        winner = i;
                        break;
                    }

                i--;

                if (winner == -1)
                    for (; i >= 0; --i)
                        if (dogs[i].Run())
                        {
                            winner = i;
                            break;
                        }
            }

            return winner;
        }

        private void OnRaceButton_Click(object sender, EventArgs e)
        {
            switch (state)
            {
                case State.Before:
                    foreach (var guy in guys)
                    {
                        if (guy.MyBet == null)
                        {
                            MessageBox.Show($"{guy.Name} hasn't placed bet");
                            return;
                        }
                    }

                    raceButton.Text = "Running..";
                    raceButton.Enabled = false;

                    int winner = Run();
                    MessageBox.Show($"Winner is Dog #{winner + 1}!");
                    foreach (var guy in guys)
                        guy.Collect(winner);

                    raceButton.Text = "Reset";
                    raceButton.Enabled = true;
                    state = State.After;

                    break;

                case State.After:
                    Reset();
                    raceButton.Text = "Race !";
                    state = State.Before;
                    break;
            }
        }

        private void OnBetButton_Click(object sender, EventArgs e)
        {
            if (radioButtonGuy0.Checked)
            {
                guys[0].PlaceBet((int)numericUpDown1.Value, (int)numericUpDown2.Value);
                guys[0].UpdateLabels();
            }
            else if (radioButtonGuy1.Checked)
            {
                guys[1].PlaceBet((int)numericUpDown1.Value, (int)numericUpDown2.Value);
                guys[1].UpdateLabels();
            }
            else if (radioButtonGuy2.Checked)
            {
                guys[2].PlaceBet((int)numericUpDown1.Value, (int)numericUpDown2.Value);
                guys[2].UpdateLabels();
            }
           
        }
    }
}
