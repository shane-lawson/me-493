//
//  Agent.cpp
//  ME 493
//
//  Created by Shane Lawson on 2/26/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include "Agent.h"
#include <random>
#include <ctime>
#include <iostream>
#include <string>

Agent::Agent(Grid* gridIn) {
   //construct an agent
   //seed random numbers only once when class is first initialized
   static bool seeded = false;
   if(!seeded){
      srand((int)time(NULL));
      seeded = true;
   }
   
   map = gridIn;
   
   //place agent in random spot
   pos.x = rand()%map->getNumCols();
   pos.y = rand()%map->getNumRows();
}

void Agent::move(char direction) {
   //if allowed, move agent in specified direction
   switch (direction) {
      case 'w':
      case 'W':
         if (pos.y-1 >= 0) {
            pos.y--;
         }
         break;
      case 's':
      case 'S':
         if (pos.y+1 < map->getNumRows()) {
            pos.y++;
         }
         break;
      case 'a':
      case 'A':
         if (pos.x-1 >= 0) {
            pos.x--;
         }
         break;
      case 'd':
      case 'D':
         if (pos.x+1 < map->getNumCols()) {
            pos.x++;
         }
         break;
         
      default:
         break;
   }

   //update the display with the agent and goal positions
   map->displayGrid(pos.x, pos.y);
}

void Agent::move() {
   //get goal position
   Position goalPos = map->getGoalPosition();
   
   //move agent toward the row containing the goal, if not there already
   if (goalPos.y != pos.y) {
      if (goalPos.y - pos.y > 0) {
         this->move('s');
      } else {
         this->move('w');
      }
   } else {
      //move agent toward the column containing the goal
      if (goalPos.x - pos.x > 0) {
         this->move('d');
      } else {
         this->move('a');
      }
   }
}

void Agent::testA() {
   //if x position is too large for grid, bring back into grid (not necessarily up against the wall)
   if (pos.x > map->getNumCols()) {
      pos.x = pos.x%map->getNumCols();
   }
   //if x position is too small for grid, bring back into grid (not necessarily up against the wall)
   if (pos.x < 0) {
      pos.x = (-pos.x)%map->getNumCols();
   }
   //if y position is too large for grid, bring back into grid (not necessarily up against the wall)
   if (pos.y > map->getNumRows()) {
      pos.y = pos.y%map->getNumRows();
   }
   //if y position is too small for grid, bring back into grid (not necessarily up against the wall)
   if (pos.y < 0) {
      pos.y = (-pos.y)%map->getNumRows();
   }
   
   //update grid display
   map->displayGrid(pos.x, pos.y);
   
   std::cout << std::endl;
}
