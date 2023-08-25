//hl5737_hw7_q5.cpp

#include <iostream>
#include <vector>

using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);
void print_arr(int* arr, int arrSize, int ver);


int main() {
    int arr[] = {-50,20,100,-1598,-257761,0,13};
    int arrSize = 7;

    int newArr1Size = 0;
    int *newArr1 = getPosNums1(arr, arrSize, newArr1Size);
    print_arr(newArr1, newArr1Size, 1);
    delete [] newArr1;

    int newArr2Size = 0;
    int *newArr2 = getPosNums2(arr, arrSize, &newArr2Size);
    print_arr(newArr2, newArr2Size, 2);
    delete [] newArr2;

    int newArr3Size = 0;
    int *newArr3;
    getPosNums3(arr, arrSize, newArr3, newArr3Size);
    print_arr(newArr3, newArr3Size, 3);
    delete [] newArr3;

    int newArr4Size = 0;
    int *newArr4;
    getPosNums4(arr, arrSize, &newArr4, &newArr4Size);
    print_arr(newArr4, newArr4Size, 4);
    delete [] newArr4;

    return 0;
}


void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {
    // uses pointer outPosArrPtr to update the base address of the array containing the positive numbers 
    // update base address of pointer outPosArrSizePtr to update the array’s logical size.
    
    for (int i = 0; i < arrSize; i++){
        if (arr[i] > 0) 
            *outPosArrSizePtr += 1;
    }

    int arrIndex = 0;
    *outPosArrPtr = new int [*outPosArrSizePtr]; 
    // dereference pointer of pointer to array to get a pointer to array

    for (int j = 0; j < arrSize; j++){
        if (arr[j] > 0){
            *(*outPosArrPtr + arrIndex) = arr[j]; 
            // leave as pointer : pointer to (pointer to (array))
            // access value : dereference (dereference (pointer to element))
            // **(outPosArrPtr + arrIndex) WRONG because outPosArrPtr is NOT pointing to arr
            // adding outPosArrPtr = arrIndex does NOT point to arrIndex-th element in arr
            arrIndex++;
        }
    }
}


void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) { // you actually don't need the &
    // updates outPosArr with the base address of the array (containing the positive numbers)
    // update parameter outPosArrSize with the array’s logical size.
    // *& means reference to a pointer, means the var itself is the original pointer value
    
    for (int i = 0; i < arrSize; i++){
        if (arr[i] > 0) 
            outPosArrSize += 1;
    }

    int arrIndex = 0;
    outPosArr = new int [outPosArrSize]; 
    // no need to declare new array since original pointer to arr is passed in

    for (int j = 0; j < arrSize; j++){
        if (arr[j] > 0){
            outPosArr[arrIndex] = arr[j];
            arrIndex++;
        }
    }
    // no need to return since it's a void function
}


int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr) {
    // cout << "value with *: " << (*outPosArrSizePtr) << endl; >> 0
    // cout << "value without *: " << outPosArrSizePtr << endl; >> 0x5ffe58
    // ?cout << "value with &: " << (&outPosArrSizePtr) << endl; why is it illegal?

    for (int i = 0; i < arrSize; i++){ 
        if (arr[i] > 0) 
            *outPosArrSizePtr += 1;
    }

    int arrIndex = 0;
    int* arrPos = new int [*outPosArrSizePtr]; // dereference pointer to get value

    for (int j = 0; j < arrSize; j++){
        if (arr[j] > 0){
            arrPos[arrIndex] = arr[j];
            arrIndex++;
        }
    }
    return arrPos;
}


int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {
    // returns the base address of the array (containing the positive numbers), and 
    // updates the output parameter outPosArrSize with the array’s logical size.

    // vector <int> varrPos; // approach 1 : vectors >> dynamic array

    // for (int i = 0; i < arrSize; i++) {
    //     if (arr[i] > 0)
    //     {
    //         varrPos.push_back(1);
    //         varrPos[outPosArrSize] = arr[i];
    //         outPosArrSize++; // updates the output parameter outPosArrSize with the array’s logical size.
    //     }
    // }

    // int *arrPos = new int [outPosArrSize];
    // for (int i = 0; i < outPosArrSize; i++) {
    //     arrPos[i] = varrPos[i];
    // }
    
    // return arrPos;

    for (int i = 0; i < arrSize; i++){ 
        // approach 2: dynamic array straight away, just need to run loop twice
        if (arr[i] > 0) 
            outPosArrSize++;
    }

    int arrIndex = 0;
    int* arrPos = new int [outPosArrSize];

    for (int j = 0; j < arrSize; j++){
        if (arr[j] > 0){
            arrPos[arrIndex] = arr[j];
            arrIndex++;
        }
    }
    return arrPos;
}


void print_arr(int* arr, int arrSize, int ver) {
    cout << "version " << ver << " : ";
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}