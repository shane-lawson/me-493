//
//  EA.h
//  ME 493
//
//  Created by Shane Lawson on 4/27/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include "Weights.h"
#include <vector>

#ifndef EA_h
#define EA_h
class EA {
   std::vector<Weights> population;
   
public:
   EA();
   void evaluate();
   void downselect(std::vector<double>);
   void replicate();
};

#endif /* EA_h */
