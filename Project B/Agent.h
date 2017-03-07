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
   Position pos;          //the current position of the agent
   Grid* map;             //the grid, given to the agent as a "map"
   Position startPos;     //a copy of the initial position
   double epsilon = 0.05; //espilon value for exploration
   int moves = 0;         //number of moves taken to find goal
   bool nearOptimal;      //flag if successful path is near optimal
   
public:
   Agent(Grid*);          //constructs an agent
   void move();           //determines which direction to move agent to get closer to the goal, then uses move(char) to move in that
   void move(char);       //moves agent one square in the specified direction and returns true if the agent and goal positions match
   void testA();          //tests if agetn is off of grid and bumps it back if so
   void testE();          //asserts that agent has successfully been reset to starting position
   void testF();          //asserts that a near optimal path has been found
//   void sense();
   int decide();          //choose which action to take based on highest Q value
   void act(int);         //move in a specified direction [using move(char)]
   bool react(int);       //update Q table based on action
   void runCycle();       //run a single decide, act, react cycle
   void reset();          //set moves to zero, and move agent back to starting position, also outputs number of moves to file, and checks if moves were near optimal
   void displayGrid();    //calls for the grid to be displayed on the console
};

#endif /* Agent_h */
