//
//  main.cpp
//  HW 1
//
//  Created by Shane Lawson on 2/1/17. 
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include <iostream>
#include <string>
#include "Shoe.h"
using namespace std;

int getNumDecksFromUser();

int main() {
   string fileName;
   int numDecks = getNumDecksFromUser();
   
   cout << "Shuffling " << numDecks << " decks..." << endl;
   
   //create a shoe with specified number of decks
   Shoe decks(numDecks);

   //shuffle shoe
   decks.shuffle();
   
   //run test on shoe
   decks.runTest();
   
   cout << "Done!" << endl;
   
   //print shoe to file
   fileName = decks.printToFile();
   
   cout << "Shuffled cards can be found in \"" << fileName << "\"." << endl;
   
   return 0;
}

int getNumDecksFromUser(){
   int input = 1;
   //console output and user input
   while(true){
      cout << string(75,'\n') << "How many decks would you like to shuffle?" << endl;
      
      //if input is not numeric or negative, ask for positive int
      if(!cin.good() || input <= 0){
         cin.clear();
         cin.ignore();
         cout << "Please enter a positive integer: ";
      }else{
         cout << "Enter number: ";
      }
      
      //get input
      cin >> input;
      
      ///break infinite loop if input is numeric and positive
      if(cin.good() && input > 0){
         break;
      }
   }
   return input;
}
