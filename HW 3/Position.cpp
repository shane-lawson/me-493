//
//  Position.cpp
//  ME 493
//
//  Created by Shane Lawson on 2/24/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include "Position.h"

Position::Position(int xCoord, int yCoord) {
   //set specified x and y coordinates
   x = xCoord;
   y = yCoord;
}

bool Position::operator==(const Position &pos) const{
   if (this->x == pos.x) {
      if (this->y == pos.y) {
         return true;
      }
   }
   return false;
}
