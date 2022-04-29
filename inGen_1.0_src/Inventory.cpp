#include "Inventory.h"


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
