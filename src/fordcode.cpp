#include <string>
#include <ostream>
#include <fstream>
#include <iostream>
#include <sys/time.h>
#include "headers.h"

using namespace std;

bool go_code = false;

string admin_pass = "Mr. Goodbytes", admin_user = "NEDRY";
bool loggedin = false;

static Alarm *visitorAlarm, *parkAlarm, *labAlarm;
Camera *visitorCamera, *vaultCamera;
Entry *visitorDoor, *vaultDoor;

bool validate(string uname, string passw)
{
    if (uname == admin_user)
    {
        if (passw == admin_pass)
        {
            loggedin = true;
        }
    }
    return loggedin;
}

void lab_controls() {
    
}

void menus()
{
    int input;
    cout << "[1] - Visitor Center \n[2] - Park \n[3] - Research Lab\n[99] - Check Alarms\n[0]  - QUIT MENU\n";
    cin >> input;
    while (input != 0)
    {
        if (input == 1)
        {
            visitor_controls();
        }
        else if (input == 2)
        {
            park_controls();
        }
        else if (input == 3)
        {
            lab_controls();
        }
        else if (input == 99)
        {
            cout << "Checking alarms ... " << endl;
            cout << "Lab:" << endl;
            Alarm::printMessage(labAlarm);
            cout << "Visitor Center:" << endl;
            Alarm::printMessage(visitorAlarm);
            cout << "Park:" << endl;
            Alarm::printMessage(parkAlarm);
        }
        else
        {
            if (input == 0)
                break;
            cout << "Invalid instruction.\n[1] - Visitor Center \n[2] - Park \n[3] - Research Lab\n[99] - Check Alarms\n[0] - QUIT MENU\n";
        }
    }
}

void parkCameras()
{
}

void getGenes()
{
}

int main()
{
    int attempts = 0;

    cout << "Welcome to InGen" << endl;
    cout << "Proud leader in Genetics since 1990" << endl
         << endl;

    ofstream outfile("sessionlog.txt");

    while (true)
    {
        if (attempts > 2)
        {
            cout << "TOO MANY ATTEMPTS" << endl;
            break;
        }

        string uname, passw;
        timeval time;

        cout << "User Name: ";
        cin >> uname;
        cout << "Password: ";
        cin >> passw;
        gettimeofday(&time, NULL);
        outfile << "TIME: " << time.tv_sec << endl;
        outfile << "USER: " << uname << endl;
        outfile << "PASS: " << passw << endl;
        outfile << "THANK YOU FOR USING THE INGEN SYSTEM" << endl;
        outfile << "WE APPRECIATE YOUR CONTRIBUTIONS" << endl;
        outfile << "TRY AGAIN LATER IF YOU WANT" << endl;
        outfile << "STORE THIS INFORMATION FOR YOUR RECORDS" << endl;
        if (!validate(uname, passw))
        {
            attempts++;
            continue;
        }
        else
        {
            cout << "Successfully logged in!" << endl;
            cout << "Enter HELP at any time to see menus and QUIT to end program" << endl;

            string input;
            if (go_code)
            { // dead-end code
                for (int i = 0; i < 3; i++)
                {
                    cout << ">>";
                    cin >> input;
                    cout << "PERMISSION DENIED" << endl;
                }
                while (true)
                {
                    cout << "AH AH AH! YOU DIDN\'T SAY THE MAGIC WORD!" << endl;
                }
            }
            while (true)
            {
                cout << ">>";
                cin >> input;
                cout << endl;
                if (input == "HELP")
                {
                    menus();
                }
                if (input == "QUIT")
                {
                    break;
                }

                // visitor center
                if (input == "alarmstatus --vc")
                {
                    visitorAlarm->printMessage();
                }
                if (input == "unlockdoor --vc")
                {
                    visitorDoor->unlock();
                }
                if (input == "lockdoor --vc")
                {
                    visitorDoor->lock();
                }
                if (input == "camerastatus --vc")
                {
                    visitorCamera->displayFeed();
                }
                if (input == "inventorysummary --vc")
                {
                }

                // park
                if (input == "alarmstatus --park")
                {
                    parkAlarm->printMessage();
                }
                if (input == "camerastatus --park")
                {
                    parkCameras();
                }
                if (input == "inventorysummary --park")
                {
                }

                // lab
                if (input == "alarmstatus --lab")
                {
                    labAlarm->printMessage();
                }
                if (input == "unlockdoor --lab")
                {
                    vaultDoor->unlock();
                }
                if (input == "lockdoor --lab")
                {
                    vaultDoor->lock();
                }
                if (input == "camerastatus --lab")
                {
                    vaultCamera->displayFeed();
                }
                if (input == "genesummary --lab")
                {
                    getGenes();
                }
            }
        }
    }
    return 0;
}