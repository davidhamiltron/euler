
#include <fstream>
#include "../Problems.h"
#include "../Problem.h"
#include "../Poker.h"

using namespace std;

void P54() {
    AddProblem(
        {
            54, "How many hands does Player 1 win?",

            []() -> string {

                //Poker::Game g("8C TS KC 9H 4S 7D 2S 5D 3S AC");
                //int p = g.Result();
                //int answer = 0;

                int player1Won = 0;
                vector<string> lines = GetLines("54.txt");
                
                for(string hands : lines)
                {
                    Poker::Game g(hands);
                    int result = g.Result();
                    if (result == 1)
                    {
                        player1Won++;
                    }
                }

                return to_string(player1Won);
            }
        });
};