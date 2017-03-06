//
//  main.cpp
//  Project B
//
//  Created by Shane Lawson on 3/2/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include <iostream>
#include "Agent.h"
#include "Grid.h"
using namespace std; 

int main() {
   // insert code here...
   std::cout << "Magical butterflies and unicorns." << endl;
   Grid gridworld;
   Agent Bond(&gridworld);
   return 0;
}
