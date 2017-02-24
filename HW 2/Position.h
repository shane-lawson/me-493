//
//  Position.h
//  ME 493
//
//  Created by Shane Lawson on 2/24/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#ifndef Position_h
#define Position_h

class Position {
   int xCoord;
   int yCoord;
   
public:
   Position(int x=-1, int y=-1);
   void setPosition(int,int);
   void SetPosition(char,int);
};

#endif /* Postition_h */
