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
}

Position Grid::getGoalPosition() {
   return endGoal.getPosition();
}

int Grid::getReward(Position pos) {
   if (pos == endGoal.getPosition()) {
      return 100;
   } else {
      return -1;
   }
}

void Grid::addAgentStartPos(Position agentPos) {
   agentStartPos = agentPos;
}
