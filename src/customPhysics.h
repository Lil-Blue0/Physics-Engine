//
// Created by jacob on 9/9/24.
//

#ifndef CUSTOMPHYSICS_H
#define CUSTOMPHYSICS_H



class customPhysics {

private:
    const double mass;
    double accelertation;
    double velocity;
    const double gravity = 9.81;
    double force;


public:
    double getMass() const;
    static void setMass(double mass);
    double accelerationGravity();
    void applyForce(double force);
    double gravityForce();

};



#endif //CUSTOMPHYSICS_H
