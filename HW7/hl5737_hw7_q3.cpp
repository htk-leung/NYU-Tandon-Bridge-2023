// hl5737_hw7_q3.cpp

// correct, but can it be shorter???

#include <iostream>
#include <vector>
using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize);
void print_arr(int arr[], int arrSize);

int main() {
    int arr[] = {5,2,11,7,6,4}; // replace with user input?
    int arrSize = 6;

    oddsKeepEvensFlip(arr, arrSize);
    print_arr(arr, arrSize);

    return 0;
}

void print_arr(int arr[], int arrSize) {
    cout << "{ ";
    bool is_last = false;
    for (int i = 0; i < arrSize; i++) {
        if (i == arrSize - 1) is_last = true;
        cout << arr[i] << (is_last ? " }" : ", ");
    }
}

void oddsKeepEvensFlip(int arr[], int arrSize) {   
    int oddInd = 0;
    int evenInd = 0;
    vector <int> odd;
    vector <int> even;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] % 2 == 1) {
            odd.push_back(1);
            odd[oddInd] = arr[i];
            oddInd++;
        }
        else {
            even.push_back(1);
            even[evenInd] = arr[i];
            evenInd++;
        }
    }
    for (int i = 0; i < oddInd; i++)
        arr[i] = odd[i];

    int temp = evenInd - 1;
    for (int i = 0; i < evenInd; i++) {
        arr[i + oddInd] = even[temp];
        temp--;
    }
}