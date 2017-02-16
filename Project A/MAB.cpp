//
//  MAB.cpp
//  ME 493
//
//  Created by Shane Lawson on 2/8/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include "MAB.h"

MAB::MAB(const int in) {
   //create new arm the specified number of times and put it in the arms vector
   for (int i = 0; i < in; i++) {
      Arm newArm;
      arms.push_back(newArm);
   }
}

double MAB::pullArm(const int i) {
   return arms.at(i).getReward();
}

int MAB::getNumArms() const{
   return (int)arms.size();
}

double MAB::getArmMean(const int arm) const{
   return arms.at(arm).getMean();
}
