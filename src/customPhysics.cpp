//
// Created by jacob on 9/9/24.
//

#include "customPhysics.h"


customPhysicsObject::customPhysicsObject(double mass, double velocity)
    : mass_(mass), velocity_(velocity), forceGravity_(gravity_ * mass) {
    // Initialization is handled by the initializer list.
}
double customPhysicsObject::getvelocity() {
    return velocity_;
}


double customPhysicsObject::getGravity() {
    return gravity_;
}

