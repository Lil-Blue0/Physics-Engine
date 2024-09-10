//
// Created by jacob on 9/10/2024.
//
#include "Kinematics.h"
#include"customPhysics.h"
#include <cmath>
#include <ctime>

double update_x_pos(double x, customPhysicsObject object,double dt) {


    x = (object.getvelocity() * dt) + (.5 * object.getGravity() * pow(dt, 2));

    return x;
}



