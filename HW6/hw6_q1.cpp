// hl5737_hw6_q1
/*
Implement function: int minInArray(int arr[], int arrSize)
This function is given arr, an array of integers, and its logical size, arrSize. When called,
it returns the minimum value in arr.
*/

#include <iostream>
using namespace std;

int minInArray(int arr[], int arrSize);

int main() {
    int SIZE = 5;
    int arr[5] = {1, 400, -30, 3920, 87};
    int min;

    min = minInArray(arr, SIZE);
    cout << min << endl;
    return 0;
}

int minInArray(int arr[], int arrSize) {
    int min_temp = 0;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] < min_temp) 
            min_temp = arr[i] ;
    }

    return min_temp;
}