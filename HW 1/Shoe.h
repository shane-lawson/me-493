//
//  Shoe.h
//  ME 493
//
//  Created by Shane Lawson on 2/2/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include "Card.h"
#include "Deck.h"
#include <vector>

#ifndef Shoe_h
#define Shoe_h

class Shoe {
   std::vector<Card> cards;
   
public:
   void shuffle();
};

#endif /* Shoe_h */
