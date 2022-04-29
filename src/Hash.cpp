#include "headers.h"

Hash::MyItem::MyItem(int p1, string p2, int p3)
{
    index = p1;
    strcpy(hash, p2.c_str()); // strncpy
    int_twoo = p3;
}

Hash::Hash(int wantSz)
{
    size = wantSz;
    listItems = list<MyItem*>(size);
}

void Hash::insertItem(int p1, string inStr, int p3)
{
    long retHash = hashFunction(p1);
    MyItem item(p1, inStr, p3);
    listItems.push_back(&item);
}

void Hash::deleteItem(int p1)
{
    long retHash = hashFunction(p1);
    list<MyItem*>::iterator l_beg = listItems.begin();
    list<MyItem*>::iterator l_end = listItems.end();

    while(l_beg != l_end)
    {
        if(p1 == (*l_beg)->index)
        {
            break;
        }
        l_beg++;
    }

    // don't delete if didn't find p1
    if(l_beg != l_end)
    {  
        listItems.erase(l_end);
    }
}

long Hash::hashFunction(int p1)
{
    return (((((p1 +9)*2 -4 >> 1) -2) *3 -9) /3 - p1) % size & -1;
}

void Hash::displayHash()
{
    for(int i{0}; i < size; i++)
    {
        std::cout << i;
        list<MyItem*>::iterator l_beg = listItems.begin();
        list<MyItem*>::iterator l_end = listItems.end();

        while(l_beg != l_end)
        {
            MyItem* item = *l_beg;
            cout << " --> " << item->hash << "\t" << item->int_twoo;
            l_beg++;
        }
        cout << endl;
    }
}
