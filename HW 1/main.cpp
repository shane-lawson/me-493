//
//  main.cpp
//  HW 1
//
//  Created by Shane Lawson on 2/1/17. 
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include <iostream>
#include "Shoe.h"
using namespace std;

int main() {
   int input;
   cout << "How many decks would you like to shuffle?" << endl;
   cout << "Enter number: ";
   cin >> input;
   cout << "Shuffling " << input << " decks..." << endl;
   
   Shoe decks(input);

   decks.shuffle();
   decks.runTest();
   decks.printToFile();
   
   cout << "Done!" << endl;
   return 0;
}
