#include "headers.h"

using namespace std;

void goCode()
{
    go_code = 1;

    // vault
    vaultDoor.unlock();
    vaultCamera.refreshFeed(img_static);

    // labAlarm
    labAlarm.setMessage("INVENTORY MISSING");

    // visitor center
    visitorDoor.unlock();
    visitorCamera.refreshFeed(img_static);
    visitorAlarm.setMessage("ICE CREAM MELTING");

    // park alarm
    parkAlarm.setMessage("ASSET OUT OF CONTAINMENT");
}

//check if name and passw are correct
bool validate(string uname, string passw)
{
    if (uname == admin_user)
    {
        if (passw == admin_pass)
        {
            loggedIn = true;
        }
    }
    return loggedIn;
}

void lab_controls()
{
    cout << "LAB CONTROLS" << endl;
    cout << "alarmstatus --lab" << endl;
    cout << "unlockdoor --lab" << endl;
    cout << "lockdoor --lab" << endl;
    cout << "camerastatus --lab" << endl;
    cout << "genesummary --lab" << endl;
}

string logdata()
{
    // passes in the desired return variable's address in RDI. believe that's just compiler optimization
    string out = "THANK YOU FOR USING THE INGEN SYSTEM\n";
    out += "WE APPRECIATE YOUR CONTRIBUTIONS\n";
    out += "TRY AGAIN LATER IF YOU WANT\n";
    out += "STORE THIS INFORMATION FOR YOUR RECORDS\n";
    return out;
}

void takeItem(stack<Inventory> * s) {
    if(s->size() > 0) {
        s->pop();
    }
}

void addItem(stack<Inventory> * s) {
    cout << "Enter the following information:" << endl;
    cout << " - Serial Number: " << flush;
    long sn;
    cin >> sn;
    cout << " - Lot Number: " << flush;
    int ln;
    cin >> ln;
    cout << " - Manufacturing Date: " << flush;
    string date;
    cin >> date;
    Inventory inv(sn, ln, date);
    s->push(inv);
}

void display(stack<Inventory> * s) {
    int itemNo = 0;
    while(s->size() > 0) {
        Inventory inv = s->top();
        cout << "Item #" << itemNo + 1 << endl;
        cout << "Serial Number: " << inv.getSerial() << endl;
        cout << "Lot Number: " << inv.getLot() << endl;
        cout << "Manufacturing Date: " << inv.getDate() << endl;
        s->pop();
        itemNo++;
    }
}

void visitor_controls() {
    cout << "VISITOR CONTROLS" << endl;
    Alarm a("All clear");
    Entry et1;
    Entry et2;
    Entry et3;

    cout << "Select from the following" << endl;
    cout << "[1] - Alarm System\n[2] - Entry Controls\n[3] - Cameras\n[4] - Inventory\n[0] - QUIT\n";
    int intIn;
    cin >> intIn;
    switch(intIn) {
        case 0:
            break;
        case 1:
            a.printMessage();
            break;
        case 2:
            cout << "Door Status" << endl;
            if(et1.isOpen() || et2.isOpen() || et3.isOpen()) {
                cout << "Area unsecure, please lock all doors" << endl;
            }
            cout << "Current Entry Controls" << endl;
            cout << "[U] - Unlock all doors\n [L] - Lock all doors" << endl;
            char charIn;
            cin >> charIn;
            if(charIn == 'U') {
                cout << "Please enter the password: " << flush;
                string stringIn;
                cin >> stringIn;
                electricalSystem.turnOff(stringIn);
                cout << "All doors unlocked, proceed with caution" << endl;
            } else {
                cout << "AN ERROR HAS OCCURED" << endl;
                a.printMessage();
            }
            break;
        case 3:
            visitorCamera.displayFeed();
            break;
        case 4:
            stack<Inventory> s;
            intIn = 0;
            while(intIn != 3) {
                cout << "Options" << endl;
                cout << "-------" << endl;
                cout << "1. Add part" << endl;
                cout << "2. Take part" << endl;
                cout << "3. Quit" << endl;
                cout << "Would you like to enter an item into inventory?" << endl;
                cout << "Choice: " << flush;
                cin >> intIn;
                if (intIn == 1) {
                    addItem(&s);
                } else if (intIn == 2) {
                    takeItem(&s);
                }
            }
            display(&s);
            cout << "EXITING VISITOR CONTROLS" << endl;
            break;
    }
}

void park_controls() {
    map<string, pair<int, int>> m;
    cout << "PARK CONTROLS" << endl;
    Alarm parkAlarm(5);
    printf("%s  \n", "Select from the folowing");
    cout << "[1] - Alarm System \n[2] - Entry Controls \n [3] - Car Tracking \n[4] - Inventory\n[0] - QUIT\n";
    int intIn;
    cin >> intIn;
    for(int i = 0; i < 1; i++) {
        if(intIn == 1) {
            parkAlarm.printMessage();
        } else if(intIn == 2) {
            cout << "Current Status: " << endl;
                cout << "Section 1 secure" << endl;
                cout << "Section 2 secure" << endl;
                cout << "Section 3 secure" << endl;
                cout << "Section 4 secure" << endl;
                cout << "Park perimeter secure" << endl;
        } else if(intIn == 3) {
            //todo
        } else if(intIn != 4) {
            cout << "EXITING PARK CONTROLS" << endl;
            return;
        } else {
            Asset dino1("Dilophosaurus", 23, 4);
            Asset dino2("Dilophosaurus", 21, 16);
            Asset dino3("Dilophosaurus", 12, 6);
            cout << "Assets 1-3 can be found in this section: " << dino1.getLocation() << endl;
            Asset dino4("T-Rex", 15, -17);
            cout << "Asset 4 can be found in this section: " << dino4.getLocation() << endl;
            Asset dino5("Triceratops", -12, -12);
            Asset dino6("Triceratops", -22, -22);
            cout << "Assets 5-6 can be found in this section: " << dino5.getLocation() << endl;
            Asset dino7("Raptor", -18, 9);
            Asset dino8("Raptor", -18, 7);
            Asset dino9("Raptor", -16, 5);
            Asset dino10("Raptor", -12, 9);
            cout << "Assets 7-10 can be found in this section: " << dino7.getLocation() << endl;

        }
    }
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
            labAlarm.printMessage();
            cout << "Visitor Center:" << endl;
            visitorAlarm.printMessage();
            cout << "Park:" << endl;
            parkAlarm.printMessage();
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
        outfile << logdata();
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
                    visitorAlarm.printMessage();
                }
                if (input == "unlockdoor --vc")
                {
                    visitorDoor.unlock();
                }
                if (input == "lockdoor --vc")
                {
                    visitorDoor.lock();
                }
                if (input == "camerastatus --vc")
                {
                    visitorCamera.displayFeed();
                }
                if (input == "inventorysummary --vc")
                {
                }

                // park
                if (input == "alarmstatus --park")
                {
                    parkAlarm.printMessage();
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
                    labAlarm.printMessage();
                }
                if (input == "unlockdoor --lab")
                {
                    vaultDoor.unlock();
                }
                if (input == "lockdoor --lab")
                {
                    vaultDoor.lock();
                }
                if (input == "camerastatus --lab")
                {
                    vaultCamera.displayFeed();
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