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
#include "MAB.h"

#define SLRAND (double)rand()/RAND_MAX //rand between 0.0 and 1.0

Agent::Agent(MAB* pMAB) {
   //seed random numbers for shuffling only once when class is first initialized
   static bool seeded = false;
   if(!seeded){
      srand((int)time(NULL));
      seeded = true;
   }
   
   mab = pMAB;
   alpha = 0.1;
   epsilon = 0.05;
   
   for (int i = 0; i <mab->getNumArms(); i++) {
      armValues.push_back(0.0);
   }
}

int Agent::getMaxArm() {
   double maxValue = 0;
   int maxPosition = 0;
   for (int i = 0; i < armValues.size(); i++) {
      if (armValues.at(i) > maxValue) {
         maxPosition = i;
         maxValue = armValues.at(i);
      }
   }
   return maxPosition;
}

int Agent::decide() {
   //epsilon (do random)
   if (SLRAND <= epsilon) {
      return rand()%mab->getNumArms();
   } else {
      //1-epsilon (do greedy)
      return this->getMaxArm();
   }
}

double Agent::act(const int armToPull) {
   return mab->pullArm(armToPull);
}

void Agent::react(const int armPulled, const double reward) {
   armValues.at(armPulled) = reward*alpha + armValues.at(armPulled)*(1-alpha);
}

void Agent::executeCycle() {
   int armToPull = this->decide();
   double reward = this->act(armToPull);
   this->react(armToPull, reward);
}
