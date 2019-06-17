
#include "../Problems.h"
#include "../Problem.h"
#include "../GeneralMaths.h"
#include "../Primes.h"
#include <iostream>
#include <set>
using namespace std;



void P35() {
    AddProblem(
        {
            35, "How many circular primes are there below one million?",

            []() -> string {

                int numCircularPrimes = 0;
                vector<int> circularPrimes;
                map<int, bool> primeMap;
                
                auto primes = GeneratePrimes(1000000);

                for (int n : primes)
                {
                    primeMap[n] = true;
                }

                for (int n : primes)
                {
                    if (n < 10)
                    {
                        circularPrimes.push_back(n);
                        continue;
                    }
                    int numDigits = NumDigits(n);
                    int m = n;
                    bool circular = true;
                    for (int i = 0; i < numDigits; i++)
                    {
                        m = Rotate(m, numDigits);
                        if (!primeMap[m]) {
                            circular = false;
                            break;
                        }
                    }
                    if (circular)
                        circularPrimes.push_back(n);
                }

                return to_string(circularPrimes.size());
            }
        });
};

