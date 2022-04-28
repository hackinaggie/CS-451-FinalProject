#pragma once
#include "headers.h"

// opens vault & visitor section doors, sets cams to statics, updates some alarms to bad things.
void goCode();

// print the possible lab control commands
void lab_controls();

// create a string that is used then logged to sessionlog.txt in the calling fxn
string logdata();

// make another Inventory obj with input from user and push it to the stack
void addItem(stack<Inventory> stk);

// checks if the stack isn't empty, then calls pop on it
void takeItem(stack<Inventory>* stk);

// display the passed in stk. REMOVES all elements from it as it displays them.
void display(stack<Inventory>* stk);

// Displays the camera's of each section
void parkCameras();

// print MANY random sequences of "TAGC" variants
void getGenes();
