/*
- 2 versions
- reads SEQUENCE of +ve int from user
- calculate geometric mean
- print geometric mean
*/

#include <iostream>
#include <cmath>

int main()
{
    using namespace std;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);

    // VERSION 1: count-controlled exit
    {
        int len, num;
        double geo_mean = 1;

        // get length of sequence
        cout << "Please enter the length of the sequence: ";
        cin >> len;

        // get sequence & product
        cout << "Please enter your sequence: \n";
        for (int i = 0; i < len; i++)
        {
            cin >> num;
            geo_mean *= num;
        }

        // geometric mean
        geo_mean = pow(geo_mean, 1.0 / len);
        cout << "The geometric mean is: " << geo_mean << endl;
    }


    // VERSION 2:
    {
        // declare vars
        int num;
        int len = 0;
        double geo_mean = 1;

        // get user input and calculate product
        cout << "Please enter a non-empty sequence of positive integers, each one in a separate line.\n"
            << "End your sequence by typing -1: \n";
        cin >> num;

        while (num > 0)
        {
            geo_mean *= num; // update product
            cin >> num; // update num to catch flag
            len++;
        }

        // geometric mean
        geo_mean = pow(geo_mean, 1.0 / len);
        cout << "The geometric mean is: " << geo_mean << endl;
    }

    return 0;
}
