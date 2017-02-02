//
//  main.cpp
//  HW 1
//
//  Created by Shane Lawson on 2/1/17. 
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include <iostream>
#include "Deck.h"

int main() {
   Deck numberOne;
   
   numberOne.display();
   numberOne.shuffle();
   cout << endl << endl;
   numberOne.display();
   
   return 0;
}
