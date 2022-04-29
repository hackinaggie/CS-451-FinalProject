#pragma once

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
    // lock it
    void lock();
    // unlock it
    void unlock();
};
