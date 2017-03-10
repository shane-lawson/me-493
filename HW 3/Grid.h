//
//  Grid.h
//  ME 493
//
//  Created by Shane Lawson on 2/24/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#ifndef Grid_h
#define Grid_h

#include "Goal.h"
#include "Position.h"
#include <vector>

class Grid {
   int rows;                                             //number of rows
   int columns;                                          //number of columns
   Goal endGoal;                                         //goal
   std::vector<std::vector<std::vector<double>>> qTable; //nice, 3D Q table
   double alpha = 0.1;                                   //alpha for reward shenanigans
   double gamma = 0.9;                                   //gamma for Q value shenanigans
   int goalFound = 0;                                    //number of times goal is found
   Position previousState;
   
   void getRowsAndColsFromUser(int&,int&);               //prompts user for size of grid and updates values by reference
   double getMaxValue(std::vector<double>*);             //returns max value from vector in this case, action possibilities
   void populateQTable();                                //fill Q table with initial values
public:
   Grid();                                               //constructs a grid
   int getNumRows();                                     //returns the number of rows contained in the grid
   int getNumCols();                                     //returns the numer of columns contained in the grid
   void displayGrid(int,int);                            //outputs the grid, agent position, and goal position to the console
   Position getGoalPosition();                           //returns goal position for hard coded rule of thumb navigation
   int getReward(Position);                              //returns the reward for a given position
   bool updateQTable(Position,int);                      //updates Q table value using that one equation
   int getMaxAction(Position);                           //gets the index (direction) of the best action
   int getMaxActionG(Position);
   void testD();                                         //asserts that all q values are less than max reward
   int getOptimalNumOfMoves(Position);                   //calculations optimal number of moves given a starting position
   void resetQTable();                                   //clears Q table and reinitializes it
   int getNumTimesFound();
};

#endif /* Grid_h */
