#include "Entry.h"


Entry::Entry()
{
    //eSys
    open = false;
    locked = true;
}

bool Entry::isOpen()
{
    return open;
}

void Entry::toggle_lock()
{
    string readIn;
    int cmpHowdy{0};

    cout << "Enter passcode: ";
    cin >> readIn;

    // correct password
    if( eSys.passcodeCorrect(readIn) )
    {
       if( eSys.isOn() )
        {
            // lock it if currently open
            if( this->locked == false )
            {
                this->locked = true;
            }
            // unlock it if currently closed
            else
            {
                this->locked = false;
            }
        }
    }
    else{
        cout << "Password Incorrect" << endl;
    }
}
