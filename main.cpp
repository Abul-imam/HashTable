/**************************
Name: Abul Imam
Assignment: 7
Purpose of the file: This file will create a hash
table and insert random ids and string (testdata).
Then it will test the hash table for functionality.
***************************/

#include "main.h"

int main() {
    /*********************************************
    This main function creates a hashtable object and fills it with test data.
    It tests the hash table thoroughly for any bugs.

    @param na : na
    @return 0 : successful execution
    @exception na : na
    *********************************************/
    
    //seed the rand function
    srand(time(NULL));

    /*
     * This code makes test data of 6 - 25 entries
     * Note this guarantees at least one non unique id and one bad id
     * Do not modify this code from here to the next comment telling
     * you to "START HERE"
     */
    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];
    
    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize-2] = ids[testdatasize-3];
    strs[testdatasize-2] = "known duplicate";
    ids[testdatasize-1] = - 1;
    strs[testdatasize-1] = "known bad";
    
    /*
     * Show test data
     */
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

    Hashtable hashtable;
    
    cout << "\nCalling getCount and printTable to show the table is empty: " <<endl;
    cout << "\nNo of ELEMENTS in the Hash Table: " << hashtable.getCount() <<endl;

    cout << "\n1. Printing HashTable....." << endl;
    hashtable.printTable();
    cout << endl;

    cout << "\n2. Inserting Test Data into the TABLE...." << endl;
    for (int i = 0; i < testdatasize; i++) {
        if (hashtable.insertEntry(ids[i], &strs[i])) {
            cout << "Success!! Inserted ===> " << ids[i] << " : " << strs[i] <<endl;
            cout << "There are " << hashtable.getCount() << " entries in the table." << endl << endl;
        } else {
            cout << "Failed. Invalid data! (duplicate/empty) ===> " << ids[i] << " : " << strs[i] <<endl <<endl;
        }
    }

    cout << "\n3. Printing HashTable after inserting data....." << endl;
    hashtable.printTable();

    cout << "\n4. No of ELEMENTS in the Hash Table: " << hashtable.getCount() <<endl;

    cout << "\n5. Retrieving Test Data on at a time..." << endl;
    string temp = "";
    for (int i = 0; i < testdatasize; i++) {
        temp = hashtable.getData(ids[i]);

        if (temp != "") {
            cout << "Success: " << ids[i] << ": " << temp << endl;
        } else {
            cout << "Failed: " << ids[i] << " is not in the table." << endl;
        }
    }

    cout << "\n5. Deleting Test Data..." << endl;
    cout << "\nTrying (1st element): " << ids[0] << ": " << hashtable.getData(ids[0]) << endl;
    if (hashtable.removeEntry(ids[0])) {
        cout << "  Success: " << ids[0] << " removed" << endl;
    } else {
        cout << "  Failed: " << ids[0] << " was not removed (INVALID DATA)" << endl;
    }

    cout << "\nTrying (middle element): " << ids[(testdatasize-1)/2] << ": " << hashtable.getData(ids[(testdatasize-1)/2]) << endl;
    if (hashtable.removeEntry(ids[(testdatasize-1)/2])) {
        cout << "  Success: " << ids[(testdatasize-1)/2] << " removed" << endl;
    } else {
        cout << "  Failed: " << ids[(testdatasize-1)/2] << " was not removed (INVALID DATA)" << endl;
    }

    cout << "\nTrying (last element): " << ids[testdatasize-1] << ": " << hashtable.getData(ids[testdatasize-1]) << endl;
    if (hashtable.removeEntry(ids[testdatasize-1])) {
        cout << "  Success: " << ids[testdatasize-1] << " removed" << endl;
    } else {
        cout << "  Failed: " << ids[testdatasize-1] << " was not removed (INVALID DATA)" << endl;
    }

    cout << "\nTrying (MAX ID + 1): " << MAXID + 1 << "..." << endl;
    if (hashtable.removeEntry(MAXID + 1)) {
        cout << "  Success: " << MAXID + 1 << " removed" << endl;
    } else {
        cout << "  Failed: " << MAXID + 1 << " was not removed (INVALID DATA)" << endl;
    }
    cout << endl;

    cout << "6. Hash Table Traversal..." << endl;
    cout << "There are " << hashtable.getCount() << " entries in the table." << endl << endl;
    hashtable.printTable();

    cout << "\n7.Removing all elements from hashtable..." <<  endl;
    for(int i = 0; i < testdatasize; i++) {
        hashtable.removeEntry(ids[i]);
    }
    cout << "There are " << hashtable.getCount() << " entries in the table." << endl << endl;
    hashtable.printTable();
    cout << endl << endl;

    /************************************************
    ******** RANDOM TESTS ***************************
    *************************************************/
   cout << "\nSTARTING Random testing ..." << endl <<endl;
   for (int i = 0; i < HASHTABLESIZE * RANDOM_MULTIPLIER; i++) {
        int choice = rand() % CHOICES + 1;
        int idx = rand() % testdatasize;
        string temp = "";

        switch (choice) {
            case 1:
            case 2:
                cout << "\nInserting DATA..." << endl;
                if (hashtable.insertEntry(ids[idx], &strs[idx])) {
                    cout << "Success!! Entry inserted    " << ids[idx] << ":" << strs[idx] << endl;
                    cout << "No of entries in the table: " << hashtable.getCount() << endl;
                    cout << endl;
                } else {
                    cout << "Failed.. INVALID DATA!" << endl;
                    cout << endl;
                }
                break;
            case 3:
                cout << "\nCounting elements..." << endl;
                cout << "Total inserted elements counts: " << hashtable.getCount() << endl;
                break;
            case 4:
                cout << "\nGetting data..." << ids[idx] << endl;
                temp = hashtable.getData(ids[i]);

                if (temp != "") {
                    cout << "  Success!!" << endl;
                } else {
                    cout << "  FAILED!" << endl;
                }
                break;
            case 5:
                cout << "\nRemoving data..." << endl;
                cout << ids[idx] << ": " <<hashtable.getData(ids[idx]) << endl;
                if (hashtable.removeEntry(ids[idx])){
                    cout << "  Success!!" << endl;
                } else {
                    cout << "  Failed to DELETE. Likely invalid id" << endl;
                }
                break;
            case 6: 
                cout << "\nPrinting hashtable..." << endl;
                hashtable.printTable();
                break;
        }
   }  
return 0;
}
