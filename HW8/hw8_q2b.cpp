#include <iostream>
using namespace std;

bool isSorted(int arr[], int arrSize) {
    // base case : int 1 < int 2
    if (arrSize == 2) {
        return (arr[0] <= arr[arrSize - 1]);
    }
    
    // recursive case : int 3 < int 4 && int 4 < int 5
    else {
        return (arr[arrSize - 2] <= arr[arrSize - 1]) && isSorted(arr, arrSize - 1);
    }
}

int main() {
    // int arr[] = {-3, -1, 3, 10};
    int arr[] = {2, -1, 3, 10};
    bool sorted = isSorted(arr, 4);
    
    cout << "The array is " << (sorted ? "sorted." : "not sorted.") << endl;
    return 0;
}