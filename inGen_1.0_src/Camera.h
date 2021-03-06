#pragma once

#include <iostream>
#include "ElectricalSystem.h"

using namespace std;

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

