#include "tovarFxns.h"

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

void addItem(stack<Inventory>* stk)
{
    long inSerial;
    int inLot;
    string inDate;

    cout << "Enter the following information:" << endl;
    
    cout << " - Serial Number: ";
    cin >> inSerial;

    cout << " - Lot Number: ";
    cin >> inLot;

    cout << " - Manufacturing Date: ";
    cin >> inDate;

    Inventory newInv(inSerial, inLot, inDate);
    stk->push(newInv);
}

void takeItem(stack<Inventory>* stk)
{
    if( stk->size() != 0 )
    {
        stk->pop();
    }
}

void display(stack<Inventory>* stk)
{
    for( int i{0}; i < stk->size(); i++)
    {
        Inventory curInventory = stk->top();
        
        cout << "Item #" << i+1 << endl;
        cout << "Serial Number: " << curInventory.getSerial() << endl;
        cout << "Lot Number: " << curInventory.getLot() << endl;
        cout << "Manufacturing Date: " << curInventory.getDate() << endl;
        cout << endl;
        stk->pop();
    }
}

void parkCameras()
{
    cout << "======================================" << endl;
    for( int i{0}; i < 5; i++)
    {
        ParkSection section = sections[i];
        cout << "Section " << i << ": " << section.sectionName << endl;
        section.camera.displayFeed();
        cout << "======================================" << endl;
    }
    
}

void getGenes()
{
    std::cout << "Gene Sequence:" << std::endl;
    std::cout << "======================================" << std::endl;
    
    // give the rand() fxn a seed. not initially seen in binary possible vuln
    srand(time(NULL));
    // "TGCA" hex encoded
    int TGCA = 0x54474341;
    for( int i{0}; i < 200; i++)
    {
        for( int j{0}; j < 5; j++)
        {
            for( int k{0}; k < 10; k++)
            {
                int random = rand();
                char* off = (char*)(&TGCA) + (random % 4) ;
                std::cout << char(*off);
            }
            std::cout << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << "===================================================" << std::endl;
}