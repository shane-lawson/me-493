//
//  Weights.h
//  ME 493
//
//  Created by Shane Lawson on 5/1/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include <vector>

#ifndef Weights_h
#define Weights_h
class Weights {
   std::vector<double> weights;
   
public:
   Weights();
   void mutate(double);
};

#endif /* Weights_h */
