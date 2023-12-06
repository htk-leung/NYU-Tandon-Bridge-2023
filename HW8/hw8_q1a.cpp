#include <iostream>
using namespace std;

const char AST = '*';

void printTriangle(int n) {
    if (n == 1) 
        cout << AST << endl;
    
    else {
        printTriangle(n - 1);
        for (int i = 0; i < n; i++) {
            cout << AST;
        }
        cout << endl;  
    }
}

int main() {
    int n;
    cout << "Please enter a positive integer:\n";
    cin >> n;
    
    printTriangle(n);
    return 0;
}

