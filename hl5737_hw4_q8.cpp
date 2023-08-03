// Q8.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
- number guessing game
- program randomly choose an integer between 1 and 100 (inclusive)
- and have the user try to guess that number

implementations guidelines:
- max 5 guesses
- before each guess announce: 
  An updated guessing-range, taking in to account previous guesses and responses.
  The number of guesses that the user has left.
- correct guess:
  announce
  tell how many guesses user used
- guessed wrong, there are still guesses left
  tell go bigger or smaller
- guessed wrong, no guesses left
  reveal number

*/

#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    using namespace std;

    // declare vars
    int x1, x2, x3, x4;
    int low, high, count, guess;
    low = 1;
    high = 100;
    count = 5;
    
    // seeding and generating random number 1-100
    srand(time(0));
    x1 = rand();
    x2 = rand();
    x3 = rand() % 100;
    x4 = (rand() % 100) + 1;

    cout << "I thought of a number between 1 and 100! Try to guess it.\n";

    // max 5 guesses do while loop for incorrect ans
    do 
    {
        cout << "Range: [" << low << ", " << high 
            << "], Number of guesses left: " << count << endl;
        cout << "Your guess: ";
        cin >> guess; // take a guess

        count--; // update count

        if (count == 0) // out of guesses, my number is...
        {
            cout << "Out of guesses! My number is " << x4 << endl;
            return 0;
        }

        else if (x4 > guess) // ouput message
        {
            low = guess; // update range
            cout << "Wrong! My number is bigger.\n";
        }
            
        else if (x4 < guess)
        {
            high = guess; // update range
            cout << "Wrong! My number is smaller.\n";
        }

        else
        {
            cout << "Congrats! You guessed my number in " << 5 - count << " guesses.\n";
            return 0;
        }
        cout << endl;

    } while ((guess != x4) && (count > 0)); // exit loop: guess correct or out of guesses

    return 0;
}
