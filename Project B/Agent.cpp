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
#include <assert.h>
#include <fstream>

#define SLRAND (double)rand()/RAND_MAX //rand between 0.0 and 1.0

Agent::Agent(Grid* gridIn) {
   //construct an agent
   //seed random numbers only once when class is first initialized
   static bool seeded = false;
   if(!seeded){
      srand((int)time(NULL));
      seeded = true;
   }
   
   nearOptimal = false;
   
   map = gridIn;
   
   //place agent in random spot
   pos.x = rand()%map->getNumCols();
   pos.y = rand()%map->getNumRows();
   
   startPos = pos;
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
   
   moves++;
   
   //run test to ensure agent has not left gridspace
   this->testA();
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
}

int Agent::decide() {
   //epsilon (do random)
   if (SLRAND <= epsilon) {
      return rand()%4;
   } else {
      //1-epsilon (do greedy)
      return map->getMaxAction(pos);
   }
}

void Agent::act(int move){
   switch (move) {
      case 0:
         this->move('w');
         break;
      case 1:
         this->move('a');
         break;
      case 2:
         this->move('s');
         break;
      case 3:
         this->move('d');
      default:
         break;
   }
}

bool Agent::react(int action) {
   //call for updating of the Q table
   return map->updateQTable(pos, action);
}

void Agent::runCycle() {
   //decide what to do
   int selectedAction = this->decide();
   //react to move
   bool found = this->react(selectedAction);
   //move
   this->act(selectedAction);
   //if goal is found, start over again
   if (found) {
      this->reset();
      this->testE(); //ensure successful reset
   }
}

void Agent::reset() {
   std::cout <<"Found in " << moves << " moves!" << std::endl;
   std::ofstream fout;
   //check if moves are near optimal
   if (moves < map->getOptimalNumOfMoves(startPos)) {
      nearOptimal = true;
   }
   //data capture shenanigans
   fout.open("moves.txt", std::ofstream::out | std::ofstream::app);
   fout << moves << std::endl;
   fout.close();
   //reset number of moves, and move agent back to start
   moves = 0;
   pos = startPos;
}

void Agent::displayGrid() {
   //update the display with the agent and goal positions
   map->displayGrid(pos.x, pos.y);
}

void Agent::testE() {
   //check that agent is at start and moves are zero
   assert(pos == startPos);
   assert(moves == 0);
}

void Agent::testF() {
   //check that optimal path has been found
   assert(nearOptimal == true);
}

void Agent::setEpsilon(double epsIn) {
   epsilon = epsIn;
}

void Agent::testG() {
   //decide what to do
   int selectedAction = map->getMaxActionG(pos);
   //react to move
   bool found = this->react(selectedAction);
   //move
   this->act(selectedAction);
   //if goal is found, start over again
   if (found) {
      this->reset();
      this->testE(); //ensure successful reset
   }
}
