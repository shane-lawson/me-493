//
//  main.cpp
//  Project B
//
//  Created by Shane Lawson on 3/2/17.
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
   Grid gridworld;
   Agent Bond(&gridworld);
   
//   int count = 0;
//   double epsValue = 0.09;
//   for (int k = 0; k<3; k++) {
//      Bond.setEpsilon(epsValue);
//      epsValue = epsValue - 0.04;
//      for (int j = 0; j < 10; j++) {
   
         while (gridworld.getNumTimesFound() < 1000) {
            Bond.runCycle();
//      if (count > 100000 && count < 100200) {
//         Bond.displayGrid();
//         cout << i << endl;
//         this_thread::sleep_for (chrono::milliseconds(50));
//      }
//      if (count > 100200) {
//         count = 0;
//      }
//      count++;
         }
         Bond.testF();

         gridworld.resetQTable();
   
   cout << "Done!" << endl;
   
   while (gridworld.getNumTimesFound() < 1000) {
      Bond.testG();
      //      if (count > 100000 && count < 100200) {
//               Bond.displayGrid();
      //         cout << i << endl;
//               this_thread::sleep_for (chrono::milliseconds(100));
      //      }
      //      if (count > 100200) {
      //         count = 0;
      //      }
      //      count++;
   }
   Bond.testF();
   
   
//      }
//   }
   return 0;
}
