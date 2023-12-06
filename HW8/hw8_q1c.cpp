#include <iostream>
using namespace std;

const char DASH = '-';

void printRuler(int n) {
    if (n == 1) 
        cout << DASH << endl;
    
    else {
        printRuler(n - 1);

        for (int i = 0; i < n; i++) 
            cout << DASH;
        cout << endl;  

        printRuler(n - 1);
    }
}

int main() {
    int n;
    cout << "Please enter a positive integer:\n";
    cin >> n;
    
    printRuler(n);
    return 0;
}

