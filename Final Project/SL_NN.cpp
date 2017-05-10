//
//  SL_NN.cpp
//  ME 493
//
//  Created by Shane Lawson on 5/10/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include "SL_NN.h"
#include <cmath>

#include <iostream>

void neural_network::setup(int input, int hidden, int output) {
   inputLayerNodes = input + 1;
   hiddenLayerNodes = hidden + 1;
   outputLayerNodes = output;
   totalNodes = inputLayerNodes + hiddenLayerNodes + outputLayerNodes;
   totalWeights = inputLayerNodes*hidden + hiddenLayerNodes*output;
}

int neural_network::get_number_of_weights() const{
   return totalWeights;
}

void neural_network::set_in_min_max(double min, double max) {
   inputMinimums.push_back(min);
   inputMaximums.push_back(max);
}

void neural_network::set_out_min_max(double min, double max) {
   outputMinimums.push_back(min);
   outputMaximums.push_back(max);
}

void neural_network::set_weights(std::vector<double> weightsIn) {
   weights = weightsIn;
}

void neural_network::set_vector_input(std::vector<double> inputsIn) {
   for (int i = 0; i < inputsIn.size(); i++) {
      inputs.push_back(normalize(inputsIn.at(i), inputMinimums.at(i), inputMaximums.at(i)));
   }
}

void neural_network::execute() {
   outputs.clear();
   
   std::vector<double> hiddenValues;
   double sumConnections;
   int weightIndexOffset = 0;
   
   //process connections into hidden layer
   for (int i = 0; i < hiddenLayerNodes-1; i++) { //-1 to not sum weights into bias node
      sumConnections = 0.0;
      for (int j = 0; j < inputLayerNodes; j++) {
         sumConnections += weights.at(weightIndexOffset+j);
//         std::cout << weightIndexOffset+j << std::endl;
      }
//      std::cout << "end loop" << std::endl;
      hiddenValues.push_back(sigmoid(sumConnections));
      weightIndexOffset += inputLayerNodes;
   }
   
   //process connections into output layer
   for (int j = 0; j < outputLayerNodes; j++) {
      sumConnections = 0.0;
      for (int k = 0; k < hiddenLayerNodes; k++) {
         sumConnections += weights.at(weightIndexOffset+(j*hiddenLayerNodes)+k);
//         std::cout << weightIndexOffset+(j*inputLayerNodes)+k << std::endl;
      }
//      std::cout << "end loop" << std::endl;
      outputs.push_back(sigmoid(sumConnections));
   }
  
   inputs.clear();
   weights.clear();
}

double neural_network::get_output(int index) {
//   std::cout << denormalize(outputs.at(index), outputMinimums.at(index), outputMaximums.at(index)) << std::endl;
   return outputs.at(index);
}

double neural_network::normalize(const double& value, const double& min, const double& max) {
   return (value-min)/(max-min);
}

double neural_network::denormalize(const double& value, const double& min, const double& max) {
   return value*(max-min) + min;
}

double neural_network::sigmoid(double x) {
   return 1 / (1 + exp(-x));
}
