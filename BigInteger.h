#pragma once

#include <vector>
#include <string>

class BigInteger
{
public:

	BigInteger();

	BigInteger(const std::string &number);

    std::string ToString();

	int Digit(int index);

	std::vector<int> GetNumber();

	void Add(BigInteger &n);

	void Multiply(int n);

    int Size() { return m_number.size(); }

private:
    std::vector<int> m_number;

};

void BigIntegerTest();