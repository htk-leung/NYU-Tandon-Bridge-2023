// hl5737_hw5_q4.cpp
/*
1. FUNCTION 1 void printDivisors (int num)
- given +ve int num
- print all of num's divisors in ascending order
- separated by space

2. program
- use function 1
- reads from user a +ve int >= 2
- output:

Please enter a positive integer >= 2: 100
1 2 4 5 10 20 25 50 100
*/

#include <iostream>
#include <cmath>

using namespace std;

void printDivisors (int);

int main() {
    int num;

    cout << "Please enter a positive integer >= 2: ";
    cin >> num;

    if (num < 2)
        cout << "Invalid input, only positive integers >= 2 accepted.\n"
            << "Program will exit now.\n";

    printDivisors(num);
    return 0;
}

void printDivisors (int num) {
    double root = sqrt(num);                                // root = max of loop
    double div_comp;
    for (int div = 1; div < root; div++) {                  // 1 to root - 1
        div_comp = num * 1.0 / div;
        if (div_comp - (int)div_comp == 0)
            cout << div << ' ';
    }

    for (int div = root; div >= 1; div--) {            // root to num
        div_comp = num * 1.0 / div;
        if (div_comp - (int)div_comp == 0)
            cout << div_comp << ' ';
    }
}
