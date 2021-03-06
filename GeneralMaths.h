#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include "BigInteger.h"

static int Fibonacci(int a, int b)
{
    return a + b;
}

static int64_t Fibonacci(int n)
{
    int64_t fib = 1;
    int64_t prev = 1;
    int64_t newPrev = 1;
    for (int i = 2; i < n; i++)
    {
        newPrev = fib;
        fib = fib + prev;
        prev = newPrev;
    }
    return fib;
}

static BigInteger BigFibonacci(int n)
{
    BigInteger fib("1");
    BigInteger prev("1");
    BigInteger newPrev("1");
    for (int i = 2; i < n; i++)
    {
        newPrev = fib;
        fib.Add(prev);
        prev = newPrev;
    }
    return fib;
}


static std::vector<int> ToDigits(int a)
{
    std::vector<int> digits;
    int temp = a;
    int rem = 0;
    while (temp > 0)
    {
        rem = temp % 10;
        digits.push_back(rem);
        //iTemp -= iRem;
        temp /= 10;
    }

    return digits;

}

static std::vector<int> ToDigitsBinary(int n)
{
    std::vector<int> digits;
    if (n == 0)
    {
        digits.push_back(0);
        return digits;
    }
    int test = n;
    int count = 0;
    while (test > 0)
    {
        digits.push_back(test & 0b1);
        test >>= 1;
    }
    return digits;
}

static int NumDigits(int n)
{
    return 
        (n < 10 ? 1 :
        (n < 100 ? 2 :
        (n < 1000 ? 3 :
        (n < 10000 ? 4 :
        (n < 100000 ? 5 :
        (n < 1000000 ? 6 :
        (n < 10000000 ? 7 :
        (n < 100000000 ? 8 :
        (n < 1000000000 ? 9 :
        10)))))))));
}

static int NumDigitsBinary(int n)
{
    if (n == 0) return 1;
    int test = n;
    int count = 0;
    while (test > 0)
    {
        test >>= 1;
        count++;
    }
    return count;
}

static int Rotate(int n, int numDigits)
{
    int lastDigit = n % 10;
    int newN = n / 10;
    newN += lastDigit * (int)pow(10, numDigits-1);
    return newN;
}


static char oneToTwenty[20][256] = {
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "fifteen",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen",
};

static char tens[10][256] = {
    "",
    "ten",
    "twenty",
    "thirty",
    "forty",
    "fifty",
    "sixty",
    "seventy",
    "eighty",
    "ninety"
};


static std::string NumLessThan100ToWords(int a, bool partOfLarger)
{

    std::string words;

    if (partOfLarger)
    {
        words += "and";
    }

    if (a == 0)
    {
        return "";
    }
    else if (a < 20) // less than 20 case
    {
        words += std::string(oneToTwenty[a]);
    }
    else
    {
        std::vector<int> digits = ToDigits(a);
        words += std::string(tens[digits[1]]);
        if (digits[0] != 0)
        {
            words += std::string(oneToTwenty[digits[0]]);
        }
    }

    return words;

}

static std::string NumToWords(int a)
{

    if (a == 1000)
    {
        return "onethousand";
    }

    int partLessThan100 = a % 100;
    a /= 100;

    bool partOfLarger = true;
    if (a == 0)
    {
        partOfLarger = false;
    }

    std::string words;
    words += NumLessThan100ToWords(partLessThan100, partOfLarger);

    std::vector<int> digits = ToDigits(a);
    int numDigits = (int)digits.size();

    for (int i = numDigits - 1; i >= 0; i--)
    {
        words = std::string(oneToTwenty[digits[i]]) + "hundred" + words;
    }
    return words;

}

static bool IsPalindromeVector(std::vector<int> & digits)
{
    int size = (int)digits.size();

    for (int i = 0; i < (size / 2); i++)
    {
        if (digits[i] != digits[(size - 1) - i])
            return false;
    }

    return true;
}

static bool IsPalindrome(int a)
{
    return IsPalindromeVector(ToDigits(a));
}





static bool IsPandigital(int n, int numDigits)
{
    std::vector<int> digits = ToDigits(n);
    if (digits.size() != numDigits) return false;
    std::map<int, int> seen;
    for (int i : digits)
    {
        if (i == 0) return false;
        seen[i]++;
        if (seen[i] >= 2) return false;
    }

    return true;
}

static std::vector<int> Factorise(int n, int &sum)
{
    std::vector<int> factors;
    int largest = (int)sqrt((float)(n));
    sum = 1;
    factors.push_back(1);
    int alternate = 0;
    for (int i = 2; i <= largest; i++)
    {
        if (n%i == 0)
        {
            factors.push_back(i);
            alternate = n / i;
            if (alternate != i)
            {
                factors.push_back(alternate);
                sum += i + alternate;
            }
            else
            {
                sum += i;
            }
        }
    }

    return factors;
}

static bool Abundant(int n)
{
    int sum = 0;
    Factorise(n, sum);
    return sum > n;
}

static int NameScore(const std::string &name)
{
    int sum = 0;
    for (char c : name)
    {
        sum += (c - 64);
    }

    return sum;
}

static int SequenceLength(__int64 n)
{
    int count = 1;
    while (n != 1)
    {
        if (n & 1)		n = 3 * n + 1;
        else		n /= 2;
        count++;
    }

    return count;
}


double PascalsValueAt(double row, double column);

static std::vector<int> NumbersByRemovingDigitsFromLeft(int n)
{
    std::vector<int> numbers;
    auto digits = ToDigits(n);
    int numDigits = (int)digits.size();
    int currentNumDigits = numDigits - 1;

    for(int i = numDigits - 1; i >= 0; i--)
    {
        n -= (digits[i] * (int)pow(10, currentNumDigits));
        if (n == 0) break;
        numbers.push_back(n);
        currentNumDigits--;
    }

    return numbers;
}

static std::vector<int> NumbersByRemovingDigitsFromRight(int n)
{
    std::vector<int> numbers;

    while (n > 0)
    {
        n /= 10;
        if (n == 0) break;
        numbers.push_back(n);
    }

    return numbers;
}