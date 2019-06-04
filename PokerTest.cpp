
#define WILD_UNITTESTING_SHOW_FAILURE_DETAILS
#include "UnitTesting/UnitTesting.h"
#include "Poker.h"
#include "Tests.h"
#include <string>

using namespace Wild;
using namespace std;


void TestResult(const string &hand, Poker::Result result)
{
    Poker::Hand h(hand);
    Poker::Result handResult = h.IdentifyResult(); 
    AssertEquals(handResult, result);
}


void PokerTest()
{
    TestResult("2S 3S 4S 5S 6S", Poker::StraightFlush);
    TestResult("4S 3S 2S 6S 5S", Poker::StraightFlush);
    TestResult("TS JS AS QS KS", Poker::RoyalFlush);
    TestResult("2C 3S 4S 5S 6S", Poker::Straight);
    TestResult("6D 3S 4S 5S 2C", Poker::Straight);
    TestResult("2S AS 4S 5S 6S", Poker::Flush);
    TestResult("TS TC TD TH 6S", Poker::FourOfAKind);
    TestResult("TS TC TD 9H 6S", Poker::ThreeOfAKind);
    TestResult("TS TC TD AH AS", Poker::FullHouse);
    TestResult("TS TC TD AH QS", Poker::ThreeOfAKind);
    TestResult("TS TC AD AH QS", Poker::TwoPairs);
    TestResult("TS TC 2D AH QS", Poker::OnePair);
    TestResult("TS 6C 2D AH QS", Poker::HighCard);

    {
        string hands = "8C TS KC 9H 4S 7D 2S 5D 3S AC";
        Poker::Game g(hands);
        int result = g.Result();
        AssertEquals(result, 2);
    } {
        string hands = "5C AD 5D AC 9C 7C 5H 8D TD KS";
        Poker::Game g(hands);
        int result = g.Result();
        AssertEquals(result, 1);
    } {
        string hands = "3H 7H 6S KC JS QH TD JC 2D 8S";
        Poker::Game g(hands);
        int result = g.Result();
        AssertEquals(result, 1);
    } {
        string hands = "TH 8H 5C QS TC 9H 4D JC KS JS";
        Poker::Game g(hands);
        int result = g.Result();
        AssertEquals(result, 2);
    } {
        string hands = "7C 5H KC QH JD AS KH 4C AD 4S";
        Poker::Game g(hands);
        int result = g.Result();
        AssertEquals(result, 2);
    } {
        string hands = "5H KS 9C 7D 9H 8D 3S 5D 5C AH";
        Poker::Game g(hands);
        int result = g.Result();
        AssertEquals(result, 1);
    } {
        string hands = "6H 4H 5C 3H 2H 3S QH 5S 6S AS";
        Poker::Game g(hands);
        int result = g.Result();
        AssertEquals(result, 1);
    }
    {
        string hands = "TD 8C 4H 7C TC KC 4C 3H 7S KS";
        Poker::Game g(hands);
        int result = g.Result();
        AssertEquals(result, 2);
    }
    {
        string hands = "7C 9C 6D KD 3H 4C QS QC AC KH";
        Poker::Game g(hands);
        int result = g.Result();
        AssertEquals(result, 2);
    }
    {
        string hands = "5D 8C 9S JS AC 2C 5C 7D 8S QH";
        Poker::Game g(hands);
        int result = g.Result();
        AssertEquals(result, 1);
    }
    {
        string hands = "5H 5C 6S 7S KD 2C 3S 8S 8D TD";
        Poker::Game g(hands);
        int result = g.Result();
        AssertEquals(result, 2);
    }
    {
        string hands = "2D 9C AS AH AC 3D 6D 7D TD QD";
        Poker::Game g(hands);
        int result = g.Result();
        AssertEquals(result, 2);
    }
    {
        string hands = "4D 6S 9H QH QC 3D 6D 7H QD QS";
        Poker::Game g(hands);
        int result = g.Result();
        AssertEquals(result, 1);
    }
    {
        string hands = "2H 2D 4C 4D 4S 3C 3D 3S 9S 9D";
        Poker::Game g(hands);
        int result = g.Result();
        AssertEquals(result, 1);
    }

}