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
   int rows;
   int columns;
   
   void getRowsAndColsFromUser(int&,int&);
public:
   Grid();
   int getNumRows();
   int getNumCols();
};

#endif /* Grid_h */
