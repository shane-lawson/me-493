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
#include <assert.h>
#include <iostream>

#include <fstream>

#define SLRAND (double)rand()/RAND_MAX //rand between 0.0 and 1.0

Agent::Agent(MAB* pMAB) {
   //seed random numbers for shuffling only once when class is first initialized
   static bool seeded = false;
   if(!seeded){
      srand((int)time(NULL));
      seeded = true;
   }
   
   mab = pMAB;
   this->reset();
}

void Agent::reset() {
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

void Agent::executeCycle(int i) {
   int armToPull;
   double reward;
   
   for (int j = 0; j < i; j++) {
      armToPull = this->decide();
      reward = this->act(armToPull);
      this->react(armToPull, reward);
   }
}

void Agent::showValues(std::ofstream* fout) {
   for (int i = 0; i < armValues.size(); i++) {
      *fout << armValues.at(i) << "\t";
   }
   *fout << std::endl;
}

void Agent::testA() {
   double averagedValue = 0.0;
   int numOfPulls = 1000000;
   
   for (int i = 0; i < numOfPulls; i++) {
      averagedValue = averagedValue + this->act(0);
   }

   averagedValue = averagedValue / numOfPulls;
   double armMean = mab->getArmMean(0);
   double threshold = 0.01; // +- % window
   double upperlimit = armMean + threshold*armMean;
   double lowerLimit = armMean - threshold*armMean;
   assert(averagedValue < upperlimit && averagedValue > lowerLimit);
}

void Agent::testB() {
   //don't actually know how to implement this test, what makes one "clearly the right choice"? Means are comparable, but perhaps a slighlty higher mean has a larger standard deviation. In that case, the safer bet to get more money might be the lower mean because it is much more consistent. I guess I'll just compare means and match the highest.
   double maxValue = 0.0;
   double maxValueArm = 0;
   for (int i = 0; i < mab->getNumArms(); i++) {
      if (mab->getArmMean(i) > maxValue) {
         maxValue = mab->getArmMean(i);
         maxValueArm = i;
      }
   }
   assert(maxValueArm == this->getMaxArm());
}

void Agent::runTest() {
   if (this->armValues.size() > 1) {
      this->testB();
      std::cout << "Test B passed!" << std::endl;
   } else {
      this->testA();
      std::cout << "Test A passed!" << std::endl;
   }
}
