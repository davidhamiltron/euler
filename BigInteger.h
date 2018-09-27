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

    void Multiply(BigInteger &n);
	void Multiply(int n);

    void Pow(int n);

    int NumDigits() { return static_cast<int>(m_number.size()); }

    bool operator <(BigInteger& d) {
        auto num = d.GetNumber();
        if (m_number.size() < num.size()) {
            return true;
        }
        if (m_number.size() > num.size()) {
            return false;
        }
        for (auto i = 0; i < m_number.size(); i++)
        {
            if (m_number[i] < num[i])
                return true;
        }
        return false;
    }

private:
    std::vector<int> m_number;

};

void BigIntegerTest();