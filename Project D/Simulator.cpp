//
//  Simulator.cpp
//  ME 493
//
//  Created by Shane Lawson on 4/27/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include "Simulator.h"
#include <cmath>

#include <iostream>

Simulator::Simulator() {
   x = 1.0;
   y = 1.0;
   theta = 0.0;
   omega = 0.0;
   u = 0.0;
   goalTop = 80.0;
   goalBottom = 70.0;
   xPosGoal = 75.0;
   steps = 0;
}

void Simulator::calc_pos() {
   xPrev = x;
   yPrev = y;
   x = x + sin(theta)*dt;
   y = y + cos(theta)*dt;
}

void Simulator::calc_theta() {
   theta = theta + omega*dt;
}

void Simulator::calc_omega() {
   omega = omega + (u-omega)*(dt/T);
}

double Simulator::step() {
   bool found = false;
   bool left = false;
   bool inLoop = false;
   calc_omega();
   calc_theta();
   calc_pos();
   
   std::cout << "X: " << x << "\t";
   std::cout << "Y: " << y << "\t";
   std::cout << "Theta: " << theta << "\t";
   std::cout << "Omega: " << omega << "\t";
   std::cout << "u: " << u << "\t";
   std::cout << std::endl;
   
   //check if last step to current step crosses from a square immediately on one side of goal to square on opposite side of goal
   if (yPrev < goalTop && yPrev > goalBottom) {
      if (xPrev < xPosGoal && xPrev > xPosGoal-10) {
         //in left section
         if (x > xPosGoal && x < xPosGoal+10) {
            if (y < goalTop && y > goalBottom) {
               found = true;
            }
         }
      }
      if (xPrev > xPosGoal && xPrev < xPosGoal+10) {
         //in right section
         if(x < xPosGoal && x > xPosGoal-10) {
            if (y < goalTop && y > goalBottom) {
               found = true;
            }
         }
      }
   }
   
   //check if left boundary
   if (x > 100) {
      left = true;
   }
   if (y > 100) {
      left = true;
   }
   if (y < 0) {
      left = true;
   }
   if (x < 0) {
      left = true;
   }
   
   if (steps == 10000) {
      inLoop = true;
   }
   steps++;
   
   if (found || inLoop) {
      return steps;
   } else if (left) {
      return steps + 5000;
   }
   return 0.0;
}

void Simulator::setInput(double input) {
   u = input;
}

double Simulator::getOmega() const{
   return omega;
}

double Simulator::getTheta() const{
   return theta;
}
