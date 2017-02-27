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
   Position pos;
   
public:
   Goal(int xCoord=-1,int yCoord=-1);
   Position getPosition();
};

#endif /* Goal_h */
