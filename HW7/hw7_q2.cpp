// hl5737_hw7_q2.cpp

// Two strings are anagrams if the letters can be rearranged to form each other. 
// For example, “Eleven plus two” is an anagram of “Twelve plus one”. 
// Each string contains one ‘v’, three ‘e’s, two ‘l’s, etc.

// Write a program that determines if two strings are anagrams. 

// The program should not be case sensitive and 
// should disregard any punctuation or spaces.

//an efficient implementation would run in a linear time (that is Θ(𝑛)).


#include <iostream>
#include <string>
using namespace std;

void init_arr(int arr[], int len);
bool is_letter(char c);
void count_char(char c, int c_arr[]);
void read_char(string l, int c_arr[]);
bool is_anagram(int arr1[], int arr2[], int len);

const int CHAR_NUM = 26;
const char SPACE = ' ';
const char LINEEND = '\n';

int main() {
    int arr1[CHAR_NUM];
    int arr2[CHAR_NUM];
    string l;

    init_arr(arr1, CHAR_NUM);
    init_arr(arr2, CHAR_NUM);

    cout << "Please enter the first string in 1 line:\n";
    getline(cin, l);
    read_char(l, arr1);

    cout << "Please enter the second string in 1 line:\n";
    getline(cin, l);
    read_char(l, arr2);

    bool anagram = is_anagram(arr1, arr2, CHAR_NUM);
    cout << "These two strings are" << (anagram ? " " : " not ") << "anagrams.\n";
    
    return 0;
}

void init_arr(int arr[], int len) {
    for (int i = 0; i < len; i++)
        arr[i] = 0;
}

void read_char(string l, int c_count[]) {
    for (char c : l) {
        count_char(c, c_count);
    }
    l.erase();
}

void count_char(char c, int c_count[]) { // The program should not be case sensitive
    int index;
    if (c >= 'a' && c <= 'z') { // if lower case
        index = c - 97;
        c_count[index]++;
    }
    else if (c >= 'A' && c <= 'Z') { // if upper case
        index = c - 65;
        c_count[index]++;
    } // disregard any punctuation or spaces.
}

bool is_anagram(int arr1[], int arr2[], int len) {
    for (int i = 0; i < len; i++) {
        if (arr1[i] != arr2[i])
            return false;
    }
    return true;
}