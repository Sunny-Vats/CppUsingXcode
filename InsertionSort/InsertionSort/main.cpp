//
//  main.cpp
//  InsertionSort
//
//  Created by Sunny Vats on 02/04/21.
//

#include <iostream>
using namespace std;

void insertionSort(int *arr, int len);
void display(int *arr, int len);

int main() {
    int arr[] {5,4,1,3,2};
    int len = sizeof(arr)/sizeof(int);
    cout << "Array to be sorted: ";
    display(arr, len);
    cout << endl;
    insertionSort(arr, len);
    cout << "Sorted array: " << endl;
    display(arr, len);
    cout << endl;
    return 0;
}

void insertionSort(int *arr, int len) {
    for (int j = 1; j < len; j++) {
        int key = arr[j];
        int i = j - 1;
        while( i >= 0 && key < arr[i] ) {
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key;
    }
}

void display(int *arr, int len) {
    int i = 0;
    while( len > i) {
        cout << *(arr+i) << " ";
        i++;
    }
    cout << endl << "±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±";
}
