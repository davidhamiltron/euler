#pragma once

#include <vector>
#include <string>

class BigInteger
{
public:

	BigInteger();

	BigInteger(const std::string &number);

    std::string ToString() const;

	int Digit(int index);

	std::vector<int> GetNumber();

	void Add(BigInteger &n);

    void Multiply(BigInteger &n);
	void Multiply(int n);

    void Pow(int n);

    int NumDigits() { return static_cast<int>(m_number.size()); }

    friend bool operator <(const BigInteger &a, const BigInteger &b);

private:
    std::vector<int> m_number;

};

std::ostream& operator<< (std::ostream& os, const BigInteger& i);

void BigIntegerTest();