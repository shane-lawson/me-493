//
//  Grid.cpp
//  ME 493
//
//  Created by Shane Lawson on 2/24/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include "Grid.h"
#include <iostream>

Grid::Grid() {
   getRowsAndColsFromUser(rows,columns);
}

void Grid::getRowsAndColsFromUser(int& row, int& column) {
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
