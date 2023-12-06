#include <iostream>
using namespace std;

int lowestCost(int* arr, int low, int high);

int main() {
    int arr[] = {0, 57, 3, 80, 6, 10};
    int arrSize = 6;

    cout << "Minimum cost of game is " 
        << lowestCost(arr, 0, arrSize - 1) 
        << endl;

    return 0;
}

int lowestCost(int* arr, int low, int high) {
    
    if (low == high) // base case: when last column reached
        return arr[high];
    
    else { // recursive step: 
        if(low == high - 2) 
            return arr[low] + lowestCost(arr, low + 2, high);

        else if(low == high - 1)
            return arr[low] + lowestCost(arr, low + 1, high);

        else{
            if (arr[low + 1] < arr[low + 2]) 
                return arr[low] + lowestCost(arr, low + 1, high);
            else
                return arr[low] + lowestCost(arr, low + 2, high);
        }
    }
}