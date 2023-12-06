// hl5737_hw6_q3
/*
Implement following functions:

a. void reverseArray(int arr[], int arrSize)
- reorders the elements of the array to appear in a reverse order.
e.g. if arr is an array containing [1, 2, 3, 4], after calling reverseArray, 
    arr will look like: [4, 3, 2, 1].

***b. void removeOdd(int arr[], int& arrSize)
- alters arr so that the only numbers in it at the end are the even ones, 
- which should remain in their original relative order.
- updates arrSize so it contains the new logical size of the array
- after removing the odd numbers (note that arrSize is a parameter used both for input and output).
e.g. if arr is an array containing [1, 2, 3, 4], after calling removeOdd, 
    arr will look like: [2, 4], and the parameter arrSize will update to 2. 
    Notice the values in arr[2] and arr[3] are discarded.

c. void splitParity(int arr[], int arrSize)
- changes the order of numbers in arr so that all the odd numbers will appear first, and 
- all the even numbers will appear last. 
- Note that the inner order of the odd numbers and the inner order of the even numbers don’t matter.
e.g. if arr is an array containing [1, 2, 3, 4], after calling splitParity, 
    arr could look like: [3, 1, 2, 4].
*/

void splitParity(int arr[], int arrSize) {
    int i = 0;
    int j = arrSize; 
    int temp;

    while (i < j) {
        while (i < j && arr[i] % 2 == 1) 
            i++;
        while (i < j && arr[j] % 2 == 0) 
            j--;
        if (i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
}

void removeOdd(int arr[], int& arrSize) {
    int new_index = 0;
    int newSize = arrSize;
    for (int i = 0; i < newSize; i++) {
        if (arr[i] % 2 == 0) {
            arr[new_index] = arr[i];
            new_index++;
        }
        else
            arrSize--;
    }
}

void reverseArray(int arr[], int arrSize) {
    int temp;
    for (int i = 0; i < arrSize / 2; i++) {
        temp = arr[i];
        arr[i] = arr[arrSize - 1 - i];
        arr[arrSize - 1 - i] = temp;
    }
}