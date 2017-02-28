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

#include <curses.h>

Agent::Agent() {
   //construct an agent
   //seed random numbers only once when class is first initialized
   static bool seeded = false;
   if(!seeded){
      srand((int)time(NULL));
      seeded = true;
   }
   
   //create goal randomly within grid
   endGoal = Goal(rand()%map.getNumCols(),rand()%map.getNumRows());

   //place agent in random spot
   pos.x = rand()%map.getNumCols();
   pos.y = rand()%map.getNumRows();
}

bool Agent::move(char direction) {
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
         if (pos.y+1 < map.getNumRows()) {
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
         if (pos.x+1 < map.getNumCols()) {
            pos.x++;
         }
         break;
         
      default:
         break;
   }

   //get position of goal
   Position goalPos = endGoal.getPosition();
   
   //update the display with the agent and goal positions
   map.displayGrid(pos.x, pos.y, goalPos.x, goalPos.y);
   
   //if agent and goal positions match, then success!
   if (pos.x == goalPos.x && pos.y == goalPos.y) {
      std::cout << std::endl << "Success!" << std::endl;
      return true;
   }
   return false;
}

bool Agent::move() {
   //get goal position
   Position goalPos = endGoal.getPosition();
   
   //move agent toward the row containing the goal, if not there already
   if (goalPos.y != pos.y) {
      if (goalPos.y - pos.y > 0) {
         return this->move('s');
      } else {
         return this->move('w');
      }
   } else {
      //move agent toward the column containing the goal
      if (goalPos.x - pos.x > 0) {
         return this->move('d');
      } else {
         return this->move('a');
      }
   }
}
