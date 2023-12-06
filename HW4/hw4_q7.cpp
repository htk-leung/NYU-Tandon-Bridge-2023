// Q7.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
* reads a positive integer n
* prints out a n x n multiplication table
* columns spaced by a tab
*/

#include <iostream>

int main()
{
    using namespace std;
    
    // declare variables
    int n;

    // get user input
    cout << "Please enter a positive integer:\n";
    cin >> n;

    for (int i = 1; i <= n; i++) // for each row up to nth row
    {
        for (int j = 1; j <= n; j++) // for loop to print each product up to nth product
            cout << i * j << '\t';
        
        cout << endl; // end with new line and 
    }

    return 0;
}
