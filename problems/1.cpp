
#include <set>
#include <iterator>
#include <algorithm>
#include <iostream>

#include "../Problems.h"
#include "../Problem.h"
#include "../GeneralMaths.h"
#include "../Primes.h"
#include "../String.h"

using namespace std;

void P1() { 
AddProblem(
{
    1, "Add all the natural numbers below 1000 that are multiples of 3 or 5.",

    []() -> string {

        int limit = 1000;
        int sum = 0; // sum of all the multiples

        for (int i = 0; i < limit; i++)
        {
            if (i % 3 == 0 || i % 5 == 0)
            {
                sum += i;
            }
        }

        return to_string(sum);
    }        
});
};

class Problem1 : Problem
{
    Problem1()
        : Problem(1, "Add all the natural numbers below 1000 that are multiples of 3 or 5.")
    {
    }

    int Solve()
    {
        int limit = 1000;
        int sum = 0; // sum of all the multiples

        for (int i = 0; i < limit; i++)
        {
            if (i % 3 == 0 || i % 5 == 0)
            {
                sum += i;
            }
        }

        return sum;
    }
};