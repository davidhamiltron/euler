
#include "../Problems.h"
#include "../Problem.h"
#include "../GeneralMaths.h"
#include "../Primes.h"
#include <iostream>
#include <set>
using namespace std;



void P36() {
    AddProblem(
        {
            36, "Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.",

            []() -> string {
                int sum = 0;

                for (int i = 1; i < 1000000; i++)
                {
                    if (IsPalindrome(i)) {
                        auto digits = ToDigitsBinary(i);
                        if (IsPalindromeVector(digits)) {
                            cout << i << endl;
                            sum += i;
                        }
                    }
                }

                return to_string(sum);
            }
        });
};

