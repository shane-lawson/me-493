//
//  City.h
//  ME 493
//
//  Created by Shane Lawson on 3/23/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#ifndef City_h
#define City_h

//representation of a city, meets LR_1
class City {
   double xPos;
   double yPos;
   
public:
   City();
   void setPosition(double,double);
   
   friend class World;
};

#endif /* City_h */
