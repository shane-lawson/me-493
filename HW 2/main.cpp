//
//  main.cpp
//  HW 2
//
//  Created by Shane Lawson on 2/19/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include <iostream>
#include <thread>
#include <chrono>
#include "Agent.h"
using namespace std;

int promptForControlMode();
void testB(Agent*);
void testC(Agent*);

////////// MAIN //////////

int main() {
   int controlMode = -1;
   
   //create agent
   Agent Bond;
   
   //get control mode from user
   controlMode = promptForControlMode();

   if (controlMode == 1) {
      testB(&Bond); //manual mode
   } else {
      testC(&Bond); //auto mode
   }
   
   return 0;
}

////////// FUNCTIONS //////////

void testB(Agent* agent) {
   char input = 'a';
   char done = false;
   
   //manual control
   while(!done) {
      //clear screen and print instructions
      cout << string(75,'\n');
      cout << "Enter WASD to move." << endl;
      cout << "Enter 'q' or 'Q' to quit." << endl;
      
      //move agent based on user input
      done = agent->move(input);
      if (!done) {
         //prompt for next move
         cout << endl << "Enter next move(s): ";
         cin >> input;
         if (input == 'q' || input == 'Q') {
            break;
         }
      }
   }
}

void testC(Agent* agent) {
   char input = 'a';
   char done = false;
   //auto control
   
   //clear screen
   cout << string(75,'\n');
   
   //move once to show grid
   done = agent->move(input);
   
   //loop until goal is found
   while(!done) {
      //clear screen
      cout << string(75,'\n');
      
      //move in auto mode
      done = agent->move();
      if (!done) {
         cout << endl;
      }
      
      //sleep thread so user can see agent work
      this_thread::sleep_for (chrono::milliseconds(500));
   }
}

int promptForControlMode() {
   int input;
   
   cout << string(75,'\n');
   cout << "How would you like to proceed?" << endl;
   cout << "\t1. Manual Control Mode" << endl;
   cout << "\t2. Rule of Thumb Control Mode" << endl;
   cout << "Enter your selection: ";
   cin >> input;
   
   return input;
}
