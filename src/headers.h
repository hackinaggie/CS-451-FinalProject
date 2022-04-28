#pragma once 

#include <iostream>
#include <list>
#include <map>
#include <stack>
#include <math.h>
#include <string.h>
#include <ostream>
#include <fstream>
#include <sys/time.h>

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


/********************************
 *          GLOBALS             *
 *******************************/
// All the below (except for go_code, loggedIn, & admin_pass) are initialized in the __static_initialization_and_destruction_0 fxn
// FLAGS
bool go_code;
bool loggedIn;

// IMAGES, FOR CAMERAS
string img_static = "::.::.::.::.::::.::.::.::.::\n\'::\'::\'::\'::\':\'::\'::\'::\'::\':\n::.::.::.::.::::.::.::.::.::\n:\'::\'::\'::\'::\':\'::\'::\'::\'::\'\n::.::.::.::.::::.::.::.::.::\n\'::\'::\'::\'::\':\'::\'::\'::\'::\':\n::.::.::.::.::::.::.::.::.::\n\'::\'::\'::\'::\':\'::\'::\'::\'::\':\n::.::.::.::.::::.::.::.::.::\n:\'::\'::\'::\'::\':\'::\'::\'::\'::\'\n::.::.::.::.::::.::.::.::.::\n\'::\'::\'::\'::\':\'::\'::\'::\'::\':\n::.::.::.::.::::.::.::.::.::";
string img_testtube = "    _______\n   (_______)\n    |     |\n    |     |\n    |  T  |\n    |     |\n    |  R  |\n    |`---\'|\n    |  E  |\n    |     |\n    |  X  |\n    |     |\n    |     |\n    |     |\n    |     |\n    `.___.\'";
string img_visitor_center = "                  ,\n               ,  ;:._.-`\'\'.\n             ;.;\'.;`      _ `.\n              \',;`       ( \\ ,`-.  \n           `:.`,         (_/ ;\\  `-.\n            \';:              / `.   `-._\n          `;.;\'              `-,/ .     `-.\n          \';;\'              _    `^`       `.\n         \';;            ,\'-\' `--._          ;\n\':      `;;        ,;     `.    \':`,,.__,,_ /\n `;`:;`;:`       ,;  \'.    ;,      \';\';\':\';;`\n              .,; \'    \'-._ `\':.;    \n            .:; `          \'._ `\';;,\n          ;:` `    :\'`\'       \',__.)\n        `;:;:.,...;\'`\'\n      \';. \'`\'::\'`\'\'  .\'`\'\n    ,\'jgs`\';;:,..::;`\'`\'\n, .;`      `\'::\'\'`\n,`;`.\n";
string img_trex = "                                              ____\n  ___                                      .-~. /_\"-._\n`-._~-.                                  / /_ \"~o\\  :Y\n      \\  \\                                / : \\~x.  ` \')\n      ]  Y                              /  |  Y< ~-.__j\n     /   !                        _.--~T : l  l<  /.-~\n    /   /                 ____.--~ .   ` l /~\\ \\<|Y\n   /   /             .-~~\"        /| .    \',-~\\ \\L|\n  /   /             /     .^   \\ Y~Y \\.^>/l_   \"--\'\n /   Y           .-\"(  .  l__  j_j l_/ /~_.-~    .\nY    l          /    \\  )    ~~~.\" / `/\"~ / \\.__/l_\n|     \\     _.-\"      ~-{__     l  :  l._Z~-.___.--~\n|      ~---~           /   ~~\"---\\_  \' __[>\nl  .                _.^   ___     _>-y~\n \\  \\     .      .-~   .-~   ~>--\"  /\n  \\  ~---\"            /     ./  _.-\'\n   \"-.,_____.,_  _.--~\\     _.-~\n               ~~     (   _}       \n                      `. ~(\n                        )  \\n                  /,`--\'~\\--\'~\\n                  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
string img_triceratops = "                                 ,,,,,,,,,,,,,,,,,,,,,\n           M                  , \'                     \',\n         {|  M            , \'                           \',\n        { |    M      , \'                                 \',\n       {./       >,,\'                             ;         ;,\n ======;;;;;    __>                               ;         ; \',\n=====,\'   @    (__                                ;         ;   \',\n___ /         .../                                ;         ;\n\\,/                  \',         \',               ;         ;\n (  ^     , \'\'\'\'\'\',,,,,\',         \',            ,;        ;\',\n  \\//_, \'         ;     ;\',        ;,,,,,,,\'\'\'\';  ;      ;   \',\n                 ;     ;   \',      ;      ;    ;   ;     ;     \',\n                ;    ;       ;     ;     ;    ;    ;    ;        \'\n               ;    ;        ;    ;     ;    ;     ;    ;\n              ;    ;         ;    ;    (/(/(/      ;    ;\n             (/(/(/          ;    ;                (/(/(/\n                             (/(/(/\n";
string img_raptor = "                                                     ___._\n                                                   .\'  <0>\'-.._\n                                                  /  /.--.____\")\n                                                 |   \\   __.-\'~\n                                                 |  :  -\'/\n                                                /:.  :.-\'\n__________                                     | : \'. |\n\'--.____  \'--------.______       _.----.-----./      :/\n        \'--.__            `\'----/       \'-.      __ :/\n              \'-.___           :           \\   .\'   /\n                    \'---._           _.-\'   ] /  _/\n                         \'-._      _/     _/ / _/\n                             \\_ .-\'____.-\'__< |  \\___\n                               <_______.\\    \\_\\_---.7\n                              |   /\'=r_.-\'     _\\ =/\n                          .--\'   /            ._/\'>\n                        .\'   _.-\'\n   snd                 / .--\'\n                      /,/\n                      |/`)\n                      \'c=,\n";

// ADMIN AUTHENTICATION
string admin_pass = "Mr. Goodbytes", admin_user = "NEDRY";

// ALARMS FOR LAB, VISITOR CENTER, PARK
Alarm labAlarm{"ALL SYSTEMS OK"}, visitorAlarm{"ALL SYSTEMS OK"}, parkAlarm{"ALL SYSTEMS OK"};

// VISITOR CENTER
Camera visitorCamera{img_visitor_center};
Entry visitorDoor;

// VAULT 
Camera vaultCamera{img_testtube};
Entry vaultDoor;

// PARK SECTIONS. 144, 232, 320, 408 called in getLocation. 48 & 0 in parkCameras. 
// per , each element 0x58 (88) from each other even though size is 0x40
ParkSection sections[]{ {"Perimeter", -25.0,25.0,-25.0,25.0, NULL}, {"Dilophosaurus Paddock", 0.0,25.0,0.0,25.0, img_visitor_center}, \
                        {"T-Rex Paddock", 0.0,25.0,-25.0,0.0, img_trex },   {"Triceratops Paddock", -25.0,0.0,-25.0,0.0, img_triceratops}, \
                        {"Raptor Paddock", -25.0,0.0,0.0,25.0, img_raptor} };

// ELECTRICAL SYSTEM
ElectricalSystem electricalSystem;