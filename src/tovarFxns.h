#pragma once
#include "headers.h"

// opens vault & visitor section doors, sets cams to statics, updates some alarms to bad things.
void goCode();

void lab_controls();

// create a string that is used then logged to sessionlog.txt in the calling fxn
string logdata();

// make another Inventory obj with input from user and push it to the stack
void addItem(stack<Inventory> stk);

// checks if the stack isn't empty, then calls pop on it
void takeItem(stack<Inventory>* stk);

