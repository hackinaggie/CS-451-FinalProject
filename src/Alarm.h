#pragma once
#include "headers.h"

class Alarm
{
    public:
    ElectricalSystem eSys;
    string msg;         // off 0x28
    string arr[5];
    // arr[0] sev_weather; // off 0x48
    // arr[1] fire_alarm;  // off 0x68
    // arr[2] breach;      // off 0x88
    // arr[3] sys_fail;    // off 0xa8
    // arr[4] escaped;     // off 0xc8

    //initial analysis indicates this inits msg to be one of the other member strings at offset INPUT
    Alarm(int input);

    // contacts a string held in a register to the INPUT and sets msg to that
    Alarm(string input);

    // prints the msg member
    void printMessage();

    // sets msg to the same thing as in the Alarm(string) constructor
    void setMessage(string input);
};

Alarm::Alarm(int input){
    // eSys default constr
    arr[0] = "SEVERE WEATHER";
    arr[1] = "THE FIRE ALARM HAS BEEN ACTIVATED. EVACUATE IMMEDIATELY";
    arr[2] = "BREACH DETECTED";
    arr[3] = "SYSTEM FAILURE";
    arr[4] = "ASSETS OUT OF CONTAINTMENT. THIS IS NOT A DRILL.";
    msg = arr[input];
}

Alarm::Alarm(string input)
{
    // eSys default constr
    arr[0] = "SEVERE WEATHER";
    arr[1] = "THE FIRE ALARM HAS BEEN ACTIVATED. EVACUATE IMMEDIATELY";
    arr[2] = "BREACH DETECTED";
    arr[3] = "SYSTEM FAILURE";
    arr[4] = "ASSETS OUT OF CONTAINTMENT. THIS IS NOT A DRILL.";
    msg = input;
}

void Alarm::printMessage()
{
    cout << "*******************************************************" << endl;
    cout << msg << endl;
    cout << "*******************************************************" << endl;
}

void Alarm::setMessage(string input){
    // register 34 stuff
    msg = input; // CONCAT44(in_register, input)
}