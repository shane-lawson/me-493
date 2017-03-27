//
//  Path.h
//  ME 493
//
//  Created by Shane Lawson on 3/23/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#ifndef Path_h
#define Path_h

#include "World.h"
#include <vector>

//represents a "policy" containing the order which it will visit each city, meets LR_3
class Path {
   std::vector<int> cities;
   double totalDistance;
   World* world;
   
public:
   Path();
   double calcPathDistance();
   void mutate(int);                   //mutates policy by swapping orders of cities visited, meets LR_4
   void ensureNoDuplicateCities();  //asserting test function, meets LR_6
};

#endif /* Path_h */
