/**
* Gelatin Implement
*
* Copyright (c) 2021, Steven Lopez.
*/


#include "gelatin.h"
#include <cstring>


Gelatin::Gelatin(double weight) : _weight(weight)
{
    strncpy(_shape, "sphere", MAX_LEN);
}

void Gelatin::morph()
{
    strncpy(_shape, "sphere", MAX_LEN);
}

void Gelatin::morph(const char shapeName[]){
    if (strcmp(shapeName, "flat"))
    {
        strncpy(_shape, "sphere", MAX_LEN);
    }
    else
    {
        strncpy(_shape, "flat", MAX_LEN);
    }
}

char* Gelatin::shape()
{
    return const_cast<char*>(_shape);
}

double Gelatin::weight() const
{
    return _weight;
}

Gelatin Gelatin::split()
{
    Gelatin newGelatin(_weight/2);
    newGelatin.morph(_shape);

    _weight = _weight/2;
    
    return newGelatin;
}

bool Gelatin::operator!=(const Gelatin &rhs) const
{
    return (&_shape != &rhs._shape || &_weight != &rhs._weight);
}

