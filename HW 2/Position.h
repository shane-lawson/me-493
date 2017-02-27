//
//  Position.h
//  ME 493
//
//  Created by Shane Lawson on 2/24/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#ifndef Position_h
#define Position_h

class Agent;

class Position {
   int x;
   int y;
   
public:
   Position(int xCoord=-1, int yCoord=-1);
   friend Agent;
};

#endif /* Postition_h */
