// hl5737_hw5_q6.cpp
/*
e = 1 + 1/1! + 1/2! + 1/3! + 1/4! + ....

approx 2.71828

FUNCTION double eApprox(int n)
- given a +ve int n
- returns approximation of e
- with first n+1 addends of the infinite sum
*/

#include <iostream>
#include <cmath>

using namespace std;

double eApprox(int n);

int main() {
    cout.precision(30);

    for (int n = 1; n <= 15; n++) {
        cout<<"n = "<<n<<'\t'<<eApprox(n)<<endl;
    }
    return 0;
}

double eApprox(int n) {
    double factN = 1;
    double factSum = 1;

    for (int i = 1; i <= n; i++) {
        factN *= i;                                 // calculate 1! = factN * 1(i)
        factSum += 1 / factN;
    }
    return factSum;
}