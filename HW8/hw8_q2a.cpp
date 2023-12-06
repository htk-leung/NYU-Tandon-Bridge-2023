#include <iostream>
using namespace std;

int sumOfSquares(int arr[], int arrSize) {
    if (arrSize == 1) 
        return arr[0] * arr[0];

    else {
        int i = arrSize - 1;
        return arr[i] * arr[i] + sumOfSquares(arr, i);
    }
}

int main() {
    int arr[] = {2, -1, 3, 10};
    int sum = sumOfSquares(arr, 4);
    
    cout << sum << endl;
    return 0;
}