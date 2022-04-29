#pragma once

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
