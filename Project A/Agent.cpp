//
//  Agent.cpp
//  ME 493
//
//  Created by Shane Lawson on 2/9/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include "Agent.h"
#include <random>
#include <ctime>

Agent::Agent() {
   //seed random numbers for shuffling only once when class is first initialized
   static bool seeded = false;
   if(!seeded){
      srand((int)time(NULL));
      seeded = true;
   }
   
   alpha = 0.1;
   epsilon = 0.05;
}

void Agent::sense() {
   
}

void Agent::decide() {
   //epsilon (do random)
   //1-epsilon (do greedy)
   
}

void Agent::act() {
   
}

void Agent::react() {
   
}
