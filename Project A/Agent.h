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

class Agent {
   double alpha;
   double epsilon;
   std::vector<double> armValues;
   
   int getMaxArm();
public:
   Agent();
   void sense();
   int decide(const int);
   double act(const int,MAB*);
   void react(const int,double);
};

#endif /* Agent_h */
