//
//  Path.cpp
//  ME 493
//
//  Created by Shane Lawson on 3/23/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include "Path.h"
#include <assert.h>
#include <random>
#include <ctime>

#include <iostream>

Path::Path(World* in) {
   //seed random numbers only once when class is first initialized
   static bool seeded = false;
   if(!seeded){
      srand((int)time(NULL));
      seeded = true;
   }

   world = in;
   
   //initialize with randomly selected path
   int numCities = world->numCities();
   int nextCity;
   bool found;

   while (cities.size() < numCities) {
      found = false;
      nextCity = rand()%numCities;
      //search for city already in path
      for (int i = 0; i < cities.size(); i++) {
         if (cities.at(i) == nextCity) {
            found = true;
         }
      }
      //if not already in path, add to end
      if (!found) {
         cities.push_back(nextCity);
      }
   }
}

double Path::calcPathDistance() { //calculates total distance, meets LR_8
   double distance = 0.0;
   for (int i = 1; i < cities.size(); i++) {
      distance = distance + world->calcDistance(cities.at(i-1), cities.at(i));
   }
   return distance;
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

void Path::showPath() {
   for (int i = 0; i < cities.size(); i++) {
      std::cout << cities.at(i) << std::endl;
   }
}
