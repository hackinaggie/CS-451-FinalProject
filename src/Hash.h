#pragma once
#include "headers.h"

class Hash
{
    public:
    // size == 28, 0x1c
    class MyItem
    {
        public:
        int int_onee;
        char cStr[20];  // off 0x04
        int int_twoo;// off 0x18 20 bytes off?
        MyItem(int p1, string p2, int p3);
    };
    
    int size;     
    list<MyItem> listItems;    // 0x08

    // init an obj with a MyItem* list of size sz
    Hash(int sz);
    // init a MyItem obj with the input and push_back() to list
    void insertItem(int p1, string inStr, int p3);
    // look for a list item with p1 and delete it if found
    void deleteItem(int p1);
    // hash the input and return a long
    long hashFunction(int p1);
    // TODO iterate size times and print the whole list of MyItems
    void displayHash();
};

// TODO: Vuln: possible cStr only 20 bytes, constr don't check sizeof p2
Hash::MyItem::MyItem(int p1, string p2, int p3)
{
    int_onee = p1;
    strcpy(cStr, p2.c_str());
    int_twoo = p3;
}

// TODO: Real Iffy on this
Hash::Hash(int wantSz)
{
    size = wantSz;
    listItems = list<MyItem>(size);
}

void Hash::insertItem(int p1, string inStr, int p3)
{
    // TODO: not sure what retHash does here. its mostly used in calculating the offsets for the array
    long retHash = hashFunction(p1);
    MyItem item(p1, inStr, p3);
    listItems.push_back(item);
}

void Hash::deleteItem(int p1)
{
    long retHash = hashFunction(p1);
    list<MyItem>::iterator l_beg = listItems.begin();
    list<MyItem>::iterator l_end = listItems.end();

    while(l_beg != l_end)
    {
        if(p1 == (*l_beg).int_onee)
        {
            break;
        }
        l_beg++;
    }

    // don't delete if didn't find p1
    if(l_beg != l_end)
    {  
        // TODO: Ask Ford what he thinds on line 39 - 43 of this fxn in Ghidra
        //listItems.erase(l_beg, l_end);
        listItems.erase(l_beg);
    }
}

long Hash::hashFunction(int p1)
{
    return (((((p1 +9)*2 -4 >> 1) -2) *3 -9) /3 - p1) % size & -1;
}

void Hash::displayHash()
{
    // TODO: this for loop dont make sense
    for(int i{0}; i < size; i++)
    {
        // i is also used to initialize the listItems var in the Ghidra. listItems = listItems[i]
        std::cout << i;
        list<MyItem>::iterator l_beg = listItems.begin();
        list<MyItem>::iterator l_end = listItems.end();

        while(l_beg != l_end)
        {
            MyItem item = *l_beg;
            cout << " --> " << item.cStr << "\t" << item.int_twoo;
            l_beg++;
        }
        cout << endl;
    }
}