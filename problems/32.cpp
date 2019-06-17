
#include "../Problems.h"
#include "../Problem.h"
#include "../GeneralMaths.h"
#include <iostream>
#include <set>
using namespace std;



void P32() {
    AddProblem(
        {
            32, "Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.",

            []() -> string {
                int product = 0;
                int pandigitalTest = 0;
                bool stopping = false;
                set<int> products;
                int sum = 0;
                // 1 and 4 digit numbers
                for (int i = 1; i <= 9; i++) {
                    for (int j = 1000; j <= 9999; j++) {
                        product = i * j;

                        if (product > 9999) {
                            break;
                        }
                        pandigitalTest = i * 100000000 + j * 10000 + product;
                        //if (!(pandigitalTest > 100000000 && pandigitalTest < 999999999)) continue;
                        if (IsPandigital(pandigitalTest, 9))
                        {
                            //cout << i << " * " << j << " = " << product << endl;
                            products.insert(product);
                        }
                    }
                }

                // 2 and 3 digit numbers
                for (int i = 10; i <= 99; i++) {
                    for (int j = 100; j <= 999; j++) {
                        product = i * j;

                        if (product > 9999) {
                            break;
                        }
                        pandigitalTest = i * 10000000 + j * 10000 + product;
                        //if (!(pandigitalTest > 100000000 && pandigitalTest < 999999999)) continue;
                        if (IsPandigital(pandigitalTest, 9))
                        {
                            cout << i << " * " << j << " = " << product << endl;
                            products.insert(product);
                        }
                    }
                }

                
                for (int i : products)
                    sum += i;
                return to_string(sum);
            }
        });
};

