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

int main() {
   int controlMode = -1;
   Agent Bond;
   cout << string(75,'\n');
   cout << "How would you like to proceed?" << endl;
   cout << "\t1. Manual Control Mode" << endl;
   cout << "\t2. Rule of Thumb Control Mode" << endl;
   cout << "Enter your selection: ";
   cin >> controlMode;
   
   char input = 'a';
   char done = false;
   if (controlMode == 1) {
      while(!done) {
         cout << string(75,'\n');
         cout << "Enter WASD to move." << endl;
         cout << "Enter 'q' or 'Q' to quit." << endl;
         done = Bond.move(input);
         if (!done) {
            cout << endl << "Enter next move(s): ";
            cin >> input;
            if (input == 'q' || input == 'Q') {
               break;
            }
         }
      }
   } else {
      //clear screen
      cout << string(75,'\n');
      
      //move once to show grid
      done = Bond.move(input);
      
      //loop until goal is found
      while(!done) {
         //clear screen
         cout << string(75,'\n');
         
         //move in auto mode
         done = Bond.move();
         if (!done) {
            cout << endl;
         }

         //sleep thread so user can see agent work
         this_thread::sleep_for (chrono::milliseconds(500));
      }
   }
   
   return 0;
}
