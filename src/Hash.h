#pragma once

class Hash
{
    public:
    // size == 28, 0x1c
    class MyItem
    {
        public:
        int index;
        char hash[20];  // off 0x04
        int int_twoo;// off 0x18 20 bytes off?
        MyItem(int p1, string p2, int p3);
    };
    
    int size;     
    list<MyItem*> listItems;    // 0x08

    // init an obj with a MyItem* list of size sz
    Hash(int sz);
    // init a MyItem obj with the input and push_back() to list
    void insertItem(int p1, string inStr, int p3);
    // look for a list item with p1 and delete it if found
    void deleteItem(int p1);
    // hash the input and return a long
    long hashFunction(int p1);
    // iterate size times and print the whole list of MyItems
    void displayHash();
};

