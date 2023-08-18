// hl5737_hw6_q4
/*
Write a program to simulate the authentication process. 

- Store an actual 5-digit PIN number in your program (make one up, and store it as a constant). 
- The program should use an array to assign random numbers to the digits from 0 to 9. 
- Output the random digits to the screen, 
- input the response from the user, and 
- output whether or not the user’s response correctly matches the PIN number.

Assuming that the actual PIN number is 12345, your program should interact with the user
exactly as it shows in the following examples (2 different executions of the program):
Please enter your PIN according to the following mapping:
PIN: 0 1 2 3 4 5 6 7 8 9
NUM: 3 2 3 1 1 3 2 2 1 3
23113
Your PIN is correct
Please enter your PIN according to the following mapping:
PIN: 0 1 2 3 4 5 6 7 8 9
NUM: 1 1 2 3 1 2 2 3 3 3
23113
Your PIN is not correct
Note: Think how to break down your implementation to functions.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void assign_random_num(int arr_random[], int arrSize);
bool correct_pin(int input[], const int PIN[], int arr_random[], const int PIN_LEN);

int main() {
    srand(time(0));
    const int PIN_LEN = 5;
    const int PIN[] = {0,0,0,4,5}; // store as const int array!!!!
    int pin_in[5];
    char pin_digit;
    int num_random[10];
    int arrSize = 10;

    assign_random_num(num_random, arrSize);

    cout << "Please enter your PIN according to the following mapping:\n"
         << "PIN: 0 1 2 3 4 5 6 7 8 9 \n"
         << "NUM:";
    for (int i = 0; i < 10; i++)
        cout << ' ' << num_random[i];
    cout << endl;

    for (int i = 0; i < PIN_LEN; i++) {
        cin >> pin_digit;
        pin_in[i] = int(pin_digit) - 48;
    }
    
    if (correct_pin(pin_in, PIN, num_random, PIN_LEN))
        cout << "Your PIN is correct\n";
    else
        cout << "Your PIN is not correct\n"; 

    return 0;
}

void assign_random_num(int arr_random[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        arr_random[i] = (rand() % 3 + 1);
    }
}

bool correct_pin(int input[], const int PIN[], int arr_random[], const int PIN_LEN) {
    for (int i = 0; i < PIN_LEN; i++) {
        if (arr_random[PIN[i]] != input[i])
            return false;
    }
    return true;
}