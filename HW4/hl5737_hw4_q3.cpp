// Q3_redo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    using namespace std;

    // declare vars
    int num, temp1, temp2, digits;

    // get user input
    cout << "Enter decimal number: \n";
    cin >> num;
    temp1 = temp2 = num;
    digits = 0;
    

    // case 1 - num = 0, program ends here
    if (num == 0)
    {
        cout << "The binary representation of 0 is 0" << endl;
        return 0;
    }

    // case 2 - num >= 1
    // figure out max power of 2
    while (temp1 > 0)
    {
        temp1 = temp1 / 2;
        digits++;
    }
        
    // get 2 to power of digits, 2^0=1 by default
    int pow_2 = 1;
    for (int j = 1; j < digits; j++)
        pow_2 *= 2;

    // print first part of output
    cout << "The binary representation of " << num << " is ";

    // for each power get remainder and print number
    for (int i = digits; i > 0; --i)
    {
        if (pow_2 <= temp2) // if pow2 <= temp2, print 1
        {
            cout << "1"; 
            temp2 -= pow_2; //update temp2
        }
        else // else, print 0
            cout << "0";

        // update pow_2
        pow_2 = pow_2 / 2;
    }

    // new line after loop ends
    cout << endl;
    return 0;
}
