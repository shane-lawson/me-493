//
//  Grid.h
//  ME 493
//
//  Created by Shane Lawson on 2/24/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#ifndef Grid_h
#define Grid_h

class Grid {
   int rows;                               //number of rows
   int columns;                            //number of columns
   
   void getRowsAndColsFromUser(int&,int&); //prompts user for size of grid and updates values by reference
public:
   Grid();                                 //constructs a grid
   int getNumRows();                       //returns the number of rows contained in the grid
   int getNumCols();                       //returns the numer of columns contained in the grid
   void displayGrid(int,int,int,int);      //outputs the grid, agent position, and goal position to the console
};

#endif /* Grid_h */
