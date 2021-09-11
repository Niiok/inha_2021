using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab1_RaceDay
{
    class Bet
    {
        public int Amount; // The amount of cash that was bet
        public int Dog; // The number of the dog the bet is on
        public Guy Bettor; // The guy who placed the bet

        public string GetDescription()
        {
            // Return a string that says who placed the bet, how much 
            // cash was bet, and which dog he bet on (“Joe bets 8 on 
            // dog #4”). If the amount is zero, no bet was placed 
            // (“Joe hasn’t placed a bet”). 
            if (Amount == 0)
                return $"{Bettor} rests on this round";
            else
                return $"{Bettor} bets {Amount} bucks on dog #{Dog}";
        }

        public int PayOut(int Winner)
        {
            // The parameter is the winner of the race. If the dog won, 
            // return the amount bet. Otherwise, return the negative of 
            // the amount bet. 
            return (Dog == Winner ? Amount : -Amount);
        }
    }
}
