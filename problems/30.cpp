
#include "../Problems.h"
#include "../Problem.h"

using namespace std;

map<int, int> fifthPowers;

int powerSum(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += fifthPowers[n%10];
        n = n / 10;
    }

    return sum;
}


void P30() {
    AddProblem(
        {
            30, "Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.",

            []() -> string {

                
                for (int i = 0; i < 10; i++)
                {
                    int result = i;
                    for (int j = 1; j < 5; j++)
                        result *= i;
                    fifthPowers[i] = result;
                }
                int sum = 0;
                for (int i = 10; i < 354294; i++) {
                    if (i == powerSum(i))
                        sum += i;
                }
                return to_string(sum);
            }
        });
};