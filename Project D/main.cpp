//
//  main.cpp
//  Project D
//
//  Created by Shane Lawson on 4/27/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include "EA.h"
#include "Simulator.h"
#include <iostream>
using namespace std;

int main() {
   cout << "Magical butterflies and unicorns." << endl;
   
   EA ea;
   
   for (int i = 0; i < 1; i++) {
      ea.replicate();
      ea.evaluate();
      ea.downselect();
   }
   
   return 0;
}
