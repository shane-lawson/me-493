//
//  main.cpp
//  Final Project
//
//  Created by Shane Lawson on 5/10/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include <iostream>
#include "SL_NN.h"
using namespace std;

int main() {
   cout << "Magical butterflies and unicorns." << endl;
   
   neural_network NN;
   NN.setup(2,2,2);
//   cout << NN.get_number_of_weights() << endl;
   NN.set_in_min_max(-1.0,15.0);
   NN.set_in_min_max(-1.0,15.0);
   NN.set_out_min_max(0.0,5.0);
   NN.set_out_min_max(0.0,5.0);
   vector<double> inputs;
   inputs.push_back(12.0);
   inputs.push_back(6.0);
   NN.set_vector_input(inputs);
   vector<double> weights;
   for (int i = 0; i < NN.get_number_of_weights(); i++) {
      weights.push_back(0.5);
   }
   NN.set_weights(weights,true);
   NN.execute();
//   cout << NN.get_output(0) << endl;
   
   return 0;
}
