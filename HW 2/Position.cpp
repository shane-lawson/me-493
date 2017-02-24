//
//  Position.cpp
//  ME 493
//
//  Created by Shane Lawson on 2/24/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include "Position.h"

Position::Position(int x, int y) {
   setPosition(x, y);
}

void Position::setPosition(int x, int y) {
   xCoord = x;
   yCoord = y;
}

void Position::SetPosition(char axis, int input) {
   if (axis == 'x') {
      xCoord = input;
   } else {
      yCoord = input;
   }
}
