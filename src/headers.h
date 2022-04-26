#pragma once 

#include <iostream>
#include <string.h>
#include <list>
#include <map>

using namespace std;

#include "Asset.h"
#include "ElectricalSystem.h"
#include "Alarm.h"
#include "Camera.h"
#include "Entry.h"
#include "Fence.h"
#include "Hash.h"
#include "Inventory.h"
#include "ParkSection.h"

// FLAGS
bool go_code;
bool loggedIn;

// IMAGES, FOR CAMERAS
string img_raptor, img_static, img_testtube, img_trex, img_triceratops, img_visitor_center;

// ADMIN AUTHENTICATION
string admin_pass, admin_user = "NEDRY";

// ALARMS FOR LAB, VISITOR CENTER, PARK
Alarm labAlarm, visitorAlarm, parkAlarm;

// VISITOR CENTER
Camera visitorCamera;
Entry visitorDoor;

// VAULT 
Entry vaultDoor;
Camera vaultCamera;
