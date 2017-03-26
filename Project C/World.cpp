//
//  World.cpp
//  ME 493
//
//  Created by Shane Lawson on 3/25/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include "World.h"
#include <cmath>

#include <iostream>

World::World() {
   for (int i = 0; i < 100; i++) {
      City tempCity;
      cities.push_back(tempCity);
   }
}

double World::calcDistance(int left, int right) { //mmets LR_7
   City cityLeft = cities.at(left);
   City cityRight = cities.at(right);
   
   return sqrt( (cityLeft.xPos-cityRight.xPos)*(cityLeft.xPos-cityRight.xPos) + (cityLeft.yPos-cityRight.yPos)*(cityLeft.yPos-cityRight.yPos) );
}

void World::showCities() {
   for (int i = 0; i<100; i++) {
      std::cout << cities.at(i).xPos << "\t" << cities.at(i).yPos << std::endl;
   }
}
