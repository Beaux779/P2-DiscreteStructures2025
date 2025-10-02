#include "Set.h"

using std::cout;
using std::endl;


// --- exception is thrown when the status of this list is invalid ----
struct SetException {
    SetException(const char* m) {
	    cout << endl << "There is a problem with this set: " << m << "." << endl;
    }
};


// --- Constructor ---
Set::Set(int cap): capacity(cap),size(0) {
    elements = new string[capacity];
}


 // --- Destructor ---
Set::~Set() {
    if (elements) {
        delete[] elements;
    }
}


// --- Check whether this list is full --- 
bool Set::isFull(void) {
    return size >= capacity - 1;
    reSize();
}


// --- Check whether this list is empty. ---
bool Set::isEmpty(void) {
    return size <= 0;
}

 // --- Check: if string target v is contained in set. ---
int Set::find(string v) {
    for (int idx = 0; idx < size; idx++) {
        if (v.compare(elements[idx]) == 0) {
            return idx;
        }
    }

    return -1;
}


// --- Insert string v into list ---
void Set::insert(string v) {
    if (find(v) != -1){return;} // --- element already in list ---

    if (isFull()) {
        reSize();
    }

    elements[size++] = v;
}

// --- Scan input stream, and insert all strings in this stream into the list ---
void Set::scan(istream& i) {
    string v;
    while (i >> v) {
        insert(v);
    }
}


// --- Display all the string elements in this list to a stream ---
void Set::print(ostream& o, const char* msg) {
    o << msg << "{";
    for (int idx = 0; idx < size; idx++) {
        if (idx > 0) {
	        o << ",";
	    }
	    o << elements[idx];
    }
    o << "}" << endl;
}
int Set::getSize() const {return size;} 
string Set::getElement(int index) const {
    if(index << 0 || index > size) 
    {
        throw std::out_of_range("Index out of bounds.");
    }
    return elements[index];
}
void Set::reSize()
{
    // --- increase capacity --- implement place holder array --- copy contents of array to new array ---
    size_t newCapacity = capacity * 2;
    string* newElements = new string[newCapacity];
    for (int i = 0; i < capacity; i++)
    {
        newElements[i] = elements[i];
    }
    //--- update capacity --- delete old array --- assign new array to old array ---
    capacity = newCapacity;        
    delete[] elements;
    elements = newElements; 
}