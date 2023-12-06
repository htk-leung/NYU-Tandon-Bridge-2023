// Q1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    using namespace std;

    int n;
    int evenNum = 2;


    // version 1 - while loop
    cout << "Please enter a positive integer: ";
    cin >> n;
    
    while (evenNum <= 2*n)
    {
        cout << evenNum << endl; 
        evenNum += 2; 
    }


    // version 2 - for loop
    cout << "Please enter a positive integer: ";
    cin >> n;
    evenNum = 2;

    for (int i = 0; i < n; i++)
    {
        cout << evenNum << endl;
        evenNum += 2;
    }

    return 0;
}
