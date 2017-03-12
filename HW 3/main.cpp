//
//  main.cpp
//  HW 3
//
//  Created by Shane Lawson on 3/10/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include <iostream>
#include <thread>
#include <chrono>
#include "Agent.h"
#include "Grid.h"

using namespace std;

int main() {
   // insert code here...
   cout << "Magical butterflies and unicorns." << endl;
   bool success = false;
   Grid gridworld;
   Agent Bond(&gridworld);
   
   Position position = Bond.getPosition();
   //heuristic method
   for (int i = 0; i < gridworld.getNumRows()*4; i++) {
      success = Bond.move();
      if ( !(position == Bond.getPosition()) ) {
         Bond.displayGrid();
         this_thread::sleep_for (chrono::milliseconds(250));
      }
      position = Bond.getPosition();
      if (success) {
         break;
      }
   }

   //q-learner method
   while (gridworld.getNumTimesFound() < 1000) {
      Bond.runCycle();
   }

    return 0;
}
