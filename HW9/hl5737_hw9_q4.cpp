// hl5737_hw9_q4

#include <iostream>
#include <vector>
using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize);

int main() {
    int arr[] = {5, 2, 11, 7, 6, 4};
    int arrSize = 6;

    oddsKeepEvensFlip(arr, arrSize);

    delete [] arr;
    return 0;
}

void oddsKeepEvensFlip(int arr[], int arrSize){
    // odd before even
    // odd num keep order
    // even num reversed order
    
    vector <int> odd; // odd in new array
    int oddCount = 0;
    vector <int> even; // even in new array
    int evenCount = 0;

    for (int i = 0; i < arrSize; i++){
        if(arr[i] % 2 == 1){
            odd.push_back(1);
            odd[oddCount] = arr[i];
            oddCount++;
        }
        else{
            even.push_back(1);
            even[evenCount] = arr[i];
            evenCount++;
        }
    }

    for (int i = 0; i < arrSize; i++){ // copy back >> or can i just change pointer??
        if(i < oddCount)
            arr[i] = odd[i];
        else
            arr[i] = even[arrSize - i - 1];
    }
}