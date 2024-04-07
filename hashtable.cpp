/**************************
Name: Abul Imam
Assignment: 7
Purpose of the file: This file contains the 
method definitions of a Hashtable class. It uses
MODULO as the hash function and Linked List objects
for seperate chaining (Collision Resolution).
***************************/

#include "hashtable.h"

Hashtable::Hashtable() {
    /*****************************************
    Constructor : Sets count to 0 (Empty Table)

    @param na : na
    @return na : na
    @exception na : na 
    *********************************************/
    count = 0;
}

Hashtable::~Hashtable() {
    /*****************************************
    Destructor: Nothing is needed because Linked List
    Destructor deallocates the memory of each node.
    *********************************************/
    
}

int Hashtable::hash(int id) {
    /*****************************************
    Finds the hash position using MODULO. Essentially it's
    returning the remainder when the id is divided by the hashtable size.

    @param id : int passed from caller
    @return id % HASHTABLESIZE: remainder when the id is divided by the hashtable size.
    @exception na : na
    *********************************************/ 
    return id % HASHTABLESIZE;
}

bool Hashtable::insertEntry(int id, string *data) {
     /*****************************************
    Adds the (id and data) into the hashtable based on the
    hash position. Essentially it passes the data to Linked list
    method addNode() which creates a new node with that info.

    @param id : id passed from caller
    @param *data : a string pointer passed from caller
    @return (bool) : Returns True if entry is added. 
    @exception na : na
    *********************************************/
    bool inserted = false;
    
    if (id > 0 && *data != "") {
        int position = hash(id);
        inserted = hashtable[position].addNode(id, data);
        if (inserted) {
            count++;
        }
    }
    return inserted;
}

bool Hashtable::removeEntry(int id) {
     /*****************************************
    Deletes the specific entry based on the id and hash position.
    It calls the Linked List method deleteNode() which looks for that 
    id and deletes that particular node in that hash position.

    @param id : id passed from caller
    @return (bool) : Returns True if entry is deleted. 
    @exception na : na
    *********************************************/
    bool removed = false;
    
    if (id > 0) {
        int position = hash(id);
        removed = hashtable[position].deleteNode(id);
        if (removed) {
            count--;
        }
    }
    return removed;
}

string Hashtable::getData(int id) { 
    /*****************************************
    Retrives the string that corresponds with the id. It looks for the
    hash position, calls the LL method getNode() and retrives the string 
    data through pass by reference.

    @param id : id passed from caller
    @return info : Returns the string that corresponds with the id.
    @exception na : na
    *********************************************/  
    string info = "";
    if (id > 0) {
        Data emptyData;
        int position = hash(id);  
        bool found = hashtable[position].getNode(id, &emptyData);
        if (found) {
            info = emptyData.data;
        }     
    }
    return info;
}

int Hashtable::getCount() {
    /*****************************************
    Gives the no of hash table entries.

    @param na : na
    @return count : No of entries in the table
    @exception na : na
    *********************************************/ 
    return count;
}

void Hashtable::printTable() {
    /*****************************************
    Prints the entire hash table. Every chain.

    @param na : na
    @return na : na
    @exception na : na
    *********************************************/ 
    for (int i = 0; i < HASHTABLESIZE; i++) {
        cout << "Entry " << i + 1 << ": ";
        hashtable[i].printList(false);
        cout << endl;
    }
}
