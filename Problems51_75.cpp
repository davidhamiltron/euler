
#include "Problems.h"
#include "GeneralMaths.h"
#include "Poker.h"

using namespace std;

map<int, ProblemLambda> Problems51_75()
{
    return{

        ProblemStart(54, "How many hands does Player 1 win?")

            Poker::Game g("5H 5C 6S 7S KD 2C 3S 8S 8D TD");
            int p = g.Result();
            answer = 0;


        ProblemEnd

        ProblemStart(67, "Add all the natural numbers below 1000 that are multiples of 3 or 5.")

            answer = 2;


        ProblemEndLast

    };
}