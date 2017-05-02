//
//  Weights.cpp
//  ME 493
//
//  Created by Shane Lawson on 5/1/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include "Weights.h"
#include <random>

#define RAND (double)rand()/RAND_MAX //rand double between 0 and 1

Weights::Weights() {
   //seed random numbers only once when class is first initialized
   static bool seeded = false;
   if(!seeded){
      srand((int)time(NULL));
      seeded = true;
   }
   
   for (int i = 0; i < 3; i++) {
      double weight = 1.0;
      weights.push_back(weight);
   }
}

void Weights::mutate(double mutationSize) {
   for (int i = 0; i < weights.size(); i++) {
      if (rand()%2 == 0) {
         weights.at(i) += mutationSize*(RAND-RAND);
      }
   }
}

std::vector<double> Weights::getWeights() {
   return weights;
}
