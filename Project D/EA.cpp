//
//  EA.cpp
//  ME 493
//
//  Created by Shane Lawson on 4/27/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include "EA.h"
#include "Simulator.h"
#include <random>

EA::EA() {
   //seed random numbers only once when class is first initialized
   static bool seeded = false;
   if(!seeded){
      srand((int)time(NULL));
      seeded = true;
   }
   
   for (int i = 0; i < 50; i++) {
      Weights newWeight;
      population.push_back(newWeight);
   }

   NN.setup(2, 5, 1);
   NN.set_in_min_max(-M_PI, M_PI); //theta
   NN.set_in_min_max(-17.0, 17.0); //omega
   NN.set_out_min_max(-15.0, 15.0); //u
}

void EA::evaluate() {
   for (int i = 0; i < population.size(); i++) {
      Simulator sim;
      double fitness = 0.0;
      
      while (!(fitness > 0.0)) {
         std::vector<double> inputs;
         inputs.push_back(sim.getTheta());
         inputs.push_back(sim.getOmega());
         NN.set_vector_input(inputs);
         NN.set_weights(population.at(i).getWeights(), true);
         NN.execute();
         sim.setInput(NN.get_output(0));
         sim.step();
      }
      fitnesses.at(i) = fitness;
   }
}

void EA::downselect() {
   std::vector<Weights> nextGen;
   int minPosition = 0;
   int minFitness = 99999999.9;
   
   //save best policy for eventual optimal policy
   for (int i = 0; i < fitnesses.size(); i++) {
      if (fitnesses.at(i) < minFitness) {
         minFitness = fitnesses.at(i);
         minPosition = i;
      }
   }
   
   //binary tournament for rest
   for (int i = 0; i < population.size()/2 -1; i++) {
      int first = rand()%100;
      int second = rand()%100;
      
      if (fitnesses.at(first) < fitnesses.at(second)) {
         nextGen.push_back(population.at(first));
      } else {
         nextGen.push_back(population.at(second));
      }
   }
   
   population.clear();
   population = nextGen;
}

void EA::replicate() {
   for (int i = 0; i < population.size(); i++) {
      Weights mutatedWeights = population.at(i);
      mutatedWeights.mutate(0.2);
      
      population.push_back(mutatedWeights);
   }
}
