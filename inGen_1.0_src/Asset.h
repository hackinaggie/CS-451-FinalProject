#pragma once

#include <iostream>
#include "ParkSection.h"

using namespace std;

class Asset
{
    public:

    string dinoName;
    double lat;      // offset 0x20
    double lon;      // offset 0x28

    // default copy constructor
    Asset(string inStr, double in1, double in2) : dinoName(inStr), lat(in1), lon(in2){};
    // return the Asset's location
    string getLocation();
};

