//
//  Grid.cpp
//  ME 493
//
//  Created by Shane Lawson on 2/24/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include "Grid.h"
#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <assert.h>
#include <cmath>

Grid::Grid() {
   //construct a grid
   //seed random numbers only once when class is first initialized
   static bool seeded = false;
   if(!seeded){
      srand((int)time(NULL));
      seeded = true;
   }
   
   getRowsAndColsFromUser(rows,columns);
   
   //create goal randomly within grid
   endGoal = Goal(rand()%columns,rand()%rows);
   
   //populate qTable
   std::vector<double> actions;
   std::vector<std::vector<double>> yPos;
   
   //give random, near zero values for each action
   for (int k = 0; k < 4; k++) {
      actions.push_back(0.0);
   }
   //copy actions for each y position
   for (int j = 0; j < rows; j++) {
      yPos.push_back(actions);
   }
   //copy y positions for each x positionr
   for (int i = 0; i < columns; i++) {
      qTable.push_back(yPos);
   }
}

void Grid::getRowsAndColsFromUser(int& row, int& column) {
   //clear screen
   std::cout << std::string(75,'\n');
   std::cout << "Please specify grid size." << std::endl;
   std::cout << "Rows: ";
   std::cin >> row;
   std::cout << "Columns: ";
   std::cin >> column;
}

int Grid::getNumCols() {
   return columns;
}

int Grid::getNumRows() {
   return rows;
}

void Grid::displayGrid(int xAgent, int yAgent) {
   for (int i = -1; i < rows; i++) {
      for (int j = -1; j < columns; j++) {
         if (j==-1 || i==-1) {
            //if at a wall position, show wall
            std::cout << "#";
         } else if (j==xAgent && i==yAgent) {
            //if at agent position, show agent
            std::cout << "A";
         } else if (j==endGoal.getPosition().x && i==endGoal.getPosition().y) {
            //if at goal position, show goal
            std::cout << "G";
         } else {
            //everywhere else, show empty space
            std::cout << " ";
         }
      }
      //finish right wall
      std::cout << "#" << std::endl;
   }
   //finish bottom wall
   for (int i = -1; i <= columns; i++) {
      std::cout << "#";
   }
   std::cout << std::endl << "Found: " << goalFound << "\t";
}

Position Grid::getGoalPosition() {
   return endGoal.getPosition();
}

int Grid::getReward(Position pos) {
   if (pos == endGoal.getPosition()) {
      goalFound++;
      return 100;
   } else {
      return 0;
   }
}

bool Grid::updateQTable(Position state, int action) {
   Position nextState = state;
   switch (action) {
      case 0:
         if (nextState.y-1 >= 0) {
            nextState.y--;
         }
         break;
      case 1:
         if (nextState.x-1 >= 0) {
            nextState.x--;
         }
         break;
      case 2:
         if (nextState.y+1 < rows) {
            nextState.y++;
         }
         break;
      case 3:
         if (nextState.x+1 < columns) {
            nextState.x++;
         }
      default:
         break;
   }
   qTable.at(state.x).at(state.y).at(action) = qTable.at(state.x).at(state.y).at(action) + alpha*(this->getReward(nextState) +gamma*this->getMaxValue(&qTable.at(nextState.x).at(nextState.y)) -qTable.at(state.x).at(state.y).at(action));
   
   //run test D to make sure no q values are greater than the goal reward.
   this->testD();
   
   if (nextState == endGoal.getPosition()) {
      return true;
   } else {
      return false;
   }
}

double Grid::getMaxValue(std::vector<double>* pQTable) {
   double maxValue = 0.0;
   for (int i = 0; i < pQTable->size(); i++) {
      if (pQTable->at(i) > maxValue) {
         maxValue = pQTable->at(i);
      }
   }
   return maxValue;
}

int Grid::getMaxAction(Position pos) {
   double maxValue = -99999;
   int maxAction = -1;
   for (int i = 0; i < 4; i++) {
      if (qTable.at(pos.x).at(pos.y).at(i) > maxValue) {
         maxValue = qTable.at(pos.x).at(pos.y).at(i);
         maxAction = i;
      }
   }

   //solve issue with agent sticking to wall because all actions have equal values, and "max" is action into wall, when all actions are equal, a random is chosen
   int same = 0;
   for (int i = 0; i < 4; i++) {
      if (qTable.at(pos.x).at(pos.y).at(i) == maxValue) {
         same++;
      }
   }
   if (same == 4) {
      return rand()%4;
   }
   //end sticky bug solution
   
   return maxAction;
}

void Grid::testD() {
   //visit every spot in q table and assert that the value is less than max reward
   for (int i = 0; i < qTable.size(); i++) {
      for (int j = 0; j < qTable.at(i).size(); j++) {
         for (int k = 0; k < qTable.at(i).at(j).size(); k++) {
            assert(qTable.at(i).at(j).at(k) < 100);
         }
      }
   }
}

int Grid::getOptimalNumOfMoves(Position pos) {
   //return sum of x direction moves and y direction moves for optimal path
   //need some sort of buffer/threshold +2?
   return (abs(pos.x-endGoal.getPosition().x) + abs(pos.y-endGoal.getPosition().y))+2;
}
