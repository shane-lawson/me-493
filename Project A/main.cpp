//
//  main.cpp
//  Project A
//
//  Created by Shane Lawson on 2/7/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include "MAB.h"
#include <iostream>
using namespace std;

int main() {
   // insert code here...
   cout << "Magical butterflies and unicorns." << endl;
   
   Arm arm1;
   cout << "Mean: " << arm1.mean << "\tstDev: " << arm1.stdDev << endl;
   
   int num = 1000;
   
   double rewards[num];
   
   for (int i = 0; i < num; i++) {
      rewards[i] = arm1.getReward();
   }
   
   double totalReward = 0.0;
   
   for (int i = 0; i < num; i++) {
      totalReward = totalReward + rewards[i];
   }
   
   totalReward = totalReward / num;
   
   cout << "Found mean: " << totalReward << endl;
   
    return 0;
}
