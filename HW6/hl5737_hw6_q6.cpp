// hl5737_hw6_q6
/*
Write a program that 
- reads in a line of text and 
- outputs the line 
- with all the digits in all integer numbers replaced with 'x'.

Please enter a line of text:
My userID is john17 and my 4 digit pin is 1234 which is secret
My userID is john17 and my x digit pin is xxxx which is secret
Notes:
1. If a digits is part of a word, then the digit is not changed to an 'x'. For example, john17 is
NOT changed to johnxx.
2. You may assume that the text entered by the user will contain only letters (upper case or
lower case), digits and spaces.
3. Think how to break down your implementation to functions.
*/

#include <iostream>
#include <string>

using namespace std;

void change_line(string& line, int strLen);
void replace_num(string& line, string temp, int Wordlen, int pos);
bool should_replace (string temp, int wordLen);

int main() {
    string line;
    cout << "Please enter a line of text:\n";
    getline(cin, line);

    int strLen = line.length();
    change_line(line, strLen);

    cout << line << endl;
    return 0;
}

void change_line(string& line, int strLen) {
    int i = 0;
    int wordLen;
    string temp;

    while (i < strLen) { // check each letter in line
        if (line[i] == ' ') 
            i++;
        else {
            while (line[i] != ' ' && i < strLen){ // get word
                temp += line [i]; 
                i++;
            }
            wordLen = temp.length();
            bool should = should_replace(temp, wordLen);
            if (should_replace(temp, wordLen)) // execute if no letter
                replace_num(line, temp, wordLen, i);
 
            temp.erase(0, wordLen); // reset
        }
    }
}

bool should_replace (string temp, int wordLen) {
    for (int j = 0; j < wordLen; j++){ // if word has a letter, break and next word
        if (temp[j] >= 'a' && temp[j] <= 'z' || temp[j] >= 'A' && temp[j] <= 'Z'){
            return false;
        }
    }
    return true;
}

void replace_num(string& line, string temp, int wordLen, int pos) {
    for (int j = (pos - wordLen); j < pos; j++)
        line[j] = 'x';
}