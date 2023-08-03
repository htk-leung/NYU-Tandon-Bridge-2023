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
    

    // figure out max power of 2
    /*
    loop 1      76 / 2      38          digit 1     0
    loop 2      38 / 2      19          digit 2     0
    loop 3      19 / 2      9           digit 3     1
    loop 4      9 / 2       4           digit 4     1
    loop 5      4 / 2       2           digit 5     0
    loop 6      2 / 2       1           digit 6     0
    loop 7      1 / 2       0           digit 7     1
    loop 8      //
    */

    while (temp1 > 0)
    {
        temp1 = temp1 / 2;
        digits++;
    }

    // case 1 - num = 0 / 1, program ends here
    if (num == 0)
    {
        cout << "The binary representation of 0 is 0" << endl;
        return 0;
    }
    else if (num == 1)
    {
        cout << "The binary representation of 1 is 1" << endl;
        return 0;
    }
        
    // case 2 - num >= 2, get 2 to power of digits
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
            cout << "1"; //update temp2
            temp2 -= pow_2;
        }
        else // else, print 0
            cout << "0"; //update temp2

        // update pow_2
        pow_2 = pow_2 / 2;
    }

    // new line after loops
    cout << endl;
    return 0;
}
