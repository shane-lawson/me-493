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
   int decks;                //number of decks contained in shoe
   std::vector<Card> cards;  //vector containing all cards in shoe
   
   void testA() const;       //runs testA to check that no card in shoe is duplicated
   void testB() const;       //runs testB to check first card of shoe appears only as many times as number of decks
public:
   Shoe(int numDecks = 0);   //constructor for shoe, allows construction with specified number of decks
   void shuffle();           //shuffles all cards in shoe
   void printToFile() const; //prints all cards in shoe to file
   void runTest() const;     //runs test of shoe, testA for single decks, testB for multidecks
};

#endif /* Shoe_h */
