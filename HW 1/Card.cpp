//
//  Card.cpp
//  HW 1
//
//  Created by Shane Lawson on 2/1/17. 
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include "Card.h"
#include <iostream>

Card::Card(){
   rank = 0;
   suit = "";
}

Card::Card(int rankIn,std::string suitIn){
   rank = rankIn;
   suit = suitIn;
}

void Card::display(){
   //display rank and suit
   std::cout << rank << "\t" << suit << std::endl;
}
