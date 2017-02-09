//
//  Arm.cpp
//  ME 493
//
//  Created by Shane Lawson on 2/8/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include "Arm.h"
#include <ctime>
#include <random>
#include <cmath>

#define SLRAND (double)rand()/RAND_MAX //rand between 0 and 1

Arm::Arm() {
   //construct an arm
   //seed random numbers for shuffling only once when class is first initialized
   static bool seeded = false;
   if(!seeded){
      srand((int)time(NULL));
      seeded = true;
   }
   
   mean = rand()%100;
   stdDev = rand()%100;
   z1 = -1;
   generate = false;
}

double Arm::getReward() {
   generate = !generate;
   //box muller gives 2 z values, so we only have to generate them every other time.
   if (generate) {
      double u1 = SLRAND;
      double u2 = SLRAND;
      double z0;
      z0 = sqrt(-2*log(u1))*cos(2*M_PI*u2);
      z1 = sqrt(-2*log(u1))*sin(2*M_PI*u2);
      return z0*stdDev + mean;
   } else {
      return z1*stdDev + mean;
   }
}
