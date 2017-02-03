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

Card::Card(){
   rank = 0;
   suit = "";
}

Card::Card(int rankIn,std::string suitIn){
   rank = rankIn;
   suit = suitIn;
}

void Card::display(std::ofstream* fout){
   //display rank and suit
   *fout << rank << "\t" << suit << std::endl;
}

bool Card::operator==(const Card &card) const {
   if ( (card.rank == this->rank) && (card.suit == this->suit) ) {
      return true;
   }
   return false;
}
