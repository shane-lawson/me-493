//
//  World.cpp
//  ME 493
//
//  Created by Shane Lawson on 3/25/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include "World.h"
#include <cmath>


double World::calcDistance(City cityLeft, City cityRight) {
   return sqrt( (cityLeft.xPos-cityRight.xPos)*(cityLeft.xPos-cityRight.xPos) + (cityLeft.yPos-cityRight.yPos)*(cityLeft.yPos-cityRight.yPos) );
}
