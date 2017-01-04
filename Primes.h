
#pragma once
#include <vector>
#include <map>
using namespace std;

map<int, int> PrimeFactorise(__int64 n, int usePrimesUnder);
vector<int> GeneratePrimes(int max);
void GeneratePrimesTest();
bool IsPrime(int a);