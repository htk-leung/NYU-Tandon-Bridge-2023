// hl5737_hw5_q2.cpp 
/*
Write a program that, prints a 'pine tree' consisting of triangles of increasing sizes
- in any symbol of choice

- read num of triangles of tree
- void printShiftedTriangle(x,y,z) print 1 triangle
    x = rows
    y = min shift space
    z = char to print

- void printPineTree(x, y) - loop the structure
    x = num triangles
    y = char to print
    each triangle: 2n-1 chars
*/

#include <iostream>

using namespace std;

void printShiftedTriangle(int, int, char);
void printPineTree(int, char);


int main()
{
    int tri;
    char symbol;

    cout << "Please enter the number of triangles desired in the pine tree: ";
    cin >> tri;
    cout << "And what symbol you would like to print it in: ";
    cin >> symbol;

    if (tri <= 0) {
        cout << "Invalid input: number of triangles must be a positive integer.\n";
        cout << "Program will exit now.\n";
        return 1;
    }

    printPineTree(tri, symbol);                         // call function
    return 0;
}

void printPineTree(int n, char symbol) {                // loops for triangle
    int count = 1;
    int shift = n - 1;

    while (count <= n) {
        printShiftedTriangle(count + 1, shift, symbol);
        count++;
        shift--;
    }
    return;
}

void printShiftedTriangle(int n, int m, char symbol) {  // each triangle
    const char SPACE = ' ';

    for (int row = 1; row <= n; row++) {                // each row
        for (int col = 1; col <= m; col++) {            // shift
            cout << SPACE;
        }
        for (int col = 1; col <= 2 * n - 1; col++) {    // triangle
            if (row + col > n && col < n + row)
                cout << symbol;
            else
                cout << SPACE;         
        }
        cout << endl;
    }
    return;
}