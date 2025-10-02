#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "Set.h"
using namespace std;

void readFile(const string& filename, Set& s) 
{
    ifstream in(filename.c_str());
    string word;
    while (in >> word) s.insert(word);
    in.close();
}

void printCartesianProduct(ofstream& out, const Set& A, const Set& B) 
{
    out << "A X B={";
    bool first = true;
    for (int i = 0; i < A.getSize(); i++) 
    {
        for (int j = 0; j < B.getSize(); j++) 
        {
            if (!first) out << ",";
            out << "(" << A.getElement(i) << "," << B.getElement(j) << ")";
            first = false;
        }
    }
}