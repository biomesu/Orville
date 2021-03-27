/**
* Eevak Implement
*
* Copyright (c) 2021, Steven Lopez.
*/

#include "species/eevak.h"

Eevak::Eevak() : _isRunning(false){
}

bool Eevak::isRunning(){
    return _isRunning;
}

void Eevak::run(){
    _isRunning = true;
}

void Eevak::stop(){
    _isRunning = false;
}
