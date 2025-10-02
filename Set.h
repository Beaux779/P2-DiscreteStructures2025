#ifndef SET_H
#define SET_H

#include <string>
#include <iostream>
using namespace std;

class Set 
{

    private:
        string* elements;
        int size;
        int capacity;
        void resize();

    public:
        Set();          //default constructor
        Set(const Set& other);          //copy constructor
        ~Set();     //destructor
        Set& operator=(const Set& other);   //assignment operator
        void insert(const string& elem);    //insert element
        bool contains(const string& elem) const; //check if element is in set
        int getSize() const; //get number of elements in set
        string getElement(int index) const; //get element at index
        Set intersection(const Set& other) const; //intersection of two sets
        void print(ostream& out) const; //print elements of set
};

#endif