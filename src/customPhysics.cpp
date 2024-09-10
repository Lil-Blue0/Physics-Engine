//
// Created by jacob on 9/9/24.
//

#include "customPhysics.h"


double customPhysics::getMass() const {
    return mass;
}

void customPhysics::setMass(double mass) {
    mass = mass;
}

double customPhysics::gravityForce() {
    return gravity * mass;
}

void customPhysics::applyForce(double force) {

}




