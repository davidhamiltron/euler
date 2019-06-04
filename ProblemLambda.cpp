
#include "ProblemLambda.h"
#include "Stopwatch.h"
#include <iostream>
//#include "String.h"
//#include "math.h"
//#include "BigInteger.h"
//#include "Primes.h"
//#include "Stopwatch.h"
//
////#include <iostream>
////#include <fstream>
////#include <map>
////#include <set>
////#include <algorithm>
////#include <iterator>
//
//#include "Problems1-25.h"
//#include "Problems51-75.h"

using namespace std;

//vector<int> ToDigits(int a);


ProblemLambda::ProblemLambda(int number, const char* description, std::function<std::string(void)> solver) :
    number(number), description(description), solver(solver)
{

}

void ProblemLambda::Solve()
{
    Stopwatch s;
    s.Start();
    answer = solver();
    s.Stop();
    durationMs = s.ElapsedMilliseconds();
    Report();
}

void ProblemLambda::Report()
{
    cout << "Problem " << number << ": " << description << endl;
    cout << "Answer: " << answer << " in " << durationMs << "ms" << endl;
    cout << endl;
}

/*


// Problem 8

Problem8::Problem8()
{
	m_szDescription = "Find the greatest product of five consecutive digits in the 1000-digit number.";
}


bool Problem8::Solve()
{

	ifstream inFile;
	inFile.open("input\\8.txt");

	char szNum[1001];

	inFile >> szNum;
	int iLargestProduct = 0;
	int iProduct = 0;

	for(int i = 0; i < (1000 - 4); i++)
	{
		iProduct = 
			(int)(szNum[i] - 48) *
			(int)(szNum[i+1] - 48) * 
			(int)(szNum[i+2] - 48) * 
			(int)(szNum[i+3] - 48) * 
			(int)(szNum[i+4] - 48);

		if(iProduct > iLargestProduct)
			iLargestProduct = iProduct;
	}

	m_szAnswer = ToString(iLargestProduct);
	return true;
}

// Problem 9

Problem9::Problem9()
{
	m_szDescription = "Find the only Pythagorean triplet, {a, b, c}, for which a + b + c = 1000.";
}


bool Problem9::Solve()
{
	int iProduct = 0;
	float c = 0;
	int a = 1;
	int b = 1;
	bool bFound = false;

	for(a = 1; a < 500; a++)
	{
		for(b = 1; b < 500; b++)
		{
			c = sqrt((float)((a*a) + (b*b)));
			if(a + b + c == 1000)
			{
				bFound = true;
				break;
			}
		}

		if(bFound) break;
	}

	//cout << a << " " << b << " " << c << endl;

	iProduct = a * b * (int)c;

	m_szAnswer = ToString(iProduct);
	return true;
}


// Problem 10

Problem10::Problem10()
{
	m_szDescription = "Calculate the sum of all the primes below one million.";
}


bool Problem10::Solve()
{
	__int64 iSum = 0;

	for(int i = 0; i < 1000000; i++)
	{
		if(IsPrime(i))
		{
			iSum += i;
		}
	}	
	m_szAnswer = ToString(iSum);
	return true;
}




// Problem 11

Problem11::Problem11()
{
	m_szDescription = "What is the greatest product of four numbers on the same straight line in the 20 by 20 grid?";
}

vector<vector<int>> LoadGrid()
{

	ifstream inFile;
	inFile.open("input\\11.txt");

	vector<vector<int>> vGrid;
	vector<int> vRow;
	int iCount = 0;
	while(true)
	{
		int iNum = 0;
		inFile >> iNum;
		vRow.push_back(iNum);

		if(inFile.eof()) break;
		iCount++;

		if(iCount == 20)
		{
			iCount = 0;
			vGrid.push_back(vRow);
			vRow.clear();
		}
	}

	return vGrid;
}

bool Problem11::Solve()
{
	
	int iLargestProduct = 0;
	vector<vector<int>> vGrid = LoadGrid();


	int iProduct;

	// horizontal
	for(unsigned int i = 0; i < vGrid.size(); i++)
	{
		for(unsigned int j = 0; j < vGrid[i].size() - 3; j++)
		{
			iProduct = vGrid[i][j] * vGrid[i][j+1] * vGrid[i][j+2] * vGrid[i][j+3];
			if(iProduct > iLargestProduct)
			{
				iLargestProduct = iProduct;
			}
		}
	}

	//cout << "Done horizontal" << endl;

	// vertical
	for(unsigned int i = 0; i < vGrid.size() - 3; i++)
	{
		for(unsigned int j = 0; j < vGrid[i].size(); j++)
		{
			iProduct = vGrid[i][j] * vGrid[i+1][j] * vGrid[i+2][j] * vGrid[i+3][j];
			if(iProduct > iLargestProduct)
			{
				iLargestProduct = iProduct;
			}
		}
	}

	//cout << "Done vertical" << endl;

	// forwards diagonal
	for(unsigned int i = 0; i < vGrid.size() - 3; i++)
	{
		for(unsigned int j = 0; j < vGrid[i].size()-3; j++)
		{
			iProduct = vGrid[i][j] * vGrid[i+1][j+1] * vGrid[i+2][j+2] * vGrid[i+3][j+3];
			if(iProduct > iLargestProduct)
			{
				iLargestProduct = iProduct;
			}
		}
	}

	//cout << "Done forwards diagonal" << endl;

	// back diagonal
	for(unsigned int i = 0; i < (vGrid.size()-3); i++)
	{
		for(unsigned int j = 3; j < vGrid[i].size(); j++)
		{
			iProduct = vGrid[i][j] * vGrid[i+1][j-1] * vGrid[i+2][j-2] * vGrid[i+3][j-3];
			if(iProduct > iLargestProduct)
			{
				iLargestProduct = iProduct;
			}
		}
	}

	//cout << "Done back diagonal" << endl;

	m_szAnswer = ToString(iLargestProduct);
	return true;
}

// Problem 12

Problem12::Problem12()
{
	m_szDescription = "What is the first triangle number to have over five-hundred divisors?";
}




bool Problem12::Solve()
{
	
	//map<int, int> primeFactors = PrimeFactorise(6, 100);

	//map<int, int>::iterator mapItr = primeFactors.begin();


	//while(mapItr != primeFactors.end())
	//{
	//	cout << (*mapItr).first << "^" << (*mapItr).second << " * ";
	//	mapItr++;
	//}

	//cout << endl;
	
	int iTarget = 500;

	__int64 iTriangle = 0;

	int i = 1;

	int numFactors = 0;
	map<int, int> primeFactors;
	map<int, int>::iterator mapItr;

	while(true)
	{
		iTriangle += i;

		primeFactors = PrimeFactorise(iTriangle, 100);

		numFactors = 1;
		mapItr = primeFactors.begin();
		// Calculate number of factors from prime factors
		while(mapItr != primeFactors.end())
		{
			if((*mapItr).second > 0)
				numFactors *= (*mapItr).second + 1;
			mapItr++;
		}

		//vFactors = Factorise(iTriangle);
		if(numFactors > iTarget)
			break;
	
		i++;					 
	}

	cout << "The first triangle number to have over " << iTarget << " divisors is " << iTriangle << ", the " << i << "th." << endl;
	m_szAnswer = ToString(i);
	return true;
}


// Problem 13

Problem13::Problem13()
{
	m_szDescription = "Find the first ten digits of the sum of one-hundred 50-digit numbers.";
}



bool Problem13::Solve()
{

	ifstream inFile;
	inFile.open("../13.txt");

	string number;
	BigInteger result;
	while(!inFile.eof())
	{
		inFile >> number;
		BigInteger n(number);
		result.Add(n);
	}

	inFile.close();

	m_szAnswer = result.ToString().substr(0,10);
	return true;
}




// Problem 14

Problem14::Problem14()
{
	m_szDescription = "Find the longest sequence using a starting number under one million.";
}

int SequenceLength(__int64 n)
{
	int count = 1;
	while(n != 1)
	{
		if(n&1)		n = 3*n + 1;
		else		n /= 2;
		count++;
	}

	return count;
}

bool Problem14::Solve()
{

	//cout << SequenceLength(13) << endl;
	int max = 0;
	int count = 0;
	int num = 0; 
	int i = 1;

	for(i = 1; i < 1000000; i++)
	{
		count = SequenceLength((__int64)i);
		if(count > max)
		{
			max = count;
			num = i;
		}
	}
	m_szAnswer = ToString(num);
	return true;
}


// Problem 15

Problem15::Problem15()
{
	m_szDescription = "Starting in the top left corner in a 20 by 20 grid, how many routes are there to the bottom right corner?";
}

// The route problem is a special case of Pascals triangle, where the top of the triangle
// is the bottom right of the grid and contains the possible routes from there to the end
// Therefore all we need to do for an n x n grid is calculate the number at position 2n, n
// of Pascals triangle.
//
// P(r,c) = ((r + 1 - c) / c) * P(r, c - 1)

double PascalsValueAt(double row, double column)
{
	if(column == 0) return 1;

	return ((row + 1 - column) / column) * PascalsValueAt(row, column - 1);
}

void Test()
{
	cout << (PascalsValueAt(0,0) == 1);
	cout << (PascalsValueAt(1,0) == 1);
	cout << (PascalsValueAt(1,1) == 1);
	cout << (PascalsValueAt(2,1) == 2);
	cout << (PascalsValueAt(5,3) == 10);
	cout << (PascalsValueAt(10,3) == 120);
	cout << endl;
	cout << (PascalsValueAt(10,3)) << endl;
}


bool Problem15::Solve()
{
	m_szAnswer = ToString((__int64)PascalsValueAt(40, 20));
	return true;
}



// Problem 16

Problem16::Problem16()
{
	m_szDescription = "What is the sum of the digits of the number 2^1000?";
}


bool Problem16::Solve()
{
	BigInteger n("2");
	for(int i = 1; i < 1000; i++)
	{
		n.Add(n);
	}

	vector<int> v = n.GetNumber();
	int sum = 0;
	for(size_t i = 0; i < v.size(); i++)
		sum += v[i];
	m_szAnswer = ToString(sum);
	return true;
}


// Problem 17

Problem17::Problem17()
{
	m_szDescription = "How many letters would be needed to write all the numbers in words from 1 to 1000?";
}



bool Problem17::Solve()
{
	
	int iSum = 0;
	string szWords;
	for(int i = 1; i <= 1000; i++)
	{
		szWords = NumToWords(i);
		//cout << szWords << " " << (int) szWords.size() << endl;
		iSum += (int) szWords.size();
	}

	

	m_szAnswer = ToString(iSum);
	return true;
}




int BruteForceRoute(vector<vector<int>> triangle, int x, int y, int sum)
{
	if(y == triangle.size())	// reached past the bottom
		return sum;

	if(x == triangle.size() || x == -1)	// reached past the side
		return sum;

	sum += triangle[y][x];

	// start more routes

	int sumLeft = BruteForceRoute(triangle, x, y+1, sum);
	int sumRight = BruteForceRoute(triangle, x+1, y+1, sum);

	if(sumLeft > sumRight)
		return sumLeft;
	return sumRight;

}

int Route(vector<vector<int>> triangle)
{
	int a, b, testA, testB, test;
	for(size_t y = triangle.size() - 1; y >= 1; y--)
	{
		for(size_t x = 0; x < triangle[y].size() - 1; x++)
		{
			a = triangle[y][x];
			b = triangle[y][x+1];
			test = triangle[y-1][x];
			testA = test + a;
			testB = test + b;
			if(testA > testB)
				triangle[y-1][x] = testA;
			else
				triangle[y-1][x] = testB;
		}
	}

	return triangle[0][0];
}

// Problem 18

Problem18::Problem18()
{
	m_szDescription = "Find the maximum sum travelling from the top of the triangle to the base.";
}


bool Problem18::Solve()
{

	ifstream inFile;
	inFile.open("input\\18.txt");
	if(!inFile) return false;

	string number;
	int iNumber = 0;

	vector<vector<int>> numberTriangle;

	int lineSize = 1;
	while(!inFile.eof())
	{
		vector<int> line;
		for(int i = 0; i < lineSize; i++)
		{
			inFile >> number;
			line.push_back(ToInt(number));
		}
		numberTriangle.push_back(line);
		lineSize++;
	}

	inFile.close();

	m_szAnswer = ToString(Route(numberTriangle));
	return true;
}



// Problem 19

Problem19::Problem19()
{
    m_szDescription = "How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?";
}

struct Date
{
    int dayOfWeek;
    int dayOfMonth;
};

bool Problem19::Solve()
{
    int currentMonth = 0;
    int currentDayOfWeek = 0;
    int currentDayOfMonth = 0;
    vector<int> months = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int currentYear = 1900;
    bool leapYear = false;
    vector<Date> dates;
    int sundaysOnFirstOfMonth = 0;

    while (currentYear <= 2000)
    {
        leapYear = ((currentYear / 4 == 0) && (currentYear / 400 == 0));
        if (leapYear)
            months[1] = 29;
        else
            months[1] = 28;

        for (currentMonth = 0; currentMonth < 12; currentMonth++)
        {
            for (currentDayOfMonth = 0; currentDayOfMonth < months[currentMonth]; currentDayOfMonth++)
            {
                Date date;
                date.dayOfWeek = currentDayOfWeek;
                date.dayOfMonth = currentDayOfMonth;
                dates.push_back(date);
                if (currentYear != 1900)
                {
                    if (currentDayOfWeek == 6 && currentDayOfMonth == 0)
                        sundaysOnFirstOfMonth++;
                }

                currentDayOfWeek++;
                if (currentDayOfWeek > 6)
                    currentDayOfWeek = 0;
            }
        }

        currentYear++;
    }

    m_szAnswer = ToString(sundaysOnFirstOfMonth);
    return true;
}



// Problem 20

Problem20::Problem20()
{
	m_szDescription = "Find the sum of digits in 100!";
}

bool Problem20::Solve()
{
	
	int iSum = 0;
	string szWords;
	BigInteger n("1");
	for(int i = 2; i <= 100; i++)
	{
		n.Multiply(i);
	}
	
	//cout << n.ToString() << endl;
	string s = n.ToString();
	int sum = 0;
	for(size_t i = 0; i < s.size(); i++)
		sum += (int)s[i] - 48;
	m_szAnswer = ToString(sum);
	return true;
}


// Problem 21

Problem21::Problem21()
{
    m_szDescription = "Evaluate the sum of all the amicable numbers under 10000.";
}



bool Problem21::Solve()
{
    // relates the sum of the proper divisors to a list of numbers with those proper divisors
    map<int, vector<int>> sums;
    vector<int> sumsByN;
    int sum = 0;
    for (int i = 0; i < 10000; i++)
    {
        auto factors = Factorise(i, sum);
        sumsByN.push_back(sum);
    }

    int sumOfAll = 0;

    for (int i = 0; i < (int)sumsByN.size(); i++)
    {
        int sum = sumsByN[i];
        //cout << i << ": " << sum << endl;
        if (sum >= (int)sumsByN.size()) continue; // can't check
        if (i == sumsByN[sum] && i != sum)
        {
            cout << "Amicable! " << i << " " << sumsByN[i] << endl;
            sumOfAll += i + sumsByN[i];
        }
    }

    m_szAnswer = ToString(sumOfAll/2);
    return true;
   
}


Problem22::Problem22()
{
    m_szDescription = "What is the total of all the name scores in the file?";
}

int NameScore(const string &name)
{
    int sum = 0;
    for (char c : name)
    {
        sum += (c - 64);
    }

    return sum;
}

bool Problem22::Solve()
{
    ifstream inFile;
    inFile.open("input/p022_names.txt");
    if (!inFile) return false;
    set<string> names;

    string name;
    while (!inFile.eof())
    {
        inFile >> name;
        //cout << "read " << name << endl;
        names.insert(name);
    }
    vector<string> namesVector(names.begin(), names.end());

    int64_t score = 0;
    int64_t sum = 0;
    for (int i = 0; i < (int)namesVector.size(); i++)
    {
        score = (i+1) * NameScore(namesVector[i]);
        if (namesVector[i] == "COLIN")
            cout << "COLIN " << (i+1) << " " << score << endl;
        sum += score;
    }

    m_szAnswer = ToString(sum);
    return true;
}

Problem23::Problem23()
{
    m_szDescription = "Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.";
}



bool Problem23::Solve()
{
    
    return true;
}

// Problem 67

Problem67::Problem67()
{
	m_szDescription = "Using an efficient algorithm find the maximal sum in the triangle.";
}


bool Problem67::Solve()
{

	ifstream inFile;
	inFile.open("input\\67.txt");
	if(!inFile) return false;

	string number;
	int iNumber = 0;

	vector<vector<int>> numberTriangle;

	int lineSize = 1;
	while(!inFile.eof())
	{
		vector<int> line;
		for(int i = 0; i < lineSize; i++)
		{
			inFile >> number;
			line.push_back(ToInt(number));
		}
		numberTriangle.push_back(line);
		lineSize++;
	}

	inFile.close();

	m_szAnswer = ToString(Route(numberTriangle));
	return true;
}
*/