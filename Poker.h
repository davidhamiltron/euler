#pragma once

#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include "String.h"

namespace Poker
{
    enum Suit
    {
        None,
        Spades,
        Clubs,
        Diamonds,
        Hearts
    };

    enum Result
    {
        HighCard,
        OnePair,
        TwoPairs,
        ThreeOfAKind,
        Straight,
        Flush,
        FullHouse,
        FourOfAKind,
        StraightFlush,
        RoyalFlush
    };


    class Card
    {
    public:

        Card(const std::string &card)
        {
            char v = card[0];
            switch (v)
            {
            case 'A': value = 14; break;
            case 'K': value = 13; break;
            case 'Q': value = 12; break;
            case 'J': value = 11; break;
            case 'T': value = 10; break;
            default:
                value = v - 48;
            }

            char s = card[1];

            switch (s)
            {
            case 'S': suit = Spades; break;
            case 'C': suit = Clubs; break;
            case 'D': suit = Diamonds; break;
            case 'H': suit = Hearts; break;
            }
        }
        int value;
        Suit suit;
    };

    static bool cardSort(const Card &a, const Card &b) { return (a.value < b.value); }

    class Hand
    {
    public:
        std::vector<Card> cards;
        std::map<int, int> cardCountsMapByValue;
        std::map<int, int> cardCountsMapByCount;
        std::vector<int> cardCounts;
        std::vector<int> cardValues;
        Result result;

        Hand(const std::string &hand)
        {
            std::vector<std::string> h;
            Split(h, hand, " ");
            for (auto i : h)
            {
                cards.push_back(Card(i));
            }
        }

        bool IsStraight()
        {
            return  cards[1].value == (cards[0].value + 1) && 
                    cards[2].value == (cards[0].value + 2) &&
                    cards[3].value == (cards[0].value + 3) &&
                    cards[4].value == (cards[0].value + 4);
        }

        bool IsFlush()
        {
            auto suit = cards[0].suit;
            for (auto card : cards)
                if (suit != card.suit)
                    return false;
            return true;
        }

        Result IdentifyResult()
        {
            std::sort(cards.begin(), cards.end(), cardSort);
            bool isStraight = IsStraight();
            bool isFlush = IsFlush();
            if (isStraight && isFlush)
            {
                if (cards[4].value == 14) // Ace
                    return Result::RoyalFlush;
                else
                    return Result::StraightFlush;
            }
            else if (isStraight)
            {
                return Result::Straight;
            }
            else if (isFlush)
            {
                return Result::Flush;
            }


            for (auto &card : cards) {
                if(cardCountsMapByValue.count(card.value) == 0)
                    cardCountsMapByValue[card.value] = 1;
                else
                    cardCountsMapByValue[card.value]++;
            }
            
            for (auto count : cardCountsMapByValue) {
                cardCounts.push_back(count.second);
                cardCountsMapByCount[count.second] = count.first;
            }

            std::sort(cardCounts.begin(), cardCounts.end());

            if (cardCounts.size() == 2)
            {
                if (cardCounts[1] == 4)
                    return Result::FourOfAKind;
                else
                    return Result::FullHouse;
            }
            
            if (cardCounts.size() == 3)
            {
                if (cardCounts[2] == 3)
                    return Result::ThreeOfAKind;
                else
                    return Result::TwoPairs;
            }

            if (cardCounts.size() == 4)
                return Result::OnePair;

            return Result::HighCard;
        }

        void Score()
        {
            result = IdentifyResult();
            for (auto &card : cards)
                cardValues.push_back(card.value);
        }

