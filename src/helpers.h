#pragma once

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

// implement user options for the Visitor, Park, Lab, and Alarms sections
void menus();

// implement visitor section options: Alarms, Entries, Cameras, and Inventory
void visitor_controls();

// implement park section options: Alarms, Entries, Car Tracking, and Inventory
void park_controls();

// determine if user input is equal to required admin_pass & admin_user
bool validate(string uname, string passw);
