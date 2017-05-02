//
//  main.cpp
//  Project D
//
//  Created by Shane Lawson on 4/27/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include "EA.h"
#include "Simulator.h"
#include "LY_NN.h"
#include <iostream>
using namespace std;

int main() {
   cout << "Magical butterflies and unicorns." << endl;
   std::vector<double> inputs;
   neural_network NN;

   NN.setup(2, 5, 1);
   NN.set_in_min_max(-M_PI, M_PI); //theta
   NN.set_in_min_max(-17.0, 17.0); //omega
   NN.set_out_min_max(-15.0, 15.0); //u
   
   Simulator thing;
   
   for (int i = 0; i < 100; i++) {
      thing.step();
   }
   
   return 0;
}
