#pragma once
#include "headers.h"

class Asset
{
    public:

    string dinoName;
    double lat;      // offset 0x20
    double lon;      // offset 0x28

    // default copy constructor
    Asset(string inStr, double in1, double in2) : dinoName(inStr), lat(in1), lon(in2){};
    // return the Asset's location
    string getLocation() __attribute__ ((fastcall));
    
};

string Asset::getLocation() __attribute__ ((fastcall))
{
    string ret;

    if( lat < 0.0 || lon < 0.0)
    {
        if( lat < 0.0 || lon >= 0.0 )
        {
            if( 0.0 <= lat || 0.0 <= lon )
            {
                // Raptor Paddock
                ret = sections[4].sectionName;
            }
            else{
                // Triceratops Paddock
                ret = sections[3].sectionName;
            }
        }
        else
        {   // T-Rex Paddock
            ret = sections[2].sectionName;
        }
    }
    else
    {
        // Dilophosaurus Paddock
        ret = sections[1].sectionName;
    }
    return ret;
}
