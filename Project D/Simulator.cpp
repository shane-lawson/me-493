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
}

void Simulator::calc_pos() {
   x = x + sin(theta)*dt;
   y = y + cos(theta)*dt;
}

void Simulator::calc_theta() {
   theta = theta + omega*dt;
}

void Simulator::calc_omega() {
   omega = omega + (u-omega)*(dt/T);
}

void Simulator::step() {
   calc_omega();
   calc_theta();
   calc_pos();
   
   std::cout << "X: " << x << "\t";
   std::cout << "Y: " << y << "\t";
   std::cout << "Theta: " << theta << "\t";
   std::cout << "Omega: " << omega << "\t";
   std::cout << "u: " << u << "\t";
   std::cout << std::endl;
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
