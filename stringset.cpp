
#include "stringset.h"
#include <vector>
#include <string.h>
#include <string>
#include <list>

Stringset::Stringset() : table(4), num_elems(0), size(4) {}

// Used in test cases and testStringset() in main.cpp
// Returns the hash table
vector<list<string>> Stringset::getTable() const
{
    return table;
}

// Used in test cases and testStringset() in main.cpp
// Returns the number of elements in the hash table
int Stringset::getNumElems() const
{
    return num_elems;
}

// Used in test cases and testStringset() in main.cpp
// Returns the size of the hash table
int Stringset::getSize() const
{
    return size;
}

// Inserts a word into the hash table
void Stringset::insert(string word)
{
    std::hash<string> h;
    int index = h(word) % size;

    // If the bucket is empty, add the word to the bucket
    if (table[index].empty() != false) {
        table[index].push_back(word);
    }
    else {
        // If the word already exists in the bucket, return
        for (std::list<string>::iterator i = table[index].begin(); i != table[index].end(); i++) {
            if (*i == word) {
                return;
            }
        }
        // Add the word to the bucket
        table[index].push_back(word);
    }

    // If the hash table is full, resize the table
    if (size == num_elems) {
        std::vector<list<string>> newTable(size * 2);
        for (int i = 0; i < size; i++) {
            for (std::list<string>::iterator j = table[i].begin(); j != table[i].end(); j++) {
                newTable[h(*j) % (size * 2)].push_back(*j);
            }
        }
        table = newTable;
        size *= 2;
        num_elems++;
    }
    else {
        num_elems++;
    }
}

// Searches for a word in the hash table
bool Stringset::find(string word) const
{
    std::hash<string> h;
    int index = h(word) % size;

    // Iterate through the bucket to find the word
    for (std::list<string>::const_iterator i = table[index].begin(); i != table[index].end(); i++) {
        if (*i == word) {
            return true;
        }
    }
    return false;
}

// Removes a word from the hash table
void Stringset::remove(string word)
{
    std::hash<string> h;
    int index = h(word) % size;

    // If the bucket is empty, return
    if (table[index].empty() != false) {
        return;
    }
    else {
        // Iterate through the bucket to find and remove the word
        for (std::list<string>::iterator i = table[index].begin(); i != table[index].end(); i++) {
            if (*i == word) {
                table[index].remove(word);
                num_elems--;
                return;
            }
        }
    }
}

