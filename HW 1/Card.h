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
   int rank;
   std::string suit;
   
public:
   Card();
   Card(int,std::string);
   void display();
};
#endif /* card_h */
