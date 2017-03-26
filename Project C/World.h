//
//  World.h
//  ME 493
//
//  Created by Shane Lawson on 3/25/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#ifndef World_h
#define World_h

#include "City.h"
#include <vector>

class World {
   std::vector<City> cities;
   
public:
   World();
   double calcDistance(int,int); //determines the distance between two cities, meets LR_7
   
   void showCities(); //for testing
};

#endif /* World_h */
