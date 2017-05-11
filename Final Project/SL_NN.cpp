//
//  SL_NN.cpp
//  ME 493
//
//  Created by Shane Lawson on 5/10/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include "SL_NN.h"
#include <cmath>

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

void neural_network::set_weights(std::vector<double> weightsIn, bool flag) {
   weights.clear();
   weights = weightsIn;
}

void neural_network::set_vector_input(std::vector<double> inputsIn) {
   for (int i = 0; i < inputsIn.size(); i++) {
      inputs.push_back(normalize(inputsIn.at(i), inputMinimums.at(i), inputMaximums.at(i)));
   }
}

void neural_network::execute(bool hyperbolicTangent) {
   outputs.clear();
   
   std::vector<double> hiddenValues;
   double sumConnections;
   int weightIndexOffset = 0;
   
   //process connections into hidden layer
   for (int i = 0; i < hiddenLayerNodes-1; i++) { //-1 to not sum weights into bias node
      sumConnections = 0.0;
      for (int j = 0; j < inputLayerNodes; j++) {
         if (j < inputLayerNodes-1) {
            sumConnections += weights.at(weightIndexOffset+j)*inputs.at(j);
         } else {
         sumConnections += weights.at(weightIndexOffset+j)*1;//bias node
         }
      }
      if(hyperbolicTangent) {
         hiddenValues.push_back(tanh(sumConnections));
      } else {
         hiddenValues.push_back(sigmoid(sumConnections));
      }
      weightIndexOffset += inputLayerNodes;
   }
   
   //process connections into output layer
   for (int j = 0; j < outputLayerNodes; j++) {
      sumConnections = 0.0;
      for (int k = 0; k < hiddenLayerNodes; k++) {
         if (k < hiddenLayerNodes-1) {
            sumConnections += weights.at(weightIndexOffset+(j*hiddenLayerNodes)+k)*hiddenValues.at(k);
         } else {
            sumConnections += weights.at(weightIndexOffset+(j*hiddenLayerNodes)+k)*1; //bias node
         }
      }
      if(hyperbolicTangent) {
         outputs.push_back(denormalize(tanh(sumConnections),outputMinimums.at(j), outputMaximums.at(j)));
      } else {
         outputs.push_back(denormalize(sigmoid(sumConnections),outputMinimums.at(j), outputMaximums.at(j)));
      }
   }
  
   inputs.clear();
}

void neural_network::execute() {
   execute(false);
}

double neural_network::get_output(int index) {
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
