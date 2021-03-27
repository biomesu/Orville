

#include "species/kaylon.h"

Kaylon::Kaylon(double h, double w): Humanoid(h,w), _isFiring(false){

}

bool Kaylon::isFiring(){
    return _isFiring;
}

void Kaylon::startFiring(){
    _isFiring = true;
}

void Kaylon::stopFiring(){
    _isFiring = false;
}


