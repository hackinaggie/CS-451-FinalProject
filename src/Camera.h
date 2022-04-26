#pragma once
#include "headers.h"

class Camera
{
    public:
    ElectricalSystem eSys;
    string feed;         // off 0x28

    // str constr
    Camera(string input="");

    // display feed
    void displayFeed();

    // update the feed
    void refreshFeed(string newFeed);
};

Camera::Camera(string input)
{
    // eSys
    feed = input;
}

void Camera::displayFeed(){
    string in;
    string p;
    bool passCorrect;

    cout << "Enter passcode: ";
    cin >> in;

    passCorrect = eSys.passcodeCorrect(in);
    
    if(passCorrect)
    {
        cout << feed << endl;
    }
    else
    {
        cout << "INCORRECT PASSCODE" << endl;
    }
}

void Camera::refreshFeed(string newFeed)
{
    feed = newFeed;
}
