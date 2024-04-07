/**************************
Name: Abul Imam
Assignment: 7
Purpose of the file: This file contains class
declarations of Data & Node struct. Data is used
to store the inputs (int, string) and Node is used
to implement a doubly linked list.
***************************/

#ifndef DATA_H
#define DATA_H

#include "string"
using std::string;

struct Data {
    int id;
    string data;
};

struct Node {
    Data data;
    Node *next;
    Node *prev;
};

#endif /* DATA_H */

