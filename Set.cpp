#include "Set.h"

Set::Set()
{
    size = 0;
    capacity = 10;
    elements = new string[capacity];
}

Set::Set(const Set& other) 
{
    size = other.size;
    capacity = other.capacity;
    elements = new string[capacity];
    for (int i = 0; i < size; i++) elements[i] = other.elements[i];
}
void Set::resize()
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
void Set::insert(const string& elem)
{
}
bool Set::contains(const string& elem) const
{
    //--- iterate through array & check if it contians elem ---
    for(int i = 0; i < size; i++){
        if (elements[i] == elem){return true;}
        else{return false;}
    }
}
int Set::getSize() const
{

}
string Set::getElement(int index) const
{

}
Set Set::intersection(const Set& other) const
{

}
void Set::print(ostream& out) const
{

}