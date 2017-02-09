//
//  MAB.h
//  ME 493
//
//  Created by Shane Lawson on 2/8/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#ifndef MAB_h
#define MAB_h

#include "Arm.h"
#include <vector>

class MAB {
   std::vector<Arm> arms;
  
public:
   MAB(int i = 1);
   double pullArm(int);
};

#endif /* MAB_h */
