#pragma once

#include <string>
#include <vector>
#include <list>
using namespace std;

class Stringset
{
    private:
        vector<list<string>> table; // Hash table to store strings
        int num_elems; // Number of elements in the table
        int size; // Size of the hash table

    public:
        Stringset(); // Constructor
        vector<list<string>> getTable() const; // Get the hash table
        int getNumElems() const; // Get the number of elements in the set
        int getSize() const; // Get the size of the hash table
        void insert(string word); // Insert a word into the set
        bool find(string word) const; // Check if a word is in the set
        void remove(string word); // Remove a word from the set
};
