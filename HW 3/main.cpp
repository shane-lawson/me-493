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

void testA(Agent*,Grid*);
void testB(Agent*,Grid*);

int main() {
   // insert code here...
   cout << "Magical butterflies and unicorns." << endl;
   Grid gridworld;
   Agent Bond(&gridworld);
   
   testA(&Bond, &gridworld);

   testB(&Bond, &gridworld);
   
    return 0;
}

void testA(Agent* agent,Grid* grid) {
   bool success = false;
   Position position = agent->getPosition();
   int i;
   
   //heuristic method
   for (i = 0; i < grid->getNumRows()*4; i++) {
      success = agent->move();
      if ( !(position == agent->getPosition()) ) {
         agent->displayGrid();
         this_thread::sleep_for (chrono::milliseconds(250));
      }
      position = agent->getPosition();
      if (success) {
         break;
      }
   }
   
   if (i == grid->getNumRows()*4) {
      cout << "Test A passed!" << endl;
   } else {
      cout << "Test A failed!" << endl;
   }
   this_thread::sleep_for (chrono::milliseconds(1000));
}

void testB(Agent* agent, Grid* grid) {
   //q-learner method
   while (grid->getNumTimesFound() < 1000) {
      agent->runCycle();
   }
   cout <<"Test B passed!" << endl;
}
