//
//  Agent.h
//  ME 493
//
//  Created by Shane Lawson on 2/26/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#ifndef Agent_h
#define Agent_h

#include "Position.h"
#include "Grid.h"
#include "Goal.h"

class Agent {
   Position pos;
   Grid map;
   Goal endGoal;
   
public:
   Agent();
   
   void move();
   void move(char);
//   void sense(); necessary for Project B
//   int decide();
//   double act();
//   void react();
};

#endif /* Agent_h */
