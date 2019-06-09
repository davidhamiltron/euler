
#define WILD_UNITTESTING_SHOW_FAILURE_DETAILS
#include "UnitTesting/UnitTesting.h"
#include "GeneralMaths.h"
#include "Tests.h"

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
}