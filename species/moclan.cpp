
#include "species/moclan.h"

Moclan::Moclan(double h, double w) : Humanoid(h, w), _isEgg(false)
{

}

bool Moclan::isEgg()
{
    return _isEgg;
}

Moclan Moclan::layEgg() {
     Moclan moclanEgg(Humanoid::height(), Humanoid::weight());
     moclanEgg._isEgg = true;
     return moclanEgg;
}

void Moclan::hatch()
{
    _isEgg = false;
}