// Q6.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
- ask user to input positive integer n
- print all of the numbers from 1 to n
that have more even digits than odd digits
*/

#include <iostream>

int main()
{
    using namespace std;

    // declare vars
    int n;

    // get user input and store into n
    cout << "Please enter a positive integer: ";
    cin >> n;

    // for each number up to n
    for (int i = 1; i <= n; ++i)
    {
        int even, odd, r, temp;
        even = odd = 0;
        temp = i;

        // determine number of digits of i has --> loop that also counts parity distribution
        while(temp > 0)
        {
            r = temp % 10;      // get lowest digit

            if (r % 2 == 0)      // determine parity of each digit - if branch
                even++;         // add parity count
            else
                odd++;

            temp = temp / 10;   // update temp
        }

        if (even > odd) // if even > odd, cout i
            cout << i << endl;
    }
    
    return 0;
}
