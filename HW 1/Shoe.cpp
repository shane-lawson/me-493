//
//  Shoe.cpp
//  ME 493
//
//  Created by Shane Lawson on 2/2/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include "Shoe.h"
#include "Deck.h"
#include <random>
#include <fstream>
#include <assert.h>

Shoe::Shoe(){
   decks = 0;
}

Shoe::Shoe(int numDecks){
   decks = numDecks;
   Deck newDeck;
   std::vector<Card> newDeckCards = newDeck.getCards();
   
   for (int i=0; i < numDecks; i++) {
      cards.insert(cards.end(),newDeckCards.begin(),newDeckCards.end());
   }
}

void Shoe::shuffle() {
   Card tempCardOne;
   Card tempCardTwo;
   int cardOneSpot;
   int cardTwoSpot;
   
   for (int i = 0 ; i < 10000; i++) {
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

void Shoe::printToFile(){
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

void Shoe::runTest(){
   if (decks > 1) {
      this->testB();
   }else{
      this->testB();
   }
}

void Shoe::testA(){
   
}

void Shoe::testB(){
   int instances = 0;
   Card firstCard = cards.at(0);
   
   for (int i=0; i<cards.size(); i++) {
      if(cards.at(i) == firstCard){
         instances++;
      }
   }
   
   assert(instances == decks);
}
