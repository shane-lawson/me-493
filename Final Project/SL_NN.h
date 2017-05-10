//
//  SL_NN.h
//  ME 493
//
//  Created by Shane Lawson on 5/10/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

//starting with a 3 layer network, 1 input, 1 hidden, and 1 output, might get fancier down the road, but this is a start.
//and also very little absraction for the time being

#ifndef SL_NN_h
#define SL_NN_h

#include <vector>

class neural_network {
   int totalNodes;
   int inputLayerNodes;
   int hiddenLayerNodes;
   int outputLayerNodes;
   int totalWeights;
   std::vector<double> inputMinimums;
   std::vector<double> inputMaximums;
   std::vector<double> outputMinimums;
   std::vector<double> outputMaximums;
   std::vector<double> weights;
   std::vector<double> inputs;
   std::vector<double> outputs;
   
   double normalize(const double& value,const double& min,const double& max);
   double denormalize(const double& value,const double& min,const double& max);
   double sigmoid(double x);
public:
   void setup(int input,int hidden,int output);
   int get_number_of_weights()const;
   void set_in_min_max(double min,double max);
   void set_out_min_max(double min,double max);
   void set_weights(std::vector<double> weightsIn);
   void set_vector_input(std::vector<double> inputsIn);
   void execute(bool hyperbolicTangent);
   double get_output(int index);
};

#endif /* SL_NN_h */
