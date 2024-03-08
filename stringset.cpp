
#include "stringset.h"
#include <vector>
#include <string.h>
#include <string>
#include <list>

Stringset::Stringset() : table(4), num_elems(0), size(4) {}

//Used in test cases and testStringset() in main.cpp
vector<list<string>> Stringset::getTable() const
{
    return table;
}

//Used in test cases and testStringset() in main.cpp
int Stringset::getNumElems() const
{
    return num_elems;
}

//Used in test cases and testStringset() in main.cpp
int Stringset::getSize() const
{
    return size;
}

void Stringset::insert(string word)
{
std::hash<string>h;
int index = h(word) % size;
if(table[index].empty() != false){
    table[index].push_back(word);
}
else{
    for(std::list<string>::iterator i = table[index].begin(); i != table[index].end(); i++){
        if(*i == word){
            return;
        }
    }
    table[index].push_back(word);
}
if(size == num_elems){
    std::vector<list<string>> newTable(size*2);
    for(int i = 0; i < size; i++){
        for(std::list<string>::iterator j = table[i].begin(); j != table[i].end(); j++){
            newTable[h(*j) % (size * 2)].push_back(*j);
        }
    }
    table = newTable;
    size *= 2;
    num_elems++;
}
else{
    num_elems++;
}
}
bool Stringset::find(string word) const
{
std::hash<string>h;
int index = h(word) % size;
for(std::list<string>::const_iterator i = table[index].begin(); i != table[index].end(); i++){
    if(*i == word){
        return true;
    }
}
return false;
}


void Stringset::remove(string word)
{
std::hash<string>h;
int index = h(word) % size;
if(table[index].empty() != false){
    return;
}
else{
    for(std::list<string>::iterator i = table[index].begin(); i != table[index].end(); i++){
        if (*i == word){
            table[index].remove(word);
            num_elems--;
            return;
        }
    }
}

}