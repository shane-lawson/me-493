//
//  Card.cpp
//  HW 1
//
//  Created by Shane Lawson on 2/1/17. 
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include "Card.h"
#include <iostream>
#include <fstream>

Card::Card(int rankIn,std::string suitIn){
   //construct card
   rank = rankIn;
   suit = suitIn;
}

void Card::display(std::ofstream* fout){
   //print rank and suit to file
   *fout << rank << "\t" << suit << std::endl;
}

bool Card::operator==(const Card &card) const {
   //overload == operator to use for comparisons of cards
   if ( (card.rank == this->rank) && (card.suit == this->suit) ) {
      return true;
   }
   return false;
}
