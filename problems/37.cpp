


#include "../Problems.h"
#include "../Problem.h"
#include "../GeneralMaths.h"
#include "../Primes.h"
#include <iostream>
#include <set>
using namespace std;



void P37() {
    AddProblem(
        {
            37, "Find the sum of the only eleven primes that are both truncatable from left to right and right to left.",

            []() -> string {
                int sum = 0;
                map<int, bool> primeMap;
                auto primes = GeneratePrimes(740000);
                for (auto prime : primes)
                {
                    primeMap[prime] = true;
                }
                bool seenComposite = false;
                vector<int> nums;
                for (auto prime : primes)
                {
                    if (prime <= 7) continue;
                    nums = NumbersByRemovingDigitsFromLeft(prime);
                    seenComposite = false;
                    for (auto num : nums)
                    {
                        if (!primeMap[num])
                        {
                            seenComposite = true;
                            break;
                        }
                    }
                    if (seenComposite) continue;

                    nums = NumbersByRemovingDigitsFromRight(prime);
                    seenComposite = false;
                    for (auto num : nums)
                    {
                        if (!primeMap[num])
                        {
                            seenComposite = true;
                            break;
                        }
                    }

                    if (!seenComposite)
                    {
                        sum += prime;
                    }
                }

                return to_string(sum);
        }
        });
};

