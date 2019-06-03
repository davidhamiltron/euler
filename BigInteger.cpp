
#include "BigInteger.h"

#include <iostream>

using namespace std;

static void Add(int n, int m, int &carry, int &result);
static vector<int> Add(const vector<int> &vn, const vector<int> &vm);


BigInteger::BigInteger()
{
}

BigInteger::BigInteger(const string &number)
{
	// Convert digits to integers and enter them into the vector
	int size = (int) number.size();
	for(int i = size - 1; i >= 0 ; i--)
		m_number.push_back((int)number[i] - 48);
}

string BigInteger::ToString() const
{
	vector<int>::const_reverse_iterator i = m_number.rbegin();
	string number = "";
	while(i != m_number.rend())
	{
		number += (char)(*i + 48);
		i++;
	}
	return number;
}

int BigInteger::Digit(int index)
{
	return m_number[index];
}

vector<int> BigInteger::GetNumber()
{
	return m_number;
}

void BigInteger::Add(BigInteger &n)
{
	vector<int> add = n.GetNumber();
	m_number = ::Add(m_number, add);
}



void BigInteger::Multiply(BigInteger &n)
{
	BigInteger current = *this;
    BigInteger i("1");
    BigInteger one("1");
    while (i < n)
    {
        this->Add(current);
        i.Add(one);
    }
}

void BigInteger::Multiply(int n)
{
    BigInteger current = *this;
    for (int i = 1; i < n; i++)
        this->Add(current);
}

void BigInteger::Pow(int n)
{
    BigInteger current = *this;
    for (int i = 1; i < n; i++)
        this->Multiply(current);
}



static void Add(int n, int m, int &carry, int &result)
{
	result = n + m + carry;
	carry = result / 10;
	if(carry)
		result %= 10;
}

static vector<int> Add(const vector<int> &vn, const vector<int> &vm)
{
	vector<int> r;
	int n, m;
	int column = 0;
	int result = 0;
	int carry = 0;
	int vnSize = (int) vn.size();
	int vmSize = (int) vm.size();
	while (true)
	{
		n = column < vnSize ? (int) vn[column] : 0;
		m = column < vmSize ? (int) vm[column] : 0;

		if(n == 0 && m == 0 && carry == 0 && column >= vnSize && column >= vmSize) break;

		Add(n, m, carry, result);

		r.push_back(result);
		
		column++;

	}
	
	return r;
}

bool operator <(const BigInteger &a, const BigInteger &b) {

    if (a.m_number.size() < b.m_number.size()) {
        return true;
    }
    if (a.m_number.size() > b.m_number.size()) {
        return false;
    }
    for (int i = ((int)(a.m_number.size())) - 1; i >= 0; i--)
    {
        if (a.m_number[i] == b.m_number[i]) continue;
        if (a.m_number[i] < b.m_number[i])
            return true;
        else
            return false;
    }
    return false;
}

std::ostream& operator<< (std::ostream& os, const BigInteger& i)
{
    os << i.ToString();
    return os;
}


void BigIntegerTest()
{
	cout << "Testing BigInteger class" << endl;
	int n = 1, m = 2, carry = 0, result = 0;
	Add(n, m, carry, result);
	cout << (result == 3);
	cout << (carry == 0);

	n = 5, m = 5, carry = 0, result = 0;
	Add(n, m, carry, result);
	cout << (result == 0);
	cout << (carry == 1);

	n = 9, m = 9, carry = 0, result = 0;
	Add(n, m, carry, result);
	cout << (result == 8);
	cout << (carry == 1);

	BigInteger a("123456789123456789123456789");
	cout << (a.ToString() == "123456789123456789123456789");
	BigInteger b("15");
	BigInteger c("14");
	b.Add(c);
	cout << (b.ToString() == "29");

	BigInteger d("55");
	BigInteger e("45");
	d.Add(e);
	cout << (d.ToString() == "100");

	a.Add(a);
	cout << (a.ToString() == "246913578246913578246913578");

	cout << endl;

}