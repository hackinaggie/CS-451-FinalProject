#pragma once

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
