// hl5737_hw7_q7.cpp

#include <iostream> 
using namespace std;

int* findMissing(int arr[], int n, int& resArrSize);

int main() {
    int arr[] = {5, 0, 0, 4, 1};
    int n = 5;
    int resArrSize = 0;

    int *missingArr = findMissing(arr, n, resArrSize);

    cout << "Array of missing numbers: [ ";
    for (int i = 0; i < resArrSize; i++){
        if (i > 0 && i < resArrSize) 
            cout << ", " << missingArr[i];
        else // i == 0
            cout << missingArr[i];
    }
    cout << " ]." << endl;

    delete [] missingArr;
    return 0;
}

int* findMissing(int arr[], int n, int& resArrSize) {
    // gets arr = 3,1,3,0,6,4
    // XXX start from 0, find 0 in array >> runtime will be n^2
    // run through array, each number, index++
    // print all whose count == 0
    int *logArr = new int [n + 1]; // full logarr

    for (int i = 0; i < n + 1; i++)
        logArr[i] = 0;

    for (int i = 0; i < n; i++){ // log 0s
        logArr[arr[i]]++;
    }

    for (int i = 0; i < n + 1; i++)
    {
        cout << logArr[i] << endl;
    }

    for (int i = 0; i < n + 1; i++) { // count 0s from log
        if (logArr[i] == 0)
            resArrSize++;
    }
    
    int *missingArr = new int [resArrSize]; // new arr
    int ind = 0;

    for (int i = 0; i < n + 1; i++) { // copy arr from log
        if (logArr[i] == 0) {
            missingArr[ind] = i;
            ind++;
        }
    }
    
    delete [] logArr;
    return missingArr;
}