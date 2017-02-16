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

   int numOfPulls = 10000; //number of iterations
   //get number of arms from user
   int numArms = getNumArmsFromUser();
   
   //create multi armed bandit with specified number of arms
   MAB mab(numArms);
   
   //create agent with pointer to multi armed bandit to interact with
   Agent Bond(&mab);
   
   //30 statistical runs
   for (int i = 0; i < 30; i++) {
      //ask agent to execute its action cycle
      Bond.executeCycle(numOfPulls);
   
      //ask agent to run test
      Bond.runTest();
      
      //reset the agent for next run (i.e. using MIB Agent K's neuralyzer)
      Bond.reset();
   }

   //output arm means to console for plotting validation
//   for (int i = 0; i < mab.getNumArms(); i++) {
//      cout << "Mean: " << mab.getArmMean(i) << endl;
//   }
   
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
