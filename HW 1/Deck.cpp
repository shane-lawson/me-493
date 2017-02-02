//
//  Deck.cpp
//  HW 1
//
//  Created by Shane Lawson on 2/1/17. 
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include "Deck.h"
#include <ctime>
#include <random>
#include <iostream>

Deck::Deck(){
   //seed random numbers only once when class is first initiliazed
   static bool seeded = false;
   if(!seeded){
      srand((int)time(NULL));
   }
   
   string suits[] = {"spades","hearts","clubs","diamonds"}; //suit possibilities
   //loop through ranks and suits to generate ordered deck of cards
   for (int i = 0; i<4; i++) {
      for (int j = 0; j<13; j++) {
         cards.push_back(Card(j+1, suits[i]));
      }
   }
}

void Deck::display(){
   //display all cards in deck
   for (int i=0; i<cards.size(); i++) {
      cards.at(i).display();
   }
}

void Deck::shuffle(){
   Card tempCardOne;
   Card tempCardTwo;
   int cardOneSpot;
   int cardTwoSpot;

   for (int i = 0 ; i < 1000; i++) {
      cardOneSpot = rand()%52;
      cardTwoSpot = rand()%52;
      tempCardOne = cards.at(cardOneSpot);
      tempCardTwo = cards.at(cardTwoSpot);
      cards.erase(cards.begin()+cardOneSpot);
      cards.insert(cards.begin()+cardOneSpot, tempCardTwo);
      cards.erase(cards.begin()+cardTwoSpot);
      cards.insert(cards.begin()+cardOneSpot, tempCardOne);
   }
}
