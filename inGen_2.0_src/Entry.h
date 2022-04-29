#pragma once


#include <iostream>
#include <string.h>
#include "ElectricalSystem.h"

using namespace std;

class Entry
{
    ElectricalSystem eSys;
    bool open;      // off 0x21
    bool locked;      // off 0x22

    public:

    // def Constr
    Entry();
    // check if open
    bool isOpen();
    // if locked, unlock. If unlocked, then lock it.
    void toggle_lock();
    // unlock it
    void unlock();
};
