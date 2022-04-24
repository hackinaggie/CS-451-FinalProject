#pragma once
#include "headers.h"

class ParkSection
{   // TODO: Not sure about exact order of these (lat/lon then minutes? or lat vars then lon vars?)
    double lat;
    double lat_min;     // off 0x08
    double lon;         // off 0x10
    double lon_min;     // off 0x18

    Fence fence;        // off 0x20
    Entry entry;        // off 0x28
    Camera camera;      // off 0x30
    string sectionName; // off 0x38

    ParkSection(string name, double d1, double d2, double d3, double d4, string feed);
};

ParkSection::ParkSection(string name, double d1, double d2, double d3, double d4, string feed)
{
    sectionName = name;
    lat = d1;
    lat_min = d2;
    lon = d3;
    lon_min = d4;

    // TODO the 'feed' thing is a strong guess. also is this how u do paramaterized constr?
    camera = Camera(feed);
}
