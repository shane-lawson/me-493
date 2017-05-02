//
//  Simulator.h
//  ME 493
//
//  Created by Shane Lawson on 4/27/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#ifndef Simulator_h
#define Simulator_h
class Simulator {
   //most of these variable are used to describe the agent's state at any given time, therefore meeting MR_3
   double x;
   double y;
   double theta;
   double omega;
   double u;
   double goalTop;
   double goalBottom;
   double xPosGoal;
   double xPrev;
   double yPrev;
   int steps;
   const double v = 3.0;
   const double dt = 0.2;
   const double T = 5.0;
   
public:
   Simulator();
   void calc_pos();
   void calc_theta();
   void calc_omega();
   double step();
   void setInput(double);
   double getTheta() const;
   double getOmega() const;
};

#endif /* Simulator_h */
