//
//  Agent.cpp
//  ME 493
//
//  Created by Shane Lawson on 2/26/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include "Agent.h"
#include <random>
#include <ctime>

#include <iostream>

Agent::Agent() {
   //construct an agent
   //seed random numbers only once when class is first initialized
   static bool seeded = false;
   if(!seeded){
      srand((int)time(NULL));
      seeded = true;
   }

   Goal endGoal(rand()%map.getNumCols(),rand()%map.getNumRows());

   //place agent in random spot
   pos.x = rand()%map.getNumCols();
   pos.y = rand()%map.getNumRows();
}
