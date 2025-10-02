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
        Set();
        Set(const Set& other);
        ~Set();
        Set& operator=(const Set& other);

        void insert(const string& elem);
        bool contains(const string& elem) const;
        int getSize() const;
        string getElement(int index) const;
        Set intersection(const Set& other) const;
        void print(ostream& out) const;
};

#endif