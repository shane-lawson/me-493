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

World::World(int i) {
   if (i == 10) {
      City tempCity;
      for (int j = 0; j < i; j++) {
         tempCity.setPosition(j, 1);
         cities.push_back(tempCity);
      }
   } else {
      for (int j = 0; j < i; j++) {
         City tempCity;
         cities.push_back(tempCity);
      }
   }
   numCities = i;
}

double World::calcDistance(int left, int right) { //meets LR_7
   City cityLeft = cities.at(left);
   City cityRight = cities.at(right);
   
   return sqrt( (cityLeft.xPos-cityRight.xPos)*(cityLeft.xPos-cityRight.xPos) + (cityLeft.yPos-cityRight.yPos)*(cityLeft.yPos-cityRight.yPos) );
}

int World::getNumCities() {
   return (int)cities.size();
}

void World::showCities() {
   for (int i = 0; i < cities.size(); i++) {
      std::cout << cities.at(i).xPos << "\t" << cities.at(i).yPos << std::endl;
   }
}
