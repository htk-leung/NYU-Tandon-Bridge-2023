#include <iostream>
#include <string>
#include <vector>
using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize);

int main() {
    string s;
    int wArrSize = 0;

    cout << "Please enter a sentence:\n";
    getline(cin, s);
    
    string *wArr = createWordsArray(s, wArrSize);
    for (int i = 0; i < wArrSize; i++) 
        cout << wArr[i] << endl;
    cout << "Size = " << wArrSize;

    delete [] wArr;
    return 0;
}

// A::: 
string* createWordsArray(string sentence, int& outWordsArrSize) {
    int sLen = sentence.length();
    string str;
    vector <string> wordVarr;

    int pos1, pos2;
    pos1 = 0;

    for (int i = 0; i < sLen; i++) {
        if (i == sLen - 1 || sentence[i] == ' ') {
            pos2 = ((i == sLen - 1) ? i + 1 : i);
            wordVarr.push_back(str);
            wordVarr[outWordsArrSize] = sentence.substr(pos1, (pos2 - pos1)); // parse into arr
            outWordsArrSize++;
            pos1 = pos2 + 1;
        }
    }

    string *wArr = new string [outWordsArrSize];
    for(int i = 0; i < outWordsArrSize; i++)
        wArr[i] = wordVarr[i];

    return wArr; // return a NEW array of strings with all words in sentence
}