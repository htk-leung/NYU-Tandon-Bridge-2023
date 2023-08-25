// hl5737_hw7_q1.cpp

#include <iostream>
#include <string>
using namespace std;

bool is_letter(char c);
bool is_new_word(char c, char prev_c);
void count_char(char c, int c_count[]);
void print_c_count(int arr[], int len);
void read_char(string l, int c_count[], int& w_count);

const char COMMA = ',';
const char PERIOD = '.';
const char SPACE = ' ';
const char LINEEND = '\n';
const int CHAR_COUNT = 26;


int main() {
    int c_count[CHAR_COUNT];
    int w_count = 0;
    string l;

    for (int i = 0; i < 26; i++)
        c_count[i] = 0;

    cout << "Please enter a line of text:\n";
    getline(cin, l);
    read_char(l, c_count, w_count);
    
    // runtime theta(n)
    cout << w_count << '\t' << "words\n";
    print_c_count(c_count, CHAR_COUNT);

    return 0;
}


void read_char(string l, int c_count[], int& w_count) {
    char prev_c;
    prev_c = SPACE;

    for (char c : l) {
        if (is_letter(c)) {                                     // ' w'ord,
            if (is_new_word(c, prev_c)) {   
                w_count++;                                      // add word count
            }
            count_char(c, c_count);
        }
        
        prev_c = c;                                             // update
    }
}

void print_c_count(int arr[], int len) {                    // output letters in alphabetical order ONLY those that do occur
    for (int i = 0; i < len; i++)
        if (arr[i] != 0)
            cout << arr[i] << '\t' << (char)(i + 97) << endl;
}

void count_char(char c, int c_count[]) {
    int index;
    if (c >= 'a' && c <= 'z')
        index = c - 97;
    else
        index = c - 65;
    c_count[index]++;
}

bool is_letter(char c) {
    if (c == COMMA || c == PERIOD || c == SPACE)
        return false;
    return true;
}

bool is_new_word(char c, char prev_c) {
    if (is_letter(c) && !is_letter(prev_c))  
        return true;
    return false;
}