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
   std::cout << "Magical butterflies and unicorns." << endl;
   Grid gridworld;
   Agent Bond(&gridworld);
   
   int count = 0;
   
   for (int i = 0; i < 1000000; i++) {
      Bond.runCycle();
      if (count > 100000 && count < 100200) {
         Bond.displayGrid();
         cout << i << endl;
         this_thread::sleep_for (chrono::milliseconds(50));
      }
      if (count > 100200) {
         count = 0;
      }
      count++;
   }
   return 0;
}
