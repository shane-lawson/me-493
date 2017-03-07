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
   Grid* map;        //the grid, given to the agent as a "map"
   Position startPos;
   double epsilon = 0.05;
   int moves = 0;
   bool nearOptimal;
   
public:
   Agent(Grid*);         //constructs an agent
   void move();     //determines which direction to move agent to get closer to the goal, then uses move(char) to move in that
   void move(char); //moves agent one square in the specified direction and returns true if the agent and goal positions match
   void testA();    //promps user where to drop agent, then displays grid showing Agent where it has been bumped to on grid.
   void testE();
   void testF();
//   void sense();
   int decide();
   void act(int);
   bool react(int);
   void runCycle();
   void reset();
   void displayGrid();
};

#endif /* Agent_h */
