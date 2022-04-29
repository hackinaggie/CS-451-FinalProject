#include "headers.h"

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
