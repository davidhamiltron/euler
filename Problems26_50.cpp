﻿

#include <set>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <array>

#include "Problems.h"
#include "GeneralMaths.h"
#include "Primes.h"
#include "String.h"

using namespace std;

enum Direction
{
    Left,
    Up,
    Right,
    Down
};

map<int, ProblemLambda> Problems26_50()
{
    return{

        ProblemStart(26, "Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.")

        
            
            answer = 0;
    
        ProblemEnd

        ProblemStart(27, "Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n=0.")

            int primesUnder = 500000;
            auto primes = GeneratePrimes(primesUnder);
            //map<int, bool> primesMap;
            bool primesMap[500000];
            for (int i = 0; i < primesUnder; i++)
                primesMap[i] = false;
            for (auto i : primes)
                primesMap[i] = true;

            auto primesSearch = GeneratePrimes(1000);
            for (auto i : primes)
                primesSearch.push_back(i * -1);


            int n = 0;
            int a = -1000;
            int primeCount = 0;
            int maxPrimes = 0;
            int maxPrimesA = 0;
            int maxPrimesB = 0;
            int res = 0;
            while (a < 1000)
            {
                for (auto b : primesSearch)
                {
                    primeCount = 0;
                    n = 0;
                    res = 0;
                    while (true)
                    {
                        res = n * n + n * a + b;
                        if (primesMap[res])
                        {
                            n++;
                            primeCount++;
                        }
                        else
                            break;
                    }

                    if (primeCount > maxPrimes)
                    {
                        //cout << "new max primes " << primeCount << " for " << a << " " << b << endl;
                        maxPrimes = primeCount;
                        maxPrimesA = a;
                        maxPrimesB = b;
                    }
                }

                a++;
            }

            //cout << "n: " << maxPrimes << ", a: " << maxPrimesA << ", b: " << maxPrimesB << endl;
            answer = maxPrimesA * maxPrimesB;

        ProblemEnd

        ProblemStart(28, "What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?")

            const int width = 1001;
            const int height = 1001;
            //int* spiral = new int[width*height];
            std::vector<std::vector<int>> spiral;

            for (int y = 0; y < height; y++)
            {
                vector<int> row;
                for (int x = 0; x < width; x++)
                    row.push_back(0);
                spiral.push_back(row);
            }

            int x = width/2;
            int y = height/2;
            Direction direction = Right;
            int num = 1;
            spiral[x][y] = num;

            while (true)
            {
                if (direction == Right)
                {
                    x += 1;
                    if (spiral[x][y - 1] == 0)
                        direction = Up;
                }
                else if (direction == Up)
                {
                    y -= 1;
                    if (spiral[x - 1][y] == 0)
                        direction = Left;
                }
                else if (direction == Left)
                {
                    x -= 1;
                    if (spiral[x][y + 1] == 0)
                        direction = Down;
                }
                else if (direction == Down)
                {
                    y += 1;
                    if (spiral[x + 1][y] == 0)
                        direction = Right;
                }

                num++;
                spiral[x][y] = num;

                if ((x + 1) == width && (y + 1) == height)
                    break;
            }

            /*for (int y = 0; y < height; y++)
            {
                for (int x = 0; x < width; x++)
                    cout << spiral[x][y] << " ";
                cout << endl;
            }*/

            int sum = 0;

            for (int y = 0, x = 0; y < height, x < width; y++, x++)
            {
                sum += spiral[x][y];
            }

            for (int y = 0, x = width - 1; y < height, x >= 0; y++, x--)
            {
                sum += spiral[x][y];
            }

            answer = sum - 1;

        ProblemEndLast

    };
}