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
   double alpha;
   double epsilon;
   std::vector<double> armValues;
   MAB* mab;
   
   int getMaxArm();
   //void sense() not required in this application
   int decide();
   double act(const int);
   void react(const int,const double);
   void testA();
   void testB();
public:
   Agent(MAB* = NULL);
   void executeCycle(int i=1);
   void showValues(std::ofstream*);
   void reset();
   void runTest();
};

#endif /* Agent_h */
