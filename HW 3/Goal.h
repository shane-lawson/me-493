//
//  Goal.h
//  ME 493
//
//  Created by Shane Lawson on 2/26/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#ifndef Goal_h
#define Goal_h

#include "Position.h"

class Goal {
   Position pos;                      //position of the goal
   
public:
   Goal(int xCoord=-1,int yCoord=-1); //construct a goal with a specified position
   Position getPosition();            //return the position of the goal
};

#endif /* Goal_h */
