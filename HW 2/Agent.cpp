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

   endGoal = Goal(rand()%map.getNumCols(),rand()%map.getNumRows());

   //place agent in random spot
   pos.x = rand()%map.getNumCols();
   pos.y = rand()%map.getNumRows();
   std::cout << "x: " << pos.x << "\ty: " << pos.y << std::endl;
}

void Agent::move(char direction) {
   switch (direction) {
      case 'u':
         if (pos.y-1 >= 0) {
            pos.y--;
         }
         break;
      case 'd':
         if (pos.y+1 < map.getNumRows()) {
            pos.y++;
         }
         break;
      case 'l':
         if (pos.x-1 >= 0) {
            pos.x--;
         }
         break;
      case 'r':
         if (pos.x+1 < map.getNumCols()) {
            pos.x++;
         }
         break;
         
      default:
         break;
   }
//   std::cout << "x: " << pos.x << "\ty: " << pos.y << std::endl;
   map.displayGrid(pos.x, pos.y, endGoal.getPosition().x, endGoal.getPosition().y);
}

void Agent::move() {
   Position goalPos = endGoal.getPosition();
   std::cout << goalPos.x << "\t" << goalPos.y << std::endl;
   if (goalPos.y != pos.y) {
      if (goalPos.y - pos.y > 0) {
         this->move('d');
      } else {
         this->move('u');
      }
   } else {
      if (goalPos.x - pos.x > 0) {
         this->move('r');
      } else {
         this->move('l');
      }
   }
}
