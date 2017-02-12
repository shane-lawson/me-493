//
//  main.cpp
//  Project A
//
//  Created by Shane Lawson on 2/7/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include "MAB.h"
#include "Agent.h"
#include <iostream>
#include <fstream>
using namespace std;

int getNumArmsFromUser();

int main() {
   // insert code here...
   cout << "Magical butterflies and unicorns." << endl;

   int numOfPulls = 1000000;
   int numArms = getNumArmsFromUser();
   
   MAB mab(numArms);
   
   Agent Bond(&mab);
   
   Bond.executeCycle(numOfPulls);
   
   Bond.runTest();

   return 0;
}

int getNumArmsFromUser(){
   int input = 1;
   //console output and user input
   while(true){
      cout << string(75,'\n') << "How many arms would you like to have?" << endl;
      
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
