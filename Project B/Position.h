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
   int x;                                  //x-coordinate
   int y;                                  //y-coordinate
   
public:
   Position(int xCoord=-1, int yCoord=-1); //constructs a specified position
   bool operator==(const Position&) const;         //overload ==
   friend class Agent;                     //friend allows the agent to interact with this directly without making data members public
};

#endif /* Postition_h */
