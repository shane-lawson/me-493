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
   double mean;            //mean value for the arm
   double stdDev;          //standard deviation for the arm
   double z1;              //second box muller value, the other is returned immediately in getReward()
   bool generate;          //flag determining if box muller needs to generate new values, or use the one stored in z1

public:
   Arm();                  //constructor for an arm
   double getReward();     //returns the payout (reward) of the arms
   double getMean() const; //returns the mean of the arm
};

#endif /* Arm_h */
