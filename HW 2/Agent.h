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
   Position pos;    //the current position of the agent
   Grid map;        //the grid, given to the agent as a "map", useful in Project B
   Goal endGoal;    //the goal
   
public:
   Agent();         //constructs an agent
   bool move();     //determines which direction to move agent to get closer to the goal, then uses move(char) to move in that
   bool move(char); //moves agent one square in the specified direction and returns true if the agent and goal positions match
//   void sense(); necessary for Project B
//   int decide();
//   double act();
//   void react();
};

#endif /* Agent_h */
