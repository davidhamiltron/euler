
#include <iostream>
#include <vector>
#include <math.h>
#include "Primes.h"



vector<int> GeneratePrimes(int max)
{
	vector<int> primes;
	vector<int> possibles;
	primes.push_back(2);

	for(int i = 3; i <= max; i += 2)
		possibles.push_back(1);

	int limit = (int)sqrt((double)max);
	int currentPrime = 3;
	int currentPrimeIndex = 0;

	int multiple = 0;
	int index = 0;

	while(currentPrime <= limit)
	{
		multiple = currentPrime * 2;
		// cross out multiples of current prime
		while(multiple <= max)
		{
			if(multiple%2 == 0)
			{
				multiple += currentPrime;	
				continue;	// we've already ignored even numbers
			}

			// Convert to array notation
			index = (multiple - 3)/2;
			possibles[index] = 0;
			multiple += currentPrime;
		}

		// move currentPrime to next highest uncrossed out number
		
		currentPrimeIndex++;
		while(currentPrime <= limit)
		{
			if(possibles[currentPrimeIndex])
				break;
			currentPrimeIndex++;
		}
		
		currentPrime = (currentPrimeIndex * 2) + 3;

	}

	for(size_t i = 0; i < possibles.size(); i++)
		if(possibles[i])
			primes.push_back(i*2 + 3);

	return primes;

}


void GeneratePrimesTest()
{


	vector<int> primes = GeneratePrimes(20000000);

	cout << primes.size() << endl;

	vector<int> expected;
	expected.push_back(2);
	expected.push_back(3);
	expected.push_back(5);
	expected.push_back(7);

	//cout << (primes == expected) << endl;

	for(int i = 0; i < (int)primes.size(); i++);
		//cout << primes[i] << endl;





}



static vector<int> s_primes;

map<int, int> PrimeFactorise(__int64 n, int usePrimesUnder)
{

	if(s_primes.size() == 0)
		s_primes = GeneratePrimes(usePrimesUnder);

	//cout << "Finding factors:" << endl;
	map<int, int> primeFactors;
	__int64 prime = 0;
	__int64 primeFactor = 0;
	__int64 power = 1;

	__int64 limit = n/2;

	for(int i = 0; i < (int)s_primes.size(); i++)
	{
		prime = s_primes[i];
		if(prime > limit) break;
		primeFactor = prime;
		primeFactors[prime] = 0;

		while(n%primeFactor == 0)
		{
			primeFactors[prime]++;
			primeFactor *= prime;
		}

	}

	return primeFactors;
}



bool IsPrime(int a)
{

    if (a == 1)
    {
        return false;
    }
    if (a == 2)
    {
        return true;
    }

    // test for evenness
    if (a % 2 == 0) return false;

    double dSquareRoot = sqrt((double)a);

    for (int i = 3; i <= (int)dSquareRoot; i += 2)
    {
        if (a%i == 0)
        {
            return false;
        }
    }

    return true;
}


/*
vector<__int64> PrimeFactorise(__int64 a, __int64& iLargestFactor)
{

cout << "Finding factors:" << endl;
vector<__int64> vFactors;
__int64 iLargest = (__int64)sqrt((float)(a));
for(int i = 1; i < iLargest; i++)
{
if(a%i == 0)
{
if(IsPrime(i))
{
cout << i << endl;
vFactors.push_back(i);
iLargestFactor = i;
}
}
}

return vFactors;
}
*/