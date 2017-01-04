#pragma once

#include <vector>
#include <string>
#include "BigInteger.h"

static int Fibonacci(int a, int b)
{
    return a + b;
}

static int Fibonacci(int n)
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
        vector<int> digits = ToDigits(a);
        words += string(tens[digits[1]]);
        if (digits[0] != 0)
        {
            words += string(oneToTwenty[digits[0]]);
        }
    }

    return words;

}

static string NumToWords(int a)
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

    string words;
    words += NumLessThan100ToWords(partLessThan100, partOfLarger);

    vector<int> digits = ToDigits(a);
    int numDigits = (int)digits.size();

    for (int i = numDigits - 1; i >= 0; i--)
    {
        words = string(oneToTwenty[digits[i]]) + "hundred" + words;
    }
    return words;

}


static bool IsPalindrome(int a)
{
    std::vector<int> digits = ToDigits(a);

    int size = (int)digits.size();

    for (int i = 0; i < (size / 2); i++)
    {
        if (digits[i] != digits[(size - 1) - i])
            return false;
    }

    return true;
}

static vector<int> Factorise(int n, int &sum)
{
    vector<int> factors;
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