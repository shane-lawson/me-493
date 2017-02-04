//
//  Deck.cpp
//  HW 1
//
//  Created by Shane Lawson on 2/1/17. 
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include "Deck.h"
#include <string>

Deck::Deck(){
   //construct an unshuffled deck of cards
   std::string suits[] = {"spades","hearts","clubs","diamonds"}; //suit possibilities
   
   //loop through ranks and suits to generate ordered deck of cards
   for (int i = 0; i<4; i++) {
      for (int j = 0; j<13; j++) {
         cards.push_back(Card(j+1, suits[i]));
      }
   }
}

std::vector<Card>* Deck::getCards(){
   //return address of cards in deck
   return &cards;
}
