/*
1. FUNCTION 1 void analyzeDividors(int num, int& outCountDivs, int& outSumDivs)
- takes as an input a positive integer num (≥ 2),
- return number of num's proper divisors
- return sum

2. FUNCTION 2 bool isPerfect(int num)
- given +ve int num
- determine if perfect number or not

3. use functions to write a program that reads a +ve int M from user
- print all perfect numbers between 2 and M
- print all paits of amicable numbers that are betweem 2 and M
** efficient algorithm would call analyzeDividors theta(M) times all together.
*/

#include <iostream>
#include <cmath>
using namespace std;

void analyzeDividors(int, int&, int&);
bool isPerfect(int);

int main() {
    int M, B;
    int ACountDivs, ASumDivs, BCountDivs, BSumDivs;
    ACountDivs = ASumDivs = BCountDivs = BSumDivs = 0;

    cout << "Please enter a positive integer >= 2: ";                       // user input
    cin >> M;

    if (M < 2)
    cout << "Invalid input, only positive integers >= 2 accepted.\n"        // valid input
        << "Program will exit now.\n";

    cout << "Perfect numbers between 2 and " << M << ": ";                  // perf num
    for (int A = 2; A <= M; A++) {        
        if (isPerfect(A))
            cout << A << ' ';
    }
    cout << endl;

    cout << "Amicable numbers between 2 and " << M << ": ";                 // amicable
    for (int A = 2; A <= M; A++) {        
        if (isPerfect(A)) continue;
        else {                                                  
            analyzeDividors(A, ACountDivs, ASumDivs);
            B = ASumDivs;
            analyzeDividors(B, BCountDivs, BSumDivs);
            if (BSumDivs == A && B <= M)
                cout << A << ' ';
        }
        ACountDivs = ASumDivs = BCountDivs = BSumDivs = 0;                  // refresh counts / sum
    }
    return 0;
}

bool isPerfect(int num) {
    int outCountDivs, outSumDivs;
    outCountDivs = outSumDivs = 0;

    analyzeDividors(num, outCountDivs, outSumDivs);

    if (num == outSumDivs)
        return true;
    return false;
}

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs) {
    double root = sqrt(num);
    double div_comp;

    for (int div = 1; div < root; div++) { // find sum 
        div_comp = num * 1.0 / div;
        if (div_comp - (int)div_comp == 0) {
                outSumDivs += div;                                      // add div
                outCountDivs++;                                         // add count
                if (div_comp != num) {
                    outSumDivs += div_comp;                             // add div_comp
                    outCountDivs++;                                     // add count
                }                                     
        }
    }
}