#ifndef SPECIES_MOCLAN_H_
#define SPECIES_MOCLAN_H_


#include "species/humanoid.h"

class Moclan: public Humanoid
{
    private:
    bool _isEgg;


    public:

    Moclan(double, double);
    bool isEgg();
    Moclan layEgg();
    void hatch();

};

#endif //SPECIES_MOCLAN_H_