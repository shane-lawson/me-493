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

Grid::Grid() {
   getRowsAndColsFromUser(rows,columns);
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

void Grid::displayGrid(int xAgent, int yAgent, int xGoal, int yGoal) {
   for (int i = -1; i < rows; i++) {
      for (int j = -1; j < columns; j++) {
         if (j==-1 || i==-1) {
            //if at a wall position, show wall
            std::cout << "#";
         } else if (j==xAgent && i==yAgent) {
            //if at agent position, show agent
            std::cout << "A";
         } else if (j==xGoal && i==yGoal) {
            //if at goal position, show goal
            std::cout << "G";
         }else {
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
