#pragma once
#include "headers.h"

class Asset
{
    public:

    string dinoName;
    double lat;      // offset 0x20
    double lon;      // offset 0x28

    // default copy constructor
    Asset(string inStr, double in1, double in2);
    // return the Asset's location
    string getLocation() __attribute__ ((fastcall));
    
};

Asset::Asset(string inStr, double in1, double in2)
{
    dinoName = inStr; // register(RSI/RDI) + name
    lat = in1;
    lon = in2;
}

// NOT DONE; TODO
string Asset::getLocation() __attribute__ ((fastcall))
{
    // some registers RSI & RDI passed in?
    // RSI == *this
    // RDI == string pointer that is first constructed with a name (raptor),
    //          then passed into an Asset constructor.

    // looks like it returns the location based on the Asset's coordinates
    // strange string construction and returning its pointer that then gets printed in park_controls (original caller)
    // but the string that gets passed into RDI is a string for dino names already
    if( lat < 0.0 || lon < 0.0)
    {
        if( lat < 0.0 || 0.0 <= lon )
        {
            if( 0.0 <= lat || 0.0 <= lon )
            {
                asm("mov rax, QWORD PTR [rdi]\n\t"
                "ret\n\t");
            }
        }
    }
    return NULL; // IDK
}
