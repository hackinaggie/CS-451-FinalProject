#pragma once
#include "headers.h"

class ElectricalSystem
{
    string passcode;
    bool on;            // off 0x20

    public:
    // constr
    ElectricalSystem();
    // check if on
    bool isOn();
    // check if inPass matches passcode (with string::compare())
    bool passcodeCorrect(string inPass);
    // turn it off if passcodeCorrect()
    void turnOff(string inPass);

};

ElectricalSystem::ElectricalSystem()
{
    // passcode empty constr
    on = 1;
}

bool ElectricalSystem::isOn(){
    return this->on;
}

bool ElectricalSystem::passcodeCorrect(string inPass){
    return passcode.compare(inPass) == 0;
}

// inefficient
void ElectricalSystem::turnOff(string inPass)
{
    bool isOn{false};
    bool goodPass{false};

    if( this->isOn() )
    {
        isOn = true;
        if( this->passcodeCorrect(inPass) )
        {
            goodPass = true;
        }
    }

    if( isOn ){
        if( goodPass )
        {
            this->on = false;
        }
    }
}
