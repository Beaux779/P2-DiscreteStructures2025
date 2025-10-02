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