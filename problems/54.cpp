
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

                char hands[256];
                int player1Won = 0;
                ifstream inFile("D:\\programming\\euler\\problems\\54.txt");
                if (!inFile) return "0";
                int count = 1;
                while (!inFile.eof())
                {
                    inFile.getline(hands, 256);
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