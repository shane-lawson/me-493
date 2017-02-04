//
//  Deck.h
//  HW 1
//
//  Created by Shane Lawson on 2/1/17. 
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include "Card.h"
#include <vector>

#ifndef Deck_h
#define Deck_h
class Deck {
   std::vector<Card> cards;            //vector containing cards in deck
   
public:
   Deck();                             //constructor for a deck of cards
   std::vector<Card> getCards() const; //return copy ofvector containing cards
};

#endif /* deck_h */
