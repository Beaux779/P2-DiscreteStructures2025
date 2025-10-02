#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using std::string;
using std::istream;
using std::ostream;

class Set
{
  private:
    int capacity;   // --- Capacity of the set, e.g. max number of available elements ---
    int size;       // --- size of the set ---
    string* elements;      // --- Pointer to a string array, used to implement this set ---
    void reSize();
  public:
    Set(int cap = 100);
    ~Set();
    bool isFull(void);    // --- Check if this set reaches capacity ---
    bool isEmpty(void);   // --- Check if set is empty ---
    int find(string v);   // --- Find index of specific string in set ---
    void insert(string v);    // --- Insert single element to set ---
    void scan(istream& i);    // --- Read elements from an input stream ---
    void print(ostream& o, const char* msg);   // --- Print all the elements of set ---
    int getSize() const; // --- return size of arr ---
    string getElement( int index ) const; // --- return desired element from index ---
     
  };


  