        bool Beats(Hand &hand)
        {
            // If the overall result is clearly different then we have a winner
            if ((int)result > (int)hand.result) return true;
            if ((int)result < (int)hand.result) return false;

            // But if both hands have the same result we need to investigate further

            if (result == RoyalFlush)
            {
                return true; // No draws in the data set
            }

            if (result == StraightFlush)
            {
                if (cardValues[0] > hand.cardValues[0])
                    return true;
                else
                    return false;
            }

            if (result == FourOfAKind)
            {
                if (cardCountsMapByCount[4] > hand.cardCountsMapByCount[4])
                    return true;
                else
                    return false;
            }

            if (result == FullHouse)
            {
                if (cardCountsMapByCount[3] > hand.cardCountsMapByCount[3])
                    return true;
                else
                {
                    if (cardCountsMapByCount[2] > hand.cardCountsMapByCount[2])
                        return true;
                    return false;
                }
            }

            if (result == Flush)
            {
                for (int i = 4; i >= 0; i--)
                {
                    if (cardValues[i] == hand.cardValues[i]) continue;
                    if (cardValues[i] > hand.cardValues[i])
                        return true;
                    else
                        return false;
                }
            }

            if (result == Straight)
            {
                if (cardValues[4] > hand.cardValues[4])
                    return true;
                else
                    return false;
            }

            if (result == ThreeOfAKind)
            {
                if (cardCountsMapByCount[3] > hand.cardCountsMapByCount[3]) return true;
                if (cardCountsMapByCount[3] < hand.cardCountsMapByCount[3]) return false;

                // Remove already compared value so we can compare the others
                cardValues.erase(std::remove(cardValues.begin(), cardValues.end(), cardCountsMapByCount[3]), cardValues.end());
                hand.cardValues.erase(std::remove(hand.cardValues.begin(), hand.cardValues.end(), hand.cardCountsMapByCount[3]), hand.cardValues.end());

                for (int i = 1; i >= 0; i++)
                {
                    if (cardValues[i] == hand.cardValues[i]) continue;
                    if (cardValues[i] > hand.cardValues[i])
                        return true;
                    else
                        return false;
                }
                return false;
            }

            if (result == TwoPairs)
            {
                int remainingCard = cardCountsMapByCount[1];
                int remainingCardCompare = hand.cardCountsMapByCount[1];

                cardValues.erase(std::remove(cardValues.begin(), cardValues.end(), cardCountsMapByCount[1]), cardValues.end());
                hand.cardValues.erase(std::remove(hand.cardValues.begin(), hand.cardValues.end(), hand.cardCountsMapByCount[1]), hand.cardValues.end());

                for (int i = 1; i >= 0; i++)
                {
                    if (cardValues[i] == hand.cardValues[i]) continue;
                    if (cardValues[i] > hand.cardValues[i])
                        return true;
                    else
                        return false;
                }

                if (remainingCard > remainingCardCompare)
                    return true;
                else
                    return false;
            }

            if (result == OnePair)
            {
                if (cardCountsMapByCount[2] > hand.cardCountsMapByCount[2]) return true;
                if (cardCountsMapByCount[2] < hand.cardCountsMapByCount[2]) return false;

                cardValues.erase(std::remove(cardValues.begin(), cardValues.end(), cardCountsMapByCount[2]), cardValues.end());
                hand.cardValues.erase(std::remove(hand.cardValues.begin(), hand.cardValues.end(), hand.cardCountsMapByCount[2]), hand.cardValues.end());

                for (int i = 2; i >= 0; i--)
                {
                    if (cardValues[i] == hand.cardValues[i]) continue;
                    if (cardValues[i] > hand.cardValues[i])
                        return true;
                    else
                        return false;
                }
                return false;
            }

            // High card
            for (int i = 4; i >= 0; i--)
            {
                if (cardValues[i] > hand.cardValues[i])
                    return true;
                else
                    return false;
            }
            return false;
        }
    };

    class Game
    {
    public:
        std::vector<Hand> hands;

        Game(const std::string &g)
        {
            std::string a = g.substr(0, 14);
            hands.push_back(Hand(a));
            std::string b = g.substr(14);
            hands.push_back(Hand(b));
        }

        int Result()
        {
            hands[0].Score();
            hands[1].Score();
            if (hands[0].Beats(hands[1]))
            {
                return 1;
            }
            else
            {
                return 2;
            }
            
            return 1;
        }
    };


}