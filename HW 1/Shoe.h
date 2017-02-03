//
//  Shoe.h
//  ME 493
//
//  Created by Shane Lawson on 2/2/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include "Card.h"
#include <vector>

#ifndef Shoe_h
#define Shoe_h

class Shoe {
   int decks;
   std::vector<Card> cards;
   
public:
   Shoe(int numDecks = 0);
   void shuffle();
   void printToFile();
   void runTest();
   void testA();
   void testB();
};

#endif /* Shoe_h */
