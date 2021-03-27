
#ifndef SPECIES_KAYLON_H_
#define SPECIES_KAYLON_H_

#include "species/humanoid.h"

class Kaylon : public Humanoid{
     private:
    bool _isFiring;


    public:
    Kaylon(double, double);
    bool isFiring();
    void startFiring();
    void stopFiring();
    
};

#endif //SPECIES_KAYLON_H_