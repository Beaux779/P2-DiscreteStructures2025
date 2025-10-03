# P2 – Discrete Structures 2025

## Project Overview
This program demonstrates set operations as part of a discrete mathematics assignment.  
The program:
- Reads two sets from input files  
- Prints their **Cartesian product**  
- Prints all **subsets** of the first set  
- Computes and prints their **intersection**  
- Writes all results to an output file  

---

## Files
- `p02.cpp` – Main driver program  
- `Set.h` – Class definition for the set  
- `Set.cpp` – Implementation of the `Set` class  
- `p02make` – Makefile to compile the project  
- `input1.dat` – Example input file for Set A  
- `input2.dat` – Example input file for Set B  
- `output.dat` – Example program output file  
- `p02.exe` – Precompiled executable (Windows)  

---

## Compilation

### Using make
`make -f p02make`

### Manual g++ Compilation (Windows PowerShell or CMD)
`g++ -g -c Set.cpp`  
`g++ -g -c p02.cpp`  
`g++ -o p02.exe p02.o Set.o`  

---

## Running
The program requires three command-line arguments:  
1. Input file for Set A  
2. Input file for Set B  
3. Output file for results  

**Example (Windows PowerShell):**  
`.\p02.exe input1.dat input2.dat output.dat`

---

## Example

### input1.dat
`1 2 3`

### input2.dat
`a b`

### output.dat
---

## Authors
- Beaux Dolf – bdolf1@uco.edu  
- Jacob Simon – jacob41simon@uco.edu  
