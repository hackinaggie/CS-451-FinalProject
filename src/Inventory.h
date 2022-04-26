#pragma once
#include "headers.h"

class Inventory
{
    long serialNum;    
    int lot;                    // off 0x08
    string manufactureDate;     // off 0x10

    public:
    // simple constructor
    Inventory(long in_serial, int in_lot, string in_date);
    // copy constr. copes serialNum & lot from og, not date
    Inventory(Inventory* og);

    // Getters & Setters
    void setDate(string cp);
    string getDate();
    void setLot(int cp);
    int getLot();
    void setSerial(long cp);
    long getSerial();
};

Inventory::Inventory(long in_serial, int in_lot, string in_date)
{
    serialNum = in_serial;
    lot = in_serial;
    manufactureDate = in_date;
}

Inventory::Inventory(Inventory* cp)
{
    this->serialNum = cp->serialNum;
    this->lot = cp->serialNum;
}

void Inventory::setDate(string cp)
{
    manufactureDate = cp;
}

string Inventory::getDate()
{
    return manufactureDate;
}

void Inventory::setLot(int cp)
{
    lot = cp;
}

int Inventory::getLot()
{
    return lot;
}

void Inventory::setSerial(long cp)
{
    serialNum = cp;
}

long Inventory::getSerial()
{
    return serialNum;
}
