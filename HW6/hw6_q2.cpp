// hl5737_hw6_q2
/*
Question 2:
A palindrome is a word, which reads the same backward or forward. 

a. Implement a function: bool isPalindrome(string str)
- given a string str containing a word
- returns true if and only if str is a palindrome.

b. Write a program that 
- reads a word from the user and 
- announces to the user if it is a palindrome or not.

Your program should interact with the user exactly as it shows in the following example:
Please enter a word: level
level is a palindrome
*/

#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string str);

int main() {
    string word; 

    cout << "Please enter a word: "; 
    cin >> word;

    bool palindrome = isPalindrome(word);

    if (palindrome) cout << word << " is a palindrome";
    else cout << word << " is not a palindrome";

    return 0;
}

bool isPalindrome(string str) {
    int n = str.length();
    for (int i = 0; i < (n / 2); i++) {
        if (str[i] != str[n - 1 - i]) return false;
    }
}