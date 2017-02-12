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
#include <fstream>
using namespace std;

int main() {
   // insert code here...
   cout << "Magical butterflies and unicorns." << endl;

   MAB steve(1);
   
   Agent Bourne(&steve);

   ofstream fout;

   for (int i = 0; i < 30; i++) {
      Bourne.testA(1000000,0.01);
   }
   
//   
//   int num = 1000000;
//   int numArms = 12;
//   
//   MAB mab(numArms);
//   
//   Agent Bond(&mab);
//   
//   fout.open("rewards12.txt");
//   
//   for (int i = 0; i < num; i++) {
//      Bond.executeCycle();
//      Bond.showValues(&fout);
//   }
//   fout.close();
   
   return 0;
}
