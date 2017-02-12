//
//  MAB.cpp
//  ME 493
//
//  Created by Shane Lawson on 2/8/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include "MAB.h"

MAB::MAB(int in) {
   for (int i = 0; i < in; i++) {
      Arm newArm;
      arms.push_back(newArm);
   }
}

double MAB::pullArm(int i) {
   return arms.at(i).getReward();
}

int MAB::getNumArms() {
   return (int)arms.size();
}

double MAB::getArmMean(int arm) const{
   return arms.at(arm).getMean();
}
