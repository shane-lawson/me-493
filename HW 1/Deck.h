//
//  Deck.h
//  HW 1
//
//  Created by Shane Lawson on 2/1/17. 
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include "Card.h"
#include <vector>
using namespace std;

#ifndef Deck_h
#define Deck_h
class Deck {
   vector<Card> cards;
   
public:
   Deck();
   void display();
   void shuffle();
};

#endif /* deck_h */
