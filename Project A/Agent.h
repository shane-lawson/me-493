//
//  Agent.h
//  ME 493
//
//  Created by Shane Lawson on 2/9/17.
//  Copyright © 2017 Shane Lawson. All rights reserved.
//

#ifndef Agent_h
#define Agent_h
class Agent {
   double alpha;
   double epsilon;
   
   Agent();
   void sense();
   void decide();
   void act();
   void react();
};

#endif /* Agent_h */
