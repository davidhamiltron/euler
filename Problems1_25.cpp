

#include <set>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Problems.h"
#include "GeneralMaths.h"
#include "Primes.h"
#include "String.h"

using namespace std;

map<int, ProblemLambda> Problems1_25()
{
return{

    ProblemStart(1, "Add all the natural numbers below 1000 that are multiples of 3 or 5.")

        int limit = 1000;
        int sum = 0; // sum of all the multiples

        for (int i = 0; i < limit; i++)
        {
            if (i % 3 == 0 || i % 5 == 0)
            {
                sum += i;
            }
        }

        answer = sum;

    ProblemEnd

    ProblemStart(2, "Find the sum of all the even-valued terms in the Fibonacci sequence which do not exceed one million.")

        int a = 1;
        int b = 2;
        int c = 0;
        int sum = 2;  // Already seen one even number

        while (c < 1000000)
        {
            c = Fibonacci(a, b);
            if (c % 2 == 0)
            {
                sum += c;
            }
            a = b;
            b = c;

        }

        answer = sum;

    ProblemEnd

    ProblemStart(3, "Find the largest prime factor of a composite number.")

        int64_t largestFactor = 0;
        int64_t num = 600851475143;
        auto factors = PrimeFactorise(num, 10000);//(__int64) sqrt((double)iNum));

        auto mapItr = factors.begin();
        while (mapItr != factors.end())
        {
            if ((*mapItr).second)
            {
                //cout << (*mapItr).first << "^" << (*mapItr).second << endl;
                largestFactor = (*mapItr).first;
            }
            mapItr++;
        }

        answer = largestFactor;
    ProblemEnd

    ProblemStart(4, "Find the largest palindrome made from the product of two 3-digit numbers.")

        int low = 100;
        int high = 999;
        int num;
        int largestPalindrome = 0;

        for (int i = high; i >= low; i--)
        {
            for (int j = 990; j >= low; j -= 11)
            {
                num = i * j;
                if (IsPalindrome(num))
                {
                    if (num > largestPalindrome)
                        largestPalindrome = num;
                }
            }
        }
        answer = largestPalindrome;
    ProblemEnd

    ProblemStart(5, "What is the smallest number divisible by each of the numbers 1 to 20?")

        int divisibleByAllLessThan = 20;

        int smallestNumber = divisibleByAllLessThan;

        bool divisible = false;
        while (!divisible)
        {
            divisible = true;

            for (int i = 1; i <= (divisibleByAllLessThan - 1); i++)		// -1 because we are only examining multiples of the highest factor
            {
                if (smallestNumber%i != 0)
                {
                    divisible = false;
                    break;
                }
            }

            if (divisible) break;

            smallestNumber += divisibleByAllLessThan;
        }

        answer = smallestNumber;
    ProblemEnd

    ProblemStart(6, "What is the difference between the sum of the squares and the square of the sums?")

        int difference = 0;
        int num = 100;

        int sumOfSquares = 0;
        int squareOfSum = 0;

        for (int i = 1; i <= num; i++)
        {
            sumOfSquares += i*i;
            squareOfSum += i;
        }

        squareOfSum *= squareOfSum;

        difference = squareOfSum - sumOfSquares;

        answer = difference;

    ProblemEnd

    ProblemStart(7, "Find the 10001st prime.")

        __int64 iPrime = 0;
        int iIndex = 10001;
        iPrime = GetPrime(iIndex);

        answer = iPrime;

    ProblemEnd

    ProblemStart(8, "Find the greatest product of five consecutive digits in the 1000-digit number.")

        auto lines = GetLines("8.txt");
    
        char num[1001];

        strncpy_s(num, lines[0].c_str(), lines[0].size());

        int largestProduct = 0;
        int product = 0;

        for (int i = 0; i < (1000 - 4); i++)
        {
            product =
                (int)(num[i] - 48) *
                (int)(num[i + 1] - 48) *
                (int)(num[i + 2] - 48) *
                (int)(num[i + 3] - 48) *
                (int)(num[i + 4] - 48);

            if (product > largestProduct)
                largestProduct = product;
        }

        answer = largestProduct;

    ProblemEnd

    ProblemStart(9, "Find the only Pythagorean triplet, {a, b, c}, for which a + b + c = 1000.")

        int product = 0;
        float c = 0;
        int a = 1;
        int b = 1;
        bool found = false;

        for (a = 1; a < 500; a++)
        {
            for (b = 1; b < 500; b++)
            {
                c = sqrt((float)((a*a) + (b*b)));
                if (a + b + c == 1000)
                {
                    found = true;
                    break;
                }
            }

            if (found) break;
        }

        //cout << a << " " << b << " " << c << endl;

        product = a * b * (int)c;

        answer = product;

    ProblemEnd

    ProblemStart(10, "Calculate the sum of all the primes below one million.")

        __int64 sum = 0;

        for (int i = 0; i < 1000000; i++)
        {
            if (IsPrime(i))
            {
                sum += i;
            }
        }
        answer = sum;

    ProblemEnd

    ProblemStart(11, "What is the greatest product of four numbers on the same straight line in the 20 by 20 grid?")

        auto lines = GetLines("11.txt");
        vector<string> numbers;

        vector<vector<int>> grid;
        vector<int> row;

        for (auto line : lines)
        {
            if (line.empty()) continue;
            Split(numbers, line, " ");
            row.clear();
            for (auto number : numbers)
            {
                row.push_back(stoi(number));
            }
            grid.push_back(row);
        }
    

        int largestProduct = 0;

        int product;

        // horizontal
        for (unsigned int i = 0; i < grid.size(); i++)
        {
            for (unsigned int j = 0; j < grid[i].size() - 3; j++)
            {
                product = grid[i][j] * grid[i][j + 1] * grid[i][j + 2] * grid[i][j + 3];
                if (product > largestProduct)
                {
                    largestProduct = product;
                }
            }
        }


        // vertical
        for (unsigned int i = 0; i < grid.size() - 3; i++)
        {
            for (unsigned int j = 0; j < grid[i].size(); j++)
            {
                product = grid[i][j] * grid[i + 1][j] * grid[i + 2][j] * grid[i + 3][j];
                if (product > largestProduct)
                {
                    largestProduct = product;
                }
            }
        }

        // forwards diagonal
        for (unsigned int i = 0; i < grid.size() - 3; i++)
        {
            for (unsigned int j = 0; j < grid[i].size() - 3; j++)
            {
                product = grid[i][j] * grid[i + 1][j + 1] * grid[i + 2][j + 2] * grid[i + 3][j + 3];
                if (product > largestProduct)
                {
                    largestProduct = product;
                }
            }
        }

        // back diagonal
        for (unsigned int i = 0; i < (grid.size() - 3); i++)
        {
            for (unsigned int j = 3; j < grid[i].size(); j++)
            {
                product = grid[i][j] * grid[i + 1][j - 1] * grid[i + 2][j - 2] * grid[i + 3][j - 3];
                if (product > largestProduct)
                {
                    largestProduct = product;
                }
            }
        }

        answer = largestProduct;

    ProblemEnd

    ProblemStart(12, "What is the first triangle number to have over five-hundred divisors?")

        int target = 500;

        __int64 triangle = 0;

        int i = 1;

        int numFactors = 0;
        map<__int64, int> primeFactors;
        map<__int64, int>::iterator mapItr;

        while (true)
        {
            triangle += i;

            primeFactors = PrimeFactorise(triangle, 100);

            numFactors = 1;
            mapItr = primeFactors.begin();
            // Calculate number of factors from prime factors
            while (mapItr != primeFactors.end())
            {
                if ((*mapItr).second > 0)
                    numFactors *= (*mapItr).second + 1;
                mapItr++;
            }

            if (numFactors > target)
                break;

            i++;
        }

        answer = i;
    
        ProblemEnd

    ProblemStart(13, "Find the first ten digits of the sum of one-hundred 50-digit numbers.")

        auto lines = GetLines("13.txt");

        string number;
        BigInteger result;
        for(auto line : lines)
        {
            BigInteger n(line);
            result.Add(n);
        }
        string sum = result.ToString().substr(0, 10);
        stringstream ss(sum);
        __int64 firstTen = 0;
        ss >> firstTen;
        answer = firstTen;

    ProblemEnd

    ProblemStart(14, "Find the longest sequence using a starting number under one million.")

        int max = 0;
        int count = 0;
        int num = 0;
        int i = 1;

        for (i = 1; i < 1000000; i++)
        {
            count = SequenceLength((__int64)i);
            if (count > max)
            {
                max = count;
                num = i;
            }
        }
        answer = num;

    ProblemEnd

    ProblemStart(15, "Starting in the top left corner in a 20 by 20 grid, how many routes are there to the bottom right corner?")

        // The route problem is a special case of Pascals triangle, where the top of the triangle
        // is the bottom right of the grid and contains the possible routes from there to the end
        // Therefore all we need to do for an n x n grid is calculate the number at position 2n, n
        // of Pascals triangle.
        //
        // P(r,c) = ((r + 1 - c) / c) * P(r, c - 1)
        answer = (__int64)PascalsValueAt(40, 20);

    ProblemEnd

    ProblemStart(16, "Calculate the sum of all the primes below one million.")

        __int64 sum = 0;

        for (int i = 0; i < 1000000; i++)
        {
            if (IsPrime(i))
            {
                sum += i;
            }
        }
        answer = sum;

    ProblemEnd

    ProblemStart(17, "How many letters would be needed to write all the numbers in words from 1 to 1000?")

        int sum = 0;
        string words;

        for (int i = 1; i <= 1000; i++)
        {
            words = NumToWords(i);
            sum += (int)words.size();
        }

        answer = sum;

    ProblemEnd

    ProblemStart(18, "Calculate the sum of all the primes below one million.")

        __int64 sum = 0;

        for (int i = 0; i < 1000000; i++)
        {
            if (IsPrime(i))
            {
                sum += i;
            }
        }
        answer = sum;

    ProblemEnd

    ProblemStart(19, "Calculate the sum of all the primes below one million.")

        __int64 sum = 0;

        for (int i = 0; i < 1000000; i++)
        {
            if (IsPrime(i))
            {
                sum += i;
            }
        }
        answer = sum;

    ProblemEnd

    ProblemStart(20, "Calculate the sum of all the primes below one million.")

        __int64 sum = 0;

        for (int i = 0; i < 1000000; i++)
        {
            if (IsPrime(i))
            {
                sum += i;
            }
        }
        answer = sum;

    ProblemEnd

    ProblemStart(21, "Evaluate the sum of all the amicable numbers under 10000.")

        vector<int> sumsByN;
        int sum = 0;
        // Generate sums of the factors of numbers from 0 to 10000
        for (int i = 0; i < 10000; i++)
        {
            // Passes out the sum of the factors
            auto factors = Factorise(i, sum);
            sumsByN.push_back(sum);
        }

        int sumOfAll = 0;

        for (int i = 0; i < (int)sumsByN.size(); i++)
        {
            int sum = sumsByN[i];
            if (sum >= (int)sumsByN.size()) continue; // can't check

            if (i == sumsByN[sum] && i != sum)
            {
                //cout << "Amicable! " << i << " " << sumsByN[i] << endl;
                sumOfAll += i + sumsByN[i];
            }
        }

        // Divide by 2 since we added (a + b) and (b + a) to the total as we went through 
        answer = sumOfAll / 2;

    ProblemEnd

    ProblemStart(22, "What is the total of all the name scores in the file?")

        // Note, names text file converted to one name per line
        auto lines = GetLines("22.txt");
        
        set<string> names;
        for(string name : lines)
        {
            names.insert(name);
        }
        vector<string> namesVector(names.begin(), names.end());

        int64_t score = 0;
        int64_t sum = 0;
        for (int i = 0; i < (int)namesVector.size(); i++)
        {
            score = (i + 1) * NameScore(namesVector[i]);
            if (namesVector[i] == "COLIN")
                cout << "COLIN " << (i + 1) << " " << score << endl;
            sum += score;
        }

        answer = sum;

    ProblemEnd

    ProblemStart(23, "Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.")

        // By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers
        vector<int> abundant;
        vector<bool> lookup(28123);
        set<int> allTo28123;
        set<int> abundantSums;
        int sum = 0;
        for (int i = 1; i < 28123; i++)
        {
            allTo28123.insert(i);
            if (Abundant(i))
            {
                //cout << "Found abundant " << i << endl;
                lookup[i] = true;
                abundant.push_back(i);
            }
            else
            {
                lookup[i] = false;
            }

            // is i the sum of two abundant numbers?

            for (int j = (int)abundant.size() - 1; j >= 0; j--)
            {
                if (lookup[i - abundant[j]])
                {
                    abundantSums.insert(i);
                    break;
                }
            }

        }

        vector<int> result;

        set_difference(allTo28123.begin(), allTo28123.end(), abundantSums.begin(), abundantSums.end(), std::back_inserter(result));

        for (auto i : result)
            sum += i;

        answer = sum;

    ProblemEnd

    ProblemStart(24, "What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?")
        
        vector<int> s = { 0,1,2,3,4,5,6,7,8,9 };
        int length = (int)s.size();
        int right = length - 1;
        int left = right - 1;
        int pivot = 0;
        int scan = 0;
        int temp = 0;

        for (int i = 1; i < 1000000; i++)
        {
            right = length - 1;
            left = right - 1;
            // find the longest non increasing suffix
            while (left != -1 && s[left] > s[right]) {
                left--;
                right--;
            }
            if (left == -1) {
                cout << "reached max number" << endl;
                break;
            }
            // left is now the pivot
            pivot = left;

            // find rightmost successor
            while (right != length && s[pivot] < s[right]) {
                left++;
                right++;
            }

            // swap
            temp = s[left];
            s[left] = s[pivot];
            s[pivot] = temp;

            // reverse suffix

            left = pivot + 1;
            right = length - 1;
            while (left < right)
            {
                temp = s[left];
                s[left] = s[right];
                s[right] = temp;
                left++;
                right--;
            }
        }

        int64_t num = 0;
        int m = 1;
        int size = static_cast<int>(s.size());
        for (int i = size - 1; i >= 0; i--)
        {
            num += m * s[i];
            m *= 10;
        }
        answer = num;

    ProblemEnd

    ProblemStart(25, "What is the index of the first term in the Fibonacci sequence to contain 1000 digits?")

        BigInteger fib("1");
        BigInteger prev("1");
        BigInteger newPrev("1");
        int index = 2;
        for (;;)
        {
            newPrev = fib;
            fib.Add(prev);
            prev = newPrev;
            index++;
            if (fib.NumDigits() >= 1000)
                break; 
        }
        answer = index;

    ProblemEndLast

};
}