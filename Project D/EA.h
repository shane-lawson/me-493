//
//  EA.h
//  ME 493
//
//  Created by Shane Lawson on 4/27/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include "Weights.h"
#include "LY_NN.h"
#include <vector>

#ifndef EA_h
#define EA_h
class EA {
   std::vector<Weights> population;
   std::vector<double> fitnesses;
   neural_network NN;
   
public:
   EA();
   void evaluate();
   void downselect();
   void replicate();
};

#endif /* EA_h */
