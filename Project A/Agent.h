//
//  Agent.h
//  ME 493
//
//  Created by Shane Lawson on 2/9/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#ifndef Agent_h
#define Agent_h

#include <vector>
class MAB;

#include <fstream>

class Agent {
   double alpha;                       //alpha value for agent
   double epsilon;                     //epsilon value for agent
   std::vector<double> armValues;      //vector storing the value for each of the arms the agent is evaluating
   MAB* mab;                           //pointer to the multi armed bandit the agent is interacting with
   
   int getMaxArm();                    //returns which arm has the max value
   //void sense() not required in this application
   int decide();                       //decide (returns) which arm to pull (greedy vs. exploration)
   double act(const int) const;        //"pull" specified arm and return reward
   void react(const int,const double); //update value of specified arm based on the reward
   void testA();                       //checks that the agent value will converge to the mean of a single arm
   void testB();                       //checks that the agent has converged to "clearly" the best arm
public:
   Agent(MAB* = NULL);                 //constructor for an agent, input is a pointer to the multi armed bandit the agent will be interacting with
   void executeCycle(int i=1);         //executes the specified number of sense, decide, act, react cycles
   void reset();                       //resets all of the agents learned values to 0
   void runTest();                     //selects and runs testA or testB depending on number of arms
   void setEpsilon(const double);      //sets epsilon to specified value, used for varying parameter tests
   void setAlpha(const double);        //sets alpha to specified value, used for varying parameter tests
};

#endif /* Agent_h */
