#pragma once
#include "headers.h"

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

Entry::Entry()
{
    //eSys
    open = false;
    locked = true;
}

bool Entry::isOpen()
{
    return open;
}

// TODO: Vuln: if input doesn't = howdy, it locks it anyway, no check against ElectSys pass
void Entry::lock()
{
    char readIn[5];
    bool electricOn{false};
    int cmpHowdy{0};

    cout << "Enter passcode: ";
    fgets(readIn, 10, stdin);       // TODO: mention that readIn size 5, reads up to 10

    cmpHowdy = strcmp(readIn, "howdy");

    // they input howdy
    if(cmpHowdy == 0)
    {
        cout << "Passoword Incorrect" << endl;
    }
    else{
        electricOn = eSys.isOn();
        if( electricOn )
        {
            this->locked = true;
        }
    }
}

// TODO: Vuln: same as above
// TODO: Ineff: same as above, reused code
void Entry::unlock()
{
    char readIn[5];
    bool electricOn{false};
    int cmpHowdy{0};

    cout << "Enter passcode: ";
    fgets(readIn, 10, stdin);       // TODO: mention that readIn size 5, reads up to 10

    cmpHowdy = strcmp(readIn, "howdy");

    // they input howdy
    if(cmpHowdy == 0)
    {
        cout << "Passoword Incorrect" << endl;
    }
    else{
        electricOn = eSys.isOn();
        if( electricOn )
        {
            this->locked = false;
        }
    }
}
