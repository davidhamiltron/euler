
#include "../Problems.h"
#include "../Problem.h"
#include "../GeneralMaths.h"
#include <iostream>
#include <set>
using namespace std;



void P34() {
    AddProblem(
        {
            34, "Find the sum of all numbers which are equal to the sum of the factorial of their digits.",

            []() -> string {
        
                int sum = 0;
                int digitsSum = 0;

                // Can precompute factorials since we only need 0 to 9;
                map<int, int> factorials;
                factorials[0] = 1;
                factorials[1] = 1;
                factorials[2] = 2;
                for (int i = 3; i <= 9; i++)
                {
                    factorials[i] = i * factorials[i - 1];
                }

                for (int i = 10; i <= 40730; i++)
                {
                    digitsSum = 0;
                    int n = i;
                    // Add each digit factorial
                    while (n > 0) {
                        int d = n % 10;
                        n /= 10;
                        digitsSum += factorials[d];
                    }
                    if (digitsSum == i)
                    {
                        cout << i << endl;
                        sum += i;
                    }
                }

                return to_string(sum);
            }
        });
};

