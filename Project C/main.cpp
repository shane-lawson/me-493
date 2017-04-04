//
//  main.cpp
//  Project C
//
//  Created by Shane Lawson on 3/23/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include <iostream>
#include "World.h"
#include "Path.h"
#include <vector>
#include <cmath>

#include <fstream>

using namespace std;

//main function serves the purpose of an "agent" which controls decisions, meets LR_2
int main() {
   cout << "Magical unicorns and butterflies." << endl;
   
   ofstream fout;
   
   World newWorld(25);
   vector<Path> paths;
   vector<Path> nextGen;
   
   int numCities = newWorld.getNumCities();
   
   int oddCityOffset = 0;
   if (numCities%2 == 1) {
      oddCityOffset = 1;
   }
   
   for (int i = 0; i < numCities/2 + oddCityOffset; i++) { //initializes a population of policies, meets MR_1
      Path tempPath(&newWorld);
      paths.push_back(tempPath);
   }
   
   newWorld.showCities();
   
   for (int i = 0; i < numCities/2 + oddCityOffset; i++) {
      cout << paths.at(i).calcPathDistance() << endl;
   }
   
   for (int j = 0; j < 10*numCities; j++) { //repeats for each generation

      for (int i = 0; i < numCities/2; i++) { //slightly mutates to repopulate, meets MR_5
         Path tempPath = paths.at(i);
         tempPath.mutate(numCities/10);
         paths.push_back(tempPath);
      }

      for (int i = 0; i < numCities/2 + oddCityOffset; i++) { //probabalistically downselects using binary tournament, meets MR_4
         int first = rand()%numCities;
         int second = rand()%numCities;
         
         //fitness in this case is lowest distance travelled, thus calculating distance evaluates fitness. This is only done on an as needed basis, meets MR_2
         //program can set the fitness of all policies, however this is not required to run properly. Fitness is calculated on an as needed basis, meets MR_3
         if (paths.at(first).calcPathDistance() < paths.at(second).calcPathDistance()) {
            nextGen.push_back(paths.at(first));
         } else {
            nextGen.push_back(paths.at(second));
         }
      }

      paths.clear();

      paths = nextGen;

      nextGen.clear();
      
      fout.open("paths.txt", std::ofstream::out | std::ofstream::app);
      for (int i = 0; i < numCities/2 + oddCityOffset; i++) {
         fout << paths.at(i).calcPathDistance() << "\t";
      }
      fout << endl;
      fout.close();
      
   }
   
   cout << "------------" << endl;
   
   for (int i = 0; i < numCities/2 + oddCityOffset; i++) {
      cout << paths.at(i).calcPathDistance() << endl;
   }
   
   return 0;
}
