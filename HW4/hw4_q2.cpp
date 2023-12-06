#include <iostream>
#include <string>

int main()
{
    using namespace std;

    int deci_num, remainder;
    string roman_num;
    int c, x, i;
    c = x = i = 0;

    // user input
    cout << "Enter decimal number:\n";
    cin >> deci_num;
    remainder = deci_num;

    // M
    while (remainder >= 1000)
    {
        roman_num = roman_num + "M"; // concatenate
        remainder = remainder - 1000; // R
    }


    // D
    if (remainder >= 500)
    {
        roman_num = roman_num + "D"; // D
        remainder = remainder - 500; // R
    }


    // C : -100 until deci_num < 0 or count = 4
    while ((remainder >= 100) && (c < 4))
    {
        roman_num = roman_num + "C"; // concatenate
        remainder = remainder - 100; // R
        c++;
    }


    // L
    if (remainder >= 50)
    {
        roman_num = roman_num + "L"; // L
        remainder = remainder - 50; // R
    }


    // X
    while ((remainder >= 10) && (x < 4))
    {
        roman_num = roman_num + "X"; // concatenate
        remainder = remainder - 10; // R
        x++;
    }


    // V 
    if (remainder >= 5)
    {
        roman_num = roman_num + "V"; // V
        remainder = remainder - 5; // R
    }


    //I
    while ((remainder >= 1) && (i < 4))
    {
        roman_num = roman_num + "I"; // concatenate
        remainder = remainder - 1; // R
        i++;
    }

    cout << deci_num << " is " << roman_num << endl;

    return 0;
}
