//
//  main.cpp
//  Project D
//
//  Created by Shane Lawson on 4/27/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#include "EA.h"
#include "Simulator.h"
#include <iostream>
using namespace std;

//I have been plagued by linker errors coming from the neural network header "LY_NN.h"
//I include the header for my EA class "EA.h" in main, because that is what I use here. In my header for the EA class I include "LY_NN.h" since I use the neural network in that class.
//When compilling I recieve many linker errors, as many as 42, and as few as 24, that are duplicate symbols in main.o and EA.o. I think that if this header was properly written, (or perhaps I don't know how to use headers?), I would not be getting duplicate symbol linker errors because everything would only be defined once, even if included more than once.
//I have tried eliminating my class headers and implementations, and jamming everything in one file, but this doesn't appear to work either.
//As a result, I have been unable to actually run my code until I fix this issue. Individual parts of the program were working as much as I tested previously, and I am very confident that my code either works, or will work with only very minor modifications after this point. The only thing that could potentially change significantly is the fitness function, if the performance of the program is not as good as expected.
//I will continue to try to figure out the linker issues, but I've already spent many hours trying to get things to work to no avail, so I'm preparing for the scenario where I still can't get it to work. As it sands, I am unable to test HR_1, HR_2, HR_3, and HR_4, until the linker errors are resolved.

int main() {
   cout << "Magical butterflies and unicorns." << endl;
   
   EA ea;
   
   for (int i = 0; i < 1; i++) {
      ea.replicate();
      ea.evaluate();
      ea.downselect();
   }
   
//   //meets MR_1
//   Simulator sim;
//   for (int i = 0; i < 100; i++) {
//      sim.setInput(0.0);
//      sim.step();
//   }
   
   return 0;
}
