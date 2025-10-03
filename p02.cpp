// User inputs 2 sets, Program reads it, Prints the Cartesian product, subsets, intersection, and writes it all out into output data.
// ----------------------------------------------
// Author(s):   Beaux Dolf, Jacob Simon
// Email(s):    bdolf1@uco.edu , jacob41simon@uco.edu
// ----------------------------------------------


#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "Set.h"

#ifndef MAX_FILE_LENGTH
#define MAX_FILE_LENGTH 255
#endif  // --- MAX_FILE_LENGTH ---

using namespace std;  

// --- Handle command line error ---
struct CommandLineException {
    CommandLineException(int max, int provided)
    {
        cout << endl;
        cout << "The number of command line arguments doesn't match." << endl;
        cout << provided << " arguments were entered, and " << max << 
                " are required." << endl;
    }  
};


// --- Handle exception when openning file ---
struct FileException {
  FileException(const string file) {
    cout << endl << "'" << file << "'" << " could not be opened." << endl;
  }
};

// --- Read the input set from  input stream/ output the subsets to output stream ---
void get_subsets(Set &s1, ostream& o) {
	s1.print(o, "A=");  // --- print set to the output stream --- 

    int n = s1.getSize();                       
    int total = 1 << n;             
    o << "Subsets of A:" << endl;             

    for (int mask = 0; mask < total; ++mask) 
    { 
        o << "{";
        bool first = true;
        for (int i = 0; i < n; ++i) 
        {
            if (mask & (1 << i)) 
            {
                if (!first) o << ",";
                o << s1.getElement(i);
                first = false;
            }
        }
        o << "}" << endl;
    }

    if (total == 1)
        o << "There is " << total << " subset of A." << endl;
    else 
        o << "There are " << total << " subsets of A." << endl;

    o << "--------------------------------" << endl;
}

// --- Read the input sets from the input streams, and output the cartesian product of these two sets to the output stream. ---
void get_cartesian_product(Set &s1, Set &s2, ostream& o) {
	Set result;
	s1.print(o, "A = ");    // --- print set 1 to the output stream ---
    s2.print(o, "B = ");    // --- print set 2 to the output stream ---

    int count = 0;
    
    // --- implement cartesian product ---
    for (int i = 0; i < s1.getSize(); i++) 
    {
        for (int j = 0; j < s2.getSize(); j++) 
        {
            string pair = "(" + s1.getElement(i) + "," + s2.getElement(j) + ")"; 
            result.insert(pair);
            ++count;
        }
    }

    result.print(o, "A X B = ");    // print the result to the output stream
    if (count < 2) 
        o << "There is " << count << " element in the Cartesian Product." << endl;
    else 
        o << "There are " << count << " elements in the Cartesian Product." << endl;
    o << "--------------------------------" << endl;
}

void get_intersection(Set &s1, Set &s2, ostream& o) {
    Set result;
	s1.print(o, "A = ");    // print set 1 to the output stream
    s2.print(o, "B = ");    // print set 2 to the output stream

    // --- get intersection of the 2 sets ---
    for (int i = 0; i < s1.getSize(); i++)
    {
        string elem = s1.getElement(i);
        if (s2.find(elem) != -1)
        {
            result.insert(elem);
        }
    }

    // --- print the result to the output stream ---
    result.print(o, "A ∩ B = ");    
    o << "--------------------------------" << endl;
}

void manage_p02(istream& i1, istream& i2, ostream& o) {
    Set s1, s2;
	s1.scan(i1);            // read set 1 from the first input stream 1
    s2.scan(i2);            // read set 2 from the second input stream 2

    get_cartesian_product(s1, s2, o);
    get_subsets(s1, o);
    get_intersection(s1, s2, o);
}

int main(int argc, char* argv[]) {
    const int n_paramters = 3;
    try
    {
        char fn[n_paramters][MAX_FILE_LENGTH]; // --- i/o file names ---

        // --- if not proper amount of parameters from CL ---
        if (argc != n_paramters + 1) {
		    throw CommandLineException(n_paramters, argc - 1);
        }

        // copy necessary command line parameters
        for (int i = 0; i < n_paramters; i++) {
            strcpy(fn[i], argv[i+1]);
        }

        ifstream i1(fn[0]);
        ifstream i2(fn[1]);
        ofstream o(fn[2]);

        if (!i1)
            throw FileException(fn[0]);
        if (!i2)
            throw FileException(fn[1]);
        if (!o)
            throw FileException(fn[2]);

        manage_p02(i1, i2, o);

        i1.close();
        i2.close();
        o.close();
    }
    catch(...)
      {
        cout << "Program ended with exception." << endl;
        exit(EXIT_FAILURE);
      }
    return 0;
}
