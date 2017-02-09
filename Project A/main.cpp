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

   int num = 100000;
   int numArms = 5;
   
   MAB mab(numArms);
   
   double rewards[numArms][num];
   
   for (int j = 0; j < numArms; j++) {
      for (int i = 0; i < num; i++) {
         rewards[j][i] = mab.pullArm(j);
      }
   }
   
   cout << "Found mean: " << endl;
   
   double totalReward[numArms];

   for (int j = 0; j < numArms; j++) {
      totalReward[j] = 0.0;
      for (int i = 0; i < num; i++) {
         totalReward[j] = totalReward[j] + rewards[j][i];
      }
      totalReward[j] = totalReward[j] / num;
      cout << totalReward[j] << endl;
   }

   
    return 0;
}
