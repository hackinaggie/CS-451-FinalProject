#include "Asset.h"

extern ParkSection sections[];

string Asset::getLocation()
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
