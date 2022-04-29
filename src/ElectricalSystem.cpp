#include "headers.h"

ElectricalSystem::ElectricalSystem()
{
    // passcode empty constr
    on = true;
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
