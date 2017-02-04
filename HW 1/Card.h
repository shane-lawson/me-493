//
//  Card.h
//  HW 1
//
//  Created by Shane Lawson on 2/1/17. 
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#ifndef Card_h
#define Card_h

#include <string>

class Card {
   int rank;                                   //number signifying card rank
   std::string suit;                           //string containing card suit
   
public:
   Card(const int i=0,const std::string s=""); //constructor for card, allows with specified suit and rank
   void display(std::ofstream*) const;         //print "(rank) (suit)" as line in file
   bool operator==(const Card&) const;         //overload == operator for comparison of cards
};
#endif /* card_h */
