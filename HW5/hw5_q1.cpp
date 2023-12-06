/*
Fibonacci numbers: F_n = F_n-1 + F_n-2

- Write a FUNCTION int fib(int n) that 
  returns the n-th element of the Fibonacci sequence.

- Write a PROGRAM that prompts the user to enter a positive integer num, and then
  prints the num�s elements in the Fibonacci sequence.
*/

#include <iostream>
using namespace std;

int fib(int n);
// function to return nth num of a Fibonacci series
// input n, output num

int main() {
    int n, num;                                     // vars

    cout << "Please enter a positive integer: ";    // get user input
    cin >> n;

    if (n <= 0) {
        cout << "Invalid input. Program will exit now.";
        return 0;
    }
    
    num = fib(n);                                   // call function
    cout << num;                                    // print return value
}

int fib(int n) {
    int n_minus1, n_minus2, num;
    n_minus2 = 0;
    n_minus1 = 1;

    if (n == 1) return 1;

    for (int n_cnt = 2; n_cnt <= n; n_cnt++) {      // loop n times
        num = n_minus2 + n_minus1;                  // num of loop n
        n_minus2 = n_minus1;                        // swap values for next loop
        n_minus1 = num;
    }
    return num;
}