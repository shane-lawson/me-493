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
using namespace std;

int main() {
   // insert code here...
   cout << "Magical butterflies and unicorns." << endl;

   int num = 1000000000;
   int numArms = 5;
   
   MAB mab(numArms);
   
   Agent Bond(&mab);
   
   for (int i = 0; i < num; i++) {
      Bond.executeCycle();
   }
   
   return 0;
}
