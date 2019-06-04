#pragma once

#include <vector>
#include <algorithm>
#include <string>
#include <set>
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
        std::map<int, int> cardCountsMap;
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
            return cards[0].value == cards[4].value + 4;
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
                if (cards[4].value = 14) // Ace
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
                if(cardCountsMap.count(card.value) == 0)
                    cardCountsMap[card.value] = 1;
                else
                    cardCountsMap[card.value]++;
            }
            
            for (auto count : cardCountsMap) {
                cardCounts.push_back(count.second);
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

        /*
        void Score()
        {
            std::sort(cards.begin(), cards.end(), cardSort);

            bool straight = true;
            bool flush = true;
            Suit flushSuit = None;
            int sameValue = 0;
            int prevValue = 0;
            vector<int> sameCount;
            vector<int> sameValues;
            sameCount.push_back(0);
            sameCount.push_back(0);
            int sameCountIndex = 0;

            for (auto c : cards)
            {
                if (flushSuit == None)
                {
                    flushSuit = c.suit;
                }
                else if(flushSuit != c.suit)
                {
                    flush = false;
                }

                if (c.value == prevValue)
                {
                    if (sameValue == c.value) // something we've seen before, just count  
                    {
                        sameCount[sameCountIndex]++;
                    }
                    else // a new set
                    {
                        if (sameCount[sameCountIndex] > 0)  // second pair so advance and count
                        {
                            sameCountIndex++;
                        }

                        sameCount[sameCountIndex] += 2;
                        sameValue = c.value;
                        sameValues.push_back(sameValue);
                    }

                }

                if (prevValue != 0 && c.value - prevValue != 1) // if the gaps between each card = 1, then it's a straight
                    straight = false;

                prevValue = c.value;
            }

            if (straight && flush)
            {
                if (cards[4].value == 14)
                {
                    result = RoyalFlush;
                }
                else
                {
                    result = StraightFlush;
                    cardValues.push_back(cards[4].value);
                }
            }

            if (sameCount[0] == 4 || sameCount[1] == 4)
            {
                result = FourOfAKind;
            }

            if ((sameCount[0] == 3 && sameCount[1] == 2) ||
                (sameCount[1] == 3 && sameCount[0] == 2))
                result = FullHouse;
             
            if (flush)
                result = Flush;

            if (straight)
            {
                result = Straight;
                //cardValues.push_back[cards[4].value];
            }

            if (sameCount[0] == 3)
                result = ThreeOfAKind;

            if (sameCount[0] == 2 && sameCount[1] == 2)
                result = TwoPairs;

            if (sameCount[0] == 2)
                result = OnePair;

            result = HighCard;
            for (auto c : cards)
            {
                cardValues.push_back(c.value);
            }
        }*/

        bool Beats(Hand &hand)
        {
            if (result == RoyalFlush) return true;

            if (result == StraightFlush)
            {
                if (hand.result == StraightFlush)
                {
                    if (cardValues[0] > hand.cardValues[0])
                        return true;
                    else
                        return false;
                }
                else
                {
                    return true;
                }
            }

            if (result == FourOfAKind)
            {
                if (hand.result == FourOfAKind)
                {
                    if (cardCounts[1] > hand.cardCounts[1])
                        return true;
                    else
                        return false;
                }
                else
                {
                    return true;
                }
            }

            if (result == FullHouse)
            {
                if (hand.result == FullHouse)
                {
                    if (cardCounts[1] > hand.cardCounts[1])
                        return true;
                    else
                    {
                        if (cardCounts[0] > hand.cardCounts[0])
                            return true;
                        return false;
                    }
                }
                else
                {
                    return true;
                }
            }

            if (result == Flush)
            {
                if (hand.result == Flush)
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
                else
                {
                    return true;
                }
            }

            if (result == Straight)
            {
                if (hand.result == Straight)
                {
                    if (cardValues[4] > hand.cardValues[4])
                        return true;
                    else
                        return false;
                }
                else
                {
                    return true;
                }
            }

            if (result == ThreeOfAKind)
            {
                if (hand.result == ThreeOfAKind)
                {
                    for (int i = 2; i >= 0; i++)
                    {
                        if (cardValues[i] == hand.cardValues[i]) continue;
                        if (cardValues[i] > hand.cardValues[i])
                            return true;
                        else
                            return false;
                    }
                    return false;
                }
                else
                {
                    return true;
                }
            }

            if (result == TwoPairs)
            {
                if (hand.result == TwoPairs)
                {
                    for (int i = 2; i >= 0; i++)
                    {
                        if (cardValues[i] == hand.cardValues[i]) continue;
                        if (cardValues[i] > hand.cardValues[i])
                            return true;
                        else
                            return false;
                    }
                    return false;
                }
                else
                {
                    return true;
                }
            }

            if (result == OnePair)
            {
                if (hand.result == OnePair)
                {
                    for (int i = 3; i >= 0; i++)
                    {
                        if (cardValues[i] == hand.cardValues[i]) continue;
                        if (cardValues[i] > hand.cardValues[i])
                            return true;
                        else
                            return false;
                    }
                    return false;
                }
                else
                {
                    return true;
                }
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