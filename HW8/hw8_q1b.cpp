#include <iostream>
using namespace std;

const char AST = '*';

void printOppositeTriangles(int n) {
    if (n == 1) 
        cout << AST << endl << AST << endl;
    
    else {
        for (int i = 0; i < n; i++) 
            cout << AST;
        cout << endl;  

        printOppositeTriangles(n - 1);

        for (int i = 0; i < n; i++) 
            cout << AST;
        cout << endl;  
    }
}

int main() {
    int n;
    cout << "Please enter a positive integer:\n";
    cin >> n;
    
    printOppositeTriangles(n);
    return 0;
}

