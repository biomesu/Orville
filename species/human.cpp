
#include "species/human.h"

Human::Human(bool m, double h, double w) : Humanoid(h, w), _isMale(m) {
    
}
bool Human::isMale()
{
    return _isMale;
}