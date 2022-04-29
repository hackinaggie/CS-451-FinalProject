#include "Entry.h"


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

void Entry::unlock()
{
    char readIn[5];
    bool electricOn{false};
    int cmpHowdy{0};

    cout << "Enter passcode: ";
    fgets(readIn, 10, stdin);

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
