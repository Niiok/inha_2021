using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab1_RaceDay
{
    class Guy
    {
        public string Name; // The guy’s name
        public Bet MyBet; // An instance of Bet() that has his bet
        public int Cash; // How much cash he has
                         // The last two fields are the guy’s GUI controls on the form 
        public RadioButton MyRadioButton; // My RadioButton
        public Label MyLabel; // My Label

        public Guy(KeyValuePair<string, int> name_money, RadioButton radio, Label label)
        {
            Name = name_money.Key;
            Cash = name_money.Value;
            MyRadioButton = radio;
            MyLabel = label;
        }

        public void UpdateLabels()
        {
            // Set my label to my bet’s description, and the label on my 
            // radio button to show my cash (“Joe has 43 bucks”) 

            if (MyBet == null)
                MyLabel.Text = $"{Name} hasn't placed a bet";
            else
                MyLabel.Text = MyBet.GetDescription();

            MyRadioButton.Text = $"{Name} has {Cash} busks";
        }
        
        public void ClearBet()
        {
            // Reset my bet so it’s zero
            MyBet = null;
        } 

        public bool PlaceBet(int Amount, int Dog)
        {
            if (Amount > Cash)
                return false;

            // Place a new bet and store it in my bet field 
            MyBet = new Bet();
            MyBet.Amount = Amount;
            MyBet.Bettor = this;
            MyBet.Dog = Dog;

            // Return true if the guy had enough money to bet 
            return true;
        }

        public void Collect(int Winner) 
        {
            // Ask my bet to pay out

            if (MyBet == null)
                return;

            Cash += MyBet.PayOut(Winner);
        }
    }
}
