//
//  main.cpp
//  HW 3
//
//  Created by Shane Lawson on 3/10/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include <iostream>
#include "Agent.h"
#include "Grid.h"

using namespace std;

int main() {
   // insert code here...
   cout << "Magical butterflies and unicorns." << endl;
   Grid gridworld;
   Agent Bond(&gridworld);
   
   //heuristic method
   for (int i = 0; i < 1000; i++) {
      Bond.move();
      Bond.displayGrid();
   }
   
   //q-learner method
   while (gridworld.getNumTimesFound() < 1) {
      Bond.runCycle();
   }

    return 0;
}
