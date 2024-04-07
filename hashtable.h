/**************************
Name: Abul Imam
Assignment: 7
Purpose of the file: This file contains all
the directives needed for hashtable.cpp to run.
***************************/

#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H

#include <iostream>
#include <string> 
#include "data.h"
#include "linkedlist.h"

#define HASHTABLESIZE 15

using std::cout;
using std::endl;
using std::string;

class Hashtable {
    /*********************************************
     * This Hashtable class works with LinkedList ADT used for collision
     * resolution (seperate chaining). It's essentially a wrapper interface
     * that passes the data to the LinkedList class to do the heavy lifting.
     * This hashtable can inset, remove, getData, getCount and printTable.
     * 
     * @attrib count : Keeps track of the elements in the list.
     * @attrib hashtable[] : used for seperate chaining. It's an array of type LinkedList.
     * *********************************************/
public:
    /**********************
     * Constructor/Destructor
     **********************/
    Hashtable();
    ~Hashtable();

    /**********************
     * Setters/Mutators
     **********************/  
    bool insertEntry(int, string*);
    bool removeEntry(int);

    /**********************
     * Getters/Accessors
     **********************/
    string getData(int);
    int getCount();
    void printTable();

private:
    int hash(int);
 
    LinkedList hashtable[HASHTABLESIZE];
    int count;
    
};

#endif /* HASHTABLE_HASHTABLE_H */