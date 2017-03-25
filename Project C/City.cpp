//
//  City.cpp
//  ME 493
//
//  Created by Shane Lawson on 3/23/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include "City.h"
#include <random>
#include <ctime>

#define SLRAND (double)rand()/RAND_MAX //rand between 0.0 and 1.0

City::City() {
   //seed random numbers only once when class is first initialized
   static bool seeded = false;
   if(!seeded){
      srand((int)time(NULL));
      seeded = true;
   }
   
   xPos = SLRAND * 100.0;
   yPos = SLRAND * 100.0;
}

double City::calcDistance(City cityIn) {
   return sqrt( (xPos-cityIn.xPos)*(xPos-cityIn.xPos) + (yPos-cityIn.yPos)*(yPos-cityIn.yPos) );
}
