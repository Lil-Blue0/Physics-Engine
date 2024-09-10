//
// Created by jacob on 9/9/24.
//

#ifndef CUSTOMPHYSICS_H
#define CUSTOMPHYSICS_H



class customPhysicsObject {

private:
    const double mass_;
    const double gravity_ = 9.81;
    double forceGravity_;
    double velocity_;

public:

    customPhysicsObject(double mass, double velocity);
    double getvelocity();
    double getGravity();

};



#endif //CUSTOMPHYSICS_H
