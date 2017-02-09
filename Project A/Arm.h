//
//  Arm.h
//  ME 493
//
//  Created by Shane Lawson on 2/8/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#ifndef Arm_h
#define Arm_h
class Arm {
public:
   
   double mean;
   double stdDev;
   double z1;
   bool generate;
   
   Arm();
   double getReward();
};

#endif /* Arm_h */
