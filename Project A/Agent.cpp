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
   
   //point to the correct multi armed bandit
   mab = pMAB;
   //set alpha, epsilon, and 0 values
   this->reset();
}

void Agent::reset() {
   alpha = 0.1;
   epsilon = 0.05;
   
   armValues.clear();
   
   for (int i = 0; i < mab->getNumArms(); i++) {
      armValues.push_back(0.0);
   }
   
}

int Agent::getMaxArm() {
   //check for max arm
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

double Agent::act(const int armToPull) const{
   return mab->pullArm(armToPull);
}

void Agent::react(const int armPulled, const double reward) {
   //update value for arm pulled based on reward recieved
   armValues.at(armPulled) = reward*alpha + armValues.at(armPulled)*(1-alpha);
}

void Agent::executeCycle(int i) {
   /* note: all the file output in the function is strictly for creating plots required for the report */
   
   int armToPull;
   double reward;
   std::ofstream fout;
   std::string fileName;
   
   if (armValues.size() == 1) {
      fileName = "singleArmRewards.txt";
   } else {
      fileName = "multiArmRewards.txt";
   }
   
   fout.open(fileName, std::ofstream::out | std::ofstream::app);
   //run cycle specified number of times
   for (int j = 0; j < i; j++) {
      armToPull = this->decide();
      reward = this->act(armToPull);
      fout << reward << "\t" << armToPull << std::endl;
      this->react(armToPull, reward);
   }
   fout.close();
}

void Agent::testA() {
   double averagedValue = 0.0;
   int numOfPulls = 1000000; //run sufficient pulls to converge
   
   //find average value of arm
   for (int i = 0; i < numOfPulls; i++) {
      averagedValue = averagedValue + this->act(0);
   }

   averagedValue = averagedValue / numOfPulls;
   double armMean = mab->getArmMean(0);
   double threshold = 0.01; // +- % window
   double upperlimit = armMean + threshold*armMean;
   double lowerLimit = armMean - threshold*armMean;
   
   //assert that the averaged value of the arm is within an acceptable range of the arm's true mean
   assert(averagedValue < upperlimit && averagedValue > lowerLimit);
}

void Agent::testB() {
   //assuming "best" arm is the one with the highest mean.
   //NOTE: this test malfunctions rarely, in the case of arms with close means with very different standard deviations when the agent recieves a couple extreme rewards at the end of its runs that influence a decision where an arm without the highest mean may be deemed more beneficial
   double maxValue = 0.0;
   double maxValueArm = 0;
   for (int i = 0; i < mab->getNumArms(); i++) {
      if (mab->getArmMean(i) > maxValue) {
         maxValue = mab->getArmMean(i);
         maxValueArm = i;
      }
   }
   //assert that the agent's arm with the highest value is indeed the multi armed bandit's highest paying arm
   assert(maxValueArm == this->getMaxArm());
}

void Agent::runTest() {
   //choose A or B test depending on number of arms
   if (this->armValues.size() > 1) {
      this->testB();
      std::cout << "Test B passed!" << std::endl;
   } else {
      this->testA();
      std::cout << "Test A passed!" << std::endl;
   }
}
