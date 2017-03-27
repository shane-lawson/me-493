//
//  Path.cpp
//  ME 493
//
//  Created by Shane Lawson on 3/23/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include "Path.h"
#include <assert.h>

Path::Path() {
   totalDistance = 0.0;
}

void Path::mutate(int swaps) { //mutates slighty, meets LR_4
   int numCities = (int)cities.size();
   int tempCity;
   for (int i = 0 ; i < swaps; i++) {
      int first = rand() % numCities;
      int second = rand() % numCities;
      tempCity = cities.at(first);
      cities.at(first) = cities.at(second);
      cities.at(second) = tempCity;
   }
}

void Path::ensureNoDuplicateCities() {
   int numFound = 0;
   int vectorSize = (int)cities.size();
   
   for (int i = 0; i < vectorSize; i++) {
      for (int j = 0; j < vectorSize; j++) {
         if (cities.at(j) == i) {
            numFound++;
         }
      }
      assert(numFound == 1); //ensure each city is only visited eactly once, meets LR_6
   }
}
