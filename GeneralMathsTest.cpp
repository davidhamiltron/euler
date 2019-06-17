
#define WILD_UNITTESTING_SHOW_FAILURE_DETAILS
#include "UnitTesting/UnitTesting.h"
#include "GeneralMaths.h"
#include "Tests.h"
#include "String.h"

using namespace Wild;
using namespace std;

void GeneralMathsTest()
{
    AssertFalse(IsPandigital(0, 3));
    AssertFalse(IsPandigital(11, 2));
    AssertFalse(IsPandigital(123456788, 9));
    AssertFalse(IsPandigital(201395786, 9));

    AssertTrue(IsPandigital(1, 1));
    AssertTrue(IsPandigital(12, 2));
    AssertTrue(IsPandigital(321, 3));
    AssertTrue(IsPandigital(4123, 4));
    AssertTrue(IsPandigital(123456789, 9));
    AssertTrue(IsPandigital(123789456, 9));

    // Num digits
    AssertEquals(NumDigits(1), 1);
    AssertEquals(NumDigits(0), 1);
    AssertEquals(NumDigits(11), 2);
    AssertEquals(NumDigits(112), 3);

    // Num digits binary
    AssertEquals(NumDigitsBinary(0b1), 1);
    AssertEquals(NumDigitsBinary(0b0), 1);
    AssertEquals(NumDigitsBinary(0b11), 2);
    AssertEquals(NumDigitsBinary(0b101), 3);

    // To digits binary
    auto v = ToDigitsBinary(0b11010101);
    vector<int> vExpected = { 1,0,1,0,1,0,1,1 };
    AssertEquals(v, vExpected);

    // Rotate
    AssertEquals(Rotate(1, 1), 1);
    AssertEquals(Rotate(22, 2), 22);
    AssertEquals(Rotate(12, 2), 21);
    AssertEquals(Rotate(123456, 6), 612345);


    // PascalsValueAt
    /*
    AssertEquals(PascalsValueAt(0, 0), 1);
    AssertEquals(PascalsValueAt(1, 0), 1);
    AssertEquals(PascalsValueAt(1, 1), 1);
    AssertEquals(PascalsValueAt(2, 1), 2);
    AssertEquals(PascalsValueAt(5, 3), 10);
    AssertEquals(PascalsValueAt(10, 3), 120);
    */

    // NumbersByRemovingDigits
    int n = 3797;
    vector<int> expected = { 797,97,7 };
    AssertEquals(NumbersByRemovingDigitsFromLeft(n), expected);
    expected = { 379,37,3 };
    AssertEquals(NumbersByRemovingDigitsFromRight(n), expected);

}