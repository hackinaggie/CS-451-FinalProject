#include "headers.h"

Alarm::Alarm(int input)
{
    // eSys default constr
    arr[0] = "SEVERE WEATHER";
    arr[1] = "THE FIRE ALARM HAS BEEN ACTIVATED. EVACUATE IMMEDIATELY";
    arr[2] = "BREACH DETECTED";
    arr[3] = "SYSTEM FAILURE";
    arr[4] = "ASSETS OUT OF CONTAINTMENT. THIS IS NOT A DRILL.";
    msg = arr[input % 5];
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

void Alarm::setMessage(string input)
{
    msg = input; 
}