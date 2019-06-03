#pragma once

#include <vector>
#include <algorithm>
#include <string>
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
        RoyalFlush,
        StraightFlush,
        FourOfAKind,
        FullHouse,
        Flush,
        Straight,
        ThreeOfAKind,
        TwoPairs,
        OnePair,
        HighCard
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

    bool cardSort(const Card &a, const Card &b) { return (a.value < b.value); }

    class Hand
    {
    public:
        std::vector<Card> cards;
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
        }

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

            if (result == FullHouse)
            {
                if (hand.result == FullHouse)
                {
                    if (cardValues[0] > hand.cardValues[0])
                        return true;
                    else
                    {
                        if (cardValues[10] > hand.cardValues[1])
                            return true;
                        return false;
                    }
                }
                else
                {
                    return true;
                }
            }

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
            /*
            if (hands[0].Score() > hands[1].Score())
            {
                std::cout << "Player 1 won" << std::endl;
                return 1;
            }
            else
            {
                std::cout << "Player 2 won" << std::endl;
                return 2;
            }
            */
            return 1;
        }
    };


}