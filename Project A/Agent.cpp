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

void Agent::sense() {
   
}

int Agent::decide(const int numArms) {
   //epsilon (do random)
   if (SLRAND <= epsilon) {
      return rand()%numArms;
   } else {
      //1-epsilon (do greedy)
      return this->getMaxArm();
   }
}

double Agent::act(const int armToPull, MAB* mab) {
   return mab->pullArm(armToPull);
}

void Agent::react(const int armPulled, double reward) {
   armValues.at(armPulled) = reward*alpha + armValues.at(armPulled)*(1-alpha);
}
