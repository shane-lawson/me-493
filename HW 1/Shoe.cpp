//
//  Shoe.cpp
//  ME 493
//
//  Created by Shane Lawson on 2/2/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include "Shoe.h"
#include "Deck.h"
#include <ctime>
#include <random>
#include <fstream>
#include <assert.h>

Shoe::Shoe(int numDecks){
   //construct a shoe
   //seed random numbers for shuffling only once when class is first initialized
   static bool seeded = false;
   if(!seeded){
      srand((int)time(NULL));
   }
   
   decks = 0;
   //create new, unshuffled deck of cards
   Deck newDeck;
   std::vector<Card> newDeckCards = newDeck.getCards();
   
   //add cards from deck to the shoe numDecks times
   for (int i=0; i < numDecks; i++) {
      cards.insert(cards.end(),newDeckCards.begin(),newDeckCards.end());
      decks++;
   }
}

void Shoe::shuffle() {
   Card tempCardOne;
   Card tempCardTwo;
   int cardOneSpot;
   int cardTwoSpot;
   
   //swap random cards a variable number of times based on how many exist in shoe
   //cards.size()*20 results in ~10000 times per deck of cards
   for (int i = 0 ; i < cards.size()*20; i++) {
      //get random indices
      cardOneSpot = rand()%cards.size();
      cardTwoSpot = rand()%cards.size();
      
      //self-made swap to avoid using built-in swap
      tempCardOne = cards.at(cardOneSpot);
      tempCardTwo = cards.at(cardTwoSpot);
      cards.erase(cards.begin()+cardOneSpot);
      cards.insert(cards.begin()+cardOneSpot, tempCardTwo);
      cards.erase(cards.begin()+cardTwoSpot);
      cards.insert(cards.begin()+cardOneSpot, tempCardOne);
   }
}

void Shoe::printToFile() const{
   //output all cards in shoe to file
   std::string fileName;
   if (decks > 1) {
      fileName = "multideck.txt";
   }else{
      fileName = "singledeck.txt";
   }
   
   std::ofstream fileOut;
   std::ofstream* fout = &fileOut;
   fout->open(fileName);
   for (int i=0; i<cards.size(); i++) {
      cards.at(i).display(fout);
   }
   fout->close();
}

void Shoe::runTest() const{
   //select which test to run based on number of decks
   if (decks > 1) {
      this->testB();
   }else{
      this->testA();
   }
}

void Shoe::testA() const{
   //run single deck test
   bool found = false;
   Card tempCard;
   
   //pull each card of the shoe, and compare it to every other card in the shoe
   //after checking each card against the rest of the shoe, assert that a match has not been found
   for (int i = 0; i < cards.size(); i++) {
      tempCard = cards.at(i);
      for (int j = 0; j < cards.size(); j++) {
         if ((tempCard == cards.at(j)) && (j != i)) {
            found = true;
         }
      }
      assert(found != true);
   }
}

void Shoe::testB() const{
   //run multideck test
   int instances = 0;
   Card firstCard = cards.at(0);
   
   //pull first card from the shoe, and compare it to every other card in the shoe
   //when a match is found, increment instances
   //assert total number of instances is the same number as decks
   for (int i=0; i < cards.size(); i++) {
      if(cards.at(i) == firstCard){
         instances++;
      }
   }
   assert(instances == decks);
}
