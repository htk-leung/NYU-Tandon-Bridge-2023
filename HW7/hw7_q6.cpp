#include <iostream>
#include <string>
#include <vector>

using namespace std;

void main1();
void main2();
void search_num_arr(int* arr, int arrSize, int num);
void search_num_varr(vector<int> arr, int arrSize, int num);
int ask_for_num();

int main() {

    main1();
    main2();
    
    return 0;
}

void main2() {
    vector <int> seqVarr;
    int seqnum;
    int count = 0;

    cout << "Please enter a sequence of positive integers, each in a separate line.\n"
        << "End your input by typing -1.\n";
    cin >> seqnum;

    while (seqnum != -1) {
        seqVarr.push_back(1);
        seqVarr[count] = seqnum;
        cin >> seqnum;
        count++;
    }

    int num = ask_for_num();
    int *seqArr = new int [count];
    for (int i = 0; i < count; i++)
        seqArr[i] = seqVarr[i];
    search_num_varr(seqVarr, count, num);
    delete [] seqArr;
}

void main1() {
    string seqnum, seq;
    int count;

    cout << "Please enter a sequence of positive integers, each in a separate line.\n"
        << "End your input by typing -1.\n";

    getline(cin, seqnum); // get user input
    while (seqnum != "-1") {
        seq += seqnum;
        seq += '/';
        count++;
        getline(cin, seqnum);
    }

    int *seqArr = new int [count]; // dynamic array
    int seqint = 0;
    int arrIndex = 0;

    for (char c: seq) {
        if (c != '/')  // until c reaches a /
            seqint = seqint * 10 + ((int)(c) - 48); // get each digit
        
        else {
            seqArr[arrIndex] = seqint; // add to list
            seqint = 0; // reset
            arrIndex++; // update index
        }
    }
    
    int num = ask_for_num();
    search_num_arr(seqArr, count, num);
    delete [] seqArr;
}

int ask_for_num() {
    int num;
    cout << "Please enter a number you want to search:\n";
    cin >> num;

    return num;
}

void search_num_arr(int* arr, int arrSize, int num) {
    bool firstfind = true;
    cout << num << " shows in lines";

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == num) {
            if (firstfind) {
                cout << " " << (i + 1) ;
                firstfind = false;
            }
            else cout << ", " << (i + 1);
        }
    }
    cout << '.' << endl;
}

void search_num_varr(vector<int> arr, int arrSize, int num) {
    bool foundone = false;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == num) {
            if (!foundone) {
                cout << num << " shows in lines " << (i + 1) ;
                foundone = true;
            }
            else cout << ", " << (i + 1);
        }
    }

    if (!foundone) cout << num << "does not show in the sequence";

    cout << '.' << endl;
}