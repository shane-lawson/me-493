//
//  Shoe.cpp
//  ME 493
//
//  Created by Shane Lawson on 2/2/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include "Shoe.h"

void Shoe::shuffle() {
   Card tempCardOne;
   Card tempCardTwo;
   int cardOneSpot;
   int cardTwoSpot;
   
   for (int i = 0 ; i < 1000; i++) {
      cardOneSpot = rand()%cards.size();
      cardTwoSpot = rand()%cards.size();
      tempCardOne = cards.at(cardOneSpot);
      tempCardTwo = cards.at(cardTwoSpot);
      cards.erase(cards.begin()+cardOneSpot);
      cards.insert(cards.begin()+cardOneSpot, tempCardTwo);
      cards.erase(cards.begin()+cardTwoSpot);
      cards.insert(cards.begin()+cardOneSpot, tempCardOne);
   }

}
