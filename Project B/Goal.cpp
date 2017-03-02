//
//  Goal.cpp
//  ME 493
//
//  Created by Shane Lawson on 2/26/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include "Goal.h"

Goal::Goal(int xCoord,int yCoord) {
   //create specified position
   pos = Position(xCoord,yCoord);
}

Position Goal::getPosition() {
   return pos;
}
