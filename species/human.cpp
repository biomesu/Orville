/**
* Human Implement
*
* Copyright (c) 2021, Steven Lopez.
*/



#include "species/human.h"

Human::Human(bool m, double h, double w) : Humanoid(h, w), _isMale(m) {
    
}
bool Human::isMale()
{
    return _isMale;
}