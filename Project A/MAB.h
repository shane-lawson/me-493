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
   std::vector<Arm> arms;              //vector containing all arms of the multi armed bandit
  
public:
   MAB(const int i = 1);               //constructor for a multi armed bandit, can specify number of arms to create if not 1
   double pullArm(const int);          //calls the Arm.getReward() function for the specified arm and returns the value
   int getNumArms() const;             //returns the number of arms the multi armed bandit has
   double getArmMean(const int) const; //calls the Arm.getArmMean() function for the specified arm and returns the value
};

#endif /* MAB_h */
